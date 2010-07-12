/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12XDP512PIMV2.h,v $                    */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for S12XDP512 PIM block                              */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/* DESCRIPTION: Defines generic structures and types for the port            */
/*              integration module (PIM) and Core IO registers.              */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV   AUTHOR      DATE        DESCRIPTION OF CHANGE                       */
/* ---   ------      --------    ---------------------                       */
/* 1.00  r27624      10/09/03                                                */
/* 1.01  r32151      01/03/05    Updated comments on ECLKCTL                 */
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


#ifndef S12XDP512PIMV2_H         /*prevent duplicated includes */
#define S12XDP512PIMV2_H

#ifndef S12_COMMON_H             /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif

typedef union uPORT     /* generic I/O port */
  {
  tU08  byte;
  struct
    {
    tU08 bit0    :1;     /*i/o port pins */
    tU08 bit1    :1;
    tU08 bit2    :1;
    tU08 bit3    :1;
    tU08 bit4    :1;
    tU08 bit5    :1;
    tU08 bit6    :1;
    tU08 bit7    :1;
    }bit;
  }tPORT;

typedef union uDDR
  {
  tU08  byte;
  struct
    {
    tU08 bit0    :1;     /*data direction bits (0:input;1:output) */
    tU08 bit1    :1;
    tU08 bit2    :1;
    tU08 bit3    :1;
    tU08 bit4    :1;
    tU08 bit5    :1;
    tU08 bit6    :1;
    tU08 bit7    :1;
    }bit;
  }tDDR;

typedef union uPUCR
  {
  tU08  byte;
  struct
    {
    tU08 pupae  :1;     /*pull-up port A enable */
    tU08 pupbe  :1;     /*pull-up port B enable */
    tU08 pupce  :1;     /*pull-up port C enable */
    tU08 pupde  :1;     /*pull-up port D enable */     
    tU08 pupee  :1;     /*pull-up port E enable */
    tU08        :1;
    tU08 bkpue  :1;     /*pull-up BKGD pin enable (special mode only) */     
    tU08 pupke  :1;     /*pull-up port K enable */
    }bit;
  }tPUCR;

#define PUPAE   0x01    /*bit mask */
#define PUPBE   0x02
#define PUPCE   0x04
#define PUPDE   0x08
#define PUPEE   0x10
#define BKPUE   0x40
#define PUPKE   0x80

typedef union uRDRIV
  {
  tU08  byte;
  struct
    {
    tU08 rdpa   :1;     /*reduced drive port A */
    tU08 rdpb   :1;     /*reduced drive port B */
    tU08 rdpc   :1;     /*reduced drive port C */
    tU08 rdpd   :1;     /*reduced drive port D */     
    tU08 rdpe   :1;     /*reduced drive port E */
    tU08        :2;     
    tU08 rdpk   :1;     /*reduced drive port K */
    }bit;
  }tRDRIV;

#define RDPA    0x01    /*bit mask */
#define RDPB    0x02
#define RDPC    0x04
#define RDPD    0x08
#define RDPE    0x10
#define RDPK    0x80


typedef union uIRQCR
  {
  tU08  byte;
  struct
    {
    tU08        :6;     /*not used */
    tU08 irqen  :1;     /*external irq enable */
    tU08 irqe   :1;     /*irq select edge sensitive only */
    }bit;
  }tIRQCR;

#define IRQEN   0x40    /*bit masks */
#define IRQE    0x80

typedef union uECLKCTL
  {
  tU08  byte;
  struct
    {
    tU08 ediv    :2;     /*eclk divider */
    tU08         :4;     /*not used */
    tU08 nclkx2  :1;     /*eclkx2 out enable */
    tU08 neclk   :1;     /*eclk out enable */
    }bit;
  }tECLKCTL;

#define EDIV0    0x01    /*bit mask */
#define EDIV1    0x02
#define NCLKX2   0x40    /*bit masks */
#define NECLK    0x80

#endif /*S12XDP512PIMV2_H */
