/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12VREG_3V3V4.h,v $                     */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for S12X VREG register block                         */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/* DESCRIPTION:  Defines the VREG register block as a datastructure of       */
/*               type tVREG.                                                 */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR       DATE       DESCRIPTION OF CHANGE                        */
/* ---  ------      --------    ---------------------                        */
/* 1.0  r54430      19/04/04    - Initial Revision                           */
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

#ifndef S12VREG_3V3V4_H       /*prevent duplicated includes */
#define S12VREG_3V3V4_H

#ifndef S12_COMMON_H          /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif

typedef union uVREGCTRL
{
  tU08   byte;
  struct
  {
    tU08 lvif  :1;
    tU08 lvie  :1;
    tU08 lvds  :1;
  }bit;
} tVREGCTRL;

#define LVIF   0x01  /*bit masks */
#define LVIE   0x02
#define LVDS  0x20

typedef union uVREGAPICL
{
  tU08   byte;
  struct
  {
    tU08 apif   :1;
    tU08 apie   :1;
    tU08 apife  :1;
    tU08 apir0  :1;
    tU08 apir1  :1;
    tU08 apir2  :1;
    tU08 apir3  :1;
    tU08 apiclk :1;
  } bit;
} tVREGAPICL;

#define APIF   0x01  /*bit masks */
#define APIE   0x02
#define APIFE  0x04
#define APIR0  0x08
#define APIR1  0x10
#define APIR2  0x20
#define APIR3  0x40
#define APICLK 0x80


typedef struct {           /* vreg datastructure   */
  volatile tREG08      rsv0;     
  volatile tVREGCTRL   vregctrl;   /* Vreg Control Register */ 
  volatile tVREGAPICL  vregapicl;  /* API Control Register */  
  volatile tREG08      vregapitr;  /* API trim Register */  
  volatile tREG08      rsv4;     
  volatile tREG08      rsv5;     
  volatile tREG08      rsv6;     
  volatile tREG08      rsv7;     
} tVREG;

#endif /*S12VREG_3V3V4_H */