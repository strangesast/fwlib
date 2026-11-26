#include <Python.h>
#include <stdint.h>
#include "fwlib32.h"

#define MACHINE_PORT_DEFAULT 8193
#define TIMEOUT_DEFAULT 10

typedef struct {
    PyObject_HEAD
    unsigned short libh;
    int connected;
    int started; /* holds a reference on the FOCAS process (see focas_acquire) */
} Context;

/*
 * cnc_startupprocess / cnc_exitprocess are process-wide, not per connection:
 * keep a count of the contexts using FOCAS so that closing one context does
 * not shut FOCAS down under the others. Only modified while holding the GIL.
 */
static int focas_users = 0;

static int focas_acquire(void) {
#ifndef _WIN32
    if (focas_users == 0 && cnc_startupprocess(0, "focas.log") != EW_OK) {
        return -1;
    }
#endif
    focas_users++;
    return 0;
}

static void focas_release(void) {
    if (focas_users > 0 && --focas_users == 0) {
#ifndef _WIN32
        cnc_exitprocess();
#endif
    }
}

/* Frees the connection and the FOCAS reference, if any. Safe to call twice. */
static void Context_close(Context* self) {
    if (self->connected) {
        cnc_freelibhndl(self->libh);
        self->connected = 0;
    }
    if (self->started) {
        focas_release();
        self->started = 0;
    }
}

static PyObject* Context_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    Context* self;
    self = (Context*) type->tp_alloc(type, 0);
    if (self != NULL) {
        self->libh = 0;
        self->connected = 0;
        self->started = 0;
    }
    return (PyObject*) self;
}

static int Context_init(Context* self, PyObject* args, PyObject* kwds) {
    const char* host = "127.0.0.1";
    int port = MACHINE_PORT_DEFAULT;
    int timeout = TIMEOUT_DEFAULT;
    unsigned short libh;
    int ret;

    static char* kwlist[] = {"host", "port", "timeout", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|sii", kwlist, &host, &port, &timeout)) {
        return -1;
    }
    if (port < 1 || port > 65535) {
        PyErr_Format(PyExc_ValueError, "port must be between 1 and 65535, got %d", port);
        return -1;
    }
    if (timeout < 0) {
        PyErr_Format(PyExc_ValueError, "timeout must be >= 0, got %d", timeout);
        return -1;
    }

    /* __init__ may be called again on the same object: drop the old connection */
    Context_close(self);

    if (focas_acquire() != 0) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to start FANUC process.");
        return -1;
    }
    self->started = 1;

    /* connecting can block for up to `timeout` seconds: let other threads run */
    Py_BEGIN_ALLOW_THREADS
    ret = cnc_allclibhndl3(host, (unsigned short) port, timeout, &libh);
    Py_END_ALLOW_THREADS

    if (ret != EW_OK) {
        Context_close(self);
        PyErr_Format(PyExc_ConnectionError, "Failed to connect to CNC: %d", ret);
        return -1;
    }
    self->libh = libh;
    self->connected = 1;

    return 0;
}

static void Context_dealloc(Context* self) {
    Context_close(self);
    Py_TYPE(self)->tp_free((PyObject*) self);
}

static PyObject* Context_read_id(Context* self, PyObject* Py_UNUSED(ignored)) {
    /* cnc_rdcncid writes four 32-bit words, whatever the `unsigned long *` in
     * its prototype suggests (unsigned long is 8 bytes on 64-bit Linux, but the
     * x64 library still stores 4-byte words): keep a uint32_t[4] buffer. */
    uint32_t cnc_ids[4] = {0, 0, 0, 0};
    unsigned short libh = self->libh;
    char cnc_id[40] = "";
    int ret;

    if (!self->connected) {
        PyErr_SetString(PyExc_RuntimeError, "Context is not connected (already closed?)");
        return NULL;
    }

    Py_BEGIN_ALLOW_THREADS
    ret = cnc_rdcncid(libh, (unsigned long*) cnc_ids);
    Py_END_ALLOW_THREADS

    if (ret != EW_OK) {
        PyErr_Format(PyExc_RuntimeError, "Failed to read CNC ID: %d", ret);
        return NULL;
    }

    snprintf(cnc_id, sizeof(cnc_id), "%08x-%08x-%08x-%08x",
             cnc_ids[0], cnc_ids[1], cnc_ids[2], cnc_ids[3]);

    return PyUnicode_FromString(cnc_id);
}

static PyObject* Context_enter(PyObject* self, PyObject* Py_UNUSED(ignored)) {
    Py_INCREF(self);
    return self;
}

/* METH_VARARGS: called as (self, (exc_type, exc_value, traceback)) */
static PyObject* Context_exit(Context* self, PyObject* Py_UNUSED(args)) {
    Context_close(self);
    Py_RETURN_NONE;
}

static PyMethodDef Context_methods[] = {
    {"read_id", (PyCFunction) Context_read_id, METH_NOARGS, "Reads the CNC ID."},
    {"__enter__", (PyCFunction) Context_enter, METH_NOARGS, "Enter the context."},
    {"__exit__", (PyCFunction) Context_exit, METH_VARARGS, "Exit the context."},
    {NULL}  /* Sentinel */
};

static PyTypeObject ContextType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "fwlib.Context",
    .tp_doc = "FANUC Context Manager",
    .tp_basicsize = sizeof(Context),
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = Context_new,
    .tp_init = (initproc) Context_init,
    .tp_dealloc = (destructor) Context_dealloc,
    .tp_methods = Context_methods,
};

static PyModuleDef fwlibmodule = {
    PyModuleDef_HEAD_INIT,
    "fwlib",
    "Python wrapper for FANUC fwlib32 library",
    -1,
    NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC PyInit_fwlib(void) {
    PyObject* m;
    if (PyType_Ready(&ContextType) < 0)
        return NULL;

    m = PyModule_Create(&fwlibmodule);
    if (m == NULL)
        return NULL;

    Py_INCREF(&ContextType);
    if (PyModule_AddObject(m, "Context", (PyObject*) &ContextType) < 0) {
        Py_DECREF(&ContextType);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
