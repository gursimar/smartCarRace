/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12SCIV5.h,v $                          */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for S12X SCI register block                          */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/*                                                                           */
/* DESCRIPTION:  Defines the SCI register block as a datastructure of        */
/*               type tSCI.                                                  */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR     DATE       DESCRIPTION OF CHANGE                          */
/* ---  ------    --------    ---------------------                          */
/* 1.0  r27624    18/11/03    - Adapted from S12SCIV3.h                      */
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

#ifndef S12SCIV5_H         /*prevent duplicated includes */
#define S12SCIV5_H

#ifndef S12_COMMON_H       /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif

typedef union uSCIBDH
{
  tU08   byte;
  struct
  {
    tU08 sbr8   :1;     /*msb baud rate select bits   */
    tU08 sbr9   :1;
    tU08 sbr10  :1;
    tU08 sbr11  :1;
    tU08 sbr12  :1;
    tU08 tnp    :2;     /*transmit narrow pulse */
    tU08 iren   :1;     /*IRDA enable */
  }bit;
  struct                /* alternate bits for SCIASR1 */
  {
    tU08 bkdif  :1;     /* break detect interrupt flag */
    tU08 berrif :1;     /* bit error interrupt flag   */
    tU08 berrv  :1;     /* bit error value */
    tU08        :4;     /* not used */
    tU08 rxedgif:1;     /* receive input active edge interrupt flag */
  }abit;
}tSCIBDH;

#define SBR8   0x01     /* bit masks   */
#define SBR9   0x02
#define SBR10  0x04
#define SBR11  0x08
#define SBR12  0x10
#define TNP0   0x20
#define TNP1   0x40
#define IREN   0x80

#define BKDIF   0x01   /* alternate bit masks */
#define BERRIF  0x02
#define BERRV   0x04
#define RXEDGIF 0x80 

typedef union uSCIBDL
{
  tU08   byte;
  struct
  {
    tU08 sbr0   :1;     /*lsb baud rate select bits   */
    tU08 sbr1   :1;
    tU08 sbr2   :1;
    tU08 sbr3   :1;
    tU08 sbr4   :1;
    tU08 sbr5   :1;     
    tU08 sbr6   :1;
    tU08 sbr7   :1;   
  }bit;
  struct                /* alternate bits for SCIACR1 */
  {
    tU08 bkdie  :1;     /* break detect interrupt enable */
    tU08 berrie :1;     /* bit error interrupt enable */
    tU08        :5;     /* not used */
    tU08 rxedgie:1;     /* receive input active edge interrupt enable */
  }abit;
}tSCIBDL;

#define SBR0   0x01  /*bit masks */
#define SBR1   0x02
#define SBR2   0x04
#define SBR3   0x08
#define SBR4   0x10
#define SBR5   0x20
#define SBR6   0x40
#define SBR7   x80

#define BKDIE   0x01  /* alternate bit masks */
#define BERRIE  0x02
#define RXEDGIE 0x80 

typedef union uSCICR1
{
  tU08   byte;
  struct
  {
    tU08 pt      :1;     /*parity type */
    tU08 pe      :1;     /*parity enable   */
    tU08 ilt     :1;     /*idle line type */
    tU08 wake    :1;     /*wake up by address mark/idle */
    tU08 m       :1;     /*mode select */
    tU08 rsrc    :1;     /*receiver source */
    tU08 sciswai :1;     /*stop in wait mode  */
    tU08 loops   :1;     /*loop mode/single wire mode enable */
  }bit;
  struct               /* alternate bits for SCIACR2 */
  {
    tU08 bkdfe   :1;     /* break detect feature enable */
    tU08 berrm0  :1;     /* bit error mode */
    tU08 berrm1  :1;     /* bit error mode */
    tU08         :5;     /* not used */
  }abit;
}tSCICR1;

#define PT       0x01 /*bit masks */
#define PE       0x02
#define ILT      0x04
#define WAKE     0x08
#define M        0x10
#define RSRC     0x20
#define SCISWAI  0x40
#define LOOPS    0x80

#define BKDFE    0x01  /* alternate bit masks */
#define BERRM0   0x02
#define BERRM1   0x04


typedef union uSCICR2
{
  tU08   byte;
  struct
  {
    tU08 sbk   :1;      /*send break character */
    tU08 rwu   :1;      /*receiver wake-up control */
    tU08 re    :1;      /*receiver enable */
    tU08 te    :1;      /*transmitter enable */
    tU08 ilie  :1;      /*idle line interrupt enable */
    tU08 rie   :1;      /*receiver interrupt enable   */
    tU08 tcie  :1;      /*transmit complete interrupt enable */
    tU08 tie   :1;      /*transmit interrupt enable   */
  }bit;
}tSCICR2;

#define SBK    0x01  /*bit masks */
#define RWU    0x02
#define RE     0x04
#define TE     0x08
#define ILIE   0x10
#define RIE    0x20
#define TCIE   0x40
#define TIE    0x80

typedef union uSCISR1
{
  tU08   byte;
  struct
  {
    tU08 pf    :1;      /*parity error flag  */
    tU08 fe    :1;      /*framing error flag */
    tU08 nf    :1;      /*noise error flag */
    tU08 orf   :1;      /*overrun error flag - 'or' in specification */
    tU08 idle  :1;      /*idle line detected flag */
    tU08 rdrf  :1;      /*receive data register full flag */
    tU08 tc    :1;      /*transmit complete flag */
    tU08 tdre  :1;      /*transmit data register empty flag */
  }bit;
}tSCISR1;

#define PF     0x01  /*bit masks */
#define FE     0x02
#define NF     0x04
#define ORF    0x08  /* 'OR' in specification */
#define IDLE   0x10
#define RDRF   0x20
#define TC     0x40
#define TDRE   0x80

typedef union uSCISR2
{
  tU08   byte;
  struct
  {
     tU08 raf    :1;   /*receiver active flag */
     tU08 txdir  :1;   /*receiver active flag */
     tU08 brk13  :1;   /*13-bit break */
     tU08 rxpol  :1;   /*receiver polarity */
     tU08 txpol  :1;   /*transmitter polarity */
     tU08        :2;   /*not used */
     tU08 amap   :1;   /*alternate register map */
  }bit;
}tSCISR2;

#define RAF    0x01    /*bit masks  */
#define TXDIR  0x02  
#define BRK13  0x04
#define RXPOL  0x08
#define TXPOL  0x10
#define AMAP   0x80

typedef union uSCIDRH
{
  tU08   byte;
  struct
  {
    tU08       :6;      /*not used */
    tU08 t8    :1;      /*transmit bit 8 */
    tU08 r8    :1;      /*receive bit 8   */
  }bit;
}tSCIDRH;

#define T8     0x40  /*bit masks */
#define R8     0x80

typedef struct          /*sci datastructure  */
  {
  volatile tSCIBDH  scibdh;   /*sci baud rate high register / alternate status register */
  volatile tSCIBDL  scibdl;   /*sci baud rate low register  / alternate control register 1 */
  volatile tSCICR1  scicr1;   /*sci control register 1      / alternate control register 2 */
  volatile tSCICR2  scicr2;   /*sci control register 2 */
  volatile tSCISR1  scisr1;   /*sci status register 1 */
  volatile tSCISR2  scisr2;   /*sci status register 2 */
  volatile tSCIDRH  scidrh;   /*sci data register high */
  volatile tREG08   scidrl;   /*sci data register low */
  }tSCI;


#define sciasr1 scibdh        /* alternate register names */
#define sciacr1 scibdl
#define sciacr2 scicr1


#endif /*S12SCIV5_H */