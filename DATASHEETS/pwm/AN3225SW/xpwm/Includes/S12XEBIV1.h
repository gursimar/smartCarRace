/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12XEBIV1.h,v $                         */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for S12X External Bus Interface (EBI) block          */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/* DESCRIPTION: Defines the EBI control registers as a data structures of    */
/*              type tEIFCTL and tMODE.                                      */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR     DATE       DESCRIPTION OF CHANGE                          */
/* ---  ------    --------    ---------------------                          */
/* 1.0  r27624    10/09/03   - Initial coding                                */
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

#ifndef S12XEBIV1_H        /*prevent duplicated includes */
#define S12XEBIV1_H

#ifndef S12_COMMON_H       /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif


typedef union uEIFCTL
  {
  tU08  byte;
  struct
    {
    tU08 ewait  :1;     /* external wait enable */
    tU08 nclkx2 :1;     /* no 2xECLK */
    tU08 ediv   :2;     /* external ECLK divider */     
    tU08 neclk  :1;     /* no external ECLK */
    tU08 cs0e   :1;     /* chip select 0 enable */
    tU08 cs1e   :1;     /* chip select 1 enable */     
    tU08 cs2e   :1;     /* chip select 2 enable */
    }bit;
  }tEIFCTL;

#define EWAIT   0x01    /*bit mask */
#define NCLKX2  0x02
#define EDIV0   0x04
#define EDIV1   0x08
#define NECLK   0x10
#define CS0E    0x20
#define CS1E    0x40
#define CS2E    0x80

typedef union uMODE
  {
  tU08  byte;
  struct
    {
    tU08        :3;     /* not used */
    tU08 ivis   :1;     /* internal visibility */     
    tU08 ithrs  :1;     /* reduced threshold select */     
    tU08 moda   :1;     /* mode select A */     
    tU08 modb   :1;     /* mode select B */
    tU08 modc   :1;     /* mode select C */
    }bit;
  }tMODE;

#define IVIS    0x08    /*bit masks */
#define ITHRS   0x10
#define MODA    0x20    
#define MODB    0x40
#define MODC    0x80


#endif /*S12XEBIV1_H */
