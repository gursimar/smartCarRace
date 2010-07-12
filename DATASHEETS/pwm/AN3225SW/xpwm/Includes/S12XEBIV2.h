/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12XEBIV2.h,v $                         */
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
/* DESCRIPTION: Defines the EBI control registers as a data structures of   */
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

#ifndef S12XEBIV2_H        /*prevent duplicated includes */
#define S12XEBIV2_H

#ifndef S12_COMMON_H       /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif

typedef union uEBICTL0
  {
  tU08  byte;
  struct
    {
    tU08 asiz   :5;     /* external address bus size */
    tU08 hdbe   :1;     /* high data byte enable */
    tU08        :1;     /* not used */     
    tU08 ithrs  :1;     /* Reduced Input threshold */
    }bit;
  }tEBICTL0;

#define HDBE    0x20
#define ITHRS   0x80

typedef union uEBICTL1
  {
  tU08  byte;
  struct
    {
    tU08 exstr   :3;     /* chip select 2 enable */
    tU08         :4;     /* not used */     
    tU08 ewaite  :1;     /* external wait enable */
    }bit;
  }tEBICTL1;

#define EXSTR0   0x01
#define EXSTR1   0x02
#define EXSTR2   0x04
#define EWAITE   0x80

#endif /*S12XEBIV2_H */
