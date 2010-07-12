/******************************************************************************
*                                             COPYRIGHT (c) FREESCALE 2005   
* FILE NAME: per_XDx512_L15Y.h                                             
*                                                                           
* PURPOSE: external declaration of on-chip peripheral variables for HCS12XDP512.                    
*          Mask Set: L15Y                    
*                                                                           
*******************************************************************************
*******************************************************************************  
**  THIS CODE IS ONLY INTENDED AS AN EXAMPLE FOR THE METROWERKS COMPILER AND **  
**      THE S12X EVB AND HAS ONLY BEEN GIVEN A MIMIMUM LEVEL OF TEST.        **  
**  IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES AND NO PROMISE OF SUPPORT.   **  
*******************************************************************************  
*******************************************************************************
*                                                                           
* DESCRIPTION:  external declarations for control register blocks of on-chip
*               peripherals.
*               Include this file in programs that interact with on-chip        
*               peripherals.                                                            
*                                                                           
* AUTHOR: r32151         LOCATION: EKB                 LAST EDIT DATE: 25/02/05  
*                                                                           
******************************************************************************/
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
                           /*prevent duplicated includes */
#ifndef per_XDx512_L15Y_H       
#define per_XDx512_L15Y_H


#if (__MWERKS__)
  #pragma MESSAGE DISABLE C1106
#endif
          
#include "S12_COMMON.h"
#include "S12ATD10B8CV3.h"
#include "S12ATD10B16CV4.h"
#include "S12CRGV6.h"
#include "S12ECT16B8CV2.h"
#include "S12IICV2.h"
#include "S12SCIV5.h"
#include "S12SPIV4.h"
#include "S12PWM8B8CV1.h"
#include "S12MSCANV3.h"
#include "S12VREG_3V3V5.h"
#include "S12XDP512PIMV2.h"
#include "S12XEETX4KV2.h"
#include "S12XFTX512K4V2.h"
#include "S12XEBIV2.h"
#include "S12XMMCV2.h"
#include "S12XGATEV2.h"
#include "S12XINTV1.h"
#include "S12PIT24B4CV1.h"
#include "S12XDBGV2.h"
#include "xgate_channels_L15Y.h"

extern volatile tPORT    PORTA;     /* Port A Data Register */
extern volatile tPORT    PORTB;     /* Port B Data Register */
extern volatile tPORT    DDRA;      /* Port A Data Direction Register */
extern volatile tPORT    DDRB;      /* Port B Data Direction Register */
extern volatile tPORT    PORTC;     /* Port C Data Register */
extern volatile tPORT    PORTD;     /* Port D Data Register */
extern volatile tPORT    DDRC;      /* Port C Data Direction Register */
extern volatile tPORT    DDRD;      /* Port D Data Direction Register */
extern volatile tPORT    PORTE;     /* Port E Data Register */
extern volatile tPORT    DDRE;      /* Port E Data Direction Register */

extern volatile tMMCCTL0 MMCCTL0;   /* MMC Control Register 0 */
extern volatile tMODE    MODE;      /* Mode Register */
extern volatile tPUCR    PUCR;      /* Pull-up Control Register */
extern volatile tRDRIV   RDRIV;     /* Reduced Drive Register */
extern volatile tEBICTL0 EBICTL0;   /* EBI Control Register 0 */
extern volatile tEBICTL1 EBICTL1;   /* EBI Control Register 1 */
extern volatile tGPAGE   GPAGE;     /* Global Page Index Register */
extern volatile tDIRECT  DIRECT;    /* Direct Page Register */
extern volatile tMMCCTL1 MMCCTL1;   /* MMC Control Register 1 */
extern volatile tRPAGE   RPAGE;     /* RAM Page Index Register */
extern volatile tEPAGE   EPAGE;     /* EEPROM Page Index Register */
extern volatile tREG16   PARTID;    /* Part ID */
extern volatile tECLKCTL ECLKCTL;   /* E-clock Control Register */
extern volatile tIRQCR   IRQCR;     /* IRQ Control Register */
extern volatile tDBG     DBG;       /* DBG module */
extern volatile tPPAGE   PPAGE;     /* Program Page Index Register */

extern volatile tPORT    PORTK;     /* Port K Data Register */
extern volatile tPORT    DDRK;      /* Port K Data Direction Register */

extern volatile tCRG     CRG;       /* Clock and Reset Generator Module */
extern volatile tTIMER   Timer;     /* Enhanced Capture Timer Module */
extern volatile tATD16   ATD1;      /* ATD Module 1 - 8 Channel ATD */
extern volatile tIIC     IIC1;      /* IIC Module 1 */
extern volatile tSCI     SCI2;      /* SCI Module 2 */
extern volatile tSCI     SCI3;      /* SCI Module 3 */
extern volatile tSCI     SCI0;      /* SCI Module 0 */
extern volatile tSCI     SCI1;      /* SCI Module 1 */
extern volatile tSPI     SPI0;      /* SPI Module 0 */
extern volatile tIIC     IIC0;      /* IIC Module 0 */
extern volatile tSPI     SPI1;      /* SPI Module 1 */
extern volatile tSPI     SPI2;      /* SPI Module 2 */
extern volatile tFLASH   Flash;     /* Flash Control Registers */
extern volatile tEEPROM  Eeprom;    /* EEPROM Control Registers */
extern volatile tXSRAM   XSRAM;     /* XGate/Shared RAM Protection Control*/
extern volatile tINT     Interrupt; /* Interrupt Control Registers */
extern volatile tSCI     SCI4;      /* SCI Module 4 */
extern volatile tSCI     SCI5;      /* SCI Module 5 */
extern volatile tMSCAN   CAN0;      /* MSCAN Module 0 */
extern volatile tMSCAN   CAN1;      /* MSCAN Module 1 */
extern volatile tMSCAN   CAN2;      /* MSCAN Module 2 */
extern volatile tMSCAN   CAN3;      /* MSCAN Module 3 */

extern volatile tPORT    PTT;       /* Port T I/O Register */
extern volatile tPORT    PTIT;      /* Port T Input Register */
extern volatile tPORT    DDRT;      /* Port T Data Direction Register */
extern volatile tPORT    RDRT;      /* Port T Reduced Drive Register */
extern volatile tPORT    PERT;      /* Port T Pull Device Enable Register */
extern volatile tPORT    PPST;      /* Port T Polarity Select Register */

extern volatile tPORT    PTS;       /* Port S I/O Register */
extern volatile tPORT    PTIS;      /* Port S Input Register */
extern volatile tPORT    DDRS;      /* Port S Data Direction Register */
extern volatile tPORT    RDRS;      /* Port S Reduced Drive Register */
extern volatile tPORT    PERS;      /* Port S Pull Device Enable Register */
extern volatile tPORT    PPSS;      /* Port S Polarity Select Register */
extern volatile tPORT    WOMS;      /* Port S Wired-Or Mode Register */

extern volatile tPORT    PTM;       /* Port M I/O Register */
extern volatile tPORT    PTIM;      /* Port M Input Register */
extern volatile tPORT    DDRM;      /* Port M Data Direction Register */
extern volatile tPORT    RDRM;      /* Port M Reduced Drive Register */
extern volatile tPORT    PERM;      /* Port M Pull Device Enable Register */
extern volatile tPORT    PPSM;      /* Port M Polarity Select Register */
extern volatile tPORT    WOMM;      /* Port M Wired-Or Mode Register */
extern volatile tPORT    MODRR;     /* Module Routing Register */

extern volatile tPORT    PTP;       /* Port P I/O Register */
extern volatile tPORT    PTIP;      /* Port P Input Register */
extern volatile tPORT    DDRP;      /* Port P Data Direction Register */
extern volatile tPORT    RDRP;      /* Port P Reduced Drive Register */
extern volatile tPORT    PERP;      /* Port P Pull Device Enable Register */
extern volatile tPORT    PPSP;      /* Port P Polarity Select Register */
extern volatile tPORT    PIEP;      /* Port P Interrupt Enable Register */
extern volatile tPORT    PIFP;      /* Port P Interrupt Flag Register */

extern volatile tPORT    PTH;       /* Port H I/O Register */
extern volatile tPORT    PTIH;      /* Port H Input Register */
extern volatile tPORT    DDRH;      /* Port H Data Direction Register */
extern volatile tPORT    RDRH;      /* Port H Reduced Drive Register */
extern volatile tPORT    PERH;      /* Port H Pull Device Enable Register */
extern volatile tPORT    PPSH;      /* Port H Polarity Select Register */
extern volatile tPORT    PIEH;      /* Port H Interrupt Enable Register */
extern volatile tPORT    PIFH;      /* Port H Interrupt Flag Register */

extern volatile tPORT    PTJ;       /* Port J I/O Register */
extern volatile tPORT    PTIJ;      /* Port J Input Register */
extern volatile tPORT    DDRJ;      /* Port J Data Direction Register */
extern volatile tPORT    RDRJ;      /* Port J Reduced Drive Register */
extern volatile tPORT    PERJ;      /* Port J Pull Device Enable Register */
extern volatile tPORT    PPSJ;      /* Port J Polarity Select Register */
extern volatile tPORT    PIEJ;      /* Port J Interrupt Enable Register */
extern volatile tPORT    PIFJ;      /* Port J Interrupt Flag Register */

extern volatile tPORT    PT1AD0;    /* Port AD0 I/O Register 1 */
extern volatile tPORT    DDR1AD0;   /* Port AD0 Data Direction Register 1 */
extern volatile tPORT    RDR1AD0;   /* Port AD0 Reduced Drive Register 1 */
extern volatile tPORT    PER1AD0;   /* Port AD0 Pull-up Enable Register 1 */

extern volatile tPORT    PT0AD1;    /* Port AD1 I/O Register 0 */
extern volatile tPORT    PT1AD1;    /* Port AD1 I/O Register 1 */
extern volatile tPORT    DDR0AD1;   /* Port AD1 Data Direction Register 0 */
extern volatile tPORT    DDR1AD1;   /* Port AD1 Data Direction Register 1 */
extern volatile tPORT    RDR0AD1;   /* Port AD1 Reduced Drive Register 0 */
extern volatile tPORT    RDR1AD1;   /* Port AD1 Reduced Drive Register 1 */
extern volatile tPORT    PER0AD1;   /* Port AD1 Pull-up Enable Register 0 */
extern volatile tPORT    PER1AD1;   /* Port AD1 Pull-up Enable Register 1 */

extern volatile tMSCAN   CAN4;      /* MSCAN Module 4 */
extern volatile tATD8    ATD0;      /* ATD Module 0 - 8 Channel ATD */
extern volatile tVREG    VREG;      /* Voltage Regulator */
extern volatile tPWM     PWM;       /* PWM */
extern volatile tPIT     PIT;       /* PIT */
extern volatile tXGATE   XGATE;     /* XGATE Module */

#endif /* per_XDx512_L15Y_H */
