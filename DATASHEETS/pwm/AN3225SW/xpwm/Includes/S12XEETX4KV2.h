/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12XEETX4KV2.h,v $                      */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12 EVB AND HAS ONLY BEEN GIVEN A      *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/* DESCRIPTION:  Defines the EEPROM control registers block as a             */
/*               datastructure of type tEEPROM.                              */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR       DATE        DESCRIPTION OF CHANGE                       */
/* ---  ------       --------    ---------------------                       */
/* 1.0   r32151      21/01/05    - Initial codeing based on S12EETS4KV2.     */
/* 1.1   r32151      28/02/05    - Corrected #defines for EEPROM commands    */
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

#ifndef S12XEETX4KV2_H           /*prevent duplicated includes */
#define S12XEETX4KV2_H

#ifndef S12_COMMON_H             /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif

typedef union uECLKDIV
  {
  tU08   byte;
  struct
    {
    tU08 ediv     :6;      /*clk divider */
    tU08 prdiv8   :1;      /*clk /8 prescaler enable */
    tU08 edivld   :1;      /*clock divider loaded flag */
    }bit;
  }tECLKDIV;

#define EDIV0  0x01  /*bit masks */
#define EDIV1  0x02
#define EDIV2  0x04
#define EDIV3  0x08
#define EDIV4  0x10
#define EDIV5  0x20
#define PRDIV8 0x40
#define EDIV8  PRDIV8
#define EDIVLD 0x80

typedef union uECNFG
  {
  tU08   byte;
  struct
    {
    tU08       :6;      /*not used */
    tU08 ccie  :1;      /*command complete interrupt enable */
    tU08 cbeie :1;      /*command buffer empty interrupt enable   */
    }bit;
  }tECNFG;

#define CCIE   0x40  
#define CCBIE  0x80

typedef union uEPROT
  {
  tU08   byte;
  struct
    {
    tU08 ep       :3;      /*protection block size: (ep+1)*64 bytes */
    tU08 epdis    :1;      /*protection disable */
    tU08 rnv4     :1;      /*user non volatile flag bit */
    tU08 rnv5     :1;      /*user non volatile flag bit */
    tU08 rnv6     :1;      /*user non volatile flag bit */
    tU08 eopen    :1;      /*open block for program/erase */
    }bit;
  }tEPROT;

#define EP0    0x01  /*bit masks */
#define EP1    0x02
#define EP2    0x04  
#define EP     0x07  /*ep block mask */
#define EPDIS  0x08
#define EOPEN  0x80

typedef union uESTAT
  {
  tU08   byte;
  struct
    {
    tU08          :2;      /*not used */
    tU08 blank    :1;      /*blank verify flag */
    tU08          :1;      /*not used */
    tU08 accerr   :1;      /*access error flag */
    tU08 pviol    :1;      /*protection violation flag */
    tU08 ccif     :1;      /*command complete interrupt flag */
    tU08 cbeif    :1;      /*command buffer empty interrupt flag */
    }bit;
  }tESTAT;

#define BLANK  0x04  /*bit masks */
#define ACCERR 0x10
#define PVIOL  0x20
#define CCIF   0x40
#define CBEIF  0x80



#define ERVER         0x05 /*eeprom command bit masks - ECMD register*/
#define PROG          0x20
#define ERASE         0x40
#define MASS_ERASE    0x41
#define ERASE_ABORT   0x47
#define SECTOR_MODIFY 0x60
#define PROGRAM_WORD  PROG
#define ERASE_VERIFY  ERVER
#define SECTOR_ERASE  ERASE

#define SECTOR_ERASE_ABORT ERASE_ABORT

typedef struct                /*eeprom datastructure */
  {
  volatile tECLKDIV  eclkdiv;   /*eeprom clock divider register */
           tU08      rsvee1[2]; /*reserved */
  volatile tECNFG    ecnfg;     /*eeprom configuration register */
  volatile tEPROT    eprot;     /*eeprom protection register */
  volatile tESTAT    estat;     /*eeprom status register */
  volatile tREG08    ecmd;      /*eeprom command buffer */ 
           tU08      rsvfee2;   /*reserved */
  volatile tU16      eaddr;     /*eeprom address register */
  volatile tU16      edata;     /*eeprom data register */
  }tEEPROM;

#endif /*S12XEETX4KV2_H */

