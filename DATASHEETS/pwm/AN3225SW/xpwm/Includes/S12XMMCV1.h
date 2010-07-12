/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12XMMCV1.h,v $                         */
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

#ifndef S12XMMCV1_H        /*prevent duplicated includes */
#define S12XMMCV1_H

#ifndef S12_COMMON_H       /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif


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


typedef union uMISC      
  {
  tU08   byte;
  struct
    {
    tU08 romon  :1;     /* ROM/Flash enable bit */
    tU08 romhm  :1;     /* ROM/Flash higher fixed page only */
    tU08 exstr  :2;     /* external access stretch bits */
    tU08 eromon :1;     /* Emulation ROM on */
    tU08        :3;     /* not used */
    }bit;
  }tMISC;

#define ROMON    0x01
#define ROMHM    0x02
#define EXSTR0   0x04
#define EXSTR1   0x08
#define EROMON   0x10

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



#endif /* XG1 ****************************************************************/

#endif /*S12XMMCV1_H */