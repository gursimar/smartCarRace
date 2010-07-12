/*****************************************************************************/
/*                                             COPYRIGHT (c) Freescale 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12IICV2.h,v $                          */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for HCS12(X) IIC module                              */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12 EVB AND HAS ONLY BEEN GIVEN A      *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/* DESCRIPTION:  Defines the IIC register block as a datastructure of        */
/*               type tIIC.                                                  */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR       DATE        DESCRIPTION OF CHANGE                       */
/* ---  ------       --------    ---------------------                       */
/* 1.0  R32151       21/02/05    - updated to Fereescale.                    */
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

#ifndef S12IICV2_H         /*prevent duplicated includes */
#define S12IICV2_H

#ifndef S12_COMMON_H       /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif

typedef union uIBAD
  {
  tU08   byte;
  struct
    {
    tU08       :1;
    tU08 adr   :7;      /*slave address bits */
    }bit;
  }tIBAD;

#define ADR1   0x02  /*bit masks */
#define ADR2   0x04
#define ADR3   0x08
#define ADR4   0x10
#define ADR5   0x20
#define ADR6   0x40
#define ADR7   0x80

typedef union uIBFD
  {
  tU08   byte;
  struct
    {
    tU08 ibc   :8;      /*iic bus clock rate bits */
    }bit;
  }tIBFD;

#define IBC0   0x01  /*bit masks */
#define IBC1   0x02
#define IBC2   0x04
#define IBC3   0x08
#define IBC4   0x10
#define IBC5   0x20
#define IBC6   0x40
#define IBC7   0x80

typedef union uIBCR
  {
  tU08   byte;
  struct
    {
    tU08 ibswai :1;      /*iic stops in wait mode */
    tU08        :1;      /*not used */
    tU08 rsta   :1;      /*repeat start */
    tU08 txak   :1;      /*transmit acknowledge enable */
    tU08 txrx   :1;      /*transmit/receive mode select */
    tU08 mssl   :1;      /*master/slave mode select */
    tU08 ibie   :1;      /*iic bus interrupt enable */
    tU08 iben   :1;      /*iic bus enable */
    }bit;
  }tIBCR;

#define IBSWAI 0x01  /*bit masks */
#define RSTA   0x04
#define TXAK   0x08
#define TXRX   0x10
#define MSSL   0x20
#define IBIE   0x40
#define IBEN   0x80

typedef union uIBSR
  {
  tU08   byte;
  struct
    {
    tU08 rxak  :1;      /*received acknowledge */
    tU08 ibif  :1;      /*iic bus interrupt flag */
    tU08 srw   :1;      /*slave read/write */
    tU08       :1;      /*not used */
    tU08 ibal  :1;      /*arbitration lost */
    tU08 ibb   :1;      /*iic busy bit */
    tU08 iaas  :1;      /*addressed as a slave bit */
    tU08 tcf   :1;      /*data transferring bit */
    }bit;
  }tIBSR;

#define RXAK   0x01  /*bit masks */
#define IBIF   0x02
#define SRW    0x04
#define IBAL   0x10
#define IBB    0x20
#define IAAS   0x40
#define TCF    0x80

typedef struct          
  {
  volatile tIBAD  ibad;   /*iic bus address register */
  volatile tIBFD  ibfd;   /*iic bus frequency divider register */
  volatile tIBCR  ibcr;   /*iic bus control register */
  volatile tIBSR  ibsr;   /*iic bus status register */
  volatile tREG08 ibdr;   /*iic bus data register */
           tU08   rsv[3]; /*reserved to complete module memory map */
  }tIIC;

#endif /*S12IICV2_H */