/******************************************************************************
*                                                  COPYRIGHT (c) FREESCALE 2005   
* FILE NAME: per_XDx512_L15Y.c     REVISION 1.0                                        
*                                                                           
* PURPOSE: Declaration of peripheral variables for an MC9S12XDx512
*          Mask Set: L15Y                    
*                                                                           
*******************************************************************************
*******************************************************************************  
** THIS CODE IS ONLY INTENDED AS AN EXAMPLE FOR THE CODEWARRIOR COMPILER AND **  
**      THE HCS12X EVB AND HAS ONLY BEEN GIVEN A MIMIMUM LEVEL OF TEST.      **  
**  IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES AND NO PROMISE OF SUPPORT.   **  
*******************************************************************************  
*******************************************************************************
*                                                                           
* DESCRIPTION:  declarations of control register blocks for on-chip peripherals.        
*                                                                           
* AUTHOR: r32151         LOCATION: EKB                 LAST EDIT DATE: 25/02/05  
*                                                                           
******************************************************************************/
/******************************************************************************
* Peripheral   Peripheral UG    Version   Doc. Order #      Header File
* ----------   ---------------  -------   ---------------   ---------------
* ATD0         ATD_10B8C        V03       S12ATD10B8CV3/D   S12ATD10B8CV3.H
* ATD1         ATD_10B16C       V04       S12ATD10B16CV4/D  S12ATD10B16CV4.H
* CRG          CRG              V06       S12CRGV6/D        S12CRGV6.H
* DEBUG        S12X_DBG         V02       S12XDBGV2/D       S12XDBGV2.H
* EBI          S12X_EBI         V02       S12XEBIV2/D       S12XEBIV2.H
* EEPROM       EETSX4K          V02       S12XEETX4KV2/D    S12XEETX4KV2.H
* FLASH        FTSX512K4        V02       S12XFTX512K4V2/D  S12XFTX512K4V2.H
* IIC          IIC              V02       S12IICV2/D        S12IICV2.H
* INTERRUPT    S12X_INTERRUPT   V01       S12XINTV1/D       S12XINTV1.H
* MMC          S12X_MMC         V02       S12XMMCV2/D       S12MMCIV2.H
* MSCAN        MSCAN            V03       S12MSCANV3/D      S12MSCANV3.H
* PIM          PIM_9XDP512      V02       S12XDP512PIMV2/D  S12XDP512PIMV2.H
* PIT          PIT_24B4C        V01       S12PIT24B4CV1/D   S12PIT24B4CV1.H
* PWM          PWM_8B8C         V01       S12PWM8B8CV1/D    S12PWM8B8CV1.H
* SCI          SCI              V05       S12SCIV5/D        S12SCIV5.H
* SPI          SPI              V04       S12SPIV4/D        S12SPIV4.H
* TIMER        ECT_16B8C        V02       S12ECT16B8CV2/D   S12ECT16B8CV2.H
* VREG         VREG             V05       S12VREG_3V3V5/D   S12VREG_3V3V5.H
* XGATE        XGATE            V02       S12XGATEV2/D      S12XGATEV2.H	  
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

#include "per_XDx512_L15Y.h"

volatile tPORT    PORTA    @0x0000;    /* Port A Data Register */
volatile tPORT    PORTB    @0x0001;    /* Port B Data Register */
volatile tPORT    DDRA     @0x0002;    /* Port A Data Direction Register */
volatile tPORT    DDRB     @0x0003;    /* Port B Data Direction Register */
volatile tPORT    PORTC    @0x0004;    /* Port C Data Register */
volatile tPORT    PORTD    @0x0005;    /* Port D Data Register */
volatile tPORT    DDRC     @0x0006;    /* Port C Data Direction Register */
volatile tPORT    DDRD     @0x0007;    /* Port D Data Direction Register */
volatile tPORT    PORTE    @0x0008;    /* Port E Data Register */
volatile tPORT    DDRE     @0x0009;    /* Port E Data Direction Register */

volatile tMMCCTL0 MMCCTL0  @0x000A;    /* MMC Control Register 0 - rev 2  */
volatile tMODE    MODE     @0x000B;    /* Mode Register => */
volatile tPUCR    PUCR     @0x000C;    /* Pull-up Control Register */
volatile tRDRIV   RDRIV    @0x000D;    /* Reduced Drive Register */
volatile tEBICTL0 EBICTL0  @0x000E;    /* EBI Control Register 0 */
volatile tEBICTL1 EBICTL1  @0x000F;    /* EBI Control Register 1 */
volatile tGPAGE   GPAGE    @0x0010;    /* Global Page Index Register */
volatile tDIRECT  DIRECT   @0x0011;    /* Direct Page Register */
volatile tMMCCTL1 MMCCTL1  @0x0013;    /* MMC Control Register 1 */
volatile tRPAGE   RPAGE    @0x0016;    /* RAM Page Index Register */
volatile tEPAGE   EPAGE    @0x0017;    /* EEPROM Page Index Register */
volatile tREG16   PARTID   @0x001A;    /* Part ID */
volatile tECLKCTL ECLKCTL  @0x001C;    /* E-clock Control Register */
volatile tIRQCR   IRQCR    @0x001E;    /* IRQ Control Register */
volatile tDBG     DBG      @0x0020;    /* DBG module */
volatile tPPAGE   PPAGE    @0x0030;    /* Program Page Index Register */

volatile tPORT    PORTK    @0x0032;    /* Port K Data Register */
volatile tPORT    DDRK     @0x0033;    /* Port K Data Direction Register */

volatile tCRG     CRG      @0x0034;    /* Clock and Reset Generator Module */
volatile tTIMER   Timer    @0x0040;    /* Enhanced Capture Timer Module */
volatile tATD16   ATD1     @0x0080;    /* ATD Module 0 - 8 Channel ATD */
volatile tIIC     IIC1     @0x00B0;    /* IIC Module 1 */
volatile tSCI     SCI2     @0x00B8;    /* SCI Module 2 */
volatile tSCI     SCI3     @0x00C0;    /* SCI Module 3 */
volatile tSCI     SCI0     @0x00C8;    /* SCI Module 0 */
volatile tSCI     SCI1     @0x00D0;    /* SCI Module 1 */
volatile tSPI     SPI0     @0x00D8;    /* SPI Module 0 */
volatile tIIC     IIC0     @0x00E0;    /* IIC Module 0 */
volatile tSPI     SPI1     @0x00F0;    /* SPI Module 1 */
volatile tSPI     SPI2     @0x00F8;    /* SPI Module 2 */
volatile tFLASH   Flash    @0x0100;    /* Flash Control Registers */
volatile tEEPROM  Eeprom   @0x0110;    /* EEPROM Control Registers */
volatile tXSRAM   XSRAM    @0x011C;    /* XGate/Shared RAM Protection Control*/
volatile tINT     Interrupt  @0x0120;  /* Interrupt Control Registers */
volatile tSCI     SCI4     @0x0130;    /* SCI Module 4 */
volatile tSCI     SCI5     @0x0138;    /* SCI Module 5 */
volatile tMSCAN   CAN0     @0x0140;    /* MSCAN Module 0 */
volatile tMSCAN   CAN1     @0x0180;    /* MSCAN Module 1 */
volatile tMSCAN   CAN2     @0x01C0;    /* MSCAN Module 2 */
volatile tMSCAN   CAN3     @0x0200;    /* MSCAN Module 3 */

volatile tPORT    PTT      @0x0240;    /* PORT T I/O Register */
volatile tPORT    PTIT     @0x0241;    /* PORT T Input Register */
volatile tPORT    DDRT     @0x0242;    /* PORT T Data Direction Register */
volatile tPORT    RDRT     @0x0243;    /* PORT T Reduced Drive Register */
volatile tPORT    PERT     @0x0244;    /* PORT T Pull Device Enable Register */
volatile tPORT    PPST     @0x0245;    /* PORT T Polarity Select Register */

volatile tPORT    PTS      @0x0248;    /* PORT S I/O Register */
volatile tPORT    PTIS     @0x0249;    /* PORT S Input Register */
volatile tPORT    DDRS     @0x024A;    /* PORT S Data Direction Register */
volatile tPORT    RDRS     @0x024B;    /* PORT S Reduced Drive Register */
volatile tPORT    PERS     @0x024C;    /* PORT S Pull Device Enable Register */
volatile tPORT    PPSS     @0x024D;    /* PORT S Polarity Select Register */
volatile tPORT    WOMS     @0x024E;    /* PORT S Wired-Or Mode Register */

volatile tPORT    PTM      @0x0250;    /* PORT M I/O Register */
volatile tPORT    PTIM     @0x0251;    /* PORT M Input Register */
volatile tPORT    DDRM     @0x0252;    /* PORT M Data Direction Register */
volatile tPORT    RDRM     @0x0253;    /* PORT M Reduced Drive Register */
volatile tPORT    PERM     @0x0254;    /* PORT M Pull Device Enable Register */
volatile tPORT    PPSM     @0x0255;    /* PORT M Polarity Select Register */
volatile tPORT    WOMM     @0x0256;    /* PORT M Wired-Or Mode Register */
volatile tPORT    MODRR    @0x0257;    /* Module Routing Register */

volatile tPORT    PTP      @0x0258;    /* PORT P I/O Register */
volatile tPORT    PTIP     @0x0259;    /* PORT P Input Register */
volatile tPORT    DDRP     @0x025A;    /* PORT P Data Direction Register */
volatile tPORT    RDRP     @0x025B;    /* PORT P Reduced Drive Register */
volatile tPORT    PERP     @0x025C;    /* PORT P Pull Device Enable Register */
volatile tPORT    PPSP     @0x025D;    /* PORT P Polarity Select Register */
volatile tPORT    PIEP     @0x025E;    /* PORT P Interrupt Enable Register */
volatile tPORT    PIFP     @0x025F;    /* PORT P Interrupt Flag Register */ 

volatile tPORT    PTH      @0x0260;    /* PORT H I/O Register */
volatile tPORT    PTIH     @0x0261;    /* PORT H Input Register */
volatile tPORT    DDRH     @0x0262;    /* PORT H Data Direction Register */
volatile tPORT    RDRH     @0x0263;    /* PORT H Reduced Drive Register */
volatile tPORT    PERH     @0x0264;    /* PORT H Pull Device Enable Register */
volatile tPORT    PPSH     @0x0265;    /* PORT H Polarity Select Register */
volatile tPORT    PIEH     @0x0266;    /* PORT H Interrupt Enable Register */
volatile tPORT    PIFH     @0x0267;    /* PORT H Interrupt Flag Register */

volatile tPORT    PTJ      @0x0268;    /* PORT J I/O Register */
volatile tPORT    PTIJ     @0x0269;    /* PORT J Input Register */
volatile tPORT    DDRJ     @0x026A;    /* PORT J Data Direction Register */
volatile tPORT    RDRJ     @0x026B;    /* PORT J Reduced Drive Register */
volatile tPORT    PERJ     @0x026C;    /* PORT J Pull Device Enable Register */
volatile tPORT    PPSJ     @0x026D;    /* PORT J Polarity Select Register */
volatile tPORT    PIEJ     @0x026E;    /* PORT J Interrupt Enable Register */
volatile tPORT    PIFJ     @0x026F;    /* PORT J Interrupt Flag Register */

volatile tPORT    PT1AD0   @0x0271;    /* PORT AD0 I/O Register 1 */
volatile tPORT    DDR1AD0  @0x0273;    /* PORT AD0 Data Direction Register 1 */
volatile tPORT    RDR1AD0  @0x0275;    /* PORT AD0 Reduced Drive Register 1 */
volatile tPORT    PER1AD0  @0x0277;    /* PORT AD0 Pull-up Enable Register 1 */ 

volatile tPORT    PT0AD1   @0x0278;    /* PORT AD1 I/O Register 0 */
volatile tPORT    PT1AD1   @0x0279;    /* PORT AD1 I/O Register 1 */
volatile tPORT    DDR0AD1  @0x027A;    /* PORT AD1 Data Direction Register 0 */
volatile tPORT    DDR1AD1  @0x027B;    /* PORT AD1 Data Direction Register 1 */
volatile tPORT    RDR0AD1  @0x027C;    /* PORT AD1 Reduced Drive Register 0 */
volatile tPORT    RDR1AD1  @0x027D;    /* PORT AD1 Reduced Drive Register 1 */
volatile tPORT    PER0AD1  @0x027E;    /* PORT AD1 Pull-up Enable Register 0 */
volatile tPORT    PER1AD1  @0x027F;    /* PORT AD1 Pull-up Enable Register 1 */

volatile tMSCAN   CAN4     @0x0280;    /* MSCAN Module 4 */
volatile tATD8    ATD0     @0x02C0;    /* ATD Module 0 - 8 Channel ATD */
volatile tVREG    VREG     @0x02F0;    /* Voltage Regulator */
volatile tPWM     PWM      @0x0300;    /* PWM */
volatile tPIT     PIT      @0x0340;    /* PIT */
volatile tXGATE   XGATE    @0x0380;    /* XGATE Module */


  
  

