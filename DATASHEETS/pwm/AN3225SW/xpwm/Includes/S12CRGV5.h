/*****************************************************************************/
/*                                             COPYRIGHT (c) FREESCALE 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12CRGV5.h,v $                          */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for HCS12(X) CRG block                               */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12 EVB AND HAS ONLY BEEN GIVEN A      *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/* DESCRIPTION: Defines the Clocks and Reset Generator (inc pll) block as a  */
/* datastructure of type tCRG.                                               */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR      DATE        DESCRIPTION OF CHANGE                        */
/* ---  ------      --------    ---------------------                        */
/* 1.0 r32151       21/01/05    - Initial coding based on S12CRGV4.h.        */
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

#ifndef S12CRGV5_H         /*prevent duplicated includes */
#define S12CRGV5_H

#ifndef S12_COMMON_H       /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif         

typedef union uSYNR
  {
  tU08   byte;
  struct
    {
    tU08 synr  :6;      /*synthesizer bits, controls multiplication factor of PLL */
    tU08       :2;      /*not used */
    }bit;
  }tSYNR;

#define SYNR0  0x01  /*bit masks */
#define SYNR1  0x02
#define SYNR2  0x04
#define SYNR3  0x08
#define SYNR4  0x10
#define SYNR5  0x20 

typedef union uREFDV
  {
  tU08   byte;
  struct
    {
    tU08 refdv :4;      /*allows finer granularity for pll ref freq  */
    tU08       :4;      /*not used */
    }bit;
  }tREFDV;

#define REFDV0 0x01  /*bit masks */
#define REFDV1 0x02
#define REFDV2 0x04
#define REFDV3 0x08


typedef union uCRGFLG
  {
  tU08   byte;
  struct
    {
    tU08 scm     :1;    /*self clock mode ststus (1: limp-home clock active) */
    tU08 scmif   :1;    /*self clock mode interrupt flag */
    tU08 track   :1;    /*track status*/
    tU08 lock    :1;    /*lock status */
    tU08 lockif  :1;    /*lock interrupt flag */
    tU08 lvrf    :1;    /*low voltage reset flag*/
   tU08 porf     :1;    /*power on reset flag */
   tU08 rtif     :1;    /*real time interrupt flag */
    }bit;
  }tCRGFLG;

#define SCM      0x01   /*bit masks */
#define SCMIF    0x02
#define TRACK    0x04   
#define LOCK     0x08   
#define LOCKIF   0x10   
#define LVRF     0x20   
#define PORF     0x40   
#define RTIF     0x80

typedef union uCRGINT
  {
  tU08   byte;
  struct
    {
    tU08        :1;     /*not used*/
    tU08 scmie  :1;     /*self clock mode interrupt enable */
    tU08        :2;     /*not used*/
    tU08 lockie :1;     /*lock interrupt enable */
    tU08        :2;     /*not used */
    tU08 rtie   :1;     /*real time interrupt enable */
    }bit;
  }tCRGINT;

#define SCMIE   0x02 /*bit masks */
#define LOCKIF  0x10 
#define RTIE    0x80


typedef union uCLKSEL
  {
  tU08   byte;
  struct
    {
    tU08 copwai   :1;      /*COP halts in wait */
    tU08 rtiwai   :1;      /*RTI halts in wait */
    tU08 cwai     :1;      /*Core halts in wait */
    tU08 pllwai   :1;      /*PLL off in wait */
    tU08 roawai   :1;      /*bus clock select pll */
    tU08          :1;      /*not used */
    tU08 pstp     :1;      /*pseudo stop mode enable */
    tU08 pllsel   :1;      /*pll select */
    }bit;
  }tCLKSEL;

#define COPWAI   0x01      /*bit masks */
#define RTIWAI   0x02      
#define CWAI     0x04      
#define PLLWAI   0x08      
#define ROAWAI   0x10      
#define PSTP     0x40      
#define PLLSEL   0x80      

typedef union uPLLCTL
  {
  tU08   byte;
  struct
    {
    tU08 scme    :1;    /*self clock mode enable */
    tU08 pce     :1;    /*pseudo stop COP enable */
    tU08 pre     :1;    /*pseudo stop RTI enable */
    tU08 fstwkp  :1;    /*fast wake up from full-stop enable */
    tU08 acq     :1;    /*not in acquisition */
    tU08 aut     :1;    /*automatic bandwidth control */
    tU08 pllon   :1;    /*phase lock loop on */
    tU08 cme     :1;    /*crystal monitor enable */
    }bit;
  }tPLLCTL;

/****

The bitfield aut was used instead of auto, as auto is a C keyword and may be
problematic to some compilers.

****/

#define SCME   0x01  /*bit masks */
#define PCE    0x02
#define PRE    0x04
#define ACQ    0x10
#define AUT    0x20
#define PLLON  0x40
#define CME    0x80

typedef union uRTICTL
{
   tU08 byte;
   struct
    {
      tU08 rtr0   :1;      /*modulus counter select */
      tU08 rtr1   :1;      
      tU08 rtr2   :1;      
      tU08 rtr3   :1;      
      tU08 rtr4   :1;      /*prescaler rate select */
      tU08 rtr5   :1;      
      tU08 rtr6   :1;      
      tU08        :1;      /*not used */
    }bit;
}tRTICTL;
  
#define RTR0   0x01  /*bit masks */
#define RTR1   0x02
#define RTR2   0x04
#define RTR3   0x08
#define RTR4   0x10
#define RTR5   0x20
#define RTR6   0x40

typedef union uCOPCTL
{          
   tU08 byte;
   struct
    {
      tU08 cr     :3;      /*cop timer rate select */
      tU08        :3;      /*not used */
      tU08 rsbck  :1;      /*cop and rti stop in active bdm */
      tU08 wcop   :1;      /*window cop enable */
    }bit;
}tCOPCTL;

#define CR0    0x01  /*bit masks */
#define CR1    0x02
#define CR2    0x04
#define RSBCK  0x40
#define WCOP   0x80

typedef union uFORBYP      
  {
  tU08   byte;
  struct
    {
    tU08        :1;     /*not used */
    tU08 fcm    :1;
    tU08        :2;     /*not used */
    tU08 pllbyp :1;
    tU08        :1;     /*not used */
    tU08 copbyp :1;
    tU08 rtibyp :1;
    }bit;
  }tFORBYP;

#define FCM    0x02  /*bit masks */
#define PLLBYP 0x10
#define COPBYP 0x40
#define RTIBYP 0x80

typedef struct          
  {
  volatile  tSYNR    synr;    /*synthesizer register */
  volatile  tREFDV   refdv;   /*reference divider register */
  volatile  tREG08   ctflg;   /*clock generator test flags register  */
  volatile  tCRGFLG  crgflg;  /*clock generator flags register */
  volatile  tCRGINT  crgint;  /*clock generator interrupt control register */
  volatile  tCLKSEL  clksel;  /*clock generator clock select register */
  volatile  tPLLCTL  pllctl;  /*pll control register */
  volatile  tREG08   rtictl;  /*rti control register */
  volatile  tCOPCTL  copctl;  /*cop control register */
  volatile  tFORBYP  forbyp;  /*crg force and bypass test register */
  volatile  tREG08   ctctl;   /*crg test control register */
  volatile  tREG08   armcop;  /*cop arming register (to reset write $55:$0AA) */
  }tCRG;

#endif /*S12CRGV5_H */