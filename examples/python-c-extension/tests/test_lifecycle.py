"""Regression tests for the fwlib extension, run against tests/stub_fwlib.c
(no CNC needed):

    docker build --target test -f examples/python-c-extension/Dockerfile .

Closing or re-initialising a Context while another thread is inside
read_id() must not free the handle under the read.
"""

import ctypes
import threading
import time
import unittest

import fwlib

# the stub the extension is linked against, for its counters
stub = ctypes.CDLL("libfwlib32.so")
EXPECTED_ID = "11111111-22222222-33333333-44444444"


class ContextLifecycleTest(unittest.TestCase):
    def setUp(self):
        stub.stub_reset()

    def close_during_read(self, close):
        ctx = fwlib.Context()
        result = {}
        reader = threading.Thread(target=lambda: result.update(id=ctx.read_id()))
        reader.start()

        deadline = time.monotonic() + 5
        while stub.stub_reads() == 0:
            self.assertLess(time.monotonic(), deadline, "read_id never started")
            time.sleep(0.001)
        close(ctx)  # while cnc_rdcncid sleeps in the reader thread

        reader.join(5)
        self.assertFalse(reader.is_alive())
        self.assertEqual(result.get("id"), EXPECTED_ID)
        self.assertEqual(
            stub.stub_overlaps(), 0, "a FOCAS call ran while cnc_rdcncid was in progress"
        )
        return ctx

    def test_exit_waits_for_read(self):
        self.close_during_read(lambda ctx: ctx.__exit__(None, None, None))
        self.assertEqual(stub.stub_frees(), 1)
        self.assertEqual(stub.stub_exits(), 1)

    def test_reinit_waits_for_read(self):
        ctx = self.close_during_read(lambda ctx: ctx.__init__())
        self.assertEqual(stub.stub_frees(), 1)
        ctx.__exit__(None, None, None)

    def test_read_id_returns_all_four_words(self):
        with fwlib.Context() as ctx:
            self.assertEqual(ctx.read_id(), EXPECTED_ID)


if __name__ == "__main__":
    unittest.main(verbosity=2)
