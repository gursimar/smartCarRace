/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/* File Name          :    $RCSfile: S12XFTX512K4V2.h,v $                    */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for HCS12(X) Flash control registers block           */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/* DESCRIPTION:  Defines the Flash control registers block as a datastructure*/
/*               of type tFLASH.                                             */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR       DATE       DESCRIPTION OF CHANGE                        */
/* ---  ------      --------    ---------------------                        */
/* 1.0  r32151      21/02/05    - Initial coding based on S12FTS512K4V1.h    */
/* 1.1  r32151      28/02/05    - Corrected #defines for Flash commands      */
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

#ifndef S12XFTX512K4V2_H         /*prevent duplicated includes */
#define S12XFTX512K4V2_H

#ifndef S12_COMMON_H             /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif

typedef union uFCLKDIV
  {
  tU08   byte;
  struct
    {
    tU08 fdiv   :6;   /*clk divider */
    tU08 prdiv8 :1;   /*clk /8 prescaler enable */
    tU08 fdivld :1;   /*clock divider loaded flag */
    }bit;
  }tFCLKDIV;

#define FDIV   0x3F   /*bit masks */
#define PRDIV8 0x40   
#define FDIV8  PRDIV8
#define FDIVLD 0x80

typedef union uFSEC
  {
  tU08   byte;
  struct
    {
    tU08 sec   :2;      /*memory security bit */
    tU08 rnv   :4;      /*user non volatile flag bits */
    tU08 keyen :2;      /*security key access enable */
    }bit;
  }tFSEC;

#define SEC0    0x01 /*bit masks */
#define SEC1    0x02
#define SECMASK 0x03
#define RNV2    0x04
#define RNV3    0x08
#define RNV4    0x10
#define RNV5    0x20
#define RNVMASK 0x3C
#define KEYEN0  0x40
#define KEYEN1  0x80

#define SECURED   0x00
#define UNSECURED SEC1

typedef union uFTSTMOD
  {
  tU08   byte;
  struct
    {
    tU08       :4;      /*unused */
    tU08 wrall :1;      /*write to all register banks */
    tU08 mrds0 :1;      /*program margin read setting */
    tU08 mrds1 :1;      /*erase margin read setting */
    tU08       :1;      /*unused */
    }bit;
  }tFTSTMOD;

#define WRALL  0x10  /*bit masks */
#define MRDS0  0x20
#define MRDS1  0x40
 

typedef union uFCNFG
  {
  tU08   byte;
  struct
    {
    tU08        :5;     /*not used */
    tU08 keyacc :1;     /*security key writing enable */
    tU08 ccie   :1;     /*command complete interrupt enable */
    tU08 cbeie  :1;     /*command buffer empty interrupt enable   */
    }bit;
  }tFCNFG;

#define KEYACC 0x20  
#define CCIE   0x40  
#define CCBIE  0x80

typedef union uFPROT
  {
  tU08   byte;
  struct
    {
    tU08 fpls     :2;      /*flash protection lower address size */
    tU08 fpldis   :1;      /*flash protection lower address range disable */
    tU08 fphs     :2;      /*flash protection higher address size */
    tU08 fphdis   :1;      /*flash protection higher address range disable */
    tU08 rnv6     :1;      /*NV user bit */
    tU08 fopen    :1;      /*open block for program/erase control */
    }bit;
  }tFPROT;

#define FPLS0     0x01  /*bit masks */
#define FPLS1     0x02
#define FPLSMASK  0x03  /*fpls block size mask */
#define FPLDIS    0x04  
#define FPHS0     0x08  
#define FPHS1     0x10
#define FPHSMASK  0x18  /*fphs block size mask */
#define FPHDIS    0x20  
#define RNV6      0x40
#define FOPEN     0x80

typedef union uFSTAT
  {
  tU08   byte;
  struct
    {
    tU08        :1;     /*not used */
    tU08 fail   :1;     /*fail flag */
    tU08 blank  :1;     /*blank verify flag */
    tU08        :1;     /*not used */
    tU08 accerr :1;     /*access error flag */
    tU08 pviol  :1;     /*protection violation flag */
    tU08 ccif   :1;     /*command complete interrupt flag */
    tU08 cbeif  :1;     /*command buffer empty interrupt flag */
    }bit;
  }tFSTAT;

#define BLANK  0x04  /*bit masks */
#define ACCERR 0x10
#define PVIOL  0x20
#define CCIF   0x40
#define CBEIF  0x80


#define ERVER         0x05  /*flash command bit masks - FCMD register*/
#define PROG          0x20
#define ERASE         0x40
#define DATA_COMPRESS 0x06
#define MASS_ERASE    0x41
#define ERASE_ABORT   0x47
#define PROGRAM_WORD  PROG
#define ERASE_VERIFY  ERVER
#define SECTOR_ERASE  ERASE
#define SECTOR_ERASE_ABORT ERASE_ABORT

typedef struct                /*flash datastructure */
  {
  volatile tFCLKDIV  fclkdiv; /*flash clock divider register */
  volatile tFSEC     fsec;    /*flash security register */
  volatile tFTSTMOD  ftstmod; /*flash test mode register */
  volatile tFCNFG    fcnfg;   /*flash configuration register */
  volatile tFPROT    fprot;   /*flash protection register */
  volatile tFSTAT    fstat;   /*flash status register */
  volatile tREG08    fcmd;    /*flash command buffer & status register */
  volatile tU08      fctl;    /*flash control register */ 
  volatile tU16      faddr;   /*flash address register */
  volatile tU16      fdata;   /*flash data register */
  volatile tU08      rsv2[4]; /*reserved */
  }tFLASH;


#endif /*S12XFTX512K4V2_H */