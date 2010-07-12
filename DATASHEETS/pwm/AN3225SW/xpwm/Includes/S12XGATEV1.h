/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12XGATEV1.h,v $                        */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for S12X XGATE register block                        */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/*                                                                           */
/* DESCRIPTION:  Defines the Interrupt register block as a datastructure     */
/*               of type tXGATE.                                             */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR       DATE       DESCRIPTION OF CHANGE                        */
/* ---  ------      --------    ---------------------                        */
/* 1.0  r32151      24/02/05    Initial coding based on s12x_xgate.h         */
/* 2.0  r32151      13/04/05    Added alternative (more intuitive) bit masks */
/*                              for the control register mask bits.          */
/*===========================================================================*/
/* Freescale reserves the right to make changes without further notice to any*/
/* product herein to improve reliability, function, or design. Freescale does*/
/* not assume any  liability arising  out  of the  application or use of any */
/* product,  circuit, or software described herein;  neither  does it convey */
/* any license under its patent rights  nor the  rights of others.  Freescale*/
/* products are not designed, intended,  or authorized for use as components */
/* in  systems  intended  for  surgical  implant  into  the  body, or  other */
/* applications intended to support life, or  for any  other application  in */
/* which the failure of the Freescale product  could create a situation where*/
/* personal injury or death may occur. Should Buyer purchase or use Freescale*/
/* products for any such intended  or unauthorized  application, Buyer shall */
/* indemnify and  hold  Freescale  and its officers, employees, subsidiaries,*/
/* affiliates,  and distributors harmless against all claims costs, damages, */
/* and expenses, and reasonable  attorney  fees arising  out of, directly or */
/* indirectly,  any claim of personal injury  or death  associated with such */
/* unintended or unauthorized use, even if such claim alleges that  Freescale*/
/* was negligent regarding the  design  or manufacture of the part. Freescale*/
/* and the Freescale logo* are registered trademarks of Freescale Ltd.       */
/*****************************************************************************/

#ifndef S12XGATEV1_H      /*prevent duplicated includes */
#define S12XGATEV1_H

#ifndef S12_COMMON_H      /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif


typedef union uXGMCTL
{
  tU08   byte;
  struct
  {
    tU08 xgie     :1;      /* XGATE Interrupt Enable */
    tU08 xgsweif  :1;      /* XGATE Software Error Interrupt Flag */
    tU08          :1;      /* not used */
    tU08 xgss     :1;      /* XGATE Single Step */
    tU08 xgdbg    :1;      /* XGATE Debug mode */
    tU08 xgdbgm   :1;      /* XGATE Debug mode Mask */
    tU08 xgfrz    :1;      /* Stop XGATE in Freeze mode */
    tU08 xge      :1;      /* XGATE Enable */
  }bit;
}tXGMCTL;

#define XGIE     0x01   /*bit masks */
#define XGSWEIF  0x04
#define XGSS     0x08
#define XGHALT   0x10
#define XGHALTM  0x20
#define XGFRZ    0x40
#define XGE      0x80

typedef union uXGSWT
{
  tU16  word;
  struct
  {
    tU08 xgswtm;        /* XGATE Software Trigger Mask Register */
    tU08 xgswtr;        /* XGATE Software Trigger Register */
  }byte;
}tXGSWT;

#define XGSWTM0 0x0100
#define XGSWTM1 0x0200
#define XGSWTM2 0x0400
#define XGSWTM3 0x0800
#define XGSWTM4 0x1000
#define XGSWTM5 0x2000
#define XGSWTM6 0x4000
#define XGSWTM7 0x8000

/* alternative mask bit defines */
#define XGSWT0M 0x0100
#define XGSWT1M 0x0200
#define XGSWT2M 0x0400
#define XGSWT3M 0x0800
#define XGSWT4M 0x1000
#define XGSWT5M 0x2000
#define XGSWT6M 0x4000
#define XGSWT7M 0x8000

#define XGSWT0 0x01
#define XGSWT1 0x02
#define XGSWT2 0x04
#define XGSWT3 0x08
#define XGSWT4 0x10
#define XGSWT5 0x20
#define XGSWT6 0x40
#define XGSWT7 0x80

typedef union uXGSEM
{
  tU16  word;
  struct
  {
    tU08 xgsemm;        /* XGATE Semaphore Mask Register */
    tU08 xgsemr;        /* XGATE Semaphore Register */
  }byte;
}tXGSEM;

#define XGSEMM0 0x0100
#define XGSEMM1 0x0200
#define XGSEMM2 0x0400
#define XGSEMM3 0x0800
#define XGSEMM4 0x1000
#define XGSEMM5 0x2000
#define XGSEMM6 0x4000
#define XGSEMM7 0x8000

/* alternative mask bit defines */
#define XGSEM0M 0x0100
#define XGSEM1M 0x0200
#define XGSEM2M 0x0400
#define XGSEM3M 0x0800
#define XGSEM4M 0x1000
#define XGSEM5M 0x2000
#define XGSEM6M 0x4000
#define XGSEM7M 0x8000

#define XGSEM0 0x01
#define XGSEM1 0x02
#define XGSEM2 0x04
#define XGSEM3 0x08
#define XGSEM4 0x10
#define XGSEM5 0x20
#define XGSEM6 0x40
#define XGSEM7 0x80

typedef union uXGCCR
{
  tU08   byte;
  struct
  {
    tU08 xgc   :1;      /* XGATE Carry Flag */
    tU08 xgv   :1;      /* XGATE Overflow Flag */
    tU08 xgz   :1;      /* XGATE Zero Flag */
    tU08 xgn   :1;      /* XGATE Sign Flag */
    tU08       :4;      /* not used */
  }bit;
}tXGCCR;


typedef struct             /* XGATE module used on the S12XDP256  */
{
  volatile tXGMCTL      xgmctl;        /* XGATE Module Control Register - rev 1   */
           tU08         rsv1;          /* reserved */
  volatile tU08         xgchid;        /* XGATE Channel ID Register     */
           tU08         rsv3;          /* reserved */
  volatile tU16         xgvbr_hi;      /* XGATE Vector Base Address Register - high word */  
  volatile tU16         xgvbr_lo;      /* XGATE Vector Base Address Register - low word */   
  volatile tU16         xgif_70;       /* XGATE Channel Interrupt Flag 70 - 78 */
  volatile tU16         xgif_60;       /* XGATE Channel Interrupt Flag 60 - 6F */
  volatile tU16         xgif_50;       /* XGATE Channel Interrupt Flag 50 - 5F */
  volatile tU16         xgif_40;       /* XGATE Channel Interrupt Flag 40 - 4F */
  volatile tU16         xgif_30;       /* XGATE Channel Interrupt Flag 30 - 3F */
  volatile tU16         xgif_20;       /* XGATE Channel Interrupt Flag 20 - 2F */
  volatile tU16         xgif_10;       /* XGATE Channel Interrupt Flag 10 - 1F */
  volatile tU16         xgif_00;       /* XGATE Channel Interrupt Flag 09 - 0F */
  volatile tXGSWT       xgswt;         /* XGATE Software Trigger Register */
  volatile tXGSEM       xgsem;         /* XGATE Semaphore Register */
           tU08         rsv1c;         /* reserved byte */
  volatile tXGCCR       xgccr;         /* XGATE Condition Code Register */
  volatile tU16         xgpc;          /* XGATE Program Counter */
           tU16         rsv20;         /* reserved word */
  volatile tU16         xgr1;          /* XGATE Register 1 */
  volatile tU16         xgr2;          /* XGATE Register 2 */
  volatile tU16         xgr3;          /* XGATE Register 3 */
  volatile tU16         xgr4;          /* XGATE Register 4 */
  volatile tU16         xgr5;          /* XGATE Register 5 */
  volatile tU16         xgr6;          /* XGATE Register 6 */
  volatile tU16         xgr7;          /* XGATE Register 7 */
}tXGATE;

#endif /* S12XGATEV1_H  */