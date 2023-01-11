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
    int16_t   dummy[2] ;  /* dummy */
    int32_t   data ;      /* actual feed / actual spindle */
} ODBACT ;

/* cnc_acts2:read actual spindle speed(S) */
/* (All or specified ) */
typedef struct odbact2 {
	 int16_t	datano;		/* spindle number */
	 int16_t	type;		/* dummy */
	 int32_t	data[MAX_SPINDLE];	/* spindle data */
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
    int16_t   dummy ;             /* dummy */
    int16_t   type ;              /* axis number */
    int32_t   data[MAX_AXIS] ;    /* data value */
} ODBAXIS ;
typedef struct odbaxis_ex {
    int16_t   counter ;           /* counter */
    int16_t   type ;              /* axis number */
    int32_t   data[MAX_AXIS] ;    /* data value */
} ODBAXIS_EX ;

/*-------------------------------------*/
/* IS-E long stroke type               */
/*-------------------------------------*/

typedef struct realdata {
    double    val;                  /* data value    */
    int32_t   dec;                  /* decimal point */
    int32_t   dummy;
} REALDATA;

/* cnc_prstwkcd64:preset work coordinate */
typedef struct idbwra64 {
    int16_t       datano;         /* dummy */
    int16_t       type;           /* axis number */
    int16_t       dummy[2];       /* dummy2 */
    REALDATA      data[MAX_AXIS]; /* preset data */
} IDBWRA64;

/* cnc_wrrelpos64:set origin / preset relative axis position */
typedef struct idbwrr64 {
    int16_t     datano;         /* dummy */
    int16_t     type;           /* axis number */
    int16_t     dummy[2];       /* dummy2 */
    REALDATA    data[MAX_AXIS]; /* preset data */
} IDBWRR64;

/* cnc_rdcommand64: read command value */
typedef struct odbcmd64 {
    char        adrs;           /* command address */
    char        num;            /* M-Code / axis num */
    int16_t     flag;           /* add info */
    int32_t     dec_val;        /* decimal point */
    double      cmd_val;        /* command data  */
} ODBCMD64;

/* cnc_zofs_rnge64:read validity of work zero offset */
/* cnc_wksft_rnge64:read validity of work shift value */
typedef struct odbdatrng64 {
    double      data_min;       /* lower limit */
    double      data_max;       /* upper limit */
    int32_t     dec;            /* decimal point */
    int32_t     status;         /* status of setting */
} ODBDATRNG64;

/* cnc_rdzofsr64:read work zero offset value(area specified) */
typedef struct iodbzor64 {
    int16_t       datano_s;           /* start offset number */
    int16_t       type;               /* axis number */
    int16_t       datano_e;           /* end offset number */
    int16_t       dummy;              /* dummy */
    REALDATA    data[MAX_AXIS*8];   /* offset value */
} IODBZOR64; /* In case that the number of axes is MAX_AXIS, the number of data is 7 */

/* cnc_rdparam64 : read  parameter (IEEE double version) */
/* cnc_wrparam64 : write parameter (IEEE double version) */
typedef struct iodbpsd64 {
    int16_t       datano;     /* data number */
    int16_t       type ;      /* data type */
    int16_t       axis ;      /* axis number */
    int16_t       dummy ;     /* dummy */
    union {
        char        cdata;  /* parameter / setting data */
        int16_t       idata;  /* int16_t tyoe data */
        int32_t        ldata;  /* int32_t tyoe data */
        REALDATA    rdata;  /* real type data */
        char        cdatas[MAX_AXIS];
        int16_t       idatas[MAX_AXIS];
        int32_t        ldatas[MAX_AXIS];
        REALDATA    rdatas[MAX_AXIS];
    } u;
} IODBPSD64;

/* cnc_rdwkcdshft64:read  work coordinate shift */
/* cnc_wrwkcdshft64:write work coordinate shift */
/* cnc_rdwkcdsfms64:read  work coordinate shift measure */
/* cnc_wrwkcdsfms64:write work coordinate shift measure */
typedef struct iodbwcsf64 {
    int16_t       dummy1;         /* dummy1 */
    int16_t       type;           /* axis number */
    int16_t       dummy2[2];      /* dummy2 */
    REALDATA    data[MAX_AXIS]; /* data */
} IODBWCSF64;

/* cnc_wrzofs64:write work zero offset value */
typedef struct iodbzofs64 {
    int16_t       datano;         /* offset NO. */
    int16_t       type;           /* axis number */
    int16_t       dummy[2];       /* dummy */
    REALDATA    data[MAX_AXIS]; /* data value */
} IODBZOFS64;

/* cnc_machine:read machine axis position */
typedef struct odbaxis64 {
    int16_t       dummy1 ;        /* dummy1 */
    int16_t       type ;          /* axis number */
    int16_t       dummy2[2];      /* dummy2 */
    REALDATA    data[MAX_AXIS]; /* data value */
} ODBAXIS64 ;

/* cnc_rdaxisdata64:read various axis data(IEEE double version) */
typedef struct odbaxdt64 {
    char    name[4];    /* axis name */
    char    dummy[4];
    double  data;       /* position data */
    int16_t   dec;        /* decimal position */
    int16_t   unit;       /* data unit */
    int16_t   flag;       /* flags */
    int16_t   reserve;    /* reserve */
} ODBAXDT64 ;

typedef struct odbdgn64 {
    int16_t   datano ;    /* data number */
    int16_t   type ;      /* axis number */
    int16_t   axis ;      /* axis number */
    int16_t   dummy ;     /* dummy */
    union {
        char        cdata ; /* diagnosis data */
        int16_t       idata ;
        int32_t        ldata ;
        REALDATA    rdata ;
        char        cdatas[MAX_AXIS] ;
        int16_t       idatas[MAX_AXIS] ;
        int32_t        ldatas[MAX_AXIS] ;
        REALDATA    rdatas[MAX_AXIS] ;
    } u ;
} ODBDGN64 ;

/* cnc_wrtofsdrctinp:write Tool offset data Direct Input(IEEE double version) */
typedef struct realmes64 {
	double mes_val; /* data of real measeure */
	int32_t   dec_val; /* decimal point of real measeure */
	int32_t   dummy;   /* dummy */
} REALMES64;

/* cnc_rddynamic:read all dynamic data */
typedef struct odbdy {
    int16_t   dummy ;
    int16_t   axis ;      /* axis number */
    int16_t   alarm ;     /* alarm status */
    int16_t   prgnum ;    /* current program number */
    int16_t   prgmnum ;   /* main program number */
    int32_t   seqnum ;    /* current sequence number */
    int32_t   actf ;      /* actual feedrate */
    int32_t   acts ;      /* actual spindle speed */
    union {
        struct {
            int32_t    absolute[MAX_AXIS] ;    /* absolute position */
            int32_t    machine[MAX_AXIS] ;     /* machine position */
            int32_t    relative[MAX_AXIS] ;    /* relative position */
            int32_t    distance[MAX_AXIS] ;    /* distance to go */
        } faxis ;
        struct {
            int32_t    absolute ;  /* absolute position */
            int32_t    machine ;   /* machine position */
            int32_t    relative ;  /* relative position */
            int32_t    distance ;  /* distance to go */
        } oaxis ;   /* In case of no axis */
    } pos ;
} ODBDY ;

/* cnc_rddynamic2:read all dynamic data */
typedef struct odbdy2 {
    int16_t   dummy ;
    int16_t   axis ;       /* axis number             */
    int32_t   alarm ;      /* alarm status            */
    int32_t   prgnum ;     /* current program number  */
    int32_t   prgmnum ;    /* main program number     */
    int32_t   seqnum ;     /* current sequence number */
    int32_t   actf ;       /* actual feedrate         */
    int32_t   acts ;       /* actual spindle speed    */
    union {
        struct {
            int32_t    absolute[MAX_AXIS] ;    /* absolute position   */
            int32_t    machine[MAX_AXIS] ;     /* machine position    */
            int32_t    relative[MAX_AXIS] ;    /* relative position   */
            int32_t    distance[MAX_AXIS] ;    /* distance to go      */
        } faxis ;
        struct {
            int32_t    absolute ;  /* absolute position   */
            int32_t    machine ;   /* machine position    */
            int32_t    relative ;  /* relative position   */
            int32_t    distance ;  /* distance to go      */
        } oaxis ;   /* In case of 1 axis  */
    } pos ;
} ODBDY2 ;

/* cnc_rddynamic3:read all dynamic data(3) */
typedef struct odbdy3 {
    int16_t   dummy ;
    int16_t   axis ;       /* axis number             */
    int32_t    alarm ;      /* alarm status            */
    int32_t    prgnum ;     /* current program number  */
    int32_t    prgmnum ;    /* main program number     */
    int32_t    seqnum ;     /* current sequence number */
    int32_t    actf ;       /* actual feedrate         */
    int32_t    acts ;       /* actual spindle speed    */
    union {
        struct {
            int32_t    absolute[MAX_AXIS] ;    /* absolute position   */
            int32_t    machine[MAX_AXIS] ;     /* machine position    */
            int32_t    relative[MAX_AXIS] ;    /* relative position   */
            int32_t    distance[MAX_AXIS] ;    /* distance to go      */
        } faxis ;
        struct {
            int32_t    absolute ;  /* absolute position   */
            int32_t    machine ;   /* machine position    */
            int32_t    relative ;  /* relative position   */
            int32_t    distance ;  /* distance to go      */
        } oaxis ;   /* In case of 1 axis  */
    } pos ;
} ODBDY3 ;

/* cnc_rddynamic3m:read all dynamic data(3m) */
typedef struct odbdy3m {
    int16_t   dummy ;
    int16_t   axis ;       /* axis number             */
    int32_t    alarm ;      /* alarm status            */
    int32_t    prgnum ;     /* current program number  */
    int32_t    prgmnum ;    /* main program number     */
    int32_t    seqnum ;     /* current sequence number */
    int32_t    actf ;       /* actual feedrate         */
    int32_t    acts ;       /* actual spindle speed    */
    union {
        struct {
            int32_t    absolute[32] ;    /* absolute position   */
            int32_t    machine[32] ;     /* machine position    */
            int32_t    relative[32] ;    /* relative position   */
            int32_t    distance[32] ;    /* distance to go      */
        } faxis ;
        struct {
            int32_t    absolute ;  /* absolute position   */
            int32_t    machine ;   /* machine position    */
            int32_t    relative ;  /* relative position   */
            int32_t    distance ;  /* distance to go      */
        } oaxis ;   /* In case of 1 axis  */
    } pos ;
} ODBDY3M ;

/* cnc_wrrelpos:set origin / preset relative axis position */
typedef struct idbwrr {
    int16_t   datano;         /* dummy */
    int16_t   type;           /* axis number */
    int32_t    data[MAX_AXIS]; /* preset data */
} IDBWRR;

/* cnc_prstwkcd:preset work coordinate */
typedef struct idbwra {
    int16_t   datano;         /* dummy */
    int16_t   type;           /* axis number */
    int32_t    data[MAX_AXIS]; /* preset data */
} IDBWRA;

/* cnc_rdmovrlap:read manual overlapped motion value */
typedef struct iodbovl {
    int16_t   datano;             /* dummy */
    int16_t   type;               /* axis number */
    int32_t    data[2][MAX_AXIS];  /* data value */
} IODBOVL;

/* cnc_rdmovrlapm:read manual overlapped motion value */
typedef struct iodbovlm {
    int16_t   datano;       /* dummy */
    int16_t   type;         /* axis number */
    int32_t    data[2][32];  /* data value */
} IODBOVLM;

/* cnc_rdspload:read load information of serial spindle */
/* cnc_rdspmaxrpm:read maximum r.p.m. ratio of serial spindle */
/* cnc_rdspgear:read gear ratio of serial spindle */
typedef struct odbspn {
    int16_t   datano;     /* spindle number */
    int16_t   type;       /* dummy */
    int16_t   data[MAX_SPINDLE];    /* spindle data */
} ODBSPN;

/* cnc_rdposition:read tool position */
typedef struct poselm {
    int32_t    data;       /* position data */
    int16_t   dec;        /* decimal position */
    int16_t   unit;       /* data unit */
    int16_t   disp;       /* display flag */
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
    int32_t    data;       /* speed data */
    int16_t   dec;        /* decimal position */
    int16_t   unit;       /* data unit */
    int16_t   disp;       /* display flag */
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
    int32_t    data;       /* load meter */
    int16_t   dec;        /* decimal position */
    int16_t   unit;       /* unit */
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
    int32_t    data;       /* position data */
    int16_t   dec;        /* decimal position */
    int16_t   unit;       /* data unit */
    int16_t   flag;       /* flags */
    int16_t   reserve;    /* reserve */
} ODBAXDT;

/* cnc_rdspcss:read constant surface speed data */
typedef struct odbcss {
    int32_t    srpm;       /* order spindle speed */
    int32_t    sspm;       /* order constant spindle speed */
    int32_t    smax;       /* order maximum spindle speed */
} ODBCSS;

/* cnc_simulation:read data for machining simulation */
typedef struct odbsiml {
    int32_t    t_code ;
    int32_t    b_code ;
    int32_t    axis_no ;
    int32_t    machine[MAX_AXIS] ;
    int32_t    dec[MAX_AXIS] ;
    int32_t    fscsl ;
} ODBSIML;

/* cnc_loadtorq */
typedef struct odbload {
	int16_t	datano;
	int16_t	type;
	int16_t	data[MAX_AXIS];
} ODBLOAD;

/* cnc_rdexecpt:read execution program pointer */
#ifndef CNC_PPC
typedef struct prgpnt {
    int32_t    prog_no;    /* program number */
    int32_t    blk_no;     /* block number */
} PRGPNT;
#endif

/* cnc_rdactpt_w:read execution pointer of program for FS160is/180is-WB */
typedef struct odbactptw {
    int32_t    mprgno;     /* main program number */
    int32_t    mblkno;     /* main block number */
    int32_t    sprgno;     /* sub program number */
    int32_t    sblkno;     /* sub block number */
} ODBACTPTW ;

/* cnc_rd5axmandt:read manual feed for 5-axis machining */
typedef	struct odb5axman {
    int16_t   type1;
    int16_t   type2;
    int16_t   type3;
    int32_t    data1;
    int32_t    data2;
    int32_t    data3;
    int32_t    c1;
    int32_t    c2;
    int32_t    dummy;
    int32_t    td;
    int32_t    r1;
    int32_t    r2;
    int32_t    vr;
    int32_t    h1;
    int32_t    h2;
} ODB5AXMAN ;

/* cnc_rdposfig:read position and decimal figure */
typedef struct odbposfig {
    int32_t    val;
    int32_t    dec;
} ODBPOSFIG ;


/*----------------------*/
/* CNC: Program related */
/*----------------------*/

/* cnc_rddncdgndt:read the diagnosis data of DNC operation */
typedef struct odbdncdgn {
    int16_t          ctrl_word;
    int16_t          can_word;
    char           nc_file[16];
    uint16_T read_ptr;
    uint16_T write_ptr;
    uint16_T empty_cnt;
    uint32_T  total_size;
} ODBDNCDGN;

/* cnc_rddncdgndt:read the diagnosis data of DNC operation (2) */
typedef struct odbdncdgn2 {
    int16_t          ctrl_word;
    int16_t          can_word;
    char           nc_file[64];
    uint16_T read_ptr;
    uint16_T write_ptr;
    uint16_T empty_cnt;
    uint32_T  total_size;
} ODBDNCDGN2;

/* cnc_upload:upload NC program */
/* cnc_cupload:upload NC program(conditional) */
typedef struct odbup {
    int16_t   dummy[2] ;  /* dummy */
    char    data[256] ; /* data */
} ODBUP ;   /* In case that the number of data is 256 */

/* cnc_buff:read buffer status for downloading/verification NC program */
typedef struct odbbuf {
    int16_t   dummy[2] ;  /* dummy */
    int16_t   data ;      /* buffer status */
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
            int16_t   reg_prg ;       /* registered program number */
            int16_t   unreg_prg ;     /* unregistered program number */
            int32_t    used_mem ;      /* used memory area */
            int32_t    unused_mem ;    /* unused memory area */
        } bin ;             /* binary data type */
        char    asc[31] ;   /* ASCII string type */
    } u ;
} ODBNC ;

/* cnc_rdprgnum:read program number under execution */
typedef struct odbpro {
    int16_t   dummy[2] ;  /* dummy */
    int16_t   data ;      /* running program number */
    int16_t   mdata ;     /* main program number */
} ODBPRO ;

/* cnc_exeprgname:read program name under execution */
typedef struct odbexeprg {
    char  name[36];     /* running program name */
    int32_t  o_num;        /* running program number */
} ODBEXEPRG;            /*                        */

/* cnc_dncprgname:read program name of DNC operation */
typedef struct odbdncprg {
    char  name[36];     /* running program name */
    int32_t  o_num;        /* running program number */
} ODBDNCPRG;            /*                        */

/* cnc_rdseqnum:read sequence number under execution */
typedef struct odbseq {
    int16_t   dummy[2] ;  /* dummy */
    int32_t    data ;      /* sequence number */
} ODBSEQ ;

/* cnc_rdexecprog3:read execute-program infomation  */
typedef struct tagEXEPRG {
    uint16_T  length;		/* read data length      */
    int16_t           prep_blk;	/* prepared block number */
    int16_t           act_blk;	/* actual block number   */
    int16_t           dummy;		/* dummy                 */
    char            data[512];	/* execute program       */
} EXEPRG;

typedef struct odbexeprginfo {
	EXEPRG	before_buffering;
	EXEPRG	after_buffering;
} ODBEXEPRGINFO;

/* cnc_rdmdipntr:read execution pointer for MDI operation */
typedef struct odbmdip {
    int16_t   mdiprog;    /* exec. program number */
    int32_t    mdipntr;    /* exec. pointer */
    int16_t   crntprog;   /* prepare program number */
    int32_t    crntpntr;   /* prepare pointer */
} ODBMDIP;

/* cnc_pdf_rdcallstack:read call stack PDF */
typedef struct odbnest{
	uint32_T	attrib;
	char			comment[64] ;
	char			prog_name[245];
	char			dummy[7];
} ODBNESTPDF;

/* cnc_rdpdf_drive:read program drive directory */
typedef struct odbpdfdrv {
	int16_t	max_num;		/* maximum drive number */
	int16_t	dummy;
	char	drive[16][12];	/* drive name */
} ODBPDFDRV ;

/* cnc_rdpdf_inf:read program drive information */
typedef struct odbpdfinf {
	int32_t	used_page;	/* used capacity */
	int32_t	all_page;	/* all capacity */
	int32_t	used_dir;	/* used directory number */
	int32_t	all_dir;	/* all directory number */
} ODBPDFINF ;

/* cnc_rdpdf_subdir:read directory (sub directories) */
typedef struct idbpdfsdir {
	char	path[212];	/* path name */
	int16_t	req_num;	/* entry number */
	int16_t	dummy;
} IDBPDFSDIR ;

/* cnc_rdpdf_subdir:read directory (sub directories) */
typedef struct odbpdfsdir {
	int16_t	sub_exist;	/* existence of sub directory */
	int16_t	dummy;
	char	d_f[36];	/* directory name */
} ODBPDFSDIR ;

/* cnc_rdpdf_alldir:read directory (all files) */
typedef struct idbpdfadir {
	char	path[212];	/* path name */
	int16_t	req_num;	/* entry number */
	int16_t	size_kind;	/* kind of size */
	int16_t	type;		/* kind of format */
	int16_t	dummy;
} IDBPDFADIR ;

/* cnc_rdpdf_alldir:read directory (all files) */
typedef struct odbpdfadir {
	int16_t	data_kind;	/* kinf of data */
	int16_t	year;		/* last date and time */
	int16_t	mon;		/* last date and time */
	int16_t	day;		/* last date and time */
	int16_t	hour;		/* last date and time */
	int16_t	min;		/* last date and time */
	int16_t	sec;		/* last date and time */
	int16_t	dummy;
	int32_t	dummy2;
	int32_t	size;		/* size */
	uint32_T attr;	/* attribute */
	char	d_f[36];	/* path name */
	char	comment[52];/* comment */
	char	o_time[12];	/* machining time stamp */
} ODBPDFADIR ;

/* cnc_rdpdf_prginf:read program infomation  */
typedef struct idbpdfprg {
	char	path[244];	/* path name */
	int16_t	size_kind;	/* kind of size */
	int16_t	type;		/* kind of format */
	int16_t	dummy;
} IDBPDFPRG ;

/* cnc_rdpdf_prginf:read program infomation  */
typedef struct odbpdfprg {
	int16_t	year;		/* last date and time */
	int16_t	mon;		/* last date and time */
	int16_t	day;		/* last date and time */
	int16_t	hour;		/* last date and time */
	int16_t	min;		/* last date and time */
	int16_t	sec;		/* last date and time */
	int32_t	size;		/* size */
	uint32_T attr;	/* attribute */
	char	comment[52];/* comment */
	char	o_time[12];	/* machining time stamp */
} ODBPDFPRG ;

/* cnc_rdprotect:read protect status  */
typedef struct odbprtct {
    int16_t       disp;           /* for disp */
    int16_t       edit;           /* for eidt */
    int16_t       encd;           /* for encode */
    int16_t       lock;           /* for program lock */
} ODBPRTCT ;

/* cnc_rdprotect2:read protect status  */
typedef struct odbprtct2 {
    int16_t       disp;           /* for disp */
    int16_t       edit;           /* for edit */
    int16_t       encd;           /* for encode */
    int16_t       lock;           /* for program lock */
    int16_t       output;         /* for output */
    int16_t       dummy;
} ODBPRTCT2 ;

/* cnc_rdpdf_subdirn:read file count the directory has */
typedef struct odbpdfnfil {
	int16_t	dir_num;	/* directory */
	int16_t	file_num;	/* file */
} ODBPDFNFIL ;

/* cncc_wrpdf_attr:change attribute of program file and directory */
typedef struct idbpdftdir {
	uint32_T slct;	/* selection */
	uint32_T attr;	/* data */
} IDBPDFTDIR ;

/* cnc_rddsfile: get file list infomation */
typedef struct in_dsfile {
    char    path[256];  /* path name   */
    int32_t    fnum;       /* file number */
    int32_t    offset;     /* offset */
    int16_t   req_num;    /* request file num */
    int16_t   size_type;  /* size type */
    int16_t   detail;    /* comment type */
    int16_t   dummy;
} IN_DSFILE;

/* cnc_rddsfile: get file list infomation */
typedef struct out_dsinfo {
    int16_t           type;       /* type */
    int16_t           dummy;
    int32_t            fnum;       /* file num */
    int32_t            total;      /* all file num */
    uint32_T   remain_h;   /* remain(high) */
    uint32_T   remain_l;   /* remain(low) */
    char            dir[256];   /* current folder */
} OUT_DSINFO;

/* cnc_rddsfile: get file list infomation */
typedef struct out_dsfile {
    int16_t           year;       /* year */
    int16_t           mon;        /* month */
    int16_t           day;        /* day */
    int16_t           hour;       /* hour */
    int16_t           min;        /* minute */
    int16_t           sec;        /* second */
    int32_t            size;       /* size */
    uint32_T   attr;       /* attribute */
    char            file[36];   /* file name */
    char            info[128];  /* file infomation */
} OUT_DSFILE;

/* cnc_dsfile_req: get file list infomation */
typedef struct in_dsfile_req {
    char            file[256];  /* file name */
    int32_t            fnum;       /* file number */
    int32_t            offset;     /* offset */
    int16_t           detail;     /* comment type */
    uint16_T  option;     /* option */
} ODB_IN_DSFILE_REQ;

/* cnc_dsstat_rdfile: get file list infomation */
typedef struct in_stat_dsfile {
    int16_t   req_num;    /* request file num */
    int16_t   size_type;  /* size type */
} ODB_IN_STAT_DSFILE;

/* cnc_rdembedf_inf:read embedded folder information*/
typedef struct odbembedfinf {
	int32_t	used_page;	/* used capacity */
	int32_t	all_page;	/* all capacity */
} ODBEMBEDFINF ;

/*---------------------------*/
/* CNC: NC file data related */
/*---------------------------*/

/* cnc_rdtofs:read tool offset value */
typedef struct odbtofs {
    int16_t   datano ;    /* data number */
    int16_t   type ;      /* data type */
    int32_t    data ;      /* data */
} ODBTOFS ;

/* cnc_rdtofsr:read tool offset value(area specified) */
/* cnc_wrtofsr:write tool offset value(area specified) */
typedef struct iodbto {
    int16_t   datano_s ;  /* start offset number */
    int16_t   type ;      /* offset type */
    int16_t   datano_e ;  /* end offset number */
    union {
        int32_t    m_ofs[5] ;      /* M Each */
        int32_t    m_ofs_a[5] ;    /* M-A All */
        int32_t    m_ofs_b[10] ;   /* M-B All */
        int32_t    m_ofs_c[20] ;   /* M-C All */
        struct  {
            int16_t   tip ;
            int32_t    data[1] ;
        } m_ofs_at[5] ;         /* M-A All with tip */
        struct  {
            int16_t   tip ;
            int32_t    data[2] ;
        } m_ofs_bt[5] ;         /* M-A All with tip  */
        struct  {
            int16_t   tip ;
            int32_t    data[4] ;
        } m_ofs_ct[5] ;         /* M-A All with tip  */
        int16_t   t_tip[5] ;      /* T Each, 2-byte */
        int32_t    t_ofs[5] ;      /* T Each, 4-byte */
        struct  {
            int16_t   tip ;
            int32_t    data[4] ;
        } t_ofs_a[5] ;          /* T-A All */
        struct {
            int16_t   tip ;
            int32_t    data[8] ;
        } t_ofs_b[5] ;          /* T-B All */
        int32_t    t_ofs_2g[15];   /* T-2nd geometry */
        int32_t    m_ofs_cnr[10];  /* M-CornerR */
        struct  {
                int32_t    data[2];
        } t_ofs_ex[5];		     /* T-Ex-Ofs */
    } u ;   /* In case that the number of data is 5 */
} IODBTO ;

/* cnc_rdzofs:read work zero offset value */
/* cnc_wrzofs:write work zero offset value */
typedef struct iodbzofs {
    int16_t   datano ;            /* offset NO. */
    int16_t   type ;              /* axis number */
    int32_t    data[MAX_AXIS] ;    /* data value */
} IODBZOFS ;

/* cnc_rdzofsr:read work zero offset value(area specified) */
/* cnc_wrzofsr:write work zero offset value(area specified) */
typedef struct iodbzor {
    int16_t   datano_s ;  /* start offset number */
    int16_t   type ;      /* axis number */
    int16_t   datano_e ;  /* end offset number */
    int32_t    data[8*MAX_AXIS] ;  /* offset value */
} IODBZOR ; /* In case that the number of axes is MAX_AXIS, the number of data is 7 */

/* cnc_rdjogmdi:read manual numeric command */
typedef struct iodbjogcmdcode {
    char    adrs;                   /* command address */
    int32_t    num;                    /* command number */
} ODBJOGCMDCODE;
/* cnc_rdjogmdi:read manual numeric command */
typedef struct iodbjogcmdscode {
    char    adrs[4];                /* command address */
    int32_t    num;                    /* command number */
} ODBJOGCMDSCODE;
/* cnc_rdjogmdi:read manual numeric command */
typedef struct iodbjogcmdaxis {
    char    name[4];                /* axis name */
    int32_t    data;                   /* command number */
    int32_t    dec;                    /* Decimal places */
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
	int32_t				axis_cnt;		/* axis count */
} ODBJOGCMD;

/* cnc_rdmsptype:read mesured point value */
/* cnc_wrmsptype:write mesured point value */
typedef struct iodbmstp {
    int16_t   datano_s ;  /* start offset number */
    int16_t   dummy ;     /* dummy */
    int16_t   datano_e ;  /* end offset number */
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
        int32_t   prm_val;     /* data of real parameter */
        int32_t   dec_val;     /* decimal point of real parameter */
} REALPRM;

#if !defined (HSSB_LIB) || defined (FS30D) || defined (FS15D) || defined (FS0IDD) /* Ethernet & FS30i & FS15i & FS0i-D */
typedef struct iodbpsd {
    int16_t   datano ;    /* data number */
    int16_t   type ;      /* axis number */
    union {
        char    cdata ;     /* parameter / setting data */
        int16_t   idata ;
        int32_t    ldata ;
        REALPRM rdata ;
        char    cdatas[MAX_AXIS] ;
        int16_t   idatas[MAX_AXIS] ;
        int32_t    ldatas[MAX_AXIS] ;
        REALPRM rdatas[MAX_AXIS] ;
    } u ;
} IODBPSD ;

#else

typedef struct iodbpsd {
    int16_t   datano ;    /* data number */
    int16_t   type ;      /* axis number */
    union {
        char    cdata ;     /* parameter / setting data */
        int16_t   idata ;
        int32_t    ldata ;
        char    cdatas[MAX_AXIS] ;
        int16_t   idatas[MAX_AXIS] ;
        int32_t    ldatas[MAX_AXIS] ;
    } u ;
} IODBPSD ;
#endif

/* cnc_rdparam_ext:read parameters */
/* cnc_rddiag_ext:read diagnosis data */
/* cnc_start_async_wrparam:async parameter write start */
typedef struct iodbprm {
    int32_t    datano ;    /* data number */
    int16_t   type ;      /* data type */
    int16_t   axis ;      /* axis information */
    int16_t   info ;      /* misc information */
    int16_t   unit ;      /* unit information */
    struct {
        int32_t    prm_val ;   /* parameter / setting data */
        int32_t    dec_val ;
    } data[32];
} IODBPRM;

/* cnc_preset_prm:parameter preset */
typedef struct iodbbook {
    int16_t   param_no ;      /* parameter number     */
    char    axis ;          /* data type            */
    char    type ;          /* axis number          */
    union {
        char    cdata ;     /* bit / byte type data */
        int16_t   idata ;     /* word type data       */
        int32_t    ldata ;     /* 2 word type data     */
        REALPRM rdata ;     /* real type data       */
    } u ;
} IODBBOOK;

/* cnc_rdpitchr:read pitch error compensation data(area specified) (incremental)*/
/* cnc_wrpitchr:write pitch error compensation data(area specified)(incremental) */
typedef struct iodbpi {
    int16_t   datano_s ;  /* start pitch number */
    int16_t   dummy ;     /* dummy */
    int16_t   datano_e ;  /* end pitch number */
    char    data[5] ;   /* offset value */
} IODBPI ;  /* In case that the number of data is 5 */

/* cnc_rdoverstore:read overstore command */
typedef struct iodbovmst {
    char    adrs;                   /* command address */
    int32_t    num;                    /* command number */
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
	int16_t	group_num ;
	struct {
		int32_t	s_no ;
		int32_t	e_no ;
		int16_t	attr ;
	} pginf [MAX_PITCH_GROUP] ;
} IODBPITCHBLK ;

/* cnc_rdvolc : read volumetric compensation data */
/* cnc_wrvolc : write volumetric compensation data */
typedef struct tagODBVOLC {
	int32_t	start_no ;
	int32_t	start_ax ;
	int32_t	end_no ;
	int32_t	end_ax ;
	int32_t	num ;
	char	type ;
	int32_t	data[72] ;
} ODBVOLC ;

/* cnc_rdrotvolc : read rotate volumetric compensation data */
/* cnc_wrrotvolc : write rotate volumetric compensation data */
/* cnc_wrrotvolc2 : write rotate volumetric compensation data (2) */
typedef struct iodbrotvolc {
     int32_t   lin[3] ;
     int32_t   rot[3] ;
} IODBROTVOLC ;

/* cnc_rdvolccomp : get volumetric compensation amount of axes */
/* cnc_dvpunchvolc : punch volumetric compensation data to device */
/* cnc_dvreadvolc : read volumetric compensation data to device */
typedef struct tagODBVOLCOMP {
	int32_t	comp[5] ;
} ODBVOLCOMP ;

/* cnc_rdmacro:read custom macro variable */
typedef struct odbm {
    int16_t   datano ;    /* variable number */
    int16_t   dummy ;     /* dummy */
    int32_t    mcr_val ;   /* macro variable */
    int16_t   dec_val ;   /* decimal point */
} ODBM ;

/* cnc_rdmacro3:read custom macro variable (3)*/
typedef struct odbm3 {
    int32_t    datano ;    /* variable number */
    int32_t    mcr_val ;   /* macro variable */
    int16_t   dec_val ;   /* decimal point */
} ODBM3 ;

/* cnc_rdmacror:read custom macro variables(area specified) */
/* cnc_wrmacror:write custom macro variables(area specified) */
typedef struct iodbmr {
    int16_t   datano_s ;  /* start macro number */
    int16_t   dummy ;     /* dummy */
    int16_t   datano_e ;  /* end macro number */
    struct {
        int32_t    mcr_val ;   /* macro variable */
        int16_t   dec_val ;   /* decimal point */
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
    int32_t    datano ;    /* variable number */
    int16_t   dummy ;     /* dummy */
    int32_t    mcr_val ;   /* macro variable */
    int16_t   dec_val ;   /* decimal point */
} ODBPM ;

/* cnc_rdpmacror:read P code macro variables(area specified) */
/* cnc_wrpmacror:write P code macro variables(area specified) */
typedef struct iodbpr {
    int32_t    datano_s ;  /* start macro number */
    int16_t   dummy ;     /* dummy */
    int32_t    datano_e ;  /* end macro number */
    struct {
        int32_t    mcr_val ;   /* macro variable */
        int16_t   dec_val ;   /* decimal point */
    } data[5] ;
} IODBPR ;  /* In case that the number of data is 5 */

/* cnc_rdtofsinfo:read tool offset information */
typedef struct odbtlinf {
    int16_t   ofs_type;
    int16_t   use_no;
} ODBTLINF;

/* cnc_rdtofsinfo2:read tool offset information(2) */
typedef struct odbtlinf2 {
    int16_t   ofs_type;
    int16_t   use_no;
    int16_t   ofs_enable;
} ODBTLINF2;

/* cnc_rdmacroinfo:read custom macro variable information */
typedef struct odbmvinf {
    int16_t   use_no1;
    int16_t   use_no2;
} ODBMVINF;

/* cnc_rdpmacroinfo:read P code macro variable information */
#if !defined (FS15BD)
typedef struct odbpminf {
    int16_t       use_no1;
#ifdef PCD_UWORD
    uint16_T  use_no2;
#else
    int16_t       use_no2;
#endif
    int16_t       v2_type;
} ODBPMINF;
#else
typedef struct odbpminf {
    int16_t       use_no1;
#ifdef PCD_UWORD
    uint16_T  use_no2;
#else
    int16_t       use_no2;
#endif
    int16_t       v2_type1;
    int16_t       v2_type2;
} ODBPMINF;
#endif

/* cnc_rdpmacroinfo2:read P code macro variable information (2) */
typedef struct odbpminf2 {
    int32_t    use_no1;
    int32_t    use_no2;
    int32_t    use_no20;
    int16_t   v1_type;
    int16_t   v2_type;
    int16_t   v20_type;
} ODBPMINF2;

/* cnc_rdpmacroinfo3:read P code macro variable information (3)*/
typedef struct odbpminf3 {
    int16_t         use_no1;
    uint32_T use_no2;
    int16_t         v1_type;
    int16_t         v2_type;
} ODBPMINF3;

/* cnc_rdpmacvalflag:read P code macro variable flag */
typedef struct odbpmvalflg {
    int16_t       exe_type;
    int16_t       aux_type;
    int16_t       tlk_type;
} ODBPMVALFLG;

/* cnc_tofs_rnge:read validity of tool offset */
/* cnc_zofs_rnge:read validity of work zero offset */
/* cnc_wksft_rnge:read validity of work shift value */
typedef struct odbdatrng {
	int32_t	data_min;	/* lower limit */
	int32_t	data_max;	/* upper limit */
	int32_t	status;		/* status of setting */
} ODBDATRNG ;

/* cnc_rdholmes:read work zero point measurement hole measured value */
typedef struct {
	char	mes_axis[2];
	char	mes_parl[2];
	int32_t	mes_val1[2];/* #1 */
	int32_t	mes_dp1[2];
	int32_t	mes_val2[2];/* #2 */
	int32_t	mes_dp2[2];
	int32_t	mes_val3[2];/* #3 */
	int32_t	mes_dp3[2];
} ODBHOLDATA;

typedef struct  hol64 {
    double mes_val1[2] ; /* #1 */
    int32_t   mes_dp1[2]  ;
    double mes_val2[2] ; /* #2 */
    int32_t   mes_dp2[2]  ;
    double mes_val3[2] ; /* #3 */
    int32_t   mes_dp3[2]  ;
    char   mes_axis[2] ; /* axis */
    char   mes_parl[2] ;
} ODBHOLDATA64 ;

/* cnc_rdtldata:read work zero point measurement TL value */
typedef struct  tlmsinf {
	int32_t	t;			/* t data */
	int32_t	m;			/* m data */
	int32_t	hm;			/* hm data */
	int32_t	hm_dp;		/* hm_dp */
	int32_t	tlofs_no;	/* offset num */
} ODBTLMSINF ;

/* cnc_rdtlmsinfo:read tool length measurement information */
typedef struct	tldata {
	int32_t	tl;			/* tl data */
	int32_t	tl_dp;		/* tl dp */
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
	int16_t   idata[MAX_AXIS];
	int32_t    ldata[MAX_AXIS];
        REALPRM rdata[MAX_AXIS];
} HSPDATA;

#else

typedef union hspdata {
	char    cdata[MAX_AXIS];
	int16_t   idata[MAX_AXIS];
	int32_t    ldata[MAX_AXIS];
} HSPDATA;
#endif
#endif

/* cnc_rdhsparam:read parameters at the high speed */
typedef union hspdatam {
	char    cdata[32];
	int16_t   idata[32];
	int32_t    ldata[32];
        REALPRM rdata[32];
} HSPDATAM;

/* cnc_rdfixoffs:read rotary table dynamic fixture offset */
/* cnc_wrfixoffs:write rotary table dynamic fixture offset */
typedef struct odbfofs {
    int32_t    mcrval;
    int16_t   decval;
} ODBFOFS;

/* cnc_rdcdslctprm:read the machining condition parameters */
typedef struct iodbctpr {
    struct {
        int32_t    acc_bipl[MAX_AXIS];
        int32_t    acc_chg_time;
        int32_t    jerk_acc_diff[MAX_AXIS];
        int32_t    jerk_acc_diff_lin[MAX_AXIS];
        char    jerk_acc_ratio;
        int32_t    max_acc[MAX_AXIS];
        int16_t   t_con_aipl[MAX_AXIS];
        int32_t    corner_feed_diff[MAX_AXIS];
        int32_t    max_cut_fdrate[MAX_AXIS];
    } data;
    struct {
        int16_t   datano;
        int16_t   type;
        union {
            char    cdata;
            int16_t   idata;
            int32_t    ldata;
            char    cdatas[MAX_AXIS];
            int16_t   idatas[MAX_AXIS];
            int32_t    ldatas[MAX_AXIS];
        } u;
    } prm[2];
} IODBCTPR;

/* cnc_rdcdslctprmm:read the machining condition parameters */
typedef struct iodbctprm {
	union {
		// Series 16i/18i
		struct {
			int32_t    acc_bipl[8];
			int32_t    acc_chg_time;
			int32_t    jerk_acc_diff[8];
			int32_t    jerk_acc_diff_lin[8];
			char    jerk_acc_ratio;
			int32_t    max_acc[8];
			int16_t   t_con_aipl[8];
			int32_t    corner_feed_diff[8];
			int32_t    max_cut_fdrate[8];
		} data_160;

		// Series 30i/31i/32i
		struct {
			REALPRM acc_bipl[32];
			REALPRM acc_chg_time;
			REALPRM jerk_acc_diff[32];
			REALPRM jerk_acc_diff_lin[32];
			char    jerk_acc_ratio;
			REALPRM max_acc[32];
			int16_t   t_con_aipl[32];
			REALPRM corner_feed_diff[32];
			REALPRM max_cut_fdrate[32];
		} data_30i;
	} data;
	// Series 16i/18i/30i/31i/32i
	struct {
		int16_t   datano;
		int16_t   type;
		union {
			char    cdata;
			int16_t   idata;
			int32_t    ldata;
			REALPRM rdata;
			char    cdatas[32];
			int16_t   idatas[32];
			int32_t    ldatas[32];
			REALPRM rdatas[32];
		} u;
	} prm[2];
} IODBCTPRM;

/* cnc_rdtlgeomsize:read tool geom size data */
/* cnc_wrtlgeomsize:write tool geom size data */
typedef struct {
    int32_t    data1;          /* tool data1   */
    int32_t    data2;          /* tool data2   */
    char    tooltype;       /* tool kind    */
    char    install;        /* attach       */
    char    toolname[9];    /* tool name    */
    char    dummy;          /* dummy        */
} IODBTLGS;

/* cnc_rdtlgeomsize_ext:read extended tool geom size data */
/* cnc_wrtlgeomsize_ext:write extended tool geom size data */
typedef struct iodbtlgsext {
    int32_t    data1;          /* tool data1   */
    int32_t    data2;          /* tool data2   */
    int32_t    data3;          /* tool data3   */
    int32_t    data4;          /* tool data4   */
    char    tooltype;       /* tool kind    */
    char    install;        /* attach       */
    char    holder;         /* holder       */
    char    toolname[9];    /* tool name    */
} IODBTLGSEXT;

/* cnc_rdtlgeomsize_ext2:read extended tool geom size data */
/* cnc_wrtlgeomsize_ext2:write extended tool geom size data */
typedef struct iodbtlgsext2 {
    int32_t    data1;          /* tool data1   */
    int32_t    data2;          /* tool data2   */
    int32_t    data3;          /* tool data3   */
    int32_t    data4;          /* tool data4   */
    int32_t    data5;          /* tool data5   */
    int32_t    data6;          /* tool data6   */
    int32_t    data7;          /* tool data7   */
    int32_t    data8;          /* tool data8   */
    int32_t    data9;          /* tool data9   */
    int32_t    data10;         /* tool data10  */
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
    int16_t   dummy ; /* dummy */
    int16_t   type ;  /* data type */
    int32_t    data ;  /* data */
} ODBTLIFE1 ;

/* cnc_rdngrp:read tool life management data(number of tool groups) */
typedef struct odbtlife2 {
    int16_t   dummy[2] ;  /* dummy */
    int32_t    data ;      /* data */
} ODBTLIFE2 ;

/* cnc_rdntool:read tool life management data(number of tools) */
/* cnc_rdlife:read tool life management data(tool life) */
/* cnc_rdcount:read tool life management data(tool lift counter) */
typedef struct odbtlife3 {
    int16_t   datano ;    /* data number */
    int16_t   dummy ;     /* dummy */
    int32_t    data ;      /* data */
} ODBTLIFE3 ;

/* cnc_rd1length:read tool life management data(tool length number-1) */
/* cnc_rd2length:read tool life management data(tool length number-2) */
/* cnc_rd1radius:read tool life management data(cutter compensation no.-1) */
/* cnc_rd2radius:read tool life management data(cutter compensation no.-2) */
/* cnc_t1info:read tool life management data(tool information-1) */
/* cnc_t2info:read tool life management data(tool information-2) */
/* cnc_toolnum:read tool life management data(tool number) */
typedef struct odbtlife4 {
    int16_t   datano ;    /* data number */
    int16_t   type ;      /* data type */
    int32_t    data ;      /* data */
} ODBTLIFE4 ;

/* cnc_rdgrpid2:read tool life management data(tool group number) 2 */
typedef struct odbtlife5 {
    int32_t    dummy ; /* dummy */
    int32_t    type ;  /* data type */
    int32_t    data ;  /* data */
} ODBTLIFE5 ;

/* cnc_rdtoolrng:read tool life management data(tool number, tool life, tool life counter)(area specified) */
typedef struct iodbtr {
    int16_t   datano_s ;  /* start group number */
    int16_t   dummy ;     /* dummy */
    int16_t   datano_e ;  /* end group number */
    struct {
        int32_t    ntool ;     /* tool number */
        int32_t    life ;      /* tool life */
        int32_t    count ;     /* tool life counter */
    } data[5] ;
} IODBTR ;  /* In case that the number of data is 5 */

/* cnc_rdtoolgrp:read tool life management data(all data within group) */
typedef struct odbtg {
    int16_t   grp_num ;   /* start group number */
    int16_t   dummy[2] ;  /* dummy */
    int32_t    ntool ;     /* tool number */
    int32_t    life ;      /* tool life */
    int32_t    count ;     /* tool life counter */
    struct {
        int32_t    tuse_num ;      /* tool number */
        int32_t    tool_num ;      /* tool life */
        int32_t    length_num ;    /* tool life counter */
        int32_t    radius_num ;    /* tool life counter */
        int32_t    tinfo ;         /* tool life counter */
    } data[5] ;
} ODBTG ;   /* In case that the number of data is 5 */

/* cnc_wrcountr:write tool life management data(tool life counter) (area specified) */
typedef struct idbwrc {
    int16_t   datano_s ;  /* start group number */
    int16_t   dummy ;     /* dummy */
    int16_t   datano_e ;  /* end group number */
    struct {
        int32_t    dummy[2] ;  /* dummy */
        int32_t    count ;     /* tool life counter */
    } data[5] ;
} IDBWRC ;  /* In case that the number of data is 5 */

/* cnc_rdusegrpid:read tool life management data(used tool group number) */
typedef struct odbusegr {
    int16_t   datano; /* dummy */
    int16_t   type;   /* dummy */
    int32_t    next;   /* next use group number */
    int32_t    use;    /* using group number */
    int32_t    slct;   /* selecting group number */
} ODBUSEGR;

/* cnc_rdmaxgrp:read tool life management data(max. number of tool groups) */
/* cnc_rdmaxtool:read tool life management data(maximum number of tool within group) */
typedef struct odblfno {
    int16_t   datano; /* dummy */
    int16_t   type;   /* dummy */
    int16_t   data;   /* number of data */
} ODBLFNO;

/* cnc_rdusetlno:read tool life management data(used tool no within group) */
typedef struct odbtluse {
    int16_t   s_grp;      /* start group number */
    int16_t   dummy;      /* dummy */
    int16_t   e_grp;      /* end group number */
    int32_t    data[5];    /* tool using number */
} ODBTLUSE; /* In case that the number of group is 5 */

/* cnc_rd1tlifedata:read tool life management data(tool data1) */
/* cnc_rd2tlifedata:read tool life management data(tool data2) */
/* cnc_wr1tlifedata:write tool life management data(tool data1) */
/* cnc_wr2tlifedata:write tool life management data(tool data2) */
typedef struct iodbtd {
    int16_t   datano;     /* tool group number */
    int16_t   type;       /* tool using number */
    int32_t    tool_num;   /* tool number */
    int32_t    h_code;     /* H code */
    int32_t    d_code;     /* D code */
    int32_t    tool_inf;   /* tool information */
} IODBTD;

/* cnc_rd1tlifedat2:read tool life management data(tool data1) 2 */
/* cnc_wr1tlifedat2:write tool life management data(tool data1) 2 */
typedef struct iodbtd2 {
    int16_t   datano;     /* tool group number */
    int16_t   dummy;      /* dummy */
    int32_t    type;       /* tool using number */
    int32_t    tool_num;   /* tool number */
    int32_t    h_code;     /* H code */
    int32_t    d_code;     /* D code */
    int32_t    tool_inf;   /* tool information */
} IODBTD2;

/* cnc_rdgrpinfo:read tool life management data(tool group information) */
/* cnc_wrgrpinfo:write tool life management data(tool group information) */
typedef struct iodbtgi {
    int16_t   s_grp;  /* start group number */
    int16_t   dummy;  /* dummy */
    int16_t   e_grp;  /* end group number */
    struct {
        int32_t    n_tool;         /* number of tool */
        int32_t    count_value;    /* tool life */
        int32_t    counter;        /* tool life counter */
        int32_t    count_type;     /* tool life counter type */
    } data[5];
} IODBTGI;  /* In case that the number of group is 5 */

/* cnc_rdgrpinfo2:read tool life management data(tool group information 2) */
/* cnc_wrgrpinfo2:write tool life management data(tool group information 2) */
typedef struct iodbtgi2 {
    int16_t   s_grp;              /* start group number */
    int16_t   dummy;              /* dummy */
    int16_t   e_grp;              /* end group number */
    int32_t    opt_grpno[5];       /* optional group number of tool */
} IODBTGI2;  /* In case that the number of group is 5 */

/* cnc_rdgrpinfo3:read tool life management data(tool group information 3) */
/* cnc_wrgrpinfo3:write tool life management data(tool group information 3) */
typedef struct iodbtgi3 {
    int16_t   s_grp;              /* start group number */
    int16_t   dummy;              /* dummy */
    int16_t   e_grp;              /* end group number */
    int32_t    life_rest[5];       /* tool life rest count */
} IODBTGI3;  /* In case that the number of group is 5 */

/* cnc_rdgrpinfo4:read tool life management data(tool group information 4) */
/* cnc_wrgrpinfo4:write tool life management data(tool group information 4) */
typedef struct iodbtgi4 {
    int16_t   grp_no;             /* group number */
	int32_t	n_tool;				/* 				*/
	int32_t	count_value;		/*				*/
	int32_t	counter;			/*				*/
	int32_t	count_type;			/*				*/
	int32_t	opt_grpno;			/*				*/
	int32_t	life_rest;			/*				*/
} IODBTGI4;

/* cnc_instlifedt:insert tool life management data(tool data) */
typedef struct idbitd {
    int16_t   datano; /* tool group number */
    int16_t   type;   /* tool using number */
    int32_t    data;   /* tool number */
} IDBITD;

/* cnc_instlifedt:insert tool life management data(tool data) */
typedef struct idbitd2 {
    int16_t   datano; /* tool group number */
    int32_t    type;   /* tool using number */
    int32_t    data;   /* tool number */
} IDBITD2;

/* cnc_rdtlinfo:read tool life management data */
typedef struct odbtlinfo {
    int32_t    max_group;  /* maximum number of tool groups */
    int32_t    max_tool;   /* maximum number of tool within group */
    int32_t    max_minute; /* maximum number of life count (minutes) */
    int32_t    max_cycle;  /* maximum number of life count (cycles) */
} ODBTLINFO;

/* cnc_rdtlusegrp:read tool life management data(used tool group number) */
typedef struct odbusegrp {
    int32_t    next;       /* next use group number */
    int32_t    use;        /* using group number */
    int32_t    slct;       /* selecting group number */
    int32_t    opt_next;   /* next use optional group number */
    int32_t    opt_use;    /* using optional group number */
    int32_t    opt_slct;   /* selecting optional group number */
} ODBUSEGRP;

/* cnc_rdtlgrp:read tool life management data(tool group information 2) */
typedef struct iodbtlgrp {
    int32_t    ntool;      /* number of all tool */
    int32_t    nfree;      /* number of free tool */
    int32_t    life;       /* tool life */
    int32_t    count;      /* tool life counter */
    int32_t    use_tool;   /* using tool number */
    int32_t    opt_grpno;  /* optional group number */
    int32_t    life_rest;  /* tool life rest count */
    int16_t   rest_sig;   /* tool life rest signal */
    int16_t   count_type; /* tool life counter type */
} IODBTLGRP;

/* cnc_rdtltool:read tool life management data (tool data1) */
typedef struct iodbtltool {
    int32_t    tool_num;   /* tool number */
    int32_t    h_code;     /* H code */
    int32_t    d_code;     /* D code */
    int32_t    tool_inf;   /* tool information */
} IODBTLTOOL;

/* cnc_rdtltool:read tool life management data (tool data1) */
typedef struct exgrp {
    int32_t    grp_no;     /* group number */
    int32_t    opt_grpno;  /* optional group number */
} ODBEXGP;


/*-----------------------------------*/
/* CNC: Tool management data related */
/*-----------------------------------*/

/* cnc_regtool:new registration of tool management data */
/* cnc_rdtool:lead of tool management data */
/* cnc_wrtool:write of tool management data */
typedef struct  iodbtlmng {
    int32_t T_code;
    int32_t life_count;
    int32_t max_life;
    int32_t rest_life;
    unsigned char  life_stat;
    unsigned char  cust_bits;
    uint16_T tool_info;
    int16_t H_code;
    int16_t D_code;
    int32_t spindle_speed;
    int32_t feedrate;
    int16_t magazine;
    int16_t pot;
    int16_t G_code;
    int16_t W_code;
    int16_t gno;
	int16_t grp;
	int16_t edge;
    int16_t org_magazine;
    int16_t org_pot;
	unsigned char edge_num;
	char reserve_c;
	int32_t reserved[2];
    int32_t custom1;
    int32_t custom2;
    int32_t custom3;
    int32_t custom4;
    int32_t custom5;
    int32_t custom6;
    int32_t custom7;
    int32_t custom8;
    int32_t custom9;
    int32_t custom10;
    int32_t custom11;
    int32_t custom12;
    int32_t custom13;
    int32_t custom14;
    int32_t custom15;
    int32_t custom16;
    int32_t custom17;
    int32_t custom18;
    int32_t custom19;
    int32_t custom20;
} IODBTLMNG;

typedef struct  iodbtlmng_f2 {
    int32_t T_code;
    int32_t life_count;
    int32_t max_life;
    int32_t rest_life;
    unsigned char  life_stat;
    unsigned char  cust_bits;
    uint16_T tool_info;
    int16_t H_code;
    int16_t D_code;
    int32_t spindle_speed;
    int32_t feedrate;
    int16_t magazine;
    int16_t pot;
    int16_t G_code;
    int16_t W_code;
    int16_t gno;
	int16_t grp;
	int16_t edge;
    int16_t org_magazine;
    int16_t org_pot;
    unsigned char edge_num;
    char reserve_c;
	int32_t reserved[2];
    int32_t custom1;
    int32_t custom2;
    int32_t custom3;
    int32_t custom4;
    int32_t custom5;
    int32_t custom6;
    int32_t custom7;
    int32_t custom8;
    int32_t custom9;
    int32_t custom10;
    int32_t custom11;
    int32_t custom12;
    int32_t custom13;
    int32_t custom14;
    int32_t custom15;
    int32_t custom16;
    int32_t custom17;
    int32_t custom18;
    int32_t custom19;
    int32_t custom20;
    int32_t custom21;
    int32_t custom22;
    int32_t custom23;
    int32_t custom24;
    int32_t custom25;
    int32_t custom26;
    int32_t custom27;
    int32_t custom28;
    int32_t custom29;
    int32_t custom30;
    int32_t custom31;
    int32_t custom32;
    int32_t custom33;
    int32_t custom34;
    int32_t custom35;
    int32_t custom36;
    int32_t custom37;
    int32_t custom38;
    int32_t custom39;
    int32_t custom40;
} IODBTLMNG_F2;

/* cnc_wrtool2:write of individual data of tool management data */
typedef struct  idbtlm {
    int16_t data_id;
    union {
        unsigned char data1;
        int16_t         data2;
        int32_t          data4;
    } item;
} IDBTLM;

/* cnc_rdtool2:read data */
typedef struct  iodbtlm2 {
    int16_t number;
    int16_t reserve;
    union {
        unsigned char data1;
        int16_t         data2;
        int32_t          data4;
    } item;
} IODBTLM2;

/* cnc_regmagazine:new registration of magazine management data */
/* cnc_rdmagazine:lead of magazine management data */
typedef struct  iodbtlmag {
    int16_t magazine;
    int16_t pot;
    int16_t tool_index;
} IODBTLMAG;

/* cnc_delmagazine:deletion of magazine management data */
typedef struct  iodbtlmag2 {
    int16_t magazine;
    int16_t pot;
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
    int16_t inf_tool[2];
} IODBTLINTF;

typedef struct  iodbtllf {
    int32_t T_code_sum;
    int32_t life_count_sum;
    int32_t rem_life_sum;
    int32_t max_life_sum;
    int32_t notice_life_sum;
    int16_t tools_sum;
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
	int16_t order;
    int16_t tool_num;
    int32_t life_count;
    int32_t rem_life;
    int32_t max_life;
    int32_t notice_life;
    char life_stat;
    char count_type;
	int16_t reserve;
} IODBTLLFD;

typedef struct  iodbtlmgr_check {
    int32_t T_code;
	int16_t tool_num;
	int16_t reserve;
} IODBTLMGR_CHECK;

typedef struct  iodbtool_date{
	int16_t year;
	int16_t mon;
	int16_t day;
	int16_t hour;
	int16_t min;
	int16_t sec;
}IODBTOOL_DATE;

typedef struct  iodbtool_inhis{
    int16_t tool_no;
	int16_t reserve;
	IODBTOOL_DATE	date;
	IODBTLMNG_F2	tool_f2;
}IODBTOOL_INHIS;

typedef struct  iodbtool_outhis{
    int16_t tool_no;
	int16_t cause;
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
    int16_t      tl_num;
    int16_t      reserve;
    IODBTLMNG_F2 data;
} IODBTLMNG_SORT;

/* cnc_rdmag_property:read of magazineproperty data */
/* cnc_wrmag_property:write of magazineproperty data */
typedef struct  iodbmagprty {
	int16_t         mag ;	
	int16_t         reserve_s ;	
	unsigned char mag_info ;	
	char          reserve[3] ;
	int16_t         mt_line ;	
	int16_t         mt_row ;	
	int32_t          cstm[4] ;	
} IODBMAGPRTY;

/* cnc_rdpot_property:read of potproperty data */
/* cnc_wrpot_property:write of potproperty data */
typedef struct  iodbpotprty {
	int16_t           tool_no ;	
	int16_t           pot_type ;	
	unsigned char   pot_info1 ;	
	unsigned char   pot_info2 ;	
	char            reserve[2] ;
	int32_t            cstm[10] ;	
} IODBPOTPRTY;

/* cnc_delmag_property:delete of magazineproperty data */
typedef struct  iodbmagprty2 {
	int16_t           mag ;	
	int16_t           reserve ;	
} IODBMAGPRTY2;

/* cnc_magazinesrch:Search  magazine management data */
/* cnc_toolsrch    :Search  tool management data */
typedef struct  idbtlm_srchdt {
	IDBTLM	id_info;
	int16_t	srch_cond;
	int16_t	add_cond;
} IDBTLM_SRCHDT;

typedef struct  iodbtlmag_srchinfo {
    IODBTLMAG2	startInfo;
    IODBTLMAG	result;	
} IODBTLMAG_SRCHINFO;

/* cnc_tool_srh_free_min_num:Serch free number */
typedef struct  odbtl_free_num {
    int16_t  edge_gp;           /* edge group number  */
    int16_t  ofs_h;             /* ofset number (H)   */
    int16_t  ofs_d;             /* ofset number (D)   */
    int16_t  ofs_g;             /* ofset number (G)   */
    int16_t  ofs_w;             /* ofset number (W)   */
    int16_t  reserve[3];       /* reserve            */
} ODBTL_FREE_NUM;

typedef struct  iodbtlmng_mu_edge_data {
    int32_t life_count;            /*$ tool life count $*/
    int32_t max_life;              /*$ max tool life $*/
    int32_t rest_life;             /*$ tool notice life $*/
    unsigned char  life_stat;   /*$ tool life status $*/
    unsigned char  cust_bits;   /*$ customize bit $*/
    int16_t reserve_s;            /*$ reserve $*/
    int16_t H_code;               /*$ H code $*/
    int16_t D_code;               /*$ D code $*/
    int32_t spindle_speed;         /*$ spindle speed $*/
    int32_t feedrate;              /*$ feedrate speed $*/
    int16_t G_code;               /*$ TG code $*/
    int16_t W_code;               /*$ TW code $*/
    int32_t custom1;               /*$ customize 1 $*/
    int32_t custom2;               /*$ customize 2 $*/
    int32_t custom3;               /*$ customize 3 $*/
    int32_t custom4;               /*$ customize 4 $*/
} IODBTLMNG_MU_EDGE_DATA;

typedef struct  odbtlmng_edge_data {
  union {
    IODBTLMNG_MU_EDGE_DATA edge;/*$ edge data $*/
    IODBTLLF               tllf;/*$ tool life sum edge data $*/
    IODBTLLFD             tllfd;/*$ tool life sum detile edge data $*/
  } u ;
} ODBTLMNG_EDGE_DATA;

typedef struct  odbtlmng_mu_edge {
    int16_t data_no;                      /*$ data no $*/
    int16_t edge_no;                      /*$ edge no $*/
    ODBTLMNG_EDGE_DATA edge_data;   /*$ edge data $*/
} ODBTLMNG_MU_EDGE;

typedef struct  iodbtlmgr_edg {
    int16_t data_no;      /*$ data no $*/
	int16_t edge_no;      /*$ edge no $*/
} IODBTLMGR_EDG;

typedef struct  idbtlmgr_add_info {
   int32_t  dsp_info;      /*$ dsp info $*/
   int16_t data_kind;     /*$ data kind $*/
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
    uint16_T  s_no;   /* start number */
    int16_t   type;           /* dummy */
    uint16_T  e_no;   /* end number */
    union {
        struct {
            int16_t   rec_type;   /* record type */
            int16_t   alm_grp;    /* alarm group */
            int16_t   alm_no;     /* alarm number */
            char    axis_no;    /* axis number */
            char    dummy;
        } rec_alm;
        struct {
            int16_t   rec_type;   /* record type */
            char    key_code;   /* key code */
            char    pw_flag;    /* power on flag */
            char    dummy[4];
        } rec_mdi;
        struct {
            int16_t   rec_type;   /* record type */
            char    sig_name;   /* signal name */
            char    sig_old;    /* old signal bit pattern */
            char    sig_new;    /* new signal bit pattern */
            char    dummy;
            int16_t   sig_no;     /* signal number */
        } rec_sgn;
        struct {
            int16_t   rec_type;   /* record type */
            char    year;       /* year */
            char    month;      /* month */
            char    day;        /* day */
            char    pw_flag;    /* power on flag */
            char    dummy[2];
        } rec_date;
        struct {
            int16_t   rec_type;   /* record flag */
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
    int16_t   rec_len;    /* length */
    int16_t   rec_type;   /* record type */
    union {
        struct {
            char    key_code;   /* key code */
            char    pw_flag;    /* power on flag */
            int16_t   dummy;
        } rec_mdi;
        struct {
            int16_t   sig_name;   /* signal name */
            int16_t   sig_no;     /* signal number */
            char    sig_old;    /* old signal bit pattern */
            char    sig_new;    /* new signal bit pattern */
            int16_t   dummy;
        } rec_sgn;
        struct {
            int16_t   alm_grp;    /* alarm group */
            int16_t   alm_no;     /* alarm number */
            int16_t   axis_no;    /* axis number */
            int16_t   year;       /* year */
            int16_t   month;      /* month */
            int16_t   day;        /* day */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   dummy;
        } rec_alm;
        struct {
            int16_t   evnt_type;  /* event type */
            int16_t   year;       /* year */
            int16_t   month;      /* month */
            int16_t   day;        /* day */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   dummy;
        } rec_date;
    } u;
} ODBOPHIS;

/* cnc_rdophistry3:read operation history data */
typedef struct odbophis3 {
    int16_t   rec_len;    /* length */
    int16_t   rec_type;   /* record type */
    union {
        struct {
            char    key_code;   /* key code */
            char    pw_flag;    /* power on flag */
            int16_t   pth_no;     /* path index */
        } rec_mdi;
        struct {
            int16_t   sig_name;   /* signal name */
            int16_t   sig_no;     /* signal number */
            char    sig_old;    /* old signal bit pattern */
            char    sig_new;    /* new signal bit pattern */
            int16_t   pmc_no;     /* pmc index */
        } rec_sgn;
        struct {
            int16_t   alm_grp;    /* alarm group */
            int16_t   alm_no;     /* alarm number */
            int16_t   axis_no;    /* axis number */
            int16_t   year;       /* year */
            int16_t   month;      /* month */
            int16_t   day;        /* day */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   pth_no;     /* path index */
        } rec_alm;
        struct {
            int16_t   evnt_type;  /* event type */
            int16_t   year;       /* year */
            int16_t   month;      /* month */
            int16_t   day;        /* day */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   dummy;
        } rec_date;
    } u;
} ODBOPHIS3;

/* cnc_rdophistry4:read operation history data */
typedef struct odbophis4 {/*--*/
    int16_t   rec_len;    /* length */
    int16_t   rec_type;   /* record type */
    union {
        struct {
            char    key_code;   /* key code */
            char    pw_flag;    /* power on flag */
            int16_t   pth_no;     /* path index */
            int16_t   ex_flag;    /* kxternal key flag */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
        } rec_mdi;              /* MDI */
        struct {
            int16_t   sig_name;   /* signal name */
            int16_t   sig_no;     /* signal number */
            char    sig_old;    /* old signal bit pattern */
            char    sig_new;    /* new signal bit pattern */
            int16_t   pmc_no;     /* pmc index */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   dummy;
        } rec_sgn;              /* SIGNAL */
        struct {
            int16_t   alm_grp;    /* alarm group */
            int16_t   alm_no;     /* alarm number */
            int16_t   axis_no;    /* axis number */
            int16_t   year;       /* year */
            int16_t   month;      /* month */
            int16_t   day;        /* day */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   pth_no;     /* path index */
#if 0
            int16_t   sys_alm;    /* sys alarm */
            int16_t   dsp_flg;    /* message dsp flag */
            int16_t   axis_num;   /* axis num */
#endif
        } rec_alm;              /* ALARM */
        struct {
            int16_t   evnt_type;  /* event type */
            int16_t   year;       /* year */
            int16_t   month;      /* month */
            int16_t   day;        /* day */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   dummy;
        } rec_date;             /* DATE */
        struct {
            int16_t   alm_grp;    /* alarm group */
            int16_t   alm_no;     /* alarm number */
            int16_t   axis_no;    /* axis number */
            int16_t   year;       /* year */
            int16_t   month;      /* month */
            int16_t   day;        /* day */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   pth_no;     /* path index */
            int16_t   sys_alm;    /* sys alarm */
            int16_t   dsp_flg;    /* message dsp flag */
            int16_t   axis_num;   /* axis num */
            int16_t   dummy1;
            int32_t    g_modal[10];/* G code Modal */
            char    g_dp[10];   /* #7:1 Block */
                                /* #6-#0 dp*/
            int16_t   dummy2;
            int32_t    a_modal[10];/* B,D,E,F,H,M,N,O,S,T code Modal */
            char    a_dp[10];   /* #7:1 Block */
                                /* #6-#0 dp*/
            int16_t   dummy3;
            int32_t    abs_pos[32];/* Abs pos */
            char    abs_dp[32]; /* Abs dp  */
            int32_t    mcn_pos[32];/* Mcn pos */
            char    mcn_dp[32]; /* Mcn dp  */
        } rec_ial;              /* INFO ALARM */
        struct {
            int16_t   alm_grp;    /* alarm group */
            int16_t   alm_no;     /* alarm number */
            int16_t   axis_no;    /* axis number */
            int16_t   year;       /* year */
            int16_t   month;      /* month */
            int16_t   day;        /* day */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   pth_no;     /* path index */
            int16_t   sys_alm;    /* sys alarm */
            int16_t   dsp_flg;    /* message dsp flag */
            int16_t   axis_num;   /* axis num */
volatile    char    alm_msg[64];/* alarm message */
            int16_t   dummy1;
            int32_t    g_modal[10];/* G code Modal */
            char    g_dp[10];   /* #7:1 Block */
                                /* #6-#0 dp*/
            int16_t   dummy2;
            int32_t    a_modal[10];/* B,D,E,F,H,M,N,O,S,T code Modal */
            char    a_dp[10];   /* #7:1 Block */
                                /* #6-#0 dp*/
            int16_t   dummy3;
            int32_t    abs_pos[32];/* Abs pos */
            char    abs_dp[32]; /* Abs dp  */
            int32_t    mcn_pos[32];/* Mcn pos */
            char    mcn_dp[32]; /* Mcn dp  */
        } rec_mal;              /* MSG ALARM */
        struct {/*opm*/
            int16_t   dsp_flg;  /* Dysplay flag(ON/OFF) */
            int16_t   om_no;    /* message number */
            int16_t   year;       /* year */
            int16_t   month;      /* month */
            int16_t   day;        /* day */
            int16_t   hour;       /* Hour */
            int16_t   minute;     /* Minute */
            int16_t   second;     /* Second */
            char    ope_msg[256];/* Messege */
        } rec_opm;              /* EXT OPMESSAGE */
        struct {
            int16_t   ofs_grp;    /* Tool offset group */
            int16_t   ofs_no;     /* Tool offset number */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   pth_no;     /* path index */
            int32_t    ofs_old;    /* old data */
            int32_t    ofs_new;    /* new data */
            int16_t   old_dp;     /* old data decimal point */
            int16_t   new_dp;     /* new data decimal point */
        } rec_ofs;              /* TOOL OFS */
        struct {
            int16_t   prm_grp;    /* paramater group */
            int16_t   prm_num;    /* paramater number */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   prm_len;    /* paramater data length */
            int32_t    prm_no;     /* paramater no */
            int32_t    prm_old;    /* old data */
            int32_t    prm_new;    /* new data */
            int16_t   old_dp;     /* old data decimal point */
            int16_t   new_dp;     /* new data decimal point */
        } rec_prm;              /* PARAMATER */
        struct {
            int16_t   ofs_grp;    /* Work offset group */
            int16_t   ofs_no;     /* Work offset number */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   pth_no;     /* path index */
            int16_t   axis_no;    /* path axis num $*/
            int16_t   dummy;
            int32_t    ofs_old;    /* old data */
            int32_t    ofs_new;    /* new data */
            int16_t   old_dp;     /* old data decimal point */
            int16_t   new_dp;     /* new data decimal point */
        } rec_wof;              /* WORK OFS */
        struct {
            int16_t   mac_no;     /* macro val number */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   pth_no;     /* path index */
            int16_t   dummy;
            int32_t    mac_old;    /* old data */
            int32_t    mac_new;    /* new data */
            int16_t   old_dp;     /* old data decimal point */
            int16_t   new_dp;     /* old data decimal point */
        } rec_mac;              /* MACRO VAL */
        struct {
            int32_t    mac_no;     /* macro val number(expand) */
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
            int16_t   pth_no;     /* path index */
            int32_t    mac_old;    /* old data */
            int32_t    mac_new;    /* new data */
            int16_t   old_dp;     /* old data decimal point */
            int16_t   new_dp;     /* old data decimal point */
        } rec_mac2;             /* MACRO VAL2*/
        struct {
            int16_t   scrn_old;   /* old screen nubmer */
            int16_t   scrn_new;   /* new screen nubmer */
            int16_t   dummy;
            int16_t   hour;       /* hour */
            int16_t   minute;     /* minute */
            int16_t   second;     /* second */
        } rec_scrn;             /* SCREEN NUMBER*/
    } u;
} ODBOPHIS4;

/* cnc_rdalmhistry:read alarm history data */
typedef struct odbahis {
    uint16_T  s_no;   /* start number */
    int16_t   type;           /* dummy */
    uint16_T  e_no;   /* end number */
    struct {
        int16_t   dummy;
        int16_t   alm_grp;        /* alarm group */
        int16_t   alm_no;         /* alarm number */
        char    axis_no;        /* axis number */
        char    year;           /* year */
        char    month;          /* month */
        char    day;            /* day */
        char    hour;           /* hour */
        char    minute;         /* minute */
        char    second;         /* second */
        char    dummy2;
        int16_t   len_msg;        /* alarm message length */
        char    alm_msg[32];    /* alarm message */
    } alm_his[10];
} ODBAHIS;  /* In case that the number of data is 10 */

/* cnc_rdalmhistry2:read alarm history data */
typedef struct odbahis2 {
    uint16_T  s_no;   /* start number */
    uint16_T  e_no;   /* end number */
    struct {
        int16_t   alm_grp;        /* alarm group */
        int16_t   alm_no;         /* alarm number */
        int16_t   axis_no;        /* axis number */
        int16_t   year;           /* year */
        int16_t   month;          /* month */
        int16_t   day;            /* day */
        int16_t   hour;           /* hour */
        int16_t   minute;         /* minute */
        int16_t   second;         /* second */
        int16_t   len_msg;        /* alarm message length */
        char    alm_msg[32];    /* alarm message */
    } alm_his[10];
} ODBAHIS2;  /* In case that the number of data is 10 */

/* cnc_rdalmhistry3:read alarm history data */
typedef struct odbahis3 {
    uint16_T  s_no;   /* start number */
    uint16_T  e_no;   /* end number */
    struct {
        int16_t   alm_grp;        /* alarm group */
        int16_t   alm_no;         /* alarm number */
        int16_t   axis_no;        /* axis number */
        int16_t   year;           /* year */
        int16_t   month;          /* month */
        int16_t   day;            /* day */
        int16_t   hour;           /* hour */
        int16_t   minute;         /* minute */
        int16_t   second;         /* second */
        int16_t   len_msg;        /* alarm message length */
        int16_t   pth_no;         /* path index */
        int16_t   dummy;
        char    alm_msg[32];    /* alarm message */
    } alm_his[10];
} ODBAHIS3;  /* In case that the number of data is 10 */

/* cnc_rdalmhistry4:read alarm history data */
typedef struct odbahis4 {
    uint16_T  s_no;   /* start number */
    uint16_T  e_no;   /* end number */
    struct {
        int16_t   alm_grp;        /* alarm group */
        int16_t   alm_no;         /* alarm number */
        int16_t   axis_no;        /* axis number */
        int16_t   year;           /* year */
        int16_t   month;          /* month */
        int16_t   day;            /* day */
        int16_t   hour;           /* hour */
        int16_t   minute;         /* minute */
        int16_t   second;         /* second */
        int16_t   len_msg;        /* alarm message length */
        int16_t   pth_no;         /* path index */
        int16_t   dummy;
        char    alm_msg[64];    /* alarm message */
    } alm_his[10];
} ODBAHIS4;  /* In case that the number of data is 10 */

/* cnc_rdalmhistry5:read alarm history data */
typedef struct odbahis5 {
    uint16_T  s_no;   /* start number */
    uint16_T  e_no;   /* end number */
    struct {
        int16_t   alm_grp;        /* alarm group */
        int16_t   alm_no;         /* alarm number */
        int16_t   axis_no;        /* axis number */
        int16_t   year;           /* year */
        int16_t   month;          /* month */
        int16_t   day;            /* day */
        int16_t   hour;           /* hour */
        int16_t   minute;         /* minute */
        int16_t   second;         /* second */
        int16_t   len_msg;        /* alarm message length */
        int16_t   pth_no;         /* path index */
/*addalm--<*/
		int16_t   sys_alm;        /* sys alarm */
		int16_t   dsp_flg;        /* message dsp flag */
		int16_t   axis_num;    /* sum axis num */
        char    alm_msg[64]; /* alarm message */
		int32_t    g_modal[10]; /* G code Modal */
		char    g_dp[10];    /* #7:1 Block */
		                     /* #6-#0 dp*/
        int16_t   dummy1;
		int32_t    a_modal[10]; /* B,D,E,F,H,M,N,O,S,T code Modal */
		char    a_dp[10];    /* #7:1 Block */
		                     /* #6-#0 dp*/
        int16_t   dummy2;
		int32_t    abs_pos[32]; /* Abs pos */
		char    abs_dp[32];  /* Abs dp */
		int32_t    mcn_pos[32]; /* Mcn pos */
		char    mcn_dp[32];  /* Mcn dp */
/*addalm-->*/
    } alm_his[10];
} ODBAHIS5;  /* In case that the number of data is 10 */

/* cnc_rdomhistry2:read operater message history data */
typedef struct odbmhis2 {
    uint16_T  s_no;   /* start number */
    uint16_T  e_no;   /* end number */
    struct {
        int16_t   dsp_flg;  /* Dysplay flag(ON/OFF) */
        int16_t   om_no;    /* operater message number */
        int16_t   year;     /* year */
        int16_t   month;    /* month */
        int16_t   day;      /* day */
        int16_t   hour;     /* Hour */
        int16_t   minute;   /* Minute */
        int16_t   second;   /* Second */
        char    ope_msg[256];/* Messege */
    } opm_his[10];
} ODBOMHIS2;  /* In case that the number of data is 10 */

/* cnc_rdhissgnl:read signals related operation history */
/* cnc_wrhissgnl:write signals related operation history */
typedef struct iodbsig {
    int16_t   datano; /* dummy */
    int16_t   type;   /* dummy */
    struct {
        int16_t   ent_no;     /* entry number */
        int16_t   sig_no;     /* signal number */
        char    sig_name;   /* signal name */
        char    mask_pat;   /* signal mask pattern */
    } data[20];
} IODBSIG;  /* In case that the number of data is 20 */

/* cnc_rdhissgnl2:read signals related operation history 2 */
/* cnc_wrhissgnl2:write signals related operation history 2 */
typedef struct iodbsig2 {
    int16_t   datano; /* dummy */
    int16_t   type;   /* dummy */
    struct {
        int16_t   ent_no;     /* entry number */
        int16_t   sig_no;     /* signal number */
        char    sig_name;   /* signal name */
        char    mask_pat;   /* signal mask pattern */
    } data[45];
} IODBSIG2;

/* cnc_rdhissgnl3:read signals related operation history */
/* cnc_wrhissgnl3:write signals related operation history */
typedef struct iodbsig3 {
    int16_t   datano; /* dummy */
    int16_t   type;   /* dummy */
    struct {
        int16_t   ent_no;     /* entry number */
        int16_t   pmc_no;     /* PMC number */
        int16_t   sig_no;     /* signal number */
        char    sig_name;   /* signal name */
        char    mask_pat;   /* signal mask pattern */
    } data[60];
} IODBSIG3;  /* In case that the number of data is 60 */


/*--------------------------------------*/
/* CNC: 3 dimensional interferect check */
/*--------------------------------------*/
/* cnc_rdtdiinfo:read 3 dimensional interferect check information */
typedef struct odbinf {
    uint16_T  max_shape_num ;     /* maximum shape number */
    uint16_T  max_tool_num ;      /* maximum tool number */
    uint16_T  max_holder_num ;    /* maximum tool holder number */
    uint16_T  max_object_num ;    /* maximum object number */
    uint16_T  max_element_num ;   /* maximum element number */
    uint16_T  max_holder_shpnum ; /* maximum each tool holder shape number */
    uint16_T  max_object_shpnum ; /* maximum each object shape number */
    int16_t           reserve ;           /* reserve */
} ODBINF ;

/* cnc_rdtdinamesetting:read name setting */
/* cnc_wrtdinamesetting:write name setting */
typedef struct odbnme {
    int16_t           ob_type ;   /* object type */
    uint16_T  obj_no ;    /* object number */
    uint16_T  nme_no ;    /* name number */
    uint16_T  suffix  ;   /* suffix */
    char            name[12] ;  /* optional name */
} ODBNME ;

/* cnc_rdtdidispsetting:read display setting */
/* cnc_wrtdidispsetting:write display setting */
typedef struct odbdst {
    int16_t           ob_type ;   /* object type */
    uint16_T  obj_no ;    /* object number */
    unsigned char   shp_disp ;  /* figure screen */
    unsigned char   mva_disp ;  /* move axis screen */
} ODBDST ;

/* cnc_rdtdishapedata:read shape data */
/* cnc_wrtdishapedata:write shape data */
typedef struct odbshp {
    int16_t           ob_type ;       /* object type */
    uint16_T  obj_no ;        /* object number */
    uint16_T  shp_no ;        /* shape number */
    uint16_T  fig_ele[10] ;    /* figure element 1-6 */
    int32_t            ref_pos[3] ;    /* reference position */
    int32_t            tool_ref[3] ;   /* tool reference position */
    int32_t            tool_dir[3] ;   /* tool direction */
    int32_t            ref_ang1 ;      /* reference angle1 */
    int32_t            ref_ang2 ;      /* reference angle2 */
    unsigned char   n_unit ;        /* numetrical unit */
} ODBSHP ;

/* cnc_rdtdicubedata:read cube data */
/* cnc_wrtdicubedata:write cube data */
typedef struct odbcub {
    int32_t            ref_vtx[3] ;      /* reference vertex */
    int32_t            adj_vtx1[3] ;     /* adjacence vertex1 */
    int32_t            adj_vtx2[3] ;     /* adjacence vertex2 */
    int32_t            adj_vtx3[3] ;     /* adjacence vertex3 */
    unsigned char   n_unit ;          /* numetrical unit */
    char   			cb_form ;         /* cube form flag */
} ODBCUB ;

/* cnc_rdtdicubeinfo:read cube infomation */
typedef struct odbcbi {
    uint16_T  cb_no ;   /* name setting */
    ODBNME          nme_set ;   /* name setting */
    unsigned char   shp_no ;    /* shape number */
    char            cd_form ;   /* cube form flag */
} ODBCBI ;

/* cnc_rdtdimoveaxis:read move axis infomation */
/* cnc_wrtdimoveaxis:write move axis infomation */
typedef struct odbmva {
    uint16_T  sync_obj ;      /* synchronized object */
    uint16_T  path ;          /* path */

    struct {
        uint16_T  axis_no ;   /* axis number */
        uint16_T  mov_dir ;   /* moving direction */
    } lin_ax[3] ;                   /* line axis(1-3) */

    struct {
        uint16_T  axis_no ;   /* axis number */
        uint16_T  c_ax_dir ;  /* rotating direction */
        int32_t            c_pos[3] ;  /* rotating position */
        int32_t            inc_ang ;   /* inclination angle */
        uint16_T  rot_dir ;   /* rotational direction */
        int16_t           reserve ;   /* reserve */
    } rot_ax[2] ;                   /* rotating axis(1-2) */

    struct {
        uint16_T  master ;    /* master rotating axis */
        uint16_T  slave ;     /* slave rotating axis */
    } rot_ele[6] ;                  /* rotating element(1-6) */
} ODBMVA ;

/* cnc_rdtdicrntshapeinf:read current shape data */
typedef struct odbcrntshp {
    int32_t            fig_type ;
	int32_t 			reserve; 
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
    int32_t            sta_pnt[3] ;      /* start point */
    int32_t            end_pnt[3] ;      /* end point */
    int32_t            radius ;          /* radius */
    unsigned char   n_unit ;          /* numetrical unit */
    char            cb_form ;         /* figure form flag */
} ODBCYL ;

/* cnc_rdtdiplanedata:read plane data */
/* cnc_wrtdiplanedata:write plane data */
typedef struct odbpln {
    int32_t            point[3] ;        /* optional point on plane */
    int32_t            vect[3] ;         /* vertical vector */
    unsigned char   n_unit ;          /* numetrical unit */
    char            cb_form ;         /* figure form flag */
} ODBPLN ;

/* cnc_rdtdifiguredata:read figure data */
/* cnc_wrtdifiguredata:write figure data */
typedef struct odbfig {
    int32_t            fig_type ;        /* figure type */
    union {
	    struct {
            int32_t    ref_vtx[3] ;      /* reference vertex */
            int32_t    adj_vtx1[3] ;     /* adjacence vertex1 */
            int32_t    adj_vtx2[3] ;     /* adjacence vertex2 */
            int32_t    adj_vtx3[3] ;     /* adjacence vertex3 */
	    } par ;
	    struct {
            int32_t    sta_pnt[3] ;      /* start point */
            int32_t    end_pnt[3] ;      /* end point */
            int32_t    radius ;          /* radius */
	    } cyl ;
	    struct {
            int32_t    point[3] ;        /* optional point on plane */
            int32_t    vect[3] ;         /* vertical vector */
	    } pln ;
    } fig ;
    uint16_T  fig_no ;          /* figure number */
    unsigned char   n_unit ;          /* numetrical unit */
    char            cb_form ;         /* figure form flag */
} ODBFIG ;

/*-------------*/
/* CNC: Others */
/*-------------*/

/* cnc_sysinfo:read CNC system information */
#if !defined (FS15BD)
typedef struct odbsys {
    int16_t   addinfo ;       /* additional information  */
    int16_t   max_axis ;      /* maximum axis number */
    char    cnc_type[2] ;   /* cnc type <ascii char> */
    char    mt_type[2] ;    /* M/T/TT <ascii char> */
    char    series[4] ;     /* series NO. <ascii char> */
    char    version[4] ;    /* version NO.<ascii char> */
    char    axes[2] ;       /* axis number<ascii char> */
} ODBSYS ;
#else
typedef struct odbsys {
    int16_t   dummy ;         /* dummy                   */
    char    max_axis[2] ;   /* maximum axis number     */
    char    cnc_type[2] ;   /* cnc type <ascii char> */
    char    mt_type[2] ;    /* M/T/TT <ascii char> */
    char    series[4] ;     /* series NO. <ascii char> */
    char    version[4] ;    /* version NO.<ascii char> */
    char    axes[2] ;       /* axis number<ascii char> */
} ODBSYS ;
#endif

typedef struct _odbsramif {
    int32_t    protect;        /* protective state of File SRAM */
    int32_t    size;           /* size of File SRAM */
} ODBSRAMIF;

typedef struct _odbsramif2 {
    int32_t            protect;    /* protective state of File SRAM */
    uint32_T   adrs;       /* address of File SRAM */
    int32_t            size;       /* size of File SRAM */
} ODBSRAMIF2;

/* cnc_statinfo:read CNC status information */

#if defined (FS15D) || defined (FS15BD)
typedef struct odbst {
    int16_t dummy[2];     /* dummy                    */
    int16_t aut;          /* selected automatic mode  */
    int16_t manual;       /* selected manual mode     */
    int16_t run;          /* running status           */
    int16_t edit;         /* editting status          */
    int16_t motion;       /* axis, dwell status       */
    int16_t mstb;         /* m, s, t, b status        */
    int16_t emergency;    /* emergency stop status    */
    int16_t write;        /* writting status          */
    int16_t labelskip;    /* label skip status        */
    int16_t alarm;        /* alarm status             */
    int16_t warning;      /* warning status           */
    int16_t battery;      /* battery status           */
} ODBST ;

#elif defined (FS16WD)
typedef struct odbst {
    int16_t   dummy[2] ;  /* dummy */
    int16_t   aut ;       /* selected automatic mode */
    int16_t   run ;       /* running status */
    int16_t   motion ;    /* axis, dwell status */
    int16_t   mstb ;      /* m, s, t, b status */
    int16_t   emergency ; /* emergency stop status */
    int16_t   alarm ;     /* alarm status */
    int16_t   edit ;      /* editting status */
} ODBST ;

#else
typedef struct odbst {
    int16_t   hdck ;      /* handl retrace status */
    int16_t   tmmode ;    /* T/M mode */
    int16_t   aut ;       /* selected automatic mode */
    int16_t   run ;       /* running status */
    int16_t   motion ;    /* axis, dwell status */
    int16_t   mstb ;      /* m, s, t, b status */
    int16_t   emergency ; /* emergency stop status */
    int16_t   alarm ;     /* alarm status */
    int16_t   edit ;      /* editting status */
} ODBST ;
#endif

/* cnc_statinfo2:read CNC status information 2 */
typedef struct odbst2 {
    int16_t   hdck ;      /* handl retrace status */
    int16_t   tmmode ;    /* T/M mode */
    int16_t   aut ;       /* selected automatic mode */
    int16_t   run ;       /* running status */
    int16_t   motion ;    /* axis, dwell status */
    int16_t   mstb ;      /* m, s, t, b status */
    int16_t   emergency ; /* emergency stop status */
    int16_t   alarm ;     /* alarm status */
    int16_t   edit ;      /* editting status */
    int16_t   warning ;   /* warning status */
    int16_t   o3dchk;     /* o3dchk status */
    int16_t   ext_opt;    /* option */
    int16_t   restart;    /* State of edit when SBK */
} ODBST2 ;

/* cnc_sramstat:After setting the option, The state of SRAM is acquired.*/
typedef struct odbopmsg {
    int16_t   msg_kind;   /* state of message */
    char    msg[30];    /* message string   */
} ODBOPMSG ;

/* cnc_sramstatus:After setting the option, The state of SRAM is acquired.*/
typedef struct odbsramstat {
    int16_t   msg_kind;   /* state of message */
    char    msg[64];    /* message string   */
} ODBSRAMSTAT ;

/* read DMG Netservice status information */
typedef struct out_statinfo_dmg {
     int16_t  dummy[1];     /* Not used                          */
     int16_t  dmg;          /* DMG Netservice status information */
     int16_t  dummy1[7];    /* Not used                          */
} OUT_STATINF_DMG ;

/* cnc_alarm:read alarm status */
typedef struct odbalm {
    int16_t   dummy[2] ;  /* dummy */
    int16_t   data ;      /* alarm status */
} ODBALM ;

/* cnc_rdalminfo:read alarm information */
typedef struct alminfo {
#if MAX_AXIS > 16
    union {
        struct {
            struct {
                int32_t    axis ;
                int16_t   alm_no ;
            } alm[5] ;
            int32_t    data_end ;
        } alm1 ;
        struct {
            struct {
                int32_t    axis ;
                int16_t   alm_no ;
                int16_t   msg_len ;
                char    alm_msg[32] ;
            } alm[5] ;
            int32_t    data_end ;
        }alm2 ;
    } u ;
#else
    union {
        struct {
            struct {
                int16_t   axis ;
                int16_t   alm_no ;
            } alm[5] ;
            int16_t   data_end ;
        } alm1 ;
        struct {
            struct {
                int16_t   axis ;
                int16_t   alm_no ;
                int16_t   msg_len ;
                char    alm_msg[32] ;
            } alm[5] ;
            int16_t   data_end ;
        }alm2 ;
    } u ;
#endif
} ALMINFO ; /* In case that the number of alarm is 5 */

/* cnc_rdalminfo2:read alarm information */
typedef struct alminfo2 {
    union {
        struct {
            struct {
                int16_t   axis ;
                int16_t   alm_no ;
            } alm[5] ;
            int16_t   data_end ;
        } alm1 ;
        struct {
            struct {
                int16_t   axis ;
                int16_t   alm_no ;
                int16_t   msg_len ;
                char    alm_msg[34] ;
            } alm[5] ;
            int16_t   data_end ;
        }alm2 ;
    } u ;
} ALMINFO2 ; /* In case that the number of alarm is 5 */

/* cnc_rdalmmsg:read alarm messages */
typedef struct odbalmmsg {
    int32_t    alm_no;
    int16_t   type;
    int16_t   axis;
    int16_t   dummy;
    int16_t   msg_len;
    char    alm_msg[32];
} ODBALMMSG ;

typedef struct odbalmmsg2 {
    int32_t    alm_no;
    int16_t   type;
    int16_t   axis;
    int16_t   dummy;
    int16_t   msg_len;
    char    alm_msg[64];
} ODBALMMSG2 ;

typedef struct odbalmmsg3 {
    int32_t    alm_no;
    int16_t   type;
    int16_t   axis;
    int16_t   dummy;
    int16_t   msg_len;
    char    alm_msg[256];
} ODBALMMSG3 ;

/* cnc_modal:read modal data */
#if defined (HSSB_LIB) && defined (FS16WD)
typedef struct odbmdl {
    int16_t   datano;
    int16_t   type;
    union {
        char    g_data;
        char    g_rdata[12];
        char    g_1shot;
        struct {
            int32_t    aux_data;
            char    flag1;
            char    flag2;
        }aux;
        struct {
            int32_t    aux_data;
            char    flag1;
            char    flag2;
        }raux1[25];
    }modal;
} ODBMDL ;
#else
typedef struct odbmdl {
    int16_t   datano;
    int16_t   type;
    union {
        char    g_data;
        char    g_rdata[35];
        char    g_1shot[4];
        struct {
            int32_t    aux_data;
            char    flag1;
            char    flag2;
        }aux;
        struct {
            int32_t    aux_data;
            char    flag1;
            char    flag2;
        }raux1[27];
        struct {
            int32_t    aux_data;
            char    flag1;
            char    flag2;
        }raux2[MAX_AXIS];
    }modal;
} ODBMDL ;
#endif

/* cnc_rdgcode: read G code */
typedef struct odbgcd {
	int16_t	group ;
	int16_t	flag ;
	char	code[8] ;
} ODBGCD;

/* cnc_rdcommand: read command value */
typedef struct odbcmd {
	char	adrs ;
	char	num ;
	int16_t	flag ;
	int32_t	cmd_val ;
	int32_t	dec_val ;
} ODBCMD;

/* cnc_diagnoss:read diagnosis data */
/* cnc_diagnosr:read diagnosis data(area specified) */
typedef struct realdgn {
        int32_t   dgn_val;     /* data of real diagnoss */
        int32_t   dec_val;     /* decimal point of real diagnoss */
} REALDGN ;

#if !defined (HSSB_LIB) || defined (FS30D) || defined (FS15D) || defined (FS0IDD) /* Ethernet & FS30i & FS15i & FS0i-D */
typedef struct odbdgn {
    int16_t   datano ;    /* data number */
    int16_t   type ;      /* axis number */
    union {
        char    cdata ; /* diagnosis data */
        int16_t   idata ;
        int32_t    ldata ;
        REALDGN rdata ;
        char    cdatas[MAX_AXIS] ;
        int16_t   idatas[MAX_AXIS] ;
        int32_t    ldatas[MAX_AXIS] ;
        REALDGN rdatas[MAX_AXIS] ;
    } u ;
} ODBDGN ;

#else

typedef struct odbdgn {
    int16_t   datano ;    /* data number */
    int16_t   type ;      /* axis number */
    union {
        char    cdata ; /* diagnosis data */
        int16_t   idata ;
        int32_t    ldata ;
        char    cdatas[MAX_AXIS] ;
        int16_t   idatas[MAX_AXIS] ;
        int32_t    ldatas[MAX_AXIS] ;
    } u ;
} ODBDGN ;
#endif

#if defined (FS15BD)

/* cnc_adcnv:read A/D conversion data */
typedef struct odbad {
    int16_t   datano ;    /* input analog voltage type */
    int16_t   type ;      /* analog voltage type */
    char    data ;      /* digital voltage data */
} ODBAD ;

#else

/* cnc_adcnv:read A/D conversion data */
typedef struct odbad {
    int16_t   datano ;    /* input analog voltage type */
    int16_t   type ;      /* analog voltage type */
    int16_t   data ;      /* digital voltage data */
} ODBAD ;

#endif

#if defined (FS15D) || defined (FS15BD)

/* cnc_rdopmsg:read operator's message */
typedef struct msg {
    int16_t datano ;     /* operator's message number */
    int16_t type ;       /* operator's message type   */
    int16_t char_num ;   /* message string length   */
    char  data[129] ;  /* operator's message string */
} OPMSG ;               /* In case that the data length is 129 */

#else	/* FS15D */

/* cnc_rdopmsg:read operator's message */
typedef struct msg {
    int16_t   datano ;    /* operator's message number */
    int16_t   type ;      /* operator's message type */
    int16_t   char_num ;  /* message string length */
    char    data[256] ; /* operator's message string */
} OPMSG ;   /* In case that the data length is 256 */

#endif	/* FS15D */

/* cnc_rdopmsg2:read operator's message */
typedef struct opmsg2 {
    int16_t   datano ;    /* operator's message number */
    int16_t   type ;      /* operator's message type */
    int16_t   char_num ;  /* message string length */
    char    data[64] ;  /* operator's message string */
} OPMSG2 ;   /* In case that the data length is 64 */

/* cnc_rdopmsg3:read operator's message */
typedef struct opmsg3 {
    int16_t   datano ;    /* operator's message number */
    int16_t   type ;      /* operator's message type */
    int16_t   char_num ;  /* message string length */
    char    data[256] ; /* operator's message string */
} OPMSG3 ;   /* In case that the data length is 256 */

/* cnc_rdopmsgmps:read operator message for MAPPS */
typedef struct _opmsgmps {
	int16_t datano;
	int16_t type;
	int16_t char_num;
	char data[256];
} OPMSGMPS;

/* cnc_sysconfig:read CNC configuration information */
#if defined (FS15BD)
typedef struct odbsysc {
    char        slot_no_p[16];
    char        slot_no_l[16];
    int16_t       mod_id[16];
    int16_t       soft_id[16];
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
    int16_t       pcb_info[20];
    int16_t       pcb_note[20][16];
} ODBSYSC ;

#elif defined (PMD)
typedef struct odbsysc {
     char    slot_no_p[16];	/* not used */
     char    slot_no_l[16];	/* not used */
     int16_t   mod_id[16];	/* not used */
     int16_t   soft_id[16];	/* software ID */
     char    s_series[16][5];	/* software series */
     char    s_version[16][5];	/* software version */
     char    dummy[16];		/* dummy */
     int16_t   m_rom;		/* not used */
     int16_t   s_rom;		/* not used */
     char    svo_soft[8];	/* series and version of searvo software */
     char    pmc_soft[6];	/* series and version of PMC management software */
     char    lad_soft[6];	/* series and version of Ladder software */
     char    mcr_soft[8];	/* series and version of a macro executor */
     char    spl1_soft[6];	/* not used */
     char    spl2_soft[6];	/* not used */
     int16_t   frmmin;		/* capacity of FROM module */
     int16_t   drmmin;		/* capacity of DRAM module */
     int16_t   srmmin;		/* capacity of added SRAM module */
     int16_t   pmcmin;		/* type of PMC module */
     int16_t   sv1min;		/* presence or absence of a servo module 1,2 */
     int16_t   sv3min;		/* presence or absence of a servo module 3,4 */
     int16_t   sv5min;		/* presence or absence of a servo module 5,6 */
     int16_t   sicmin;		/* presence or absence of SIC */
     int16_t   posmin;		/* presence or absence of a position LSI */
     int16_t   submin;		/* information of sub-board */
     int16_t   hdiio;		/* presence or absence of an LSI for high-speed skip(I/O card) */
     int16_t   dummy2[32];	/* dummy */
} ODBSYSC;

#else
typedef struct odbsysc {
    char    slot_no_p[16];
    char    slot_no_l[16];
    int16_t   mod_id[16];
    int16_t   soft_id[16];
    char    s_series[16][5];
    char    s_version[16][5];
    char    dummy[16];
    int16_t   m_rom;
    int16_t   s_rom;
    char    svo_soft[8];
    char    pmc_soft[6];
    char    lad_soft[6];
    char    mcr_soft[8];
    char    spl1_soft[6];
    char    spl2_soft[6];
    int16_t   frmmin;
    int16_t   drmmin;
    int16_t   srmmin;
    int16_t   pmcmin;
    int16_t   crtmin;
    int16_t   sv1min;
    int16_t   sv3min;
    int16_t   sicmin;
    int16_t   posmin;
    int16_t   drmmrc;
    int16_t   drmarc;
    int16_t   pmcmrc;
    int16_t   dmaarc;
    int16_t   iopt;
    int16_t   hdiio;
    int16_t   frmsub;
    int16_t   drmsub;
    int16_t   srmsub;
    int16_t   sv5sub;
    int16_t   sv7sub;
    int16_t   sicsub;
    int16_t   possub;
    int16_t   hamsub;
    int16_t   gm2gr1;
    int16_t   crtgr2;
    int16_t   gm1gr2;
    int16_t   gm2gr2;
    int16_t   cmmrb;
    int16_t   sv5axs;
    int16_t   sv7axs;
    int16_t   sicaxs;
    int16_t   posaxs;
    int16_t   hanaxs;
    int16_t   romr64;
    int16_t   srmr64;
    int16_t   dr1r64;
    int16_t   dr2r64;
    int16_t   iopio2;
    int16_t   hdiio2;
    int16_t   cmmrb2;
    int16_t   romfap;
    int16_t   srmfap;
    int16_t   drmfap;
} ODBSYSC ;
#endif

/* cnc_rdprstrinfo:read program restart information */
typedef struct odbprs {
    int16_t   datano;         /* dummy */
    int16_t   type;           /* dummy */
    int16_t   data_info[5];   /* data setting information */
    int32_t    rstr_bc;        /* block counter */
    int32_t    rstr_m[35];     /* M code value */
    int32_t    rstr_t[2];      /* T code value */
    int32_t    rstr_s;         /* S code value */
    int32_t    rstr_b;         /* B code value */
    int32_t    dest[MAX_AXIS]; /* program re-start position */
    int32_t    dist[MAX_AXIS]; /* program re-start distance */
} ODBPRS;

/* cnc_rdprstrinfo:read program restart information */
typedef struct odbprsm {
    int16_t   datano;          /* dummy */
    int16_t   type;            /* dummy */
    int16_t   data_info[5];    /* data setting information */
    int32_t    rstr_bc;         /* block counter */
    int32_t    rstr_m[35];      /* M code value */
    int32_t    rstr_t[2];       /* T code value */
    int32_t    rstr_s;          /* S code value */
    int32_t    rstr_b;          /* B code value */
    int32_t    dest[32];        /* program re-start position */
    int32_t    dist[32];        /* program re-start distance */
} ODBPRSM;

#if defined (FS15D) || defined (FS15BD)

/* cnc_rdopnlsgnl:read output signal image of software operator's panel */
/* cnc_wropnlsgnl:write output signal of software operator's panel */
typedef struct iodbsgnl {
    int16_t   datano;     /* dummy */
    int16_t   type;       /* data select flag */
    int16_t   mode;       /* mode signal */
    int16_t   hndl_ax;    /* Manual handle feed axis selection signal */
    int16_t   hndl_mv;    /* Manual handle feed travel distance selection signal */
    int16_t   rpd_ovrd;   /* rapid traverse override signal */
    int16_t   jog_ovrd;   /* manual feedrate override signal */
    int16_t   feed_ovrd;  /* feedrate override signal */
    int16_t   spdl_ovrd;  /* spindle override signal */
    int16_t   blck_del;   /* optional block skip signal */
    int16_t   sngl_blck;  /* single block signal */
    int16_t   machn_lock; /* machine lock signal */
    int16_t   dry_run;    /* dry run signal */
    int16_t   mem_prtct;  /* memory protection signal */
    int16_t   feed_hold;  /* automatic operation halt signal */
    int16_t   manual_rpd; /* manual rapid traverse selection signal */
    int16_t   dummy[2];   /* (not used) */
} IODBSGNL;

#else	/* FS15D */

/* cnc_rdopnlsgnl:read output signal image of software operator's panel */
/* cnc_wropnlsgnl:write output signal of software operator's panel */
typedef struct iodbsgnl {
    int16_t   datano;     /* dummy */
    int16_t   type;       /* data select flag */
    int16_t   mode;       /* mode signal */
    int16_t   hndl_ax;    /* Manual handle feed axis selection signal */
    int16_t   hndl_mv;    /* Manual handle feed travel distance selection signal */
    int16_t   rpd_ovrd;   /* rapid traverse override signal */
    int16_t   jog_ovrd;   /* manual feedrate override signal */
    int16_t   feed_ovrd;  /* feedrate override signal */
    int16_t   spdl_ovrd;  /* (not used) */
    int16_t   blck_del;   /* optional block skip signal */
    int16_t   sngl_blck;  /* single block signal */
    int16_t   machn_lock; /* machine lock signal */
    int16_t   dry_run;    /* dry run signal */
    int16_t   mem_prtct;  /* memory protection signal */
    int16_t   feed_hold;  /* automatic operation halt signal */
} IODBSGNL;

#endif	/* FS15D */

/* cnc_rdopnlgnrl:read general signal image of software operator's panel */
/* cnc_wropnlgnrl:write general signal image of software operator's panel */
typedef struct iodbgnrl {
    int16_t   datano; /* dummy */
    int16_t   type;   /* data select flag */
    char    sgnal;  /* general signal */
} IODBGNRL;

/* cnc_rdopnlgnrl2:read general signal image of software operator's panel(2) */
/* cnc_wropnlgnrl2:write general signal image of software operator's panel(2) */
typedef struct iodbgnrl2 {
    int16_t   datano; /* dummy */
    int16_t   type;   /* data select flag */
    int16_t   sgnal;  /* general signal */
} IODBGNRL2;

/* cnc_rdopnlgsname:read general signal name of software operator's panel */
/* cnc_wropnlgsname:write general signal name of software operator's panel*/
typedef struct iodbrdna {
    int16_t   datano;         /* dummy */
    int16_t   type;           /* data select flag */
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
    int16_t   datano;         /* dummy */
    int16_t   type;           /* data select flag */
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
    int16_t   err_no ;
    int16_t   err_dtno ;
} ODBERR ;

/* cnc_rdparainfo:read informations of CNC parameter */
typedef struct odbparaif {
    uint16_T  info_no ;
    int16_t   prev_no ;
    int16_t   next_no ;
    struct {
        int16_t   prm_no ;
        int16_t   prm_type ;
    } info[10] ;    /* In case that the number of data is 10 */
} ODBPARAIF ;

/* cnc_rdsetinfo:read informations of CNC setting data */
typedef struct odbsetif {
    uint16_T  info_no ;
    int16_t   prev_no ;
    int16_t   next_no ;
    struct {
        int16_t   set_no ;
        int16_t   set_type ;
    } info[10] ;    /* In case that the number of data is 10 */
} ODBSETIF ;

/* cnc_rddiaginfo:read informations of CNC diagnose data */
typedef struct odbdiagif {
    uint16_T  info_no ;
    int16_t   prev_no ;
    int16_t   next_no ;
    struct {
        int16_t   diag_no ;
        int16_t   diag_type ;
    } info[10] ;    /* In case that the number of data is 10 */
} ODBDIAGIF ;

/* cnc_rdparainfo2:read informations of CNC parameter(2) */
/* cnc_rdparainfo3:read informations of CNC parameter(3) */
/* cnc_rdsetinfo2:read informations of CNC setting data(2) */
/* cnc_rddiaginfo2:read informations of CNC diagnose data(2) */
typedef struct odbparaif2 {
    int16_t   prm_no;         /* parameter number */
    int16_t   size;           /* size */
    int16_t   array;          /* array type */
    int16_t   unit;           /* unit */
    int16_t   dim;            /* dimension */
    int16_t   input;          /* input type */
    int16_t   display;        /* display infomation */
    int16_t   others;         /* others */
} ODBPARAIF2 ;

/* cnc_rdparanum:read maximum, minimum and total number of CNC parameter */
typedef struct odbparanum {
    uint16_T  para_min ;
    uint16_T  para_max ;
    uint16_T  total_no ;
} ODBPARANUM ;

/* cnc_rdsetnum:read maximum, minimum and total number of CNC setting data */
typedef struct odbsetnum {
    uint16_T  set_min ;
    uint16_T  set_max ;
    uint16_T  total_no ;
} ODBSETNUM ;

/* cnc_rddiagnum:read maximum, minimum and total number of CNC diagnose data */
typedef struct odbdiagnum {
    uint16_T  diag_min ;
    uint16_T  diag_max ;
    uint16_T  total_no ;
} ODBDIAGNUM ;

/* cnc_rdfrominfo:read F-ROM information on CNC  */
typedef struct odbfinfo {
    char  slotname[12];      /* Slot Name */
    int32_t  fromnum;           /* Number of F-ROM SYSTEM data */
    struct {
        char  sysname[12];   /* F-ROM SYSTEM data Name */
        int32_t  fromsize;      /* F-ROM Size */
    } info[32];
} ODBFINFO;

/* cnc_getfrominfo:read F-ROM information on CNC  */
#ifndef CNC_PPC
typedef struct odbfinform {
    int32_t  slotno;            /* Slot Number */
    char  slotname[12];      /* Slot Name */
    int32_t  fromnum;           /* Number of F-ROM SYSTEM data */
    struct {
        char  sysname[12];   /* F-ROM SYSTEM data Name */
        int32_t  fromsize;      /* F-ROM Size */
        int32_t  fromattrib;    /* F-ROM data attribute */
    } info[128];
} ODBFINFORM;
#endif

/* cnc_rdsraminfo:read S-RAM information on CNC */
/* cnc_getsraminfo:read S-RAM information on CNC */
typedef struct odbsinfo {
    int32_t  sramnum;          /* Number of S-RAM data */
    struct {
        char  sramname[12]; /* S-RAM data Name */
        int32_t  sramsize;     /* S-RAM data Size */
        int16_t divnumber;    /* Division number of S-RAM file */
        char  fname[6][16]; /* S-RAM file names */
    } info[8];
} ODBSINFO;

/* cnc_rdsramaddr:read S-RAM address on CNC */
typedef struct sramaddr {
    int16_t   type ;          /* SRAM data type */
    int32_t    size ;          /* SRAM data size */
    int32_t    offset ;        /* offset from top address of SRAM */
} SRAMADDR ;

/* cnc_dtsvrdpgdir:read file directory in Data Server */
typedef struct odbdsdir {
    int32_t    file_num ;
    int32_t    remainder ;
    int16_t   data_num ;
    struct {
        char    file_name[16] ;
        char    comment[64] ;
        int32_t    size ;
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
	int32_t empty_cnt ;
	int32_t total_size ;
	int32_t read_ptr ;
	int32_t write_ptr ;
} ODBDSMNT ;

/* cnc_rdposerrs2:read the position deviation S1 and S2 */
typedef struct odbpser {
    int32_t    poserr1 ;
    int32_t    poserr2 ;
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
        int16_t   dummy;
        int16_t   dtype;
        int32_t    fback[MAX_AXIS];
        int32_t    afback[MAX_AXIS];
} ODBSVFBACK;

/* cnc_rdwaveprm:read the parameter of wave diagnosis */
/* cnc_wrwaveprm:write the parameter of wave diagnosis */
typedef struct iodbwave {
    int16_t   condition ;
    char    trg_adr ;
    char    trg_bit ;
    int16_t   trg_no ;
    int16_t   delay ;
    int16_t   t_range ;
    struct {
        int16_t   kind ;
        union {
#if MAX_AXIS > 16
            int32_t        axis ;
#else
            int16_t       axis ;
#endif
            struct {
                char    adr ;
                char    bit ;
                int16_t   no ;
            } io ;
        } u ;
    } ch[12] ;
} IODBWAVE ;

/* cnc_rdwaveprm2:read the parameter of wave diagnosis 2 */
/* cnc_wrwaveprm2:write the parameter of wave diagnosis 2 */
typedef struct iodbwvprm {
    int16_t   condition ;
    char    trg_adr ;
    char    trg_bit ;
    int16_t   trg_no ;
    int16_t   reserve1 ;
    int32_t    delay ;
    int32_t    t_range ;
    struct {
        int16_t   kind ;
        union {
            int32_t    axis ;
            struct {
                char    adr ;
                char    bit ;
                int16_t   no ;
            } io ;
        } u ;
        int32_t    reserve2 ;
    } ch[12] ;
} IODBWVPRM ;

/* cnc_rdwaveprm3:read the parameter of wave diagnosis 3 */
/* cnc_wrwaveprm3:write the parameter of wave diagnosis 3 */
typedef struct iodbwvprm3 {
    int16_t   condition ;
    int16_t   trg_unittype ;
    char    trg_adr ;
    char    trg_bit ;
    int16_t   trg_no ;
    int16_t   alm_kind ;
    int16_t   alm_no ;
    int16_t   alm_axis ;
    int16_t   reserve1 ;
    int32_t    delay ;
    int32_t    t_range ;
    int16_t   wav_cycle ;
    int16_t   dio_cycle ;
    struct {
        int16_t   kind ;
        int16_t   reserve2 ;
        union {
            struct {
                int32_t    axis ;
                int32_t    reserve3;
            } ax ;
            struct {
                int16_t   unittype ;
                char    adr ;
                char    bit ;
                int16_t   no ;
                int16_t   reserve3 ;
            } io ;
        } u ;
    } ch[40] ;
} IODBWVPRM3 ;

/* cnc_rdwavedata:read the data of wave diagnosis */
typedef struct odbwvdt {
    int16_t   channel ;
    int16_t   kind ;
    union {
        int16_t   axis ;
        struct {
            char    adr ;
            char    bit ;
            int16_t   no ;
        } io ;
    } u ;
    char    year ;
    char    month ;
    char    day ;
    char    hour ;
    char    minute ;
    char    second ;
    int16_t   t_cycle ;
    int16_t   data[8192] ;
} ODBWVDT ;

typedef struct odbwvdt2 {
    int16_t   channel ;
    union {
        struct {
            int16_t   axis ;
            char    kind ;
        } w ;
        struct {
            int16_t   no ;
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
    int16_t   t_cycle ;
    int16_t   adjust ;
    int16_t   data[ 8192 ] ;
} ODBWVDT2 ;

/* cnc_rdwavedata3:read the data of wave diagnosis */
typedef struct odbwvdt3 {
    int16_t   channel ;
    int16_t   kind ;
    union {
        struct{
            int16_t   axis ;
            int16_t   reserve[3] ;
        } ax ;
        struct {
            int16_t   unittype ;
            char    adr ;
            char    bit ;
            int16_t   no ;
            int16_t   reserve ;
        } io ;
    } u ;
    char    year ;
    char    month ;
    char    day ;
    char    hour ;
    char    minute ;
    char    second ;
    int16_t   t_cycle ;
    int16_t   data[8192] ;
} ODBWVDT3 ;

/* cnc_rdrmtwaveprm:read the parameter of wave diagnosis for remort diagnosis */
/* cnc_wrrmtwaveprm:write the parameter of wave diagnosis for remort diagnosis */
typedef struct iodbrmtprm {
    int16_t   condition ;
    int16_t   reserve ;
    union {
        struct {
            int16_t   no ;
            char    axis ;
            char    type ;
        } alm ;
        struct {
            char    adr ;
            char    bit ;
            int16_t   no ;
        } io ;
    } trg ;
    int32_t    delay ;
    int16_t   wv_intrvl ;
    int16_t   io_intrvl ;
    int16_t   kind1 ;
    int16_t   kind2 ;
    struct {
           char    adr ;
           char    bit ;
           int16_t   no ;
    } smpl[32] ;
} IODBRMTPRM ;

/* cnc_rdrmtwavedt:read the data of wave diagnosis for remort diagnosis */
typedef struct odbrmtdt {
    int16_t   channel ;
    int16_t   kind ;
    char    year ;
    char    month ;
    char    day ;
    char    hour ;
    char    minute ;
    char    second ;
    int16_t   t_intrvl ;
    int16_t   trg_data;
    int32_t    ins_ptr;
    int16_t   t_delta;
    int16_t   data[1917] ;
} ODBRMTDT ;

/* cnc_rdsavsigadr:read of address for PMC signal batch save */
/* cnc_wrsavsigadr:write of address for PMC signal batch save */
typedef struct iodbsigad {
    char    adr ;
    char    reserve ;
    int16_t   no ;
    int16_t   size ;
} IODBSIGAD ;

/* cnc_rdmgrpdata:read M-code group data */
typedef struct odbmgrp {
	int32_t  m_code ;
	int16_t grp_no ;
	char  m_name[21] ;
	char  dummy ;
} ODBMGRP;

/* cnc_wrmgrpdata:write M-code group data */
typedef struct idbmgrp {
	int16_t s_no ;
	int16_t dummy ;
	int16_t num ;
	int16_t group[500] ;
} IDBMGRP ;

/* cnc_rdexecmcode:read executing M-code group data */
typedef struct odbexem {
    int16_t	grp_no;
    int16_t	mem_no;
    struct{
	int32_t	no;
	int16_t	flag;
    }m_code[5];
    char	m_name[21];
    char	dummy;
} ODBEXEM;

/* cnc_rdrstrmcode:read program restart M-code group data */
#ifndef CNC_PPC
typedef struct odbrstrm {
    int16_t	grp_no;
    int16_t	mem_no;
    struct{
	int32_t	no;
	int16_t	flag;
    }m_code[5];
} ODBRSTRM;
#endif

/* cnc_rdproctime:read processing time stamp data */
typedef struct odbptime {
	int16_t	num;
	struct{
		int32_t	prg_no;
		int16_t	hour;
		char	minute;
		char	second;
	}data[10];
} ODBPTIME;

typedef struct odbptime3 {
	int16_t	hour;
	int16_t	min;
	int16_t	sec;
	int16_t	dummy;
} ODBPTIME3;

/* cnc_rdprgdirtime:read program directory for processing time data */
typedef struct prgdirtm {
	int32_t	prg_no;
	char	comment[51];
	char	cuttime[13];
} PRGDIRTM;

/* cnc_rdprogdir2:read program directory 2 */
typedef struct prgdir2 {
	int16_t	number ;
	int32_t	length ;
	char	comment[51] ;
	char	dummy ;
} PRGDIR2;

/* cnc_rdprogdir3:read program directory 3 */
typedef struct prgdir3 {
	int32_t	number ;
	int32_t	length ;
	int32_t	page ;
	char	comment[52] ;
	struct{
		int16_t	year;
		int16_t	month;
		int16_t	day;
		int16_t	hour;
		int16_t	minute;
		int16_t	dummy;
	} mdate;
	struct{
		int16_t	year;
		int16_t	month;
		int16_t	day;
		int16_t	hour;
		int16_t	minute;
		int16_t	dummy;
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
	uint32_T  StatPstv ;
	uint32_T  StatNgtv ;
	uint32_T  Statmask ;
	uint32_T  AlarmStat ;
	uint32_T  PsclHaddr ;
	uint32_T  PsclLaddr ;
	uint16_T SvcMode1 ;
	uint16_T SvcMode2 ;
	int32_t           FileTout ;
	int32_t           RemTout ;
} IODBCPRM ;

/* cnc_rdintchk:read interference check */
/* cnc_wrintchk:write interference check */
typedef	struct  iodbint {
	int16_t   datano_s;	/* start offset No. */
	int16_t   type;		/* kind of position */
	int16_t   datano_e;	/* end offset No. */
	int32_t	data[24];	/* position value of area for not attach */
} IODBINT ;

/* cnc_rdwkcdshft:read work coordinate shift */
/* cnc_wrwkcdshft:write work coordinate shift */
/* cnc_rdwkcdsfms:read work coordinate shift measure */
/* cnc_wrwkcdsfms:write work coordinate shift measure */
typedef struct iodbwcsf {
     int16_t	datano;         /* datano			*/
     int16_t	type;           /* axis number			*/
     int32_t	data[MAX_AXIS]; /* data				*/
} IODBWCSF;

/* cnc_rdomhisinfo:read operator message history information */
typedef struct odbomif {
	uint16_T	om_max ;   /* maximum operator message history */
	uint16_T	om_sum ;   /* actually operator message history */
	uint16_T	om_char ;  /* maximum character (include NULL) */
} ODBOMIF ;

/* cnc_rdomhistry:read operator message history */
typedef struct odbomhis {
	int16_t	om_no;	/* operator message number */
	int16_t	year;	/* year */
	int16_t	month;	/* month */
	int16_t	day;	/* day */
	int16_t	hour;	/* hour */
	int16_t	minute;	/* mimute */
	int16_t	second;	/* second */
	char	om_msg[256];	/* operator message */
} ODBOMHIS ;

/* cnc_rdbtofsr:read b-axis tool offset value(area specified) */
/* cnc_wrbtofsr:write b-axis tool offset value(area specified) */
typedef	struct	iodbbto {
	int16_t datano_s;		/* start offset number */
	int16_t type;		/* offset type */
	int16_t datano_e;		/* end offset number */
	int32_t  ofs[18];		/* offset */
} IODBBTO ;	/* In case that the number of data is 9 (B type) */

/* cnc_rdbtofsinfo:read b-axis tool offset information */
typedef	struct  odbbtlinf {
	int16_t	ofs_type;	/* memory type */
	int16_t	use_no;		/* sum of b-axis offset */
	int16_t	sub_no;		/* sub function number of offset cancel */
} ODBBTLINF ;

/* cnc_rdbaxis:read b-axis command */
typedef struct odbbaxis {
	int16_t		flag ;        /* b-axis command exist or not */
	int16_t		command ;     /* b-axis command */
	uint16_T	speed ;       /* b-axis speed */
	int32_t		sub_data ;    /* b-axis sub data */
} ODBBAXIS ;

/* cnc_rdsyssoft:read CNC system soft series and version */
typedef struct odbsyss {
     char    slot_no_p[16];
     char    slot_no_l[16];
     int16_t   module_id[16];
     int16_t   soft_id[16];
     char    soft_series[16][5];
     char    soft_version[16][5];
     int16_t   soft_inst;
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
     int16_t   module_id[16];
     int16_t   soft_id[16];
     char    soft_series[16][5];
     char    soft_version[16][5];
     int16_t   soft_inst;
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
     int16_t   soft_id;
     char    soft_series[5];
     char    soft_edition[5];
} ODBSYSS3 ;

typedef struct odbsyss3_str {
    int16_t   soft_id ;
    char    soft_name[13];
    char    soft_series[5] ;
    char    soft_edition[5] ;
    char    dummy[3] ;
} ODBSYSS3_STR ;

typedef struct odbsysh_str {
    int16_t   group_id ;
    char    group_name[14] ;
    int16_t   hard_id ;
    char    hard_name[13] ;
    char    id1[11] ;
    char    id2[9] ;
    char    slot_no[3];
    char    dummy[2] ;
} ODBSYSH_STR ;

typedef struct odbsysh {
     uint32_T id1 ;
     uint32_T id2 ;
     int16_t  group_id ;
     int16_t  hard_id ;
     int16_t  hard_num ;
     int16_t  slot_no ;
     int16_t  id1_format ;
     int16_t  id2_format ;
} ODBSYSH ;

/* cnc_rdmdlconfig:read CNC module configuration information */
typedef struct odbmdlc {
     int16_t   from;
     int16_t   dram;
     int16_t   sram;
     int16_t   pmc;
     int16_t   crtc;
     int16_t   servo12;
     int16_t   servo34;
     int16_t   servo56;
     int16_t   servo78;
     int16_t   sic;
     int16_t   pos_lsi;
     int16_t   hi_aio;
     int16_t   reserve[12];
     int16_t   drmmrc;
     int16_t   drmarc;
     int16_t   pmcmrc;
     int16_t   dmaarc;
     int16_t   iopt;
     int16_t   hdiio;
     int16_t   gm2gr1;
     int16_t   crtgr2;
     int16_t   gm1gr2;
     int16_t   gm2gr2;
     int16_t   cmmrb;
     int16_t   sv5axs;
     int16_t   sv7axs;
     int16_t   sicaxs;
     int16_t   posaxs;
     int16_t   hamaxs;
     int16_t   romr64;
     int16_t   srmr64;
     int16_t   dr1r64;
     int16_t   dr2r64;
     int16_t   iopio2;
     int16_t   hdiio2;
     int16_t   cmmrb2;
     int16_t   romfap;
     int16_t   srmfap;
     int16_t   drmfap;
     int16_t   drmare;
     int16_t   pmcmre;
     int16_t   dmaare;
     int16_t   frmbgg;
     int16_t   drmbgg;
     int16_t   asrbgg;
     int16_t   edtpsc;
     int16_t   slcpsc;
     int16_t   reserve2[34];
} ODBMDLC ;

/* cnc_rdpscdproc:read processing condition file (processing data) */
/* cnc_wrpscdproc:write processing condition file (processing data) */
typedef struct iodbpscd {
	int16_t   slct;
	int32_t    feed;
	int16_t   power;
	int16_t   freq;
	int16_t   duty;
	int16_t   g_press;
	int16_t   g_kind;
	int16_t   g_ready_t;
	int16_t   displace;
	int32_t    supple;
	int16_t   edge_slt;
	int16_t   appr_slt;
	int16_t   pwr_ctrl;
    int32_t    displace2;
    char    gap_axis;
    char    feed_dec ;
    char    supple_dec ;
    char    dsp2_dec;
} IODBPSCD ;

/* cnc_rdpscdproc2:read processing condition file (processing data) */
/* cnc_wrpscdproc2:write processing condition file (processing data) */
typedef struct iodbpscd2 {
    int32_t    slct ;
    int32_t    feed ;
    int16_t   power ;
    int16_t   freq ;
    int16_t   duty ;
    int16_t   g_press ;
    int16_t   g_kind ;
    int16_t   g_ready_t ;
    int16_t   displace ;
    int32_t    supple ;
    int16_t   edge_slt ;
    int16_t   appr_slt ;
    int16_t   pwr_ctrl ;
    int32_t    displace2 ;
    char    gap_axis ;
    char    feed_dec ;
    char    supple_dec ;
    char    dsp2_dec ;
    int16_t   pb_power ;
    int16_t   reserve[8] ;
} IODBPSCD2 ;

/* cnc_rdpscdpirc:read processing condition file (piercing data) */
/* cnc_wrpscdpirc:write processing condition file (piercing data) */
typedef struct iodbpirc {
	int16_t   slct;
	int16_t   power;
	int16_t   freq;
	int16_t   duty;
	int16_t   i_freq;
	int16_t   i_duty;
	int16_t   step_t;
	int16_t   step_sum;
	int32_t    pier_t;
	int16_t   g_press;
	int16_t   g_kind;
	int16_t   g_time;
	int16_t   def_pos;
    int32_t    def_pos2;
    char    gap_axis;
    char    def_pos2_dec;
    int16_t   pb_power;
} IODBPIRC ;

/* cnc_rdpscdedge:read processing condition file (edging data) */
/* cnc_wrpscdedge:write processing condition file (edging data) */
typedef struct iodbedge {
	int16_t   slct;
	int16_t   angle;
	int16_t   power;
	int16_t   freq;
	int16_t   duty;
	int32_t    pier_t;
	int16_t   g_press;
	int16_t   g_kind;
	int32_t    r_len;
	int16_t   r_feed;
	int16_t   r_freq;
	int16_t   r_duty;
	int16_t   gap;
	int16_t   reserve[4];
} IODBEDGE ;

/* cnc_rdpscdslop:read processing condition file (slope data) */
/* cnc_wrpscdslop:write processing condition file (slope data) */
typedef struct iodbslop {
	int32_t    slct;
	int32_t    upleng;
	int16_t   upsp[10];
	int32_t    dwleng;
	int16_t   dwsp[10];
    char    upleng_dec;
    char    dwleng_dec;
	int16_t   reserve[9];
} IODBSLOP ;

/* cnc_rdlpwrdty:read power controll duty data */
/* cnc_wrlpwrdty:write power controll duty data */
typedef struct iodblpwdt {
	int16_t   slct;
	int16_t   dty_const;
	int16_t   dty_min;
	int16_t   reserve[6];
} IODBLPWDT ;

/* cnc_rdlpwrdat:read laser power data */
typedef struct odblopdt {
	int16_t   slct;
	int16_t   pwr_mon;
	int16_t   pwr_ofs;
	int16_t   pwr_act;
	int32_t    feed_act;
	char    feed_dec;
	char    reserve;
	int16_t   reserves[3];
} ODBLOPDT ;

/* cnc_rdlagslt:read laser assist gas selection */
/* cnc_wrlagslt:write laser assist gas selection */
typedef struct iodblagsl {
	int16_t   slct;
	int16_t   ag_slt;
	int16_t   agflow_slt;
    int16_t   ag_press;
    int16_t   ag_ready_t;
    int16_t   reserve[4];
} IODBLAGSL ;

/* cnc_rdlagst:read laser assist gas flow */
/* cnc_wrlagst:write laser assist gas flow */
typedef struct iodblagst {
	struct {
		int16_t   slct;
		int16_t   pre_time;
		int16_t   pre_press;
		int16_t   proc_press;
		int16_t   end_time;
		int16_t   end_press;
		int16_t   reserve[3];
	} gasflow[3] ;
} IODBLAGST ;

/* cnc_rdledgprc:read laser power for edge processing */
/* cnc_wrledgprc:write laser power for edge processing */
typedef struct iodblegpr {
	int16_t   slct;
	int16_t   power;
	int16_t   freq;
	int16_t   duty;
	int16_t   reserve[5];
} IODBLEGPR ;

/* cnc_rdlprcprc:read laser power for piercing */
/* cnc_wrlprcprc:write laser power for piercing */
typedef struct iodblpcpr {
	int16_t   slct;
	int16_t   power;
	int16_t   freq;
	int16_t   duty;
	int32_t    time;
	int16_t   reserve[4];
} IODBLPCPR ;

/* cnc_rdlcmddat:read laser command data */
typedef struct iodblcmdt {
	int16_t   slct;
	int32_t    feed;
	int16_t   power;
	int16_t   freq;
	int16_t   duty;
	int16_t   g_kind;
	int16_t   g_ready_t;
	int16_t   g_press;
	int16_t   error;
	int32_t    dsplc;
	int32_t    error2;
    char    gap_axis;
    char    feed_dec;
    char    dsplc_dec;
    char    error2_dec;
    int16_t   pb_power ;
	int16_t   reserve[2];
} ODBLCMDT ;

/* cnc_rdlactnum:read active number */
typedef struct odblactn {
	int16_t   slct;
	int16_t   act_proc;
	int16_t   act_pirce;
	int16_t   act_slop;
	int16_t   reserve[5];
} ODBLACTN ;

/* cnc_rdlcmmt:read laser comment */
typedef struct odblcmmt {
	char    comment[25];
} ODBLCMMT ;

/* cnc_rdpwofsthis:read power correction factor history data */
typedef struct odbpwofst {
        int32_t             pwratio;
        int32_t             rfvolt;
        uint16_T   year;
        uint16_T   month;
        uint16_T   day;
        uint16_T   hour;
        uint16_T   minute;
        uint16_T   second;
} ODBPWOFST;

/* cnc_rdmngtime:read management time */
/* cnc_wrmngtime:write management time */
typedef struct iodbmngtime {
        uint32_T    life;
        uint32_T    total;
} IODBMNGTIME;

/* cnc_rddischarge:read data related to electrical discharge at power correction ends */
typedef struct odbdischrg {
        uint16_T   aps;
        uint16_T   year;
        uint16_T   month;
        uint16_T   day;
        uint16_T   hour;
        uint16_T   minute;
        uint16_T   second;
        int16_t            hpc;
        int16_t            hfq;
        int16_t            hdt;
        int16_t            hpa;
        int32_t             hce;
        int32_t             rfi[8];
        int32_t             rfv[8];
        int32_t             dci[8];
        int32_t             dcv[8];
        int32_t             dcw[8];
} ODBDISCHRG;

/* cnc_rddischrgalm:read alarm history data related to electrical discharg */
typedef struct odbdischrgalm {
        uint16_T   year;
        uint16_T   month;
        uint16_T   day;
        uint16_T   hour;
        uint16_T   minute;
        uint16_T   second;
        int32_t             almnum;
        uint32_T    psec;
        int16_t            hpc;
        int16_t            hfq;
        int16_t            hdt;
        int16_t            hpa;
        int32_t             hce;
        uint16_T   asq;
        uint16_T   psu;
        uint16_T   aps;
        int16_t            dummy;
        int32_t             rfi[8];
        int32_t             rfv[8];
        int32_t             dci[8];
        int32_t             dcv[8];
        int32_t             dcw[8];
        int16_t            almcd[8];
} ODBDISCHRGALM;

/* cnc_rdlppfbdt:read power feedback data */
/* cnc_wrlppfbdt:write power feedback data */
typedef struct idblppfbfg {
        int16_t   s_no;
        int16_t   slct;
        int16_t   s_freq;
        int16_t   e_freq;
        int16_t   s_duty;
        int16_t   e_duty;
} IDBLPPFBFG ;

typedef struct iodblppfbdt {
	int16_t   ppower;
        int16_t   dummy;
        int16_t   freq[10];
        int16_t   duty[10];
        int16_t   rpower[10][10];
} IODBLPPFBDT ;

/* cnc_gettimer:get date and time from cnc */
/* cnc_settimer:set date and time for cnc */
typedef struct iodbtimer {
	int16_t	type ;
	int16_t	dummy ;
	union {
		struct {
			int16_t	year ;
			int16_t	month ;
			int16_t	date ;
		} date ;
		struct {
			int16_t	hour ;
			int16_t	minute ;
			int16_t	second ;
		} time ;
	} data ;
} IODBTIMER ;

/* cnc_rdtimer:read timer data from cnc */
/* cnc_wrtimer:write timer data for cnc */
typedef struct iodbtime {
	int32_t	minute ;
	int32_t	msec ;
} IODBTIME ;

/* cnc_rdtlctldata: read tool controll data */
/* cnc_wrtlctldata: write tool controll data */
typedef struct iodbtlctl {
	int16_t	slct;
	int16_t	used_tool;
	int16_t	turret_indx;
	int32_t	zero_tl_no;
	int32_t	t_axis_move;
	int32_t	total_punch[2];
    char    t_axis_dec;
    char    reserve;
    int16_t   reserves[10];
} IODBTLCTL ;

/* cnc_rdtooldata: read tool data */
/* cnc_wrtooldata: read tool data */
typedef struct iodbtldt {
	int16_t	slct;
	int32_t	tool_no;
	int32_t	x_axis_ofs;
	int32_t	y_axis_ofs;
	int32_t	turret_pos;
	int32_t	chg_tl_no;
	int32_t	punch_count;
	int32_t	tool_life;
	int32_t	m_tl_radius;
	int32_t	m_tl_angle;
	char	tl_shape;
	int32_t	tl_size_i;
	int32_t	tl_size_j;
	int32_t	tl_angle;
    char    x_axis_dec;
    char    y_axis_dec;
    char    turret_dec;
    char    m_radius_dec;
    char    m_angle_dec;
    char    tl_size_i_dec;
    char    tl_size_j_dec;
    char    tl_angle_dec;
    int16_t   reserve[2];
} IODBTLDT ;

/* cnc_rdmultitldt: read multi tool data */
/* cnc_wrmultitldt: write multi tool data */
typedef struct iodbmlttl {
	int16_t	slct;
	int16_t	m_tl_no;
	int32_t	m_tl_radius;
	int32_t	m_tl_angle;
	int32_t	x_axis_ofs;
	int32_t	y_axis_ofs;
	char	tl_shape;
	int32_t	tl_size_i;
	int32_t	tl_size_j;
	int32_t	tl_angle;
    char    m_radius_dec;
    char    m_angle_dec;
    char    x_axis_dec;
    char    y_axis_dec; 
    char    tl_size_i_dec;
    char    tl_size_j_dec;
    char    tl_angle_dec; 
    char    reserve; 
    int32_t    reserves[5];
} IODBMLTTL ;

/* cnc_rdmtapdata: read multi tap data */
/* cnc_wrmtapdata: write multi tap data */
typedef struct iodbmtap {
	int16_t	slct;
	int32_t	tool_no;
	int32_t	x_axis_ofs;
	int32_t	y_axis_ofs;
	int32_t	punch_count;
	int32_t	tool_life;
	int32_t	reserve[11];
} IODBMTAP ;

/* cnc_rdtoolinfo: read tool information */
typedef struct odbptlinf {
	int16_t	tld_max;
	int16_t	mlt_max;
	int16_t	reserve;
	int16_t	tld_size[16];
	int16_t	mlt_size[16];
	int16_t	reserves[16];
} ODBPTLINF ;

/* cnc_rdsafetyzone: read safetyzone data */
/* cnc_wrsafetyzone: write safetyzone data */
typedef struct iodbsafe {
	int16_t	slct;
	int32_t	data[3];
} IODBSAFE ;

/* cnc_rdtoolzone: read toolzone data */
/* cnc_wrtoolzone: write toolzone data */
typedef struct iodbtlzn {
	int16_t	slct;
	int32_t	data[2];
} IODBTLZN ;

/* cnc_rdacttlzone: read active toolzone data */
typedef struct odbacttlzn {
	int16_t	act_no;
	int32_t	data[2];
} ODBACTTLZN ;

/* cnc_rdbrstrinfo:read block restart information */
typedef struct odbbrs {
    int32_t dest[MAX_AXIS];
    int32_t dist[MAX_AXIS];
} ODBBRS ;		/*  In case that the number of axes is 10 */

/* cnc_rdradofs:read tool radius offset for position data */
typedef struct odbrofs {
    int16_t mode;
    int16_t pln_axes[2];
    int32_t ofsvct[2];
} ODBROFS ;

/* cnc_rdlenofs:read tool length offset for position data */
typedef struct odblofs {
    int16_t mode;
    int32_t ofsvct[MAX_AXIS];
} ODBLOFS ;		/*  In case that the number of axes is 10 */

/* cnc_rdfixcycle:read fixed cycle for position data */
typedef struct odbfix {
    int16_t mode;
    int16_t pln_axes[2];
    int16_t drl_axes;
    int32_t i_pos;
    int32_t r_pos;
    int32_t z_pos;
    int32_t cmd_cnt;
    int32_t act_cnt;
    int32_t cut;
    int32_t shift[2];
} ODBFIX ;

/* cnc_rdcdrotate:read coordinate rotate for position data */
typedef struct odbrot {
    int16_t mode;
    int16_t pln_axes[2];
    int32_t center[2];
    int32_t angle;
} ODBROT ;

/* cnc_rd3dcdcnv:read 3D coordinate convert for position data */
typedef struct odb3dcd {
    int16_t mode;
    int16_t dno;
    int16_t cd_axes[3];
    int32_t center[2][3];
    int32_t direct[2][3];
    int32_t angle[2];
} ODB3DCD ;

/* cnc_rdmirimage:read programable mirror image for position data */
typedef struct odbmir {
    int16_t mode;
    int32_t mir_flag;
    int32_t mir_pos[MAX_AXIS];
} ODBMIR ;		/*  In case that the number of axes is 10 */

/* cnc_rdscaling:read scaling data for position data */
typedef struct odbscl {
    int16_t mode;
    int32_t center[MAX_AXIS];
    int32_t magnif[MAX_AXIS];
} ODBSCL ;		/*  In case that the number of axes is 10 */

/* cnc_rd3dtofs:read 3D tool offset for position data */
typedef struct odb3dto {
    int16_t mode;
    int16_t ofs_axes[3];
    int32_t ofsvct[3];
} ODB3DTO ;

/* cnc_rdposofs:read tool position offset for position data */
typedef struct odbpofs {
    int16_t mode;
    int32_t ofsvct[MAX_AXIS];
} ODBPOFS ;		/*  In case that the number of axes is 10 */

/* cnc_rdhpccset:read hpcc setting data */
/* cnc_wrhpccset:write hpcc setting data */
typedef struct iodbhpst {
    int16_t       slct ;
    int16_t       hpcc ;
    int16_t       multi ;
    int16_t       ovr1 ;
    int16_t       ign_f ;
    int16_t       foward ;
    int32_t        max_f ;
    int16_t       ovr2 ;
    int16_t       ovr3 ;
    int16_t       ovr4 ;
    int32_t        reserve[7] ;
} IODBHPST ;

/* cnc_rdhpcctupr:read hpcc tuning data ( parameter input ) */
/* cnc_wrhpcctupr:write hpcc tuning data ( parameter input ) */
typedef struct iodbhppr {
    struct {
        int16_t   slct ;
        int16_t   diff ;
        int16_t   fine ;
        int16_t   acc_lv ;
        int32_t    max_f ;
        int16_t   bipl ;
        int16_t   aipl ;
        int32_t    corner ;
        int16_t   clamp ;
        int32_t    radius ;
        int32_t    max_cf ;
        int32_t    min_cf ;
        int32_t    foward ;
        int32_t    reserve[5] ;
    }tune[3] ;
} IODBHPPR ;

/* cnc_rdhpcctuac:read hpcc tuning data ( acc input ) */
/* cnc_wrhpcctuac:write hpcc tuning data ( acc input ) */
typedef struct iodbhpac {
    struct {
        int16_t   slct ;
        int16_t   diff ;
        int16_t   fine ;
        int16_t   acc_lv ;
        int32_t    bipl ;
        int16_t   aipl ;
        int32_t    corner ;
        int32_t    clamp ;
        int32_t    c_acc ;
        int32_t    foward ;
        int32_t    reserve[8] ;
    }tune[3] ;
} IODBHPAC ;

/* cnc_rd3dtooltip:read tip of tool for 3D handle */
/* cnc_rd3dmovrlap:read move overrlap of tool for 3D handle */
typedef struct odb3dhdl {
	int16_t	axes[5] ;
	int32_t	data[5] ;
} ODB3DHDL ;

/* cnc_rd3dpulse:read pulse for 3D handle */
typedef struct odb3dpls {
	int32_t	right_angle_x ;
	int32_t	right_angle_y ;
	int32_t	tool_axis     ;
	int32_t	tool_tip_a_b  ;
	int32_t	tool_tip_c    ;
} ODB3DPLS ;

/* cnc_rd5dtooltip:read tip of 5 axis manufacture send handle */
/* cnc_rd5dtoolmac:read machine axis of 5 axis manufacture send handle */
typedef struct odb5dhdl {
	char	name[4];
	int32_t	data   ;
	int16_t	dec    ;
	int16_t	flag   ;
	int16_t	axis   ;
} ODB5DHDL ;

/* cnc_rd5dpulse:read pulse of 5 axis manufacture send handle */
typedef struct odb5dpls {
	char	name[3];
	int32_t	data   ;
	int16_t	dec    ;
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
    int16_t path;          /* path number */
    int16_t rel_axis;      /* axis number */
} ODBRELAXIS ;

/* cnc_wrunsolicprm: Set the unsolicited message parameters */
/* cnc_rdunsolicprm: Get the unsolicited message parameters */
typedef struct iodbunsolic {
    char            ipaddr[16] ;
    uint16_T  port ;
    int16_t           reqaddr ;
    int16_t           pmcno ;
    int16_t           retry ;
    int16_t           timeout ;
    int16_t           alivetime;
    int16_t           setno ;
    union {
        struct {
            int16_t   type ;
            int16_t   rdaddr ;
            int16_t   rdno ;
            int16_t   rdsize ;
        } pmc ;
        struct {
            int16_t   type ;
            int32_t    dummy1 ;
            int16_t   dummy2 ;
        } dmy ;
    } rddata[3] ;
} IODBUNSOLIC ;

/* cnc_wrunsolicprm2: Set the unsolicited message parameters(2) */
/* cnc_rdunsolicprm2: Get the unsolicited message parameters(2) */
typedef struct unsolicmsg_type_prm {
    uint16_T      type;
    char                dummy1[2];
    union {
        struct {
            uint16_T  path;
            int16_t           addr;
            uint32_T   no;
            uint32_T   size;
        } pmc;
        struct {
            uint16_T  path;
            char            dummy2[2];
            uint32_T   no; 
            uint32_T   num;
        } macro;
    } prm;
} UNSOLICMSG_TYPE_PRM;

typedef struct iodbunsolic2 {
    char                ipaddr[64];
    uint32_T       port;
    uint16_T      retry;
    uint16_T      timeout;
    uint16_T      alivetime;
    char                dummy1[8];
    UNSOLICMSG_TYPE_PRM cntrl;
    uint16_T      transnum;
    char                dummy2[14];
    UNSOLICMSG_TYPE_PRM trans[3];
} IODBUNSOLIC2;

/* cnc_rdunsolicmsg: Reads the unsolicited message data */
typedef struct idbunsolicmsg {
    int16_t   getno ;
    struct {
        int16_t   rdsize ;
        void    *data ;
    } msg[3] ;
} IDBUNSOLICMSG ;

/* cnc_rdunsolicmsg2: Reads the unsolicited message data(2) */
typedef struct unsolicmsg_type_msg {
    uint16_T      type;
    char                dummy1[2];
    union {
        struct {
            uint16_T  path;
            char            dummy2[2];
            uint32_T   size;
            void            *data;
        } pmc;
        struct {
            uint16_T  path;
            char            dummy3[2];
            uint32_T   num;
            void            *data;
        } macro;
    } msg;
} UNSOLICMSG_TYPE_MSG ;

typedef struct idbunsolicmsg2 {
    uint16_T      getnum;
    char                dummy[2];
    UNSOLICMSG_TYPE_MSG get[3];
} IDBUNSOLICMSG2 ;

/* cnc_wrtrqlimit: Set torque limit data */
typedef struct idbtrq {
    int16_t   datano;         /* dummy */
    int16_t   type;           /* axis number */
    uint16_T data[MAX_AXIS]; /* torque limit data */
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
	uint16_T	TcpPort;
	uint16_T	UdpPort;
	uint16_T	UdpInterval;
} FWLIBPRMW;

typedef struct flinkprmw {
	char			IPAddress[16];
	uint16_T	Port;
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
    int32_t   type;        /* life count type */
    int32_t   total;       /* total life time (minite basis) */
    int32_t   remain;      /* life rest time */
    int32_t   stat;        /* life state */
} IODBPMAINTE ;

/* cnc_rdofslength:read tool length offset data */
typedef struct odbofslen {
     int32_t    len;    /* tool length offset */
     int32_t    dec;    /* decimal point */
} ODBOFSLEN ;

/* cnc_sysinfo_ex:read CNC system path information */
typedef struct odbsysex {
    int16_t max_axis;       /* maximum axis number */
    int16_t max_spdl;       /*  */
    int16_t max_path;       /*  */
    int16_t max_mchn;       /*  */
    int16_t ctrl_axis;      /*  */
    int16_t ctrl_srvo;      /*  */
    int16_t ctrl_spdl;      /*  */
    int16_t ctrl_path;      /*  */
    int16_t ctrl_mchn;      /*  */
    int16_t addinfo ;       /* additional information	*/
    int16_t reserved[2];    /* reserve		 		*/
    struct {
        int16_t system;     /* M/T/TT <ascii char> */
        int16_t group;      /*  */
        int16_t attrib;     /*  */
        int16_t ctrl_axis;  /*  */
        int16_t ctrl_srvo;  /*  */
        int16_t ctrl_spdl;  /*  */
        int16_t mchn_no;    /*  */
        int16_t reserved;
    } path[MAX_CNCPATH] ;
} ODBSYSEX ;

/* cnc_rdwseterror:read Work-piece setting error data */
/* cnc_wrwseterror:write Work-piece setting error data */
typedef struct wseterror {
     int32_t      data;      /*  */
     int16_t     dec;       /*  */
	 int16_t	   dummy;
} REALWSET ;

typedef struct iodbwseterror {
	int32_t	d_no;			/* active group number */
	int32_t	data_act[6];	/* active data */
	int32_t	dp_act[6];		/* decimal point for active data */
	int32_t	dsp_ix[2];		/* axisnumber for axisname */
	REALWSET  data[WSETER_GRP][WSETER_DATA];
} IODBWSETERROR ;

/* cnc_rdlrntrnsdata:read Transfer Data */
typedef struct odbtrns {
		int16_t	status ;				/* transfer status */
		int16_t	pct ;					/* transfer ratio (%) */
		int16_t	type ;					/* transfer type */
		char	dummy[2] ;
} ODBTRNS;

/* cnc_rdlrninfo:read Parts Learning Data */
typedef struct odblrninfo {
	char	name[33] ;			/* program name */
	char	dummy1[3] ;
	char	axis[4][4] ;		/* No.1-No.4 Learning axis name */
	int16_t	year ;				/* update(year) */
	int16_t	month ; 			/* update(month) */
	int16_t	day ;				/* update(day) */
	int16_t	hour ;				/* update(hour) */
	int16_t	minute ;			/* update(minute) */
	int16_t	second ;			/* update(second) */
	char	comment[33] ;		/* comment */
	char	dummy2[3] ;
} ODBLRNINFO;

/* cnc_rdlrninfo2:read Parts Learning Data */
typedef struct odblrninfo2 {
	char	name[33] ;			/* program name */
	char	dummy1[3] ;
	char	axis[20][4] ;		/* No.1-No.20 Learning axis name */
	int16_t	year ;				/* update(year) */
	int16_t	month ; 			/* update(month) */
	int16_t	day ;				/* update(day) */
	int16_t	hour ;				/* update(hour) */
	int16_t	minute ;			/* update(minute) */
	int16_t	second ;			/* update(second) */
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
	uint32_T key[2];	/* key info */
} ODBKEYINFO;

/* cnc_3dchkdata:Reads 3D interference chaeck data */
typedef struct prginf {
    uint32_T prgid[4];
} PRGINF;

typedef struct toolinf {
    int32_t  tcode;
    int32_t  magazin;
    int32_t  pot;
} TOOLINF;

typedef struct posinf {
    struct {
        int16_t prec_pntr;
        int16_t prec_time;
        int32_t  data[MAX_POS_BUF];
        int16_t dec;
        int16_t unit;
    } pos;
    struct {
        int32_t  data;
        int16_t dec;
        int16_t unit;
    } feed;
} POSINF;

typedef struct odb3dchk {
    int32_t  pathno;
    struct {
        int32_t    mode;
        PRGINF  prginf;
        int32_t    dummy[2];
        int32_t    mcode[2];
        TOOLINF tlinf;
        int32_t    dummy2[3];
        int32_t    ctrlaxis;
        POSINF  data[MAX_AXIS];
    } path[MAX_CNCPATH] ;
} ODB3DCHK;

typedef struct odb3dmtbinfo {
    PRGINF  prginf;
    int32_t    mcode[3];
    int32_t    bcode;
    TOOLINF tlinf;
    int32_t    hisorder;
    int32_t    dummy[3];
} ODB3DMTBINFO;

typedef struct odb3dmtbinfo2 {
    uint32_T    path;
    PRGINF           prginf;
    int32_t             mcode[3];
    int32_t             bcode;
    TOOLINF          tlinf;
    int32_t             dummy[4];
} ODB3DMTBINFO2;

/* cnc_3dchk_mchn_stop: Stop machine for 3D interference check */
typedef struct idb3dmstop {
    struct {
        uint32_T   plus;
        uint32_T   minus;
    } path[MAX_CNCPATH] ;
} IDB3DMSTOP;


/* cnc_read_cexeinfo */
typedef struct cexeinfo {
    int32_t    cond;           /*      condition       */
    int32_t    cycle;          /*    cycle of start    */
    int32_t    count;          /*    number of start   */
    int32_t    time;           /*    execution time    */
    int32_t    dummy1;         /*        dummy1        */
    int32_t    dummy2;         /*        dummy2        */
    int32_t    dummy3;         /*        dummy3        */
    int32_t    dummy4;         /*        dummy4        */
} CEXEINFO ;

/* cnc_cannedcycle:read canned command data */
typedef struct cmnddata {
    double  val;         /* Command value */
    int32_t    dec;         /* Decimal point */
    int32_t    dummy;       /* dummy */
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
    int32_t alm_no;
    int16_t type;
    int16_t axis;
    int16_t path;
    int16_t reserved;
} IODBMDGINFO;

/* cnc_mdg_rdmsg */
typedef struct odbmdgmsg {
    int32_t alm_no;
    int16_t msgidx;
    int16_t reserved;
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
    int16_t msgidx;
    int16_t yesidx;
    int16_t noidx;
    int16_t reserved;
    char message[400];
    int16_t detail;
    int16_t operate;
} ODBMDGFLOW;

/* cnc_mdg_rddtmsg */
typedef struct odbmdgdtmsg {
    char message[1600];
    uint32_T imgid;
} ODBMDGDTMSG;

/* cnc_mdg_rdalminfoview2 */
typedef union odbmdgval {
    int32_t lval;
    uint32_T ulval;
    int16_t sval;
    uint16_T usval;
    char cval;
    unsigned char ucval;
} ODBMDGVAL;

typedef struct odbmdgdt {
    ODBMDGVAL dt;
    int16_t fp;
    int16_t reserved;
} ODBMDGDT;

typedef struct odbsigdio {
    char sgnl1;
    char sgnl2;
    char sgnl3;
    char sgnl4;
} ODBSIGDIO;

typedef struct odbsv2_grp1 {
    int32_t cmd_pls;
    int32_t fb_pls;
    int32_t refc;
    int32_t pos_err;
    ODBMDGDT act_spd;
    uint16_T amr;
    int16_t reserved;
} ODBSV2_GRP1;

typedef struct odbsv2_grp2 {
    ODBMDGDT mt_cur;
    int16_t trq_cmd;
    int16_t efc_cur;
    uint16_T dlvl;
    uint16_T heat;
    int16_t opt;
    int16_t opt2;
} ODBSV2_GRP2;

typedef struct odbsv2_grp3 {
    ODBMDGDT ps_vumb;
    ODBMDGDT ps_vthd;
    ODBMDGDT freq;
    uint16_T ps_vrms;
    uint16_T ps_cur;
    uint16_T dvolt;
    unsigned char ps_statf;
    char reserved;
} ODBSV2_GRP3;

typedef struct odbsv2_grp4 {
    ODBMDGDT resistance;
    unsigned char detect_res;
    char reserved[7];
} ODBSV2_GRP4;

typedef struct odbsv2_grp5 {
    uint16_T ps_dgn;
    uint16_T ps_sub_dgn;
    uint16_T sv_dgn;
    unsigned char ps_int_tmp;
    unsigned char ps_sink_tmp;
    unsigned char sv_int_tmp;
    unsigned char sv_sink_tmp;
    unsigned char amp_grp;
    unsigned char amp_slv;
} ODBSV2_GRP5;

typedef struct odbsv2_grp6 {
    uint16_T sv_up_err1;
    uint16_T sv_up_err2;
    uint16_T sv_lw_err1;
    uint16_T sv_lw_err2;
    uint16_T sv_up_jt1;
    uint16_T sv_up_jt2;
    uint16_T sv_lw_jt1;
    uint16_T sv_lw_jt2;
    uint16_T sdu_up_err1;
    uint16_T sdu_up_err2;
    uint16_T sdu_lw_err1;
    uint16_T sdu_lw_err2;
    uint16_T sdu_up_jt1;
    uint16_T sdu_up_jt2;
    uint16_T sdu_lw_jt1;
    uint16_T sdu_lw_jt2;
} ODBSV2_GRP6;

typedef struct odbsv2_grp7 {
    uint16_T id_intp;
    uint16_T id_com;
    uint16_T id_wrn;
    uint16_T ed_intp;
    uint16_T ed_com;
    uint16_T ed_wrn;
    int16_t sv_dat1;
    int16_t sv_dat2;
    int16_t sv_dat3;
    int16_t sv_dat4;
} ODBSV2_GRP7;

typedef struct odbsp2_grp1 {
    int32_t motion;
    int16_t cmd_spd;
    char mode;
    char gear;
    char osel;
    char reserved[3];
    ODBSIGDIO sig_in;
    ODBSIGDIO sig_out;
} ODBSP2_GRP1;

typedef struct odbsp2_grp2 {
    int32_t pos_err;
    int32_t syn_err;
    int32_t sp_spd;
    int32_t mt_spd;
    ODBMDGDT mt_cur;
    uint16_T ldmtr;
    int16_t trq_cmd;
    char heat_mt;
    char heat_amp;
    char reserved[2];
} ODBSP2_GRP2;

typedef struct odbsp2_grp3 {
    ODBMDGDT ps_vumb;
    ODBMDGDT ps_vthd;
    ODBMDGDT freq;
    uint16_T ps_vrms;
    uint16_T ps_cur;
    uint16_T dvolt;
    unsigned char ps_statf;
    char reserved;
} ODBSP2_GRP3;

typedef struct odbsp2_grp4 {
    ODBMDGDT resistance;
    unsigned char detect_res;
    char reserved[7];
} ODBSP2_GRP4;

typedef struct odbsp2_grp5 {
    uint16_T ps_dgn;
    uint16_T ps_sub_dgn;
    uint16_T sp_dgn;
    unsigned char ps_int_tmp;
    unsigned char ps_sink_tmp;
    unsigned char sp_int_tmp;
    unsigned char sp_sink_tmp;
    unsigned char amp_grp;
    unsigned char amp_slv;
} ODBSP2_GRP5;

typedef struct odbsp2_grp6 {
    uint16_T sp_up_err1;
    uint16_T sp_up_err2;
    uint16_T sp_lw_err1;
    uint16_T sp_lw_err2;
    uint16_T sp_up_jt1;
    uint16_T sp_up_jt2;
    uint16_T sp_lw_jt1;
    uint16_T sp_lw_jt2;
} ODBSP2_GRP6;

typedef struct odbsp2_grp7 {
    ODBMDGDT iab_amplt;
    ODBMDGDT eab_amplt;
    int16_t iab_ofs_a;
    int16_t iab_ofs_b;
    int16_t iab_noise;
    int16_t eab_ofs_a;
    int16_t eab_ofs_b;
    int16_t eab_noise;
    uint16_T iab_max_flt;
    uint16_T eab_max_flt;
} ODBSP2_GRP7;

typedef struct odbsp2_grp8 {
    uint16_T isncr_intp;
    uint16_T isncr_com;
    uint16_T isncr_wrn;
    uint16_T esncr_intp;
    uint16_T esncr_com;
    uint16_T esncr_wrn;
    int16_t sp_dat1;
    int16_t sp_dat2;
    int16_t sp_dat3;
    int16_t sp_dat4;
} ODBSP2_GRP8;

typedef struct odblat_grp1 {
    uint32_T nnum;
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
    int32_t ldata[500];
    uint16_T p_dec;
    uint16_T num;
    uint16_T channel;
    uint16_T axis;
    uint16_T kind;
    uint16_T interval;
    uint16_T t_cycle;
    char unit;
    char sw_alm;
} ODBMDGWVDT;

/*-----*/
/* CNC */
/*-----*/

/* cnc_srcsrdidinfo */
/* cnc_srcswridinfo */
typedef struct iodbidinf {
	int32_t  id_no;
	int16_t drv_no;
	int16_t acc_element;
	int16_t err_general;
	int16_t err_id_no;
	int16_t err_id_name;
	int16_t err_attr;
	int16_t err_unit;
	int16_t err_min_val;
	int16_t err_max_val;
	int16_t id_name_len;
	int16_t id_name_max;
	char  id_name[60];
	int32_t  attr;
	int16_t unit_len;
	int16_t unit_max;
	char  unit[12];
	int32_t  min_val;
	int32_t  max_val;
} IODBIDINF;

/* cnc_srcsrdexstat */
typedef struct odbsrcsst {
	int16_t acc_element;
	int16_t err_general;
	int16_t err_id_no;
	int16_t err_attr;
	int16_t err_op_data;
} ODBSRCSST;

/* cnc_srcsrdlayout */
typedef struct odbsrcslyt {
	int16_t spndl[4];
	int16_t servo[8];
	char  axis_name[8];
} ODBSRCSLYT;

/*-----*/
/* CNC */
/*-----*/
/* cnc_sdsetchnl */
typedef struct idbchan {
	char            chno;
	char            axis;
	int32_t            datanum;
	uint16_T  datainf;
	int16_t           dataadr;
} IDBCHAN;

/* cnc_sdsetchnl2 */
typedef struct pmc_data {
	int16_t			unittype;
	char			adr;
	unsigned char	bit;
	uint16_T	no;
} PMC_DATA;

/* cnc_sdsetchnl2 */
typedef struct idbchan2 {
	int16_t           chno;
	int16_t           axis;
	int32_t            datanum;
	uint16_T  datainf;
	int16_t           dataadr;
	PMC_DATA		io[16];
} IDBCHAN2;

/* cnc_sdstartsmpl2 */
typedef struct trgdata {
	int32_t		seq_no;
	PMC_DATA	pmc_trg;
} TRG_DATA;

/* cnc_sdbetainfo */
typedef struct odbbinfo {
	int16_t   iochno;
	int16_t   grpno;
	int16_t   axis;
	char    name;
	char    suff;
	int16_t   reserve[3];
} ODBBINFO;

/* cnc_sdsetchnl */
typedef struct odbsd {
	uint16_T  *chadata;
	int32_t            *count;
} ODBSD;

/* cnc_sfbsetchnl */
typedef struct idbsfbchan {
        char            chno;
        char            axis;
        uint16_T  shift;
} IDBSFBCHAN;

/* cnc_sdtsetchnl */
typedef struct idbsdtchan {
		int16_t			type;
		char			chno;
		char			axis;
		uint16_T	shift;
} IDBSDTCHAN;

/* cnc_sdtsetchnl2 */
typedef struct idbsdtchan2 {
	int16_t			type;
	char			chno;
	char			axis;
	uint16_T	shift;
	PMC_DATA		io[16];
} IDBSDTCHAN2;

typedef struct idbsdttrg {
	int32_t		seq_no;
	PMC_DATA	pmc_trg;
} IDBSDTTRG;

/*----------------------------*/
/* CNC : REMOTE DIAGNOSIS I/F */
/*----------------------------*/
/* cnc_pdf_startrmtdgn: Remote Diagnosis Start */
/* cnc_pdf_rdrmtdgn: Read Remote Diagnosis Information */
typedef struct rmtdgn_info {
    uint32_T  receipt_num;	    /* Receipt Number   */
    uint32_T  time;            /* Time             */
    int16_t          status;          /* Status           */
    int16_t          err_num;         /* Error Number     */
    char           err_msg[36];     /* Error Message    */
} OUT_RMTDGNINFO;

/*-------------------------*/
/* CNC : FS18-LN function  */
/*-------------------------*/

/* cnc_allowcnd:read allowanced state */
typedef struct odbcaxis {
    int16_t   dummy ;             /* dummy */
    int16_t   type ;              /* axis number */
    unsigned char    data[MAX_AXIS] ;    /* data value */
} ODBCAXIS ;


/*-----------*/
/* Oxxxxxxxx */
/*-----------*/

/* cnc_rdprgnumo8:read program number under execution */
typedef struct odbproo8 {
     int16_t   dummy[2] ;  /* dummy */
     int32_t    data ;      /* running program number */
     int32_t    mdata ;     /* main program number */
} ODBPROO8 ;

/* cnc_rddynamico8:read all dynamic data */
typedef struct odbdyo8 {
    int16_t   dummy ;
    int16_t   axis ;       /* axis number             */
    int16_t   alarm ;      /* alarm status            */
    int32_t    prgnum ;     /* current program number  */
    int32_t    prgmnum ;    /* main program number     */
    int32_t    seqnum ;     /* current sequence number */
    int32_t    actf ;       /* actual feedrate         */
    int32_t    acts ;       /* actual spindle speed    */
    union {
        struct {
            int32_t    absolute[MAX_AXIS] ;    /* absolute position   */
            int32_t    machine[MAX_AXIS] ;     /* machine position    */
            int32_t    relative[MAX_AXIS] ;    /* relative position   */
            int32_t    distance[MAX_AXIS] ;    /* distance to go      */
        } faxis ;
        struct {
            int32_t    absolute ;  /* absolute position   */
            int32_t    machine ;   /* machine position    */
            int32_t    relative ;  /* relative position   */
            int32_t    distance ;  /* distance to go      */
        } oaxis ;   /* In case of no axis  */
    } pos ;
} ODBDYO8 ;

/* (op)cnc_rdmdipntro8:read execution pointer for MDI operation */
typedef struct odbmdipo8 {
    int32_t   mdiprog;     /* exec. program number */
    int32_t   mdipntr;     /* exec. pointer */
    int32_t   crntprog;    /* prepare program number */
    int32_t   crntpntr;    /* prepare pointer */
} ODBMDIPO8;

/* cnc_rdprogdir2o8:read program directory 2 */
typedef struct prgdir2o8 {
	int32_t	number ;
	int32_t	length ;
	char	comment[51] ;
	char	dummy ;
} PRGDIR2O8;


/*---------------------------------*/
/* CNC : C-EXE SRAM file function  */
/*---------------------------------*/

/* read C-EXE SRAM disk directory */
typedef struct cfileinfo {
	char	fname[12] ;	/* file name */
	int32_t	file_size ;	/* file size (bytes) */
	int32_t	file_attr ;	/* attribute */
	int16_t	year;		/* year */
	int16_t	month;		/* month */
	int16_t	day;		/* day */
	int16_t	hour;		/* hour */
	int16_t	minute;		/* mimute */
	int16_t	second;		/* second */
} CFILEINFO;


/*------------*/
/* CNC : FSSB */
/*------------*/

/* cnc_rdfssb_amp:read amp information */
typedef struct tagODBFSSBAMP {
	int16_t	ln_num;			/* line number */
	int16_t	slave_num;		/* slave number */
	char	name[8];		/* amp name */
	char	seires[8];		/* amp series name */
	char	unit[8];		/* amp unit type */
	char	cur[8]; 		/* amp currect */
	int16_t	axis_num;		/* axis number */
//	int16_t	reserve;		/* reserved */
	char	axis_name[4];	/* axis name */
} ODBFSSBAMP ;

/* cnc_rdfssb_plsmod:read pulse module information */
typedef struct tagODBPLSMDL {
	int16_t	ln_num;			/* line number */
	int16_t	slave_num;		/* slave number */
	char	name[8];		/* pulse module name */
	char	type[8];		/* pulse module type name */
	char	pcb_id[8];		/* pulse module hard ID */
	char	function[32];	/* pulse module function */
} ODBPLSMDL ;

/* cnc_rdfssb_axis:read axis information */
/* cnc_wrfssb_axis:write axis information */
typedef struct tagIODBFSSBAXIS {
	int16_t	axis_num;		/* axis number */
	int16_t	reserve1;		/* reserved */
	char	axis_name[4];	/* axis name */
	char	amp_name[8];	/* amp name */
	int16_t	m1;				/* M1 */
	int16_t	m2;				/* M2 */
	int16_t	m3;				/* M3 */
	int16_t	m4;				/* M4 */
	int16_t	dsp1;			/* 1-DSP */
//	int16_t	spos;			/* SPOS */
	int16_t	cs;				/* Cs */
	int16_t	tndm;			/* tandem */
//	int16_t	egb;			/* EGB */
	int16_t	reserve2;		/* reserved */
} IODBFSSBAXIS ;

/* cnc_rdfssb_mainte:read maintenance information */
typedef struct tagODBFSSBMT {
	int16_t	axis_num;		/* axis number */
	int16_t	reserve;		/* reserved */
	char	axis_name[4];	/* axis name */
	char	amp_name[8];	/* amp name */
	char	amp_seires[8];	/* amp series name */
	char	amp_unit[8];	/* amp unit type */
	char	amp_cur[8];		/* amp maximum current */
	char	amp_edt[8];		/* amp version */
	int16_t	amp_axis_num;	/* amp axis */
	int16_t	test_year;		/* amp tested year */
	int16_t	test_month;		/* amp tested month */
	int16_t	test_day;		/* amp tested date */
	int16_t	amp_mainte;		/* amp serial number */
} ODBFSSBMT ;

/* cnc_rdfssb_info:read FSSB information */
typedef struct tagODBFSSBINFO {
	int16_t	card_num;		/* axis card amount */
	struct {
		int16_t	amp_num;	/* amp amount */
		int16_t	plsm_num;	/* pulse module amount */
	} card[8];
} ODBFSSBINFO ;


/* FSSB for 30iB (IFSB) */
typedef struct tagODBIFSBLINE {
    uint16_T  hrv_ln;         /* HRV */
    uint16_T  ax_num_ln;      /* Axis Num */
    uint16_T  sp_num_ln;      /* Spindel Num */
    uint16_T  pm_num_ln;      /* Pulse Module Num */
}ODBIFSBLINE;

typedef struct tagODBIFSBINFO {
    unsigned char   fssb_line_mnt_st;   /* Mount Status */
    unsigned char   reserve;            /* Mount Status */
    uint16_T  card_num;           /* Card Num */
    ODBIFSBLINE     line_info[MAX_IFSB_LINE]; /* Line information */
}ODBIFSBINFO;

typedef struct tagODBFSSBSLVUNT {
    int16_t   slv_unt_num;    /* Slave unit number */
    char    kind;           /* Slave kind */
    char    attrb;          /* Slave attribute */
} ODBIFSBSLVUNT;

typedef struct tagODBIFSBSLUSV {
    int16_t   slave_num;      /* Slave Number */
    int16_t   axis_num;       /* Axis Number */
    char    axis_name[4];   /* Axis Name */
    char    tndm;
    char    reserve[3];
} ODBIFSBSLUSV;

typedef struct tagODBIFSBSVAMP {
    int16_t   slave_num;          /* Slave Number */
    char    name[8];            /* Amp Name */
    char    series[12];         /* Amp Series */
    char    cur[8];             /* Amp Current */
    int16_t   as_axis_num;        /* Axis number for Auto Set */
    char    as_axis_name[4];    /* Axis name for Auto Set */
} ODBIFSBSVAMP;

typedef struct tagODBIFSBSLUSP {
    int16_t   slave_num;      /* Slave Number */
    int16_t   spdl_num;       /* Spindle Number */
    char    spdl_name[4];   /* Spindle Name */
} ODBIFSBSLUSP;

typedef struct tagODBIFSBSLUPM {
    int16_t   slave_num;          /* Slave Number */
    int16_t   axis_num[8];        /* Axis Number */
    char    axis_name[8][4];    /* Axis Name */
} ODBIFSBSLUPM;

typedef struct tagODBIFSBSPAMP {
    int16_t   slave_num;          /* Slave Number */
    char    name[8];            /* Amp Name */
    char    series[12];         /* Amp Series */
    char    pwr[8];             /* Amp Power */
    int16_t   as_spdl_num;        /* Spindle number for Auto Set */
    char    as_spdl_name[4];    /* Spindle name for Auto Set */
} ODBIFSBSPAMP;

typedef struct tagODBIFSBPLSMDL {
    int16_t           slave_num;  /* Slave Number */
    char            name[8];    /* PM Name */
    char            type[8];    /* PM Type */
    uint16_T  pcb_id;     /* PM PCBID */
    char            info[24];   /* PM Information */
} ODBIFSBPLSMDL;

typedef struct tagIODBIFSBAXIS {
    int16_t   axis_num;       /* Axis Number */
    char    axis_name[4];   /* Axis Name */
    int16_t   line;
    char    amp_name[8];    /* Amp Name */
    int16_t   pm[8];          /* M1 - M8 */
    int16_t   cs;             /* Cs */
    int16_t   tndm;           /* tandem */
} IODBIFSBAXIS;

typedef struct tagODBIFSBMNTSV {
    int16_t   axis_num;           /* Axis Number */
    char    axis_name[4];       /* Axis Name */
    int16_t   line;
    char    amp_name[8];        /* Amp Name */
    char    amp_series[12];     /* Amp Series */
    char    amp_cur[8];         /* Amp Current */
    char    amp_edt[8];         /* Amp Edition */
    int16_t   amp_axis_num;       /* Amp Axis Number */
    char    amp_spec_num[23];   /* Amp Specificaion */
    char    amp_serial_num[13]; /* Amp Serial Number */
} ODBIFSBMNTSV;

typedef struct tagODBIFSBMNTSP {
    int16_t   spdl_num;           /* Spindle Number */
    char    spdl_name[4];       /* Spindle Name */
    int16_t   line;
    char    amp_name[8];        /* Amp Name */
    char    amp_series[12];     /* Amp Series */
    char    amp_pwr[8];         /* Amp Power */
    char    amp_edt[8];         /* Amp Edition */
    int16_t   amp_spdl_num;       /* Amp Axis Number */
    char    amp_spec_num[23];   /* Amp Specificaion */
    char    amp_serial_num[13]; /* Amp Serial Number */
} ODBIFSBMNTSP;

typedef struct tagODBIFSBSYSALM {
    int32_t    num_sys_alm;
    int16_t   error_line;
    int16_t   error_slvnum1;
    int16_t   error_slvnum2;
    int16_t   year;
    int16_t   mon;
    int16_t   day;
    int16_t   hour;
    int16_t   min;
    int16_t   sec;
    char    alarm_cause[100];
} ODBIFSBSYSALM;

typedef struct tagODBIFSBFSSBUNT {
    int16_t   slv_unt_num;    /* slave unit number */
    int16_t   fssb_unt_num;   /* fssb unit number */
    char    name[4];        /* name */
} ODBIFSBFSSBUNT;

typedef struct tagODBIFSBCOMSTATDTL {
    int32_t    error_inf;      /* error information */
    int32_t    jitter_inf;     /* jitter information */
    char    n_warning;      /* noise warning flag */
    char    j_warning;      /* jitter warning flag */
    char    reserve[2];     /* reserve */
} ODBIFSBCOMSTATDTL;

typedef struct tagODBIFSBWARNINGMSG {
    int16_t   line;           /* warning line number */
    int16_t   slv_src;        /* warning slave number for source*/
    int16_t   slv_dst;        /* warning slave number for destination */
    int16_t   type;           /* warning type */
    char    wm_typ[32];     /* warning message for type*/
    char    wm_pnt[32];     /* warning message for point*/
} ODBIFSBWARNINGMSG;

typedef struct tagODBIFSBWARNHSTMSG {
    int16_t   year;           /* year of occurrence of warning */
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
    int16_t   year;
    char    month;
    char    day;
    char    hour;
    char    minute;
    char    second;
    char    msu_num;
    char    path_num;
    char    pmc_num;
    uint16_T  nonsave;
    char    save_trigger;
    char    reserve[3];
} ODBMSRHSTINF ;

typedef struct tag_ODBMSUXTERM{
    char    kind;
    char    ch;
    char    atrb;
    char    dec;
    int32_t    data;
}ODBMSUXTERM;

typedef struct tag_ODBMSUYTERM{
    int16_t   data;
    int16_t   dummy;
}ODBMSUYTERM;

typedef struct tag_ODBMSUINF{
    char    pmc_no;
    char    dummy[3];
    int32_t    x_top_adrs;
    int32_t    y_top_adrs;
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
    int32_t    top_adrs;
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
    int32_t    adrs;
    char    pmc_no;
    char    kind;
    char    data;
    char    mask;
    char    enbl;
    char    dummy[3];
} ODBMSRPMCSGNL ;

typedef struct odbmsrncdat {
    int16_t       sv_num;
    int16_t       sp_num;
    ODBAXDT     mcn[32];
    ODBAXDT     abs[32];
    ODBAXDT     spdl[8];
    ODBAXDT     actf;
    char        ex_prg_name[248];
    int32_t        ex_blk;
    int16_t       aut;
    int16_t       tmmode;
    ODBCMD      m_mdl[5];
    ODBCMD      s_mdl;
    ODBCMD      t_mdl;
    ODBCMD      b_mdl;
} ODBMSRNCDAT ;

/*-----------------*/
/* CNC : EcoMode   */
/*-----------------*/
typedef struct odbpowccyc {
	uint32_T	cycletime ;
	uint32_T	powc_axis ;
	uint32_T	powc_spindle ;
	uint32_T	powc_outer ;
} ODBPOWCCYC ;

typedef struct odbpowcouter {
	uint32_T	ave_pow[8] ;
	uint16_T	ref_ofs ;
	char			ref_adrs ;
	unsigned char	ref_path ;
} ODBPOWCOUTER;

typedef struct odbpowchis {
	uint32_T	get_time ;
	uint32_T	powc_axis ;
	uint32_T	powc_spindle ;
	uint32_T	powc_outer ;
} ODBPOWCHIS ;

typedef struct odbpowchisall {
	ODBPOWCHIS		powchis[30] ;
} ODBPOWCHISALL ;

/*---------------------------------*/
/* CNC : Power Consumption Monitor */
/*---------------------------------*/
/* cnc_pwcm_rd_consump:read power consumption */
typedef struct odbpwcm {
    int32_t consump ;          /* Integral power consumption */
    int32_t regen ;            /* Integral power regeneration */
    int32_t net ;              /* Integral net amount of power consumption */
    int32_t present ;          /* Present net power consumption */
} ODBPWCM ;

typedef struct odbpwcmdat {
    uint32_T time ;           /* Integrating time of power consumption */
    int16_t   axis_num ;             /* Number of servo axis */
    int16_t   spindle_num ;          /* Number of spindle axis */
    ODBPWCM all ;                  /* Power consumption of all axes */
    ODBPWCM axis[MAX_AXIS] ;       /* Power consumption of each servo axis */
    ODBPWCM spindle[MAX_SPINDLE] ; /* Power consumption of each spindle axis */
} ODBPWCMDAT ;

/*---------------*/
/* CNC : GRAPHIC */
/*---------------*/

/* cnc_rd_grppos:read graphic position */
typedef struct posval {
	int32_t	data ;			/* Value */
	int32_t	dec ;			/* Decimal places */
} POSVAL ;

typedef struct odbgrppos {
	POSVAL	abs ;			/* Absolute position */
	POSVAL	mcn ;			/* Machine position */
	int16_t	feed_type ;		/* Feed type */
	int16_t	reserved ;		/* Padding */
} ODBGRPPOS ;

/* cnc_rdgrpaxisinfo:read graphic axis information */
typedef struct odbgrpaxis {
	int16_t	path_num ;		/* Path number */
	int16_t	draw_num ;		/* Drawing axis number */
} ODBGRPAXIS ;

typedef struct odbwact {
    int32_t    data[6] ;       /* Valule */
} ODBWACT ;

#if defined (PMD) /* only Power Mate D/H */
/*------------------------------*/
/* MAXIS: Axis Movement Control */
/*------------------------------*/
/* cnc_opdi:signal operation command */
typedef struct odbopdi {
	int16_t	axis;	/* axis number */
	union {
		char	cdata;
		int16_t	idata;
		int32_t	ldata;
	} u;
} ODBOPDI;

/* cnc_abspoint:absolute movement */
/* cnc_incpoint:incremental movement */
/* cnc_dwell:dwell */
/* cnc_coordre:coordinate establihment */
typedef struct odbpos {
	int16_t	idata;	/* axis number */
	int32_t	ldata;	/* coordinate value */
} ODBPOS;

/* cnc_refpoint:reference point return */
/* cnc_abspoint:absolute movement */
/* cnc_incpoint:incremental movement */
/* cnc_dwell:dwell */
/* cnc_coordre:coordinate establihment */
/* cnc_exebufstat:reading of the executive buffer condition */
typedef struct odbexec {
	int16_t	dummy;		/* dummy */
	char	cdata[2][8];	/* the infomation of the executive condition of */
} ODBEXEC;			/* each PATH                                    */

/* cnc_finstate:Reading of the execution completion condition */
/* cnc_setfin:Release of the reading mode of the execution completion condition */
typedef struct odbfin {
	int16_t	dummy;		/* dummy */
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
    int16_t            type_a ;    /* PMC address type */
    int16_t            type_d ;    /* PMC data type */
    uint16_T   datano_s ;  /* start PMC address */
    uint16_T   datano_e ;  /* end PMC address */
    union {
        char    cdata[5] ;  /* PMC data */
        int16_t   idata[5] ;
        int32_t    ldata[5] ;
        float   fdata[5] ;
        double  dfdata[5] ;
    } u ;
} IODBPMC ; /* In case that the number of data is 5 */
#else
typedef struct iodbpmc {
    int16_t   type_a ;    /* PMC address type */
    int16_t   type_d ;    /* PMC data type */
    int16_t   datano_s ;  /* start PMC address */
    int16_t   datano_e ;  /* end PMC address */
    union {
        char    cdata[5] ;  /* PMC data */
        int16_t   idata[5] ;
        int32_t    ldata[5] ;
        float   fdata[5] ;
        double  dfdata[5] ;
    } u ;
} IODBPMC ; /* In case that the number of data is 5 */
#endif

typedef struct  iodbrwpmc {
    int16_t           type_rw ;
    int16_t           type_a ;
    int16_t           type_d ;
    uint16_T  datano_s ;
    int16_t           length ;
    int16_t           conv ;
    int16_t           err_code ;
    int16_t           reserved;
    void            *data ;
} IODBRWPMC ;

/* pmc_rdpmcinfo:read informations of PMC data */
typedef struct odbpmcinf {
    int16_t   datano ;
    struct {
        char    pmc_adr ;
        char    adr_attr ;
        uint16_T  top_num ;
        uint16_T  last_num ;
    } info[64] ;
} ODBPMCINF ;

/* pmc_rdcntldata:read PMC parameter data table control data */
/* pmc_wrcntldata:write PMC parameter data table control data */
typedef struct iodbpmccntl {
    int16_t   datano_s ;
    int16_t   dummy ;
    int16_t   datano_e ;
    struct {
        char    tbl_prm ;
        char    data_type ;
        uint16_T  data_size ;
        uint16_T  data_dsp ;
        int16_t   dummy ;
    } info[100] ;
} IODBPMCCNTL ;

/* pmc_rdalmmsg:read PMC alarm message */
typedef struct  odbpmcalm {
    char    almmsg[128] ;    /* alarm message */
} ODBPMCALM ;

/* pmc_getdtailerr:get detail error for pmc */
typedef struct odbpmcerr {
    int16_t   err_no ;
    int16_t   err_dtno ;
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
	int16_t	type_a ;	/* PMC address type */
	int16_t	type_d ;	/* PMC data type */
	int16_t	datano_s ;	/* start PMC address */
	int16_t	datano_e ;	/* end PMC address */
	int16_t	err_code ;	/* error code */
	int16_t	reserved ;	/* reserved */
	void	*data ;		/* pointer to buffer */
} IODBPMCEXT ;

/* pmc_rdpmcaddr:read PMC address information */
typedef struct odbpmcadr {
	uint16_T pmc_adr ;	/* PMC address type */
	uint16_T adr_attr ;	/* PMC address attribute */
	uint32_T  adr ;		/* offset address from the top of the PMC address area */
	uint32_T  top ;		/* top number of the PMC address area */
	uint32_T  num ;		/* number of the PMC address area */
} ODBPMCADR ;

/* pmc_read_seq_program_and_memory_type:Reads sequence program and momory type */
typedef struct
{
   uint32_T SystemType;
   uint32_T SystemAttribute;
   uint32_T TargetType;
   uint32_T TargetAttribute;
   char          SystemTypeStr[32];
   char          TargetTypeStr[32];
} ODBPMCLADMEMTYPE;

/* pmc_convert_from_string_to_address:Convert to PMC address information from address or symbol string */
typedef struct odbpmcadrinfo
{
   int16_t sPmcUnit;      /*j PMC unittype */
   int16_t sAdrType;      /*j ID code indicating the PMC address type */
   int32_t  iAdrNum;       /*j number of PMC address */
   int16_t sBitPos;       /*j bit position of PMC address */
   int16_t sDataType;     /*j deta type of PMC address */
} ODBPMCADRINFO;

/*--------------------------*/
/* PROFIBUS function        */
/*--------------------------*/

/* pmc_prfrdcinfo:read PROFIBUS information data */
typedef struct odbprfinfo {
    uint16_T series ;
    uint16_T vers1 ;
    uint16_T vers2 ;
    uint16_T profi ;
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
    uint16_T tsl ;
    uint16_T min_tsdr ;
    uint16_T max_tsdr ;
    unsigned char  tqui ;
    unsigned char  tset ;
    int32_t           ttr ;
    char           gap ;
    char           hsa ;
    char           max_retry ;
    unsigned char  bp_flag ;
    uint16_T min_slv_int ;
    uint16_T poll_tout ;
    uint16_T data_cntl ;
    char           reserve1[6] ;
    char           cls2_name[32] ;
    int16_t          user_dlen ;
    char           user_data[62] ;
    char           reserve2[96] ;
} IODBBUSPRM ;

/* pmc_prfrdslvprm:read slave parameter for master function */
/* pmc_prfwrslvprm:write slave parameter for master function */
typedef struct iodbslvprm {
    int16_t          dis_enb ;
    uint16_T ident_no ;
    unsigned char  slv_flag ;
    unsigned char  slv_type ;
    char           reserve1[12] ;
    unsigned char  slv_stat ;
    unsigned char  wd_fact1 ;
    unsigned char  wd_fact2 ;
    unsigned char  min_tsdr ;
    char           reserve2 ;
    unsigned char  grp_ident ;
    int16_t          user_plen ;
    char           user_pdata[32] ;
    int16_t          cnfg_dlen ;
    char           cnfg_data[126] ;
    int16_t          slv_ulen ;
    char           slv_udata[30] ;
    char           reserve3[8] ;
} IODBSLVPRM ;

typedef struct iodbslvprm2 {
    int16_t          dis_enb ;
    uint16_T ident_no ;
    unsigned char  slv_flag ;
    unsigned char  slv_type ;
    char           reserve1[12] ;
    unsigned char  slv_stat ;
    unsigned char  wd_fact1 ;
    unsigned char  wd_fact2 ;
    unsigned char  min_tsdr ;
    char           reserve2 ;
    unsigned char  grp_ident ;
    int16_t          user_plen ;
    char           user_pdata[206] ;
    int16_t          cnfg_dlen ;
    char           cnfg_data[126] ;
    int16_t          slv_ulen ;
    char           slv_udata[30] ;
    char           reserve3[8] ;
} IODBSLVPRM2 ;

/* pmc_prfrdallcadr:read allocation address for master function */
/* pmc_prfwrallcadr:set allocation address for master function */
typedef struct iodbprfadr {
    char           di_size ;
    char           di_type ;
    uint16_T di_addr ;
    int16_t          reserve1;
    char           do_size ;
    char           do_type ;
    uint16_T do_addr ;
    int16_t          reserve2;
    char           dgn_size ;
    char           dgn_type ;
    uint16_T dgn_addr ;
} IODBPRFADR ;

/* pmc_prfrdslvaddr:read allocation address for slave function */
/* pmc_prfwrslvaddr:set allocation address for slave function */
typedef struct iodbslvadr {
    char           slave_no ;
    char           di_size ;
    char           di_type ;
    uint16_T di_addr ;
    char           do_size ;
    char           do_type ;
    uint16_T do_addr ;
    char           reserve[7] ;
} IODBSLVADR ;

/* pmc_prfrdslvstat:read status for slave function */
typedef struct odbslvst {
    unsigned char  cnfg_stat ;
    unsigned char  prm_stat ;
    char           wdg_stat ;
    unsigned char  live_stat ;
    int16_t          ident_no ;
} ODBSLVST ;

/* pmc_prfrdslvid:Reads slave index data of master function */
/* pmc_prfwrslvid:Writes slave index data of master function */
typedef struct {
    int16_t          dis_enb ;
    int16_t          slave_no ;
    int16_t          nsl ;
    unsigned char  dgn_size ;
    char           dgn_type ;
    uint16_T dgn_addr ;
} IODBSLVID ;

/* pmc_prfrdslvprm2:Reads slave parameter of master function(2) */
/* pmc_prfwrslvprm2:Writes slave parameter of master function(2) */
typedef struct {
    uint16_T ident_no ;
    unsigned char  slv_flag ;
    unsigned char  slv_type ;
    char           reserve1[12] ;
    unsigned char  slv_stat ;
    unsigned char  wd_fact1 ;
    unsigned char  wd_fact2 ;
    unsigned char  min_tsdr ;
    char           reserve2 ;
    unsigned char  grp_ident ;
    int16_t          user_plen ;
    char           user_pdata[206] ;
    int16_t          slv_ulen ;
    char           slv_udata[30] ;
} IODBSLVPRM3 ;

/* pmc_prfrddido:Reads DI/DO parameter of master function */
/* pmc_prfwrdido:Writes DI/DO parameter of master function */
typedef struct {
    int16_t          slave_no ;
    int16_t          slot_no ;
    unsigned char  di_size ;
    char           di_type ;
    uint16_T di_addr ;
    unsigned char  do_size ;
    char           do_type ;
    uint16_T do_addr ;
    int16_t          shift;
    unsigned char  module_dlen ;
    char           module_data[128] ;
} IODBDIDO ;

/* pmc_prfrdindiadr:Reads indication address of master function */
/* pmc_prfwrindiadr:Writes indication address of master function */
typedef struct {
    unsigned char  dummy ;
    char           indi_type ;
    uint16_T indi_addr ;
} IODBINDEADR ;


/*-----------------------------------*/
/* CB : CUSTOMER'S BOARD function    */
/*-----------------------------------*/

typedef struct odbtransinfo {
    int32_t    mas_buff_size;
    int16_t   trans_start_reqflag;
    int16_t   trans_end_reqflag;
    int16_t   trans_start_respflag;
    int16_t   trans_end_respflag;
    int32_t    all_transfer_size;
    int16_t   data_id;
    int16_t   reserve;
    int32_t    data_write_pt;
    int32_t    data_read_pt;
    int32_t    accumulation_counter;
    int16_t   forwarding_status;
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
	uint16_T DataServerPort;
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
	int16_t MaximumChannel;
	int16_t HDDExistence;
	int16_t NumberOfScreens;
} ETBPRM;

typedef struct _iodbetp {
	int16_t ParameterType;
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
	int32_t file_num;
	int32_t remainder_l;
	int32_t remainder_h;
	char current_dir[32];
} ODBHDDINF;

/* ds_rdhdddir : read the file list of the Data Server's HDD */
typedef struct _odbhdddir {
	char  file_name[64];
	char  comment[80];
	int16_t attribute;
	int16_t reserved;
	int32_t  size;
	char  date[16];
} ODBHDDDIR;

/* ds_rdhostdir : read the file list of the host */
typedef struct _odbhostdir {
	char host_file[128];
} ODBHOSTDIR;

/* ds_rdmntinfo : read maintenance information */
typedef struct _dsmntinfo {
	uint16_T empty_cnt;
	uint32_T  total_size;
	uint16_T ReadPtr;
	uint16_T WritePtr;
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
    uint32_T           TcpPort;
    uint32_T           UdpPort;
    uint32_T           TimeInterval;
} FOCAS2_PRM;

typedef struct _ftp_client_prm {
    char                    HostName[64];
    uint32_T           ControlPort;
    uint32_T           Dummy;
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
    uint32_T           Port;
    char                    InquiryName[64];
} RMTDIAG_CLIENT_PRM;

typedef struct _rmtdiag_prm {
    char                    MtbInformation[17];
    char                    MachineInformation[17];
    RMTDIAG_CLIENT_PRM      opposite[3];
} RMTDIAG_PRM;

typedef struct _factolink_client_prm {
    char                    HostName[64];
    uint32_T           Port;
} FACTOLINK_CLIENT_PRM;

typedef struct _factolink_prm {
    FACTOLINK_CLIENT_PRM    opposite[3];
} FACTO_PRM;

typedef struct _maintain_ping_prm {
    char                    HostName[64];
    uint16_T          Count;
} PING_PRM;

typedef struct _maintain_prm {
    PING_PRM                opposite;
} MAINTAIN_PRM;

typedef struct _netsrv_prm {
    char                    HostName[64];
    uint32_T           Port;
    uint32_T           TimeInterval;
    uint32_T           UdpPeriod;
    char                    MachineNumber[25];
    char                    dummy1[7];
    char                    AcceptanceReply[25];
    char                    dummy2[7];
    char                    ErrorReply[25];
    char                    dummy3[7];
} NETSRV_PRM;

typedef struct _unsolicmsg_prm {
    char                    HostName[64];
    uint32_T           Port;
    uint16_T          RetryCount;
    uint16_T          Timeout;
    uint16_T          AliveTime;
    char                    dummy1[8];
    UNSOLICMSG_TYPE_PRM     Control;
    uint16_T          TransmissionNumber;
    char                    dummy2[14];
    UNSOLICMSG_TYPE_PRM     Transmission[3];
} UNSOLICMSG_PRM;

typedef struct _pmc_addr {
    uint16_T          Path;
    int16_t                   Kind;
    uint32_T           Address;
} PMC_ADDR;

typedef struct _mbsvr_area_prm {
    uint32_T           DatSize;
    uint32_T           DatModAddr;
    PMC_ADDR                DatPmcAddr;
} MBSVR_AREA_PRM;

typedef struct _mbsvr_prm {
    uint32_T           TcpPort;
    uint16_T          Option1;
    uint16_T          Option2;
    PMC_ADDR                StsPmcAddr;
    MBSVR_AREA_PRM          AreaPrm[3];
} MBSVR_PRM;

typedef struct _user_account_prm {
    char    UserName[32];
    char    Password[32];
} USER_ACCOUNT_PRM;

typedef struct _httpsvr_prm {
    uint32_T           TcpPort;
    uint32_T           Timeout;
    USER_ACCOUNT_PRM        UserAccount[2];
} HTTPSVR_PRM;

typedef struct _stsntf_prm {
    uint32_T           PopSvrPort;
    uint32_T           SmtpSvrPort;
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
    int16_t                   reserve01;
    int16_t                   reserve02;
    int16_t                   reserve03;
    int16_t                   reserve04;
    int16_t                   reserve05;
    int16_t                   reserve06;
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
    uint16_T          Option;
    int16_t                   Type;
    int16_t                   Dhcp;
    int16_t                   ValidDevice;
    int16_t                   DtsvrChannel;
    int16_t                   Storage;
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
    int16_t                   DsMode[10];
} OUT_ETHDSMODE;

typedef struct _out_ethping1shot {
    uint16_T          MsgId;
    char                    IpAddress[64];
} OUT_ETHPING1SHOT;

/* eth_ping_result : */
typedef struct _out_ethping {
    int16_t                   Device;
    int16_t                   Count;
    OUT_ETHPING1SHOT        reply[10];
} OUT_ETHPING;

typedef struct _emblsi {
    uint16_T          Collision;
    uint16_T          CarrierSenseLost;
    uint16_T          DelayOver;
    uint16_T          Underrun;
    uint16_T          SendParityError;
    uint16_T          AlignmentError;
    uint16_T          CrcError;
    uint16_T          Overrun;
    uint16_T          FrameLengthViolation;
    uint16_T          RecvParityError;
} EMBLSI;

typedef struct _boardlsi {
    uint16_T          SendRetryOver;
    uint16_T          Collision;
    uint16_T          CarrierSenseLost;
    uint16_T          NoCarrier;
    uint16_T          InvalidFrameLength;
    uint16_T          CrcError;
    uint16_T          ShortFrame;
    uint16_T          LongFrame;
    uint16_T          OddFrame;
    uint16_T          Overflow;
    uint16_T          PhyLsiError;
} BOARDLSI;

/* eth_rdlsistate : */
typedef struct _out_ethlsi {
    int16_t                   Type;
    int16_t                   Baudrate;
    uint16_T          RecvPacketCount;
    uint16_T          RecvBroadcastCount;
    uint16_T          SendPacketCount;
    union {
        EMBLSI              emb;
        BOARDLSI            board;
    } lst;
} OUT_ETHLSI;

typedef struct _tsk_sts {
    uint16_T          StsId;
    char                    Status[30];
} TSK_STS;

/* eth_rdtaskstate : */
typedef struct _out_ethtask {
    int16_t                   Type;
    int16_t                   Count;
    char                    pad[12];
    TSK_STS                 task[32];
} OUT_ETHTASK;

typedef struct _out_ethlog1shot {
    int16_t                   Type;
    uint16_T          MsgId;
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
    int16_t                   Count;
    char                    reserve[14];
    OUT_ETHLOG1SHOT         logData[15];
} OUT_ETHLOG;

/* eth_rdtype : */
typedef struct _out_ethtype {
    int16_t                   Kind;
    int16_t                   FunctionEmb;
    int16_t                   FunctionBoard;
    int16_t                   FunctionEmbCe;
} OUT_ETHTYPE;

/* eth_rdtype2 : */
typedef struct _out_ethtype2 {
    uint16_T          Kind;
    int16_t                   dummy;
    uint32_T           FunctionEmb;
    uint32_T           FunctionEmbPcm;
    uint32_T           FunctionBoard;
    uint32_T           FunctionEmbCe;
    uint32_T           FunctionEmbCePcm;
} OUT_ETHTYPE2;

/* eth_rdtype3 : */
typedef struct _out_ethtype3 {
    uint32_T           Kind;
    uint16_T          KindFLnet;
    int16_t                   Pad;
    uint32_T           FunctionEmb;
    uint32_T           FunctionEmbPcm;
    uint32_T           FunctionBoard;
    uint32_T           FunctionEmbCe;
    uint32_T           FunctionEmbCePcm;
    uint32_T           FunctionReserve;
} OUT_ETHTYPE3;

/* eth_rddsstate : */
typedef struct _out_dsstate {
    int16_t                   DtsvrChannel;
    int16_t                   pad;
    int16_t                   Mode;
    uint16_T          EmptyCount;
    uint32_T           TotalSize;
    uint16_T          WritePtr;
    uint16_T          ReadPtr;
} OUT_DSSTATE;

/* eth_rdunsolicstate : */
typedef struct _out_unsolicstate {
    char                    IpAddress[64];
    uint16_T          status;
} OUT_UNSOLICSTATE;

/* eth_rdfsclntinfo : */
typedef struct _clnt_info {
    char                    IpAddress[64];
    int32_t                    SocketId;
    uint32_T           ConnectTime;
} CLNT_INFO;

typedef struct _out_fsinfo {
    int16_t                   Number;
    unsigned char           pad[2];
    CLNT_INFO               clntinfo[10];
} OUT_FSINFO;

/* eth_rdmbsclntinfo : */
typedef struct _mbsvr_clnt_info {
    char                    IpAddress[64];
    uint32_T           ConnectTime;
} MBSVR_CLNT_INFO;

typedef struct _out_mbsvrinfo {
    int16_t                   Number;
    unsigned char           pad[2];
    MBSVR_CLNT_INFO         clntinfo[10];
} OUT_MBSVRINFO;

/* net_rdtype : */
typedef struct _out_fl_devtype {
    uint16_T          Kind1;
    unsigned char           pad1[2];
    uint32_T           FunctionFLnet1;
    uint16_T          Kind2;
    unsigned char           pad2[2];
    uint32_T           FunctionFLnet2;
} FL_DEVTYPE;

typedef struct _out_pnc_devtype {
    uint16_T          Kind;
    unsigned char           pad[2];
    uint32_T           FunctionPnc;
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
    uint16_T          TcpPort;
    uint16_T          UdpPort;
    char                    DiDataOnAbnormal;
    unsigned char           Option1;
    char                    pad[2];
} EIP_COMMON_PRM;

typedef struct _eipa_basic_prm {
    EIP_COMMON_PRM          Common;
    unsigned char           Option2;
    unsigned char           AllocMax;
    uint16_T          ConnectMax;
    uint16_T          RPI_Min;
    uint16_T          RPI_Max;
    struct {
        uint16_T      Path;
        int16_t               Addr;
        uint32_T       No;
    }                       Status;
    uint32_T           StatusSize;
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
    uint16_T          Type;
    char                    pad[2];
    union {
        struct {
            uint16_T  Path;
            int16_t           Addr;
            uint32_T   No;
            uint32_T   Size;
        } pmc;
        struct {
            uint16_T  Path;
            char            pad[2];
            uint32_T   No;
            uint32_T   Num;
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
    uint16_T          VendorId;
    uint16_T          DeviceType;
    uint16_T          ProductCode;
    unsigned char           MajorRevision;
    unsigned char           MinorRevision;
    uint32_T           SerialNo;
} OUT_EIP_DEVICEINFO;

typedef struct _out_eipa_scndata {
    int32_t                    ConnectionId;
    uint32_T           ConnectTime;
    char                    IpAddress[40];
} OUT_EIPA_SCNDATA;

typedef struct _out_eip_listdetail {
    char                    IpAddress[40];
    uint32_T           ConnectTime;
    char                    ApplicationType;
    char                    pad1;
    uint16_T          O2T_RPI;
    uint16_T          T2O_RPI;
    uint16_T          O2T_API;
    uint16_T          T2O_API;
    uint16_T          RecvPacket;
    uint16_T          SendPacket;
    uint16_T          LostPacket;
    int16_t                   AllocationId;
    char                    pad2[2];
} OUT_EIP_LISTDETAIL;

typedef struct _eip_unuse_addr {
    uint16_T          Param1;
    int16_t                   Param2;
    uint32_T           Param3;
} EIP_UNUSE_ADDR;

typedef struct _eip_pmc_addr {
    uint16_T          Path;
    int16_t                   Addr;
    uint32_T           No;
} EIP_PMC_ADDR;

typedef struct _eip_multi_addr {
    union {
        EIP_UNUSE_ADDR      Unuse;
        EIP_PMC_ADDR        Pmc;
    } Prm;
} EIP_MULTI_ADDR;

typedef struct _eips_basic_prm {
    EIP_COMMON_PRM          Common;
    uint16_T          Network;
    unsigned char           pad[2];
    unsigned char           Option2;
    unsigned char           AllocMax;
    uint16_T          ConnectMax;
    uint16_T          RPI_Min;
    uint16_T          RPI_Max;
    EIP_PMC_ADDR            StatusAddr;
    uint32_T           StatusSize;
} EIPS_BASIC_PRM;

typedef EIPS_BASIC_PRM   IN_EIPS_BASIC_PRM;
typedef EIPS_BASIC_PRM  OUT_EIPS_BASIC_PRM;

typedef struct _out_eips_state_prm {
    unsigned char           State[32];
    char                    reserve[32];
} OUT_EIPS_STATE_PRM;

typedef struct _eips_conn_prm {
    uint32_T           AssemblyInstance;
    uint16_T          Type;
    char                    pad1[2];
    EIP_MULTI_ADDR          Addr;
    uint32_T           Size;
    uint32_T           RPI;
    uint16_T          TransportType;
    uint16_T          HeaderFormat;
    uint16_T          Priority;
    char                    pad2[2];
    char                    reserve[28];
    char                    pad3[4];
} EIPS_CONN_PRM;

typedef struct _eips_electronic_key {
    uint16_T          VendorID;
    uint16_T          DeviceType;
    uint16_T          ProductCode;
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
    uint32_T           ConfigInstance;
    EIPS_CONN_PRM           ConnT2O;
    EIPS_CONN_PRM           ConnO2T;
    EIP_PMC_ADDR            reserve1;
    EIP_PMC_ADDR            reserve2;
    unsigned char           ProductTrigger;
    unsigned char           Timeout;
    unsigned char           Reconnect;
    char                    pad;
    EIPS_ELECTRONIC_KEY     ElectronicKey;
    uint32_T           DataPerSec;
    uint32_T           DataPerSecTotal;
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
    int16_t                   Result;
    char                    pad1[2];
    char                    IpAddress[40];
    unsigned char           GeneralCode;
    char                    pad2;
    uint16_T          ExtendedCode;
    uint32_T           ConnectTime;
    uint16_T          O2T_RPI;
    uint16_T          T2O_RPI;
    uint16_T          O2T_API;
    uint16_T          T2O_API;
    uint16_T          RecvPacket;
    uint16_T          SendPacket;
    uint16_T          LostPacket;
    char                    pad3[2];
} OUT_EIPS_DETAIL_INFO;

typedef struct _out_eips_identity_info {
    int16_t                   Result;
    char                    pad1[2];
    uint16_T          VendorId;
    uint16_T          DeviceType;
    uint16_T          ProductCode;
    unsigned char           MajorRevision;
    unsigned char           MinorRevision;
    uint32_T           SerialNo;
    char                    ProductName[33];
    char                    pad2[3];
} OUT_EIPS_IDENTITY_INFO;

typedef struct _out_adpsafe_mntinfo {
    uint16_T  SupervisorStatus;
    unsigned char   SafetyNetworkNumber[6];

    uint16_T  SelfDiagnosisErrorA;
    uint16_T  SelfDiagnosisErrorB;
    uint16_T  SelfDiagnosisDetailA;
    uint16_T  SelfDiagnosisDetailB;

    uint32_T   SafetyParameterCrc;
    uint16_T  ChangeDateYear;
    unsigned char   ChangeDateMonth;
    unsigned char   ChangeDateDay;
    uint16_T  ChangeTimeHours;
    uint16_T  ChangeTimeMinutes;
    uint16_T  ChangeTimeSeconds;
    uint16_T  Pad;

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

    uint16_T  DiRecvPacketNumberA;
    uint16_T  DiRecvPacketNumberB;
    uint16_T  DoSendPacketNumberA;
    uint16_T  DoSendPacketNumberB;
} OUT_ADPSAFE_MNTINFO;

/*---------------------------*/
/* NET : PROFIBUS function   */
/*---------------------------*/

/* pbm_rd_param */
typedef struct _T_MAS_USR
{
    uint16_T          master_user_data_len;
    unsigned char           master_user_data[62];
} T_MAS_USR;

typedef struct _T_BUS_PARA
{
    unsigned char           fdl_add;
    unsigned char           baud_rate;
    uint16_T          tsl;
    uint16_T          min_tsdr;
    uint16_T          max_tsdr;
    unsigned char           tqui;
    unsigned char           tset;
    uint32_T           ttr;
    unsigned char           g;
    unsigned char           hsa;
    unsigned char           max_retry_limit;
    unsigned char           bp_flag;
    uint16_T          min_slave_interval;
    uint16_T          poll_timeout;
    uint16_T          data_control_time;
    unsigned char           reserved[6];
    char                    master_class2_name[32];
    T_MAS_USR               mas_usr;
} T_BUS_PARA;

typedef struct _T_MODE_ADDR_ALLOC
{
    unsigned char           md_path;
    unsigned char           md_kind;
    uint16_T          md_top_address;
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
    uint16_T          user_prm_data_len;
    unsigned char           user_prm_data[201];
    unsigned char           pad;
} T_USR_PRM_DATA;

typedef struct _T_PRM_DATA
{
    unsigned char           station_status;
    unsigned char           wd_fact_1;
    unsigned char           wd_fact_2;
    unsigned char           min_tsdr;
    uint16_T          ident_number;
    unsigned char           group_ident;
    unsigned char           pad;
    T_USR_PRM_DATA  usr_prm;
} T_PRM_DATA;

typedef struct _T_CFG_DATA
{
    uint16_T          cfg_data_len;
    unsigned char           cfg_data[128];
} T_CFG_DATA;

typedef struct _T_SLV_USR_DATA
{
    uint16_T          slave_user_data_len;
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
    uint16_T          dgn_top_address;
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
    uint16_T          module_len;
    unsigned char           module_data[128];
} T_MODULE_DATA;

typedef struct _T_DIDO_ADDR_ALLOC
{
    T_SLOT_IND_PARA         slt_ind_para;
    unsigned char           di_path;
    unsigned char           do_path;
    unsigned char           di_kind;
    unsigned char           do_kind;
    uint16_T          di_top_address;
    uint16_T          do_top_address;
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
    uint16_T          dgn_top_address;
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
    uint16_T          param_err_code[4];
    uint16_T          inter_err_code[4];
} T_ERR_CODE;

/* pbm_chg_mode */
typedef struct _OUT_CHGMODERESULT{
    unsigned char           crnt_mode;
    unsigned char           pad;
    uint16_T          result;
} OUT_CHGMODERESULT;

/* pbm_rd_comstate */
typedef struct _T_DATA_REF_TIM{
    uint16_T          total_ref_tim;
    uint16_T          board_ref_tim;
    uint16_T          cnc_ref_tim;
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
    uint16_T          ident;
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
    uint16_T          di_top_address;
    uint16_T          do_top_address;
    unsigned char           module_type;
    unsigned char           commstat;
    uint16_T          reserved;
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
    uint16_T          di_top_address;
    uint16_T          do_top_address;
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
    uint16_T          di_top_address;
    uint16_T          do_top_address;
} IN_PBSPRM;

/* pbs_rd_cominfo */
typedef struct _OUT_PBSSTATUS{
    unsigned char           config_sts;
    unsigned char           param_sts;
    unsigned char           watchdog_sts;
    unsigned char           pad;
    uint16_T          ident_no;
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
    uint16_T          di_top_address;
    uint16_T          do_top_address;
    unsigned char           sts_path;
    unsigned char           sts_kind;
    uint16_T          sts_top_address;
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
    uint16_T          di_top_address;
    uint16_T          do_top_address;
    unsigned char           sts_path;
    unsigned char           sts_kind;
    uint16_T          sts_top_address;
} IN_PBSPRM2;

/* pbs_rd_cominfo2 */
typedef struct _OUT_PBSSTATUS2{
    unsigned char           config_sts;
    unsigned char           param_sts;
    unsigned char           watchdog_sts;
    unsigned char           pad1;
    uint16_T          ident_no;
    unsigned char           sts;
    unsigned char           pad2;
} OUT_PBSSTATUS2;

/*--------------------------*/
/* HSSB multiple connection */
/*--------------------------*/

/* cnc_rdnodeinfo:read node informations */
typedef struct odbnode {
	int32_t node_no;
	int32_t io_base;
	int32_t status;
	int32_t cnc_type;
	char node_name[20];
} ODBNODE;

/*--------------------------*/
/*  Power Mate CNC manager  */
/*--------------------------*/

/* initialize */

typedef struct odbpmmslv {
	int32_t	slvnum;       /* a number of groups  */
	int32_t	group[8];     /* group's number */
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
	int32_t	top;         /* top number */
	int32_t	num;         /* number of data  */
} IDBPMMGTI ;


/* get continuos data */
typedef struct odbpmmget {
	int32_t   pos     ;        /* position           */
	int32_t   feed    ;        /* actual feed        */
    int32_t   data[20];        /* diagnosis's data   */
	int32_t   number[20];      /* number of diagnosis's data */
	int16_t  axis[20];        /* axis attribute of diagnosis's data */
	int16_t  type[20];        /* data type of diagnosis's data */
	char   alaxis[40];        /* axis attribute of alarm */
	uint16_T  alnumber[40]; /* number of alarm */
	int32_t   chanl ;     /* data's chanl      */
	int32_t   group ;     /* data's group      */
} ODBPMMGET ;

/* get parameter 1 page */
typedef struct odbpmmprp {
	int32_t            data    ;        /* data    */
	uint16_T  number  ;        /* number  */
	unsigned char   axis    ;        /* axis attribute */
	unsigned char   type    ;        /* data type */
} ODBPMMPRP ;

/* read/write  parameter (tape memory) */
typedef struct idbpmmprp {
	int32_t   chanl       ;        /* channel */
	int32_t   group       ;        /* group   */
	char   folder[130] ;        /* folder (current //CNC_MEM/USER/PATH1/)*/
	int32_t   warn        ;        /* warnning */
} IDBPMMPRP ;

/* I/O LINK channel number */
typedef struct odbpmmio {
    int32_t   chanlnum;     /* channel number */
} ODBPMMIO ;

/*--------------------------*/
/* real-time custom macro   */
/*--------------------------*/

typedef struct  iodbrtmio {
	int16_t adr_type;
	int16_t dummy;
	uint32_T no;
	char	bit;
} IODBRTMIO ;

typedef struct  iodbrtmior {
	int16_t adr_type;		/* kind of DI/DO variable address(alphabet) */
	int32_t adr_attr ;		/* PMC address attribute (use for cnc_getrtmioinfo only) */
	uint32_T sno;	/* DI/DO variable access enable start no. */
	uint32_T eno;	/* DI/DI variable access enable end no. */
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
    int32_t    data[MAX_AXIS]; /* Axis move distance   */
    int32_t    dp[MAX_AXIS];   /* Decimal point        */
} IODBAXIS ;

/* cnc_wrtofsdrctinp:write Tool offset data Direct Input */
typedef struct realmes {
	int32_t   mes_val; /* data of real measeure */
	int32_t   dec_val; /* decimal point of real measeure */
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
		 int32_t  hour;
		 int32_t  minute;
		 int32_t  second;
	 } time;
	 int32_t  testno;		/* Last Test No. */
	 int32_t  sign;		/* Test Request DI */
} DCSMCC;

typedef struct dcsmca {
	int32_t	mgrp_no ;
	DCSMCC*	mcc_test_inf ;
} DCSMCA;

typedef struct dcsfmoni {
    int32_t  data_d ;		/* Fixed Val  */
    int32_t  data_p ;		/* Present Val*/
} ODBDCSFMONI;

typedef struct dcscrsalm {
	int32_t existFlag;
	int32_t pmc_no;
	struct {
		char  pmc_adr[8] ;
		int32_t  pmc_data[8];
		char  dcs_adr[8];
		int32_t  dcs_data[8];
	} pmc ;
	struct {
		char  pmc_adr[8] ;
		int32_t  pmc_data[8];
		char  dcs_adr[8];
		int32_t  dcs_data[8];
	} dcspmc ;
} DCSCRSALM ;

typedef struct dcssvspsts {
 	char	name[4];
 	int32_t	dummy;
    double	ncdata;
    double	svspdata;
}DCSSVSPSTS;

typedef struct dcssvspst2 {
	double	limit_dt_p;
	double	limit_dt_m;
	int16_t	axissts;
	int16_t	unittype;
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
    uint16_T  Address;
} PMC_REG;

/* dnm_rdparam  */
/* dnm_rdparam2 */
typedef struct _out_dnmprm_bus {
    int16_t           Network;
    int16_t           BaudRate;
    int16_t           DiDataOnAbnormal;
    int16_t           OwnMacId;
    PMC_REG         CommonStatus;
    int16_t           CommonStatusSize;
    int16_t           CycleTimeSetting;
    int16_t           CycleTimeCurrent;
    int16_t           CycleTimeMaximum;
    int16_t           CycleTimeMinimum;
    uint16_T  RefreshTime;
} OUT_DNMPRM_BUS;

typedef struct _out_dnmprm_each_node {
    int16_t           NodeNumber;
    int16_t           Communication;
    int16_t           reserved1[6];
    PMC_REG         DetailStatus;
    int16_t           reserved2[2];
    PMC_REG         Di;
    int16_t           DiSize;
    int16_t           reserved3;
    PMC_REG         Do;
    int16_t           DoSize;
    int16_t           reserved4;
} OUT_DNMPRM_SLAVE;

typedef struct _out_dnmprm {
    union {
        OUT_DNMPRM_BUS      bus;
        OUT_DNMPRM_SLAVE    slave;
    } prm;
} OUT_DNMPRM;

typedef struct _out_dnmprm_bus2 {
    int16_t           Network;
    int16_t           BaudRate;
    int16_t           DiDataOnAbnormal;
    int16_t           OwnMacId;
    PMC_REG         CommonStatus;
    int16_t           CommonStatusSize;
    int16_t           CycleTimeSetting;
    int16_t           CycleTimeCurrent;
    int16_t           CycleTimeMaximum;
    int16_t           CycleTimeMinimum;
    uint16_T  RefreshTime;
    uint16_T  Option;
    int16_t           reserved;
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
    int16_t           Network;
    int16_t           BaudRate;
    int16_t           DiDataOnAbnormal;
    int16_t           OwnMacId;
    PMC_REG         CommonStatus;
    int16_t           CommonStatusSize;
    int16_t           CycleTimeSetting;
    int16_t           reserved[8];
} IN_DNMPRM_BUS;

typedef struct _in_dnmprm_each_node {
    int16_t           reserved1;
    int16_t           Communication;
    int16_t           reserved2[6];
    PMC_REG         DetailStatus;
    int16_t           reserved3[2];
    PMC_REG         Di;
    int16_t           DiSize;
    int16_t           reserved4;
    PMC_REG         Do;
    int16_t           DoSize;
    int16_t           reserved5;
} IN_DNMPRM_SLAVE;

typedef struct _in_dnmprm {
    union {
        IN_DNMPRM_BUS       bus;
        IN_DNMPRM_SLAVE     slave;
    } prm;
} IN_DNMPRM;

typedef struct _in_dnmprm_bus2 {
    int16_t           Network;
    int16_t           BaudRate;
    int16_t           DiDataOnAbnormal;
    int16_t           OwnMacId;
    PMC_REG         CommonStatus;
    int16_t           CommonStatusSize;
    int16_t           CycleTimeSetting;
    int16_t           reserved1[4];
    uint16_T  Option;
    int16_t           reserved2[3];
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
    int16_t           MacId;
    int16_t           State;
    int16_t           RetryCounter;
    uint16_T  VenderId;
    uint16_T  DeviceType;
    uint16_T  ProductCode;
} OUT_DNMNODEINFO;

/* dnm_rdfirminfo */
typedef struct _out_dnmfirm {
    uint16_T  MpuStatus1;
    uint16_T  MpuStatus2;
    uint16_T  MasterStatus1;
    uint16_T  CanRecvCounter;
    uint16_T  CanSendCounter;
    uint16_T  CanRecvErrorCounter;
    uint16_T  CanSendErrorCounter;
    uint16_T  FirmwareVersion;
} OUT_DNMFIRM;

/* dnm_rderrorrecord */
typedef struct _out_dnmerr_record {
    uint16_T  AbnormalCode;
    uint16_T  DetailCode;
} OUT_DNMERR_RECORD;

typedef struct _out_dnmerr {
    OUT_DNMERR_RECORD   record[8];
} OUT_DNMERR;

/* dnm_rd_hist */
typedef struct _out_dnmhist_log {
    unsigned char   Type;
    unsigned char   reserved;
    uint16_T  Mpu1;
    uint16_T  Mpu2;
    uint16_T  Sts1;
    unsigned char   Slave[8];
    unsigned char   Date;
    unsigned char   Hour;
    unsigned char   Minute;
    unsigned char   Second;
} OUT_DNMHIST_LOG;

typedef struct _out_dnmhist {
    uint16_T  Count;
    uint16_T  reserved;
    OUT_DNMHIST_LOG Log[32];
} OUT_DNMHIST;

/* dns_rdparam */
typedef struct _out_dnsprm {
    int16_t           BaudRate;
    int16_t           DiDataOnAbnormal;
    int16_t           OwnMacId;
    char            pad1[2];
    PMC_REG         Di;
    int16_t           DiSize;
    char            pad2[2];
    PMC_REG         Do;
    int16_t           DoSize;
    char            pad3[2];
    PMC_REG         Status;
    int16_t           StatusSize;
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
    int16_t           BaudRate;
    int16_t           DiDataOnAbnormal;
    int16_t           OwnMacId;
    char            pad1[2];
    PMC_REG         Di;
    int16_t           DiSize;
    char            pad2[2];
    PMC_REG         Do;
    int16_t           DoSize;
    char            pad3[2];
    PMC_REG         Status;
    int16_t           StatusSize;
    char            pad4[2];
} IN_DNSPRM;

/* dns_rdinfo */
typedef struct _dnsidentityinfo {
    uint16_T  VenderID;
    uint16_T  DeviceType;
    uint16_T  ProductCode;
    unsigned char   MajorRev;
    unsigned char   MinorRev;
    uint32_T   SerialNo;
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
    uint16_T  Count;
    uint16_T  reserved;
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
    int16_t           Area1CmnMemAddr;
    int16_t           Area1CmnMemSize;
    int16_t           Area2CmnMemAddr;
    int16_t           Area2CmnMemSize;
    unsigned char   TokenWatch;
    char            MinFrame;
    char            Reserved0[2];
    PMC_REG         OwnStatus;
    PMC_REG         EntryNode;
    PMC_REG         Area1PmcAddr;
    int16_t           Area1ExchgAddr;
    int16_t           Area1ExchgSize;
    PMC_REG         Area2PmcAddr;
    int16_t           Area2ExchgAddr;
    int16_t           Area2ExchgSize;
    PMC_REG         Area2PmcDoAddr;
    int16_t           Area2ExchgDoSize;
    char            Reserved1[2];
    PMC_REG         Area2PmcDiAddr;
    PMC_REG         Area2ConditionAddr;
    PMC_REG         Area2AlterAddr;
    int16_t           Area2ExchgDiAddr;
    int16_t           Area2ExchgDiSize;
    PMC_REG         ClientMsgAddr;
    int16_t           ClientMsgSize;
    char            Reserved2[2];
    PMC_REG         ServerMsgAddr;
    int16_t           ServerMsgSize;
    char            Reserved3[2];
    uint16_T  Option1;
    uint16_T  Option2;
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
    int16_t           Area1CmnMemAddr;
    int16_t           Area1CmnMemSize;
    int16_t           Area2CmnMemAddr;
    int16_t           Area2CmnMemSize;
    unsigned char   TokenWatch;
    char            MinFrame;
    char            Reserved0[2];
    PMC_REG         OwnStatus;
    PMC_REG         EntryNode;
    PMC_REG         Area1PmcAddr;
    int16_t           Area1ExchgAddr;
    int16_t           Area1ExchgSize;
    PMC_REG         Area2PmcAddr;
    int16_t           Area2ExchgAddr;
    int16_t           Area2ExchgSize;
    PMC_REG         Area2PmcDoAddr;
    int16_t           Area2ExchgDoSize;
    char            Reserved1[2];
    PMC_REG         Area2PmcDiAddr;
    PMC_REG         Area2ConditionAddr;
    PMC_REG         Area2AlterAddr;
    int16_t           Area2ExchgDiAddr;
    int16_t           Area2ExchgDiSize;
    PMC_REG         ClientMsgAddr;
    int16_t           ClientMsgSize;
    char            Reserved2[2];
    PMC_REG         ServerMsgAddr;
    int16_t           ServerMsgSize;
    char            Reserved3[2];
    uint16_T  Option1;
    uint16_T  Option2;
} IN_FLNTPRM;

/* flnt_rdentry  */
/* flnt_rdentry2 */
typedef struct _out_flntentry {
    unsigned char   Node;
    char            Reserved[3];
    uint32_T   EntryNode[8];
} OUT_FLNTENTRY;

/* flnt_rdnodeinfo  */
/* flnt_rdnodeinfo2 */
typedef struct _out_flntnodetbl {
    char            NodeName[12];
    char            VendorName[12];
    char            MakerType[12];
    int16_t           Area1Address;
    int16_t           Area1Size;
    int16_t           Area2Address;
    int16_t           Area2Size;
    uint16_T  Rct;
    uint16_T  Uls;
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
    uint16_T  Rct;
    uint16_T  Rcm;
    uint16_T  MaxRcm;
    uint16_T  MinRcm;
} OUT_FLNTNETTBL;

/* flnt_rdlog */
typedef struct _out_flntlog {
    uint32_T   TotalSend;
    uint32_T   SendErr;
    uint32_T   TotalRecv;
    uint32_T   RecvErr;
    uint32_T   CycErr;
    uint32_T   MsgRetry;
    uint32_T   MsgRetryOver;
    uint32_T   RecvMsgErr;
    uint32_T   AckErr;
    uint32_T   DuplicatedToken;
    uint32_T   DestroyedToken;
    uint32_T   ReissueToken;
    uint32_T   FrameWait;
    uint32_T   Entry;
    uint32_T   OutRing;
    uint32_T   Skip;
    uint32_T   Disconnect;
} OUT_FLNTLOG;

/* flnt_rdlog2 */
typedef struct _out_flntlog2 {
    uint32_T   TotalSend;
    uint32_T   SendErr;
    uint32_T   TotalRecv;
    uint32_T   RecvErr;
    uint32_T   CycErr;
    uint32_T   MsgRetry;
    uint32_T   MsgRetryOver;
    uint32_T   RecvMsgErr;
    uint32_T   AckErr;
    uint32_T   DuplicatedToken;
    uint32_T   DestroyedToken;
    uint32_T   ReissueToken;
    uint32_T   FrameWait;
    uint32_T   Entry;
    uint32_T   OutRing;
    uint32_T   Skip;
    uint32_T   Disconnect;
    int16_t           Baudrate;
    char            Reserved[2];
} OUT_FLNTLOG2;

/* flnt_rdmsg  */
/* flnt_rdmsg2 */
typedef struct _out_flnteachmsg {
    uint16_T  MsgId;
    unsigned char   Year;
    unsigned char   Month;
    unsigned char   Day;
    unsigned char   Hour;
    unsigned char   Minute;
    unsigned char   Second;
    char            Text[32];
} OUT_FLNTEACHMSG;

typedef struct _out_flntmsg {
    int16_t           Count;
    char            reserve[14];
    OUT_FLNTEACHMSG msgData[15];
} OUT_FLNTMSG;

/* flnt_rddeviceinfo */
typedef struct _out_flntdevinfo {
    uint16_T      Kind;
    int16_t               dummy;
    uint32_T       FunctionFLnetBoard;
    uint32_T       FunctionFLnetEmb;
    uint32_T       FunctionFLnetCard;
} OUT_FLNTDEVINFO;

/* flnt_rddeviceinfo2 */
typedef struct _out_flntdevinfo2 {
    uint16_T      Kind;
    int16_t               Pad;
    uint32_T       FunctionFLnet;
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
    int16_t           AlarmInfo;
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
    uint32_T   EntryNode;
    NODE_ERR        nodeErr[30];
} OUT_FLNTSFERRTBL;


/*----------------------------*/
/* NET : CC-Link function     */
/*----------------------------*/

/* cclr_rdparam */
typedef struct _out_cclrprm {
    int16_t           BaudRate;
    int16_t           ID;
    int16_t           UseIDCount;
    int16_t           DataOnAbnormal;
    PMC_REG         Status;
    PMC_REG         RY;
    int16_t           RYSize;
    char            pad1[2];
    PMC_REG         RX;
    int16_t           RXSize;
    char            pad2[2];
    PMC_REG         RWw;
    int16_t           RWwSize;
    char            pad3[2];
    PMC_REG         RWr;
    int16_t           RWrSize;
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
    int16_t           BaudRate;
    int16_t           ID;
    int16_t           UseIDCount;
    int16_t           DataOnAbnormal;
    PMC_REG         Status;
    PMC_REG         RY;
    int16_t           RYSize;
    char            pad1[2];
    PMC_REG         RX;
    int16_t           RXSize;
    char            pad2[2];
    PMC_REG         RWw;
    int16_t           RWwSize;
    char            pad3[2];
    PMC_REG         RWr;
    int16_t           RWrSize;
    char            pad4[2];
} IN_CCLRPRM;

/* cclr_rdinfo */
typedef struct _out_cclrinfo {
    unsigned char   LineStatus;
    unsigned char   MachineCode;
    uint16_T  MakerCode;
    uint16_T  errCode;
    char            pad[2];
} OUT_CCLRINFO;


/*----------------------------*/
/* NET : USB function         */
/*----------------------------*/

/* usb_rdinfo */
typedef struct _out_usbinfo {
    int16_t           UsbStatus;
    uint16_T  VendorID;
    uint16_T  ProductID;
    uint16_T  DeviceRelease;
    char            Manufacturer[64];
    char            ProductName[64];
    char            SerialNumber[64];
} OUT_USBINFO;

/* usb_rdlog */
typedef struct _out_usblog1shot {
    int16_t           Type;
    uint16_T  MsgId;
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
    int16_t           Count;
    char            reserve[14];
    OUT_USBLOG1SHOT logData[15];
} OUT_USBLOG;

/*-----------------------------------*/
/* NET : PROFINET IO Device function */
/*-----------------------------------*/

typedef struct _pnd_addr {
    uint16_T          Path;
    int16_t                   Kind;
    uint32_T           Addr;
    uint32_T           Size;
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
    uint16_T          Count;
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
    uint16_T          VendorID;
    uint16_T          DeviceID;
    uint16_T          InputSize;
    uint16_T          OutputSize;
    uint16_T          RcvRead;
    uint16_T          RcvWrite;
    uint16_T          RcvRt;
    uint16_T          RcvRtU;
    uint16_T          RcvPause;
    uint16_T          RcvLldp;
    uint16_T          InputCycleTime;
    uint16_T          OutputCycleTime;
    uint16_T          DoRefreshTime;
    uint16_T          DiRefreshTIme;
} OUT_PND_MNTINFO;

/*---------------------------------------*/
/* NET : PROFINET IO Controller function */
/*---------------------------------------*/

/* pnc_rdparam pnc_wrparam */
typedef struct _pnc_addr {
    uint16_T          Path;
    int16_t                   Kind;
    uint32_T           Addr;
    uint32_T           Size;
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
    uint16_T          Count;
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
    uint16_T          Path;
    int16_t                   Kind;
    uint32_T           Addr;
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
    uint16_T          DiDoRefreshTime;
} OUT_PNC_CNTRLR_INFO;

/* pnc_rdmntinfo */
typedef struct _out_pnc_device_info {
    char                    IpAddress[16];
    unsigned char           Status;
    unsigned char           pad[3];
    PNC_ADDRTOP             DiAddrTop;
    PNC_ADDRTOP             DoAddrTop;
    uint16_T          InputSize;
    uint16_T          OutputSize;
    uint16_T          InputCycleTime;
    uint16_T          OutputCycleTime;
    uint32_T           AlarmNum;
    uint32_T           ConnectTime;
} OUT_PNC_DEVICE_INFO;

/* pnc_rdmntinfo */
typedef struct _out_pnc_allcom_stat {
    unsigned char           State[48];
} OUT_PNC_ALLCOM_STAT;

/* pnc_resdetailinfo */
typedef struct _out_pnc_detail_info {
    int16_t                   Result;
    unsigned char           pad[2];
    char                    IpAddress[16];
    char                    Info[360];
} OUT_PNC_DETAIL_INFO;

/*-----------------------------------*/
/* NET : EtherCAT function           */
/*-----------------------------------*/

/* ect_rdlog */
typedef struct _out_ectlog1shot {
    uint16_T          MsgId;
    unsigned char           Year;
    unsigned char           Month;
    unsigned char           Day;
    unsigned char           Hour;
    unsigned char           Minute;
    unsigned char           Second;
    char                    Text[32];
} OUT_ECTLOG1SHOT;

typedef struct _out_ectlog {
    uint16_T          Count;
    unsigned char           reserve[14];
    OUT_ECTLOG1SHOT         logData[15];
} OUT_ECTLOG;

/* ect_rdslvtype */
typedef struct _out_ecttype {
    unsigned char           Kind;
    unsigned char           Slot;
    uint16_T          FunctionEctSlv;
} OUT_ECTTYPE;

/* ect_rdslvdeviceinfo */
typedef struct _out_ectdevinfo {
    char                    EsiVersion[8];
    uint32_T           VendorID;
    uint32_T           ProductCode;
    uint32_T           RevisionNo;
    uint16_T          NodeAddress;
    unsigned char           pad[2];
} OUT_ECTDEVINFO;

/* ect_rdslvdeviceinfo */
typedef struct _out_ectnetinfo {
    uint16_T          Esm;
    uint16_T          Mode;
} OUT_ECTNETINFO;


/*--------------------*/
/* RENISHAW function  */
/*--------------------*/
typedef struct odbrenplt {
    int16_t           delay_time ;
    uint16_T  data_flag ;
    int16_t           pos_data[6] ;
} ODBRENPLT ;

/* cnc_rdproctime:read processing time stamp data */
typedef struct odbptime2 {
	int16_t	num;
	struct{
		char	filename[36];
		int16_t	hour;
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
   	int16_t   file_no;
   	char    file_name[16];
   	int16_t   repeat_num;
   	int16_t   current_num;
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
            int16_t   ov_time ;
            int16_t   number ;
            int16_t   next_table ;
            int16_t   skip_table ;
            int16_t   skip_signal ;
            int16_t   table_kind ;
            int16_t   master_indx_no ;
        }state1;
        struct{
            double  l_value_e_sub ;
            double  pos_value_e_sub ;
            double  l_value_sub ;
            int32_t    repeat_e_sub ;
            int32_t    repeat_sub ;
            int16_t   number_sub ;
            int16_t   next_table_sub ;
            int16_t   skip_table_sub ;
            int16_t   skip_signal_sub ;
            int16_t   table_kind_sub ;
            int16_t   master_indx_no_sub ;
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
            int32_t    srpm ;
            int32_t    sspm ;
            int32_t    smax ;
            int16_t   ov_time ;
            int16_t   number ;
            int16_t   next_table ;
            int16_t   skip_table ;
            int16_t   skip_signal ;
            char    sp_mode ;
        }state1;
        struct{
            double  l_value_e_sub ;
            double  pos_value_e_sub ;
            double  l_value_sub ;
            int32_t    repeat_e_sub ;
            int32_t    repeat_sub ;
            int16_t   number_sub ;
            int16_t   next_table_sub ;
            int16_t   skip_table_sub ;
            int16_t   skip_signal_sub ;
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
            int32_t    m_code[3] ;
            int16_t   ov_time ;
            int16_t   number ;
            int16_t   next_table ;
            int16_t   skip_table ;
            int16_t   skip_signal ;
            int16_t   table_kind ;
            int16_t   master_indx_no ;
            int16_t   m_count ;
        }state1;
        struct{
            double  l_value_e_sub ;
            double  l_value_sub ;
            int32_t    repeat_e_sub ;
            int32_t    repeat_sub ;
            int16_t   number_sub ;
            int16_t   next_table_sub ;
            int16_t   skip_table_sub ;
            int16_t   skip_signal_sub ;
            int16_t   table_kind_sub ;
            int16_t   master_indx_no_sub ;
        }state2;
    }u;
}ODBPTAXFUNCSTAT ;

/*--- cnc_rdptcomment ---*/
typedef struct odbptcomment {
    int32_t    t_code ;
    char    comment_count ;
    char    pto_mode ;
    char    dummy1[2] ;
    char    comment[10][32] ;
}ODBPTCOMMENT ;

/*--- cnc_rdpthis_gb ---*/
typedef struct odbpthis_gb {
    struct {
        int16_t   year;
        char    mon;
        char    day;
        char    hour;
        char    min;
        char    sec;
    } date;
    char    reserve1;
    int32_t    info1;
    char    path_num;
    char    reserve2[3];
} ODBPTHIS_GB ;

/*--- cnc_rdpthis_pt ---*/
typedef struct odbpthis_pt {
    double  time;
    int16_t   dist_err;
    int16_t   ov_time;
    int32_t    info1 ;
    int16_t   alarm_no ;
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
    int32_t    repeat_sub ;
    int32_t    repeat_e_sub ;
    int32_t    info1 ;
    int16_t   number ;
    int16_t   number_sub ;
    int16_t   number_cycle ;
    int16_t   table_kind ;
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
    int32_t    repeat_sub ;
    int32_t    repeat_e_sub ;
    int32_t    srpm ;
    int32_t    rrpm ;
    int32_t    sspm ;
    int32_t    smax ;
    int32_t    info1 ;
    int16_t   number ;
    int16_t   number_sub ;
    int16_t   table_kind ;
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
    int32_t    repeat_sub ;
    int32_t    repeat_e_sub ;
    int32_t    m_code[3] ;
    int32_t    info1 ;
    int16_t   number ;
    int16_t   number_sub ;
    int16_t   table_kind ;
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
    int16_t   number;
} ODBPTHIS_LOG ;

/*--- cnc_rdptcnvinfo2 ---*/
typedef struct odbptcnvinfo2{
	int16_t	executing[2][10] ;
	int32_t	conv_status[2][10] ;
	int16_t	ofs_change[2][10] ;
}ODBPTCNVINFO2 ;

typedef struct odbaxsts_bg {
    int32_t   flag;    
} ODBAXSTS_BG;

/*--- cnc_rdpalaxis ---*/
/* Parallel axis control */
typedef struct iodbpalax{
	int32_t   max_pal ;
	int32_t   data[MAX_AXIS] ;
}IODBPALAX ;

/*--- cnc_hdck_nochange_info ---*/
/*    handle retrace message    */
typedef struct odbahdck {
	int16_t	dat_path ;
	struct {
		int16_t	stat ;
		int16_t	data ;
	} info[MAX_CNCPATH];
} ODBAHDCK;

/*--- cnc_rstrt_rdpntlist ---*/
/* restart point list  */
typedef struct odbrstlist {
	char  prg_name[246];
	char  dummy[2];
	int32_t  seq_no;
	int32_t  c_blck_cnt;
} ODBRSTLIST ;

typedef struct odbrstlist2 {
	char  prg_name[246];
	char  status;
	char  dummy;
	int32_t  seq_no;
	int32_t  wait_m_code;
	int32_t  c_blck_cnt;
	char  time_s;
	char  time_m;
	char  time_h;
	char  time_d;
	int32_t  id_no;
	int32_t  reserve[3];
} ODBRSTLIST2 ;

/*--- cnc_rstrt_rdpnt ---*/
/* restart point info  */
typedef struct iodbrstinfo {
	int32_t  seq_no;
	int32_t  c_blck_cnt;
	int32_t  t_blck_cnt;
	int32_t  call_from_no;
	int32_t  call_from_blck;
	int16_t prg_rep;
	int16_t seq_rep;
	int16_t c_blck_rep;
	int16_t nest_lv;
	char  prg_name[246];
	char  dummy1[2];
	char  call_from_prg[246];
	char  dummy2[2];
	char  edit_flag;
	char  reserve;
	int16_t repeat;
	int32_t  wait_m_code;
} IODBRSTINFO ;

/*--- cnc_rstrt_rdpnt2 ---*/
/* restart point info  */
typedef struct iodbrstinfo2 {
	int32_t  seq_no;
	int32_t  c_blck_cnt;
	int32_t  t_blck_cnt;
	int32_t  call_from_no;
	int32_t  call_from_blck;
	int16_t prg_rep;
	int16_t seq_rep;
	int16_t c_blck_rep;
	int16_t nest_lv;
	char  prg_name[246];
	char  dummy1[2];
	char  call_from_prg[246];
	char  dummy2[2];
	char  edit_flag;
	char  reserve;
	int16_t repeat;
	int32_t  wait_m_code;
	char  time_s;
	char  time_m;
	char  time_h;
	char  time_d;
	int32_t  id_no;
	int32_t  reserve2[3];
} IODBRSTINFO2 ;

/*---cnc_rstrt_rdlpmppnt---*/
/* restart point mpinfo */
typedef struct odbrstmpinfo {
    int32_t    u_block_num;
    int32_t    mltpiece_all;
    int32_t    mltpiece_exe;
    char    u_file_name[246];
}ODBRSTMPINFO ;

/*---------------------*/
/* spindle unit offset */
/*---------------------*/
typedef struct iodbsuofs {
    int32_t		vect_val;	/* vector element */
    int32_t		frc_dgt;   	/* fraction digit */
} ODBSUOVECT ;

typedef struct odbsuodata {
     char  data_name[4]; /* axis name   */
     int32_t  prm_val;      /* parameter value */
     int32_t  frc_dgt;      /* fraction digit */
} ODBSUODATA ;
/*----------------------------*/
/*  Memory card access        */
/*----------------------------*/
/*--- cnc_rdmcdfinfo -------------*/
typedef struct odbfilestatus {
    uint32_T  size;      
    unsigned char  min;       
    unsigned char  hour;      
    unsigned char  day;       
    unsigned char  month;     
    uint16_T year;      
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
	int16_t	        coord_x ;
	int16_t	        coord_y ;
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
	uint16_T	speedsignal;	/* speed signal */
	uint32_T	axisctrldata;	/* data signal */
	uint16_T	subinstnum;		/* subinstruction number */
	uint16_T	subinstlength;	/* data length of subinstruction */
	uint32_T	subinstdata1;	/* subinstruction data 1 */
	uint32_T	subinstdata2;	/* subinstruction data 2 */
	uint32_T	subinstdata3;	/* subinstruction data 3 */
	uint32_T	subinstdata4;	/* subinstruction data 4 */
	uint32_T	subinstdata5;	/* subinstruction data 5 */
	uint32_T	subinstdata6;	/* subinstruction data 6 */
	uint32_T	subinstdata7;	/* subinstruction data 7 */
} ODBPMCAXISINFO;

/*--- cnc_mdd_rdinfo ---*/
/* Modification detection information */
typedef struct odbmddinfo {
    int16_t           status;         /* Modification detection status */
    int16_t           prot;           /* Data protection status */
    int16_t           year;           /* Registered year */
    int16_t           month;          /*            month */
    int16_t           day;            /*            day */
    int16_t           hour;           /*            hour */
    int16_t           min;            /*            minute */
    int16_t           sec;            /*            second */
    uint32_T   reg_code;       /* Check code - registered */
    uint32_T   cur_code;       /* Check code - current */
    int16_t           modulate;       /* C-EXE code modulation status */
} ODBMDDINFO ;

/* Modification detection exception parameter */
typedef struct iodbmddexceptinfo {
    int32_t           sno;            /* Start Parameter Number */
    int32_t           eno;            /* End Parameter Number   */
} IODBMDDEXCEPTPRM ;

/*----------------------------*/
/*  USB Memory access         */
/*----------------------------*/
/*--- cnc_rdusbdevinfo ---*/
/* USB Memory size information */
typedef struct odbusbsize {
    uint32_T    totalsize_h;      /* total size (high) */
    uint32_T    totalsize_l;      /* total size (low)  */
    uint32_T    freesize_h;       /* free size (high)  */
    uint32_T    freesize_l;       /* free size (low)   */
} ODBUSBSIZE;

/*--- cnc_rdusbfilelist ---*/
/* input data */
typedef struct idbusbfile {
    char             path[256];  /* base path              */
    uint32_T    offset;     /* offset                 */
    int16_t            req_num;    /* number of demand files */
    uint16_T   req_attrib; /* attribute              */
    char             sort;       /* sort flag              */
	char             req_comment;/* comment flag           */
	char			 req_total;	 /* file count flag		   */
	char			 dummy;
} IDBUSBFILE;
/* output data */
typedef struct odbusbinfo {
    int16_t           f_num;      /* number of files actually acquired */
    char            next_entry; /* next file entry                   */
    char            dummy;
	uint32_T   total;      /* number of total files             */
} ODBUSBINFO;
/* file information */
typedef struct odbusbfile {
    /* output */
    uint32_T   size;       /* size        */
    uint16_T  attribute;  /* attribute   */
    uint16_T  int32_t_name;  /* information */
    uint16_T  year;       /* time stamp  */
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
    uint16_T   req_attrib; /* attribute              */
    char             sort;       /* sort flag              */
    char             dummy;
} IDBUSBSEARCH;


/*------------------------*/
/* Robot Connect Function */
/*------------------------*/
typedef struct odbrbsignal{
	char type;
	char state;
	uint16_T no;
	char name[76];
}ODBRBSIGNAL;

typedef struct iodbrbsignal2{
    char type;
    char state;
    uint16_T no;
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
	uint16_T address;
}IODBRBTOPSIG;

typedef struct iodbrbpowersig{
	char unit_type;
	char adr_type;
	uint16_T address;
	char bit;
	char reserve[3];
}IODBRBPOWERSIG;

typedef struct iodbrbcomset{
	IODBRBTOPSIG di_top;
	IODBRBTOPSIG do_top;
	IODBRBPOWERSIG power_on;
	uint16_T di_offset; 
	uint16_T do_offset; 
	unsigned char property;
	char reserve[3];
}IODBRBCOMSET;

typedef struct iodbrbsummary{
	char signal_type;
	char reserve;
	uint16_T no;
}IODBRBSUMMARY;

/*--- cnc_rdindexprm -------------------*/
/*--- cnc_wrindexprm -------------------*/
typedef struct iodbindexprm {
    int32_t            ofs_limit;
    int32_t            detect_width;
    uint16_T  jog_clamp[3];
    char            matrix_single;
    unsigned char   torque_ovr;
    char            ofs_adjust;
    char            dummy[3];
} IODBINDEXPRM;
/*--- cnc_rdindexdata ------------------*/
/*--- cnc_wrindexdata ------------------*/
typedef struct iodbindexdat{
    int32_t            pos;
    int32_t            inp_width;
    uint16_T  speed;
    char            f_flg;
    char            dummy;
}IODBINDEXDAT;
/*--- cnc_rdindexofs -------------------*/
/*--- cnc_wrindexofs -------------------*/
/* nothing */
/*--- cnc_rdindexposdata ---------------*/
/*--- cnc_wrindexposdata ---------------*/
typedef struct indexposdat{
    int32_t            min_value;
    int32_t            max_value;
    char            setting;
    char            dummy[3];
} IODBINDEXPOSDAT;
/*--- cnc_rdindexinfo ---------------*/	
typedef struct odbindexinfo{
    uint16_T  mode;
    int16_t           nc_ax;
    int16_t           inpos_point;
    int16_t           ofs_edit_signal;
} ODBINDEXINFO;

/*------------------------*/
/* Chopping Function      */
/*------------------------*/
typedef struct realnum{
	int32_t val;
	int32_t dec;
}REALNUM;

typedef struct odbchopping{
	REALNUM cur_pos;
	REALNUM cur_speed;
	REALNUM real_udp;
	REALNUM real_ldp;
	uint32_T stroke_cnt;
}ODBCHOPPING;

/*---------------------------------------*/
/* Tilted Working Plane Command          */
/*---------------------------------------*/
typedef struct _odbcoord{
    int32_t    orign[3] ;
    int16_t   vec_x[3] ;
    int16_t   vec_y[3] ;
    int16_t   vec_z[3] ;
} ODBCOORD ;

typedef struct idbtwp_euler_fmt{
    double orign[3];
    double i;
    double j;
    double k;
    int32_t   reserve[24];
} IDBTWP_EULER_FMT;

typedef struct idbtwp_rpy_fmt{
    double orign[3];
    double i;
    double j;
    double k;
    int16_t  turn ;
    int16_t  reserve0 ;
    int32_t   reserve[23];
} IDBTWP_RPY_FMT;

typedef struct idbtwp_3p_fmt{
    double p1[3];
    double p2[3];
    double p3[3];
    double sft[3];
    double rot;
    int32_t   reserve[10];
} IDBTWP_3P_FMT;

typedef struct idbtwp_2vct_fmt{
    double orign[3];
    double vtr1[3];
    double vtr2[3];
    int32_t   reserve[18];
} IDBTWP_2VCT_FMT;

typedef struct idbtwp_pjct_fmt{
    double orign[3];
    double i;
    double j;
    double k;
    int32_t   reserve[24];
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
    int16_t   alm_type ;
    int16_t   alm_no ;
} ODBSFSGALM ;

typedef struct odbsfsgalmtime{
    int16_t   year ;
    int16_t   month ;
    int16_t   date ;
    int16_t   hour ;
    int16_t   minute ;
    int16_t   second ;
} ODBSFSGALMTIME ;

typedef struct odbsfsgloginf {
    int16_t           signal_num;
    int16_t           sig_his_period;

    int16_t           sig_his_count;
    int16_t           sig_his_after;

    int16_t           alm_detect_time[3];
    int16_t           dummy;
    ODBSFSGALM      sfsg_alm;
    ODBSFSGALMTIME  sfsg_alm_time;
} ODBSFSGLOGINF ;

typedef struct iodbsfsgsiginf{
    int32_t     unittype;
    int32_t     number;
    int16_t    adr_type;
    int16_t    bit;
} IODBSFSGSIGINF ;

typedef struct odbsfsgsiginfex{
    IODBSFSGSIGINF  sfsg_siginf;
    int16_t           select;
    int16_t           reserve;
} ODBSFSGSIGINFEX ;

typedef struct iodbsfsgsighis {
    int16_t   sno_sig ;
    int16_t   len_sig ;
    int16_t   sno_sig_his ;
    int16_t   len_sig_his ;
    int16_t   extract ;
} IODBSFSGSIGHIS ;

typedef struct odbsfsgsignalnum {
    int16_t   signal_num_default;
    int16_t   signal_num_extract;
} ODBSFSGSIGNALNUM ;

typedef struct iodbsfsgdspstat {
    int16_t   extract;
    int16_t   symbol;
    int16_t   extend;
} IODBSFSGDSPSTAT ;

/* cnc_rd1punchtl_ex  :read punchpress tool data  */
/* cnc_wrldsplc_ex    :write punchpress tool data */
typedef struct iodbpunch1_ex {
    uint16_T  number ;
    uint16_T  attr ;
    union {
        uint16_T  u2data ;
        int16_t           s2data ;
        uint32_T   u4data ;
        int32_t            s4data ;
        uint32_T   u8data[2] ;
    } u ;
    int16_t   decimal ;
    int16_t   reserve ;
} IODBPUNCH1_EX;

/* cnc_rd2punchtl_ex  :read punchpress tool data  */
typedef struct iodbpunch2_ex {
    uint32_T   number ;
    uint16_T  attr ;
    union {
        uint16_T  u2data ;
        int16_t           s2data ;
        uint32_T   u4data ;
        int32_t            s4data ;
        uint32_T   u8data[2] ;
    } u ;
    int16_t   decimal ;
    int16_t   reserve ;
} IODBPUNCH2_EX;

/*---------------------------------------*/
/* Main Menu      */
/*---------------------------------------*/
typedef struct odbmmscrninf {
    uint32_T scrn_id;
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
    int32_t          icn_id;
    int32_t          msg_id;
}IODBMMMCSCRNDEFDAT;

typedef struct iodbmmmcctgrydefdat{
    int32_t          cmsg_id;
}IODBMMMCCTGRYDEFDAT;

/*-----------------------------*/
/*            LASER            */
/*-----------------------------*/
/*------ cnc_rdpscdedge2 ------*/
/*------ cnc_wrpscdedge2 ------*/
typedef struct iodbedge2 {
    int16_t    slct;
    int16_t    power;
    int16_t    freq;
    int16_t    duty;
    int16_t    g_press;
    int16_t    g_kind;
    int32_t     pier_t;
    int32_t     angle;
    int32_t     gap;
    int32_t     r_len;
    int32_t     r_feed;
    int16_t    r_freq;
    int16_t    r_duty;
    char     gap_axis;
    char     angle_dec;
    char     gap_dec;
    char     r_len_dec;
    char     r_feed_dec;
    char     reserve;
    int16_t    pb_power ;
    int16_t    reserves[2];
} IODBEDGE2 ;

/*------ cnc_rdlpscdpwrctl ------*/
/*------ cnc_wrlpscdpwrctl ------*/
typedef struct iodbpwrctl {
    int16_t    slct;
    int16_t    power_min;
    int16_t    pwr_sp_zr;
    int16_t    freq_min;
    int16_t    freq_sp_zr; 
    int16_t    duty_min;   
    int16_t    duty_sp_zr; 
    char     feed_r_dec; 
    char     reserve;    
    int32_t     feed_r;     
    int16_t    ag_press_min ;
    int16_t    ag_press_sp_zr ;
    int16_t    pb_power_min ;
    int16_t    pb_pwr_sp_zr ;
    int16_t    reserves[2] ;
} IODBPWRCTL ;

/*------ cnc_rdldsplc2 ------*/
/*------ cnc_wrldsplc2 ------*/
typedef struct iodbdsplc {
    int16_t   slct;
    int32_t    dsplc;
    int16_t   dsplc_dec;
    char    gap_ix;
    int16_t   reserves[4];
} IODBDSPLC ;

/* cnc_rdlhsstate : read laser high speed state data */
typedef struct odblstate {
    int32_t    cmd_feed;
    int32_t    act_feed;
    int16_t   cmd_power;
    int16_t   cmd_freq;
    int16_t   cmd_duty;
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
    int16_t   pwrofs_set;
    int16_t   pwrofs_coef;
    int16_t   pwrofs_upper;
    int16_t   pwrofs_max;
    int16_t   pwrofs_min;
    int16_t   pwrinofs_coef;
    char    reserve[8];
} ODBLPWOFS ;

/* cnc_wrlswork : white laser work data */
typedef struct idblswork {
    int16_t   slct ;
    int16_t   skeyinf ;
    int16_t   reserve[14] ;
} IDBLSWORK ;

typedef struct odblalmhis {
    uint16_T  s_no;
    uint16_T  e_no;
    struct {
        int16_t   lalm_wrg ;
        int16_t   alm_grp;
        int16_t   alm_wrg_no ;
        int16_t   year ;
        int16_t   month ;
        int16_t   day ;
        int16_t   hour ;
        int16_t   minute ;
        int16_t   second ;
        int16_t   len_msg ;
        char    alm_msg[64] ;
        int16_t   reserve[4] ;
    }alm_his[50] ;
} ODBLALMHIS;

/*--------------------------------*/
/*   PDSA Pulse Input Diag Data   */
/*--------------------------------*/
typedef struct odbplsdata {
	int16_t	pulse_type;		/* Pulse Type */
	int16_t	channel_state;	/* Channel Connect State */
	int16_t	reserve1;		/* reserve */
	int16_t	reserve2;		/* reserve */
	int16_t	alarm[4];		/* Alarm Detail(CH1-4) */
	int16_t	cmd_val[4];		/* Command Value(CH1-4) */
	int16_t	reserve3[4];		/* reserve */
	int32_t	total_val[4];	/* Total Value(CH1-4) */
	int32_t	reserve4[4];	/* reserve */
} ODBPLSDATA;

/* cnc_rduvactpt2 : uv macro pointer */
typedef struct odbuvmcrpt2 {
	char    prog_name[248] ;    
	int32_t    blk_no ;       
	int32_t    uvblk_no ;     
	int32_t    mult_piece_no ;
    int16_t   reserve[2] ;
} ODBUVMCRPT2 ;

typedef struct odbhmprogstat {
    int16_t   run;
    int16_t   disp;
    int16_t   alm_no;
    int16_t   reserve;
    int32_t    prog_no;
    int32_t    block_no;
} ODBHMPROGSTAT ;

/*-----------------------------------*/
/*  Teach Program Input/Output Data  */
/*-----------------------------------*/
typedef struct odbtpaprg {
    /* output */
    int16_t       format_version;		/* Data format version */
    int16_t       func_version;		/* Function set version */
    int32_t        size;				/* Memory usage */
    struct {						/* Creation date */
        int16_t       year;
        int16_t       mon;
        int16_t       day;
        int16_t       hour;
        int16_t       min;
        int16_t       sec;
    } create ;
    struct {						/* Edit date */
        int16_t       year;
        int16_t       mon;
        int16_t       day;
        int16_t       hour;
        int16_t       min;
        int16_t       sec;
    } edit ;
    struct {						/* Conversion date */
        int16_t       year;
        int16_t       mon;
        int16_t       day;
        int16_t       hour;
        int16_t       min;
        int16_t       sec;
    } convert ;
    uint32_T attr;				/* Program attribute */
    char        name_copy[36];		/* Name of copy original */

    char        prg_name[36];		/* Program name */
    char        comment[20];		/* Comment text of program */
    uint32_T axis;				/* Control axis bit (in path) */
    char        out_nc_prg[36];		/* Output NC program name */
    int32_t        reserve[2];
} ODBTPAPRG ;

typedef struct idbtpinfo {
	char			prg_name[36];	/* Program name */
	char			comment[20];	/* Comment text of program */
	uint32_T	axis;			/* Control axis bit (in path) */
	char			out_nc_prg[36];	/* Output NC program name */
	int32_t			reserve[2];
} IDBTPINFO ;

typedef struct tprogeditcmd {
    char cmd_num ;					/* Count of cmd[] */
    char cmd[31] ;					/* Array of available commands */
    char word_num ;					/* Count of word[] */
    char word[31] ;					/* Array of available words */
} ODBTPEDTCMD;

typedef struct tprogcmd {
    int32_t cmd_id ;					/* Kind of edit operation */
									/* Arguments */
    int32_t    integer[4];					/* integer */
    struct {							/* real */
       int32_t val;
       int32_t dec;
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
    int32_t    tcode;
    union {
        struct {
            int32_t    mv_p[8];
        } rapid;
        struct {
            int32_t    mv_p[8];
        } line;
        struct {
            int32_t    mv_p[8];
            int32_t    cnt_p[4];
        } arc;
        struct {
            int32_t    mv_p[8];
            int32_t    ptch;
        } thrd1;
        struct {
            int32_t    mv_p[8];
            int32_t    ptch;
            int32_t    mv_p2[2];
        } thrd2;
        struct {
            int32_t    mv_p[16];
        } dummy_d;
    } data;
    char    dm_type;
    char    cssc_md;
    int32_t    dm_x[3];
    int32_t    dm_y[3];
    int32_t    dm_z[3];
    int32_t    cnt_x[3];
    int32_t    cord[6];
    char    tlchng;
    char    fd_type;
    int32_t    mcode;
    int16_t   dummy4;
    int32_t    cylndr;
    int32_t    aux;
    int32_t    dcode;
    int32_t    smax;
    int32_t    dwell;
    int32_t    fcode;
    int32_t    scode;
    char    nummcd;
    char    fcddec;
    int32_t    shift;
    char    fbsft;
    char    tilt;
} IODBSIMUELM;

/* anm_rdsimuelm2 : move element data with multi M code */
typedef struct iodbsimuelm2 {
    char    type;
    char    rot_w;
    char    type2;
    char    plane;
    int32_t    tcode;
    union {
        struct {
            int32_t    mv_p[8];
        } rapid;
        struct {
            int32_t    mv_p[8];
        } line;
        struct {
            int32_t    mv_p[8];
            int32_t    cnt_p[4];
        } arc;
        struct {
            int32_t    mv_p[8];
            int32_t    ptch;
        } thrd1;
        struct {
            int32_t    mv_p[8];
            int32_t    ptch;
            int32_t    mv_p2[2];
        } thrd2;
        struct {
            int32_t    mv_p[16];
        } dummy_d;
    } data;
    char    dm_type;
    char    cssc_md;
    int32_t    dm_x[3];
    int32_t    dm_y[3];
    int32_t    dm_z[3];
    int32_t    cnt_x[3];
    int32_t    cord[6];
    char    tlchng;
    char    fd_type;
    int32_t    mcode;
    int16_t   dummy4;
    int32_t    cylndr;
    int32_t    aux;
    int32_t    dcode;
    int32_t    smax;
    int32_t    dwell;
    int32_t    fcode;
    int32_t    scode;
    char    nummcd;
    char    fcddec;
    int32_t    shift;
    char    fbsft;
    char    tilt;
    int16_t   dummy6;
    int32_t    mcode2;
    int32_t    mcode3;
    int32_t    mcode4;
    int32_t    mcode5;
    int32_t    reserve[10];
} IODBSIMUELM2;
#endif

/*--- cnc_rdsvgtungstat ---*/

typedef struct odbtunreq {
    struct {
        int16_t status;
        int16_t dummy;
    } stat[MAX_AXIS];
} ODBTUNREQ;

typedef struct obdtunstat {
    struct {
        int16_t status;
        int16_t dummy;
    } stat[MAX_AXIS];
} ODBTUNSTAT;

/*------------------------*/
/* Reducing Cycle Time    */
/*------------------------*/

typedef struct iodbrct_item {
    uint16_T  item_num;
    unsigned char   type ;
             char   axsp_num ;
             char   ptn_num ;
    unsigned char   dummy ;
    uint16_T  attr ;

    struct data_info {
        char    enable ;
        char    dummy2[3] ;
        int32_t    attr2 ;
        union {
            char    bdata ;
            char    cdata ;
            int16_t   idata ;
            int32_t    ldata ;
            REALPRM rdata ;
            char    bdatas[MAX_AXIS] ;
            char    cdatas[MAX_AXIS] ;
            int16_t   idatas[MAX_AXIS] ;
            int32_t    ldatas[MAX_AXIS] ;
            REALPRM rdatas[MAX_AXIS] ;
        } uParam ;
    } ptn[6] ;
} IODBRCT_ITEM;

typedef struct iodbrct_cstmname {
    uint16_T  grp_num;       			/* grp number    */
    uint16_T  dummy;              	/* dummy         */
              char  grp_name[16];       	/* group name    */
              char  ptn_name[3][16];    	/* pattern name  */
} IODBRCT_CSTMNAME;

typedef struct iodbrct_grpptn {
    uint16_T  grp_num;                /* grp number    */
    uint16_T  ptn_num;                /* dummy         */
} IODBRCT_GRPPTN ;

typedef struct odbrct_slctptnname {
    int32_t            sl_ptrn_no ;            /* pattern number */
    int16_t           sl_nm_slct ;            /* name number    */
} ODBRCT_SLCTPTNNAME ;

typedef struct odbpressure {
    int32_t    cmd_val;
    int32_t    feedbak_val;
} ODBPRESSURE;

typedef struct odbexpos {
    double  data;
    int32_t    dec;
    int32_t    digit;
} ODBEXPOS ;

/*------------------------------*/
/* Scroll Waiting Mcode Setting */
/*------------------------------*/
typedef struct iodbwaitmcode {
    int32_t	mcode;                /* scroll wait mcode   */
    int32_t	pathnum;              /* path num            */
} IODBWAITMCODE ;

/*-------------------------*/
/* Smart Adaptive controll */
/*-------------------------*/
typedef struct curoverr {
    uint16_T  current ;
    uint16_T  minmum ;
    uint16_T  maximum ;
    int16_t           dummy ;
} CUROVRR ;
typedef struct curload {
    uint16_T  current ;
    uint16_T  effect ;
    uint16_T  target ;
    uint16_T  irregular ;
    int32_t            dummy ;
} CURLOAD ;
typedef struct curtemp {
    uint16_T  current ;
    uint16_T  start ;
    uint16_T  end ;
    uint16_T  alarm ;
    int32_t            dummy ;
} CURTEMP ;
typedef struct currdtm {
    uint16_T  current ;
    uint16_T  threshold ;
    int32_t            dummy ;
} CURRDTM ;
typedef struct odbsoccur {
    int16_t           mode ;
    int16_t           table ;
    int32_t            dummy ;
    CUROVRR         ovrr ;
    CURLOAD         load ;
    CURTEMP         temp ;
    CURRDTM         rdtm ;
} ODBSOCCUR ;

typedef struct soctlattr {
	int16_t	prm_no ;
	char	type ;
} ODBSOCTLATTR ;

typedef struct soctldat {
	union {
		char	cdata ;
		int16_t	idata ;
		int32_t	ldata ;
		REALPRM	rdata ;
	} u ;
} IODBSOCTLDAT ;

#ifdef _MSC_VER
#pragma pack(pop)
#endif

/* read machine axis position3 */
FWLIBAPI int16_t WINAPI cnc_machine3( uint16_T, int16_t, int16_t, int16_t, ODBAXIS * ) ;

/* read machine axis position3 ex */
FWLIBAPI int16_t WINAPI cnc_machine3_ex(uint16_T, int16_t, int16_t, int16_t, ODBAXIS_EX *) ;

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
FWLIBAPI int16_t WINAPI cnc_actf( uint16_T, ODBACT * ) ;

/* read absolute axis position */
FWLIBAPI int16_t WINAPI cnc_absolute( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read machine axis position */
FWLIBAPI int16_t WINAPI cnc_machine( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read machine axis position(2) */
FWLIBAPI int16_t WINAPI cnc_machine2( uint16_T, int16_t, int16_t, int16_t, ODBAXIS * ) ;

/* read relative axis position */
FWLIBAPI int16_t WINAPI cnc_relative( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read distance to go */
FWLIBAPI int16_t WINAPI cnc_distance( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read distance to go (m) */
FWLIBAPI int16_t WINAPI cnc_distancem( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read skip position */
FWLIBAPI int16_t WINAPI cnc_skip( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read servo delay value */
FWLIBAPI int16_t WINAPI cnc_srvdelay( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read acceleration/deceleration delay value */
FWLIBAPI int16_t WINAPI cnc_accdecdly( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

#ifndef CNC_PPC
/* read all dynamic data */
FWLIBAPI int16_t WINAPI cnc_rddynamic( uint16_T, int16_t, int16_t, ODBDY * ) ;
#endif

/* read all dynamic data */
FWLIBAPI int16_t WINAPI cnc_rddynamic2( uint16_T, int16_t, int16_t, ODBDY2 * ) ;

#ifndef CNC_PPC
/* read all dynamic data (3) */
FWLIBAPI int16_t WINAPI cnc_rddynamic3( uint16_T, int16_t, int16_t, ODBDY3 * ) ;
#endif

/* read all dynamic data (3) */
FWLIBAPI int16_t WINAPI cnc_rddynamic3m( uint16_T, int16_t, int16_t, ODBDY3M * ) ;

/* read actual spindle speed(S) */
FWLIBAPI int16_t WINAPI cnc_acts( uint16_T, ODBACT * ) ;

/* read actual spindle speed(S) (All or spesified) */
FWLIBAPI int16_t WINAPI cnc_acts2( uint16_T, int16_t, ODBACT2 * ) ;

/* set origin / preset relative axis position */
FWLIBAPI int16_t WINAPI cnc_wrrelpos( uint16_T, int16_t, IDBWRR * ) ;

/* preset work coordinate */
FWLIBAPI int16_t WINAPI cnc_prstwkcd( uint16_T, int16_t, IDBWRA * ) ;

/* read manual overlapped motion value */
FWLIBAPI int16_t WINAPI cnc_rdmovrlap( uint16_T, int16_t, int16_t, IODBOVL * ) ;

/* read manual overlapped motion value */
FWLIBAPI int16_t WINAPI cnc_rdmovrlapm( uint16_T, int16_t, int16_t, IODBOVLM * ) ;

/* cancel manual overlapped motion value */
FWLIBAPI int16_t WINAPI cnc_canmovrlap( uint16_T, int16_t ) ;

/* read load information of serial spindle */
FWLIBAPI int16_t WINAPI cnc_rdspload( uint16_T, int16_t, ODBSPN * ) ;

/* read maximum r.p.m. ratio of serial spindle */
FWLIBAPI int16_t WINAPI cnc_rdspmaxrpm( uint16_T, int16_t, ODBSPN * ) ;

/* read gear ratio of serial spindle */
FWLIBAPI int16_t WINAPI cnc_rdspgear( uint16_T, int16_t, ODBSPN * ) ;

/* read absolute axis position 2 */
FWLIBAPI int16_t WINAPI cnc_absolute2( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read relative axis position 2 */
FWLIBAPI int16_t WINAPI cnc_relative2( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read distance to go 2 */
 FWLIBAPI int16_t WINAPI cnc_distance2( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* set wire vertival position */
FWLIBAPI int16_t WINAPI cnc_setvrtclpos( uint16_T, int16_t );

/* set wire threading position */
FWLIBAPI int16_t WINAPI cnc_setthrdngpos( uint16_T );

/* read tool position */
FWLIBAPI int16_t WINAPI cnc_rdposition( uint16_T, int16_t, int16_t *, ODBPOS * );

/* read current speed */
FWLIBAPI int16_t WINAPI cnc_rdspeed( uint16_T, int16_t, ODBSPEED * );

/* read servo load meter */
FWLIBAPI int16_t WINAPI cnc_rdsvmeter( uint16_T, int16_t *, ODBSVLOAD * );

/* read spindle load meter */
FWLIBAPI int16_t WINAPI cnc_rdspmeter( uint16_T, int16_t, int16_t *, ODBSPLOAD * );

/* read handle interruption */
FWLIBAPI int16_t WINAPI cnc_rdhndintrpt( uint16_T, int16_t, int16_t *, ODBHND * );

/* read manual feed for 5-axis machining */
FWLIBAPI int16_t WINAPI cnc_rd5axmandt( uint16_T, ODB5AXMAN * );

/* read amount of machine axes movement of manual feed for 5-axis machining */
FWLIBAPI int16_t WINAPI cnc_rd5axovrlap( uint16_T, int16_t, int16_t, ODBAXIS * );

/* clear pulse values of manual feed for 5-axis machining */
FWLIBAPI int16_t WINAPI cnc_clr5axpls( uint16_T, int16_t );

/* read constant surface speed */
FWLIBAPI int16_t WINAPI cnc_rdspcss( uint16_T, ODBCSS * );

#ifndef CNC_PPC
/* read execution program pointer */
FWLIBAPI int16_t WINAPI cnc_rdexecpt( uint16_T, PRGPNT *, PRGPNT *) ;

/* read execution program pointer(m) */
FWLIBAPI int16_t WINAPI cnc_rdexecptm( uint16_T, PRGPNT *, PRGPNT *) ;

/* read execution program number */
FWLIBAPI int16_t WINAPI cnc_rdexecprgnum( uint16_T, int32_t * ) ;
#endif

/* read displayed jog or dryrun feedrate */
FWLIBAPI int16_t WINAPI cnc_rdjogdrun( uint16_T, int16_t, ODBJOGDRUN * );

/* set floating reference point */
FWLIBAPI int16_t WINAPI cnc_setfrp( uint16_T, int16_t );

/* read various axis data */
FWLIBAPI int16_t WINAPI cnc_rdaxisdata( uint16_T, int16_t, int16_t *, int16_t, int16_t *, ODBAXDT * );

/* cnc_simulation:read data for machining sumilartion */
FWLIBAPI int16_t WINAPI cnc_simulation( uint16_T, int16_t, int16_t, ODBSIML * );

#ifndef CNC_PPC
/* read sirial spindle speed */
FWLIBAPI int16_t WINAPI cnc_rdspdlspeed( uint16_T, int16_t, int16_t, int32_t * );
#endif

/* cnc_rdposfig:read position and decimal figure */
FWLIBAPI int16_t WINAPI cnc_rdposfig( uint16_T, int16_t, int16_t, int16_t *, ODBPOSFIG * );

/* get active spindle no */
FWLIBAPI int16_t WINAPI cnc_rdactspdl(uint16_T, int16_t *, int16_t * );

/*----------------------*/
/* CNC: Program related */
/*----------------------*/

/* start downloading NC program */
FWLIBAPI int16_t WINAPI cnc_dwnstart( uint16_T ) ;

/* download NC program */
FWLIBAPI int16_t WINAPI cnc_download( uint16_T, char *, int16_t ) ;

/* download NC program(conditional) */
FWLIBAPI int16_t WINAPI cnc_cdownload( uint16_T, char *, int16_t ) ;

/* end of downloading NC program */
FWLIBAPI int16_t WINAPI cnc_dwnend( uint16_T ) ;

/* end of downloading NC program 2 */
FWLIBAPI int16_t WINAPI cnc_dwnend2( uint16_T, char * ) ;

/* start downloading NC program 3 */
FWLIBAPI int16_t WINAPI cnc_dwnstart3( uint16_T, int16_t ) ;

/* start downloading NC program 3 special */
FWLIBAPI int16_t WINAPI cnc_dwnstart3_f( uint16_T, int16_t, char *, char * ) ;

/* download NC program 3 */
FWLIBAPI int16_t WINAPI cnc_download3( uint16_T, int32_t *, char * ) ;

/* end of downloading NC program 3 */
FWLIBAPI int16_t WINAPI cnc_dwnend3( uint16_T ) ;

#ifndef CNC_PPC
/* start downloading NC program 3m */
FWLIBAPI int16_t WINAPI cnc_dwnstart3m( uint16_T, int16_t, int32_t ) ;

/* download NC program 3m */
FWLIBAPI int16_t WINAPI cnc_download3m( uint16_T, int32_t *, char * ) ;

/* end of downloading NC program 3m */
FWLIBAPI int16_t WINAPI cnc_dwnend3m( uint16_T, int16_t ) ;
#endif

/* start downloading NC program 4 */
FWLIBAPI int16_t WINAPI cnc_dwnstart4( uint16_T, int16_t, char * ) ;

/* download NC program 4 */
FWLIBAPI int16_t WINAPI cnc_download4( uint16_T, int32_t *, char * ) ;

/* end of downloading NC program 4 */
FWLIBAPI int16_t WINAPI cnc_dwnend4( uint16_T ) ;

/* start reading file to PC */
FWLIBAPI int16_t WINAPI cnc_fileread_start( uint16_T, int16_t, char * ) ;

/* read file to PC */
FWLIBAPI int16_t WINAPI cnc_fileread( uint16_T, int32_t * , char * ) ;

/* end of reading file to PC */
FWLIBAPI int16_t WINAPI cnc_fileread_end( uint16_T ) ;

/* start writing file from PC */
FWLIBAPI int16_t WINAPI cnc_filewrite_start( uint16_T, int16_t, char * , int16_t ) ;

/* write file from PC */
FWLIBAPI int16_t WINAPI cnc_filewrite( uint16_T, int32_t * , char * ) ;

/* end of writing file from PC */
FWLIBAPI int16_t WINAPI cnc_filewrite_end( uint16_T ) ;

/* start verification of NC program */
FWLIBAPI int16_t WINAPI cnc_vrfstart( uint16_T ) ;

/* verify NC program */
FWLIBAPI int16_t WINAPI cnc_verify( uint16_T, char *, int16_t ) ;

/* verify NC program(conditional) */
FWLIBAPI int16_t WINAPI cnc_cverify( uint16_T, char *, int16_t ) ;

/* end of verification */
FWLIBAPI int16_t WINAPI cnc_vrfend( uint16_T ) ;

/* start verification of NC program */
FWLIBAPI int16_t WINAPI cnc_vrfstart4(uint16_T, char*);

/* verify NC program */
FWLIBAPI int16_t WINAPI cnc_verify4( uint16_T, int32_t *length, char *data ) ;

/* end of verification */
FWLIBAPI int16_t WINAPI cnc_vrfend4( uint16_T ) ;

/* start downloading DNC program */
FWLIBAPI int16_t WINAPI cnc_dncstart( uint16_T ) ;

/* download DNC program */
#if defined (HSSB_LIB)
#if defined (FS15D) || defined (FS15BD)
FWLIBAPI int16_t WINAPI cnc_dnc( uint16_T, char *, int16_t ) ;
#else
FWLIBAPI int16_t WINAPI cnc_dnc( uint16_T, char *, uint16_T ) ;
#endif
#else
FWLIBAPI int16_t WINAPI cnc_dnc( uint16_T, char *, uint16_T ) ;
#endif

/* download DNC program(conditional) */
#if defined (HSSB_LIB)
#if defined (FS15D) || defined (FS15BD)
FWLIBAPI int16_t WINAPI cnc_cdnc( uint16_T, char *, int16_t ) ;
#else
FWLIBAPI int16_t WINAPI cnc_cdnc( uint16_T, char *, uint16_T ) ;
#endif
#else
FWLIBAPI int16_t WINAPI cnc_cdnc( uint16_T, char *, uint16_T ) ;
#endif

/* end of downloading DNC program */
FWLIBAPI int16_t WINAPI cnc_dncend( uint16_T ) ;

/* start downloading DNC program 2 */
FWLIBAPI int16_t WINAPI cnc_dncstart2( uint16_T, char * ) ;

/* download DNC program 2 */
FWLIBAPI int16_t WINAPI cnc_dnc2( uint16_T, int32_t *, char * ) ;

/* end of downloading DNC program 2 */
FWLIBAPI int16_t WINAPI cnc_dncend2( uint16_T, int16_t ) ;

/* read the diagnosis data of DNC operation */
FWLIBAPI int16_t WINAPI cnc_rddncdgndt( uint16_T, ODBDNCDGN * ) ;

/* read the diagnosis data of DNC operation 2 */
FWLIBAPI int16_t WINAPI cnc_rddncdgndt2( uint16_T, ODBDNCDGN2 * ) ;

/* start uploading NC program */
FWLIBAPI int16_t WINAPI cnc_upstart( uint16_T, int16_t ) ;

/* upload NC program */
FWLIBAPI int16_t WINAPI cnc_upload( uint16_T, ODBUP *, uint16_T * ) ;

/* upload NC program(conditional) */
FWLIBAPI int16_t WINAPI cnc_cupload( uint16_T, ODBUP *, uint16_T * ) ;

/* end of uploading NC program */
FWLIBAPI int16_t WINAPI cnc_upend( uint16_T ) ;

/* start uploading NC program 3 */
FWLIBAPI int16_t WINAPI cnc_upstart3( uint16_T, int16_t, int32_t, int32_t ) ;

/* start uploading NC program special 3 */
FWLIBAPI int16_t WINAPI cnc_upstart3_f( uint16_T, int16_t, char *, char * ) ;

/* upload NC program 3 */
FWLIBAPI int16_t WINAPI cnc_upload3( uint16_T, int32_t *, char * ) ;

/* end of uploading NC program 3 */
FWLIBAPI int16_t WINAPI cnc_upend3( uint16_T ) ;

/* start uploading NC program 4 */
FWLIBAPI int16_t WINAPI cnc_upstart4( uint16_T, int16_t, char * ) ;

/* upload NC program 4 */
FWLIBAPI int16_t WINAPI cnc_upload4( uint16_T, int32_t *, char * ) ;

/* end of uploading NC program 4 */
FWLIBAPI int16_t WINAPI cnc_upend4( uint16_T ) ;

/* maintenance data write F-ROM */
FWLIBAPI int16_t WINAPI cnc_save_maint( uint16_T );

/* maintenance data clear F-ROM */
FWLIBAPI int16_t WINAPI cnc_clear_maint( uint16_T );

/* read buffer status for downloading/verification NC program */
FWLIBAPI int16_t WINAPI cnc_buff( uint16_T, ODBBUF * ) ;

/* search specified program */
FWLIBAPI int16_t WINAPI cnc_search( uint16_T, int16_t ) ;

#ifndef CNC_PPC
/* search specified program (2) */
FWLIBAPI int16_t WINAPI cnc_search2( uint16_T, int32_t ) ;
#endif

/* delete all programs */
FWLIBAPI int16_t WINAPI cnc_delall( uint16_T ) ;

/* delete all programs */
FWLIBAPI int16_t WINAPI cnc_pdf_delall( uint16_T, int16_t, char * ) ;

/* delete specified program */
FWLIBAPI int16_t WINAPI cnc_delete( uint16_T, int16_t ) ;

/* delete program (area specified) */
 FWLIBAPI int16_t WINAPI cnc_delrange( uint16_T, int32_t, int32_t ) ;

#ifndef CNC_PPC
/* read program directory */
FWLIBAPI int16_t WINAPI cnc_rdprogdir( uint16_T, int16_t, int16_t, int16_t, uint16_T, PRGDIR * ) ;
#endif

/* read program information */
FWLIBAPI int16_t WINAPI cnc_rdproginfo( uint16_T, int16_t, int16_t, ODBNC * ) ;

/* read program number under execution */
FWLIBAPI int16_t WINAPI cnc_rdprgnum( uint16_T, ODBPRO * ) ;

/* read program name under execution */
FWLIBAPI int16_t WINAPI cnc_exeprgname( uint16_T, ODBEXEPRG * ) ;

/* read program name under execution (Full path) */
FWLIBAPI int16_t WINAPI cnc_exeprgname2( uint16_T, char * ) ;

/* read program name under background execution */
FWLIBAPI int16_t WINAPI cnc_exeprgname_bg( uint16_T, ODBEXEPRG * ) ;

/* read program name of DNC operation */
FWLIBAPI int16_t WINAPI cnc_dncprgname( uint16_T, ODBDNCPRG * ) ;

/* read sequence number under execution */
FWLIBAPI int16_t WINAPI cnc_rdseqnum( uint16_T, ODBSEQ * ) ;

/* search specified sequence number */
FWLIBAPI int16_t WINAPI cnc_seqsrch( uint16_T, int32_t ) ;

/* search specified sequence number (2) */
 FWLIBAPI int16_t WINAPI cnc_seqsrch2( uint16_T, int32_t ) ;

/* rewind cursor of NC program */
FWLIBAPI int16_t WINAPI cnc_rewind( uint16_T ) ;

/* read block counter */
FWLIBAPI int16_t WINAPI cnc_rdblkcount( uint16_T, int32_t * ) ;

/* read program under execution */
FWLIBAPI int16_t WINAPI cnc_rdexecprog( uint16_T, uint16_T *, int16_t *, char * ) ;
FWLIBAPI int16_t WINAPI cnc_rdexecprog2(uint16_T, uint16_T *, int16_t *, int16_t *, char *) ;
FWLIBAPI int16_t WINAPI cnc_rdexecprog3(uint16_T, int16_t *, ODBEXEPRGINFO *) ;

/* read program for MDI operation */
FWLIBAPI int16_t WINAPI cnc_rdmdiprog( uint16_T, int16_t *, char * ) ;

/* write program for MDI operation */
FWLIBAPI int16_t WINAPI cnc_wrmdiprog( uint16_T, int16_t, char * ) ;

/* read execution pointer for MDI operation */
FWLIBAPI int16_t WINAPI cnc_rdmdipntr( uint16_T, ODBMDIP * ) ;

/* write execution pointer for MDI operation */
FWLIBAPI int16_t WINAPI cnc_wrmdipntr( uint16_T, int32_t ) ;

#ifndef CNC_PPC
/* register new program */
FWLIBAPI int16_t WINAPI cnc_newprog( uint16_T, int32_t );

/* copy program */
FWLIBAPI int16_t WINAPI cnc_copyprog( uint16_T, int32_t, int32_t );

/* rename program */
FWLIBAPI int16_t WINAPI cnc_renameprog( uint16_T, int32_t, int32_t );

/* condense program */
FWLIBAPI int16_t WINAPI cnc_condense( uint16_T, int16_t, int32_t );
#endif

/* merge program */
FWLIBAPI int16_t WINAPI cnc_mergeprog( uint16_T, int16_t, int32_t, uint32_T, int32_t );

/* read current program and its pointer */
#ifndef CNC_PPC
FWLIBAPI int16_t WINAPI cnc_rdactpt( uint16_T, int32_t * , int32_t * );
#endif
FWLIBAPI int16_t WINAPI cnc_pdf_rdactpt( uint16_T, char * , int32_t * ) ;
FWLIBAPI int16_t WINAPI cnc_pdf_rdprgname( uint16_T, char *  ) ;
FWLIBAPI int16_t WINAPI cnc_pdf_rdactpt_bgedt( uint16_T, char * , int32_t * ) ;
FWLIBAPI int16_t WINAPI cnc_pdf_rdmainpt( uint16_T, char * , int32_t * ) ;

/* read all nest program */
FWLIBAPI int16_t WINAPI cnc_pdf_rdcallstack( uint16_T, uint16_T, int16_t * , ODBNESTPDF * ) ;

/* select act pointer kind */
FWLIBAPI int16_t WINAPI cnc_setactptopt( uint16_T, int32_t );

/* read current program and its pointer and UV macro pointer */
 FWLIBAPI int16_t WINAPI cnc_rduvactpt( uint16_T, int32_t * , int32_t *, int32_t * );

/* set current program and its pointer */
#ifndef CNC_PPC
FWLIBAPI int16_t WINAPI cnc_wractpt( uint16_T, int32_t, int16_t, int32_t * );
#endif
FWLIBAPI int16_t WINAPI cnc_pdf_wractpt( uint16_T, char * , int16_t, int32_t * ) ;
FWLIBAPI int16_t WINAPI cnc_pdf_wractpt_bgedt( uint16_T, char * , int16_t, int32_t * ) ;

#ifndef CNC_PPC
/* line edit (read program) */
FWLIBAPI int16_t WINAPI cnc_rdprogline( uint16_T, int32_t, uint32_T, char *, uint32_T *, uint32_T * );
FWLIBAPI int16_t WINAPI cnc_rdprogline2( uint16_T, int32_t, uint32_T, char *, uint32_T *, uint32_T * );
FWLIBAPI int16_t WINAPI cnc_rdprogdata( uint16_T, int32_t, uint32_T, char *, uint32_T *, uint32_T * );

/* line edit (write program) */
FWLIBAPI int16_t WINAPI cnc_wrprogline( uint16_T, int32_t, uint32_T, char *, uint32_T );

/* line edit (delete line in program) */
FWLIBAPI int16_t WINAPI cnc_delprogline( uint16_T, int32_t, uint32_T, uint32_T );

/* line edit (search string) */
FWLIBAPI int16_t WINAPI cnc_searchword( uint16_T, int32_t, uint32_T, int16_t, int16_t, uint32_T, char * );
#endif

FWLIBAPI int16_t WINAPI cnc_searchword2( uint16_T, int32_t, uint32_T, int16_t, int16_t, uint32_T, char * );
FWLIBAPI int16_t WINAPI cnc_pdf_searchword( uint16_T, char *, uint32_T, uint32_T, uint32_T, uint32_T, char * );
FWLIBAPI int16_t WINAPI cnc_pdf_searchword2( uint16_T, char *, uint32_T, uint32_T, uint32_T, uint32_T, char * );
FWLIBAPI int16_t WINAPI cnc_pdf_searchword_bgedt( uint16_T, char *, uint32_T, uint32_T, uint32_T, uint32_T, char * );

/* line edit (search string in Data Server) */
FWLIBAPI int16_t WINAPI cnc_pdf_dssearch( uint16_T, char *, uint32_T, uint32_T, uint32_T, uint32_T, char *,int16_t );

/* line edit (search string) */
#ifndef CNC_PPC
FWLIBAPI int16_t WINAPI cnc_searchresult( uint16_T, uint32_T * );
#endif
FWLIBAPI int16_t WINAPI cnc_searchresult2( uint16_T, uint32_T * );
FWLIBAPI int16_t WINAPI cnc_pdf_searchresult( uint16_T, uint32_T * );
FWLIBAPI int16_t WINAPI cnc_pdf_searchresult2( uint16_T, uint32_T * );
FWLIBAPI int16_t WINAPI cnc_pdf_searchresult_bgedt( uint16_T, uint32_T * );

/* replace all words */
FWLIBAPI int16_t WINAPI cnc_pdf_replaceword_all( uint16_T, char *, uint32_T, uint32_T, uint32_T, char *, char * );

/* set program lock */
FWLIBAPI int16_t WINAPI cnc_setpglock( uint16_T, int32_t );
FWLIBAPI int16_t WINAPI cnc_setpdf_pglock( uint16_T, char * );

/* reset program lock */
FWLIBAPI int16_t WINAPI cnc_resetpglock( uint16_T, int32_t );
FWLIBAPI int16_t WINAPI cnc_resetpdf_pglock( uint16_T, char * );

/* read program lock status */
FWLIBAPI int16_t WINAPI cnc_rdpglockstat( uint16_T, int32_t *, int32_t * );
FWLIBAPI int16_t WINAPI cnc_rdpdf_pglockstat( uint16_T, int32_t *, ODBPRGNAME * );

/* program sum data */
FWLIBAPI int16_t WINAPI cnc_setsumdt(uint16_T, int16_t, char *);

/* line edit (read program by file name) */
FWLIBAPI int16_t WINAPI cnc_rdpdf_line( uint16_T, char *, uint32_T, char *, uint32_T *, uint32_T * );
FWLIBAPI int16_t WINAPI cnc_rdpdf_line2( uint16_T, char *, uint32_T, char *, uint32_T *, uint32_T * );
FWLIBAPI int16_t WINAPI cnc_rdpdf_line_bgedt( uint16_T, char *, uint32_T, char *, uint32_T *, uint32_T * );
FWLIBAPI int16_t WINAPI cnc_rdpdf_execline( uint16_T, char *, uint32_T, char *, uint32_T *, uint32_T * );

/* line edit (write program by file name) */
FWLIBAPI int16_t WINAPI cnc_wrpdf_line( uint16_T, char *, uint32_T, char *, uint32_T );

/* line edit (delete line by file name) */
FWLIBAPI int16_t WINAPI cnc_pdf_delline( uint16_T, char *, uint32_T, uint32_T );

/* chara edit (write program by file name)	 */
FWLIBAPI int16_t WINAPI cnc_wrpdf_char( uint16_T, char *, uint32_T, uint32_T, char *, uint32_T );

/* char edit (delete character by file name) */
FWLIBAPI int16_t WINAPI cnc_pdf_delchar( uint16_T, char *, uint32_T, uint32_T, uint32_T );

/* char edit (replace character by file name)*/
FWLIBAPI int16_t WINAPI cnc_pdf_replacechar(uint16_T, char *, uint32_T, uint32_T, uint32_T, char *, uint32_T );

/* read program drive directory */
FWLIBAPI int16_t WINAPI cnc_rdpdf_drive( uint16_T, ODBPDFDRV * );

/* read program drive information */
FWLIBAPI int16_t WINAPI cnc_rdpdf_inf( uint16_T, char *, int16_t, ODBPDFINF * );

/* read current directory */
FWLIBAPI int16_t WINAPI cnc_rdpdf_curdir( uint16_T, int16_t, char * );

/* set current directory */
FWLIBAPI int16_t WINAPI cnc_wrpdf_curdir( uint16_T, int16_t, char * );

/* read directory (sub directories) */
FWLIBAPI int16_t WINAPI cnc_rdpdf_subdir( uint16_T, int16_t *, IDBPDFSDIR *, ODBPDFSDIR * );

/* read directory (all files) */
FWLIBAPI int16_t WINAPI cnc_rdpdf_alldir( uint16_T, int16_t *, IDBPDFADIR *, ODBPDFADIR * );

/* read file */
FWLIBAPI int16_t WINAPI cnc_rdpdf_prginf( uint16_T, IDBPDFPRG *, ODBPDFPRG * );

/* read protect*/
FWLIBAPI int16_t WINAPI cnc_rdprotect(uint16_T FlibHndl,int16_t type, char *path, ODBPRTCT *prtct);

/* read protect*/
FWLIBAPI int16_t WINAPI cnc_rdprotect2(uint16_T FlibHndl,int16_t type, char *path, ODBPRTCT2 *prtct);

/* read file count in directory */
FWLIBAPI int16_t WINAPI cnc_rdpdf_subdirn( uint16_T, char *, ODBPDFNFIL * );

/* create file or directory */
FWLIBAPI int16_t WINAPI cnc_pdf_add( uint16_T, char * );
FWLIBAPI int16_t WINAPI cnc_pdf_add_bgedt( uint16_T, char * );

/* delete file or directory */
FWLIBAPI int16_t WINAPI cnc_pdf_del( uint16_T, char * );

/* rename file or directory */
FWLIBAPI int16_t WINAPI cnc_pdf_rename( uint16_T, char *, char * );

/* read selected file name */
FWLIBAPI int16_t WINAPI cnc_pdf_rdmain( uint16_T, char * );

/* select program file */
FWLIBAPI int16_t WINAPI cnc_pdf_slctmain( uint16_T, char * );

/* condense program file */
FWLIBAPI int16_t WINAPI cnc_pdf_cond( uint16_T, char * );

/* change attribute of program file and directory */
FWLIBAPI int16_t WINAPI cnc_wrpdf_attr( uint16_T, char *, IDBPDFTDIR * );

/* copy program file */
FWLIBAPI int16_t WINAPI cnc_pdf_copy( uint16_T, char *, char * );

/* move program file */
FWLIBAPI int16_t WINAPI cnc_pdf_move( uint16_T, char *, char * );

/* copy or move programs/folders asynchronously*/
FWLIBAPI int16_t WINAPI cnc_pdf_cpmv_start(uint16_T, int16_t, char *, char *, int16_t);
FWLIBAPI int16_t WINAPI cnc_pdf_cpmv_poll(uint16_T, int16_t *, char *);
FWLIBAPI int16_t WINAPI cnc_pdf_cpmv_end(uint16_T);
FWLIBAPI int16_t WINAPI cnc_pdf_cpmv_restart(uint16_T, int16_t);

/* copy or move any files/folders asynchronously*/
FWLIBAPI int16_t WINAPI cnc_file_cpmv_start(uint16_T, int16_t, char *, char *, uint16_T);
FWLIBAPI int16_t WINAPI cnc_file_cpmv_poll(uint16_T, int16_t *, char *);
FWLIBAPI int16_t WINAPI cnc_file_cpmv_end(uint16_T);
FWLIBAPI int16_t WINAPI cnc_file_cpmv_restart(uint16_T, int16_t);

/* punch program */
FWLIBAPI int16_t WINAPI cnc_punch_prog(uint16_T ,int32_t );
FWLIBAPI int16_t WINAPI cnc_punch_prog2(uint16_T ,int32_t, char * );
FWLIBAPI int16_t WINAPI cnc_punch_prog3(uint16_T ,char *, char * );
FWLIBAPI int16_t WINAPI cnc_punch_prog_bg(uint16_T ,int32_t );
FWLIBAPI int16_t WINAPI cnc_punch_prog2_bg(uint16_T ,int32_t, char * );
FWLIBAPI int16_t WINAPI cnc_punch_prog3_bg(uint16_T ,char *, char * );
FWLIBAPI int16_t WINAPI cnc_start_async_punch_prog3( uint16_T, char *, char * );
FWLIBAPI int16_t WINAPI cnc_end_async_punch_prog3( uint16_T, char *, int16_t * );
FWLIBAPI int16_t WINAPI cnc_start_async_punch_prog3_bg( uint16_T, char *, char * );
FWLIBAPI int16_t WINAPI cnc_end_async_punch_prog3_bg( uint16_T, char *, int16_t * );
FWLIBAPI int16_t WINAPI cnc_pdf_punch(uint16_T, int32_t, char *, char * );
FWLIBAPI int16_t WINAPI cnc_pdf_punch_bg(uint16_T, int32_t, char *, char * );
FWLIBAPI int16_t WINAPI cnc_start_async_pdf_punch( uint16_T, int32_t, char *, char * ) ;
FWLIBAPI int16_t WINAPI cnc_end_async_pdf_punch( uint16_T, int16_t * ) ;

/* read program */
FWLIBAPI int16_t WINAPI cnc_read_prog(uint16_T ,int32_t );
FWLIBAPI int16_t WINAPI cnc_read_prog2(uint16_T ,int32_t, char * );
FWLIBAPI int16_t WINAPI cnc_read_prog3(uint16_T ,char *, char * );
FWLIBAPI int16_t WINAPI cnc_read_prog_bg(uint16_T ,int32_t, char * );
FWLIBAPI int16_t WINAPI cnc_read_prog2_bg(uint16_T ,int32_t, char *, char * );
FWLIBAPI int16_t WINAPI cnc_read_prog3_bg(uint16_T ,char *, char *, char * );
FWLIBAPI int16_t WINAPI cnc_start_async_read_prog3( uint16_T, char *, char * );
FWLIBAPI int16_t WINAPI cnc_end_async_read_prog3( uint16_T, char *, int16_t * );
FWLIBAPI int16_t WINAPI cnc_start_async_read_prog3_bg( uint16_T, char *, char * );
FWLIBAPI int16_t WINAPI cnc_end_async_read_prog3_bg( uint16_T, char *, char *, int16_t * );
FWLIBAPI int16_t WINAPI cnc_pdf_read(uint16_T, char *, char * );
FWLIBAPI int16_t WINAPI cnc_pdf_read_bg(uint16_T, char *, char * );
FWLIBAPI int16_t WINAPI cnc_start_async_pdf_read( uint16_T, char *, char * ) ;
FWLIBAPI int16_t WINAPI cnc_end_async_pdf_read( uint16_T, int16_t * ) ;
FWLIBAPI int16_t WINAPI cnc_pdf_read_start(uint16_T, int16_t, char *, char *, int16_t) ;
FWLIBAPI int16_t WINAPI cnc_pdf_read_poll(uint16_T, int16_t *, char *, char *) ;
FWLIBAPI int16_t WINAPI cnc_pdf_read_end(uint16_T) ;
FWLIBAPI int16_t WINAPI cnc_pdf_read_restart(uint16_T, int16_t, char *) ;
/* Stop Read/Punch Program   */
FWLIBAPI int16_t WINAPI cnc_stop_async_read_punch(uint16_T h);

/* verify program */
FWLIBAPI int16_t WINAPI cnc_verify_prog(uint16_T, char *, char * );
FWLIBAPI int16_t WINAPI cnc_verify_prog_bg(uint16_T, char *, char * );

/* punch/read data */
FWLIBAPI int16_t WINAPI cnc_punch_data(uint16_T , int16_t, char *);
FWLIBAPI int16_t WINAPI cnc_read_data(uint16_T , int16_t, char *);
FWLIBAPI int16_t WINAPI cnc_punch_data_start( uint16_T, int16_t, uint32_T, uint32_T, char * );
FWLIBAPI int16_t WINAPI cnc_punch_data_end( uint16_T, uint32_T *, uint32_T *, int16_t * );

FWLIBAPI int16_t WINAPI cnc_start_async_data_punch(uint16_T , int16_t , char *);
FWLIBAPI int16_t WINAPI cnc_end_async_data_punch(uint16_T , int16_t , int16_t *);
FWLIBAPI int16_t WINAPI cnc_start_async_data_read(uint16_T , int16_t , char *);
FWLIBAPI int16_t WINAPI cnc_end_async_data_read(uint16_T , int16_t , int16_t *);

/* memory card program */
FWLIBAPI int16_t WINAPI cnc_mcdp_unmount(uint16_T);
FWLIBAPI int16_t WINAPI cnc_mcdp_mountchk(uint16_T, char *);
FWLIBAPI int16_t WINAPI cnc_mcdp_mount(uint16_T);
FWLIBAPI int16_t WINAPI cnc_mcdp_update_entry(uint16_T, int32_t);
FWLIBAPI int16_t WINAPI cnc_mcdp_wractpt(uint16_T, char *, int32_t, uint32_T *);

/* cnc_rdactpt_w:read execution pointer of program for FS160is/180is-WB */
FWLIBAPI int16_t WINAPI cnc_rdactpt_w( uint16_T, int16_t, ODBACTPTW * );

/* cnc_wractpt_w:set execution pointer of program for FS160is/180is-WB */
FWLIBAPI int16_t WINAPI cnc_wractpt_w( uint16_T, int16_t, int32_t );

/* set dnc file name */
FWLIBAPI int16_t WINAPI cnc_pdf_dncset( uint16_T, char * );

/* set dnc file name */
FWLIBAPI int16_t WINAPI cnc_pdf_dncset2( uint16_T, char * ,uint16_T );

/* read dnc file name */
FWLIBAPI int16_t WINAPI cnc_pdf_dncread( uint16_T, char * );

/* merge program */
FWLIBAPI int16_t WINAPI cnc_pdf_mergeprog(uint16_T, int16_t, char *, uint32_T, uint32_T, char *);

/* read embedded folder information */
FWLIBAPI int16_t WINAPI cnc_rdembedf_inf( uint16_T, char *, int16_t, ODBEMBEDFINF * );

/* for program reference mode */
FWLIBAPI int16_t WINAPI cnc_setpdf_pglockexec( uint16_T, char * );

/* get system folder number */
FWLIBAPI int16_t WINAPI cnc_getsysfolder_num( uint16_T, int16_t * );

/* get execution macro running status */
FWLIBAPI int16_t WINAPI cnc_getexemacstat( uint16_T, int16_t * );

/* release main program file */
FWLIBAPI int16_t WINAPI cnc_pdf_relsmain(uint16_T);

/*---------------------------*/
/* CNC: NC file data related */
/*---------------------------*/

/* read tool offset value */
FWLIBAPI int16_t WINAPI cnc_rdtofs( uint16_T, int16_t, int16_t, int16_t, ODBTOFS * ) ;

/* write tool offset value */
FWLIBAPI int16_t WINAPI cnc_wrtofs( uint16_T, int16_t, int16_t, int16_t, int32_t ) ;

/* read tool offset value(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdtofsr( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBTO * ) ;

/* write tool offset value(area specified) */
FWLIBAPI int16_t WINAPI cnc_wrtofsr( uint16_T, int16_t, IODBTO * ) ;

/* clear tool offset value(all data) */
FWLIBAPI int16_t WINAPI cnc_clrtofs( uint16_T , int16_t );

/* read work zero offset value */
FWLIBAPI int16_t WINAPI cnc_rdzofs( uint16_T, int16_t, int16_t, int16_t, IODBZOFS * ) ;

/* write work zero offset value */
FWLIBAPI int16_t WINAPI cnc_wrzofs( uint16_T, int16_t, IODBZOFS * ) ;

/* read work zero offset value(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdzofsr( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBZOR * ) ;

/* write work zero offset value(area specified) */
FWLIBAPI int16_t WINAPI cnc_wrzofsr( uint16_T, int16_t, IODBZOR * ) ;

/* read mesured point value */
FWLIBAPI int16_t WINAPI cnc_rdmsptype( uint16_T, int16_t, int16_t, int16_t, IODBMSTP * ) ;

/* write mesured point value */
FWLIBAPI int16_t WINAPI cnc_wrmsptype( uint16_T, int16_t, IODBMSTP * ) ;

/* read parameter */
FWLIBAPI int16_t WINAPI cnc_rdparam( uint16_T, int16_t, int16_t, int16_t, IODBPSD * ) ;

/* read parameter */
FWLIBAPI int16_t WINAPI cnc_rdparam3( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBPSD * ) ;

/* write parameter */
FWLIBAPI int16_t WINAPI cnc_wrparam( uint16_T, int16_t, IODBPSD * ) ;

/* write parameter */
FWLIBAPI int16_t WINAPI cnc_wrparam3( uint16_T, int16_t, int16_t, IODBPSD * ) ;

/* read parameter(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdparar( uint16_T, int16_t *, int16_t, int16_t *, int16_t *, void * ) ;

/* read parameter(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdparar3( uint16_T, int16_t *, int16_t, int16_t *, int16_t *, int16_t, void * ) ;

/* write parameter(area specified) */
FWLIBAPI int16_t WINAPI cnc_wrparas( uint16_T, int16_t, void * ) ;

/* write parameter(area specified) */
FWLIBAPI int16_t WINAPI cnc_wrparas3( uint16_T, int16_t, int16_t, void * ) ;

/* write parameter presede */
FWLIBAPI int16_t WINAPI cnc_preset_prm( uint16_T, int16_t, IODBBOOK * ) ;

/* write parameter presede */
FWLIBAPI int16_t WINAPI cnc_validate_prm( uint16_T, int16_t ) ;

/* write parameter presede */
FWLIBAPI int16_t WINAPI cnc_cancel_prm( uint16_T, int16_t ) ;

/* read cnc id */
FWLIBAPI int16_t WINAPI cnc_rdcncid( uint16_T, uint32_T * );

/* After setting the option, The state of SRAM is acquired */
FWLIBAPI int16_t WINAPI cnc_sramstat( uint16_T, int16_t, int16_t *, ODBOPMSG * );

/* After setting the option, The state of SRAM is acquired */
FWLIBAPI int16_t WINAPI cnc_sramstatus( uint16_T, int16_t, int16_t *, ODBSRAMSTAT * );

/* option write select */
FWLIBAPI int16_t WINAPI cnc_validate_opt( uint16_T, int16_t slct );

/* read setting data */
FWLIBAPI int16_t WINAPI cnc_rdset( uint16_T, int16_t, int16_t, int16_t, IODBPSD * ) ;

/* write setting data */
FWLIBAPI int16_t WINAPI cnc_wrset( uint16_T, int16_t, IODBPSD * ) ;

/* read setting data(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdsetr( uint16_T, int16_t *, int16_t, int16_t *, int16_t *, void * ) ;

/* write setting data(area specified) */
FWLIBAPI int16_t WINAPI cnc_wrsets( uint16_T, int16_t, void * ) ;

/* read parameters */
FWLIBAPI int16_t WINAPI cnc_rdparam_ext( uint16_T, int32_t *, int16_t, IODBPRM * ) ;

/* async parameter write start */
FWLIBAPI int16_t WINAPI cnc_start_async_wrparam( uint16_T, IODBPRM * ) ;

/* async parameter write end */
FWLIBAPI int16_t WINAPI cnc_end_async_wrparam( uint16_T, int16_t * ) ;

/* read busy status for async parameter write */
FWLIBAPI int16_t WINAPI cnc_async_busy_state( uint16_T, int16_t * );

/* read diagnosis data */
FWLIBAPI int16_t WINAPI cnc_rddiag_ext( uint16_T, int32_t *, int16_t, IODBPRM * ) ;

/* read pitch error compensation data(area specified) (incremental)*/
FWLIBAPI int16_t WINAPI cnc_rdpitchr( uint16_T, int16_t, int16_t, int16_t, IODBPI * ) ;

/* write pitch error compensation data(area specified) (incremental)*/
FWLIBAPI int16_t WINAPI cnc_wrpitchr( uint16_T, int16_t, IODBPI * ) ;

/* read pitch error compensation data(area specified) (incremental/absolute)*/
FWLIBAPI int16_t WINAPI cnc_rdpitchr2(uint16_T, int16_t, int16_t *, int16_t *);

/* write pitch error compensation data(area specified) (incremental/absolute)*/
FWLIBAPI int16_t WINAPI cnc_wrpitchr2(uint16_T, int16_t, int16_t *, int16_t *);

/* check pich error compensation data(area specified) (absolute) */
FWLIBAPI int16_t WINAPI cnc_checkpitch(uint16_T, int16_t, int16_t *, int16_t *);

/* read high precision pitch error compensation data */
FWLIBAPI int16_t WINAPI cnc_rdhipitchr( uint16_T, int32_t, int32_t *, int32_t * ) ;

/* write high precision pitch error compensation data */
FWLIBAPI int16_t WINAPI cnc_wrhipitchr( uint16_T, int32_t, int32_t *, int32_t * ) ;

/* read high precision pitch error compensation info */
FWLIBAPI int16_t WINAPI cnc_rdhipitchinfo( uint16_T, int32_t * ) ;

/* read custom macro variable */
FWLIBAPI int16_t WINAPI cnc_rdmacro( uint16_T, int16_t, int16_t, ODBM * ) ;

/* write custom macro variable */
FWLIBAPI int16_t WINAPI cnc_wrmacro( uint16_T, int16_t, int16_t, int32_t, int16_t ) ;

/* read custom macro variable 2 */
 FWLIBAPI int16_t WINAPI cnc_rdmacro2( uint16_T, int16_t, int16_t, ODBM * ) ;

/* read custom macro variable (3)*/
 FWLIBAPI int16_t WINAPI cnc_rdmacro3( uint16_T, int32_t, int16_t, ODBM3 * ) ;

/* write custom macro variable (3)*/
 FWLIBAPI int16_t WINAPI cnc_wrmacro3( uint16_T, int32_t, int16_t, int32_t, int16_t ) ;

/* read custom macro variables(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdmacror( uint16_T, int16_t, int16_t, int16_t, IODBMR * ) ;

/* write custom macro variables(area specified) */
FWLIBAPI int16_t WINAPI cnc_wrmacror( uint16_T, int16_t, IODBMR * ) ;

#if defined (HSSB_LIB) && defined (FS15BD)
/* read custom macro variables(area specified) 2 */
FWLIBAPI int16_t WINAPI cnc_rdmacror2( uint16_T, int16_t, int16_t, int16_t, IODBMR * ) ;
#else
/* read custom macro variables(IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdmacror2( uint16_T, uint32_T, uint32_T *, double * ) ;
FWLIBAPI int16_t WINAPI cnc_rdmacror2_name( uint16_T, uint32_T, uint32_T *, IODBMRN *pdb ) ;
#endif
FWLIBAPI int16_t WINAPI cnc_rdmacror3( uint16_T, uint32_T, uint32_T *, IODBMRN3 *pdb ) ;
FWLIBAPI int16_t WINAPI cnc_rdmacror4( uint16_T, uint32_T, uint32_T *, IODBMRN4 *pdb ) ;

/* write custom macro variables(IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_wrmacror2( uint16_T, uint32_T, uint32_T *, double * ) ;

/* read custom macro variable(Back ground version) */
FWLIBAPI int16_t WINAPI cnc_rdmacro_bg( uint16_T, int16_t, int16_t, ODBM * ) ;

/* write custom macro variable(Back ground version) */
FWLIBAPI int16_t WINAPI cnc_wrmacro_bg( uint16_T, int16_t, int16_t, int32_t, int16_t ) ;

/* read custom macro variable number */
FWLIBAPI int16_t WINAPI cnc_rdmacronum( uint16_T, char *, uint32_T, uint32_T *, int16_t * ) ;

/* read P code macro variable */
FWLIBAPI int16_t WINAPI cnc_rdpmacro( uint16_T, int32_t, ODBPM * ) ;

/* write P code macro variable */
FWLIBAPI int16_t WINAPI cnc_wrpmacro( uint16_T, int32_t, int32_t, int16_t ) ;

/* read P code macro variables(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdpmacror( uint16_T, int32_t, int32_t, uint16_T, IODBPR * ) ;

/* write P code macro variables(area specified) */
FWLIBAPI int16_t WINAPI cnc_wrpmacror( uint16_T, uint16_T, IODBPR * ) ;

/* read P code macro variables(IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdpmacror2( uint16_T, uint32_T, uint32_T *, uint16_T, double * );

/* write P code macro variables(IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_wrpmacror2( uint16_T, uint32_T, uint32_T *, uint16_T, double * );

/* read P code macro variables(Back ground version) */
FWLIBAPI int16_t WINAPI cnc_rdpmacror_bg( uint16_T, uint32_T, uint32_T *, double * );

/* write P code macro variables(Back ground version) */
FWLIBAPI int16_t WINAPI cnc_wrpmacror_bg( uint16_T, uint32_T, uint32_T *, double * );

/* read tool offset information */
FWLIBAPI int16_t WINAPI cnc_rdtofsinfo( uint16_T, ODBTLINF * ) ;

/* read tool offset information(2) */
FWLIBAPI int16_t WINAPI cnc_rdtofsinfo2( uint16_T, ODBTLINF2 * ) ;

/* read work zero offset information */
FWLIBAPI int16_t WINAPI cnc_rdzofsinfo( uint16_T, int16_t * ) ;

/* read work zero point measurement hole measured value */
FWLIBAPI int16_t WINAPI cnc_rdholmes( uint16_T, ODBHOLDATA * ) ;

/* check [MEASURE] operation is available or not */
FWLIBAPI int16_t WINAPI cnc_rdenblinfo( uint16_T, char * ) ;

/* check [MEASURE] [CENTER] operation is available or not */
FWLIBAPI int16_t WINAPI cnc_rdcenblinfo( uint16_T, char * ) ;

/* read work zero point measurement value */
FWLIBAPI int16_t WINAPI cnc_rdzofsmes( uint16_T, int32_t, int32_t, int32_t, int32_t *, int32_t * ) ;

/* read work zero point measurement TL value */
FWLIBAPI int16_t WINAPI cnc_rdtldata( uint16_T, ODBTLDATA * ) ;

/* write work zero point measurement TL value */
FWLIBAPI int16_t WINAPI cnc_wrtldata( uint16_T, int32_t, int32_t, int32_t ) ;

/* read work zero point measurement hole center value */
FWLIBAPI int16_t WINAPI cnc_rdcenter( uint16_T, int32_t *, int32_t *, int32_t *, int32_t *, int32_t *, int32_t * ) ;

/* read tool length measurement information */
FWLIBAPI int16_t WINAPI cnc_rdtlmsinfo( uint16_T, ODBTLMSINF * ) ;

/* check [MEASURE] [MEASURE+] operation is available or not */
FWLIBAPI int16_t WINAPI cnc_rdtofsenbl( uint16_T, char * ) ;

/* write tool length measurement measured value */
FWLIBAPI int16_t WINAPI cnc_wrtofsms( uint16_T, int32_t, int32_t ) ;

/* read pitch error compensation data information */
FWLIBAPI int16_t WINAPI cnc_rdpitchinfo( uint16_T, int16_t * ) ;

/* read custom macro variable information */
FWLIBAPI int16_t WINAPI cnc_rdmacroinfo( uint16_T, ODBMVINF * ) ;

/* local val Level read */
FWLIBAPI int16_t WINAPI cnc_rdmacrolclevel(uint16_T, int16_t* );

/* Select Level local val (#1 - #31) read */
FWLIBAPI int16_t WINAPI cnc_rdmacrolcval(uint16_T, int16_t, int16_t, int16_t, double* );

/* read custom macro variable information ( block ) for Series 30i */
FWLIBAPI int16_t WINAPI cnc_rdpitchblkinfo ( uint16_T, IODBPITCHBLK * ) ;

/* read volumetric compensation data */
FWLIBAPI int16_t WINAPI	cnc_rdvolc( uint16_T, ODBVOLC *, int32_t * ) ;

/* write volumetric compensation data */
FWLIBAPI int16_t WINAPI	cnc_wrvolc( uint16_T, ODBVOLC *, int32_t * ) ;

/* get volumetric compensation amount of axes */
FWLIBAPI int16_t WINAPI	cnc_rdvolccomp	( uint16_T, ODBVOLCOMP * ) ;

/* punch volumetric compensation data to device */
FWLIBAPI int16_t WINAPI	cnc_dvpunchvolc	( uint16_T, ODBVOLCOMP * ) ;

/* read volumetric compensation data to device */
FWLIBAPI int16_t WINAPI	cnc_dvreadvolc	( uint16_T, ODBVOLCOMP * ) ;

/* read rotate volumetric compensation data */
FWLIBAPI int16_t WINAPI	cnc_rdrotvolc( uint16_T, int32_t , int32_t *, IODBROTVOLC * ) ;

/* write rotate volumetric compensation data */
FWLIBAPI int16_t WINAPI	cnc_wrrotvolc( uint16_T, int32_t , int32_t *, IODBROTVOLC * );

/* write rotate volumetric compensation data (2) */
FWLIBAPI int16_t WINAPI	cnc_wrrotvolc2( uint16_T, int32_t , int32_t *, IODBROTVOLC * );

/* read P code macro variable information */
FWLIBAPI int16_t WINAPI cnc_rdpmacroinfo( uint16_T, ODBPMINF * ) ;

/* read P code macro variable information (2) */
FWLIBAPI int16_t WINAPI cnc_rdpmacroinfo2( uint16_T, ODBPMINF2 * ) ;

/* read P code macro variable information (3) */
FWLIBAPI int16_t WINAPI cnc_rdpmacroinfo3( uint16_T, ODBPMINF3 * ) ;

/* read P code macro variable flag */
FWLIBAPI int16_t WINAPI cnc_rdpmacvalflag( uint16_T, ODBPMVALFLG * );

/* read validity of tool offset */
FWLIBAPI int16_t WINAPI cnc_tofs_rnge( uint16_T, int16_t, int16_t, ODBDATRNG * );

/* read validity of work zero offset */
FWLIBAPI int16_t WINAPI cnc_zofs_rnge( uint16_T, int16_t, int16_t, ODBDATRNG * );

/* read validity of work shift value */
FWLIBAPI int16_t WINAPI cnc_wksft_rnge( uint16_T, int16_t, ODBDATRNG * );

#ifndef CNC_PPC
/* read the information for function cnc_rdhsparam() */
FWLIBAPI int16_t WINAPI cnc_rdhsprminfo( uint16_T, int32_t, HSPINFO * );

/* read parameters at the high speed */
FWLIBAPI int16_t WINAPI cnc_rdhsparam( uint16_T, int32_t, HSPINFO *, HSPDATA * );
#endif

/* read parameters at the high speed */
FWLIBAPI int16_t WINAPI cnc_rdhsparamm( uint16_T, int32_t, HSPINFO *, HSPDATAM * );

/* read multi edge tool offset */
FWLIBAPI int16_t WINAPI cnc_rdmofs( uint16_T, int16_t, int16_t, int32_t * );

/* write multi edge tool offset */
FWLIBAPI int16_t WINAPI cnc_wrmofs( uint16_T, int16_t, int16_t, int16_t, int32_t );

/* clear multi edge tool offset */
FWLIBAPI int16_t WINAPI cnc_clrmofs( uint16_T, int16_t, int16_t );

/* read tool geom size data */
FWLIBAPI int16_t WINAPI cnc_rdtlgeomsize( uint16_T, int16_t, int16_t, int16_t *, IODBTLGS * );

/* write tool geom size data */
FWLIBAPI int16_t WINAPI cnc_wrtlgeomsize( uint16_T, int16_t, int16_t, int16_t, int16_t *, IODBTLGS * );

/* read extended tool geom size data */
FWLIBAPI int16_t WINAPI cnc_rdtlgeomsize_ext( uint16_T, int16_t, int16_t, int16_t *, IODBTLGSEXT * );

/* write extended tool geom size data */
FWLIBAPI int16_t WINAPI cnc_wrtlgeomsize_ext( uint16_T, int16_t, int16_t, int16_t, int16_t *, IODBTLGSEXT * );

/* read extended tool geom size data */
FWLIBAPI int16_t WINAPI cnc_rdtlgeomsize_ext2( uint16_T, int16_t, int16_t, int16_t *, IODBTLGSEXT2 * );

/* write extended tool geom size data */
FWLIBAPI int16_t WINAPI cnc_wrtlgeomsize_ext2( uint16_T, int16_t, int16_t, int16_t, int16_t *, IODBTLGSEXT2 * );

/*----------------------------------------*/
/* CNC: Tool life management data related */
/*----------------------------------------*/

/* read tool life management data(tool group number) */
FWLIBAPI int16_t WINAPI cnc_rdgrpid( uint16_T, int16_t, ODBTLIFE1 * ) ;

/* read tool life management data(number of tool groups) */
FWLIBAPI int16_t WINAPI cnc_rdngrp( uint16_T, ODBTLIFE2 * ) ;

/* read tool life management data(number of tools) */
FWLIBAPI int16_t WINAPI cnc_rdntool( uint16_T, int16_t, ODBTLIFE3 * ) ;

/* read tool life management data(tool life) */
FWLIBAPI int16_t WINAPI cnc_rdlife( uint16_T, int16_t, ODBTLIFE3 * ) ;

/* read tool life management data(tool lift counter) */
FWLIBAPI int16_t WINAPI cnc_rdcount( uint16_T, int16_t, ODBTLIFE3 * ) ;

/* read tool life management data(tool length number-1) */
FWLIBAPI int16_t WINAPI cnc_rd1length( uint16_T, int16_t, int16_t, ODBTLIFE4 * ) ;

/* read tool life management data(tool length number-2) */
FWLIBAPI int16_t WINAPI cnc_rd2length( uint16_T, int16_t, int16_t, ODBTLIFE4 * ) ;

/* read tool life management data(cutter compensation no.-1) */
FWLIBAPI int16_t WINAPI cnc_rd1radius( uint16_T, int16_t, int16_t, ODBTLIFE4 * ) ;

/* read tool life management data(cutter compensation no.-2) */
FWLIBAPI int16_t WINAPI cnc_rd2radius( uint16_T, int16_t, int16_t, ODBTLIFE4 * ) ;

/* read tool life management data(tool information-1) */
FWLIBAPI int16_t WINAPI cnc_t1info( uint16_T, int16_t, int16_t, ODBTLIFE4 * ) ;

/* read tool life management data(tool information-2) */
FWLIBAPI int16_t WINAPI cnc_t2info( uint16_T, int16_t, int16_t, ODBTLIFE4 * ) ;

/* read tool life management data(tool number) */
FWLIBAPI int16_t WINAPI cnc_toolnum( uint16_T, int16_t, int16_t, ODBTLIFE4 * ) ;

/* read tool life management data(tool number, tool life, tool life counter)(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdtoolrng( uint16_T, int16_t, int16_t, int16_t, IODBTR * ) ;

/* read tool life management data(all data within group) */
FWLIBAPI int16_t WINAPI cnc_rdtoolgrp( uint16_T, int16_t, int16_t, ODBTG * ) ;

/* write tool life management data(tool life counter) (area specified) */
FWLIBAPI int16_t WINAPI cnc_wrcountr( uint16_T, int16_t, IDBWRC * ) ;

/* read tool life management data(used tool group number) */
FWLIBAPI int16_t WINAPI cnc_rdusegrpid( uint16_T, ODBUSEGR * ) ;

/* read tool life management data(max. number of tool groups) */
FWLIBAPI int16_t WINAPI cnc_rdmaxgrp( uint16_T, ODBLFNO * ) ;

/* read tool life management data(maximum number of tool within group) */
FWLIBAPI int16_t WINAPI cnc_rdmaxtool( uint16_T, ODBLFNO * ) ;

/* read tool life management data(used tool no. within group) */
FWLIBAPI int16_t WINAPI cnc_rdusetlno( uint16_T, int16_t, int16_t, int16_t, ODBTLUSE * ) ;

/* read tool life management data(tool data1) */
FWLIBAPI int16_t WINAPI cnc_rd1tlifedata( uint16_T, int16_t, int16_t, IODBTD * ) ;

/* read tool life management data(tool data2) */
FWLIBAPI int16_t WINAPI cnc_rd2tlifedata( uint16_T, int16_t, int16_t, IODBTD * ) ;

/* write tool life management data(tool data1) */
FWLIBAPI int16_t WINAPI cnc_wr1tlifedata( uint16_T, IODBTD * ) ;

/* write tool life management data(tool data2) */
FWLIBAPI int16_t WINAPI cnc_wr2tlifedata( uint16_T, IODBTD * ) ;

/* read tool life management data(tool group information) */
FWLIBAPI int16_t WINAPI cnc_rdgrpinfo( uint16_T, int16_t, int16_t, int16_t, IODBTGI * ) ;

/* read tool life management data(tool group information 2) */
FWLIBAPI int16_t WINAPI cnc_rdgrpinfo2( uint16_T, int16_t, int16_t, int16_t, IODBTGI2 * ) ;

/* read tool life management data(tool group information 3) */
FWLIBAPI int16_t WINAPI cnc_rdgrpinfo3( uint16_T, int16_t, int16_t, int16_t, IODBTGI3 * ) ;

FWLIBAPI int16_t WINAPI cnc_rdgrpinfo4( uint16_T, int16_t, int16_t, int16_t, int16_t *, IODBTGI4 * );

/* write tool life management data(tool group information) */
FWLIBAPI int16_t WINAPI cnc_wrgrpinfo( uint16_T, int16_t, IODBTGI * ) ;

/* write tool life management data(tool group information 2) */
FWLIBAPI int16_t WINAPI cnc_wrgrpinfo2( uint16_T, int16_t, IODBTGI2 * ) ;

/* write tool life management data(tool group information 3) */
FWLIBAPI int16_t WINAPI cnc_wrgrpinfo3( uint16_T, int16_t, IODBTGI3 * ) ;

/* delete tool life management data(tool group) */
FWLIBAPI int16_t WINAPI cnc_deltlifegrp( uint16_T, int16_t ) ;

/* insert tool life management data(tool data) */
FWLIBAPI int16_t WINAPI cnc_instlifedt( uint16_T, IDBITD * ) ;

/* delete tool life management data(tool data) */
FWLIBAPI int16_t WINAPI cnc_deltlifedt( uint16_T, int16_t, int16_t ) ;

/* clear tool life management data(tool life counter, tool information)(area specified) */
FWLIBAPI int16_t WINAPI cnc_clrcntinfo( uint16_T, int16_t, int16_t ) ;

/* read tool life management data(tool group number) 2 */
FWLIBAPI int16_t WINAPI cnc_rdgrpid2( uint16_T, int32_t, ODBTLIFE5 * ) ;

/* read tool life management data(tool data1) 2 */
FWLIBAPI int16_t WINAPI cnc_rd1tlifedat2( uint16_T, int16_t, int32_t, IODBTD2 * ) ;

/* write tool life management data(tool data1) 2 */
FWLIBAPI int16_t WINAPI cnc_wr1tlifedat2( uint16_T, IODBTD2 * ) ;

/* read tool life management data */
FWLIBAPI int16_t WINAPI cnc_rdtlinfo( uint16_T, ODBTLINFO * ) ;

/* read tool life management data(used tool group number) */
FWLIBAPI int16_t WINAPI cnc_rdtlusegrp( uint16_T, ODBUSEGRP * ) ;

/* read tool life management data(tool group information 2) */
FWLIBAPI int16_t WINAPI cnc_rdtlgrp( uint16_T, int32_t, int16_t *, IODBTLGRP * ) ;

/* read tool life management data (tool data1) */
FWLIBAPI int16_t WINAPI cnc_rdtltool( uint16_T, int32_t, int32_t, int16_t *, IODBTLTOOL * ) ;

/* read tool life management data ( tool change groupe ) */
FWLIBAPI int16_t WINAPI cnc_rdtoolchggrp( uint16_T, int16_t , int16_t , int32_t *);

/* read tool life management data ( count count over ride ) */
FWLIBAPI int16_t WINAPI cnc_rdcntover( uint16_T, int16_t * ) ;

FWLIBAPI int16_t WINAPI cnc_rdexchgtgrp( uint16_T, int16_t *, ODBEXGP *);

FWLIBAPI int16_t WINAPI cnc_rdtlinfo( uint16_T, ODBTLINFO *);

FWLIBAPI int16_t WINAPI cnc_rdtlusegrp( uint16_T, ODBUSEGRP *);

FWLIBAPI int16_t WINAPI cnc_rdcnttype( uint16_T, int16_t, ODBTLIFE3 * ) ;

/* write tool life management data(tool group number) */
FWLIBAPI int16_t WINAPI cnc_wrtoolgrp( uint16_T, int32_t, IDBITD * );

/* C_EXE */
/* Write Tool Life Management Data ( Group Life )         */
FWLIBAPI int16_t WINAPI cnc_wrlife( uint16_T, IDBITD *);
/* Write Tool Life Management Data ( Group Count )        */
FWLIBAPI int16_t WINAPI cnc_wrcount( uint16_T, IDBITD *);
/* Write Tool Life Management Data ( Group CountType )    */
FWLIBAPI int16_t WINAPI cnc_wrcnttype( uint16_T, IDBITD *);

/* write tool life management data( tool length number 1 ) */
FWLIBAPI int16_t WINAPI cnc_wr1length( uint16_T, IDBITD2 * );

/* write tool life management data( tool length number 2 ) */
FWLIBAPI int16_t WINAPI cnc_wr2length( uint16_T, IDBITD * );

/* write tool life management data( tool radius number 1 ) */
FWLIBAPI int16_t WINAPI cnc_wr1radius( uint16_T, IDBITD2 * );

/* write tool life management data( tool radius number 2 ) */
FWLIBAPI int16_t WINAPI cnc_wr2radius( uint16_T, IDBITD * );

/* write tool life management data( tool infomation 1 ) */
FWLIBAPI int16_t WINAPI cnc_wrt1info( uint16_T, IDBITD2 * );

/* write tool life management data( tool infomation 2 ) */
FWLIBAPI int16_t WINAPI cnc_wrt2info( uint16_T, IDBITD * );

/* write tool life management data( tool number ) */
FWLIBAPI int16_t WINAPI cnc_wrtoolnum( uint16_T, IDBITD * );

/* read task information */
FWLIBAPI int16_t WINAPI cnc_read_cexeinfo(uint16_T ,int16_t, CEXEINFO * );

/*-----------------------------------*/
/* CNC: Tool management data related */
/*-----------------------------------*/
/* register new tool management data */
FWLIBAPI int16_t WINAPI cnc_regtool( uint16_T, int16_t, int16_t *, IODBTLMNG * ) ;

/* register new tool management data */
FWLIBAPI int16_t WINAPI cnc_regtool_f2( uint16_T, int16_t, int16_t *, IODBTLMNG_F2 * ) ;

/* delete tool management data */
FWLIBAPI int16_t WINAPI cnc_deltool( uint16_T, int16_t, int16_t *  ) ;

/* read tool management data */
FWLIBAPI int16_t WINAPI cnc_rdtool( uint16_T, int16_t, int16_t *, IODBTLMNG * ) ;

/* read tool management data */
FWLIBAPI int16_t WINAPI cnc_rdtool2(uint16_T, int16_t, int16_t, int16_t *, IODBTLM2 *);

/* read tool management data */
FWLIBAPI int16_t WINAPI cnc_rdtool_f2( uint16_T, int16_t, int16_t *, IODBTLMNG_F2 * ) ;

/* write tool management data */
FWLIBAPI int16_t WINAPI cnc_wrtool( uint16_T, int16_t, IODBTLMNG * ) ;

/* write tool management data */
FWLIBAPI int16_t WINAPI cnc_wrtool_f2( uint16_T, int16_t, IODBTLMNG_F2 * ) ;

/* write individual data of tool management data */
FWLIBAPI int16_t WINAPI cnc_wrtool2( uint16_T, int16_t, IDBTLM * ) ;

/* register new magazine management data */
FWLIBAPI int16_t WINAPI cnc_regmagazine( uint16_T, int16_t *, IODBTLMAG * ) ;

/* delete magazine management data */
FWLIBAPI int16_t WINAPI cnc_delmagazine( uint16_T, int16_t *, IODBTLMAG2 * ) ;

/* read magazine management data */
FWLIBAPI int16_t WINAPI cnc_rdmagazine( uint16_T, int16_t *, IODBTLMAG * ) ;

/* write magazine management data */
FWLIBAPI int16_t WINAPI cnc_wrmagazine( uint16_T, int16_t, int16_t, int16_t ) ;

/* read customdata name */
FWLIBAPI int16_t WINAPI cnc_rdctname( uint16_T, int16_t, unsigned char * ) ;

/* read toollife state name */
FWLIBAPI int16_t WINAPI cnc_rdtlname( uint16_T, int16_t, unsigned char * ) ;

/* read tool kind number in 1st spindle position and 1st wait position */
FWLIBAPI int16_t WINAPI cnc_rdhdnxt( uint16_T, int32_t *, int32_t *) ;

/* read of the customise data of a tool management screen */
FWLIBAPI int16_t WINAPI cnc_rdtldspcstms( uint16_T, int16_t * ) ;

/* read of the customise data of a screen for tool management function */
FWLIBAPI int16_t WINAPI cnc_rdtldspcstms2( uint16_T, int16_t, int16_t * ) ;

/* read of the spindle name and the wait name */
FWLIBAPI int16_t WINAPI cnc_rdspdlwaitname( uint16_T, IODBTLSPWTNAME * );

/* read of the number of below decimal point beams of customaize data */
FWLIBAPI int16_t WINAPI cnc_rdcstmdecfig( uint16_T, unsigned char * ) ;

/* read of the renewal status every kind data of a tool management */
FWLIBAPI int16_t WINAPI cnc_rdtlnewstatus( uint16_T, uint32_T * ) ;

/* write  bigtool geom set data */
FWLIBAPI int16_t WINAPI cnc_rdtoolgeom_tlm( uint16_T, int16_t, int16_t *, IODBTLGEOM * ) ;

/* read  bigtool geom set data */
FWLIBAPI int16_t WINAPI cnc_wrtoolgeom_tlm( uint16_T, int16_t, int16_t *, IODBTLGEOM * ) ;

/* search  freepot */
FWLIBAPI int16_t WINAPI cnc_btlfpotsrh( uint16_T, int16_t, int16_t, int16_t, int16_t *) ;

/* search  freepot */
FWLIBAPI int16_t WINAPI cnc_rdinterference( uint16_T, IODBTLINTF *) ;

FWLIBAPI int16_t WINAPI cnc_rdtoollife_count( uint16_T, char, int16_t * );

FWLIBAPI int16_t WINAPI cnc_rdtoollife_data( uint16_T, int16_t , int16_t * , IODBTL_RDTYPE , IODBTLLF*  );

FWLIBAPI int16_t WINAPI cnc_rdtoollifed_count( uint16_T, int32_t , int16_t * );

FWLIBAPI int16_t WINAPI cnc_rdtoollifed_data( uint16_T, int32_t , int16_t , int16_t * , IODBTLLFD* );

FWLIBAPI int16_t WINAPI cnc_rdtoollife_tcodedata	( uint16_T, int32_t , unsigned char , IODBTLLF*  );
FWLIBAPI int16_t WINAPI cnc_rdtlmgr_check	( uint16_T, IODBTLMGR_CHECK*  );

FWLIBAPI int16_t WINAPI cnc_tool_in( uint16_T, int16_t* , IODBTLMNG_F2*  );
FWLIBAPI int16_t WINAPI cnc_tool_out( uint16_T, char , IODBTLMAG2*  );
FWLIBAPI int16_t WINAPI cnc_rdtool_inhis	( uint16_T, int16_t, int16_t*, IODBTOOL_INHIS*  );
FWLIBAPI int16_t WINAPI cnc_rdtool_outhis	( uint16_T, int16_t, int16_t*, IODBTOOL_OUTHIS*  );
FWLIBAPI int16_t WINAPI cnc_rdtool_cause	( uint16_T, IODBTOOL_CAUSENME* );

FWLIBAPI int16_t WINAPI cnc_tool_temp_in( uint16_T, IODBTLMAG2*  );
FWLIBAPI int16_t WINAPI cnc_tool_temp_out( uint16_T, IODBTLMAG2*  );

FWLIBAPI int16_t WINAPI cnc_tool_in2( uint16_T, IODBTLMAG*  );

FWLIBAPI int16_t WINAPI cnc_srttl_getnum(uint16_T , int16_t, int32_t, int32_t, int16_t*);
FWLIBAPI int16_t WINAPI cnc_srttl_getdata(uint16_T , int16_t, int16_t*, int16_t, int32_t, int32_t, IODBTLMNG_SORT*);

/* read customisedata name */
FWLIBAPI int16_t WINAPI cnc_rdtlmgr_name(uint16_T , int16_t , int16_t , int16_t*, unsigned char* );

/* read customise decdata */
FWLIBAPI int16_t WINAPI cnc_rdcstm_decfig(uint16_T , int16_t ,  int16_t , int16_t*, unsigned char* );

/* read  magazineproperty data */
FWLIBAPI int16_t WINAPI cnc_rdmag_property(uint16_T , int16_t*, IODBMAGPRTY* );

/* write  magazineproperty data */
FWLIBAPI int16_t WINAPI cnc_wrmag_property(uint16_T , int16_t*, IODBMAGPRTY* );

/* read  potproperty data */
FWLIBAPI int16_t WINAPI cnc_rdpot_property(uint16_T , int16_t , int16_t , int16_t*, IODBPOTPRTY* );

/* write  potproperty data */
FWLIBAPI int16_t WINAPI cnc_wrpot_property(uint16_T ,int16_t ,int16_t , int16_t*, IODBPOTPRTY* );

/* delete magazineproperty data */
FWLIBAPI int16_t WINAPI cnc_delmag_property(uint16_T ,int16_t*, IODBMAGPRTY2*);

/* delete potproperty data */
FWLIBAPI int16_t WINAPI cnc_delpot_property(uint16_T , int16_t ,int16_t ,int16_t*);

/* move tool data*/
FWLIBAPI int16_t WINAPI cnc_tool_move(uint16_T , IODBTLMAG2*, IODBTLMAG2*);

/* resistry tool strage position */
FWLIBAPI int16_t WINAPI cnc_reg_toolstrage( uint16_T, unsigned char, IODBTLMAG *);

/* Search  magazine management data */
FWLIBAPI int16_t WINAPI cnc_magazinesrch(uint16_T, int16_t, IDBTLM_SRCHDT, IODBTLMAG_SRCHINFO* );

/* Search  tool management data     */
FWLIBAPI int16_t WINAPI cnc_toolsrch(uint16_T , int16_t , int16_t , IDBTLM_SRCHDT , int16_t* );

FWLIBAPI int16_t WINAPI cnc_rdedgedata(uint16_T, int16_t, int16_t, int16_t *, ODBTLMNG_MU_EDGE * );
FWLIBAPI int16_t WINAPI cnc_wredgedata(uint16_T, int16_t, int16_t, IODBTLMNG_MU_EDGE_DATA * );
FWLIBAPI int16_t WINAPI cnc_wredgedata2(uint16_T, int16_t, int16_t, IDBTLM * );
FWLIBAPI int16_t WINAPI cnc_rdedgedatapage(uint16_T, IDBTLMGR_ADD_INFO, unsigned char, int16_t *, IODBTLMGR_PAGE * );

/* read edge num */
FWLIBAPI int16_t WINAPI cnc_rdedgeactive( uint16_T, int16_t, char * );
FWLIBAPI int16_t WINAPI cnc_tool_in3( uint16_T, int16_t *, IODBTLMNG_F2 *, IODBTLMNG_MU_EDGE_DATA * );

/*-------------------------------------*/
/* CNC: Operation history data related */
/*-------------------------------------*/

/* stop logging operation history data */
FWLIBAPI int16_t WINAPI cnc_stopophis( uint16_T ) ;

/* restart logging operation history data */
FWLIBAPI int16_t WINAPI cnc_startophis( uint16_T ) ;

/* read number of operation history data */
FWLIBAPI int16_t WINAPI cnc_rdophisno( uint16_T, uint16_T * ) ;

/* read operation history data */
FWLIBAPI int16_t WINAPI cnc_rdophistry( uint16_T, uint16_T, uint16_T, uint16_T, ODBHIS * ) ;

/* read operation history data */
FWLIBAPI int16_t WINAPI cnc_rdophistry2( uint16_T, uint16_T, uint16_T *, uint16_T *, void * ) ;

/* read operation history data F30i*/
FWLIBAPI int16_t WINAPI cnc_rdophistry3( uint16_T, uint16_T, uint16_T *, uint16_T *, void * ) ;

/* read number of alarm history data */
FWLIBAPI int16_t WINAPI cnc_rdalmhisno( uint16_T, uint16_T * ) ;

/* read alarm history data */
FWLIBAPI int16_t WINAPI cnc_rdalmhistry( uint16_T, uint16_T, uint16_T, uint16_T, ODBAHIS * ) ;

/* read alarm history data */
FWLIBAPI int16_t WINAPI cnc_rdalmhistry_w( uint16_T, uint16_T, uint16_T, uint16_T, ODBAHIS * ) ;

/* read alarm history data */
FWLIBAPI int16_t WINAPI cnc_rdalmhistry2( uint16_T, uint16_T, uint16_T, uint16_T, ODBAHIS2 * ) ;

/* read alarm history data F30i*/
FWLIBAPI int16_t WINAPI cnc_rdalmhistry3( uint16_T, uint16_T, uint16_T, uint16_T, ODBAHIS3 * ) ;

/* clear operation history data */
FWLIBAPI int16_t WINAPI cnc_clearophis( uint16_T, int16_t ) ;

/* backup operation history data */
FWLIBAPI int16_t WINAPI cnc_backupophis( uint16_T ) ;

/* read signals related operation history */
FWLIBAPI int16_t WINAPI cnc_rdhissgnl( uint16_T, IODBSIG * ) ;

/* read signals related operation history 2 */
FWLIBAPI int16_t WINAPI cnc_rdhissgnl2( uint16_T, IODBSIG2 * ) ;

/* read signals related operation history for F30i*/
FWLIBAPI int16_t WINAPI cnc_rdhissgnl3( uint16_T, IODBSIG3 * ) ;

/* write signals related operation history */
FWLIBAPI int16_t WINAPI cnc_wrhissgnl( uint16_T, IODBSIG * ) ;

/* write signals related operation history 2 */
FWLIBAPI int16_t WINAPI cnc_wrhissgnl2( uint16_T, IODBSIG2 * ) ;

/* write signals related operation history for F30i*/
FWLIBAPI int16_t WINAPI cnc_wrhissgnl3( uint16_T, IODBSIG3 * ) ;

//------------------------------------------------------------------------------------------------------------------
/* read operation history data F30i*/
FWLIBAPI int16_t WINAPI cnc_rdophistry4( uint16_T, uint16_T, uint16_T *, uint16_T *, void * ) ;

/* read number of operation history data (for cnc_rdophistry4 ) */
FWLIBAPI int16_t WINAPI cnc_rdophisno4( uint16_T, uint16_T * ) ;

/* read number of operater message history data */
FWLIBAPI int16_t WINAPI cnc_rdomhisno( uint16_T, uint16_T * ) ;

/* read alarm history data F30i*/
FWLIBAPI int16_t WINAPI cnc_rdalmhistry4( uint16_T, uint16_T, uint16_T, uint16_T, ODBAHIS4 * );

/* read operater message history data F30i */
FWLIBAPI int16_t WINAPI cnc_rdomhistry2( uint16_T, uint16_T, uint16_T, uint16_T, ODBOMHIS2 * ) ;

/* read number of operation history data */
FWLIBAPI int16_t WINAPI cnc_rdophisno3( uint16_T, uint16_T * ) ;

/* read number of alarm history data */
FWLIBAPI int16_t WINAPI cnc_rdalmhisno3( uint16_T, uint16_T * ) ;

/* read alarm history data F30i*/
FWLIBAPI int16_t WINAPI cnc_rdalmhistry5( uint16_T, uint16_T, uint16_T, uint16_T, ODBAHIS5 * );

#ifndef CNC_PPC
/* write external key operation history for F30i*/
FWLIBAPI int16_t WINAPI cnc_wrkeyhistry( uint16_T, char) ;
#endif

/*--------------------------------------*/
/* CNC: 3D interference check           */
/*--------------------------------------*/

/* cnc_rdtdiinfo:read 3 dimensional interferect check information */
FWLIBAPI int16_t WINAPI cnc_rdtdiinfo(uint16_T, ODBINF *);

/* cnc_rdtdinamesetting:read name setting */
FWLIBAPI int16_t WINAPI cnc_rdtdinamesetting(uint16_T, int16_t, uint16_T, uint16_T *, ODBNME *);

/* cnc_wrtdinamesetting:write name setting */
FWLIBAPI int16_t WINAPI cnc_wrtdinamesetting(uint16_T, int16_t, uint16_T, uint16_T, ODBNME *);

/* cnc_rdtdifignum:read figure number */
FWLIBAPI int16_t WINAPI cnc_rdtdifignum(uint16_T, uint16_T *);

/* cnc_wrtdifignum:write figure number */
FWLIBAPI int16_t WINAPI cnc_wrtdifignum(uint16_T, uint16_T);

/* cnc_rdtdidispsetting:read display setting */
FWLIBAPI int16_t WINAPI cnc_rdtdidispsetting(uint16_T, int16_t, uint16_T, uint16_T *, ODBDST *);

/* cnc_wrtdidispsetting:write display setting */
FWLIBAPI int16_t WINAPI cnc_wrtdidispsetting(uint16_T, int16_t, uint16_T, uint16_T, ODBDST *);

/* cnc_rdtdishapedata:read shape data */
FWLIBAPI int16_t WINAPI cnc_rdtdishapedata(uint16_T, int16_t, uint16_T, uint16_T, uint16_T *, ODBSHP *);

/* cnc_wrtdishapedata:write shape data */
FWLIBAPI int16_t WINAPI cnc_wrtdishapedata(uint16_T, int16_t, uint16_T, uint16_T, uint16_T, ODBSHP *);

/* cnc_rdtdicubedata:read cube data */
FWLIBAPI int16_t WINAPI cnc_rdtdicubedata(uint16_T, uint16_T, ODBCUB *);

/* cnc_wrtdicubedata:write cube data */
FWLIBAPI int16_t WINAPI cnc_wrtdicubedata(uint16_T, uint16_T, ODBCUB *);

/* cnc_rdtdicubeinfo:read cube infomation */
FWLIBAPI int16_t WINAPI cnc_rdtdicubeinfo(uint16_T, uint16_T, uint16_T *, ODBCBI *);

/* cnc_rdtdieffectshape:read effect shape */
FWLIBAPI int16_t WINAPI cnc_rdtdieffectshape(uint16_T, int16_t, uint16_T, uint16_T *);

/* cnc_rdtdieffectshape:write effect shape */
FWLIBAPI int16_t WINAPI cnc_wrtdieffectshape(uint16_T, int16_t, uint16_T, uint16_T);

/* cnc_rdtdimoveaxis:read move axis infomation */
FWLIBAPI int16_t WINAPI cnc_rdtdimoveaxis(uint16_T, int16_t, uint16_T, ODBMVA *);

/* cnc_wrtdimoveaxis:write move axis infomation */
FWLIBAPI int16_t WINAPI cnc_wrtdimoveaxis(uint16_T, int16_t, uint16_T, ODBMVA *);

/* cnc_rdtdiseltool:read selected tool infomation */
FWLIBAPI int16_t WINAPI cnc_rdtdiseltool(uint16_T, int32_t, int32_t *, int32_t *);

/* cnc_rdtdicurrentshape:read current shape */
FWLIBAPI int16_t WINAPI cnc_rdtdicurrentshape(uint16_T, int16_t, uint16_T, uint16_T *);

/* cnc_rdtdicrntshapeinf:read current shape infomation */
FWLIBAPI int16_t WINAPI cnc_rdtdicrntshapeinf(uint16_T, int16_t, uint16_T, uint16_T, uint16_T *, ODBCRNTSHP *);

/* cnc_opentdicubeinfo:open cube infomation */
FWLIBAPI int16_t WINAPI cnc_opentdicubeinfo(uint16_T FlibHndl, uint16_T *, uint16_T *);

/* cnc_seqrdtdicubeinfo:sequential read cube infomation */
FWLIBAPI int16_t WINAPI cnc_seqrdtdicubeinfo(uint16_T FlibHndl, uint16_T, uint16_T, uint16_T *, ODBCBI *);

/* cnc_rdtdicylinderdata:read cylinder data */
FWLIBAPI int16_t WINAPI cnc_rdtdicylinderdata(uint16_T, uint16_T, ODBCYL *);

/* cnc_wrtdicylinderdata:write cylinder data */
FWLIBAPI int16_t WINAPI cnc_wrtdicylinderdata(uint16_T, uint16_T, ODBCYL *);

/* cnc_rdtdiplanedata:read plane data */
FWLIBAPI int16_t WINAPI cnc_rdtdiplanedata(uint16_T, uint16_T, ODBPLN *);

/* cnc_wrtdiplanedata:write plane data */
FWLIBAPI int16_t WINAPI cnc_wrtdiplanedata(uint16_T, uint16_T, ODBPLN *);

/* cnc_rdtdifiguredata:read figure data */
FWLIBAPI int16_t WINAPI cnc_rdtdifiguredata(uint16_T, uint16_T, uint16_T *, ODBFIG *);

/* cnc_wrtdifiguredata:write figure data */
FWLIBAPI int16_t WINAPI cnc_wrtdifiguredata(uint16_T, uint16_T, uint16_T, ODBFIG *);

/* cnc_rdtdiinitview:read initial view type */
FWLIBAPI int16_t WINAPI cnc_rdtdiinitview(uint16_T, uint16_T *);

/* cnc_wrtdiinitview:write initial view type */
FWLIBAPI int16_t WINAPI cnc_wrtdiinitview(uint16_T, uint16_T);

/* cnc_settdiobjectshape:set object shape (G22.2 imitation) */
FWLIBAPI int16_t WINAPI cnc_settdiobjectshape(uint16_T, uint16_T, uint16_T);

/* cnc_settditoolshape:set tool shape (WINDW 431 imitation) */
FWLIBAPI int16_t WINAPI cnc_settditoolshape(uint16_T, uint16_T, uint16_T);

/* read 3D interference check comment */
FWLIBAPI int16_t WINAPI cnc_rdtdicomment(uint16_T FlibHndl, int16_t *length, char *comment);

/* read 3D interference check comment */
FWLIBAPI int16_t WINAPI cnc_wrtdicomment(uint16_T FlibHndl, int16_t *length, char *comment);

/* read 3D interference check color data */
FWLIBAPI int16_t WINAPI cnc_rdtdicolordata(uint16_T FlibHndl, int16_t ob_type, uint16_T ob_s_no, uint16_T rd_num, char *data);

/* write 3D interference check color data */
FWLIBAPI int16_t WINAPI cnc_wrtdicolordata(uint16_T FlibHndl, int16_t ob_type, uint16_T ob_s_no, uint16_T wrt_num, char *data);

/*-----------------------------------*/
/* CNC: trouble diagnosis            */
/*-----------------------------------*/
/* cnc_mdg_rdalmnum:Reading of alarm number when generated */
FWLIBAPI int16_t WINAPI cnc_mdg_rdalmnum(uint16_T, int32_t*);

/* cnc_mdg_rdalminfo:Reading of alarm infomation when generated */
FWLIBAPI int16_t WINAPI cnc_mdg_rdalminfo(uint16_T, int32_t, int32_t*, IODBMDGINFO*);

/* cnc_mdg_rdmsg:Reading of presumption cause message */
FWLIBAPI int16_t WINAPI cnc_mdg_rdmsg(uint16_T, IODBMDGINFO*, ODBMDGMSG*);

/* cnc_mdg_rdflow:Reading of flow message */
FWLIBAPI int16_t WINAPI cnc_mdg_rdflow(uint16_T, int16_t, int16_t, IODBMDGINFO*, ODBMDGFLOW*);

/* cnc_mdg_rddtmsg:Reading of detail message */
FWLIBAPI int16_t WINAPI cnc_mdg_rddtmsg(uint16_T, int16_t, IODBMDGINFO*, ODBMDGDTMSG*);

/* cnc_mdg_rdmsgnum:Reading of presumption cause message number */
FWLIBAPI int16_t WINAPI cnc_mdg_rdmsgnum(uint16_T, int16_t, int32_t*);

/* cnc_mdg_msgsrch:Searching of presumption cause message */
FWLIBAPI int16_t WINAPI cnc_mdg_msgsrch(uint16_T, int16_t, int32_t, int32_t*);

/* cnc_mdg_rdmsgordr:Reading of the registration order presumption cause message */
FWLIBAPI int16_t WINAPI cnc_mdg_rdmsgordr(uint16_T, int16_t, int32_t, int32_t*, ODBMDGMSG*);

/* cnc_mdg_rdcontinfo:Reading of information on alarm when being continuing */
FWLIBAPI int16_t WINAPI cnc_mdg_rdcontinfo(uint16_T, int16_t*, int32_t*, int32_t*, IODBMDGINFO*);

/* cnc_mdg_rdorderalmno:Reading of the diagnosis order alarm number */
FWLIBAPI int16_t WINAPI cnc_mdg_rdorderalmno(uint16_T, IODBMDGINFO*, int32_t*);

/* cnc_mdg_rdlatchedalm:Reading of alarm information on maintenance */
FWLIBAPI int16_t WINAPI cnc_mdg_rdlatchedalm(uint16_T, IODBMDGINFO*, int16_t*);

/* cnc_mdg_rdalminfoview2:Reading of trouble diagnosis monitor information */
FWLIBAPI int16_t WINAPI cnc_mdg_rdalminfoview2(uint16_T, int16_t, int16_t, int16_t, ODBVIEWGRP2*);

/* cnc_mdg_rdwvdata:Reading of waveform data */
FWLIBAPI int16_t WINAPI cnc_mdg_rdwvdata(uint16_T, int16_t, char, ODBMDGWVDT*);

/* cnc_mdg_rdheatsimlt:Reading of present value of heat simulation */
FWLIBAPI int16_t WINAPI cnc_mdg_rdheatsimlt(uint16_T, int16_t, int16_t, int16_t, ODBLOAD*);

/* cnc_mdg_rdloadlvl:Reading of present value of disturbance level */
FWLIBAPI int16_t WINAPI cnc_mdg_rdloadlvl(uint16_T, int16_t, int16_t, int16_t, ODBLOAD*);

/* cnc_mdg_monistat:Reading of state of monitor information on alarm */
FWLIBAPI int16_t WINAPI cnc_mdg_monistat(uint16_T, int16_t*);

/* cnc_mdg_moniclear:Deletion of monitor information on alarm */
FWLIBAPI int16_t WINAPI cnc_mdg_moniclear(uint16_T);

/* cnc_mdg_rdsysinfo:Reading of trouble diagnosis infomation */
FWLIBAPI int16_t WINAPI cnc_mdg_rdsysinfo(uint16_T, int16_t, int32_t*);

/*-------------*/
/* CNC: Others */
/*-------------*/

/* read CNC system information */
FWLIBAPI int16_t WINAPI cnc_sysinfo( uint16_T, ODBSYS * ) ;

/* read CNC status information */
FWLIBAPI int16_t WINAPI cnc_statinfo( uint16_T, ODBST * ) ;

/* read CNC status information */
FWLIBAPI int16_t WINAPI cnc_statinfo2( uint16_T, ODBST2 * ) ;

/* read axis status information */
FWLIBAPI int16_t WINAPI cnc_rdmovestate( uint16_T, int16_t, int16_t *, unsigned char * ) ;

/* read DMG Netservice status information */
FWLIBAPI int16_t WINAPI cnc_statinfo_dmg( uint16_T, OUT_STATINF_DMG * ) ;

/* read status + diagnosis data for ROBODRILL and TOYOTA  */
FWLIBAPI int16_t WINAPI cnc_rdcmstatdata( uint16_T, uint32_T * ) ;

/* read alarm status */
FWLIBAPI int16_t WINAPI cnc_alarm( uint16_T, ODBALM * ) ;

/* read alarm status */
FWLIBAPI int16_t WINAPI cnc_alarm2( uint16_T, int32_t * ) ;

/* clear alarm */
FWLIBAPI int16_t WINAPI cnc_clearalm( uint16_T, int16_t ) ;

/* read alarm information */
FWLIBAPI int16_t WINAPI cnc_rdalminfo( uint16_T, int16_t, int16_t, int16_t, ALMINFO * ) ;

/* read alarm information (2) */
FWLIBAPI int16_t WINAPI cnc_rdalminfo2( uint16_T, int16_t, int16_t, int16_t, ALMINFO2 * ) ;

/* read alarm message */
FWLIBAPI int16_t WINAPI cnc_rdalmmsg( uint16_T, int16_t, int16_t *, ODBALMMSG * ) ;

/* read alarm message */
FWLIBAPI int16_t WINAPI cnc_rdalmmsg2( uint16_T, int16_t, int16_t *, ODBALMMSG2 * ) ;

/* read alarm message */
FWLIBAPI int16_t WINAPI cnc_rdalmmsg3( uint16_T, int16_t, int16_t *, ODBALMMSG3 * ) ;

/* clear CNC alarm */
FWLIBAPI int16_t WINAPI cnc_clralm( uint16_T hndl, int16_t id ) ;

/* read modal data */
FWLIBAPI int16_t WINAPI cnc_modal( uint16_T, int16_t, int16_t, ODBMDL * ) ;

/* read canned command */
FWLIBAPI int16_t WINAPI cnc_cannedcycle( uint16_T, ODBCANCMD * ) ;

/* read G code */
FWLIBAPI int16_t WINAPI cnc_rdgcode( uint16_T, int16_t, int16_t, int16_t *, ODBGCD * ) ;

/* read G code (m) */
FWLIBAPI int16_t WINAPI cnc_rdgcodem( uint16_T, int16_t, int16_t, int16_t *, ODBGCD * ) ;

/* block_status */
FWLIBAPI int16_t WINAPI cnc_block_status( uint16_T, int16_t*);

/* read command value */
FWLIBAPI int16_t WINAPI cnc_rdcommand( uint16_T, int16_t, int16_t, int16_t *, ODBCMD * ) ;

/* read diagnosis data */
FWLIBAPI int16_t WINAPI cnc_diagnoss( uint16_T, int16_t, int16_t, int16_t, ODBDGN * ) ;

/* read diagnosis data(area specified) */
FWLIBAPI int16_t WINAPI cnc_diagnosr( uint16_T, int16_t *, int16_t, int16_t *, int16_t *, void * ) ;

/* read A/D conversion data */
FWLIBAPI int16_t WINAPI cnc_adcnv( uint16_T, int16_t, int16_t, ODBAD * ) ;

/* read operator's message */
FWLIBAPI int16_t WINAPI cnc_rdopmsg( uint16_T, int16_t, int16_t, OPMSG * ) ;

/* read operator's message */
FWLIBAPI int16_t WINAPI cnc_rdopmsg2( uint16_T, int16_t, int16_t, OPMSG2 * ) ;

/* read operator's message */
FWLIBAPI int16_t WINAPI cnc_rdopmsg3( uint16_T, int16_t, int16_t *, OPMSG3 * ) ;

/* read operator's message (m) */
FWLIBAPI int16_t WINAPI cnc_rdopmsg3m( uint16_T, int16_t, int16_t *, OPMSG3 * ) ;

/* read operator's message on key-in line */
FWLIBAPI int16_t WINAPI cnc_rdlnopmsg( uint16_T, char * ) ;

/* read operator message */
 FWLIBAPI int16_t WINAPI cnc_rdopmsgmps( uint16_T, int16_t, int16_t *, OPMSGMPS * ) ;

/* set path number(for 4 axes lathes, multi-path) */
FWLIBAPI int16_t WINAPI cnc_setpath( uint16_T, int16_t ) ;

/* get path number(for 4 axes lathes, multi-path) */
FWLIBAPI int16_t WINAPI cnc_getpath( uint16_T, int16_t *, int16_t * ) ;

/* allocate library handle */
FWLIBAPI int16_t WINAPI cnc_allclibhndl( uint16_T * ) ;

/* free library handle */
FWLIBAPI int16_t WINAPI cnc_freelibhndl( uint16_T ) ;

/* get library option */
FWLIBAPI int16_t WINAPI cnc_getlibopt(uint16_T, int32_t, char *, int32_t *);

/* set library option */
FWLIBAPI int16_t WINAPI cnc_setlibopt(uint16_T, int32_t, char *, int32_t);

/* get custom macro type */
FWLIBAPI int16_t WINAPI cnc_getmactype( uint16_T, int16_t * ) ;

/* set custom macro type */
FWLIBAPI int16_t WINAPI cnc_setmactype( uint16_T, int16_t ) ;

/* get P code macro type */
FWLIBAPI int16_t WINAPI cnc_getpmactype( uint16_T, int16_t * ) ;

/* set P code macro type */
FWLIBAPI int16_t WINAPI cnc_setpmactype( uint16_T, int16_t ) ;

/* get screen status */
FWLIBAPI int16_t WINAPI cnc_getcrntscrn( uint16_T, int16_t * ) ;

/* change screen mode */
FWLIBAPI int16_t WINAPI cnc_slctscrn( uint16_T, int16_t ) ;

/* read CNC configuration information */
FWLIBAPI int16_t WINAPI cnc_sysconfig( uint16_T, ODBSYSC * ) ;

/* read program restart information */
FWLIBAPI int16_t WINAPI cnc_rdprstrinfo( uint16_T, ODBPRS * ) ;

/* read program restart information */
FWLIBAPI int16_t WINAPI cnc_rdprstrinfom( uint16_T, ODBPRSM * ) ;

/* search sequence number for program restart */
FWLIBAPI int16_t WINAPI cnc_rstrseqsrch( uint16_T, int32_t, int32_t, int16_t, int16_t ) ;

/* search sequence number for program restart 2 */
FWLIBAPI int16_t WINAPI cnc_rstrseqsrch2( uint16_T, int32_t, int32_t, int16_t, int16_t, int32_t ) ;

/* read output signal image of software operator's panel  */
FWLIBAPI int16_t WINAPI cnc_rdopnlsgnl( uint16_T, int16_t, IODBSGNL * ) ;

/* write output signal of software operator's panel  */
FWLIBAPI int16_t WINAPI cnc_wropnlsgnl( uint16_T, IODBSGNL * ) ;

/* read general signal image of software operator's panel  */
FWLIBAPI int16_t WINAPI cnc_rdopnlgnrl( uint16_T, int16_t, IODBGNRL * ) ;

/* write general signal image of software operator's panel  */
FWLIBAPI int16_t WINAPI cnc_wropnlgnrl( uint16_T, IODBGNRL * ) ;

/* read general signal image of software operator's panel(2)  */
FWLIBAPI int16_t WINAPI cnc_rdopnlgnrl2( uint16_T, int16_t, IODBGNRL2 * ) ;

/* write general signal image of software operator's panel(2)  */
FWLIBAPI int16_t WINAPI cnc_wropnlgnrl2( uint16_T, IODBGNRL2 * ) ;

/* read general signal name of software operator's panel  */
FWLIBAPI int16_t WINAPI cnc_rdopnlgsname( uint16_T, int16_t, IODBRDNA * ) ;

/* write general signal name of software operator's panel  */
FWLIBAPI int16_t WINAPI cnc_wropnlgsname( uint16_T, IODBRDNA * ) ;

/* read general signal name of software operator's panel(2)  */
FWLIBAPI int16_t WINAPI cnc_rdopnlgsname2( uint16_T, int16_t, IODBRDNA2 * ) ;

/* write general signal name of software operator's panel(2)  */
FWLIBAPI int16_t WINAPI cnc_wropnlgsname2( uint16_T, IODBRDNA2 * ) ;

/* get detail error */
FWLIBAPI int16_t WINAPI cnc_getdtailerr( uint16_T, ODBERR * ) ;

/* get detail error(2) */
FWLIBAPI int16_t WINAPI cnc_getdtailerr2( uint16_T, ODBERR * ) ;

/* read informations of CNC parameter */
FWLIBAPI int16_t WINAPI cnc_rdparainfo( uint16_T, int16_t, uint16_T, ODBPARAIF * ) ;

/* read informations of CNC setting data */
FWLIBAPI int16_t WINAPI cnc_rdsetinfo( uint16_T, int16_t, uint16_T, ODBSETIF * ) ;

/* read informations of CNC diagnose data */
FWLIBAPI int16_t WINAPI cnc_rddiaginfo( uint16_T, int16_t, uint16_T, ODBDIAGIF * ) ;

/* read informations of CNC parameter(2) */
FWLIBAPI int16_t WINAPI cnc_rdparainfo2( uint16_T, int16_t, int16_t*, int16_t*, int16_t*, ODBPARAIF2 * ) ;

/* read informations of CNC parameter(3) */
FWLIBAPI int16_t WINAPI cnc_rdparainfo3( uint16_T, int16_t, int16_t*, int16_t*, int16_t*, ODBPARAIF2 * ) ;

/* read informations of CNC setting data(2) */
FWLIBAPI int16_t WINAPI cnc_rdsetinfo2( uint16_T, int16_t, int16_t*, int16_t*, int16_t*, ODBPARAIF2 * ) ;

/* read informations of CNC diagnose data(2) */
FWLIBAPI int16_t WINAPI cnc_rddiaginfo2( uint16_T, int16_t, int16_t*, int16_t*, int16_t*, ODBPARAIF2 * ) ;

/* read maximum, minimum and total number of CNC parameter */
FWLIBAPI int16_t WINAPI cnc_rdparanum( uint16_T, ODBPARANUM * ) ;

/* read maximum, minimum and total number of CNC setting data */
FWLIBAPI int16_t WINAPI cnc_rdsetnum( uint16_T, ODBSETNUM * ) ;

/* read maximum, minimum and total number of CNC diagnose data */
FWLIBAPI int16_t WINAPI cnc_rddiagnum( uint16_T, ODBDIAGNUM * ) ;

/* get maximum valid figures and number of decimal places */
FWLIBAPI int16_t WINAPI cnc_getfigure( uint16_T, int16_t, int16_t *, int16_t *, int16_t * ) ;

/* read F-ROM information on CNC  */
FWLIBAPI int16_t WINAPI cnc_rdfrominfo( uint16_T, int16_t, ODBFINFO * ) ;

/* start of reading F-ROM data from CNC */
FWLIBAPI int16_t WINAPI cnc_fromsvstart( uint16_T, int16_t, char *, int32_t ) ;

/* read F-ROM data from CNC */
FWLIBAPI int16_t WINAPI cnc_fromsave( uint16_T, int16_t *, void *, int32_t * ) ;

/* end of reading F-ROM data from CNC */
FWLIBAPI int16_t WINAPI cnc_fromsvend( uint16_T ) ;

/* start of writing F-ROM data to CNC */
FWLIBAPI int16_t WINAPI cnc_fromldstart( uint16_T, int16_t, int32_t ) ;

/* write F-ROM data to CNC */
FWLIBAPI int16_t WINAPI cnc_fromload( uint16_T, void *, int32_t * ) ;

/* end of writing F-ROM data to CNC */
FWLIBAPI int16_t WINAPI cnc_fromldend( uint16_T ) ;

/* delete F-ROM data on CNC */
FWLIBAPI int16_t WINAPI cnc_fromdelete( uint16_T, int16_t, char *, int32_t ) ;

/* read S-RAM information on CNC */
FWLIBAPI int16_t WINAPI cnc_rdsraminfo( uint16_T, ODBSINFO * ) ;

/* start of reading S-RAM data from CNC */
FWLIBAPI int16_t WINAPI cnc_srambkstart( uint16_T, char *, int32_t ) ;

/* read S-RAM data from CNC */
FWLIBAPI int16_t WINAPI cnc_srambackup( uint16_T, int16_t *, void *, int32_t * ) ;

/* end of reading S-RAM data from CNC */
FWLIBAPI int16_t WINAPI cnc_srambkend( uint16_T ) ;

#ifndef CNC_PPC
/* read F-ROM information on CNC  */
FWLIBAPI int16_t WINAPI cnc_getfrominfo( uint16_T, int16_t, int16_t *, ODBFINFORM * ) ;

/* start of reading F-ROM data from CNC */
FWLIBAPI int16_t WINAPI cnc_fromgetstart( uint16_T, int16_t, char * ) ;

/* read F-ROM data from CNC */
FWLIBAPI int16_t WINAPI cnc_fromget( uint16_T, int16_t *, void *, int32_t * ) ;

/* end of reading F-ROM data from CNC */
FWLIBAPI int16_t WINAPI cnc_fromgetend( uint16_T ) ;

/* start of writing F-ROM data to CNC */
FWLIBAPI int16_t WINAPI cnc_fromputstart( uint16_T, int16_t ) ;

/* write F-ROM data to CNC */
FWLIBAPI int16_t WINAPI cnc_fromput( uint16_T, void *, int32_t * ) ;

/* end of writing F-ROM data to CNC */
FWLIBAPI int16_t WINAPI cnc_fromputend( uint16_T ) ;

/* delete F-ROM data on CNC */
FWLIBAPI int16_t WINAPI cnc_fromremove( uint16_T, int16_t, char * ) ;

/* read S-RAM information on CNC */
FWLIBAPI int16_t WINAPI cnc_getsraminfo( uint16_T, ODBSINFO * ) ;
#endif

/* start of reading S-RAM data from CNC */
FWLIBAPI int16_t WINAPI cnc_sramgetstart( uint16_T, char * ) ;

#ifndef CNC_PPC
/* start of reading S-RAM data from CNC (2) */
FWLIBAPI int16_t WINAPI cnc_sramgetstart2( uint16_T, char * ) ;
#endif

/* read S-RAM data from CNC */
FWLIBAPI int16_t WINAPI cnc_sramget( uint16_T, int16_t *, void *, int32_t * ) ;

#ifndef CNC_PPC
/* read S-RAM data from CNC (2) */
FWLIBAPI int16_t WINAPI cnc_sramget2( uint16_T, int16_t *, void *, int32_t * ) ;
#endif

/* end of reading S-RAM data from CNC */
FWLIBAPI int16_t WINAPI cnc_sramgetend( uint16_T ) ;

#ifndef CNC_PPC
/* end of reading S-RAM data from CNC (2) */
FWLIBAPI int16_t WINAPI cnc_sramgetend2( uint16_T ) ;

/* start of writing S-RAM data to CNC */
 FWLIBAPI int16_t WINAPI cnc_sramputstart( uint16_T, char * ) ;

/* start of writing S-RAM data to CNC (2) */
 FWLIBAPI int16_t WINAPI cnc_sramputstart2( uint16_T, char * ) ;

/* write S-RAM data to CNC */
 FWLIBAPI int16_t WINAPI cnc_sramput( uint16_T, int16_t *, void *, int32_t * ) ;

/* write S-RAM data to CNC (2) */
 FWLIBAPI int16_t WINAPI cnc_sramput2( uint16_T, int16_t *, void *, int32_t * ) ;

/* end of writing S-RAM data to CNC */
 FWLIBAPI int16_t WINAPI cnc_sramputend( uint16_T ) ;

/* end of writing S-RAM data to CNC (2) */
 FWLIBAPI int16_t WINAPI cnc_sramputend2( uint16_T ) ;
#endif

/* read number of S-RAM data kind on CNC */
FWLIBAPI int16_t WINAPI cnc_rdsramnum( uint16_T, int16_t * ) ;

/* read S-RAM data address information on CNC */
FWLIBAPI int16_t WINAPI cnc_rdsramaddr( uint16_T, int16_t *, SRAMADDR * ) ;

/* get current NC data protection information */
FWLIBAPI int16_t WINAPI cnc_getlockstat( uint16_T, int16_t, unsigned char * ) ;

/* change NC data protection status */
FWLIBAPI int16_t WINAPI cnc_chgprotbit( uint16_T, int16_t, unsigned char *, int32_t ) ;

/* transfer a file from host computer to CNC by FTP */
FWLIBAPI int16_t WINAPI cnc_dtsvftpget( uint16_T, char *, char * ) ;

/* transfer a file from CNC to host computer by FTP */
FWLIBAPI int16_t WINAPI cnc_dtsvftpput( uint16_T, char *, char * ) ;

/* get transfer status for FTP */
FWLIBAPI int16_t WINAPI cnc_dtsvftpstat( uint16_T ) ;

/* read file directory in Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvrdpgdir( uint16_T, char *, int16_t, ODBDSDIR * ) ;

/* delete files in Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvdelete( uint16_T, char * ) ;

/* down load from CNC (transfer a file from CNC to MMC) */
FWLIBAPI int16_t WINAPI cnc_dtsvdownload( uint16_T, char * ) ;

/* up load to CNC (transfer a file from MMC to CNC) */
FWLIBAPI int16_t WINAPI cnc_dtsvupload( uint16_T, char * ) ;

/* close upload/download between Data Server and CNC */
FWLIBAPI int16_t WINAPI cnc_dtsvcnclupdn( uint16_T ) ;

/* get transfer status for up/down load */
FWLIBAPI int16_t WINAPI cnc_dtsvupdnstat( uint16_T ) ;

/* get file name for DNC operation in Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvgetdncpg( uint16_T, char * ) ;

/* set program number of DNC oparation to CNC */
FWLIBAPI int16_t WINAPI cnc_dtsvsetdncpg( uint16_T, char * ) ;

/* read setting data for Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvrdset( uint16_T, IODBDSSET * ) ;

/* write setting data for Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvwrset( uint16_T, IODBDSSET * ) ;

/* check hard disk in Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvchkdsk( uint16_T ) ;

/* format hard disk in Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvhdformat( uint16_T ) ;

/* save interface area in Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvsavecram( uint16_T ) ;

/* get interface area in Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvrdcram( uint16_T, int32_t, int32_t *, char * ) ;

/* read maintenance information for Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvmntinfo( uint16_T, ODBDSMNT * ) ;

/* get Data Server mode */
FWLIBAPI int16_t WINAPI cnc_dtsvgetmode( uint16_T, int16_t * ) ;

/* set Data Server mode */
FWLIBAPI int16_t WINAPI cnc_dtsvsetmode( uint16_T, int16_t ) ;

/* read error message for Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvrderrmsg( uint16_T, int16_t, char * ) ;

/* transfar file from Pc to Data Server */
FWLIBAPI int16_t WINAPI cnc_dtsvwrfile( uint16_T, char *, char *,int16_t );

/* transfar file from Data Server to Pc */
FWLIBAPI int16_t WINAPI cnc_dtsvrdfile( uint16_T, char *, char *,int16_t );

/* read the loop gain for each axis */
FWLIBAPI int16_t WINAPI cnc_rdloopgain( uint16_T, int32_t * ) ;

/* read the actual current for each axis */
#if !defined (PMD)
FWLIBAPI int16_t WINAPI cnc_rdcurrent( uint16_T, int16_t * ) ;
#else
FWLIBAPI int16_t WINAPI cnc_rdcurrent( uint16_T, int32_t * ) ;
#endif

/* read the actual speed for each axis */
FWLIBAPI int16_t WINAPI cnc_rdsrvspeed( uint16_T, int32_t * ) ;

/* read the TSA data for each axis */
FWLIBAPI int16_t WINAPI cnc_rdsrvtsa( uint16_T, int16_t * ) ;

/* read the TCMD data for each axis */
FWLIBAPI int16_t WINAPI cnc_rdsrvtcmd( uint16_T, int16_t * ) ;

/* read the operation mode */
FWLIBAPI int16_t WINAPI cnc_rdopmode( uint16_T, int16_t * ) ;

/* read the position deviation S */
FWLIBAPI int16_t WINAPI cnc_rdposerrs( uint16_T, int32_t * ) ;

/* read the position deviation S1 and S2 */
FWLIBAPI int16_t WINAPI cnc_rdposerrs2( uint16_T, ODBPSER * ) ;

/* read the position deviation Z in the rigid tap mode */
FWLIBAPI int16_t WINAPI cnc_rdposerrz( uint16_T, int32_t * ) ;

/* read the synchronous error in the synchronous control mode */
FWLIBAPI int16_t WINAPI cnc_rdsynerrsy( uint16_T, int32_t * ) ;

/* read the synchronous error in the rigid tap mode */
FWLIBAPI int16_t WINAPI cnc_rdsynerrrg( uint16_T, int32_t * ) ;

/* read the spindle alarm */
FWLIBAPI int16_t WINAPI cnc_rdspdlalm( uint16_T, char * ) ;

/* read the control input signal */
FWLIBAPI int16_t WINAPI cnc_rdctrldi( uint16_T, ODBSPDI * ) ;

/* read the control output signal */
FWLIBAPI int16_t WINAPI cnc_rdctrldo( uint16_T, ODBSPDO * ) ;

/* read the number of controled spindle */
FWLIBAPI int16_t WINAPI cnc_rdnspdl( uint16_T, int16_t * ) ;

/* read Servo feedback multiplication data */
 FWLIBAPI int16_t WINAPI cnc_rdsvfeedback(uint16_T, int16_t, ODBSVFBACK * );

#ifndef CNC_PPC
/* read data from FANUC BUS */
FWLIBAPI int16_t WINAPI cnc_rdfbusmem( uint16_T, int16_t, int16_t, int32_t, int32_t, void * ) ;

/* write data to FANUC BUS */
FWLIBAPI int16_t WINAPI cnc_wrfbusmem( uint16_T, int16_t, int16_t, int32_t, int32_t, void * ) ;
#endif

/* read the parameter of wave diagnosis */
FWLIBAPI int16_t WINAPI cnc_rdwaveprm( uint16_T, IODBWAVE * ) ;

/* write the parameter of wave diagnosis */
FWLIBAPI int16_t WINAPI cnc_wrwaveprm( uint16_T, IODBWAVE * ) ;

/* read the parameter of wave diagnosis 2 */
FWLIBAPI int16_t WINAPI cnc_rdwaveprm2( uint16_T, IODBWVPRM * ) ;

/* write the parameter of wave diagnosis 2 */
FWLIBAPI int16_t WINAPI cnc_wrwaveprm2( uint16_T, IODBWVPRM * ) ;

/* read the parameter of wave diagnosis 3 */
FWLIBAPI int16_t WINAPI cnc_rdwaveprm3( uint16_T, IODBWVPRM3 * ) ;

/* write the parameter of wave diagnosis 3 */
FWLIBAPI int16_t WINAPI cnc_wrwaveprm3( uint16_T, IODBWVPRM3 * ) ;

/* start the sampling for wave diagnosis */
FWLIBAPI int16_t WINAPI cnc_wavestart( uint16_T ) ;

/* stop the sampling for wave diagnosis */
FWLIBAPI int16_t WINAPI cnc_wavestop( uint16_T ) ;

/* read the status of wave diagnosis */
FWLIBAPI int16_t WINAPI cnc_wavestat( uint16_T, int16_t * ) ;

/* read the data of wave diagnosis */
FWLIBAPI int16_t WINAPI cnc_rdwavedata( uint16_T, int16_t, int16_t, int32_t, int32_t *, ODBWVDT * ) ;
FWLIBAPI int16_t WINAPI cnc_rdwavedata3( uint16_T, int16_t, int32_t, int32_t *, ODBWVDT3 * ) ;
/* read the count of wave diagnosis */
FWLIBAPI int16_t WINAPI cnc_rdwavecount( uint16_T, int16_t, int32_t * ) ;

/* read the data of wave diagnosis 2 */
FWLIBAPI int16_t WINAPI cnc_rdwavedata2( uint16_T, int16_t, int32_t, int32_t *, ODBWVDT2 * ) ;

/* read the parameter of wave diagnosis for remort diagnosis */
FWLIBAPI int16_t WINAPI cnc_rdrmtwaveprm( uint16_T, IODBRMTPRM *, int16_t ) ;

/* write the parameter of wave diagnosis for remort diagnosis */
FWLIBAPI int16_t WINAPI cnc_wrrmtwaveprm( uint16_T, IODBRMTPRM * ) ;

/* start the sampling for wave diagnosis for remort diagnosis */
FWLIBAPI int16_t WINAPI cnc_rmtwavestart( uint16_T ) ;

/* stop the sampling for wave diagnosis for remort diagnosis */
FWLIBAPI int16_t WINAPI cnc_rmtwavestop( uint16_T ) ;

/* read the status of wave diagnosis for remort diagnosis*/
FWLIBAPI int16_t WINAPI cnc_rmtwavestat( uint16_T, int16_t * ) ;

/* read the data of wave diagnosis for remort diagnosis */
FWLIBAPI int16_t WINAPI cnc_rdrmtwavedt( uint16_T, int16_t, int32_t, int32_t *, ODBRMTDT * ) ;

/* read of address for PMC signal batch save */
FWLIBAPI int16_t WINAPI cnc_rdsavsigadr( uint16_T, IODBSIGAD *, int16_t ) ;

/* write of address for PMC signal batch save */
FWLIBAPI int16_t WINAPI cnc_wrsavsigadr( uint16_T, IODBSIGAD *, int16_t * ) ;

/* read of data for PMC signal batch save */
FWLIBAPI int16_t WINAPI cnc_rdsavsigdata( uint16_T, int16_t, int16_t, void *, int16_t * ) ;

/* read M-code group data */
FWLIBAPI int16_t WINAPI cnc_rdmgrpdata( uint16_T, int16_t, int16_t *, ODBMGRP * ) ;

/* write M-code group data */
FWLIBAPI int16_t WINAPI cnc_wrmgrpdata( uint16_T, IDBMGRP * ) ;

#ifndef CNC_PPC
/* read executing M-code group data */
FWLIBAPI int16_t WINAPI cnc_rdexecmcode( uint16_T, int16_t, int16_t *, ODBEXEM * );

/* read program restart M-code group data */
FWLIBAPI int16_t WINAPI cnc_rdrstrmcode( uint16_T, int16_t, int16_t *, ODBRSTRM * );
#endif

/* read processing time stamp data */
FWLIBAPI int16_t WINAPI cnc_rdproctime( uint16_T, ODBPTIME * ) ;

FWLIBAPI int16_t WINAPI cnc_rdproctime3( uint16_T, char *, ODBPTIME3 * );

/* read MDI program stat */
FWLIBAPI int16_t WINAPI cnc_rdmdiprgstat( uint16_T, uint16_T * );

/* read program directory for processing time data */
FWLIBAPI int16_t WINAPI cnc_rdprgdirtime( uint16_T, int32_t *, int16_t *, PRGDIRTM * ) ;

/* read program directory 2 */
FWLIBAPI int16_t WINAPI cnc_rdprogdir2( uint16_T, int16_t, int16_t *, int16_t *, PRGDIR2 * ) ;

/* read program directory 3 */
FWLIBAPI int16_t WINAPI cnc_rdprogdir3( uint16_T, int16_t, int32_t *, int16_t *, PRGDIR3 * ) ;

/* read program directory 4 */
FWLIBAPI int16_t WINAPI cnc_rdprogdir4( uint16_T, int16_t, int32_t, int16_t *, PRGDIR4 * ) ;

/* read program directory 4 for wire cut */
FWLIBAPI int16_t WINAPI cnc_rdprogdir4_w( uint16_T, int16_t, int16_t, int16_t, int16_t, int16_t *, PRGDIR3 * );

/* read DNC file name for DNC1, DNC2, OSI-Ethernet */
FWLIBAPI int16_t WINAPI cnc_rddncfname( uint16_T, char * ) ;

/* write DNC file name for DNC1, DNC2, OSI-Ethernet */
FWLIBAPI int16_t WINAPI cnc_wrdncfname( uint16_T, char * ) ;

/* read communication parameter for DNC1, DNC2, OSI-Ethernet */
FWLIBAPI int16_t WINAPI cnc_rdcomparam( uint16_T, IODBCPRM * ) ;

/* write communication parameter for DNC1, DNC2, OSI-Ethernet */
FWLIBAPI int16_t WINAPI cnc_wrcomparam( uint16_T, IODBCPRM * ) ;

/* read log message for DNC2 */
FWLIBAPI int16_t WINAPI cnc_rdcomlogmsg( uint16_T, char * ) ;

/* read operator message for DNC1, DNC2 */
FWLIBAPI int16_t WINAPI cnc_rdcomopemsg( uint16_T, char * ) ;

/* read recieve message for OSI-Ethernet */
FWLIBAPI int16_t WINAPI cnc_rdrcvmsg( uint16_T, char * ) ;

/* read send message for OSI-Ethernet */
FWLIBAPI int16_t WINAPI cnc_rdsndmsg( uint16_T, char * ) ;

/* send message for OSI-Ethernet */
FWLIBAPI int16_t WINAPI cnc_sendmessage( uint16_T, char * ) ;

/* clear message buffer for OSI-Ethernet */
FWLIBAPI int16_t WINAPI cnc_clrmsgbuff( uint16_T, int16_t ) ;

/* read message recieve status for OSI-Ethernet */
FWLIBAPI int16_t WINAPI cnc_rdrcvstat( uint16_T, uint16_T * ) ;

/* read interference check */
FWLIBAPI int16_t WINAPI cnc_rdintchk( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBINT * ) ;

/* write interference check */
FWLIBAPI int16_t WINAPI cnc_wrintchk( uint16_T, int16_t, IODBINT * ) ;

/* read interference check information */
FWLIBAPI int16_t WINAPI cnc_rdintinfo( uint16_T, int16_t * ) ;

/* read work coordinate shift */
FWLIBAPI int16_t WINAPI cnc_rdwkcdshft( uint16_T, int16_t, int16_t, IODBWCSF * ) ;

/* write work coordinate shift */
FWLIBAPI int16_t WINAPI cnc_wrwkcdshft( uint16_T, int16_t, IODBWCSF * ) ;

/* read work coordinate shift measure */
FWLIBAPI int16_t WINAPI cnc_rdwkcdsfms( uint16_T, int16_t, int16_t, IODBWCSF * ) ;

/* write work coordinate shift measure */
FWLIBAPI int16_t WINAPI cnc_wrwkcdsfms( uint16_T, int16_t, IODBWCSF * ) ;

/* read work coordinate shift2 */
FWLIBAPI int16_t WINAPI cnc_rdwkcdshft2(uint16_T, int16_t, int16_t, uint16_T, IODBWCSF *);

/* write work coordinate shift2 */
FWLIBAPI int16_t WINAPI cnc_wrwkcdshft2(uint16_T, uint16_T, int16_t, IODBWCSF *);

/* read work coordinate shift measure2 */
FWLIBAPI int16_t WINAPI cnc_rdwkcdsfms2(uint16_T, int16_t, int16_t, uint16_T, IODBWCSF *);

/* write work coordinate shift measure2 */
FWLIBAPI int16_t WINAPI cnc_wrwkcdsfms2(uint16_T, uint16_T, int16_t, IODBWCSF *);

/* read work coordinate shift3 */
FWLIBAPI int16_t WINAPI cnc_rdwkcdshft3(uint16_T, int16_t, int16_t, int16_t, IODBWCSF *);

/* write work coordinate shift3 */
FWLIBAPI int16_t WINAPI cnc_wrwkcdshft3(uint16_T, int16_t, int16_t, IODBWCSF *);

/* read work coordinate shift measure3 */
FWLIBAPI int16_t WINAPI cnc_rdwkcdsfms3(uint16_T, int16_t, int16_t, int16_t, IODBWCSF *);

/* write work coordinate shift measure3 */
FWLIBAPI int16_t WINAPI cnc_wrwkcdsfms3(uint16_T, int16_t, int16_t, IODBWCSF *);

/* stop the sampling for operator message history */
FWLIBAPI int16_t WINAPI cnc_stopomhis( uint16_T ) ;

/* start the sampling for operator message history */
FWLIBAPI int16_t WINAPI cnc_startomhis( uint16_T ) ;

/* read operator message history information */
FWLIBAPI int16_t WINAPI cnc_rdomhisinfo( uint16_T, ODBOMIF * ) ;

/* read operator message history */
FWLIBAPI int16_t WINAPI cnc_rdomhistry( uint16_T, uint16_T, uint16_T *, ODBOMHIS * ) ;

/* clear operator message history */
FWLIBAPI int16_t WINAPI cnc_clearomhis( uint16_T ) ;

/* read b-axis tool offset value(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdbtofsr( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBBTO * ) ;

/* write b-axis tool offset value(area specified) */
FWLIBAPI int16_t WINAPI cnc_wrbtofsr( uint16_T, int16_t, IODBBTO * ) ;

/* read b-axis tool offset information */
FWLIBAPI int16_t WINAPI cnc_rdbtofsinfo( uint16_T, ODBBTLINF * ) ;

/* read b-axis command */
FWLIBAPI int16_t WINAPI cnc_rdbaxis( uint16_T, ODBBAXIS * ) ;

/* read CNC system soft series and version */
FWLIBAPI int16_t WINAPI cnc_rdsyssoft( uint16_T, ODBSYSS * ) ;

/* read CNC system soft series and version (2) */
FWLIBAPI int16_t WINAPI cnc_rdsyssoft2( uint16_T, ODBSYSS2 * ) ;

/* read CNC module configuration information */
FWLIBAPI int16_t WINAPI cnc_rdmdlconfig( uint16_T, ODBMDLC * ) ;

/* read CNC module configuration information 2 */
FWLIBAPI int16_t WINAPI cnc_rdmdlconfig2( uint16_T, char * ) ;

/* read processing condition file (processing data) */
FWLIBAPI int16_t WINAPI cnc_rdpscdproc( uint16_T, int16_t, int16_t *, IODBPSCD * ) ;

/* write processing condition file (processing data) */
FWLIBAPI int16_t WINAPI cnc_wrpscdproc( uint16_T, int16_t, int16_t *, IODBPSCD * ) ;

/* read processing condition file (processing data) */
FWLIBAPI int16_t WINAPI cnc_rdpscdproc2( uint16_T, int16_t, int16_t *, IODBPSCD2 * ) ;

/* write processing condition file (processing data) */
FWLIBAPI int16_t WINAPI cnc_wrpscdproc2( uint16_T, int16_t, int16_t *, IODBPSCD2 * ) ;

/* read processing condition file (piercing data) */
FWLIBAPI int16_t WINAPI cnc_rdpscdpirc( uint16_T, int16_t, int16_t *, IODBPIRC * ) ;

/* write processing condition file (piercing data) */
FWLIBAPI int16_t WINAPI cnc_wrpscdpirc( uint16_T, int16_t, int16_t *, IODBPIRC * ) ;

/* read processing condition file (edging data) */
FWLIBAPI int16_t WINAPI cnc_rdpscdedge( uint16_T, int16_t, int16_t *, IODBEDGE * ) ;

/* write processing condition file (edging data) */
FWLIBAPI int16_t WINAPI cnc_wrpscdedge( uint16_T, int16_t, int16_t *, IODBEDGE * ) ;

/* read processing condition file (slope data) */
FWLIBAPI int16_t WINAPI cnc_rdpscdslop( uint16_T, int16_t, int16_t *, IODBSLOP * ) ;

/* write processing condition file (slope data) */
FWLIBAPI int16_t WINAPI cnc_wrpscdslop( uint16_T, int16_t, int16_t *, IODBSLOP * ) ;

/* read power controll duty data */
FWLIBAPI int16_t WINAPI cnc_rdlpwrdty( uint16_T, IODBLPWDT * ) ;

/* write power controll duty data */
FWLIBAPI int16_t WINAPI cnc_wrlpwrdty( uint16_T, IODBLPWDT * ) ;

/* read laser power data */
FWLIBAPI int16_t WINAPI cnc_rdlpwrdat( uint16_T, ODBLOPDT * ) ;

/* read power complement */
FWLIBAPI int16_t WINAPI cnc_rdlpwrcpst( uint16_T, int16_t * ) ;

/* write power complement */
FWLIBAPI int16_t WINAPI cnc_wrlpwrcpst( uint16_T, int16_t ) ;

/* read laser assist gas selection */
FWLIBAPI int16_t WINAPI cnc_rdlagslt( uint16_T, IODBLAGSL * ) ;

/* write laser assist gas selection */
FWLIBAPI int16_t WINAPI cnc_wrlagslt( uint16_T, IODBLAGSL * ) ;

/* read laser assist gas flow */
FWLIBAPI int16_t WINAPI cnc_rdlagst( uint16_T, IODBLAGST * ) ;

/* write laser assist gas flow */
FWLIBAPI int16_t WINAPI cnc_wrlagst( uint16_T, IODBLAGST * ) ;

/* read laser power for edge processing */
FWLIBAPI int16_t WINAPI cnc_rdledgprc( uint16_T, IODBLEGPR * ) ;

/* write laser power for edge processing */
FWLIBAPI int16_t WINAPI cnc_wrledgprc( uint16_T, IODBLEGPR * ) ;

/* read laser power for piercing */
FWLIBAPI int16_t WINAPI cnc_rdlprcprc( uint16_T, IODBLPCPR * ) ;

/* write laser power for piercing */
FWLIBAPI int16_t WINAPI cnc_wrlprcprc( uint16_T, IODBLPCPR * ) ;

/* read laser command data */
FWLIBAPI int16_t WINAPI cnc_rdlcmddat( uint16_T, ODBLCMDT * ) ;

/* read displacement */
FWLIBAPI int16_t WINAPI cnc_rdldsplc( uint16_T, int16_t * ) ;

/* write displacement */
FWLIBAPI int16_t WINAPI cnc_wrldsplc( uint16_T, int16_t ) ;

/* read error for axis z */
FWLIBAPI int16_t WINAPI cnc_rdlerrz( uint16_T, int16_t * ) ;

/* read active number */
FWLIBAPI int16_t WINAPI cnc_rdlactnum( uint16_T, ODBLACTN * ) ;

/* read laser comment */
FWLIBAPI int16_t WINAPI cnc_rdlcmmt( uint16_T, ODBLCMMT * ) ;

/* read laser power select */
FWLIBAPI int16_t WINAPI cnc_rdlpwrslt( uint16_T, int16_t * ) ;

/* write laser power select */
FWLIBAPI int16_t WINAPI cnc_wrlpwrslt( uint16_T, int16_t ) ;

/* read laser power controll */
FWLIBAPI int16_t WINAPI cnc_rdlpwrctrl( uint16_T, int16_t * ) ;

/* write laser power controll */
FWLIBAPI int16_t WINAPI cnc_wrlpwrctrl( uint16_T, int16_t ) ;

/* read power correction factor history data */
FWLIBAPI int16_t WINAPI cnc_rdpwofsthis( uint16_T, int32_t, int32_t *, ODBPWOFST * ) ;

/* read management time */
FWLIBAPI int16_t WINAPI cnc_rdmngtime( uint16_T, int32_t, int32_t *, IODBMNGTIME * ) ;

/* write management time */
FWLIBAPI int16_t WINAPI cnc_wrmngtime( uint16_T, int32_t, IODBMNGTIME * ) ;

/* read data related to electrical discharge at power correction ends */
FWLIBAPI int16_t WINAPI cnc_rddischarge( uint16_T, ODBDISCHRG * ) ;

/* read alarm history data related to electrical discharg */
FWLIBAPI int16_t WINAPI cnc_rddischrgalm( uint16_T, int32_t, int32_t *, ODBDISCHRGALM * ) ;

/* read power feedback data */
 FWLIBAPI int16_t WINAPI cnc_rdlppfbdt( uint16_T, IDBLPPFBFG *, int16_t *, IODBLPPFBDT * );

/* write power feedback data */
 FWLIBAPI int16_t WINAPI cnc_wrlppfbdt( uint16_T, IDBLPPFBFG *, int16_t *, IODBLPPFBDT * );

/* get date and time from cnc */
FWLIBAPI int16_t WINAPI cnc_gettimer( uint16_T, IODBTIMER * ) ;

/* set date and time for cnc */
FWLIBAPI int16_t WINAPI cnc_settimer( uint16_T, IODBTIMER * ) ;

/* read timer data from cnc */
FWLIBAPI int16_t WINAPI cnc_rdtimer( uint16_T, int16_t, IODBTIME * ) ;

/* write timer data for cnc */
FWLIBAPI int16_t WINAPI cnc_wrtimer( uint16_T, int16_t, IODBTIME * ) ;

/* read tool controll data */
FWLIBAPI int16_t WINAPI cnc_rdtlctldata( uint16_T, IODBTLCTL * ) ;

/* write tool controll data */
FWLIBAPI int16_t WINAPI cnc_wrtlctldata( uint16_T, IODBTLCTL * ) ;

/* read tool data */
FWLIBAPI int16_t WINAPI cnc_rdtooldata( uint16_T, int16_t, int16_t *, IODBTLDT * ) ;

/* read tool data */
FWLIBAPI int16_t WINAPI cnc_wrtooldata( uint16_T, int16_t, int16_t *, IODBTLDT * ) ;

/* read multi tool data */
FWLIBAPI int16_t WINAPI cnc_rdmultitldt( uint16_T, int16_t, int16_t *, IODBMLTTL * ) ;

/* write multi tool data */
FWLIBAPI int16_t WINAPI cnc_wrmultitldt( uint16_T, int16_t, int16_t *, IODBMLTTL * ) ;

/* read multi tap data */
FWLIBAPI int16_t WINAPI cnc_rdmtapdata( uint16_T, int16_t, int16_t *, IODBMTAP * ) ;

/* write multi tap data */
FWLIBAPI int16_t WINAPI cnc_wrmtapdata( uint16_T, int16_t, int16_t *, IODBMTAP * ) ;

/* read multi-piece machining number */
 FWLIBAPI int16_t WINAPI cnc_rdmultipieceno( uint16_T, int32_t * );

/* read tool information */
FWLIBAPI int16_t WINAPI cnc_rdtoolinfo( uint16_T, ODBPTLINF * ) ;

/* read safetyzone data */
FWLIBAPI int16_t WINAPI cnc_rdsafetyzone( uint16_T, int16_t, int16_t *, IODBSAFE * ) ;

/* write safetyzone data */
FWLIBAPI int16_t WINAPI cnc_wrsafetyzone( uint16_T, int16_t, int16_t *, IODBSAFE * ) ;

/* read toolzone data */
FWLIBAPI int16_t WINAPI cnc_rdtoolzone( uint16_T, int16_t, int16_t *, IODBTLZN * ) ;

/* write toolzone data */
FWLIBAPI int16_t WINAPI cnc_wrtoolzone( uint16_T, int16_t, int16_t *, IODBTLZN * ) ;

/* read active toolzone data */
FWLIBAPI int16_t WINAPI cnc_rdacttlzone( uint16_T, ODBACTTLZN * ) ;

/* read setzone number */
FWLIBAPI int16_t WINAPI cnc_rdsetzone( uint16_T, int16_t * ) ;

/* write setzone number */
FWLIBAPI int16_t WINAPI cnc_wrsetzone( uint16_T, int16_t ) ;

/* read block restart information */
FWLIBAPI int16_t WINAPI cnc_rdbrstrinfo( uint16_T, ODBBRS * ) ;

/* read menu switch signal */
FWLIBAPI int16_t WINAPI cnc_rdmenuswitch( uint16_T, int16_t * ) ;

/* write menu switch signal */
FWLIBAPI int16_t WINAPI cnc_wrmenuswitch( uint16_T, int16_t, int16_t ) ;

/* read tool radius offset for position data */
FWLIBAPI int16_t WINAPI cnc_rdradofs( uint16_T, ODBROFS * ) ;

/* read tool length offset for position data */
FWLIBAPI int16_t WINAPI cnc_rdlenofs( uint16_T, ODBLOFS * ) ;

/* read fixed cycle for position data */
FWLIBAPI int16_t WINAPI cnc_rdfixcycle( uint16_T, ODBFIX * ) ;

/* read coordinate rotate for position data */
FWLIBAPI int16_t WINAPI cnc_rdcdrotate( uint16_T, ODBROT * ) ;

/* read 3D coordinate convert for position data */
FWLIBAPI int16_t WINAPI cnc_rd3dcdcnv( uint16_T, ODB3DCD * ) ;

/* read programable mirror image for position data */
FWLIBAPI int16_t WINAPI cnc_rdmirimage( uint16_T, ODBMIR * ) ;

/* read scaling for position data */
FWLIBAPI int16_t WINAPI cnc_rdscaling( uint16_T, ODBSCL * ) ;

/* read 3D tool offset for position data */
FWLIBAPI int16_t WINAPI cnc_rd3dtofs( uint16_T, ODB3DTO * ) ;

/* read tool position offset for position data */
FWLIBAPI int16_t WINAPI cnc_rdposofs( uint16_T, ODBPOFS * ) ;

/* read hpcc setting data */
FWLIBAPI int16_t WINAPI cnc_rdhpccset( uint16_T, IODBHPST * ) ;

/* write hpcc setting data */
FWLIBAPI int16_t WINAPI cnc_wrhpccset( uint16_T, IODBHPST * ) ;

/* hpcc data auto setting data */
FWLIBAPI int16_t WINAPI cnc_hpccatset( uint16_T ) ;

/* read hpcc tuning data ( parameter input ) */
FWLIBAPI int16_t WINAPI cnc_rdhpcctupr( uint16_T, IODBHPPR * ) ;

/* write hpcc tuning data ( parameter input ) */
FWLIBAPI int16_t WINAPI cnc_wrhpcctupr( uint16_T, IODBHPPR * ) ;

/* read hpcc tuning data ( acc input ) */
FWLIBAPI int16_t WINAPI cnc_rdhpcctuac( uint16_T, IODBHPAC * ) ;

/* write hpcc tuning data ( acc input ) */
FWLIBAPI int16_t WINAPI cnc_wrhpcctuac( uint16_T, IODBHPAC * ) ;

/* hpcc data auto tuning */
FWLIBAPI int16_t WINAPI cnc_hpccattune( uint16_T, int16_t, int16_t * ) ;

/* read hpcc fine level */
FWLIBAPI int16_t WINAPI cnc_hpccactfine( uint16_T, int16_t * ) ;

/* select hpcc fine level */
FWLIBAPI int16_t WINAPI cnc_hpccselfine( uint16_T, int16_t ) ;

/* read rotary table dynamic fixture offset */
 FWLIBAPI int16_t WINAPI cnc_rdfixoffs( uint16_T, int16_t, int16_t, ODBFOFS * ) ;

/* write rotary table dynamic fixture offset */
 FWLIBAPI int16_t WINAPI cnc_wrfixoffs( uint16_T, int16_t, int16_t, ODBFOFS * ) ;

/* read active fixture offset */
FWLIBAPI int16_t WINAPI cnc_rdactfixofs( uint16_T, int16_t, IODBZOFS * ) ;

/* read fixture offset */
FWLIBAPI int16_t WINAPI cnc_rdfixofs( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBZOR * ) ;

/* write fixture offset */
FWLIBAPI int16_t WINAPI cnc_wrfixofs( uint16_T, int16_t, IODBZOR * ) ;

/* read active dynamic offset */
FWLIBAPI int16_t WINAPI cnc_rdactdofs( uint16_T, int16_t, IODBZOFS * ) ;

/* read dynamic offset */
FWLIBAPI int16_t WINAPI cnc_rddofs( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBZOR * ) ;

/* write dynamic offset */
FWLIBAPI int16_t WINAPI cnc_wrdofs( uint16_T, int16_t, IODBZOR * ) ;

/* auto set the machining condition */
 FWLIBAPI int16_t WINAPI cnc_cdautoset( uint16_T, int16_t, int16_t ) ;

/* read the machining condition parameters */
 FWLIBAPI int16_t WINAPI cnc_rdcdslctprm( uint16_T, int16_t, uint16_T *, IODBCTPR * ) ;

/* read the machining condition parameters */
FWLIBAPI int16_t WINAPI cnc_rdcdslctprmm( uint16_T, int16_t, uint16_T *, IODBCTPRM * ) ;

/* Read manual numeric command */
FWLIBAPI int16_t WINAPI cnc_rdjogmdi( uint16_T, ODBJOGCMD *code );

/* Write manual numeric command */
FWLIBAPI int16_t WINAPI cnc_wrjogmdi( uint16_T, char * );

/* Clear manual numeric command */
FWLIBAPI int16_t WINAPI cnc_wrjogmdiclr( uint16_T );

/* read tip of tool for 3D handle */
FWLIBAPI int16_t WINAPI cnc_rd3dtooltip( uint16_T, ODB3DHDL * ) ;

/* read tip of 5 axis manufacture send handle */
FWLIBAPI int16_t WINAPI cnc_rd5dtooltip( uint16_T, int16_t *, ODB5DHDL * ) ;

/* read machine move of 5 axis manufacture send handle */
FWLIBAPI int16_t WINAPI cnc_rd5dmacmov( uint16_T, int16_t *, ODB5DHDL * ) ;

/* read pulse of 5 axis manufacture send handle */
FWLIBAPI int16_t WINAPI cnc_rd5dpulse( uint16_T, int16_t, int16_t *, ODB5DPLS * );

/* clear pulse of 5 axis manufacture send handle */
FWLIBAPI int16_t WINAPI cnc_clr5dplsmov( uint16_T, int16_t ) ;

/* read pulse for 3D handle */
FWLIBAPI int16_t WINAPI cnc_rd3dpulse( uint16_T, ODB3DPLS * ) ;

/* read move overrlap of tool for 3D handle */
FWLIBAPI int16_t WINAPI cnc_rd3dmovrlap( uint16_T, ODB3DHDL * ) ;

/* read change offset for 3D handle */
FWLIBAPI int16_t WINAPI cnc_rd3dofschg( uint16_T, int32_t * ) ;

/* clear pulse and change offset for 3D handle */
FWLIBAPI int16_t WINAPI cnc_clr3dplsmov( uint16_T, int16_t ) ;

/* cycle start */
FWLIBAPI int16_t WINAPI cnc_start( uint16_T );

/* reset CNC */
FWLIBAPI int16_t WINAPI cnc_reset( uint16_T );

/* reset CNC 2 */
FWLIBAPI int16_t WINAPI cnc_reset2( uint16_T );

/* Display of optional message */
FWLIBAPI int16_t WINAPI cnc_dispoptmsg( uint16_T, char * );

/* Reading of answer for optional message display */
FWLIBAPI int16_t WINAPI cnc_optmsgans( uint16_T, int16_t * );

/* Get CNC Model */
FWLIBAPI int16_t WINAPI cnc_getcncmodel( uint16_T, int16_t * );

/* read axis name */
FWLIBAPI int16_t WINAPI cnc_rdaxisname( uint16_T, int16_t *, ODBAXISNAME *);

/* read spindle name */
FWLIBAPI int16_t WINAPI cnc_rdspdlname( uint16_T, int16_t *, ODBSPDLNAME *);

/* read spindle name(m) */
FWLIBAPI int16_t WINAPI cnc_rdspdlnamem( uint16_T, int16_t *, ODBSPDLNAME *);

#ifndef CNC_PPC
/* read extended axis name */
FWLIBAPI int16_t WINAPI cnc_exaxisname( uint16_T, int16_t, int16_t *, char (*)[MAX_AXISNAME] );
#endif

/* read extended axis name */
FWLIBAPI int16_t WINAPI cnc_exaxisname2( uint16_T, int16_t, int16_t, int16_t *, char (*)[MAX_AXISNAME] );

/* read relative axis */
FWLIBAPI int16_t WINAPI cnc_rdrelaxis( uint16_T, int16_t, int16_t, int16_t *, ODBRELAXIS *);

/* read absolute axis */
FWLIBAPI int16_t WINAPI cnc_rdabsaxis( uint16_T, int16_t, int16_t, int16_t, int16_t *, int16_t *);

/* read axis num */
FWLIBAPI int16_t WINAPI cnc_axisnum( uint16_T, int16_t, int16_t * );

/* read axis num */
FWLIBAPI int16_t WINAPI cnc_axisnum2( uint16_T, int16_t, int16_t, int16_t * );

/* read SRAM variable area for C language executor */
FWLIBAPI int16_t WINAPI cnc_rdcexesram( uint16_T, int32_t, void *, int32_t * );

#ifndef CNC_PPC
/* write SRAM variable area for C language executor */
FWLIBAPI int16_t WINAPI cnc_wrcexesram( uint16_T, int32_t, void *, int32_t * );
#endif

/* read maximum size and linear address of SRAM variable area for C language executor */
FWLIBAPI int16_t WINAPI cnc_cexesraminfo( uint16_T, int16_t *, int32_t *, int32_t * );

#ifndef CNC_PPC
/* read maximum size of SRAM variable area for C language executor */
FWLIBAPI int16_t WINAPI cnc_cexesramsize( uint16_T, int32_t * );
#endif

/* Get load torque data of FANUC Auto HMI/T */
FWLIBAPI int16_t WINAPI cnc_rdtrqmonitor( uint16_T, int32_t, void *, int32_t * );

/* read additional workpiece coordinate systems number */
FWLIBAPI int16_t WINAPI cnc_rdcoordnum( uint16_T, int16_t * );

/* converts from FANUC code to Shift JIS code */
FWLIBAPI int16_t WINAPI cnc_ftosjis( uint16_T, char *, char * );

/* Set the unsolicited message parameters */
FWLIBAPI int16_t WINAPI cnc_wrunsolicprm( uint16_T FlibHndl, int16_t number, IODBUNSOLIC *data );

/* Get the unsolicited message parameters */
FWLIBAPI int16_t WINAPI cnc_rdunsolicprm( uint16_T FlibHndl, int16_t number, IODBUNSOLIC *data );

/* Set the unsolicited message parameters(2) */
FWLIBAPI int16_t WINAPI cnc_wrunsolicprm2( uint16_T FlibHndl, int16_t number, IODBUNSOLIC2 *data );

/* Get the unsolicited message parameters(2) */
FWLIBAPI int16_t WINAPI cnc_rdunsolicprm2( uint16_T FlibHndl, int16_t number, IODBUNSOLIC2 *data );

/* Start of unsolicited message */
FWLIBAPI int16_t WINAPI cnc_unsolicstart( uint16_T FlibHndl, int16_t number, HWND hWnd, uint32_T msgno, int16_t chkalive, int16_t *bill );

/* End of unsolicited message */
FWLIBAPI int16_t WINAPI cnc_unsolicstop( uint16_T FlibHndl, int16_t number );

/* Reads the unsolicited message data */
FWLIBAPI int16_t WINAPI cnc_rdunsolicmsg( int16_t bill, IDBUNSOLICMSG *data );

/* Reads the unsolicited message data(2) */
FWLIBAPI int16_t WINAPI cnc_rdunsolicmsg2( int16_t bill, IDBUNSOLICMSG2 *data2 );

/* Set torque limit data */
FWLIBAPI int16_t WINAPI cnc_wrtrqlimit( uint16_T, int16_t, IDBTRQ * );

/* Fine toruqe senshing from save */
FWLIBAPI int16_t WINAPI cnc_ftrq_from_save( uint16_T );

/* Fine toruqe senshing from load */
FWLIBAPI int16_t WINAPI cnc_ftrq_from_load( uint16_T );

/* Fine toruqe sensing from copy */
FWLIBAPI int16_t WINAPI cnc_ftrq_data_copy( uint16_T );

/* Get setting information of "Fine toruqe sensing function" */
FWLIBAPI int16_t WINAPI cnc_rdftrq_info( uint16_T, int16_t, ODBP_FTRQ_PRM_INF * );

/* Get stored data count of "Fine toruqe sensing function" */
FWLIBAPI int16_t WINAPI cnc_rdftrq_storecount( uint16_T, int16_t, int32_t* );

/* Get stored data of "Fine toruqe sensing function" */
FWLIBAPI int16_t WINAPI cnc_rdftrq_data( uint16_T, int16_t, int32_t, int16_t*, uint32_T * );


/* embetb_rdparam_w:read embedded ethernet parameter for FS160is/180is-WB */
FWLIBAPI int16_t WINAPI embetb_rdparam_w( uint16_T, int16_t, IODBEMBETHPRMW * );

/* embetb_wrparam_w:write embedded ethernet parameter for FS160is/180is-WB */
FWLIBAPI int16_t WINAPI embetb_wrparam_w( uint16_T, int16_t, IODBEMBETHPRMW * );

/* read machine specific maintenance item */
FWLIBAPI int16_t WINAPI cnc_rdpm_mcnitem( uint16_T, int16_t, int16_t *, char (*)[62] );

/* write machine specific maintenance item */
FWLIBAPI int16_t WINAPI cnc_wrpm_mcnitem( uint16_T, int16_t, int16_t, char (*)[62] );

/* read cnc maintenance item */
FWLIBAPI int16_t WINAPI cnc_rdpm_cncitem( uint16_T, int16_t, int16_t *, char (*)[62]);

/* read maintenance item status */
FWLIBAPI int16_t WINAPI cnc_rdpm_item( uint16_T, int16_t, int16_t *, IODBPMAINTE * );

/* write maintenance item status */
FWLIBAPI int16_t WINAPI cnc_wrpm_item( uint16_T, int16_t, int16_t, int16_t, IODBPMAINTE * );

/* read CNC memory */
FWLIBAPI int16_t WINAPI cnc_rdcncmem( uint16_T, int16_t, uint32_T, uint32_T, void* );

/* write CNC memory */
FWLIBAPI int16_t WINAPI cnc_wrcncmem( uint16_T, int16_t, uint32_T, uint32_T, void* );

/* read current operation level */
FWLIBAPI int16_t WINAPI cnc_rdope_lvl( uint16_T, int16_t * );

/* set password for operation level */
FWLIBAPI int16_t WINAPI cnc_prot_pswinp( uint16_T, char * );

/* cancel password for operation level */
FWLIBAPI int16_t WINAPI cnc_prot_pswcan( uint16_T );

/* change password for operation level */
FWLIBAPI int16_t WINAPI cnc_prot_pswchg( uint16_T, int16_t , char *, char *, char * );

/* initialize password for operation level */
FWLIBAPI int16_t WINAPI cnc_prot_pswinit( uint16_T, int16_t );

/* read protection level to modify and output */
FWLIBAPI int16_t WINAPI cnc_rdprt_lvl( uint16_T, int16_t, int16_t *, int16_t * );

/* set protection level to modify and output */
FWLIBAPI int16_t WINAPI cnc_wrprt_lvl( uint16_T, int16_t, int16_t, int16_t );

/* check protection state to modify and output */
FWLIBAPI int16_t WINAPI cnc_rdprt_data( uint16_T, int16_t, int16_t * );

/* Read information of File SRAM */
FWLIBAPI int16_t WINAPI cnc_rdfsraminfo( uint16_T, uint32_T, ODBSRAMIF * );
FWLIBAPI int16_t WINAPI cnc_rdfsraminfo2( uint16_T, uint32_T, ODBSRAMIF2 * );

/* Read File SRAM */
FWLIBAPI int16_t WINAPI cnc_rdfile_sram( uint16_T, uint32_T, uint32_T, int32_t, char * );

/* Write File SRAM */
FWLIBAPI int16_t WINAPI cnc_wrfile_sram( uint16_T, uint32_T, uint32_T, int32_t, char * );

/* Request alarm of "Power must be off" */
FWLIBAPI int16_t WINAPI cnc_pwoff_alarm( uint16_T );

FWLIBAPI int16_t WINAPI cnc_req_alarm(uint16_T FlibHndl, int16_t alm_grp, int16_t alm_num);

/* Set Parameter Execute Value */
FWLIBAPI int16_t WINAPI cnc_set_cutcnd_exval( uint16_T );

/* Language Change */
FWLIBAPI int16_t WINAPI cnc_chglang( uint16_T, char );

/* set touch panel mode */
FWLIBAPI int16_t WINAPI cnc_settpnlcalib( uint16_T, int16_t );

/* Get touch panel status & point */
FWLIBAPI int16_t WINAPI cnc_tpl_read( uint16_T FlibHndl, ODBTPNLINTF *data );

/* Get next axis distance */
FWLIBAPI int16_t WINAPI cnc_nextdistance( uint16_T, int16_t, int16_t, IODBAXIS * );

/* Get distribute infomation */
FWLIBAPI int16_t WINAPI cnc_rdipltp( uint16_T, ODBIPL *buf );

/* read CNC system soft series and version (3) */
FWLIBAPI int16_t WINAPI cnc_rdsyssoft3(uint16_T, int16_t , int16_t *, int16_t *, ODBSYSS3 *);

/* Tool Compensation Number Send To NC*/
FWLIBAPI int16_t WINAPI cnc_settolnum_qset(uint16_T, int16_t);

/* Work Coordinates Send To NC */
FWLIBAPI int16_t WINAPI cnc_setzofsnum_qset(uint16_T, int16_t);

/* Get Tool Compensation Number */
FWLIBAPI int16_t WINAPI cnc_gettolnum_qset(uint16_T, int16_t *);

/* Get Work Coordinates */
FWLIBAPI int16_t WINAPI cnc_getzofsnum_qset(uint16_T, int16_t *);

/* Set Tool Offset Direct Input */
FWLIBAPI int16_t WINAPI cnc_wrtofsdrctinp(uint16_T, int16_t, int16_t, REALMES);

/* Read overstore command */
FWLIBAPI int16_t WINAPI cnc_rdoverstore(uint16_T FlibHndl, IODBOVSTR *code);

/* Write overstore command */
FWLIBAPI int16_t WINAPI cnc_wroverstore(uint16_T FlibHndl, IODBOVSTR *code);

/* Clear overstore command */
FWLIBAPI int16_t WINAPI cnc_clroverstore(uint16_T FlibHndl);

/* Change overstore mode */
FWLIBAPI int16_t WINAPI cnc_chgoverstore(uint16_T FlibHndl);

/* Read overstore exec mode */
FWLIBAPI int16_t WINAPI cnc_rdoverstoremode(uint16_T FlibHndl, int32_t *mode );

/* Read program block count */
FWLIBAPI int16_t WINAPI cnc_rdblockcount( uint16_T, ODBPRS * ) ;

/* Read abnormal load torq data */
FWLIBAPI int16_t WINAPI cnc_loadtorq( uint16_T, int16_t motor, int16_t axis, int16_t, ODBLOAD * );

/* Read servo id info */
FWLIBAPI int16_t WINAPI cnc_rdservoid( uint16_T, int16_t, int16_t, ODBCSVID * ) ;

/* Read spindle id info */
FWLIBAPI int16_t WINAPI cnc_rdspindleid( uint16_T, int16_t, int16_t, ODBCSPID * ) ;

/* Read from servo id info */
FWLIBAPI int16_t WINAPI cnc_rdfromservoid( uint16_T, int16_t, ODBCSVID * ) ;

/* Read from spindle id info */
FWLIBAPI int16_t WINAPI cnc_rdfromspindleid( uint16_T, int16_t, ODBCSPID * ) ;

/* Write from servo id info */
FWLIBAPI int16_t WINAPI cnc_wrfromservoid( uint16_T, int16_t, ODBCSVID * ) ;

/* Write from spindle id info */
FWLIBAPI int16_t WINAPI cnc_wrfromspindleid( uint16_T, int16_t, ODBCSPID * ) ;

/* Read servo id info */
FWLIBAPI int16_t WINAPI cnc_rdservoid2( uint16_T, int16_t, int16_t, ODBCSVID2 * ) ;

/* Read spindle id info */
FWLIBAPI int16_t WINAPI cnc_rdspindleid2( uint16_T, int16_t, int16_t, ODBCSPID2 * ) ;

/* Read from servo id info */
FWLIBAPI int16_t WINAPI cnc_rdfromservoid2( uint16_T, int16_t, ODBCSVID2 * ) ;

/* Read from spindle id info */
FWLIBAPI int16_t WINAPI cnc_rdfromspindleid2( uint16_T, int16_t, ODBCSPID2 * ) ;

/* Write from servo id info */
FWLIBAPI int16_t WINAPI cnc_wrfromservoid2( uint16_T, int16_t, ODBCSVID2 * ) ;

/* Write from spindle id info */
FWLIBAPI int16_t WINAPI cnc_wrfromspindleid2( uint16_T, int16_t, ODBCSPID2 * ) ;

/* Clear from spindle id info */
FWLIBAPI int16_t WINAPI cnc_clrfromsvspid( uint16_T ) ;

/* Read tool length offset data */
FWLIBAPI int16_t WINAPI cnc_rdofslength( uint16_T , ODBOFSLEN * ) ;

#ifndef CNC_PPC
/* read number of repeats */
FWLIBAPI int16_t WINAPI cnc_rdrepeatval( uint16_T, int32_t * );
#endif

/* read number of repeats(2) */
FWLIBAPI int16_t WINAPI cnc_rdrepeatval_ext( uint16_T, int32_t *, int32_t * );

/* read registered program number */
FWLIBAPI int16_t WINAPI cnc_getregprgnum( uint16_T, int16_t *, int16_t *, int16_t * );

/* read CNC system hard info */
FWLIBAPI int16_t WINAPI cnc_rdsyshard(uint16_T , int16_t , int16_t *, ODBSYSH *) ;

/* read CNC system soft series and version (3) string name */
FWLIBAPI int16_t WINAPI cnc_rdsyssoft3_str(uint16_T, int16_t , int16_t *, int16_t *, ODBSYSS3_STR *);

/* read CNC system hard info  string name */
FWLIBAPI int16_t WINAPI cnc_rdsyshard_str(uint16_T , int16_t , int16_t *, int16_t * , ODBSYSH_STR *) ;

/* read CNC system path information */
FWLIBAPI int16_t WINAPI cnc_sysinfo_ex( uint16_T, ODBSYSEX * ) ;

/* read processing time stamp data filename ver*/
FWLIBAPI int16_t WINAPI cnc_rdproctime2( uint16_T, ODBPTIME2 * ) ;

/* read Work-piece setting error data */
FWLIBAPI int16_t WINAPI cnc_rdwseterror(uint16_T FlibHndl, int16_t number, int16_t g_num, int16_t code, IODBWSETERROR *data);

/* write Work-piece setting error data */
FWLIBAPI int16_t WINAPI cnc_wrwseterror(uint16_T FlibHndl, int16_t number, int16_t g_num, int16_t code, IODBWSETERROR *data);

/* read Transfer Data (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_rdlrntrnsdata( uint16_T, int16_t, ODBTRNS * ) ;

/* read Learning Info (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_rdlrninfo( uint16_T, int16_t, ODBLRNINFO * );

/* read Learning Info (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_rdlrninfo2( uint16_T, int16_t, ODBLRNINFO2 * );

/* write Learning Info (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_wrlrninfo( uint16_T, int16_t, int16_t, char * );

/* Clear Data (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_clrlrncrnt( uint16_T );

/* Backup Data (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_backuplrn( uint16_T );

/* Restore Data (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_restorlrn( uint16_T );

/* Punch Data (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_punchlrncrnt( uint16_T, char * );

/* Read Data (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_readlrncrnt( uint16_T, char * );

/* Stop transfer (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_stoplrntrns( uint16_T );

/* Status of transfer (Parts Learning Control) */
FWLIBAPI int16_t WINAPI cnc_statlrntrns( uint16_T );

/* read Learning Infol (Learning Control) */
FWLIBAPI int16_t WINAPI cnc_rdlrninfol( uint16_T, int16_t, int16_t, int16_t *, ODBLRNINFOL *);

/* read Profile Data (Learning Control) */
FWLIBAPI int16_t WINAPI cnc_rdlrnprfcmnt( uint16_T, int16_t, int16_t, int16_t *, ODBLRNPRF *);

/* write Profile Data (Learning Control) */
FWLIBAPI int16_t WINAPI cnc_wrlrnprf( uint16_T, int16_t, int16_t, char *);

/* Get option function information */
FWLIBAPI int16_t WINAPI cnc_rdoptfuncinfo(uint16_T, int16_t);

/* Send MDI key information */	
FWLIBAPI int16_t WINAPI cnc_sendkey(uint16_T, ODBKEYINFO *);

/* Get CNC display language */
FWLIBAPI int16_t WINAPI cnc_getlanguage(uint16_T, int16_t *);

/* Start of 3D interference check */
FWLIBAPI int16_t WINAPI cnc_3dchk_start(uint16_T, int16_t, int16_t);

/* Start of 3D interference check(2) */
FWLIBAPI int16_t WINAPI cnc_3dchk_start2(uint16_T);

/* Reads 3D interference chaeck data */
FWLIBAPI int16_t WINAPI cnc_3dchk_rddata(uint16_T, ODB3DCHK *);

/* Reads 3D interference chaeck data(2) */
FWLIBAPI int16_t WINAPI cnc_3dchk_rddata2(uint16_T, ODB3DCHK *, int16_t [], ODB3DMTBINFO [] );

/* Reads 3D interference chaeck data(3) */
FWLIBAPI int16_t WINAPI cnc_3dchk_rddata3(uint16_T, uint32_T *, ODB3DCHK [], int16_t [], ODB3DMTBINFO [] );

/* Reads 3D interference chaeck data(4) */
FWLIBAPI int16_t WINAPI cnc_3dchk_rddata4(uint16_T, uint32_T *, ODB3DCHK [], int16_t *, ODB3DMTBINFO2 [] );

/* End of 3D interference check */
FWLIBAPI int16_t WINAPI cnc_3dchk_end(uint16_T);

/* Get of Program information for 3D interference check */
FWLIBAPI int16_t WINAPI cnc_3dchk_getprginfo(uint16_T, uint32_T *, char *, int32_t *);

/* Stop machine for 3D interference check */
FWLIBAPI int16_t WINAPI cnc_3dchk_mchn_stop(uint16_T, IDB3DMSTOP *);

/* Set axis number to move to program restart coordinates. */
FWLIBAPI int16_t WINAPI cnc_setrstraxis(uint16_T, int16_t);

/* Release axis number to move to program restart coordinates. */
FWLIBAPI int16_t WINAPI cnc_clrrstraxis(uint16_T);

/* read option board memory */
FWLIBAPI int16_t WINAPI cnc_rdcncmem2( uint16_T, int16_t, uint32_T, uint32_T, void*, int16_t );

/* write option board memory */
FWLIBAPI int16_t WINAPI cnc_wrcncmem2( uint16_T, int16_t, uint32_T, uint32_T, void*, int16_t );

/* read background axis data */
FWLIBAPI int16_t WINAPI cnc_rdaxisstatus_bg(uint16_T,  int16_t*,  ODBAXSTS_BG *);

/* Set Smooth Parameter Execute Value */
FWLIBAPI int16_t WINAPI cnc_set_smth_exval( uint16_T );

/* Restart notification of stop program */
FWLIBAPI int16_t WINAPI cnc_confirm_restart( uint16_T, uint16_T );

/* check coresspond focas2 function */
FWLIBAPI int16_t WINAPI cnc_chkversion( uint16_T, uint32_T* condition);

/* search free edge group number and offset number about tool offset data */
FWLIBAPI int16_t WINAPI cnc_tool_srh_free_min_num( uint16_T, ODBTL_FREE_NUM *);

/* Read transfer detection initial data number */
FWLIBAPI int16_t WINAPI cnc_rdmtdtnid( uint16_T, uint32_T *);

/* Start transfer detection search */
FWLIBAPI int16_t WINAPI cnc_mtdtnstart( uint16_T);

/* get screen owner number */
FWLIBAPI int16_t WINAPI cnc_getscrowner( uint16_T, int16_t * );

/* Read data from HSSB CRAM for EDM */
FWLIBAPI int16_t WINAPI cnc_rdedmcram( uint16_T, uint32_T, int16_t, int32_t *, void * ) ;

/* Write data to HSSB CRAM for EDM */
FWLIBAPI int16_t WINAPI cnc_wredmcram( uint16_T, uint32_T, int16_t, int32_t *, void * ) ;

/* Read modal integer value (Auto HMI/T) */
FWLIBAPI int16_t WINAPI cnc_rdmodalval( uint16_T, int16_t, int32_t * );

/* Read servo analog data (Auto HMI/T) */
FWLIBAPI int16_t WINAPI cnc_rdsvmonitor( uint16_T, int16_t, int16_t, int16_t *, int32_t * );

/* Read spindle analog data (Auto HMI/T) */
FWLIBAPI int16_t WINAPI cnc_rdspmonitor( uint16_T, int16_t, int16_t, int16_t *, int32_t * );

/* Write special F signal */
FWLIBAPI int16_t WINAPI cnc_wrsignal_f(uint16_T, int16_t, uint32_T);

/* NCGuide protect cancel */
FWLIBAPI int16_t WINAPI cnc_ncg_protcancel( uint16_T, char *, int32_t );

#ifndef CNC_PPC
FWLIBAPI int16_t WINAPI cnc_set_prps( uint16_T, int16_t, char *, uint32_T );
FWLIBAPI int16_t WINAPI cnc_reset_prps( uint16_T, int16_t, char * );
FWLIBAPI int16_t WINAPI cnc_status_prps( uint16_T, int16_t, uint32_T * );
#endif

/*-----*/
/* CNC */
/*-----*/

FWLIBAPI int16_t WINAPI cnc_srcsrsvchnl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_srcsrdidinfo( uint16_T, int32_t, int16_t, int16_t, IODBIDINF * );

FWLIBAPI int16_t WINAPI cnc_srcswridinfo( uint16_T, IODBIDINF * );

FWLIBAPI int16_t WINAPI cnc_srcsstartrd( uint16_T, int32_t, int16_t );

FWLIBAPI int16_t WINAPI cnc_srcsstartwrt( uint16_T, int32_t, int16_t );

FWLIBAPI int16_t WINAPI cnc_srcsstopexec( uint16_T );

FWLIBAPI int16_t WINAPI cnc_srcsrdexstat( uint16_T, ODBSRCSST * );

FWLIBAPI int16_t WINAPI cnc_srcsrdopdata( uint16_T, int32_t, int32_t *, void * );

FWLIBAPI int16_t WINAPI cnc_srcswropdata( uint16_T, int32_t, int32_t, void * );

FWLIBAPI int16_t WINAPI cnc_srcsfreechnl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_srcsrdlayout( uint16_T, ODBSRCSLYT * );

FWLIBAPI int16_t WINAPI cnc_srcsrddrvcp( uint16_T, int16_t * );


/*----------------------------*/
/* CNC : Graphic command data */
/*----------------------------*/

/* Start drawing position */
FWLIBAPI int16_t WINAPI cnc_startdrawpos( uint16_T );

/* Stop drawing position */
FWLIBAPI int16_t WINAPI cnc_stopdrawpos( uint16_T );

/* Start dynamic graphic */
FWLIBAPI int16_t WINAPI cnc_startdyngrph( uint16_T );

/* Stop dynamic graphic */
FWLIBAPI int16_t WINAPI cnc_stopdyngrph( uint16_T );

/* Read graphic command data */
FWLIBAPI int16_t WINAPI cnc_rdgrphcmd( uint16_T, int16_t *, int16_t * );

/* Update graphic command read pointer */
FWLIBAPI int16_t WINAPI cnc_wrgrphcmdptr( uint16_T, int16_t );

/* Read cancel flag */
FWLIBAPI int16_t WINAPI cnc_rdgrphcanflg( uint16_T, int16_t * );

/* Clear graphic command */
FWLIBAPI int16_t WINAPI cnc_clrgrphcmd( uint16_T );

/* Read actual position data for wire */
FWLIBAPI int16_t WINAPI cnc_rdactpos_w( uint16_T, int16_t, ODBWACT * );

/* copy CNC data for multi path system */
FWLIBAPI int16_t WINAPI cnc_data_copy( uint16_T, int16_t, int16_t, int16_t );

/*---------------*/
/* CNC : GRAPHIC */
/*---------------*/

/* Start position sampling */
FWLIBAPI int16_t WINAPI cnc_start_grppos( uint16_T );

/* Stop position sampling */
FWLIBAPI int16_t WINAPI cnc_stop_grppos( uint16_T );

/* Read position data */
FWLIBAPI int16_t WINAPI cnc_rd_grppos( uint16_T, int16_t *, ODBGRPPOS * );

/* Read drawing axis information */
FWLIBAPI int16_t WINAPI cnc_rd_grpaxisinfo( uint16_T, int16_t *, ODBGRPAXIS * );

/* Start position sampling */
FWLIBAPI int16_t WINAPI cnc_start_grppos3( uint16_T );

/* Stop position sampling */
FWLIBAPI int16_t WINAPI cnc_stop_grppos3( uint16_T );

/* Read position data */
FWLIBAPI int16_t WINAPI cnc_rd_grppos3( uint16_T, int16_t *, ODBGRPPOS * );

/*---------------------------*/
/* CNC : Servo learning data */
/*---------------------------*/

#ifndef CNC_PPC
/* Servo learning data read start */
FWLIBAPI int16_t WINAPI cnc_svdtstartrd( uint16_T, int16_t );

/* Servo learning data write start */
FWLIBAPI int16_t WINAPI cnc_svdtstartwr( uint16_T, int16_t );

/* Servo learning data read end */
FWLIBAPI int16_t WINAPI cnc_svdtendrd( uint16_T );

/* Servo learning data write end */
FWLIBAPI int16_t WINAPI cnc_svdtendwr( uint16_T );

/* Servo learning data read/write stop */
FWLIBAPI int16_t WINAPI cnc_svdtstopexec( uint16_T );

/* Servo learning data read from I/F buffer */
FWLIBAPI int16_t WINAPI cnc_svdtrddata( uint16_T, int16_t *, int32_t *, void * );

/* Servo learning data write to I/F buffer */
FWLIBAPI int16_t WINAPI cnc_svdtwrdata( uint16_T, int16_t *, int32_t *, void * );
#endif

/* Servo learning data read start (dual channel) */
FWLIBAPI int16_t WINAPI cnc_svdtstartrd2( uint16_T, int16_t, int16_t );

/* Servo learning data write start (dual channel) */
FWLIBAPI int16_t WINAPI cnc_svdtstartwr2( uint16_T, int16_t, int16_t );

/* Servo learning data read end (dual channel) */
FWLIBAPI int16_t WINAPI cnc_svdtendrd2( uint16_T );

/* Servo learning data write end (dual channel) */
FWLIBAPI int16_t WINAPI cnc_svdtendwr2( uint16_T );

/* Servo learning data read from I/F buffer (dual channel) */
FWLIBAPI int16_t WINAPI cnc_svdtrddata2( uint16_T, int16_t *, int32_t *, void *, int16_t *, int32_t *, void * );

/* Servo learning data write to I/F buffer (dual channel) */
FWLIBAPI int16_t WINAPI cnc_svdtwrdata2( uint16_T, int16_t *, int32_t *, void *, int16_t *, int32_t *, void * );


/*-----*/
/* CNC */
/*-----*/
FWLIBAPI int16_t WINAPI cnc_sdsetchnl( uint16_T, int16_t, IDBCHAN * );

FWLIBAPI int16_t WINAPI cnc_sdsetchnl2(uint16_T, int16_t, IDBCHAN2 * );

FWLIBAPI int16_t WINAPI cnc_sdclrchnl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sdstartsmpl( uint16_T, int16_t, int32_t, int16_t * );

FWLIBAPI int16_t WINAPI cnc_sdstartsmplb( uint16_T, int16_t, int32_t, int16_t, int16_t, int32_t );

FWLIBAPI int16_t WINAPI cnc_sdstartsmpl2( uint16_T, int16_t, int16_t, TRG_DATA * );

FWLIBAPI int16_t WINAPI cnc_sdcancelsmpl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sdreadsmpl( uint16_T, int16_t *, int32_t, ODBSD * );

FWLIBAPI int16_t WINAPI cnc_sdreadsmpl2( uint16_T, uint16_T* trg, int32_t, ODBSD * );

FWLIBAPI int16_t WINAPI cnc_sdendsmpl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sdendsmpl2( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sdread1shot( uint16_T, uint16_T* );

FWLIBAPI int16_t WINAPI cnc_sdbetainfo( uint16_T, int16_t *, ODBBINFO * );

FWLIBAPI int16_t WINAPI cnc_sfbsetchnl( uint16_T, int16_t, int32_t, IDBSFBCHAN * );

FWLIBAPI int16_t WINAPI cnc_sfbclrchnl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sfbstartsmpl( uint16_T, int16_t, int32_t );

FWLIBAPI int16_t WINAPI cnc_sfbcancelsmpl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sfbreadsmpl( uint16_T, int16_t *, int32_t, ODBSD * );

FWLIBAPI int16_t WINAPI cnc_sfbendsmpl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sdtsetchnl( uint16_T, int16_t, int32_t, IDBSDTCHAN * );

FWLIBAPI int16_t WINAPI cnc_sdtsetchnl2( uint16_T, int16_t, int32_t, IDBSDTCHAN2 * );

FWLIBAPI int16_t WINAPI cnc_sdtclrchnl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sdtstartsmpl( uint16_T, int16_t, int32_t );

FWLIBAPI int16_t WINAPI cnc_sdtstartsmpl2( uint16_T, int16_t, int16_t, TRG_DATA * );

FWLIBAPI int16_t WINAPI cnc_sdtcancelsmpl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sdtreadsmpl( uint16_T, int16_t *, int32_t, ODBSD * );

FWLIBAPI int16_t WINAPI cnc_sdtreadsmpl2( uint16_T, uint16_T *, int32_t, ODBSD * );

FWLIBAPI int16_t WINAPI cnc_sdtendsmpl( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sdtendsmpl2( uint16_T );

FWLIBAPI int16_t WINAPI cnc_sdtread1shot( uint16_T, uint16_T * );


/*----------------------------*/
/* CNC : NC display function  */
/*----------------------------*/

/* Start NC display */
FWLIBAPI int16_t WINAPI cnc_startnccmd( uint16_T );

#ifndef CNC_PPC
/* Start NC display (2) */
FWLIBAPI int16_t WINAPI cnc_startnccmd2( uint16_T, char * );
#endif

/* Stop NC display */
FWLIBAPI int16_t WINAPI cnc_stopnccmd( uint16_T );

/* Get NC display mode */
FWLIBAPI int16_t WINAPI cnc_getdspmode( uint16_T, int16_t * );

//#ifndef CNC_PPC
/* Set current display screen */
FWLIBAPI int16_t WINAPI cnc_setcurscrn( uint16_T, int16_t );
//#endif

/* Change status of SDF */
FWLIBAPI int16_t WINAPI cnc_sdfstatchg( uint16_T, int16_t, int16_t, int, int32_t );

/* Set manager application for SDF */
FWLIBAPI int16_t WINAPI cnc_sdfmnghwnd( uint16_T, int16_t, HWND, uint32_T );

/* Get file name for BPRNT/DPRNT */
FWLIBAPI int16_t WINAPI cnc_getprntname( uint16_T, char * );


/*------------------------------------*/
/* CNC : Remote diagnostics function  */
/*------------------------------------*/

/* Start remote diagnostics function */
FWLIBAPI int16_t WINAPI cnc_startrmtdgn( uint16_T );

/* Stop remote diagnostics function */
FWLIBAPI int16_t WINAPI cnc_stoprmtdgn( uint16_T );

/* Read data from remote diagnostics I/F */
FWLIBAPI int16_t WINAPI cnc_rdrmtdgn( uint16_T, int32_t *, char * );

/* Write data to remote diagnostics I/F */
FWLIBAPI int16_t WINAPI cnc_wrrmtdgn( uint16_T, int32_t *, char * );

/* Set CommStatus of remote diagnostics I/F area */
FWLIBAPI int16_t WINAPI cnc_wrcommstatus( uint16_T, int16_t );

/* Check remote diagnostics I/F */
FWLIBAPI int16_t WINAPI cnc_chkrmtdgn( uint16_T );

/* remote diagnosis start */
FWLIBAPI int16_t WINAPI cnc_pdf_startrmtdgn( uint16_T, char, int16_t, OUT_RMTDGNINFO * ) ;

/* remote diagnosis end */
FWLIBAPI int16_t WINAPI cnc_pdf_stoprmtdgn( uint16_T, char, int16_t ) ;

/* read remote diagnosis information */
FWLIBAPI int16_t WINAPI cnc_pdf_rdrmtdgn( uint16_T, char, int16_t *, OUT_RMTDGNINFO * ) ;

/* change inguiry number */
FWLIBAPI int16_t WINAPI cnc_pdf_chginquiry( uint16_T, char, int16_t ) ;

/*-------------------------*/
/* CNC : FS18-LN function  */
/*-------------------------*/

/* read allowance */
FWLIBAPI int16_t WINAPI cnc_allowance( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read allowanced state */
FWLIBAPI int16_t WINAPI cnc_allowcnd( uint16_T, int16_t, int16_t, ODBCAXIS * ) ;

/* set work zero */
FWLIBAPI int16_t WINAPI cnc_workzero( uint16_T, int16_t, IODBZOFS * ) ;

/* set slide position */
FWLIBAPI int16_t WINAPI cnc_slide( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/*---------------------------*/
/* CNC : FS31i-LNB function  */
/*---------------------------*/

/* read feed mode */
FWLIBAPI int16_t WINAPI cnc_rdfeedmode( uint16_T, int16_t, int16_t * ) ;

/*-----------*/
/* Oxxxxxxxx */
/*-----------*/

/* start uploading NC program */
FWLIBAPI int16_t WINAPI cnc_upstarto8( uint16_T, int32_t ) ;

/* search specified program */
FWLIBAPI int16_t WINAPI cnc_searcho8( uint16_T, int32_t ) ;

/* delete specified program */
FWLIBAPI int16_t WINAPI cnc_deleteo8( uint16_T, int32_t ) ;

/* read program directory */
FWLIBAPI int16_t WINAPI cnc_rdprogdiro8( uint16_T, int16_t, int32_t, int32_t, uint16_T, PRGDIR * ) ;

/* read program number under execution */
FWLIBAPI int16_t WINAPI cnc_rdprgnumo8( uint16_T, ODBPROO8 * ) ;

/* read all dynamic data */
FWLIBAPI int16_t WINAPI cnc_rddynamico8( uint16_T, int16_t, int16_t, ODBDYO8 * ) ;

/* read execution pointer for MDI operation */
FWLIBAPI int16_t WINAPI cnc_rdmdipntro8( uint16_T, ODBMDIPO8 * ) ;

/* read program directory 2 */
FWLIBAPI int16_t WINAPI cnc_rdprogdir2o8( uint16_T, int16_t, int32_t *, int16_t *, PRGDIR2O8 * ) ;

#ifndef CNC_PPC
/* read digit of program number */
FWLIBAPI int16_t WINAPI cnc_progdigit( uint16_T, int16_t * );
#endif

/*----------------------------------*/
/* CNC: Teaching data I/F function  */
/*----------------------------------*/

/* Teaching data get start */
FWLIBAPI int16_t WINAPI cnc_startgetdgdat( uint16_T FlibHndl );

/* Teaching data get stop */
FWLIBAPI int16_t WINAPI cnc_stopgetdgdat( uint16_T FlibHndl );

/* Teaching data read */
FWLIBAPI int16_t WINAPI cnc_rddgdat( uint16_T FlibHndl, int16_t * , int16_t * );

/* Teaching data read pointer write */
FWLIBAPI int16_t WINAPI cnc_wrdgdatptr( uint16_T FlibHndl, int16_t );

/* Teaching data clear */
FWLIBAPI int16_t WINAPI cnc_clrdgdat( uint16_T FlibHndl );


/*---------------------------------*/
/* CNC : C-EXE SRAM file function  */
/*---------------------------------*/

/* open C-EXE SRAM file */
FWLIBAPI int16_t WINAPI cnc_opencexefile( uint16_T, char *, int16_t, int16_t );

/* close C-EXE SRAM file */
FWLIBAPI int16_t WINAPI cnc_closecexefile( uint16_T );

/* read C-EXE SRAM file */
FWLIBAPI int16_t WINAPI cnc_rdcexefile( uint16_T, unsigned char *, uint32_T * );

/* write C-EXE SRAM file */
FWLIBAPI int16_t WINAPI cnc_wrcexefile( uint16_T, unsigned char *, uint32_T * );

/* read C-EXE SRAM disk directory */
FWLIBAPI int16_t WINAPI cnc_cexedirectory( uint16_T, char *, uint16_T *,
		uint16_T, CFILEINFO * );


/*------------*/
/* CNC : FSSB */
/*------------*/

/* read amp information */
FWLIBAPI int16_t WINAPI cnc_rdfssb_amp( uint16_T, int16_t, int16_t, int16_t *, ODBFSSBAMP * );

/* write axis number */
FWLIBAPI int16_t WINAPI cnc_wrfssb_axis_num( uint16_T, int16_t, int16_t, int16_t, int16_t * );

/* read pulse module information */
FWLIBAPI int16_t WINAPI cnc_rdfssb_plsmod( uint16_T, int16_t, int16_t, int16_t *, ODBPLSMDL * );

/* read axis information */
FWLIBAPI int16_t WINAPI cnc_rdfssb_axis( uint16_T, int16_t, int16_t *, IODBFSSBAXIS * );

/* write axis information */
FWLIBAPI int16_t WINAPI cnc_wrfssb_axis( uint16_T, int16_t, int16_t, int16_t, IODBFSSBAXIS * );

/* read maintenance information */
FWLIBAPI int16_t WINAPI cnc_rdfssb_mainte( uint16_T, int16_t, int16_t *, ODBFSSBMT * );

/* read FSSB information */
FWLIBAPI int16_t WINAPI cnc_rdfssb_info( uint16_T, ODBFSSBINFO * );

/* set automatic FSSB settings */
FWLIBAPI int16_t WINAPI cnc_fssb_autoset( uint16_T, int16_t );

/* reset FSSB settings */
FWLIBAPI int16_t WINAPI cnc_fssb_reset( uint16_T, int16_t );

/* FSSB fpr 30iB (IFSB) */
FWLIBAPI int16_t WINAPI cnc_rdifsb_info(uint16_T , int16_t, ODBIFSBINFO *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_slvunt(uint16_T, int16_t, int16_t, int16_t, int16_t *, ODBIFSBSLVUNT *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_slu_sv(uint16_T, int16_t, int16_t, int16_t *, ODBIFSBSLUSV *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_slu_sp(uint16_T, int16_t, int16_t, int16_t *, ODBIFSBSLUSP *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_slu_pm(uint16_T, int16_t, int16_t, int16_t *, ODBIFSBSLUPM *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_as_amp_sv(uint16_T, int16_t, int16_t, int16_t *, ODBIFSBSVAMP *);
FWLIBAPI int16_t WINAPI cnc_wrifsb_as_axis_num(uint16_T, int16_t, int16_t, int16_t, int16_t *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_as_hrv(uint16_T, uint16_T *);
FWLIBAPI int16_t WINAPI cnc_wrifsb_as_hrv(uint16_T, uint16_T);
FWLIBAPI int16_t WINAPI cnc_rdifsb_as_amp_sp(uint16_T, int16_t, int16_t, int16_t *, ODBIFSBSPAMP *);
FWLIBAPI int16_t WINAPI cnc_wrifsb_as_spdl_num(uint16_T, int16_t, int16_t, int16_t, int16_t *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_as_plsmod(uint16_T, int16_t, int16_t, int16_t *, ODBIFSBPLSMDL *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_as_sv_axis(uint16_T, int16_t, int16_t *, IODBIFSBAXIS *);
FWLIBAPI int16_t WINAPI cnc_wrifsb_as_sv_axis(uint16_T, int16_t, int16_t, int16_t, IODBIFSBAXIS *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_mainte_sv(uint16_T, int16_t, int16_t *, ODBIFSBMNTSV *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_mainte_sp(uint16_T, int16_t, int16_t *, ODBIFSBMNTSP *);
FWLIBAPI int16_t WINAPI cnc_ifsb_autoset(uint16_T);
FWLIBAPI int16_t WINAPI cnc_ifsb_reset(uint16_T);
FWLIBAPI int16_t WINAPI cnc_rdifsb_almstate(uint16_T, char *, char *);
FWLIBAPI int16_t WINAPI cnc_rdifsb_sysalm(uint16_T, int16_t, ODBIFSBSYSALM* );
FWLIBAPI int16_t WINAPI cnc_rdifsb_fssbunt(uint16_T, int16_t, int16_t, int16_t*, ODBIFSBFSSBUNT* );
FWLIBAPI int16_t WINAPI cnc_rdifsb_comstatdtl(uint16_T, int16_t, int16_t, int16_t, int16_t*, ODBIFSBCOMSTATDTL* );
FWLIBAPI int16_t WINAPI cnc_rdifsb_warning_cnt(uint16_T, int16_t* );
FWLIBAPI int16_t WINAPI cnc_rdifsb_warning_msg(uint16_T, int16_t, int16_t*, ODBIFSBWARNINGMSG* );
FWLIBAPI int16_t WINAPI cnc_rdifsb_warnhst_cnt(uint16_T, int16_t* );
FWLIBAPI int16_t WINAPI cnc_rdifsb_warnhst_msg(uint16_T, int16_t, int16_t*, ODBIFSBWARNHSTMSG* );

#if defined (PMD) /* only Power Mate D/H */
/*------------------------------*/
/* MAXIS: Axis Movement Control */
/*------------------------------*/

/* cnc_opdi:signal operation command */
FWLIBAPI int16_t WINAPI cnc_opdi(uint16_T,int16_t,ODBOPDI *);

/* cnc_refpoint:reference point return */
FWLIBAPI int16_t WINAPI cnc_refpoint(uint16_T,int16_t,int16_t,int16_t,ODBEXEC *);

/* cnc_abspoint:absolute movement */
FWLIBAPI int16_t WINAPI cnc_abspoint(uint16_T,int16_t,int16_t,int16_t,int32_t,ODBPOS *,ODBEXEC *);

/* cnc_incpoint:incremental movement */
FWLIBAPI int16_t WINAPI cnc_incpoint(uint16_T,int16_t,int16_t,int16_t,int32_t,ODBPOS *,ODBEXEC *);

/* cnc_dwell:dwell */
FWLIBAPI int16_t WINAPI cnc_dwell(uint16_T,int16_t,int16_t,int16_t,ODBPOS *,ODBEXEC *);

/* cnc_coordre:coordinate establihment */
FWLIBAPI int16_t WINAPI cnc_coordre(uint16_T,int16_t,int16_t,int16_t,ODBPOS *,ODBEXEC *);

/* cnc_exebufstat:reading of the executive buffer condition */
FWLIBAPI int16_t WINAPI cnc_exebufstat(uint16_T,ODBEXEC *);

/* cnc_finstate:Reading of the execution completion condition */
FWLIBAPI int16_t WINAPI cnc_finstate(uint16_T,ODBFIN *);

/* cnc_setfin:Release of the reading mode of the execution completion condition */
FWLIBAPI int16_t WINAPI cnc_setfin(uint16_T,ODBFIN *);
#endif


/*-----*/
/* PMC */
/*-----*/

/* read message from PMC to MMC */
FWLIBAPI int16_t WINAPI pmc_rdmsg( uint16_T, int16_t *, int16_t * ) ;

/* write message from MMC to PMC */
FWLIBAPI int16_t WINAPI pmc_wrmsg( uint16_T, int16_t, int16_t * ) ;

/* read message from PMC to MMC(conditional) */
FWLIBAPI int16_t WINAPI pmc_crdmsg( uint16_T, int16_t *, int16_t * ) ;

/* write message from MMC to PMC(conditional) */
FWLIBAPI int16_t WINAPI pmc_cwrmsg( uint16_T, int16_t, int16_t * ) ;

/* read PMC data(area specified) */
#if !defined (PMD)
FWLIBAPI int16_t WINAPI pmc_rdpmcrng( uint16_T, int16_t, int16_t, uint16_T, uint16_T, uint16_T, IODBPMC * ) ;
#else
FWLIBAPI int16_t WINAPI pmc_rdpmcrng( uint16_T, int16_t, int16_t, int16_t, int16_t, int16_t, IODBPMC *);
#endif

/* write PMC data(area specified) */
#if !defined (PMD)
FWLIBAPI int16_t WINAPI pmc_wrpmcrng( uint16_T, uint16_T, IODBPMC * ) ;
#else
FWLIBAPI int16_t WINAPI pmc_wrpmcrng( uint16_T, int16_t, IODBPMC *);
#endif

/* write PMC data2(area specified) */
FWLIBAPI int16_t WINAPI pmc_wrpmcrng2( uint16_T, uint16_T, IODBPMC * ) ;

FWLIBAPI int16_t WINAPI pmc_rdwrpmcrng( uint16_T, int16_t, IODBRWPMC [] );

/* read data from extended backup memory */
FWLIBAPI int16_t WINAPI pmc_rdkpm( uint16_T, uint32_T, char *, uint16_T ) ;

/* write data to extended backup memory */
FWLIBAPI int16_t WINAPI pmc_wrkpm( uint16_T, uint32_T, char *, uint16_T ) ;

/* read data from extended backup memory 2 */
 FWLIBAPI int16_t WINAPI pmc_rdkpm2( uint16_T, uint32_T, char *, uint32_T ) ;

/* write data to extended backup memory 2 */
 FWLIBAPI int16_t WINAPI pmc_wrkpm2( uint16_T, uint32_T, char *, uint32_T ) ;

/* read maximum size of extended backup memory */
FWLIBAPI int16_t WINAPI pmc_kpmsiz( uint16_T, uint32_T * ) ;

/* read informations of PMC data */
FWLIBAPI int16_t WINAPI pmc_rdpmcinfo( uint16_T, int16_t, ODBPMCINF * ) ;

/* read PMC parameter data table contorol data */
FWLIBAPI int16_t WINAPI pmc_rdcntldata( uint16_T, int16_t, int16_t, int16_t, IODBPMCCNTL * ) ;

/* write PMC parameter data table contorol data */
FWLIBAPI int16_t WINAPI pmc_wrcntldata( uint16_T, int16_t, IODBPMCCNTL * ) ;

/* read PMC parameter data table contorol data group number */
FWLIBAPI int16_t WINAPI pmc_rdcntlgrp( uint16_T, int16_t * ) ;

/* write PMC parameter data table contorol data group number */
FWLIBAPI int16_t WINAPI pmc_wrcntlgrp( uint16_T, int16_t ) ;

/* read PMC alarm message */
FWLIBAPI int16_t WINAPI pmc_rdalmmsg( uint16_T, int16_t, int16_t *, int16_t *, ODBPMCALM * ) ;

/* get detail error for pmc */
FWLIBAPI int16_t WINAPI pmc_getdtailerr( uint16_T, ODBPMCERR * ) ;

/* read PMC memory data */
FWLIBAPI int16_t WINAPI pmc_rdpmcmem( uint16_T, int16_t, int32_t, int32_t, void * ) ;

/* write PMC memory data */
FWLIBAPI int16_t WINAPI pmc_wrpmcmem( uint16_T, int16_t, int32_t, int32_t, void * ) ;

/* read PMC memory data */
FWLIBAPI int16_t WINAPI pmc_rdpmcsemem( uint16_T, int16_t, int32_t, int32_t, void * ) ;

/* write PMC memory data */
FWLIBAPI int16_t WINAPI pmc_wrpmcsemem( uint16_T, int16_t, int32_t, int32_t, void * ) ;

/* read pmc title data */
FWLIBAPI int16_t WINAPI pmc_rdpmctitle( uint16_T, ODBPMCTITLE * ) ;
FWLIBAPI int16_t WINAPI pmc_rdpmctitle2( uint16_T, ODBPMCTITLE2 * ) ;

/* read PMC parameter start */
 FWLIBAPI int16_t WINAPI pmc_rdprmstart( uint16_T ) ;

/* read PMC parameter */
 FWLIBAPI int16_t WINAPI pmc_rdpmcparam( uint16_T, int32_t *, char * ) ;

/* read PMC parameter end */
 FWLIBAPI int16_t WINAPI pmc_rdprmend( uint16_T ) ;

/* write PMC parameter start */
 FWLIBAPI int16_t WINAPI pmc_wrprmstart( uint16_T ) ;

/* write PMC parameter */
 FWLIBAPI int16_t WINAPI pmc_wrpmcparam( uint16_T, int32_t *, char * ) ;

/* write PMC parameter end */
 FWLIBAPI int16_t WINAPI pmc_wrprmend( uint16_T ) ;

/* read PMC data */
FWLIBAPI int16_t WINAPI pmc_rdpmcrng_ext( uint16_T, int16_t, IODBPMCEXT * ) ;

/* write PMC I/O link assigned data */
FWLIBAPI int16_t WINAPI pmc_wriolinkdat( uint16_T, int32_t, int32_t, uint32_T, void *, uint32_T ) ;

/* read PMC address information */
FWLIBAPI int16_t WINAPI pmc_rdpmcaddr( uint16_T, int32_t, uint16_T, uint32_T, ODBPMCADR * );

/*j select PMC unit */
FWLIBAPI int16_t WINAPI pmc_select_pmc_unit( uint16_T h, int32_t unittype );

/*j get current PMC unit */
FWLIBAPI int16_t WINAPI pmc_get_current_pmc_unit( uint16_T h, int32_t * unittype );

/*j get number of PMC */
FWLIBAPI int16_t WINAPI pmc_get_number_of_pmc(uint16_T h, int32_t * piNum);

/*j get PMC unit types */
FWLIBAPI int16_t WINAPI pmc_get_pmc_unit_types( uint16_T h, int32_t unittypes[], int32_t * count );

/* set PMC Timer type */
FWLIBAPI int16_t WINAPI pmc_set_timer_type( uint16_T h, uint16_T, uint16_T, int16_t * );

/* get PMC Timer type */
FWLIBAPI int16_t WINAPI pmc_get_timer_type( uint16_T h, uint16_T, uint16_T, int16_t * );

/* Reads sequence program and momory type */
FWLIBAPI int16_t WINAPI pmc_read_seq_program_and_memory_type( uint16_T, ODBPMCLADMEMTYPE * );

/* read PMC parameter extend relay contorol data */
FWLIBAPI int16_t WINAPI pmc_rdcntlexrelay( uint16_T, int16_t, int16_t, int16_t, IODBPMCCNTL * ) ;

/* write PMC parameter extend relay contorol data */
FWLIBAPI int16_t WINAPI pmc_wrcntlexrelay( uint16_T, int16_t, IODBPMCCNTL * ) ;

/* read PMC parameter extend relay contorol data group number */
FWLIBAPI int16_t WINAPI pmc_rdcntl_exrelay_grp( uint16_T, int16_t * ) ;

/* write PMC parameter extend relay contorol data group number */
FWLIBAPI int16_t WINAPI pmc_wrcntl_exrelay_grp( uint16_T, int16_t ) ;

/* convert to PMC address information from address or symbol string */
FWLIBAPI int16_t WINAPI pmc_convert_from_string_to_address( uint16_T, const char *, ODBPMCADRINFO * );

/*j select divided ladder */
FWLIBAPI int16_t WINAPI pmc_select_divided_ladder( uint16_T h, int32_t divnumber );

/*j get current divided ladder */
FWLIBAPI int16_t WINAPI pmc_get_current_divided_ladder( uint16_T h, int32_t * divnumber );

/*j get number of Ladder */
FWLIBAPI int16_t WINAPI pmc_get_number_of_ladder( uint16_T h, int32_t * number );

/*j get Divided Ladders */
FWLIBAPI int16_t WINAPI pmc_get_divided_ladders( uint16_T h, int32_t divnums[], int32_t * count );

FWLIBAPI int16_t WINAPI pmc_rdioconfigtitle(uint16_T, int32_t, char *);

FWLIBAPI int16_t WINAPI pmc_rdmessagetitle(uint16_T, int32_t, char *);

/*----------------------------*/
/* PMC : PROFIBUS function    */
/*----------------------------*/

/* read PROFIBUS information data */
FWLIBAPI int16_t WINAPI pmc_prfrdinfo( uint16_T, ODBPRFINFO * ) ;

/* read PROFIBUS configration data */
FWLIBAPI int16_t WINAPI pmc_prfrdconfig( uint16_T, ODBPRFCNF * ) ;

/* read bus parameter for master function */
FWLIBAPI int16_t WINAPI pmc_prfrdbusprm( uint16_T, IODBBUSPRM * ) ;

/* write bus parameter for master function */
FWLIBAPI int16_t WINAPI pmc_prfwrbusprm( uint16_T, IODBBUSPRM * ) ;

/* read slave parameter for master function */
FWLIBAPI int16_t WINAPI pmc_prfrdslvprm( uint16_T, int16_t, void * ) ;

/* write slave parameter for master function */
FWLIBAPI int16_t WINAPI pmc_prfwrslvprm( uint16_T, int16_t, void * ) ;

/* read allocation address for master function */
FWLIBAPI int16_t WINAPI pmc_prfrdallcadr( uint16_T, int16_t, IODBPRFADR * ) ;

/* set allocation address for master function */
FWLIBAPI int16_t WINAPI pmc_prfwrallcadr( uint16_T, int16_t, IODBPRFADR * ) ;

/* read allocation address for slave function */
FWLIBAPI int16_t WINAPI pmc_prfrdslvaddr( uint16_T, IODBSLVADR * ) ;

/* set allocation address for slave function */
FWLIBAPI int16_t WINAPI pmc_prfwrslvaddr( uint16_T, IODBSLVADR * ) ;

/* read status for slave function */
FWLIBAPI int16_t WINAPI pmc_prfrdslvstat( uint16_T, ODBSLVST * ) ;

/* Reads slave index data of master function */
FWLIBAPI int16_t WINAPI pmc_prfrdslvid( uint16_T, int16_t, IODBSLVID * ) ;

/* Writes slave index data of master function */
FWLIBAPI int16_t WINAPI pmc_prfwrslvid( uint16_T, int16_t, IODBSLVID * ) ;

/* Reads slave parameter of master function(2) */
FWLIBAPI int16_t WINAPI pmc_prfrdslvprm2( uint16_T, int16_t, IODBSLVPRM3 * ) ;

/* Writes slave parameter of master function(2) */
FWLIBAPI int16_t WINAPI pmc_prfwrslvprm2( uint16_T, int16_t, IODBSLVPRM3 * ) ;

/* Reads DI/DO parameter of master function */
FWLIBAPI int16_t WINAPI pmc_prfrddido( uint16_T, int16_t, IODBDIDO * ) ;

/* Writes DI/DO parameter of master function */
FWLIBAPI int16_t WINAPI pmc_prfwrdido( uint16_T, int16_t, IODBDIDO * ) ;

/* Reads indication address of master function */
FWLIBAPI int16_t WINAPI pmc_prfrdindiadr( uint16_T, IODBINDEADR * ) ;

/* Writes indication address of master function */
FWLIBAPI int16_t WINAPI pmc_prfwrindiadr( uint16_T, IODBINDEADR * ) ;

/* Reads operation mode of master function */
FWLIBAPI int16_t WINAPI pmc_prfrdopmode( uint16_T, int16_t * ) ;

/* Writes operation mode of master function */
FWLIBAPI int16_t WINAPI pmc_prfwropmode( uint16_T, int16_t, int16_t * ) ;


/*-----------------------------------*/
/* CB : CUSTOMER'S BOARD function    */
/*-----------------------------------*/

/* start downloading Customer's board data */
FWLIBAPI int16_t WINAPI cb_dwnstart( uint16_T FwHndl, uint16_T a, int32_t b ) ;

/* download Customer's board data */
FWLIBAPI int16_t WINAPI cb_download( uint16_T FwHndl, int32_t *a, char *b ) ;

/* end of downloading Customer's board data */
FWLIBAPI int16_t WINAPI cb_dwnend( uint16_T FwHndl ) ;

/* start uploading Customer's board data */
FWLIBAPI int16_t WINAPI cb_upstart( uint16_T FwHndl, uint16_T *a, int32_t *b ) ;

/* upload Customer's board data */
FWLIBAPI int16_t WINAPI cb_upload( uint16_T FwHndl, int32_t *a, char *b ) ;

/* end of uploading Customer's board data */
FWLIBAPI int16_t WINAPI cb_upend( uint16_T FwHndl ) ;

/* get transfer informations */
FWLIBAPI int16_t WINAPI cb_transinfo( uint16_T FwHndl, ODBTRANSINFO *info ) ;


/*-----*/
/* DSA */
/*-----*/
FWLIBAPI int16_t WINAPI dsa_rdbyte( uint16_T, int32_t, char * );
FWLIBAPI int16_t WINAPI dsa_rdword( uint16_T, int32_t, int16_t * );
FWLIBAPI int16_t WINAPI dsa_rddword( uint16_T, int32_t, int32_t * );
FWLIBAPI int16_t WINAPI dsa_wrbyte( uint16_T, int32_t, char );
FWLIBAPI int16_t WINAPI dsa_wrword( uint16_T, int32_t, int16_t );
FWLIBAPI int16_t WINAPI dsa_wrdword( uint16_T, int32_t, int32_t );


/*-----------------------------------------------*/
/* DS : Data server & Ethernet board function    */
/*-----------------------------------------------*/

/* read the parameter of the Ethernet board */
 FWLIBAPI int16_t WINAPI etb_rdparam(uint16_T hLib, int16_t a, IODBETP *b);

/* write the parameter of the Ethernet board */
 FWLIBAPI int16_t WINAPI etb_wrparam(uint16_T hLib, IODBETP *a);

/* read the error message of the Ethernet board */
 FWLIBAPI int16_t WINAPI etb_rderrmsg(uint16_T hLib, int16_t a, ODBETMSG *b);

/* read the mode of the Data Server */
 FWLIBAPI int16_t WINAPI ds_rdmode(uint16_T hLib, int16_t *a);

/* write the mode of the Data Server */
 FWLIBAPI int16_t WINAPI ds_wrmode(uint16_T hLib, int16_t a);

/* read information of the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_rdhddinfo(uint16_T hLib, ODBHDDINF *a);

/* read the file list of the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_rdhdddir(uint16_T hLib, char *a, int32_t b, int16_t *c, ODBHDDDIR *d);

/* delete the file of the Data Serve's HDD */
 FWLIBAPI int16_t WINAPI ds_delhddfile(uint16_T hLib, char *a);

/* copy the file of the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_copyhddfile(uint16_T hLib, char *a, char *b);

/* change the file name of the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_renhddfile(uint16_T hLib, char *a, char *b);

/* execute the PUT command of the FTP */
 FWLIBAPI int16_t WINAPI ds_puthddfile(uint16_T hLib, char *a, char *b);

/* execute the MPUT command of the FTP */
 FWLIBAPI int16_t WINAPI ds_mputhddfile(uint16_T hLib, char *a);

/* read information of the host */
 FWLIBAPI int16_t WINAPI ds_rdhostinfo(uint16_T hLib, int32_t *a, int32_t b);

/* read the file list of the host */
 FWLIBAPI int16_t WINAPI ds_rdhostdir(uint16_T hLib, int16_t a, int32_t b, int16_t *c, ODBHOSTDIR *d, int32_t e);

/* read the file list of the host 2 */
 FWLIBAPI int16_t WINAPI ds_rdhostdir2(uint16_T hLib, int16_t a, int32_t b, int16_t *c, int32_t *d, ODBHOSTDIR *e, int32_t f);

/* delete the file of the host */
 FWLIBAPI int16_t WINAPI ds_delhostfile(uint16_T hLib, char *a, int32_t b);

/* execute the GET command of the FTP */
 FWLIBAPI int16_t WINAPI ds_gethostfile(uint16_T hLib, char *a, char *b);

/* execute the MGET command of the FTP */
 FWLIBAPI int16_t WINAPI ds_mgethostfile(uint16_T hLib, char *a);

/* read the execution result */
 FWLIBAPI int16_t WINAPI ds_rdresult(uint16_T hLib);

/* stop the execution of the command */
 FWLIBAPI int16_t WINAPI ds_cancel(uint16_T hLib);

/* read the file from the Data Server */
 FWLIBAPI int16_t WINAPI ds_rdncfile(uint16_T hLib, int16_t a, char *b);

/* read the file from the Data Server 2 */
 FWLIBAPI int16_t WINAPI ds_rdncfile2(uint16_T hLib, char *a);

/* write the file to the Data Server */
 FWLIBAPI int16_t WINAPI ds_wrncfile(uint16_T hLib, int16_t a, int32_t b);

/* read the file name for the DNC operation in the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_rddnchddfile(uint16_T hLib, char *a);

/* write the file name for the DNC operation in the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_wrdnchddfile(uint16_T hLib, char *a);

/* read the file name for the DNC operation in the host */
 FWLIBAPI int16_t WINAPI ds_rddnchostfile(uint16_T hLib, int16_t *a, char *b);

/* write the file name for the DNC operation in the host */
 FWLIBAPI int16_t WINAPI ds_wrdnchostfile(uint16_T hLib, char *a);

/* read the connecting host number */
 FWLIBAPI int16_t WINAPI ds_rdhostno(uint16_T hLib, int16_t *a);

/* read maintenance information */
 FWLIBAPI int16_t WINAPI ds_rdmntinfo(uint16_T hLib, int16_t a, DSMNTINFO *b);

/* check the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_checkhdd(uint16_T hLib);

/* format the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_formathdd(uint16_T hLib);

/* create the directory in the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_makehdddir(uint16_T hLib, char *a);

/* delete directory in the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_delhdddir(uint16_T hLib, char *a);

/* change the current directory */
 FWLIBAPI int16_t WINAPI ds_chghdddir(uint16_T hLib, char *a);

/* execute the PUT command according to the list file */
 FWLIBAPI int16_t WINAPI ds_lputhddfile(uint16_T hLib, char *a);

/* delete files according to the list file */
 FWLIBAPI int16_t WINAPI ds_ldelhddfile(uint16_T hLib, char *a);

/* execute the GET command according to the list file */
 FWLIBAPI int16_t WINAPI ds_lgethostfile(uint16_T hLib, char *a);

/* read the directory for M198 operation */
 FWLIBAPI int16_t WINAPI ds_rdm198hdddir(uint16_T hLib, char *a);

/* write the directory for M198 operation */
 FWLIBAPI int16_t WINAPI ds_wrm198hdddir(uint16_T hLib);

/* read the connecting host number for the M198 operation */
 FWLIBAPI int16_t WINAPI ds_rdm198host(uint16_T hLib, int16_t *a);

/* write the connecting host number for the M198 operation */
 FWLIBAPI int16_t WINAPI ds_wrm198host(uint16_T hLib);

/* write the connecting host number */
 FWLIBAPI int16_t WINAPI ds_wrhostno(uint16_T hLib, int16_t a);

/* search string in data server program */
 FWLIBAPI int16_t WINAPI ds_searchword(uint16_T FlibHndl, char *prog_data);

/* read the searching result */
 FWLIBAPI int16_t WINAPI ds_searchresult(uint16_T FlibHndl);

/* read file in the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_rdfile(uint16_T hLib, char *a, char *b);

/* write file in the Data Server's HDD */
 FWLIBAPI int16_t WINAPI ds_wrfile(uint16_T hLib, char *a, char *b);

/* start downloading Data Server data */
FWLIBAPI int16_t WINAPI ds_dwnstart( uint16_T, char *, int16_t ) ;

/* download Data Server data */
FWLIBAPI int16_t WINAPI ds_download( uint16_T, int32_t *, char * ) ;

/* end of downloading Data Server data */
FWLIBAPI int16_t WINAPI ds_dwnend( uint16_T ) ;


/*----------------------------*/
/* NET : Ethernet function    */
/*----------------------------*/

/* read parameter for ethernet function */
FWLIBAPI int16_t WINAPI eth_rdparam( uint16_T, int16_t, OUT_ETHPRM * );

/* write parameter for ethernet function */
FWLIBAPI int16_t WINAPI eth_wrparam( uint16_T, int16_t, IN_ETHPRMFLAG *, IN_ETHPRM * );

/* read kind of device for embedded ethernet function */
FWLIBAPI int16_t WINAPI eth_rdembdev( uint16_T, int16_t * );

/* set device for embedded ethernet function */
FWLIBAPI int16_t WINAPI eth_wrembdev( uint16_T, int16_t );

/* restart for embedded ethernet function */
FWLIBAPI int16_t WINAPI eth_embrestart( uint16_T, int16_t );

/* read mode for dataserver function */
FWLIBAPI int16_t WINAPI eth_rddsmode( uint16_T, OUT_ETHDSMODE * );

/* write mode for dataserver function */
FWLIBAPI int16_t WINAPI eth_wrdsmode( uint16_T, int16_t, int16_t );

/* execute ping function */
FWLIBAPI int16_t WINAPI eth_ping( uint16_T, int16_t, char *, uint32_T * );

/* get result of ping function */
FWLIBAPI int16_t WINAPI eth_ping_result( uint16_T, int16_t, OUT_ETHPING * );

/* cancel ping function */
FWLIBAPI int16_t WINAPI eth_ping_cancel( uint16_T, int16_t );

/* read state of LSI for ethernet function */
FWLIBAPI int16_t WINAPI eth_rdlsistate( uint16_T, int16_t, OUT_ETHLSI * );

/* clear state of LSI for ethernet function */
FWLIBAPI int16_t WINAPI eth_clrlsistate( uint16_T, int16_t );

/* read state of task for ethernet function */
FWLIBAPI int16_t WINAPI eth_rdtaskstate( uint16_T, int16_t, OUT_ETHTASK * );

/* read log for ethernet function */
FWLIBAPI int16_t WINAPI eth_rdlog( uint16_T, int16_t, int16_t, int16_t, OUT_ETHLOG * );

/* clear log for ethernet function */
FWLIBAPI int16_t WINAPI eth_clrlog( uint16_T, int16_t );

/* read type for ethernet function */
FWLIBAPI int16_t WINAPI eth_rdtype( uint16_T, OUT_ETHTYPE * );

/* read type for ethernet function */
FWLIBAPI int16_t WINAPI eth_rdtype2( uint16_T, OUT_ETHTYPE2 * );

/* read type for ethernet function */
FWLIBAPI int16_t WINAPI eth_rdtype3( uint16_T, OUT_ETHTYPE3 * );

/* read state for dataserver function */
FWLIBAPI int16_t WINAPI eth_rddsstate( uint16_T, int16_t, OUT_DSSTATE * );

/* read host number for ethernet function */
FWLIBAPI int16_t WINAPI eth_rdhost( uint16_T, int16_t, int16_t * );

/* write host number for ethernet function */
FWLIBAPI int16_t WINAPI eth_wrhost( uint16_T, int16_t, int16_t );

/* read m198 folder for dataserver function */
FWLIBAPI int16_t WINAPI eth_rddsm198dir( uint16_T, int16_t, char * );

/* write m198 folder for dataserver function */
FWLIBAPI int16_t WINAPI eth_wrdsm198dir( uint16_T, int16_t, char * );

/* read m198 host number for dataserver function */
FWLIBAPI int16_t WINAPI eth_rddsm198host( uint16_T, int16_t, int16_t *, char * );

/* write m198 host number for dataserver function */
FWLIBAPI int16_t WINAPI eth_wrdsm198host( uint16_T, int16_t, int16_t, char * );

/* read m198 host number for embedded ethernet function */
FWLIBAPI int16_t WINAPI eth_rdembm198host( uint16_T, int16_t, int16_t *, char * );

/* write m198 host number for embedded ethernet function */
FWLIBAPI int16_t WINAPI eth_wrembm198host( uint16_T, int16_t, int16_t, char * );

/* read ATA card format type */
FWLIBAPI int16_t WINAPI eth_rddsformat( uint16_T, int16_t * );

/* format ATA card */
FWLIBAPI int16_t WINAPI eth_dsformat( uint16_T, int16_t, int16_t * );

/* checkdisk ATA card */
FWLIBAPI int16_t WINAPI eth_dschkdsk( uint16_T, int16_t * );

/*j read inquiry of machine remote diagnosis for ethernet function */
FWLIBAPI int16_t WINAPI eth_rdrmdinquiry( uint16_T, int16_t, int16_t * );

/*j write inquiry of machine remote diagnosis for ethernet function */
FWLIBAPI int16_t WINAPI eth_wrrmdinquiry( uint16_T, int16_t, int16_t );

/* read mode of unsolicited message */
FWLIBAPI int16_t WINAPI eth_rdunsolicmode( uint16_T, int16_t, int16_t * );

/* write mode of unsolicited message */
FWLIBAPI int16_t WINAPI eth_wrunsolicmode( uint16_T, int16_t, int16_t );

/* read state of unsolicited message */
FWLIBAPI int16_t WINAPI eth_rdunsolicstate( uint16_T, int16_t, OUT_UNSOLICSTATE * );

/* apply parameter of unsolicited message */
FWLIBAPI int16_t WINAPI eth_applyunsolicprm( uint16_T, int16_t );

/* copy net-parameter from cnc's SRAM to memory card */
FWLIBAPI int16_t WINAPI net_backup_param( uint16_T, int16_t, char * );

/* copy net-parameter from memory card to cnc's SRAM */
FWLIBAPI int16_t WINAPI net_restore_param( uint16_T, int16_t, char * );

/* read information of FTP server for dataserver function */
FWLIBAPI int16_t WINAPI eth_rdfsclntinfo( uint16_T, OUT_FSINFO * );

/* disconnect a section from FTP server for dataserver function */
FWLIBAPI int16_t WINAPI eth_disconfsclnt( uint16_T, int32_t );

/* disconnect all section from FTP server for dataserver funtion */
FWLIBAPI int16_t WINAPI eth_disconfsclntall( uint16_T );

/* read information of Modbus/TCP client for Modbus/TCP server function */
FWLIBAPI int16_t WINAPI eth_rdmbsclntinfo( uint16_T, OUT_MBSVRINFO * );

/* read information of Modbus/TCP client for Modbus/TCP server function */
FWLIBAPI int16_t WINAPI eth_rdmbsclntinfo2( uint16_T, int16_t, OUT_MBSVRINFO * );

/* read parameter of basic screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_rdeipabscparam( uint16_T, OUT_EIPA_BASIC_PRM * );

/* read parameter of basic screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_rdeipabscparam2( uint16_T, int16_t, OUT_EIPA_BASIC_PRM * );

/* write parameter of basic screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_wreipabscparam( uint16_T, IN_EIPA_BASIC_PRM_FLG *, IN_EIPA_BASIC_PRM * );

/* write parameter of basic screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_wreipabscparam2( uint16_T, int16_t, IN_EIPA_BASIC_PRM_FLG *, IN_EIPA_BASIC_PRM * );

/* read parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_rdeipaalcparam( uint16_T, int16_t, int16_t, OUT_EIPA_ALLOC_PRM * );

/* read parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_rdeipaalcparam2( uint16_T, int16_t, int16_t, int16_t, OUT_EIPA_ALLOC_PRM * );

/* write parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_wreipaalcparam( uint16_T, int16_t, int16_t, IN_EIPA_ALLOC_PRM_FLG *, IN_EIPA_ALLOC_PRM * );

/* write parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_wreipaalcparam2( uint16_T, int16_t, int16_t, int16_t, IN_EIPA_ALLOC_PRM_FLG *, IN_EIPA_ALLOC_PRM * );

/* read information of MS/NS for EtherNet/IP funtion */
FWLIBAPI int16_t WINAPI eth_rdeipmsnsinfo( uint16_T, OUT_EIP_MSNSINFO * );

/* read information of MS/NS for EtherNet/IP funtion */
FWLIBAPI int16_t WINAPI eth_rdeipmsnsinfo2( uint16_T, int16_t, OUT_EIP_MSNSINFO * );

/* read information of device for EtherNet/IP funtion */
FWLIBAPI int16_t WINAPI eth_rdeipdeviceinfo( uint16_T, OUT_EIP_DEVICEINFO * );

/* read information of device for EtherNet/IP funtion */
FWLIBAPI int16_t WINAPI eth_rdeipdeviceinfo2( uint16_T, int16_t, OUT_EIP_DEVICEINFO * );

/* read scanner's list for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_rdeipascnlist( uint16_T, int16_t, int16_t, int16_t *, OUT_EIPA_SCNDATA * );

/* read scanner's list for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_rdeipascnlist2( uint16_T, int16_t, int16_t, int16_t, int16_t *, OUT_EIPA_SCNDATA * );

/* read detail info of connection for EtherNet/IP funtion */
FWLIBAPI int16_t WINAPI eth_rdeiplistdetail( uint16_T, int32_t, OUT_EIP_LISTDETAIL * );

/* read detail info of connection for EtherNet/IP funtion */
FWLIBAPI int16_t WINAPI eth_rdeiplistdetail2( uint16_T, int16_t, int32_t, OUT_EIP_LISTDETAIL * );

/* make EDS file from parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_eipaedsout( uint16_T, char * );

/* make EDS file from parameter of allocative screen for EtherNet/IP Adapter funtion */
FWLIBAPI int16_t WINAPI eth_eipaedsout2( uint16_T, int16_t, char * );

/* read parameter for EtherNet/IP Scanner funtion */
FWLIBAPI int16_t WINAPI eth_rdeipsparam( uint16_T, int16_t, OUT_EIPS_BASIC_PRM *, OUT_EIPS_STATE_PRM *, OUT_EIPS_ALLOC_PRM * );

/* read parameter for EtherNet/IP Scanner funtion */
FWLIBAPI int16_t WINAPI eth_rdeipsparam2( uint16_T, int16_t, int16_t, OUT_EIPS_BASIC_PRM *, OUT_EIPS_STATE_PRM *, OUT_EIPS_ALLOC_PRM * );

/* write parameter for EtherNet/IP Scanner funtion */
FWLIBAPI int16_t WINAPI eth_wreipsparam( uint16_T, int16_t, int16_t, int16_t, IN_EIPS_BASIC *, IN_EIPS_ALLOC * );

/* write parameter for EtherNet/IP Scanner funtion */
FWLIBAPI int16_t WINAPI eth_wreipsparam2( uint16_T, int16_t, int16_t, int16_t, int16_t, IN_EIPS_BASIC *, IN_EIPS_ALLOC * );

/* read maintenance information for EtherNet/IP Scanner funtion */
FWLIBAPI int16_t WINAPI eth_rdeipsmntinfo( uint16_T, int16_t, OUT_EIPS_COM_INFO *, OUT_EIPS_DETAIL_INFO * );

/* read maintenance information for EtherNet/IP Scanner funtion */
FWLIBAPI int16_t WINAPI eth_rdeipsmntinfo2( uint16_T, int16_t, int16_t, OUT_EIPS_COM_INFO *, OUT_EIPS_DETAIL_INFO * );

/* request identity information of Adapter */
FWLIBAPI int16_t WINAPI eth_reqeipsidinfo( uint16_T, char * );

/* request identity information of Adapter */
FWLIBAPI int16_t WINAPI eth_reqeipsidinfo2( uint16_T, int16_t, char * );

/* responce to request identity information of Adapter */
FWLIBAPI int16_t WINAPI eth_reseipsidinfo( uint16_T, OUT_EIPS_IDENTITY_INFO * );

/* responce to request identity information of Adapter */
FWLIBAPI int16_t WINAPI eth_reseipsidinfo2( uint16_T, int16_t, OUT_EIPS_IDENTITY_INFO * );

/* make EDS file from parameter for EtherNet/IP Scanner funtion */
FWLIBAPI int16_t WINAPI eth_eipsedsout( uint16_T, char * );

/* make EDS file from parameter for EtherNet/IP Scanner funtion */
FWLIBAPI int16_t WINAPI eth_eipsedsout2( uint16_T, int16_t, char * );

/* sort IP Address for EtherNet/IP Scanner funtion */
FWLIBAPI int16_t WINAPI eth_eipsparamsort( uint16_T, int16_t );

/* read maintenance information for EtherNet/IP Safety Adapter funtion */
FWLIBAPI int16_t WINAPI eth_rdeipsafmntinfo( uint16_T, OUT_ADPSAFE_MNTINFO * );

/* make Safety Dump Error file for EtherNet/IP Safety Adapter funtion */
FWLIBAPI int16_t WINAPI eth_eipsafdumperror( uint16_T, char * );

/* make XML file for EtherNet/IP EDA funtion */
FWLIBAPI int16_t WINAPI eth_edaxmlout( uint16_T, int16_t, char * );

/* read type for network function */
FWLIBAPI int16_t WINAPI net_rdtype(uint16_T, int16_t, OUT_NETDEVPRM *);

/* get DNC operation file */
FWLIBAPI int16_t WINAPI cnc_rddsdncfile( uint16_T, char *, int16_t *, char * );

/* set DNC operation file */
FWLIBAPI int16_t WINAPI cnc_wrdsdncfile( uint16_T, char *, char * );

/* set DNC operation file */
FWLIBAPI int16_t WINAPI cnc_wrdsdncfile2( uint16_T, char *, char *, uint16_T );

/* get device infomation for dataserver function */
FWLIBAPI int16_t WINAPI cnc_rddsdevinfo( uint16_T, int16_t, ODBPDFINF * );

/* change operation folder */
FWLIBAPI int16_t WINAPI cnc_rddsdir( uint16_T, char *, int16_t *, char * );

/* get file list infomation */
FWLIBAPI int16_t WINAPI cnc_rddsfile( uint16_T, char *, IN_DSFILE *, OUT_DSINFO *, OUT_DSFILE * );

/* make folder */
FWLIBAPI int16_t WINAPI cnc_dsmkdir( uint16_T, char *, char * );

/* delete folder */
FWLIBAPI int16_t WINAPI cnc_dsrmdir( uint16_T, char *, char * );

/* delete file */
FWLIBAPI int16_t WINAPI cnc_dsremove( uint16_T, char *, char * );

/* change current folder */
FWLIBAPI int16_t WINAPI cnc_dschdir( uint16_T, char *, char *, IN_DSFILE *, OUT_DSINFO *, OUT_DSFILE * );

/* rename folder / file */
FWLIBAPI int16_t WINAPI cnc_dsrename( uint16_T, char *, char *, char * );

/* copy file for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dscopyfile( uint16_T, char *, char * );

/* start GET command for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dsget_req( uint16_T, char *, char *, int16_t );

/* start PUT command for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dsput_req( uint16_T, char *, char * );

/* start MGET command for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dsmget_req( uint16_T, char * );

/* start MPUT command for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dsmput_req( uint16_T, char * );

/* start List-GET command for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dslistget_req( uint16_T, char * );

/* start List-PUT command for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dslistput_req( uint16_T, char * );

/* start List delete for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dslistdel_req( uint16_T, char * );

/* read file transport result for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dsftpstat( uint16_T );

/* cancel to file transport for dataserver function */
FWLIBAPI int16_t WINAPI cnc_dsftpcancel( uint16_T );

/* Reads MAC address */
FWLIBAPI int16_t WINAPI cnc_getmacaddress( uint16_T, char* );

/* search file */
FWLIBAPI int16_t WINAPI cnc_dssearch( uint16_T, char*, char*, uint16_T, uint32_T*  );

/* Data server file read open */
FWLIBAPI int16_t WINAPI cnc_dsrdopen(uint16_T, char*);

/* Data server file read */
FWLIBAPI int16_t WINAPI cnc_dsread(uint16_T, int32_t*, char*);

/* Data server file read close */
FWLIBAPI int16_t WINAPI cnc_dsrdclose(uint16_T);

/* Data server file write open */
FWLIBAPI int16_t WINAPI cnc_dswropen(uint16_T, int16_t, char*);

/* Data server file write */
FWLIBAPI int16_t WINAPI cnc_dswrite(uint16_T, int32_t*, char*);

/* Data server file write close */
FWLIBAPI int16_t WINAPI cnc_dswrclose(uint16_T);

/* start reading file list infomation */
FWLIBAPI int16_t WINAPI cnc_dsfile_req( uint16_T, char *, ODB_IN_DSFILE_REQ * );

/* read file transport result for reading file list infomation */
FWLIBAPI int16_t WINAPI cnc_dsstat_rdfile( uint16_T, char *, ODB_IN_STAT_DSFILE *, OUT_DSINFO *, OUT_DSFILE * );

/*----------------------------*/
/* NET : PROFIBUS function    */
/*----------------------------*/

/* read parameter for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_rd_param(uint16_T, int16_t, T_SLVSLT_IND *, OUT_PBMPRM *);

/* write parameter for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_wr_param(uint16_T, int16_t, IN_PBMPRMFLG *, IN_PBMPRM *);

/* initialize parameter for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_ini_prm(uint16_T, int16_t, T_SLVSLT_IND *);

/* read slave index table for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_rd_allslvtbl(uint16_T, OUT_ALLSLVTBL *);

/* execute sub function for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_exe_subfunc(uint16_T, int16_t, T_SLVSLT_IND *);

/* read sub parameter for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_rd_subprm(uint16_T, int16_t, T_SLVSLT_IND *, OUT_PBMSUBPRM *);

/* read error code for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_rd_errcode(uint16_T, T_ERR_CODE *);

/* change mode for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_chg_mode(uint16_T, unsigned char, OUT_CHGMODERESULT *);

/* read communication information for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_rd_cominfo(uint16_T, int16_t, OUT_PBMCOMINFO *);

/* read node information table for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_rd_nodetable(uint16_T, int16_t, char *);

/* read node information for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_rd_nodeinfo(uint16_T, int16_t, int16_t, OUT_PBMNODEINFO *);

/* read slot number for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_rd_slot(uint16_T, int16_t *);

/* read slot information for PROFIBUS MASTER function */
FWLIBAPI int16_t WINAPI pbm_rd_slotinfo(uint16_T, int16_t, int16_t, OUT_PBMSLOTINFO *);

/* read parameter for PROFIBUS SLAVE fucntion */
FWLIBAPI int16_t WINAPI pbs_rd_param(uint16_T, OUT_PBSPRM *);

/*j write parameter for PROFIBUS SLAVE function */
FWLIBAPI int16_t WINAPI pbs_wr_param(uint16_T, IN_PBSPRMFLG *, IN_PBSPRM *);

/*j initialize parameter for PROFIBUS SLAVE function */
FWLIBAPI int16_t WINAPI pbs_ini_prm(uint16_T, int16_t);

/*j read communication information for PROFIBUS SLAVE function */
FWLIBAPI int16_t WINAPI pbs_rd_cominfo(uint16_T, OUT_PBSSTATUS *);

/* read parameter 2 for PROFIBUS SLAVE fucntion */
FWLIBAPI int16_t WINAPI pbs_rd_param2(uint16_T, OUT_PBSPRM2 *);

/*j write parameter 2 for PROFIBUS SLAVE function */
FWLIBAPI int16_t WINAPI pbs_wr_param2(uint16_T, IN_PBSPRMFLG2 *, IN_PBSPRM2 *);

/*j read communication information 2 for PROFIBUS SLAVE function */
FWLIBAPI int16_t WINAPI pbs_rd_cominfo2(uint16_T, OUT_PBSSTATUS2 *);

/*----------------------------*/
/* NET : DeviceNet function   */
/*----------------------------*/

/* read parameter for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_rdparam(uint16_T, int16_t, int16_t, OUT_DNMPRM *);

/* read parameter for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_rdparam2(uint16_T, int16_t, int16_t, OUT_DNMPRM2 *);

/* write parameter for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_wrparam(uint16_T, int16_t, int16_t, IN_DNMPRMFLAG *, IN_DNMPRM *);

/* write parameter for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_wrparam2(uint16_T, int16_t, int16_t, IN_DNMPRMFLAG2 *, IN_DNMPRM2 *);

/* read node table for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_rdnodetable(uint16_T, OUT_DNMNODE *);

/* read all node infomation for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_rdnodeinfo(uint16_T, int16_t, OUT_DNMNODEINFO *);

/* read firm infomation for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_rdfirminfo(uint16_T, OUT_DNMFIRM *);

/* read error record for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_rderrorrecord(uint16_T, OUT_DNMERR *);

/* clear error record for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_clrerrorrecord(uint16_T);

/* read slave status for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_rdslvstatus(uint16_T, int16_t, unsigned char *);

/* read communication history for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_rd_hist(uint16_T, uint16_T, uint16_T, uint16_T, OUT_DNMHIST *);

/* clear communication history for DeviceNet MASTER function */
FWLIBAPI int16_t WINAPI dnm_clr_hist(uint16_T);

/* read parameter for DeviceNet SLAVE function */
FWLIBAPI int16_t WINAPI dns_rdparam(uint16_T, OUT_DNSPRM *);

/* write parameter for DeviceNet SLAVE function */
FWLIBAPI int16_t WINAPI dns_wrparam(uint16_T, IN_DNSPRMFLAG *, IN_DNSPRM *);

/* read infomation for DeviceNet SLAVE function */
FWLIBAPI int16_t WINAPI dns_rdinfo(uint16_T, OUT_DNSINFO *);

/* restart for DeviceNet SLAVE function */
FWLIBAPI int16_t WINAPI dns_restart(uint16_T);

/* read communication history for DeviceNet SLAVE function */
FWLIBAPI int16_t WINAPI dns_rd_hist(uint16_T, uint16_T, uint16_T, OUT_DNSHIST *);

/* clear communication history for DeviceNet SLAVE function */
FWLIBAPI int16_t WINAPI dns_clr_hist(uint16_T);


/*----------------------------*/
/* NET : FL-net function      */
/*----------------------------*/

/* read parameter for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdparam(uint16_T, OUT_FLNTPRM *);

/* read parameter for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdparam2(uint16_T, int16_t, OUT_FLNTPRM *);

/* write parameter for FL-net function */
FWLIBAPI int16_t WINAPI flnt_wrparam(uint16_T, IN_FLNTPRMFLG *, IN_FLNTPRM *);

/* write parameter for FL-net function */
FWLIBAPI int16_t WINAPI flnt_wrparam2(uint16_T, int16_t, IN_FLNTPRMFLG *, IN_FLNTPRM *);

/* read node entry for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdentry(uint16_T, OUT_FLNTENTRY *);

/* read node entry for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdentry2(uint16_T, int16_t, OUT_FLNTENTRY *);

/* read node information for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdnodeinfo(uint16_T, unsigned char, OUT_FLNTNODETBL *);

/* read node information for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdnodeinfo2(uint16_T, int16_t, unsigned char, OUT_FLNTNODETBL *);

/* read network information for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdnetwork(uint16_T, OUT_FLNTNETTBL *);

/* read network information for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdnetwork2(uint16_T, int16_t, OUT_FLNTNETTBL *);

/* clear network information for FL-net function */
FWLIBAPI int16_t WINAPI flnt_clrnetwork(uint16_T);

/* clear network information for FL-net function */
FWLIBAPI int16_t WINAPI flnt_clrnetwork2(uint16_T, int16_t);

/* read log for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdlog(uint16_T, OUT_FLNTLOG *);

/* read log for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdlog2(uint16_T, int16_t, OUT_FLNTLOG2 *);

/* clear log for FL-net function */
FWLIBAPI int16_t WINAPI flnt_clrlog(uint16_T);

/* clear log for FL-net function */
FWLIBAPI int16_t WINAPI flnt_clrlog2(uint16_T, int16_t);

/* read message for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdmsg(uint16_T, int16_t, int16_t, int16_t, OUT_FLNTMSG *);

/* read message for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rdmsg2(uint16_T, int16_t, int16_t, int16_t, int16_t, OUT_FLNTMSG *);

/* clear message for FL-net function */
FWLIBAPI int16_t WINAPI flnt_clrmsg(uint16_T);

/* clear message for FL-net function */
FWLIBAPI int16_t WINAPI flnt_clrmsg2(uint16_T, int16_t);

/* read device information for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rddeviceinfo(uint16_T, OUT_FLNTDEVINFO *);

/* read device information for FL-net function */
FWLIBAPI int16_t WINAPI flnt_rddeviceinfo2(uint16_T, int16_t, OUT_FLNTDEVINFO2 *);

/* read status for FL-net Safety function */
FWLIBAPI int16_t WINAPI flnt_rdsfstatus(uint16_T, int16_t, OUT_FLNTSFSTS *);

/* read error node information for FL-net Safety function */
FWLIBAPI int16_t WINAPI flnt_rdsferrnode(uint16_T, int16_t, OUT_FLNTSFERRTBL *);

/* Read FL-net Sram area (for 16i Series) */
FWLIBAPI int16_t WINAPI cnc_rdflnetsram(uint16_T, int16_t, uint32_T, uint32_T *, void *);

/* Write FL-net Sram area (for 16i Series)  */
FWLIBAPI int16_t WINAPI cnc_wrflnetsram(uint16_T, int16_t, uint32_T, uint32_T *, void *);


/*----------------------------*/
/* NET : CC-Link function     */
/*----------------------------*/

/* read parameter for CC-Link Remote Device function */
FWLIBAPI int16_t WINAPI cclr_rdparam(uint16_T, OUT_CCLRPRM *);

/* write parameter for CC-Link Remote Device function */
FWLIBAPI int16_t WINAPI cclr_wrparam(uint16_T, IN_CCLRPRMFLAG *, IN_CCLRPRM *);

/* read network information for CC-Link Remote Device function */
FWLIBAPI int16_t WINAPI cclr_rdinfo(uint16_T, OUT_CCLRINFO *);


/*----------------------------*/
/* NET : USB function     */
/*----------------------------*/

/* read maintenance information for USB function */
FWLIBAPI int16_t WINAPI usb_rdinfo(uint16_T, int16_t, OUT_USBINFO *);

/* read log for USB function */
FWLIBAPI int16_t WINAPI usb_rdlog(uint16_T, int16_t, int16_t, int16_t, OUT_USBLOG *);

/* clear log for USB function */
FWLIBAPI int16_t WINAPI usb_clrlog(uint16_T);

/* start format for USB function */
FWLIBAPI int16_t WINAPI usb_format_start(uint16_T, int16_t);

/* get result of format for USB function */
FWLIBAPI int16_t WINAPI usb_format_result(uint16_T, int16_t, int16_t *);

/*-----------------------------------*/
/* NET : PROFINET function           */
/*-----------------------------------*/
/* read parameter for PROFINET IO Device funtion */
FWLIBAPI int16_t WINAPI pnd_rdparam( uint16_T, OUT_PND_PARAM * );

/* write parameter for PROFINET IO Device funtion */
FWLIBAPI int16_t WINAPI pnd_wrparam( uint16_T, IN_PND_PARAM * );

/* read maintenance information for PROFINET IO Device funtion */
FWLIBAPI int16_t WINAPI pnd_rdmntinfo( uint16_T, OUT_PND_MNTINFO * );

/* clear maintenance information for PROFINET IO Device funtion */
FWLIBAPI int16_t WINAPI pnd_clrmntinfo( uint16_T );

/* read mode for PROFINET IO Device funtion */
FWLIBAPI int16_t WINAPI pnd_rdmode( uint16_T, unsigned char * );

/* write mode for PROFINET IO Device funtion */
FWLIBAPI int16_t WINAPI pnd_wrmode( uint16_T, unsigned char );

/* make Safety Mainte information file for PROFINET IO Device Safety function  */
FWLIBAPI int16_t WINAPI pnd_outsafemntinfo( uint16_T, char * );

/* read parameter for PROFINET IO Controller funtion */
FWLIBAPI int16_t WINAPI pnc_rdparam(uint16_T, OUT_PNC_PARAM *);

/* write parameter for PROFINET IO Controller funtion */
FWLIBAPI int16_t WINAPI pnc_wrparam(uint16_T, IN_PNC_PARAM *);

/* read maintenance information for PROFINET IO Controller funtion */
FWLIBAPI int16_t WINAPI pnc_rdmntinfo(uint16_T, int16_t, OUT_PNC_CNTRLR_INFO *, OUT_PNC_DEVICE_INFO *, OUT_PNC_ALLCOM_STAT *);

/* request maintenance information for PROFINET IO Controller funtion */
FWLIBAPI int16_t WINAPI pnc_reqdetailinfo(uint16_T, int16_t, int16_t, char *);

/* response maintenance information for PROFINET IO Controller funtion */
FWLIBAPI int16_t WINAPI pnc_resdetailinfo(uint16_T, int16_t, int16_t, OUT_PNC_DETAIL_INFO *);

/* read mode for PROFINET IO Controller funtion */
FWLIBAPI int16_t WINAPI pnc_rdmode(uint16_T, unsigned char *);

/* write mode for PROFINET IO Controller funtion */
FWLIBAPI int16_t WINAPI pnc_wrmode(uint16_T, unsigned char);

/*-----------------------------------*/
/* NET : EtherCAT function           */
/*-----------------------------------*/
FWLIBAPI int16_t WINAPI ect_rdlog(uint16_T, int16_t, int16_t, int16_t, int16_t, OUT_ECTLOG *);

FWLIBAPI int16_t WINAPI ect_clrlog(uint16_T, int16_t);

FWLIBAPI int16_t WINAPI ect_outputlog(uint16_T, char *);

FWLIBAPI int16_t WINAPI ect_rdslvtype(uint16_T, int16_t, OUT_ECTTYPE *);

FWLIBAPI int16_t WINAPI ect_rdslvdeviceinfo(uint16_T, int16_t, OUT_ECTDEVINFO *);

FWLIBAPI int16_t WINAPI ect_rdslvnetwork(uint16_T, int16_t, OUT_ECTNETINFO *);

FWLIBAPI int16_t WINAPI ect_chgslvmode(uint16_T, int16_t, uint16_T);

FWLIBAPI int16_t WINAPI ect_outputesi(uint16_T, char *);

/*--------------------------*/
/* HSSB multiple connection */
/*--------------------------*/

/* read number of node */
FWLIBAPI int16_t WINAPI cnc_rdnodenum( int32_t * );

/* read node informations */
FWLIBAPI int16_t WINAPI cnc_rdnodeinfo( int32_t, ODBNODE * );

/* set default node number */
FWLIBAPI int16_t WINAPI cnc_setdefnode( int32_t );

/* allocate library handle 2 */
FWLIBAPI int16_t WINAPI cnc_allclibhndl2( int32_t, uint16_T * );


/*---------------------*/
/* Ethernet connection */
/*---------------------*/

/* allocate library handle 3 */
FWLIBAPI int16_t WINAPI cnc_allclibhndl3( const char *, uint16_T, int32_t, uint16_T * );

/* allocate library handle 4 */
FWLIBAPI int16_t WINAPI cnc_allclibhndl4( const char *, uint16_T, int32_t, uint32_T, uint16_T * );

/* set timeout for socket */
FWLIBAPI int16_t WINAPI cnc_settimeout( uint16_T, int32_t );

/* reset all socket connection */
FWLIBAPI int16_t WINAPI cnc_resetconnect( uint16_T );

/* get option state for FOCAS1/Ethernet */
FWLIBAPI int16_t WINAPI cnc_getfocas1opt( uint16_T, int16_t, int32_t * );

/* read Ethernet board information */
FWLIBAPI int16_t WINAPI cnc_rdetherinfo( uint16_T, int16_t *, int16_t * ) ;

/*--------------------------*/
/*  Power Mate CNC manager  */
/*--------------------------*/

/* initialize */
FWLIBAPI int16_t WINAPI cnc_pmminit( uint16_T, int32_t, ODBPMMSLV *);

/* check alarm status */
FWLIBAPI int16_t WINAPI cnc_pmmchkalm(uint16_T, int32_t, int32_t *);

/* get serise , version */
FWLIBAPI int16_t WINAPI cnc_pmmsysdt(uint16_T, int32_t, int32_t, ODBPMMSYD *);

/* get continous data start */
FWLIBAPI int16_t WINAPI cnc_pmmgetstart(uint16_T, int32_t, int32_t, int32_t, IDBPMMGTI *);

/* get continous data */
FWLIBAPI int16_t WINAPI cnc_pmmget(uint16_T, int32_t, int32_t, int32_t, ODBPMMGET *);

/* get continous end */
FWLIBAPI int16_t WINAPI cnc_pmmgetend(uint16_T, int32_t, int32_t, int32_t);

/* get parameter 1 page */
FWLIBAPI int16_t WINAPI cnc_pmmprmpage(uint16_T, int32_t, int32_t, int32_t, int32_t, ODBPMMPRP *);

/* write parameter */
FWLIBAPI int16_t WINAPI cnc_wrpmmprm(uint16_T, int32_t, int32_t, int32_t, ODBPMMPRP *);

/* read parameter (tape memory) */
FWLIBAPI int16_t WINAPI cnc_rdpmmprmtp(uint16_T, IDBPMMPRP *);

/* write parameter (tape memory) */
FWLIBAPI int16_t WINAPI cnc_wrpmmprmtp(uint16_T, IDBPMMPRP *);

/* I/O LINK channel number */
FWLIBAPI int16_t WINAPI cnc_pmmiochanl(uint16_T, ODBPMMIO *);

/* read PMC path & PMC addr F/G signal */
FWLIBAPI int16_t WINAPI cnc_rdioassigned( uint16_T, uint16_T *, uint16_T * ) ;

/*---------------------*/
/* Background function */
/*---------------------*/

/* read absolute axis position (BG) */
FWLIBAPI int16_t WINAPI cnc_absolute_bg( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read relative axis position (BG) */
FWLIBAPI int16_t WINAPI cnc_relative_bg( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read machine axis position (BG) */
FWLIBAPI int16_t WINAPI cnc_machine_bg( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/* read current program and its pointer (BG) */
FWLIBAPI int16_t WINAPI cnc_pdf_rdactpt_bg( uint16_T, char * , int32_t * ) ;

/* set current program and its pointer (BG) */
FWLIBAPI int16_t WINAPI cnc_pdf_wractpt_bg( uint16_T, char * , int16_t, int32_t * ) ;

/* read CNC status information (BG) */
FWLIBAPI int16_t WINAPI cnc_statinfo_bg( uint16_T, ODBST * ) ;

/* read sequence number under execution (BG) */
FWLIBAPI int16_t WINAPI cnc_rdseqnum_bg( uint16_T, ODBSEQ * ) ;

/* read modal data (BG) */
FWLIBAPI int16_t WINAPI cnc_modal_bg( uint16_T, int16_t, int16_t, ODBMDL * ) ;

/* Get distribute infomation (BG) */
FWLIBAPI int16_t WINAPI cnc_rdipltp_bg( uint16_T, ODBIPL *buf );

/* Get next axis distance (BG) */
FWLIBAPI int16_t WINAPI cnc_nextdistance_bg( uint16_T, int16_t, int16_t, IODBAXIS * );

/* read tool offset value (BG) */
FWLIBAPI int16_t WINAPI cnc_rdtofs_bg( uint16_T, int16_t, int16_t, int16_t, ODBTOFS * ) ;

/* read tool offset value(area specified) (BG) */
FWLIBAPI int16_t WINAPI cnc_rdtofsr_bg( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBTO * ) ;

/* read work zero offset value (BG) */
FWLIBAPI int16_t WINAPI cnc_rdzofs_bg( uint16_T, int16_t, int16_t, int16_t, IODBZOFS * ) ;

/* read work zero offset value(area specified) (BG) */
FWLIBAPI int16_t WINAPI cnc_rdzofsr_bg( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBZOR * ) ;

/* read work coordinate shift (BG) */
FWLIBAPI int16_t WINAPI cnc_rdwkcdshft_bg( uint16_T, int16_t, int16_t, IODBWCSF * ) ;

/* read alarm information (BG) */
FWLIBAPI int16_t WINAPI cnc_rdalminfo_bg( uint16_T, int16_t, int16_t, int16_t, ALMINFO * ) ;

/* read program number under execution (BG) */
FWLIBAPI int16_t WINAPI cnc_rdprgnumo8_bg( uint16_T, ODBPROO8 * ) ;

/* read program under execution (BG) */
FWLIBAPI int16_t WINAPI cnc_rdexecprog_bg( uint16_T, uint16_T *, int16_t *, char * ) ;

/* read absolute axis position (with compensation) */
FWLIBAPI int16_t WINAPI cnc_absolute_mgi( uint16_T, int16_t, int16_t, ODBAXIS * ) ;

/*-----------------------------*/
/* Dual Check Safety Functions */
/*-----------------------------*/
/* Get dual check safety MCC test status */
FWLIBAPI int16_t WINAPI cnc_get_mccteststs(uint16_T, int16_t *, DCSMCA * );

/* Get dual check safety Flow Monitor */
FWLIBAPI int16_t WINAPI cnc_get_flowmonitor(uint16_T, int16_t, int16_t *, ODBDCSFMONI * );

/* Get dual check safety Cross Check Alarm */
FWLIBAPI int16_t WINAPI cnc_get_crosschk_alarm (uint16_T, DCSCRSALM * );

/* Get dual check safety Monitoring Data(Feed, Machine Position, Position Error) */
FWLIBAPI int16_t WINAPI cnc_get_safetysts(uint16_T, int16_t, int16_t, int16_t *, DCSSVSPSTS *);

/* Get dual check safety Monitoring Data(Limit, Axis status, Unit ) */
FWLIBAPI int16_t WINAPI cnc_get_safetysts2(uint16_T, int16_t, int16_t, int16_t *, DCSSVSPST2 *);

/*-----------------------------*/
/* Real-time custom macro      */
/*-----------------------------*/
/* get the number of real-time custom macro non-volatile variables */
FWLIBAPI int16_t WINAPI cnc_getrtmrvars ( uint16_T, int32_t * ) ;

/* read real-time custom macro non-volatile variables (IEEE double version only) */
FWLIBAPI int16_t WINAPI cnc_rdrtmrvars ( uint16_T, int32_t, int32_t *, double * ) ;

/* write real-time custom macro non-volatile variables (IEEE double version only) */
FWLIBAPI int16_t WINAPI cnc_wrrtmrvars ( uint16_T, int32_t, int32_t *, double * ) ;

/* get the number of real-time custom macro volatile variables */
FWLIBAPI int16_t WINAPI cnc_getrtmrvar ( uint16_T, int32_t * ) ;

/* read real-time custom macro volatile variables (IEEE double version only) */
FWLIBAPI int16_t WINAPI cnc_rdrtmrvar ( uint16_T, int32_t, int32_t *, double * ) ;

/* write real-time custom macro volatile variables (IEEE double version only) */
FWLIBAPI int16_t WINAPI cnc_wrrtmrvar ( uint16_T, int32_t, int32_t *, double * ) ;

/* read real-time custom macro di/do variables write enable status  (per byte) */
FWLIBAPI int16_t WINAPI cnc_getrtmioinfo ( uint16_T, int16_t, IODBRTMIOR *, uint32_T * ) ;

/* get the number of real-time custom macro di/do variable range index */
FWLIBAPI int16_t WINAPI cnc_getrtmiorngnum ( uint16_T, uint32_T * ) ;

/* read real-time custom macro di/do variables write enable information */
FWLIBAPI int16_t WINAPI cnc_rdrtmiowrenbl ( uint16_T, IODBRTMIO *, uint32_T *, char * ) ;

/* write real-time custom macro di/do variables write enable status (per byte) */
FWLIBAPI int16_t WINAPI cnc_wrrtmiowrenbl ( uint16_T, IODBRTMIO *, uint32_T *, char * ) ;

/* read real-time custom macro di/do variables write enable status  (bit) */
FWLIBAPI int16_t WINAPI cnc_rdrtmiowrenblbit ( uint16_T, IODBRTMIO *, char * ) ;

/* write real-time custom macro di/do variables write enable status (per byte) */
FWLIBAPI int16_t WINAPI cnc_wrrtmiowrenblbit ( uint16_T, IODBRTMIO *, char *, int32_t ) ;

/* read real-time custom macro di/do variables write enable status (valid range) */
FWLIBAPI int16_t WINAPI cnc_rdrtmiowrenblrng ( uint16_T, IODBRTMIOR *, int32_t, uint32_T * ) ;

/* write real-time custom macro di/do variables write enable status (valid range) */
FWLIBAPI int16_t WINAPI cnc_wrrtmiowrenblrng ( uint16_T, IODBRTMIOR *, int32_t, uint32_T * ) ;

/*--------------------*/
/* RENISHAW function  */
/*--------------------*/
/* Start renishaw PLUTO sumpling */
FWLIBAPI int16_t WINAPI cnc_stplutosmpl( uint16_T, int16_t, char * ) ;

/* Read  renishaw PLUTO sumpling */
FWLIBAPI int16_t WINAPI cnc_rdplutosmpl( uint16_T, int32_t *, ODBRENPLT *) ;

/* End   renishaw PLUTO sumpling */
FWLIBAPI int16_t WINAPI cnc_edplutosmpl( uint16_T ) ;

/*---------------------------------------------*/
/* continuous positional data output function  */
/*---------------------------------------------*/
/* Start sampling */
FWLIBAPI int16_t WINAPI cnc_stpossmpl( uint16_T, int16_t, char * ) ;

/* Read sampling */
FWLIBAPI int16_t WINAPI cnc_rdpossmpl( uint16_T, int32_t *, ODBRENPLT *) ;

/* End sampling */
FWLIBAPI int16_t WINAPI cnc_endpossmpl( uint16_T ) ;

/*------------------------*/
/* Custom Board function  */
/*------------------------*/
typedef struct iodbcbp {
    int16_t datano ;
    int16_t type ;
    union {
        char    cdata ;
        int16_t   idata ;
        int32_t    ldata ;
        REALPRM rdata ;
        char    cdatas[32] ;
        int16_t   idatas[32] ;
        int32_t    ldatas[32] ;
        REALPRM rdatas[32] ;
    } u ;
} IODBCBP;



FWLIBAPI int16_t WINAPI cnc_rdcbmem( uint16_T , int32_t , int32_t , void* ) ;
FWLIBAPI int16_t WINAPI cnc_rdcbmem2( uint16_T , int16_t, int32_t , int32_t , void* ) ;
FWLIBAPI int16_t WINAPI cnc_wrcbmem( uint16_T , int32_t , int32_t , void* ) ;
FWLIBAPI int16_t WINAPI cnc_wrcbmem2( uint16_T , int16_t, int32_t , int32_t , void* ) ;
FWLIBAPI int16_t WINAPI cnc_rdcbprm( uint16_T , int16_t* , int16_t , int16_t*, int16_t*, void* ) ;
FWLIBAPI int16_t WINAPI cnc_wrcbprm( uint16_T , int16_t* , void* ) ;

/*--------------------*/
/* schedule function  */
/*--------------------*/
/* write schedule data */
FWLIBAPI int16_t WINAPI cnc_wrscdldat(uint16_T FlibHndl, int16_t s_number, int16_t e_number, int16_t length, SCDL_1D scdldat[]);

/* read schedule data */
FWLIBAPI int16_t WINAPI cnc_rdscdldat(uint16_T FlibHndl, int16_t s_number, int16_t e_number, int16_t length, SCDL_1D scdldat[]);

/* read schedule information */
FWLIBAPI int16_t WINAPI cnc_rdscdlinfo(uint16_T FlibHndl, int16_t *scdl_mode, int16_t *scdl_num, int16_t *data_no, int16_t *crnt_no);

/*---------------------*/
/* path table function */
/*---------------------*/
/* analysis data set */
FWLIBAPI int16_t WINAPI cnc_startptcnv( uint16_T FlibHndl, int16_t *request );
/* read execution state */
FWLIBAPI int16_t WINAPI cnc_rdptcnvinfo( uint16_T FlibHndl, int16_t *executing, int32_t *conv_status, int16_t *ofs_change );
/* alarm conversion */
FWLIBAPI int16_t WINAPI cnc_rdptcnvalm( uint16_T FlibHndl, int32_t *alm_no, char *prog_name, char *prog_data );

/*-------------------------------*/
/* path table function (for DGN) */
/*-------------------------------*/
/* alarm execution */
FWLIBAPI int16_t WINAPI cnc_rdptexedistalm( uint16_T FlibHndl, int32_t *dist_alm_no );
/* read execution state (for axis table)*/
FWLIBAPI int16_t WINAPI cnc_rdptaxitablestatus( uint16_T FlibHndl, int16_t type, int16_t axis, ODBPTAXISTAT *odbptaxistat );
/* read execution state (for spindle table)*/
FWLIBAPI int16_t WINAPI cnc_rdptsptablestatus( uint16_T FlibHndl, int16_t type, int16_t axis, ODBPTSPSTAT *odbptspstat );
/* read execution state (for auxiliary-function table)*/
FWLIBAPI int16_t WINAPI cnc_rdptaxfunctablestatus( uint16_T FlibHndl, int16_t type, ODBPTAXFUNCSTAT *odbptaxistat );

/*---------------------------------------------*/
/* path table function (for Direct Conversion) */
/*---------------------------------------------*/
#ifndef CNC_PPC
/* clear Path Table executive form data */
FWLIBAPI int16_t WINAPI cnc_clrptdata( uint16_T FlibHndl );
/* start direct conversion */
FWLIBAPI int16_t WINAPI cnc_ptdwnstart( uint16_T FlibHndl );
/* direct conversion */
FWLIBAPI int16_t WINAPI cnc_ptdownload( uint16_T FlibHndl, int32_t *length, char *data );
/* end direct conversion */
FWLIBAPI int16_t WINAPI cnc_ptdwnend( uint16_T FlibHndl );
/* binary data link */
FWLIBAPI int16_t WINAPI cnc_ptlink( uint16_T FlibHndl, int16_t backup );
/* binary data link (2) */
FWLIBAPI int16_t WINAPI cnc_ptlink2( uint16_T FlibHndl );
#endif
/* select binary data memory */
FWLIBAPI int16_t WINAPI cnc_slctptdata( uint16_T FlibHndl, int16_t num );
/* select binary data memory type */
FWLIBAPI int16_t WINAPI cnc_slctpttype( uint16_T FlibHndl, int16_t type );
/* read execution state (2) */
FWLIBAPI int16_t WINAPI cnc_rdptcnvinfo2( uint16_T FlibHndl, ODBPTCNVINFO2 *cnvinfo );

/*----------------------------------------------*/
/* Path Table Operation status display function */
/*----------------------------------------------*/
/* read comment, T code, PTO execution status information */
FWLIBAPI int16_t WINAPI cnc_rdptcomment( uint16_T FlibHndl, ODBPTCOMMENT *odbptcomment ) ;

/* Path Table Oparation History */
FWLIBAPI int16_t WINAPI cnc_rdpthis_num( uint16_T FlibHndl, int32_t* hist_num );
FWLIBAPI int16_t WINAPI cnc_rdpthis_gb( uint16_T FlibHndl, int32_t hist_idx, ODBPTHIS_GB *odbpthis_gb );
FWLIBAPI int16_t WINAPI cnc_rdpthis_pt( uint16_T FlibHndl, int32_t hist_idx, int32_t path, ODBPTHIS_PT *odbpthis_pt );
FWLIBAPI int16_t WINAPI cnc_rdpthis_ax( uint16_T FlibHndl, int32_t hist_idx, int32_t path, int32_t axis, ODBPTHIS_AX *odbpthis_ax );
FWLIBAPI int16_t WINAPI cnc_rdpthis_sp( uint16_T FlibHndl, int32_t hist_idx, int32_t path, int32_t spdl, ODBPTHIS_SP *odbpthis_sp );
FWLIBAPI int16_t WINAPI cnc_rdpthis_aux( uint16_T FlibHndl, int32_t hist_idx, int32_t path, ODBPTHIS_AUX *odbpthis_aux );
FWLIBAPI int16_t WINAPI cnc_rdpthis_log( uint16_T FlibHndl, int32_t hist_idx, int32_t type, int32_t path, int32_t idx, int32_t* count, ODBPTHIS_LOG *odbpthis_log );

/* Path Table Operation stop at specified reference time */
FWLIBAPI int16_t WINAPI cnc_rdptstoptime( uint16_T, double* stop_time);
FWLIBAPI int16_t WINAPI cnc_wrptstoptime( uint16_T, double stop_time);

/* Arbitrary allocating function of path table executive form data area */
FWLIBAPI int16_t WINAPI cnc_rdptcmdsize( uint16_T, int16_t cmd_id, int32_t* cmd_size );

/*---------------------*/
/* DataServer version  */
/*---------------------*/
FWLIBAPI int16_t WINAPI cnc_dtsvinfo(uint16_T  h ,int16_t *dtsvver);

/*---------------------*/
/* System Alarm Data   */
/*---------------------*/
FWLIBAPI int16_t WINAPI cnc_delsysalm(uint16_T FlibHndl);
FWLIBAPI int16_t WINAPI cnc_rdsysalm(uint16_T FlibHndl, int16_t kind, int16_t page, uint16_T length, char *data);

/*-----------------------*/
/* Parallel axis control */
/*-----------------------*/
FWLIBAPI int16_t WINAPI cnc_rdpalaxis(uint16_T FlibHndl, int16_t axis, IODBPALAX *palax);

/*------------------------*/
/* handle retrace message */
/*------------------------*/
FWLIBAPI int16_t WINAPI cnc_hdck_nochange_info(uint16_T FlibHndl, int16_t path_no, ODBAHDCK *hdck_info);

/*------------------------*/
/* Program ex-restart     */
/*------------------------*/
FWLIBAPI int16_t WINAPI cnc_rstrt_getpntcnt(uint16_T, int16_t *);
FWLIBAPI int16_t WINAPI cnc_rstrt_rdpntlist(uint16_T, int16_t, int16_t *, ODBRSTLIST *);
FWLIBAPI int16_t WINAPI cnc_rstrt_rdpnt(uint16_T, int16_t, IODBRSTINFO *);
FWLIBAPI int16_t WINAPI cnc_rstrt_rdmodal(uint16_T, int16_t, int16_t *, int16_t *, ODBGCD *, ODBCMD *);
FWLIBAPI int16_t WINAPI cnc_rstrt_selectpnt(uint16_T, int16_t);
FWLIBAPI int16_t WINAPI cnc_rstrt_wrpnt(uint16_T, uint16_T, IODBRSTINFO *);
FWLIBAPI int16_t WINAPI cnc_rstrt_createpnt(uint16_T);
FWLIBAPI int16_t WINAPI cnc_rstrt_search(uint16_T, int16_t);
FWLIBAPI int16_t WINAPI cnc_rstrt_setsuppress(uint16_T, int16_t,int16_t);
FWLIBAPI int16_t WINAPI cnc_rstrt_rdpntlist2(uint16_T, int16_t, int16_t *, ODBRSTLIST2 *);
FWLIBAPI int16_t WINAPI cnc_rstrt_rdpnt2(uint16_T, int16_t, IODBRSTINFO2 *);
FWLIBAPI int16_t WINAPI cnc_rstrt_wrpnt2(uint16_T, uint16_T, IODBRSTINFO2 *);
FWLIBAPI int16_t WINAPI cnc_rstrt_getdncprg(uint16_T, int16_t, char *);
FWLIBAPI int16_t WINAPI cnc_rstrt_rdaddinfo(uint16_T, int16_t, int16_t *, int16_t, int32_t *);
FWLIBAPI int16_t WINAPI cnc_rstrt_rdlpmppnt(uint16_T, int16_t, ODBRSTMPINFO *);
/*---------------------*/
/* spindle unit offset */
/*---------------------*/
FWLIBAPI int16_t WINAPI cnc_rdsuofs_vect( uint16_T FlibHndl, int16_t ax_idx, int16_t *ax_cnt, ODBSUOVECT *su_ofs_info );
FWLIBAPI int16_t WINAPI cnc_rdnutatortofs_vect ( uint16_T FlibHndl, int16_t ax_idx, int16_t *ax_cnt, ODBSUOVECT *su_ofs_info );
FWLIBAPI int16_t WINAPI cnc_rdsuo_prm_name( uint16_T h, int16_t data_idx, ODBSUODATA *su_data, int16_t *length );
/*---------------------*/
/* Memory Card         */
/*---------------------*/
/* Get informatin of files in Memory card */
FWLIBAPI int16_t WINAPI cnc_rdmcdfinfo(uint16_T FlibHndl, int32_t file_no, ODBFILESTATUS *file_inf);
/* Cancel informatin of files in Memory card */
FWLIBAPI int16_t WINAPI cnc_canmcdfinfo(uint16_T FlibHndl);
/* Check existence of file in Memory card */
FWLIBAPI int16_t WINAPI cnc_chkmcdfile(uint16_T FlibHndl, char* fname, char* exist);
/* Delete file in Memory card */
FWLIBAPI int16_t WINAPI cnc_delmcdfile(uint16_T FlibHndl, char* fname);
/* Delete file by number in Memory card */
FWLIBAPI int16_t WINAPI cnc_delmcdfilebynum(uint16_T FlibHndl, int32_t file_no);
/* Get program comment in Memory card */
FWLIBAPI int16_t WINAPI cnc_rdmcdprgcmnt(uint16_T FlibHndl, char *fname, ODBPROGINFO *prog_inf);

FWLIBAPI int16_t WINAPI cnc_rdpmcaxisinfo(uint16_T FlibHndl, int16_t axis, int16_t type, ODBPMCAXISINFO *pmcaxisinfo);

/*---------------------*/
/* USB Memory          */
/*---------------------*/
FWLIBAPI int16_t WINAPI cnc_rdusbdevinfo(uint16_T, char, ODBUSBSIZE *);
FWLIBAPI int16_t WINAPI cnc_rdusbfilelist(uint16_T, IDBUSBFILE *, ODBUSBINFO *, ODBUSBFILE *);
FWLIBAPI int16_t WINAPI cnc_usbmkdir(uint16_T, char *);
FWLIBAPI int16_t WINAPI cnc_usbrmdir(uint16_T, char *);
FWLIBAPI int16_t WINAPI cnc_usbremove(uint16_T, char *);
FWLIBAPI int16_t WINAPI cnc_usbrename(uint16_T, char *, char *);
FWLIBAPI int16_t WINAPI cnc_chkusbfile(uint16_T, char* , char* );
FWLIBAPI int16_t WINAPI cnc_searchusbfile(uint16_T, IDBUSBSEARCH *, uint32_T *);
FWLIBAPI int16_t WINAPI cnc_chkusbmount (uint16_T, char, uint16_T * );
FWLIBAPI int16_t WINAPI cnc_writeusbfile(uint16_T h, char* path, char* buf, int32_t buf_size);
/*---------------------------------------------*/
/* IS-E int32_t stroke type                       */
/*---------------------------------------------*/
/* read various axis data (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdaxisdata64( uint16_T, int16_t, int16_t *, int16_t, int16_t *, ODBAXDT64 * );

/* preset work coordinate (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_prstwkcd64( uint16_T, int16_t, IDBWRA64 * ) ;

/* set origin / preset relative axis position (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_wrrelpos64( uint16_T, int16_t, IDBWRR64 * ) ;

/* read command value (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdcommand64( uint16_T, int16_t, int16_t, int16_t *, ODBCMD64 * ) ;

/* read parameter (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdparam64( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBPSD64 * ) ;

/* write parameter (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_wrparam64( uint16_T, int16_t, int16_t, IODBPSD64 * ) ;

/* read validity of work zero offset (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_zofs_rnge64( uint16_T, int16_t, int16_t, ODBDATRNG64 * );

/* read work zero offset value(area specified) */
FWLIBAPI int16_t WINAPI cnc_rdzofsr64( uint16_T, int16_t, int16_t, int16_t, int16_t, IODBZOR64 * ) ;

/* write work zero offset value (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_wrzofs64( uint16_T, int16_t, IODBZOFS64 * ) ;

/* read validity of work shift value (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_wksft_rnge64( uint16_T, int16_t, ODBDATRNG64 * );

/* read work coordinate shift64 (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdwkcdshft64( uint16_T, int16_t, int16_t, int16_t, IODBWCSF64 * ) ;

/* write work coordinate shift64 (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_wrwkcdshft64( uint16_T, int16_t, int16_t, IODBWCSF64 * );

/* read work coordinate shift measure64 (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdwkcdsfms64( uint16_T, int16_t, int16_t, int16_t, IODBWCSF64 * );

/* write work coordinate shift measure64 (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_wrwkcdsfms64( uint16_T, int16_t, int16_t, IODBWCSF64 * );

/* read diagnosis data (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_diagnoss64( uint16_T, int16_t, int16_t, int16_t, ODBDGN64 * );

/* read diagnosis data (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_diagnosr64( uint16_T, int16_t *, int16_t, int16_t *, int16_t *, void * ) ;

/* Set Tool Offset Direct Input (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_wrtofsdrctinp64( uint16_T, int16_t, int16_t, REALMES64 );

/* read hole measurement data (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdholmes64(uint16_T, ODBHOLDATA64 * );

/* read center data (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdcenter64(uint16_T, double *, double *, int32_t *, int32_t *, int32_t *, int32_t * );

/* read work offset measurement data (IEEE double version) */
FWLIBAPI int16_t WINAPI cnc_rdzofsmes64(uint16_T, int32_t, double, int32_t, double *, int32_t * );

/*----------------------------*/
/* High-speed Program Manager */
/*----------------------------*/
/* Calling with  function of program save */
FWLIBAPI int16_t WINAPI cnc_saveprog_start(uint16_T FlibHndl);
/* Get the result of cnc_saveprog_start function */
FWLIBAPI int16_t WINAPI cnc_saveprog_end(uint16_T FlibHndl, int16_t *result);

/*------------------------*/
/* Modification detection */
/*------------------------*/
FWLIBAPI int16_t WINAPI cnc_mdd_unlock( uint16_T, int16_t, char * );
FWLIBAPI int16_t WINAPI cnc_mdd_lock( uint16_T, int16_t );
FWLIBAPI int16_t WINAPI cnc_mdd_setpassword( uint16_T, int16_t, char * );
FWLIBAPI int16_t WINAPI cnc_mdd_unregister( uint16_T, int16_t );
FWLIBAPI int16_t WINAPI cnc_mdd_register( uint16_T, int16_t );
FWLIBAPI int16_t WINAPI cnc_mdd_rdinfo( uint16_T, int16_t, ODBMDDINFO * );
FWLIBAPI int16_t WINAPI cnc_mdd_setswitch( uint16_T, int16_t, uint16_T );
FWLIBAPI int16_t WINAPI cnc_mdd_getswitch( uint16_T, int16_t, uint16_T * );
FWLIBAPI int16_t WINAPI cnc_mdd_setexceptparam(uint16_T, int16_t, int16_t, IODBMDDEXCEPTPRM *);
FWLIBAPI int16_t WINAPI cnc_mdd_getexceptparam(uint16_T, int16_t, int16_t, IODBMDDEXCEPTPRM *);
FWLIBAPI int16_t WINAPI cnc_mdd_update( uint16_T, int16_t);

/*------------------------*/
/* Robot Connect Function */
/*------------------------*/
/* read robot signal status*/
FWLIBAPI int16_t WINAPI cnc_robo_rdsignals(uint16_T, char, char, uint16_T, uint16_T *, ODBRBSIGNAL *);
/* read robot alarm messages*/
FWLIBAPI int16_t WINAPI cnc_robo_rdalmmsg(uint16_T, uint16_T, uint16_T*, IODBRBALMMSG *alm_msg);
/* read robot-NC program groups*/
FWLIBAPI int16_t WINAPI cnc_robo_rdgrouplist(uint16_T , uint16_T, uint16_T*, ODBRBGRPLIST*);
/* write robot-NC program group*/
FWLIBAPI int16_t WINAPI cnc_robo_wrgroup(uint16_T, uint16_T, IDBRBGROUP *);
/* select robot-NC proguram group*/
FWLIBAPI int16_t WINAPI cnc_robo_selectgroup(uint16_T, uint16_T);
/* write robot signal names*/
FWLIBAPI int16_t WINAPI cnc_robo_wrsignalname(uint16_T, char, uint16_T, uint16_T*, IDBRBSIGNAL*);
/* write robot alarm messages*/
FWLIBAPI int16_t WINAPI cnc_robo_wralmmsg(uint16_T, uint16_T, uint16_T*, IODBRBALMMSG*);
/* write robot communication setting*/
FWLIBAPI int16_t WINAPI cnc_robo_wrcomsetting(uint16_T, uint16_T, IODBRBCOMSET*);
/* read robot communication setting*/
FWLIBAPI int16_t WINAPI cnc_robo_rdcomsetting(uint16_T, IODBRBCOMSET *);
/* write selected signals */
FWLIBAPI int16_t WINAPI cnc_robo_wrselectedsignals(uint16_T, uint16_T, uint16_T*,IODBRBSUMMARY *);
/* read selected signals*/
FWLIBAPI int16_t WINAPI cnc_robo_rdselectedsignals(uint16_T, uint16_T, uint16_T*,IODBRBSUMMARY *);

/* read robot signal status*/
FWLIBAPI int16_t WINAPI cnc_robo_rdsignals2(uint16_T, char, char, uint16_T, uint16_T *, IODBRBSIGNAL2 *);
/* write robot signal status*/
FWLIBAPI int16_t WINAPI cnc_robo_wrsignals2(uint16_T, char, uint16_T, uint16_T, IODBRBSIGNAL2 *);
/* clear robot signal status*/
FWLIBAPI int16_t WINAPI cnc_robo_clrsignals(uint16_T);
/* read property at power-on*/
FWLIBAPI int16_t WINAPI cnc_robo_rdponprop(uint16_T, unsigned char *);

/*------------------------------*/
/* T-code Message Read Function */
/*------------------------------*/
/* read tcode message */
FWLIBAPI int16_t WINAPI cnc_rdtcodemsg(uint16_T, char *);

/*------------------------*/
/* Auxiliary status       */
/*------------------------*/
FWLIBAPI int16_t WINAPI cnc_aux_statinfo(uint16_T h, uint32_T *stat);

/* Read IndexAxis data  ( idxax paramter screen )       */
FWLIBAPI int16_t WINAPI cnc_rdindexprm( uint16_T, int16_t, IODBINDEXPRM * );
/* Write IndexAxis data ( idxax paramter screen )       */
FWLIBAPI int16_t WINAPI cnc_wrindexprm( uint16_T, int16_t, int16_t, IODBINDEXPRM * );
/* Read IndexAxis data  ( idxax position screen )       */
FWLIBAPI int16_t WINAPI cnc_rdindexdata( uint16_T, int16_t, int16_t, int16_t *, IODBINDEXDAT * );
/* Write IndexAxis data ( idxax position screen )       */
FWLIBAPI int16_t WINAPI cnc_wrindexdata( uint16_T, int16_t, int16_t, int16_t, IODBINDEXDAT * );
/* Read IndexAxis offset data  ( idxax position screen )*/
FWLIBAPI int16_t WINAPI cnc_rdindexofs( uint16_T, int16_t, int32_t * );
/* Write IndexAxis offset data ( idxax position screen )*/
FWLIBAPI int16_t WINAPI cnc_wrindexofs( uint16_T, int16_t, int32_t * );
/* Read IndexAxis data  ( idxax pos-switch screen )     */
FWLIBAPI int16_t WINAPI cnc_rdindexposdata( uint16_T, int16_t, int16_t, int16_t *, IODBINDEXPOSDAT * );
/* Write IndexAxis data ( idxax pos-switch screen )     */
FWLIBAPI int16_t WINAPI cnc_wrindexposdata( uint16_T, int16_t, int16_t, int16_t, IODBINDEXPOSDAT * );
/* Read IndexAxis infomation for idxax screen           */
FWLIBAPI int16_t WINAPI cnc_rdindexinfo( uint16_T, int16_t, ODBINDEXINFO * );

/*------------------------*/
/* Chopping Function      */
/*------------------------*/
FWLIBAPI int16_t WINAPI cnc_rdchopping(uint16_T h, ODBCHOPPING *chopping);

/*----------------------------*/
/* Safety I/O signal history  */
/*----------------------------*/
/* read safety I/O signal history log information */
FWLIBAPI int16_t WINAPI cnc_rd_sfsg_loginf( uint16_T, ODBSFSGLOGINF *sfsgloginf);
/* read safety I/O signal history signal information */
FWLIBAPI int16_t WINAPI cnc_rd_sfsg_siginf( uint16_T, int16_t sno_sig, int16_t *len_sig, int16_t extract,
                            ODBSFSGSIGINFEX *sfsg_siginf_ex_pmc,
                            ODBSFSGSIGINFEX *sfsg_siginf_ex_dcs);
/* read safety I/O signal history signal history */
FWLIBAPI int16_t WINAPI cnc_rd_sfsg_sighis( uint16_T, IODBSFSGSIGHIS *sfsg_sighis, unsigned char *sig_his_pmc, unsigned char *sig_his_dcs);
/* read safety I/O signal history total signal number */
FWLIBAPI int16_t WINAPI cnc_rd_sfsg_signal_num( uint16_T, ODBSFSGSIGNALNUM *sfsg_signal_num);
/* read safety I/O signal history alarm count */
FWLIBAPI int16_t WINAPI cnc_rd_sfsg_update_count( uint16_T, uint16_T *update_count);
/* read safety I/O signal history signal search */
FWLIBAPI int16_t WINAPI cnc_rd_sfsg_search( uint16_T, IODBSFSGSIGINF *sfsg_siginf, int16_t extract, int16_t *no_sig);
/* write safety I/O signal history extract status */
FWLIBAPI int16_t WINAPI cnc_wr_sfsg_extractslct( uint16_T, int16_t no_sig, int16_t select, int16_t extract);
/* read safety I/O signal history display status */
FWLIBAPI int16_t WINAPI cnc_rd_sfsg_disp_stat( uint16_T, IODBSFSGDSPSTAT *sfsg_dsp_stat);
/* write safety I/O signal history display status */
FWLIBAPI int16_t WINAPI cnc_wr_sfsg_disp_stat( uint16_T, IODBSFSGDSPSTAT *sfsg_dsp_stat, int16_t select);

/*-------------------------------------------------------*/
/* 5 axis machining configuration selection function     */
/*-------------------------------------------------------*/
/* read 5-axis machining configuration data */
FWLIBAPI int16_t WINAPI cnc_s5s_rdparam(uint16_T FlibHndl, int16_t set_num, int16_t number, int16_t axis, int16_t length, IODBPSD *param); 
/* write 5-axis machining configuration data */
FWLIBAPI int16_t WINAPI cnc_s5s_wrparam(uint16_T FlibHndl, int16_t set_num, int16_t length, IODBPSD *param);
/* read 5-axis machining configuration name */
FWLIBAPI int16_t WINAPI cnc_s5s_rdname(uint16_T FlibHndl,int16_t set_num, char *setname);
/* write 5-axis machining configuration name */
FWLIBAPI int16_t WINAPI cnc_s5s_wrname(uint16_T FlibHndl, int16_t set_num, char *setname);
/* read maximum, minimum and total number of 5-axis machining configuration data */
FWLIBAPI int16_t WINAPI cnc_s5s_rdparanum(uint16_T FlibHndl, ODBPARANUM *paranum);
/* read informations of 5-axis machining configuration data */
FWLIBAPI int16_t WINAPI cnc_s5s_rdparainfo2(uint16_T FlibHndl, int16_t s_number, int16_t* read_no, int16_t* prev_no, int16_t* next_no, ODBPARAIF2 info[]);
/* read current 5-axis machining configuration set number */
FWLIBAPI int16_t WINAPI cnc_s5s_rdactset(uint16_T FlibHndl, int16_t* set_num);
/* write current 5-axis machining configuration set number */
FWLIBAPI int16_t WINAPI cnc_s5s_wractset(uint16_T FlibHndl, int16_t set_num);

/*-----------------------------------*/
/* Machine Status Monitor / Recorder */
/*-----------------------------------*/
FWLIBAPI int16_t WINAPI cnc_msr_stop_sample(uint16_T h);
FWLIBAPI int16_t WINAPI cnc_msr_start_sample(uint16_T h);
FWLIBAPI int16_t WINAPI cnc_msr_rdhis_allnum(uint16_T h,int16_t *his_num);
FWLIBAPI int16_t WINAPI cnc_msr_rdhis_inf(uint16_T h, int16_t st_no, int16_t *num, ODBMSRHSTINF *hstinf);
FWLIBAPI int16_t WINAPI cnc_msr_rdhis_msudat(uint16_T h, int16_t hst_no, int16_t msu_no, ODBMSUDAT *msudat);
FWLIBAPI int16_t WINAPI cnc_msr_rdhis_pmc_ex(uint16_T FlibHndl,int16_t hst_no, int16_t expmcsgnl_no, ODBEXPMCSGNL *expmcsgnl);
FWLIBAPI int16_t WINAPI cnc_msr_rdhis_pmc(uint16_T h, int16_t hst_no, ODBMSRPMCSGNL *pmcsgnl);
FWLIBAPI int16_t WINAPI cnc_msr_rdhis_ncdat(uint16_T h, int16_t hst_no, int16_t path_no, ODBMSRNCDAT *ncdat);
FWLIBAPI int16_t WINAPI cnc_msr_delhis_all(uint16_T h);
FWLIBAPI int16_t WINAPI cnc_msr_rdmon_msunum(uint16_T h, int16_t *msu_num);
FWLIBAPI int16_t WINAPI cnc_msr_rdmon_msudat(uint16_T h, int16_t msu_no, ODBMSUDAT *msudat);
FWLIBAPI int16_t WINAPI cnc_msr_rdmon_pmcinf_ex(uint16_T FlibHndl,int16_t expmcsgnl_no, ODBEXPMCSGNL *expmcsgnl);
FWLIBAPI int16_t WINAPI cnc_msr_rdmon_pmcinf(uint16_T h, ODBMSRPMCSGNL *pmcsgnl);
FWLIBAPI int16_t WINAPI cnc_msr_rdhis_ohisnum(uint16_T h, int16_t hst_no, uint16_T *num);
FWLIBAPI int16_t WINAPI cnc_msr_rdhis_ohisrec(uint16_T h, int16_t hst_no, uint16_T st_no, uint16_T *ed_no,
                                      uint16_T *len, void *db) ;

/*------------*/
/* Eco Mode   */
/*------------*/
FWLIBAPI int16_t WINAPI cnc_powc_rd_cycle_data(uint16_T h, int16_t lev, int16_t atrb, ODBPOWCCYC *powccyc);
FWLIBAPI int16_t WINAPI cnc_powc_clear_inte(uint16_T h);
FWLIBAPI int16_t WINAPI cnc_powc_rd_clear_time(uint16_T h, uint32_T *clear_time);
FWLIBAPI int16_t WINAPI cnc_powc_wr_outer_set(uint16_T h, int16_t data_no, ODBPOWCOUTER *powcouter);
FWLIBAPI int16_t WINAPI cnc_powc_rd_outer_set(uint16_T h, ODBPOWCOUTER *powcouter);
FWLIBAPI int16_t WINAPI cnc_powc_del_cycle_data(uint16_T h, int16_t lev);
FWLIBAPI int16_t WINAPI cnc_powc_rd_history(uint16_T h, int16_t unit, int16_t *num, ODBPOWCHISALL *powchisall);

/*------------------------------*/
/* Power Consumption Monitor	*/
/*------------------------------*/
FWLIBAPI int16_t WINAPI cnc_pwcm_clear_consump(uint16_T h);
/* read power consumption */
FWLIBAPI int16_t WINAPI cnc_pwcm_rd_consump(uint16_T FlibHndl, int16_t type, ODBPWCMDAT *power);

/*-------------------------*/
/* LASER                   */
/*-------------------------*/
/* write processing condition file (edging data) */
FWLIBAPI int16_t WINAPI cnc_wrpscdedge2(uint16_T ,int16_t ,int16_t *, IODBEDGE2 *) ;
/* read processing condition file (edging data)  */
FWLIBAPI int16_t WINAPI cnc_rdpscdedge2(uint16_T ,int16_t ,int16_t *, IODBEDGE2 *) ;
/* write processing condition file (power control data) */
FWLIBAPI int16_t WINAPI cnc_wrlpscdpwrctl(uint16_T ,int16_t ,int16_t *, IODBPWRCTL *); 
/* read processing condition file (power control data)  */
FWLIBAPI int16_t WINAPI cnc_rdlpscdpwrctl(uint16_T ,int16_t ,int16_t *, IODBPWRCTL *); 
/* read displacement */
FWLIBAPI int16_t WINAPI cnc_rdldsplc2(uint16_T ,IODBDSPLC *);
/* write displacement */
FWLIBAPI int16_t WINAPI cnc_wrldsplc2(uint16_T ,IODBDSPLC *);
/* write agingmode */
FWLIBAPI int16_t WINAPI cnc_wrlagingmode(uint16_T ,int16_t );
/* read agingmode */
FWLIBAPI int16_t WINAPI cnc_rdlagingmode(uint16_T ,int16_t *);
/* read agingtime */
FWLIBAPI int16_t WINAPI cnc_rdlagingtime(uint16_T ,int16_t *);
/* read laser state */
FWLIBAPI int16_t WINAPI cnc_rdlhsstate(uint16_T ,ODBLSTATE *) ;
/* read laser power offset */
FWLIBAPI int16_t WINAPI cnc_rdlpoweroffset(uint16_T , ODBLPWOFS *) ;
/* write laser work data */
FWLIBAPI int16_t WINAPI cnc_wrlswork(uint16_T , IDBLSWORK *) ;
/* read laser alarm history */
FWLIBAPI int16_t WINAPI cnc_rdlalmhistry( uint16_T, uint16_T , uint16_T , uint16_T , ODBLALMHIS * );
/* read  uvmacro pointer */
FWLIBAPI int16_t WINAPI cnc_rduvactpt2( uint16_T, ODBUVMCRPT2 * );
/* read nozzle tip machine position */
FWLIBAPI int16_t WINAPI cnc_rdlnzlmcn( uint16_T, int16_t, int16_t, ODBAXIS * ) ;
/*$ read fiber data $*/
FWLIBAPI int16_t WINAPI cnc_rdlfiberdata(uint16_T, int16_t, int16_t, int16_t *, int32_t *) ;
/*----------------------------------*/
/* cut condition customize function */
/*----------------------------------*/
FWLIBAPI int16_t WINAPI cnc_lctcdcstm(uint16_T , uint16_T , uint16_T , unsigned char *, unsigned char *) ;
FWLIBAPI int16_t WINAPI cnc_rdlcstmname(uint16_T , uint16_T , uint16_T , unsigned char *, unsigned char *) ;
/*---------------------------------------*/
/* read/write punchpress tool data       */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_rd1punchtl_ex( uint16_T, IODBPUNCH1_EX *) ;
FWLIBAPI int16_t WINAPI cnc_wrpunchtl_ex( uint16_T, int16_t, IODBPUNCH1_EX *) ;
FWLIBAPI int16_t WINAPI cnc_rd2punchtl_ex( uint16_T, IODBPUNCH2_EX *) ;

/*---------------------------------------*/
/* Tilted Working Plane Command          */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_twp_rdfcoord(uint16_T, char, ODBCOORD *); 
FWLIBAPI int16_t WINAPI cnc_twp_rdfmt_mtrx(uint16_T, int16_t, IDBTWPFORM *, ODBFTRMTX *);

/*---------------------------------------*/
/* Machining Condition Setting           */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_mcs_rdparam(uint16_T, int16_t, int16_t, int16_t, int16_t, IODBPSD *);
FWLIBAPI int16_t WINAPI cnc_mcs_wrparam(uint16_T, int16_t, int16_t, IODBPSD *);
FWLIBAPI int16_t WINAPI cnc_mcs_rdparanum(uint16_T, ODBPARANUM *);
FWLIBAPI int16_t WINAPI cnc_mcs_rdparainfo2(uint16_T, int16_t, int16_t *, int16_t *, int16_t *, ODBPARAIF2 *);
FWLIBAPI int16_t WINAPI cnc_mcs_rdactset(uint16_T, int16_t *);
FWLIBAPI int16_t WINAPI cnc_mcs_wractset(uint16_T, int16_t);
FWLIBAPI int16_t WINAPI cnc_mcs_rdheader(uint16_T, int16_t, ODBMCSHEAD *);
FWLIBAPI int16_t WINAPI cnc_mcs_wrheader(uint16_T, int16_t, ODBMCSHEAD *, char);
FWLIBAPI int16_t WINAPI cnc_mcs_rdcompparam(uint16_T, char *);

/*---------------------------------------*/
/* Peripheral axis control               */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_getpaxispath(uint16_T, int16_t *, int16_t *);

/*---------------------------------------*/
/* read program alarm status             */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_rdalarmchar(uint16_T, int16_t *, int16_t *); 

/*---------------------------------------*/
/* High Motion Compile (PMi-A only)      */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_start_hm_cmpl(uint16_T, int32_t);
FWLIBAPI int16_t WINAPI cnc_rd_hm_cmpl_stat(uint16_T, int32_t *, uint32_T *, int16_t *, int16_t *);

/*---------------------------------------------------*/
/* Multi-Axes High Response Progam (PMi-A only)      */
/*---------------------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_rd_hm_progstat(uint16_T, int32_t, int16_t *, ODBHMPROGSTAT *);
FWLIBAPI int16_t WINAPI cnc_set_hm_progno(uint16_T, int32_t);
FWLIBAPI int16_t WINAPI cnc_rd_hm_execprog(uint16_T, uint16_T *, char *);

FWLIBAPI int16_t WINAPI cnc_rdprgrmupdtcnt(uint16_T, uint32_T*);

/*---------------------------------------------------*/
/* Teach Program Function (PMi-A only)               */
/*---------------------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_tprog_rdprg_by_num( uint16_T, int32_t *, int32_t, int32_t, ODBTPAPRG *);
FWLIBAPI int16_t WINAPI cnc_tprog_rdprg_by_name( uint16_T, int32_t *, char *, int32_t, ODBTPAPRG *);
FWLIBAPI int16_t WINAPI cnc_tprog_wrinfo( uint16_T, int16_t, char *, IDBTPINFO *);
FWLIBAPI int16_t WINAPI cnc_tprog_rdcmd( uint16_T, char *, int32_t, int32_t, ODBTPEDTCMD *);
FWLIBAPI int16_t WINAPI cnc_tprog_editcmd( uint16_T, char *, int32_t , int32_t, IDBTPCMD *);
FWLIBAPI int16_t WINAPI cnc_tprog_rdline( uint16_T, char *, int32_t, char *, uint32_T *, uint32_T *);
FWLIBAPI int16_t WINAPI cnc_tprog_st_convert(uint16_T, int16_t, int16_t) ;
FWLIBAPI int16_t WINAPI cnc_tprog_convert_stat(uint16_T, int32_t *, int32_t *, int32_t *, int16_t *, int16_t *) ;
FWLIBAPI int16_t WINAPI cnc_tprog_rdpos( uint16_T, char *, uint16_T, uint16_T *, int32_t *);
FWLIBAPI int16_t WINAPI cnc_tprog_wrpos( uint16_T, char *, uint16_T, uint16_T *, int32_t *);

/*---------------------------------------------------*/
/* Electric Cam Data SRAM Use (PMi-A only)           */
/*---------------------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_rdecamdatar(uint16_T, uint32_T, uint32_T *, int32_t *);
FWLIBAPI int16_t WINAPI cnc_wrecamdatar(uint16_T, uint32_T, uint32_T *, int32_t *);

/*---------------------------------------*/
/*   PDSA Pulse Input Diag               */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI dsa_rdpulsediag(uint16_T, ODBPLSDATA *);

/*---------------------------------------*/
/* Main Menu      */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_rd_mm_setting_data(uint16_T, int16_t, int16_t, int16_t*, ODBMMSCRNINF*);
FWLIBAPI int16_t WINAPI cnc_wr_mm_setting_data(uint16_T, int16_t, int16_t, int16_t, ODBMMSCRNINF*);
FWLIBAPI int16_t WINAPI cnc_rd_mm_icn_cstm_str_num(uint16_T, int16_t*);
FWLIBAPI int16_t WINAPI cnc_rd_mm_icn_cstm_str_data(uint16_T, int16_t, int16_t*, IODBMMICONCSTMSTRING*);
FWLIBAPI int16_t WINAPI cnc_wr_mm_icn_cstm_str_data(uint16_T, int16_t, int16_t, IODBMMICONCSTMSTRING*);
FWLIBAPI int16_t WINAPI cnc_rd_mm_ctgry_cstm_str_data(uint16_T, int16_t, int16_t*, IODBMMCTGRYCSTMSTRING*);
FWLIBAPI int16_t WINAPI cnc_wr_mm_ctgry_cstm_str_data(uint16_T, int16_t, int16_t, IODBMMCTGRYCSTMSTRING*);
FWLIBAPI int16_t WINAPI cnc_rd_mm_mc_dflt_scrn_inf(uint16_T, int16_t, int16_t, int16_t*, ODBMMSCRNINF*);
FWLIBAPI int16_t WINAPI cnc_rd_mm_mc_scrn_def_num(uint16_T, int16_t*);
FWLIBAPI int16_t WINAPI cnc_rd_mm_mc_scrn_def_data(uint16_T, int16_t, int16_t*, IODBMMMCSCRNDEFDAT*);
FWLIBAPI int16_t WINAPI cnc_rd_mm_mc_ctgry_def_data(uint16_T, int16_t, int16_t*, IODBMMMCCTGRYDEFDAT* );
FWLIBAPI int16_t WINAPI cnc_rd_mm_mc_message_string(uint16_T, int32_t, char*, int32_t*);

/*----------------------------*/
/* Machining simulation       */
/*----------------------------*/
#ifndef CNC_PPC
FWLIBAPI int16_t WINAPI anm_simuopen(uint16_T, char, int32_t, char *);
FWLIBAPI int16_t WINAPI anm_simuclose(uint16_T);
FWLIBAPI int16_t WINAPI anm_simurwd(uint16_T, char, int32_t, char *);
FWLIBAPI int16_t WINAPI anm_simustart(uint16_T);
FWLIBAPI int16_t WINAPI anm_simustop(uint16_T);
FWLIBAPI int16_t WINAPI anm_simuproc(uint16_T);
FWLIBAPI int16_t WINAPI anm_simusngl(uint16_T);
FWLIBAPI int16_t WINAPI anm_rdsimuelm(uint16_T, IODBSIMUELM *);
FWLIBAPI int16_t WINAPI anm_rdsimuelm2(uint16_T, IODBSIMUELM2 *);
#endif

/*----------------*/
/* Block distance */
/*----------------*/
FWLIBAPI int16_t WINAPI cnc_rdblkdist(uint16_T, REALDATA *);

FWLIBAPI int16_t WINAPI cnc_reqsvgtung( uint16_T, int16_t, int16_t, ODBTUNREQ * ) ;
FWLIBAPI int16_t WINAPI cnc_stopsvgtung( uint16_T ) ;
FWLIBAPI int16_t WINAPI cnc_rdsvgtungstat( uint16_T, int16_t, int16_t, ODBTUNSTAT * ) ;

/*------------------------*/
/* Reducing Cycle Time    */
/*------------------------*/
FWLIBAPI int16_t WINAPI cnc_rct_rdCtgInfo(uint16_T, uint16_T, uint16_T*, uint16_T* );
FWLIBAPI int16_t WINAPI cnc_rct_rdItem   (uint16_T, uint16_T, IODBRCT_ITEM* );
FWLIBAPI int16_t WINAPI cnc_rct_wrItem   (uint16_T, uint16_T, IODBRCT_ITEM* );
FWLIBAPI int16_t WINAPI cnc_rct_wrRecom  (uint16_T, int32_t, int16_t );
FWLIBAPI int16_t WINAPI cnc_rct_rdRcmAdjst  (uint16_T, int16_t, int16_t*, int16_t*, int16_t* );
FWLIBAPI int16_t WINAPI cnc_rct_wrRcmAdjst  (uint16_T, int16_t, int16_t );
FWLIBAPI int16_t WINAPI cnc_rct_wrOvLp   (uint16_T, int16_t, int16_t );
FWLIBAPI int16_t WINAPI cnc_rct_cpSlctPtn(uint16_T, int32_t, uint16_T, uint16_T );
FWLIBAPI int16_t WINAPI cnc_rct_rdGrpName(uint16_T, uint16_T, IODBRCT_CSTMNAME* );
FWLIBAPI int16_t WINAPI cnc_rct_wrGrpName(uint16_T, uint16_T, IODBRCT_CSTMNAME* );
FWLIBAPI int16_t WINAPI cnc_rct_rdPtnSlct(uint16_T, uint16_T, IODBRCT_GRPPTN* );
FWLIBAPI int16_t WINAPI cnc_rct_wrPtnSlct(uint16_T, uint16_T, IODBRCT_GRPPTN* );
FWLIBAPI int16_t WINAPI cnc_rct_rdslctptnname(uint16_T, ODBRCT_SLCTPTNNAME* );
FWLIBAPI int16_t WINAPI cnc_rct_rdptnadjst(uint16_T, int16_t, int16_t*, int16_t*, int16_t*);
FWLIBAPI int16_t WINAPI cnc_rct_wrptnadjst(uint16_T, int16_t, int16_t*);
FWLIBAPI int16_t WINAPI cnc_rct_rdtunemoni(uint16_T, int16_t, int16_t*, int16_t*);

/*---------------------------------------*/
/*   Pressure position control           */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_rdpressure(uint16_T, int16_t, int16_t *, ODBPRESSURE *);

/*------------------------*/
/*   Position (ExDigit)   */
/*------------------------*/
FWLIBAPI int16_t WINAPI cnc_absolute2_exdgt(uint16_T FlibHndl, ODBEXPOS *axis_data);
FWLIBAPI int16_t WINAPI cnc_machine_exdgt(uint16_T FlibHndl, ODBEXPOS *axis_data);
FWLIBAPI int16_t WINAPI cnc_relative2_exdgt(uint16_T FlibHndl, ODBEXPOS *axis_data);
FWLIBAPI int16_t WINAPI cnc_distance_exdgt(uint16_T FlibHndl, ODBEXPOS *axis_data);

/*------------------------------*/
/* Scroll Waiting Mcode Setting */
/*------------------------------*/
FWLIBAPI int16_t WINAPI cnc_wr_scrlwaitmcode ( uint16_T, int16_t, int16_t*, IODBWAITMCODE* );
FWLIBAPI int16_t WINAPI cnc_rd_scrlwaitmcode ( uint16_T, int16_t, int16_t*, IODBWAITMCODE* );
FWLIBAPI int16_t WINAPI cnc_del_scrlwaitmcode( uint16_T );

/*------------------------*/
/* Smart Adaptive control */
/*------------------------*/
FWLIBAPI int16_t WINAPI cnc_rdsoc_curdat(uint16_T, int16_t, ODBSOCCUR* );
FWLIBAPI int16_t WINAPI cnc_rdsoc_wave_start(uint16_T, int16_t );
FWLIBAPI int16_t WINAPI cnc_rdsoc_wave(uint16_T, int32_t*, uint16_T* );
FWLIBAPI int16_t WINAPI cnc_rdsoc_wave_end(uint16_T );
FWLIBAPI int16_t WINAPI cnc_soc_wave_setchnl(uint16_T, int16_t* );
FWLIBAPI int16_t WINAPI cnc_rdsoc_tlatrr ( uint16_T, int16_t, int16_t*, int16_t, int16_t*, int16_t*, int16_t*, ODBSOCTLATTR* );
FWLIBAPI int16_t WINAPI cnc_rdsoc_tldat  ( uint16_T, int16_t, int16_t*, int16_t, int16_t*, char, IODBSOCTLDAT* );
FWLIBAPI int16_t WINAPI cnc_wrsoc_tldat  ( uint16_T, int16_t, int16_t*, int16_t, int16_t*, IODBSOCTLDAT* );
	
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

FWLIBAPI int16_t WINAPI cnc_pmclad_screen(uint16_T FwHndl, int iCommand, void * pParam, PMCLAD_MESSAGE *pstMessage);

#ifndef CNC_PPC
typedef struct odbdllversion {
	struct {
		char Name[260];
		char FileVersion[32];
		char ProductVersion[32];
	} dll[2];
} ODBDLLVERSION;

FWLIBAPI int16_t WINAPI cnc_getdllversion( uint16_T FwHndl, ODBDLLVERSION *vers );
#endif

/*---------------------------------------*/
/* Linux process and thread              */
/*---------------------------------------*/
FWLIBAPI int16_t WINAPI cnc_startupprocess(int32_t, const char *);
FWLIBAPI int16_t WINAPI cnc_exitprocess();
FWLIBAPI int16_t WINAPI cnc_exitthread();

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
