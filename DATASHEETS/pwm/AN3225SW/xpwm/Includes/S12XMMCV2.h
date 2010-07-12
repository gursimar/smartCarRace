/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12XMMCV2.h,v $                         */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for S12X Module Mapping Control (MMC) registers      */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/* DESCRIPTION:  Defines structures and types for memory control registers.  */
/*               Defines the registers controlling XGate/Shared RAM data     */
/*               protection as a structure of type tXSRAM remaining          */
/*               compatible with Version 1.                                  */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR     DATE       DESCRIPTION OF CHANGE                          */
/* ---  ------    --------    ---------------------                          */
/* 1.0  r27624    15/9/03     - Initial coding                               */
/*                                                                           */
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

#ifndef S12XMMCV2_H        /*prevent duplicated includes */
#define S12XMMCV2_H

#ifndef S12_COMMON_H       /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif


typedef union uMMCCTL0
  {
  tU08  byte;
  struct
    {
    tU08 cs0e   :1;     /* chip select 0 enable */
    tU08 cs1e   :1;     /* chip select 1 enable */     
    tU08 cs2e   :1;     /* chip select 2 enable */
    tU08 cs3e   :1;     /* chip select 3 enable */
    tU08        :4;     /* not used */
    }bit;
  }tMMCCTL0;

#define CS0E    0x01    /*bit masks */
#define CS1E    0x02
#define CS2E    0x04
#define CS3E    0x08

typedef union uMODE
  {
  tU08  byte;
  struct
    {
    tU08        :5;     /* not used */
    tU08 moda   :1;     /* mode select A */     
    tU08 modb   :1;     /* mode select B */
    tU08 modc   :1;     /* mode select C */
    }bit;
  }tMODE;

#define MODA    0x20    /*bit masks */
#define MODB    0x40
#define MODC    0x80

typedef union uGPAGE
  {
  tU08   byte;
  struct
    {
    tU08 gp :7;         /*active page bits */
    tU08    :1;         /*not used */
    }bit;
  }tGPAGE;

typedef union uDIRECT
  {
  tU08   byte;
  struct
    {
    tU08 dp :8;         /*active page bits */
    }bit;
  }tDIRECT;


typedef union uMMCCTL1      
  {
  tU08   byte;
  struct
    {
    tU08 romon  :1;     /* ROM/Flash enable bit */
    tU08 romhm  :1;     /* ROM/Flash higher fixed page only */
    tU08 eromon :1;     /* Emulation ROM on */
    tU08        :5;     /* not used */
    }bit;
  }tMMCCTL1;

#define ROMON    0x01
#define ROMHM    0x02
#define EROMON   0x04

typedef union uRPAGE
  {
  tU08   byte;
  struct
    {
    tU08 rp    :8;      /*active page bits */
    }bit;
  }tRPAGE;
  
#define RPAGE_FB 0xFB
#define RPAGE_FC 0xFC
#define RPAGE_FD 0xFD

typedef union uEPAGE
  {
  tU08   byte;
  struct
    {
    tU08 ep    :8;      /*active page bits */
    }bit;
  }tEPAGE;

typedef union uPPAGE
  {
  tU08   byte;
  struct
    {
    tU08 pix   :8;      /*active page bits */
    }bit;
  }tPPAGE;

typedef union uRAMWPC
{
  tU08   byte;
  struct
  {
    tU08 avif    :1;  /* RAM CPU Access Violation Flag */
    tU08 avie    :1;  /* RAM CPU Access Violation Interrupt Enable */
    tU08         :5;  /* not used */
    tU08 rwpe    :1;  /* RAM Region Check Enable Bit */
  }bit;
}tRAMWPC;

#define AVIF   0x01  /*bit masks */
#define AVIE   0x02
#define RPWE   0x80


typedef struct          /* XGate/Shared RAM data structure - maintaining XSRAM */
{                       /* name remains compatible with S12X Version 1 */
  volatile tRAMWPC  ramwpc;  /*RAM Protection control register */
  volatile tU08     ramxgu;  /*RAM XGate code upper boundary */
  volatile tU08     ramshl;  /*RAM shared lower boundary */
  volatile tU08     ramshu;  /*RAM shared upper boundary */
}tXSRAM;

#endif /*S12XMMCV2_H */