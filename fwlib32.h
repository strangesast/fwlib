/*-------------------------------------------------------------------*/
/* fwlib32.h                                                         */
/*                                                                   */
/* CNC/PMC Data Window Library for FOCAS                             */
/*                                                                   */
/* Copyright (C) 2003-2017 by FANUC CORPORATION All rights reserved. */
/*                                                                   */
/*-------------------------------------------------------------------*/

#ifndef _INC_FWLIB
#define _INC_FWLIB
/*

  This library is proprietary software complied by GCC through Eligible Compilation Process.

  As for GCC and Eligible Compilation Process, 
  see <http://www.gnu.org/licenses/gcc-exception-3.1.html>.

*/

#if defined (_WIN32) ||  defined (_WIN32_WCE)
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {

namespace Fwlib32
{
#endif

#if defined (_WIN32) ||  defined (_WIN32_WCE)
#if !defined(_FWLIBDLL_)
#define FWLIBAPI __declspec(dllimport)
#else
#define FWLIBAPI __declspec(dllexport)
#endif
#else
#define FWLIBAPI
#define WINAPI
#define HWND	int
#endif

/*
    Axis define
*/
/* machine information for Ethernet library for Linux */
#if defined (F22_TYPE5)
#define MAX_AXIS        48
#define MAX_SPINDLE     16
#else
#define MAX_AXIS        32
#define MAX_SPINDLE     8
#endif

#if !defined (MAX_AXIS)
#if defined (F22_TYPEB) || ((!defined(CNC_PPC)) && (!defined(CNC_SIM)))
#define MAX_AXIS        96
#elif defined (F22_TYPEA)
#define MAX_AXIS        72
#elif defined (F22_TYPE5)
#define MAX_AXIS        48
#else
#define MAX_AXIS        32
#endif
#endif
#if !defined (MAX_SPINDLE)
#if defined (F22_TYPEB) || ((!defined(CNC_PPC)) && (!defined(CNC_SIM)))
#define MAX_SPINDLE     24
#elif defined (F22_TYPEA) || defined (F22_TYPE5)
#define MAX_SPINDLE     16
#else
#define MAX_SPINDLE      8
#endif
#endif

#define MAX_AXISNAME    4

#define ALL_AXES        (-1)
#define ALL_SPINDLES    (-1)

#if !defined (MAX_IFSB_LINE)
#if defined(F22_TYPEA) || defined(F22_TYPEB) || ((defined(PM_H)) && (!defined(DSA_SYS))) || ((!defined(CNC_PPC)) && (!defined(CNC_SIM)))
#define MAX_IFSB_LINE   4   /* Maximum line number */
#else
#define MAX_IFSB_LINE   3   /* Maximum line number */
#endif
#endif

#if !defined (MAX_CNCPATH)
#if defined(F22_TYPEA) || ((!defined(CNC_PPC)) && (!defined(CNC_SIM)))
#define MAX_CNCPATH     15
#else
#define MAX_CNCPATH     10
#endif
#endif

/*
    Program lock define
*/
#define MAX_LOCK_PROG   12              /* Program lock max num */

/*
    Error Codes
*/
#define EW_PROTOCOL     (-17)           /* protocol error */
#define EW_SOCKET       (-16)           /* Windows socket error */
#define EW_NODLL        (-15)           /* DLL not exist error */
#define	EW_INIERR       (-14)           /* error in APi library inital valiefile */
#define	EW_ITLOW        (-13)           /* low temperature alarm of intelligent terminal */
#define	EW_ITHIGHT      (-12)           /* hight temperature alarm of intelligent terminal */
#define EW_BUS          (-11)           /* bus error */
#define EW_SYSTEM2      (-10)           /* system error */
#define EW_HSSB         (-9)            /* hssb communication error */
#define EW_HANDLE       (-8)            /* Windows library handle error */
#define EW_VERSION      (-7)            /* CNC/PMC version missmatch */
#define EW_UNEXP        (-6)            /* abnormal error */
#define EW_SYSTEM       (-5)            /* system error */
#define EW_PARITY       (-4)            /* shared RAM parity error */
#define EW_MMCSYS       (-3)            /* emm386 or mmcsys install error */
#define EW_RESET        (-2)            /* reset or stop occured error */
#define EW_BUSY         (-1)            /* busy error */
#define EW_OK           0               /* no problem */
#define EW_FUNC         1               /* command prepare error */
#define EW_NOPMC        1               /* pmc not exist */
#define EW_LENGTH       2               /* data block length error */
#define EW_NUMBER       3               /* data number error */
#define EW_RANGE        3               /* address range error */
#define EW_ATTRIB       4               /* data attribute error */
#define EW_TYPE         4               /* data type error */
#define EW_DATA         5               /* data error */
#define EW_NOOPT        6               /* no option error */
#define EW_PROT         7               /* write protect error */
#define EW_OVRFLOW      8               /* memory overflow error */
#define EW_PARAM        9               /* cnc parameter not correct error */
#define EW_BUFFER       10              /* buffer error */
#define EW_PATH         11              /* path error */
#define EW_MODE         12              /* cnc mode error */
#define EW_REJECT       13              /* execution rejected error */
#define EW_DTSRVR       14              /* data server error */
#define EW_ALARM        15              /* alarm has been occurred */
#define EW_STOP         16              /* CNC is not running */
#define EW_PASSWD       17              /* protection data error */
#define EW_PMC          18              /* error generated by PMC */
#define EW_PMCHANDLE    19              /* PMC handle error */
#define EW_RD_OVWSTP    20              /* overwrite stop in program read  */
#define EW_RD_RSTFIN    21              /* reset interrupt in program read  */

/*
   Result codes of DNC operation
*/
#define DNC_NORMAL	(-1)		/* normal completed */
#define DNC_CANCEL	(-32768)	/* DNC operation was canceled by CNC */
#define DNC_OPENERR	(-514)		/* file open error */
#define DNC_NOFILE	(-516)		/* file not found */
#define DNC_READERR	(-517)		/* read error */

/*
   Option name for cnc_getlibopt / cnc_setlibopt
*/
#define LIB_MODE          0
#define MOVE_RDPRGPTR     1
#define PRM_ALLPATH       2
#define UPLOAD_M02M99     3
#define MSG_NOCTRL        4
#define DIAM_RAD_SWITCH   5
#define MSG_CONV          6
#define ASYNC_READ_PROG3  7

#define UP_DNLOAD_EDT     8
#define PROG_WORD_SRCH    9
#define ONUM_ZERO_SUP    10
#define LONG_ISE_FIG     11
#define INT_CHK_UNIT     12
#define HZR_PRM_WR_SKIP  13
#define SLVSRAM_ACCESS   14
#define GET_SMTCP_STAT   15
#define TLIFE_OPTION     16
#define SVGD_MATE_PUNCH  17
#define READ_FLD_ON      18
#define DELETE_RECURSIVE 19
#define READ_ORIG_OPT    20
#define SVGD_MATE_ORIGIN 21
#define PUN_SFZN_MDP     22
#define PAXIS_PATH       23
#define AXDATA_G198      24
#define BG_EDIT_SIGNAL   25
#define UPLOAD_BG        26
#define TDATA_EXTRACT    27
#define PROG_CHECK_CMNT  28
#define INITIAL_AX_CONFIG 29
#define MGI_SPECIFICATION 30
#define EFFECTIVE_COND   31
#define LEVEL8_PROTECT   32
#define ACTPT_M198       33
#define SYSINFO_AXIS     34
#define ALARM_INFO_TYPE  35
#define PROG_LEDT_SPUP   36
#define OPMSG_STATUS     37
#define ASYNC_SEARCHWORD 38
#define MA_OPT           39
#define ENABLE_FOCAS_DMA 40
#define DSHOST_RD_SRCH   41
#define BG_EDIT_CONTINUE 42
#define BG_EDIT_GRAPH    43
#define SEARCHWORD_PNTR  44
#define PROG_UPLD_PROT   45
#define POLAR_IPL_POS    46
#define PRG_NO_RD_PROT   47
#define TOOL_STORAGE     48
#define PRG_FMT_CK       49
#define NCPROG_MODE      50
#define COMMAND_TIMEOUT  51
#define PGLOCK_TYPE      64
#define TLIFE_TOOL0     128
#define OPPROG_DSP      256
#define OPPROG_MODE     512
#define PROGRAM_CHECK  1024
#define CZPP_NEDPP     2048
#define MULTI_PATH_MIX_AXIS_NAME    4096

/*
   Work-piece setting
*/
#define WSETER_GRP		8
#define WSETER_DATA		8

/*
   3D interference check
*/
#define MAX_POS_BUF		2

/* cnc_rdtlgeomsize:read tool geom size data */
#define TLGS_EMP  0x7FFFFFFF

/*
    cnc_data_copy
*/
#define DC_PRM          1   /* parameter          */
#define DC_OFS          2   /* offset             */
#define DC_WKZ          3   /* work zero offset   */
#define DC_MAC          4   /* macro value        */
#define DC_PCD          5   /* P-CODE macro value */
#define DC_RTM          6   /* RTM value          */

/*--------------------*/
/*                    */
/* Structure Template */
/*                    */
/*--------------------*/
/*-------------------------------------*/
/* CNC: Control axis / spindle related */
/*-------------------------------------*/

#ifdef _MSC_VER
#pragma pack(push, 4)
#endif
/* cnc_actf:read actual axis feedrate(F) */
/* cnc_acts:read actual spindle speed(S) */
typedef struct odbact {
    short   dummy[2] ;  /* dummy */
    long    data ;      /* actual feed / actual spindle */
} ODBACT ;

/* cnc_acts2:read actual spindle speed(S) */
/* (All or specified ) */
typedef struct odbact2 {
	 short	datano;		/* spindle number */
	 short	type;		/* dummy */
	 long	data[MAX_SPINDLE];	/* spindle data */
} ODBACT2 ;

/* cnc_absolute:read absolute axis position */
/* cnc_machine:read machine axis position */
/* cnc_machine2:read machine axis position(2) */
/* cnc_relative:read relative axis position */
/* cnc_distance:read distance to go */
/* cnc_skip:read skip position */
/* cnc_srvdelay:read servo delay value */
/* cnc_accdecdly:read acceleration/deceleration delay value */
/* cnc_absolute2:read absolute axis position 2 */
/* cnc_relative2:read relative axis position 2 */
/* cnc_absolute_bg:read absolute axis position (BG) */
/* cnc_relative_bg:read relative axis position (BG) */
/* cnc_machine_bg:read machine axis position (BG) */
typedef struct odbaxis {
    short   dummy ;             /* dummy */
    short   type ;              /* axis number */
    long    data[MAX_AXIS] ;    /* data value */
} ODBAXIS ;
typedef struct odbaxis_ex {
    short   counter ;           /* counter */
    short   type ;              /* axis number */
    long    data[MAX_AXIS] ;    /* data value */
} ODBAXIS_EX ;

/*-------------------------------------*/
/* IS-E long stroke type               */
/*-------------------------------------*/

typedef struct realdata {
    double val;                  /* data value    */
    long   dec;                  /* decimal point */
    long   dummy;
} REALDATA;

/* cnc_prstwkcd64:preset work coordinate */
typedef struct idbwra64 {
    short       datano;         /* dummy */
    short       type;           /* axis number */
    short       dummy[2];       /* dummy2 */
    REALDATA    data[MAX_AXIS]; /* preset data */
} IDBWRA64;

/* cnc_wrrelpos64:set origin / preset relative axis position */
typedef struct idbwrr64 {
    short       datano;         /* dummy */
    short       type;           /* axis number */
    short       dummy[2];       /* dummy2 */
    REALDATA    data[MAX_AXIS]; /* preset data */
} IDBWRR64;

/* cnc_rdcommand64: read command value */
typedef struct odbcmd64 {
    char        adrs;           /* command address */
    char        num;            /* M-Code / axis num */
    short       flag;           /* add info */
    long        dec_val;        /* decimal point */
    double      cmd_val;        /* command data  */
} ODBCMD64;

/* cnc_zofs_rnge64:read validity of work zero offset */
/* cnc_wksft_rnge64:read validity of work shift value */
typedef struct odbdatrng64 {
    double      data_min;       /* lower limit */
    double      data_max;       /* upper limit */
    long        dec;            /* decimal point */
    long        status;         /* status of setting */
} ODBDATRNG64;

/* cnc_rdzofsr64:read work zero offset value(area specified) */
typedef struct iodbzor64 {
    short       datano_s;           /* start offset number */
    short       type;               /* axis number */
    short       datano_e;           /* end offset number */
    short       dummy;              /* dummy */
    REALDATA    data[MAX_AXIS*8];   /* offset value */
} IODBZOR64; /* In case that the number of axes is MAX_AXIS, the number of data is 7 */

/* cnc_rdparam64 : read  parameter (IEEE double version) */
/* cnc_wrparam64 : write parameter (IEEE double version) */
typedef struct iodbpsd64 {
    short       datano;     /* data number */
    short       type ;      /* data type */
    short       axis ;      /* axis number */
    short       dummy ;     /* dummy */
    union {
        char        cdata;  /* parameter / setting data */
        short       idata;  /* short tyoe data */
        long        ldata;  /* long tyoe data */
        REALDATA    rdata;  /* real type data */
        char        cdatas[MAX_AXIS];
        short       idatas[MAX_AXIS];
        long        ldatas[MAX_AXIS];
        REALDATA    rdatas[MAX_AXIS];
    } u;
} IODBPSD64;

/* cnc_rdwkcdshft64:read  work coordinate shift */
/* cnc_wrwkcdshft64:write work coordinate shift */
/* cnc_rdwkcdsfms64:read  work coordinate shift measure */
/* cnc_wrwkcdsfms64:write work coordinate shift measure */
typedef struct iodbwcsf64 {
    short       dummy1;         /* dummy1 */
    short       type;           /* axis number */
    short       dummy2[2];      /* dummy2 */
    REALDATA    data[MAX_AXIS]; /* data */
} IODBWCSF64;

/* cnc_wrzofs64:write work zero offset value */
typedef struct iodbzofs64 {
    short       datano;         /* offset NO. */
    short       type;           /* axis number */
    short       dummy[2];       /* dummy */
    REALDATA    data[MAX_AXIS]; /* data value */
} IODBZOFS64;

/* cnc_machine:read machine axis position */
typedef struct odbaxis64 {
    short       dummy1 ;        /* dummy1 */
    short       type ;          /* axis number */
    short       dummy2[2];      /* dummy2 */
    REALDATA    data[MAX_AXIS]; /* data value */
} ODBAXIS64 ;

/* cnc_rdaxisdata64:read various axis data(IEEE double version) */
typedef struct odbaxdt64 {
    char    name[4];    /* axis name */
    char    dummy[4];
    double  data;       /* position data */
    short   dec;        /* decimal position */
    short   unit;       /* data unit */
    short   flag;       /* flags */
    short   reserve;    /* reserve */
} ODBAXDT64 ;

typedef struct odbdgn64 {
    short   datano ;    /* data number */
    short   type ;      /* axis number */
    short   axis ;      /* axis number */
    short   dummy ;     /* dummy */
    union {
        char        cdata ; /* diagnosis data */
        short       idata ;
        long        ldata ;
        REALDATA    rdata ;
        char        cdatas[MAX_AXIS] ;
        short       idatas[MAX_AXIS] ;
        long        ldatas[MAX_AXIS] ;
        REALDATA    rdatas[MAX_AXIS] ;
    } u ;
} ODBDGN64 ;

/* cnc_wrtofsdrctinp:write Tool offset data Direct Input(IEEE double version) */
typedef struct realmes64 {
	double mes_val; /* data of real measeure */
	long   dec_val; /* decimal point of real measeure */
	long   dummy;   /* dummy */
} REALMES64;

/* cnc_rddynamic:read all dynamic data */
typedef struct odbdy {
    short   dummy ;
    short   axis ;      /* axis number */
    short   alarm ;     /* alarm status */
    short   prgnum ;    /* current program number */
    short   prgmnum ;   /* main program number */
    long    seqnum ;    /* current sequence number */
    long    actf ;      /* actual feedrate */
    long    acts ;      /* actual spindle speed */
    union {
        struct {
            long    absolute[MAX_AXIS] ;    /* absolute position */
            long    machine[MAX_AXIS] ;     /* machine position */
            long    relative[MAX_AXIS] ;    /* relative position */
            long    distance[MAX_AXIS] ;    /* distance to go */
        } faxis ;
        struct {
            long    absolute ;  /* absolute position */
            long    machine ;   /* machine position */
            long    relative ;  /* relative position */
            long    distance ;  /* distance to go */
        } oaxis ;   /* In case of no axis */
    } pos ;
} ODBDY ;

/* cnc_rddynamic2:read all dynamic data */
typedef struct odbdy2 {
    short   dummy ;
    short   axis ;       /* axis number             */
    long    alarm ;      /* alarm status            */
    long    prgnum ;     /* current program number  */
    long    prgmnum ;    /* main program number     */
    long    seqnum ;     /* current sequence number */
    long    actf ;       /* actual feedrate         */
    long    acts ;       /* actual spindle speed    */
    union {
        struct {
            long    absolute[MAX_AXIS] ;    /* absolute position   */
            long    machine[MAX_AXIS] ;     /* machine position    */
            long    relative[MAX_AXIS] ;    /* relative position   */
            long    distance[MAX_AXIS] ;    /* distance to go      */
        } faxis ;
        struct {
            long    absolute ;  /* absolute position   */
            long    machine ;   /* machine position    */
            long    relative ;  /* relative position   */
            long    distance ;  /* distance to go      */
        } oaxis ;   /* In case of 1 axis  */
    } pos ;
} ODBDY2 ;

/* cnc_rddynamic3:read all dynamic data(3) */
typedef struct odbdy3 {
    short   dummy ;
    short   axis ;       /* axis number             */
    long    alarm ;      /* alarm status            */
    long    prgnum ;     /* current program number  */
    long    prgmnum ;    /* main program number     */
    long    seqnum ;     /* current sequence number */
    long    actf ;       /* actual feedrate         */
    long    acts ;       /* actual spindle speed    */
    union {
        struct {
            long    absolute[MAX_AXIS] ;    /* absolute position   */
            long    machine[MAX_AXIS] ;     /* machine position    */
            long    relative[MAX_AXIS] ;    /* relative position   */
            long    distance[MAX_AXIS] ;    /* distance to go      */
        } faxis ;
        struct {
            long    absolute ;  /* absolute position   */
            long    machine ;   /* machine position    */
            long    relative ;  /* relative position   */
            long    distance ;  /* distance to go      */
        } oaxis ;   /* In case of 1 axis  */
    } pos ;
} ODBDY3 ;

/* cnc_rddynamic3m:read all dynamic data(3m) */
typedef struct odbdy3m {
    short   dummy ;
    short   axis ;       /* axis number             */
    long    alarm ;      /* alarm status            */
    long    prgnum ;     /* current program number  */
    long    prgmnum ;    /* main program number     */
    long    seqnum ;     /* current sequence number */
    long    actf ;       /* actual feedrate         */
    long    acts ;       /* actual spindle speed    */
    union {
        struct {
            long    absolute[32] ;    /* absolute position   */
            long    machine[32] ;     /* machine position    */
            long    relative[32] ;    /* relative position   */
            long    distance[32] ;    /* distance to go      */
        } faxis ;
        struct {
            long    absolute ;  /* absolute position   */
            long    machine ;   /* machine position    */
            long    relative ;  /* relative position   */
            long    distance ;  /* distance to go      */
        } oaxis ;   /* In case of 1 axis  */
    } pos ;
} ODBDY3M ;

/* cnc_wrrelpos:set origin / preset relative axis position */
typedef struct idbwrr {
    short   datano;         /* dummy */
    short   type;           /* axis number */
    long    data[MAX_AXIS]; /* preset data */
} IDBWRR;

/* cnc_prstwkcd:preset work coordinate */
typedef struct idbwra {
    short   datano;         /* dummy */
    short   type;           /* axis number */
    long    data[MAX_AXIS]; /* preset data */
} IDBWRA;

/* cnc_rdmovrlap:read manual overlapped motion value */
typedef struct iodbovl {
    short   datano;             /* dummy */
    short   type;               /* axis number */
    long    data[2][MAX_AXIS];  /* data value */
} IODBOVL;

/* cnc_rdmovrlapm:read manual overlapped motion value */
typedef struct iodbovlm {
    short   datano;       /* dummy */
    short   type;         /* axis number */
    long    data[2][32];  /* data value */
} IODBOVLM;

/* cnc_rdspload:read load information of serial spindle */
/* cnc_rdspmaxrpm:read maximum r.p.m. ratio of serial spindle */
/* cnc_rdspgear:read gear ratio of serial spindle */
typedef struct odbspn {
    short   datano;     /* spindle number */
    short   type;       /* dummy */
    short   data[MAX_SPINDLE];    /* spindle data */
} ODBSPN;

/* cnc_rdposition:read tool position */
typedef struct poselm {
    long    data;       /* position data */
    short   dec;        /* decimal position */
    short   unit;       /* data unit */
    short   disp;       /* display flag */
    char    name;       /* axis name */
    char    suff;       /* suffix */
} POSELM;

#if !defined (PMD) /* except Power Mate D/H */
typedef struct odbpos {
    POSELM  abs;        /* absolute position */
    POSELM  mach;       /* machine position */
    POSELM  rel;        /* relative position */
    POSELM  dist;       /* distance position */
} ODBPOS ;
#endif

/* cnc_rdhndintrpt:read handle interruption */
typedef struct odbhnd {
    POSELM  input;      /* input unit */
    POSELM  output;     /* output unit */
} ODBHND ;

/* cnc_rdspeed:read current speed */
/* cnc_rdjogdrun:read displayed jog or dryrun feedrate */
typedef struct speedelm {
    long    data;       /* speed data */
    short   dec;        /* decimal position */
    short   unit;       /* data unit */
    short   disp;       /* display flag */
    char    name;       /* name of data */
    char    suff;       /* suffix */
} SPEEDELM ;

typedef struct odbspeed {
    SPEEDELM    actf;   /* actual feed rate */
//  SPEEDELM    acts;   /* actual spindle speed */
    SPEEDELM    acts;   /* type = 1,-1 : actual spindle speed */
						/* type = 2,-2 : milling servo speed  */
} ODBSPEED ;

typedef struct odbjogdrun {
    SPEEDELM    jogdrun;/* jog or dryrun feedrate */
} ODBJOGDRUN ;

/* cnc_rdsvmeter:read servo load meter */
/* cnc_rdspmeter:read spindle load meter */
typedef struct loadelm {
    long    data;       /* load meter */
    short   dec;        /* decimal position */
    short   unit;       /* unit */
    char    name;       /* name of data */
    char    suff1;      /* suffix */
    char    suff2;      /* suffix */
    char    reserve;    /* reserve */
} LOADELM ;

typedef struct odbsvload {
    LOADELM svload;     /* servo load meter */
} ODBSVLOAD ;

typedef struct odbspload {
    LOADELM spload;     /* spindle load meter */
    LOADELM spspeed;    /* spindle speed */
} ODBSPLOAD ;

/* cnc_rdaxisdata:read various axis data */
typedef struct odbaxdt {
    char    name[4];    /* axis name */
    long    data;       /* position data */
    short   dec;        /* decimal position */
    short   unit;       /* data unit */
    short   flag;       /* flags */
    short   reserve;    /* reserve */
} ODBAXDT;

/* cnc_rdspcss:read constant surface speed data */
typedef struct odbcss {
    long    srpm;       /* order spindle speed */
    long    sspm;       /* order constant spindle speed */
    long    smax;       /* order maximum spindle speed */
} ODBCSS;

/* cnc_simulation:read data for machining simulation */
typedef struct odbsiml {
    long    t_code ;
    long    b_code ;
    long    axis_no ;
    long    machine[MAX_AXIS] ;
    long    dec[MAX_AXIS] ;
    long    fscsl ;
} ODBSIML;

/* cnc_loadtorq */
typedef struct odbload {
	short	datano;
	short	type;
	short	data[MAX_AXIS];
} ODBLOAD;

/* cnc_rdexecpt:read execution program pointer */
#ifndef CNC_PPC
typedef struct prgpnt {
    long    prog_no;    /* program number */
    long    blk_no;     /* block number */
} PRGPNT;
#endif

/* cnc_rdactpt_w:read execution pointer of program for FS160is/180is-WB */
typedef struct odbactptw {
    long    mprgno;     /* main program number */
    long    mblkno;     /* main block number */
    long    sprgno;     /* sub program number */
    long    sblkno;     /* sub block number */
} ODBACTPTW ;

/* cnc_rd5axmandt:read manual feed for 5-axis machining */
typedef	struct odb5axman {
    short   type1;
    short   type2;
    short   type3;
    long    data1;
    long    data2;
    long    data3;
    long    c1;
    long    c2;
    long    dummy;
    long    td;
    long    r1;
    long    r2;
    long    vr;
    long    h1;
    long    h2;
} ODB5AXMAN ;

/* cnc_rdposfig:read position and decimal figure */
typedef struct odbposfig {
    long    val;
    long    dec;
} ODBPOSFIG ;


/*----------------------*/
/* CNC: Program related */
/*----------------------*/

/* cnc_rddncdgndt:read the diagnosis data of DNC operation */
typedef struct odbdncdgn {
    short          ctrl_word;
    short          can_word;
    char           nc_file[16];
    unsigned short read_ptr;
    unsigned short write_ptr;
    unsigned short empty_cnt;
    unsigned long  total_size;
} ODBDNCDGN;

/* cnc_rddncdgndt:read the diagnosis data of DNC operation (2) */
typedef struct odbdncdgn2 {
    short          ctrl_word;
    short          can_word;
    char           nc_file[64];
    unsigned short read_ptr;
    unsigned short write_ptr;
    unsigned short empty_cnt;
    unsigned long  total_size;
} ODBDNCDGN2;

/* cnc_upload:upload NC program */
/* cnc_cupload:upload NC program(conditional) */
typedef struct odbup {
    short   dummy[2] ;  /* dummy */
    char    data[256] ; /* data */
} ODBUP ;   /* In case that the number of data is 256 */

/* cnc_buff:read buffer status for downloading/verification NC program */
typedef struct odbbuf {
    short   dummy[2] ;  /* dummy */
    short   data ;      /* buffer status */
} ODBBUF ;

/* cnc_rdpdf_pglockstat: read program lock status */
typedef struct odbprgname {
    char    name[MAX_LOCK_PROG][256];
} ODBPRGNAME;

/* cnc_rdprogdir:read program directory */
typedef struct prgdir {
    char    prg_data[256] ; /* directory data */
} PRGDIR ;  /* In case that the number of data is 256 */

/* cnc_rdproginfo:read program information */
typedef struct odbnc {
    union {
        struct {
            short   reg_prg ;       /* registered program number */
            short   unreg_prg ;     /* unregistered program number */
            long    used_mem ;      /* used memory area */
            long    unused_mem ;    /* unused memory area */
        } bin ;             /* binary data type */
        char    asc[31] ;   /* ASCII string type */
    } u ;
} ODBNC ;

/* cnc_rdprgnum:read program number under execution */
typedef struct odbpro {
    short   dummy[2] ;  /* dummy */
    short   data ;      /* running program number */
    short   mdata ;     /* main program number */
} ODBPRO ;

/* cnc_exeprgname:read program name under execution */
typedef struct odbexeprg {
    char  name[36];     /* running program name */
    long  o_num;        /* running program number */
} ODBEXEPRG;            /*                        */

/* cnc_dncprgname:read program name of DNC operation */
typedef struct odbdncprg {
    char  name[36];     /* running program name */
    long  o_num;        /* running program number */
} ODBDNCPRG;            /*                        */

/* cnc_rdseqnum:read sequence number under execution */
typedef struct odbseq {
    short   dummy[2] ;  /* dummy */
    long    data ;      /* sequence number */
} ODBSEQ ;

/* cnc_rdexecprog3:read execute-program infomation  */
typedef struct tagEXEPRG {
    unsigned short  length;		/* read data length      */
    short           prep_blk;	/* prepared block number */
    short           act_blk;	/* actual block number   */
    short           dummy;		/* dummy                 */
    char            data[512];	/* execute program       */
} EXEPRG;

typedef struct odbexeprginfo {
	EXEPRG	before_buffering;
	EXEPRG	after_buffering;
} ODBEXEPRGINFO;

/* cnc_rdmdipntr:read execution pointer for MDI operation */
typedef struct odbmdip {
    short   mdiprog;    /* exec. program number */
    long    mdipntr;    /* exec. pointer */
    short   crntprog;   /* prepare program number */
    long    crntpntr;   /* prepare pointer */
} ODBMDIP;

/* cnc_pdf_rdcallstack:read call stack PDF */
typedef struct odbnest{
	unsigned long	attrib;
	char			comment[64] ;
	char			prog_name[245];
	char			dummy[7];
} ODBNESTPDF;

/* cnc_rdpdf_drive:read program drive directory */
typedef struct odbpdfdrv {
	short	max_num;		/* maximum drive number */
	short	dummy;
	char	drive[16][12];	/* drive name */
} ODBPDFDRV ;

/* cnc_rdpdf_inf:read program drive information */
typedef struct odbpdfinf {
	long	used_page;	/* used capacity */
	long	all_page;	/* all capacity */
	long	used_dir;	/* used directory number */
	long	all_dir;	/* all directory number */
} ODBPDFINF ;

/* cnc_rdpdf_subdir:read directory (sub directories) */
typedef struct idbpdfsdir {
	char	path[212];	/* path name */
	short	req_num;	/* entry number */
	short	dummy;
} IDBPDFSDIR ;

/* cnc_rdpdf_subdir:read directory (sub directories) */
typedef struct odbpdfsdir {
	short	sub_exist;	/* existence of sub directory */
	short	dummy;
	char	d_f[36];	/* directory name */
} ODBPDFSDIR ;

/* cnc_rdpdf_alldir:read directory (all files) */
typedef struct idbpdfadir {
	char	path[212];	/* path name */
	short	req_num;	/* entry number */
	short	size_kind;	/* kind of size */
	short	type;		/* kind of format */
	short	dummy;
} IDBPDFADIR ;

/* cnc_rdpdf_alldir:read directory (all files) */
typedef struct odbpdfadir {
	short	data_kind;	/* kinf of data */
	short	year;		/* last date and time */
	short	mon;		/* last date and time */
	short	day;		/* last date and time */
	short	hour;		/* last date and time */
	short	min;		/* last date and time */
	short	sec;		/* last date and time */
	short	dummy;
	long	dummy2;
	long	size;		/* size */
	unsigned long attr;	/* attribute */
	char	d_f[36];	/* path name */
	char	comment[52];/* comment */
	char	o_time[12];	/* machining time stamp */
} ODBPDFADIR ;

/* cnc_rdpdf_prginf:read program infomation  */
typedef struct idbpdfprg {
	char	path[244];	/* path name */
	short	size_kind;	/* kind of size */
	short	type;		/* kind of format */
	short	dummy;
} IDBPDFPRG ;

/* cnc_rdpdf_prginf:read program infomation  */
typedef struct odbpdfprg {
	short	year;		/* last date and time */
	short	mon;		/* last date and time */
	short	day;		/* last date and time */
	short	hour;		/* last date and time */
	short	min;		/* last date and time */
	short	sec;		/* last date and time */
	long	size;		/* size */
	unsigned long attr;	/* attribute */
	char	comment[52];/* comment */
	char	o_time[12];	/* machining time stamp */
} ODBPDFPRG ;

/* cnc_rdprotect:read protect status  */
typedef struct odbprtct {
    short       disp;           /* for disp */
    short       edit;           /* for eidt */
    short       encd;           /* for encode */
    short       lock;           /* for program lock */
} ODBPRTCT ;

/* cnc_rdprotect2:read protect status  */
typedef struct odbprtct2 {
    short       disp;           /* for disp */
    short       edit;           /* for edit */
    short       encd;           /* for encode */
    short       lock;           /* for program lock */
    short       output;         /* for output */
    short       dummy;
} ODBPRTCT2 ;

/* cnc_rdpdf_subdirn:read file count the directory has */
typedef struct odbpdfnfil {
	short	dir_num;	/* directory */
	short	file_num;	/* file */
} ODBPDFNFIL ;

/* cncc_wrpdf_attr:change attribute of program file and directory */
typedef struct idbpdftdir {
	unsigned long slct;	/* selection */
	unsigned long attr;	/* data */
} IDBPDFTDIR ;

/* cnc_rddsfile: get file list infomation */
typedef struct in_dsfile {
    char    path[256];  /* path name   */
    long    fnum;       /* file number */
    long    offset;     /* offset */
    short   req_num;    /* request file num */
    short   size_type;  /* size type */
    short   detail;    /* comment type */
    short   dummy;
} IN_DSFILE;

/* cnc_rddsfile: get file list infomation */
typedef struct out_dsinfo {
    short           type;       /* type */
    short           dummy;
    long            fnum;       /* file num */
    long            total;      /* all file num */
    unsigned long   remain_h;   /* remain(high) */
    unsigned long   remain_l;   /* remain(low) */
    char            dir[256];   /* current folder */
} OUT_DSINFO;

/* cnc_rddsfile: get file list infomation */
typedef struct out_dsfile {
    short           year;       /* year */
    short           mon;        /* month */
    short           day;        /* day */
    short           hour;       /* hour */
    short           min;        /* minute */
    short           sec;        /* second */
    long            size;       /* size */
    unsigned long   attr;       /* attribute */
    char            file[36];   /* file name */
    char            info[128];  /* file infomation */
} OUT_DSFILE;

/* cnc_dsfile_req: get file list infomation */
typedef struct in_dsfile_req {
    char            file[256];  /* file name */
    long            fnum;       /* file number */
    long            offset;     /* offset */
    short           detail;     /* comment type */
    unsigned short  option;     /* option */
} ODB_IN_DSFILE_REQ;

/* cnc_dsstat_rdfile: get file list infomation */
typedef struct in_stat_dsfile {
    short   req_num;    /* request file num */
    short   size_type;  /* size type */
} ODB_IN_STAT_DSFILE;

/* cnc_rdembedf_inf:read embedded folder information*/
typedef struct odbembedfinf {
	long	used_page;	/* used capacity */
	long	all_page;	/* all capacity */
} ODBEMBEDFINF ;

/*---------------------------*/
/* CNC: NC file data related */
/*---------------------------*/

/* cnc_rdtofs:read tool offset value */
typedef struct odbtofs {
    short   datano ;    /* data number */
    short   type ;      /* data type */
    long    data ;      /* data */
} ODBTOFS ;

/* cnc_rdtofsr:read tool offset value(area specified) */
/* cnc_wrtofsr:write tool offset value(area specified) */
typedef struct iodbto {
    short   datano_s ;  /* start offset number */
    short   type ;      /* offset type */
    short   datano_e ;  /* end offset number */
    union {
        long    m_ofs[5] ;      /* M Each */
        long    m_ofs_a[5] ;    /* M-A All */
        long    m_ofs_b[10] ;   /* M-B All */
        long    m_ofs_c[20] ;   /* M-C All */
        struct  {
            short   tip ;
            long    data[1] ;
        } m_ofs_at[5] ;         /* M-A All with tip */
        struct  {
            short   tip ;
            long    data[2] ;
        } m_ofs_bt[5] ;         /* M-A All with tip  */
        struct  {
            short   tip ;
            long    data[4] ;
        } m_ofs_ct[5] ;         /* M-A All with tip  */
        short   t_tip[5] ;      /* T Each, 2-byte */
        long    t_ofs[5] ;      /* T Each, 4-byte */
        struct  {
            short   tip ;
            long    data[4] ;
        } t_ofs_a[5] ;          /* T-A All */
        struct {
            short   tip ;
            long    data[8] ;
        } t_ofs_b[5] ;          /* T-B All */
        long    t_ofs_2g[15];   /* T-2nd geometry */
        long    m_ofs_cnr[10];  /* M-CornerR */
        struct  {
                long    data[2];
        } t_ofs_ex[5];		     /* T-Ex-Ofs */
    } u ;   /* In case that the number of data is 5 */
} IODBTO ;

/* cnc_rdzofs:read work zero offset value */
/* cnc_wrzofs:write work zero offset value */
typedef struct iodbzofs {
    short   datano ;            /* offset NO. */
    short   type ;              /* axis number */
    long    data[MAX_AXIS] ;    /* data value */
} IODBZOFS ;

/* cnc_rdzofsr:read work zero offset value(area specified) */
/* cnc_wrzofsr:write work zero offset value(area specified) */
typedef struct iodbzor {
    short   datano_s ;  /* start offset number */
    short   type ;      /* axis number */
    short   datano_e ;  /* end offset number */
    long    data[8*MAX_AXIS] ;  /* offset value */
} IODBZOR ; /* In case that the number of axes is MAX_AXIS, the number of data is 7 */

/* cnc_rdjogmdi:read manual numeric command */
typedef struct iodbjogcmdcode {
    char    adrs;                   /* command address */
    long    num;                    /* command number */
} ODBJOGCMDCODE;
/* cnc_rdjogmdi:read manual numeric command */
typedef struct iodbjogcmdscode {
    char    adrs[4];                /* command address */
    long    num;                    /* command number */
} ODBJOGCMDSCODE;
/* cnc_rdjogmdi:read manual numeric command */
typedef struct iodbjogcmdaxis {
    char    name[4];                /* axis name */
    long    data;                   /* command number */
    long    dec;                    /* Decimal places */
} ODBJOGCMDAXIS;
/* cnc_rdjogmdi:read manual numeric command */
typedef struct odbjogcmd {
    ODBJOGCMDCODE       gcode;          /* G code */
    ODBJOGCMDCODE       mcode;          /* M code */
    ODBJOGCMDCODE       scode;          /* S code */
    ODBJOGCMDCODE       tcode;          /* T code */
    ODBJOGCMDCODE       bcode;          /* B code */
    ODBJOGCMDCODE       padr;           /* address P */
	ODBJOGCMDSCODE		extscode[4];	/* extension S code */
    ODBJOGCMDAXIS       axis[MAX_AXIS]; /* axis */
	long				axis_cnt;		/* axis count */
} ODBJOGCMD;

/* cnc_rdmsptype:read mesured point value */
/* cnc_wrmsptype:write mesured point value */
typedef struct iodbmstp {
    short   datano_s ;  /* start offset number */
    short   dummy ;     /* dummy */
    short   datano_e ;  /* end offset number */
    char    data[7] ;   /* mesured point value */
} IODBMSTP ;

/* cnc_rdparam:read parameter */
/* cnc_wrparam:write parameter */
/* cnc_rdset:read setting data */
/* cnc_wrset:write setting data */
/* cnc_rdparar:read parameter(area specified) */
/* cnc_wrparas:write parameter(plural specified) */
/* cnc_rdsetr:read setting data(area specified) */
/* cnc_wrsets:write setting data(plural specified) */
typedef struct realprm {
        long   prm_val;     /* data of real parameter */
        long   dec_val;     /* decimal point of real parameter */
} REALPRM;

#if !defined (HSSB_LIB) || defined (FS30D) || defined (FS15D) || defined (FS0IDD) /* Ethernet & FS30i & FS15i & FS0i-D */
typedef struct iodbpsd {
    short   datano ;    /* data number */
    short   type ;      /* axis number */
    union {
        char    cdata ;     /* parameter / setting data */
        short   idata ;
        long    ldata ;
        REALPRM rdata ;
        char    cdatas[MAX_AXIS] ;
        short   idatas[MAX_AXIS] ;
        long    ldatas[MAX_AXIS] ;
        REALPRM rdatas[MAX_AXIS] ;
    } u ;
} IODBPSD ;

#else

typedef struct iodbpsd {
    short   datano ;    /* data number */
    short   type ;      /* axis number */
    union {
        char    cdata ;     /* parameter / setting data */
        short   idata ;
        long    ldata ;
        char    cdatas[MAX_AXIS] ;
        short   idatas[MAX_AXIS] ;
        long    ldatas[MAX_AXIS] ;
    } u ;
} IODBPSD ;
#endif

/* cnc_rdparam_ext:read parameters */
/* cnc_rddiag_ext:read diagnosis data */
/* cnc_start_async_wrparam:async parameter write start */
typedef struct iodbprm {
    long    datano ;    /* data number */
    short   type ;      /* data type */
    short   axis ;      /* axis information */
    short   info ;      /* misc information */
    short   unit ;      /* unit information */
    struct {
        long    prm_val ;   /* parameter / setting data */
        long    dec_val ;
    } data[32];
} IODBPRM;

/* cnc_preset_prm:parameter preset */
typedef struct iodbbook {
    short   param_no ;      /* parameter number     */
    char    axis ;          /* data type            */
    char    type ;          /* axis number          */
    union {
        char    cdata ;     /* bit / byte type data */
        short   idata ;     /* word type data       */
        long    ldata ;     /* 2 word type data     */
        REALPRM rdata ;     /* real type data       */
    } u ;
} IODBBOOK;

/* cnc_rdpitchr:read pitch error compensation data(area specified) (incremental)*/
/* cnc_wrpitchr:write pitch error compensation data(area specified)(incremental) */
typedef struct iodbpi {
    short   datano_s ;  /* start pitch number */
    short   dummy ;     /* dummy */
    short   datano_e ;  /* end pitch number */
    char    data[5] ;   /* offset value */
} IODBPI ;  /* In case that the number of data is 5 */

/* cnc_rdoverstore:read overstore command */
typedef struct iodbovmst {
    char    adrs;                   /* command address */
    long    num;                    /* command number */
} IODBOVMST;

/* cnc_rdoverstore:read overstore command */
typedef struct iodbovstr {
    IODBOVMST       mcode;          /* M code */
    IODBOVMST       scode;          /* S code */
    IODBOVMST       tcode;          /* T code */
    IODBOVMST       bcode;          /* B code */
} IODBOVSTR;

#define	MAX_PITCH_GROUP		8
/* cnc_rdpitchblkinfo : read pitch compensation data */
typedef struct tagIODBPITCHBLK {
	short	group_num ;
	struct {
		long	s_no ;
		long	e_no ;
		short	attr ;
	} pginf [MAX_PITCH_GROUP] ;
} IODBPITCHBLK ;

/* cnc_rdvolc : read volumetric compensation data */
/* cnc_wrvolc : write volumetric compensation data */
typedef struct tagODBVOLC {
	long	start_no ;
	long	start_ax ;
	long	end_no ;
	long	end_ax ;
	long	num ;
	char	type ;
	long	data[72] ;
} ODBVOLC ;

/* cnc_rdrotvolc : read rotate volumetric compensation data */
/* cnc_wrrotvolc : write rotate volumetric compensation data */
/* cnc_wrrotvolc2 : write rotate volumetric compensation data (2) */
typedef struct iodbrotvolc {
     long   lin[3] ;
     long   rot[3] ;
} IODBROTVOLC ;

/* cnc_rdvolccomp : get volumetric compensation amount of axes */
/* cnc_dvpunchvolc : punch volumetric compensation data to device */
/* cnc_dvreadvolc : read volumetric compensation data to device */
typedef struct tagODBVOLCOMP {
	long	comp[5] ;
} ODBVOLCOMP ;

/* cnc_rdmacro:read custom macro variable */
typedef struct odbm {
    short   datano ;    /* variable number */
    short   dummy ;     /* dummy */
    long    mcr_val ;   /* macro variable */
    short   dec_val ;   /* decimal point */
} ODBM ;

/* cnc_rdmacro3:read custom macro variable (3)*/
typedef struct odbm3 {
    long    datano ;    /* variable number */
    long    mcr_val ;   /* macro variable */
    short   dec_val ;   /* decimal point */
} ODBM3 ;

/* cnc_rdmacror:read custom macro variables(area specified) */
/* cnc_wrmacror:write custom macro variables(area specified) */
typedef struct iodbmr {
    short   datano_s ;  /* start macro number */
    short   dummy ;     /* dummy */
    short   datano_e ;  /* end macro number */
    struct {
        long    mcr_val ;   /* macro variable */
        short   dec_val ;   /* decimal point */
    } data[5] ;
} IODBMR ;  /* In case that the number of data is 5 */

/* cnc_rdmacror2_name:read custom macro names(area specified) */
typedef struct iodbmnr {
    double  mcr_val ;   /* macro variable */
    char    name[16] ;  /* macro name */
} IODBMRN ;  /* In case that the number of data is 50 */

/* cnc_rdmacror3:read custom macro names(area specified) */
typedef struct iodbmnr3 {
    double  mcr_val ;   /* macro variable */
    char    name[32] ;  /* macro name */
} IODBMRN3 ;  /* In case that the number of data is 50 */

/* cnc_rdmacror4:read custom macro names(area specified) */
typedef struct iodbmnr4 {
    double  mcr_val ;   /* macro variable */
    char    name[64] ;  /* macro name */
} IODBMRN4 ;

/* cnc_rdpmacro:read P code macro variable */
typedef struct odbpm {
    long    datano ;    /* variable number */
    short   dummy ;     /* dummy */
    long    mcr_val ;   /* macro variable */
    short   dec_val ;   /* decimal point */
} ODBPM ;

/* cnc_rdpmacror:read P code macro variables(area specified) */
/* cnc_wrpmacror:write P code macro variables(area specified) */
typedef struct iodbpr {
    long    datano_s ;  /* start macro number */
    short   dummy ;     /* dummy */
    long    datano_e ;  /* end macro number */
    struct {
        long    mcr_val ;   /* macro variable */
        short   dec_val ;   /* decimal point */
    } data[5] ;
} IODBPR ;  /* In case that the number of data is 5 */

/* cnc_rdtofsinfo:read tool offset information */
typedef struct odbtlinf {
    short   ofs_type;
    short   use_no;
} ODBTLINF;

/* cnc_rdtofsinfo2:read tool offset information(2) */
typedef struct odbtlinf2 {
    short   ofs_type;
    short   use_no;
    short   ofs_enable;
} ODBTLINF2;

/* cnc_rdmacroinfo:read custom macro variable information */
typedef struct odbmvinf {
    short   use_no1;
    short   use_no2;
} ODBMVINF;

/* cnc_rdpmacroinfo:read P code macro variable information */
#if !defined (FS15BD)
typedef struct odbpminf {
    short       use_no1;
#ifdef PCD_UWORD
    unsigned short  use_no2;
#else
    short       use_no2;
#endif
    short       v2_type;
} ODBPMINF;
#else
typedef struct odbpminf {
    short       use_no1;
#ifdef PCD_UWORD
    unsigned short  use_no2;
#else
    short       use_no2;
#endif
    short       v2_type1;
    short       v2_type2;
} ODBPMINF;
#endif

/* cnc_rdpmacroinfo2:read P code macro variable information (2) */
typedef struct odbpminf2 {
    long    use_no1;
    long    use_no2;
    long    use_no20;
    short   v1_type;
    short   v2_type;
    short   v20_type;
} ODBPMINF2;

/* cnc_rdpmacroinfo3:read P code macro variable information (3)*/
typedef struct odbpminf3 {
    short         use_no1;
    unsigned long use_no2;
    short         v1_type;
    short         v2_type;
} ODBPMINF3;

/* cnc_rdpmacvalflag:read P code macro variable flag */
typedef struct odbpmvalflg {
    short       exe_type;
    short       aux_type;
    short       tlk_type;
} ODBPMVALFLG;

/* cnc_tofs_rnge:read validity of tool offset */
/* cnc_zofs_rnge:read validity of work zero offset */
/* cnc_wksft_rnge:read validity of work shift value */
typedef struct odbdatrng {
	long	data_min;	/* lower limit */
	long	data_max;	/* upper limit */
	long	status;		/* status of setting */
} ODBDATRNG ;

/* cnc_rdholmes:read work zero point measurement hole measured value */
typedef struct {
	char	mes_axis[2];
	char	mes_parl[2];
	long	mes_val1[2];/* #1 */
	long	mes_dp1[2];
	long	mes_val2[2];/* #2 */
	long	mes_dp2[2];
	long	mes_val3[2];/* #3 */
	long	mes_dp3[2];
} ODBHOLDATA;

typedef struct  hol64 {
    double mes_val1[2] ; /* #1 */
    long   mes_dp1[2]  ;
    double mes_val2[2] ; /* #2 */
    long   mes_dp2[2]  ;
    double mes_val3[2] ; /* #3 */
    long   mes_dp3[2]  ;
    char   mes_axis[2] ; /* axis */
    char   mes_parl[2] ;
} ODBHOLDATA64 ;

/* cnc_rdtldata:read work zero point measurement TL value */
typedef struct  tlmsinf {
	long	t;			/* t data */
	long	m;			/* m data */
	long	hm;			/* hm data */
	long	hm_dp;		/* hm_dp */
	long	tlofs_no;	/* offset num */
} ODBTLMSINF ;

/* cnc_rdtlmsinfo:read tool length measurement information */
typedef struct	tldata {
	long	tl;			/* tl data */
	long	tl_dp;		/* tl dp */
} ODBTLDATA ;

/* cnc_rdhsprminfo:read the information for function cnc_rdhsparam() */
typedef struct hspinfo {
	char prminfo[8][16];
} HSPINFO;

/* cnc_rdhsparam:read parameters at the high speed */
#ifndef CNC_PPC
#if !defined (HSSB_LIB) || defined (FS30D) || defined (FS15D) || defined (FS0IDD) /* Ethernet & FS30i & FS15i & FS0i-D */
typedef union hspdata {
	char    cdata[MAX_AXIS];
	short   idata[MAX_AXIS];
	long    ldata[MAX_AXIS];
        REALPRM rdata[MAX_AXIS];
} HSPDATA;

#else

typedef union hspdata {
	char    cdata[MAX_AXIS];
	short   idata[MAX_AXIS];
	long    ldata[MAX_AXIS];
} HSPDATA;
#endif
#endif

/* cnc_rdhsparam:read parameters at the high speed */
typedef union hspdatam {
	char    cdata[32];
	short   idata[32];
	long    ldata[32];
        REALPRM rdata[32];
} HSPDATAM;

/* cnc_rdfixoffs:read rotary table dynamic fixture offset */
/* cnc_wrfixoffs:write rotary table dynamic fixture offset */
typedef struct odbfofs {
    long    mcrval;
    short   decval;
} ODBFOFS;

/* cnc_rdcdslctprm:read the machining condition parameters */
typedef struct iodbctpr {
    struct {
        long    acc_bipl[MAX_AXIS];
        long    acc_chg_time;
        long    jerk_acc_diff[MAX_AXIS];
        long    jerk_acc_diff_lin[MAX_AXIS];
        char    jerk_acc_ratio;
        long    max_acc[MAX_AXIS];
        short   t_con_aipl[MAX_AXIS];
        long    corner_feed_diff[MAX_AXIS];
        long    max_cut_fdrate[MAX_AXIS];
    } data;
    struct {
        short   datano;
        short   type;
        union {
            char    cdata;
            short   idata;
            long    ldata;
            char    cdatas[MAX_AXIS];
            short   idatas[MAX_AXIS];
            long    ldatas[MAX_AXIS];
        } u;
    } prm[2];
} IODBCTPR;

/* cnc_rdcdslctprmm:read the machining condition parameters */
typedef struct iodbctprm {
	union {
		// Series 16i/18i
		struct {
			long    acc_bipl[8];
			long    acc_chg_time;
			long    jerk_acc_diff[8];
			long    jerk_acc_diff_lin[8];
			char    jerk_acc_ratio;
			long    max_acc[8];
			short   t_con_aipl[8];
			long    corner_feed_diff[8];
			long    max_cut_fdrate[8];
		} data_160;

		// Series 30i/31i/32i
		struct {
			REALPRM acc_bipl[32];
			REALPRM acc_chg_time;
			REALPRM jerk_acc_diff[32];
			REALPRM jerk_acc_diff_lin[32];
			char    jerk_acc_ratio;
			REALPRM max_acc[32];
			short   t_con_aipl[32];
			REALPRM corner_feed_diff[32];
			REALPRM max_cut_fdrate[32];
		} data_30i;
	} data;
	// Series 16i/18i/30i/31i/32i
	struct {
		short   datano;
		short   type;
		union {
			char    cdata;
			short   idata;
			long    ldata;
			REALPRM rdata;
			char    cdatas[32];
			short   idatas[32];
			long    ldatas[32];
			REALPRM rdatas[32];
		} u;
	} prm[2];
} IODBCTPRM;

/* cnc_rdtlgeomsize:read tool geom size data */
/* cnc_wrtlgeomsize:write tool geom size data */
typedef struct {
    long    data1;          /* tool data1   */
    long    data2;          /* tool data2   */
    char    tooltype;       /* tool kind    */
    char    install;        /* attach       */
    char    toolname[9];    /* tool name    */
    char    dummy;          /* dummy        */
} IODBTLGS;

/* cnc_rdtlgeomsize_ext:read extended tool geom size data */
/* cnc_wrtlgeomsize_ext:write extended tool geom size data */
typedef struct iodbtlgsext {
    long    data1;          /* tool data1   */
    long    data2;          /* tool data2   */
    long    data3;          /* tool data3   */
    long    data4;          /* tool data4   */
    char    tooltype;       /* tool kind    */
    char    install;        /* attach       */
    char    holder;         /* holder       */
    char    toolname[9];    /* tool name    */
} IODBTLGSEXT;

/* cnc_rdtlgeomsize_ext2:read extended tool geom size data */
/* cnc_wrtlgeomsize_ext2:write extended tool geom size data */
typedef struct iodbtlgsext2 {
    long    data1;          /* tool data1   */
    long    data2;          /* tool data2   */
    long    data3;          /* tool data3   */
    long    data4;          /* tool data4   */
    long    data5;          /* tool data5   */
    long    data6;          /* tool data6   */
    long    data7;          /* tool data7   */
    long    data8;          /* tool data8   */
    long    data9;          /* tool data9   */
    long    data10;         /* tool data10  */
    char    tooltype;       /* tool kind    */
    char    install;        /* attach       */
    char    holder;         /* holder       */
    char    toolname[9];    /* tool name    */
} IODBTLGSEXT2;

/*----------------------------------------*/
/* CNC: Tool life management data related */
/*----------------------------------------*/

/* cnc_rdgrpid:read tool life management data(tool group number) */
typedef struct odbtlife1 {
    short   dummy ; /* dummy */
    short   type ;  /* data type */
    long    data ;  /* data */
} ODBTLIFE1 ;

/* cnc_rdngrp:read tool life management data(number of tool groups) */
typedef struct odbtlife2 {
    short   dummy[2] ;  /* dummy */
    long    data ;      /* data */
} ODBTLIFE2 ;

/* cnc_rdntool:read tool life management data(number of tools) */
/* cnc_rdlife:read tool life management data(tool life) */
/* cnc_rdcount:read tool life management data(tool lift counter) */
typedef struct odbtlife3 {
    short   datano ;    /* data number */
    short   dummy ;     /* dummy */
    long    data ;      /* data */
} ODBTLIFE3 ;

/* cnc_rd1length:read tool life management data(tool length number-1) */
/* cnc_rd2length:read tool life management data(tool length number-2) */
/* cnc_rd1radius:read tool life management data(cutter compensation no.-1) */
/* cnc_rd2radius:read tool life management data(cutter compensation no.-2) */
/* cnc_t1info:read tool life management data(tool information-1) */
/* cnc_t2info:read tool life management data(tool information-2) */
/* cnc_toolnum:read tool life management data(tool number) */
typedef struct odbtlife4 {
    short   datano ;    /* data number */
    short   type ;      /* data type */
    long    data ;      /* data */
} ODBTLIFE4 ;

/* cnc_rdgrpid2:read tool life management data(tool group number) 2 */
typedef struct odbtlife5 {
    long    dummy ; /* dummy */
    long    type ;  /* data type */
    long    data ;  /* data */
} ODBTLIFE5 ;

/* cnc_rdtoolrng:read tool life management data(tool number, tool life, tool life counter)(area specified) */
typedef struct iodbtr {
    short   datano_s ;  /* start group number */
    short   dummy ;     /* dummy */
    short   datano_e ;  /* end group number */
    struct {
        long    ntool ;     /* tool number */
        long    life ;      /* tool life */
        long    count ;     /* tool life counter */
    } data[5] ;
} IODBTR ;  /* In case that the number of data is 5 */

/* cnc_rdtoolgrp:read tool life management data(all data within group) */
typedef struct odbtg {
    short   grp_num ;   /* start group number */
    short   dummy[2] ;  /* dummy */
    long    ntool ;     /* tool number */
    long    life ;      /* tool life */
    long    count ;     /* tool life counter */
    struct {
        long    tuse_num ;      /* tool number */
        long    tool_num ;      /* tool life */
        long    length_num ;    /* tool life counter */
        long    radius_num ;    /* tool life counter */
        long    tinfo ;         /* tool life counter */
    } data[5] ;
} ODBTG ;   /* In case that the number of data is 5 */

/* cnc_wrcountr:write tool life management data(tool life counter) (area specified) */
typedef struct idbwrc {
    short   datano_s ;  /* start group number */
    short   dummy ;     /* dummy */
    short   datano_e ;  /* end group number */
    struct {
        long    dummy[2] ;  /* dummy */
        long    count ;     /* tool life counter */
    } data[5] ;
} IDBWRC ;  /* In case that the number of data is 5 */

/* cnc_rdusegrpid:read tool life management data(used tool group number) */
typedef struct odbusegr {
    short   datano; /* dummy */
    short   type;   /* dummy */
    long    next;   /* next use group number */
    long    use;    /* using group number */
    long    slct;   /* selecting group number */
} ODBUSEGR;

/* cnc_rdmaxgrp:read tool life management data(max. number of tool groups) */
/* cnc_rdmaxtool:read tool life management data(maximum number of tool within group) */
typedef struct odblfno {
    short   datano; /* dummy */
    short   type;   /* dummy */
    short   data;   /* number of data */
} ODBLFNO;

/* cnc_rdusetlno:read tool life management data(used tool no within group) */
typedef struct odbtluse {
    short   s_grp;      /* start group number */
    short   dummy;      /* dummy */
    short   e_grp;      /* end group number */
    long    data[5];    /* tool using number */
} ODBTLUSE; /* In case that the number of group is 5 */

/* cnc_rd1tlifedata:read tool life management data(tool data1) */
/* cnc_rd2tlifedata:read tool life management data(tool data2) */
/* cnc_wr1tlifedata:write tool life management data(tool data1) */
/* cnc_wr2tlifedata:write tool life management data(tool data2) */
typedef struct iodbtd {
    short   datano;     /* tool group number */
    short   type;       /* tool using number */
    long    tool_num;   /* tool number */
    long    h_code;     /* H code */
    long    d_code;     /* D code */
    long    tool_inf;   /* tool information */
} IODBTD;

/* cnc_rd1tlifedat2:read tool life management data(tool data1) 2 */
/* cnc_wr1tlifedat2:write tool life management data(tool data1) 2 */
typedef struct iodbtd2 {
    short   datano;     /* tool group number */
    short   dummy;      /* dummy */
    long    type;       /* tool using number */
    long    tool_num;   /* tool number */
    long    h_code;     /* H code */
    long    d_code;     /* D code */
    long    tool_inf;   /* tool information */
} IODBTD2;

/* cnc_rdgrpinfo:read tool life management data(tool group information) */
/* cnc_wrgrpinfo:write tool life management data(tool group information) */
typedef struct iodbtgi {
    short   s_grp;  /* start group number */
    short   dummy;  /* dummy */
    short   e_grp;  /* end group number */
    struct {
        long    n_tool;         /* number of tool */
        long    count_value;    /* tool life */
        long    counter;        /* tool life counter */
        long    count_type;     /* tool life counter type */
    } data[5];
} IODBTGI;  /* In case that the number of group is 5 */

/* cnc_rdgrpinfo2:read tool life management data(tool group information 2) */
/* cnc_wrgrpinfo2:write tool life management data(tool group information 2) */
typedef struct iodbtgi2 {
    short   s_grp;              /* start group number */
    short   dummy;              /* dummy */
    short   e_grp;              /* end group number */
    long    opt_grpno[5];       /* optional group number of tool */
} IODBTGI2;  /* In case that the number of group is 5 */

/* cnc_rdgrpinfo3:read tool life management data(tool group information 3) */
/* cnc_wrgrpinfo3:write tool life management data(tool group information 3) */
typedef struct iodbtgi3 {
    short   s_grp;              /* start group number */
    short   dummy;              /* dummy */
    short   e_grp;              /* end group number */
    long    life_rest[5];       /* tool life rest count */
} IODBTGI3;  /* In case that the number of group is 5 */

/* cnc_rdgrpinfo4:read tool life management data(tool group information 4) */
/* cnc_wrgrpinfo4:write tool life management data(tool group information 4) */
typedef struct iodbtgi4 {
    short   grp_no;             /* group number */
	long	n_tool;				/* 				*/
	long	count_value;		/*				*/
	long	counter;			/*				*/
	long	count_type;			/*				*/
	long	opt_grpno;			/*				*/
	long	life_rest;			/*				*/
} IODBTGI4;

/* cnc_instlifedt:insert tool life management data(tool data) */
typedef struct idbitd {
    short   datano; /* tool group number */
    short   type;   /* tool using number */
    long    data;   /* tool number */
} IDBITD;

/* cnc_instlifedt:insert tool life management data(tool data) */
typedef struct idbitd2 {
    short   datano; /* tool group number */
    long    type;   /* tool using number */
    long    data;   /* tool number */
} IDBITD2;

/* cnc_rdtlinfo:read tool life management data */
typedef struct odbtlinfo {
    long    max_group;  /* maximum number of tool groups */
    long    max_tool;   /* maximum number of tool within group */
    long    max_minute; /* maximum number of life count (minutes) */
    long    max_cycle;  /* maximum number of life count (cycles) */
} ODBTLINFO;

/* cnc_rdtlusegrp:read tool life management data(used tool group number) */
typedef struct odbusegrp {
    long    next;       /* next use group number */
    long    use;        /* using group number */
    long    slct;       /* selecting group number */
    long    opt_next;   /* next use optional group number */
    long    opt_use;    /* using optional group number */
    long    opt_slct;   /* selecting optional group number */
} ODBUSEGRP;

/* cnc_rdtlgrp:read tool life management data(tool group information 2) */
typedef struct iodbtlgrp {
    long    ntool;      /* number of all tool */
    long    nfree;      /* number of free tool */
    long    life;       /* tool life */
    long    count;      /* tool life counter */
    long    use_tool;   /* using tool number */
    long    opt_grpno;  /* optional group number */
    long    life_rest;  /* tool life rest count */
    short   rest_sig;   /* tool life rest signal */
    short   count_type; /* tool life counter type */
} IODBTLGRP;

/* cnc_rdtltool:read tool life management data (tool data1) */
typedef struct iodbtltool {
    long    tool_num;   /* tool number */
    long    h_code;     /* H code */
    long    d_code;     /* D code */
    long    tool_inf;   /* tool information */
} IODBTLTOOL;

/* cnc_rdtltool:read tool life management data (tool data1) */
typedef struct exgrp {
    long    grp_no;     /* group number */
    long    opt_grpno;  /* optional group number */
} ODBEXGP;


/*-----------------------------------*/
/* CNC: Tool management data related */
/*-----------------------------------*/

/* cnc_regtool:new registration of tool management data */
/* cnc_rdtool:lead of tool management data */
/* cnc_wrtool:write of tool management data */
typedef struct  iodbtlmng {
    long T_code;
    long life_count;
    long max_life;
    long rest_life;
    unsigned char  life_stat;
    unsigned char  cust_bits;
    unsigned short tool_info;
    short H_code;
    short D_code;
    long spindle_speed;
    long feedrate;
    short magazine;
    short pot;
    short G_code;
    short W_code;
    short gno;
	short grp;
	short edge;
    short org_magazine;
    short org_pot;
	unsigned char edge_num;
	char reserve_c;
	long reserved[2];
    long custom1;
    long custom2;
    long custom3;
    long custom4;
    long custom5;
    long custom6;
    long custom7;
    long custom8;
    long custom9;
    long custom10;
    long custom11;
    long custom12;
    long custom13;
    long custom14;
    long custom15;
    long custom16;
    long custom17;
    long custom18;
    long custom19;
    long custom20;
} IODBTLMNG;

typedef struct  iodbtlmng_f2 {
    long T_code;
    long life_count;
    long max_life;
    long rest_life;
    unsigned char  life_stat;
    unsigned char  cust_bits;
    unsigned short tool_info;
    short H_code;
    short D_code;
    long spindle_speed;
    long feedrate;
    short magazine;
    short pot;
    short G_code;
    short W_code;
    short gno;
	short grp;
	short edge;
    short org_magazine;
    short org_pot;
    unsigned char edge_num;
    char reserve_c;
	long reserved[2];
    long custom1;
    long custom2;
    long custom3;
    long custom4;
    long custom5;
    long custom6;
    long custom7;
    long custom8;
    long custom9;
    long custom10;
    long custom11;
    long custom12;
    long custom13;
    long custom14;
    long custom15;
    long custom16;
    long custom17;
    long custom18;
    long custom19;
    long custom20;
    long custom21;
    long custom22;
    long custom23;
    long custom24;
    long custom25;
    long custom26;
    long custom27;
    long custom28;
    long custom29;
    long custom30;
    long custom31;
    long custom32;
    long custom33;
    long custom34;
    long custom35;
    long custom36;
    long custom37;
    long custom38;
    long custom39;
    long custom40;
} IODBTLMNG_F2;

/* cnc_wrtool2:write of individual data of tool management data */
typedef struct  idbtlm {
    short data_id;
    union {
        unsigned char data1;
        short         data2;
        long          data4;
    } item;
} IDBTLM;

/* cnc_rdtool2:read data */
typedef struct  iodbtlm2 {
    short number;
    short reserve;
    union {
        unsigned char data1;
        short         data2;
        long          data4;
    } item;
} IODBTLM2;

/* cnc_regmagazine:new registration of magazine management data */
/* cnc_rdmagazine:lead of magazine management data */
typedef struct  iodbtlmag {
    short magazine;
    short pot;
    short tool_index;
} IODBTLMAG;

/* cnc_delmagazine:deletion of magazine management data */
typedef struct  iodbtlmag2 {
    short magazine;
    short pot;
} IODBTLMAG2;

/* cnc_rdspdlwaitname */
typedef struct  iodbtlname {
    struct {
        char sp_pos1[5] ;
        char sp_pos2[5] ;
        char sp_pos3[5] ;
        char sp_pos4[5] ;
    } sp_name ;
    struct {
        char wt_pos1[5] ;
        char wt_pos2[5] ;
        char wt_pos3[5] ;
        char wt_pos4[5] ;
    } wt_name ;
} IODBTLSPWTNAME ;

typedef struct  tlmngtlgeom {
    unsigned char l_pot_num;
    unsigned char r_pot_num;
    unsigned char u_pot_num;
    unsigned char d_pot_num;
    unsigned char tl_geom_num;
} IODBTLGEOM;

typedef struct  iodbtlintf {
    short inf_tool[2];
} IODBTLINTF;

typedef struct  iodbtllf {
    long T_code_sum;
    long life_count_sum;
    long rem_life_sum;
    long max_life_sum;
    long notice_life_sum;
    short tools_sum;
    char notice_stat_sum;
    char count_type_sum;
} IODBTLLF;

typedef struct  iodbtl_retype {
	unsigned char type;
	unsigned char data_type;
	char renew;
	char reserve;
}IODBTL_RDTYPE;

typedef struct  iodbtllfd {
	short order;
    short tool_num;
    long life_count;
    long rem_life;
    long max_life;
    long notice_life;
    char life_stat;
    char count_type;
	short reserve;
} IODBTLLFD;

typedef struct  iodbtlmgr_check {
    long T_code;
	short tool_num;
	short reserve;
} IODBTLMGR_CHECK;

typedef struct  iodbtool_date{
	short year;
	short mon;
	short day;
	short hour;
	short min;
	short sec;
}IODBTOOL_DATE;

typedef struct  iodbtool_inhis{
    short tool_no;
	short reserve;
	IODBTOOL_DATE	date;
	IODBTLMNG_F2	tool_f2;
}IODBTOOL_INHIS;

typedef struct  iodbtool_outhis{
    short tool_no;
	short cause;
	IODBTOOL_DATE	date;
	IODBTLMNG_F2	tool_f2;
}IODBTOOL_OUTHIS;

typedef struct  iodbtool_causenme {
	char cause1[8] ;
	char cause2[8] ;
	char cause3[8] ;
	char cause4[8] ;
	char cause5[8] ;
} IODBTOOL_CAUSENME ;

/* Tlmgr sort function */
typedef struct  iodbtlmng_sort {
    short      tl_num;
    short      reserve;
    IODBTLMNG_F2 data;
} IODBTLMNG_SORT;

/* cnc_rdmag_property:read of magazineproperty data */
/* cnc_wrmag_property:write of magazineproperty data */
typedef struct  iodbmagprty {
	short         mag ;	
	short         reserve_s ;	
	unsigned char mag_info ;	
	char          reserve[3] ;
	short         mt_line ;	
	short         mt_row ;	
	long          cstm[4] ;	
} IODBMAGPRTY;

/* cnc_rdpot_property:read of potproperty data */
/* cnc_wrpot_property:write of potproperty data */
typedef struct  iodbpotprty {
	short           tool_no ;	
	short           pot_type ;	
	unsigned char   pot_info1 ;	
	unsigned char   pot_info2 ;	
	char            reserve[2] ;
	long            cstm[10] ;	
} IODBPOTPRTY;

/* cnc_delmag_property:delete of magazineproperty data */
typedef struct  iodbmagprty2 {
	short           mag ;	
	short           reserve ;	
} IODBMAGPRTY2;

/* cnc_magazinesrch:Search  magazine management data */
/* cnc_toolsrch    :Search  tool management data */
typedef struct  idbtlm_srchdt {
	IDBTLM	id_info;
	short	srch_cond;
	short	add_cond;
} IDBTLM_SRCHDT;

typedef struct  iodbtlmag_srchinfo {
    IODBTLMAG2	startInfo;
    IODBTLMAG	result;	
} IODBTLMAG_SRCHINFO;

/* cnc_tool_srh_free_min_num:Serch free number */
typedef struct  odbtl_free_num {
    short  edge_gp;           /* edge group number  */
    short  ofs_h;             /* ofset number (H)   */
    short  ofs_d;             /* ofset number (D)   */
    short  ofs_g;             /* ofset number (G)   */
    short  ofs_w;             /* ofset number (W)   */
    short  reserve[3];       /* reserve            */
} ODBTL_FREE_NUM;

typedef struct  iodbtlmng_mu_edge_data {
    long life_count;            /*$ tool life count $*/
    long max_life;              /*$ max tool life $*/
    long rest_life;             /*$ tool notice life $*/
    unsigned char  life_stat;   /*$ tool life status $*/
    unsigned char  cust_bits;   /*$ customize bit $*/
    short reserve_s;            /*$ reserve $*/
    short H_code;               /*$ H code $*/
    short D_code;               /*$ D code $*/
    long spindle_speed;         /*$ spindle speed $*/
    long feedrate;              /*$ feedrate speed $*/
    short G_code;               /*$ TG code $*/
    short W_code;               /*$ TW code $*/
    long custom1;               /*$ customize 1 $*/
    long custom2;               /*$ customize 2 $*/
    long custom3;               /*$ customize 3 $*/
    long custom4;               /*$ customize 4 $*/
} IODBTLMNG_MU_EDGE_DATA;

typedef struct  odbtlmng_edge_data {
  union {
    IODBTLMNG_MU_EDGE_DATA edge;/*$ edge data $*/
    IODBTLLF               tllf;/*$ tool life sum edge data $*/
    IODBTLLFD             tllfd;/*$ tool life sum detile edge data $*/
  } u ;
} ODBTLMNG_EDGE_DATA;

typedef struct  odbtlmng_mu_edge {
    short data_no;                      /*$ data no $*/
    short edge_no;                      /*$ edge no $*/
    ODBTLMNG_EDGE_DATA edge_data;   /*$ edge data $*/
} ODBTLMNG_MU_EDGE;

typedef struct  iodbtlmgr_edg {
    short data_no;      /*$ data no $*/
	short edge_no;      /*$ edge no $*/
} IODBTLMGR_EDG;

typedef struct  idbtlmgr_add_info {
   long  dsp_info;      /*$ dsp info $*/
   short data_kind;     /*$ data kind $*/
} IDBTLMGR_ADD_INFO;

typedef struct  iodbtlmgr_page {
    union {
        IODBTLMGR_EDG edg;      /*$ data no and edge no $*/
        struct {                
            IODBTLMGR_EDG s_edg;/*$ start data no and start edge no $*/
            IODBTLMGR_EDG e_edg;/*$ end data no and end edge no $*/
        } page;
    } info;
} IODBTLMGR_PAGE;

/*-------------------------------------*/
/* CNC: Operation history data related */
/*-------------------------------------*/

/* cnc_rdophistry:read operation history data */
typedef struct odbhis {
    unsigned short  s_no;   /* start number */
    short   type;           /* dummy */
    unsigned short  e_no;   /* end number */
    union {
        struct {
            short   rec_type;   /* record type */
            short   alm_grp;    /* alarm group */
            short   alm_no;     /* alarm number */
            char    axis_no;    /* axis number */
            char    dummy;
        } rec_alm;
        struct {
            short   rec_type;   /* record type */
            char    key_code;   /* key code */
            char    pw_flag;    /* power on flag */
            char    dummy[4];
        } rec_mdi;
        struct {
            short   rec_type;   /* record type */
            char    sig_name;   /* signal name */
            char    sig_old;    /* old signal bit pattern */
            char    sig_new;    /* new signal bit pattern */
            char    dummy;
            short   sig_no;     /* signal number */
        } rec_sgn;
        struct {
            short   rec_type;   /* record type */
            char    year;       /* year */
            char    month;      /* month */
            char    day;        /* day */
            char    pw_flag;    /* power on flag */
            char    dummy[2];
        } rec_date;
        struct {
            short   rec_type;   /* record flag */
            char    hour;       /* hour */
            char    minute;     /* minute */
            char    second;     /* second */
            char    pw_flag;    /* power on flag */
            char    dummy[2];
        } rec_time;
    } data[10];
} ODBHIS;   /* In case that the number of data is 10 */

/* cnc_rdophistry2:read operation history data */
typedef struct odbophis {
    short   rec_len;    /* length */
    short   rec_type;   /* record type */
    union {
        struct {
            char    key_code;   /* key code */
            char    pw_flag;    /* power on flag */
            short   dummy;
        } rec_mdi;
        struct {
            short   sig_name;   /* signal name */
            short   sig_no;     /* signal number */
            char    sig_old;    /* old signal bit pattern */
            char    sig_new;    /* new signal bit pattern */
            short   dummy;
        } rec_sgn;
        struct {
            short   alm_grp;    /* alarm group */
            short   alm_no;     /* alarm number */
            short   axis_no;    /* axis number */
            short   year;       /* year */
            short   month;      /* month */
            short   day;        /* day */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   dummy;
        } rec_alm;
        struct {
            short   evnt_type;  /* event type */
            short   year;       /* year */
            short   month;      /* month */
            short   day;        /* day */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   dummy;
        } rec_date;
    } u;
} ODBOPHIS;

/* cnc_rdophistry3:read operation history data */
typedef struct odbophis3 {
    short   rec_len;    /* length */
    short   rec_type;   /* record type */
    union {
        struct {
            char    key_code;   /* key code */
            char    pw_flag;    /* power on flag */
            short   pth_no;     /* path index */
        } rec_mdi;
        struct {
            short   sig_name;   /* signal name */
            short   sig_no;     /* signal number */
            char    sig_old;    /* old signal bit pattern */
            char    sig_new;    /* new signal bit pattern */
            short   pmc_no;     /* pmc index */
        } rec_sgn;
        struct {
            short   alm_grp;    /* alarm group */
            short   alm_no;     /* alarm number */
            short   axis_no;    /* axis number */
            short   year;       /* year */
            short   month;      /* month */
            short   day;        /* day */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   pth_no;     /* path index */
        } rec_alm;
        struct {
            short   evnt_type;  /* event type */
            short   year;       /* year */
            short   month;      /* month */
            short   day;        /* day */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   dummy;
        } rec_date;
    } u;
} ODBOPHIS3;

/* cnc_rdophistry4:read operation history data */
typedef struct odbophis4 {/*--*/
    short   rec_len;    /* length */
    short   rec_type;   /* record type */
    union {
        struct {
            char    key_code;   /* key code */
            char    pw_flag;    /* power on flag */
            short   pth_no;     /* path index */
            short   ex_flag;    /* kxternal key flag */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
        } rec_mdi;              /* MDI */
        struct {
            short   sig_name;   /* signal name */
            short   sig_no;     /* signal number */
            char    sig_old;    /* old signal bit pattern */
            char    sig_new;    /* new signal bit pattern */
            short   pmc_no;     /* pmc index */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   dummy;
        } rec_sgn;              /* SIGNAL */
        struct {
            short   alm_grp;    /* alarm group */
            short   alm_no;     /* alarm number */
            short   axis_no;    /* axis number */
            short   year;       /* year */
            short   month;      /* month */
            short   day;        /* day */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   pth_no;     /* path index */
#if 0
            short   sys_alm;    /* sys alarm */
            short   dsp_flg;    /* message dsp flag */
            short   axis_num;   /* axis num */
#endif
        } rec_alm;              /* ALARM */
        struct {
            short   evnt_type;  /* event type */
            short   year;       /* year */
            short   month;      /* month */
            short   day;        /* day */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   dummy;
        } rec_date;             /* DATE */
        struct {
            short   alm_grp;    /* alarm group */
            short   alm_no;     /* alarm number */
            short   axis_no;    /* axis number */
            short   year;       /* year */
            short   month;      /* month */
            short   day;        /* day */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   pth_no;     /* path index */
            short   sys_alm;    /* sys alarm */
            short   dsp_flg;    /* message dsp flag */
            short   axis_num;   /* axis num */
            short   dummy1;
            long    g_modal[10];/* G code Modal */
            char    g_dp[10];   /* #7:1 Block */
                                /* #6-#0 dp*/
            short   dummy2;
            long    a_modal[10];/* B,D,E,F,H,M,N,O,S,T code Modal */
            char    a_dp[10];   /* #7:1 Block */
                                /* #6-#0 dp*/
            short   dummy3;
            long    abs_pos[32];/* Abs pos */
            char    abs_dp[32]; /* Abs dp  */
            long    mcn_pos[32];/* Mcn pos */
            char    mcn_dp[32]; /* Mcn dp  */
        } rec_ial;              /* INFO ALARM */
        struct {
            short   alm_grp;    /* alarm group */
            short   alm_no;     /* alarm number */
            short   axis_no;    /* axis number */
            short   year;       /* year */
            short   month;      /* month */
            short   day;        /* day */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   pth_no;     /* path index */
            short   sys_alm;    /* sys alarm */
            short   dsp_flg;    /* message dsp flag */
            short   axis_num;   /* axis num */
volatile    char    alm_msg[64];/* alarm message */
            short   dummy1;
            long    g_modal[10];/* G code Modal */
            char    g_dp[10];   /* #7:1 Block */
                                /* #6-#0 dp*/
            short   dummy2;
            long    a_modal[10];/* B,D,E,F,H,M,N,O,S,T code Modal */
            char    a_dp[10];   /* #7:1 Block */
                                /* #6-#0 dp*/
            short   dummy3;
            long    abs_pos[32];/* Abs pos */
            char    abs_dp[32]; /* Abs dp  */
            long    mcn_pos[32];/* Mcn pos */
            char    mcn_dp[32]; /* Mcn dp  */
        } rec_mal;              /* MSG ALARM */
        struct {/*opm*/
            short   dsp_flg;  /* Dysplay flag(ON/OFF) */
            short   om_no;    /* message number */
            short   year;       /* year */
            short   month;      /* month */
            short   day;        /* day */
            short   hour;       /* Hour */
            short   minute;     /* Minute */
            short   second;     /* Second */
            char    ope_msg[256];/* Messege */
        } rec_opm;              /* EXT OPMESSAGE */
        struct {
            short   ofs_grp;    /* Tool offset group */
            short   ofs_no;     /* Tool offset number */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   pth_no;     /* path index */
            long    ofs_old;    /* old data */
            long    ofs_new;    /* new data */
            short   old_dp;     /* old data decimal point */
            short   new_dp;     /* new data decimal point */
        } rec_ofs;              /* TOOL OFS */
        struct {
            short   prm_grp;    /* paramater group */
            short   prm_num;    /* paramater number */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   prm_len;    /* paramater data length */
            long    prm_no;     /* paramater no */
            long    prm_old;    /* old data */
            long    prm_new;    /* new data */
            short   old_dp;     /* old data decimal point */
            short   new_dp;     /* new data decimal point */
        } rec_prm;              /* PARAMATER */
        struct {
            short   ofs_grp;    /* Work offset group */
            short   ofs_no;     /* Work offset number */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   pth_no;     /* path index */
            short   axis_no;    /* path axis num $*/
            short   dummy;
            long    ofs_old;    /* old data */
            long    ofs_new;    /* new data */
            short   old_dp;     /* old data decimal point */
            short   new_dp;     /* new data decimal point */
        } rec_wof;              /* WORK OFS */
        struct {
            short   mac_no;     /* macro val number */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   pth_no;     /* path index */
            short   dummy;
            long    mac_old;    /* old data */
            long    mac_new;    /* new data */
            short   old_dp;     /* old data decimal point */
            short   new_dp;     /* old data decimal point */
        } rec_mac;              /* MACRO VAL */
        struct {
            long    mac_no;     /* macro val number(expand) */
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
            short   pth_no;     /* path index */
            long    mac_old;    /* old data */
            long    mac_new;    /* new data */
            short   old_dp;     /* old data decimal point */
            short   new_dp;     /* old data decimal point */
        } rec_mac2;             /* MACRO VAL2*/
        struct {
            short   scrn_old;   /* old screen nubmer */
            short   scrn_new;   /* new screen nubmer */
            short   dummy;
            short   hour;       /* hour */
            short   minute;     /* minute */
            short   second;     /* second */
        } rec_scrn;             /* SCREEN NUMBER*/
    } u;
} ODBOPHIS4;

/* cnc_rdalmhistry:read alarm history data */
typedef struct odbahis {
    unsigned short  s_no;   /* start number */
    short   type;           /* dummy */
    unsigned short  e_no;   /* end number */
    struct {
        short   dummy;
        short   alm_grp;        /* alarm group */
        short   alm_no;         /* alarm number */
        char    axis_no;        /* axis number */
        char    year;           /* year */
        char    month;          /* month */
        char    day;            /* day */
        char    hour;           /* hour */
        char    minute;         /* minute */
        char    second;         /* second */
        char    dummy2;
        short   len_msg;        /* alarm message length */
        char    alm_msg[32];    /* alarm message */
    } alm_his[10];
} ODBAHIS;  /* In case that the number of data is 10 */

/* cnc_rdalmhistry2:read alarm history data */
typedef struct odbahis2 {
    unsigned short  s_no;   /* start number */
    unsigned short  e_no;   /* end number */
    struct {
        short   alm_grp;        /* alarm group */
        short   alm_no;         /* alarm number */
        short   axis_no;        /* axis number */
        short   year;           /* year */
        short   month;          /* month */
        short   day;            /* day */
        short   hour;           /* hour */
        short   minute;         /* minute */
        short   second;         /* second */
        short   len_msg;        /* alarm message length */
        char    alm_msg[32];    /* alarm message */
    } alm_his[10];
} ODBAHIS2;  /* In case that the number of data is 10 */

/* cnc_rdalmhistry3:read alarm history data */
typedef struct odbahis3 {
    unsigned short  s_no;   /* start number */
    unsigned short  e_no;   /* end number */
    struct {
        short   alm_grp;        /* alarm group */
        short   alm_no;         /* alarm number */
        short   axis_no;        /* axis number */
        short   year;           /* year */
        short   month;          /* month */
        short   day;            /* day */
        short   hour;           /* hour */
        short   minute;         /* minute */
        short   second;         /* second */
        short   len_msg;        /* alarm message length */
        short   pth_no;         /* path index */
        short   dummy;
        char    alm_msg[32];    /* alarm message */
    } alm_his[10];
} ODBAHIS3;  /* In case that the number of data is 10 */

/* cnc_rdalmhistry4:read alarm history data */
typedef struct odbahis4 {
    unsigned short  s_no;   /* start number */
    unsigned short  e_no;   /* end number */
    struct {
        short   alm_grp;        /* alarm group */
        short   alm_no;         /* alarm number */
        short   axis_no;        /* axis number */
        short   year;           /* year */
        short   month;          /* month */
        short   day;            /* day */
        short   hour;           /* hour */
        short   minute;         /* minute */
        short   second;         /* second */
        short   len_msg;        /* alarm message length */
        short   pth_no;         /* path index */
        short   dummy;
        char    alm_msg[64];    /* alarm message */
    } alm_his[10];
} ODBAHIS4;  /* In case that the number of data is 10 */

/* cnc_rdalmhistry5:read alarm history data */
typedef struct odbahis5 {
    unsigned short  s_no;   /* start number */
    unsigned short  e_no;   /* end number */
    struct {
        short   alm_grp;        /* alarm group */
        short   alm_no;         /* alarm number */
        short   axis_no;        /* axis number */
        short   year;           /* year */
        short   month;          /* month */
        short   day;            /* day */
        short   hour;           /* hour */
        short   minute;         /* minute */
        short   second;         /* second */
        short   len_msg;        /* alarm message length */
        short   pth_no;         /* path index */
/*addalm--<*/
		short   sys_alm;        /* sys alarm */
		short   dsp_flg;        /* message dsp flag */
		short   axis_num;    /* sum axis num */
        char    alm_msg[64]; /* alarm message */
		long    g_modal[10]; /* G code Modal */
		char    g_dp[10];    /* #7:1 Block */
		                     /* #6-#0 dp*/
        short   dummy1;
		long    a_modal[10]; /* B,D,E,F,H,M,N,O,S,T code Modal */
		char    a_dp[10];    /* #7:1 Block */
		                     /* #6-#0 dp*/
        short   dummy2;
		long    abs_pos[32]; /* Abs pos */
		char    abs_dp[32];  /* Abs dp */
		long    mcn_pos[32]; /* Mcn pos */
		char    mcn_dp[32];  /* Mcn dp */
/*addalm-->*/
    } alm_his[10];
} ODBAHIS5;  /* In case that the number of data is 10 */

/* cnc_rdomhistry2:read operater message history data */
typedef struct odbmhis2 {
    unsigned short  s_no;   /* start number */
    unsigned short  e_no;   /* end number */
    struct {
        short   dsp_flg;  /* Dysplay flag(ON/OFF) */
        short   om_no;    /* operater message number */
        short   year;     /* year */
        short   month;    /* month */
        short   day;      /* day */
        short   hour;     /* Hour */
        short   minute;   /* Minute */
        short   second;   /* Second */
        char    ope_msg[256];/* Messege */
    } opm_his[10];
} ODBOMHIS2;  /* In case that the number of data is 10 */

/* cnc_rdhissgnl:read signals related operation history */
/* cnc_wrhissgnl:write signals related operation history */
typedef struct iodbsig {
    short   datano; /* dummy */
    short   type;   /* dummy */
    struct {
        short   ent_no;     /* entry number */
        short   sig_no;     /* signal number */
        char    sig_name;   /* signal name */
        char    mask_pat;   /* signal mask pattern */
    } data[20];
} IODBSIG;  /* In case that the number of data is 20 */

/* cnc_rdhissgnl2:read signals related operation history 2 */
/* cnc_wrhissgnl2:write signals related operation history 2 */
typedef struct iodbsig2 {
    short   datano; /* dummy */
    short   type;   /* dummy */
    struct {
        short   ent_no;     /* entry number */
        short   sig_no;     /* signal number */
        char    sig_name;   /* signal name */
        char    mask_pat;   /* signal mask pattern */
    } data[45];
} IODBSIG2;

/* cnc_rdhissgnl3:read signals related operation history */
/* cnc_wrhissgnl3:write signals related operation history */
typedef struct iodbsig3 {
    short   datano; /* dummy */
    short   type;   /* dummy */
    struct {
        short   ent_no;     /* entry number */
        short   pmc_no;     /* PMC number */
        short   sig_no;     /* signal number */
        char    sig_name;   /* signal name */
        char    mask_pat;   /* signal mask pattern */
    } data[60];
} IODBSIG3;  /* In case that the number of data is 60 */


/*--------------------------------------*/
/* CNC: 3 dimensional interferect check */
/*--------------------------------------*/
/* cnc_rdtdiinfo:read 3 dimensional interferect check information */
typedef struct odbinf {
    unsigned short  max_shape_num ;     /* maximum shape number */
    unsigned short  max_tool_num ;      /* maximum tool number */
    unsigned short  max_holder_num ;    /* maximum tool holder number */
    unsigned short  max_object_num ;    /* maximum object number */
    unsigned short  max_element_num ;   /* maximum element number */
    unsigned short  max_holder_shpnum ; /* maximum each tool holder shape number */
    unsigned short  max_object_shpnum ; /* maximum each object shape number */
    short           reserve ;           /* reserve */
} ODBINF ;

/* cnc_rdtdinamesetting:read name setting */
/* cnc_wrtdinamesetting:write name setting */
typedef struct odbnme {
    short           ob_type ;   /* object type */
    unsigned short  obj_no ;    /* object number */
    unsigned short  nme_no ;    /* name number */
    unsigned short  suffix  ;   /* suffix */
    char            name[12] ;  /* optional name */
} ODBNME ;

/* cnc_rdtdidispsetting:read display setting */
/* cnc_wrtdidispsetting:write display setting */
typedef struct odbdst {
    short           ob_type ;   /* object type */
    unsigned short  obj_no ;    /* object number */
    unsigned char   shp_disp ;  /* figure screen */
    unsigned char   mva_disp ;  /* move axis screen */
} ODBDST ;

/* cnc_rdtdishapedata:read shape data */
/* cnc_wrtdishapedata:write shape data */
typedef struct odbshp {
    short           ob_type ;       /* object type */
    unsigned short  obj_no ;        /* object number */
    unsigned short  shp_no ;        /* shape number */
    unsigned short  fig_ele[10] ;    /* figure element 1-6 */
    long            ref_pos[3] ;    /* reference position */
    long            tool_ref[3] ;   /* tool reference position */
    long            tool_dir[3] ;   /* tool direction */
    long            ref_ang1 ;      /* reference angle1 */
    long            ref_ang2 ;      /* reference angle2 */
    unsigned char   n_unit ;        /* numetrical unit */
} ODBSHP ;

/* cnc_rdtdicubedata:read cube data */
/* cnc_wrtdicubedata:write cube data */
typedef struct odbcub {
    long            ref_vtx[3] ;      /* reference vertex */
    long            adj_vtx1[3] ;     /* adjacence vertex1 */
    long            adj_vtx2[3] ;     /* adjacence vertex2 */
    long            adj_vtx3[3] ;     /* adjacence vertex3 */
    unsigned char   n_unit ;          /* numetrical unit */
    char   			cb_form ;         /* cube form flag */
} ODBCUB ;

/* cnc_rdtdicubeinfo:read cube infomation */
typedef struct odbcbi {
    unsigned short  cb_no ;   /* name setting */
    ODBNME          nme_set ;   /* name setting */
    unsigned char   shp_no ;    /* shape number */
    char            cd_form ;   /* cube form flag */
} ODBCBI ;

/* cnc_rdtdimoveaxis:read move axis infomation */
/* cnc_wrtdimoveaxis:write move axis infomation */
typedef struct odbmva {
    unsigned short  sync_obj ;      /* synchronized object */
    unsigned short  path ;          /* path */

    struct {
        unsigned short  axis_no ;   /* axis number */
        unsigned short  mov_dir ;   /* moving direction */
    } lin_ax[3] ;                   /* line axis(1-3) */

    struct {
        unsigned short  axis_no ;   /* axis number */
        unsigned short  c_ax_dir ;  /* rotating direction */
        long            c_pos[3] ;  /* rotating position */
        long            inc_ang ;   /* inclination angle */
        unsigned short  rot_dir ;   /* rotational direction */
        short           reserve ;   /* reserve */
    } rot_ax[2] ;                   /* rotating axis(1-2) */

    struct {
        unsigned short  master ;    /* master rotating axis */
        unsigned short  slave ;     /* slave rotating axis */
    } rot_ele[6] ;                  /* rotating element(1-6) */
} ODBMVA ;

/* cnc_rdtdicrntshapeinf:read current shape data */
typedef struct odbcrntshp {
    long            fig_type ;
	long 			reserve; 
    union {
	    struct {
	        double	base_pos[3] ;
	        double	vect1[3] ;
	        double	vect2[3] ;
	        double	vect3[3] ;
	    } par ;
	    struct {
	        double	vect1[3] ;
	        double	vect2[3] ;
	        double	v ;
	    } cyl ;
	    struct {
	        double	point[3] ;
	        double	vect[3] ;
	    } pln ;
    } fig ;
    char   			cb_form ;
    char   			reserve2[7] ;
} ODBCRNTSHP ;

/* cnc_rdtdicylinderdata:read cylinder data */
/* cnc_wrtdicylinderdata:write cylinder data */
typedef struct odbcyl {
    long            sta_pnt[3] ;      /* start point */
    long            end_pnt[3] ;      /* end point */
    long            radius ;          /* radius */
    unsigned char   n_unit ;          /* numetrical unit */
    char            cb_form ;         /* figure form flag */
} ODBCYL ;

/* cnc_rdtdiplanedata:read plane data */
/* cnc_wrtdiplanedata:write plane data */
typedef struct odbpln {
    long            point[3] ;        /* optional point on plane */
    long            vect[3] ;         /* vertical vector */
    unsigned char   n_unit ;          /* numetrical unit */
    char            cb_form ;         /* figure form flag */
} ODBPLN ;

/* cnc_rdtdifiguredata:read figure data */
/* cnc_wrtdifiguredata:write figure data */
typedef struct odbfig {
    long            fig_type ;        /* figure type */
    union {
	    struct {
            long    ref_vtx[3] ;      /* reference vertex */
            long    adj_vtx1[3] ;     /* adjacence vertex1 */
            long    adj_vtx2[3] ;     /* adjacence vertex2 */
            long    adj_vtx3[3] ;     /* adjacence vertex3 */
	    } par ;
	    struct {
            long    sta_pnt[3] ;      /* start point */
            long    end_pnt[3] ;      /* end point */
            long    radius ;          /* radius */
	    } cyl ;
	    struct {
            long    point[3] ;        /* optional point on plane */
            long    vect[3] ;         /* vertical vector */
	    } pln ;
    } fig ;
    unsigned short  fig_no ;          /* figure number */
    unsigned char   n_unit ;          /* numetrical unit */
    char            cb_form ;         /* figure form flag */
} ODBFIG ;

/*-------------*/
/* CNC: Others */
/*-------------*/

/* cnc_sysinfo:read CNC system information */
#if !defined (FS15BD)
typedef struct odbsys {
    short   addinfo ;       /* additional information  */
    short   max_axis ;      /* maximum axis number */
    char    cnc_type[2] ;   /* cnc type <ascii char> */
    char    mt_type[2] ;    /* M/T/TT <ascii char> */
    char    series[4] ;     /* series NO. <ascii char> */
    char    version[4] ;    /* version NO.<ascii char> */
    char    axes[2] ;       /* axis number<ascii char> */
} ODBSYS ;
#else
typedef struct odbsys {
    short   dummy ;         /* dummy                   */
    char    max_axis[2] ;   /* maximum axis number     */
    char    cnc_type[2] ;   /* cnc type <ascii char> */
    char    mt_type[2] ;    /* M/T/TT <ascii char> */
    char    series[4] ;     /* series NO. <ascii char> */
    char    version[4] ;    /* version NO.<ascii char> */
    char    axes[2] ;       /* axis number<ascii char> */
} ODBSYS ;
#endif

typedef struct _odbsramif {
    long    protect;        /* protective state of File SRAM */
    long    size;           /* size of File SRAM */
} ODBSRAMIF;

typedef struct _odbsramif2 {
    long            protect;    /* protective state of File SRAM */
    unsigned long   adrs;       /* address of File SRAM */
    long            size;       /* size of File SRAM */
} ODBSRAMIF2;

/* cnc_statinfo:read CNC status information */

#if defined (FS15D) || defined (FS15BD)
typedef struct odbst {
    short dummy[2];     /* dummy                    */
    short aut;          /* selected automatic mode  */
    short manual;       /* selected manual mode     */
    short run;          /* running status           */
    short edit;         /* editting status          */
    short motion;       /* axis, dwell status       */
    short mstb;         /* m, s, t, b status        */
    short emergency;    /* emergency stop status    */
    short write;        /* writting status          */
    short labelskip;    /* label skip status        */
    short alarm;        /* alarm status             */
    short warning;      /* warning status           */
    short battery;      /* battery status           */
} ODBST ;

#elif defined (FS16WD)
typedef struct odbst {
    short   dummy[2] ;  /* dummy */
    short   aut ;       /* selected automatic mode */
    short   run ;       /* running status */
    short   motion ;    /* axis, dwell status */
    short   mstb ;      /* m, s, t, b status */
    short   emergency ; /* emergency stop status */
    short   alarm ;     /* alarm status */
    short   edit ;      /* editting status */
} ODBST ;

#else
typedef struct odbst {
    short   hdck ;      /* handl retrace status */
    short   tmmode ;    /* T/M mode */
    short   aut ;       /* selected automatic mode */
    short   run ;       /* running status */
    short   motion ;    /* axis, dwell status */
    short   mstb ;      /* m, s, t, b status */
    short   emergency ; /* emergency stop status */
    short   alarm ;     /* alarm status */
    short   edit ;      /* editting status */
} ODBST ;
#endif

/* cnc_statinfo2:read CNC status information 2 */
typedef struct odbst2 {
    short   hdck ;      /* handl retrace status */
    short   tmmode ;    /* T/M mode */
    short   aut ;       /* selected automatic mode */
    short   run ;       /* running status */
    short   motion ;    /* axis, dwell status */
    short   mstb ;      /* m, s, t, b status */
    short   emergency ; /* emergency stop status */
    short   alarm ;     /* alarm status */
    short   edit ;      /* editting status */
    short   warning ;   /* warning status */
    short   o3dchk;     /* o3dchk status */
    short   ext_opt;    /* option */
    short   restart;    /* State of edit when SBK */
} ODBST2 ;

/* cnc_sramstat:After setting the option, The state of SRAM is acquired.*/
typedef struct odbopmsg {
    short   msg_kind;   /* state of message */
    char    msg[30];    /* message string   */
} ODBOPMSG ;

/* cnc_sramstatus:After setting the option, The state of SRAM is acquired.*/
typedef struct odbsramstat {
    short   msg_kind;   /* state of message */
    char    msg[64];    /* message string   */
} ODBSRAMSTAT ;

/* read DMG Netservice status information */
typedef struct out_statinfo_dmg {
     short  dummy[1];     /* Not used                          */
     short  dmg;          /* DMG Netservice status information */
     short  dummy1[7];    /* Not used                          */
} OUT_STATINF_DMG ;

/* cnc_alarm:read alarm status */
typedef struct odbalm {
    short   dummy[2] ;  /* dummy */
    short   data ;      /* alarm status */
} ODBALM ;

/* cnc_rdalminfo:read alarm information */
typedef struct alminfo {
#if MAX_AXIS > 16
    union {
        struct {
            struct {
                long    axis ;
                short   alm_no ;
            } alm[5] ;
            long    data_end ;
        } alm1 ;
        struct {
            struct {
                long    axis ;
                short   alm_no ;
                short   msg_len ;
                char    alm_msg[32] ;
            } alm[5] ;
            long    data_end ;
        }alm2 ;
    } u ;
#else
    union {
        struct {
            struct {
                short   axis ;
                short   alm_no ;
            } alm[5] ;
            short   data_end ;
        } alm1 ;
        struct {
            struct {
                short   axis ;
                short   alm_no ;
                short   msg_len ;
                char    alm_msg[32] ;
            } alm[5] ;
            short   data_end ;
        }alm2 ;
    } u ;
#endif
} ALMINFO ; /* In case that the number of alarm is 5 */

/* cnc_rdalminfo2:read alarm information */
typedef struct alminfo2 {
    union {
        struct {
            struct {
                short   axis ;
                short   alm_no ;
            } alm[5] ;
            short   data_end ;
        } alm1 ;
        struct {
            struct {
                short   axis ;
                short   alm_no ;
                short   msg_len ;
                char    alm_msg[34] ;
            } alm[5] ;
            short   data_end ;
        }alm2 ;
    } u ;
} ALMINFO2 ; /* In case that the number of alarm is 5 */

/* cnc_rdalmmsg:read alarm messages */
typedef struct odbalmmsg {
    long    alm_no;
    short   type;
    short   axis;
    short   dummy;
    short   msg_len;
    char    alm_msg[32];
} ODBALMMSG ;

typedef struct odbalmmsg2 {
    long    alm_no;
    short   type;
    short   axis;
    short   dummy;
    short   msg_len;
    char    alm_msg[64];
} ODBALMMSG2 ;

typedef struct odbalmmsg3 {
    long    alm_no;
    short   type;
    short   axis;
    short   dummy;
    short   msg_len;
    char    alm_msg[256];
} ODBALMMSG3 ;

/* cnc_modal:read modal data */
#if defined (HSSB_LIB) && defined (FS16WD)
typedef struct odbmdl {
    short   datano;
    short   type;
    union {
        char    g_data;
        char    g_rdata[12];
        char    g_1shot;
        struct {
            long    aux_data;
            char    flag1;
            char    flag2;
        }aux;
        struct {
            long    aux_data;
            char    flag1;
            char    flag2;
        }raux1[25];
    }modal;
} ODBMDL ;
#else
typedef struct odbmdl {
    short   datano;
    short   type;
    union {
        char    g_data;
        char    g_rdata[35];
        char    g_1shot[4];
        struct {
            long    aux_data;
            char    flag1;
            char    flag2;
        }aux;
        struct {
            long    aux_data;
            char    flag1;
            char    flag2;
        }raux1[27];
        struct {
            long    aux_data;
            char    flag1;
            char    flag2;
        }raux2[MAX_AXIS];
    }modal;
} ODBMDL ;
#endif

/* cnc_rdgcode: read G code */
typedef struct odbgcd {
	short	group ;
	short	flag ;
	char	code[8] ;
} ODBGCD;

/* cnc_rdcommand: read command value */
typedef struct odbcmd {
	char	adrs ;
	char	num ;
	short	flag ;
	long	cmd_val ;
	long	dec_val ;
} ODBCMD;

/* cnc_diagnoss:read diagnosis data */
/* cnc_diagnosr:read diagnosis data(area specified) */
typedef struct realdgn {
        long   dgn_val;     /* data of real diagnoss */
        long   dec_val;     /* decimal point of real diagnoss */
} REALDGN ;

#if !defined (HSSB_LIB) || defined (FS30D) || defined (FS15D) || defined (FS0IDD) /* Ethernet & FS30i & FS15i & FS0i-D */
typedef struct odbdgn {
    short   datano ;    /* data number */
    short   type ;      /* axis number */
    union {
        char    cdata ; /* diagnosis data */
        short   idata ;
        long    ldata ;
        REALDGN rdata ;
        char    cdatas[MAX_AXIS] ;
        short   idatas[MAX_AXIS] ;
        long    ldatas[MAX_AXIS] ;
        REALDGN rdatas[MAX_AXIS] ;
    } u ;
} ODBDGN ;

#else

typedef struct odbdgn {
    short   datano ;    /* data number */
    short   type ;      /* axis number */
    union {
        char    cdata ; /* diagnosis data */
        short   idata ;
        long    ldata ;
        char    cdatas[MAX_AXIS] ;
        short   idatas[MAX_AXIS] ;
        long    ldatas[MAX_AXIS] ;
    } u ;
} ODBDGN ;
#endif

#if defined (FS15BD)

/* cnc_adcnv:read A/D conversion data */
typedef struct odbad {
    short   datano ;    /* input analog voltage type */
    short   type ;      /* analog voltage type */
    char    data ;      /* digital voltage data */
} ODBAD ;

#else

/* cnc_adcnv:read A/D conversion data */
typedef struct odbad {
    short   datano ;    /* input analog voltage type */
    short   type ;      /* analog voltage type */
    short   data ;      /* digital voltage data */
} ODBAD ;

#endif

#if defined (FS15D) || defined (FS15BD)

/* cnc_rdopmsg:read operator's message */
typedef struct msg {
    short datano ;     /* operator's message number */
    short type ;       /* operator's message type   */
    short char_num ;   /* message string length   */
    char  data[129] ;  /* operator's message string */
} OPMSG ;               /* In case that the data length is 129 */

#else	/* FS15D */

/* cnc_rdopmsg:read operator's message */
typedef struct msg {
    short   datano ;    /* operator's message number */
    short   type ;      /* operator's message type */
    short   char_num ;  /* message string length */
    char    data[256] ; /* operator's message string */
} OPMSG ;   /* In case that the data length is 256 */

#endif	/* FS15D */

/* cnc_rdopmsg2:read operator's message */
typedef struct opmsg2 {
    short   datano ;    /* operator's message number */
    short   type ;      /* operator's message type */
    short   char_num ;  /* message string length */
    char    data[64] ;  /* operator's message string */
} OPMSG2 ;   /* In case that the data length is 64 */

/* cnc_rdopmsg3:read operator's message */
typedef struct opmsg3 {
    short   datano ;    /* operator's message number */
    short   type ;      /* operator's message type */
    short   char_num ;  /* message string length */
    char    data[256] ; /* operator's message string */
} OPMSG3 ;   /* In case that the data length is 256 */

/* cnc_rdopmsgmps:read operator message for MAPPS */
typedef struct _opmsgmps {
	short datano;
	short type;
	short char_num;
	char data[256];
} OPMSGMPS;

/* cnc_sysconfig:read CNC configuration information */
#if defined (FS15BD)
typedef struct odbsysc {
    char        slot_no_p[16];
    char        slot_no_l[16];
    short       mod_id[16];
    short       soft_id[16];
    char        s_series[16][5];
    char        s_version[16][5];
    char        sys_id[16];
    char        sys_ser[5];
    char        sys_ver[5];
    char        basic_ver[5];
    char        opta1_ver[5];
    char        opta2_ver[5];
    char        opta3_ver[5];
    char        opta4_ver[5];
    char        sub_ver[5];
    char        opts1_ver[5];
    char        tcopt_ver[5];
    char        axis_ser[5];
    char        axis_ver[5];
    char        help_ser[5];
    char        help_ver[5];
    char        boot_ser[5];
    char        boot_ver[5];
    char        servo_ser[5];
    char        servo_ver[5];
    char        cmpl_ser[5];
    char        cmpl_ver[5];
    char        sral1_ser[5];
    char        sral1_ver[5];
    char        sral2_ser[5];
    char        sral2_ver[5];
    char        sral3_ser[5];
    char        sral3_ver[5];
    char        sral4_ser[5];
    char        sral4_ver[5];
    short       pcb_info[20];
    short       pcb_note[20][16];
} ODBSYSC ;

#elif defined (PMD)
typedef struct odbsysc {
     char    slot_no_p[16];	/* not used */
     char    slot_no_l[16];	/* not used */
     short   mod_id[16];	/* not used */
     short   soft_id[16];	/* software ID */
     char    s_series[16][5];	/* software series */
     char    s_version[16][5];	/* software version */
     char    dummy[16];		/* dummy */
     short   m_rom;		/* not used */
     short   s_rom;		/* not used */
     char    svo_soft[8];	/* series and version of searvo software */
     char    pmc_soft[6];	/* series and version of PMC management software */
     char    lad_soft[6];	/* series and version of Ladder software */
     char    mcr_soft[8];	/* series and version of a macro executor */
     char    spl1_soft[6];	/* not used */
     char    spl2_soft[6];	/* not used */
     short   frmmin;		/* capacity of FROM module */
     short   drmmin;		/* capacity of DRAM module */
     short   srmmin;		/* capacity of added SRAM module */
     short   pmcmin;		/* type of PMC module */
     short   sv1min;		/* presence or absence of a servo module 1,2 */
     short   sv3min;		/* presence or absence of a servo module 3,4 */
     short   sv5min;		/* presence or absence of a servo module 5,6 */
     short   sicmin;		/* presence or absence of SIC */
     short   posmin;		/* presence or absence of a position LSI */
     short   submin;		/* information of sub-board */
     short   hdiio;		/* presence or absence of an LSI for high-speed skip(I/O card) */
     short   dummy2[32];	/* dummy */
} ODBSYSC;

#else
typedef struct odbsysc {
    char    slot_no_p[16];
    char    slot_no_l[16];
    short   mod_id[16];
    short   soft_id[16];
    char    s_series[16][5];
    char    s_version[16][5];
    char    dummy[16];
    short   m_rom;
    short   s_rom;
    char    svo_soft[8];
    char    pmc_soft[6];
    char    lad_soft[6];
    char    mcr_soft[8];
    char    spl1_soft[6];
    char    spl2_soft[6];
    short   frmmin;
    short   drmmin;
    short   srmmin;
    short   pmcmin;
    short   crtmin;
    short   sv1min;
    short   sv3min;
    short   sicmin;
    short   posmin;
    short   drmmrc;
    short   drmarc;
    short   pmcmrc;
    short   dmaarc;
    short   iopt;
    short   hdiio;
    short   frmsub;
    short   drmsub;
    short   srmsub;
    short   sv5sub;
    short   sv7sub;
    short   sicsub;
    short   possub;
    short   hamsub;
    short   gm2gr1;
    short   crtgr2;
    short   gm1gr2;
    short   gm2gr2;
    short   cmmrb;
    short   sv5axs;
    short   sv7axs;
    short   sicaxs;
    short   posaxs;
    short   hanaxs;
    short   romr64;
    short   srmr64;
    short   dr1r64;
    short   dr2r64;
    short   iopio2;
    short   hdiio2;
    short   cmmrb2;
    short   romfap;
    short   srmfap;
    short   drmfap;
} ODBSYSC ;
#endif

/* cnc_rdprstrinfo:read program restart information */
typedef struct odbprs {
    short   datano;         /* dummy */
    short   type;           /* dummy */
    short   data_info[5];   /* data setting information */
    long    rstr_bc;        /* block counter */
    long    rstr_m[35];     /* M code value */
    long    rstr_t[2];      /* T code value */
    long    rstr_s;         /* S code value */
    long    rstr_b;         /* B code value */
    long    dest[MAX_AXIS]; /* program re-start position */
    long    dist[MAX_AXIS]; /* program re-start distance */
} ODBPRS;

/* cnc_rdprstrinfo:read program restart information */
typedef struct odbprsm {
    short   datano;          /* dummy */
    short   type;            /* dummy */
    short   data_info[5];    /* data setting information */
    long    rstr_bc;         /* block counter */
    long    rstr_m[35];      /* M code value */
    long    rstr_t[2];       /* T code value */
    long    rstr_s;          /* S code value */
    long    rstr_b;          /* B code value */
    long    dest[32];        /* program re-start position */
    long    dist[32];        /* program re-start distance */
} ODBPRSM;

#if defined (FS15D) || defined (FS15BD)

/* cnc_rdopnlsgnl:read output signal image of software operator's panel */
/* cnc_wropnlsgnl:write output signal of software operator's panel */
typedef struct iodbsgnl {
    short   datano;     /* dummy */
    short   type;       /* data select flag */
    short   mode;       /* mode signal */
    short   hndl_ax;    /* Manual handle feed axis selection signal */
    short   hndl_mv;    /* Manual handle feed travel distance selection signal */
    short   rpd_ovrd;   /* rapid traverse override signal */
    short   jog_ovrd;   /* manual feedrate override signal */
    short   feed_ovrd;  /* feedrate override signal */
    short   spdl_ovrd;  /* spindle override signal */
    short   blck_del;   /* optional block skip signal */
    short   sngl_blck;  /* single block signal */
    short   machn_lock; /* machine lock signal */
    short   dry_run;    /* dry run signal */
    short   mem_prtct;  /* memory protection signal */
    short   feed_hold;  /* automatic operation halt signal */
    short   manual_rpd; /* manual rapid traverse selection signal */
    short   dummy[2];   /* (not used) */
} IODBSGNL;

#else	/* FS15D */

/* cnc_rdopnlsgnl:read output signal image of software operator's panel */
/* cnc_wropnlsgnl:write output signal of software operator's panel */
typedef struct iodbsgnl {
    short   datano;     /* dummy */
    short   type;       /* data select flag */
    short   mode;       /* mode signal */
    short   hndl_ax;    /* Manual handle feed axis selection signal */
    short   hndl_mv;    /* Manual handle feed travel distance selection signal */
    short   rpd_ovrd;   /* rapid traverse override signal */
    short   jog_ovrd;   /* manual feedrate override signal */
    short   feed_ovrd;  /* feedrate override signal */
    short   spdl_ovrd;  /* (not used) */
    short   blck_del;   /* optional block skip signal */
    short   sngl_blck;  /* single block signal */
    short   machn_lock; /* machine lock signal */
    short   dry_run;    /* dry run signal */
    short   mem_prtct;  /* memory protection signal */
    short   feed_hold;  /* automatic operation halt signal */
} IODBSGNL;

#endif	/* FS15D */

/* cnc_rdopnlgnrl:read general signal image of software operator's panel */
/* cnc_wropnlgnrl:write general signal image of software operator's panel */
typedef struct iodbgnrl {
    short   datano; /* dummy */
    short   type;   /* data select flag */
    char    sgnal;  /* general signal */
} IODBGNRL;

/* cnc_rdopnlgnrl2:read general signal image of software operator's panel(2) */
/* cnc_wropnlgnrl2:write general signal image of software operator's panel(2) */
typedef struct iodbgnrl2 {
    short   datano; /* dummy */
    short   type;   /* data select flag */
    short   sgnal;  /* general signal */
} IODBGNRL2;

/* cnc_rdopnlgsname:read general signal name of software operator's panel */
/* cnc_wropnlgsname:write general signal name of software operator's panel*/
typedef struct iodbrdna {
    short   datano;         /* dummy */
    short   type;           /* data select flag */
    char    sgnl1_name[9];  /* general signal 1 name */
    char    sgnl2_name[9];  /* general signal 2 name */
    char    sgnl3_name[9];  /* general signal 3 name */
    char    sgnl4_name[9];  /* general signal 4 name */
    char    sgnl5_name[9];  /* general signal 5 name */
    char    sgnl6_name[9];  /* general signal 6 name */
    char    sgnl7_name[9];  /* general signal 7 name */
    char    sgnl8_name[9];  /* general signal 8 name */
} IODBRDNA;

/* cnc_rdopnlgsname2:read general signal name of software operator's panel(2) */
/* cnc_wropnlgsname2:write general signal name of software operator's panel(2)*/
typedef struct iodbrdna2 {
    short   datano;         /* dummy */
    short   type;           /* data select flag */
    char    sgnl1_name[9];  /* general signal 1 name */
    char    sgnl2_name[9];  /* general signal 2 name */
    char    sgnl3_name[9];  /* general signal 3 name */
    char    sgnl4_name[9];  /* general signal 4 name */
    char    sgnl5_name[9];  /* general signal 5 name */
    char    sgnl6_name[9];  /* general signal 6 name */
    char    sgnl7_name[9];  /* general signal 7 name */
    char    sgnl8_name[9];  /* general signal 8 name */
    char    sgnl9_name[9];  /* general signal 9 name */
    char    sgnl10_name[9]; /* general signal 10 name */
    char    sgnl11_name[9]; /* general signal 11 name */
    char    sgnl12_name[9]; /* general signal 12 name */
    char    sgnl13_name[9]; /* general signal 13 name */
    char    sgnl14_name[9]; /* general signal 14 name */
    char    sgnl15_name[9]; /* general signal 15 name */
    char    sgnl16_name[9]; /* general signal 16 name */
} IODBRDNA2;

/* cnc_getdtailerr:get detail error */
typedef struct odberr {
    short   err_no ;
    short   err_dtno ;
} ODBERR ;

/* cnc_rdparainfo:read informations of CNC parameter */
typedef struct odbparaif {
    unsigned short  info_no ;
    short   prev_no ;
    short   next_no ;
    struct {
        short   prm_no ;
        short   prm_type ;
    } info[10] ;    /* In case that the number of data is 10 */
} ODBPARAIF ;

/* cnc_rdsetinfo:read informations of CNC setting data */
typedef struct odbsetif {
    unsigned short  info_no ;
    short   prev_no ;
    short   next_no ;
    struct {
        short   set_no ;
        short   set_type ;
    } info[10] ;    /* In case that the number of data is 10 */
} ODBSETIF ;

/* cnc_rddiaginfo:read informations of CNC diagnose data */
typedef struct odbdiagif {
    unsigned short  info_no ;
    short   prev_no ;
    short   next_no ;
    struct {
        short   diag_no ;
        short   diag_type ;
    } info[10] ;    /* In case that the number of data is 10 */
} ODBDIAGIF ;

/* cnc_rdparainfo2:read informations of CNC parameter(2) */
/* cnc_rdparainfo3:read informations of CNC parameter(3) */
/* cnc_rdsetinfo2:read informations of CNC setting data(2) */
/* cnc_rddiaginfo2:read informations of CNC diagnose data(2) */
typedef struct odbparaif2 {
    short   prm_no;         /* parameter number */
    short   size;           /* size */
    short   array;          /* array type */
    short   unit;           /* unit */
    short   dim;            /* dimension */
    short   input;          /* input type */
    short   display;        /* display infomation */
    short   others;         /* others */
} ODBPARAIF2 ;

/* cnc_rdparanum:read maximum, minimum and total number of CNC parameter */
typedef struct odbparanum {
    unsigned short  para_min ;
    unsigned short  para_max ;
    unsigned short  total_no ;
} ODBPARANUM ;

/* cnc_rdsetnum:read maximum, minimum and total number of CNC setting data */
typedef struct odbsetnum {
    unsigned short  set_min ;
    unsigned short  set_max ;
    unsigned short  total_no ;
} ODBSETNUM ;

/* cnc_rddiagnum:read maximum, minimum and total number of CNC diagnose data */
typedef struct odbdiagnum {
    unsigned short  diag_min ;
    unsigned short  diag_max ;
    unsigned short  total_no ;
} ODBDIAGNUM ;

/* cnc_rdfrominfo:read F-ROM information on CNC  */
typedef struct odbfinfo {
    char  slotname[12];      /* Slot Name */
    long  fromnum;           /* Number of F-ROM SYSTEM data */
    struct {
        char  sysname[12];   /* F-ROM SYSTEM data Name */
        long  fromsize;      /* F-ROM Size */
    } info[32];
} ODBFINFO;

/* cnc_getfrominfo:read F-ROM information on CNC  */
#ifndef CNC_PPC
typedef struct odbfinform {
    long  slotno;            /* Slot Number */
    char  slotname[12];      /* Slot Name */
    long  fromnum;           /* Number of F-ROM SYSTEM data */
    struct {
        char  sysname[12];   /* F-ROM SYSTEM data Name */
        long  fromsize;      /* F-ROM Size */
        long  fromattrib;    /* F-ROM data attribute */
    } info[128];
} ODBFINFORM;
#endif

/* cnc_rdsraminfo:read S-RAM information on CNC */
/* cnc_getsraminfo:read S-RAM information on CNC */
typedef struct odbsinfo {
    long  sramnum;          /* Number of S-RAM data */
    struct {
        char  sramname[12]; /* S-RAM data Name */
        long  sramsize;     /* S-RAM data Size */
        short divnumber;    /* Division number of S-RAM file */
        char  fname[6][16]; /* S-RAM file names */
    } info[8];
} ODBSINFO;

/* cnc_rdsramaddr:read S-RAM address on CNC */
typedef struct sramaddr {
    short   type ;          /* SRAM data type */
    long    size ;          /* SRAM data size */
    long    offset ;        /* offset from top address of SRAM */
} SRAMADDR ;

/* cnc_dtsvrdpgdir:read file directory in Data Server */
typedef struct odbdsdir {
    long    file_num ;
    long    remainder ;
    short   data_num ;
    struct {
        char    file_name[16] ;
        char    comment[64] ;
        long    size ;
        char    date[16] ;
    } data[32] ;
} ODBDSDIR ;

/* cnc_dtsvrdset:read setting data for Data Server */
/* cnc_dtsvwrset:write setting data for Data Server */
typedef struct iodbdsset {
	char host_ip[16] ;
	char host_uname[32] ;
	char host_passwd[32] ;
	char host_dir[128] ;
	char dtsv_mac[13] ;
	char dtsv_ip[16] ;
	char dtsv_mask[16] ;
} IODBDSSET ;

/* cnc_dtsvmntinfo:read maintenance information for Data Server */
typedef struct odbdsmnt {
	long empty_cnt ;
	long total_size ;
	long read_ptr ;
	long write_ptr ;
} ODBDSMNT ;

/* cnc_rdposerrs2:read the position deviation S1 and S2 */
typedef struct odbpser {
    long    poserr1 ;
    long    poserr2 ;
} ODBPSER ;

/* cnc_rdctrldi:read the control input signal */
typedef struct odbspdi {
    char    sgnl1 ;
    char    sgnl2 ;
    char    sgnl3 ;
    char    sgnl4 ;
} ODBSPDI ;

/* cnc_rdctrldo:read the control output signal */
typedef struct odbspdo {
    char    sgnl1 ;
    char    sgnl2 ;
    char    sgnl3 ;
    char    sgnl4 ;
} ODBSPDO ;

/* cnc_rdsvfeedback:Read Servo feedback multiplication data */
typedef struct odbsvfback {
        short   dummy;
        short   dtype;
        long    fback[MAX_AXIS];
        long    afback[MAX_AXIS];
} ODBSVFBACK;

/* cnc_rdwaveprm:read the parameter of wave diagnosis */
/* cnc_wrwaveprm:write the parameter of wave diagnosis */
typedef struct iodbwave {
    short   condition ;
    char    trg_adr ;
    char    trg_bit ;
    short   trg_no ;
    short   delay ;
    short   t_range ;
    struct {
        short   kind ;
        union {
#if MAX_AXIS > 16
            long        axis ;
#else
            short       axis ;
#endif
            struct {
                char    adr ;
                char    bit ;
                short   no ;
            } io ;
        } u ;
    } ch[12] ;
} IODBWAVE ;

/* cnc_rdwaveprm2:read the parameter of wave diagnosis 2 */
/* cnc_wrwaveprm2:write the parameter of wave diagnosis 2 */
typedef struct iodbwvprm {
    short   condition ;
    char    trg_adr ;
    char    trg_bit ;
    short   trg_no ;
    short   reserve1 ;
    long    delay ;
    long    t_range ;
    struct {
        short   kind ;
        union {
            long    axis ;
            struct {
                char    adr ;
                char    bit ;
                short   no ;
            } io ;
        } u ;
        long    reserve2 ;
    } ch[12] ;
} IODBWVPRM ;

/* cnc_rdwaveprm3:read the parameter of wave diagnosis 3 */
/* cnc_wrwaveprm3:write the parameter of wave diagnosis 3 */
typedef struct iodbwvprm3 {
    short   condition ;
    short   trg_unittype ;
    char    trg_adr ;
    char    trg_bit ;
    short   trg_no ;
    short   alm_kind ;
    short   alm_no ;
    short   alm_axis ;
    short   reserve1 ;
    long    delay ;
    long    t_range ;
    short   wav_cycle ;
    short   dio_cycle ;
    struct {
        short   kind ;
        short   reserve2 ;
        union {
            struct {
                long    axis ;
                long    reserve3;
            } ax ;
            struct {
                short   unittype ;
                char    adr ;
                char    bit ;
                short   no ;
                short   reserve3 ;
            } io ;
        } u ;
    } ch[40] ;
} IODBWVPRM3 ;

/* cnc_rdwavedata:read the data of wave diagnosis */
typedef struct odbwvdt {
    short   channel ;
    short   kind ;
    union {
        short   axis ;
        struct {
            char    adr ;
            char    bit ;
            short   no ;
        } io ;
    } u ;
    char    year ;
    char    month ;
    char    day ;
    char    hour ;
    char    minute ;
    char    second ;
    short   t_cycle ;
    short   data[8192] ;
} ODBWVDT ;

typedef struct odbwvdt2 {
    short   channel ;
    union {
        struct {
            short   axis ;
            char    kind ;
        } w ;
        struct {
            short   no ;
            char    adr ;
            char    bit ;
        } io ;
    } u ;
    struct {
        char   year ;
        char   month ;
        char   day ;
        char   hour ;
        char   minute ;
        char   second ;
    } start , stop ;
    short   t_cycle ;
    short   adjust ;
    short   data[ 8192 ] ;
} ODBWVDT2 ;

/* cnc_rdwavedata3:read the data of wave diagnosis */
typedef struct odbwvdt3 {
    short   channel ;
    short   kind ;
    union {
        struct{
            short   axis ;
            short   reserve[3] ;
        } ax ;
        struct {
            short   unittype ;
            char    adr ;
            char    bit ;
            short   no ;
            short   reserve ;
        } io ;
    } u ;
    char    year ;
    char    month ;
    char    day ;
    char    hour ;
    char    minute ;
    char    second ;
    short   t_cycle ;
    short   data[8192] ;
} ODBWVDT3 ;

/* cnc_rdrmtwaveprm:read the parameter of wave diagnosis for remort diagnosis */
/* cnc_wrrmtwaveprm:write the parameter of wave diagnosis for remort diagnosis */
typedef struct iodbrmtprm {
    short   condition ;
    short   reserve ;
    union {
        struct {
            short   no ;
            char    axis ;
            char    type ;
        } alm ;
        struct {
            char    adr ;
            char    bit ;
            short   no ;
        } io ;
    } trg ;
    long    delay ;
    short   wv_intrvl ;
    short   io_intrvl ;
    short   kind1 ;
    short   kind2 ;
    struct {
           char    adr ;
           char    bit ;
           short   no ;
    } smpl[32] ;
} IODBRMTPRM ;

/* cnc_rdrmtwavedt:read the data of wave diagnosis for remort diagnosis */
typedef struct odbrmtdt {
    short   channel ;
    short   kind ;
    char    year ;
    char    month ;
    char    day ;
    char    hour ;
    char    minute ;
    char    second ;
    short   t_intrvl ;
    short   trg_data;
    long    ins_ptr;
    short   t_delta;
    short   data[1917] ;
} ODBRMTDT ;

/* cnc_rdsavsigadr:read of address for PMC signal batch save */
/* cnc_wrsavsigadr:write of address for PMC signal batch save */
typedef struct iodbsigad {
    char    adr ;
    char    reserve ;
    short   no ;
    short   size ;
} IODBSIGAD ;

/* cnc_rdmgrpdata:read M-code group data */
typedef struct odbmgrp {
	long  m_code ;
	short grp_no ;
	char  m_name[21] ;
	char  dummy ;
} ODBMGRP;

/* cnc_wrmgrpdata:write M-code group data */
typedef struct idbmgrp {
	short s_no ;
	short dummy ;
	short num ;
	short group[500] ;
} IDBMGRP ;

/* cnc_rdexecmcode:read executing M-code group data */
typedef struct odbexem {
    short	grp_no;
    short	mem_no;
    struct{
	long	no;
	short	flag;
    }m_code[5];
    char	m_name[21];
    char	dummy;
} ODBEXEM;

/* cnc_rdrstrmcode:read program restart M-code group data */
#ifndef CNC_PPC
typedef struct odbrstrm {
    short	grp_no;
    short	mem_no;
    struct{
	long	no;
	short	flag;
    }m_code[5];
} ODBRSTRM;
#endif

/* cnc_rdproctime:read processing time stamp data */
typedef struct odbptime {
	short	num;
	struct{
		long	prg_no;
		short	hour;
		char	minute;
		char	second;
	}data[10];
} ODBPTIME;

typedef struct odbptime3 {
	short	hour;
	short	min;
	short	sec;
	short	dummy;
} ODBPTIME3;

/* cnc_rdprgdirtime:read program directory for processing time data */
typedef struct prgdirtm {
	long	prg_no;
	char	comment[51];
	char	cuttime[13];
} PRGDIRTM;

/* cnc_rdprogdir2:read program directory 2 */
typedef struct prgdir2 {
	short	number ;
	long	length ;
	char	comment[51] ;
	char	dummy ;
} PRGDIR2;

/* cnc_rdprogdir3:read program directory 3 */
typedef struct prgdir3 {
	long	number ;
	long	length ;
	long	page ;
	char	comment[52] ;
	struct{
		short	year;
		short	month;
		short	day;
		short	hour;
		short	minute;
		short	dummy;
	} mdate;
	struct{
		short	year;
		short	month;
		short	day;
		short	hour;
		short	minute;
		short	dummy;
	} cdate;
} PRGDIR3;

/* cnc_rdprogdir4:read program directory 4 */
#define PRGDIR4 PRGDIR3

/* cnc_rdcomparam:read communication parameter for DNC1, DNC2, OSI-Ethernet */
/* cnc_wrcomparam:write communication parameter for DNC1, DNC2, OSI-Ethernet */
typedef struct iodbcprm {
	char           NcApli[65] ;
	char           Dummy1 ;
	char           HostApli[65] ;
	char           Dummy2 ;
	unsigned long  StatPstv ;
	unsigned long  StatNgtv ;
	unsigned long  Statmask ;
	unsigned long  AlarmStat ;
	unsigned long  PsclHaddr ;
	unsigned long  PsclLaddr ;
	unsigned short SvcMode1 ;
	unsigned short SvcMode2 ;
	long           FileTout ;
	long           RemTout ;
} IODBCPRM ;

/* cnc_rdintchk:read interference check */
/* cnc_wrintchk:write interference check */
typedef	struct  iodbint {
	short   datano_s;	/* start offset No. */
	short   type;		/* kind of position */
	short   datano_e;	/* end offset No. */
	long	data[24];	/* position value of area for not attach */
} IODBINT ;

/* cnc_rdwkcdshft:read work coordinate shift */
/* cnc_wrwkcdshft:write work coordinate shift */
/* cnc_rdwkcdsfms:read work coordinate shift measure */
/* cnc_wrwkcdsfms:write work coordinate shift measure */
typedef struct iodbwcsf {
     short	datano;         /* datano			*/
     short	type;           /* axis number			*/
     long	data[MAX_AXIS]; /* data				*/
} IODBWCSF;

/* cnc_rdomhisinfo:read operator message history information */
typedef struct odbomif {
	unsigned short	om_max ;   /* maximum operator message history */
	unsigned short	om_sum ;   /* actually operator message history */
	unsigned short	om_char ;  /* maximum character (include NULL) */
} ODBOMIF ;

/* cnc_rdomhistry:read operator message history */
typedef struct odbomhis {
	short	om_no;	/* operator message number */
	short	year;	/* year */
	short	month;	/* month */
	short	day;	/* day */
	short	hour;	/* hour */
	short	minute;	/* mimute */
	short	second;	/* second */
	char	om_msg[256];	/* operator message */
} ODBOMHIS ;

/* cnc_rdbtofsr:read b-axis tool offset value(area specified) */
/* cnc_wrbtofsr:write b-axis tool offset value(area specified) */
typedef	struct	iodbbto {
	short datano_s;		/* start offset number */
	short type;		/* offset type */
	short datano_e;		/* end offset number */
	long  ofs[18];		/* offset */
} IODBBTO ;	/* In case that the number of data is 9 (B type) */

/* cnc_rdbtofsinfo:read b-axis tool offset information */
typedef	struct  odbbtlinf {
	short	ofs_type;	/* memory type */
	short	use_no;		/* sum of b-axis offset */
	short	sub_no;		/* sub function number of offset cancel */
} ODBBTLINF ;

/* cnc_rdbaxis:read b-axis command */
typedef struct odbbaxis {
	short		flag ;        /* b-axis command exist or not */
	short		command ;     /* b-axis command */
	unsigned short	speed ;       /* b-axis speed */
	long		sub_data ;    /* b-axis sub data */
} ODBBAXIS ;

/* cnc_rdsyssoft:read CNC system soft series and version */
typedef struct odbsyss {
     char    slot_no_p[16];
     char    slot_no_l[16];
     short   module_id[16];
     short   soft_id[16];
     char    soft_series[16][5];
     char    soft_version[16][5];
     short   soft_inst;
     char    boot_ser[5];
     char    boot_ver[5];
     char    servo_ser[5];
     char    servo_ver[5];
     char    pmc_ser[5];
     char    pmc_ver[5];
     char    ladder_ser[5];
     char    ladder_ver[5];
     char    mcrlib_ser[5];
     char    mcrlib_ver[5];
     char    mcrapl_ser[5];
     char    mcrapl_ver[5];
     char    spl1_ser[5];
     char    spl1_ver[5];
     char    spl2_ser[5];
     char    spl2_ver[5];
     char    spl3_ser[5];
     char    spl3_ver[5];
     char    c_exelib_ser[5];
     char    c_exelib_ver[5];
     char    c_exeapl_ser[5];
     char    c_exeapl_ver[5];
     char    int_vga_ser[5];
     char    int_vga_ver[5];
     char    out_vga_ser[5];
     char    out_vga_ver[5];
     char    pmm_ser[5];
     char    pmm_ver[5];
     char    pmc_mng_ser[5];
     char    pmc_mng_ver[5];
     char    pmc_shin_ser[5];
     char    pmc_shin_ver[5];
     char    pmc_shout_ser[5];
     char    pmc_shout_ver[5];
     char    pmc_c_ser[5];
     char    pmc_c_ver[5];
     char    pmc_edit_ser[5];
     char    pmc_edit_ver[5];
     char    lddr_mng_ser[5];
     char    lddr_mng_ver[5];
     char    lddr_apl_ser[5];
     char    lddr_apl_ver[5];
     char    spl4_ser[5];
     char    spl4_ver[5];
     char    mcr2_ser[5];
     char    mcr2_ver[5];
     char    mcr3_ser[5];
     char    mcr3_ver[5];
     char    eth_boot_ser[5];
     char    eth_boot_ver[5];
     char    reserve[8][5];
} ODBSYSS ;

/* cnc_rdsyssoft2:read CNC system soft series and version (2) */
typedef struct odbsyss2 {
     char    slot_no_p[16];
     char    slot_no_l[16];
     short   module_id[16];
     short   soft_id[16];
     char    soft_series[16][5];
     char    soft_version[16][5];
     short   soft_inst;
     char    boot_ser[5];
     char    boot_ver[5];
     char    servo_ser[5];
     char    servo_ver[5];
     char    pmc_ser[5];
     char    pmc_ver[5];
     char    ladder_ser[5];
     char    ladder_ver[5];
     char    mcrlib_ser[5];
     char    mcrlib_ver[5];
     char    mcrapl_ser[5];
     char    mcrapl_ver[5];
     char    spl1_ser[5];
     char    spl1_ver[5];
     char    spl2_ser[5];
     char    spl2_ver[5];
     char    spl3_ser[5];
     char    spl3_ver[5];
     char    c_exelib_ser[5];
     char    c_exelib_ver[5];
     char    c_exeapl_ser[5];
     char    c_exeapl_ver[5];
     char    int_vga_ser[5];
     char    int_vga_ver[5];
     char    out_vga_ser[5];
     char    out_vga_ver[5];
     char    pmm_ser[5];
     char    pmm_ver[5];
     char    pmc_mng_ser[5];
     char    pmc_mng_ver[5];
     char    pmc_shin_ser[5];
     char    pmc_shin_ver[5];
     char    pmc_shout_ser[5];
     char    pmc_shout_ver[5];
     char    pmc_c_ser[5];
     char    pmc_c_ver[5];
     char    pmc_edit_ser[5];
     char    pmc_edit_ver[5];
     char    lddr_mng_ser[5];
     char    lddr_mng_ver[5];
     char    lddr_apl_ser[5];
     char    lddr_apl_ver[5];
     char    spl4_ser[5];
     char    spl4_ver[5];
     char    mcr2_ser[5];
     char    mcr2_ver[5];
     char    mcr3_ser[5];
     char    mcr3_ver[5];
     char    eth_boot_ser[5];
     char    eth_boot_ver[5];
     char    reserve[8][5];
     char    embEthe_ser[5];
     char    embEthe_ver[5];
     char    reserve2[38][5];
} ODBSYSS2 ;

typedef struct odbsyss3 {
     short   soft_id;
     char    soft_series[5];
     char    soft_edition[5];
} ODBSYSS3 ;

typedef struct odbsyss3_str {
    short   soft_id ;
    char    soft_name[13];
    char    soft_series[5] ;
    char    soft_edition[5] ;
    char    dummy[3] ;
} ODBSYSS3_STR ;

typedef struct odbsysh_str {
    short   group_id ;
    char    group_name[14] ;
    short   hard_id ;
    char    hard_name[13] ;
    char    id1[11] ;
    char    id2[9] ;
    char    slot_no[3];
    char    dummy[2] ;
} ODBSYSH_STR ;

typedef struct odbsysh {
     unsigned long id1 ;
     unsigned long id2 ;
     short  group_id ;
     short  hard_id ;
     short  hard_num ;
     short  slot_no ;
     short  id1_format ;
     short  id2_format ;
} ODBSYSH ;

/* cnc_rdmdlconfig:read CNC module configuration information */
typedef struct odbmdlc {
     short   from;
     short   dram;
     short   sram;
     short   pmc;
     short   crtc;
     short   servo12;
     short   servo34;
     short   servo56;
     short   servo78;
     short   sic;
     short   pos_lsi;
     short   hi_aio;
     short   reserve[12];
     short   drmmrc;
     short   drmarc;
     short   pmcmrc;
     short   dmaarc;
     short   iopt;
     short   hdiio;
     short   gm2gr1;
     short   crtgr2;
     short   gm1gr2;
     short   gm2gr2;
     short   cmmrb;
     short   sv5axs;
     short   sv7axs;
     short   sicaxs;
     short   posaxs;
     short   hamaxs;
     short   romr64;
     short   srmr64;
     short   dr1r64;
     short   dr2r64;
     short   iopio2;
     short   hdiio2;
     short   cmmrb2;
     short   romfap;
     short   srmfap;
     short   drmfap;
     short   drmare;
     short   pmcmre;
     short   dmaare;
     short   frmbgg;
     short   drmbgg;
     short   asrbgg;
     short   edtpsc;
     short   slcpsc;
     short   reserve2[34];
} ODBMDLC ;

/* cnc_rdpscdproc:read processing condition file (processing data) */
/* cnc_wrpscdproc:write processing condition file (processing data) */
typedef struct iodbpscd {
	short   slct;
	long    feed;
	short   power;
	short   freq;
	short   duty;
	short   g_press;
	short   g_kind;
	short   g_ready_t;
	short   displace;
	long    supple;
	short   edge_slt;
	short   appr_slt;
	short   pwr_ctrl;
    long    displace2;
    char    gap_axis;
    char    feed_dec ;
    char    supple_dec ;
    char    dsp2_dec;
} IODBPSCD ;

/* cnc_rdpscdproc2:read processing condition file (processing data) */
/* cnc_wrpscdproc2:write processing condition file (processing data) */
typedef struct iodbpscd2 {
    long    slct ;
    long    feed ;
    short   power ;
    short   freq ;
    short   duty ;
    short   g_press ;
    short   g_kind ;
    short   g_ready_t ;
    short   displace ;
    long    supple ;
    short   edge_slt ;
    short   appr_slt ;
    short   pwr_ctrl ;
    long    displace2 ;
    char    gap_axis ;
    char    feed_dec ;
    char    supple_dec ;
    char    dsp2_dec ;
    short   pb_power ;
    short   reserve[8] ;
} IODBPSCD2 ;

/* cnc_rdpscdpirc:read processing condition file (piercing data) */
/* cnc_wrpscdpirc:write processing condition file (piercing data) */
typedef struct iodbpirc {
	short   slct;
	short   power;
	short   freq;
	short   duty;
	short   i_freq;
	short   i_duty;
	short   step_t;
	short   step_sum;
	long    pier_t;
	short   g_press;
	short   g_kind;
	short   g_time;
	short   def_pos;
    long    def_pos2;
    char    gap_axis;
    char    def_pos2_dec;
    short   pb_power;
} IODBPIRC ;

/* cnc_rdpscdedge:read processing condition file (edging data) */
/* cnc_wrpscdedge:write processing condition file (edging data) */
typedef struct iodbedge {
	short   slct;
	short   angle;
	short   power;
	short   freq;
	short   duty;
	long    pier_t;
	short   g_press;
	short   g_kind;
	long    r_len;
	short   r_feed;
	short   r_freq;
	short   r_duty;
	short   gap;
	short   reserve[4];
} IODBEDGE ;

/* cnc_rdpscdslop:read processing condition file (slope data) */
/* cnc_wrpscdslop:write processing condition file (slope data) */
typedef struct iodbslop {
	long    slct;
	long    upleng;
	short   upsp[10];
	long    dwleng;
	short   dwsp[10];
    char    upleng_dec;
    char    dwleng_dec;
	short   reserve[9];
} IODBSLOP ;

/* cnc_rdlpwrdty:read power controll duty data */
/* cnc_wrlpwrdty:write power controll duty data */
typedef struct iodblpwdt {
	short   slct;
	short   dty_const;
	short   dty_min;
	short   reserve[6];
} IODBLPWDT ;

/* cnc_rdlpwrdat:read laser power data */
typedef struct odblopdt {
	short   slct;
	short   pwr_mon;
	short   pwr_ofs;
	short   pwr_act;
	long    feed_act;
	char    feed_dec;
	char    reserve;
	short   reserves[3];
} ODBLOPDT ;

/* cnc_rdlagslt:read laser assist gas selection */
/* cnc_wrlagslt:write laser assist gas selection */
typedef struct iodblagsl {
	short   slct;
	short   ag_slt;
	short   agflow_slt;
    short   ag_press;
    short   ag_ready_t;
    short   reserve[4];
} IODBLAGSL ;

/* cnc_rdlagst:read laser assist gas flow */
/* cnc_wrlagst:write laser assist gas flow */
typedef struct iodblagst {
	struct {
		short   slct;
		short   pre_time;
		short   pre_press;
		short   proc_press;
		short   end_time;
		short   end_press;
		short   reserve[3];
	} gasflow[3] ;
} IODBLAGST ;

/* cnc_rdledgprc:read laser power for edge processing */
/* cnc_wrledgprc:write laser power for edge processing */
typedef struct iodblegpr {
	short   slct;
	short   power;
	short   freq;
	short   duty;
	short   reserve[5];
} IODBLEGPR ;

/* cnc_rdlprcprc:read laser power for piercing */
/* cnc_wrlprcprc:write laser power for piercing */
typedef struct iodblpcpr {
	short   slct;
	short   power;
	short   freq;
	short   duty;
	long    time;
	short   reserve[4];
} IODBLPCPR ;

/* cnc_rdlcmddat:read laser command data */
typedef struct iodblcmdt {
	short   slct;
	long    feed;
	short   power;
	short   freq;
	short   duty;
	short   g_kind;
	short   g_ready_t;
	short   g_press;
	short   error;
	long    dsplc;
	long    error2;
    char    gap_axis;
    char    feed_dec;
    char    dsplc_dec;
    char    error2_dec;
    short   pb_power ;
	short   reserve[2];
} ODBLCMDT ;

/* cnc_rdlactnum:read active number */
typedef struct odblactn {
	short   slct;
	short   act_proc;
	short   act_pirce;
	short   act_slop;
	short   reserve[5];
} ODBLACTN ;

/* cnc_rdlcmmt:read laser comment */
typedef struct odblcmmt {
	char    comment[25];
} ODBLCMMT ;

/* cnc_rdpwofsthis:read power correction factor history data */
typedef struct odbpwofst {
        long             pwratio;
        long             rfvolt;
        unsigned short   year;
        unsigned short   month;
        unsigned short   day;
        unsigned short   hour;
        unsigned short   minute;
        unsigned short   second;
} ODBPWOFST;

/* cnc_rdmngtime:read management time */
/* cnc_wrmngtime:write management time */
typedef struct iodbmngtime {
        unsigned long    life;
        unsigned long    total;
} IODBMNGTIME;

/* cnc_rddischarge:read data related to electrical discharge at power correction ends */
typedef struct odbdischrg {
        unsigned short   aps;
        unsigned short   year;
        unsigned short   month;
        unsigned short   day;
        unsigned short   hour;
        unsigned short   minute;
        unsigned short   second;
        short            hpc;
        short            hfq;
        short            hdt;
        short            hpa;
        long             hce;
        long             rfi[8];
        long             rfv[8];
        long             dci[8];
        long             dcv[8];
        long             dcw[8];
} ODBDISCHRG;

/* cnc_rddischrgalm:read alarm history data related to electrical discharg */
typedef struct odbdischrgalm {
        unsigned short   year;
        unsigned short   month;
        unsigned short   day;
        unsigned short   hour;
        unsigned short   minute;
        unsigned short   second;
        long             almnum;
        unsigned long    psec;
        short            hpc;
        short            hfq;
        short            hdt;
        short            hpa;
        long             hce;
        unsigned short   asq;
        unsigned short   psu;
        unsigned short   aps;
        short            dummy;
        long             rfi[8];
        long             rfv[8];
        long             dci[8];
        long             dcv[8];
        long             dcw[8];
        short            almcd[8];
} ODBDISCHRGALM;

/* cnc_rdlppfbdt:read power feedback data */
/* cnc_wrlppfbdt:write power feedback data */
typedef struct idblppfbfg {
        short   s_no;
        short   slct;
        short   s_freq;
        short   e_freq;
        short   s_duty;
        short   e_duty;
} IDBLPPFBFG ;

typedef struct iodblppfbdt {
	short   ppower;
        short   dummy;
        short   freq[10];
        short   duty[10];
        short   rpower[10][10];
} IODBLPPFBDT ;

/* cnc_gettimer:get date and time from cnc */
/* cnc_settimer:set date and time for cnc */
typedef struct iodbtimer {
	short	type ;
	short	dummy ;
	union {
		struct {
			short	year ;
			short	month ;
			short	date ;
		} date ;
		struct {
			short	hour ;
			short	minute ;
			short	second ;
		} time ;
	} data ;
} IODBTIMER ;

/* cnc_rdtimer:read timer data from cnc */
/* cnc_wrtimer:write timer data for cnc */
typedef struct iodbtime {
	long	minute ;
	long	msec ;
} IODBTIME ;

/* cnc_rdtlctldata: read tool controll data */
/* cnc_wrtlctldata: write tool controll data */
typedef struct iodbtlctl {
	short	slct;
	short	used_tool;
	short	turret_indx;
	long	zero_tl_no;
	long	t_axis_move;
	long	total_punch[2];
    char    t_axis_dec;
    char    reserve;
    short   reserves[10];
} IODBTLCTL ;

/* cnc_rdtooldata: read tool data */
/* cnc_wrtooldata: read tool data */
typedef struct iodbtldt {
	short	slct;
	long	tool_no;
	long	x_axis_ofs;
	long	y_axis_ofs;
	long	turret_pos;
	long	chg_tl_no;
	long	punch_count;
	long	tool_life;
	long	m_tl_radius;
	long	m_tl_angle;
	char	tl_shape;
	long	tl_size_i;
	long	tl_size_j;
	long	tl_angle;
    char    x_axis_dec;
    char    y_axis_dec;
    char    turret_dec;
    char    m_radius_dec;
    char    m_angle_dec;
    char    tl_size_i_dec;
    char    tl_size_j_dec;
    char    tl_angle_dec;
    short   reserve[2];
} IODBTLDT ;

/* cnc_rdmultitldt: read multi tool data */
/* cnc_wrmultitldt: write multi tool data */
typedef struct iodbmlttl {
	short	slct;
	short	m_tl_no;
	long	m_tl_radius;
	long	m_tl_angle;
	long	x_axis_ofs;
	long	y_axis_ofs;
	char	tl_shape;
	long	tl_size_i;
	long	tl_size_j;
	long	tl_angle;
    char    m_radius_dec;
    char    m_angle_dec;
    char    x_axis_dec;
    char    y_axis_dec; 
    char    tl_size_i_dec;
    char    tl_size_j_dec;
    char    tl_angle_dec; 
    char    reserve; 
    long    reserves[5];
} IODBMLTTL ;

/* cnc_rdmtapdata: read multi tap data */
/* cnc_wrmtapdata: write multi tap data */
typedef struct iodbmtap {
	short	slct;
	long	tool_no;
	long	x_axis_ofs;
	long	y_axis_ofs;
	long	punch_count;
	long	tool_life;
	long	reserve[11];
} IODBMTAP ;

/* cnc_rdtoolinfo: read tool information */
typedef struct odbptlinf {
	short	tld_max;
	short	mlt_max;
	short	reserve;
	short	tld_size[16];
	short	mlt_size[16];
	short	reserves[16];
} ODBPTLINF ;

/* cnc_rdsafetyzone: read safetyzone data */
/* cnc_wrsafetyzone: write safetyzone data */
typedef struct iodbsafe {
	short	slct;
	long	data[3];
} IODBSAFE ;

/* cnc_rdtoolzone: read toolzone data */
/* cnc_wrtoolzone: write toolzone data */
typedef struct iodbtlzn {
	short	slct;
	long	data[2];
} IODBTLZN ;

/* cnc_rdacttlzone: read active toolzone data */
typedef struct odbacttlzn {
	short	act_no;
	long	data[2];
} ODBACTTLZN ;

/* cnc_rdbrstrinfo:read block restart information */
typedef struct odbbrs {
    long dest[MAX_AXIS];
    long dist[MAX_AXIS];
} ODBBRS ;		/*  In case that the number of axes is 10 */

/* cnc_rdradofs:read tool radius offset for position data */
typedef struct odbrofs {
    short mode;
    short pln_axes[2];
    long ofsvct[2];
} ODBROFS ;

/* cnc_rdlenofs:read tool length offset for position data */
typedef struct odblofs {
    short mode;
    long ofsvct[MAX_AXIS];
} ODBLOFS ;		/*  In case that the number of axes is 10 */

/* cnc_rdfixcycle:read fixed cycle for position data */
typedef struct odbfix {
    short mode;
    short pln_axes[2];
    short drl_axes;
    long i_pos;
    long r_pos;
    long z_pos;
    long cmd_cnt;
    long act_cnt;
    long cut;
    long shift[2];
} ODBFIX ;

/* cnc_rdcdrotate:read coordinate rotate for position data */
typedef struct odbrot {
    short mode;
    short pln_axes[2];
    long center[2];
    long angle;
} ODBROT ;

/* cnc_rd3dcdcnv:read 3D coordinate convert for position data */
typedef struct odb3dcd {
    short mode;
    short dno;
    short cd_axes[3];
    long center[2][3];
    long direct[2][3];
    long angle[2];
} ODB3DCD ;

/* cnc_rdmirimage:read programable mirror image for position data */
typedef struct odbmir {
    short mode;
    long mir_flag;
    long mir_pos[MAX_AXIS];
} ODBMIR ;		/*  In case that the number of axes is 10 */

/* cnc_rdscaling:read scaling data for position data */
typedef struct odbscl {
    short mode;
    long center[MAX_AXIS];
    long magnif[MAX_AXIS];
} ODBSCL ;		/*  In case that the number of axes is 10 */

/* cnc_rd3dtofs:read 3D tool offset for position data */
typedef struct odb3dto {
    short mode;
    short ofs_axes[3];
    long ofsvct[3];
} ODB3DTO ;

/* cnc_rdposofs:read tool position offset for position data */
typedef struct odbpofs {
    short mode;
    long ofsvct[MAX_AXIS];
} ODBPOFS ;		/*  In case that the number of axes is 10 */

/* cnc_rdhpccset:read hpcc setting data */
/* cnc_wrhpccset:write hpcc setting data */
typedef struct iodbhpst {
    short       slct ;
    short       hpcc ;
    short       multi ;
    short       ovr1 ;
    short       ign_f ;
    short       foward ;
    long        max_f ;
    short       ovr2 ;
    short       ovr3 ;
    short       ovr4 ;
    long        reserve[7] ;
} IODBHPST ;

/* cnc_rdhpcctupr:read hpcc tuning data ( parameter input ) */
/* cnc_wrhpcctupr:write hpcc tuning data ( parameter input ) */
typedef struct iodbhppr {
    struct {
        short   slct ;
        short   diff ;
        short   fine ;
        short   acc_lv ;
        long    max_f ;
        short   bipl ;
        short   aipl ;
        long    corner ;
        short   clamp ;
        long    radius ;
        long    max_cf ;
        long    min_cf ;
        long    foward ;
        long    reserve[5] ;
    }tune[3] ;
} IODBHPPR ;

/* cnc_rdhpcctuac:read hpcc tuning data ( acc input ) */
/* cnc_wrhpcctuac:write hpcc tuning data ( acc input ) */
typedef struct iodbhpac {
    struct {
        short   slct ;
        short   diff ;
        short   fine ;
        short   acc_lv ;
        long    bipl ;
        short   aipl ;
        long    corner ;
        long    clamp ;
        long    c_acc ;
        long    foward ;
        long    reserve[8] ;
    }tune[3] ;
} IODBHPAC ;

/* cnc_rd3dtooltip:read tip of tool for 3D handle */
/* cnc_rd3dmovrlap:read move overrlap of tool for 3D handle */
typedef struct odb3dhdl {
	short	axes[5] ;
	long	data[5] ;
} ODB3DHDL ;

/* cnc_rd3dpulse:read pulse for 3D handle */
typedef struct odb3dpls {
	long	right_angle_x ;
	long	right_angle_y ;
	long	tool_axis     ;
	long	tool_tip_a_b  ;
	long	tool_tip_c    ;
} ODB3DPLS ;

/* cnc_rd5dtooltip:read tip of 5 axis manufacture send handle */
/* cnc_rd5dtoolmac:read machine axis of 5 axis manufacture send handle */
typedef struct odb5dhdl {
	char	name[4];
	long	data   ;
	short	dec    ;
	short	flag   ;
	short	axis   ;
} ODB5DHDL ;

/* cnc_rd5dpulse:read pulse of 5 axis manufacture send handle */
typedef struct odb5dpls {
	char	name[3];
	long	data   ;
	short	dec    ;
} ODB5DPLS ;

/* cnc_rdaxisname: read axis name */
typedef struct odbaxisname {
    char name;          /* axis name */
    char suff;          /* suffix */
} ODBAXISNAME ;

/* cnc_rdspdlname: read spindle name */
typedef struct odbspdlname {
    char name;          /* spindle name */
    char suff1;         /* suffix */
    char suff2;         /* suffix */
    char suff3;         /* suffix */
} ODBSPDLNAME ;

/* cnc_rdrelaxis: read relative axis */
typedef struct odbrelaxis {
    short path;          /* path number */
    short rel_axis;      /* axis number */
} ODBRELAXIS ;

/* cnc_wrunsolicprm: Set the unsolicited message parameters */
/* cnc_rdunsolicprm: Get the unsolicited message parameters */
typedef struct iodbunsolic {
    char            ipaddr[16] ;
    unsigned short  port ;
    short           reqaddr ;
    short           pmcno ;
    short           retry ;
    short           timeout ;
    short           alivetime;
    short           setno ;
    union {
        struct {
            short   type ;
            short   rdaddr ;
            short   rdno ;
            short   rdsize ;
        } pmc ;
        struct {
            short   type ;
            long    dummy1 ;
            short   dummy2 ;
        } dmy ;
    } rddata[3] ;
} IODBUNSOLIC ;

/* cnc_wrunsolicprm2: Set the unsolicited message parameters(2) */
/* cnc_rdunsolicprm2: Get the unsolicited message parameters(2) */
typedef struct unsolicmsg_type_prm {
    unsigned short      type;
    char                dummy1[2];
    union {
        struct {
            unsigned short  path;
            short           addr;
            unsigned long   no;
            unsigned long   size;
        } pmc;
        struct {
            unsigned short  path;
            char            dummy2[2];
            unsigned long   no; 
            unsigned long   num;
        } macro;
    } prm;
} UNSOLICMSG_TYPE_PRM;

typedef struct iodbunsolic2 {
    char                ipaddr[64];
    unsigned long       port;
    unsigned short      retry;
    unsigned short      timeout;
    unsigned short      alivetime;
    char                dummy1[8];
    UNSOLICMSG_TYPE_PRM cntrl;
    unsigned short      transnum;
    char                dummy2[14];
    UNSOLICMSG_TYPE_PRM trans[3];
} IODBUNSOLIC2;

/* cnc_rdunsolicmsg: Reads the unsolicited message data */
typedef struct idbunsolicmsg {
    short   getno ;
    struct {
        short   rdsize ;
        void    *data ;
    } msg[3] ;
} IDBUNSOLICMSG ;

/* cnc_rdunsolicmsg2: Reads the unsolicited message data(2) */
typedef struct unsolicmsg_type_msg {
    unsigned short      type;
    char                dummy1[2];
    union {
        struct {
            unsigned short  path;
            char            dummy2[2];
            unsigned long   size;
            void            *data;
        } pmc;
        struct {
            unsigned short  path;
            char            dummy3[2];
            unsigned long   num;
            void            *data;
        } macro;
    } msg;
} UNSOLICMSG_TYPE_MSG ;

typedef struct idbunsolicmsg2 {
    unsigned short      getnum;
    char                dummy[2];
    UNSOLICMSG_TYPE_MSG get[3];
} IDBUNSOLICMSG2 ;

/* cnc_wrtrqlimit: Set torque limit data */
typedef struct idbtrq {
    short   datano;         /* dummy */
    short   type;           /* axis number */
    unsigned short data[MAX_AXIS]; /* torque limit data */
} IDBTRQ;

/* cnc_rdftrq_info: Get setting information of "Fine toruqe sensing function" */
typedef struct {
	char	smpl_enbl ;			/* sample data save function flag	*/
	char    cycle ;				/* sampling cycle					*/
	char    axis_num ;			/* number of object axes			*/
	char    dummy1 ;			/* dummy							*/
} ODBP_FTRQ_PRM_INF ;


/* embetb_rdparam_w:read embedded ethernet parameter for FS160is/180is-WB */
/* embetb_wrparam_w:write embedded ethernet parameter for FS160is/180is-WB */
typedef struct embtcpprmw {
	char			IPAddress[16];
	char			SubNetMask[16];
	char			RouterIPAddress[16];
} EMBTCPPRMW;

typedef struct fwlibprmw {
	unsigned short	TcpPort;
	unsigned short	UdpPort;
	unsigned short	UdpInterval;
} FWLIBPRMW;

typedef struct flinkprmw {
	char			IPAddress[16];
	unsigned short	Port;
} FLINKPRMW;

typedef struct iodbembethprmw {
	union {
		EMBTCPPRMW	tcpip;
		FWLIBPRMW	fwlib;
		FLINKPRMW	flink;
		char		MACAddress[13];
	} embethprm;
} IODBEMBETHPRMW;

/* cnc_rdpm_item:read maintenance item status */
/* cnc_wrpm_item:write maintenance item status */
typedef struct iodbpmainte {
    char   name[62];    /* name */
    long   type;        /* life count type */
    long   total;       /* total life time (minite basis) */
    long   remain;      /* life rest time */
    long   stat;        /* life state */
} IODBPMAINTE ;

/* cnc_rdofslength:read tool length offset data */
typedef struct odbofslen {
     long    len;    /* tool length offset */
     long    dec;    /* decimal point */
} ODBOFSLEN ;

/* cnc_sysinfo_ex:read CNC system path information */
typedef struct odbsysex {
    short max_axis;       /* maximum axis number */
    short max_spdl;       /*  */
    short max_path;       /*  */
    short max_mchn;       /*  */
    short ctrl_axis;      /*  */
    short ctrl_srvo;      /*  */
    short ctrl_spdl;      /*  */
    short ctrl_path;      /*  */
    short ctrl_mchn;      /*  */
    short addinfo ;       /* additional information	*/
    short reserved[2];    /* reserve		 		*/
    struct {
        short system;     /* M/T/TT <ascii char> */
        short group;      /*  */
        short attrib;     /*  */
        short ctrl_axis;  /*  */
        short ctrl_srvo;  /*  */
        short ctrl_spdl;  /*  */
        short mchn_no;    /*  */
        short reserved;
    } path[MAX_CNCPATH] ;
} ODBSYSEX ;

/* cnc_rdwseterror:read Work-piece setting error data */
/* cnc_wrwseterror:write Work-piece setting error data */
typedef struct wseterror {
     long      data;      /*  */
     short     dec;       /*  */
	 short	   dummy;
} REALWSET ;

typedef struct iodbwseterror {
	long	d_no;			/* active group number */
	long	data_act[6];	/* active data */
	long	dp_act[6];		/* decimal point for active data */
	long	dsp_ix[2];		/* axisnumber for axisname */
	REALWSET  data[WSETER_GRP][WSETER_DATA];
} IODBWSETERROR ;

/* cnc_rdlrntrnsdata:read Transfer Data */
typedef struct odbtrns {
		short	status ;				/* transfer status */
		short	pct ;					/* transfer ratio (%) */
		short	type ;					/* transfer type */
		char	dummy[2] ;
} ODBTRNS;

/* cnc_rdlrninfo:read Parts Learning Data */
typedef struct odblrninfo {
	char	name[33] ;			/* program name */
	char	dummy1[3] ;
	char	axis[4][4] ;		/* No.1-No.4 Learning axis name */
	short	year ;				/* update(year) */
	short	month ; 			/* update(month) */
	short	day ;				/* update(day) */
	short	hour ;				/* update(hour) */
	short	minute ;			/* update(minute) */
	short	second ;			/* update(second) */
	char	comment[33] ;		/* comment */
	char	dummy2[3] ;
} ODBLRNINFO;

/* cnc_rdlrninfo2:read Parts Learning Data */
typedef struct odblrninfo2 {
	char	name[33] ;			/* program name */
	char	dummy1[3] ;
	char	axis[20][4] ;		/* No.1-No.20 Learning axis name */
	short	year ;				/* update(year) */
	short	month ; 			/* update(month) */
	short	day ;				/* update(day) */
	short	hour ;				/* update(hour) */
	short	minute ;			/* update(minute) */
	short	second ;			/* update(second) */
	char	comment[33] ;		/* comment */
	char	dummy2[3] ;
} ODBLRNINFO2;

/* cnc_rdlrninfol:read Learning Data  */
typedef struct odblrninfol {
	char	axis[4];			/* Learning axis name */
	char	name[33];			/* program name */
	char	comment[33];		/* comment */
	char    path;               /* path */
	char	dummy1;
}ODBLRNINFOL;

/* cnc_rdlrnprfcmnt:read Profile Data  */
typedef struct odblrnprf {
        char    status ;            /* status */
        char    comment[17] ;       /* comment */
        char    path ;              /* path */
        char    dummy1 ;
}ODBLRNPRF;

/* cnc_sendkey:Send MDI key information */
typedef struct odbkeyinfo {
	unsigned long key[2];	/* key info */
} ODBKEYINFO;

/* cnc_3dchkdata:Reads 3D interference chaeck data */
typedef struct prginf {
    unsigned long prgid[4];
} PRGINF;

typedef struct toolinf {
    long  tcode;
    long  magazin;
    long  pot;
} TOOLINF;

typedef struct posinf {
    struct {
        short prec_pntr;
        short prec_time;
        long  data[MAX_POS_BUF];
        short dec;
        short unit;
    } pos;
    struct {
        long  data;
        short dec;
        short unit;
    } feed;
} POSINF;

typedef struct odb3dchk {
    long  pathno;
    struct {
        long    mode;
        PRGINF  prginf;
        long    dummy[2];
        long    mcode[2];
        TOOLINF tlinf;
        long    dummy2[3];
        long    ctrlaxis;
        POSINF  data[MAX_AXIS];
    } path[MAX_CNCPATH] ;
} ODB3DCHK;

typedef struct odb3dmtbinfo {
    PRGINF  prginf;
    long    mcode[3];
    long    bcode;
    TOOLINF tlinf;
    long    hisorder;
    long    dummy[3];
} ODB3DMTBINFO;

typedef struct odb3dmtbinfo2 {
    unsigned long    path;
    PRGINF           prginf;
    long             mcode[3];
    long             bcode;
    TOOLINF          tlinf;
    long             dummy[4];
} ODB3DMTBINFO2;

/* cnc_3dchk_mchn_stop: Stop machine for 3D interference check */
typedef struct idb3dmstop {
    struct {
        unsigned long   plus;
        unsigned long   minus;
    } path[MAX_CNCPATH] ;
} IDB3DMSTOP;


/* cnc_read_cexeinfo */
typedef struct cexeinfo {
    long    cond;           /*      condition       */
    long    cycle;          /*    cycle of start    */
    long    count;          /*    number of start   */
    long    time;           /*    execution time    */
    long    dummy1;         /*        dummy1        */
    long    dummy2;         /*        dummy2        */
    long    dummy3;         /*        dummy3        */
    long    dummy4;         /*        dummy4        */
} CEXEINFO ;

/* cnc_cannedcycle:read canned command data */
typedef struct cmnddata {
    double  val;         /* Command value */
    long    dec;         /* Decimal point */
    long    dummy;       /* dummy */
} CMNDDATA;

typedef struct odbcancmd {
    CMNDDATA  p_data ;      /* P command */
    CMNDDATA  q_data ;      /* Q command */
    CMNDDATA  r_data ;      /* R command */
    CMNDDATA  z_data ;      /* Z command */
} ODBCANCMD ;

/*-----------------------------------*/
/* CNC: trouble diagnosis            */
/*-----------------------------------*/
/* cnc_mdg_rdalminfo */
typedef struct iodbmdginfo {
    long alm_no;
    short type;
    short axis;
    short path;
    short reserved;
} IODBMDGINFO;

/* cnc_mdg_rdmsg */
typedef struct odbmdgmsg {
    long alm_no;
    short msgidx;
    short reserved;
    char type[4];
    char part[4];
    char level[4];
    char add_inf[4];
    char mark[20];
    char message[100];
    char cause[300];
} ODBMDGMSG;

/* cnc_mdg_rdflow */
typedef struct odbmdgflow {
    short msgidx;
    short yesidx;
    short noidx;
    short reserved;
    char message[400];
    short detail;
    short operate;
} ODBMDGFLOW;

/* cnc_mdg_rddtmsg */
typedef struct odbmdgdtmsg {
    char message[1600];
    unsigned long imgid;
} ODBMDGDTMSG;

/* cnc_mdg_rdalminfoview2 */
typedef union odbmdgval {
    long lval;
    unsigned long ulval;
    short sval;
    unsigned short usval;
    char cval;
    unsigned char ucval;
} ODBMDGVAL;

typedef struct odbmdgdt {
    ODBMDGVAL dt;
    short fp;
    short reserved;
} ODBMDGDT;

typedef struct odbsigdio {
    char sgnl1;
    char sgnl2;
    char sgnl3;
    char sgnl4;
} ODBSIGDIO;

typedef struct odbsv2_grp1 {
    long cmd_pls;
    long fb_pls;
    long refc;
    long pos_err;
    ODBMDGDT act_spd;
    unsigned short amr;
    short reserved;
} ODBSV2_GRP1;

typedef struct odbsv2_grp2 {
    ODBMDGDT mt_cur;
    short trq_cmd;
    short efc_cur;
    unsigned short dlvl;
    unsigned short heat;
    short opt;
    short opt2;
} ODBSV2_GRP2;

typedef struct odbsv2_grp3 {
    ODBMDGDT ps_vumb;
    ODBMDGDT ps_vthd;
    ODBMDGDT freq;
    unsigned short ps_vrms;
    unsigned short ps_cur;
    unsigned short dvolt;
    unsigned char ps_statf;
    char reserved;
} ODBSV2_GRP3;

typedef struct odbsv2_grp4 {
    ODBMDGDT resistance;
    unsigned char detect_res;
    char reserved[7];
} ODBSV2_GRP4;

typedef struct odbsv2_grp5 {
    unsigned short ps_dgn;
    unsigned short ps_sub_dgn;
    unsigned short sv_dgn;
    unsigned char ps_int_tmp;
    unsigned char ps_sink_tmp;
    unsigned char sv_int_tmp;
    unsigned char sv_sink_tmp;
    unsigned char amp_grp;
    unsigned char amp_slv;
} ODBSV2_GRP5;

typedef struct odbsv2_grp6 {
    unsigned short sv_up_err1;
    unsigned short sv_up_err2;
    unsigned short sv_lw_err1;
    unsigned short sv_lw_err2;
    unsigned short sv_up_jt1;
    unsigned short sv_up_jt2;
    unsigned short sv_lw_jt1;
    unsigned short sv_lw_jt2;
    unsigned short sdu_up_err1;
    unsigned short sdu_up_err2;
    unsigned short sdu_lw_err1;
    unsigned short sdu_lw_err2;
    unsigned short sdu_up_jt1;
    unsigned short sdu_up_jt2;
    unsigned short sdu_lw_jt1;
    unsigned short sdu_lw_jt2;
} ODBSV2_GRP6;

typedef struct odbsv2_grp7 {
    unsigned short id_intp;
    unsigned short id_com;
    unsigned short id_wrn;
    unsigned short ed_intp;
    unsigned short ed_com;
    unsigned short ed_wrn;
    short sv_dat1;
    short sv_dat2;
    short sv_dat3;
    short sv_dat4;
} ODBSV2_GRP7;

typedef struct odbsp2_grp1 {
    long motion;
    short cmd_spd;
    char mode;
    char gear;
    char osel;
    char reserved[3];
    ODBSIGDIO sig_in;
    ODBSIGDIO sig_out;
} ODBSP2_GRP1;

typedef struct odbsp2_grp2 {
    long pos_err;
    long syn_err;
    long sp_spd;
    long mt_spd;
    ODBMDGDT mt_cur;
    unsigned short ldmtr;
    short trq_cmd;
    char heat_mt;
    char heat_amp;
    char reserved[2];
} ODBSP2_GRP2;

typedef struct odbsp2_grp3 {
    ODBMDGDT ps_vumb;
    ODBMDGDT ps_vthd;
    ODBMDGDT freq;
    unsigned short ps_vrms;
    unsigned short ps_cur;
    unsigned short dvolt;
    unsigned char ps_statf;
    char reserved;
} ODBSP2_GRP3;

typedef struct odbsp2_grp4 {
    ODBMDGDT resistance;
    unsigned char detect_res;
    char reserved[7];
} ODBSP2_GRP4;

typedef struct odbsp2_grp5 {
    unsigned short ps_dgn;
    unsigned short ps_sub_dgn;
    unsigned short sp_dgn;
    unsigned char ps_int_tmp;
    unsigned char ps_sink_tmp;
    unsigned char sp_int_tmp;
    unsigned char sp_sink_tmp;
    unsigned char amp_grp;
    unsigned char amp_slv;
} ODBSP2_GRP5;

typedef struct odbsp2_grp6 {
    unsigned short sp_up_err1;
    unsigned short sp_up_err2;
    unsigned short sp_lw_err1;
    unsigned short sp_lw_err2;
    unsigned short sp_up_jt1;
    unsigned short sp_up_jt2;
    unsigned short sp_lw_jt1;
    unsigned short sp_lw_jt2;
} ODBSP2_GRP6;

typedef struct odbsp2_grp7 {
    ODBMDGDT iab_amplt;
    ODBMDGDT eab_amplt;
    short iab_ofs_a;
    short iab_ofs_b;
    short iab_noise;
    short eab_ofs_a;
    short eab_ofs_b;
    short eab_noise;
    unsigned short iab_max_flt;
    unsigned short eab_max_flt;
} ODBSP2_GRP7;

typedef struct odbsp2_grp8 {
    unsigned short isncr_intp;
    unsigned short isncr_com;
    unsigned short isncr_wrn;
    unsigned short esncr_intp;
    unsigned short esncr_com;
    unsigned short esncr_wrn;
    short sp_dat1;
    short sp_dat2;
    short sp_dat3;
    short sp_dat4;
} ODBSP2_GRP8;

typedef struct odblat_grp1 {
    unsigned long nnum;
    char prog[36];
    char year;
    char mon;
    char day;
    char hour;
    char min;
    char sec;
    char reserved[2];
} ODBLAT_GRP1;

typedef union odbviewgrp2 {
    ODBSV2_GRP1 sv1;
    ODBSV2_GRP2 sv2;
    ODBSV2_GRP3 sv3;
    ODBSV2_GRP4 sv4;
    ODBSV2_GRP5 sv5;
    ODBSV2_GRP6 sv6;
    ODBSV2_GRP7 sv7;
    ODBSP2_GRP1 sp1;
    ODBSP2_GRP2 sp2;
    ODBSP2_GRP3 sp3;
    ODBSP2_GRP4 sp4;
    ODBSP2_GRP5 sp5;
    ODBSP2_GRP6 sp6;
    ODBSP2_GRP7 sp7;
    ODBSP2_GRP8 sp8;
    ODBLAT_GRP1 lat1;
} ODBVIEWGRP2;

/* cnc_mdg_rdwvdata */
typedef struct odbmdgwvdt {
    long ldata[500];
    unsigned short p_dec;
    unsigned short num;
    unsigned short channel;
    unsigned short axis;
    unsigned short kind;
    unsigned short interval;
    unsigned short t_cycle;
    char unit;
    char sw_alm;
} ODBMDGWVDT;

/*-----*/
/* CNC */
/*-----*/

/* cnc_srcsrdidinfo */
/* cnc_srcswridinfo */
typedef struct iodbidinf {
	long  id_no;
	short drv_no;
	short acc_element;
	short err_general;
	short err_id_no;
	short err_id_name;
	short err_attr;
	short err_unit;
	short err_min_val;
	short err_max_val;
	short id_name_len;
	short id_name_max;
	char  id_name[60];
	long  attr;
	short unit_len;
	short unit_max;
	char  unit[12];
	long  min_val;
	long  max_val;
} IODBIDINF;

/* cnc_srcsrdexstat */
typedef struct odbsrcsst {
	short acc_element;
	short err_general;
	short err_id_no;
	short err_attr;
	short err_op_data;
} ODBSRCSST;

/* cnc_srcsrdlayout */
typedef struct odbsrcslyt {
	short spndl[4];
	short servo[8];
	char  axis_name[8];
} ODBSRCSLYT;

/*-----*/
/* CNC */
/*-----*/
/* cnc_sdsetchnl */
typedef struct idbchan {
	char            chno;
	char            axis;
	long            datanum;
	unsigned short  datainf;
	short           dataadr;
} IDBCHAN;

/* cnc_sdsetchnl2 */
typedef struct pmc_data {
	short			unittype;
	char			adr;
	unsigned char	bit;
	unsigned short	no;
} PMC_DATA;

/* cnc_sdsetchnl2 */
typedef struct idbchan2 {
	short           chno;
	short           axis;
	long            datanum;
	unsigned short  datainf;
	short           dataadr;
	PMC_DATA		io[16];
} IDBCHAN2;

/* cnc_sdstartsmpl2 */
typedef struct trgdata {
	long		seq_no;
	PMC_DATA	pmc_trg;
} TRG_DATA;

/* cnc_sdbetainfo */
typedef struct odbbinfo {
	short   iochno;
	short   grpno;
	short   axis;
	char    name;
	char    suff;
	short   reserve[3];
} ODBBINFO;

/* cnc_sdsetchnl */
typedef struct odbsd {
	unsigned short  *chadata;
	long            *count;
} ODBSD;

/* cnc_sfbsetchnl */
typedef struct idbsfbchan {
        char            chno;
        char            axis;
        unsigned short  shift;
} IDBSFBCHAN;

/* cnc_sdtsetchnl */
typedef struct idbsdtchan {
		short			type;
		char			chno;
		char			axis;
		unsigned short	shift;
} IDBSDTCHAN;

/* cnc_sdtsetchnl2 */
typedef struct idbsdtchan2 {
	short			type;
	char			chno;
	char			axis;
	unsigned short	shift;
	PMC_DATA		io[16];
} IDBSDTCHAN2;

typedef struct idbsdttrg {
	long		seq_no;
	PMC_DATA	pmc_trg;
} IDBSDTTRG;

/*----------------------------*/
/* CNC : REMOTE DIAGNOSIS I/F */
/*----------------------------*/
/* cnc_pdf_startrmtdgn: Remote Diagnosis Start */
/* cnc_pdf_rdrmtdgn: Read Remote Diagnosis Information */
typedef struct rmtdgn_info {
    unsigned long  receipt_num;	    /* Receipt Number   */
    unsigned long  time;            /* Time             */
    short          status;          /* Status           */
    short          err_num;         /* Error Number     */
    char           err_msg[36];     /* Error Message    */
} OUT_RMTDGNINFO;

/*-------------------------*/
/* CNC : FS18-LN function  */
/*-------------------------*/

/* cnc_allowcnd:read allowanced state */
typedef struct odbcaxis {
    short   dummy ;             /* dummy */
    short   type ;              /* axis number */
    unsigned char    data[MAX_AXIS] ;    /* data value */
} ODBCAXIS ;


/*-----------*/
/* Oxxxxxxxx */
/*-----------*/

/* cnc_rdprgnumo8:read program number under execution */
typedef struct odbproo8 {
     short   dummy[2] ;  /* dummy */
     long    data ;      /* running program number */
     long    mdata ;     /* main program number */
} ODBPROO8 ;

/* cnc_rddynamico8:read all dynamic data */
typedef struct odbdyo8 {
    short   dummy ;
    short   axis ;       /* axis number             */
    short   alarm ;      /* alarm status            */
    long    prgnum ;     /* current program number  */
    long    prgmnum ;    /* main program number     */
    long    seqnum ;     /* current sequence number */
    long    actf ;       /* actual feedrate         */
    long    acts ;       /* actual spindle speed    */
    union {
        struct {
            long    absolute[MAX_AXIS] ;    /* absolute position   */
            long    machine[MAX_AXIS] ;     /* machine position    */
            long    relative[MAX_AXIS] ;    /* relative position   */
            long    distance[MAX_AXIS] ;    /* distance to go      */
        } faxis ;
        struct {
            long    absolute ;  /* absolute position   */
            long    machine ;   /* machine position    */
            long    relative ;  /* relative position   */
            long    distance ;  /* distance to go      */
        } oaxis ;   /* In case of no axis  */
    } pos ;
} ODBDYO8 ;

/* (op)cnc_rdmdipntro8:read execution pointer for MDI operation */
typedef struct odbmdipo8 {
    long   mdiprog;     /* exec. program number */
    long   mdipntr;     /* exec. pointer */
    long   crntprog;    /* prepare program number */
    long   crntpntr;    /* prepare pointer */
} ODBMDIPO8;

/* cnc_rdprogdir2o8:read program directory 2 */
typedef struct prgdir2o8 {
	long	number ;
	long	length ;
	char	comment[51] ;
	char	dummy ;
} PRGDIR2O8;


/*---------------------------------*/
/* CNC : C-EXE SRAM file function  */
/*---------------------------------*/

/* read C-EXE SRAM disk directory */
typedef struct cfileinfo {
	char	fname[12] ;	/* file name */
	long	file_size ;	/* file size (bytes) */
	long	file_attr ;	/* attribute */
	short	year;		/* year */
	short	month;		/* month */
	short	day;		/* day */
	short	hour;		/* hour */
	short	minute;		/* mimute */
	short	second;		/* second */
} CFILEINFO;


/*------------*/
/* CNC : FSSB */
/*------------*/

/* cnc_rdfssb_amp:read amp information */
typedef struct tagODBFSSBAMP {
	short	ln_num;			/* line number */
	short	slave_num;		/* slave number */
	char	name[8];		/* amp name */
	char	seires[8];		/* amp series name */
	char	unit[8];		/* amp unit type */
	char	cur[8]; 		/* amp currect */
	short	axis_num;		/* axis number */
//	short	reserve;		/* reserved */
	char	axis_name[4];	/* axis name */
} ODBFSSBAMP ;

/* cnc_rdfssb_plsmod:read pulse module information */
typedef struct tagODBPLSMDL {
	short	ln_num;			/* line number */
	short	slave_num;		/* slave number */
	char	name[8];		/* pulse module name */
	char	type[8];		/* pulse module type name */
	char	pcb_id[8];		/* pulse module hard ID */
	char	function[32];	/* pulse module function */
} ODBPLSMDL ;

/* cnc_rdfssb_axis:read axis information */
/* cnc_wrfssb_axis:write axis information */
typedef struct tagIODBFSSBAXIS {
	short	axis_num;		/* axis number */
	short	reserve1;		/* reserved */
	char	axis_name[4];	/* axis name */
	char	amp_name[8];	/* amp name */
	short	m1;				/* M1 */
	short	m2;				/* M2 */
	short	m3;				/* M3 */
	short	m4;				/* M4 */
	short	dsp1;			/* 1-DSP */
//	short	spos;			/* SPOS */
	short	cs;				/* Cs */
	short	tndm;			/* tandem */
//	short	egb;			/* EGB */
	short	reserve2;		/* reserved */
} IODBFSSBAXIS ;

/* cnc_rdfssb_mainte:read maintenance information */
typedef struct tagODBFSSBMT {
	short	axis_num;		/* axis number */
	short	reserve;		/* reserved */
	char	axis_name[4];	/* axis name */
	char	amp_name[8];	/* amp name */
	char	amp_seires[8];	/* amp series name */
	char	amp_unit[8];	/* amp unit type */
	char	amp_cur[8];		/* amp maximum current */
	char	amp_edt[8];		/* amp version */
	short	amp_axis_num;	/* amp axis */
	short	test_year;		/* amp tested year */
	short	test_month;		/* amp tested month */
	short	test_day;		/* amp tested date */
	short	amp_mainte;		/* amp serial number */
} ODBFSSBMT ;

/* cnc_rdfssb_info:read FSSB information */
typedef struct tagODBFSSBINFO {
	short	card_num;		/* axis card amount */
	struct {
		short	amp_num;	/* amp amount */
		short	plsm_num;	/* pulse module amount */
	} card[8];
} ODBFSSBINFO ;


/* FSSB for 30iB (IFSB) */
typedef struct tagODBIFSBLINE {
    unsigned short  hrv_ln;         /* HRV */
    unsigned short  ax_num_ln;      /* Axis Num */
    unsigned short  sp_num_ln;      /* Spindel Num */
    unsigned short  pm_num_ln;      /* Pulse Module Num */
}ODBIFSBLINE;

typedef struct tagODBIFSBINFO {
    unsigned char   fssb_line_mnt_st;   /* Mount Status */
    unsigned char   reserve;            /* Mount Status */
    unsigned short  card_num;           /* Card Num */
    ODBIFSBLINE     line_info[MAX_IFSB_LINE]; /* Line information */
}ODBIFSBINFO;

typedef struct tagODBFSSBSLVUNT {
    short   slv_unt_num;    /* Slave unit number */
    char    kind;           /* Slave kind */
    char    attrb;          /* Slave attribute */
} ODBIFSBSLVUNT;

typedef struct tagODBIFSBSLUSV {
    short   slave_num;      /* Slave Number */
    short   axis_num;       /* Axis Number */
    char    axis_name[4];   /* Axis Name */
    char    tndm;
    char    reserve[3];
} ODBIFSBSLUSV;

typedef struct tagODBIFSBSVAMP {
    short   slave_num;          /* Slave Number */
    char    name[8];            /* Amp Name */
    char    series[12];         /* Amp Series */
    char    cur[8];             /* Amp Current */
    short   as_axis_num;        /* Axis number for Auto Set */
    char    as_axis_name[4];    /* Axis name for Auto Set */
} ODBIFSBSVAMP;

typedef struct tagODBIFSBSLUSP {
    short   slave_num;      /* Slave Number */
    short   spdl_num;       /* Spindle Number */
    char    spdl_name[4];   /* Spindle Name */
} ODBIFSBSLUSP;

typedef struct tagODBIFSBSLUPM {
    short   slave_num;          /* Slave Number */
    short   axis_num[8];        /* Axis Number */
    char    axis_name[8][4];    /* Axis Name */
} ODBIFSBSLUPM;

typedef struct tagODBIFSBSPAMP {
    short   slave_num;          /* Slave Number */
    char    name[8];            /* Amp Name */
    char    series[12];         /* Amp Series */
    char    pwr[8];             /* Amp Power */
    short   as_spdl_num;        /* Spindle number for Auto Set */
    char    as_spdl_name[4];    /* Spindle name for Auto Set */
} ODBIFSBSPAMP;

typedef struct tagODBIFSBPLSMDL {
    short           slave_num;  /* Slave Number */
    char            name[8];    /* PM Name */
    char            type[8];    /* PM Type */
    unsigned short  pcb_id;     /* PM PCBID */
    char            info[24];   /* PM Information */
} ODBIFSBPLSMDL;

typedef struct tagIODBIFSBAXIS {
    short   axis_num;       /* Axis Number */
    char    axis_name[4];   /* Axis Name */
    short   line;
    char    amp_name[8];    /* Amp Name */
    short   pm[8];          /* M1 - M8 */
    short   cs;             /* Cs */
    short   tndm;           /* tandem */
} IODBIFSBAXIS;

typedef struct tagODBIFSBMNTSV {
    short   axis_num;           /* Axis Number */
    char    axis_name[4];       /* Axis Name */
    short   line;
    char    amp_name[8];        /* Amp Name */
    char    amp_series[12];     /* Amp Series */
    char    amp_cur[8];         /* Amp Current */
    char    amp_edt[8];         /* Amp Edition */
    short   amp_axis_num;       /* Amp Axis Number */
    char    amp_spec_num[23];   /* Amp Specificaion */
    char    amp_serial_num[13]; /* Amp Serial Number */
} ODBIFSBMNTSV;

typedef struct tagODBIFSBMNTSP {
    short   spdl_num;           /* Spindle Number */
    char    spdl_name[4];       /* Spindle Name */
    short   line;
    char    amp_name[8];        /* Amp Name */
    char    amp_series[12];     /* Amp Series */
    char    amp_pwr[8];         /* Amp Power */
    char    amp_edt[8];         /* Amp Edition */
    short   amp_spdl_num;       /* Amp Axis Number */
    char    amp_spec_num[23];   /* Amp Specificaion */
    char    amp_serial_num[13]; /* Amp Serial Number */
} ODBIFSBMNTSP;

typedef struct tagODBIFSBSYSALM {
    long    num_sys_alm;
    short   error_line;
    short   error_slvnum1;
    short   error_slvnum2;
    short   year;
    short   mon;
    short   day;
    short   hour;
    short   min;
    short   sec;
    char    alarm_cause[100];
} ODBIFSBSYSALM;

typedef struct tagODBIFSBFSSBUNT {
    short   slv_unt_num;    /* slave unit number */
    short   fssb_unt_num;   /* fssb unit number */
    char    name[4];        /* name */
} ODBIFSBFSSBUNT;

typedef struct tagODBIFSBCOMSTATDTL {
    long    error_inf;      /* error information */
    long    jitter_inf;     /* jitter information */
    char    n_warning;      /* noise warning flag */
    char    j_warning;      /* jitter warning flag */
    char    reserve[2];     /* reserve */
} ODBIFSBCOMSTATDTL;

typedef struct tagODBIFSBWARNINGMSG {
    short   line;           /* warning line number */
    short   slv_src;        /* warning slave number for source*/
    short   slv_dst;        /* warning slave number for destination */
    short   type;           /* warning type */
    char    wm_typ[32];     /* warning message for type*/
    char    wm_pnt[32];     /* warning message for point*/
} ODBIFSBWARNINGMSG;

typedef struct tagODBIFSBWARNHSTMSG {
    short   year;           /* year of occurrence of warning */
    char    month;          /* month */
    char    day;            /* day */
    char    hour;           /* hour */
    char    minute;         /* minute */
    char    second;         /* second */
    char    dummy;
    ODBIFSBWARNINGMSG   msg_dat;  /* message */
} ODBIFSBWARNHSTMSG;

/*-----------------------------------*/
/* Machine Status Monitor / Recorder */
/*-----------------------------------*/
typedef struct odbmsrhstinf {
    short   year;
    char    month;
    char    day;
    char    hour;
    char    minute;
    char    second;
    char    msu_num;
    char    path_num;
    char    pmc_num;
    unsigned short  nonsave;
    char    save_trigger;
    char    reserve[3];
} ODBMSRHSTINF ;

typedef struct tag_ODBMSUXTERM{
    char    kind;
    char    ch;
    char    atrb;
    char    dec;
    long    data;
}ODBMSUXTERM;

typedef struct tag_ODBMSUYTERM{
    short   data;
    short   dummy;
}ODBMSUYTERM;

typedef struct tag_ODBMSUINF{
    char    pmc_no;
    char    dummy[3];
    long    x_top_adrs;
    long    y_top_adrs;
}ODBMSUINF;

typedef struct odbmsudat {
    ODBMSUINF   inf;
    ODBMSUXTERM x_term[16];
    ODBMSUYTERM y_term[16];
} ODBMSUDAT ;

typedef struct tag_ODBEXPMCSGNLINF{
    char    pmc_no;
    char    kind;
	char	length;
    char    dummy;
    long    top_adrs;
} ODBEXPMCSGNLINF;

typedef struct tag_ODBEXPMCSGNLTERM{
    char    data;
    char    dummy;
} ODBEXPMCSGNLTERM;

typedef struct odbexpmcsgnl {
     ODBEXPMCSGNLINF    inf[2];
     ODBEXPMCSGNLTERM   exsgnlterm[2][32];
} ODBEXPMCSGNL ;

typedef struct odbmsrpmcsgnl {
    long    adrs;
    char    pmc_no;
    char    kind;
    char    data;
    char    mask;
    char    enbl;
    char    dummy[3];
} ODBMSRPMCSGNL ;

typedef struct odbmsrncdat {
    short       sv_num;
    short       sp_num;
    ODBAXDT     mcn[32];
    ODBAXDT     abs[32];
    ODBAXDT     spdl[8];
    ODBAXDT     actf;
    char        ex_prg_name[248];
    long        ex_blk;
    short       aut;
    short       tmmode;
    ODBCMD      m_mdl[5];
    ODBCMD      s_mdl;
    ODBCMD      t_mdl;
    ODBCMD      b_mdl;
} ODBMSRNCDAT ;

/*-----------------*/
/* CNC : EcoMode   */
/*-----------------*/
typedef struct odbpowccyc {
	unsigned long	cycletime ;
	unsigned long	powc_axis ;
	unsigned long	powc_spindle ;
	unsigned long	powc_outer ;
} ODBPOWCCYC ;

typedef struct odbpowcouter {
	unsigned long	ave_pow[8] ;
	unsigned short	ref_ofs ;
	char			ref_adrs ;
	unsigned char	ref_path ;
} ODBPOWCOUTER;

typedef struct odbpowchis {
	unsigned long	get_time ;
	unsigned long	powc_axis ;
	unsigned long	powc_spindle ;
	unsigned long	powc_outer ;
} ODBPOWCHIS ;

typedef struct odbpowchisall {
	ODBPOWCHIS		powchis[30] ;
} ODBPOWCHISALL ;

/*---------------------------------*/
/* CNC : Power Consumption Monitor */
/*---------------------------------*/
/* cnc_pwcm_rd_consump:read power consumption */
typedef struct odbpwcm {
    long consump ;          /* Integral power consumption */
    long regen ;            /* Integral power regeneration */
    long net ;              /* Integral net amount of power consumption */
    long present ;          /* Present net power consumption */
} ODBPWCM ;

typedef struct odbpwcmdat {
    unsigned long time ;           /* Integrating time of power consumption */
    short   axis_num ;             /* Number of servo axis */
    short   spindle_num ;          /* Number of spindle axis */
    ODBPWCM all ;                  /* Power consumption of all axes */
    ODBPWCM axis[MAX_AXIS] ;       /* Power consumption of each servo axis */
    ODBPWCM spindle[MAX_SPINDLE] ; /* Power consumption of each spindle axis */
} ODBPWCMDAT ;

/*---------------*/
/* CNC : GRAPHIC */
/*---------------*/

/* cnc_rd_grppos:read graphic position */
typedef struct posval {
	long	data ;			/* Value */
	long	dec ;			/* Decimal places */
} POSVAL ;

typedef struct odbgrppos {
	POSVAL	abs ;			/* Absolute position */
	POSVAL	mcn ;			/* Machine position */
	short	feed_type ;		/* Feed type */
	short	reserved ;		/* Padding */
} ODBGRPPOS ;

/* cnc_rdgrpaxisinfo:read graphic axis information */
typedef struct odbgrpaxis {
	short	path_num ;		/* Path number */
	short	draw_num ;		/* Drawing axis number */
} ODBGRPAXIS ;

typedef struct odbwact {
    long    data[6] ;       /* Valule */
} ODBWACT ;

#if defined (PMD) /* only Power Mate D/H */
/*------------------------------*/
/* MAXIS: Axis Movement Control */
/*------------------------------*/
/* cnc_opdi:signal operation command */
typedef struct odbopdi {
	short	axis;	/* axis number */
	union {
		char	cdata;
		short	idata;
		long	ldata;
	} u;
} ODBOPDI;

/* cnc_abspoint:absolute movement */
/* cnc_incpoint:incremental movement */
/* cnc_dwell:dwell */
/* cnc_coordre:coordinate establihment */
typedef struct odbpos {
	short	idata;	/* axis number */
	long	ldata;	/* coordinate value */
} ODBPOS;

/* cnc_refpoint:reference point return */
/* cnc_abspoint:absolute movement */
/* cnc_incpoint:incremental movement */
/* cnc_dwell:dwell */
/* cnc_coordre:coordinate establihment */
/* cnc_exebufstat:reading of the executive buffer condition */
typedef struct odbexec {
	short	dummy;		/* dummy */
	char	cdata[2][8];	/* the infomation of the executive condition of */
} ODBEXEC;			/* each PATH                                    */

/* cnc_finstate:Reading of the execution completion condition */
/* cnc_setfin:Release of the reading mode of the execution completion condition */
typedef struct odbfin {
	short	dummy;		/* dummy */
	char	cdata[8];	/* the infomation of the complete notice flag */
} ODBFIN;			/* condition of each PATH                     */
#endif

/*-----*/
/* PMC */
/*-----*/

/* pmc_rdpmcrng:read PMC data(area specified) */
/* pmc_wrpmcrng:write PMC data(area specified) */
#if defined (PMCMEMD)
typedef struct iodbpmc {
    short            type_a ;    /* PMC address type */
    short            type_d ;    /* PMC data type */
    unsigned short   datano_s ;  /* start PMC address */
    unsigned short   datano_e ;  /* end PMC address */
    union {
        char    cdata[5] ;  /* PMC data */
        short   idata[5] ;
        long    ldata[5] ;
        float   fdata[5] ;
        double  dfdata[5] ;
    } u ;
} IODBPMC ; /* In case that the number of data is 5 */
#else
typedef struct iodbpmc {
    short   type_a ;    /* PMC address type */
    short   type_d ;    /* PMC data type */
    short   datano_s ;  /* start PMC address */
    short   datano_e ;  /* end PMC address */
    union {
        char    cdata[5] ;  /* PMC data */
        short   idata[5] ;
        long    ldata[5] ;
        float   fdata[5] ;
        double  dfdata[5] ;
    } u ;
} IODBPMC ; /* In case that the number of data is 5 */
#endif

typedef struct  iodbrwpmc {
    short           type_rw ;
    short           type_a ;
    short           type_d ;
    unsigned short  datano_s ;
    short           length ;
    short           conv ;
    short           err_code ;
    short           reserved;
    void            *data ;
} IODBRWPMC ;

/* pmc_rdpmcinfo:read informations of PMC data */
typedef struct odbpmcinf {
    short   datano ;
    struct {
        char    pmc_adr ;
        char    adr_attr ;
        unsigned short  top_num ;
        unsigned short  last_num ;
    } info[64] ;
} ODBPMCINF ;

/* pmc_rdcntldata:read PMC parameter data table control data */
/* pmc_wrcntldata:write PMC parameter data table control data */
typedef struct iodbpmccntl {
    short   datano_s ;
    short   dummy ;
    short   datano_e ;
    struct {
        char    tbl_prm ;
        char    data_type ;
        unsigned short  data_size ;
        unsigned short  data_dsp ;
        short   dummy ;
    } info[100] ;
} IODBPMCCNTL ;

/* pmc_rdalmmsg:read PMC alarm message */
typedef struct  odbpmcalm {
    char    almmsg[128] ;    /* alarm message */
} ODBPMCALM ;

/* pmc_getdtailerr:get detail error for pmc */
typedef struct odbpmcerr {
    short   err_no ;
    short   err_dtno ;
} ODBPMCERR ;

/* pmc_rdpmctitle:read pmc title data */
typedef struct  odbpmctitle {
    char    mtb[48];
    char    machine[48];
    char    type[48];
    char    prgno[8];
    char    prgvers[4];
    char    prgdraw[48];
    char    date[32];
    char    design[48];
    char    written[48];
    char    remarks[48];
} ODBPMCTITLE ;

/* pmc_rdpmctitle2:read pmc title data */
typedef struct  odbpmctitle2 {
    char    mtb[48];
    char    machine[48];
    char    type[48];
    char    prgno[16];
    char    prgvers[16];
    char    prgdraw[48];
    char    date[32];
    char    design[48];
    char    written[48];
    char    remarks[48];
} ODBPMCTITLE2 ;

/* pmc_rdpmcrng_ext:read PMC data */
typedef struct iodbpmcext {
	short	type_a ;	/* PMC address type */
	short	type_d ;	/* PMC data type */
	short	datano_s ;	/* start PMC address */
	short	datano_e ;	/* end PMC address */
	short	err_code ;	/* error code */
	short	reserved ;	/* reserved */
	void	*data ;		/* pointer to buffer */
} IODBPMCEXT ;

/* pmc_rdpmcaddr:read PMC address information */
typedef struct odbpmcadr {
	unsigned short pmc_adr ;	/* PMC address type */
	unsigned short adr_attr ;	/* PMC address attribute */
	unsigned long  adr ;		/* offset address from the top of the PMC address area */
	unsigned long  top ;		/* top number of the PMC address area */
	unsigned long  num ;		/* number of the PMC address area */
} ODBPMCADR ;

/* pmc_read_seq_program_and_memory_type:Reads sequence program and momory type */
typedef struct
{
   unsigned long SystemType;
   unsigned long SystemAttribute;
   unsigned long TargetType;
   unsigned long TargetAttribute;
   char          SystemTypeStr[32];
   char          TargetTypeStr[32];
} ODBPMCLADMEMTYPE;

/* pmc_convert_from_string_to_address:Convert to PMC address information from address or symbol string */
typedef struct odbpmcadrinfo
{
   short sPmcUnit;      /*j PMC unittype */
   short sAdrType;      /*j ID code indicating the PMC address type */
   long  iAdrNum;       /*j number of PMC address */
   short sBitPos;       /*j bit position of PMC address */
   short sDataType;     /*j deta type of PMC address */
} ODBPMCADRINFO;

/*--------------------------*/
/* PROFIBUS function        */
/*--------------------------*/

/* pmc_prfrdcinfo:read PROFIBUS information data */
typedef struct odbprfinfo {
    unsigned short series ;
    unsigned short vers1 ;
    unsigned short vers2 ;
    unsigned short profi ;
} ODBPRFINFO ;

/* pmc_prfrdconfig:read PROFIBUS configration data */
typedef struct odbprfcnf {
    char    master_ser[5] ;
    char    master_ver[3] ;
    char    slave_ser[5] ;
    char    slave_ver[3] ;
    char    cntl_ser[5] ;
    char    cntl_ver[3] ;
} ODBPRFCNF ;

/* pmc_prfrdbusprm:read bus parameter for master function */
/* pmc_prfwrbusprm:write bus parameter for master function */
typedef struct iodbbusprm {
    char           fdl_add ;
    char           baudrate ;
    unsigned short tsl ;
    unsigned short min_tsdr ;
    unsigned short max_tsdr ;
    unsigned char  tqui ;
    unsigned char  tset ;
    long           ttr ;
    char           gap ;
    char           hsa ;
    char           max_retry ;
    unsigned char  bp_flag ;
    unsigned short min_slv_int ;
    unsigned short poll_tout ;
    unsigned short data_cntl ;
    char           reserve1[6] ;
    char           cls2_name[32] ;
    short          user_dlen ;
    char           user_data[62] ;
    char           reserve2[96] ;
} IODBBUSPRM ;

/* pmc_prfrdslvprm:read slave parameter for master function */
/* pmc_prfwrslvprm:write slave parameter for master function */
typedef struct iodbslvprm {
    short          dis_enb ;
    unsigned short ident_no ;
    unsigned char  slv_flag ;
    unsigned char  slv_type ;
    char           reserve1[12] ;
    unsigned char  slv_stat ;
    unsigned char  wd_fact1 ;
    unsigned char  wd_fact2 ;
    unsigned char  min_tsdr ;
    char           reserve2 ;
    unsigned char  grp_ident ;
    short          user_plen ;
    char           user_pdata[32] ;
    short          cnfg_dlen ;
    char           cnfg_data[126] ;
    short          slv_ulen ;
    char           slv_udata[30] ;
    char           reserve3[8] ;
} IODBSLVPRM ;

typedef struct iodbslvprm2 {
    short          dis_enb ;
    unsigned short ident_no ;
    unsigned char  slv_flag ;
    unsigned char  slv_type ;
    char           reserve1[12] ;
    unsigned char  slv_stat ;
    unsigned char  wd_fact1 ;
    unsigned char  wd_fact2 ;
    unsigned char  min_tsdr ;
    char           reserve2 ;
    unsigned char  grp_ident ;
    short          user_plen ;
    char           user_pdata[206] ;
    short          cnfg_dlen ;
    char           cnfg_data[126] ;
    short          slv_ulen ;
    char           slv_udata[30] ;
    char           reserve3[8] ;
} IODBSLVPRM2 ;

/* pmc_prfrdallcadr:read allocation address for master function */
/* pmc_prfwrallcadr:set allocation address for master function */
typedef struct iodbprfadr {
    char           di_size ;
    char           di_type ;
    unsigned short di_addr ;
    short          reserve1;
    char           do_size ;
    char           do_type ;
    unsigned short do_addr ;
    short          reserve2;
    char           dgn_size ;
    char           dgn_type ;
    unsigned short dgn_addr ;
} IODBPRFADR ;

/* pmc_prfrdslvaddr:read allocation address for slave function */
/* pmc_prfwrslvaddr:set allocation address for slave function */
typedef struct iodbslvadr {
    char           slave_no ;
    char           di_size ;
    char           di_type ;
    unsigned short di_addr ;
    char           do_size ;
    char           do_type ;
    unsigned short do_addr ;
    char           reserve[7] ;
} IODBSLVADR ;

/* pmc_prfrdslvstat:read status for slave function */
typedef struct odbslvst {
    unsigned char  cnfg_stat ;
    unsigned char  prm_stat ;
    char           wdg_stat ;
    unsigned char  live_stat ;
    short          ident_no ;
} ODBSLVST ;

/* pmc_prfrdslvid:Reads slave index data of master function */
/* pmc_prfwrslvid:Writes slave index data of master function */
typedef struct {
    short          dis_enb ;
    short          slave_no ;
    short          nsl ;
    unsigned char  dgn_size ;
    char           dgn_type ;
    unsigned short dgn_addr ;
} IODBSLVID ;

/* pmc_prfrdslvprm2:Reads slave parameter of master function(2) */
/* pmc_prfwrslvprm2:Writes slave parameter of master function(2) */
typedef struct {
    unsigned short ident_no ;
    unsigned char  slv_flag ;
    unsigned char  slv_type ;
    char           reserve1[12] ;
    unsigned char  slv_stat ;
    unsigned char  wd_fact1 ;
    unsigned char  wd_fact2 ;
    unsigned char  min_tsdr ;
    char           reserve2 ;
    unsigned char  grp_ident ;
    short          user_plen ;
    char           user_pdata[206] ;
    short          slv_ulen ;
    char           slv_udata[30] ;
} IODBSLVPRM3 ;

/* pmc_prfrddido:Reads DI/DO parameter of master function */
/* pmc_prfwrdido:Writes DI/DO parameter of master function */
typedef struct {
    short          slave_no ;
    short          slot_no ;
    unsigned char  di_size ;
    char           di_type ;
    unsigned short di_addr ;
    unsigned char  do_size ;
    char           do_type ;
    unsigned short do_addr ;
    short          shift;
    unsigned char  module_dlen ;
    char           module_data[128] ;
} IODBDIDO ;

/* pmc_prfrdindiadr:Reads indication address of master function */
/* pmc_prfwrindiadr:Writes indication address of master function */
typedef struct {
    unsigned char  dummy ;
    char           indi_type ;
    unsigned short indi_addr ;
} IODBINDEADR ;


/*-----------------------------------*/
/* CB : CUSTOMER'S BOARD function    */
/*-----------------------------------*/

typedef struct odbtransinfo {
    long    mas_buff_size;
    short   trans_start_reqflag;
    short   trans_end_reqflag;
    short   trans_start_respflag;
    short   trans_end_respflag;
    long    all_transfer_size;
    short   data_id;
    short   reserve;
    long    data_write_pt;
    long    data_read_pt;
    long    accumulation_counter;
    short   forwarding_status;
} ODBTRANSINFO ;


/*-----------------------------------------------*/
/* DS : Data server & Ethernet board function    */
/*-----------------------------------------------*/

/* etb_rdparam : read the parameter of the Ethernet board */
/* etb_wrparam : write the parameter of the Ethernet board */
typedef struct _tcpprm {
	char OwnIPAddress[16];
	char SubNetMask[16];
	char RouterIPAddress[16];
} TCPPRM;

typedef struct _hostprm {
	unsigned short DataServerPort;
	char           DataServerIPAddress[16];
	char           DataServerUserName[32];
	char           DataServerPassword[32];
	char           DataServerLoginDirectory[128];
} HOSTPRM;

typedef struct _ftpprm {
	char FTPServerUserName[32];
	char FTPServerPassword[32];
	char FTPServerLoginDirectory[128];
} FTPPRM;

typedef struct _etbprm {
	char  OwnMACAddress[13];
	short MaximumChannel;
	short HDDExistence;
	short NumberOfScreens;
} ETBPRM;

typedef struct _iodbetp {
	short ParameterType;
	union {
		TCPPRM  tcp;
		HOSTPRM host;
		FTPPRM  ftp;
		ETBPRM  etb;
	} prm;
} IODBETP;

/* etb_rderrmsg : read the error message of the Ethernet board */
typedef struct _odbetmsg {
	char title[33];
	char message[10][39];
} ODBETMSG;

/* ds_rdhddinfo : read information of the Data Server's HDD */
typedef struct _odbhddinf {
	long file_num;
	long remainder_l;
	long remainder_h;
	char current_dir[32];
} ODBHDDINF;

/* ds_rdhdddir : read the file list of the Data Server's HDD */
typedef struct _odbhdddir {
	char  file_name[64];
	char  comment[80];
	short attribute;
	short reserved;
	long  size;
	char  date[16];
} ODBHDDDIR;

/* ds_rdhostdir : read the file list of the host */
typedef struct _odbhostdir {
	char host_file[128];
} ODBHOSTDIR;

/* ds_rdmntinfo : read maintenance information */
typedef struct _dsmntinfo {
	unsigned short empty_cnt;
	unsigned long  total_size;
	unsigned short ReadPtr;
	unsigned short WritePtr;
} DSMNTINFO;


/*----------------------------*/
/* NET : Ethernet function    */
/*----------------------------*/
typedef struct _common_prm {
    char                    OwnMacAddress[13];
    char                    OwnIpAddress[40];
    char                    SubNetmask[16];
    char                    RouterIpAddress[40];
    char                    DnsServer1IpAddress[40];
    char                    DnsServer2IpAddress[40];
    char                    OwnHostName[32];
    char                    OwnDomain[63];
} COMMON_PRM;

typedef struct _focas2_prm {
    unsigned long           TcpPort;
    unsigned long           UdpPort;
    unsigned long           TimeInterval;
} FOCAS2_PRM;

typedef struct _ftp_client_prm {
    char                    HostName[64];
    unsigned long           ControlPort;
    unsigned long           Dummy;
    char                    UserName[32];
    char                    Password[32];
    char                    LoginDirectory[128];
} FTP_CLIENT_PRM;

typedef struct _ftp_server_prm {
    char                    UserName[32];
    char                    Password[32];
    char                    LoginDirectory[128];
} FTP_SERVER_PRM;

typedef struct _ftptrans_prm {
    FTP_CLIENT_PRM          opposite[3];
} FTPTRANS_PRM;

typedef struct _dtsvr_prm {
    FTP_CLIENT_PRM          opposite[3];
    FTP_SERVER_PRM          own;
} DTSVR_PRM;

typedef struct _rmtdiag_client_prm {
    char                    HostName[64];
    unsigned long           Port;
    char                    InquiryName[64];
} RMTDIAG_CLIENT_PRM;

typedef struct _rmtdiag_prm {
    char                    MtbInformation[17];
    char                    MachineInformation[17];
    RMTDIAG_CLIENT_PRM      opposite[3];
} RMTDIAG_PRM;

typedef struct _factolink_client_prm {
    char                    HostName[64];
    unsigned long           Port;
} FACTOLINK_CLIENT_PRM;

typedef struct _factolink_prm {
    FACTOLINK_CLIENT_PRM    opposite[3];
} FACTO_PRM;

typedef struct _maintain_ping_prm {
    char                    HostName[64];
    unsigned short          Count;
} PING_PRM;

typedef struct _maintain_prm {
    PING_PRM                opposite;
} MAINTAIN_PRM;

typedef struct _netsrv_prm {
    char                    HostName[64];
    unsigned long           Port;
    unsigned long           TimeInterval;
    unsigned long           UdpPeriod;
    char                    MachineNumber[25];
    char                    dummy1[7];
    char                    AcceptanceReply[25];
    char                    dummy2[7];
    char                    ErrorReply[25];
    char                    dummy3[7];
} NETSRV_PRM;

typedef struct _unsolicmsg_prm {
    char                    HostName[64];
    unsigned long           Port;
    unsigned short          RetryCount;
    unsigned short          Timeout;
    unsigned short          AliveTime;
    char                    dummy1[8];
    UNSOLICMSG_TYPE_PRM     Control;
    unsigned short          TransmissionNumber;
    char                    dummy2[14];
    UNSOLICMSG_TYPE_PRM     Transmission[3];
} UNSOLICMSG_PRM;

typedef struct _pmc_addr {
    unsigned short          Path;
    short                   Kind;
    unsigned long           Address;
} PMC_ADDR;

typedef struct _mbsvr_area_prm {
    unsigned long           DatSize;
    unsigned long           DatModAddr;
    PMC_ADDR                DatPmcAddr;
} MBSVR_AREA_PRM;

typedef struct _mbsvr_prm {
    unsigned long           TcpPort;
    unsigned short          Option1;
    unsigned short          Option2;
    PMC_ADDR                StsPmcAddr;
    MBSVR_AREA_PRM          AreaPrm[3];
} MBSVR_PRM;

typedef struct _user_account_prm {
    char    UserName[32];
    char    Password[32];
} USER_ACCOUNT_PRM;

typedef struct _httpsvr_prm {
    unsigned long           TcpPort;
    unsigned long           Timeout;
    USER_ACCOUNT_PRM        UserAccount[2];
} HTTPSVR_PRM;

typedef struct _stsntf_prm {
    unsigned long           PopSvrPort;
    unsigned long           SmtpSvrPort;
    USER_ACCOUNT_PRM        UserAccount[1];
} STSNTF_PRM;

typedef struct _common_prm_flg {
    char                    OwnIpAddress;
    char                    SubNetmask;
    char                    RouterIpAddress;
    char                    DnsServer1IpAddress;
    char                    DnsServer2IpAddress;
    char                    OwnHostName;
    char                    OwnDomain;
} COMMON_PRM_FLG;

typedef struct _focas2_prm_flg {
    char                    TcpPort;
    char                    UdpPort;
    char                    TimeInterval;
} FOCAS2_PRM_FLG;

typedef struct _ftp_client_prm_flg {
    char                    HostName;
    char                    ControlPort;
    char                    Dummy;
    char                    UserName;
    char                    Password;
    char                    LoginDirectory;
} FTP_CLIENT_PRM_FLG;

typedef struct _ftp_server_prm_flg {
    char                    UserName;
    char                    Password;
    char                    LoginDirectory;
} FTP_SERVER_PRM_FLG;

typedef struct _ftptrans_prm_flg {
    FTP_CLIENT_PRM_FLG      opposite[3];
} FTPTRANS_PRM_FLG;

typedef struct _dtsvr_prm_flg {
    FTP_CLIENT_PRM_FLG      opposite[3];
    FTP_SERVER_PRM_FLG      own;
} DTSVR_PRM_FLG;

typedef struct _rmtdiag_client_prm_flg {
    char                    HostName;
    char                    Port;
    char                    InquiryName;
} RMTDIAG_CLIENT_PRM_FLG;

typedef struct _rmtdiag_prm_flg {
    char                    MtbInformation;
    char                    MachineInformation;
    RMTDIAG_CLIENT_PRM_FLG  opposite[3];
} RMTDIAG_PRM_FLG;

typedef struct _facto_client_prm_flg {
    char                    HostName;
    char                    Port;
} FACTO_CLIENT_PRM_FLG;

typedef struct _facto_prm_flg {
    FACTO_CLIENT_PRM_FLG    opposite[3];
} FACTO_PRM_FLG;

typedef struct _ping_prm_flg {
    char                    HostName;
    char                    Count;
} PING_PRM_FLG;

typedef struct _maintain_prm_flg {
    PING_PRM_FLG            opposite;
} MAINTAIN_PRM_FLG;

typedef struct _netsrv_prm_flg {
    char                    HostName;
    char                    Port;
    char                    TimeInterval;
    char                    UdpPeriod;
    char                    MachineNumber;
    char                    AcceptanceReply;
    char                    ErrorReply;
} NETSRV_PRM_FLG;

typedef struct _unsolicmsg_type_prm_flg {
    char                    Type;
    char                    dummy1[3];
    union {
        struct {
            char            PathKindAddress;
            char            Size;
        } Pmc;
        struct {
            char            PathNo;
            char            Number;
        } Macro;
    } Prm;
    char                    dummy2[2];
} UNSOLICMSG_TYPE_PRM_FLG;

typedef struct _unsolicmsg_prm_flg {
    char                    HostName;
    char                    Port;
    char                    RetryCount;
    char                    Timeout;
    char                    AliveTime;
    char                    dummy1[3];
    UNSOLICMSG_TYPE_PRM_FLG Control;
    char                    TransmissionNumber;
    char                    dummy2[3];
    UNSOLICMSG_TYPE_PRM_FLG Transmission[3];
} UNSOLICMSG_PRM_FLG;

typedef struct _mbsvr_area_prm_flg {
    char                    DatSize;
    char                    DatModAddr;
    char                    DatPmcAddr;
    char                    dummy;
} MBSVR_AREA_PRM_FLG;

typedef struct _mbsvr_prm_flg {
    char                    TcpPort;
    char                    Option1;
    char                    Option2;
    char                    StsPmcAddr;
    MBSVR_AREA_PRM_FLG      AreaPrm[3];
} MBSVR_PRM_FLG;

typedef struct _user_account_prm_flg {
    char    UserName;
    char    Password;
} USER_ACCOUNT_PRM_FLG;

typedef struct _httpsvr_prm_flg {
    char                    TcpPort;
    char                    Timeout;
    USER_ACCOUNT_PRM_FLG    UserAccount[2];
} HTTPSVR_PRM_FLG;

typedef struct _stsntf_prm_flg {
    char                    PopSvrPort;
    char                    SmtpSvrPort;
    USER_ACCOUNT_PRM_FLG    UserAccount[1];
} STSNTF_PRM_FLG;

/* eth_wrparam : */
typedef struct _in_ethprm_flag {
    union {
        COMMON_PRM_FLG      common;
        FOCAS2_PRM_FLG      focas2;
        FTPTRANS_PRM_FLG    ftpTrans;
        DTSVR_PRM_FLG       dataServer;
        RMTDIAG_PRM_FLG     remoteDiag;
        FACTO_PRM_FLG       factolink;
        MAINTAIN_PRM_FLG    maintain;
        NETSRV_PRM_FLG      netservice;
        UNSOLICMSG_PRM_FLG  unsolicmsg;
        MBSVR_PRM_FLG       mbsvr;
        HTTPSVR_PRM_FLG     httpsvr;
        STSNTF_PRM_FLG      stsntf;
    } flg;
} IN_ETHPRMFLAG;

typedef struct _in_ethprm {
    short                   reserve01;
    short                   reserve02;
    short                   reserve03;
    short                   reserve04;
    short                   reserve05;
    short                   reserve06;
    union {
        COMMON_PRM          common;
        FOCAS2_PRM          focas2;
        FTPTRANS_PRM        ftpTrans;
        DTSVR_PRM           dataServer;
        RMTDIAG_PRM         remoteDiag;
        FACTO_PRM           factolink;
        MAINTAIN_PRM        maintain;
        NETSRV_PRM          netservice;
        UNSOLICMSG_PRM      unsolicmsg;
        MBSVR_PRM           mbsvr;
        HTTPSVR_PRM         httpsvr;
        STSNTF_PRM          stsntf;
    } prm;
} IN_ETHPRM;

/* eth_rdparam : */
typedef struct _out_ethprm {
    unsigned short          Option;
    short                   Type;
    short                   Dhcp;
    short                   ValidDevice;
    short                   DtsvrChannel;
    short                   Storage;
    union {
        COMMON_PRM          common;
        FOCAS2_PRM          focas2;
        FTPTRANS_PRM        ftpTrans;
        DTSVR_PRM           dataServer;
        RMTDIAG_PRM         remoteDiag;
        FACTO_PRM           factolink;
        MAINTAIN_PRM        maintain;
        NETSRV_PRM          netservice;
        UNSOLICMSG_PRM      unsolicmsg;
        MBSVR_PRM           mbsvr;
        HTTPSVR_PRM         httpsvr;
        STSNTF_PRM          stsntf;
    } prm;
} OUT_ETHPRM;

typedef struct _out_ethdsmode {
    short                   DsMode[10];
} OUT_ETHDSMODE;

typedef struct _out_ethping1shot {
    unsigned short          MsgId;
    char                    IpAddress[64];
} OUT_ETHPING1SHOT;

/* eth_ping_result : */
typedef struct _out_ethping {
    short                   Device;
    short                   Count;
    OUT_ETHPING1SHOT        reply[10];
} OUT_ETHPING;

typedef struct _emblsi {
    unsigned short          Collision;
    unsigned short          CarrierSenseLost;
    unsigned short          DelayOver;
    unsigned short          Underrun;
    unsigned short          SendParityError;
    unsigned short          AlignmentError;
    unsigned short          CrcError;
    unsigned short          Overrun;
    unsigned short          FrameLengthViolation;
    unsigned short          RecvParityError;
} EMBLSI;

typedef struct _boardlsi {
    unsigned short          SendRetryOver;
    unsigned short          Collision;
    unsigned short          CarrierSenseLost;
    unsigned short          NoCarrier;
    unsigned short          InvalidFrameLength;
    unsigned short          CrcError;
    unsigned short          ShortFrame;
    unsigned short          LongFrame;
    unsigned short          OddFrame;
    unsigned short          Overflow;
    unsigned short          PhyLsiError;
} BOARDLSI;

/* eth_rdlsistate : */
typedef struct _out_ethlsi {
    short                   Type;
    short                   Baudrate;
    unsigned short          RecvPacketCount;
    unsigned short          RecvBroadcastCount;
    unsigned short          SendPacketCount;
    union {
        EMBLSI              emb;
        BOARDLSI            board;
    } lst;
} OUT_ETHLSI;

typedef struct _tsk_sts {
    unsigned short          StsId;
    char                    Status[30];
} TSK_STS;

/* eth_rdtaskstate : */
typedef struct _out_ethtask {
    short                   Type;
    short                   Count;
    char                    pad[12];
    TSK_STS                 task[32];
} OUT_ETHTASK;

typedef struct _out_ethlog1shot {
    short                   Type;
    unsigned short          MsgId;
    unsigned char           Year;
    unsigned char           Month;
    unsigned char           Day;
    unsigned char           Hour;
    unsigned char           Minute;
    unsigned char           Second;
    char                    reserve[2];
    char                    Text[84];
} OUT_ETHLOG1SHOT;

/* eth_rdlog : */
typedef struct _out_ethlog {
    short                   Count;
    char                    reserve[14];
    OUT_ETHLOG1SHOT         logData[15];
} OUT_ETHLOG;

/* eth_rdtype : */
typedef struct _out_ethtype {
    short                   Kind;
    short                   FunctionEmb;
    short                   FunctionBoard;
    short                   FunctionEmbCe;
} OUT_ETHTYPE;

/* eth_rdtype2 : */
typedef struct _out_ethtype2 {
    unsigned short          Kind;
    short                   dummy;
    unsigned long           FunctionEmb;
    unsigned long           FunctionEmbPcm;
    unsigned long           FunctionBoard;
    unsigned long           FunctionEmbCe;
    unsigned long           FunctionEmbCePcm;
} OUT_ETHTYPE2;

/* eth_rdtype3 : */
typedef struct _out_ethtype3 {
    unsigned long           Kind;
    unsigned short          KindFLnet;
    short                   Pad;
    unsigned long           FunctionEmb;
    unsigned long           FunctionEmbPcm;
    unsigned long           FunctionBoard;
    unsigned long           FunctionEmbCe;
    unsigned long           FunctionEmbCePcm;
    unsigned long           FunctionReserve;
} OUT_ETHTYPE3;

/* eth_rddsstate : */
typedef struct _out_dsstate {
    short                   DtsvrChannel;
    short                   pad;
    short                   Mode;
    unsigned short          EmptyCount;
    unsigned long           TotalSize;
    unsigned short          WritePtr;
    unsigned short          ReadPtr;
} OUT_DSSTATE;

/* eth_rdunsolicstate : */
typedef struct _out_unsolicstate {
    char                    IpAddress[64];
    unsigned short          status;
} OUT_UNSOLICSTATE;

/* eth_rdfsclntinfo : */
typedef struct _clnt_info {
    char                    IpAddress[64];
    long                    SocketId;
    unsigned long           ConnectTime;
} CLNT_INFO;

typedef struct _out_fsinfo {
    short                   Number;
    unsigned char           pad[2];
    CLNT_INFO               clntinfo[10];
} OUT_FSINFO;

/* eth_rdmbsclntinfo : */
typedef struct _mbsvr_clnt_info {
    char                    IpAddress[64];
    unsigned long           ConnectTime;
} MBSVR_CLNT_INFO;

typedef struct _out_mbsvrinfo {
    short                   Number;
    unsigned char           pad[2];
    MBSVR_CLNT_INFO         clntinfo[10];
} OUT_MBSVRINFO;

/* net_rdtype : */
typedef struct _out_fl_devtype {
    unsigned short          Kind1;
    unsigned char           pad1[2];
    unsigned long           FunctionFLnet1;
    unsigned short          Kind2;
    unsigned char           pad2[2];
    unsigned long           FunctionFLnet2;
} FL_DEVTYPE;

typedef struct _out_pnc_devtype {
    unsigned short          Kind;
    unsigned char           pad[2];
    unsigned long           FunctionPnc;
} PNC_DEVTYPE;

typedef struct _out_netdevprm {
    union {
       FL_DEVTYPE           Fldevtype;
       PNC_DEVTYPE          Pncdevtype;
    } prm;
} OUT_NETDEVPRM;

/*----------------------------*/
/* NET : EtherNet/IP function */
/*----------------------------*/

typedef struct _eip_common_prm {
    unsigned short          TcpPort;
    unsigned short          UdpPort;
    char                    DiDataOnAbnormal;
    unsigned char           Option1;
    char                    pad[2];
} EIP_COMMON_PRM;

typedef struct _eipa_basic_prm {
    EIP_COMMON_PRM          Common;
    unsigned char           Option2;
    unsigned char           AllocMax;
    unsigned short          ConnectMax;
    unsigned short          RPI_Min;
    unsigned short          RPI_Max;
    struct {
        unsigned short      Path;
        short               Addr;
        unsigned long       No;
    }                       Status;
    unsigned long           StatusSize;
} EIPA_BASIC_PRM;

typedef EIPA_BASIC_PRM      OUT_EIPA_BASIC_PRM;
typedef EIPA_BASIC_PRM       IN_EIPA_BASIC_PRM;

typedef struct _in_eip_common_prm_flg {
    char                    TcpPort;
    char                    UdpPort;
    char                    DiDataOnAbnormal;
    char                    Option1;
    char                    pad[4];
} IN_EIP_COMMON_PRM_FLG;

typedef struct _in_eipa_basic_prm_flg {
    IN_EIP_COMMON_PRM_FLG   Common;
    char                    Option2;
    char                    pad[5];
    char                    Status;
    char                    StatusSize;
} IN_EIPA_BASIC_PRM_FLG;

typedef struct _eip_type_prm {
    unsigned short          Type;
    char                    pad[2];
    union {
        struct {
            unsigned short  Path;
            short           Addr;
            unsigned long   No;
            unsigned long   Size;
        } pmc;
        struct {
            unsigned short  Path;
            char            pad[2];
            unsigned long   No;
            unsigned long   Num;
        } macro;
    } prm;
    char                    TagName[28];
    char                    pad2[4];
} EIP_TYPE_PRM;

typedef struct _eipa_alloc_prm {
    char                    State;
    unsigned char           Option;
    char                    pad[2];
    EIP_TYPE_PRM            DI;
    EIP_TYPE_PRM            DO;
} EIPA_ALLOC_PRM;

typedef EIPA_ALLOC_PRM      OUT_EIPA_ALLOC_PRM;
typedef EIPA_ALLOC_PRM       IN_EIPA_ALLOC_PRM;

typedef struct _eip_type_prm_flg {
    char                    Type;
    char                    pad1[2];
    char                    Address;
    char                    Size;
    char                    TagName;
    char                    pad2[2];
} IN_EIP_TYPE_PRM_FLG;

typedef struct _in_eipa_alloc_prm_flg{
    char                    State;
    char                    Option;
    char                    pad[2];
    IN_EIP_TYPE_PRM_FLG     DI;
    IN_EIP_TYPE_PRM_FLG     DO;
} IN_EIPA_ALLOC_PRM_FLG;

typedef struct _out_eip_msnsinfo {
    char                    ModuleStatus;
    char                    NetworkStatus;
    char                    pad[2];
} OUT_EIP_MSNSINFO;

typedef struct _out_eip_deviceinfo {
    unsigned short          VendorId;
    unsigned short          DeviceType;
    unsigned short          ProductCode;
    unsigned char           MajorRevision;
    unsigned char           MinorRevision;
    unsigned long           SerialNo;
} OUT_EIP_DEVICEINFO;

typedef struct _out_eipa_scndata {
    long                    ConnectionId;
    unsigned long           ConnectTime;
    char                    IpAddress[40];
} OUT_EIPA_SCNDATA;

typedef struct _out_eip_listdetail {
    char                    IpAddress[40];
    unsigned long           ConnectTime;
    char                    ApplicationType;
    char                    pad1;
    unsigned short          O2T_RPI;
    unsigned short          T2O_RPI;
    unsigned short          O2T_API;
    unsigned short          T2O_API;
    unsigned short          RecvPacket;
    unsigned short          SendPacket;
    unsigned short          LostPacket;
    short                   AllocationId;
    char                    pad2[2];
} OUT_EIP_LISTDETAIL;

typedef struct _eip_unuse_addr {
    unsigned short          Param1;
    short                   Param2;
    unsigned long           Param3;
} EIP_UNUSE_ADDR;

typedef struct _eip_pmc_addr {
    unsigned short          Path;
    short                   Addr;
    unsigned long           No;
} EIP_PMC_ADDR;

typedef struct _eip_multi_addr {
    union {
        EIP_UNUSE_ADDR      Unuse;
        EIP_PMC_ADDR        Pmc;
    } Prm;
} EIP_MULTI_ADDR;

typedef struct _eips_basic_prm {
    EIP_COMMON_PRM          Common;
    unsigned short          Network;
    unsigned char           pad[2];
    unsigned char           Option2;
    unsigned char           AllocMax;
    unsigned short          ConnectMax;
    unsigned short          RPI_Min;
    unsigned short          RPI_Max;
    EIP_PMC_ADDR            StatusAddr;
    unsigned long           StatusSize;
} EIPS_BASIC_PRM;

typedef EIPS_BASIC_PRM   IN_EIPS_BASIC_PRM;
typedef EIPS_BASIC_PRM  OUT_EIPS_BASIC_PRM;

typedef struct _out_eips_state_prm {
    unsigned char           State[32];
    char                    reserve[32];
} OUT_EIPS_STATE_PRM;

typedef struct _eips_conn_prm {
    unsigned long           AssemblyInstance;
    unsigned short          Type;
    char                    pad1[2];
    EIP_MULTI_ADDR          Addr;
    unsigned long           Size;
    unsigned long           RPI;
    unsigned short          TransportType;
    unsigned short          HeaderFormat;
    unsigned short          Priority;
    char                    pad2[2];
    char                    reserve[28];
    char                    pad3[4];
} EIPS_CONN_PRM;

typedef struct _eips_electronic_key {
    unsigned short          VendorID;
    unsigned short          DeviceType;
    unsigned short          ProductCode;
    unsigned char           MajorRevision;
    unsigned char           MinorRevision;
    unsigned char           Compatibility;
    char                    pad[3];
} EIPS_ELECTRONIC_KEY;

typedef struct _eips_alloc_prm {
    char                    IpAddress[40];
    unsigned char           Option1;
    unsigned char           Option2;
    unsigned char           DataUnit;
    unsigned char           Endian;
    unsigned long           ConfigInstance;
    EIPS_CONN_PRM           ConnT2O;
    EIPS_CONN_PRM           ConnO2T;
    EIP_PMC_ADDR            reserve1;
    EIP_PMC_ADDR            reserve2;
    unsigned char           ProductTrigger;
    unsigned char           Timeout;
    unsigned char           Reconnect;
    char                    pad;
    EIPS_ELECTRONIC_KEY     ElectronicKey;
    unsigned long           DataPerSec;
    unsigned long           DataPerSecTotal;
} EIPS_ALLOC_PRM;

typedef EIPS_ALLOC_PRM   IN_EIPS_ALLOC_PRM;
typedef EIPS_ALLOC_PRM  OUT_EIPS_ALLOC_PRM;

typedef struct _in_eips_basic_prm_flg {
    IN_EIP_COMMON_PRM_FLG   Common;
    char                    Option2;
    char                    StatusAddr;
    char                    StatusSize;
    char                    pad;
} IN_EIPS_BASIC_PRM_FLG;

typedef struct _in_eips_basic {
    IN_EIPS_BASIC_PRM_FLG   flg;
    IN_EIPS_BASIC_PRM       prm;
} IN_EIPS_BASIC;

typedef struct _in_eips_conn_prm_flg {
    char                    AssemblyInstance;
    char                    Type;
    char                    Addr;
    char                    Size;
    char                    RPI;
    char                    TransportType;
    char                    HeaderFormat;
    char                    Priority;
    char                    reserve;
    char                    pad[3];
} IN_EIPS_CONN_PRM_FLG;

typedef struct _in_eips_alloc_prm_flg {
    char                    IpAddress;
    char                    Option1;
    char                    Option2;
    char                    DataUnit;
    char                    Endian;
    char                    ConfigInstance;
    char                    pad1[2];
    IN_EIPS_CONN_PRM_FLG    ConnT2O;
    IN_EIPS_CONN_PRM_FLG    ConnO2T;
    char                    reserve1;
    char                    reserve2;
    char                    ProductTrigger;
    char                    Timeout;
    char                    Reconnect;
    char                    VendorID;
    char                    DeviceType;
    char                    ProductCode;
    char                    MajorRevision;
    char                    MinorRevision;
    char                    Compatibility;
    char                    pad2;
} IN_EIPS_ALLOC_PRM_FLG;

typedef struct _in_eips_alloc {
    IN_EIPS_ALLOC_PRM_FLG   flg;
    IN_EIPS_ALLOC_PRM       prm;
} IN_EIPS_ALLOC;

typedef struct _out_eips_com_info {
    unsigned char           State[32];
    char                    reserve[32];
} OUT_EIPS_COM_INFO;

typedef struct _out_eips_detail_info {
    short                   Result;
    char                    pad1[2];
    char                    IpAddress[40];
    unsigned char           GeneralCode;
    char                    pad2;
    unsigned short          ExtendedCode;
    unsigned long           ConnectTime;
    unsigned short          O2T_RPI;
    unsigned short          T2O_RPI;
    unsigned short          O2T_API;
    unsigned short          T2O_API;
    unsigned short          RecvPacket;
    unsigned short          SendPacket;
    unsigned short          LostPacket;
    char                    pad3[2];
} OUT_EIPS_DETAIL_INFO;

typedef struct _out_eips_identity_info {
    short                   Result;
    char                    pad1[2];
    unsigned short          VendorId;
    unsigned short          DeviceType;
    unsigned short          ProductCode;
    unsigned char           MajorRevision;
    unsigned char           MinorRevision;
    unsigned long           SerialNo;
    char                    ProductName[33];
    char                    pad2[3];
} OUT_EIPS_IDENTITY_INFO;

typedef struct _out_adpsafe_mntinfo {
    unsigned short  SupervisorStatus;
    unsigned char   SafetyNetworkNumber[6];

    unsigned short  SelfDiagnosisErrorA;
    unsigned short  SelfDiagnosisErrorB;
    unsigned short  SelfDiagnosisDetailA;
    unsigned short  SelfDiagnosisDetailB;

    unsigned long   SafetyParameterCrc;
    unsigned short  ChangeDateYear;
    unsigned char   ChangeDateMonth;
    unsigned char   ChangeDateDay;
    unsigned short  ChangeTimeHours;
    unsigned short  ChangeTimeMinutes;
    unsigned short  ChangeTimeSeconds;
    unsigned short  Pad;

    unsigned char   DiConnectionStatusA;
    unsigned char   DiConnectionStatusB;
    unsigned char   DoConnectionStatusA;
    unsigned char   DoConnectionStatusB;

    unsigned char   DiConnectionDataSizeA;
    unsigned char   DiConnectionDataSizeB;
    unsigned char   DoConnectionDataSizeA;
    unsigned char   DoConnectionDataSizeB;

    unsigned char   DiConnectionErrorA;
    unsigned char   DiConnectionErrorB;
    unsigned char   DoConnectionErrorA;
    unsigned char   DoConnectionErrorB;

    unsigned short  DiRecvPacketNumberA;
    unsigned short  DiRecvPacketNumberB;
    unsigned short  DoSendPacketNumberA;
    unsigned short  DoSendPacketNumberB;
} OUT_ADPSAFE_MNTINFO;

/*---------------------------*/
/* NET : PROFIBUS function   */
/*---------------------------*/

/* pbm_rd_param */
typedef struct _T_MAS_USR
{
    unsigned short          master_user_data_len;
    unsigned char           master_user_data[62];
} T_MAS_USR;

typedef struct _T_BUS_PARA
{
    unsigned char           fdl_add;
    unsigned char           baud_rate;
    unsigned short          tsl;
    unsigned short          min_tsdr;
    unsigned short          max_tsdr;
    unsigned char           tqui;
    unsigned char           tset;
    unsigned long           ttr;
    unsigned char           g;
    unsigned char           hsa;
    unsigned char           max_retry_limit;
    unsigned char           bp_flag;
    unsigned short          min_slave_interval;
    unsigned short          poll_timeout;
    unsigned short          data_control_time;
    unsigned char           reserved[6];
    char                    master_class2_name[32];
    T_MAS_USR               mas_usr;
} T_BUS_PARA;

typedef struct _T_MODE_ADDR_ALLOC
{
    unsigned char           md_path;
    unsigned char           md_kind;
    unsigned short          md_top_address;
    unsigned char           md_size;
    unsigned char           pad;
} T_MODE_ADDR_ALLOC;

typedef struct _T_SLAVE_IND_PARA
{
    unsigned char           slv_idx;
    unsigned char           slv_no;
} T_SLAVE_IND_PARA;

typedef struct _T_SLAVE_SUB_PARA
{
    T_SLAVE_IND_PARA        slv_ind_para;
    unsigned char           slv_enable;
    unsigned char           slt_num;
} T_SLAVE_SUB_PARA;

typedef struct _T_USR_PRM_DATA
{
    unsigned short          user_prm_data_len;
    unsigned char           user_prm_data[201];
    unsigned char           pad;
} T_USR_PRM_DATA;

typedef struct _T_PRM_DATA
{
    unsigned char           station_status;
    unsigned char           wd_fact_1;
    unsigned char           wd_fact_2;
    unsigned char           min_tsdr;
    unsigned short          ident_number;
    unsigned char           group_ident;
    unsigned char           pad;
    T_USR_PRM_DATA  usr_prm;
} T_PRM_DATA;

typedef struct _T_CFG_DATA
{
    unsigned short          cfg_data_len;
    unsigned char           cfg_data[128];
} T_CFG_DATA;

typedef struct _T_SLV_USR_DATA
{
    unsigned short          slave_user_data_len;
    unsigned char           slave_user_data[30];
} T_SLV_USR_DATA;

typedef struct _T_SLAVE_PARA
{
    T_SLAVE_IND_PARA        slv_ind_para;
    unsigned char           sl_flag;
    unsigned char           slave_type;
    unsigned char           reserved[12];
    T_PRM_DATA              prm_data;
    T_CFG_DATA              cfg_data;
    T_SLV_USR_DATA          slv_usr;
} T_SLAVE_PARA;

typedef struct _T_DGN_ADDR_ALLOC
{
    T_SLAVE_IND_PARA        slv_ind_para;
    unsigned char           dgn_path;
    unsigned char           dgn_kind;
    unsigned short          dgn_top_address;
    unsigned char           dgn_size;
    unsigned char           pad;
} T_DGN_ADDR_ALLOC;

typedef struct _T_SLOT_IND_PARA
{
    unsigned char           slv_no;
    unsigned char           slt_no;
} T_SLOT_IND_PARA;

typedef struct _T_MODULE_DATA
{
    T_SLOT_IND_PARA         slt_ind_para;
    unsigned short          module_len;
    unsigned char           module_data[128];
} T_MODULE_DATA;

typedef struct _T_DIDO_ADDR_ALLOC
{
    T_SLOT_IND_PARA         slt_ind_para;
    unsigned char           di_path;
    unsigned char           do_path;
    unsigned char           di_kind;
    unsigned char           do_kind;
    unsigned short          di_top_address;
    unsigned short          do_top_address;
    unsigned char           di_size;
    unsigned char           do_size;
    unsigned char           module_type;
    unsigned char           pad;
} T_DIDO_ADDR_ALLOC;

typedef struct _OUT_PBMPRM{
    union {
        T_BUS_PARA          bus_para;
        T_MODE_ADDR_ALLOC   mode_addr_alloc;
        T_SLAVE_SUB_PARA    slv_sub_para;
        T_SLAVE_PARA        slv_para;
        T_DGN_ADDR_ALLOC    dgn_addr_alloc;
        T_MODULE_DATA       module_data;
        T_DIDO_ADDR_ALLOC   dido_addr_alloc;
    } prm;
} OUT_PBMPRM;

/* pbm_wr_param */
typedef struct _T_MAS_USR_FLG
{
    char                    master_user_data_len;
    char                    master_user_data;
} T_MAS_USR_FLG;

typedef struct _T_BUS_PARA_FLG {
    char                    fdl_add;
    char                    baud_rate;
    char                    tsl;
    char                    min_tsdr;
    char                    max_tsdr;
    char                    tqui;
    char                    tset;
    char                    ttr;
    char                    g;
    char                    hsa;
    char                    max_retry_limit;
    char                    bp_flag;
    char                    min_slave_interval;
    char                    poll_timeout;
    char                    data_control_time;
    char                    pad1;
    char                    reserved[6];
    char                    master_class2_name_rsv;
    char                    pad2;
    T_MAS_USR_FLG   mas_usr;
} T_BUS_PARA_FLG;

typedef struct _T_MODE_ADDR_ALLOC_FLG
{
    char                    md_path;
    char                    md_kind;
    char                    md_top_address;
    char                    md_size;
} T_MODE_ADDR_ALLOC_FLG;

typedef struct _T_SLAVE_IND_PARA_FLG
{
    char                    slv_idx;
    char                    slv_no;
} T_SLAVE_IND_PARA_FLG;

typedef struct _T_SLAVE_SUB_PARA_FLG
{
    T_SLAVE_IND_PARA_FLG    slv_ind_para;
    char                    slv_enable;
    char                    slt_num;
} T_SLAVE_SUB_PARA_FLG;

typedef struct _T_USR_PRM_DATA_FLG
{
    char                    user_prm_data_len;
    char                    user_prm_data;
} T_USR_PRM_DATA_FLG;

typedef struct _T_PRM_DATA_FLG
{
    char                    station_status;
    char                    wd_fact_1;
    char                    wd_fact_2;
    char                    min_tsdr;
    char                    ident_number;
    char                    group_ident;
    T_USR_PRM_DATA_FLG      usr_prm;
} T_PRM_DATA_FLG;

typedef struct _T_CFG_DATA_FLG
{
    char                    cfg_data_len;
    char                    cfg_data;
} T_CFG_DATA_FLG;

typedef struct _T_SLV_USR_DATA_FLAG
{
    char                    slave_user_data_len;
    char                    slave_user_data;
} T_SLV_USR_DATA_FLG;

typedef struct _T_SLAVE_PARA_FLG
{
    T_SLAVE_IND_PARA_FLG    slv_ind_para;
    char                    sl_flag;
    char                    slave_type;
    char                    reserved[12];
    T_PRM_DATA_FLG          prm_data;
    T_CFG_DATA_FLG          cfg_data_rsv;
    T_SLV_USR_DATA_FLG      slv_usr;
} T_SLAVE_PARA_FLG;

typedef struct _T_DGN_ADDR_ALLOC_FLG
{
    T_SLAVE_IND_PARA_FLG    slv_ind_para;
    char                    dgn_path;
    char                    dgn_kind;
    char                    dgn_top_address;
    char                    dgn_size;
} T_DGN_ADDR_ALLOC_FLG;

typedef struct _T_SLOT_IND_PARA_FLG
{
    char                    slv_no;
    char                    slt_no;
} T_SLOT_IND_PARA_FLG;

typedef struct _T_MODULE_DATA_FLG
{
    T_SLOT_IND_PARA_FLG     slt_ind_para;
    char                    module_len;
    char                    module_data;
} T_MODULE_DATA_FLG;

typedef struct _T_DIDO_ADDR_ALLOC_FLG
{
    T_SLOT_IND_PARA_FLG     slt_ind_para;
    char                    di_path;
    char                    do_path;
    char                    di_kind;
    char                    do_kind;
    char                    di_top_address;
    char                    do_top_address;
    char                    di_size;
    char                    do_size;
    char                    module_type_rsv;
    char                    pad;
} T_DIDO_ADDR_ALLOC_FLG;

typedef struct _IN_PBMPRM{
    union {
        T_BUS_PARA          bus_para;
        T_MODE_ADDR_ALLOC   mode_addr_alloc;
        T_SLAVE_SUB_PARA    slv_sub_para;
        T_SLAVE_PARA        slv_para;
        T_DGN_ADDR_ALLOC    dgn_addr_alloc;
        T_MODULE_DATA       module_data;
        T_DIDO_ADDR_ALLOC   dido_addr_alloc;
    } prm;
} IN_PBMPRM;

typedef struct _IN_PBMPRMFLG {
    union {
        T_BUS_PARA_FLG          bus_para;
        T_MODE_ADDR_ALLOC_FLG   mode_addr_alloc;
        T_SLAVE_SUB_PARA_FLG    slv_sub_para;
        T_SLAVE_PARA_FLG        slv_para;
        T_DGN_ADDR_ALLOC_FLG    dgn_addr_alloc;
        T_MODULE_DATA_FLG       module_data;
        T_DIDO_ADDR_ALLOC_FLG   dido_addr_alloc;
    } flg;
} IN_PBMPRMFLG;

/* pbm_ini_prm */
typedef struct _T_SLVSLT_IND{
    unsigned char           slv_no;
    unsigned char           slt_no;
} T_SLVSLT_IND;

/* pbm_rd_allslvtbl */
typedef struct _T_SLVTBL{
    T_SLAVE_IND_PARA        slv_ind_para;
    unsigned char           slv_enable;
    unsigned char           slt_num;
    unsigned char           dgn_path;
    unsigned char           dgn_kind;
    unsigned short          dgn_top_address;
    unsigned char           dgn_size;
    unsigned char           pad;
} T_SLVTBL;

typedef struct _OUT_ALLSLVTBL{
    T_SLVTBL                slv_tbl[80];
} OUT_ALLSLVTBL;

/* pbm_rd_subprm */
typedef struct _T_MAXMODLENPRM{
    unsigned char           slv_no;
    unsigned char           slt_no;
    unsigned char           max_mod_len;
    unsigned char           pad;
} T_MAXMODLENPRM;

typedef struct _OUT_PBMSUBPRM{
    union {
        unsigned char       max_slv_num;
        unsigned char       max_slt_num;
        unsigned char       enb_slv_num;
        unsigned char       total_slts;
        unsigned char       shift_mode_stat;
        T_MAXMODLENPRM      max_mod_len_prm;
    } subprm;
} OUT_PBMSUBPRM;

/* pbm_rd_errcode */
typedef struct _T_ERR_CODE{
    unsigned short          param_err_code[4];
    unsigned short          inter_err_code[4];
} T_ERR_CODE;

/* pbm_chg_mode */
typedef struct _OUT_CHGMODERESULT{
    unsigned char           crnt_mode;
    unsigned char           pad;
    unsigned short          result;
} OUT_CHGMODERESULT;

/* pbm_rd_comstate */
typedef struct _T_DATA_REF_TIM{
    unsigned short          total_ref_tim;
    unsigned short          board_ref_tim;
    unsigned short          cnc_ref_tim;
} T_DATA_REF_TIM;

typedef struct _OUT_PBMCOMINFO{
    union {
        unsigned char       crnt_mode;
        T_DATA_REF_TIM      data_ref_tim;
    } cominfo;
} OUT_PBMCOMINFO;

/* pbm_rd_nodeinfo */
typedef struct _OUT_PBMNODEINFO{
    unsigned char           slv_no;
    unsigned char           commstat;
    unsigned char           status1;
    unsigned char           status2;
    unsigned char           status3;
    unsigned char           master;
    unsigned short          ident;
} OUT_PBMNODEINFO;

/* pbm_rd_slotinto */
typedef struct _OUT_PBMSLOTINFO{
    unsigned char           slv_no;
    unsigned char           slt_no;
    unsigned char           di_size;
    unsigned char           do_size;
    unsigned char           di_path;
    unsigned char           do_path;
    unsigned char           di_kind;
    unsigned char           do_kind;
    unsigned short          di_top_address;
    unsigned short          do_top_address;
    unsigned char           module_type;
    unsigned char           commstat;
    unsigned short          reserved;
} OUT_PBMSLOTINFO;

/* pbs_rd_param */
typedef struct _OUT_PBSPRM{
    unsigned char           slave_no;
    unsigned char           pad;
    unsigned char           di_size;
    unsigned char           do_size;
    unsigned char           di_path;
    unsigned char           do_path;
    unsigned char           di_kind;
    unsigned char           do_kind;
    unsigned short          di_top_address;
    unsigned short          do_top_address;
} OUT_PBSPRM;

/* pbs_wr_param */
typedef struct _IN_PBSPRMFLG{
    char                    slave_no;
    char                    pad;
    char                    di_size;
    char                    do_size;
    char                    di_path;
    char                    do_path;
    char                    di_kind;
    char                    do_kind;
    char                    di_top_address;
    char                    do_top_address;
} IN_PBSPRMFLG;

typedef struct _IN_PBSPRM{
    unsigned char           slave_no;
    unsigned char           pad;
    unsigned char           di_size;
    unsigned char           do_size;
    unsigned char           di_path;
    unsigned char           do_path;
    unsigned char           di_kind;
    unsigned char           do_kind;
    unsigned short          di_top_address;
    unsigned short          do_top_address;
} IN_PBSPRM;

/* pbs_rd_cominfo */
typedef struct _OUT_PBSSTATUS{
    unsigned char           config_sts;
    unsigned char           param_sts;
    unsigned char           watchdog_sts;
    unsigned char           pad;
    unsigned short          ident_no;
} OUT_PBSSTATUS;

/* pbs_rd_param2 */
typedef struct _OUT_PBSPRM2{
    unsigned char           slave_no;
    unsigned char           pad;
    unsigned char           di_size;
    unsigned char           do_size;
    unsigned char           di_path;
    unsigned char           do_path;
    unsigned char           di_kind;
    unsigned char           do_kind;
    unsigned short          di_top_address;
    unsigned short          do_top_address;
    unsigned char           sts_path;
    unsigned char           sts_kind;
    unsigned short          sts_top_address;
} OUT_PBSPRM2;

/* pbs_wr_param2 */
typedef struct _IN_PBSPRMFLG2{
    char                    slave_no;
    char                    pad1;
    char                    di_size;
    char                    do_size;
    char                    di_path;
    char                    do_path;
    char                    di_kind;
    char                    do_kind;
    char                    di_top_address;
    char                    do_top_address;
    char                    sts_path;
    char                    sts_kind;
    char                    sts_top_address;
    char                    pad2;
} IN_PBSPRMFLG2;

typedef struct _IN_PBSPRM2{
    unsigned char           slave_no;
    unsigned char           pad;
    unsigned char           di_size;
    unsigned char           do_size;
    unsigned char           di_path;
    unsigned char           do_path;
    unsigned char           di_kind;
    unsigned char           do_kind;
    unsigned short          di_top_address;
    unsigned short          do_top_address;
    unsigned char           sts_path;
    unsigned char           sts_kind;
    unsigned short          sts_top_address;
} IN_PBSPRM2;

/* pbs_rd_cominfo2 */
typedef struct _OUT_PBSSTATUS2{
    unsigned char           config_sts;
    unsigned char           param_sts;
    unsigned char           watchdog_sts;
    unsigned char           pad1;
    unsigned short          ident_no;
    unsigned char           sts;
    unsigned char           pad2;
} OUT_PBSSTATUS2;

/*--------------------------*/
/* HSSB multiple connection */
/*--------------------------*/

/* cnc_rdnodeinfo:read node informations */
typedef struct odbnode {
	long node_no;
	long io_base;
	long status;
	long cnc_type;
	char node_name[20];
} ODBNODE;

/*--------------------------*/
/*  Power Mate CNC manager  */
/*--------------------------*/

/* initialize */

typedef struct odbpmmslv {
	long	slvnum;       /* a number of groups  */
	long	group[8];     /* group's number */
}ODBPMMSLV;

/* get serise , version */

typedef struct odbpmmsyd {
    char   system[2];     /* */
    char   model[2];      /* */
    char   series[4];     /* serise */
    char   edition[4];    /* version */
} ODBPMMSYD ;


/* get continuos data start */

typedef struct idbpmmgti {
	long	top;         /* top number */
	long	num;         /* number of data  */
} IDBPMMGTI ;


/* get continuos data */
typedef struct odbpmmget {
	long   pos     ;        /* position           */
	long   feed    ;        /* actual feed        */
    long   data[20];        /* diagnosis's data   */
	long   number[20];      /* number of diagnosis's data */
	short  axis[20];        /* axis attribute of diagnosis's data */
	short  type[20];        /* data type of diagnosis's data */
	char   alaxis[40];        /* axis attribute of alarm */
	unsigned short  alnumber[40]; /* number of alarm */
	long   chanl ;     /* data's chanl      */
	long   group ;     /* data's group      */
} ODBPMMGET ;

/* get parameter 1 page */
typedef struct odbpmmprp {
	long            data    ;        /* data    */
	unsigned short  number  ;        /* number  */
	unsigned char   axis    ;        /* axis attribute */
	unsigned char   type    ;        /* data type */
} ODBPMMPRP ;

/* read/write  parameter (tape memory) */
typedef struct idbpmmprp {
	long   chanl       ;        /* channel */
	long   group       ;        /* group   */
	char   folder[130] ;        /* folder (current //CNC_MEM/USER/PATH1/)*/
	long   warn        ;        /* warnning */
} IDBPMMPRP ;

/* I/O LINK channel number */
typedef struct odbpmmio {
    long   chanlnum;     /* channel number */
} ODBPMMIO ;

/*--------------------------*/
/* real-time custom macro   */
/*--------------------------*/

typedef struct  iodbrtmio {
	short adr_type;
	short dummy;
	unsigned long no;
	char	bit;
} IODBRTMIO ;

typedef struct  iodbrtmior {
	short adr_type;		/* kind of DI/DO variable address(alphabet) */
	long adr_attr ;		/* PMC address attribute (use for cnc_getrtmioinfo only) */
	unsigned long sno;	/* DI/DO variable access enable start no. */
	unsigned long eno;	/* DI/DI variable access enable end no. */
} IODBRTMIOR ;


/* Distribute infomation */
typedef struct odbipl {
	unsigned char	outpt;
	unsigned char	ipltp;
	unsigned char	mv;     /* Not used             */
	unsigned char	inp;    /* Not used             */
} ODBIPL ;

/* Axis move distance */
typedef struct  iodbaxis {
    int	    axnum;          /* Axis number          */
    long    data[MAX_AXIS]; /* Axis move distance   */
    long    dp[MAX_AXIS];   /* Decimal point        */
} IODBAXIS ;

/* cnc_wrtofsdrctinp:write Tool offset data Direct Input */
typedef struct realmes {
	long   mes_val; /* data of real measeure */
	long   dec_val; /* decimal point of real measeure */
} REALMES;

/* servoid spindleid info */
typedef struct odbcsvid {
    char   mt_spc[20] ;        /* servo motor spec	*/
    char   mt_srn[10] ;        /* servo motor s/n	*/
    char   plc_spc[22] ;       /* pulsecoder spec	*/
    char   plc_srn[9] ;        /* pulsecoder s/n	*/
    char   svm_spc[22] ;       /* servo amp spec	*/
    char   svm_srn[12] ;       /* servo amp s/n		*/
    char   psm_spc[22] ;       /* psm spec			*/
    char   psm_srn[12] ;       /* psm s/n			*/
} ODBCSVID ;

typedef struct odbcspid {
    char   mt_spc[20] ;		   /* sp motor spec		*/
    char   mt_srn[10] ;		   /* sp motor s/n		*/
    char   sbmt_spc[20] ;	   /* subsp motor spec  */
    char   sbmt_srn[10] ;	   /* subsp motor s/n	*/
    char   spm_spc[22] ;	   /* sp amp spec		*/
    char   spm_srn[12] ;	   /* sp amp s/n		*/
    char   psm_spc[22] ;	   /* psm spec			*/
    char   psm_srn[12] ;	   /* psm s/n			*/
} ODBCSPID ;

/* servoid spindleid info2 */
typedef struct odbcsvid2 {
    char   mt_spc[20] ;        /* servo motor spec       */
    char   mt_srn[10] ;        /* servo motor s/n        */
    char   plc_spc[22] ;       /* pulsecoder spec        */
    char   plc_srn[9] ;        /* pulsecoder s/n         */
    char   svm_spc[22] ;       /* sv spec                */
    char   svm_srn[12] ;       /* sv s/n                 */
    char   psm_spc[22] ;       /* ps spec                */
    char   psm_srn[12] ;       /* ps s/n                 */
    char   svs_see[9] ;        /* sv soft series/edition */
    char   pss_see[9] ;        /* ps soft series/edition */
    char   pm1_spc[22] ;       /* pm1 spec               */
    char   pm1_srn[9] ;        /* pm1 s/n                */
    char   pm2_spc[22] ;       /* pm2 spec               */
    char   pm2_srn[9] ;        /* pm2 s/n                */
} ODBCSVID2 ;

typedef struct odbcspid2 {
    char   mt_spc[20] ;        /* main spinlde motor spec */
    char   mt_srn[10] ;        /* main spinlde motor s/n  */
    char   sbmt_spc[20] ;      /* sub spinlde motor spec  */
    char   sbmt_srn[10] ;      /* sub spinlde motor s/n   */
    char   spm_spc[22] ;       /* sp spec                 */
    char   spm_srn[12] ;       /* sp s/n                  */
    char   psm_spc[22] ;       /* ps spec                 */
    char   psm_srn[12] ;       /* ps s/n                  */
    char   pss_see[9] ;        /* ps soft series/edition  */
} ODBCSPID2 ;

/* Dual Check Safety MCC Test Status */
typedef struct dcsmcc {
	 struct {
		 long  hour;
		 long  minute;
		 long  second;
	 } time;
	 long  testno;		/* Last Test No. */
	 long  sign;		/* Test Request DI */
} DCSMCC;

typedef struct dcsmca {
	long	mgrp_no ;
	DCSMCC*	mcc_test_inf ;
} DCSMCA;

typedef struct dcsfmoni {
    long  data_d ;		/* Fixed Val  */
    long  data_p ;		/* Present Val*/
} ODBDCSFMONI;

typedef struct dcscrsalm {
	long existFlag;
	long pmc_no;
	struct {
		char  pmc_adr[8] ;
		long  pmc_data[8];
		char  dcs_adr[8];
		long  dcs_data[8];
	} pmc ;
	struct {
		char  pmc_adr[8] ;
		long  pmc_data[8];
		char  dcs_adr[8];
		long  dcs_data[8];
	} dcspmc ;
} DCSCRSALM ;

typedef struct dcssvspsts {
 	char	name[4];
 	long	dummy;
    double	ncdata;
    double	svspdata;
}DCSSVSPSTS;

typedef struct dcssvspst2 {
	double	limit_dt_p;
	double	limit_dt_m;
	short	axissts;
	short	unittype;
	char	axissts2;
	char	level;
	char	alm_lvl;
	char	add_info;
}DCSSVSPST2;


/*----------------------------*/
/* NET : DeviceNet function   */
/*----------------------------*/
typedef struct _pmc_reg {
    unsigned char   Path;
    unsigned char   Kind;
    unsigned short  Address;
} PMC_REG;

/* dnm_rdparam  */
/* dnm_rdparam2 */
typedef struct _out_dnmprm_bus {
    short           Network;
    short           BaudRate;
    short           DiDataOnAbnormal;
    short           OwnMacId;
    PMC_REG         CommonStatus;
    short           CommonStatusSize;
    short           CycleTimeSetting;
    short           CycleTimeCurrent;
    short           CycleTimeMaximum;
    short           CycleTimeMinimum;
    unsigned short  RefreshTime;
} OUT_DNMPRM_BUS;

typedef struct _out_dnmprm_each_node {
    short           NodeNumber;
    short           Communication;
    short           reserved1[6];
    PMC_REG         DetailStatus;
    short           reserved2[2];
    PMC_REG         Di;
    short           DiSize;
    short           reserved3;
    PMC_REG         Do;
    short           DoSize;
    short           reserved4;
} OUT_DNMPRM_SLAVE;

typedef struct _out_dnmprm {
    union {
        OUT_DNMPRM_BUS      bus;
        OUT_DNMPRM_SLAVE    slave;
    } prm;
} OUT_DNMPRM;

typedef struct _out_dnmprm_bus2 {
    short           Network;
    short           BaudRate;
    short           DiDataOnAbnormal;
    short           OwnMacId;
    PMC_REG         CommonStatus;
    short           CommonStatusSize;
    short           CycleTimeSetting;
    short           CycleTimeCurrent;
    short           CycleTimeMaximum;
    short           CycleTimeMinimum;
    unsigned short  RefreshTime;
    unsigned short  Option;
    short           reserved;
} OUT_DNMPRM_BUS2;

typedef struct _out_dnmprm2 {
    union {
        OUT_DNMPRM_BUS2     bus;
        OUT_DNMPRM_SLAVE    slave;
    } prm;
} OUT_DNMPRM2;

/* dnm_wrparam  */
/* dnm_wrparam2 */
typedef struct _in_dnmprmflag_bus {
    char            Network;
    char            BaudRate;
    char            DiDataOnAbnormal;
    char            OwnMacId;
    char            CommonStatus;
    char            CommonStatusSize;
    char            CycleTimeSetting;
    char            reserved[9];
} IN_DNMPRMFLAG_BUS;

typedef struct _in_dnmprmflag_each_node {
    char            Communication;
    char            DetailStatus;
    char            Di;
    char            DiSize;
    char            Do;
    char            DoSize;
    char            reserved[10];
} IN_DNMPRMFLAG_SLAVE;

typedef struct _in_dnmprmflag {
    union {
        IN_DNMPRMFLAG_BUS   bus;
        IN_DNMPRMFLAG_SLAVE slave;
    } flg;
} IN_DNMPRMFLAG;

typedef struct _in_dnmprmflag_bus2 {
    char            Network;
    char            BaudRate;
    char            DiDataOnAbnormal;
    char            OwnMacId;
    char            CommonStatus;
    char            CommonStatusSize;
    char            CycleTimeSetting;
    char            reserved1[4];
    char            Option;
    char            reserved2[4];
} IN_DNMPRMFLAG_BUS2;

typedef struct _in_dnmprmflag2 {
    union {
        IN_DNMPRMFLAG_BUS2  bus;
        IN_DNMPRMFLAG_SLAVE slave;
    } flg;
} IN_DNMPRMFLAG2;

typedef struct _in_dnmprm_bus {
    short           Network;
    short           BaudRate;
    short           DiDataOnAbnormal;
    short           OwnMacId;
    PMC_REG         CommonStatus;
    short           CommonStatusSize;
    short           CycleTimeSetting;
    short           reserved[8];
} IN_DNMPRM_BUS;

typedef struct _in_dnmprm_each_node {
    short           reserved1;
    short           Communication;
    short           reserved2[6];
    PMC_REG         DetailStatus;
    short           reserved3[2];
    PMC_REG         Di;
    short           DiSize;
    short           reserved4;
    PMC_REG         Do;
    short           DoSize;
    short           reserved5;
} IN_DNMPRM_SLAVE;

typedef struct _in_dnmprm {
    union {
        IN_DNMPRM_BUS       bus;
        IN_DNMPRM_SLAVE     slave;
    } prm;
} IN_DNMPRM;

typedef struct _in_dnmprm_bus2 {
    short           Network;
    short           BaudRate;
    short           DiDataOnAbnormal;
    short           OwnMacId;
    PMC_REG         CommonStatus;
    short           CommonStatusSize;
    short           CycleTimeSetting;
    short           reserved1[4];
    unsigned short  Option;
    short           reserved2[3];
} IN_DNMPRM_BUS2;

typedef struct _in_dnmprm2 {
    union {
        IN_DNMPRM_BUS2      bus;
        IN_DNMPRM_SLAVE     slave;
    } prm;
} IN_DNMPRM2;

/* dnm_rdnodetable */
typedef struct _out_dnmnode {
    char        node[64];
} OUT_DNMNODE;

/* dnm_rdnodeinfo */
typedef struct _out_dnmnodeinfo {
    short           MacId;
    short           State;
    short           RetryCounter;
    unsigned short  VenderId;
    unsigned short  DeviceType;
    unsigned short  ProductCode;
} OUT_DNMNODEINFO;

/* dnm_rdfirminfo */
typedef struct _out_dnmfirm {
    unsigned short  MpuStatus1;
    unsigned short  MpuStatus2;
    unsigned short  MasterStatus1;
    unsigned short  CanRecvCounter;
    unsigned short  CanSendCounter;
    unsigned short  CanRecvErrorCounter;
    unsigned short  CanSendErrorCounter;
    unsigned short  FirmwareVersion;
} OUT_DNMFIRM;

/* dnm_rderrorrecord */
typedef struct _out_dnmerr_record {
    unsigned short  AbnormalCode;
    unsigned short  DetailCode;
} OUT_DNMERR_RECORD;

typedef struct _out_dnmerr {
    OUT_DNMERR_RECORD   record[8];
} OUT_DNMERR;

/* dnm_rd_hist */
typedef struct _out_dnmhist_log {
    unsigned char   Type;
    unsigned char   reserved;
    unsigned short  Mpu1;
    unsigned short  Mpu2;
    unsigned short  Sts1;
    unsigned char   Slave[8];
    unsigned char   Date;
    unsigned char   Hour;
    unsigned char   Minute;
    unsigned char   Second;
} OUT_DNMHIST_LOG;

typedef struct _out_dnmhist {
    unsigned short  Count;
    unsigned short  reserved;
    OUT_DNMHIST_LOG Log[32];
} OUT_DNMHIST;

/* dns_rdparam */
typedef struct _out_dnsprm {
    short           BaudRate;
    short           DiDataOnAbnormal;
    short           OwnMacId;
    char            pad1[2];
    PMC_REG         Di;
    short           DiSize;
    char            pad2[2];
    PMC_REG         Do;
    short           DoSize;
    char            pad3[2];
    PMC_REG         Status;
    short           StatusSize;
    char            pad4[2];
} OUT_DNSPRM;

/* dns_wrparam */
typedef struct _in_dnsprmflag {
    char            BaudRate;
    char            DiDataOnAbnormal;
    char            OwnMacId;
    char            Di;
    char            DiSize;
    char            Do;
    char            DoSize;
    char            Status;
    char            StatusSize;
    char            pad[7];
} IN_DNSPRMFLAG;

typedef struct _in_dnsprm {
    short           BaudRate;
    short           DiDataOnAbnormal;
    short           OwnMacId;
    char            pad1[2];
    PMC_REG         Di;
    short           DiSize;
    char            pad2[2];
    PMC_REG         Do;
    short           DoSize;
    char            pad3[2];
    PMC_REG         Status;
    short           StatusSize;
    char            pad4[2];
} IN_DNSPRM;

/* dns_rdinfo */
typedef struct _dnsidentityinfo {
    unsigned short  VenderID;
    unsigned short  DeviceType;
    unsigned short  ProductCode;
    unsigned char   MajorRev;
    unsigned char   MinorRev;
    unsigned long   SerialNo;
    char            ProductName[32];
    char            pad[4];
} DNS_IDENTITY_INFO;

typedef struct _dnsstatusinfo {
    unsigned char   Status;
    unsigned char   MpuStatus;
    unsigned char   MpuState;
    unsigned char   MpuAlarmCode;
    unsigned char   MpuVerInfo;
    unsigned char   pad[3];
} DNS_STATUS_INFO;

typedef struct _out_dnsmonitor {
    DNS_IDENTITY_INFO   IdentityInfo;
    DNS_STATUS_INFO     StatusInfo;
} OUT_DNSINFO;

/* dns_rd_hist */
typedef struct _out_dnshist_log {
    unsigned char   Type;
    unsigned char   Status;
    unsigned char   MpuStatus;
    unsigned char   MpuFsm;
    unsigned char   MpuAlarm;
    unsigned char   Date;
    unsigned char   Hour;
    unsigned char   Minute;
    unsigned char   Second;
    unsigned char   reserved[3];
} OUT_DNSHIST_LOG;

typedef struct _out_dnshist {
    unsigned short  Count;
    unsigned short  reserved;
    OUT_DNSHIST_LOG Log[32];
} OUT_DNSHIST;


/*----------------------------*/
/* NET : FL-net function      */
/*----------------------------*/

/* flnt_rdparam  */
/* flnt_rdparam2 */
typedef struct _out_flntprm {
    char            OwnMacAddress[16];
    char            OwnIpAddress[40];
    char            NodeName[12];
    short           Area1CmnMemAddr;
    short           Area1CmnMemSize;
    short           Area2CmnMemAddr;
    short           Area2CmnMemSize;
    unsigned char   TokenWatch;
    char            MinFrame;
    char            Reserved0[2];
    PMC_REG         OwnStatus;
    PMC_REG         EntryNode;
    PMC_REG         Area1PmcAddr;
    short           Area1ExchgAddr;
    short           Area1ExchgSize;
    PMC_REG         Area2PmcAddr;
    short           Area2ExchgAddr;
    short           Area2ExchgSize;
    PMC_REG         Area2PmcDoAddr;
    short           Area2ExchgDoSize;
    char            Reserved1[2];
    PMC_REG         Area2PmcDiAddr;
    PMC_REG         Area2ConditionAddr;
    PMC_REG         Area2AlterAddr;
    short           Area2ExchgDiAddr;
    short           Area2ExchgDiSize;
    PMC_REG         ClientMsgAddr;
    short           ClientMsgSize;
    char            Reserved2[2];
    PMC_REG         ServerMsgAddr;
    short           ServerMsgSize;
    char            Reserved3[2];
    unsigned short  Option1;
    unsigned short  Option2;
} OUT_FLNTPRM;

/* flnt_wrparam  */
/* flnt_wrparam2 */
typedef struct _in_flntprmflag {
    char            OwnIpAddress;
    char            NodeName;
    char            Area1CmnMemAddr;
    char            Area1CmnMemSize;
    char            Area2CmnMemAddr;
    char            Area2CmnMemSize;
    char            TokenWatch;
    char            MinFrame;
    char            OwnStatus;
    char            EntryNode;
    char            Area1PmcAddr;
    char            Area1ExchgAddr;
    char            Area1ExchgSize;
    char            Area2PmcAddr;
    char            Area2ExchgAddr;
    char            Area2ExchgSize;
    char            Area2PmcDoAddr;
    char            Area2ExchgDoSize;
    char            Area2PmcDiAddr;
    char            Area2ConditionAddr;
    char            Area2AlterAddr;
    char            Area2ExchgDiAddr;
    char            Area2ExchgDiSize;
    char            ClientMsgAddr;
    char            ClientMsgSize;
    char            ServerMsgAddr;
    char            ServerMsgSize;
    char            Option1;
    char            Option2;
} IN_FLNTPRMFLG;

typedef struct _in_flntprm {
    char            OwnIpAddress[40];
    char            NodeName[12];
    short           Area1CmnMemAddr;
    short           Area1CmnMemSize;
    short           Area2CmnMemAddr;
    short           Area2CmnMemSize;
    unsigned char   TokenWatch;
    char            MinFrame;
    char            Reserved0[2];
    PMC_REG         OwnStatus;
    PMC_REG         EntryNode;
    PMC_REG         Area1PmcAddr;
    short           Area1ExchgAddr;
    short           Area1ExchgSize;
    PMC_REG         Area2PmcAddr;
    short           Area2ExchgAddr;
    short           Area2ExchgSize;
    PMC_REG         Area2PmcDoAddr;
    short           Area2ExchgDoSize;
    char            Reserved1[2];
    PMC_REG         Area2PmcDiAddr;
    PMC_REG         Area2ConditionAddr;
    PMC_REG         Area2AlterAddr;
    short           Area2ExchgDiAddr;
    short           Area2ExchgDiSize;
    PMC_REG         ClientMsgAddr;
    short           ClientMsgSize;
    char            Reserved2[2];
    PMC_REG         ServerMsgAddr;
    short           ServerMsgSize;
    char            Reserved3[2];
    unsigned short  Option1;
    unsigned short  Option2;
} IN_FLNTPRM;

/* flnt_rdentry  */
/* flnt_rdentry2 */
typedef struct _out_flntentry {
    unsigned char   Node;
    char            Reserved[3];
    unsigned long   EntryNode[8];
} OUT_FLNTENTRY;

/* flnt_rdnodeinfo  */
/* flnt_rdnodeinfo2 */
typedef struct _out_flntnodetbl {
    char            NodeName[12];
    char            VendorName[12];
    char            MakerType[12];
    short           Area1Address;
    short           Area1Size;
    short           Area2Address;
    short           Area2Size;
    unsigned short  Rct;
    unsigned short  Uls;
    unsigned char   TokenWatch;
    unsigned char   MinFrame;
    unsigned char   Lks;
    unsigned char   Status;
} OUT_FLNTNODETBL;

/* flnt_rdnetwork  */
/* flnt_rdnetwork2 */
typedef struct _out_flntnettbl {
    unsigned char   TokenNode;
    unsigned char   MinFrame;
    unsigned short  Rct;
    unsigned short  Rcm;
    unsigned short  MaxRcm;
    unsigned short  MinRcm;
} OUT_FLNTNETTBL;

/* flnt_rdlog */
typedef struct _out_flntlog {
    unsigned long   TotalSend;
    unsigned long   SendErr;
    unsigned long   TotalRecv;
    unsigned long   RecvErr;
    unsigned long   CycErr;
    unsigned long   MsgRetry;
    unsigned long   MsgRetryOver;
    unsigned long   RecvMsgErr;
    unsigned long   AckErr;
    unsigned long   DuplicatedToken;
    unsigned long   DestroyedToken;
    unsigned long   ReissueToken;
    unsigned long   FrameWait;
    unsigned long   Entry;
    unsigned long   OutRing;
    unsigned long   Skip;
    unsigned long   Disconnect;
} OUT_FLNTLOG;

/* flnt_rdlog2 */
typedef struct _out_flntlog2 {
    unsigned long   TotalSend;
    unsigned long   SendErr;
    unsigned long   TotalRecv;
    unsigned long   RecvErr;
    unsigned long   CycErr;
    unsigned long   MsgRetry;
    unsigned long   MsgRetryOver;
    unsigned long   RecvMsgErr;
    unsigned long   AckErr;
    unsigned long   DuplicatedToken;
    unsigned long   DestroyedToken;
    unsigned long   ReissueToken;
    unsigned long   FrameWait;
    unsigned long   Entry;
    unsigned long   OutRing;
    unsigned long   Skip;
    unsigned long   Disconnect;
    short           Baudrate;
    char            Reserved[2];
} OUT_FLNTLOG2;

/* flnt_rdmsg  */
/* flnt_rdmsg2 */
typedef struct _out_flnteachmsg {
    unsigned short  MsgId;
    unsigned char   Year;
    unsigned char   Month;
    unsigned char   Day;
    unsigned char   Hour;
    unsigned char   Minute;
    unsigned char   Second;
    char            Text[32];
} OUT_FLNTEACHMSG;

typedef struct _out_flntmsg {
    short           Count;
    char            reserve[14];
    OUT_FLNTEACHMSG msgData[15];
} OUT_FLNTMSG;

/* flnt_rddeviceinfo */
typedef struct _out_flntdevinfo {
    unsigned short      Kind;
    short               dummy;
    unsigned long       FunctionFLnetBoard;
    unsigned long       FunctionFLnetEmb;
    unsigned long       FunctionFLnetCard;
} OUT_FLNTDEVINFO;

/* flnt_rddeviceinfo2 */
typedef struct _out_flntdevinfo2 {
    unsigned short      Kind;
    short               Pad;
    unsigned long       FunctionFLnet;
} OUT_FLNTDEVINFO2;

/* flnt_rdsfstatus */
typedef struct _each_sts{
    unsigned char   StatusFlag;
    unsigned char   ErrDetectNode;
    unsigned char   ErrSendNode;
    char            Reserved[1];
} EACH_STS;

typedef struct _out_flntsfsts{
    EACH_STS        eachSts[2];
    short           AlarmInfo;
    char            Reserved[2];
} OUT_FLNTSFSTS;

/* flnt_rdsferrnode */
typedef struct _each_err{
    unsigned char   ErrFlag;
    unsigned char   ErrNode;
    char            Reserved[2];
} EACH_ERR;

typedef struct _node_err{
    EACH_ERR        eachErr[2];
} NODE_ERR;

typedef struct _out_flntsferrtbl{
    unsigned char   SelfNode;
    char            Reserved[3];
    unsigned long   EntryNode;
    NODE_ERR        nodeErr[30];
} OUT_FLNTSFERRTBL;


/*----------------------------*/
/* NET : CC-Link function     */
/*----------------------------*/

/* cclr_rdparam */
typedef struct _out_cclrprm {
    short           BaudRate;
    short           ID;
    short           UseIDCount;
    short           DataOnAbnormal;
    PMC_REG         Status;
    PMC_REG         RY;
    short           RYSize;
    char            pad1[2];
    PMC_REG         RX;
    short           RXSize;
    char            pad2[2];
    PMC_REG         RWw;
    short           RWwSize;
    char            pad3[2];
    PMC_REG         RWr;
    short           RWrSize;
    char            pad4[2];
} OUT_CCLRPRM;

/* cclr_wrparam */
typedef struct _in_cclrprmflag {
    char            BaudRate;
    char            ID;
    char            UseIDCount;
    char            DataOnAbnormal;
    char            Status;
    char            RY;
    char            RYSize;
    char            RX;
    char            RXSize;
    char            RWw;
    char            RWwSize;
    char            RWr;
    char            RWrSize;
    char            pad[3];
} IN_CCLRPRMFLAG;

typedef struct _in_cclrprm {
    short           BaudRate;
    short           ID;
    short           UseIDCount;
    short           DataOnAbnormal;
    PMC_REG         Status;
    PMC_REG         RY;
    short           RYSize;
    char            pad1[2];
    PMC_REG         RX;
    short           RXSize;
    char            pad2[2];
    PMC_REG         RWw;
    short           RWwSize;
    char            pad3[2];
    PMC_REG         RWr;
    short           RWrSize;
    char            pad4[2];
} IN_CCLRPRM;

/* cclr_rdinfo */
typedef struct _out_cclrinfo {
    unsigned char   LineStatus;
    unsigned char   MachineCode;
    unsigned short  MakerCode;
    unsigned short  errCode;
    char            pad[2];
} OUT_CCLRINFO;


/*----------------------------*/
/* NET : USB function         */
/*----------------------------*/

/* usb_rdinfo */
typedef struct _out_usbinfo {
    short           UsbStatus;
    unsigned short  VendorID;
    unsigned short  ProductID;
    unsigned short  DeviceRelease;
    char            Manufacturer[64];
    char            ProductName[64];
    char            SerialNumber[64];
} OUT_USBINFO;

/* usb_rdlog */
typedef struct _out_usblog1shot {
    short           Type;
    unsigned short  MsgId;
    unsigned char   Year;
    unsigned char   Month;
    unsigned char   Day;
    unsigned char   Hour;
    unsigned char   Minute;
    unsigned char   Second;
    char            reserve[2];
    char            Text[84];
} OUT_USBLOG1SHOT;

typedef struct _out_usblog {
    short           Count;
    char            reserve[14];
    OUT_USBLOG1SHOT logData[15];
} OUT_USBLOG;

/*-----------------------------------*/
/* NET : PROFINET IO Device function */
/*-----------------------------------*/

typedef struct _pnd_addr {
    unsigned short          Path;
    short                   Kind;
    unsigned long           Addr;
    unsigned long           Size;
} PND_ADDR;

typedef struct _pnd_common_param {
    char                    OwnMacAddress[16];
    char                    OwnIpAddress[40];
    char                    SubNetmask[16];
    char                    RouterIpAddress[40];
    char                    DnsServer1IpAddress[40];
    char                    DnsServer2IpAddress[40];
    char                    OwnHostName[32];
    char                    OwnDomain[64];
} PND_COMMON_PARAM;

typedef struct _pnd_ping_param {
    char                    IpAddress[64];
    unsigned short          Count;
    char                    pad[2];
} PND_PING_PARAM;

typedef struct _pnd_setting_param {
    unsigned char           PnDeviceMode;
    unsigned char           DiDataOnAbnormal;
    unsigned char           pad1[2];
    unsigned char           BasicOption1;
    unsigned char           BasicOption2;
    unsigned char           AllocOption1;
    unsigned char           AllocOption2;
    PND_ADDR                DiData;
    PND_ADDR                DoData;
    PND_ADDR                Status;
    char                    DeviceName[244];
} PND_SETTING_PARAM;

typedef struct _pnd_param_flg {
    char                    OwnIpAddress;
    char                    SubNetmask;
    char                    RouterIpAddress;
    char                    DnsServer1IpAddress;
    char                    DnsServer2IpAddress;
    char                    OwnHostName;
    char                    OwnDomain;
    char                    PingIpAddress;
    char                    PingCount;
    char                    PnDeviceMode;
    char                    DiDataOnAbnormal;
    char                    BasicOption1;
    char                    BasicOption2;
    char                    AllocOption1;
    char                    AllocOption2;
    char                    DiData;
    char                    DoData;
    char                    Status;
    char                    DeviceName;
    char                    pad2;
} PND_PARAM_FLG;

typedef struct _pnd_param {
    PND_COMMON_PARAM        Common;
    PND_PING_PARAM          Ping;
    PND_SETTING_PARAM       Setting;
} PND_PARAM;

typedef PND_PARAM           OUT_PND_PARAM;

typedef struct _in_pnd_param {
    PND_PARAM_FLG           flg;
    PND_PARAM               prm;
} IN_PND_PARAM;

typedef struct _out_pnd_mntinfo {
    unsigned char           Status;
    unsigned char           pad[3];
    unsigned short          VendorID;
    unsigned short          DeviceID;
    unsigned short          InputSize;
    unsigned short          OutputSize;
    unsigned short          RcvRead;
    unsigned short          RcvWrite;
    unsigned short          RcvRt;
    unsigned short          RcvRtU;
    unsigned short          RcvPause;
    unsigned short          RcvLldp;
    unsigned short          InputCycleTime;
    unsigned short          OutputCycleTime;
    unsigned short          DoRefreshTime;
    unsigned short          DiRefreshTIme;
} OUT_PND_MNTINFO;

/*---------------------------------------*/
/* NET : PROFINET IO Controller function */
/*---------------------------------------*/

/* pnc_rdparam pnc_wrparam */
typedef struct _pnc_addr {
    unsigned short          Path;
    short                   Kind;
    unsigned long           Addr;
    unsigned long           Size;
} PNC_ADDR;

/* pnc_rdparam */
typedef struct _pnc_common_param {
    char                    OwnMacAddress[16];
    char                    OwnIpAddress[40];
    char                    SubNetmask[16];
    char                    RouterIpAddress[40];
} PNC_COMMON_PARAM;

/* pnc_rdparam pnc_wrparam */
typedef struct _pnc_ping_param {
    char                    IpAddress[64];
    unsigned short          Count;
    char                    pad[2];
} PNC_PING_PARAM;

/* pnc_rdparam */
typedef struct _pnc_setting_param {
    unsigned char           PnControllerMode;
    unsigned char           TotalDeviceNum;
    unsigned char           BasicOption1;
    unsigned char           reserve1;
    PNC_ADDR                DiData;
    PNC_ADDR                DoData;
    PNC_ADDR                Status;
    unsigned char           reserve2[12];
} PNC_SETTING_PARAM;

/* pnc_rdparam */
typedef struct _pnc_param {
    PNC_COMMON_PARAM        Common;
    PNC_PING_PARAM          Ping;
    PNC_SETTING_PARAM       Setting;
} PNC_PARAM;

/* pnc_rdparam */
typedef PNC_PARAM           OUT_PNC_PARAM;

/* pnc_wrparam pnc_rdmntinfo */
typedef struct _pnc_addr_top {
    unsigned short          Path;
    short                   Kind;
    unsigned long           Addr;
} PNC_ADDRTOP;

/* pnc_wrparam */
typedef struct _pnc_common_param_w {
    char                    OwnIpAddress[40];
    char                    SubNetmask[16];
    char                    RouterIpAddress[40];
} PNC_COMMON_PARAM_W;

/* pnc_wrparam */
typedef struct _pnc_setting_param_w {
    unsigned char           PnControllerMode;
    unsigned char           pad;
    unsigned char           BasicOption1;
    unsigned char           reserve1;
    PNC_ADDRTOP             DiAddrTop;
    PNC_ADDRTOP             DoAddrTop;
    PNC_ADDR                Status;
    unsigned char           reserve2[12];
} PNC_SETTING_PARAM_W;

/* pnc_wrparam */
typedef struct _pnc_param_flg {
    char                    OwnIpAddress;
    char                    SubNetmask;
    char                    RouterIpAddress;
    char                    PingIpAddress;
    char                    PingCount;
    char                    PnControllerMode;
    char                    BasicOption1;
    char                    reserve1;
    char                    DiAddrTop;
    char                    DoAddrTop;
    char                    Status;
    char                    reserve2;
} PNC_PARAM_FLG;

/* pnc_wrparam */
typedef struct _pnc_param_w {
    PNC_COMMON_PARAM_W      Common;
    PNC_PING_PARAM          Ping;
    PNC_SETTING_PARAM_W     Setting;
} PNC_PARAM_W;

/* pnc_wrparam */
typedef struct _in_pnc_param {
    PNC_PARAM_FLG           flg;
    PNC_PARAM_W             prm;
} IN_PNC_PARAM;

/* pnc_rdmntinfo */
typedef struct _out_pnc_cntrlr_info {
    unsigned char           Status;
    unsigned char           pad;
    unsigned short          DiDoRefreshTime;
} OUT_PNC_CNTRLR_INFO;

/* pnc_rdmntinfo */
typedef struct _out_pnc_device_info {
    char                    IpAddress[16];
    unsigned char           Status;
    unsigned char           pad[3];
    PNC_ADDRTOP             DiAddrTop;
    PNC_ADDRTOP             DoAddrTop;
    unsigned short          InputSize;
    unsigned short          OutputSize;
    unsigned short          InputCycleTime;
    unsigned short          OutputCycleTime;
    unsigned long           AlarmNum;
    unsigned long           ConnectTime;
} OUT_PNC_DEVICE_INFO;

/* pnc_rdmntinfo */
typedef struct _out_pnc_allcom_stat {
    unsigned char           State[48];
} OUT_PNC_ALLCOM_STAT;

/* pnc_resdetailinfo */
typedef struct _out_pnc_detail_info {
    short                   Result;
    unsigned char           pad[2];
    char                    IpAddress[16];
    char                    Info[360];
} OUT_PNC_DETAIL_INFO;

/*-----------------------------------*/
/* NET : EtherCAT function           */
/*-----------------------------------*/

/* ect_rdlog */
typedef struct _out_ectlog1shot {
    unsigned short          MsgId;
    unsigned char           Year;
    unsigned char           Month;
    unsigned char           Day;
    unsigned char           Hour;
    unsigned char           Minute;
    unsigned char           Second;
    char                    Text[32];
} OUT_ECTLOG1SHOT;

typedef struct _out_ectlog {
    unsigned short          Count;
    unsigned char           reserve[14];
    OUT_ECTLOG1SHOT         logData[15];
} OUT_ECTLOG;

/* ect_rdslvtype */
typedef struct _out_ecttype {
    unsigned char           Kind;
    unsigned char           Slot;
    unsigned short          FunctionEctSlv;
} OUT_ECTTYPE;

/* ect_rdslvdeviceinfo */
typedef struct _out_ectdevinfo {
    char                    EsiVersion[8];
    unsigned long           VendorID;
    unsigned long           ProductCode;
    unsigned long           RevisionNo;
    unsigned short          NodeAddress;
    unsigned char           pad[2];
} OUT_ECTDEVINFO;

/* ect_rdslvdeviceinfo */
typedef struct _out_ectnetinfo {
    unsigned short          Esm;
    unsigned short          Mode;
} OUT_ECTNETINFO;


/*--------------------*/
/* RENISHAW function  */
/*--------------------*/
typedef struct odbrenplt {
    short           delay_time ;
    unsigned short  data_flag ;
    short           pos_data[6] ;
} ODBRENPLT ;

/* cnc_rdproctime:read processing time stamp data */
typedef struct odbptime2 {
	short	num;
	struct{
		char	filename[36];
		short	hour;
		char	min;
		char	sec;
	}data[10];
} ODBPTIME2;

/*--------------------*/
/* schedule function  */
/*--------------------*/
#if !defined _SCDL_1D
#define _SCDL_1D
typedef struct  scdldata {
   	short   file_no;
   	char    file_name[16];
   	short   repeat_num;
   	short   current_num;
   	char   dummy[2];
} SCDL_1D ;

#endif

/*--------------------------*/
/*   path table function    */
/*--------------------------*/
/*--- cnc_rdptaxitablestatus ---*/
/* Axis-Motion Table */
typedef struct odbptaxistat{
    union{
        struct{
            double  l_value_e ;
            double  pos_value_e ;
            double  l_value ;
            //double  pos_value ;
            double  time ;
            short   ov_time ;
            short   number ;
            short   next_table ;
            short   skip_table ;
            short   skip_signal ;
            short   table_kind ;
            short   master_indx_no ;
        }state1;
        struct{
            double  l_value_e_sub ;
            double  pos_value_e_sub ;
            double  l_value_sub ;
            long    repeat_e_sub ;
            long    repeat_sub ;
            short   number_sub ;
            short   next_table_sub ;
            short   skip_table_sub ;
            short   skip_signal_sub ;
            short   table_kind_sub ;
            short   master_indx_no_sub ;
        }state2;
    }u;
}ODBPTAXISTAT ;

/*--- cnc_rdptsptablestatus ---*/
/* Spindle-Command Table */
typedef struct odbptspstat{
    union{
        struct{
            double  l_value_e ;
            double  pos_value_e ;
            double  l_value ;
            //double  pos_value ;
            double  time ;
            long    srpm ;
            long    sspm ;
            long    smax ;
            short   ov_time ;
            short   number ;
            short   next_table ;
            short   skip_table ;
            short   skip_signal ;
            char    sp_mode ;
        }state1;
        struct{
            double  l_value_e_sub ;
            double  pos_value_e_sub ;
            double  l_value_sub ;
            long    repeat_e_sub ;
            long    repeat_sub ;
            short   number_sub ;
            short   next_table_sub ;
            short   skip_table_sub ;
            short   skip_signal_sub ;
        }state2;
    }u;
}ODBPTSPSTAT ;

/*--- cnc_rdptaxfunctablestatus ---*/
/* Auxiliary-Function Table */
typedef struct odbptaxfuncstat{
    union{
        struct{
            double  l_value_e ;
            double  l_value ;
            double  time ;
            long    m_code[3] ;
            short   ov_time ;
            short   number ;
            short   next_table ;
            short   skip_table ;
            short   skip_signal ;
            short   table_kind ;
            short   master_indx_no ;
            short   m_count ;
        }state1;
        struct{
            double  l_value_e_sub ;
            double  l_value_sub ;
            long    repeat_e_sub ;
            long    repeat_sub ;
            short   number_sub ;
            short   next_table_sub ;
            short   skip_table_sub ;
            short   skip_signal_sub ;
            short   table_kind_sub ;
            short   master_indx_no_sub ;
        }state2;
    }u;
}ODBPTAXFUNCSTAT ;

/*--- cnc_rdptcomment ---*/
typedef struct odbptcomment {
    long    t_code ;
    char    comment_count ;
    char    pto_mode ;
    char    dummy1[2] ;
    char    comment[10][32] ;
}ODBPTCOMMENT ;

/*--- cnc_rdpthis_gb ---*/
typedef struct odbpthis_gb {
    struct {
        short   year;
        char    mon;
        char    day;
        char    hour;
        char    min;
        char    sec;
    } date;
    char    reserve1;
    long    info1;
    char    path_num;
    char    reserve2[3];
} ODBPTHIS_GB ;

/*--- cnc_rdpthis_pt ---*/
typedef struct odbpthis_pt {
    double  time;
    short   dist_err;
    short   ov_time;
    long    info1 ;
    short   alarm_no ;
    char    alarm_type ;
    char    alarm_axis ;
    char    path_axis_num ;
    char    path_spdl_num ;
    char    time_frac ;
    char    reserve1;
} ODBPTHIS_PT ;

/*--- cnc_rdpthis_ax ---*/
typedef struct odbpthis_ax {
    double  l_value ;
    double  l_value_e ;
    double  pos_value ;
    double  pos_value_e ;
    double  l_value_sub ;
    double  l_value_e_sub ;
    double  l_value_cycle ;
    double  l_value_e_cycle ;
    long    repeat_sub ;
    long    repeat_e_sub ;
    long    info1 ;
    short   number ;
    short   number_sub ;
    short   number_cycle ;
    short   table_kind ;
    char    name[4] ;
    char    cs_spdl_idx_pt ;
    char    cs_spdl_idx_rel ;
    char    master_indx_no_pt ;
    char    master_indx_no_rel ;
    char    pos_frac ;
    char    l_frac ;
    char    l_frac_cycle ;
    char    reserve1;
} ODBPTHIS_AX ;

/*--- cnc_rdpthis_sp ---*/
typedef struct odbpthis_sp {
    double  l_value ;
    double  l_value_e ;
    double  pos_value ;
    double  pos_value_e ;
    double  l_value_sub ;
    double  l_value_e_sub ;
    long    repeat_sub ;
    long    repeat_e_sub ;
    long    srpm ;
    long    rrpm ;
    long    sspm ;
    long    smax ;
    long    info1 ;
    short   number ;
    short   number_sub ;
    short   table_kind ;
    char    sp_mode ;
    char    name[4] ;
    char    ov_sp;
    char    reserve1;
    char    cs_axis_idx_pt ;
    char    cs_axis_idx_rel ;
    char    pos_frac ;
    char    l_frac ;
    char    reserve2[3];
} ODBPTHIS_SP ;

/*--- cnc_rdpthis_aux ---*/
typedef struct odbpthis_aux {
    double  l_value ;
    double  l_value_e ;
    double  l_value_sub ;
    double  l_value_e_sub ;
    long    repeat_sub ;
    long    repeat_e_sub ;
    long    m_code[3] ;
    long    info1 ;
    short   number ;
    short   number_sub ;
    short   table_kind ;
    char    m_count ;
    char    master_indx_no_pt ;
    char    master_indx_no_rel ;
    char    l_frac ;
    char    reserve1[6];
} ODBPTHIS_AUX ;

/*--- cnc_rdpthis_log ---*/
typedef struct odbpthis_log {
    char    issub;
    char    kind;
    short   number;
} ODBPTHIS_LOG ;

/*--- cnc_rdptcnvinfo2 ---*/
typedef struct odbptcnvinfo2{
	short	executing[2][10] ;
	long	conv_status[2][10] ;
	short	ofs_change[2][10] ;
}ODBPTCNVINFO2 ;

typedef struct odbaxsts_bg {
    long   flag;    
} ODBAXSTS_BG;

/*--- cnc_rdpalaxis ---*/
/* Parallel axis control */
typedef struct iodbpalax{
	long   max_pal ;
	long   data[MAX_AXIS] ;
}IODBPALAX ;

/*--- cnc_hdck_nochange_info ---*/
/*    handle retrace message    */
typedef struct odbahdck {
	short	dat_path ;
	struct {
		short	stat ;
		short	data ;
	} info[MAX_CNCPATH];
} ODBAHDCK;

/*--- cnc_rstrt_rdpntlist ---*/
/* restart point list  */
typedef struct odbrstlist {
	char  prg_name[246];
	char  dummy[2];
	long  seq_no;
	long  c_blck_cnt;
} ODBRSTLIST ;

typedef struct odbrstlist2 {
	char  prg_name[246];
	char  status;
	char  dummy;
	long  seq_no;
	long  wait_m_code;
	long  c_blck_cnt;
	char  time_s;
	char  time_m;
	char  time_h;
	char  time_d;
	long  id_no;
	long  reserve[3];
} ODBRSTLIST2 ;

/*--- cnc_rstrt_rdpnt ---*/
/* restart point info  */
typedef struct iodbrstinfo {
	long  seq_no;
	long  c_blck_cnt;
	long  t_blck_cnt;
	long  call_from_no;
	long  call_from_blck;
	short prg_rep;
	short seq_rep;
	short c_blck_rep;
	short nest_lv;
	char  prg_name[246];
	char  dummy1[2];
	char  call_from_prg[246];
	char  dummy2[2];
	char  edit_flag;
	char  reserve;
	short repeat;
	long  wait_m_code;
} IODBRSTINFO ;

/*--- cnc_rstrt_rdpnt2 ---*/
/* restart point info  */
typedef struct iodbrstinfo2 {
	long  seq_no;
	long  c_blck_cnt;
	long  t_blck_cnt;
	long  call_from_no;
	long  call_from_blck;
	short prg_rep;
	short seq_rep;
	short c_blck_rep;
	short nest_lv;
	char  prg_name[246];
	char  dummy1[2];
	char  call_from_prg[246];
	char  dummy2[2];
	char  edit_flag;
	char  reserve;
	short repeat;
	long  wait_m_code;
	char  time_s;
	char  time_m;
	char  time_h;
	char  time_d;
	long  id_no;
	long  reserve2[3];
} IODBRSTINFO2 ;

/*---cnc_rstrt_rdlpmppnt---*/
/* restart point mpinfo */
typedef struct odbrstmpinfo {
    long    u_block_num;
    long    mltpiece_all;
    long    mltpiece_exe;
    char    u_file_name[246];
}ODBRSTMPINFO ;

/*---------------------*/
/* spindle unit offset */
/*---------------------*/
typedef struct iodbsuofs {
    long		vect_val;	/* vector element */
    long		frc_dgt;   	/* fraction digit */
} ODBSUOVECT ;

typedef struct odbsuodata {
     char  data_name[4]; /* axis name   */
     long  prm_val;      /* parameter value */
     long  frc_dgt;      /* fraction digit */
} ODBSUODATA ;
/*----------------------------*/
/*  Memory card access        */
/*----------------------------*/
/*--- cnc_rdmcdfinfo -------------*/
typedef struct odbfilestatus {
    unsigned long  size;      
    unsigned char  min;       
    unsigned char  hour;      
    unsigned char  day;       
    unsigned char  month;     
    unsigned short year;      
    unsigned char  reserve[2] ;
    char           filename[20];
}ODBFILESTATUS;

/*--- cnc_rdmcdprgcmnt -----------*/
typedef struct odbproginfo {
    char comment[52];
    char o_time[12];
} ODBPROGINFO ;

/* cnc_tpnl_read:read touch panel status & point */
typedef struct odbtpnlinf{
	unsigned char	status ;
	unsigned char	dummy[3]   ;
	short	        coord_x ;
	short	        coord_y ;
}ODBTPNLINTF;

/*--- cnc_rdpmcaxisinfo ---*/
/*    handle retrace message    */
typedef struct odbpmcaxisinfo {
	unsigned char	datastatus;		/* active / nonactive */
	unsigned char	axisstatus;		/* axis status */
	unsigned char	commandsignal;	/* command signal */
	unsigned char	statussignal;	/* status signal */
	unsigned char	dummy;			/* boundary alignment */
	unsigned char	instruction;	/* instruction number */
	unsigned short	speedsignal;	/* speed signal */
	unsigned long	axisctrldata;	/* data signal */
	unsigned short	subinstnum;		/* subinstruction number */
	unsigned short	subinstlength;	/* data length of subinstruction */
	unsigned long	subinstdata1;	/* subinstruction data 1 */
	unsigned long	subinstdata2;	/* subinstruction data 2 */
	unsigned long	subinstdata3;	/* subinstruction data 3 */
	unsigned long	subinstdata4;	/* subinstruction data 4 */
	unsigned long	subinstdata5;	/* subinstruction data 5 */
	unsigned long	subinstdata6;	/* subinstruction data 6 */
	unsigned long	subinstdata7;	/* subinstruction data 7 */
} ODBPMCAXISINFO;

/*--- cnc_mdd_rdinfo ---*/
/* Modification detection information */
typedef struct odbmddinfo {
    short           status;         /* Modification detection status */
    short           prot;           /* Data protection status */
    short           year;           /* Registered year */
    short           month;          /*            month */
    short           day;            /*            day */
    short           hour;           /*            hour */
    short           min;            /*            minute */
    short           sec;            /*            second */
    unsigned long   reg_code;       /* Check code - registered */
    unsigned long   cur_code;       /* Check code - current */
    short           modulate;       /* C-EXE code modulation status */
} ODBMDDINFO ;

/* Modification detection exception parameter */
typedef struct iodbmddexceptinfo {
    long           sno;            /* Start Parameter Number */
    long           eno;            /* End Parameter Number   */
} IODBMDDEXCEPTPRM ;

/*----------------------------*/
/*  USB Memory access         */
/*----------------------------*/
/*--- cnc_rdusbdevinfo ---*/
/* USB Memory size information */
typedef struct odbusbsize {
    unsigned long    totalsize_h;      /* total size (high) */
    unsigned long    totalsize_l;      /* total size (low)  */
    unsigned long    freesize_h;       /* free size (high)  */
    unsigned long    freesize_l;       /* free size (low)   */
} ODBUSBSIZE;

/*--- cnc_rdusbfilelist ---*/
/* input data */
typedef struct idbusbfile {
    char             path[256];  /* base path              */
    unsigned long    offset;     /* offset                 */
    short            req_num;    /* number of demand files */
    unsigned short   req_attrib; /* attribute              */
    char             sort;       /* sort flag              */
	char             req_comment;/* comment flag           */
	char			 req_total;	 /* file count flag		   */
	char			 dummy;
} IDBUSBFILE;
/* output data */
typedef struct odbusbinfo {
    short           f_num;      /* number of files actually acquired */
    char            next_entry; /* next file entry                   */
    char            dummy;
	unsigned long   total;      /* number of total files             */
} ODBUSBINFO;
/* file information */
typedef struct odbusbfile {
    /* output */
    unsigned long   size;       /* size        */
    unsigned short  attribute;  /* attribute   */
    unsigned short  long_name;  /* information */
    unsigned short  year;       /* time stamp  */
    unsigned char   mon;        /* time stamp  */
    unsigned char   day;        /* time stamp  */
    unsigned char   hour;       /* time stamp  */
    unsigned char   min;        /* time stamp  */
    unsigned char   sec;        /* time stamp  */
    unsigned char   dummy;
    char            fname[36];   /* file name   */
	char            comment[64];/* comment     */
} ODBUSBFILE;
/*--- cnc_searchusbfile ---*/
/* input data */
typedef struct idbusbsearch {
    char             path[256];  /* base path              */
    char             s_fname[36];/* search file/folder name */
    unsigned short   req_attrib; /* attribute              */
    char             sort;       /* sort flag              */
    char             dummy;
} IDBUSBSEARCH;


/*------------------------*/
/* Robot Connect Function */
/*------------------------*/
typedef struct odbrbsignal{
	char type;
	char state;
	unsigned short no;
	char name[76];
}ODBRBSIGNAL;

typedef struct iodbrbsignal2{
    char type;
    char state;
    unsigned short no;
    char name[73];
    char reserve[3];
}IODBRBSIGNAL2;

typedef struct iodbrbalmmsg{
	char msg[152];
}IODBRBALMMSG;

typedef struct odbrbgrplist{
	char select;
	unsigned char robot_program;
	char nc_program_folder[213];
	char nc_program_name[33];
	char comment[52];
}ODBRBGRPLIST;

typedef struct idbrbgroup{
	unsigned char robot_program;
	char nc_program_folder[213];
	char nc_program_name[33];
}IDBRBGROUP; 

typedef struct idbrbsignal{
	char name[76];
}IDBRBSIGNAL;

typedef struct iodbrbtopsig{
	char unit_type;
	char adr_type;
	unsigned short address;
}IODBRBTOPSIG;

typedef struct iodbrbpowersig{
	char unit_type;
	char adr_type;
	unsigned short address;
	char bit;
	char reserve[3];
}IODBRBPOWERSIG;

typedef struct iodbrbcomset{
	IODBRBTOPSIG di_top;
	IODBRBTOPSIG do_top;
	IODBRBPOWERSIG power_on;
	unsigned short di_offset; 
	unsigned short do_offset; 
	unsigned char property;
	char reserve[3];
}IODBRBCOMSET;

typedef struct iodbrbsummary{
	char signal_type;
	char reserve;
	unsigned short no;
}IODBRBSUMMARY;

/*--- cnc_rdindexprm -------------------*/
/*--- cnc_wrindexprm -------------------*/
typedef struct iodbindexprm {
    long            ofs_limit;
    long            detect_width;
    unsigned short  jog_clamp[3];
    char            matrix_single;
    unsigned char   torque_ovr;
    char            ofs_adjust;
    char            dummy[3];
} IODBINDEXPRM;
/*--- cnc_rdindexdata ------------------*/
/*--- cnc_wrindexdata ------------------*/
typedef struct iodbindexdat{
    long            pos;
    long            inp_width;
    unsigned short  speed;
    char            f_flg;
    char            dummy;
}IODBINDEXDAT;
/*--- cnc_rdindexofs -------------------*/
/*--- cnc_wrindexofs -------------------*/
/* nothing */
/*--- cnc_rdindexposdata ---------------*/
/*--- cnc_wrindexposdata ---------------*/
typedef struct indexposdat{
    long            min_value;
    long            max_value;
    char            setting;
    char            dummy[3];
} IODBINDEXPOSDAT;
/*--- cnc_rdindexinfo ---------------*/	
typedef struct odbindexinfo{
    unsigned short  mode;
    short           nc_ax;
    short           inpos_point;
    short           ofs_edit_signal;
} ODBINDEXINFO;

/*------------------------*/
/* Chopping Function      */
/*------------------------*/
typedef struct realnum{
	long val;
	long dec;
}REALNUM;

typedef struct odbchopping{
	REALNUM cur_pos;
	REALNUM cur_speed;
	REALNUM real_udp;
	REALNUM real_ldp;
	unsigned long stroke_cnt;
}ODBCHOPPING;

/*---------------------------------------*/
/* Tilted Working Plane Command          */
/*---------------------------------------*/
typedef struct _odbcoord{
    long    orign[3] ;
    short   vec_x[3] ;
    short   vec_y[3] ;
    short   vec_z[3] ;
} ODBCOORD ;

typedef struct idbtwp_euler_fmt{
    double orign[3];
    double i;
    double j;
    double k;
    long   reserve[24];
} IDBTWP_EULER_FMT;

typedef struct idbtwp_rpy_fmt{
    double orign[3];
    double i;
    double j;
    double k;
    short  turn ;
    short  reserve0 ;
    long   reserve[23];
} IDBTWP_RPY_FMT;

typedef struct idbtwp_3p_fmt{
    double p1[3];
    double p2[3];
    double p3[3];
    double sft[3];
    double rot;
    long   reserve[10];
} IDBTWP_3P_FMT;

typedef struct idbtwp_2vct_fmt{
    double orign[3];
    double vtr1[3];
    double vtr2[3];
    long   reserve[18];
} IDBTWP_2VCT_FMT;

typedef struct idbtwp_pjct_fmt{
    double orign[3];
    double i;
    double j;
    double k;
    long   reserve[24];
} IDBTWP_PJCT_FMT;

typedef union idbviewgrp{
    IDBTWP_EULER_FMT euler;
    IDBTWP_RPY_FMT   rpy;
    IDBTWP_3P_FMT    p3;
    IDBTWP_2VCT_FMT  vct2;
    IDBTWP_PJCT_FMT  pjct;
} IDBTWPFORM;

typedef struct odbftrmtx{
    double orgn[3];
    double rot[3][3];
} ODBFTRMTX;

/*---------------------------------------*/
/* Machining Condition Setting           */
/*---------------------------------------*/
typedef struct _odbmcshead {
    char    layout     ;
    char    string1[51];
    char    string2[51];
} ODBMCSHEAD ;

/*----------------------------*/
/* Safety I/O signal history  */
/*----------------------------*/
typedef struct odbsfsgalm{
    short   alm_type ;
    short   alm_no ;
} ODBSFSGALM ;

typedef struct odbsfsgalmtime{
    short   year ;
    short   month ;
    short   date ;
    short   hour ;
    short   minute ;
    short   second ;
} ODBSFSGALMTIME ;

typedef struct odbsfsgloginf {
    short           signal_num;
    short           sig_his_period;

    short           sig_his_count;
    short           sig_his_after;

    short           alm_detect_time[3];
    short           dummy;
    ODBSFSGALM      sfsg_alm;
    ODBSFSGALMTIME  sfsg_alm_time;
} ODBSFSGLOGINF ;

typedef struct iodbsfsgsiginf{
    long     unittype;
    long     number;
    short    adr_type;
    short    bit;
} IODBSFSGSIGINF ;

typedef struct odbsfsgsiginfex{
    IODBSFSGSIGINF  sfsg_siginf;
    short           select;
    short           reserve;
} ODBSFSGSIGINFEX ;

typedef struct iodbsfsgsighis {
    short   sno_sig ;
    short   len_sig ;
    short   sno_sig_his ;
    short   len_sig_his ;
    short   extract ;
} IODBSFSGSIGHIS ;

typedef struct odbsfsgsignalnum {
    short   signal_num_default;
    short   signal_num_extract;
} ODBSFSGSIGNALNUM ;

typedef struct iodbsfsgdspstat {
    short   extract;
    short   symbol;
    short   extend;
} IODBSFSGDSPSTAT ;

/* cnc_rd1punchtl_ex  :read punchpress tool data  */
/* cnc_wrldsplc_ex    :write punchpress tool data */
typedef struct iodbpunch1_ex {
    unsigned short  number ;
    unsigned short  attr ;
    union {
        unsigned short  u2data ;
        short           s2data ;
        unsigned long   u4data ;
        long            s4data ;
        unsigned long   u8data[2] ;
    } u ;
    short   decimal ;
    short   reserve ;
} IODBPUNCH1_EX;

/* cnc_rd2punchtl_ex  :read punchpress tool data  */
typedef struct iodbpunch2_ex {
    unsigned long   number ;
    unsigned short  attr ;
    union {
        unsigned short  u2data ;
        short           s2data ;
        unsigned long   u4data ;
        long            s4data ;
        unsigned long   u8data[2] ;
    } u ;
    short   decimal ;
    short   reserve ;
} IODBPUNCH2_EX;

/*---------------------------------------*/
/* Main Menu      */
/*---------------------------------------*/
typedef struct odbmmscrninf {
    unsigned long scrn_id;
}ODBMMSCRNINF;

typedef struct iodbmmiconcstmstring {
    ODBMMSCRNINF    scrninf;
    char            string[13];
    char            reserve[3];
}IODBMMICONCSTMSTRING;

typedef struct iodbmmctgrycstmstring {
    char            string[13];
    char            reserve[3];
}IODBMMCTGRYCSTMSTRING;

typedef struct iodbmmmcscrndefdat{
    ODBMMSCRNINF  scrninf;
    long          icn_id;
    long          msg_id;
}IODBMMMCSCRNDEFDAT;

typedef struct iodbmmmcctgrydefdat{
    long          cmsg_id;
}IODBMMMCCTGRYDEFDAT;

/*-----------------------------*/
/*            LASER            */
/*-----------------------------*/
/*------ cnc_rdpscdedge2 ------*/
/*------ cnc_wrpscdedge2 ------*/
typedef struct iodbedge2 {
    short    slct;
    short    power;
    short    freq;
    short    duty;
    short    g_press;
    short    g_kind;
    long     pier_t;
    long     angle;
    long     gap;
    long     r_len;
    long     r_feed;
    short    r_freq;
    short    r_duty;
    char     gap_axis;
    char     angle_dec;
    char     gap_dec;
    char     r_len_dec;
    char     r_feed_dec;
    char     reserve;
    short    pb_power ;
    short    reserves[2];
} IODBEDGE2 ;

/*------ cnc_rdlpscdpwrctl ------*/
/*------ cnc_wrlpscdpwrctl ------*/
typedef struct iodbpwrctl {
    short    slct;
    short    power_min;
    short    pwr_sp_zr;
    short    freq_min;
    short    freq_sp_zr; 
    short    duty_min;   
    short    duty_sp_zr; 
    char     feed_r_dec; 
    char     reserve;    
    long     feed_r;     
    short    ag_press_min ;
    short    ag_press_sp_zr ;
    short    pb_power_min ;
    short    pb_pwr_sp_zr ;
    short    reserves[2] ;
} IODBPWRCTL ;

/*------ cnc_rdldsplc2 ------*/
/*------ cnc_wrldsplc2 ------*/
typedef struct iodbdsplc {
    short   slct;
    long    dsplc;
    short   dsplc_dec;
    char    gap_ix;
    short   reserves[4];
} IODBDSPLC ;

/* cnc_rdlhsstate : read laser high speed state data */
typedef struct odblstate {
    long    cmd_feed;
    long    act_feed;
    short   cmd_power;
    short   cmd_freq;
    short   cmd_duty;
    char    beam;
    char    beam_lock;
    char    cw_mode;
    char    pulse_mode;
    char    cmd_feed_dec;
    char    act_feed_dec;
    char    reserve[8];
} ODBLSTATE ;

/* cnc_rdlpoweroffset : read laser power offset data */
typedef struct odblpwofs {
    short   pwrofs_set;
    short   pwrofs_coef;
    short   pwrofs_upper;
    short   pwrofs_max;
    short   pwrofs_min;
    short   pwrinofs_coef;
    char    reserve[8];
} ODBLPWOFS ;

/* cnc_wrlswork : white laser work data */
typedef struct idblswork {
    short   slct ;
    short   skeyinf ;
    short   reserve[14] ;
} IDBLSWORK ;

typedef struct odblalmhis {
    unsigned short  s_no;
    unsigned short  e_no;
    struct {
        short   lalm_wrg ;
        short   alm_grp;
        short   alm_wrg_no ;
        short   year ;
        short   month ;
        short   day ;
        short   hour ;
        short   minute ;
        short   second ;
        short   len_msg ;
        char    alm_msg[64] ;
        short   reserve[4] ;
    }alm_his[50] ;
} ODBLALMHIS;

/*--------------------------------*/
/*   PDSA Pulse Input Diag Data   */
/*--------------------------------*/
typedef struct odbplsdata {
	short	pulse_type;		/* Pulse Type */
	short	channel_state;	/* Channel Connect State */
	short	reserve1;		/* reserve */
	short	reserve2;		/* reserve */
	short	alarm[4];		/* Alarm Detail(CH1-4) */
	short	cmd_val[4];		/* Command Value(CH1-4) */
	short	reserve3[4];		/* reserve */
	long	total_val[4];	/* Total Value(CH1-4) */
	long	reserve4[4];	/* reserve */
} ODBPLSDATA;

/* cnc_rduvactpt2 : uv macro pointer */
typedef struct odbuvmcrpt2 {
	char    prog_name[248] ;    
	long    blk_no ;       
	long    uvblk_no ;     
	long    mult_piece_no ;
    short   reserve[2] ;
} ODBUVMCRPT2 ;

typedef struct odbhmprogstat {
    short   run;
    short   disp;
    short   alm_no;
    short   reserve;
    long    prog_no;
    long    block_no;
} ODBHMPROGSTAT ;

/*-----------------------------------*/
/*  Teach Program Input/Output Data  */
/*-----------------------------------*/
typedef struct odbtpaprg {
    /* output */
    short       format_version;		/* Data format version */
    short       func_version;		/* Function set version */
    long        size;				/* Memory usage */
    struct {						/* Creation date */
        short       year;
        short       mon;
        short       day;
        short       hour;
        short       min;
        short       sec;
    } create ;
    struct {						/* Edit date */
        short       year;
        short       mon;
        short       day;
        short       hour;
        short       min;
        short       sec;
    } edit ;
    struct {						/* Conversion date */
        short       year;
        short       mon;
        short       day;
        short       hour;
        short       min;
        short       sec;
    } convert ;
    unsigned long attr;				/* Program attribute */
    char        name_copy[36];		/* Name of copy original */

    char        prg_name[36];		/* Program name */
    char        comment[20];		/* Comment text of program */
    unsigned long axis;				/* Control axis bit (in path) */
    char        out_nc_prg[36];		/* Output NC program name */
    long        reserve[2];
} ODBTPAPRG ;

typedef struct idbtpinfo {
	char			prg_name[36];	/* Program name */
	char			comment[20];	/* Comment text of program */
	unsigned long	axis;			/* Control axis bit (in path) */
	char			out_nc_prg[36];	/* Output NC program name */
	long			reserve[2];
} IDBTPINFO ;

typedef struct tprogeditcmd {
    char cmd_num ;					/* Count of cmd[] */
    char cmd[31] ;					/* Array of available commands */
    char word_num ;					/* Count of word[] */
    char word[31] ;					/* Array of available words */
} ODBTPEDTCMD;

typedef struct tprogcmd {
    long cmd_id ;					/* Kind of edit operation */
									/* Arguments */
    long    integer[4];					/* integer */
    struct {							/* real */
       long val;
       long dec;
    } val[4];
    char    text[64];					/* text */
} IDBTPCMD;

/*----------------------------*/
/* Machining simulation       */
/*----------------------------*/
#ifndef CNC_PPC
/* anm_rdsimuelm : move element data */
typedef struct iodbsimuelm {
    char    type;
    char    rot_w;
    char    type2;
    char    plane;
    long    tcode;
    union {
        struct {
            long    mv_p[8];
        } rapid;
        struct {
            long    mv_p[8];
        } line;
        struct {
            long    mv_p[8];
            long    cnt_p[4];
        } arc;
        struct {
            long    mv_p[8];
            long    ptch;
        } thrd1;
        struct {
            long    mv_p[8];
            long    ptch;
            long    mv_p2[2];
        } thrd2;
        struct {
            long    mv_p[16];
        } dummy_d;
    } data;
    char    dm_type;
    char    cssc_md;
    long    dm_x[3];
    long    dm_y[3];
    long    dm_z[3];
    long    cnt_x[3];
    long    cord[6];
    char    tlchng;
    char    fd_type;
    long    mcode;
    short   dummy4;
    long    cylndr;
    long    aux;
    long    dcode;
    long    smax;
    long    dwell;
    long    fcode;
    long    scode;
    char    nummcd;
    char    fcddec;
    long    shift;
    char    fbsft;
    char    tilt;
} IODBSIMUELM;

/* anm_rdsimuelm2 : move element data with multi M code */
typedef struct iodbsimuelm2 {
    char    type;
    char    rot_w;
    char    type2;
    char    plane;
    long    tcode;
    union {
        struct {
            long    mv_p[8];
        } rapid;
        struct {
            long    mv_p[8];
        } line;
        struct {
            long    mv_p[8];
            long    cnt_p[4];
        } arc;
        struct {
            long    mv_p[8];
            long    ptch;
        } thrd1;
        struct {
            long    mv_p[8];
            long    ptch;
            long    mv_p2[2];
        } thrd2;
        struct {
            long    mv_p[16];
        } dummy_d;
    } data;
    char    dm_type;
    char    cssc_md;
    long    dm_x[3];
    long    dm_y[3];
    long    dm_z[3];
    long    cnt_x[3];
    long    cord[6];
    char    tlchng;
    char    fd_type;
    long    mcode;
    short   dummy4;
    long    cylndr;
    long    aux;
    long    dcode;
    long    smax;
    long    dwell;
    long    fcode;
    long    scode;
    char    nummcd;
    char    fcddec;
    long    shift;
    char    fbsft;
    char    tilt;
    short   dummy6;
    long    mcode2;
    long    mcode3;
    long    mcode4;
    long    mcode5;
    long    reserve[10];
} IODBSIMUELM2;
#endif

/*--- cnc_rdsvgtungstat ---*/

typedef struct odbtunreq {
    struct {
        short status;
        short dummy;
    } stat[MAX_AXIS];
} ODBTUNREQ;

typedef struct obdtunstat {
    struct {
        short status;
        short dummy;
    } stat[MAX_AXIS];
} ODBTUNSTAT;

/*------------------------*/
/* Reducing Cycle Time    */
/*------------------------*/

typedef struct iodbrct_item {
    unsigned short  item_num;
    unsigned char   type ;
             char   axsp_num ;
             char   ptn_num ;
    unsigned char   dummy ;
    unsigned short  attr ;

    struct data_info {
        char    enable ;
        char    dummy2[3] ;
        long    attr2 ;
        union {
            char    bdata ;
            char    cdata ;
            short   idata ;
            long    ldata ;
            REALPRM rdata ;
            char    bdatas[MAX_AXIS] ;
            char    cdatas[MAX_AXIS] ;
            short   idatas[MAX_AXIS] ;
            long    ldatas[MAX_AXIS] ;
            REALPRM rdatas[MAX_AXIS] ;
        } uParam ;
    } ptn[6] ;
} IODBRCT_ITEM;

typedef struct iodbrct_cstmname {
    unsigned short  grp_num;       			/* grp number    */
    unsigned short  dummy;              	/* dummy         */
              char  grp_name[16];       	/* group name    */
              char  ptn_name[3][16];    	/* pattern name  */
} IODBRCT_CSTMNAME;

typedef struct iodbrct_grpptn {
    unsigned short  grp_num;                /* grp number    */
    unsigned short  ptn_num;                /* dummy         */
} IODBRCT_GRPPTN ;

typedef struct odbrct_slctptnname {
    long            sl_ptrn_no ;            /* pattern number */
    short           sl_nm_slct ;            /* name number    */
} ODBRCT_SLCTPTNNAME ;

typedef struct odbpressure {
    long    cmd_val;
    long    feedbak_val;
} ODBPRESSURE;

typedef struct odbexpos {
    double  data;
    long    dec;
    long    digit;
} ODBEXPOS ;

/*------------------------------*/
/* Scroll Waiting Mcode Setting */
/*------------------------------*/
typedef struct iodbwaitmcode {
    long	mcode;                /* scroll wait mcode   */
    long	pathnum;              /* path num            */
} IODBWAITMCODE ;

/*-------------------------*/
/* Smart Adaptive controll */
/*-------------------------*/
typedef struct curoverr {
    unsigned short  current ;
    unsigned short  minmum ;
    unsigned short  maximum ;
    short           dummy ;
} CUROVRR ;
typedef struct curload {
    unsigned short  current ;
    unsigned short  effect ;
    unsigned short  target ;
    unsigned short  irregular ;
    long            dummy ;
} CURLOAD ;
typedef struct curtemp {
    unsigned short  current ;
    unsigned short  start ;
    unsigned short  end ;
    unsigned short  alarm ;
    long            dummy ;
} CURTEMP ;
typedef struct currdtm {
    unsigned short  current ;
    unsigned short  threshold ;
    long            dummy ;
} CURRDTM ;
typedef struct odbsoccur {
    short           mode ;
    short           table ;
    long            dummy ;
    CUROVRR         ovrr ;
    CURLOAD         load ;
    CURTEMP         temp ;
    CURRDTM         rdtm ;
} ODBSOCCUR ;

typedef struct soctlattr {
	short	prm_no ;
	char	type ;
} ODBSOCTLATTR ;

typedef struct soctldat {
	union {
		char	cdata ;
		short	idata ;
		long	ldata ;
		REALPRM	rdata ;
	} u ;
} IODBSOCTLDAT ;

#ifdef _MSC_VER
#pragma pack(pop)
#endif

/* read machine axis position3 */
FWLIBAPI short WINAPI cnc_machine3( unsigned short, short, short, short, ODBAXIS * ) ;

/* read machine axis position3 ex */
FWLIBAPI short WINAPI cnc_machine3_ex(unsigned short, short, short, short, ODBAXIS_EX *) ;

#ifdef MCN_EX
#define odbaxis		odbaxis_ex
#define ODBAXIS		ODBAXIS_EX
#define cnc_machine3	cnc_machine3_ex
#undef MCN_EX
#endif

/*-------------------------------------*/
/* CNC: Control axis / spindle related */
/*-------------------------------------*/

/* read actual axis feedrate(F) */
FWLIBAPI short WINAPI cnc_actf( unsigned short, ODBACT * ) ;

/* read absolute axis position */
FWLIBAPI short WINAPI cnc_absolute( unsigned short, short, short, ODBAXIS * ) ;

/* read machine axis position */
FWLIBAPI short WINAPI cnc_machine( unsigned short, short, short, ODBAXIS * ) ;

/* read machine axis position(2) */
FWLIBAPI short WINAPI cnc_machine2( unsigned short, short, short, short, ODBAXIS * ) ;

/* read relative axis position */
FWLIBAPI short WINAPI cnc_relative( unsigned short, short, short, ODBAXIS * ) ;

/* read distance to go */
FWLIBAPI short WINAPI cnc_distance( unsigned short, short, short, ODBAXIS * ) ;

/* read distance to go (m) */
FWLIBAPI short WINAPI cnc_distancem( unsigned short, short, short, ODBAXIS * ) ;

/* read skip position */
FWLIBAPI short WINAPI cnc_skip( unsigned short, short, short, ODBAXIS * ) ;

/* read servo delay value */
FWLIBAPI short WINAPI cnc_srvdelay( unsigned short, short, short, ODBAXIS * ) ;

/* read acceleration/deceleration delay value */
FWLIBAPI short WINAPI cnc_accdecdly( unsigned short, short, short, ODBAXIS * ) ;

#ifndef CNC_PPC
/* read all dynamic data */
FWLIBAPI short WINAPI cnc_rddynamic( unsigned short, short, short, ODBDY * ) ;
#endif

/* read all dynamic data */
FWLIBAPI short WINAPI cnc_rddynamic2( unsigned short, short, short, ODBDY2 * ) ;

#ifndef CNC_PPC
/* read all dynamic data (3) */
FWLIBAPI short WINAPI cnc_rddynamic3( unsigned short, short, short, ODBDY3 * ) ;
#endif

/* read all dynamic data (3) */
FWLIBAPI short WINAPI cnc_rddynamic3m( unsigned short, short, short, ODBDY3M * ) ;

/* read actual spindle speed(S) */
FWLIBAPI short WINAPI cnc_acts( unsigned short, ODBACT * ) ;

/* read actual spindle speed(S) (All or spesified) */
FWLIBAPI short WINAPI cnc_acts2( unsigned short, short, ODBACT2 * ) ;

/* set origin / preset relative axis position */
FWLIBAPI short WINAPI cnc_wrrelpos( unsigned short, short, IDBWRR * ) ;

/* preset work coordinate */
FWLIBAPI short WINAPI cnc_prstwkcd( unsigned short, short, IDBWRA * ) ;

/* read manual overlapped motion value */
FWLIBAPI short WINAPI cnc_rdmovrlap( unsigned short, short, short, IODBOVL * ) ;

/* read manual overlapped motion value */
FWLIBAPI short WINAPI cnc_rdmovrlapm( unsigned short, short, short, IODBOVLM * ) ;

/* cancel manual overlapped motion value */
FWLIBAPI short WINAPI cnc_canmovrlap( unsigned short, short ) ;

/* read load information of serial spindle */
FWLIBAPI short WINAPI cnc_rdspload( unsigned short, short, ODBSPN * ) ;

/* read maximum r.p.m. ratio of serial spindle */
FWLIBAPI short WINAPI cnc_rdspmaxrpm( unsigned short, short, ODBSPN * ) ;

/* read gear ratio of serial spindle */
FWLIBAPI short WINAPI cnc_rdspgear( unsigned short, short, ODBSPN * ) ;

/* read absolute axis position 2 */
FWLIBAPI short WINAPI cnc_absolute2( unsigned short, short, short, ODBAXIS * ) ;

/* read relative axis position 2 */
FWLIBAPI short WINAPI cnc_relative2( unsigned short, short, short, ODBAXIS * ) ;

/* read distance to go 2 */
 FWLIBAPI short WINAPI cnc_distance2( unsigned short, short, short, ODBAXIS * ) ;

/* set wire vertival position */
FWLIBAPI short WINAPI cnc_setvrtclpos( unsigned short, short );

/* set wire threading position */
FWLIBAPI short WINAPI cnc_setthrdngpos( unsigned short );

/* read tool position */
FWLIBAPI short WINAPI cnc_rdposition( unsigned short, short, short *, ODBPOS * );

/* read current speed */
FWLIBAPI short WINAPI cnc_rdspeed( unsigned short, short, ODBSPEED * );

/* read servo load meter */
FWLIBAPI short WINAPI cnc_rdsvmeter( unsigned short, short *, ODBSVLOAD * );

/* read spindle load meter */
FWLIBAPI short WINAPI cnc_rdspmeter( unsigned short, short, short *, ODBSPLOAD * );

/* read handle interruption */
FWLIBAPI short WINAPI cnc_rdhndintrpt( unsigned short, short, short *, ODBHND * );

/* read manual feed for 5-axis machining */
FWLIBAPI short WINAPI cnc_rd5axmandt( unsigned short, ODB5AXMAN * );

/* read amount of machine axes movement of manual feed for 5-axis machining */
FWLIBAPI short WINAPI cnc_rd5axovrlap( unsigned short, short, short, ODBAXIS * );

/* clear pulse values of manual feed for 5-axis machining */
FWLIBAPI short WINAPI cnc_clr5axpls( unsigned short, short );

/* read constant surface speed */
FWLIBAPI short WINAPI cnc_rdspcss( unsigned short, ODBCSS * );

#ifndef CNC_PPC
/* read execution program pointer */
FWLIBAPI short WINAPI cnc_rdexecpt( unsigned short, PRGPNT *, PRGPNT *) ;

/* read execution program pointer(m) */
FWLIBAPI short WINAPI cnc_rdexecptm( unsigned short, PRGPNT *, PRGPNT *) ;

/* read execution program number */
FWLIBAPI short WINAPI cnc_rdexecprgnum( unsigned short, long * ) ;
#endif

/* read displayed jog or dryrun feedrate */
FWLIBAPI short WINAPI cnc_rdjogdrun( unsigned short, short, ODBJOGDRUN * );

/* set floating reference point */
FWLIBAPI short WINAPI cnc_setfrp( unsigned short, short );

/* read various axis data */
FWLIBAPI short WINAPI cnc_rdaxisdata( unsigned short, short, short *, short, short *, ODBAXDT * );

/* cnc_simulation:read data for machining sumilartion */
FWLIBAPI short WINAPI cnc_simulation( unsigned short, short, short, ODBSIML * );

#ifndef CNC_PPC
/* read sirial spindle speed */
FWLIBAPI short WINAPI cnc_rdspdlspeed( unsigned short, short, short, long * );
#endif

/* cnc_rdposfig:read position and decimal figure */
FWLIBAPI short WINAPI cnc_rdposfig( unsigned short, short, short, short *, ODBPOSFIG * );

/* get active spindle no */
FWLIBAPI short WINAPI cnc_rdactspdl(unsigned short, short *, short * );

/*----------------------*/
/* CNC: Program related */
/*----------------------*/

/* start downloading NC program */
FWLIBAPI short WINAPI cnc_dwnstart( unsigned short ) ;

/* download NC program */
FWLIBAPI short WINAPI cnc_download( unsigned short, char *, short ) ;

/* download NC program(conditional) */
FWLIBAPI short WINAPI cnc_cdownload( unsigned short, char *, short ) ;

/* end of downloading NC program */
FWLIBAPI short WINAPI cnc_dwnend( unsigned short ) ;

/* end of downloading NC program 2 */
FWLIBAPI short WINAPI cnc_dwnend2( unsigned short, char * ) ;

/* start downloading NC program 3 */
FWLIBAPI short WINAPI cnc_dwnstart3( unsigned short, short ) ;

/* start downloading NC program 3 special */
FWLIBAPI short WINAPI cnc_dwnstart3_f( unsigned short, short, char *, char * ) ;

/* download NC program 3 */
FWLIBAPI short WINAPI cnc_download3( unsigned short, long *, char * ) ;

/* end of downloading NC program 3 */
FWLIBAPI short WINAPI cnc_dwnend3( unsigned short ) ;

#ifndef CNC_PPC
/* start downloading NC program 3m */
FWLIBAPI short WINAPI cnc_dwnstart3m( unsigned short, short, long ) ;

/* download NC program 3m */
FWLIBAPI short WINAPI cnc_download3m( unsigned short, long *, char * ) ;

/* end of downloading NC program 3m */
FWLIBAPI short WINAPI cnc_dwnend3m( unsigned short, short ) ;
#endif

/* start downloading NC program 4 */
FWLIBAPI short WINAPI cnc_dwnstart4( unsigned short, short, char * ) ;

/* download NC program 4 */
FWLIBAPI short WINAPI cnc_download4( unsigned short, long *, char * ) ;

/* end of downloading NC program 4 */
FWLIBAPI short WINAPI cnc_dwnend4( unsigned short ) ;

/* start reading file to PC */
FWLIBAPI short WINAPI cnc_fileread_start( unsigned short, short, char * ) ;

/* read file to PC */
FWLIBAPI short WINAPI cnc_fileread( unsigned short, long * , char * ) ;

/* end of reading file to PC */
FWLIBAPI short WINAPI cnc_fileread_end( unsigned short ) ;

/* start writing file from PC */
FWLIBAPI short WINAPI cnc_filewrite_start( unsigned short, short, char * , short ) ;

/* write file from PC */
FWLIBAPI short WINAPI cnc_filewrite( unsigned short, long * , char * ) ;

/* end of writing file from PC */
FWLIBAPI short WINAPI cnc_filewrite_end( unsigned short ) ;

/* start verification of NC program */
FWLIBAPI short WINAPI cnc_vrfstart( unsigned short ) ;

/* verify NC program */
FWLIBAPI short WINAPI cnc_verify( unsigned short, char *, short ) ;

/* verify NC program(conditional) */
FWLIBAPI short WINAPI cnc_cverify( unsigned short, char *, short ) ;

/* end of verification */
FWLIBAPI short WINAPI cnc_vrfend( unsigned short ) ;

/* start verification of NC program */
FWLIBAPI short WINAPI cnc_vrfstart4(unsigned short, char*);

/* verify NC program */
FWLIBAPI short WINAPI cnc_verify4( unsigned short, long *length, char *data ) ;

/* end of verification */
FWLIBAPI short WINAPI cnc_vrfend4( unsigned short ) ;

/* start downloading DNC program */
FWLIBAPI short WINAPI cnc_dncstart( unsigned short ) ;

/* download DNC program */
#if defined (HSSB_LIB)
#if defined (FS15D) || defined (FS15BD)
FWLIBAPI short WINAPI cnc_dnc( unsigned short, char *, short ) ;
#else
FWLIBAPI short WINAPI cnc_dnc( unsigned short, char *, unsigned short ) ;
#endif
#else
FWLIBAPI short WINAPI cnc_dnc( unsigned short, char *, unsigned short ) ;
#endif

/* download DNC program(conditional) */
#if defined (HSSB_LIB)
#if defined (FS15D) || defined (FS15BD)
FWLIBAPI short WINAPI cnc_cdnc( unsigned short, char *, short ) ;
#else
FWLIBAPI short WINAPI cnc_cdnc( unsigned short, char *, unsigned short ) ;
#endif
#else
FWLIBAPI short WINAPI cnc_cdnc( unsigned short, char *, unsigned short ) ;
#endif

/* end of downloading DNC program */
FWLIBAPI short WINAPI cnc_dncend( unsigned short ) ;

/* start downloading DNC program 2 */
FWLIBAPI short WINAPI cnc_dncstart2( unsigned short, char * ) ;

/* download DNC program 2 */
FWLIBAPI short WINAPI cnc_dnc2( unsigned short, long *, char * ) ;

/* end of downloading DNC program 2 */
FWLIBAPI short WINAPI cnc_dncend2( unsigned short, short ) ;

/* read the diagnosis data of DNC operation */
FWLIBAPI short WINAPI cnc_rddncdgndt( unsigned short, ODBDNCDGN * ) ;

/* read the diagnosis data of DNC operation 2 */
FWLIBAPI short WINAPI cnc_rddncdgndt2( unsigned short, ODBDNCDGN2 * ) ;

/* start uploading NC program */
FWLIBAPI short WINAPI cnc_upstart( unsigned short, short ) ;

/* upload NC program */
FWLIBAPI short WINAPI cnc_upload( unsigned short, ODBUP *, unsigned short * ) ;

/* upload NC program(conditional) */
FWLIBAPI short WINAPI cnc_cupload( unsigned short, ODBUP *, unsigned short * ) ;

/* end of uploading NC program */
FWLIBAPI short WINAPI cnc_upend( unsigned short ) ;

/* start uploading NC program 3 */
FWLIBAPI short WINAPI cnc_upstart3( unsigned short, short, long, long ) ;

/* start uploading NC program special 3 */
FWLIBAPI short WINAPI cnc_upstart3_f( unsigned short, short, char *, char * ) ;

/* upload NC program 3 */
FWLIBAPI short WINAPI cnc_upload3( unsigned short, long *, char * ) ;

/* end of uploading NC program 3 */
FWLIBAPI short WINAPI cnc_upend3( unsigned short ) ;

/* start uploading NC program 4 */
FWLIBAPI short WINAPI cnc_upstart4( unsigned short, short, char * ) ;

/* upload NC program 4 */
FWLIBAPI short WINAPI cnc_upload4( unsigned short, long *, char * ) ;

/* end of uploading NC program 4 */
FWLIBAPI short WINAPI cnc_upend4( unsigned short ) ;

/* maintenance data write F-ROM */
FWLIBAPI short WINAPI cnc_save_maint( unsigned short );

/* maintenance data clear F-ROM */
FWLIBAPI short WINAPI cnc_clear_maint( unsigned short );

/* read buffer status for downloading/verification NC program */
FWLIBAPI short WINAPI cnc_buff( unsigned short, ODBBUF * ) ;

/* search specified program */
FWLIBAPI short WINAPI cnc_search( unsigned short, short ) ;

#ifndef CNC_PPC
/* search specified program (2) */
FWLIBAPI short WINAPI cnc_search2( unsigned short, long ) ;
#endif

/* delete all programs */
FWLIBAPI short WINAPI cnc_delall( unsigned short ) ;

/* delete all programs */
FWLIBAPI short WINAPI cnc_pdf_delall( unsigned short, short, char * ) ;

/* delete specified program */
FWLIBAPI short WINAPI cnc_delete( unsigned short, short ) ;

/* delete program (area specified) */
 FWLIBAPI short WINAPI cnc_delrange( unsigned short, long, long ) ;

#ifndef CNC_PPC
/* read program directory */
FWLIBAPI short WINAPI cnc_rdprogdir( unsigned short, short, short, short, unsigned short, PRGDIR * ) ;
#endif

/* read program information */
FWLIBAPI short WINAPI cnc_rdproginfo( unsigned short, short, short, ODBNC * ) ;

/* read program number under execution */
FWLIBAPI short WINAPI cnc_rdprgnum( unsigned short, ODBPRO * ) ;

/* read program name under execution */
FWLIBAPI short WINAPI cnc_exeprgname( unsigned short, ODBEXEPRG * ) ;

/* read program name under execution (Full path) */
FWLIBAPI short WINAPI cnc_exeprgname2( unsigned short, char * ) ;

/* read program name under background execution */
FWLIBAPI short WINAPI cnc_exeprgname_bg( unsigned short, ODBEXEPRG * ) ;

/* read program name of DNC operation */
FWLIBAPI short WINAPI cnc_dncprgname( unsigned short, ODBDNCPRG * ) ;

/* read sequence number under execution */
FWLIBAPI short WINAPI cnc_rdseqnum( unsigned short, ODBSEQ * ) ;

/* search specified sequence number */
FWLIBAPI short WINAPI cnc_seqsrch( unsigned short, long ) ;

/* search specified sequence number (2) */
 FWLIBAPI short WINAPI cnc_seqsrch2( unsigned short, long ) ;

/* rewind cursor of NC program */
FWLIBAPI short WINAPI cnc_rewind( unsigned short ) ;

/* read block counter */
FWLIBAPI short WINAPI cnc_rdblkcount( unsigned short, long * ) ;

/* read program under execution */
FWLIBAPI short WINAPI cnc_rdexecprog( unsigned short, unsigned short *, short *, char * ) ;
FWLIBAPI short WINAPI cnc_rdexecprog2(unsigned short, unsigned short *, short *, short *, char *) ;
FWLIBAPI short WINAPI cnc_rdexecprog3(unsigned short, short *, ODBEXEPRGINFO *) ;

/* read program for MDI operation */
FWLIBAPI short WINAPI cnc_rdmdiprog( unsigned short, short *, char * ) ;

/* write program for MDI operation */
FWLIBAPI short WINAPI cnc_wrmdiprog( unsigned short, short, char * ) ;

/* read execution pointer for MDI operation */
FWLIBAPI short WINAPI cnc_rdmdipntr( unsigned short, ODBMDIP * ) ;

/* write execution pointer for MDI operation */
FWLIBAPI short WINAPI cnc_wrmdipntr( unsigned short, long ) ;

#ifndef CNC_PPC
/* register new program */
FWLIBAPI short WINAPI cnc_newprog( unsigned short, long );

/* copy program */
FWLIBAPI short WINAPI cnc_copyprog( unsigned short, long, long );

/* rename program */
FWLIBAPI short WINAPI cnc_renameprog( unsigned short, long, long );

/* condense program */
FWLIBAPI short WINAPI cnc_condense( unsigned short, short, long );
#endif

/* merge program */
FWLIBAPI short WINAPI cnc_mergeprog( unsigned short, short, long, unsigned long, long );

/* read current program and its pointer */
#ifndef CNC_PPC
FWLIBAPI short WINAPI cnc_rdactpt( unsigned short, long * , long * );
#endif
FWLIBAPI short WINAPI cnc_pdf_rdactpt( unsigned short, char * , long * ) ;
FWLIBAPI short WINAPI cnc_pdf_rdprgname( unsigned short, char *  ) ;
FWLIBAPI short WINAPI cnc_pdf_rdactpt_bgedt( unsigned short, char * , long * ) ;
FWLIBAPI short WINAPI cnc_pdf_rdmainpt( unsigned short, char * , long * ) ;

/* read all nest program */
FWLIBAPI short WINAPI cnc_pdf_rdcallstack( unsigned short, unsigned short, short * , ODBNESTPDF * ) ;

/* select act pointer kind */
FWLIBAPI short WINAPI cnc_setactptopt( unsigned short, long );

/* read current program and its pointer and UV macro pointer */
 FWLIBAPI short WINAPI cnc_rduvactpt( unsigned short, long * , long *, long * );

/* set current program and its pointer */
#ifndef CNC_PPC
FWLIBAPI short WINAPI cnc_wractpt( unsigned short, long, short, long * );
#endif
FWLIBAPI short WINAPI cnc_pdf_wractpt( unsigned short, char * , short, long * ) ;
FWLIBAPI short WINAPI cnc_pdf_wractpt_bgedt( unsigned short, char * , short, long * ) ;

#ifndef CNC_PPC
/* line edit (read program) */
FWLIBAPI short WINAPI cnc_rdprogline( unsigned short, long, unsigned long, char *, unsigned long *, unsigned long * );
FWLIBAPI short WINAPI cnc_rdprogline2( unsigned short, long, unsigned long, char *, unsigned long *, unsigned long * );
FWLIBAPI short WINAPI cnc_rdprogdata( unsigned short, long, unsigned long, char *, unsigned long *, unsigned long * );

/* line edit (write program) */
FWLIBAPI short WINAPI cnc_wrprogline( unsigned short, long, unsigned long, char *, unsigned long );

/* line edit (delete line in program) */
FWLIBAPI short WINAPI cnc_delprogline( unsigned short, long, unsigned long, unsigned long );

/* line edit (search string) */
FWLIBAPI short WINAPI cnc_searchword( unsigned short, long, unsigned long, short, short, unsigned long, char * );
#endif

FWLIBAPI short WINAPI cnc_searchword2( unsigned short, long, unsigned long, short, short, unsigned long, char * );
FWLIBAPI short WINAPI cnc_pdf_searchword( unsigned short, char *, unsigned long, unsigned long, unsigned long, unsigned long, char * );
FWLIBAPI short WINAPI cnc_pdf_searchword2( unsigned short, char *, unsigned long, unsigned long, unsigned long, unsigned long, char * );
FWLIBAPI short WINAPI cnc_pdf_searchword_bgedt( unsigned short, char *, unsigned long, unsigned long, unsigned long, unsigned long, char * );

/* line edit (search string in Data Server) */
FWLIBAPI short WINAPI cnc_pdf_dssearch( unsigned short, char *, unsigned long, unsigned long, unsigned long, unsigned long, char *,short );

/* line edit (search string) */
#ifndef CNC_PPC
FWLIBAPI short WINAPI cnc_searchresult( unsigned short, unsigned long * );
#endif
FWLIBAPI short WINAPI cnc_searchresult2( unsigned short, unsigned long * );
FWLIBAPI short WINAPI cnc_pdf_searchresult( unsigned short, unsigned long * );
FWLIBAPI short WINAPI cnc_pdf_searchresult2( unsigned short, unsigned long * );
FWLIBAPI short WINAPI cnc_pdf_searchresult_bgedt( unsigned short, unsigned long * );

/* replace all words */
FWLIBAPI short WINAPI cnc_pdf_replaceword_all( unsigned short, char *, unsigned long, unsigned long, unsigned long, char *, char * );

/* set program lock */
FWLIBAPI short WINAPI cnc_setpglock( unsigned short, long );
FWLIBAPI short WINAPI cnc_setpdf_pglock( unsigned short, char * );

/* reset program lock */
FWLIBAPI short WINAPI cnc_resetpglock( unsigned short, long );
FWLIBAPI short WINAPI cnc_resetpdf_pglock( unsigned short, char * );

/* read program lock status */
FWLIBAPI short WINAPI cnc_rdpglockstat( unsigned short, long *, long * );
FWLIBAPI short WINAPI cnc_rdpdf_pglockstat( unsigned short, long *, ODBPRGNAME * );

/* program sum data */
FWLIBAPI short WINAPI cnc_setsumdt(unsigned short, short, char *);

/* line edit (read program by file name) */
FWLIBAPI short WINAPI cnc_rdpdf_line( unsigned short, char *, unsigned long, char *, unsigned long *, unsigned long * );
FWLIBAPI short WINAPI cnc_rdpdf_line2( unsigned short, char *, unsigned long, char *, unsigned long *, unsigned long * );
FWLIBAPI short WINAPI cnc_rdpdf_line_bgedt( unsigned short, char *, unsigned long, char *, unsigned long *, unsigned long * );
FWLIBAPI short WINAPI cnc_rdpdf_execline( unsigned short, char *, unsigned long, char *, unsigned long *, unsigned long * );

/* line edit (write program by file name) */
FWLIBAPI short WINAPI cnc_wrpdf_line( unsigned short, char *, unsigned long, char *, unsigned long );

/* line edit (delete line by file name) */
FWLIBAPI short WINAPI cnc_pdf_delline( unsigned short, char *, unsigned long, unsigned long );

/* chara edit (write program by file name)	 */
FWLIBAPI short WINAPI cnc_wrpdf_char( unsigned short, char *, unsigned long, unsigned long, char *, unsigned long );

/* char edit (delete character by file name) */
FWLIBAPI short WINAPI cnc_pdf_delchar( unsigned short, char *, unsigned long, unsigned long, unsigned long );

/* char edit (replace character by file name)*/
FWLIBAPI short WINAPI cnc_pdf_replacechar(unsigned short, char *, unsigned long, unsigned long, unsigned long, char *, unsigned long );

/* read program drive directory */
FWLIBAPI short WINAPI cnc_rdpdf_drive( unsigned short, ODBPDFDRV * );

/* read program drive information */
FWLIBAPI short WINAPI cnc_rdpdf_inf( unsigned short, char *, short, ODBPDFINF * );

/* read current directory */
FWLIBAPI short WINAPI cnc_rdpdf_curdir( unsigned short, short, char * );

/* set current directory */
FWLIBAPI short WINAPI cnc_wrpdf_curdir( unsigned short, short, char * );

/* read directory (sub directories) */
FWLIBAPI short WINAPI cnc_rdpdf_subdir( unsigned short, short *, IDBPDFSDIR *, ODBPDFSDIR * );

/* read directory (all files) */
FWLIBAPI short WINAPI cnc_rdpdf_alldir( unsigned short, short *, IDBPDFADIR *, ODBPDFADIR * );

/* read file */
FWLIBAPI short WINAPI cnc_rdpdf_prginf( unsigned short, IDBPDFPRG *, ODBPDFPRG * );

/* read protect*/
FWLIBAPI short WINAPI cnc_rdprotect(unsigned short FlibHndl,short type, char *path, ODBPRTCT *prtct);

/* read protect*/
FWLIBAPI short WINAPI cnc_rdprotect2(unsigned short FlibHndl,short type, char *path, ODBPRTCT2 *prtct);

/* read file count in directory */
FWLIBAPI short WINAPI cnc_rdpdf_subdirn( unsigned short, char *, ODBPDFNFIL * );

/* create file or directory */
FWLIBAPI short WINAPI cnc_pdf_add( unsigned short, char * );
FWLIBAPI short WINAPI cnc_pdf_add_bgedt( unsigned short, char * );

/* delete file or directory */
FWLIBAPI short WINAPI cnc_pdf_del( unsigned short, char * );

/* rename file or directory */
FWLIBAPI short WINAPI cnc_pdf_rename( unsigned short, char *, char * );

/* read selected file name */
FWLIBAPI short WINAPI cnc_pdf_rdmain( unsigned short, char * );

/* select program file */
FWLIBAPI short WINAPI cnc_pdf_slctmain( unsigned short, char * );

/* condense program file */
FWLIBAPI short WINAPI cnc_pdf_cond( unsigned short, char * );

/* change attribute of program file and directory */
FWLIBAPI short WINAPI cnc_wrpdf_attr( unsigned short, char *, IDBPDFTDIR * );

/* copy program file */
FWLIBAPI short WINAPI cnc_pdf_copy( unsigned short, char *, char * );

/* move program file */
FWLIBAPI short WINAPI cnc_pdf_move( unsigned short, char *, char * );

/* copy or move programs/folders asynchronously*/
FWLIBAPI short WINAPI cnc_pdf_cpmv_start(unsigned short, short, char *, char *, short);
FWLIBAPI short WINAPI cnc_pdf_cpmv_poll(unsigned short, short *, char *);
FWLIBAPI short WINAPI cnc_pdf_cpmv_end(unsigned short);
FWLIBAPI short WINAPI cnc_pdf_cpmv_restart(unsigned short, short);

/* copy or move any files/folders asynchronously*/
FWLIBAPI short WINAPI cnc_file_cpmv_start(unsigned short, short, char *, char *, unsigned short);
FWLIBAPI short WINAPI cnc_file_cpmv_poll(unsigned short, short *, char *);
FWLIBAPI short WINAPI cnc_file_cpmv_end(unsigned short);
FWLIBAPI short WINAPI cnc_file_cpmv_restart(unsigned short, short);

/* punch program */
FWLIBAPI short WINAPI cnc_punch_prog(unsigned short ,long );
FWLIBAPI short WINAPI cnc_punch_prog2(unsigned short ,long, char * );
FWLIBAPI short WINAPI cnc_punch_prog3(unsigned short ,char *, char * );
FWLIBAPI short WINAPI cnc_punch_prog_bg(unsigned short ,long );
FWLIBAPI short WINAPI cnc_punch_prog2_bg(unsigned short ,long, char * );
FWLIBAPI short WINAPI cnc_punch_prog3_bg(unsigned short ,char *, char * );
FWLIBAPI short WINAPI cnc_start_async_punch_prog3( unsigned short, char *, char * );
FWLIBAPI short WINAPI cnc_end_async_punch_prog3( unsigned short, char *, short * );
FWLIBAPI short WINAPI cnc_start_async_punch_prog3_bg( unsigned short, char *, char * );
FWLIBAPI short WINAPI cnc_end_async_punch_prog3_bg( unsigned short, char *, short * );
FWLIBAPI short WINAPI cnc_pdf_punch(unsigned short, long, char *, char * );
FWLIBAPI short WINAPI cnc_pdf_punch_bg(unsigned short, long, char *, char * );
FWLIBAPI short WINAPI cnc_start_async_pdf_punch( unsigned short, long, char *, char * ) ;
FWLIBAPI short WINAPI cnc_end_async_pdf_punch( unsigned short, short * ) ;

/* read program */
FWLIBAPI short WINAPI cnc_read_prog(unsigned short ,long );
FWLIBAPI short WINAPI cnc_read_prog2(unsigned short ,long, char * );
FWLIBAPI short WINAPI cnc_read_prog3(unsigned short ,char *, char * );
FWLIBAPI short WINAPI cnc_read_prog_bg(unsigned short ,long, char * );
FWLIBAPI short WINAPI cnc_read_prog2_bg(unsigned short ,long, char *, char * );
FWLIBAPI short WINAPI cnc_read_prog3_bg(unsigned short ,char *, char *, char * );
FWLIBAPI short WINAPI cnc_start_async_read_prog3( unsigned short, char *, char * );
FWLIBAPI short WINAPI cnc_end_async_read_prog3( unsigned short, char *, short * );
FWLIBAPI short WINAPI cnc_start_async_read_prog3_bg( unsigned short, char *, char * );
FWLIBAPI short WINAPI cnc_end_async_read_prog3_bg( unsigned short, char *, char *, short * );
FWLIBAPI short WINAPI cnc_pdf_read(unsigned short, char *, char * );
FWLIBAPI short WINAPI cnc_pdf_read_bg(unsigned short, char *, char * );
FWLIBAPI short WINAPI cnc_start_async_pdf_read( unsigned short, char *, char * ) ;
FWLIBAPI short WINAPI cnc_end_async_pdf_read( unsigned short, short * ) ;
FWLIBAPI short WINAPI cnc_pdf_read_start(unsigned short, short, char *, char *, short) ;
FWLIBAPI short WINAPI cnc_pdf_read_poll(unsigned short, short *, char *, char *) ;
FWLIBAPI short WINAPI cnc_pdf_read_end(unsigned short) ;
FWLIBAPI short WINAPI cnc_pdf_read_restart(unsigned short, short, char *) ;
/* Stop Read/Punch Program   */
FWLIBAPI short WINAPI cnc_stop_async_read_punch(unsigned short h);

/* verify program */
FWLIBAPI short WINAPI cnc_verify_prog(unsigned short, char *, char * );
FWLIBAPI short WINAPI cnc_verify_prog_bg(unsigned short, char *, char * );

/* punch/read data */
FWLIBAPI short WINAPI cnc_punch_data(unsigned short , short, char *);
FWLIBAPI short WINAPI cnc_read_data(unsigned short , short, char *);
FWLIBAPI short WINAPI cnc_punch_data_start( unsigned short, short, unsigned long, unsigned long, char * );
FWLIBAPI short WINAPI cnc_punch_data_end( unsigned short, unsigned long *, unsigned long *, short * );

FWLIBAPI short WINAPI cnc_start_async_data_punch(unsigned short , short , char *);
FWLIBAPI short WINAPI cnc_end_async_data_punch(unsigned short , short , short *);
FWLIBAPI short WINAPI cnc_start_async_data_read(unsigned short , short , char *);
FWLIBAPI short WINAPI cnc_end_async_data_read(unsigned short , short , short *);

/* memory card program */
FWLIBAPI short WINAPI cnc_mcdp_unmount(unsigned short);
FWLIBAPI short WINAPI cnc_mcdp_mountchk(unsigned short, char *);
FWLIBAPI short WINAPI cnc_mcdp_mount(unsigned short);
FWLIBAPI short WINAPI cnc_mcdp_update_entry(unsigned short, long);
FWLIBAPI short WINAPI cnc_mcdp_wractpt(unsigned short, char *, long, unsigned long *);

/* cnc_rdactpt_w:read execution pointer of program for FS160is/180is-WB */
FWLIBAPI short WINAPI cnc_rdactpt_w( unsigned short, short, ODBACTPTW * );

/* cnc_wractpt_w:set execution pointer of program for FS160is/180is-WB */
FWLIBAPI short WINAPI cnc_wractpt_w( unsigned short, short, long );

/* set dnc file name */
FWLIBAPI short WINAPI cnc_pdf_dncset( unsigned short, char * );

/* set dnc file name */
FWLIBAPI short WINAPI cnc_pdf_dncset2( unsigned short, char * ,unsigned short );

/* read dnc file name */
FWLIBAPI short WINAPI cnc_pdf_dncread( unsigned short, char * );

/* merge program */
FWLIBAPI short WINAPI cnc_pdf_mergeprog(unsigned short, short, char *, unsigned long, unsigned long, char *);

/* read embedded folder information */
FWLIBAPI short WINAPI cnc_rdembedf_inf( unsigned short, char *, short, ODBEMBEDFINF * );

/* for program reference mode */
FWLIBAPI short WINAPI cnc_setpdf_pglockexec( unsigned short, char * );

/* get system folder number */
FWLIBAPI short WINAPI cnc_getsysfolder_num( unsigned short, short * );

/* get execution macro running status */
FWLIBAPI short WINAPI cnc_getexemacstat( unsigned short, short * );

/* release main program file */
FWLIBAPI short WINAPI cnc_pdf_relsmain(unsigned short);

/*---------------------------*/
/* CNC: NC file data related */
/*---------------------------*/

/* read tool offset value */
FWLIBAPI short WINAPI cnc_rdtofs( unsigned short, short, short, short, ODBTOFS * ) ;

/* write tool offset value */
FWLIBAPI short WINAPI cnc_wrtofs( unsigned short, short, short, short, long ) ;

/* read tool offset value(area specified) */
FWLIBAPI short WINAPI cnc_rdtofsr( unsigned short, short, short, short, short, IODBTO * ) ;

/* write tool offset value(area specified) */
FWLIBAPI short WINAPI cnc_wrtofsr( unsigned short, short, IODBTO * ) ;

/* clear tool offset value(all data) */
FWLIBAPI short WINAPI cnc_clrtofs( unsigned short , short );

/* read work zero offset value */
FWLIBAPI short WINAPI cnc_rdzofs( unsigned short, short, short, short, IODBZOFS * ) ;

/* write work zero offset value */
FWLIBAPI short WINAPI cnc_wrzofs( unsigned short, short, IODBZOFS * ) ;

/* read work zero offset value(area specified) */
FWLIBAPI short WINAPI cnc_rdzofsr( unsigned short, short, short, short, short, IODBZOR * ) ;

/* write work zero offset value(area specified) */
FWLIBAPI short WINAPI cnc_wrzofsr( unsigned short, short, IODBZOR * ) ;

/* read mesured point value */
FWLIBAPI short WINAPI cnc_rdmsptype( unsigned short, short, short, short, IODBMSTP * ) ;

/* write mesured point value */
FWLIBAPI short WINAPI cnc_wrmsptype( unsigned short, short, IODBMSTP * ) ;

/* read parameter */
FWLIBAPI short WINAPI cnc_rdparam( unsigned short, short, short, short, IODBPSD * ) ;

/* read parameter */
FWLIBAPI short WINAPI cnc_rdparam3( unsigned short, short, short, short, short, IODBPSD * ) ;

/* write parameter */
FWLIBAPI short WINAPI cnc_wrparam( unsigned short, short, IODBPSD * ) ;

/* write parameter */
FWLIBAPI short WINAPI cnc_wrparam3( unsigned short, short, short, IODBPSD * ) ;

/* read parameter(area specified) */
FWLIBAPI short WINAPI cnc_rdparar( unsigned short, short *, short, short *, short *, void * ) ;

/* read parameter(area specified) */
FWLIBAPI short WINAPI cnc_rdparar3( unsigned short, short *, short, short *, short *, short, void * ) ;

/* write parameter(area specified) */
FWLIBAPI short WINAPI cnc_wrparas( unsigned short, short, void * ) ;

/* write parameter(area specified) */
FWLIBAPI short WINAPI cnc_wrparas3( unsigned short, short, short, void * ) ;

/* write parameter presede */
FWLIBAPI short WINAPI cnc_preset_prm( unsigned short, short, IODBBOOK * ) ;

/* write parameter presede */
FWLIBAPI short WINAPI cnc_validate_prm( unsigned short, short ) ;

/* write parameter presede */
FWLIBAPI short WINAPI cnc_cancel_prm( unsigned short, short ) ;

/* read cnc id */
FWLIBAPI short WINAPI cnc_rdcncid( unsigned short, unsigned long * );

/* After setting the option, The state of SRAM is acquired */
FWLIBAPI short WINAPI cnc_sramstat( unsigned short, short, short *, ODBOPMSG * );

/* After setting the option, The state of SRAM is acquired */
FWLIBAPI short WINAPI cnc_sramstatus( unsigned short, short, short *, ODBSRAMSTAT * );

/* option write select */
FWLIBAPI short WINAPI cnc_validate_opt( unsigned short, short slct );

/* read setting data */
FWLIBAPI short WINAPI cnc_rdset( unsigned short, short, short, short, IODBPSD * ) ;

/* write setting data */
FWLIBAPI short WINAPI cnc_wrset( unsigned short, short, IODBPSD * ) ;

/* read setting data(area specified) */
FWLIBAPI short WINAPI cnc_rdsetr( unsigned short, short *, short, short *, short *, void * ) ;

/* write setting data(area specified) */
FWLIBAPI short WINAPI cnc_wrsets( unsigned short, short, void * ) ;

/* read parameters */
FWLIBAPI short WINAPI cnc_rdparam_ext( unsigned short, long *, short, IODBPRM * ) ;

/* async parameter write start */
FWLIBAPI short WINAPI cnc_start_async_wrparam( unsigned short, IODBPRM * ) ;

/* async parameter write end */
FWLIBAPI short WINAPI cnc_end_async_wrparam( unsigned short, short * ) ;

/* read busy status for async parameter write */
FWLIBAPI short WINAPI cnc_async_busy_state( unsigned short, short * );

/* read diagnosis data */
FWLIBAPI short WINAPI cnc_rddiag_ext( unsigned short, long *, short, IODBPRM * ) ;

/* read pitch error compensation data(area specified) (incremental)*/
FWLIBAPI short WINAPI cnc_rdpitchr( unsigned short, short, short, short, IODBPI * ) ;

/* write pitch error compensation data(area specified) (incremental)*/
FWLIBAPI short WINAPI cnc_wrpitchr( unsigned short, short, IODBPI * ) ;

/* read pitch error compensation data(area specified) (incremental/absolute)*/
FWLIBAPI short WINAPI cnc_rdpitchr2(unsigned short, short, short *, short *);

/* write pitch error compensation data(area specified) (incremental/absolute)*/
FWLIBAPI short WINAPI cnc_wrpitchr2(unsigned short, short, short *, short *);

/* check pich error compensation data(area specified) (absolute) */
FWLIBAPI short WINAPI cnc_checkpitch(unsigned short, short, short *, short *);

/* read high precision pitch error compensation data */
FWLIBAPI short WINAPI cnc_rdhipitchr( unsigned short, long, long *, long * ) ;

/* write high precision pitch error compensation data */
FWLIBAPI short WINAPI cnc_wrhipitchr( unsigned short, long, long *, long * ) ;

/* read high precision pitch error compensation info */
FWLIBAPI short WINAPI cnc_rdhipitchinfo( unsigned short, long * ) ;

/* read custom macro variable */
FWLIBAPI short WINAPI cnc_rdmacro( unsigned short, short, short, ODBM * ) ;

/* write custom macro variable */
FWLIBAPI short WINAPI cnc_wrmacro( unsigned short, short, short, long, short ) ;

/* read custom macro variable 2 */
 FWLIBAPI short WINAPI cnc_rdmacro2( unsigned short, short, short, ODBM * ) ;

/* read custom macro variable (3)*/
 FWLIBAPI short WINAPI cnc_rdmacro3( unsigned short, long, short, ODBM3 * ) ;

/* write custom macro variable (3)*/
 FWLIBAPI short WINAPI cnc_wrmacro3( unsigned short, long, short, long, short ) ;

/* read custom macro variables(area specified) */
FWLIBAPI short WINAPI cnc_rdmacror( unsigned short, short, short, short, IODBMR * ) ;

/* write custom macro variables(area specified) */
FWLIBAPI short WINAPI cnc_wrmacror( unsigned short, short, IODBMR * ) ;

#if defined (HSSB_LIB) && defined (FS15BD)
/* read custom macro variables(area specified) 2 */
FWLIBAPI short WINAPI cnc_rdmacror2( unsigned short, short, short, short, IODBMR * ) ;
#else
/* read custom macro variables(IEEE double version) */
FWLIBAPI short WINAPI cnc_rdmacror2( unsigned short, unsigned long, unsigned long *, double * ) ;
FWLIBAPI short WINAPI cnc_rdmacror2_name( unsigned short, unsigned long, unsigned long *, IODBMRN *pdb ) ;
#endif
FWLIBAPI short WINAPI cnc_rdmacror3( unsigned short, unsigned long, unsigned long *, IODBMRN3 *pdb ) ;
FWLIBAPI short WINAPI cnc_rdmacror4( unsigned short, unsigned long, unsigned long *, IODBMRN4 *pdb ) ;

/* write custom macro variables(IEEE double version) */
FWLIBAPI short WINAPI cnc_wrmacror2( unsigned short, unsigned long, unsigned long *, double * ) ;

/* read custom macro variable(Back ground version) */
FWLIBAPI short WINAPI cnc_rdmacro_bg( unsigned short, short, short, ODBM * ) ;

/* write custom macro variable(Back ground version) */
FWLIBAPI short WINAPI cnc_wrmacro_bg( unsigned short, short, short, long, short ) ;

/* read custom macro variable number */
FWLIBAPI short WINAPI cnc_rdmacronum( unsigned short, char *, unsigned long, unsigned long *, short * ) ;

/* read P code macro variable */
FWLIBAPI short WINAPI cnc_rdpmacro( unsigned short, long, ODBPM * ) ;

/* write P code macro variable */
FWLIBAPI short WINAPI cnc_wrpmacro( unsigned short, long, long, short ) ;

/* read P code macro variables(area specified) */
FWLIBAPI short WINAPI cnc_rdpmacror( unsigned short, long, long, unsigned short, IODBPR * ) ;

/* write P code macro variables(area specified) */
FWLIBAPI short WINAPI cnc_wrpmacror( unsigned short, unsigned short, IODBPR * ) ;

/* read P code macro variables(IEEE double version) */
FWLIBAPI short WINAPI cnc_rdpmacror2( unsigned short, unsigned long, unsigned long *, unsigned short, double * );

/* write P code macro variables(IEEE double version) */
FWLIBAPI short WINAPI cnc_wrpmacror2( unsigned short, unsigned long, unsigned long *, unsigned short, double * );

/* read P code macro variables(Back ground version) */
FWLIBAPI short WINAPI cnc_rdpmacror_bg( unsigned short, unsigned long, unsigned long *, double * );

/* write P code macro variables(Back ground version) */
FWLIBAPI short WINAPI cnc_wrpmacror_bg( unsigned short, unsigned long, unsigned long *, double * );

/* read tool offset information */
FWLIBAPI short WINAPI cnc_rdtofsinfo( unsigned short, ODBTLINF * ) ;

/* read tool offset information(2) */
FWLIBAPI short WINAPI cnc_rdtofsinfo2( unsigned short, ODBTLINF2 * ) ;

/* read work zero offset information */
FWLIBAPI short WINAPI cnc_rdzofsinfo( unsigned short, short * ) ;

/* read work zero point measurement hole measured value */
FWLIBAPI short WINAPI cnc_rdholmes( unsigned short, ODBHOLDATA * ) ;

/* check [MEASURE] operation is available or not */
FWLIBAPI short WINAPI cnc_rdenblinfo( unsigned short, char * ) ;

/* check [MEASURE] [CENTER] operation is available or not */
FWLIBAPI short WINAPI cnc_rdcenblinfo( unsigned short, char * ) ;

/* read work zero point measurement value */
FWLIBAPI short WINAPI cnc_rdzofsmes( unsigned short, long, long, long, long *, long * ) ;

/* read work zero point measurement TL value */
FWLIBAPI short WINAPI cnc_rdtldata( unsigned short, ODBTLDATA * ) ;

/* write work zero point measurement TL value */
FWLIBAPI short WINAPI cnc_wrtldata( unsigned short, long, long, long ) ;

/* read work zero point measurement hole center value */
FWLIBAPI short WINAPI cnc_rdcenter( unsigned short, long *, long *, long *, long *, long *, long * ) ;

/* read tool length measurement information */
FWLIBAPI short WINAPI cnc_rdtlmsinfo( unsigned short, ODBTLMSINF * ) ;

/* check [MEASURE] [MEASURE+] operation is available or not */
FWLIBAPI short WINAPI cnc_rdtofsenbl( unsigned short, char * ) ;

/* write tool length measurement measured value */
FWLIBAPI short WINAPI cnc_wrtofsms( unsigned short, long, long ) ;

/* read pitch error compensation data information */
FWLIBAPI short WINAPI cnc_rdpitchinfo( unsigned short, short * ) ;

/* read custom macro variable information */
FWLIBAPI short WINAPI cnc_rdmacroinfo( unsigned short, ODBMVINF * ) ;

/* local val Level read */
FWLIBAPI short WINAPI cnc_rdmacrolclevel(unsigned short, short* );

/* Select Level local val (#1 - #31) read */
FWLIBAPI short WINAPI cnc_rdmacrolcval(unsigned short, short, short, short, double* );

/* read custom macro variable information ( block ) for Series 30i */
FWLIBAPI short WINAPI cnc_rdpitchblkinfo ( unsigned short, IODBPITCHBLK * ) ;

/* read volumetric compensation data */
FWLIBAPI short WINAPI	cnc_rdvolc( unsigned short, ODBVOLC *, long * ) ;

/* write volumetric compensation data */
FWLIBAPI short WINAPI	cnc_wrvolc( unsigned short, ODBVOLC *, long * ) ;

/* get volumetric compensation amount of axes */
FWLIBAPI short WINAPI	cnc_rdvolccomp	( unsigned short, ODBVOLCOMP * ) ;

/* punch volumetric compensation data to device */
FWLIBAPI short WINAPI	cnc_dvpunchvolc	( unsigned short, ODBVOLCOMP * ) ;

/* read volumetric compensation data to device */
FWLIBAPI short WINAPI	cnc_dvreadvolc	( unsigned short, ODBVOLCOMP * ) ;

/* read rotate volumetric compensation data */
FWLIBAPI short WINAPI	cnc_rdrotvolc( unsigned short, long , long *, IODBROTVOLC * ) ;

/* write rotate volumetric compensation data */
FWLIBAPI short WINAPI	cnc_wrrotvolc( unsigned short, long , long *, IODBROTVOLC * );

/* write rotate volumetric compensation data (2) */
FWLIBAPI short WINAPI	cnc_wrrotvolc2( unsigned short, long , long *, IODBROTVOLC * );

/* read P code macro variable information */
FWLIBAPI short WINAPI cnc_rdpmacroinfo( unsigned short, ODBPMINF * ) ;

/* read P code macro variable information (2) */
FWLIBAPI short WINAPI cnc_rdpmacroinfo2( unsigned short, ODBPMINF2 * ) ;

/* read P code macro variable information (3) */
FWLIBAPI short WINAPI cnc_rdpmacroinfo3( unsigned short, ODBPMINF3 * ) ;

/* read P code macro variable flag */
FWLIBAPI short WINAPI cnc_rdpmacvalflag( unsigned short, ODBPMVALFLG * );

/* read validity of tool offset */
FWLIBAPI short WINAPI cnc_tofs_rnge( unsigned short, short, short, ODBDATRNG * );

/* read validity of work zero offset */
FWLIBAPI short WINAPI cnc_zofs_rnge( unsigned short, short, short, ODBDATRNG * );

/* read validity of work shift value */
FWLIBAPI short WINAPI cnc_wksft_rnge( unsigned short, short, ODBDATRNG * );

#ifndef CNC_PPC
/* read the information for function cnc_rdhsparam() */
FWLIBAPI short WINAPI cnc_rdhsprminfo( unsigned short, long, HSPINFO * );

/* read parameters at the high speed */
FWLIBAPI short WINAPI cnc_rdhsparam( unsigned short, long, HSPINFO *, HSPDATA * );
#endif

/* read parameters at the high speed */
FWLIBAPI short WINAPI cnc_rdhsparamm( unsigned short, long, HSPINFO *, HSPDATAM * );

/* read multi edge tool offset */
FWLIBAPI short WINAPI cnc_rdmofs( unsigned short, short, short, long * );

/* write multi edge tool offset */
FWLIBAPI short WINAPI cnc_wrmofs( unsigned short, short, short, short, long );

/* clear multi edge tool offset */
FWLIBAPI short WINAPI cnc_clrmofs( unsigned short, short, short );

/* read tool geom size data */
FWLIBAPI short WINAPI cnc_rdtlgeomsize( unsigned short, short, short, short *, IODBTLGS * );

/* write tool geom size data */
FWLIBAPI short WINAPI cnc_wrtlgeomsize( unsigned short, short, short, short, short *, IODBTLGS * );

/* read extended tool geom size data */
FWLIBAPI short WINAPI cnc_rdtlgeomsize_ext( unsigned short, short, short, short *, IODBTLGSEXT * );

/* write extended tool geom size data */
FWLIBAPI short WINAPI cnc_wrtlgeomsize_ext( unsigned short, short, short, short, short *, IODBTLGSEXT * );

/* read extended tool geom size data */
FWLIBAPI short WINAPI cnc_rdtlgeomsize_ext2( unsigned short, short, short, short *, IODBTLGSEXT2 * );

/* write extended tool geom size data */
FWLIBAPI short WINAPI cnc_wrtlgeomsize_ext2( unsigned short, short, short, short, short *, IODBTLGSEXT2 * );

/*----------------------------------------*/
/* CNC: Tool life management data related */
/*----------------------------------------*/

/* read tool life management data(tool group number) */
FWLIBAPI short WINAPI cnc_rdgrpid( unsigned short, short, ODBTLIFE1 * ) ;

/* read tool life management data(number of tool groups) */
FWLIBAPI short WINAPI cnc_rdngrp( unsigned short, ODBTLIFE2 * ) ;

/* read tool life management data(number of tools) */
FWLIBAPI short WINAPI cnc_rdntool( unsigned short, short, ODBTLIFE3 * ) ;

/* read tool life management data(tool life) */
FWLIBAPI short WINAPI cnc_rdlife( unsigned short, short, ODBTLIFE3 * ) ;

/* read tool life management data(tool lift counter) */
FWLIBAPI short WINAPI cnc_rdcount( unsigned short, short, ODBTLIFE3 * ) ;

/* read tool life management data(tool length number-1) */
FWLIBAPI short WINAPI cnc_rd1length( unsigned short, short, short, ODBTLIFE4 * ) ;

/* read tool life management data(tool length number-2) */
FWLIBAPI short WINAPI cnc_rd2length( unsigned short, short, short, ODBTLIFE4 * ) ;

/* read tool life management data(cutter compensation no.-1) */
FWLIBAPI short WINAPI cnc_rd1radius( unsigned short, short, short, ODBTLIFE4 * ) ;

/* read tool life management data(cutter compensation no.-2) */
FWLIBAPI short WINAPI cnc_rd2radius( unsigned short, short, short, ODBTLIFE4 * ) ;

/* read tool life management data(tool information-1) */
FWLIBAPI short WINAPI cnc_t1info( unsigned short, short, short, ODBTLIFE4 * ) ;

/* read tool life management data(tool information-2) */
FWLIBAPI short WINAPI cnc_t2info( unsigned short, short, short, ODBTLIFE4 * ) ;

/* read tool life management data(tool number) */
FWLIBAPI short WINAPI cnc_toolnum( unsigned short, short, short, ODBTLIFE4 * ) ;

/* read tool life management data(tool number, tool life, tool life counter)(area specified) */
FWLIBAPI short WINAPI cnc_rdtoolrng( unsigned short, short, short, short, IODBTR * ) ;

/* read tool life management data(all data within group) */
FWLIBAPI short WINAPI cnc_rdtoolgrp( unsigned short, short, short, ODBTG * ) ;

/* write tool life management data(tool life counter) (area specified) */
FWLIBAPI short WINAPI cnc_wrcountr( unsigned short, short, IDBWRC * ) ;

/* read tool life management data(used tool group number) */
FWLIBAPI short WINAPI cnc_rdusegrpid( unsigned short, ODBUSEGR * ) ;

/* read tool life management data(max. number of tool groups) */
FWLIBAPI short WINAPI cnc_rdmaxgrp( unsigned short, ODBLFNO * ) ;

/* read tool life management data(maximum number of tool within group) */
FWLIBAPI short WINAPI cnc_rdmaxtool( unsigned short, ODBLFNO * ) ;

/* read tool life management data(used tool no. within group) */
FWLIBAPI short WINAPI cnc_rdusetlno( unsigned short, short, short, short, ODBTLUSE * ) ;

/* read tool life management data(tool data1) */
FWLIBAPI short WINAPI cnc_rd1tlifedata( unsigned short, short, short, IODBTD * ) ;

/* read tool life management data(tool data2) */
FWLIBAPI short WINAPI cnc_rd2tlifedata( unsigned short, short, short, IODBTD * ) ;

/* write tool life management data(tool data1) */
FWLIBAPI short WINAPI cnc_wr1tlifedata( unsigned short, IODBTD * ) ;

/* write tool life management data(tool data2) */
FWLIBAPI short WINAPI cnc_wr2tlifedata( unsigned short, IODBTD * ) ;

/* read tool life management data(tool group information) */
FWLIBAPI short WINAPI cnc_rdgrpinfo( unsigned short, short, short, short, IODBTGI * ) ;

/* read tool life management data(tool group information 2) */
FWLIBAPI short WINAPI cnc_rdgrpinfo2( unsigned short, short, short, short, IODBTGI2 * ) ;

/* read tool life management data(tool group information 3) */
FWLIBAPI short WINAPI cnc_rdgrpinfo3( unsigned short, short, short, short, IODBTGI3 * ) ;

FWLIBAPI short WINAPI cnc_rdgrpinfo4( unsigned short, short, short, short, short *, IODBTGI4 * );

/* write tool life management data(tool group information) */
FWLIBAPI short WINAPI cnc_wrgrpinfo( unsigned short, short, IODBTGI * ) ;

/* write tool life management data(tool group information 2) */
FWLIBAPI short WINAPI cnc_wrgrpinfo2( unsigned short, short, IODBTGI2 * ) ;

/* write tool life management data(tool group information 3) */
FWLIBAPI short WINAPI cnc_wrgrpinfo3( unsigned short, short, IODBTGI3 * ) ;

/* delete tool life management data(tool group) */
FWLIBAPI short WINAPI cnc_deltlifegrp( unsigned short, short ) ;

/* insert tool life management data(tool data) */
FWLIBAPI short WINAPI cnc_instlifedt( unsigned short, IDBITD * ) ;

/* delete tool life management data(tool data) */
FWLIBAPI short WINAPI cnc_deltlifedt( unsigned short, short, short ) ;

/* clear tool life management data(tool life counter, tool information)(area specified) */
FWLIBAPI short WINAPI cnc_clrcntinfo( unsigned short, short, short ) ;

/* read tool life management data(tool group number) 2 */
FWLIBAPI short WINAPI cnc_rdgrpid2( unsigned short, long, ODBTLIFE5 * ) ;

/* read tool life management data(tool data1) 2 */
FWLIBAPI short WINAPI cnc_rd1tlifedat2( unsigned short, short, long, IODBTD2 * ) ;

/* write tool life management data(tool data1) 2 */
FWLIBAPI short WINAPI cnc_wr1tlifedat2( unsigned short, IODBTD2 * ) ;

/* read tool life management data */
FWLIBAPI short WINAPI cnc_rdtlinfo( unsigned short, ODBTLINFO * ) ;

/* read tool life management data(used tool group number) */
FWLIBAPI short WINAPI cnc_rdtlusegrp( unsigned short, ODBUSEGRP * ) ;

/* read tool life management data(tool group information 2) */
FWLIBAPI short WINAPI cnc_rdtlgrp( unsigned short, long, short *, IODBTLGRP * ) ;

/* read tool life management data (tool data1) */
FWLIBAPI short WINAPI cnc_rdtltool( unsigned short, long, long, short *, IODBTLTOOL * ) ;

/* read tool life management data ( tool change groupe ) */
FWLIBAPI short WINAPI cnc_rdtoolchggrp( unsigned short, short , short , long *);

/* read tool life management data ( count count over ride ) */
FWLIBAPI short WINAPI cnc_rdcntover( unsigned short, short * ) ;

FWLIBAPI short WINAPI cnc_rdexchgtgrp( unsigned short, short *, ODBEXGP *);

FWLIBAPI short WINAPI cnc_rdtlinfo( unsigned short, ODBTLINFO *);

FWLIBAPI short WINAPI cnc_rdtlusegrp( unsigned short, ODBUSEGRP *);

FWLIBAPI short WINAPI cnc_rdcnttype( unsigned short, short, ODBTLIFE3 * ) ;

/* write tool life management data(tool group number) */
FWLIBAPI short WINAPI cnc_wrtoolgrp( unsigned short, long, IDBITD * );

/* C_EXE */
/* Write Tool Life Management Data ( Group Life )         */
FWLIBAPI short WINAPI cnc_wrlife( unsigned short, IDBITD *);
/* Write Tool Life Management Data ( Group Count )        */
FWLIBAPI short WINAPI cnc_wrcount( unsigned short, IDBITD *);
/* Write Tool Life Management Data ( Group CountType )    */
FWLIBAPI short WINAPI cnc_wrcnttype( unsigned short, IDBITD *);

/* write tool life management data( tool length number 1 ) */
FWLIBAPI short WINAPI cnc_wr1length( unsigned short, IDBITD2 * );

/* write tool life management data( tool length number 2 ) */
FWLIBAPI short WINAPI cnc_wr2length( unsigned short, IDBITD * );

/* write tool life management data( tool radius number 1 ) */
FWLIBAPI short WINAPI cnc_wr1radius( unsigned short, IDBITD2 * );

/* write tool life management data( tool radius number 2 ) */
FWLIBAPI short WINAPI cnc_wr2radius( unsigned short, IDBITD * );

/* write tool life management data( tool infomation 1 ) */
FWLIBAPI short WINAPI cnc_wrt1info( unsigned short, IDBITD2 * );

/* write tool life management data( tool infomation 2 ) */
FWLIBAPI short WINAPI cnc_wrt2info( unsigned short, IDBITD * );

/* write tool life management data( tool number ) */
FWLIBAPI short WINAPI cnc_wrtoolnum( unsigned short, IDBITD * );

/* read task information */
FWLIBAPI short WINAPI cnc_read_cexeinfo(unsigned short ,short, CEXEINFO * );

/*-----------------------------------*/
/* CNC: Tool management data related */
/*-----------------------------------*/
/* register new tool management data */
FWLIBAPI short WINAPI cnc_regtool( unsigned short, short, short *, IODBTLMNG * ) ;

/* register new tool management data */
FWLIBAPI short WINAPI cnc_regtool_f2( unsigned short, short, short *, IODBTLMNG_F2 * ) ;

/* delete tool management data */
FWLIBAPI short WINAPI cnc_deltool( unsigned short, short, short *  ) ;

/* read tool management data */
FWLIBAPI short WINAPI cnc_rdtool( unsigned short, short, short *, IODBTLMNG * ) ;

/* read tool management data */
FWLIBAPI short WINAPI cnc_rdtool2(unsigned short, short, short, short *, IODBTLM2 *);

/* read tool management data */
FWLIBAPI short WINAPI cnc_rdtool_f2( unsigned short, short, short *, IODBTLMNG_F2 * ) ;

/* write tool management data */
FWLIBAPI short WINAPI cnc_wrtool( unsigned short, short, IODBTLMNG * ) ;

/* write tool management data */
FWLIBAPI short WINAPI cnc_wrtool_f2( unsigned short, short, IODBTLMNG_F2 * ) ;

/* write individual data of tool management data */
FWLIBAPI short WINAPI cnc_wrtool2( unsigned short, short, IDBTLM * ) ;

/* register new magazine management data */
FWLIBAPI short WINAPI cnc_regmagazine( unsigned short, short *, IODBTLMAG * ) ;

/* delete magazine management data */
FWLIBAPI short WINAPI cnc_delmagazine( unsigned short, short *, IODBTLMAG2 * ) ;

/* read magazine management data */
FWLIBAPI short WINAPI cnc_rdmagazine( unsigned short, short *, IODBTLMAG * ) ;

/* write magazine management data */
FWLIBAPI short WINAPI cnc_wrmagazine( unsigned short, short, short, short ) ;

/* read customdata name */
FWLIBAPI short WINAPI cnc_rdctname( unsigned short, short, unsigned char * ) ;

/* read toollife state name */
FWLIBAPI short WINAPI cnc_rdtlname( unsigned short, short, unsigned char * ) ;

/* read tool kind number in 1st spindle position and 1st wait position */
FWLIBAPI short WINAPI cnc_rdhdnxt( unsigned short, long *, long *) ;

/* read of the customise data of a tool management screen */
FWLIBAPI short WINAPI cnc_rdtldspcstms( unsigned short, short * ) ;

/* read of the customise data of a screen for tool management function */
FWLIBAPI short WINAPI cnc_rdtldspcstms2( unsigned short, short, short * ) ;

/* read of the spindle name and the wait name */
FWLIBAPI short WINAPI cnc_rdspdlwaitname( unsigned short, IODBTLSPWTNAME * );

/* read of the number of below decimal point beams of customaize data */
FWLIBAPI short WINAPI cnc_rdcstmdecfig( unsigned short, unsigned char * ) ;

/* read of the renewal status every kind data of a tool management */
FWLIBAPI short WINAPI cnc_rdtlnewstatus( unsigned short, unsigned long * ) ;

/* write  bigtool geom set data */
FWLIBAPI short WINAPI cnc_rdtoolgeom_tlm( unsigned short, short, short *, IODBTLGEOM * ) ;

/* read  bigtool geom set data */
FWLIBAPI short WINAPI cnc_wrtoolgeom_tlm( unsigned short, short, short *, IODBTLGEOM * ) ;

/* search  freepot */
FWLIBAPI short WINAPI cnc_btlfpotsrh( unsigned short, short, short, short, short *) ;

/* search  freepot */
FWLIBAPI short WINAPI cnc_rdinterference( unsigned short, IODBTLINTF *) ;

FWLIBAPI short WINAPI cnc_rdtoollife_count( unsigned short, char, short * );

FWLIBAPI short WINAPI cnc_rdtoollife_data( unsigned short, short , short * , IODBTL_RDTYPE , IODBTLLF*  );

FWLIBAPI short WINAPI cnc_rdtoollifed_count( unsigned short, long , short * );

FWLIBAPI short WINAPI cnc_rdtoollifed_data( unsigned short, long , short , short * , IODBTLLFD* );

FWLIBAPI short WINAPI cnc_rdtoollife_tcodedata	( unsigned short, long , unsigned char , IODBTLLF*  );
FWLIBAPI short WINAPI cnc_rdtlmgr_check	( unsigned short, IODBTLMGR_CHECK*  );

FWLIBAPI short WINAPI cnc_tool_in( unsigned short, short* , IODBTLMNG_F2*  );
FWLIBAPI short WINAPI cnc_tool_out( unsigned short, char , IODBTLMAG2*  );
FWLIBAPI short WINAPI cnc_rdtool_inhis	( unsigned short, short, short*, IODBTOOL_INHIS*  );
FWLIBAPI short WINAPI cnc_rdtool_outhis	( unsigned short, short, short*, IODBTOOL_OUTHIS*  );
FWLIBAPI short WINAPI cnc_rdtool_cause	( unsigned short, IODBTOOL_CAUSENME* );

FWLIBAPI short WINAPI cnc_tool_temp_in( unsigned short, IODBTLMAG2*  );
FWLIBAPI short WINAPI cnc_tool_temp_out( unsigned short, IODBTLMAG2*  );

FWLIBAPI short WINAPI cnc_tool_in2( unsigned short, IODBTLMAG*  );

FWLIBAPI short WINAPI cnc_srttl_getnum(unsigned short , short, long, long, short*);
FWLIBAPI short WINAPI cnc_srttl_getdata(unsigned short , short, short*, short, long, long, IODBTLMNG_SORT*);

/* read customisedata name */
FWLIBAPI short WINAPI cnc_rdtlmgr_name(unsigned short , short , short , short*, unsigned char* );

/* read customise decdata */
FWLIBAPI short WINAPI cnc_rdcstm_decfig(unsigned short , short ,  short , short*, unsigned char* );

/* read  magazineproperty data */
FWLIBAPI short WINAPI cnc_rdmag_property(unsigned short , short*, IODBMAGPRTY* );

/* write  magazineproperty data */
FWLIBAPI short WINAPI cnc_wrmag_property(unsigned short , short*, IODBMAGPRTY* );

/* read  potproperty data */
FWLIBAPI short WINAPI cnc_rdpot_property(unsigned short , short , short , short*, IODBPOTPRTY* );

/* write  potproperty data */
FWLIBAPI short WINAPI cnc_wrpot_property(unsigned short ,short ,short , short*, IODBPOTPRTY* );

/* delete magazineproperty data */
FWLIBAPI short WINAPI cnc_delmag_property(unsigned short ,short*, IODBMAGPRTY2*);

/* delete potproperty data */
FWLIBAPI short WINAPI cnc_delpot_property(unsigned short , short ,short ,short*);

/* move tool data*/
FWLIBAPI short WINAPI cnc_tool_move(unsigned short , IODBTLMAG2*, IODBTLMAG2*);

/* resistry tool strage position */
FWLIBAPI short WINAPI cnc_reg_toolstrage( unsigned short, unsigned char, IODBTLMAG *);

/* Search  magazine management data */
FWLIBAPI short WINAPI cnc_magazinesrch(unsigned short, short, IDBTLM_SRCHDT, IODBTLMAG_SRCHINFO* );

/* Search  tool management data     */
FWLIBAPI short WINAPI cnc_toolsrch(unsigned short , short , short , IDBTLM_SRCHDT , short* );

FWLIBAPI short WINAPI cnc_rdedgedata(unsigned short, short, short, short *, ODBTLMNG_MU_EDGE * );
FWLIBAPI short WINAPI cnc_wredgedata(unsigned short, short, short, IODBTLMNG_MU_EDGE_DATA * );
FWLIBAPI short WINAPI cnc_wredgedata2(unsigned short, short, short, IDBTLM * );
FWLIBAPI short WINAPI cnc_rdedgedatapage(unsigned short, IDBTLMGR_ADD_INFO, unsigned char, short *, IODBTLMGR_PAGE * );

/* read edge num */
FWLIBAPI short WINAPI cnc_rdedgeactive( unsigned short, short, char * );
FWLIBAPI short WINAPI cnc_tool_in3( unsigned short, short *, IODBTLMNG_F2 *, IODBTLMNG_MU_EDGE_DATA * );

/*-------------------------------------*/
/* CNC: Operation history data related */
/*-------------------------------------*/

/* stop logging operation history data */
FWLIBAPI short WINAPI cnc_stopophis( unsigned short ) ;

/* restart logging operation history data */
FWLIBAPI short WINAPI cnc_startophis( unsigned short ) ;

/* read number of operation history data */
FWLIBAPI short WINAPI cnc_rdophisno( unsigned short, unsigned short * ) ;

/* read operation history data */
FWLIBAPI short WINAPI cnc_rdophistry( unsigned short, unsigned short, unsigned short, unsigned short, ODBHIS * ) ;

/* read operation history data */
FWLIBAPI short WINAPI cnc_rdophistry2( unsigned short, unsigned short, unsigned short *, unsigned short *, void * ) ;

/* read operation history data F30i*/
FWLIBAPI short WINAPI cnc_rdophistry3( unsigned short, unsigned short, unsigned short *, unsigned short *, void * ) ;

/* read number of alarm history data */
FWLIBAPI short WINAPI cnc_rdalmhisno( unsigned short, unsigned short * ) ;

/* read alarm history data */
FWLIBAPI short WINAPI cnc_rdalmhistry( unsigned short, unsigned short, unsigned short, unsigned short, ODBAHIS * ) ;

/* read alarm history data */
FWLIBAPI short WINAPI cnc_rdalmhistry_w( unsigned short, unsigned short, unsigned short, unsigned short, ODBAHIS * ) ;

/* read alarm history data */
FWLIBAPI short WINAPI cnc_rdalmhistry2( unsigned short, unsigned short, unsigned short, unsigned short, ODBAHIS2 * ) ;

/* read alarm history data F30i*/
FWLIBAPI short WINAPI cnc_rdalmhistry3( unsigned short, unsigned short, unsigned short, unsigned short, ODBAHIS3 * ) ;

/* clear operation history data */
FWLIBAPI short WINAPI cnc_clearophis( unsigned short, short ) ;

/* backup operation history data */
FWLIBAPI short WINAPI cnc_backupophis( unsigned short ) ;

/* read signals related operation history */
FWLIBAPI short WINAPI cnc_rdhissgnl( unsigned short, IODBSIG * ) ;

/* read signals related operation history 2 */
FWLIBAPI short WINAPI cnc_rdhissgnl2( unsigned short, IODBSIG2 * ) ;

/* read signals related operation history for F30i*/
FWLIBAPI short WINAPI cnc_rdhissgnl3( unsigned short, IODBSIG3 * ) ;

/* write signals related operation history */
FWLIBAPI short WINAPI cnc_wrhissgnl( unsigned short, IODBSIG * ) ;

/* write signals related operation history 2 */
FWLIBAPI short WINAPI cnc_wrhissgnl2( unsigned short, IODBSIG2 * ) ;

/* write signals related operation history for F30i*/
FWLIBAPI short WINAPI cnc_wrhissgnl3( unsigned short, IODBSIG3 * ) ;

//------------------------------------------------------------------------------------------------------------------
/* read operation history data F30i*/
FWLIBAPI short WINAPI cnc_rdophistry4( unsigned short, unsigned short, unsigned short *, unsigned short *, void * ) ;

/* read number of operation history data (for cnc_rdophistry4 ) */
FWLIBAPI short WINAPI cnc_rdophisno4( unsigned short, unsigned short * ) ;

/* read number of operater message history data */
FWLIBAPI short WINAPI cnc_rdomhisno( unsigned short, unsigned short * ) ;

/* read alarm history data F30i*/
FWLIBAPI short WINAPI cnc_rdalmhistry4( unsigned short, unsigned short, unsigned short, unsigned short, ODBAHIS4 * );

/* read operater message history data F30i */
FWLIBAPI short WINAPI cnc_rdomhistry2( unsigned short, unsigned short, unsigned short, unsigned short, ODBOMHIS2 * ) ;

/* read number of operation history data */
FWLIBAPI short WINAPI cnc_rdophisno3( unsigned short, unsigned short * ) ;

/* read number of alarm history data */
FWLIBAPI short WINAPI cnc_rdalmhisno3( unsigned short, unsigned short * ) ;

/* read alarm history data F30i*/
FWLIBAPI short WINAPI cnc_rdalmhistry5( unsigned short, unsigned short, unsigned short, unsigned short, ODBAHIS5 * );

#ifndef CNC_PPC
/* write external key operation history for F30i*/
FWLIBAPI short WINAPI cnc_wrkeyhistry( unsigned short, char) ;
#endif

/*--------------------------------------*/
/* CNC: 3D interference check           */
/*--------------------------------------*/

/* cnc_rdtdiinfo:read 3 dimensional interferect check information */
FWLIBAPI short WINAPI cnc_rdtdiinfo(unsigned short, ODBINF *);

/* cnc_rdtdinamesetting:read name setting */
FWLIBAPI short WINAPI cnc_rdtdinamesetting(unsigned short, short, unsigned short, unsigned short *, ODBNME *);

/* cnc_wrtdinamesetting:write name setting */
FWLIBAPI short WINAPI cnc_wrtdinamesetting(unsigned short, short, unsigned short, unsigned short, ODBNME *);

/* cnc_rdtdifignum:read figure number */
FWLIBAPI short WINAPI cnc_rdtdifignum(unsigned short, unsigned short *);

/* cnc_wrtdifignum:write figure number */
FWLIBAPI short WINAPI cnc_wrtdifignum(unsigned short, unsigned short);

/* cnc_rdtdidispsetting:read display setting */
FWLIBAPI short WINAPI cnc_rdtdidispsetting(unsigned short, short, unsigned short, unsigned short *, ODBDST *);

/* cnc_wrtdidispsetting:write display setting */
FWLIBAPI short WINAPI cnc_wrtdidispsetting(unsigned short, short, unsigned short, unsigned short, ODBDST *);

/* cnc_rdtdishapedata:read shape data */
FWLIBAPI short WINAPI cnc_rdtdishapedata(unsigned short, short, unsigned short, unsigned short, unsigned short *, ODBSHP *);

/* cnc_wrtdishapedata:write shape data */
FWLIBAPI short WINAPI cnc_wrtdishapedata(unsigned short, short, unsigned short, unsigned short, unsigned short, ODBSHP *);

/* cnc_rdtdicubedata:read cube data */
FWLIBAPI short WINAPI cnc_rdtdicubedata(unsigned short, unsigned short, ODBCUB *);

/* cnc_wrtdicubedata:write cube data */
FWLIBAPI short WINAPI cnc_wrtdicubedata(unsigned short, unsigned short, ODBCUB *);

/* cnc_rdtdicubeinfo:read cube infomation */
FWLIBAPI short WINAPI cnc_rdtdicubeinfo(unsigned short, unsigned short, unsigned short *, ODBCBI *);

/* cnc_rdtdieffectshape:read effect shape */
FWLIBAPI short WINAPI cnc_rdtdieffectshape(unsigned short, short, unsigned short, unsigned short *);

/* cnc_rdtdieffectshape:write effect shape */
FWLIBAPI short WINAPI cnc_wrtdieffectshape(unsigned short, short, unsigned short, unsigned short);

/* cnc_rdtdimoveaxis:read move axis infomation */
FWLIBAPI short WINAPI cnc_rdtdimoveaxis(unsigned short, short, unsigned short, ODBMVA *);

/* cnc_wrtdimoveaxis:write move axis infomation */
FWLIBAPI short WINAPI cnc_wrtdimoveaxis(unsigned short, short, unsigned short, ODBMVA *);

/* cnc_rdtdiseltool:read selected tool infomation */
FWLIBAPI short WINAPI cnc_rdtdiseltool(unsigned short, long, long *, long *);

/* cnc_rdtdicurrentshape:read current shape */
FWLIBAPI short WINAPI cnc_rdtdicurrentshape(unsigned short, short, unsigned short, unsigned short *);

/* cnc_rdtdicrntshapeinf:read current shape infomation */
FWLIBAPI short WINAPI cnc_rdtdicrntshapeinf(unsigned short, short, unsigned short, unsigned short, unsigned short *, ODBCRNTSHP *);

/* cnc_opentdicubeinfo:open cube infomation */
FWLIBAPI short WINAPI cnc_opentdicubeinfo(unsigned short FlibHndl, unsigned short *, unsigned short *);

/* cnc_seqrdtdicubeinfo:sequential read cube infomation */
FWLIBAPI short WINAPI cnc_seqrdtdicubeinfo(unsigned short FlibHndl, unsigned short, unsigned short, unsigned short *, ODBCBI *);

/* cnc_rdtdicylinderdata:read cylinder data */
FWLIBAPI short WINAPI cnc_rdtdicylinderdata(unsigned short, unsigned short, ODBCYL *);

/* cnc_wrtdicylinderdata:write cylinder data */
FWLIBAPI short WINAPI cnc_wrtdicylinderdata(unsigned short, unsigned short, ODBCYL *);

/* cnc_rdtdiplanedata:read plane data */
FWLIBAPI short WINAPI cnc_rdtdiplanedata(unsigned short, unsigned short, ODBPLN *);

/* cnc_wrtdiplanedata:write plane data */
FWLIBAPI short WINAPI cnc_wrtdiplanedata(unsigned short, unsigned short, ODBPLN *);

/* cnc_rdtdifiguredata:read figure data */
FWLIBAPI short WINAPI cnc_rdtdifiguredata(unsigned short, unsigned short, unsigned short *, ODBFIG *);

/* cnc_wrtdifiguredata:write figure data */
FWLIBAPI short WINAPI cnc_wrtdifiguredata(unsigned short, unsigned short, unsigned short, ODBFIG *);

/* cnc_rdtdiinitview:read initial view type */
FWLIBAPI short WINAPI cnc_rdtdiinitview(unsigned short, unsigned short *);

/* cnc_wrtdiinitview:write initial view type */
FWLIBAPI short WINAPI cnc_wrtdiinitview(unsigned short, unsigned short);

/* cnc_settdiobjectshape:set object shape (G22.2 imitation) */
FWLIBAPI short WINAPI cnc_settdiobjectshape(unsigned short, unsigned short, unsigned short);

/* cnc_settditoolshape:set tool shape (WINDW 431 imitation) */
FWLIBAPI short WINAPI cnc_settditoolshape(unsigned short, unsigned short, unsigned short);

/* read 3D interference check comment */
FWLIBAPI short WINAPI cnc_rdtdicomment(unsigned short FlibHndl, short *length, char *comment);

/* read 3D interference check comment */
FWLIBAPI short WINAPI cnc_wrtdicomment(unsigned short FlibHndl, short *length, char *comment);

/* read 3D interference check color data */
FWLIBAPI short WINAPI cnc_rdtdicolordata(unsigned short FlibHndl, short ob_type, unsigned short ob_s_no, unsigned short rd_num, char *data);

/* write 3D interference check color data */
FWLIBAPI short WINAPI cnc_wrtdicolordata(unsigned short FlibHndl, short ob_type, unsigned short ob_s_no, unsigned short wrt_num, char *data);

/*-----------------------------------*/
/* CNC: trouble diagnosis            */
/*-----------------------------------*/
/* cnc_mdg_rdalmnum:Reading of alarm number when generated */
FWLIBAPI short WINAPI cnc_mdg_rdalmnum(unsigned short, long*);

/* cnc_mdg_rdalminfo:Reading of alarm infomation when generated */
FWLIBAPI short WINAPI cnc_mdg_rdalminfo(unsigned short, long, long*, IODBMDGINFO*);

/* cnc_mdg_rdmsg:Reading of presumption cause message */
FWLIBAPI short WINAPI cnc_mdg_rdmsg(unsigned short, IODBMDGINFO*, ODBMDGMSG*);

/* cnc_mdg_rdflow:Reading of flow message */
FWLIBAPI short WINAPI cnc_mdg_rdflow(unsigned short, short, short, IODBMDGINFO*, ODBMDGFLOW*);

/* cnc_mdg_rddtmsg:Reading of detail message */
FWLIBAPI short WINAPI cnc_mdg_rddtmsg(unsigned short, short, IODBMDGINFO*, ODBMDGDTMSG*);

/* cnc_mdg_rdmsgnum:Reading of presumption cause message number */
FWLIBAPI short WINAPI cnc_mdg_rdmsgnum(unsigned short, short, long*);

/* cnc_mdg_msgsrch:Searching of presumption cause message */
FWLIBAPI short WINAPI cnc_mdg_msgsrch(unsigned short, short, long, long*);

/* cnc_mdg_rdmsgordr:Reading of the registration order presumption cause message */
FWLIBAPI short WINAPI cnc_mdg_rdmsgordr(unsigned short, short, long, long*, ODBMDGMSG*);

/* cnc_mdg_rdcontinfo:Reading of information on alarm when being continuing */
FWLIBAPI short WINAPI cnc_mdg_rdcontinfo(unsigned short, short*, long*, long*, IODBMDGINFO*);

/* cnc_mdg_rdorderalmno:Reading of the diagnosis order alarm number */
FWLIBAPI short WINAPI cnc_mdg_rdorderalmno(unsigned short, IODBMDGINFO*, long*);

/* cnc_mdg_rdlatchedalm:Reading of alarm information on maintenance */
FWLIBAPI short WINAPI cnc_mdg_rdlatchedalm(unsigned short, IODBMDGINFO*, short*);

/* cnc_mdg_rdalminfoview2:Reading of trouble diagnosis monitor information */
FWLIBAPI short WINAPI cnc_mdg_rdalminfoview2(unsigned short, short, short, short, ODBVIEWGRP2*);

/* cnc_mdg_rdwvdata:Reading of waveform data */
FWLIBAPI short WINAPI cnc_mdg_rdwvdata(unsigned short, short, char, ODBMDGWVDT*);

/* cnc_mdg_rdheatsimlt:Reading of present value of heat simulation */
FWLIBAPI short WINAPI cnc_mdg_rdheatsimlt(unsigned short, short, short, short, ODBLOAD*);

/* cnc_mdg_rdloadlvl:Reading of present value of disturbance level */
FWLIBAPI short WINAPI cnc_mdg_rdloadlvl(unsigned short, short, short, short, ODBLOAD*);

/* cnc_mdg_monistat:Reading of state of monitor information on alarm */
FWLIBAPI short WINAPI cnc_mdg_monistat(unsigned short, short*);

/* cnc_mdg_moniclear:Deletion of monitor information on alarm */
FWLIBAPI short WINAPI cnc_mdg_moniclear(unsigned short);

/* cnc_mdg_rdsysinfo:Reading of trouble diagnosis infomation */
FWLIBAPI short WINAPI cnc_mdg_rdsysinfo(unsigned short, short, long*);

/*-------------*/
/* CNC: Others */
/*-------------*/

/* read CNC system information */
FWLIBAPI short WINAPI cnc_sysinfo( unsigned short, ODBSYS * ) ;

/* read CNC status information */
FWLIBAPI short WINAPI cnc_statinfo( unsigned short, ODBST * ) ;

/* read CNC status information */
FWLIBAPI short WINAPI cnc_statinfo2( unsigned short, ODBST2 * ) ;

/* read axis status information */
FWLIBAPI short WINAPI cnc_rdmovestate( unsigned short, short, short *, unsigned char * ) ;

/* read DMG Netservice status information */
FWLIBAPI short WINAPI cnc_statinfo_dmg( unsigned short, OUT_STATINF_DMG * ) ;

/* read status + diagnosis data for ROBODRILL and TOYOTA  */
FWLIBAPI short WINAPI cnc_rdcmstatdata( unsigned short, unsigned long * ) ;

/* read alarm status */
FWLIBAPI short WINAPI cnc_alarm( unsigned short, ODBALM * ) ;

/* read alarm status */
FWLIBAPI short WINAPI cnc_alarm2( unsigned short, long * ) ;

/* clear alarm */
FWLIBAPI short WINAPI cnc_clearalm( unsigned short, short ) ;

/* read alarm information */
FWLIBAPI short WINAPI cnc_rdalminfo( unsigned short, short, short, short, ALMINFO * ) ;

/* read alarm information (2) */
FWLIBAPI short WINAPI cnc_rdalminfo2( unsigned short, short, short, short, ALMINFO2 * ) ;

/* read alarm message */
FWLIBAPI short WINAPI cnc_rdalmmsg( unsigned short, short, short *, ODBALMMSG * ) ;

/* read alarm message */
FWLIBAPI short WINAPI cnc_rdalmmsg2( unsigned short, short, short *, ODBALMMSG2 * ) ;

/* read alarm message */
FWLIBAPI short WINAPI cnc_rdalmmsg3( unsigned short, short, short *, ODBALMMSG3 * ) ;

/* clear CNC alarm */
FWLIBAPI short WINAPI cnc_clralm( unsigned short hndl, short id ) ;

/* read modal data */
FWLIBAPI short WINAPI cnc_modal( unsigned short, short, short, ODBMDL * ) ;

/* read canned command */
FWLIBAPI short WINAPI cnc_cannedcycle( unsigned short, ODBCANCMD * ) ;

/* read G code */
FWLIBAPI short WINAPI cnc_rdgcode( unsigned short, short, short, short *, ODBGCD * ) ;

/* read G code (m) */
FWLIBAPI short WINAPI cnc_rdgcodem( unsigned short, short, short, short *, ODBGCD * ) ;

/* block_status */
FWLIBAPI short WINAPI cnc_block_status( unsigned short, short*);

/* read command value */
FWLIBAPI short WINAPI cnc_rdcommand( unsigned short, short, short, short *, ODBCMD * ) ;

/* read diagnosis data */
FWLIBAPI short WINAPI cnc_diagnoss( unsigned short, short, short, short, ODBDGN * ) ;

/* read diagnosis data(area specified) */
FWLIBAPI short WINAPI cnc_diagnosr( unsigned short, short *, short, short *, short *, void * ) ;

/* read A/D conversion data */
FWLIBAPI short WINAPI cnc_adcnv( unsigned short, short, short, ODBAD * ) ;

/* read operator's message */
FWLIBAPI short WINAPI cnc_rdopmsg( unsigned short, short, short, OPMSG * ) ;

/* read operator's message */
FWLIBAPI short WINAPI cnc_rdopmsg2( unsigned short, short, short, OPMSG2 * ) ;

/* read operator's message */
FWLIBAPI short WINAPI cnc_rdopmsg3( unsigned short, short, short *, OPMSG3 * ) ;

/* read operator's message (m) */
FWLIBAPI short WINAPI cnc_rdopmsg3m( unsigned short, short, short *, OPMSG3 * ) ;

/* read operator's message on key-in line */
FWLIBAPI short WINAPI cnc_rdlnopmsg( unsigned short, char * ) ;

/* read operator message */
 FWLIBAPI short WINAPI cnc_rdopmsgmps( unsigned short, short, short *, OPMSGMPS * ) ;

/* set path number(for 4 axes lathes, multi-path) */
FWLIBAPI short WINAPI cnc_setpath( unsigned short, short ) ;

/* get path number(for 4 axes lathes, multi-path) */
FWLIBAPI short WINAPI cnc_getpath( unsigned short, short *, short * ) ;

/* allocate library handle */
FWLIBAPI short WINAPI cnc_allclibhndl( unsigned short * ) ;

/* free library handle */
FWLIBAPI short WINAPI cnc_freelibhndl( unsigned short ) ;

/* get library option */
FWLIBAPI short WINAPI cnc_getlibopt(unsigned short, long, char *, long *);

/* set library option */
FWLIBAPI short WINAPI cnc_setlibopt(unsigned short, long, char *, long);

/* get custom macro type */
FWLIBAPI short WINAPI cnc_getmactype( unsigned short, short * ) ;

/* set custom macro type */
FWLIBAPI short WINAPI cnc_setmactype( unsigned short, short ) ;

/* get P code macro type */
FWLIBAPI short WINAPI cnc_getpmactype( unsigned short, short * ) ;

/* set P code macro type */
FWLIBAPI short WINAPI cnc_setpmactype( unsigned short, short ) ;

/* get screen status */
FWLIBAPI short WINAPI cnc_getcrntscrn( unsigned short, short * ) ;

/* change screen mode */
FWLIBAPI short WINAPI cnc_slctscrn( unsigned short, short ) ;

/* read CNC configuration information */
FWLIBAPI short WINAPI cnc_sysconfig( unsigned short, ODBSYSC * ) ;

/* read program restart information */
FWLIBAPI short WINAPI cnc_rdprstrinfo( unsigned short, ODBPRS * ) ;

/* read program restart information */
FWLIBAPI short WINAPI cnc_rdprstrinfom( unsigned short, ODBPRSM * ) ;

/* search sequence number for program restart */
FWLIBAPI short WINAPI cnc_rstrseqsrch( unsigned short, long, long, short, short ) ;

/* search sequence number for program restart 2 */
FWLIBAPI short WINAPI cnc_rstrseqsrch2( unsigned short, long, long, short, short, long ) ;

/* read output signal image of software operator's panel  */
FWLIBAPI short WINAPI cnc_rdopnlsgnl( unsigned short, short, IODBSGNL * ) ;

/* write output signal of software operator's panel  */
FWLIBAPI short WINAPI cnc_wropnlsgnl( unsigned short, IODBSGNL * ) ;

/* read general signal image of software operator's panel  */
FWLIBAPI short WINAPI cnc_rdopnlgnrl( unsigned short, short, IODBGNRL * ) ;

/* write general signal image of software operator's panel  */
FWLIBAPI short WINAPI cnc_wropnlgnrl( unsigned short, IODBGNRL * ) ;

/* read general signal image of software operator's panel(2)  */
FWLIBAPI short WINAPI cnc_rdopnlgnrl2( unsigned short, short, IODBGNRL2 * ) ;

/* write general signal image of software operator's panel(2)  */
FWLIBAPI short WINAPI cnc_wropnlgnrl2( unsigned short, IODBGNRL2 * ) ;

/* read general signal name of software operator's panel  */
FWLIBAPI short WINAPI cnc_rdopnlgsname( unsigned short, short, IODBRDNA * ) ;

/* write general signal name of software operator's panel  */
FWLIBAPI short WINAPI cnc_wropnlgsname( unsigned short, IODBRDNA * ) ;

/* read general signal name of software operator's panel(2)  */
FWLIBAPI short WINAPI cnc_rdopnlgsname2( unsigned short, short, IODBRDNA2 * ) ;

/* write general signal name of software operator's panel(2)  */
FWLIBAPI short WINAPI cnc_wropnlgsname2( unsigned short, IODBRDNA2 * ) ;

/* get detail error */
FWLIBAPI short WINAPI cnc_getdtailerr( unsigned short, ODBERR * ) ;

/* get detail error(2) */
FWLIBAPI short WINAPI cnc_getdtailerr2( unsigned short, ODBERR * ) ;

/* read informations of CNC parameter */
FWLIBAPI short WINAPI cnc_rdparainfo( unsigned short, short, unsigned short, ODBPARAIF * ) ;

/* read informations of CNC setting data */
FWLIBAPI short WINAPI cnc_rdsetinfo( unsigned short, short, unsigned short, ODBSETIF * ) ;

/* read informations of CNC diagnose data */
FWLIBAPI short WINAPI cnc_rddiaginfo( unsigned short, short, unsigned short, ODBDIAGIF * ) ;

/* read informations of CNC parameter(2) */
FWLIBAPI short WINAPI cnc_rdparainfo2( unsigned short, short, short*, short*, short*, ODBPARAIF2 * ) ;

/* read informations of CNC parameter(3) */
FWLIBAPI short WINAPI cnc_rdparainfo3( unsigned short, short, short*, short*, short*, ODBPARAIF2 * ) ;

/* read informations of CNC setting data(2) */
FWLIBAPI short WINAPI cnc_rdsetinfo2( unsigned short, short, short*, short*, short*, ODBPARAIF2 * ) ;

/* read informations of CNC diagnose data(2) */
FWLIBAPI short WINAPI cnc_rddiaginfo2( unsigned short, short, short*, short*, short*, ODBPARAIF2 * ) ;

/* read maximum, minimum and total number of CNC parameter */
FWLIBAPI short WINAPI cnc_rdparanum( unsigned short, ODBPARANUM * ) ;

/* read maximum, minimum and total number of CNC setting data */
FWLIBAPI short WINAPI cnc_rdsetnum( unsigned short, ODBSETNUM * ) ;

/* read maximum, minimum and total number of CNC diagnose data */
FWLIBAPI short WINAPI cnc_rddiagnum( unsigned short, ODBDIAGNUM * ) ;

/* get maximum valid figures and number of decimal places */
FWLIBAPI short WINAPI cnc_getfigure( unsigned short, short, short *, short *, short * ) ;

/* read F-ROM information on CNC  */
FWLIBAPI short WINAPI cnc_rdfrominfo( unsigned short, short, ODBFINFO * ) ;

/* start of reading F-ROM data from CNC */
FWLIBAPI short WINAPI cnc_fromsvstart( unsigned short, short, char *, long ) ;

/* read F-ROM data from CNC */
FWLIBAPI short WINAPI cnc_fromsave( unsigned short, short *, void *, long * ) ;

/* end of reading F-ROM data from CNC */
FWLIBAPI short WINAPI cnc_fromsvend( unsigned short ) ;

/* start of writing F-ROM data to CNC */
FWLIBAPI short WINAPI cnc_fromldstart( unsigned short, short, long ) ;

/* write F-ROM data to CNC */
FWLIBAPI short WINAPI cnc_fromload( unsigned short, void *, long * ) ;

/* end of writing F-ROM data to CNC */
FWLIBAPI short WINAPI cnc_fromldend( unsigned short ) ;

/* delete F-ROM data on CNC */
FWLIBAPI short WINAPI cnc_fromdelete( unsigned short, short, char *, long ) ;

/* read S-RAM information on CNC */
FWLIBAPI short WINAPI cnc_rdsraminfo( unsigned short, ODBSINFO * ) ;

/* start of reading S-RAM data from CNC */
FWLIBAPI short WINAPI cnc_srambkstart( unsigned short, char *, long ) ;

/* read S-RAM data from CNC */
FWLIBAPI short WINAPI cnc_srambackup( unsigned short, short *, void *, long * ) ;

/* end of reading S-RAM data from CNC */
FWLIBAPI short WINAPI cnc_srambkend( unsigned short ) ;

#ifndef CNC_PPC
/* read F-ROM information on CNC  */
FWLIBAPI short WINAPI cnc_getfrominfo( unsigned short, short, short *, ODBFINFORM * ) ;

/* start of reading F-ROM data from CNC */
FWLIBAPI short WINAPI cnc_fromgetstart( unsigned short, short, char * ) ;

/* read F-ROM data from CNC */
FWLIBAPI short WINAPI cnc_fromget( unsigned short, short *, void *, long * ) ;

/* end of reading F-ROM data from CNC */
FWLIBAPI short WINAPI cnc_fromgetend( unsigned short ) ;

/* start of writing F-ROM data to CNC */
FWLIBAPI short WINAPI cnc_fromputstart( unsigned short, short ) ;

/* write F-ROM data to CNC */
FWLIBAPI short WINAPI cnc_fromput( unsigned short, void *, long * ) ;

/* end of writing F-ROM data to CNC */
FWLIBAPI short WINAPI cnc_fromputend( unsigned short ) ;

/* delete F-ROM data on CNC */
FWLIBAPI short WINAPI cnc_fromremove( unsigned short, short, char * ) ;

/* read S-RAM information on CNC */
FWLIBAPI short WINAPI cnc_getsraminfo( unsigned short, ODBSINFO * ) ;
#endif

/* start of reading S-RAM data from CNC */
FWLIBAPI short WINAPI cnc_sramgetstart( unsigned short, char * ) ;

#ifndef CNC_PPC
/* start of reading S-RAM data from CNC (2) */
FWLIBAPI short WINAPI cnc_sramgetstart2( unsigned short, char * ) ;
#endif

/* read S-RAM data from CNC */
FWLIBAPI short WINAPI cnc_sramget( unsigned short, short *, void *, long * ) ;

#ifndef CNC_PPC
/* read S-RAM data from CNC (2) */
FWLIBAPI short WINAPI cnc_sramget2( unsigned short, short *, void *, long * ) ;
#endif

/* end of reading S-RAM data from CNC */
FWLIBAPI short WINAPI cnc_sramgetend( unsigned short ) ;

#ifndef CNC_PPC
/* end of reading S-RAM data from CNC (2) */
FWLIBAPI short WINAPI cnc_sramgetend2( unsigned short ) ;

/* start of writing S-RAM data to CNC */
 FWLIBAPI short WINAPI cnc_sramputstart( unsigned short, char * ) ;

/* start of writing S-RAM data to CNC (2) */
 FWLIBAPI short WINAPI cnc_sramputstart2( unsigned short, char * ) ;

/* write S-RAM data to CNC */
 FWLIBAPI short WINAPI cnc_sramput( unsigned short, short *, void *, long * ) ;

/* write S-RAM data to CNC (2) */
 FWLIBAPI short WINAPI cnc_sramput2( unsigned short, short *, void *, long * ) ;

/* end of writing S-RAM data to CNC */
 FWLIBAPI short WINAPI cnc_sramputend( unsigned short ) ;

/* end of writing S-RAM data to CNC (2) */
 FWLIBAPI short WINAPI cnc_sramputend2( unsigned short ) ;
#endif

/* read number of S-RAM data kind on CNC */
FWLIBAPI short WINAPI cnc_rdsramnum( unsigned short, short * ) ;

/* read S-RAM data address information on CNC */
FWLIBAPI short WINAPI cnc_rdsramaddr( unsigned short, short *, SRAMADDR * ) ;

/* get current NC data protection information */
FWLIBAPI short WINAPI cnc_getlockstat( unsigned short, short, unsigned char * ) ;

/* change NC data protection status */
FWLIBAPI short WINAPI cnc_chgprotbit( unsigned short, short, unsigned char *, long ) ;

/* transfer a file from host computer to CNC by FTP */
FWLIBAPI short WINAPI cnc_dtsvftpget( unsigned short, char *, char * ) ;

/* transfer a file from CNC to host computer by FTP */
FWLIBAPI short WINAPI cnc_dtsvftpput( unsigned short, char *, char * ) ;

/* get transfer status for FTP */
FWLIBAPI short WINAPI cnc_dtsvftpstat( unsigned short ) ;

/* read file directory in Data Server */
FWLIBAPI short WINAPI cnc_dtsvrdpgdir( unsigned short, char *, short, ODBDSDIR * ) ;

/* delete files in Data Server */
FWLIBAPI short WINAPI cnc_dtsvdelete( unsigned short, char * ) ;

/* down load from CNC (transfer a file from CNC to MMC) */
FWLIBAPI short WINAPI cnc_dtsvdownload( unsigned short, char * ) ;

/* up load to CNC (transfer a file from MMC to CNC) */
FWLIBAPI short WINAPI cnc_dtsvupload( unsigned short, char * ) ;

/* close upload/download between Data Server and CNC */
FWLIBAPI short WINAPI cnc_dtsvcnclupdn( unsigned short ) ;

/* get transfer status for up/down load */
FWLIBAPI short WINAPI cnc_dtsvupdnstat( unsigned short ) ;

/* get file name for DNC operation in Data Server */
FWLIBAPI short WINAPI cnc_dtsvgetdncpg( unsigned short, char * ) ;

/* set program number of DNC oparation to CNC */
FWLIBAPI short WINAPI cnc_dtsvsetdncpg( unsigned short, char * ) ;

/* read setting data for Data Server */
FWLIBAPI short WINAPI cnc_dtsvrdset( unsigned short, IODBDSSET * ) ;

/* write setting data for Data Server */
FWLIBAPI short WINAPI cnc_dtsvwrset( unsigned short, IODBDSSET * ) ;

/* check hard disk in Data Server */
FWLIBAPI short WINAPI cnc_dtsvchkdsk( unsigned short ) ;

/* format hard disk in Data Server */
FWLIBAPI short WINAPI cnc_dtsvhdformat( unsigned short ) ;

/* save interface area in Data Server */
FWLIBAPI short WINAPI cnc_dtsvsavecram( unsigned short ) ;

/* get interface area in Data Server */
FWLIBAPI short WINAPI cnc_dtsvrdcram( unsigned short, long, long *, char * ) ;

/* read maintenance information for Data Server */
FWLIBAPI short WINAPI cnc_dtsvmntinfo( unsigned short, ODBDSMNT * ) ;

/* get Data Server mode */
FWLIBAPI short WINAPI cnc_dtsvgetmode( unsigned short, short * ) ;

/* set Data Server mode */
FWLIBAPI short WINAPI cnc_dtsvsetmode( unsigned short, short ) ;

/* read error message for Data Server */
FWLIBAPI short WINAPI cnc_dtsvrderrmsg( unsigned short, short, char * ) ;

/* transfar file from Pc to Data Server */
FWLIBAPI short WINAPI cnc_dtsvwrfile( unsigned short, char *, char *,short );

/* transfar file from Data Server to Pc */
FWLIBAPI short WINAPI cnc_dtsvrdfile( unsigned short, char *, char *,short );

/* read the loop gain for each axis */
FWLIBAPI short WINAPI cnc_rdloopgain( unsigned short, long * ) ;

/* read the actual current for each axis */
#if !defined (PMD)
FWLIBAPI short WINAPI cnc_rdcurrent( unsigned short, short * ) ;
#else
FWLIBAPI short WINAPI cnc_rdcurrent( unsigned short, long * ) ;
#endif

/* read the actual speed for each axis */
FWLIBAPI short WINAPI cnc_rdsrvspeed( unsigned short, long * ) ;

/* read the TSA data for each axis */
FWLIBAPI short WINAPI cnc_rdsrvtsa( unsigned short, short * ) ;

/* read the TCMD data for each axis */
FWLIBAPI short WINAPI cnc_rdsrvtcmd( unsigned short, short * ) ;

/* read the operation mode */
FWLIBAPI short WINAPI cnc_rdopmode( unsigned short, short * ) ;

/* read the position deviation S */
FWLIBAPI short WINAPI cnc_rdposerrs( unsigned short, long * ) ;

/* read the position deviation S1 and S2 */
FWLIBAPI short WINAPI cnc_rdposerrs2( unsigned short, ODBPSER * ) ;

/* read the position deviation Z in the rigid tap mode */
FWLIBAPI short WINAPI cnc_rdposerrz( unsigned short, long * ) ;

/* read the synchronous error in the synchronous control mode */
FWLIBAPI short WINAPI cnc_rdsynerrsy( unsigned short, long * ) ;

/* read the synchronous error in the rigid tap mode */
FWLIBAPI short WINAPI cnc_rdsynerrrg( unsigned short, long * ) ;

/* read the spindle alarm */
FWLIBAPI short WINAPI cnc_rdspdlalm( unsigned short, char * ) ;

/* read the control input signal */
FWLIBAPI short WINAPI cnc_rdctrldi( unsigned short, ODBSPDI * ) ;

/* read the control output signal */
FWLIBAPI short WINAPI cnc_rdctrldo( unsigned short, ODBSPDO * ) ;

/* read the number of controled spindle */
FWLIBAPI short WINAPI cnc_rdnspdl( unsigned short, short * ) ;

/* read Servo feedback multiplication data */
 FWLIBAPI short WINAPI cnc_rdsvfeedback(unsigned short, short, ODBSVFBACK * );

#ifndef CNC_PPC
/* read data from FANUC BUS */
FWLIBAPI short WINAPI cnc_rdfbusmem( unsigned short, short, short, long, long, void * ) ;

/* write data to FANUC BUS */
FWLIBAPI short WINAPI cnc_wrfbusmem( unsigned short, short, short, long, long, void * ) ;
#endif

/* read the parameter of wave diagnosis */
FWLIBAPI short WINAPI cnc_rdwaveprm( unsigned short, IODBWAVE * ) ;

/* write the parameter of wave diagnosis */
FWLIBAPI short WINAPI cnc_wrwaveprm( unsigned short, IODBWAVE * ) ;

/* read the parameter of wave diagnosis 2 */
FWLIBAPI short WINAPI cnc_rdwaveprm2( unsigned short, IODBWVPRM * ) ;

/* write the parameter of wave diagnosis 2 */
FWLIBAPI short WINAPI cnc_wrwaveprm2( unsigned short, IODBWVPRM * ) ;

/* read the parameter of wave diagnosis 3 */
FWLIBAPI short WINAPI cnc_rdwaveprm3( unsigned short, IODBWVPRM3 * ) ;

/* write the parameter of wave diagnosis 3 */
FWLIBAPI short WINAPI cnc_wrwaveprm3( unsigned short, IODBWVPRM3 * ) ;

/* start the sampling for wave diagnosis */
FWLIBAPI short WINAPI cnc_wavestart( unsigned short ) ;

/* stop the sampling for wave diagnosis */
FWLIBAPI short WINAPI cnc_wavestop( unsigned short ) ;

/* read the status of wave diagnosis */
FWLIBAPI short WINAPI cnc_wavestat( unsigned short, short * ) ;

/* read the data of wave diagnosis */
FWLIBAPI short WINAPI cnc_rdwavedata( unsigned short, short, short, long, long *, ODBWVDT * ) ;
FWLIBAPI short WINAPI cnc_rdwavedata3( unsigned short, short, long, long *, ODBWVDT3 * ) ;
/* read the count of wave diagnosis */
FWLIBAPI short WINAPI cnc_rdwavecount( unsigned short, short, long * ) ;

/* read the data of wave diagnosis 2 */
FWLIBAPI short WINAPI cnc_rdwavedata2( unsigned short, short, long, long *, ODBWVDT2 * ) ;

/* read the parameter of wave diagnosis for remort diagnosis */
FWLIBAPI short WINAPI cnc_rdrmtwaveprm( unsigned short, IODBRMTPRM *, short ) ;

/* write the parameter of wave diagnosis for remort diagnosis */
FWLIBAPI short WINAPI cnc_wrrmtwaveprm( unsigned short, IODBRMTPRM * ) ;

/* start the sampling for wave diagnosis for remort diagnosis */
FWLIBAPI short WINAPI cnc_rmtwavestart( unsigned short ) ;

/* stop the sampling for wave diagnosis for remort diagnosis */
FWLIBAPI short WINAPI cnc_rmtwavestop( unsigned short ) ;

/* read the status of wave diagnosis for remort diagnosis*/
FWLIBAPI short WINAPI cnc_rmtwavestat( unsigned short, short * ) ;

/* read the data of wave diagnosis for remort diagnosis */
FWLIBAPI short WINAPI cnc_rdrmtwavedt( unsigned short, short, long, long *, ODBRMTDT * ) ;

/* read of address for PMC signal batch save */
FWLIBAPI short WINAPI cnc_rdsavsigadr( unsigned short, IODBSIGAD *, short ) ;

/* write of address for PMC signal batch save */
FWLIBAPI short WINAPI cnc_wrsavsigadr( unsigned short, IODBSIGAD *, short * ) ;

/* read of data for PMC signal batch save */
FWLIBAPI short WINAPI cnc_rdsavsigdata( unsigned short, short, short, void *, short * ) ;

/* read M-code group data */
FWLIBAPI short WINAPI cnc_rdmgrpdata( unsigned short, short, short *, ODBMGRP * ) ;

/* write M-code group data */
FWLIBAPI short WINAPI cnc_wrmgrpdata( unsigned short, IDBMGRP * ) ;

#ifndef CNC_PPC
/* read executing M-code group data */
FWLIBAPI short WINAPI cnc_rdexecmcode( unsigned short, short, short *, ODBEXEM * );

/* read program restart M-code group data */
FWLIBAPI short WINAPI cnc_rdrstrmcode( unsigned short, short, short *, ODBRSTRM * );
#endif

/* read processing time stamp data */
FWLIBAPI short WINAPI cnc_rdproctime( unsigned short, ODBPTIME * ) ;

FWLIBAPI short WINAPI cnc_rdproctime3( unsigned short, char *, ODBPTIME3 * );

/* read MDI program stat */
FWLIBAPI short WINAPI cnc_rdmdiprgstat( unsigned short, unsigned short * );

/* read program directory for processing time data */
FWLIBAPI short WINAPI cnc_rdprgdirtime( unsigned short, long *, short *, PRGDIRTM * ) ;

/* read program directory 2 */
FWLIBAPI short WINAPI cnc_rdprogdir2( unsigned short, short, short *, short *, PRGDIR2 * ) ;

/* read program directory 3 */
FWLIBAPI short WINAPI cnc_rdprogdir3( unsigned short, short, long *, short *, PRGDIR3 * ) ;

/* read program directory 4 */
FWLIBAPI short WINAPI cnc_rdprogdir4( unsigned short, short, long, short *, PRGDIR4 * ) ;

/* read program directory 4 for wire cut */
FWLIBAPI short WINAPI cnc_rdprogdir4_w( unsigned short, short, short, short, short, short *, PRGDIR3 * );

/* read DNC file name for DNC1, DNC2, OSI-Ethernet */
FWLIBAPI short WINAPI cnc_rddncfname( unsigned short, char * ) ;

/* write DNC file name for DNC1, DNC2, OSI-Ethernet */
FWLIBAPI short WINAPI cnc_wrdncfname( unsigned short, char * ) ;

/* read communication parameter for DNC1, DNC2, OSI-Ethernet */
FWLIBAPI short WINAPI cnc_rdcomparam( unsigned short, IODBCPRM * ) ;

/* write communication parameter for DNC1, DNC2, OSI-Ethernet */
FWLIBAPI short WINAPI cnc_wrcomparam( unsigned short, IODBCPRM * ) ;

/* read log message for DNC2 */
FWLIBAPI short WINAPI cnc_rdcomlogmsg( unsigned short, char * ) ;

/* read operator message for DNC1, DNC2 */
FWLIBAPI short WINAPI cnc_rdcomopemsg( unsigned short, char * ) ;

/* read recieve message for OSI-Ethernet */
FWLIBAPI short WINAPI cnc_rdrcvmsg( unsigned short, char * ) ;

/* read send message for OSI-Ethernet */
FWLIBAPI short WINAPI cnc_rdsndmsg( unsigned short, char * ) ;

/* send message for OSI-Ethernet */
FWLIBAPI short WINAPI cnc_sendmessage( unsigned short, char * ) ;

/* clear message buffer for OSI-Ethernet */
FWLIBAPI short WINAPI cnc_clrmsgbuff( unsigned short, short ) ;

/* read message recieve status for OSI-Ethernet */
FWLIBAPI short WINAPI cnc_rdrcvstat( unsigned short, unsigned short * ) ;

/* read interference check */
FWLIBAPI short WINAPI cnc_rdintchk( unsigned short, short, short, short, short, IODBINT * ) ;

/* write interference check */
FWLIBAPI short WINAPI cnc_wrintchk( unsigned short, short, IODBINT * ) ;

/* read interference check information */
FWLIBAPI short WINAPI cnc_rdintinfo( unsigned short, short * ) ;

/* read work coordinate shift */
FWLIBAPI short WINAPI cnc_rdwkcdshft( unsigned short, short, short, IODBWCSF * ) ;

/* write work coordinate shift */
FWLIBAPI short WINAPI cnc_wrwkcdshft( unsigned short, short, IODBWCSF * ) ;

/* read work coordinate shift measure */
FWLIBAPI short WINAPI cnc_rdwkcdsfms( unsigned short, short, short, IODBWCSF * ) ;

/* write work coordinate shift measure */
FWLIBAPI short WINAPI cnc_wrwkcdsfms( unsigned short, short, IODBWCSF * ) ;

/* read work coordinate shift2 */
FWLIBAPI short WINAPI cnc_rdwkcdshft2(unsigned short, short, short, unsigned short, IODBWCSF *);

/* write work coordinate shift2 */
FWLIBAPI short WINAPI cnc_wrwkcdshft2(unsigned short, unsigned short, short, IODBWCSF *);

/* read work coordinate shift measure2 */
FWLIBAPI short WINAPI cnc_rdwkcdsfms2(unsigned short, short, short, unsigned short, IODBWCSF *);

/* write work coordinate shift measure2 */
FWLIBAPI short WINAPI cnc_wrwkcdsfms2(unsigned short, unsigned short, short, IODBWCSF *);

/* read work coordinate shift3 */
FWLIBAPI short WINAPI cnc_rdwkcdshft3(unsigned short, short, short, short, IODBWCSF *);

/* write work coordinate shift3 */
FWLIBAPI short WINAPI cnc_wrwkcdshft3(unsigned short, short, short, IODBWCSF *);

/* read work coordinate shift measure3 */
FWLIBAPI short WINAPI cnc_rdwkcdsfms3(unsigned short, short, short, short, IODBWCSF *);

/* write work coordinate shift measure3 */
FWLIBAPI short WINAPI cnc_wrwkcdsfms3(unsigned short, short, short, IODBWCSF *);

/* stop the sampling for operator message history */
FWLIBAPI short WINAPI cnc_stopomhis( unsigned short ) ;

/* start the sampling for operator message history */
FWLIBAPI short WINAPI cnc_startomhis( unsigned short ) ;

/* read operator message history information */
FWLIBAPI short WINAPI cnc_rdomhisinfo( unsigned short, ODBOMIF * ) ;

/* read operator message history */
FWLIBAPI short WINAPI cnc_rdomhistry( unsigned short, unsigned short, unsigned short *, ODBOMHIS * ) ;

/* clear operator message history */
FWLIBAPI short WINAPI cnc_clearomhis( unsigned short ) ;

/* read b-axis tool offset value(area specified) */
FWLIBAPI short WINAPI cnc_rdbtofsr( unsigned short, short, short, short, short, IODBBTO * ) ;

/* write b-axis tool offset value(area specified) */
FWLIBAPI short WINAPI cnc_wrbtofsr( unsigned short, short, IODBBTO * ) ;

/* read b-axis tool offset information */
FWLIBAPI short WINAPI cnc_rdbtofsinfo( unsigned short, ODBBTLINF * ) ;

/* read b-axis command */
FWLIBAPI short WINAPI cnc_rdbaxis( unsigned short, ODBBAXIS * ) ;

/* read CNC system soft series and version */
FWLIBAPI short WINAPI cnc_rdsyssoft( unsigned short, ODBSYSS * ) ;

/* read CNC system soft series and version (2) */
FWLIBAPI short WINAPI cnc_rdsyssoft2( unsigned short, ODBSYSS2 * ) ;

/* read CNC module configuration information */
FWLIBAPI short WINAPI cnc_rdmdlconfig( unsigned short, ODBMDLC * ) ;

/* read CNC module configuration information 2 */
FWLIBAPI short WINAPI cnc_rdmdlconfig2( unsigned short, char * ) ;

/* read processing condition file (processing data) */
FWLIBAPI short WINAPI cnc_rdpscdproc( unsigned short, short, short *, IODBPSCD * ) ;

/* write processing condition file (processing data) */
FWLIBAPI short WINAPI cnc_wrpscdproc( unsigned short, short, short *, IODBPSCD * ) ;

/* read processing condition file (processing data) */
FWLIBAPI short WINAPI cnc_rdpscdproc2( unsigned short, short, short *, IODBPSCD2 * ) ;

/* write processing condition file (processing data) */
FWLIBAPI short WINAPI cnc_wrpscdproc2( unsigned short, short, short *, IODBPSCD2 * ) ;

/* read processing condition file (piercing data) */
FWLIBAPI short WINAPI cnc_rdpscdpirc( unsigned short, short, short *, IODBPIRC * ) ;

/* write processing condition file (piercing data) */
FWLIBAPI short WINAPI cnc_wrpscdpirc( unsigned short, short, short *, IODBPIRC * ) ;

/* read processing condition file (edging data) */
FWLIBAPI short WINAPI cnc_rdpscdedge( unsigned short, short, short *, IODBEDGE * ) ;

/* write processing condition file (edging data) */
FWLIBAPI short WINAPI cnc_wrpscdedge( unsigned short, short, short *, IODBEDGE * ) ;

/* read processing condition file (slope data) */
FWLIBAPI short WINAPI cnc_rdpscdslop( unsigned short, short, short *, IODBSLOP * ) ;

/* write processing condition file (slope data) */
FWLIBAPI short WINAPI cnc_wrpscdslop( unsigned short, short, short *, IODBSLOP * ) ;

/* read power controll duty data */
FWLIBAPI short WINAPI cnc_rdlpwrdty( unsigned short, IODBLPWDT * ) ;

/* write power controll duty data */
FWLIBAPI short WINAPI cnc_wrlpwrdty( unsigned short, IODBLPWDT * ) ;

/* read laser power data */
FWLIBAPI short WINAPI cnc_rdlpwrdat( unsigned short, ODBLOPDT * ) ;

/* read power complement */
FWLIBAPI short WINAPI cnc_rdlpwrcpst( unsigned short, short * ) ;

/* write power complement */
FWLIBAPI short WINAPI cnc_wrlpwrcpst( unsigned short, short ) ;

/* read laser assist gas selection */
FWLIBAPI short WINAPI cnc_rdlagslt( unsigned short, IODBLAGSL * ) ;

/* write laser assist gas selection */
FWLIBAPI short WINAPI cnc_wrlagslt( unsigned short, IODBLAGSL * ) ;

/* read laser assist gas flow */
FWLIBAPI short WINAPI cnc_rdlagst( unsigned short, IODBLAGST * ) ;

/* write laser assist gas flow */
FWLIBAPI short WINAPI cnc_wrlagst( unsigned short, IODBLAGST * ) ;

/* read laser power for edge processing */
FWLIBAPI short WINAPI cnc_rdledgprc( unsigned short, IODBLEGPR * ) ;

/* write laser power for edge processing */
FWLIBAPI short WINAPI cnc_wrledgprc( unsigned short, IODBLEGPR * ) ;

/* read laser power for piercing */
FWLIBAPI short WINAPI cnc_rdlprcprc( unsigned short, IODBLPCPR * ) ;

/* write laser power for piercing */
FWLIBAPI short WINAPI cnc_wrlprcprc( unsigned short, IODBLPCPR * ) ;

/* read laser command data */
FWLIBAPI short WINAPI cnc_rdlcmddat( unsigned short, ODBLCMDT * ) ;

/* read displacement */
FWLIBAPI short WINAPI cnc_rdldsplc( unsigned short, short * ) ;

/* write displacement */
FWLIBAPI short WINAPI cnc_wrldsplc( unsigned short, short ) ;

/* read error for axis z */
FWLIBAPI short WINAPI cnc_rdlerrz( unsigned short, short * ) ;

/* read active number */
FWLIBAPI short WINAPI cnc_rdlactnum( unsigned short, ODBLACTN * ) ;

/* read laser comment */
FWLIBAPI short WINAPI cnc_rdlcmmt( unsigned short, ODBLCMMT * ) ;

/* read laser power select */
FWLIBAPI short WINAPI cnc_rdlpwrslt( unsigned short, short * ) ;

/* write laser power select */
FWLIBAPI short WINAPI cnc_wrlpwrslt( unsigned short, short ) ;

/* read laser power controll */
FWLIBAPI short WINAPI cnc_rdlpwrctrl( unsigned short, short * ) ;

/* write laser power controll */
FWLIBAPI short WINAPI cnc_wrlpwrctrl( unsigned short, short ) ;

/* read power correction factor history data */
FWLIBAPI short WINAPI cnc_rdpwofsthis( unsigned short, long, long *, ODBPWOFST * ) ;

/* read management time */
FWLIBAPI short WINAPI cnc_rdmngtime( unsigned short, long, long *, IODBMNGTIME * ) ;

/* write management time */
FWLIBAPI short WINAPI cnc_wrmngtime( unsigned short, long, IODBMNGTIME * ) ;

/* read data related to electrical discharge at power correction ends */
FWLIBAPI short WINAPI cnc_rddischarge( unsigned short, ODBDISCHRG * ) ;

/* read alarm history data related to electrical discharg */
FWLIBAPI short WINAPI cnc_rddischrgalm( unsigned short, long, long *, ODBDISCHRGALM * ) ;

/* read power feedback data */
 FWLIBAPI short WINAPI cnc_rdlppfbdt( unsigned short, IDBLPPFBFG *, short *, IODBLPPFBDT * );

/* write power feedback data */
 FWLIBAPI short WINAPI cnc_wrlppfbdt( unsigned short, IDBLPPFBFG *, short *, IODBLPPFBDT * );

/* get date and time from cnc */
FWLIBAPI short WINAPI cnc_gettimer( unsigned short, IODBTIMER * ) ;

/* set date and time for cnc */
FWLIBAPI short WINAPI cnc_settimer( unsigned short, IODBTIMER * ) ;

/* read timer data from cnc */
FWLIBAPI short WINAPI cnc_rdtimer( unsigned short, short, IODBTIME * ) ;

/* write timer data for cnc */
FWLIBAPI short WINAPI cnc_wrtimer( unsigned short, short, IODBTIME * ) ;

/* read tool controll data */
FWLIBAPI short WINAPI cnc_rdtlctldata( unsigned short, IODBTLCTL * ) ;

/* write tool controll data */
FWLIBAPI short WINAPI cnc_wrtlctldata( unsigned short, IODBTLCTL * ) ;

/* read tool data */
FWLIBAPI short WINAPI cnc_rdtooldata( unsigned short, short, short *, IODBTLDT * ) ;

/* read tool data */
FWLIBAPI short WINAPI cnc_wrtooldata( unsigned short, short, short *, IODBTLDT * ) ;

/* read multi tool data */
FWLIBAPI short WINAPI cnc_rdmultitldt( unsigned short, short, short *, IODBMLTTL * ) ;

/* write multi tool data */
FWLIBAPI short WINAPI cnc_wrmultitldt( unsigned short, short, short *, IODBMLTTL * ) ;

/* read multi tap data */
FWLIBAPI short WINAPI cnc_rdmtapdata( unsigned short, short, short *, IODBMTAP * ) ;

/* write multi tap data */
FWLIBAPI short WINAPI cnc_wrmtapdata( unsigned short, short, short *, IODBMTAP * ) ;

/* read multi-piece machining number */
 FWLIBAPI short WINAPI cnc_rdmultipieceno( unsigned short, long * );

/* read tool information */
FWLIBAPI short WINAPI cnc_rdtoolinfo( unsigned short, ODBPTLINF * ) ;

/* read safetyzone data */
FWLIBAPI short WINAPI cnc_rdsafetyzone( unsigned short, short, short *, IODBSAFE * ) ;

/* write safetyzone data */
FWLIBAPI short WINAPI cnc_wrsafetyzone( unsigned short, short, short *, IODBSAFE * ) ;

/* read toolzone data */
FWLIBAPI short WINAPI cnc_rdtoolzone( unsigned short, short, short *, IODBTLZN * ) ;

/* write toolzone data */
FWLIBAPI short WINAPI cnc_wrtoolzone( unsigned short, short, short *, IODBTLZN * ) ;

/* read active toolzone data */
FWLIBAPI short WINAPI cnc_rdacttlzone( unsigned short, ODBACTTLZN * ) ;

/* read setzone number */
FWLIBAPI short WINAPI cnc_rdsetzone( unsigned short, short * ) ;

/* write setzone number */
FWLIBAPI short WINAPI cnc_wrsetzone( unsigned short, short ) ;

/* read block restart information */
FWLIBAPI short WINAPI cnc_rdbrstrinfo( unsigned short, ODBBRS * ) ;

/* read menu switch signal */
FWLIBAPI short WINAPI cnc_rdmenuswitch( unsigned short, short * ) ;

/* write menu switch signal */
FWLIBAPI short WINAPI cnc_wrmenuswitch( unsigned short, short, short ) ;

/* read tool radius offset for position data */
FWLIBAPI short WINAPI cnc_rdradofs( unsigned short, ODBROFS * ) ;

/* read tool length offset for position data */
FWLIBAPI short WINAPI cnc_rdlenofs( unsigned short, ODBLOFS * ) ;

/* read fixed cycle for position data */
FWLIBAPI short WINAPI cnc_rdfixcycle( unsigned short, ODBFIX * ) ;

/* read coordinate rotate for position data */
FWLIBAPI short WINAPI cnc_rdcdrotate( unsigned short, ODBROT * ) ;

/* read 3D coordinate convert for position data */
FWLIBAPI short WINAPI cnc_rd3dcdcnv( unsigned short, ODB3DCD * ) ;

/* read programable mirror image for position data */
FWLIBAPI short WINAPI cnc_rdmirimage( unsigned short, ODBMIR * ) ;

/* read scaling for position data */
FWLIBAPI short WINAPI cnc_rdscaling( unsigned short, ODBSCL * ) ;

/* read 3D tool offset for position data */
FWLIBAPI short WINAPI cnc_rd3dtofs( unsigned short, ODB3DTO * ) ;

/* read tool position offset for position data */
FWLIBAPI short WINAPI cnc_rdposofs( unsigned short, ODBPOFS * ) ;

/* read hpcc setting data */
FWLIBAPI short WINAPI cnc_rdhpccset( unsigned short, IODBHPST * ) ;

/* write hpcc setting data */
FWLIBAPI short WINAPI cnc_wrhpccset( unsigned short, IODBHPST * ) ;

/* hpcc data auto setting data */
FWLIBAPI short WINAPI cnc_hpccatset( unsigned short ) ;

/* read hpcc tuning data ( parameter input ) */
FWLIBAPI short WINAPI cnc_rdhpcctupr( unsigned short, IODBHPPR * ) ;

/* write hpcc tuning data ( parameter input ) */
FWLIBAPI short WINAPI cnc_wrhpcctupr( unsigned short, IODBHPPR * ) ;

/* read hpcc tuning data ( acc input ) */
FWLIBAPI short WINAPI cnc_rdhpcctuac( unsigned short, IODBHPAC * ) ;

/* write hpcc tuning data ( acc input ) */
FWLIBAPI short WINAPI cnc_wrhpcctuac( unsigned short, IODBHPAC * ) ;

/* hpcc data auto tuning */
FWLIBAPI short WINAPI cnc_hpccattune( unsigned short, short, short * ) ;

/* read hpcc fine level */
FWLIBAPI short WINAPI cnc_hpccactfine( unsigned short, short * ) ;

/* select hpcc fine level */
FWLIBAPI short WINAPI cnc_hpccselfine( unsigned short, short ) ;

/* read rotary table dynamic fixture offset */
 FWLIBAPI short WINAPI cnc_rdfixoffs( unsigned short, short, short, ODBFOFS * ) ;

/* write rotary table dynamic fixture offset */
 FWLIBAPI short WINAPI cnc_wrfixoffs( unsigned short, short, short, ODBFOFS * ) ;

/* read active fixture offset */
FWLIBAPI short WINAPI cnc_rdactfixofs( unsigned short, short, IODBZOFS * ) ;

/* read fixture offset */
FWLIBAPI short WINAPI cnc_rdfixofs( unsigned short, short, short, short, short, IODBZOR * ) ;

/* write fixture offset */
FWLIBAPI short WINAPI cnc_wrfixofs( unsigned short, short, IODBZOR * ) ;

/* read active dynamic offset */
FWLIBAPI short WINAPI cnc_rdactdofs( unsigned short, short, IODBZOFS * ) ;

/* read dynamic offset */
FWLIBAPI short WINAPI cnc_rddofs( unsigned short, short, short, short, short, IODBZOR * ) ;

/* write dynamic offset */
FWLIBAPI short WINAPI cnc_wrdofs( unsigned short, short, IODBZOR * ) ;

/* auto set the machining condition */
 FWLIBAPI short WINAPI cnc_cdautoset( unsigned short, short, short ) ;

/* read the machining condition parameters */
 FWLIBAPI short WINAPI cnc_rdcdslctprm( unsigned short, short, unsigned short *, IODBCTPR * ) ;

/* read the machining condition parameters */
FWLIBAPI short WINAPI cnc_rdcdslctprmm( unsigned short, short, unsigned short *, IODBCTPRM * ) ;

/* Read manual numeric command */
FWLIBAPI short WINAPI cnc_rdjogmdi( unsigned short, ODBJOGCMD *code );

/* Write manual numeric command */
FWLIBAPI short WINAPI cnc_wrjogmdi( unsigned short, char * );

/* Clear manual numeric command */
FWLIBAPI short WINAPI cnc_wrjogmdiclr( unsigned short );

/* read tip of tool for 3D handle */
FWLIBAPI short WINAPI cnc_rd3dtooltip( unsigned short, ODB3DHDL * ) ;

/* read tip of 5 axis manufacture send handle */
FWLIBAPI short WINAPI cnc_rd5dtooltip( unsigned short, short *, ODB5DHDL * ) ;

/* read machine move of 5 axis manufacture send handle */
FWLIBAPI short WINAPI cnc_rd5dmacmov( unsigned short, short *, ODB5DHDL * ) ;

/* read pulse of 5 axis manufacture send handle */
FWLIBAPI short WINAPI cnc_rd5dpulse( unsigned short, short, short *, ODB5DPLS * );

/* clear pulse of 5 axis manufacture send handle */
FWLIBAPI short WINAPI cnc_clr5dplsmov( unsigned short, short ) ;

/* read pulse for 3D handle */
FWLIBAPI short WINAPI cnc_rd3dpulse( unsigned short, ODB3DPLS * ) ;

/* read move overrlap of tool for 3D handle */
FWLIBAPI short WINAPI cnc_rd3dmovrlap( unsigned short, ODB3DHDL * ) ;

/* read change offset for 3D handle */
FWLIBAPI short WINAPI cnc_rd3dofschg( unsigned short, long * ) ;

/* clear pulse and change offset for 3D handle */
FWLIBAPI short WINAPI cnc_clr3dplsmov( unsigned short, short ) ;

/* cycle start */
FWLIBAPI short WINAPI cnc_start( unsigned short );

/* reset CNC */
FWLIBAPI short WINAPI cnc_reset( unsigned short );

/* reset CNC 2 */
FWLIBAPI short WINAPI cnc_reset2( unsigned short );

/* Display of optional message */
FWLIBAPI short WINAPI cnc_dispoptmsg( unsigned short, char * );

/* Reading of answer for optional message display */
FWLIBAPI short WINAPI cnc_optmsgans( unsigned short, short * );

/* Get CNC Model */
FWLIBAPI short WINAPI cnc_getcncmodel( unsigned short, short * );

/* read axis name */
FWLIBAPI short WINAPI cnc_rdaxisname( unsigned short, short *, ODBAXISNAME *);

/* read spindle name */
FWLIBAPI short WINAPI cnc_rdspdlname( unsigned short, short *, ODBSPDLNAME *);

/* read spindle name(m) */
FWLIBAPI short WINAPI cnc_rdspdlnamem( unsigned short, short *, ODBSPDLNAME *);

#ifndef CNC_PPC
/* read extended axis name */
FWLIBAPI short WINAPI cnc_exaxisname( unsigned short, short, short *, char (*)[MAX_AXISNAME] );
#endif

/* read extended axis name */
FWLIBAPI short WINAPI cnc_exaxisname2( unsigned short, short, short, short *, char (*)[MAX_AXISNAME] );

/* read relative axis */
FWLIBAPI short WINAPI cnc_rdrelaxis( unsigned short, short, short, short *, ODBRELAXIS *);

/* read absolute axis */
FWLIBAPI short WINAPI cnc_rdabsaxis( unsigned short, short, short, short, short *, short *);

/* read axis num */
FWLIBAPI short WINAPI cnc_axisnum( unsigned short, short, short * );

/* read axis num */
FWLIBAPI short WINAPI cnc_axisnum2( unsigned short, short, short, short * );

/* read SRAM variable area for C language executor */
FWLIBAPI short WINAPI cnc_rdcexesram( unsigned short, long, void *, long * );

#ifndef CNC_PPC
/* write SRAM variable area for C language executor */
FWLIBAPI short WINAPI cnc_wrcexesram( unsigned short, long, void *, long * );
#endif

/* read maximum size and linear address of SRAM variable area for C language executor */
FWLIBAPI short WINAPI cnc_cexesraminfo( unsigned short, short *, long *, long * );

#ifndef CNC_PPC
/* read maximum size of SRAM variable area for C language executor */
FWLIBAPI short WINAPI cnc_cexesramsize( unsigned short, long * );
#endif

/* Get load torque data of FANUC Auto HMI/T */
FWLIBAPI short WINAPI cnc_rdtrqmonitor( unsigned short, long, void *, long * );

/* read additional workpiece coordinate systems number */
FWLIBAPI short WINAPI cnc_rdcoordnum( unsigned short, short * );

/* converts from FANUC code to Shift JIS code */
FWLIBAPI short WINAPI cnc_ftosjis( unsigned short, char *, char * );

/* Set the unsolicited message parameters */
FWLIBAPI short WINAPI cnc_wrunsolicprm( unsigned short FlibHndl, short number, IODBUNSOLIC *data );

/* Get the unsolicited message parameters */
FWLIBAPI short WINAPI cnc_rdunsolicprm( unsigned short FlibHndl, short number, IODBUNSOLIC *data );

/* Set the unsolicited message parameters(2) */
FWLIBAPI short WINAPI cnc_wrunsolicprm2( unsigned short FlibHndl, short number, IODBUNSOLIC2 *data );

/* Get the unsolicited message parameters(2) */
FWLIBAPI short WINAPI cnc_rdunsolicprm2( unsigned short FlibHndl, short number, IODBUNSOLIC2 *data );

/* Start of unsolicited message */
FWLIBAPI short WINAPI cnc_unsolicstart( unsigned short FlibHndl, short number, HWND hWnd, unsigned long msgno, short chkalive, short *bill );

/* End of unsolicited message */
FWLIBAPI short WINAPI cnc_unsolicstop( unsigned short FlibHndl, short number );

/* Reads the unsolicited message data */
FWLIBAPI short WINAPI cnc_rdunsolicmsg( short bill, IDBUNSOLICMSG *data );

/* Reads the unsolicited message data(2) */
FWLIBAPI short WINAPI cnc_rdunsolicmsg2( short bill, IDBUNSOLICMSG2 *data2 );

/* Set torque limit data */
FWLIBAPI short WINAPI cnc_wrtrqlimit( unsigned short, short, IDBTRQ * );

/* Fine toruqe senshing from save */
FWLIBAPI short WINAPI cnc_ftrq_from_save( unsigned short );

/* Fine toruqe senshing from load */
FWLIBAPI short WINAPI cnc_ftrq_from_load( unsigned short );

/* Fine toruqe sensing from copy */
FWLIBAPI short WINAPI cnc_ftrq_data_copy( unsigned short );

/* Get setting information of "Fine toruqe sensing function" */
FWLIBAPI short WINAPI cnc_rdftrq_info( unsigned short, short, ODBP_FTRQ_PRM_INF * );

/* Get stored data count of "Fine toruqe sensing function" */
FWLIBAPI short WINAPI cnc_rdftrq_storecount( unsigned short, short, long* );

/* Get stored data of "Fine toruqe sensing function" */
FWLIBAPI short WINAPI cnc_rdftrq_data( unsigned short, short, long, short*, unsigned long * );


/* embetb_rdparam_w:read embedded ethernet parameter for FS160is/180is-WB */
FWLIBAPI short WINAPI embetb_rdparam_w( unsigned short, short, IODBEMBETHPRMW * );

/* embetb_wrparam_w:write embedded ethernet parameter for FS160is/180is-WB */
FWLIBAPI short WINAPI embetb_wrparam_w( unsigned short, short, IODBEMBETHPRMW * );

/* read machine specific maintenance item */
FWLIBAPI short WINAPI cnc_rdpm_mcnitem( unsigned short, short, short *, char (*)[62] );

/* write machine specific maintenance item */
FWLIBAPI short WINAPI cnc_wrpm_mcnitem( unsigned short, short, short, char (*)[62] );

/* read cnc maintenance item */
FWLIBAPI short WINAPI cnc_rdpm_cncitem( unsigned short, short, short *, char (*)[62]);

/* read maintenance item status */
FWLIBAPI short WINAPI cnc_rdpm_item( unsigned short, short, short *, IODBPMAINTE * );

/* write maintenance item status */
FWLIBAPI short WINAPI cnc_wrpm_item( unsigned short, short, short, short, IODBPMAINTE * );

/* read CNC memory */
FWLIBAPI short WINAPI cnc_rdcncmem( unsigned short, short, unsigned long, unsigned long, void* );

/* write CNC memory */
FWLIBAPI short WINAPI cnc_wrcncmem( unsigned short, short, unsigned long, unsigned long, void* );

/* read current operation level */
FWLIBAPI short WINAPI cnc_rdope_lvl( unsigned short, short * );

/* set password for operation level */
FWLIBAPI short WINAPI cnc_prot_pswinp( unsigned short, char * );

/* cancel password for operation level */
FWLIBAPI short WINAPI cnc_prot_pswcan( unsigned short );

/* change password for operation level */
FWLIBAPI short WINAPI cnc_prot_pswchg( unsigned short, short , char *, char *, char * );

/* initialize password for operation level */
FWLIBAPI short WINAPI cnc_prot_pswinit( unsigned short, short );

/* read protection level to modify and output */
FWLIBAPI short WINAPI cnc_rdprt_lvl( unsigned short, short, short *, short * );

/* set protection level to modify and output */
FWLIBAPI short WINAPI cnc_wrprt_lvl( unsigned short, short, short, short );

/* check protection state to modify and output */
FWLIBAPI short WINAPI cnc_rdprt_data( unsigned short, short, short * );

/* Read information of File SRAM */
FWLIBAPI short WINAPI cnc_rdfsraminfo( unsigned short, unsigned long, ODBSRAMIF * );
FWLIBAPI short WINAPI cnc_rdfsraminfo2( unsigned short, unsigned long, ODBSRAMIF2 * );

/* Read File SRAM */
FWLIBAPI short WINAPI cnc_rdfile_sram( unsigned short, unsigned long, unsigned long, long, char * );

/* Write File SRAM */
FWLIBAPI short WINAPI cnc_wrfile_sram( unsigned short, unsigned long, unsigned long, long, char * );

/* Request alarm of "Power must be off" */
FWLIBAPI short WINAPI cnc_pwoff_alarm( unsigned short );

FWLIBAPI short WINAPI cnc_req_alarm(unsigned short FlibHndl, short alm_grp, short alm_num);

/* Set Parameter Execute Value */
FWLIBAPI short WINAPI cnc_set_cutcnd_exval( unsigned short );

/* Language Change */
FWLIBAPI short WINAPI cnc_chglang( unsigned short, char );

/* set touch panel mode */
FWLIBAPI short WINAPI cnc_settpnlcalib( unsigned short, short );

/* Get touch panel status & point */
FWLIBAPI short WINAPI cnc_tpl_read( unsigned short FlibHndl, ODBTPNLINTF *data );

/* Get next axis distance */
FWLIBAPI short WINAPI cnc_nextdistance( unsigned short, short, short, IODBAXIS * );

/* Get distribute infomation */
FWLIBAPI short WINAPI cnc_rdipltp( unsigned short, ODBIPL *buf );

/* read CNC system soft series and version (3) */
FWLIBAPI short WINAPI cnc_rdsyssoft3(unsigned short, short , short *, short *, ODBSYSS3 *);

/* Tool Compensation Number Send To NC*/
FWLIBAPI short WINAPI cnc_settolnum_qset(unsigned short, short);

/* Work Coordinates Send To NC */
FWLIBAPI short WINAPI cnc_setzofsnum_qset(unsigned short, short);

/* Get Tool Compensation Number */
FWLIBAPI short WINAPI cnc_gettolnum_qset(unsigned short, short *);

/* Get Work Coordinates */
FWLIBAPI short WINAPI cnc_getzofsnum_qset(unsigned short, short *);

/* Set Tool Offset Direct Input */
FWLIBAPI short WINAPI cnc_wrtofsdrctinp(unsigned short, short, short, REALMES);

/* Read overstore command */
FWLIBAPI short WINAPI cnc_rdoverstore(unsigned short FlibHndl, IODBOVSTR *code);

/* Write overstore command */
FWLIBAPI short WINAPI cnc_wroverstore(unsigned short FlibHndl, IODBOVSTR *code);

/* Clear overstore command */
FWLIBAPI short WINAPI cnc_clroverstore(unsigned short FlibHndl);

/* Change overstore mode */
FWLIBAPI short WINAPI cnc_chgoverstore(unsigned short FlibHndl);

/* Read overstore exec mode */
FWLIBAPI short WINAPI cnc_rdoverstoremode(unsigned short FlibHndl, long *mode );

/* Read program block count */
FWLIBAPI short WINAPI cnc_rdblockcount( unsigned short, ODBPRS * ) ;

/* Read abnormal load torq data */
FWLIBAPI short WINAPI cnc_loadtorq( unsigned short, short motor, short axis, short, ODBLOAD * );

/* Read servo id info */
FWLIBAPI short WINAPI cnc_rdservoid( unsigned short, short, short, ODBCSVID * ) ;

/* Read spindle id info */
FWLIBAPI short WINAPI cnc_rdspindleid( unsigned short, short, short, ODBCSPID * ) ;

/* Read from servo id info */
FWLIBAPI short WINAPI cnc_rdfromservoid( unsigned short, short, ODBCSVID * ) ;

/* Read from spindle id info */
FWLIBAPI short WINAPI cnc_rdfromspindleid( unsigned short, short, ODBCSPID * ) ;

/* Write from servo id info */
FWLIBAPI short WINAPI cnc_wrfromservoid( unsigned short, short, ODBCSVID * ) ;

/* Write from spindle id info */
FWLIBAPI short WINAPI cnc_wrfromspindleid( unsigned short, short, ODBCSPID * ) ;

/* Read servo id info */
FWLIBAPI short WINAPI cnc_rdservoid2( unsigned short, short, short, ODBCSVID2 * ) ;

/* Read spindle id info */
FWLIBAPI short WINAPI cnc_rdspindleid2( unsigned short, short, short, ODBCSPID2 * ) ;

/* Read from servo id info */
FWLIBAPI short WINAPI cnc_rdfromservoid2( unsigned short, short, ODBCSVID2 * ) ;

/* Read from spindle id info */
FWLIBAPI short WINAPI cnc_rdfromspindleid2( unsigned short, short, ODBCSPID2 * ) ;

/* Write from servo id info */
FWLIBAPI short WINAPI cnc_wrfromservoid2( unsigned short, short, ODBCSVID2 * ) ;

/* Write from spindle id info */
FWLIBAPI short WINAPI cnc_wrfromspindleid2( unsigned short, short, ODBCSPID2 * ) ;

/* Clear from spindle id info */
FWLIBAPI short WINAPI cnc_clrfromsvspid( unsigned short ) ;

/* Read tool length offset data */
FWLIBAPI short WINAPI cnc_rdofslength( unsigned short , ODBOFSLEN * ) ;

#ifndef CNC_PPC
/* read number of repeats */
FWLIBAPI short WINAPI cnc_rdrepeatval( unsigned short, long * );
#endif

/* read number of repeats(2) */
FWLIBAPI short WINAPI cnc_rdrepeatval_ext( unsigned short, long *, long * );

/* read registered program number */
FWLIBAPI short WINAPI cnc_getregprgnum( unsigned short, short *, short *, short * );

/* read CNC system hard info */
FWLIBAPI short WINAPI cnc_rdsyshard(unsigned short , short , short *, ODBSYSH *) ;

/* read CNC system soft series and version (3) string name */
FWLIBAPI short WINAPI cnc_rdsyssoft3_str(unsigned short, short , short *, short *, ODBSYSS3_STR *);

/* read CNC system hard info  string name */
FWLIBAPI short WINAPI cnc_rdsyshard_str(unsigned short , short , short *, short * , ODBSYSH_STR *) ;

/* read CNC system path information */
FWLIBAPI short WINAPI cnc_sysinfo_ex( unsigned short, ODBSYSEX * ) ;

/* read processing time stamp data filename ver*/
FWLIBAPI short WINAPI cnc_rdproctime2( unsigned short, ODBPTIME2 * ) ;

/* read Work-piece setting error data */
FWLIBAPI short WINAPI cnc_rdwseterror(unsigned short FlibHndl, short number, short g_num, short code, IODBWSETERROR *data);

/* write Work-piece setting error data */
FWLIBAPI short WINAPI cnc_wrwseterror(unsigned short FlibHndl, short number, short g_num, short code, IODBWSETERROR *data);

/* read Transfer Data (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_rdlrntrnsdata( unsigned short, short, ODBTRNS * ) ;

/* read Learning Info (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_rdlrninfo( unsigned short, short, ODBLRNINFO * );

/* read Learning Info (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_rdlrninfo2( unsigned short, short, ODBLRNINFO2 * );

/* write Learning Info (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_wrlrninfo( unsigned short, short, short, char * );

/* Clear Data (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_clrlrncrnt( unsigned short );

/* Backup Data (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_backuplrn( unsigned short );

/* Restore Data (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_restorlrn( unsigned short );

/* Punch Data (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_punchlrncrnt( unsigned short, char * );

/* Read Data (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_readlrncrnt( unsigned short, char * );

/* Stop transfer (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_stoplrntrns( unsigned short );

/* Status of transfer (Parts Learning Control) */
FWLIBAPI short WINAPI cnc_statlrntrns( unsigned short );

/* read Learning Infol (Learning Control) */
FWLIBAPI short WINAPI cnc_rdlrninfol( unsigned short, short, short, short *, ODBLRNINFOL *);

/* read Profile Data (Learning Control) */
FWLIBAPI short WINAPI cnc_rdlrnprfcmnt( unsigned short, short, short, short *, ODBLRNPRF *);

/* write Profile Data (Learning Control) */
FWLIBAPI short WINAPI cnc_wrlrnprf( unsigned short, short, short, char *);

/* Get option function information */
FWLIBAPI short WINAPI cnc_rdoptfuncinfo(unsigned short, short);

/* Send MDI key information */	
FWLIBAPI short WINAPI cnc_sendkey(unsigned short, ODBKEYINFO *);

/* Get CNC display language */
FWLIBAPI short WINAPI cnc_getlanguage(unsigned short, short *);

/* Start of 3D interference check */
FWLIBAPI short WINAPI cnc_3dchk_start(unsigned short, short, short);

/* Start of 3D interference check(2) */
FWLIBAPI short WINAPI cnc_3dchk_start2(unsigned short);

/* Reads 3D interference chaeck data */
FWLIBAPI short WINAPI cnc_3dchk_rddata(unsigned short, ODB3DCHK *);

/* Reads 3D interference chaeck data(2) */
FWLIBAPI short WINAPI cnc_3dchk_rddata2(unsigned short, ODB3DCHK *, short [], ODB3DMTBINFO [] );

/* Reads 3D interference chaeck data(3) */
FWLIBAPI short WINAPI cnc_3dchk_rddata3(unsigned short, unsigned long *, ODB3DCHK [], short [], ODB3DMTBINFO [] );

/* Reads 3D interference chaeck data(4) */
FWLIBAPI short WINAPI cnc_3dchk_rddata4(unsigned short, unsigned long *, ODB3DCHK [], short *, ODB3DMTBINFO2 [] );

/* End of 3D interference check */
FWLIBAPI short WINAPI cnc_3dchk_end(unsigned short);

/* Get of Program information for 3D interference check */
FWLIBAPI short WINAPI cnc_3dchk_getprginfo(unsigned short, unsigned long *, char *, long *);

/* Stop machine for 3D interference check */
FWLIBAPI short WINAPI cnc_3dchk_mchn_stop(unsigned short, IDB3DMSTOP *);

/* Set axis number to move to program restart coordinates. */
FWLIBAPI short WINAPI cnc_setrstraxis(unsigned short, short);

/* Release axis number to move to program restart coordinates. */
FWLIBAPI short WINAPI cnc_clrrstraxis(unsigned short);

/* read option board memory */
FWLIBAPI short WINAPI cnc_rdcncmem2( unsigned short, short, unsigned long, unsigned long, void*, short );

/* write option board memory */
FWLIBAPI short WINAPI cnc_wrcncmem2( unsigned short, short, unsigned long, unsigned long, void*, short );

/* read background axis data */
FWLIBAPI short WINAPI cnc_rdaxisstatus_bg(unsigned short,  short*,  ODBAXSTS_BG *);

/* Set Smooth Parameter Execute Value */
FWLIBAPI short WINAPI cnc_set_smth_exval( unsigned short );

/* Restart notification of stop program */
FWLIBAPI short WINAPI cnc_confirm_restart( unsigned short, unsigned short );

/* check coresspond focas2 function */
FWLIBAPI short WINAPI cnc_chkversion( unsigned short, unsigned long* condition);

/* search free edge group number and offset number about tool offset data */
FWLIBAPI short WINAPI cnc_tool_srh_free_min_num( unsigned short, ODBTL_FREE_NUM *);

/* Read transfer detection initial data number */
FWLIBAPI short WINAPI cnc_rdmtdtnid( unsigned short, unsigned long *);

/* Start transfer detection search */
FWLIBAPI short WINAPI cnc_mtdtnstart( unsigned short);

/* get screen owner number */
FWLIBAPI short WINAPI cnc_getscrowner( unsigned short, short * );

/* Read data from HSSB CRAM for EDM */
FWLIBAPI short WINAPI cnc_rdedmcram( unsigned short, unsigned long, short, long *, void * ) ;

/* Write data to HSSB CRAM for EDM */
FWLIBAPI short WINAPI cnc_wredmcram( unsigned short, unsigned long, short, long *, void * ) ;

/* Read modal integer value (Auto HMI/T) */
FWLIBAPI short WINAPI cnc_rdmodalval( unsigned short, short, long * );

/* Read servo analog data (Auto HMI/T) */
FWLIBAPI short WINAPI cnc_rdsvmonitor( unsigned short, short, short, short *, long * );

/* Read spindle analog data (Auto HMI/T) */
FWLIBAPI short WINAPI cnc_rdspmonitor( unsigned short, short, short, short *, long * );

/* Write special F signal */
FWLIBAPI short WINAPI cnc_wrsignal_f(unsigned short, short, unsigned long);

/* NCGuide protect cancel */
FWLIBAPI short WINAPI cnc_ncg_protcancel( unsigned short, char *, long );

#ifndef CNC_PPC
FWLIBAPI short WINAPI cnc_set_prps( unsigned short, short, char *, unsigned long );
FWLIBAPI short WINAPI cnc_reset_prps( unsigned short, short, char * );
FWLIBAPI short WINAPI cnc_status_prps( unsigned short, short, unsigned long * );
#endif

/*-----*/
/* CNC */
/*-----*/

FWLIBAPI short WINAPI cnc_srcsrsvchnl( unsigned short );

FWLIBAPI short WINAPI cnc_srcsrdidinfo( unsigned short, long, short, short, IODBIDINF * );

FWLIBAPI short WINAPI cnc_srcswridinfo( unsigned short, IODBIDINF * );

FWLIBAPI short WINAPI cnc_srcsstartrd( unsigned short, long, short );

FWLIBAPI short WINAPI cnc_srcsstartwrt( unsigned short, long, short );

FWLIBAPI short WINAPI cnc_srcsstopexec( unsigned short );

FWLIBAPI short WINAPI cnc_srcsrdexstat( unsigned short, ODBSRCSST * );

FWLIBAPI short WINAPI cnc_srcsrdopdata( unsigned short, long, long *, void * );

FWLIBAPI short WINAPI cnc_srcswropdata( unsigned short, long, long, void * );

FWLIBAPI short WINAPI cnc_srcsfreechnl( unsigned short );

FWLIBAPI short WINAPI cnc_srcsrdlayout( unsigned short, ODBSRCSLYT * );

FWLIBAPI short WINAPI cnc_srcsrddrvcp( unsigned short, short * );


/*----------------------------*/
/* CNC : Graphic command data */
/*----------------------------*/

/* Start drawing position */
FWLIBAPI short WINAPI cnc_startdrawpos( unsigned short );

/* Stop drawing position */
FWLIBAPI short WINAPI cnc_stopdrawpos( unsigned short );

/* Start dynamic graphic */
FWLIBAPI short WINAPI cnc_startdyngrph( unsigned short );

/* Stop dynamic graphic */
FWLIBAPI short WINAPI cnc_stopdyngrph( unsigned short );

/* Read graphic command data */
FWLIBAPI short WINAPI cnc_rdgrphcmd( unsigned short, short *, short * );

/* Update graphic command read pointer */
FWLIBAPI short WINAPI cnc_wrgrphcmdptr( unsigned short, short );

/* Read cancel flag */
FWLIBAPI short WINAPI cnc_rdgrphcanflg( unsigned short, short * );

/* Clear graphic command */
FWLIBAPI short WINAPI cnc_clrgrphcmd( unsigned short );

/* Read actual position data for wire */
FWLIBAPI short WINAPI cnc_rdactpos_w( unsigned short, short, ODBWACT * );

/* copy CNC data for multi path system */
FWLIBAPI short WINAPI cnc_data_copy( unsigned short, short, short, short );

/*---------------*/
/* CNC : GRAPHIC */
/*---------------*/

/* Start position sampling */
FWLIBAPI short WINAPI cnc_start_grppos( unsigned short );

/* Stop position sampling */
FWLIBAPI short WINAPI cnc_stop_grppos( unsigned short );

/* Read position data */
FWLIBAPI short WINAPI cnc_rd_grppos( unsigned short, short *, ODBGRPPOS * );

/* Read drawing axis information */
FWLIBAPI short WINAPI cnc_rd_grpaxisinfo( unsigned short, short *, ODBGRPAXIS * );

/* Start position sampling */
FWLIBAPI short WINAPI cnc_start_grppos3( unsigned short );

/* Stop position sampling */
FWLIBAPI short WINAPI cnc_stop_grppos3( unsigned short );

/* Read position data */
FWLIBAPI short WINAPI cnc_rd_grppos3( unsigned short, short *, ODBGRPPOS * );

/*---------------------------*/
/* CNC : Servo learning data */
/*---------------------------*/

#ifndef CNC_PPC
/* Servo learning data read start */
FWLIBAPI short WINAPI cnc_svdtstartrd( unsigned short, short );

/* Servo learning data write start */
FWLIBAPI short WINAPI cnc_svdtstartwr( unsigned short, short );

/* Servo learning data read end */
FWLIBAPI short WINAPI cnc_svdtendrd( unsigned short );

/* Servo learning data write end */
FWLIBAPI short WINAPI cnc_svdtendwr( unsigned short );

/* Servo learning data read/write stop */
FWLIBAPI short WINAPI cnc_svdtstopexec( unsigned short );

/* Servo learning data read from I/F buffer */
FWLIBAPI short WINAPI cnc_svdtrddata( unsigned short, short *, long *, void * );

/* Servo learning data write to I/F buffer */
FWLIBAPI short WINAPI cnc_svdtwrdata( unsigned short, short *, long *, void * );
#endif

/* Servo learning data read start (dual channel) */
FWLIBAPI short WINAPI cnc_svdtstartrd2( unsigned short, short, short );

/* Servo learning data write start (dual channel) */
FWLIBAPI short WINAPI cnc_svdtstartwr2( unsigned short, short, short );

/* Servo learning data read end (dual channel) */
FWLIBAPI short WINAPI cnc_svdtendrd2( unsigned short );

/* Servo learning data write end (dual channel) */
FWLIBAPI short WINAPI cnc_svdtendwr2( unsigned short );

/* Servo learning data read from I/F buffer (dual channel) */
FWLIBAPI short WINAPI cnc_svdtrddata2( unsigned short, short *, long *, void *, short *, long *, void * );

/* Servo learning data write to I/F buffer (dual channel) */
FWLIBAPI short WINAPI cnc_svdtwrdata2( unsigned short, short *, long *, void *, short *, long *, void * );


/*-----*/
/* CNC */
/*-----*/
FWLIBAPI short WINAPI cnc_sdsetchnl( unsigned short, short, IDBCHAN * );

FWLIBAPI short WINAPI cnc_sdsetchnl2(unsigned short, short, IDBCHAN2 * );

FWLIBAPI short WINAPI cnc_sdclrchnl( unsigned short );

FWLIBAPI short WINAPI cnc_sdstartsmpl( unsigned short, short, long, short * );

FWLIBAPI short WINAPI cnc_sdstartsmplb( unsigned short, short, long, short, short, long );

FWLIBAPI short WINAPI cnc_sdstartsmpl2( unsigned short, short, short, TRG_DATA * );

FWLIBAPI short WINAPI cnc_sdcancelsmpl( unsigned short );

FWLIBAPI short WINAPI cnc_sdreadsmpl( unsigned short, short *, long, ODBSD * );

FWLIBAPI short WINAPI cnc_sdreadsmpl2( unsigned short, unsigned short* trg, long, ODBSD * );

FWLIBAPI short WINAPI cnc_sdendsmpl( unsigned short );

FWLIBAPI short WINAPI cnc_sdendsmpl2( unsigned short );

FWLIBAPI short WINAPI cnc_sdread1shot( unsigned short, unsigned short* );

FWLIBAPI short WINAPI cnc_sdbetainfo( unsigned short, short *, ODBBINFO * );

FWLIBAPI short WINAPI cnc_sfbsetchnl( unsigned short, short, long, IDBSFBCHAN * );

FWLIBAPI short WINAPI cnc_sfbclrchnl( unsigned short );

FWLIBAPI short WINAPI cnc_sfbstartsmpl( unsigned short, short, long );

FWLIBAPI short WINAPI cnc_sfbcancelsmpl( unsigned short );

FWLIBAPI short WINAPI cnc_sfbreadsmpl( unsigned short, short *, long, ODBSD * );

FWLIBAPI short WINAPI cnc_sfbendsmpl( unsigned short );

FWLIBAPI short WINAPI cnc_sdtsetchnl( unsigned short, short, long, IDBSDTCHAN * );

FWLIBAPI short WINAPI cnc_sdtsetchnl2( unsigned short, short, long, IDBSDTCHAN2 * );

FWLIBAPI short WINAPI cnc_sdtclrchnl( unsigned short );

FWLIBAPI short WINAPI cnc_sdtstartsmpl( unsigned short, short, long );

FWLIBAPI short WINAPI cnc_sdtstartsmpl2( unsigned short, short, short, TRG_DATA * );

FWLIBAPI short WINAPI cnc_sdtcancelsmpl( unsigned short );

FWLIBAPI short WINAPI cnc_sdtreadsmpl( unsigned short, short *, long, ODBSD * );

FWLIBAPI short WINAPI cnc_sdtreadsmpl2( unsigned short, unsigned short *, long, ODBSD * );

FWLIBAPI short WINAPI cnc_sdtendsmpl( unsigned short );

FWLIBAPI short WINAPI cnc_sdtendsmpl2( unsigned short );

FWLIBAPI short WINAPI cnc_sdtread1shot( unsigned short, unsigned short * );


/*----------------------------*/
/* CNC : NC display function  */
/*----------------------------*/

/* Start NC display */
FWLIBAPI short WINAPI cnc_startnccmd( unsigned short );

#ifndef CNC_PPC
/* Start NC display (2) */
FWLIBAPI short WINAPI cnc_startnccmd2( unsigned short, char * );
#endif

/* Stop NC display */
FWLIBAPI short WINAPI cnc_stopnccmd( unsigned short );

/* Get NC display mode */
FWLIBAPI short WINAPI cnc_getdspmode( unsigned short, short * );

//#ifndef CNC_PPC
/* Set current display screen */
FWLIBAPI short WINAPI cnc_setcurscrn( unsigned short, short );
//#endif

/* Change status of SDF */
FWLIBAPI short WINAPI cnc_sdfstatchg( unsigned short, short, short, int, long );

/* Set manager application for SDF */
FWLIBAPI short WINAPI cnc_sdfmnghwnd( unsigned short, short, HWND, unsigned long );

/* Get file name for BPRNT/DPRNT */
FWLIBAPI short WINAPI cnc_getprntname( unsigned short, char * );


/*------------------------------------*/
/* CNC : Remote diagnostics function  */
/*------------------------------------*/

/* Start remote diagnostics function */
FWLIBAPI short WINAPI cnc_startrmtdgn( unsigned short );

/* Stop remote diagnostics function */
FWLIBAPI short WINAPI cnc_stoprmtdgn( unsigned short );

/* Read data from remote diagnostics I/F */
FWLIBAPI short WINAPI cnc_rdrmtdgn( unsigned short, long *, char * );

/* Write data to remote diagnostics I/F */
FWLIBAPI short WINAPI cnc_wrrmtdgn( unsigned short, long *, char * );

/* Set CommStatus of remote diagnostics I/F area */
FWLIBAPI short WINAPI cnc_wrcommstatus( unsigned short, short );

/* Check remote diagnostics I/F */
FWLIBAPI short WINAPI cnc_chkrmtdgn( unsigned short );

/* remote diagnosis start */
FWLIBAPI short WINAPI cnc_pdf_startrmtdgn( unsigned short, char, short, OUT_RMTDGNINFO * ) ;

/* remote diagnosis end */
FWLIBAPI short WINAPI cnc_pdf_stoprmtdgn( unsigned short, char, short ) ;

/* read remote diagnosis information */
FWLIBAPI short WINAPI cnc_pdf_rdrmtdgn( unsigned short, char, short *, OUT_RMTDGNINFO * ) ;

/* change inguiry number */
FWLIBAPI short WINAPI cnc_pdf_chginquiry( unsigned short, char, short ) ;

/*-------------------------*/
/* CNC : FS18-LN function  */
/*-------------------------*/

/* read allowance */
FWLIBAPI short WINAPI cnc_allowance( unsigned short, short, short, ODBAXIS * ) ;

/* read allowanced state */
FWLIBAPI short WINAPI cnc_allowcnd( unsigned short, short, short, ODBCAXIS * ) ;

/* set work zero */
FWLIBAPI short WINAPI cnc_workzero( unsigned short, short, IODBZOFS * ) ;

/* set slide position */
FWLIBAPI short WINAPI cnc_slide( unsigned short, short, short, ODBAXIS * ) ;

/*---------------------------*/
/* CNC : FS31i-LNB function  */
/*---------------------------*/

/* read feed mode */
FWLIBAPI short WINAPI cnc_rdfeedmode( unsigned short, short, short * ) ;

/*-----------*/
/* Oxxxxxxxx */
/*-----------*/

/* start uploading NC program */
FWLIBAPI short WINAPI cnc_upstarto8( unsigned short, long ) ;

/* search specified program */
FWLIBAPI short WINAPI cnc_searcho8( unsigned short, long ) ;

/* delete specified program */
FWLIBAPI short WINAPI cnc_deleteo8( unsigned short, long ) ;

/* read program directory */
FWLIBAPI short WINAPI cnc_rdprogdiro8( unsigned short, short, long, long, unsigned short, PRGDIR * ) ;

/* read program number under execution */
FWLIBAPI short WINAPI cnc_rdprgnumo8( unsigned short, ODBPROO8 * ) ;

/* read all dynamic data */
FWLIBAPI short WINAPI cnc_rddynamico8( unsigned short, short, short, ODBDYO8 * ) ;

/* read execution pointer for MDI operation */
FWLIBAPI short WINAPI cnc_rdmdipntro8( unsigned short, ODBMDIPO8 * ) ;

/* read program directory 2 */
FWLIBAPI short WINAPI cnc_rdprogdir2o8( unsigned short, short, long *, short *, PRGDIR2O8 * ) ;

#ifndef CNC_PPC
/* read digit of program number */
FWLIBAPI short WINAPI cnc_progdigit( unsigned short, short * );
#endif

/*----------------------------------*/
/* CNC: Teaching data I/F function  */
/*----------------------------------*/

/* Teaching data get start */
FWLIBAPI short WINAPI cnc_startgetdgdat( unsigned short FlibHndl );

/* Teaching data get stop */
FWLIBAPI short WINAPI cnc_stopgetdgdat( unsigned short FlibHndl );

/* Teaching data read */
FWLIBAPI short WINAPI cnc_rddgdat( unsigned short FlibHndl, short * , short * );

/* Teaching data read pointer write */
FWLIBAPI short WINAPI cnc_wrdgdatptr( unsigned short FlibHndl, short );

/* Teaching data clear */
FWLIBAPI short WINAPI cnc_clrdgdat( unsigned short FlibHndl );


/*---------------------------------*/
/* CNC : C-EXE SRAM file function  */
/*---------------------------------*/

/* open C-EXE SRAM file */
FWLIBAPI short WINAPI cnc_opencexefile( unsigned short, char *, short, short );

/* close C-EXE SRAM file */
FWLIBAPI short WINAPI cnc_closecexefile( unsigned short );

/* read C-EXE SRAM file */
FWLIBAPI short WINAPI cnc_rdcexefile( unsigned short, unsigned char *, unsigned long * );

/* write C-EXE SRAM file */
FWLIBAPI short WINAPI cnc_wrcexefile( unsigned short, unsigned char *, unsigned long * );

/* read C-EXE SRAM disk directory */
FWLIBAPI short WINAPI cnc_cexedirectory( unsigned short, char *, unsigned short *,
		unsigned short, CFILEINFO * );


/*------------*/
/* CNC : FSSB */
/*------------*/

/* read amp information */
FWLIBAPI short WINAPI cnc_rdfssb_amp( unsigned short, short, short, short *, ODBFSSBAMP * );

/* write axis number */
FWLIBAPI short WINAPI cnc_wrfssb_axis_num( unsigned short, short, short, short, short * );

/* read pulse module information */
FWLIBAPI short WINAPI cnc_rdfssb_plsmod( unsigned short, short, short, short *, ODBPLSMDL * );

/* read axis information */
FWLIBAPI short WINAPI cnc_rdfssb_axis( unsigned short, short, short *, IODBFSSBAXIS * );

/* write axis information */
FWLIBAPI short WINAPI cnc_wrfssb_axis( unsigned short, short, short, short, IODBFSSBAXIS * );

/* read maintenance information */
FWLIBAPI short WINAPI cnc_rdfssb_mainte( unsigned short, short, short *, ODBFSSBMT * );

/* read FSSB information */
FWLIBAPI short WINAPI cnc_rdfssb_info( unsigned short, ODBFSSBINFO * );

/* set automatic FSSB settings */
FWLIBAPI short WINAPI cnc_fssb_autoset( unsigned short, short );

/* reset FSSB settings */
FWLIBAPI short WINAPI cnc_fssb_reset( unsigned short, short );

/* FSSB fpr 30iB (IFSB) */
FWLIBAPI short WINAPI cnc_rdifsb_info(unsigned short , short, ODBIFSBINFO *);
FWLIBAPI short WINAPI cnc_rdifsb_slvunt(unsigned short, short, short, short, short *, ODBIFSBSLVUNT *);
FWLIBAPI short WINAPI cnc_rdifsb_slu_sv(unsigned short, short, short, short *, ODBIFSBSLUSV *);
FWLIBAPI short WINAPI cnc_rdifsb_slu_sp(unsigned short, short, short, short *, ODBIFSBSLUSP *);
FWLIBAPI short WINAPI cnc_rdifsb_slu_pm(unsigned short, short, short, short *, ODBIFSBSLUPM *);
FWLIBAPI short WINAPI cnc_rdifsb_as_amp_sv(unsigned short, short, short, short *, ODBIFSBSVAMP *);
FWLIBAPI short WINAPI cnc_wrifsb_as_axis_num(unsigned short, short, short, short, short *);
FWLIBAPI short WINAPI cnc_rdifsb_as_hrv(unsigned short, unsigned short *);
FWLIBAPI short WINAPI cnc_wrifsb_as_hrv(unsigned short, unsigned short);
FWLIBAPI short WINAPI cnc_rdifsb_as_amp_sp(unsigned short, short, short, short *, ODBIFSBSPAMP *);
FWLIBAPI short WINAPI cnc_wrifsb_as_spdl_num(unsigned short, short, short, short, short *);
FWLIBAPI short WINAPI cnc_rdifsb_as_plsmod(unsigned short, short, short, short *, ODBIFSBPLSMDL *);
FWLIBAPI short WINAPI cnc_rdifsb_as_sv_axis(unsigned short, short, short *, IODBIFSBAXIS *);
FWLIBAPI short WINAPI cnc_wrifsb_as_sv_axis(unsigned short, short, short, short, IODBIFSBAXIS *);
FWLIBAPI short WINAPI cnc_rdifsb_mainte_sv(unsigned short, short, short *, ODBIFSBMNTSV *);
FWLIBAPI short WINAPI cnc_rdifsb_mainte_sp(unsigned short, short, short *, ODBIFSBMNTSP *);
FWLIBAPI short WINAPI cnc_ifsb_autoset(unsigned short);
FWLIBAPI short WINAPI cnc_ifsb_reset(unsigned short);
FWLIBAPI short WINAPI cnc_rdifsb_almstate(unsigned short, char *, char *);
FWLIBAPI short WINAPI cnc_rdifsb_sysalm(unsigned short, short, ODBIFSBSYSALM* );
FWLIBAPI short WINAPI cnc_rdifsb_fssbunt(unsigned short, short, short, short*, ODBIFSBFSSBUNT* );
FWLIBAPI short WINAPI cnc_rdifsb_comstatdtl(unsigned short, short, short, short, short*, ODBIFSBCOMSTATDTL* );
FWLIBAPI short WINAPI cnc_rdifsb_warning_cnt(unsigned short, short* );
FWLIBAPI short WINAPI cnc_rdifsb_warning_msg(unsigned short, short, short*, ODBIFSBWARNINGMSG* );
FWLIBAPI short WINAPI cnc_rdifsb_warnhst_cnt(unsigned short, short* );
FWLIBAPI short WINAPI cnc_rdifsb_warnhst_msg(unsigned short, short, short*, ODBIFSBWARNHSTMSG* );

#if defined (PMD) /* only Power Mate D/H */
/*------------------------------*/
/* MAXIS: Axis Movement Control */
/*------------------------------*/

/* cnc_opdi:signal operation command */
FWLIBAPI short WINAPI cnc_opdi(unsigned short,short,ODBOPDI *);

/* cnc_refpoint:reference point return */
FWLIBAPI short WINAPI cnc_refpoint(unsigned short,short,short,short,ODBEXEC *);

/* cnc_abspoint:absolute movement */
FWLIBAPI short WINAPI cnc_abspoint(unsigned short,short,short,short,long,ODBPOS *,ODBEXEC *);

/* cnc_incpoint:incremental movement */
FWLIBAPI short WINAPI cnc_incpoint(unsigned short,short,short,short,long,ODBPOS *,ODBEXEC *);

/* cnc_dwell:dwell */
FWLIBAPI short WINAPI cnc_dwell(unsigned short,short,short,short,ODBPOS *,ODBEXEC *);

/* cnc_coordre:coordinate establihment */
FWLIBAPI short WINAPI cnc_coordre(unsigned short,short,short,short,ODBPOS *,ODBEXEC *);

/* cnc_exebufstat:reading of the executive buffer condition */
FWLIBAPI short WINAPI cnc_exebufstat(unsigned short,ODBEXEC *);

/* cnc_finstate:Reading of the execution completion condition */
FWLIBAPI short WINAPI cnc_finstate(unsigned short,ODBFIN *);

/* cnc_setfin:Release of the reading mode of the execution completion condition */
FWLIBAPI short WINAPI cnc_setfin(unsigned short,ODBFIN *);
#endif


/*-----*/
/* PMC */
/*-----*/

/* read message from PMC to MMC */
FWLIBAPI short WINAPI pmc_rdmsg( unsigned short, short *, short * ) ;

/* write message from MMC to PMC */
FWLIBAPI short WINAPI pmc_wrmsg( unsigned short, short, short * ) ;

/* read message from PMC to MMC(conditional) */
FWLIBAPI short WINAPI pmc_crdmsg( unsigned short, short *, short * ) ;

/* write message from MMC to PMC(conditional) */
FWLIBAPI short WINAPI pmc_cwrmsg( unsigned short, short, short * ) ;

/* read PMC data(area specified) */
#if !defined (PMD)
FWLIBAPI short WINAPI pmc_rdpmcrng( unsigned short, short, short, unsigned short, unsigned short, unsigned short, IODBPMC * ) ;
#else
FWLIBAPI short WINAPI pmc_rdpmcrng( unsigned short, short, short, short, short, short, IODBPMC *);
#endif

/* write PMC data(area specified) */
#if !defined (PMD)
FWLIBAPI short WINAPI pmc_wrpmcrng( unsigned short, unsigned short, IODBPMC * ) ;
#else
FWLIBAPI short WINAPI pmc_wrpmcrng( unsigned short, short, IODBPMC *);
#endif

/* write PMC data2(area specified) */
FWLIBAPI short WINAPI pmc_wrpmcrng2( unsigned short, unsigned short, IODBPMC * ) ;

FWLIBAPI short WINAPI pmc_rdwrpmcrng( unsigned short, short, IODBRWPMC [] );

/* read data from extended backup memory */
FWLIBAPI short WINAPI pmc_rdkpm( unsigned short, unsigned long, char *, unsigned short ) ;

/* write data to extended backup memory */
FWLIBAPI short WINAPI pmc_wrkpm( unsigned short, unsigned long, char *, unsigned short ) ;

/* read data from extended backup memory 2 */
 FWLIBAPI short WINAPI pmc_rdkpm2( unsigned short, unsigned long, char *, unsigned long ) ;

/* write data to extended backup memory 2 */
 FWLIBAPI short WINAPI pmc_wrkpm2( unsigned short, unsigned long, char *, unsigned long ) ;

/* read maximum size of extended backup memory */
FWLIBAPI short WINAPI pmc_kpmsiz( unsigned short, unsigned long * ) ;

/* read informations of PMC data */
FWLIBAPI short WINAPI pmc_rdpmcinfo( unsigned short, short, ODBPMCINF * ) ;

/* read PMC parameter data table contorol data */
FWLIBAPI short WINAPI pmc_rdcntldata( unsigned short, short, short, short, IODBPMCCNTL * ) ;

/* write PMC parameter data table contorol data */
FWLIBAPI short WINAPI pmc_wrcntldata( unsigned short, short, IODBPMCCNTL * ) ;

/* read PMC parameter data table contorol data group number */
FWLIBAPI short WINAPI pmc_rdcntlgrp( unsigned short, short * ) ;

/* write PMC parameter data table contorol data group number */
FWLIBAPI short WINAPI pmc_wrcntlgrp( unsigned short, short ) ;

/* read PMC alarm message */
FWLIBAPI short WINAPI pmc_rdalmmsg( unsigned short, short, short *, short *, ODBPMCALM * ) ;

/* get detail error for pmc */
FWLIBAPI short WINAPI pmc_getdtailerr( unsigned short, ODBPMCERR * ) ;

/* read PMC memory data */
FWLIBAPI short WINAPI pmc_rdpmcmem( unsigned short, short, long, long, void * ) ;

/* write PMC memory data */
FWLIBAPI short WINAPI pmc_wrpmcmem( unsigned short, short, long, long, void * ) ;

/* read PMC memory data */
FWLIBAPI short WINAPI pmc_rdpmcsemem( unsigned short, short, long, long, void * ) ;

/* write PMC memory data */
FWLIBAPI short WINAPI pmc_wrpmcsemem( unsigned short, short, long, long, void * ) ;

/* read pmc title data */
FWLIBAPI short WINAPI pmc_rdpmctitle( unsigned short, ODBPMCTITLE * ) ;
FWLIBAPI short WINAPI pmc_rdpmctitle2( unsigned short, ODBPMCTITLE2 * ) ;

/* read PMC parameter start */
 FWLIBAPI short WINAPI pmc_rdprmstart( unsigned short ) ;

/* read PMC parameter */
 FWLIBAPI short WINAPI pmc_rdpmcparam( unsigned short, long *, char * ) ;

/* read PMC parameter end */
 FWLIBAPI short WINAPI pmc_rdprmend( unsigned short ) ;

/* write PMC parameter start */
 FWLIBAPI short WINAPI pmc_wrprmstart( unsigned short ) ;

/* write PMC parameter */
 FWLIBAPI short WINAPI pmc_wrpmcparam( unsigned short, long *, char * ) ;

/* write PMC parameter end */
 FWLIBAPI short WINAPI pmc_wrprmend( unsigned short ) ;

/* read PMC data */
FWLIBAPI short WINAPI pmc_rdpmcrng_ext( unsigned short, short, IODBPMCEXT * ) ;

/* write PMC I/O link assigned data */
FWLIBAPI short WINAPI pmc_wriolinkdat( unsigned short, long, long, unsigned long, void *, unsigned long ) ;

/* read PMC address information */
FWLIBAPI short WINAPI pmc_rdpmcaddr( unsigned short, long, unsigned short, unsigned long, ODBPMCADR * );

/*j select PMC unit */
FWLIBAPI short WINAPI pmc_select_pmc_unit( unsigned short h, long unittype );

/*j get current PMC unit */
FWLIBAPI short WINAPI pmc_get_current_pmc_unit( unsigned short h, long * unittype );

/*j get number of PMC */
FWLIBAPI short WINAPI pmc_get_number_of_pmc(unsigned short h, long * piNum);

/*j get PMC unit types */
FWLIBAPI short WINAPI pmc_get_pmc_unit_types( unsigned short h, long unittypes[], long * count );

/* set PMC Timer type */
FWLIBAPI short WINAPI pmc_set_timer_type( unsigned short h, unsigned short, unsigned short, short * );

/* get PMC Timer type */
FWLIBAPI short WINAPI pmc_get_timer_type( unsigned short h, unsigned short, unsigned short, short * );

/* Reads sequence program and momory type */
FWLIBAPI short WINAPI pmc_read_seq_program_and_memory_type( unsigned short, ODBPMCLADMEMTYPE * );

/* read PMC parameter extend relay contorol data */
FWLIBAPI short WINAPI pmc_rdcntlexrelay( unsigned short, short, short, short, IODBPMCCNTL * ) ;

/* write PMC parameter extend relay contorol data */
FWLIBAPI short WINAPI pmc_wrcntlexrelay( unsigned short, short, IODBPMCCNTL * ) ;

/* read PMC parameter extend relay contorol data group number */
FWLIBAPI short WINAPI pmc_rdcntl_exrelay_grp( unsigned short, short * ) ;

/* write PMC parameter extend relay contorol data group number */
FWLIBAPI short WINAPI pmc_wrcntl_exrelay_grp( unsigned short, short ) ;

/* convert to PMC address information from address or symbol string */
FWLIBAPI short WINAPI pmc_convert_from_string_to_address( unsigned short, const char *, ODBPMCADRINFO * );

/*j select divided ladder */
FWLIBAPI short WINAPI pmc_select_divided_ladder( unsigned short h, long divnumber );

/*j get current divided ladder */
FWLIBAPI short WINAPI pmc_get_current_divided_ladder( unsigned short h, long * divnumber );

/*j get number of Ladder */
FWLIBAPI short WINAPI pmc_get_number_of_ladder( unsigned short h, long * number );

/*j get Divided Ladders */
FWLIBAPI short WINAPI pmc_get_divided_ladders( unsigned short h, long divnums[], long * count );

FWLIBAPI short WINAPI pmc_rdioconfigtitle(unsigned short, long, char *);

FWLIBAPI short WINAPI pmc_rdmessagetitle(unsigned short, long, char *);

/*----------------------------*/
/* PMC : PROFIBUS function    */
/*----------------------------*/

/* read PROFIBUS information data */
FWLIBAPI short WINAPI pmc_prfrdinfo( unsigned short, ODBPRFINFO * ) ;

/* read PROFIBUS configration data */
FWLIBAPI short WINAPI pmc_prfrdconfig( unsigned short, ODBPRFCNF * ) ;

/* read bus parameter for master function */
FWLIBAPI short WINAPI pmc_prfrdbusprm( unsigned short, IODBBUSPRM * ) ;

/* write bus parameter for master function */
FWLIBAPI short WINAPI pmc_prfwrbusprm( unsigned short, IODBBUSPRM * ) ;

/* read slave parameter for master function */
FWLIBAPI short WINAPI pmc_prfrdslvprm( unsigned short, short, void * ) ;

/* write slave parameter for master function */
FWLIBAPI short WINAPI pmc_prfwrslvprm( unsigned short, short, void * ) ;

/* read allocation address for master function */
FWLIBAPI short WINAPI pmc_prfrdallcadr( unsigned short, short, IODBPRFADR * ) ;

/* set allocation address for master function */
FWLIBAPI short WINAPI pmc_prfwrallcadr( unsigned short, short, IODBPRFADR * ) ;

/* read allocation address for slave function */
FWLIBAPI short WINAPI pmc_prfrdslvaddr( unsigned short, IODBSLVADR * ) ;

/* set allocation address for slave function */
FWLIBAPI short WINAPI pmc_prfwrslvaddr( unsigned short, IODBSLVADR * ) ;

/* read status for slave function */
FWLIBAPI short WINAPI pmc_prfrdslvstat( unsigned short, ODBSLVST * ) ;

/* Reads slave index data of master function */
FWLIBAPI short WINAPI pmc_prfrdslvid( unsigned short, short, IODBSLVID * ) ;

/* Writes slave index data of master function */
FWLIBAPI short WINAPI pmc_prfwrslvid( unsigned short, short, IODBSLVID * ) ;

/* Reads slave parameter of master function(2) */
FWLIBAPI short WINAPI pmc_prfrdslvprm2( unsigned short, short, IODBSLVPRM3 * ) ;

/* Writes slave parameter of master function(2) */
FWLIBAPI short WINAPI pmc_prfwrslvprm2( unsigned short, short, IODBSLVPRM3 * ) ;

/* Reads DI/DO parameter of master function */
FWLIBAPI short WINAPI pmc_prfrddido( unsigned short, short, IODBDIDO * ) ;

/* Writes DI/DO parameter of master function */
FWLIBAPI short WINAPI pmc_prfwrdido( unsigned short, short, IODBDIDO * ) ;

/* Reads indication address of master function */
FWLIBAPI short WINAPI pmc_prfrdindiadr( unsigned short, IODBINDEADR * ) ;

/* Writes indication address of master function */
FWLIBAPI short WINAPI pmc_prfwrindiadr( unsigned short, IODBINDEADR * ) ;

/* Reads operation mode of master function */
FWLIBAPI short WINAPI pmc_prfrdopmode( unsigned short, short * ) ;

/* Writes operation mode of master function */
FWLIBAPI short WINAPI pmc_prfwropmode( unsigned short, short, short * ) ;


/*-----------------------------------*/
/* CB : CUSTOMER'S BOARD function    */
/*-----------------------------------*/

/* start downloading Customer's board data */
FWLIBAPI short WINAPI cb_dwnstart( unsigned short FwHndl, unsigned short a, long b ) ;

/* download Customer's board data */
FWLIBAPI short WINAPI cb_download( unsigned short FwHndl, long *a, char *b ) ;

/* end of downloading Customer's board data */
FWLIBAPI short WINAPI cb_dwnend( unsigned short FwHndl ) ;

/* start uploading Customer's board data */
FWLIBAPI short WINAPI cb_upstart( unsigned short FwHndl, unsigned short *a, long *b ) ;

/* upload Customer's board data */
FWLIBAPI short WINAPI cb_upload( unsigned short FwHndl, long *a, char *b ) ;

/* end of uploading Customer's board data */
FWLIBAPI short WINAPI cb_upend( unsigned short FwHndl ) ;

/* get transfer informations */
FWLIBAPI short WINAPI cb_transinfo( unsigned short FwHndl, ODBTRANSINFO *info ) ;


/*-----*/
/* DSA */
/*-----*/
FWLIBAPI short WINAPI dsa_rdbyte( unsigned short, long, char * );
FWLIBAPI short WINAPI dsa_rdword( unsigned short, long, short * );
FWLIBAPI short WINAPI dsa_rddword( unsigned short, long, long * );
FWLIBAPI short WINAPI dsa_wrbyte( unsigned short, long, char );
FWLIBAPI short WINAPI dsa_wrword( unsigned short, long, short );
FWLIBAPI short WINAPI dsa_wrdword( unsigned short, long, long );


/*-----------------------------------------------*/
/* DS : Data server & Ethernet board function    */
/*-----------------------------------------------*/

/* read the parameter of the Ethernet board */
 FWLIBAPI short WINAPI etb_rdparam(unsigned short hLib, short a, IODBETP *b);

/* write the parameter of the Ethernet board */
 FWLIBAPI short WINAPI etb_wrparam(unsigned short hLib, IODBETP *a);

/* read the error message of the Ethernet board */
 FWLIBAPI short WINAPI etb_rderrmsg(unsigned short hLib, short a, ODBETMSG *b);

/* read the mode of the Data Server */
 FWLIBAPI short WINAPI ds_rdmode(unsigned short hLib, short *a);

/* write the mode of the Data Server */
 FWLIBAPI short WINAPI ds_wrmode(unsigned short hLib, short a);

/* read information of the Data Server's HDD */
 FWLIBAPI short WINAPI ds_rdhddinfo(unsigned short hLib, ODBHDDINF *a);

/* read the file list of the Data Server's HDD */
 FWLIBAPI short WINAPI ds_rdhdddir(unsigned short hLib, char *a, long b, short *c, ODBHDDDIR *d);

/* delete the file of the Data Serve's HDD */
 FWLIBAPI short WINAPI ds_delhddfile(unsigned short hLib, char *a);

/* copy the file of the Data Server's HDD */
 FWLIBAPI short WINAPI ds_copyhddfile(unsigned short hLib, char *a, char *b);

/* change the file name of the Data Server's HDD */
 FWLIBAPI short WINAPI ds_renhddfile(unsigned short hLib, char *a, char *b);

/* execute the PUT command of the FTP */
 FWLIBAPI short WINAPI ds_puthddfile(unsigned short hLib, char *a, char *b);

/* execute the MPUT command of the FTP */
 FWLIBAPI short WINAPI ds_mputhddfile(unsigned short hLib, char *a);

/* read information of the host */
 FWLIBAPI short WINAPI ds_rdhostinfo(unsigned short hLib, long *a, long b);

/* read the file list of the host */
 FWLIBAPI short WINAPI ds_rdhostdir(unsigned short hLib, short a, long b, short *c, ODBHOSTDIR *d, long e);

/* read the file list of the host 2 */
 FWLIBAPI short WINAPI ds_rdhostdir2(unsigned short hLib, short a, long b, short *c, long *d, ODBHOSTDIR *e, long f);

/* delete the file of the host */
 FWLIBAPI short WINAPI ds_delhostfile(unsigned short hLib, char *a, long b);

/* execute the GET command of the FTP */
 FWLIBAPI short WINAPI ds_gethostfile(unsigned short hLib, char *a, char *b);

/* execute the MGET command of the FTP */
 FWLIBAPI short WINAPI ds_mgethostfile(unsigned short hLib, char *a);

/* read the execution result */
 FWLIBAPI short WINAPI ds_rdresult(unsigned short hLib);

/* stop the execution of the command */
 FWLIBAPI short WINAPI ds_cancel(unsigned short hLib);

/* read the file from the Data Server */
 FWLIBAPI short WINAPI ds_rdncfile(unsigned short hLib, short a, char *b);

/* read the file from the Data Server 2 */
 FWLIBAPI short WINAPI ds_rdncfile2(unsigned short hLib, char *a);

/* write the file to the Data Server */
 FWLIBAPI short WINAPI ds_wrncfile(unsigned short hLib, short a, long b);

/* read the file name for the DNC operation in the Data Server's HDD */
 FWLIBAPI short WINAPI ds_rddnchddfile(unsigned short hLib, char *a);

/* write the file name for the DNC operation in the Data Server's HDD */
 FWLIBAPI short WINAPI ds_wrdnchddfile(unsigned short hLib, char *a);

/* read the file name for the DNC operation in the host */
 FWLIBAPI short WINAPI ds_rddnchostfile(unsigned short hLib, short *a, char *b);

/* write the file name for the DNC operation in the host */
 FWLIBAPI short WINAPI ds_wrdnchostfile(unsigned short hLib, char *a);

/* read the connecting host number */
 FWLIBAPI short WINAPI ds_rdhostno(unsigned short hLib, short *a);

/* read maintenance information */
 FWLIBAPI short WINAPI ds_rdmntinfo(unsigned short hLib, short a, DSMNTINFO *b);

/* check the Data Server's HDD */
 FWLIBAPI short WINAPI ds_checkhdd(unsigned short hLib);

/* format the Data Server's HDD */
 FWLIBAPI short WINAPI ds_formathdd(unsigned short hLib);

/* create the directory in the Data Server's HDD */
 FWLIBAPI short WINAPI ds_makehdddir(unsigned short hLib, char *a);

/* delete directory in the Data Server's HDD */
 FWLIBAPI short WINAPI ds_delhdddir(unsigned short hLib, char *a);

/* change the current directory */
 FWLIBAPI short WINAPI ds_chghdddir(unsigned short hLib, char *a);

/* execute the PUT command according to the list file */
 FWLIBAPI short WINAPI ds_lputhddfile(unsigned short hLib, char *a);

/* delete files according to the list file */
 FWLIBAPI short WINAPI ds_ldelhddfile(unsigned short hLib, char *a);

/* execute the GET command according to the list file */
 FWLIBAPI short WINAPI ds_lgethostfile(unsigned short hLib, char *a);

/* read the directory for M198 operation */
 FWLIBAPI short WINAPI ds_rdm198hdddir(unsigned short hLib, char *a);

/* write the directory for M198 operation */
 FWLIBAPI short WINAPI ds_wrm198hdddir(unsigned short hLib);

/* read the connecting host number for the M198 operation */
 FWLIBAPI short WINAPI ds_rdm198host(unsigned short hLib, short *a);

/* write the connecting host number for the M198 operation */
 FWLIBAPI short WINAPI ds_wrm198host(unsigned short hLib);

/* write the connecting host number */
 FWLIBAPI short WINAPI ds_wrhostno(unsigned short hLib, short a);

/* search string in data server program */
 FWLIBAPI short WINAPI ds_searchword(unsigned short FlibHndl, char *prog_data);

/* read the searching result */
 FWLIBAPI short WINAPI ds_searchresult(unsigned short FlibHndl);

/* read file in the Data Server's HDD */
 FWLIBAPI short WINAPI ds_rdfile(unsigned short hLib, char *a, char *b);

/* write file in the Data Server's HDD */
 FWLIBAPI short WINAPI ds_wrfile(unsigned short hLib, char *a, char *b);

/* start downloading Data Server data */
FWLIBAPI short WINAPI ds_dwnstart( unsigned short, char *, short ) ;

/* download Data Server data */
FWLIBAPI short WINAPI ds_download( unsigned short, long *, char * ) ;

/* end of downloading Data Server data */
FWLIBAPI short WINAPI ds_dwnend( unsigned short ) ;


/*----------------------------*/
/* NET : Ethernet function    */
/*----------------------------*/

/* read parameter for ethernet function */
FWLIBAPI short WINAPI eth_rdparam( unsigned short, short, OUT_ETHPRM * );

/* write parameter for ethernet function */
FWLIBAPI short WINAPI eth_wrparam( unsigned short, short, IN_ETHPRMFLAG *, IN_ETHPRM * );

/* read kind of device for embedded ethernet function */
FWLIBAPI short WINAPI eth_rdembdev( unsigned short, short * );

/* set device for embedded ethernet function */
FWLIBAPI short WINAPI eth_wrembdev( unsigned short, short );

/* restart for embedded ethernet function */
FWLIBAPI short WINAPI eth_embrestart( unsigned short, short );

/* read mode for dataserver function */
FWLIBAPI short WINAPI eth_rddsmode( unsigned short, OUT_ETHDSMODE * );

/* write mode for dataserver function */
FWLIBAPI short WINAPI eth_wrdsmode( unsigned short, short, short );

/* execute ping function */
FWLIBAPI short WINAPI eth_ping( unsigned short, short, char *, unsigned long * );

/* get result of ping function */
FWLIBAPI short WINAPI eth_ping_result( unsigned short, short, OUT_ETHPING * );

/* cancel ping function */
FWLIBAPI short WINAPI eth_ping_cancel( unsigned short, short );

/* read state of LSI for ethernet function */
FWLIBAPI short WINAPI eth_rdlsistate( unsigned short, short, OUT_ETHLSI * );

/* clear state of LSI for ethernet function */
FWLIBAPI short WINAPI eth_clrlsistate( unsigned short, short );

/* read state of task for ethernet function */
FWLIBAPI short WINAPI eth_rdtaskstate( unsigned short, short, OUT_ETHTASK * );

/* read log for ethernet function */
FWLIBAPI short WINAPI eth_rdlog( unsigned short, short, short, short, OUT_ETHLOG * );

/* clear log for ethernet function */
FWLIBAPI short WINAPI eth_clrlog( unsigned short, short );

/* read type for ethernet function */
FWLIBAPI short WINAPI eth_rdtype( unsigned short, OUT_ETHTYPE * );

/* read type for ethernet function */
FWLIBAPI short WINAPI eth_rdtype2( unsigned short, OUT_ETHTYPE2 * );

/* read type for ethernet function */
FWLIBAPI short WINAPI eth_rdtype3( unsigned short, OUT_ETHTYPE3 * );

/* read state for dataserver function */
FWLIBAPI short WINAPI eth_rddsstate( unsigned short, short, OUT_DSSTATE * );

/* read host number for ethernet function */
FWLIBAPI short WINAPI eth_rdhost( unsigned short, short, short * );

/* write host number for ethernet function */
FWLIBAPI short WINAPI eth_wrhost( unsigned short, short, short );

/* read m198 folder for dataserver function */
FWLIBAPI short WINAPI eth_rddsm198dir( unsigned short, short, char * );

/* write m198 folder for dataserver function */
FWLIBAPI short WINAPI eth_wrdsm198dir( unsigned short, short, char * );

/* read m198 host number for dataserver function */
FWLIBAPI short WINAPI eth_rddsm198host( unsigned short, short, short *, char * );

/* write m198 host number for dataserver function */
FWLIBAPI short WINAPI eth_wrdsm198host( unsigned short, short, short, char * );

/* read m198 host number for embedded ethernet function */
FWLIBAPI short WINAPI eth_rdembm198host( unsigned short, short, short *, char * );

/* write m198 host number for embedded ethernet function */
FWLIBAPI short WINAPI eth_wrembm198host( unsigned short, short, short, char * );

/* read ATA card format type */
FWLIBAPI short WINAPI eth_rddsformat( unsigned short, short * );

/* format ATA card */
FWLIBAPI short WINAPI eth_dsformat( unsigned short, short, short * );

/* checkdisk ATA card */
FWLIBAPI short WINAPI eth_dschkdsk( unsigned short, short * );

/*j read inquiry of machine remote diagnosis for ethernet function */
FWLIBAPI short WINAPI eth_rdrmdinquiry( unsigned short, short, short * );

/*j write inquiry of machine remote diagnosis for ethernet function */
FWLIBAPI short WINAPI eth_wrrmdinquiry( unsigned short, short, short );

/* read mode of unsolicited message */
FWLIBAPI short WINAPI eth_rdunsolicmode( unsigned short, short, short * );

/* write mode of unsolicited message */
FWLIBAPI short WINAPI eth_wrunsolicmode( unsigned short, short, short );

/* read state of unsolicited message */
FWLIBAPI short WINAPI eth_rdunsolicstate( unsigned short, short, OUT_UNSOLICSTATE * );

/* apply parameter of unsolicited message */
FWLIBAPI short WINAPI eth_applyunsolicprm( unsigned short, short );

/* copy net-parameter from cnc's SRAM to memory card */
FWLIBAPI short WINAPI net_backup_param( unsigned short, short, char * );

/* copy net-parameter from memory card to cnc's SRAM */
FWLIBAPI short WINAPI net_restore_param( unsigned short, short, char * );

/* read information of FTP server for dataserver function */
FWLIBAPI short WINAPI eth_rdfsclntinfo( unsigned short, OUT_FSINFO * );

/* disconnect a section from FTP server for dataserver function */
FWLIBAPI short WINAPI eth_disconfsclnt( unsigned short, long );

/* disconnect all section from FTP server for dataserver funtion */
FWLIBAPI short WINAPI eth_disconfsclntall( unsigned short );

/* read information of Modbus/TCP client for Modbus/TCP server function */
FWLIBAPI short WINAPI eth_rdmbsclntinfo( unsigned short, OUT_MBSVRINFO * );

/* read information of Modbus/TCP client for Modbus/TCP server function */
FWLIBAPI short WINAPI eth_rdmbsclntinfo2( unsigned short, short, OUT_MBSVRINFO * );

/* read parameter of basic screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_rdeipabscparam( unsigned short, OUT_EIPA_BASIC_PRM * );

/* read parameter of basic screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_rdeipabscparam2( unsigned short, short, OUT_EIPA_BASIC_PRM * );

/* write parameter of basic screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_wreipabscparam( unsigned short, IN_EIPA_BASIC_PRM_FLG *, IN_EIPA_BASIC_PRM * );

/* write parameter of basic screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_wreipabscparam2( unsigned short, short, IN_EIPA_BASIC_PRM_FLG *, IN_EIPA_BASIC_PRM * );

/* read parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_rdeipaalcparam( unsigned short, short, short, OUT_EIPA_ALLOC_PRM * );

/* read parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_rdeipaalcparam2( unsigned short, short, short, short, OUT_EIPA_ALLOC_PRM * );

/* write parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_wreipaalcparam( unsigned short, short, short, IN_EIPA_ALLOC_PRM_FLG *, IN_EIPA_ALLOC_PRM * );

/* write parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_wreipaalcparam2( unsigned short, short, short, short, IN_EIPA_ALLOC_PRM_FLG *, IN_EIPA_ALLOC_PRM * );

/* read information of MS/NS for EtherNet/IP funtion */
FWLIBAPI short WINAPI eth_rdeipmsnsinfo( unsigned short, OUT_EIP_MSNSINFO * );

/* read information of MS/NS for EtherNet/IP funtion */
FWLIBAPI short WINAPI eth_rdeipmsnsinfo2( unsigned short, short, OUT_EIP_MSNSINFO * );

/* read information of device for EtherNet/IP funtion */
FWLIBAPI short WINAPI eth_rdeipdeviceinfo( unsigned short, OUT_EIP_DEVICEINFO * );

/* read information of device for EtherNet/IP funtion */
FWLIBAPI short WINAPI eth_rdeipdeviceinfo2( unsigned short, short, OUT_EIP_DEVICEINFO * );

/* read scanner's list for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_rdeipascnlist( unsigned short, short, short, short *, OUT_EIPA_SCNDATA * );

/* read scanner's list for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_rdeipascnlist2( unsigned short, short, short, short, short *, OUT_EIPA_SCNDATA * );

/* read detail info of connection for EtherNet/IP funtion */
FWLIBAPI short WINAPI eth_rdeiplistdetail( unsigned short, long, OUT_EIP_LISTDETAIL * );

/* read detail info of connection for EtherNet/IP funtion */
FWLIBAPI short WINAPI eth_rdeiplistdetail2( unsigned short, short, long, OUT_EIP_LISTDETAIL * );

/* make EDS file from parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_eipaedsout( unsigned short, char * );

/* make EDS file from parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI short WINAPI eth_eipaedsout2( unsigned short, short, char * );

/* read parameter for EtherNet/IP Scanner funtion */
FWLIBAPI short WINAPI eth_rdeipsparam( unsigned short, short, OUT_EIPS_BASIC_PRM *, OUT_EIPS_STATE_PRM *, OUT_EIPS_ALLOC_PRM * );

/* read parameter for EtherNet/IP Scanner funtion */
FWLIBAPI short WINAPI eth_rdeipsparam2( unsigned short, short, short, OUT_EIPS_BASIC_PRM *, OUT_EIPS_STATE_PRM *, OUT_EIPS_ALLOC_PRM * );

/* write parameter for EtherNet/IP Scanner funtion */
FWLIBAPI short WINAPI eth_wreipsparam( unsigned short, short, short, short, IN_EIPS_BASIC *, IN_EIPS_ALLOC * );

/* write parameter for EtherNet/IP Scanner funtion */
FWLIBAPI short WINAPI eth_wreipsparam2( unsigned short, short, short, short, short, IN_EIPS_BASIC *, IN_EIPS_ALLOC * );

/* read maintenance information for EtherNet/IP Scanner funtion */
FWLIBAPI short WINAPI eth_rdeipsmntinfo( unsigned short, short, OUT_EIPS_COM_INFO *, OUT_EIPS_DETAIL_INFO * );

/* read maintenance information for EtherNet/IP Scanner funtion */
FWLIBAPI short WINAPI eth_rdeipsmntinfo2( unsigned short, short, short, OUT_EIPS_COM_INFO *, OUT_EIPS_DETAIL_INFO * );

/* request identity information of Adapter */
FWLIBAPI short WINAPI eth_reqeipsidinfo( unsigned short, char * );

/* request identity information of Adapter */
FWLIBAPI short WINAPI eth_reqeipsidinfo2( unsigned short, short, char * );

/* responce to request identity information of Adapter */
FWLIBAPI short WINAPI eth_reseipsidinfo( unsigned short, OUT_EIPS_IDENTITY_INFO * );

/* responce to request identity information of Adapter */
FWLIBAPI short WINAPI eth_reseipsidinfo2( unsigned short, short, OUT_EIPS_IDENTITY_INFO * );

/* make EDS file from parameter for EtherNet/IP Scanner funtion */
FWLIBAPI short WINAPI eth_eipsedsout( unsigned short, char * );

/* make EDS file from parameter for EtherNet/IP Scanner funtion */
FWLIBAPI short WINAPI eth_eipsedsout2( unsigned short, short, char * );

/* sort IP Address for EtherNet/IP Scanner funtion */
FWLIBAPI short WINAPI eth_eipsparamsort( unsigned short, short );

/* read maintenance information for EtherNet/IP Safety Adapter funtion */
FWLIBAPI short WINAPI eth_rdeipsafmntinfo( unsigned short, OUT_ADPSAFE_MNTINFO * );

/* make Safety Dump Error file for EtherNet/IP Safety Adapter funtion */
FWLIBAPI short WINAPI eth_eipsafdumperror( unsigned short, char * );

/* make XML file for EtherNet/IP EDA funtion */
FWLIBAPI short WINAPI eth_edaxmlout( unsigned short, short, char * );

/* read type for network function */
FWLIBAPI short WINAPI net_rdtype(unsigned short, short, OUT_NETDEVPRM *);

/* get DNC operation file */
FWLIBAPI short WINAPI cnc_rddsdncfile( unsigned short, char *, short *, char * );

/* set DNC operation file */
FWLIBAPI short WINAPI cnc_wrdsdncfile( unsigned short, char *, char * );

/* set DNC operation file */
FWLIBAPI short WINAPI cnc_wrdsdncfile2( unsigned short, char *, char *, unsigned short );

/* get device infomation for dataserver function */
FWLIBAPI short WINAPI cnc_rddsdevinfo( unsigned short, short, ODBPDFINF * );

/* change operation folder */
FWLIBAPI short WINAPI cnc_rddsdir( unsigned short, char *, short *, char * );

/* get file list infomation */
FWLIBAPI short WINAPI cnc_rddsfile( unsigned short, char *, IN_DSFILE *, OUT_DSINFO *, OUT_DSFILE * );

/* make folder */
FWLIBAPI short WINAPI cnc_dsmkdir( unsigned short, char *, char * );

/* delete folder */
FWLIBAPI short WINAPI cnc_dsrmdir( unsigned short, char *, char * );

/* delete file */
FWLIBAPI short WINAPI cnc_dsremove( unsigned short, char *, char * );

/* change current folder */
FWLIBAPI short WINAPI cnc_dschdir( unsigned short, char *, char *, IN_DSFILE *, OUT_DSINFO *, OUT_DSFILE * );

/* rename folder / file */
FWLIBAPI short WINAPI cnc_dsrename( unsigned short, char *, char *, char * );

/* copy file for dataserver function */
FWLIBAPI short WINAPI cnc_dscopyfile( unsigned short, char *, char * );

/* start GET command for dataserver function */
FWLIBAPI short WINAPI cnc_dsget_req( unsigned short, char *, char *, short );

/* start PUT command for dataserver function */
FWLIBAPI short WINAPI cnc_dsput_req( unsigned short, char *, char * );

/* start MGET command for dataserver function */
FWLIBAPI short WINAPI cnc_dsmget_req( unsigned short, char * );

/* start MPUT command for dataserver function */
FWLIBAPI short WINAPI cnc_dsmput_req( unsigned short, char * );

/* start List-GET command for dataserver function */
FWLIBAPI short WINAPI cnc_dslistget_req( unsigned short, char * );

/* start List-PUT command for dataserver function */
FWLIBAPI short WINAPI cnc_dslistput_req( unsigned short, char * );

/* start List delete for dataserver function */
FWLIBAPI short WINAPI cnc_dslistdel_req( unsigned short, char * );

/* read file transport result for dataserver function */
FWLIBAPI short WINAPI cnc_dsftpstat( unsigned short );

/* cancel to file transport for dataserver function */
FWLIBAPI short WINAPI cnc_dsftpcancel( unsigned short );

/* Reads MAC address */
FWLIBAPI short WINAPI cnc_getmacaddress( unsigned short, char* );

/* search file */
FWLIBAPI short WINAPI cnc_dssearch( unsigned short, char*, char*, unsigned short, unsigned long*  );

/* Data server file read open */
FWLIBAPI short WINAPI cnc_dsrdopen(unsigned short, char*);

/* Data server file read */
FWLIBAPI short WINAPI cnc_dsread(unsigned short, long*, char*);

/* Data server file read close */
FWLIBAPI short WINAPI cnc_dsrdclose(unsigned short);

/* Data server file write open */
FWLIBAPI short WINAPI cnc_dswropen(unsigned short, short, char*);

/* Data server file write */
FWLIBAPI short WINAPI cnc_dswrite(unsigned short, long*, char*);

/* Data server file write close */
FWLIBAPI short WINAPI cnc_dswrclose(unsigned short);

/* start reading file list infomation */
FWLIBAPI short WINAPI cnc_dsfile_req( unsigned short, char *, ODB_IN_DSFILE_REQ * );

/* read file transport result for reading file list infomation */
FWLIBAPI short WINAPI cnc_dsstat_rdfile( unsigned short, char *, ODB_IN_STAT_DSFILE *, OUT_DSINFO *, OUT_DSFILE * );

/*----------------------------*/
/* NET : PROFIBUS function    */
/*----------------------------*/

/* read parameter for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_rd_param(unsigned short, short, T_SLVSLT_IND *, OUT_PBMPRM *);

/* write parameter for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_wr_param(unsigned short, short, IN_PBMPRMFLG *, IN_PBMPRM *);

/* initialize parameter for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_ini_prm(unsigned short, short, T_SLVSLT_IND *);

/* read slave index table for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_rd_allslvtbl(unsigned short, OUT_ALLSLVTBL *);

/* execute sub function for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_exe_subfunc(unsigned short, short, T_SLVSLT_IND *);

/* read sub parameter for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_rd_subprm(unsigned short, short, T_SLVSLT_IND *, OUT_PBMSUBPRM *);

/* read error code for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_rd_errcode(unsigned short, T_ERR_CODE *);

/* change mode for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_chg_mode(unsigned short, unsigned char, OUT_CHGMODERESULT *);

/* read communication information for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_rd_cominfo(unsigned short, short, OUT_PBMCOMINFO *);

/* read node information table for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_rd_nodetable(unsigned short, short, char *);

/* read node information for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_rd_nodeinfo(unsigned short, short, short, OUT_PBMNODEINFO *);

/* read slot number for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_rd_slot(unsigned short, short *);

/* read slot information for PROFIBUS MASTER function */
FWLIBAPI short WINAPI pbm_rd_slotinfo(unsigned short, short, short, OUT_PBMSLOTINFO *);

/* read parameter for PROFIBUS SLAVE fucntion */
FWLIBAPI short WINAPI pbs_rd_param(unsigned short, OUT_PBSPRM *);

/*j write parameter for PROFIBUS SLAVE function */
FWLIBAPI short WINAPI pbs_wr_param(unsigned short, IN_PBSPRMFLG *, IN_PBSPRM *);

/*j initialize parameter for PROFIBUS SLAVE function */
FWLIBAPI short WINAPI pbs_ini_prm(unsigned short, short);

/*j read communication information for PROFIBUS SLAVE function */
FWLIBAPI short WINAPI pbs_rd_cominfo(unsigned short, OUT_PBSSTATUS *);

/* read parameter 2 for PROFIBUS SLAVE fucntion */
FWLIBAPI short WINAPI pbs_rd_param2(unsigned short, OUT_PBSPRM2 *);

/*j write parameter 2 for PROFIBUS SLAVE function */
FWLIBAPI short WINAPI pbs_wr_param2(unsigned short, IN_PBSPRMFLG2 *, IN_PBSPRM2 *);

/*j read communication information 2 for PROFIBUS SLAVE function */
FWLIBAPI short WINAPI pbs_rd_cominfo2(unsigned short, OUT_PBSSTATUS2 *);

/*----------------------------*/
/* NET : DeviceNet function   */
/*----------------------------*/

/* read parameter for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_rdparam(unsigned short, short, short, OUT_DNMPRM *);

/* read parameter for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_rdparam2(unsigned short, short, short, OUT_DNMPRM2 *);

/* write parameter for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_wrparam(unsigned short, short, short, IN_DNMPRMFLAG *, IN_DNMPRM *);

/* write parameter for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_wrparam2(unsigned short, short, short, IN_DNMPRMFLAG2 *, IN_DNMPRM2 *);

/* read node table for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_rdnodetable(unsigned short, OUT_DNMNODE *);

/* read all node infomation for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_rdnodeinfo(unsigned short, short, OUT_DNMNODEINFO *);

/* read firm infomation for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_rdfirminfo(unsigned short, OUT_DNMFIRM *);

/* read error record for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_rderrorrecord(unsigned short, OUT_DNMERR *);

/* clear error record for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_clrerrorrecord(unsigned short);

/* read slave status for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_rdslvstatus(unsigned short, short, unsigned char *);

/* read communication history for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_rd_hist(unsigned short, unsigned short, unsigned short, unsigned short, OUT_DNMHIST *);

/* clear communication history for DeviceNet MASTER function */
FWLIBAPI short WINAPI dnm_clr_hist(unsigned short);

/* read parameter for DeviceNet SLAVE function */
FWLIBAPI short WINAPI dns_rdparam(unsigned short, OUT_DNSPRM *);

/* write parameter for DeviceNet SLAVE function */
FWLIBAPI short WINAPI dns_wrparam(unsigned short, IN_DNSPRMFLAG *, IN_DNSPRM *);

/* read infomation for DeviceNet SLAVE function */
FWLIBAPI short WINAPI dns_rdinfo(unsigned short, OUT_DNSINFO *);

/* restart for DeviceNet SLAVE function */
FWLIBAPI short WINAPI dns_restart(unsigned short);

/* read communication history for DeviceNet SLAVE function */
FWLIBAPI short WINAPI dns_rd_hist(unsigned short, unsigned short, unsigned short, OUT_DNSHIST *);

/* clear communication history for DeviceNet SLAVE function */
FWLIBAPI short WINAPI dns_clr_hist(unsigned short);


/*----------------------------*/
/* NET : FL-net function      */
/*----------------------------*/

/* read parameter for FL-net function */
FWLIBAPI short WINAPI flnt_rdparam(unsigned short, OUT_FLNTPRM *);

/* read parameter for FL-net function */
FWLIBAPI short WINAPI flnt_rdparam2(unsigned short, short, OUT_FLNTPRM *);

/* write parameter for FL-net function */
FWLIBAPI short WINAPI flnt_wrparam(unsigned short, IN_FLNTPRMFLG *, IN_FLNTPRM *);

/* write parameter for FL-net function */
FWLIBAPI short WINAPI flnt_wrparam2(unsigned short, short, IN_FLNTPRMFLG *, IN_FLNTPRM *);

/* read node entry for FL-net function */
FWLIBAPI short WINAPI flnt_rdentry(unsigned short, OUT_FLNTENTRY *);

/* read node entry for FL-net function */
FWLIBAPI short WINAPI flnt_rdentry2(unsigned short, short, OUT_FLNTENTRY *);

/* read node information for FL-net function */
FWLIBAPI short WINAPI flnt_rdnodeinfo(unsigned short, unsigned char, OUT_FLNTNODETBL *);

/* read node information for FL-net function */
FWLIBAPI short WINAPI flnt_rdnodeinfo2(unsigned short, short, unsigned char, OUT_FLNTNODETBL *);

/* read network information for FL-net function */
FWLIBAPI short WINAPI flnt_rdnetwork(unsigned short, OUT_FLNTNETTBL *);

/* read network information for FL-net function */
FWLIBAPI short WINAPI flnt_rdnetwork2(unsigned short, short, OUT_FLNTNETTBL *);

/* clear network information for FL-net function */
FWLIBAPI short WINAPI flnt_clrnetwork(unsigned short);

/* clear network information for FL-net function */
FWLIBAPI short WINAPI flnt_clrnetwork2(unsigned short, short);

/* read log for FL-net function */
FWLIBAPI short WINAPI flnt_rdlog(unsigned short, OUT_FLNTLOG *);

/* read log for FL-net function */
FWLIBAPI short WINAPI flnt_rdlog2(unsigned short, short, OUT_FLNTLOG2 *);

/* clear log for FL-net function */
FWLIBAPI short WINAPI flnt_clrlog(unsigned short);

/* clear log for FL-net function */
FWLIBAPI short WINAPI flnt_clrlog2(unsigned short, short);

/* read message for FL-net function */
FWLIBAPI short WINAPI flnt_rdmsg(unsigned short, short, short, short, OUT_FLNTMSG *);

/* read message for FL-net function */
FWLIBAPI short WINAPI flnt_rdmsg2(unsigned short, short, short, short, short, OUT_FLNTMSG *);

/* clear message for FL-net function */
FWLIBAPI short WINAPI flnt_clrmsg(unsigned short);

/* clear message for FL-net function */
FWLIBAPI short WINAPI flnt_clrmsg2(unsigned short, short);

/* read device information for FL-net function */
FWLIBAPI short WINAPI flnt_rddeviceinfo(unsigned short, OUT_FLNTDEVINFO *);

/* read device information for FL-net function */
FWLIBAPI short WINAPI flnt_rddeviceinfo2(unsigned short, short, OUT_FLNTDEVINFO2 *);

/* read status for FL-net Safety function */
FWLIBAPI short WINAPI flnt_rdsfstatus(unsigned short, short, OUT_FLNTSFSTS *);

/* read error node information for FL-net Safety function */
FWLIBAPI short WINAPI flnt_rdsferrnode(unsigned short, short, OUT_FLNTSFERRTBL *);

/* Read FL-net Sram area (for 16i Series) */
FWLIBAPI short WINAPI cnc_rdflnetsram(unsigned short, short, unsigned long, unsigned long *, void *);

/* Write FL-net Sram area (for 16i Series)  */
FWLIBAPI short WINAPI cnc_wrflnetsram(unsigned short, short, unsigned long, unsigned long *, void *);


/*----------------------------*/
/* NET : CC-Link function     */
/*----------------------------*/

/* read parameter for CC-Link Remote Device function */
FWLIBAPI short WINAPI cclr_rdparam(unsigned short, OUT_CCLRPRM *);

/* write parameter for CC-Link Remote Device function */
FWLIBAPI short WINAPI cclr_wrparam(unsigned short, IN_CCLRPRMFLAG *, IN_CCLRPRM *);

/* read network information for CC-Link Remote Device function */
FWLIBAPI short WINAPI cclr_rdinfo(unsigned short, OUT_CCLRINFO *);


/*----------------------------*/
/* NET : USB function     */
/*----------------------------*/

/* read maintenance information for USB function */
FWLIBAPI short WINAPI usb_rdinfo(unsigned short, short, OUT_USBINFO *);

/* read log for USB function */
FWLIBAPI short WINAPI usb_rdlog(unsigned short, short, short, short, OUT_USBLOG *);

/* clear log for USB function */
FWLIBAPI short WINAPI usb_clrlog(unsigned short);

/* start format for USB function */
FWLIBAPI short WINAPI usb_format_start(unsigned short, short);

/* get result of format for USB function */
FWLIBAPI short WINAPI usb_format_result(unsigned short, short, short *);

/*-----------------------------------*/
/* NET : PROFINET function           */
/*-----------------------------------*/
/* read parameter for PROFINET IO Device funtion */
FWLIBAPI short WINAPI pnd_rdparam( unsigned short, OUT_PND_PARAM * );

/* write parameter for PROFINET IO Device funtion */
FWLIBAPI short WINAPI pnd_wrparam( unsigned short, IN_PND_PARAM * );

/* read maintenance information for PROFINET IO Device funtion */
FWLIBAPI short WINAPI pnd_rdmntinfo( unsigned short, OUT_PND_MNTINFO * );

/* clear maintenance information for PROFINET IO Device funtion */
FWLIBAPI short WINAPI pnd_clrmntinfo( unsigned short );

/* read mode for PROFINET IO Device funtion */
FWLIBAPI short WINAPI pnd_rdmode( unsigned short, unsigned char * );

/* write mode for PROFINET IO Device funtion */
FWLIBAPI short WINAPI pnd_wrmode( unsigned short, unsigned char );

/* make Safety Mainte information file for PROFINET IO Device Safety function  */
FWLIBAPI short WINAPI pnd_outsafemntinfo( unsigned short, char * );

/* read parameter for PROFINET IO Controller funtion */
FWLIBAPI short WINAPI pnc_rdparam(unsigned short, OUT_PNC_PARAM *);

/* write parameter for PROFINET IO Controller funtion */
FWLIBAPI short WINAPI pnc_wrparam(unsigned short, IN_PNC_PARAM *);

/* read maintenance information for PROFINET IO Controller funtion */
FWLIBAPI short WINAPI pnc_rdmntinfo(unsigned short, short, OUT_PNC_CNTRLR_INFO *, OUT_PNC_DEVICE_INFO *, OUT_PNC_ALLCOM_STAT *);

/* request maintenance information for PROFINET IO Controller funtion */
FWLIBAPI short WINAPI pnc_reqdetailinfo(unsigned short, short, short, char *);

/* response maintenance information for PROFINET IO Controller funtion */
FWLIBAPI short WINAPI pnc_resdetailinfo(unsigned short, short, short, OUT_PNC_DETAIL_INFO *);

/* read mode for PROFINET IO Controller funtion */
FWLIBAPI short WINAPI pnc_rdmode(unsigned short, unsigned char *);

/* write mode for PROFINET IO Controller funtion */
FWLIBAPI short WINAPI pnc_wrmode(unsigned short, unsigned char);

/*-----------------------------------*/
/* NET : EtherCAT function           */
/*-----------------------------------*/
FWLIBAPI short WINAPI ect_rdlog(unsigned short, short, short, short, short, OUT_ECTLOG *);

FWLIBAPI short WINAPI ect_clrlog(unsigned short, short);

FWLIBAPI short WINAPI ect_outputlog(unsigned short, char *);

FWLIBAPI short WINAPI ect_rdslvtype(unsigned short, short, OUT_ECTTYPE *);

FWLIBAPI short WINAPI ect_rdslvdeviceinfo(unsigned short, short, OUT_ECTDEVINFO *);

FWLIBAPI short WINAPI ect_rdslvnetwork(unsigned short, short, OUT_ECTNETINFO *);

FWLIBAPI short WINAPI ect_chgslvmode(unsigned short, short, unsigned short);

FWLIBAPI short WINAPI ect_outputesi(unsigned short, char *);

/*--------------------------*/
/* HSSB multiple connection */
/*--------------------------*/

/* read number of node */
FWLIBAPI short WINAPI cnc_rdnodenum( long * );

/* read node informations */
FWLIBAPI short WINAPI cnc_rdnodeinfo( long, ODBNODE * );

/* set default node number */
FWLIBAPI short WINAPI cnc_setdefnode( long );

/* allocate library handle 2 */
FWLIBAPI short WINAPI cnc_allclibhndl2( long, unsigned short * );


/*---------------------*/
/* Ethernet connection */
/*---------------------*/

/* allocate library handle 3 */
FWLIBAPI short WINAPI cnc_allclibhndl3( const char *, unsigned short, long, unsigned short * );

/* allocate library handle 4 */
FWLIBAPI short WINAPI cnc_allclibhndl4( const char *, unsigned short, long, unsigned long, unsigned short * );

/* set timeout for socket */
FWLIBAPI short WINAPI cnc_settimeout( unsigned short, long );

/* reset all socket connection */
FWLIBAPI short WINAPI cnc_resetconnect( unsigned short );

/* get option state for FOCAS1/Ethernet */
FWLIBAPI short WINAPI cnc_getfocas1opt( unsigned short, short, long * );

/* read Ethernet board information */
FWLIBAPI short WINAPI cnc_rdetherinfo( unsigned short, short *, short * ) ;

/*--------------------------*/
/*  Power Mate CNC manager  */
/*--------------------------*/

/* initialize */
FWLIBAPI short WINAPI cnc_pmminit( unsigned short, long, ODBPMMSLV *);

/* check alarm status */
FWLIBAPI short WINAPI cnc_pmmchkalm(unsigned short, long, long *);

/* get serise , version */
FWLIBAPI short WINAPI cnc_pmmsysdt(unsigned short, long, long, ODBPMMSYD *);

/* get continous data start */
FWLIBAPI short WINAPI cnc_pmmgetstart(unsigned short, long, long, long, IDBPMMGTI *);

/* get continous data */
FWLIBAPI short WINAPI cnc_pmmget(unsigned short, long, long, long, ODBPMMGET *);

/* get continous end */
FWLIBAPI short WINAPI cnc_pmmgetend(unsigned short, long, long, long);

/* get parameter 1 page */
FWLIBAPI short WINAPI cnc_pmmprmpage(unsigned short, long, long, long, long, ODBPMMPRP *);

/* write parameter */
FWLIBAPI short WINAPI cnc_wrpmmprm(unsigned short, long, long, long, ODBPMMPRP *);

/* read parameter (tape memory) */
FWLIBAPI short WINAPI cnc_rdpmmprmtp(unsigned short, IDBPMMPRP *);

/* write parameter (tape memory) */
FWLIBAPI short WINAPI cnc_wrpmmprmtp(unsigned short, IDBPMMPRP *);

/* I/O LINK channel number */
FWLIBAPI short WINAPI cnc_pmmiochanl(unsigned short, ODBPMMIO *);

/* read PMC path & PMC addr F/G signal */
FWLIBAPI short WINAPI cnc_rdioassigned( unsigned short, unsigned short *, unsigned short * ) ;

/*---------------------*/
/* Background function */
/*---------------------*/

/* read absolute axis position (BG) */
FWLIBAPI short WINAPI cnc_absolute_bg( unsigned short, short, short, ODBAXIS * ) ;

/* read relative axis position (BG) */
FWLIBAPI short WINAPI cnc_relative_bg( unsigned short, short, short, ODBAXIS * ) ;

/* read machine axis position (BG) */
FWLIBAPI short WINAPI cnc_machine_bg( unsigned short, short, short, ODBAXIS * ) ;

/* read current program and its pointer (BG) */
FWLIBAPI short WINAPI cnc_pdf_rdactpt_bg( unsigned short, char * , long * ) ;

/* set current program and its pointer (BG) */
FWLIBAPI short WINAPI cnc_pdf_wractpt_bg( unsigned short, char * , short, long * ) ;

/* read CNC status information (BG) */
FWLIBAPI short WINAPI cnc_statinfo_bg( unsigned short, ODBST * ) ;

/* read sequence number under execution (BG) */
FWLIBAPI short WINAPI cnc_rdseqnum_bg( unsigned short, ODBSEQ * ) ;

/* read modal data (BG) */
FWLIBAPI short WINAPI cnc_modal_bg( unsigned short, short, short, ODBMDL * ) ;

/* Get distribute infomation (BG) */
FWLIBAPI short WINAPI cnc_rdipltp_bg( unsigned short, ODBIPL *buf );

/* Get next axis distance (BG) */
FWLIBAPI short WINAPI cnc_nextdistance_bg( unsigned short, short, short, IODBAXIS * );

/* read tool offset value (BG) */
FWLIBAPI short WINAPI cnc_rdtofs_bg( unsigned short, short, short, short, ODBTOFS * ) ;

/* read tool offset value(area specified) (BG) */
FWLIBAPI short WINAPI cnc_rdtofsr_bg( unsigned short, short, short, short, short, IODBTO * ) ;

/* read work zero offset value (BG) */
FWLIBAPI short WINAPI cnc_rdzofs_bg( unsigned short, short, short, short, IODBZOFS * ) ;

/* read work zero offset value(area specified) (BG) */
FWLIBAPI short WINAPI cnc_rdzofsr_bg( unsigned short, short, short, short, short, IODBZOR * ) ;

/* read work coordinate shift (BG) */
FWLIBAPI short WINAPI cnc_rdwkcdshft_bg( unsigned short, short, short, IODBWCSF * ) ;

/* read alarm information (BG) */
FWLIBAPI short WINAPI cnc_rdalminfo_bg( unsigned short, short, short, short, ALMINFO * ) ;

/* read program number under execution (BG) */
FWLIBAPI short WINAPI cnc_rdprgnumo8_bg( unsigned short, ODBPROO8 * ) ;

/* read program under execution (BG) */
FWLIBAPI short WINAPI cnc_rdexecprog_bg( unsigned short, unsigned short *, short *, char * ) ;

/* read absolute axis position (with compensation) */
FWLIBAPI short WINAPI cnc_absolute_mgi( unsigned short, short, short, ODBAXIS * ) ;

/*-----------------------------*/
/* Dual Check Safety Functions */
/*-----------------------------*/
/* Get dual check safety MCC test status */
FWLIBAPI short WINAPI cnc_get_mccteststs(unsigned short, short *, DCSMCA * );

/* Get dual check safety Flow Monitor */
FWLIBAPI short WINAPI cnc_get_flowmonitor(unsigned short, short, short *, ODBDCSFMONI * );

/* Get dual check safety Cross Check Alarm */
FWLIBAPI short WINAPI cnc_get_crosschk_alarm (unsigned short, DCSCRSALM * );

/* Get dual check safety Monitoring Data(Feed, Machine Position, Position Error) */
FWLIBAPI short WINAPI cnc_get_safetysts(unsigned short, short, short, short *, DCSSVSPSTS *);

/* Get dual check safety Monitoring Data(Limit, Axis status, Unit ) */
FWLIBAPI short WINAPI cnc_get_safetysts2(unsigned short, short, short, short *, DCSSVSPST2 *);

/*-----------------------------*/
/* Real-time custom macro      */
/*-----------------------------*/
/* get the number of real-time custom macro non-volatile variables */
FWLIBAPI short WINAPI cnc_getrtmrvars ( unsigned short, long * ) ;

/* read real-time custom macro non-volatile variables (IEEE double version only) */
FWLIBAPI short WINAPI cnc_rdrtmrvars ( unsigned short, long, long *, double * ) ;

/* write real-time custom macro non-volatile variables (IEEE double version only) */
FWLIBAPI short WINAPI cnc_wrrtmrvars ( unsigned short, long, long *, double * ) ;

/* get the number of real-time custom macro volatile variables */
FWLIBAPI short WINAPI cnc_getrtmrvar ( unsigned short, long * ) ;

/* read real-time custom macro volatile variables (IEEE double version only) */
FWLIBAPI short WINAPI cnc_rdrtmrvar ( unsigned short, long, long *, double * ) ;

/* write real-time custom macro volatile variables (IEEE double version only) */
FWLIBAPI short WINAPI cnc_wrrtmrvar ( unsigned short, long, long *, double * ) ;

/* read real-time custom macro di/do variables write enable status  (per byte) */
FWLIBAPI short WINAPI cnc_getrtmioinfo ( unsigned short, short, IODBRTMIOR *, unsigned long * ) ;

/* get the number of real-time custom macro di/do variable range index */
FWLIBAPI short WINAPI cnc_getrtmiorngnum ( unsigned short, unsigned long * ) ;

/* read real-time custom macro di/do variables write enable information */
FWLIBAPI short WINAPI cnc_rdrtmiowrenbl ( unsigned short, IODBRTMIO *, unsigned long *, char * ) ;

/* write real-time custom macro di/do variables write enable status (per byte) */
FWLIBAPI short WINAPI cnc_wrrtmiowrenbl ( unsigned short, IODBRTMIO *, unsigned long *, char * ) ;

/* read real-time custom macro di/do variables write enable status  (bit) */
FWLIBAPI short WINAPI cnc_rdrtmiowrenblbit ( unsigned short, IODBRTMIO *, char * ) ;

/* write real-time custom macro di/do variables write enable status (per byte) */
FWLIBAPI short WINAPI cnc_wrrtmiowrenblbit ( unsigned short, IODBRTMIO *, char *, long ) ;

/* read real-time custom macro di/do variables write enable status (valid range) */
FWLIBAPI short WINAPI cnc_rdrtmiowrenblrng ( unsigned short, IODBRTMIOR *, long, unsigned long * ) ;

/* write real-time custom macro di/do variables write enable status (valid range) */
FWLIBAPI short WINAPI cnc_wrrtmiowrenblrng ( unsigned short, IODBRTMIOR *, long, unsigned long * ) ;

/*--------------------*/
/* RENISHAW function  */
/*--------------------*/
/* Start renishaw PLUTO sumpling */
FWLIBAPI short WINAPI cnc_stplutosmpl( unsigned short, short, char * ) ;

/* Read  renishaw PLUTO sumpling */
FWLIBAPI short WINAPI cnc_rdplutosmpl( unsigned short, long *, ODBRENPLT *) ;

/* End   renishaw PLUTO sumpling */
FWLIBAPI short WINAPI cnc_edplutosmpl( unsigned short ) ;

/*---------------------------------------------*/
/* continuous positional data output function  */
/*---------------------------------------------*/
/* Start sampling */
FWLIBAPI short WINAPI cnc_stpossmpl( unsigned short, short, char * ) ;

/* Read sampling */
FWLIBAPI short WINAPI cnc_rdpossmpl( unsigned short, long *, ODBRENPLT *) ;

/* End sampling */
FWLIBAPI short WINAPI cnc_endpossmpl( unsigned short ) ;

/*------------------------*/
/* Custom Board function  */
/*------------------------*/
typedef struct iodbcbp {
    short datano ;
    short type ;
    union {
        char    cdata ;
        short   idata ;
        long    ldata ;
        REALPRM rdata ;
        char    cdatas[32] ;
        short   idatas[32] ;
        long    ldatas[32] ;
        REALPRM rdatas[32] ;
    } u ;
} IODBCBP;



FWLIBAPI short WINAPI cnc_rdcbmem( unsigned short , long , long , void* ) ;
FWLIBAPI short WINAPI cnc_rdcbmem2( unsigned short , short, long , long , void* ) ;
FWLIBAPI short WINAPI cnc_wrcbmem( unsigned short , long , long , void* ) ;
FWLIBAPI short WINAPI cnc_wrcbmem2( unsigned short , short, long , long , void* ) ;
FWLIBAPI short WINAPI cnc_rdcbprm( unsigned short , short* , short , short*, short*, void* ) ;
FWLIBAPI short WINAPI cnc_wrcbprm( unsigned short , short* , void* ) ;

/*--------------------*/
/* schedule function  */
/*--------------------*/
/* write schedule data */
FWLIBAPI short WINAPI cnc_wrscdldat(unsigned short FlibHndl, short s_number, short e_number, short length, SCDL_1D scdldat[]);

/* read schedule data */
FWLIBAPI short WINAPI cnc_rdscdldat(unsigned short FlibHndl, short s_number, short e_number, short length, SCDL_1D scdldat[]);

/* read schedule information */
FWLIBAPI short WINAPI cnc_rdscdlinfo(unsigned short FlibHndl, short *scdl_mode, short *scdl_num, short *data_no, short *crnt_no);

/*---------------------*/
/* path table function */
/*---------------------*/
/* analysis data set */
FWLIBAPI short WINAPI cnc_startptcnv( unsigned short FlibHndl, short *request );
/* read execution state */
FWLIBAPI short WINAPI cnc_rdptcnvinfo( unsigned short FlibHndl, short *executing, long *conv_status, short *ofs_change );
/* alarm conversion */
FWLIBAPI short WINAPI cnc_rdptcnvalm( unsigned short FlibHndl, long *alm_no, char *prog_name, char *prog_data );

/*-------------------------------*/
/* path table function (for DGN) */
/*-------------------------------*/
/* alarm execution */
FWLIBAPI short WINAPI cnc_rdptexedistalm( unsigned short FlibHndl, long *dist_alm_no );
/* read execution state (for axis table)*/
FWLIBAPI short WINAPI cnc_rdptaxitablestatus( unsigned short FlibHndl, short type, short axis, ODBPTAXISTAT *odbptaxistat );
/* read execution state (for spindle table)*/
FWLIBAPI short WINAPI cnc_rdptsptablestatus( unsigned short FlibHndl, short type, short axis, ODBPTSPSTAT *odbptspstat );
/* read execution state (for auxiliary-function table)*/
FWLIBAPI short WINAPI cnc_rdptaxfunctablestatus( unsigned short FlibHndl, short type, ODBPTAXFUNCSTAT *odbptaxistat );

/*---------------------------------------------*/
/* path table function (for Direct Conversion) */
/*---------------------------------------------*/
#ifndef CNC_PPC
/* clear Path Table executive form data */
FWLIBAPI short WINAPI cnc_clrptdata( unsigned short FlibHndl );
/* start direct conversion */
FWLIBAPI short WINAPI cnc_ptdwnstart( unsigned short FlibHndl );
/* direct conversion */
FWLIBAPI short WINAPI cnc_ptdownload( unsigned short FlibHndl, long *length, char *data );
/* end direct conversion */
FWLIBAPI short WINAPI cnc_ptdwnend( unsigned short FlibHndl );
/* binary data link */
FWLIBAPI short WINAPI cnc_ptlink( unsigned short FlibHndl, short backup );
/* binary data link (2) */
FWLIBAPI short WINAPI cnc_ptlink2( unsigned short FlibHndl );
#endif
/* select binary data memory */
FWLIBAPI short WINAPI cnc_slctptdata( unsigned short FlibHndl, short num );
/* select binary data memory type */
FWLIBAPI short WINAPI cnc_slctpttype( unsigned short FlibHndl, short type );
/* read execution state (2) */
FWLIBAPI short WINAPI cnc_rdptcnvinfo2( unsigned short FlibHndl, ODBPTCNVINFO2 *cnvinfo );

/*----------------------------------------------*/
/* Path Table Operation status display function */
/*----------------------------------------------*/
/* read comment, T code, PTO execution status information */
FWLIBAPI short WINAPI cnc_rdptcomment( unsigned short FlibHndl, ODBPTCOMMENT *odbptcomment ) ;

/* Path Table Oparation History */
FWLIBAPI short WINAPI cnc_rdpthis_num( unsigned short FlibHndl, long* hist_num );
FWLIBAPI short WINAPI cnc_rdpthis_gb( unsigned short FlibHndl, long hist_idx, ODBPTHIS_GB *odbpthis_gb );
FWLIBAPI short WINAPI cnc_rdpthis_pt( unsigned short FlibHndl, long hist_idx, long path, ODBPTHIS_PT *odbpthis_pt );
FWLIBAPI short WINAPI cnc_rdpthis_ax( unsigned short FlibHndl, long hist_idx, long path, long axis, ODBPTHIS_AX *odbpthis_ax );
FWLIBAPI short WINAPI cnc_rdpthis_sp( unsigned short FlibHndl, long hist_idx, long path, long spdl, ODBPTHIS_SP *odbpthis_sp );
FWLIBAPI short WINAPI cnc_rdpthis_aux( unsigned short FlibHndl, long hist_idx, long path, ODBPTHIS_AUX *odbpthis_aux );
FWLIBAPI short WINAPI cnc_rdpthis_log( unsigned short FlibHndl, long hist_idx, long type, long path, long idx, long* count, ODBPTHIS_LOG *odbpthis_log );

/* Path Table Operation stop at specified reference time */
FWLIBAPI short WINAPI cnc_rdptstoptime( unsigned short, double* stop_time);
FWLIBAPI short WINAPI cnc_wrptstoptime( unsigned short, double stop_time);

/* Arbitrary allocating function of path table executive form data area */
FWLIBAPI short WINAPI cnc_rdptcmdsize( unsigned short, short cmd_id, long* cmd_size );

/*---------------------*/
/* DataServer version  */
/*---------------------*/
FWLIBAPI short WINAPI cnc_dtsvinfo(unsigned short  h ,short *dtsvver);

/*---------------------*/
/* System Alarm Data   */
/*---------------------*/
FWLIBAPI short WINAPI cnc_delsysalm(unsigned short FlibHndl);
FWLIBAPI short WINAPI cnc_rdsysalm(unsigned short FlibHndl, short kind, short page, unsigned short length, char *data);

/*-----------------------*/
/* Parallel axis control */
/*-----------------------*/
FWLIBAPI short WINAPI cnc_rdpalaxis(unsigned short FlibHndl, short axis, IODBPALAX *palax);

/*------------------------*/
/* handle retrace message */
/*------------------------*/
FWLIBAPI short WINAPI cnc_hdck_nochange_info(unsigned short FlibHndl, short path_no, ODBAHDCK *hdck_info);

/*------------------------*/
/* Program ex-restart     */
/*------------------------*/
FWLIBAPI short WINAPI cnc_rstrt_getpntcnt(unsigned short, short *);
FWLIBAPI short WINAPI cnc_rstrt_rdpntlist(unsigned short, short, short *, ODBRSTLIST *);
FWLIBAPI short WINAPI cnc_rstrt_rdpnt(unsigned short, short, IODBRSTINFO *);
FWLIBAPI short WINAPI cnc_rstrt_rdmodal(unsigned short, short, short *, short *, ODBGCD *, ODBCMD *);
FWLIBAPI short WINAPI cnc_rstrt_selectpnt(unsigned short, short);
FWLIBAPI short WINAPI cnc_rstrt_wrpnt(unsigned short, unsigned short, IODBRSTINFO *);
FWLIBAPI short WINAPI cnc_rstrt_createpnt(unsigned short);
FWLIBAPI short WINAPI cnc_rstrt_search(unsigned short, short);
FWLIBAPI short WINAPI cnc_rstrt_setsuppress(unsigned short, short,short);
FWLIBAPI short WINAPI cnc_rstrt_rdpntlist2(unsigned short, short, short *, ODBRSTLIST2 *);
FWLIBAPI short WINAPI cnc_rstrt_rdpnt2(unsigned short, short, IODBRSTINFO2 *);
FWLIBAPI short WINAPI cnc_rstrt_wrpnt2(unsigned short, unsigned short, IODBRSTINFO2 *);
FWLIBAPI short WINAPI cnc_rstrt_getdncprg(unsigned short, short, char *);
FWLIBAPI short WINAPI cnc_rstrt_rdaddinfo(unsigned short, short, short *, short, long *);
FWLIBAPI short WINAPI cnc_rstrt_rdlpmppnt(unsigned short, short, ODBRSTMPINFO *);
/*---------------------*/
/* spindle unit offset */
/*---------------------*/
FWLIBAPI short WINAPI cnc_rdsuofs_vect( unsigned short FlibHndl, short ax_idx, short *ax_cnt, ODBSUOVECT *su_ofs_info );
FWLIBAPI short WINAPI cnc_rdnutatortofs_vect ( unsigned short FlibHndl, short ax_idx, short *ax_cnt, ODBSUOVECT *su_ofs_info );
FWLIBAPI short WINAPI cnc_rdsuo_prm_name( unsigned short h, short data_idx, ODBSUODATA *su_data, short *length );
/*---------------------*/
/* Memory Card         */
/*---------------------*/
/* Get informatin of files in Memory card */
FWLIBAPI short WINAPI cnc_rdmcdfinfo(unsigned short FlibHndl, long file_no, ODBFILESTATUS *file_inf);
/* Cancel informatin of files in Memory card */
FWLIBAPI short WINAPI cnc_canmcdfinfo(unsigned short FlibHndl);
/* Check existence of file in Memory card */
FWLIBAPI short WINAPI cnc_chkmcdfile(unsigned short FlibHndl, char* fname, char* exist);
/* Delete file in Memory card */
FWLIBAPI short WINAPI cnc_delmcdfile(unsigned short FlibHndl, char* fname);
/* Delete file by number in Memory card */
FWLIBAPI short WINAPI cnc_delmcdfilebynum(unsigned short FlibHndl, long file_no);
/* Get program comment in Memory card */
FWLIBAPI short WINAPI cnc_rdmcdprgcmnt(unsigned short FlibHndl, char *fname, ODBPROGINFO *prog_inf);

FWLIBAPI short WINAPI cnc_rdpmcaxisinfo(unsigned short FlibHndl, short axis, short type, ODBPMCAXISINFO *pmcaxisinfo);

/*---------------------*/
/* USB Memory          */
/*---------------------*/
FWLIBAPI short WINAPI cnc_rdusbdevinfo(unsigned short, char, ODBUSBSIZE *);
FWLIBAPI short WINAPI cnc_rdusbfilelist(unsigned short, IDBUSBFILE *, ODBUSBINFO *, ODBUSBFILE *);
FWLIBAPI short WINAPI cnc_usbmkdir(unsigned short, char *);
FWLIBAPI short WINAPI cnc_usbrmdir(unsigned short, char *);
FWLIBAPI short WINAPI cnc_usbremove(unsigned short, char *);
FWLIBAPI short WINAPI cnc_usbrename(unsigned short, char *, char *);
FWLIBAPI short WINAPI cnc_chkusbfile(unsigned short, char* , char* );
FWLIBAPI short WINAPI cnc_searchusbfile(unsigned short, IDBUSBSEARCH *, unsigned long *);
FWLIBAPI short WINAPI cnc_chkusbmount (unsigned short, char, unsigned short * );
FWLIBAPI short WINAPI cnc_writeusbfile(unsigned short h, char* path, char* buf, long buf_size);
/*---------------------------------------------*/
/* IS-E long stroke type                       */
/*---------------------------------------------*/
/* read various axis data (IEEE double version) */
FWLIBAPI short WINAPI cnc_rdaxisdata64( unsigned short, short, short *, short, short *, ODBAXDT64 * );

/* preset work coordinate (IEEE double version) */
FWLIBAPI short WINAPI cnc_prstwkcd64( unsigned short, short, IDBWRA64 * ) ;

/* set origin / preset relative axis position (IEEE double version) */
FWLIBAPI short WINAPI cnc_wrrelpos64( unsigned short, short, IDBWRR64 * ) ;

/* read command value (IEEE double version) */
FWLIBAPI short WINAPI cnc_rdcommand64( unsigned short, short, short, short *, ODBCMD64 * ) ;

/* read parameter (IEEE double version) */
FWLIBAPI short WINAPI cnc_rdparam64( unsigned short, short, short, short, short, IODBPSD64 * ) ;

/* write parameter (IEEE double version) */
FWLIBAPI short WINAPI cnc_wrparam64( unsigned short, short, short, IODBPSD64 * ) ;

/* read validity of work zero offset (IEEE double version) */
FWLIBAPI short WINAPI cnc_zofs_rnge64( unsigned short, short, short, ODBDATRNG64 * );

/* read work zero offset value(area specified) */
FWLIBAPI short WINAPI cnc_rdzofsr64( unsigned short, short, short, short, short, IODBZOR64 * ) ;

/* write work zero offset value (IEEE double version) */
FWLIBAPI short WINAPI cnc_wrzofs64( unsigned short, short, IODBZOFS64 * ) ;

/* read validity of work shift value (IEEE double version) */
FWLIBAPI short WINAPI cnc_wksft_rnge64( unsigned short, short, ODBDATRNG64 * );

/* read work coordinate shift64 (IEEE double version) */
FWLIBAPI short WINAPI cnc_rdwkcdshft64( unsigned short, short, short, short, IODBWCSF64 * ) ;

/* write work coordinate shift64 (IEEE double version) */
FWLIBAPI short WINAPI cnc_wrwkcdshft64( unsigned short, short, short, IODBWCSF64 * );

/* read work coordinate shift measure64 (IEEE double version) */
FWLIBAPI short WINAPI cnc_rdwkcdsfms64( unsigned short, short, short, short, IODBWCSF64 * );

/* write work coordinate shift measure64 (IEEE double version) */
FWLIBAPI short WINAPI cnc_wrwkcdsfms64( unsigned short, short, short, IODBWCSF64 * );

/* read diagnosis data (IEEE double version) */
FWLIBAPI short WINAPI cnc_diagnoss64( unsigned short, short, short, short, ODBDGN64 * );

/* read diagnosis data (IEEE double version) */
FWLIBAPI short WINAPI cnc_diagnosr64( unsigned short, short *, short, short *, short *, void * ) ;

/* Set Tool Offset Direct Input (IEEE double version) */
FWLIBAPI short WINAPI cnc_wrtofsdrctinp64( unsigned short, short, short, REALMES64 );

/* read hole measurement data (IEEE double version) */
FWLIBAPI short WINAPI cnc_rdholmes64(unsigned short, ODBHOLDATA64 * );

/* read center data (IEEE double version) */
FWLIBAPI short WINAPI cnc_rdcenter64(unsigned short, double *, double *, long *, long *, long *, long * );

/* read work offset measurement data (IEEE double version) */
FWLIBAPI short WINAPI cnc_rdzofsmes64(unsigned short, long, double, long, double *, long * );

/*----------------------------*/
/* High-speed Program Manager */
/*----------------------------*/
/* Calling with  function of program save */
FWLIBAPI short WINAPI cnc_saveprog_start(unsigned short FlibHndl);
/* Get the result of cnc_saveprog_start function */
FWLIBAPI short WINAPI cnc_saveprog_end(unsigned short FlibHndl, short *result);

/*------------------------*/
/* Modification detection */
/*------------------------*/
FWLIBAPI short WINAPI cnc_mdd_unlock( unsigned short, short, char * );
FWLIBAPI short WINAPI cnc_mdd_lock( unsigned short, short );
FWLIBAPI short WINAPI cnc_mdd_setpassword( unsigned short, short, char * );
FWLIBAPI short WINAPI cnc_mdd_unregister( unsigned short, short );
FWLIBAPI short WINAPI cnc_mdd_register( unsigned short, short );
FWLIBAPI short WINAPI cnc_mdd_rdinfo( unsigned short, short, ODBMDDINFO * );
FWLIBAPI short WINAPI cnc_mdd_setswitch( unsigned short, short, unsigned short );
FWLIBAPI short WINAPI cnc_mdd_getswitch( unsigned short, short, unsigned short * );
FWLIBAPI short WINAPI cnc_mdd_setexceptparam(unsigned short, short, short, IODBMDDEXCEPTPRM *);
FWLIBAPI short WINAPI cnc_mdd_getexceptparam(unsigned short, short, short, IODBMDDEXCEPTPRM *);
FWLIBAPI short WINAPI cnc_mdd_update( unsigned short, short);

/*------------------------*/
/* Robot Connect Function */
/*------------------------*/
/* read robot signal status*/
FWLIBAPI short WINAPI cnc_robo_rdsignals(unsigned short, char, char, unsigned short, unsigned short *, ODBRBSIGNAL *);
/* read robot alarm messages*/
FWLIBAPI short WINAPI cnc_robo_rdalmmsg(unsigned short, unsigned short, unsigned short*, IODBRBALMMSG *alm_msg);
/* read robot-NC program groups*/
FWLIBAPI short WINAPI cnc_robo_rdgrouplist(unsigned short , unsigned short, unsigned short*, ODBRBGRPLIST*);
/* write robot-NC program group*/
FWLIBAPI short WINAPI cnc_robo_wrgroup(unsigned short, unsigned short, IDBRBGROUP *);
/* select robot-NC proguram group*/
FWLIBAPI short WINAPI cnc_robo_selectgroup(unsigned short, unsigned short);
/* write robot signal names*/
FWLIBAPI short WINAPI cnc_robo_wrsignalname(unsigned short, char, unsigned short, unsigned short*, IDBRBSIGNAL*);
/* write robot alarm messages*/
FWLIBAPI short WINAPI cnc_robo_wralmmsg(unsigned short, unsigned short, unsigned short*, IODBRBALMMSG*);
/* write robot communication setting*/
FWLIBAPI short WINAPI cnc_robo_wrcomsetting(unsigned short, unsigned short, IODBRBCOMSET*);
/* read robot communication setting*/
FWLIBAPI short WINAPI cnc_robo_rdcomsetting(unsigned short, IODBRBCOMSET *);
/* write selected signals */
FWLIBAPI short WINAPI cnc_robo_wrselectedsignals(unsigned short, unsigned short, unsigned short*,IODBRBSUMMARY *);
/* read selected signals*/
FWLIBAPI short WINAPI cnc_robo_rdselectedsignals(unsigned short, unsigned short, unsigned short*,IODBRBSUMMARY *);

/* read robot signal status*/
FWLIBAPI short WINAPI cnc_robo_rdsignals2(unsigned short, char, char, unsigned short, unsigned short *, IODBRBSIGNAL2 *);
/* write robot signal status*/
FWLIBAPI short WINAPI cnc_robo_wrsignals2(unsigned short, char, unsigned short, unsigned short, IODBRBSIGNAL2 *);
/* clear robot signal status*/
FWLIBAPI short WINAPI cnc_robo_clrsignals(unsigned short);
/* read property at power-on*/
FWLIBAPI short WINAPI cnc_robo_rdponprop(unsigned short, unsigned char *);

/*------------------------------*/
/* T-code Message Read Function */
/*------------------------------*/
/* read tcode message */
FWLIBAPI short WINAPI cnc_rdtcodemsg(unsigned short, char *);

/*------------------------*/
/* Auxiliary status       */
/*------------------------*/
FWLIBAPI short WINAPI cnc_aux_statinfo(unsigned short h, unsigned long *stat);

/* Read IndexAxis data  ( idxax paramter screen )       */
FWLIBAPI short WINAPI cnc_rdindexprm( unsigned short, short, IODBINDEXPRM * );
/* Write IndexAxis data ( idxax paramter screen )       */
FWLIBAPI short WINAPI cnc_wrindexprm( unsigned short, short, short, IODBINDEXPRM * );
/* Read IndexAxis data  ( idxax position screen )       */
FWLIBAPI short WINAPI cnc_rdindexdata( unsigned short, short, short, short *, IODBINDEXDAT * );
/* Write IndexAxis data ( idxax position screen )       */
FWLIBAPI short WINAPI cnc_wrindexdata( unsigned short, short, short, short, IODBINDEXDAT * );
/* Read IndexAxis offset data  ( idxax position screen )*/
FWLIBAPI short WINAPI cnc_rdindexofs( unsigned short, short, long * );
/* Write IndexAxis offset data ( idxax position screen )*/
FWLIBAPI short WINAPI cnc_wrindexofs( unsigned short, short, long * );
/* Read IndexAxis data  ( idxax pos-switch screen )     */
FWLIBAPI short WINAPI cnc_rdindexposdata( unsigned short, short, short, short *, IODBINDEXPOSDAT * );
/* Write IndexAxis data ( idxax pos-switch screen )     */
FWLIBAPI short WINAPI cnc_wrindexposdata( unsigned short, short, short, short, IODBINDEXPOSDAT * );
/* Read IndexAxis infomation for idxax screen           */
FWLIBAPI short WINAPI cnc_rdindexinfo( unsigned short, short, ODBINDEXINFO * );

/*------------------------*/
/* Chopping Function      */
/*------------------------*/
FWLIBAPI short WINAPI cnc_rdchopping(unsigned short h, ODBCHOPPING *chopping);

/*----------------------------*/
/* Safety I/O signal history  */
/*----------------------------*/
/* read safety I/O signal history log information */
FWLIBAPI short WINAPI cnc_rd_sfsg_loginf( unsigned short, ODBSFSGLOGINF *sfsgloginf);
/* read safety I/O signal history signal information */
FWLIBAPI short WINAPI cnc_rd_sfsg_siginf( unsigned short, short sno_sig, short *len_sig, short extract,
                            ODBSFSGSIGINFEX *sfsg_siginf_ex_pmc,
                            ODBSFSGSIGINFEX *sfsg_siginf_ex_dcs);
/* read safety I/O signal history signal history */
FWLIBAPI short WINAPI cnc_rd_sfsg_sighis( unsigned short, IODBSFSGSIGHIS *sfsg_sighis, unsigned char *sig_his_pmc, unsigned char *sig_his_dcs);
/* read safety I/O signal history total signal number */
FWLIBAPI short WINAPI cnc_rd_sfsg_signal_num( unsigned short, ODBSFSGSIGNALNUM *sfsg_signal_num);
/* read safety I/O signal history alarm count */
FWLIBAPI short WINAPI cnc_rd_sfsg_update_count( unsigned short, unsigned short *update_count);
/* read safety I/O signal history signal search */
FWLIBAPI short WINAPI cnc_rd_sfsg_search( unsigned short, IODBSFSGSIGINF *sfsg_siginf, short extract, short *no_sig);
/* write safety I/O signal history extract status */
FWLIBAPI short WINAPI cnc_wr_sfsg_extractslct( unsigned short, short no_sig, short select, short extract);
/* read safety I/O signal history display status */
FWLIBAPI short WINAPI cnc_rd_sfsg_disp_stat( unsigned short, IODBSFSGDSPSTAT *sfsg_dsp_stat);
/* write safety I/O signal history display status */
FWLIBAPI short WINAPI cnc_wr_sfsg_disp_stat( unsigned short, IODBSFSGDSPSTAT *sfsg_dsp_stat, short select);

/*-------------------------------------------------------*/
/* 5 axis machining configuration selection function     */
/*-------------------------------------------------------*/
/* read 5-axis machining configuration data */
FWLIBAPI short WINAPI cnc_s5s_rdparam(unsigned short FlibHndl, short set_num, short number, short axis, short length, IODBPSD *param); 
/* write 5-axis machining configuration data */
FWLIBAPI short WINAPI cnc_s5s_wrparam(unsigned short FlibHndl, short set_num, short length, IODBPSD *param);
/* read 5-axis machining configuration name */
FWLIBAPI short WINAPI cnc_s5s_rdname(unsigned short FlibHndl,short set_num, char *setname);
/* write 5-axis machining configuration name */
FWLIBAPI short WINAPI cnc_s5s_wrname(unsigned short FlibHndl, short set_num, char *setname);
/* read maximum, minimum and total number of 5-axis machining configuration data */
FWLIBAPI short WINAPI cnc_s5s_rdparanum(unsigned short FlibHndl, ODBPARANUM *paranum);
/* read informations of 5-axis machining configuration data */
FWLIBAPI short WINAPI cnc_s5s_rdparainfo2(unsigned short FlibHndl, short s_number, short* read_no, short* prev_no, short* next_no, ODBPARAIF2 info[]);
/* read current 5-axis machining configuration set number */
FWLIBAPI short WINAPI cnc_s5s_rdactset(unsigned short FlibHndl, short* set_num);
/* write current 5-axis machining configuration set number */
FWLIBAPI short WINAPI cnc_s5s_wractset(unsigned short FlibHndl, short set_num);

/*-----------------------------------*/
/* Machine Status Monitor / Recorder */
/*-----------------------------------*/
FWLIBAPI short WINAPI cnc_msr_stop_sample(unsigned short h);
FWLIBAPI short WINAPI cnc_msr_start_sample(unsigned short h);
FWLIBAPI short WINAPI cnc_msr_rdhis_allnum(unsigned short h,short *his_num);
FWLIBAPI short WINAPI cnc_msr_rdhis_inf(unsigned short h, short st_no, short *num, ODBMSRHSTINF *hstinf);
FWLIBAPI short WINAPI cnc_msr_rdhis_msudat(unsigned short h, short hst_no, short msu_no, ODBMSUDAT *msudat);
FWLIBAPI short WINAPI cnc_msr_rdhis_pmc_ex(unsigned short FlibHndl,short hst_no, short expmcsgnl_no, ODBEXPMCSGNL *expmcsgnl);
FWLIBAPI short WINAPI cnc_msr_rdhis_pmc(unsigned short h, short hst_no, ODBMSRPMCSGNL *pmcsgnl);
FWLIBAPI short WINAPI cnc_msr_rdhis_ncdat(unsigned short h, short hst_no, short path_no, ODBMSRNCDAT *ncdat);
FWLIBAPI short WINAPI cnc_msr_delhis_all(unsigned short h);
FWLIBAPI short WINAPI cnc_msr_rdmon_msunum(unsigned short h, short *msu_num);
FWLIBAPI short WINAPI cnc_msr_rdmon_msudat(unsigned short h, short msu_no, ODBMSUDAT *msudat);
FWLIBAPI short WINAPI cnc_msr_rdmon_pmcinf_ex(unsigned short FlibHndl,short expmcsgnl_no, ODBEXPMCSGNL *expmcsgnl);
FWLIBAPI short WINAPI cnc_msr_rdmon_pmcinf(unsigned short h, ODBMSRPMCSGNL *pmcsgnl);
FWLIBAPI short WINAPI cnc_msr_rdhis_ohisnum(unsigned short h, short hst_no, unsigned short *num);
FWLIBAPI short WINAPI cnc_msr_rdhis_ohisrec(unsigned short h, short hst_no, unsigned short st_no, unsigned short *ed_no,
                                      unsigned short *len, void *db) ;

/*------------*/
/* Eco Mode   */
/*------------*/
FWLIBAPI short WINAPI cnc_powc_rd_cycle_data(unsigned short h, short lev, short atrb, ODBPOWCCYC *powccyc);
FWLIBAPI short WINAPI cnc_powc_clear_inte(unsigned short h);
FWLIBAPI short WINAPI cnc_powc_rd_clear_time(unsigned short h, unsigned long *clear_time);
FWLIBAPI short WINAPI cnc_powc_wr_outer_set(unsigned short h, short data_no, ODBPOWCOUTER *powcouter);
FWLIBAPI short WINAPI cnc_powc_rd_outer_set(unsigned short h, ODBPOWCOUTER *powcouter);
FWLIBAPI short WINAPI cnc_powc_del_cycle_data(unsigned short h, short lev);
FWLIBAPI short WINAPI cnc_powc_rd_history(unsigned short h, short unit, short *num, ODBPOWCHISALL *powchisall);

/*------------------------------*/
/* Power Consumption Monitor	*/
/*------------------------------*/
FWLIBAPI short WINAPI cnc_pwcm_clear_consump(unsigned short h);
/* read power consumption */
FWLIBAPI short WINAPI cnc_pwcm_rd_consump(unsigned short FlibHndl, short type, ODBPWCMDAT *power);

/*-------------------------*/
/* LASER                   */
/*-------------------------*/
/* write processing condition file (edging data) */
FWLIBAPI short WINAPI cnc_wrpscdedge2(unsigned short ,short ,short *, IODBEDGE2 *) ;
/* read processing condition file (edging data)  */
FWLIBAPI short WINAPI cnc_rdpscdedge2(unsigned short ,short ,short *, IODBEDGE2 *) ;
/* write processing condition file (power control data) */
FWLIBAPI short WINAPI cnc_wrlpscdpwrctl(unsigned short ,short ,short *, IODBPWRCTL *); 
/* read processing condition file (power control data)  */
FWLIBAPI short WINAPI cnc_rdlpscdpwrctl(unsigned short ,short ,short *, IODBPWRCTL *); 
/* read displacement */
FWLIBAPI short WINAPI cnc_rdldsplc2(unsigned short ,IODBDSPLC *);
/* write displacement */
FWLIBAPI short WINAPI cnc_wrldsplc2(unsigned short ,IODBDSPLC *);
/* write agingmode */
FWLIBAPI short WINAPI cnc_wrlagingmode(unsigned short ,short );
/* read agingmode */
FWLIBAPI short WINAPI cnc_rdlagingmode(unsigned short ,short *);
/* read agingtime */
FWLIBAPI short WINAPI cnc_rdlagingtime(unsigned short ,short *);
/* read laser state */
FWLIBAPI short WINAPI cnc_rdlhsstate(unsigned short ,ODBLSTATE *) ;
/* read laser power offset */
FWLIBAPI short WINAPI cnc_rdlpoweroffset(unsigned short , ODBLPWOFS *) ;
/* write laser work data */
FWLIBAPI short WINAPI cnc_wrlswork(unsigned short , IDBLSWORK *) ;
/* read laser alarm history */
FWLIBAPI short WINAPI cnc_rdlalmhistry( unsigned short, unsigned short , unsigned short , unsigned short , ODBLALMHIS * );
/* read  uvmacro pointer */
FWLIBAPI short WINAPI cnc_rduvactpt2( unsigned short, ODBUVMCRPT2 * );
/* read nozzle tip machine position */
FWLIBAPI short WINAPI cnc_rdlnzlmcn( unsigned short, short, short, ODBAXIS * ) ;
/*$ read fiber data $*/
FWLIBAPI short WINAPI cnc_rdlfiberdata(unsigned short, short, short, short *, long *) ;
/*----------------------------------*/
/* cut condition customize function */
/*----------------------------------*/
FWLIBAPI short WINAPI cnc_lctcdcstm(unsigned short , unsigned short , unsigned short , unsigned char *, unsigned char *) ;
FWLIBAPI short WINAPI cnc_rdlcstmname(unsigned short , unsigned short , unsigned short , unsigned char *, unsigned char *) ;
/*---------------------------------------*/
/* read/write punchpress tool data       */
/*---------------------------------------*/
FWLIBAPI short WINAPI cnc_rd1punchtl_ex( unsigned short, IODBPUNCH1_EX *) ;
FWLIBAPI short WINAPI cnc_wrpunchtl_ex( unsigned short, short, IODBPUNCH1_EX *) ;
FWLIBAPI short WINAPI cnc_rd2punchtl_ex( unsigned short, IODBPUNCH2_EX *) ;

/*---------------------------------------*/
/* Tilted Working Plane Command          */
/*---------------------------------------*/
FWLIBAPI short WINAPI cnc_twp_rdfcoord(unsigned short, char, ODBCOORD *); 
FWLIBAPI short WINAPI cnc_twp_rdfmt_mtrx(unsigned short, short, IDBTWPFORM *, ODBFTRMTX *);

/*---------------------------------------*/
/* Machining Condition Setting           */
/*---------------------------------------*/
FWLIBAPI short WINAPI cnc_mcs_rdparam(unsigned short, short, short, short, short, IODBPSD *);
FWLIBAPI short WINAPI cnc_mcs_wrparam(unsigned short, short, short, IODBPSD *);
FWLIBAPI short WINAPI cnc_mcs_rdparanum(unsigned short, ODBPARANUM *);
FWLIBAPI short WINAPI cnc_mcs_rdparainfo2(unsigned short, short, short *, short *, short *, ODBPARAIF2 *);
FWLIBAPI short WINAPI cnc_mcs_rdactset(unsigned short, short *);
FWLIBAPI short WINAPI cnc_mcs_wractset(unsigned short, short);
FWLIBAPI short WINAPI cnc_mcs_rdheader(unsigned short, short, ODBMCSHEAD *);
FWLIBAPI short WINAPI cnc_mcs_wrheader(unsigned short, short, ODBMCSHEAD *, char);
FWLIBAPI short WINAPI cnc_mcs_rdcompparam(unsigned short, char *);

/*---------------------------------------*/
/* Peripheral axis control               */
/*---------------------------------------*/
FWLIBAPI short WINAPI cnc_getpaxispath(unsigned short, short *, short *);

/*---------------------------------------*/
/* read program alarm status             */
/*---------------------------------------*/
FWLIBAPI short WINAPI cnc_rdalarmchar(unsigned short, short *, short *); 

/*---------------------------------------*/
/* High Motion Compile (PMi-A only)      */
/*---------------------------------------*/
FWLIBAPI short WINAPI cnc_start_hm_cmpl(unsigned short, long);
FWLIBAPI short WINAPI cnc_rd_hm_cmpl_stat(unsigned short, long *, unsigned long *, short *, short *);

/*---------------------------------------------------*/
/* Multi-Axes High Response Progam (PMi-A only)      */
/*---------------------------------------------------*/
FWLIBAPI short WINAPI cnc_rd_hm_progstat(unsigned short, long, short *, ODBHMPROGSTAT *);
FWLIBAPI short WINAPI cnc_set_hm_progno(unsigned short, long);
FWLIBAPI short WINAPI cnc_rd_hm_execprog(unsigned short, unsigned short *, char *);

FWLIBAPI short WINAPI cnc_rdprgrmupdtcnt(unsigned short, unsigned long*);

/*---------------------------------------------------*/
/* Teach Program Function (PMi-A only)               */
/*---------------------------------------------------*/
FWLIBAPI short WINAPI cnc_tprog_rdprg_by_num( unsigned short, long *, long, long, ODBTPAPRG *);
FWLIBAPI short WINAPI cnc_tprog_rdprg_by_name( unsigned short, long *, char *, long, ODBTPAPRG *);
FWLIBAPI short WINAPI cnc_tprog_wrinfo( unsigned short, short, char *, IDBTPINFO *);
FWLIBAPI short WINAPI cnc_tprog_rdcmd( unsigned short, char *, long, long, ODBTPEDTCMD *);
FWLIBAPI short WINAPI cnc_tprog_editcmd( unsigned short, char *, long , long, IDBTPCMD *);
FWLIBAPI short WINAPI cnc_tprog_rdline( unsigned short, char *, long, char *, unsigned long *, unsigned long *);
FWLIBAPI short WINAPI cnc_tprog_st_convert(unsigned short, short, short) ;
FWLIBAPI short WINAPI cnc_tprog_convert_stat(unsigned short, long *, long *, long *, short *, short *) ;
FWLIBAPI short WINAPI cnc_tprog_rdpos( unsigned short, char *, unsigned short, unsigned short *, long *);
FWLIBAPI short WINAPI cnc_tprog_wrpos( unsigned short, char *, unsigned short, unsigned short *, long *);

/*---------------------------------------------------*/
/* Electric Cam Data SRAM Use (PMi-A only)           */
/*---------------------------------------------------*/
FWLIBAPI short WINAPI cnc_rdecamdatar(unsigned short, unsigned long, unsigned long *, long *);
FWLIBAPI short WINAPI cnc_wrecamdatar(unsigned short, unsigned long, unsigned long *, long *);

/*---------------------------------------*/
/*   PDSA Pulse Input Diag               */
/*---------------------------------------*/
FWLIBAPI short WINAPI dsa_rdpulsediag(unsigned short, ODBPLSDATA *);

/*---------------------------------------*/
/* Main Menu      */
/*---------------------------------------*/
FWLIBAPI short WINAPI cnc_rd_mm_setting_data(unsigned short, short, short, short*, ODBMMSCRNINF*);
FWLIBAPI short WINAPI cnc_wr_mm_setting_data(unsigned short, short, short, short, ODBMMSCRNINF*);
FWLIBAPI short WINAPI cnc_rd_mm_icn_cstm_str_num(unsigned short, short*);
FWLIBAPI short WINAPI cnc_rd_mm_icn_cstm_str_data(unsigned short, short, short*, IODBMMICONCSTMSTRING*);
FWLIBAPI short WINAPI cnc_wr_mm_icn_cstm_str_data(unsigned short, short, short, IODBMMICONCSTMSTRING*);
FWLIBAPI short WINAPI cnc_rd_mm_ctgry_cstm_str_data(unsigned short, short, short*, IODBMMCTGRYCSTMSTRING*);
FWLIBAPI short WINAPI cnc_wr_mm_ctgry_cstm_str_data(unsigned short, short, short, IODBMMCTGRYCSTMSTRING*);
FWLIBAPI short WINAPI cnc_rd_mm_mc_dflt_scrn_inf(unsigned short, short, short, short*, ODBMMSCRNINF*);
FWLIBAPI short WINAPI cnc_rd_mm_mc_scrn_def_num(unsigned short, short*);
FWLIBAPI short WINAPI cnc_rd_mm_mc_scrn_def_data(unsigned short, short, short*, IODBMMMCSCRNDEFDAT*);
FWLIBAPI short WINAPI cnc_rd_mm_mc_ctgry_def_data(unsigned short, short, short*, IODBMMMCCTGRYDEFDAT* );
FWLIBAPI short WINAPI cnc_rd_mm_mc_message_string(unsigned short, long, char*, long*);

/*----------------------------*/
/* Machining simulation       */
/*----------------------------*/
#ifndef CNC_PPC
FWLIBAPI short WINAPI anm_simuopen(unsigned short, char, long, char *);
FWLIBAPI short WINAPI anm_simuclose(unsigned short);
FWLIBAPI short WINAPI anm_simurwd(unsigned short, char, long, char *);
FWLIBAPI short WINAPI anm_simustart(unsigned short);
FWLIBAPI short WINAPI anm_simustop(unsigned short);
FWLIBAPI short WINAPI anm_simuproc(unsigned short);
FWLIBAPI short WINAPI anm_simusngl(unsigned short);
FWLIBAPI short WINAPI anm_rdsimuelm(unsigned short, IODBSIMUELM *);
FWLIBAPI short WINAPI anm_rdsimuelm2(unsigned short, IODBSIMUELM2 *);
#endif

/*----------------*/
/* Block distance */
/*----------------*/
FWLIBAPI short WINAPI cnc_rdblkdist(unsigned short, REALDATA *);

FWLIBAPI short WINAPI cnc_reqsvgtung( unsigned short, short, short, ODBTUNREQ * ) ;
FWLIBAPI short WINAPI cnc_stopsvgtung( unsigned short ) ;
FWLIBAPI short WINAPI cnc_rdsvgtungstat( unsigned short, short, short, ODBTUNSTAT * ) ;

/*------------------------*/
/* Reducing Cycle Time    */
/*------------------------*/
FWLIBAPI short WINAPI cnc_rct_rdCtgInfo(unsigned short, unsigned short, unsigned short*, unsigned short* );
FWLIBAPI short WINAPI cnc_rct_rdItem   (unsigned short, unsigned short, IODBRCT_ITEM* );
FWLIBAPI short WINAPI cnc_rct_wrItem   (unsigned short, unsigned short, IODBRCT_ITEM* );
FWLIBAPI short WINAPI cnc_rct_wrRecom  (unsigned short, long, short );
FWLIBAPI short WINAPI cnc_rct_rdRcmAdjst  (unsigned short, short, short*, short*, short* );
FWLIBAPI short WINAPI cnc_rct_wrRcmAdjst  (unsigned short, short, short );
FWLIBAPI short WINAPI cnc_rct_wrOvLp   (unsigned short, short, short );
FWLIBAPI short WINAPI cnc_rct_cpSlctPtn(unsigned short, long, unsigned short, unsigned short );
FWLIBAPI short WINAPI cnc_rct_rdGrpName(unsigned short, unsigned short, IODBRCT_CSTMNAME* );
FWLIBAPI short WINAPI cnc_rct_wrGrpName(unsigned short, unsigned short, IODBRCT_CSTMNAME* );
FWLIBAPI short WINAPI cnc_rct_rdPtnSlct(unsigned short, unsigned short, IODBRCT_GRPPTN* );
FWLIBAPI short WINAPI cnc_rct_wrPtnSlct(unsigned short, unsigned short, IODBRCT_GRPPTN* );
FWLIBAPI short WINAPI cnc_rct_rdslctptnname(unsigned short, ODBRCT_SLCTPTNNAME* );
FWLIBAPI short WINAPI cnc_rct_rdptnadjst(unsigned short, short, short*, short*, short*);
FWLIBAPI short WINAPI cnc_rct_wrptnadjst(unsigned short, short, short*);
FWLIBAPI short WINAPI cnc_rct_rdtunemoni(unsigned short, short, short*, short*);

/*---------------------------------------*/
/*   Pressure position control           */
/*---------------------------------------*/
FWLIBAPI short WINAPI cnc_rdpressure(unsigned short, short, short *, ODBPRESSURE *);

/*------------------------*/
/*   Position (ExDigit)   */
/*------------------------*/
FWLIBAPI short WINAPI cnc_absolute2_exdgt(unsigned short FlibHndl, ODBEXPOS *axis_data);
FWLIBAPI short WINAPI cnc_machine_exdgt(unsigned short FlibHndl, ODBEXPOS *axis_data);
FWLIBAPI short WINAPI cnc_relative2_exdgt(unsigned short FlibHndl, ODBEXPOS *axis_data);
FWLIBAPI short WINAPI cnc_distance_exdgt(unsigned short FlibHndl, ODBEXPOS *axis_data);

/*------------------------------*/
/* Scroll Waiting Mcode Setting */
/*------------------------------*/
FWLIBAPI short WINAPI cnc_wr_scrlwaitmcode ( unsigned short, short, short*, IODBWAITMCODE* );
FWLIBAPI short WINAPI cnc_rd_scrlwaitmcode ( unsigned short, short, short*, IODBWAITMCODE* );
FWLIBAPI short WINAPI cnc_del_scrlwaitmcode( unsigned short );

/*------------------------*/
/* Smart Adaptive control */
/*------------------------*/
FWLIBAPI short WINAPI cnc_rdsoc_curdat(unsigned short, short, ODBSOCCUR* );
FWLIBAPI short WINAPI cnc_rdsoc_wave_start(unsigned short, short );
FWLIBAPI short WINAPI cnc_rdsoc_wave(unsigned short, long*, unsigned short* );
FWLIBAPI short WINAPI cnc_rdsoc_wave_end(unsigned short );
FWLIBAPI short WINAPI cnc_soc_wave_setchnl(unsigned short, short* );
FWLIBAPI short WINAPI cnc_rdsoc_tlatrr ( unsigned short, short, short*, short, short*, short*, short*, ODBSOCTLATTR* );
FWLIBAPI short WINAPI cnc_rdsoc_tldat  ( unsigned short, short, short*, short, short*, char, IODBSOCTLDAT* );
FWLIBAPI short WINAPI cnc_wrsoc_tldat  ( unsigned short, short, short*, short, short*, IODBSOCTLDAT* );
	
/*-------------------*/
/* PMC Ladder screen */
/*-------------------*/
typedef struct tag_PMCLAD_COIL_ADDRESS
{
    int pmc;
    int program;
    int type;
    int offset;
    int bit;
    int _reserved;
} PMCLAD_COIL_ADDRESS;

typedef struct tag_PMCLAD_COIL_STRING
{
    int pmc;
    int program;
    char * string;
    int _reserved;
} PMCLAD_COIL_STRING;

typedef struct tag_PMCLAD_MESSAGE
{
    const char * message;
    int lines;
    int color_fg;
    int color_bg;
} PMCLAD_MESSAGE;

FWLIBAPI short WINAPI cnc_pmclad_screen(unsigned short FwHndl, int iCommand, void * pParam, PMCLAD_MESSAGE *pstMessage);

#ifndef CNC_PPC
typedef struct odbdllversion {
	struct {
		char Name[260];
		char FileVersion[32];
		char ProductVersion[32];
	} dll[2];
} ODBDLLVERSION;

FWLIBAPI short WINAPI cnc_getdllversion( unsigned short FwHndl, ODBDLLVERSION *vers );
#endif

/*---------------------------------------*/
/* Linux process and thread              */
/*---------------------------------------*/
FWLIBAPI short WINAPI cnc_startupprocess(long, const char *);
FWLIBAPI short WINAPI cnc_exitprocess();
FWLIBAPI short WINAPI cnc_exitthread();

/*---------------------*/
/* Macro for Oxxxxxxxx */
/*---------------------*/

#ifdef ONO8D
#define odbpro		odbproo8
#define odbdy		odbdyo8
#define odbmdip		odbmdipo8
#define prgdir2		prgdir2o8
#define ODBPRO		ODBPROO8
#define ODBDY		ODBDYO8
#define ODBMDIP		ODBMDIPO8
#define PRGDIR2		PRGDIR2O8

#define cnc_upstart	cnc_upstarto8
#define cnc_search	cnc_searcho8
#define cnc_delete	cnc_deleteo8
#ifndef CNC_PPC
#define cnc_rdprogdir	cnc_rdprogdiro8
#endif
#define cnc_rdprgnum	cnc_rdprgnumo8
#ifndef CNC_PPC
#define cnc_rddynamic	cnc_rddynamico8
#endif
#define cnc_rdmdipntr	cnc_rdmdipntro8
#define cnc_rdprogdir2	cnc_rdprogdir2o8
#endif


#ifdef __cplusplus
} // namespace Fwlib32

using namespace Fwlib32;

}
#endif

#endif  /* _INC_FWLIB */
