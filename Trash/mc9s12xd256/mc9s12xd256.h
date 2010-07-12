 Based on CPU DB MC9S12XD256_144, version 2.87.166 (RegistersPrg V2.09) 

 ###################################################################
     Filename   mc9s12xd256.h
     Processor  MC9S12XD256BCFV
     FileFormat V2.09
     DataSheet  MC9S12XDP512 Rev. 2.15 July 2006
     Compiler   CodeWarrior compiler
     DateTime  14.09.2006, 1959
     Abstract  
         This header implements the mapping of IO devices.

     (c) Copyright UNIS, spol. s r.o. 1997-2006
     UNIS, spol. s r.o.
     Jundrovska 33
     624 00 Brno
     Czech Republic
     http       www.processorexpert.com
     mail       info@processorexpert.com

     File-Format-Revisions
      - 14.11.2005, V2.00 
               - Deprecated symbols added for backward compatibility (section at the end of this file)
      - 15.11.2005, V2.01 
               - Fixed invalid instruction in macro __RESET_WATCHDOG for HCS12 family.
      - 17.12.2005, V2.02 
               - Arrays (symbols xx_ARR) are defined as pointer to volatile, see issue #2778
      - 16.01.2006, V2.03 
               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #2920.
               - volatile modifier removed from declaration of non volatile registers (that contain modifier const)
      - 08.03.2006, V2.04 
               - Support for bit(s) names duplicated with any register name in .h header files
      - 24.03.2006, V2.05 
               - Fixed macro __RESET_WATCHDOG for HCS12 family - address and correct write order.
      - 26.04.2006, V2.06 
               - Revision is not related to this file (CPU family)
      - 27.04.2006, V2.07 
               - Fixed macro __RESET_WATCHDOG for HCS12, HCS12X ,HCS08 DZ and HCS08 EN derivatives (write 0x55,0xAA).
      - 07.06.2006, V2.08 
               - Revision is not related to this file (CPU family)
      - 03.07.2006, V2.09 
               - Revision is not related to this file (CPU family)

     CPU Registers Revisions
      - 23.05.2006, V2.87.111
              - Added register ATD1TEST1. REASON Bug in data sheet (Rev. 2.12)
      - 24.05.2006, V2.87.112
              - Removed bits MCCNTlo_BIT0..MCCNTlo_BIT7 and MCCNThi_BIT8.. MCCNThi_BIT15. REASON Bug-fix (#3166 from UNIS issue manager)
      - 09.08.2006, V2.87.159
              - Added SPI2 device. REASON Changes in data sheet (from rev 2.12 to rev 2.15)
 ###################################################################


#ifndef _MC9S12XD256_H
#define _MC9S12XD256_H

 Types definition 
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                 Base address for the IO register block 


#pragma MESSAGE DISABLE C1106  WARNING C1106 Non-standard bitfield type 
#pragma OPTION ADD V30toV31Compatible -BfaGapLimitBits4294967295 this guarantee correct bitfield positions

 interrupt vector table 
#define Vsi                     0x0000FF10
#define Reserved119             0x0000FF12
#define Reserved118             0x0000FF14
#define Reserved117             0x0000FF16
#define Reserved116             0x0000FF18
#define Reserved115             0x0000FF1A
#define Reserved114             0x0000FF1C
#define Reserved113             0x0000FF1E
#define Reserved112             0x0000FF20
#define Reserved111             0x0000FF22
#define Reserved110             0x0000FF24
#define Reserved109             0x0000FF26
#define Reserved108             0x0000FF28
#define Reserved107             0x0000FF2A
#define Reserved106             0x0000FF2C
#define Reserved105             0x0000FF2E
#define Reserved104             0x0000FF30
#define Reserved103             0x0000FF32
#define Reserved102             0x0000FF34
#define Reserved101             0x0000FF36
#define Reserved100             0x0000FF38
#define Reserved99              0x0000FF3A
#define Reserved98              0x0000FF3C
#define Reserved97              0x0000FF3E
#define Reserved96              0x0000FF40
#define Reserved95              0x0000FF42
#define Reserved94              0x0000FF44
#define Reserved93              0x0000FF46
#define Reserved92              0x0000FF48
#define Reserved91              0x0000FF4A
#define Reserved90              0x0000FF4C
#define Reserved89              0x0000FF4E
#define Reserved88              0x0000FF50
#define Reserved87              0x0000FF52
#define Reserved86              0x0000FF54
#define Reserved85              0x0000FF56
#define Reserved84              0x0000FF58
#define Reserved83              0x0000FF5A
#define Reserved82              0x0000FF5C
#define Reserved81              0x0000FF5E
#define Vxsramav                0x0000FF60
#define Vxsei                   0x0000FF62
#define Vxst7                   0x0000FF64
#define Vxst6                   0x0000FF66
#define Vxst5                   0x0000FF68
#define Vxst4                   0x0000FF6A
#define Vxst3                   0x0000FF6C
#define Vxst2                   0x0000FF6E
#define Vxst1                   0x0000FF70
#define Vxst0                   0x0000FF72
#define Vpit3                   0x0000FF74
#define Vpit2                   0x0000FF76
#define Vpit1                   0x0000FF78
#define Vpit0                   0x0000FF7A
#define VReserved65             0x0000FF7C
#define Vapi                    0x0000FF7E
#define Vlvi                    0x0000FF80
#define VReserved62             0x0000FF82
#define VReserved61             0x0000FF84
#define Vsci4                   0x0000FF86
#define VReserved59             0x0000FF88
#define Vsci2                   0x0000FF8A
#define Vpwmesdn                0x0000FF8C
#define Vportp                  0x0000FF8E
#define VReserved55             0x0000FF90
#define VReserved54             0x0000FF92
#define VReserved53             0x0000FF94
#define VReserved52             0x0000FF96
#define VReserved51             0x0000FF98
#define VReserved50             0x0000FF9A
#define VReserved49             0x0000FF9C
#define VReserved48             0x0000FF9E
#define VReserved47             0x0000FFA0
#define VReserved46             0x0000FFA2
#define VReserved45             0x0000FFA4
#define VReserved44             0x0000FFA6
#define VReserved43             0x0000FFA8
#define VReserved42             0x0000FFAA
#define VReserved41             0x0000FFAC
#define VReserved40             0x0000FFAE
#define Vcan0tx                 0x0000FFB0
#define Vcan0rx                 0x0000FFB2
#define Vcan0err                0x0000FFB4
#define Vcan0wkup               0x0000FFB6
#define Vflash                  0x0000FFB8
#define Veeprom                 0x0000FFBA
#define Vspi2                   0x0000FFBC
#define Vspi1                   0x0000FFBE
#define Viic0                   0x0000FFC0
#define VReserved30             0x0000FFC2
#define Vcrgscm                 0x0000FFC4
#define Vcrgplllck              0x0000FFC6
#define Vtimpabovf              0x0000FFC8
#define Vtimmdcu                0x0000FFCA
#define Vporth                  0x0000FFCC
#define Vportj                  0x0000FFCE
#define Vatd1                   0x0000FFD0
#define Vatd0                   0x0000FFD2
#define Vsci1                   0x0000FFD4
#define Vsci0                   0x0000FFD6
#define Vspi0                   0x0000FFD8
#define Vtimpaie                0x0000FFDA
#define Vtimpaaovf              0x0000FFDC
#define Vtimovf                 0x0000FFDE
#define Vtimch7                 0x0000FFE0
#define Vtimch6                 0x0000FFE2
#define Vtimch5                 0x0000FFE4
#define Vtimch4                 0x0000FFE6
#define Vtimch3                 0x0000FFE8
#define Vtimch2                 0x0000FFEA
#define Vtimch1                 0x0000FFEC
#define Vtimch0                 0x0000FFEE
#define Vrti                    0x0000FFF0
#define Virq                    0x0000FFF2
#define Vxirq                   0x0000FFF4
#define Vswi                    0x0000FFF6
#define Vtrap                   0x0000FFF8
#define Vcop                    0x0000FFFA
#define Vclkmon                 0x0000FFFC
#define Vreset                  0x0000FFFE

 registers IO map 

 PORTAB - Port AB; 0x00000000 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PORTA - Port A Register; 0x00000000 
    union {
      byte Byte;
      struct {
        byte PA0         1;                                        Port A Bit 0 
        byte PA1         1;                                        Port A Bit 1 
        byte PA2         1;                                        Port A Bit 2 
        byte PA3         1;                                        Port A Bit 3 
        byte PA4         1;                                        Port A Bit 4 
        byte PA5         1;                                        Port A Bit 5 
        byte PA6         1;                                        Port A Bit 6 
        byte PA7         1;                                        Port A Bit 7 
      } Bits;
    } PORTASTR;
    #define PORTA                       _PORTAB.Overlap_STR.PORTASTR.Byte
    #define PORTA_PA0                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA0
    #define PORTA_PA1                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA1
    #define PORTA_PA2                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA2
    #define PORTA_PA3                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA3
    #define PORTA_PA4                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA4
    #define PORTA_PA5                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA5
    #define PORTA_PA6                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA6
    #define PORTA_PA7                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA7
    
    
    #define PORTA_PA0_MASK              1
    #define PORTA_PA1_MASK              2
    #define PORTA_PA2_MASK              4
    #define PORTA_PA3_MASK              8
    #define PORTA_PA4_MASK              16
    #define PORTA_PA5_MASK              32
    #define PORTA_PA6_MASK              64
    #define PORTA_PA7_MASK              128


     PORTB - Port B Register; 0x00000001 
    union {
      byte Byte;
      struct {
        byte PB0         1;                                        Port B Bit 0 
        byte PB1         1;                                        Port B Bit 1 
        byte PB2         1;                                        Port B Bit 2 
        byte PB3         1;                                        Port B Bit 3 
        byte PB4         1;                                        Port B Bit 4 
        byte PB5         1;                                        Port B Bit 5 
        byte PB6         1;                                        Port B Bit 6 
        byte PB7         1;                                        Port B Bit 7 
      } Bits;
    } PORTBSTR;
    #define PORTB                       _PORTAB.Overlap_STR.PORTBSTR.Byte
    #define PORTB_PB0                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB0
    #define PORTB_PB1                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB1
    #define PORTB_PB2                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB2
    #define PORTB_PB3                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB3
    #define PORTB_PB4                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB4
    #define PORTB_PB5                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB5
    #define PORTB_PB6                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB6
    #define PORTB_PB7                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB7
    
    
    #define PORTB_PB0_MASK              1
    #define PORTB_PB1_MASK              2
    #define PORTB_PB2_MASK              4
    #define PORTB_PB3_MASK              8
    #define PORTB_PB4_MASK              16
    #define PORTB_PB5_MASK              32
    #define PORTB_PB6_MASK              64
    #define PORTB_PB7_MASK              128

  } Overlap_STR;

  struct {
    word PB0         1;                                        Port B Bit 0 
    word PB1         1;                                        Port B Bit 1 
    word PB2         1;                                        Port B Bit 2 
    word PB3         1;                                        Port B Bit 3 
    word PB4         1;                                        Port B Bit 4 
    word PB5         1;                                        Port B Bit 5 
    word PB6         1;                                        Port B Bit 6 
    word PB7         1;                                        Port B Bit 7 
    word PA0         1;                                        Port A Bit 0 
    word PA1         1;                                        Port A Bit 1 
    word PA2         1;                                        Port A Bit 2 
    word PA3         1;                                        Port A Bit 3 
    word PA4         1;                                        Port A Bit 4 
    word PA5         1;                                        Port A Bit 5 
    word PA6         1;                                        Port A Bit 6 
    word PA7         1;                                        Port A Bit 7 
  } Bits;
  struct {
    word grpPB   8;
    word grpPA   8;
  } MergedBits;
} PORTABSTR;
extern volatile PORTABSTR _PORTAB @(REG_BASE + 0x00000000);
#define PORTAB                          _PORTAB.Word
#define PORTAB_PB0                      _PORTAB.Bits.PB0
#define PORTAB_PB1                      _PORTAB.Bits.PB1
#define PORTAB_PB2                      _PORTAB.Bits.PB2
#define PORTAB_PB3                      _PORTAB.Bits.PB3
#define PORTAB_PB4                      _PORTAB.Bits.PB4
#define PORTAB_PB5                      _PORTAB.Bits.PB5
#define PORTAB_PB6                      _PORTAB.Bits.PB6
#define PORTAB_PB7                      _PORTAB.Bits.PB7
#define PORTAB_PA0                      _PORTAB.Bits.PA0
#define PORTAB_PA1                      _PORTAB.Bits.PA1
#define PORTAB_PA2                      _PORTAB.Bits.PA2
#define PORTAB_PA3                      _PORTAB.Bits.PA3
#define PORTAB_PA4                      _PORTAB.Bits.PA4
#define PORTAB_PA5                      _PORTAB.Bits.PA5
#define PORTAB_PA6                      _PORTAB.Bits.PA6
#define PORTAB_PA7                      _PORTAB.Bits.PA7
#define PORTAB_PB                       _PORTAB.MergedBits.grpPB
#define PORTAB_PA                       _PORTAB.MergedBits.grpPA

#define PORTAB_PB0_MASK                 1
#define PORTAB_PB1_MASK                 2
#define PORTAB_PB2_MASK                 4
#define PORTAB_PB3_MASK                 8
#define PORTAB_PB4_MASK                 16
#define PORTAB_PB5_MASK                 32
#define PORTAB_PB6_MASK                 64
#define PORTAB_PB7_MASK                 128
#define PORTAB_PA0_MASK                 256
#define PORTAB_PA1_MASK                 512
#define PORTAB_PA2_MASK                 1024
#define PORTAB_PA3_MASK                 2048
#define PORTAB_PA4_MASK                 4096
#define PORTAB_PA5_MASK                 8192
#define PORTAB_PA6_MASK                 16384
#define PORTAB_PA7_MASK                 32768
#define PORTAB_PB_MASK                  255
#define PORTAB_PB_BITNUM                0
#define PORTAB_PA_MASK                  65280
#define PORTAB_PA_BITNUM                8


 DDRAB - Port AB Data Direction; 0x00000002 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     DDRA - Port A Data Direction Register; 0x00000002 
    union {
      byte Byte;
      struct {
        byte DDRA0       1;                                        Data Direction Port A Bit 0 
        byte DDRA1       1;                                        Data Direction Port A Bit 1 
        byte DDRA2       1;                                        Data Direction Port A Bit 2 
        byte DDRA3       1;                                        Data Direction Port A Bit 3 
        byte DDRA4       1;                                        Data Direction Port A Bit 4 
        byte DDRA5       1;                                        Data Direction Port A Bit 5 
        byte DDRA6       1;                                        Data Direction Port A Bit 6 
        byte DDRA7       1;                                        Data Direction Port A Bit 7 
      } Bits;
    } DDRASTR;
    #define DDRA                        _DDRAB.Overlap_STR.DDRASTR.Byte
    #define DDRA_DDRA0                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA0
    #define DDRA_DDRA1                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA1
    #define DDRA_DDRA2                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA2
    #define DDRA_DDRA3                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA3
    #define DDRA_DDRA4                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA4
    #define DDRA_DDRA5                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA5
    #define DDRA_DDRA6                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA6
    #define DDRA_DDRA7                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA7
    
    
    #define DDRA_DDRA0_MASK             1
    #define DDRA_DDRA1_MASK             2
    #define DDRA_DDRA2_MASK             4
    #define DDRA_DDRA3_MASK             8
    #define DDRA_DDRA4_MASK             16
    #define DDRA_DDRA5_MASK             32
    #define DDRA_DDRA6_MASK             64
    #define DDRA_DDRA7_MASK             128


     DDRB - Port B Data Direction Register; 0x00000003 
    union {
      byte Byte;
      struct {
        byte DDRB0       1;                                        Data Direction Port B Bit 0 
        byte DDRB1       1;                                        Data Direction Port B Bit 1 
        byte DDRB2       1;                                        Data Direction Port B Bit 2 
        byte DDRB3       1;                                        Data Direction Port B Bit 3 
        byte DDRB4       1;                                        Data Direction Port B Bit 4 
        byte DDRB5       1;                                        Data Direction Port B Bit 5 
        byte DDRB6       1;                                        Data Direction Port B Bit 6 
        byte DDRB7       1;                                        Data Direction Port B Bit 7 
      } Bits;
    } DDRBSTR;
    #define DDRB                        _DDRAB.Overlap_STR.DDRBSTR.Byte
    #define DDRB_DDRB0                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB0
    #define DDRB_DDRB1                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB1
    #define DDRB_DDRB2                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB2
    #define DDRB_DDRB3                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB3
    #define DDRB_DDRB4                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB4
    #define DDRB_DDRB5                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB5
    #define DDRB_DDRB6                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB6
    #define DDRB_DDRB7                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB7
    
    
    #define DDRB_DDRB0_MASK             1
    #define DDRB_DDRB1_MASK             2
    #define DDRB_DDRB2_MASK             4
    #define DDRB_DDRB3_MASK             8
    #define DDRB_DDRB4_MASK             16
    #define DDRB_DDRB5_MASK             32
    #define DDRB_DDRB6_MASK             64
    #define DDRB_DDRB7_MASK             128

  } Overlap_STR;

  struct {
    word DDRB0       1;                                        Data Direction Port B Bit 0 
    word DDRB1       1;                                        Data Direction Port B Bit 1 
    word DDRB2       1;                                        Data Direction Port B Bit 2 
    word DDRB3       1;                                        Data Direction Port B Bit 3 
    word DDRB4       1;                                        Data Direction Port B Bit 4 
    word DDRB5       1;                                        Data Direction Port B Bit 5 
    word DDRB6       1;                                        Data Direction Port B Bit 6 
    word DDRB7       1;                                        Data Direction Port B Bit 7 
    word DDRA0       1;                                        Data Direction Port A Bit 0 
    word DDRA1       1;                                        Data Direction Port A Bit 1 
    word DDRA2       1;                                        Data Direction Port A Bit 2 
    word DDRA3       1;                                        Data Direction Port A Bit 3 
    word DDRA4       1;                                        Data Direction Port A Bit 4 
    word DDRA5       1;                                        Data Direction Port A Bit 5 
    word DDRA6       1;                                        Data Direction Port A Bit 6 
    word DDRA7       1;                                        Data Direction Port A Bit 7 
  } Bits;
  struct {
    word grpDDRB 8;
    word grpDDRA 8;
  } MergedBits;
} DDRABSTR;
extern volatile DDRABSTR _DDRAB @(REG_BASE + 0x00000002);
#define DDRAB                           _DDRAB.Word
#define DDRAB_DDRB0                     _DDRAB.Bits.DDRB0
#define DDRAB_DDRB1                     _DDRAB.Bits.DDRB1
#define DDRAB_DDRB2                     _DDRAB.Bits.DDRB2
#define DDRAB_DDRB3                     _DDRAB.Bits.DDRB3
#define DDRAB_DDRB4                     _DDRAB.Bits.DDRB4
#define DDRAB_DDRB5                     _DDRAB.Bits.DDRB5
#define DDRAB_DDRB6                     _DDRAB.Bits.DDRB6
#define DDRAB_DDRB7                     _DDRAB.Bits.DDRB7
#define DDRAB_DDRA0                     _DDRAB.Bits.DDRA0
#define DDRAB_DDRA1                     _DDRAB.Bits.DDRA1
#define DDRAB_DDRA2                     _DDRAB.Bits.DDRA2
#define DDRAB_DDRA3                     _DDRAB.Bits.DDRA3
#define DDRAB_DDRA4                     _DDRAB.Bits.DDRA4
#define DDRAB_DDRA5                     _DDRAB.Bits.DDRA5
#define DDRAB_DDRA6                     _DDRAB.Bits.DDRA6
#define DDRAB_DDRA7                     _DDRAB.Bits.DDRA7
#define DDRAB_DDRB                      _DDRAB.MergedBits.grpDDRB
#define DDRAB_DDRA                      _DDRAB.MergedBits.grpDDRA

#define DDRAB_DDRB0_MASK                1
#define DDRAB_DDRB1_MASK                2
#define DDRAB_DDRB2_MASK                4
#define DDRAB_DDRB3_MASK                8
#define DDRAB_DDRB4_MASK                16
#define DDRAB_DDRB5_MASK                32
#define DDRAB_DDRB6_MASK                64
#define DDRAB_DDRB7_MASK                128
#define DDRAB_DDRA0_MASK                256
#define DDRAB_DDRA1_MASK                512
#define DDRAB_DDRA2_MASK                1024
#define DDRAB_DDRA3_MASK                2048
#define DDRAB_DDRA4_MASK                4096
#define DDRAB_DDRA5_MASK                8192
#define DDRAB_DDRA6_MASK                16384
#define DDRAB_DDRA7_MASK                32768
#define DDRAB_DDRB_MASK                 255
#define DDRAB_DDRB_BITNUM               0
#define DDRAB_DDRA_MASK                 65280
#define DDRAB_DDRA_BITNUM               8


 PORTCD - Port CD; 0x00000004 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PORTC - Port C Register; 0x00000004 
    union {
      byte Byte;
      struct {
        byte PC0         1;                                        Port C Bit 0 
        byte PC1         1;                                        Port C Bit 1 
        byte PC2         1;                                        Port C Bit 2 
        byte PC3         1;                                        Port C Bit 3 
        byte PC4         1;                                        Port C Bit 4 
        byte PC5         1;                                        Port C Bit 5 
        byte PC6         1;                                        Port C Bit 6 
        byte PC7         1;                                        Port C Bit 7 
      } Bits;
    } PORTCSTR;
    #define PORTC                       _PORTCD.Overlap_STR.PORTCSTR.Byte
    #define PORTC_PC0                   _PORTCD.Overlap_STR.PORTCSTR.Bits.PC0
    #define PORTC_PC1                   _PORTCD.Overlap_STR.PORTCSTR.Bits.PC1
    #define PORTC_PC2                   _PORTCD.Overlap_STR.PORTCSTR.Bits.PC2
    #define PORTC_PC3                   _PORTCD.Overlap_STR.PORTCSTR.Bits.PC3
    #define PORTC_PC4                   _PORTCD.Overlap_STR.PORTCSTR.Bits.PC4
    #define PORTC_PC5                   _PORTCD.Overlap_STR.PORTCSTR.Bits.PC5
    #define PORTC_PC6                   _PORTCD.Overlap_STR.PORTCSTR.Bits.PC6
    #define PORTC_PC7                   _PORTCD.Overlap_STR.PORTCSTR.Bits.PC7
    
    
    #define PORTC_PC0_MASK              1
    #define PORTC_PC1_MASK              2
    #define PORTC_PC2_MASK              4
    #define PORTC_PC3_MASK              8
    #define PORTC_PC4_MASK              16
    #define PORTC_PC5_MASK              32
    #define PORTC_PC6_MASK              64
    #define PORTC_PC7_MASK              128


     PORTD - Port D Register; 0x00000005 
    union {
      byte Byte;
      struct {
        byte PD0         1;                                        Port D Bit 0 
        byte PD1         1;                                        Port D Bit 1 
        byte PD2         1;                                        Port D Bit 2 
        byte PD3         1;                                        Port D Bit 3 
        byte PD4         1;                                        Port D Bit 4 
        byte PD5         1;                                        Port D Bit 5 
        byte PD6         1;                                        Port D Bit 6 
        byte PD7         1;                                        Port D Bit 7 
      } Bits;
    } PORTDSTR;
    #define PORTD                       _PORTCD.Overlap_STR.PORTDSTR.Byte
    #define PORTD_PD0                   _PORTCD.Overlap_STR.PORTDSTR.Bits.PD0
    #define PORTD_PD1                   _PORTCD.Overlap_STR.PORTDSTR.Bits.PD1
    #define PORTD_PD2                   _PORTCD.Overlap_STR.PORTDSTR.Bits.PD2
    #define PORTD_PD3                   _PORTCD.Overlap_STR.PORTDSTR.Bits.PD3
    #define PORTD_PD4                   _PORTCD.Overlap_STR.PORTDSTR.Bits.PD4
    #define PORTD_PD5                   _PORTCD.Overlap_STR.PORTDSTR.Bits.PD5
    #define PORTD_PD6                   _PORTCD.Overlap_STR.PORTDSTR.Bits.PD6
    #define PORTD_PD7                   _PORTCD.Overlap_STR.PORTDSTR.Bits.PD7
    
    
    #define PORTD_PD0_MASK              1
    #define PORTD_PD1_MASK              2
    #define PORTD_PD2_MASK              4
    #define PORTD_PD3_MASK              8
    #define PORTD_PD4_MASK              16
    #define PORTD_PD5_MASK              32
    #define PORTD_PD6_MASK              64
    #define PORTD_PD7_MASK              128

  } Overlap_STR;

  struct {
    word PD0         1;                                        Port D Bit 0 
    word PD1         1;                                        Port D Bit 1 
    word PD2         1;                                        Port D Bit 2 
    word PD3         1;                                        Port D Bit 3 
    word PD4         1;                                        Port D Bit 4 
    word PD5         1;                                        Port D Bit 5 
    word PD6         1;                                        Port D Bit 6 
    word PD7         1;                                        Port D Bit 7 
    word PC0         1;                                        Port C Bit 0 
    word PC1         1;                                        Port C Bit 1 
    word PC2         1;                                        Port C Bit 2 
    word PC3         1;                                        Port C Bit 3 
    word PC4         1;                                        Port C Bit 4 
    word PC5         1;                                        Port C Bit 5 
    word PC6         1;                                        Port C Bit 6 
    word PC7         1;                                        Port C Bit 7 
  } Bits;
  struct {
    word grpPD   8;
    word grpPC   8;
  } MergedBits;
} PORTCDSTR;
extern volatile PORTCDSTR _PORTCD @(REG_BASE + 0x00000004);
#define PORTCD                          _PORTCD.Word
#define PORTCD_PD0                      _PORTCD.Bits.PD0
#define PORTCD_PD1                      _PORTCD.Bits.PD1
#define PORTCD_PD2                      _PORTCD.Bits.PD2
#define PORTCD_PD3                      _PORTCD.Bits.PD3
#define PORTCD_PD4                      _PORTCD.Bits.PD4
#define PORTCD_PD5                      _PORTCD.Bits.PD5
#define PORTCD_PD6                      _PORTCD.Bits.PD6
#define PORTCD_PD7                      _PORTCD.Bits.PD7
#define PORTCD_PC0                      _PORTCD.Bits.PC0
#define PORTCD_PC1                      _PORTCD.Bits.PC1
#define PORTCD_PC2                      _PORTCD.Bits.PC2
#define PORTCD_PC3                      _PORTCD.Bits.PC3
#define PORTCD_PC4                      _PORTCD.Bits.PC4
#define PORTCD_PC5                      _PORTCD.Bits.PC5
#define PORTCD_PC6                      _PORTCD.Bits.PC6
#define PORTCD_PC7                      _PORTCD.Bits.PC7
#define PORTCD_PD                       _PORTCD.MergedBits.grpPD
#define PORTCD_PC                       _PORTCD.MergedBits.grpPC

#define PORTCD_PD0_MASK                 1
#define PORTCD_PD1_MASK                 2
#define PORTCD_PD2_MASK                 4
#define PORTCD_PD3_MASK                 8
#define PORTCD_PD4_MASK                 16
#define PORTCD_PD5_MASK                 32
#define PORTCD_PD6_MASK                 64
#define PORTCD_PD7_MASK                 128
#define PORTCD_PC0_MASK                 256
#define PORTCD_PC1_MASK                 512
#define PORTCD_PC2_MASK                 1024
#define PORTCD_PC3_MASK                 2048
#define PORTCD_PC4_MASK                 4096
#define PORTCD_PC5_MASK                 8192
#define PORTCD_PC6_MASK                 16384
#define PORTCD_PC7_MASK                 32768
#define PORTCD_PD_MASK                  255
#define PORTCD_PD_BITNUM                0
#define PORTCD_PC_MASK                  65280
#define PORTCD_PC_BITNUM                8


 DDRCD - Port CD Data Direction; 0x00000006 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     DDRC - Port C Data Direction Register; 0x00000006 
    union {
      byte Byte;
      struct {
        byte DDRC0       1;                                        Data Direction Port C Bit 0 
        byte DDRC1       1;                                        Data Direction Port C Bit 1 
        byte DDRC2       1;                                        Data Direction Port C Bit 2 
        byte DDRC3       1;                                        Data Direction Port C Bit 3 
        byte DDRC4       1;                                        Data Direction Port C Bit 4 
        byte DDRC5       1;                                        Data Direction Port C Bit 5 
        byte DDRC6       1;                                        Data Direction Port C Bit 6 
        byte DDRC7       1;                                        Data Direction Port C Bit 7 
      } Bits;
    } DDRCSTR;
    #define DDRC                        _DDRCD.Overlap_STR.DDRCSTR.Byte
    #define DDRC_DDRC0                  _DDRCD.Overlap_STR.DDRCSTR.Bits.DDRC0
    #define DDRC_DDRC1                  _DDRCD.Overlap_STR.DDRCSTR.Bits.DDRC1
    #define DDRC_DDRC2                  _DDRCD.Overlap_STR.DDRCSTR.Bits.DDRC2
    #define DDRC_DDRC3                  _DDRCD.Overlap_STR.DDRCSTR.Bits.DDRC3
    #define DDRC_DDRC4                  _DDRCD.Overlap_STR.DDRCSTR.Bits.DDRC4
    #define DDRC_DDRC5                  _DDRCD.Overlap_STR.DDRCSTR.Bits.DDRC5
    #define DDRC_DDRC6                  _DDRCD.Overlap_STR.DDRCSTR.Bits.DDRC6
    #define DDRC_DDRC7                  _DDRCD.Overlap_STR.DDRCSTR.Bits.DDRC7
    
    
    #define DDRC_DDRC0_MASK             1
    #define DDRC_DDRC1_MASK             2
    #define DDRC_DDRC2_MASK             4
    #define DDRC_DDRC3_MASK             8
    #define DDRC_DDRC4_MASK             16
    #define DDRC_DDRC5_MASK             32
    #define DDRC_DDRC6_MASK             64
    #define DDRC_DDRC7_MASK             128


     DDRD - Port D Data Direction Register; 0x00000007 
    union {
      byte Byte;
      struct {
        byte DDRD0       1;                                        Data Direction Port D Bit 0 
        byte DDRD1       1;                                        Data Direction Port D Bit 1 
        byte DDRD2       1;                                        Data Direction Port D Bit 2 
        byte DDRD3       1;                                        Data Direction Port D Bit 3 
        byte DDRD4       1;                                        Data Direction Port D Bit 4 
        byte DDRD5       1;                                        Data Direction Port D Bit 5 
        byte DDRD6       1;                                        Data Direction Port D Bit 6 
        byte DDRD7       1;                                        Data Direction Port D Bit 7 
      } Bits;
    } DDRDSTR;
    #define DDRD                        _DDRCD.Overlap_STR.DDRDSTR.Byte
    #define DDRD_DDRD0                  _DDRCD.Overlap_STR.DDRDSTR.Bits.DDRD0
    #define DDRD_DDRD1                  _DDRCD.Overlap_STR.DDRDSTR.Bits.DDRD1
    #define DDRD_DDRD2                  _DDRCD.Overlap_STR.DDRDSTR.Bits.DDRD2
    #define DDRD_DDRD3                  _DDRCD.Overlap_STR.DDRDSTR.Bits.DDRD3
    #define DDRD_DDRD4                  _DDRCD.Overlap_STR.DDRDSTR.Bits.DDRD4
    #define DDRD_DDRD5                  _DDRCD.Overlap_STR.DDRDSTR.Bits.DDRD5
    #define DDRD_DDRD6                  _DDRCD.Overlap_STR.DDRDSTR.Bits.DDRD6
    #define DDRD_DDRD7                  _DDRCD.Overlap_STR.DDRDSTR.Bits.DDRD7
    
    
    #define DDRD_DDRD0_MASK             1
    #define DDRD_DDRD1_MASK             2
    #define DDRD_DDRD2_MASK             4
    #define DDRD_DDRD3_MASK             8
    #define DDRD_DDRD4_MASK             16
    #define DDRD_DDRD5_MASK             32
    #define DDRD_DDRD6_MASK             64
    #define DDRD_DDRD7_MASK             128

  } Overlap_STR;

  struct {
    word DDRD0       1;                                        Data Direction Port D Bit 0 
    word DDRD1       1;                                        Data Direction Port D Bit 1 
    word DDRD2       1;                                        Data Direction Port D Bit 2 
    word DDRD3       1;                                        Data Direction Port D Bit 3 
    word DDRD4       1;                                        Data Direction Port D Bit 4 
    word DDRD5       1;                                        Data Direction Port D Bit 5 
    word DDRD6       1;                                        Data Direction Port D Bit 6 
    word DDRD7       1;                                        Data Direction Port D Bit 7 
    word DDRC0       1;                                        Data Direction Port C Bit 0 
    word DDRC1       1;                                        Data Direction Port C Bit 1 
    word DDRC2       1;                                        Data Direction Port C Bit 2 
    word DDRC3       1;                                        Data Direction Port C Bit 3 
    word DDRC4       1;                                        Data Direction Port C Bit 4 
    word DDRC5       1;                                        Data Direction Port C Bit 5 
    word DDRC6       1;                                        Data Direction Port C Bit 6 
    word DDRC7       1;                                        Data Direction Port C Bit 7 
  } Bits;
  struct {
    word grpDDRD 8;
    word grpDDRC 8;
  } MergedBits;
} DDRCDSTR;
extern volatile DDRCDSTR _DDRCD @(REG_BASE + 0x00000006);
#define DDRCD                           _DDRCD.Word
#define DDRCD_DDRD0                     _DDRCD.Bits.DDRD0
#define DDRCD_DDRD1                     _DDRCD.Bits.DDRD1
#define DDRCD_DDRD2                     _DDRCD.Bits.DDRD2
#define DDRCD_DDRD3                     _DDRCD.Bits.DDRD3
#define DDRCD_DDRD4                     _DDRCD.Bits.DDRD4
#define DDRCD_DDRD5                     _DDRCD.Bits.DDRD5
#define DDRCD_DDRD6                     _DDRCD.Bits.DDRD6
#define DDRCD_DDRD7                     _DDRCD.Bits.DDRD7
#define DDRCD_DDRC0                     _DDRCD.Bits.DDRC0
#define DDRCD_DDRC1                     _DDRCD.Bits.DDRC1
#define DDRCD_DDRC2                     _DDRCD.Bits.DDRC2
#define DDRCD_DDRC3                     _DDRCD.Bits.DDRC3
#define DDRCD_DDRC4                     _DDRCD.Bits.DDRC4
#define DDRCD_DDRC5                     _DDRCD.Bits.DDRC5
#define DDRCD_DDRC6                     _DDRCD.Bits.DDRC6
#define DDRCD_DDRC7                     _DDRCD.Bits.DDRC7
#define DDRCD_DDRD                      _DDRCD.MergedBits.grpDDRD
#define DDRCD_DDRC                      _DDRCD.MergedBits.grpDDRC

#define DDRCD_DDRD0_MASK                1
#define DDRCD_DDRD1_MASK                2
#define DDRCD_DDRD2_MASK                4
#define DDRCD_DDRD3_MASK                8
#define DDRCD_DDRD4_MASK                16
#define DDRCD_DDRD5_MASK                32
#define DDRCD_DDRD6_MASK                64
#define DDRCD_DDRD7_MASK                128
#define DDRCD_DDRC0_MASK                256
#define DDRCD_DDRC1_MASK                512
#define DDRCD_DDRC2_MASK                1024
#define DDRCD_DDRC3_MASK                2048
#define DDRCD_DDRC4_MASK                4096
#define DDRCD_DDRC5_MASK                8192
#define DDRCD_DDRC6_MASK                16384
#define DDRCD_DDRC7_MASK                32768
#define DDRCD_DDRD_MASK                 255
#define DDRCD_DDRD_BITNUM               0
#define DDRCD_DDRC_MASK                 65280
#define DDRCD_DDRC_BITNUM               8


 PORTE - Port E Register; 0x00000008 
typedef union {
  byte Byte;
  struct {
    byte PE0         1;                                        Port E Bit 0 
    byte PE1         1;                                        Port E Bit 1 
    byte PE2         1;                                        Port E Bit 2 
    byte PE3         1;                                        Port E Bit 3 
    byte PE4         1;                                        Port E Bit 4 
    byte PE5         1;                                        Port E Bit 5 
    byte PE6         1;                                        Port E Bit 6 
    byte PE7         1;                                        Port E Bit 7 
  } Bits;
} PORTESTR;
extern volatile PORTESTR _PORTE @(REG_BASE + 0x00000008);
#define PORTE                           _PORTE.Byte
#define PORTE_PE0                       _PORTE.Bits.PE0
#define PORTE_PE1                       _PORTE.Bits.PE1
#define PORTE_PE2                       _PORTE.Bits.PE2
#define PORTE_PE3                       _PORTE.Bits.PE3
#define PORTE_PE4                       _PORTE.Bits.PE4
#define PORTE_PE5                       _PORTE.Bits.PE5
#define PORTE_PE6                       _PORTE.Bits.PE6
#define PORTE_PE7                       _PORTE.Bits.PE7

#define PORTE_PE0_MASK                  1
#define PORTE_PE1_MASK                  2
#define PORTE_PE2_MASK                  4
#define PORTE_PE3_MASK                  8
#define PORTE_PE4_MASK                  16
#define PORTE_PE5_MASK                  32
#define PORTE_PE6_MASK                  64
#define PORTE_PE7_MASK                  128


 DDRE - Port E Data Direction Register; 0x00000009 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte DDRE2       1;                                        Data Direction Port E Bit 2 
    byte DDRE3       1;                                        Data Direction Port E Bit 3 
    byte DDRE4       1;                                        Data Direction Port E Bit 4 
    byte DDRE5       1;                                        Data Direction Port E Bit 5 
    byte DDRE6       1;                                        Data Direction Port E Bit 6 
    byte DDRE7       1;                                        Data Direction Port E Bit 7 
  } Bits;
  struct {
    byte         1;
    byte         1;
    byte grpDDRE_2 6;
  } MergedBits;
} DDRESTR;
extern volatile DDRESTR _DDRE @(REG_BASE + 0x00000009);
#define DDRE                            _DDRE.Byte
#define DDRE_DDRE2                      _DDRE.Bits.DDRE2
#define DDRE_DDRE3                      _DDRE.Bits.DDRE3
#define DDRE_DDRE4                      _DDRE.Bits.DDRE4
#define DDRE_DDRE5                      _DDRE.Bits.DDRE5
#define DDRE_DDRE6                      _DDRE.Bits.DDRE6
#define DDRE_DDRE7                      _DDRE.Bits.DDRE7
#define DDRE_DDRE_2                     _DDRE.MergedBits.grpDDRE_2

#define DDRE_DDRE2_MASK                 4
#define DDRE_DDRE3_MASK                 8
#define DDRE_DDRE4_MASK                 16
#define DDRE_DDRE5_MASK                 32
#define DDRE_DDRE6_MASK                 64
#define DDRE_DDRE7_MASK                 128
#define DDRE_DDRE_2_MASK                252
#define DDRE_DDRE_2_BITNUM              2


 MMCCTL0 - S12X_MMC Control Register 0; 0x0000000A 
typedef union {
  byte Byte;
  struct {
    byte CS0E        1;                                        Chip Select Enable 0 
    byte CS1E        1;                                        Chip Select Enable 1 
    byte CS2E        1;                                        Chip Select Enable 2 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} MMCCTL0STR;
extern volatile MMCCTL0STR _MMCCTL0 @(REG_BASE + 0x0000000A);
#define MMCCTL0                         _MMCCTL0.Byte
#define MMCCTL0_CS0E                    _MMCCTL0.Bits.CS0E
#define MMCCTL0_CS1E                    _MMCCTL0.Bits.CS1E
#define MMCCTL0_CS2E                    _MMCCTL0.Bits.CS2E

#define MMCCTL0_CS0E_MASK               1
#define MMCCTL0_CS1E_MASK               2
#define MMCCTL0_CS2E_MASK               4


 MODE - Mode Register; 0x0000000B 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte MODA        1;                                        Mode Select Bit A 
    byte MODB        1;                                        Mode Select Bit B 
    byte MODC        1;                                        Mode Select Bit C 
  } Bits;
  struct {
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte grpMODx 3;
  } MergedBits;
} MODESTR;
extern volatile MODESTR _MODE @(REG_BASE + 0x0000000B);
#define MODE                            _MODE.Byte
#define MODE_MODA                       _MODE.Bits.MODA
#define MODE_MODB                       _MODE.Bits.MODB
#define MODE_MODC                       _MODE.Bits.MODC
#define MODE_MODx                       _MODE.MergedBits.grpMODx

#define MODE_MODA_MASK                  32
#define MODE_MODB_MASK                  64
#define MODE_MODC_MASK                  128
#define MODE_MODx_MASK                  224
#define MODE_MODx_BITNUM                5


 PUCR - Pull-Up Control Register; 0x0000000C 
typedef union {
  byte Byte;
  struct {
    byte PUPAE       1;                                        Pull-Up Port A Enable 
    byte PUPBE       1;                                        Pull-Up Port B Enable 
    byte PUPCE       1;                                        Pull-Up Port C Enable 
    byte PUPDE       1;                                        Pull-Up Port D Enable 
    byte PUPEE       1;                                        Pull-Up Port E Enable 
    byte             1; 
    byte BKPUE       1;                                        BKGD and VREGEN Pin Pull-up Enable 
    byte PUPKE       1;                                        Pull-Up Port K Enable 
  } Bits;
} PUCRSTR;
extern volatile PUCRSTR _PUCR @(REG_BASE + 0x0000000C);
#define PUCR                            _PUCR.Byte
#define PUCR_PUPAE                      _PUCR.Bits.PUPAE
#define PUCR_PUPBE                      _PUCR.Bits.PUPBE
#define PUCR_PUPCE                      _PUCR.Bits.PUPCE
#define PUCR_PUPDE                      _PUCR.Bits.PUPDE
#define PUCR_PUPEE                      _PUCR.Bits.PUPEE
#define PUCR_BKPUE                      _PUCR.Bits.BKPUE
#define PUCR_PUPKE                      _PUCR.Bits.PUPKE

#define PUCR_PUPAE_MASK                 1
#define PUCR_PUPBE_MASK                 2
#define PUCR_PUPCE_MASK                 4
#define PUCR_PUPDE_MASK                 8
#define PUCR_PUPEE_MASK                 16
#define PUCR_BKPUE_MASK                 64
#define PUCR_PUPKE_MASK                 128


 RDRIV - Reduced Drive of IO Lines; 0x0000000D 
typedef union {
  byte Byte;
  struct {
    byte RDPA        1;                                        Reduced Drive of Port A 
    byte RDPB        1;                                        Reduced Drive of Port B 
    byte RDPC        1;                                        Reduced Drive of Port C 
    byte RDPD        1;                                        Reduced Drive of Port D 
    byte RDPE        1;                                        Reduced Drive of Port E 
    byte             1; 
    byte             1; 
    byte RDPK        1;                                        Reduced Drive of Port K 
  } Bits;
  struct {
    byte grpRDPx 5;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} RDRIVSTR;
extern volatile RDRIVSTR _RDRIV @(REG_BASE + 0x0000000D);
#define RDRIV                           _RDRIV.Byte
#define RDRIV_RDPA                      _RDRIV.Bits.RDPA
#define RDRIV_RDPB                      _RDRIV.Bits.RDPB
#define RDRIV_RDPC                      _RDRIV.Bits.RDPC
#define RDRIV_RDPD                      _RDRIV.Bits.RDPD
#define RDRIV_RDPE                      _RDRIV.Bits.RDPE
#define RDRIV_RDPK                      _RDRIV.Bits.RDPK
#define RDRIV_RDPx                      _RDRIV.MergedBits.grpRDPx

#define RDRIV_RDPA_MASK                 1
#define RDRIV_RDPB_MASK                 2
#define RDRIV_RDPC_MASK                 4
#define RDRIV_RDPD_MASK                 8
#define RDRIV_RDPE_MASK                 16
#define RDRIV_RDPK_MASK                 128
#define RDRIV_RDPx_MASK                 31
#define RDRIV_RDPx_BITNUM               0


 EBICTL0 - External Bus Interface Control Register 0; 0x0000000E 
typedef union {
  byte Byte;
  struct {
    byte ASIZ0       1;                                        External Address Bus Size Bit 0 
    byte ASIZ1       1;                                        External Address Bus Size Bit 1 
    byte ASIZ2       1;                                        External Address Bus Size Bit 2 
    byte ASIZ3       1;                                        External Address Bus Size Bit 3 
    byte ASIZ4       1;                                        External Address Bus Size Bit 4 
    byte HDBE        1;                                        High Data Byte Enable 
    byte             1; 
    byte ITHRS       1;                                        Reduced Input Threshold 
  } Bits;
  struct {
    byte grpASIZ 5;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} EBICTL0STR;
extern volatile EBICTL0STR _EBICTL0 @(REG_BASE + 0x0000000E);
#define EBICTL0                         _EBICTL0.Byte
#define EBICTL0_ASIZ0                   _EBICTL0.Bits.ASIZ0
#define EBICTL0_ASIZ1                   _EBICTL0.Bits.ASIZ1
#define EBICTL0_ASIZ2                   _EBICTL0.Bits.ASIZ2
#define EBICTL0_ASIZ3                   _EBICTL0.Bits.ASIZ3
#define EBICTL0_ASIZ4                   _EBICTL0.Bits.ASIZ4
#define EBICTL0_HDBE                    _EBICTL0.Bits.HDBE
#define EBICTL0_ITHRS                   _EBICTL0.Bits.ITHRS
 EBICTL_ARR Access 2 EBICTLx registers in an array 
#define EBICTL_ARR                      ((volatile byte ) &EBICTL0)
#define EBICTL0_ASIZ                    _EBICTL0.MergedBits.grpASIZ

#define EBICTL0_ASIZ0_MASK              1
#define EBICTL0_ASIZ1_MASK              2
#define EBICTL0_ASIZ2_MASK              4
#define EBICTL0_ASIZ3_MASK              8
#define EBICTL0_ASIZ4_MASK              16
#define EBICTL0_HDBE_MASK               32
#define EBICTL0_ITHRS_MASK              128
#define EBICTL0_ASIZ_MASK               31
#define EBICTL0_ASIZ_BITNUM             0


 EBICTL1 - External Bus Interface Control Register 1; 0x0000000F 
typedef union {
  byte Byte;
  struct {
    byte EXSTR0      1;                                        External Access Stretch Bit 0 
    byte EXSTR1      1;                                        External Access Stretch Bit 1 
    byte EXSTR2      1;                                        External Access Stretch Bit 2 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte EWAITE      1;                                        External Wait Enable 
  } Bits;
  struct {
    byte grpEXSTR 3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} EBICTL1STR;
extern volatile EBICTL1STR _EBICTL1 @(REG_BASE + 0x0000000F);
#define EBICTL1                         _EBICTL1.Byte
#define EBICTL1_EXSTR0                  _EBICTL1.Bits.EXSTR0
#define EBICTL1_EXSTR1                  _EBICTL1.Bits.EXSTR1
#define EBICTL1_EXSTR2                  _EBICTL1.Bits.EXSTR2
#define EBICTL1_EWAITE                  _EBICTL1.Bits.EWAITE
#define EBICTL1_EXSTR                   _EBICTL1.MergedBits.grpEXSTR

#define EBICTL1_EXSTR0_MASK             1
#define EBICTL1_EXSTR1_MASK             2
#define EBICTL1_EXSTR2_MASK             4
#define EBICTL1_EWAITE_MASK             128
#define EBICTL1_EXSTR_MASK              7
#define EBICTL1_EXSTR_BITNUM            0


 GPAGE - Global Page Index Register; 0x00000010 
typedef union {
  byte Byte;
  struct {
    byte GP0         1;                                        Global Page Index Bit 0 
    byte GP1         1;                                        Global Page Index Bit 1 
    byte GP2         1;                                        Global Page Index Bit 2 
    byte GP3         1;                                        Global Page Index Bit 3 
    byte GP4         1;                                        Global Page Index Bit 4 
    byte GP5         1;                                        Global Page Index Bit 5 
    byte GP6         1;                                        Global Page Index Bit 6 
    byte             1; 
  } Bits;
  struct {
    byte grpGP   7;
    byte         1;
  } MergedBits;
} GPAGESTR;
extern volatile GPAGESTR _GPAGE @(REG_BASE + 0x00000010);
#define GPAGE                           _GPAGE.Byte
#define GPAGE_GP0                       _GPAGE.Bits.GP0
#define GPAGE_GP1                       _GPAGE.Bits.GP1
#define GPAGE_GP2                       _GPAGE.Bits.GP2
#define GPAGE_GP3                       _GPAGE.Bits.GP3
#define GPAGE_GP4                       _GPAGE.Bits.GP4
#define GPAGE_GP5                       _GPAGE.Bits.GP5
#define GPAGE_GP6                       _GPAGE.Bits.GP6
#define GPAGE_GP                        _GPAGE.MergedBits.grpGP

#define GPAGE_GP0_MASK                  1
#define GPAGE_GP1_MASK                  2
#define GPAGE_GP2_MASK                  4
#define GPAGE_GP3_MASK                  8
#define GPAGE_GP4_MASK                  16
#define GPAGE_GP5_MASK                  32
#define GPAGE_GP6_MASK                  64
#define GPAGE_GP_MASK                   127
#define GPAGE_GP_BITNUM                 0


 DIRECT - Direct Page Register; 0x00000011 
typedef union {
  byte Byte;
  struct {
    byte DP8         1;                                        Direct Page Bit 8 
    byte DP9         1;                                        Direct Page Bit 9 
    byte DP10        1;                                        Direct Page Bit 10 
    byte DP11        1;                                        Direct Page Bit 11 
    byte DP12        1;                                        Direct Page Bit 12 
    byte DP13        1;                                        Direct Page Bit 13 
    byte DP14        1;                                        Direct Page Bit 14 
    byte DP15        1;                                        Direct Page Bit 15 
  } Bits;
} DIRECTSTR;
extern volatile DIRECTSTR _DIRECT @(REG_BASE + 0x00000011);
#define DIRECT                          _DIRECT.Byte
#define DIRECT_DP8                      _DIRECT.Bits.DP8
#define DIRECT_DP9                      _DIRECT.Bits.DP9
#define DIRECT_DP10                     _DIRECT.Bits.DP10
#define DIRECT_DP11                     _DIRECT.Bits.DP11
#define DIRECT_DP12                     _DIRECT.Bits.DP12
#define DIRECT_DP13                     _DIRECT.Bits.DP13
#define DIRECT_DP14                     _DIRECT.Bits.DP14
#define DIRECT_DP15                     _DIRECT.Bits.DP15

#define DIRECT_DP8_MASK                 1
#define DIRECT_DP9_MASK                 2
#define DIRECT_DP10_MASK                4
#define DIRECT_DP11_MASK                8
#define DIRECT_DP12_MASK                16
#define DIRECT_DP13_MASK                32
#define DIRECT_DP14_MASK                64
#define DIRECT_DP15_MASK                128


 MMCCTL1 - S12X_MMC Control Register 1; 0x00000013 
typedef union {
  byte Byte;
  struct {
    byte ROMON       1;                                        Enable FLASH or ROM in the memory map 
    byte ROMHM       1;                                        FLASH or ROM only in higher Half of Memory Map 
    byte EROMON      1;                                        Enables emulated FLASH or ROM memory in the memory map. 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} MMCCTL1STR;
extern volatile MMCCTL1STR _MMCCTL1 @(REG_BASE + 0x00000013);
#define MMCCTL1                         _MMCCTL1.Byte
#define MMCCTL1_ROMON                   _MMCCTL1.Bits.ROMON
#define MMCCTL1_ROMHM                   _MMCCTL1.Bits.ROMHM
#define MMCCTL1_EROMON                  _MMCCTL1.Bits.EROMON

#define MMCCTL1_ROMON_MASK              1
#define MMCCTL1_ROMHM_MASK              2
#define MMCCTL1_EROMON_MASK             4


 RPAGE - RAM Page Index Register; 0x00000016 
typedef union {
  byte Byte;
  struct {
    byte RP0         1;                                        RAM Page Index Bit 0 
    byte RP1         1;                                        RAM Page Index Bit 1 
    byte RP2         1;                                        RAM Page Index Bit 2 
    byte RP3         1;                                        RAM Page Index Bit 3 
    byte RP4         1;                                        RAM Page Index Bit 4 
    byte RP5         1;                                        RAM Page Index Bit 5 
    byte RP6         1;                                        RAM Page Index Bit 6 
    byte RP7         1;                                        RAM Page Index Bit 7 
  } Bits;
} RPAGESTR;
extern volatile RPAGESTR _RPAGE @(REG_BASE + 0x00000016);
#define RPAGE                           _RPAGE.Byte
#define RPAGE_RP0                       _RPAGE.Bits.RP0
#define RPAGE_RP1                       _RPAGE.Bits.RP1
#define RPAGE_RP2                       _RPAGE.Bits.RP2
#define RPAGE_RP3                       _RPAGE.Bits.RP3
#define RPAGE_RP4                       _RPAGE.Bits.RP4
#define RPAGE_RP5                       _RPAGE.Bits.RP5
#define RPAGE_RP6                       _RPAGE.Bits.RP6
#define RPAGE_RP7                       _RPAGE.Bits.RP7

#define RPAGE_RP0_MASK                  1
#define RPAGE_RP1_MASK                  2
#define RPAGE_RP2_MASK                  4
#define RPAGE_RP3_MASK                  8
#define RPAGE_RP4_MASK                  16
#define RPAGE_RP5_MASK                  32
#define RPAGE_RP6_MASK                  64
#define RPAGE_RP7_MASK                  128


 EPAGE - EEPROM Page Index Register; 0x00000017 
typedef union {
  byte Byte;
  struct {
    byte EP0         1;                                        EEPROM Page Index Bit 0 
    byte EP1         1;                                        EEPROM Page Index Bit 1 
    byte EP2         1;                                        EEPROM Page Index Bit 2 
    byte EP3         1;                                        EEPROM Page Index Bit 3 
    byte EP4         1;                                        EEPROM Page Index Bit 4 
    byte EP5         1;                                        EEPROM Page Index Bit 5 
    byte EP6         1;                                        EEPROM Page Index Bit 6 
    byte EP7         1;                                        EEPROM Page Index Bit 7 
  } Bits;
} EPAGESTR;
extern volatile EPAGESTR _EPAGE @(REG_BASE + 0x00000017);
#define EPAGE                           _EPAGE.Byte
#define EPAGE_EP0                       _EPAGE.Bits.EP0
#define EPAGE_EP1                       _EPAGE.Bits.EP1
#define EPAGE_EP2                       _EPAGE.Bits.EP2
#define EPAGE_EP3                       _EPAGE.Bits.EP3
#define EPAGE_EP4                       _EPAGE.Bits.EP4
#define EPAGE_EP5                       _EPAGE.Bits.EP5
#define EPAGE_EP6                       _EPAGE.Bits.EP6
#define EPAGE_EP7                       _EPAGE.Bits.EP7

#define EPAGE_EP0_MASK                  1
#define EPAGE_EP1_MASK                  2
#define EPAGE_EP2_MASK                  4
#define EPAGE_EP3_MASK                  8
#define EPAGE_EP4_MASK                  16
#define EPAGE_EP5_MASK                  32
#define EPAGE_EP6_MASK                  64
#define EPAGE_EP7_MASK                  128


 PARTID - Part ID Register; 0x0000001A 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PARTIDH - Part ID Register High; 0x0000001A 
    union {
      byte Byte;
      struct {
        byte ID8         1;                                        Part ID Register Bit 8 
        byte ID9         1;                                        Part ID Register Bit 9 
        byte ID10        1;                                        Part ID Register Bit 10 
        byte ID11        1;                                        Part ID Register Bit 11 
        byte ID12        1;                                        Part ID Register Bit 12 
        byte ID13        1;                                        Part ID Register Bit 13 
        byte ID14        1;                                        Part ID Register Bit 14 
        byte ID15        1;                                        Part ID Register Bit 15 
      } Bits;
    } PARTIDHSTR;
    #define PARTIDH                     _PARTID.Overlap_STR.PARTIDHSTR.Byte
    #define PARTIDH_ID8                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID8
    #define PARTIDH_ID9                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID9
    #define PARTIDH_ID10                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID10
    #define PARTIDH_ID11                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID11
    #define PARTIDH_ID12                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID12
    #define PARTIDH_ID13                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID13
    #define PARTIDH_ID14                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID14
    #define PARTIDH_ID15                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID15
    
    
    #define PARTIDH_ID8_MASK            1
    #define PARTIDH_ID9_MASK            2
    #define PARTIDH_ID10_MASK           4
    #define PARTIDH_ID11_MASK           8
    #define PARTIDH_ID12_MASK           16
    #define PARTIDH_ID13_MASK           32
    #define PARTIDH_ID14_MASK           64
    #define PARTIDH_ID15_MASK           128


     PARTIDL - Part ID Register Low; 0x0000001B 
    union {
      byte Byte;
      struct {
        byte ID0         1;                                        Part ID Register Bit 0 
        byte ID1         1;                                        Part ID Register Bit 1 
        byte ID2         1;                                        Part ID Register Bit 2 
        byte ID3         1;                                        Part ID Register Bit 3 
        byte ID4         1;                                        Part ID Register Bit 4 
        byte ID5         1;                                        Part ID Register Bit 5 
        byte ID6         1;                                        Part ID Register Bit 6 
        byte ID7         1;                                        Part ID Register Bit 7 
      } Bits;
    } PARTIDLSTR;
    #define PARTIDL                     _PARTID.Overlap_STR.PARTIDLSTR.Byte
    #define PARTIDL_ID0                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID0
    #define PARTIDL_ID1                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID1
    #define PARTIDL_ID2                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID2
    #define PARTIDL_ID3                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID3
    #define PARTIDL_ID4                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID4
    #define PARTIDL_ID5                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID5
    #define PARTIDL_ID6                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID6
    #define PARTIDL_ID7                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID7
    
    
    #define PARTIDL_ID0_MASK            1
    #define PARTIDL_ID1_MASK            2
    #define PARTIDL_ID2_MASK            4
    #define PARTIDL_ID3_MASK            8
    #define PARTIDL_ID4_MASK            16
    #define PARTIDL_ID5_MASK            32
    #define PARTIDL_ID6_MASK            64
    #define PARTIDL_ID7_MASK            128

  } Overlap_STR;

  struct {
    word ID0         1;                                        Part ID Register Bit 0 
    word ID1         1;                                        Part ID Register Bit 1 
    word ID2         1;                                        Part ID Register Bit 2 
    word ID3         1;                                        Part ID Register Bit 3 
    word ID4         1;                                        Part ID Register Bit 4 
    word ID5         1;                                        Part ID Register Bit 5 
    word ID6         1;                                        Part ID Register Bit 6 
    word ID7         1;                                        Part ID Register Bit 7 
    word ID8         1;                                        Part ID Register Bit 8 
    word ID9         1;                                        Part ID Register Bit 9 
    word ID10        1;                                        Part ID Register Bit 10 
    word ID11        1;                                        Part ID Register Bit 11 
    word ID12        1;                                        Part ID Register Bit 12 
    word ID13        1;                                        Part ID Register Bit 13 
    word ID14        1;                                        Part ID Register Bit 14 
    word ID15        1;                                        Part ID Register Bit 15 
  } Bits;
} PARTIDSTR;
extern volatile PARTIDSTR _PARTID @(REG_BASE + 0x0000001A);
#define PARTID                          _PARTID.Word
#define PARTID_ID0                      _PARTID.Bits.ID0
#define PARTID_ID1                      _PARTID.Bits.ID1
#define PARTID_ID2                      _PARTID.Bits.ID2
#define PARTID_ID3                      _PARTID.Bits.ID3
#define PARTID_ID4                      _PARTID.Bits.ID4
#define PARTID_ID5                      _PARTID.Bits.ID5
#define PARTID_ID6                      _PARTID.Bits.ID6
#define PARTID_ID7                      _PARTID.Bits.ID7
#define PARTID_ID8                      _PARTID.Bits.ID8
#define PARTID_ID9                      _PARTID.Bits.ID9
#define PARTID_ID10                     _PARTID.Bits.ID10
#define PARTID_ID11                     _PARTID.Bits.ID11
#define PARTID_ID12                     _PARTID.Bits.ID12
#define PARTID_ID13                     _PARTID.Bits.ID13
#define PARTID_ID14                     _PARTID.Bits.ID14
#define PARTID_ID15                     _PARTID.Bits.ID15

#define PARTID_ID0_MASK                 1
#define PARTID_ID1_MASK                 2
#define PARTID_ID2_MASK                 4
#define PARTID_ID3_MASK                 8
#define PARTID_ID4_MASK                 16
#define PARTID_ID5_MASK                 32
#define PARTID_ID6_MASK                 64
#define PARTID_ID7_MASK                 128
#define PARTID_ID8_MASK                 256
#define PARTID_ID9_MASK                 512
#define PARTID_ID10_MASK                1024
#define PARTID_ID11_MASK                2048
#define PARTID_ID12_MASK                4096
#define PARTID_ID13_MASK                8192
#define PARTID_ID14_MASK                16384
#define PARTID_ID15_MASK                32768


 ECLKCTL - ECLK Control Register; 0x0000001C 
typedef union {
  byte Byte;
  struct {
    byte EDIV0       1;                                        Free-running ECLK Divider Bit 0 
    byte EDIV1       1;                                        Free-running ECLK Divider Bit 1 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte NCLKX2      1;                                        No ECLKX2 
    byte NECLK       1;                                        No ECLK 
  } Bits;
  struct {
    byte grpEDIV 2;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte grpNCLKX_2 1;
    byte         1;
  } MergedBits;
} ECLKCTLSTR;
extern volatile ECLKCTLSTR _ECLKCTL @(REG_BASE + 0x0000001C);
#define ECLKCTL                         _ECLKCTL.Byte
#define ECLKCTL_EDIV0                   _ECLKCTL.Bits.EDIV0
#define ECLKCTL_EDIV1                   _ECLKCTL.Bits.EDIV1
#define ECLKCTL_NCLKX2                  _ECLKCTL.Bits.NCLKX2
#define ECLKCTL_NECLK                   _ECLKCTL.Bits.NECLK
#define ECLKCTL_EDIV                    _ECLKCTL.MergedBits.grpEDIV

#define ECLKCTL_EDIV0_MASK              1
#define ECLKCTL_EDIV1_MASK              2
#define ECLKCTL_NCLKX2_MASK             64
#define ECLKCTL_NECLK_MASK              128
#define ECLKCTL_EDIV_MASK               3
#define ECLKCTL_EDIV_BITNUM             0


 IRQCR - Interrupt Control Register; 0x0000001E 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte IRQEN       1;                                        External IRQ Enable 
    byte IRQE        1;                                        IRQ Select Edge Sensitive Only 
  } Bits;
} IRQCRSTR;
extern volatile IRQCRSTR _IRQCR @(REG_BASE + 0x0000001E);
#define IRQCR                           _IRQCR.Byte
#define IRQCR_IRQEN                     _IRQCR.Bits.IRQEN
#define IRQCR_IRQE                      _IRQCR.Bits.IRQE

#define IRQCR_IRQEN_MASK                64
#define IRQCR_IRQE_MASK                 128


 DBGC1 - Debug Control Register 1; 0x00000020 
typedef union {
  byte Byte;
  struct {
    byte COMRV       2;                                        Comparator Register Visibility Bits 
    byte DBGBRK      2;                                        S12X_DBG Breakpoint Enable Bits 
    byte BDM         1;                                        Background Debug Mode Enable 
    byte XGSBPE      1;                                        XGATE SW Breakpoint Enable 
    byte TRIG        1;                                        Immediate Trigger Request Bit 
    byte ARM         1;                                        Arm Bit 
  } Bits;
} DBGC1STR;
extern volatile DBGC1STR _DBGC1 @(REG_BASE + 0x00000020);
#define DBGC1                           _DBGC1.Byte
#define DBGC1_COMRV                     _DBGC1.Bits.COMRV
#define DBGC1_DBGBRK                    _DBGC1.Bits.DBGBRK
#define DBGC1_BDM                       _DBGC1.Bits.BDM
#define DBGC1_XGSBPE                    _DBGC1.Bits.XGSBPE
#define DBGC1_TRIG                      _DBGC1.Bits.TRIG
#define DBGC1_ARM                       _DBGC1.Bits.ARM

#define DBGC1_COMRV_MASK                3
#define DBGC1_COMRV_BITNUM              0
#define DBGC1_DBGBRK_MASK               12
#define DBGC1_DBGBRK_BITNUM             2
#define DBGC1_BDM_MASK                  16
#define DBGC1_XGSBPE_MASK               32
#define DBGC1_TRIG_MASK                 64
#define DBGC1_ARM_MASK                  128


 DBGSR - Debug Status Register; 0x00000021 
typedef union {
  byte Byte;
  struct {
    byte SSF0        1;                                        State Sequencer Flag Bit 0 
    byte SSF1        1;                                        State Sequencer Flag Bit 1 
    byte SSF2        1;                                        State Sequencer Flag Bit 2 
    byte             1; 
    byte             1; 
    byte             1; 
    byte EXTF        1;                                        External Tag Hit Flag 
    byte TBF         1;                                        Trace Buffer Full 
  } Bits;
  struct {
    byte grpSSF  3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} DBGSRSTR;
extern volatile DBGSRSTR _DBGSR @(REG_BASE + 0x00000021);
#define DBGSR                           _DBGSR.Byte
#define DBGSR_SSF0                      _DBGSR.Bits.SSF0
#define DBGSR_SSF1                      _DBGSR.Bits.SSF1
#define DBGSR_SSF2                      _DBGSR.Bits.SSF2
#define DBGSR_EXTF                      _DBGSR.Bits.EXTF
#define DBGSR_TBF                       _DBGSR.Bits.TBF
#define DBGSR_SSF                       _DBGSR.MergedBits.grpSSF

#define DBGSR_SSF0_MASK                 1
#define DBGSR_SSF1_MASK                 2
#define DBGSR_SSF2_MASK                 4
#define DBGSR_EXTF_MASK                 64
#define DBGSR_TBF_MASK                  128
#define DBGSR_SSF_MASK                  7
#define DBGSR_SSF_BITNUM                0


 DBGTCR - Debug Trace Control Register; 0x00000022 
typedef union {
  byte Byte;
  struct {
    byte TALIGN      2;                                        Trigger Align Bits 
    byte TRCMOD      2;                                        Trace Mode Bits 
    byte TRANGE      2;                                        Trace Range Bits 
    byte TSOURCE     2;                                        Trace Source Control Bits 
  } Bits;
} DBGTCRSTR;
extern volatile DBGTCRSTR _DBGTCR @(REG_BASE + 0x00000022);
#define DBGTCR                          _DBGTCR.Byte
#define DBGTCR_TALIGN                   _DBGTCR.Bits.TALIGN
#define DBGTCR_TRCMOD                   _DBGTCR.Bits.TRCMOD
#define DBGTCR_TRANGE                   _DBGTCR.Bits.TRANGE
#define DBGTCR_TSOURCE                  _DBGTCR.Bits.TSOURCE

#define DBGTCR_TALIGN_MASK              3
#define DBGTCR_TALIGN_BITNUM            0
#define DBGTCR_TRCMOD_MASK              12
#define DBGTCR_TRCMOD_BITNUM            2
#define DBGTCR_TRANGE_MASK              48
#define DBGTCR_TRANGE_BITNUM            4
#define DBGTCR_TSOURCE_MASK             192
#define DBGTCR_TSOURCE_BITNUM           6


 DBGC2 - Debug Control Register 2; 0x00000023 
typedef union {
  byte Byte;
  struct {
    byte ABCM        2;                                        A and B Comparator Match Control 
    byte CDCM        2;                                        C and D Comparator Match Control 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} DBGC2STR;
extern volatile DBGC2STR _DBGC2 @(REG_BASE + 0x00000023);
#define DBGC2                           _DBGC2.Byte
#define DBGC2_ABCM                      _DBGC2.Bits.ABCM
#define DBGC2_CDCM                      _DBGC2.Bits.CDCM

#define DBGC2_ABCM_MASK                 3
#define DBGC2_ABCM_BITNUM               0
#define DBGC2_CDCM_MASK                 12
#define DBGC2_CDCM_BITNUM               2


 DBGTB - Debug Trace Buffer Register; 0x00000024 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     DBGTBH - Debug Trace Buffer Register High; 0x00000024 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Debug Trace Buffer Bit 8 
        byte BIT9        1;                                        Debug Trace Buffer Bit 9 
        byte BIT10       1;                                        Debug Trace Buffer Bit 10 
        byte BIT11       1;                                        Debug Trace Buffer Bit 11 
        byte BIT12       1;                                        Debug Trace Buffer Bit 12 
        byte BIT13       1;                                        Debug Trace Buffer Bit 13 
        byte BIT14       1;                                        Debug Trace Buffer Bit 14 
        byte BIT15       1;                                        Debug Trace Buffer Bit 15 
      } Bits;
    } DBGTBHSTR;
    #define DBGTBH                      _DBGTB.Overlap_STR.DBGTBHSTR.Byte
    #define DBGTBH_BIT8                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT8
    #define DBGTBH_BIT9                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT9
    #define DBGTBH_BIT10                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT10
    #define DBGTBH_BIT11                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT11
    #define DBGTBH_BIT12                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT12
    #define DBGTBH_BIT13                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT13
    #define DBGTBH_BIT14                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT14
    #define DBGTBH_BIT15                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT15
    
    
    #define DBGTBH_BIT8_MASK            1
    #define DBGTBH_BIT9_MASK            2
    #define DBGTBH_BIT10_MASK           4
    #define DBGTBH_BIT11_MASK           8
    #define DBGTBH_BIT12_MASK           16
    #define DBGTBH_BIT13_MASK           32
    #define DBGTBH_BIT14_MASK           64
    #define DBGTBH_BIT15_MASK           128


     DBGTBL - Debug Trace Buffer Register Low; 0x00000025 
    union {
      byte Byte;
      struct {
        byte BIT0        1;                                        Debug Trace Buffer Bit 0 
        byte BIT1        1;                                        Debug Trace Buffer Bit 1 
        byte BIT2        1;                                        Debug Trace Buffer Bit 2 
        byte BIT3        1;                                        Debug Trace Buffer Bit 3 
        byte BIT4        1;                                        Debug Trace Buffer Bit 4 
        byte BIT5        1;                                        Debug Trace Buffer Bit 5 
        byte BIT6        1;                                        Debug Trace Buffer Bit 6 
        byte BIT7        1;                                        Debug Trace Buffer Bit 7 
      } Bits;
    } DBGTBLSTR;
    #define DBGTBL                      _DBGTB.Overlap_STR.DBGTBLSTR.Byte
    #define DBGTBL_BIT0                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT0
    #define DBGTBL_BIT1                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT1
    #define DBGTBL_BIT2                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT2
    #define DBGTBL_BIT3                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT3
    #define DBGTBL_BIT4                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT4
    #define DBGTBL_BIT5                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT5
    #define DBGTBL_BIT6                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT6
    #define DBGTBL_BIT7                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT7
    
    
    #define DBGTBL_BIT0_MASK            1
    #define DBGTBL_BIT1_MASK            2
    #define DBGTBL_BIT2_MASK            4
    #define DBGTBL_BIT3_MASK            8
    #define DBGTBL_BIT4_MASK            16
    #define DBGTBL_BIT5_MASK            32
    #define DBGTBL_BIT6_MASK            64
    #define DBGTBL_BIT7_MASK            128

  } Overlap_STR;

  struct {
    word BIT0        1;                                        Debug Trace Buffer Bit 0 
    word BIT1        1;                                        Debug Trace Buffer Bit 1 
    word BIT2        1;                                        Debug Trace Buffer Bit 2 
    word BIT3        1;                                        Debug Trace Buffer Bit 3 
    word BIT4        1;                                        Debug Trace Buffer Bit 4 
    word BIT5        1;                                        Debug Trace Buffer Bit 5 
    word BIT6        1;                                        Debug Trace Buffer Bit 6 
    word BIT7        1;                                        Debug Trace Buffer Bit 7 
    word BIT8        1;                                        Debug Trace Buffer Bit 8 
    word BIT9        1;                                        Debug Trace Buffer Bit 9 
    word BIT10       1;                                        Debug Trace Buffer Bit 10 
    word BIT11       1;                                        Debug Trace Buffer Bit 11 
    word BIT12       1;                                        Debug Trace Buffer Bit 12 
    word BIT13       1;                                        Debug Trace Buffer Bit 13 
    word BIT14       1;                                        Debug Trace Buffer Bit 14 
    word BIT15       1;                                        Debug Trace Buffer Bit 15 
  } Bits;
} DBGTBSTR;
extern volatile DBGTBSTR _DBGTB @(REG_BASE + 0x00000024);
#define DBGTB                           _DBGTB.Word
#define DBGTB_BIT0                      _DBGTB.Bits.BIT0
#define DBGTB_BIT1                      _DBGTB.Bits.BIT1
#define DBGTB_BIT2                      _DBGTB.Bits.BIT2
#define DBGTB_BIT3                      _DBGTB.Bits.BIT3
#define DBGTB_BIT4                      _DBGTB.Bits.BIT4
#define DBGTB_BIT5                      _DBGTB.Bits.BIT5
#define DBGTB_BIT6                      _DBGTB.Bits.BIT6
#define DBGTB_BIT7                      _DBGTB.Bits.BIT7
#define DBGTB_BIT8                      _DBGTB.Bits.BIT8
#define DBGTB_BIT9                      _DBGTB.Bits.BIT9
#define DBGTB_BIT10                     _DBGTB.Bits.BIT10
#define DBGTB_BIT11                     _DBGTB.Bits.BIT11
#define DBGTB_BIT12                     _DBGTB.Bits.BIT12
#define DBGTB_BIT13                     _DBGTB.Bits.BIT13
#define DBGTB_BIT14                     _DBGTB.Bits.BIT14
#define DBGTB_BIT15                     _DBGTB.Bits.BIT15

#define DBGTB_BIT0_MASK                 1
#define DBGTB_BIT1_MASK                 2
#define DBGTB_BIT2_MASK                 4
#define DBGTB_BIT3_MASK                 8
#define DBGTB_BIT4_MASK                 16
#define DBGTB_BIT5_MASK                 32
#define DBGTB_BIT6_MASK                 64
#define DBGTB_BIT7_MASK                 128
#define DBGTB_BIT8_MASK                 256
#define DBGTB_BIT9_MASK                 512
#define DBGTB_BIT10_MASK                1024
#define DBGTB_BIT11_MASK                2048
#define DBGTB_BIT12_MASK                4096
#define DBGTB_BIT13_MASK                8192
#define DBGTB_BIT14_MASK                16384
#define DBGTB_BIT15_MASK                32768


 DBGCNT - Debug Count Register; 0x00000026 
typedef union {
  byte Byte;
  struct {
    byte CNT         7;                                        Count value 
    byte             1; 
  } Bits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @(REG_BASE + 0x00000026);
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT                      _DBGCNT.Bits.CNT

#define DBGCNT_CNT_MASK                 127
#define DBGCNT_CNT_BITNUM               0


 DBGSCRX - Debug State Control Register 0; 0x00000027 
typedef union {
  byte Byte;
  struct {
    byte SC0         1;                                        These bit (0) select the targeted next state whilst in StateX, based upon the match event 
    byte SC1         1;                                        These bit (1) select the targeted next state whilst in StateX, based upon the match event 
    byte SC2         1;                                        These bit (2) select the targeted next state whilst in StateX, based upon the match event 
    byte SC3         1;                                        These bit (3) select the targeted next state whilst in StateX, based upon the match event 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpSC   4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} DBGSCRXSTR;
extern volatile DBGSCRXSTR _DBGSCRX @(REG_BASE + 0x00000027);
#define DBGSCRX                         _DBGSCRX.Byte
#define DBGSCRX_SC0                     _DBGSCRX.Bits.SC0
#define DBGSCRX_SC1                     _DBGSCRX.Bits.SC1
#define DBGSCRX_SC2                     _DBGSCRX.Bits.SC2
#define DBGSCRX_SC3                     _DBGSCRX.Bits.SC3
#define DBGSCRX_SC                      _DBGSCRX.MergedBits.grpSC

#define DBGSCRX_SC0_MASK                1
#define DBGSCRX_SC1_MASK                2
#define DBGSCRX_SC2_MASK                4
#define DBGSCRX_SC3_MASK                8
#define DBGSCRX_SC_MASK                 15
#define DBGSCRX_SC_BITNUM               0


 DBGXCTL - Debug Comparator Control Register; 0x00000028 
typedef union {
  byte Byte;
  struct {
    byte COMPE       1;                                        Determines if comparator is enabled 
    byte SRC         1;                                        Determines mapping of comparator to S12X_CPU or XGATE 
    byte RWE         1;                                        ReadWrite Enable Bit 
    byte RW          1;                                        ReadWrite Comparator Value Bit 
    byte             1; 
    byte TAG         1;                                        Tag select 
    byte NDB_SZ      1;                                        Not Data Bus Compare (for comparators A and C), Size Comparator Value Bit (for comparators B and D) 
    byte SZE         1;                                        Size Comparator Enable Bit (for comparators B and D) 
  } Bits;
} DBGXCTLSTR;
extern volatile DBGXCTLSTR _DBGXCTL @(REG_BASE + 0x00000028);
#define DBGXCTL                         _DBGXCTL.Byte
#define DBGXCTL_COMPE                   _DBGXCTL.Bits.COMPE
#define DBGXCTL_SRC                     _DBGXCTL.Bits.SRC
#define DBGXCTL_RWE                     _DBGXCTL.Bits.RWE
#define DBGXCTL_RW                      _DBGXCTL.Bits.RW
#define DBGXCTL_TAG                     _DBGXCTL.Bits.TAG
#define DBGXCTL_NDB_SZ                  _DBGXCTL.Bits.NDB_SZ
#define DBGXCTL_SZE                     _DBGXCTL.Bits.SZE

#define DBGXCTL_COMPE_MASK              1
#define DBGXCTL_SRC_MASK                2
#define DBGXCTL_RWE_MASK                4
#define DBGXCTL_RW_MASK                 8
#define DBGXCTL_TAG_MASK                32
#define DBGXCTL_NDB_SZ_MASK             64
#define DBGXCTL_SZE_MASK                128


 DBGXAH - Debug Comparator Address High Register; 0x00000029 
typedef union {
  byte Byte;
  struct {
    byte BIT16       1;                                        Comparator Address High Compare Bit 16 
    byte BIT17       1;                                        Comparator Address High Compare Bit 17 
    byte BIT18       1;                                        Comparator Address High Compare Bit 18 
    byte BIT19       1;                                        Comparator Address High Compare Bit 19 
    byte BIT20       1;                                        Comparator Address High Compare Bit 20 
    byte BIT21       1;                                        Comparator Address High Compare Bit 21 
    byte BIT22       1;                                        Comparator Address High Compare Bit 22 
    byte             1; 
  } Bits;
  struct {
    byte grpBIT_16 7;
    byte         1;
  } MergedBits;
} DBGXAHSTR;
extern volatile DBGXAHSTR _DBGXAH @(REG_BASE + 0x00000029);
#define DBGXAH                          _DBGXAH.Byte
#define DBGXAH_BIT16                    _DBGXAH.Bits.BIT16
#define DBGXAH_BIT17                    _DBGXAH.Bits.BIT17
#define DBGXAH_BIT18                    _DBGXAH.Bits.BIT18
#define DBGXAH_BIT19                    _DBGXAH.Bits.BIT19
#define DBGXAH_BIT20                    _DBGXAH.Bits.BIT20
#define DBGXAH_BIT21                    _DBGXAH.Bits.BIT21
#define DBGXAH_BIT22                    _DBGXAH.Bits.BIT22
#define DBGXAH_BIT_16                   _DBGXAH.MergedBits.grpBIT_16
#define DBGXAH_BIT                      DBGXAH_BIT_16

#define DBGXAH_BIT16_MASK               1
#define DBGXAH_BIT17_MASK               2
#define DBGXAH_BIT18_MASK               4
#define DBGXAH_BIT19_MASK               8
#define DBGXAH_BIT20_MASK               16
#define DBGXAH_BIT21_MASK               32
#define DBGXAH_BIT22_MASK               64
#define DBGXAH_BIT_16_MASK              127
#define DBGXAH_BIT_16_BITNUM            0


 DBGXAM - Debug Comparator Address Mid Register; 0x0000002A 
typedef union {
  byte Byte;
  struct {
    byte BIT8        1;                                        Comparator Address Mid Compare Bit 8 
    byte BIT9        1;                                        Comparator Address Mid Compare Bit 9 
    byte BIT10       1;                                        Comparator Address Mid Compare Bit 10 
    byte BIT11       1;                                        Comparator Address Mid Compare Bit 11 
    byte BIT12       1;                                        Comparator Address Mid Compare Bit 12 
    byte BIT13       1;                                        Comparator Address Mid Compare Bit 13 
    byte BIT14       1;                                        Comparator Address Mid Compare Bit 14 
    byte BIT15       1;                                        Comparator Address Mid Compare Bit 15 
  } Bits;
} DBGXAMSTR;
extern volatile DBGXAMSTR _DBGXAM @(REG_BASE + 0x0000002A);
#define DBGXAM                          _DBGXAM.Byte
#define DBGXAM_BIT8                     _DBGXAM.Bits.BIT8
#define DBGXAM_BIT9                     _DBGXAM.Bits.BIT9
#define DBGXAM_BIT10                    _DBGXAM.Bits.BIT10
#define DBGXAM_BIT11                    _DBGXAM.Bits.BIT11
#define DBGXAM_BIT12                    _DBGXAM.Bits.BIT12
#define DBGXAM_BIT13                    _DBGXAM.Bits.BIT13
#define DBGXAM_BIT14                    _DBGXAM.Bits.BIT14
#define DBGXAM_BIT15                    _DBGXAM.Bits.BIT15

#define DBGXAM_BIT8_MASK                1
#define DBGXAM_BIT9_MASK                2
#define DBGXAM_BIT10_MASK               4
#define DBGXAM_BIT11_MASK               8
#define DBGXAM_BIT12_MASK               16
#define DBGXAM_BIT13_MASK               32
#define DBGXAM_BIT14_MASK               64
#define DBGXAM_BIT15_MASK               128


 DBGXAL - Debug Comparator Address Low Register; 0x0000002B 
typedef union {
  byte Byte;
  struct {
    byte BIT0        1;                                        Comparator Address Low Compare Bit 0 
    byte BIT1        1;                                        Comparator Address Low Compare Bit 1 
    byte BIT2        1;                                        Comparator Address Low Compare Bit 2 
    byte BIT3        1;                                        Comparator Address Low Compare Bit 3 
    byte BIT4        1;                                        Comparator Address Low Compare Bit 4 
    byte BIT5        1;                                        Comparator Address Low Compare Bit 5 
    byte BIT6        1;                                        Comparator Address Low Compare Bit 6 
    byte BIT7        1;                                        Comparator Address Low Compare Bit 7 
  } Bits;
} DBGXALSTR;
extern volatile DBGXALSTR _DBGXAL @(REG_BASE + 0x0000002B);
#define DBGXAL                          _DBGXAL.Byte
#define DBGXAL_BIT0                     _DBGXAL.Bits.BIT0
#define DBGXAL_BIT1                     _DBGXAL.Bits.BIT1
#define DBGXAL_BIT2                     _DBGXAL.Bits.BIT2
#define DBGXAL_BIT3                     _DBGXAL.Bits.BIT3
#define DBGXAL_BIT4                     _DBGXAL.Bits.BIT4
#define DBGXAL_BIT5                     _DBGXAL.Bits.BIT5
#define DBGXAL_BIT6                     _DBGXAL.Bits.BIT6
#define DBGXAL_BIT7                     _DBGXAL.Bits.BIT7

#define DBGXAL_BIT0_MASK                1
#define DBGXAL_BIT1_MASK                2
#define DBGXAL_BIT2_MASK                4
#define DBGXAL_BIT3_MASK                8
#define DBGXAL_BIT4_MASK                16
#define DBGXAL_BIT5_MASK                32
#define DBGXAL_BIT6_MASK                64
#define DBGXAL_BIT7_MASK                128


 DBGXDH - Debug Comparator Data High Register; 0x0000002C 
typedef union {
  byte Byte;
  struct {
    byte BIT0        1;                                        Comparator A Compare Bit 0 
    byte BIT1        1;                                        Comparator A Compare Bit 1 
    byte BIT2        1;                                        Comparator A Compare Bit 2 
    byte BIT3        1;                                        Comparator A Compare Bit 3 
    byte BIT4        1;                                        Comparator A Compare Bit 4 
    byte BIT5        1;                                        Comparator A Compare Bit 5 
    byte BIT6        1;                                        Comparator A Compare Bit 6 
    byte BIT7        1;                                        Comparator A Compare Bit 7 
  } Bits;
} DBGXDHSTR;
extern volatile DBGXDHSTR _DBGXDH @(REG_BASE + 0x0000002C);
#define DBGXDH                          _DBGXDH.Byte
#define DBGXDH_BIT0                     _DBGXDH.Bits.BIT0
#define DBGXDH_BIT1                     _DBGXDH.Bits.BIT1
#define DBGXDH_BIT2                     _DBGXDH.Bits.BIT2
#define DBGXDH_BIT3                     _DBGXDH.Bits.BIT3
#define DBGXDH_BIT4                     _DBGXDH.Bits.BIT4
#define DBGXDH_BIT5                     _DBGXDH.Bits.BIT5
#define DBGXDH_BIT6                     _DBGXDH.Bits.BIT6
#define DBGXDH_BIT7                     _DBGXDH.Bits.BIT7

#define DBGXDH_BIT0_MASK                1
#define DBGXDH_BIT1_MASK                2
#define DBGXDH_BIT2_MASK                4
#define DBGXDH_BIT3_MASK                8
#define DBGXDH_BIT4_MASK                16
#define DBGXDH_BIT5_MASK                32
#define DBGXDH_BIT6_MASK                64
#define DBGXDH_BIT7_MASK                128


 DBGXDL - Debug Comparator Data Low Register; 0x0000002D 
typedef union {
  byte Byte;
  struct {
    byte BIT0        1;                                        Comparator Address Low Compare Bit 0 
    byte BIT1        1;                                        Comparator Address Low Compare Bit 1 
    byte BIT2        1;                                        Comparator Address Low Compare Bit 2 
    byte BIT3        1;                                        Comparator Address Low Compare Bit 3 
    byte BIT4        1;                                        Comparator Address Low Compare Bit 4 
    byte BIT5        1;                                        Comparator Address Low Compare Bit 5 
    byte BIT6        1;                                        Comparator Address Low Compare Bit 6 
    byte BIT7        1;                                        Comparator Address Low Compare Bit 7 
  } Bits;
} DBGXDLSTR;
extern volatile DBGXDLSTR _DBGXDL @(REG_BASE + 0x0000002D);
#define DBGXDL                          _DBGXDL.Byte
#define DBGXDL_BIT0                     _DBGXDL.Bits.BIT0
#define DBGXDL_BIT1                     _DBGXDL.Bits.BIT1
#define DBGXDL_BIT2                     _DBGXDL.Bits.BIT2
#define DBGXDL_BIT3                     _DBGXDL.Bits.BIT3
#define DBGXDL_BIT4                     _DBGXDL.Bits.BIT4
#define DBGXDL_BIT5                     _DBGXDL.Bits.BIT5
#define DBGXDL_BIT6                     _DBGXDL.Bits.BIT6
#define DBGXDL_BIT7                     _DBGXDL.Bits.BIT7

#define DBGXDL_BIT0_MASK                1
#define DBGXDL_BIT1_MASK                2
#define DBGXDL_BIT2_MASK                4
#define DBGXDL_BIT3_MASK                8
#define DBGXDL_BIT4_MASK                16
#define DBGXDL_BIT5_MASK                32
#define DBGXDL_BIT6_MASK                64
#define DBGXDL_BIT7_MASK                128


 DBGXDHM - Debug Comparator Data High Mask Register; 0x0000002E 
typedef union {
  byte Byte;
  struct {
    byte BIT8        1;                                        Comparator Data High Mask Bit 8 
    byte BIT9        1;                                        Comparator Data High Mask Bit 9 
    byte BIT10       1;                                        Comparator Data High Mask Bit 10 
    byte BIT11       1;                                        Comparator Data High Mask Bit 11 
    byte BIT12       1;                                        Comparator Data High Mask Bit 12 
    byte BIT13       1;                                        Comparator Data High Mask Bit 13 
    byte BIT14       1;                                        Comparator Data High Mask Bit 14 
    byte BIT15       1;                                        Comparator Data High Mask Bit 15 
  } Bits;
} DBGXDHMSTR;
extern volatile DBGXDHMSTR _DBGXDHM @(REG_BASE + 0x0000002E);
#define DBGXDHM                         _DBGXDHM.Byte
#define DBGXDHM_BIT8                    _DBGXDHM.Bits.BIT8
#define DBGXDHM_BIT9                    _DBGXDHM.Bits.BIT9
#define DBGXDHM_BIT10                   _DBGXDHM.Bits.BIT10
#define DBGXDHM_BIT11                   _DBGXDHM.Bits.BIT11
#define DBGXDHM_BIT12                   _DBGXDHM.Bits.BIT12
#define DBGXDHM_BIT13                   _DBGXDHM.Bits.BIT13
#define DBGXDHM_BIT14                   _DBGXDHM.Bits.BIT14
#define DBGXDHM_BIT15                   _DBGXDHM.Bits.BIT15

#define DBGXDHM_BIT8_MASK               1
#define DBGXDHM_BIT9_MASK               2
#define DBGXDHM_BIT10_MASK              4
#define DBGXDHM_BIT11_MASK              8
#define DBGXDHM_BIT12_MASK              16
#define DBGXDHM_BIT13_MASK              32
#define DBGXDHM_BIT14_MASK              64
#define DBGXDHM_BIT15_MASK              128


 DBGXDLM - Debug Comparator Data Low Mask Register; 0x0000002F 
typedef union {
  byte Byte;
  struct {
    byte BIT0        1;                                        Comparator Data High Mask Bit 0 
    byte BIT1        1;                                        Comparator Data High Mask Bit 1 
    byte BIT2        1;                                        Comparator Data High Mask Bit 2 
    byte BIT3        1;                                        Comparator Data High Mask Bit 3 
    byte BIT4        1;                                        Comparator Data High Mask Bit 4 
    byte BIT5        1;                                        Comparator Data High Mask Bit 5 
    byte BIT6        1;                                        Comparator Data High Mask Bit 6 
    byte BIT7        1;                                        Comparator Data High Mask Bit 7 
  } Bits;
} DBGXDLMSTR;
extern volatile DBGXDLMSTR _DBGXDLM @(REG_BASE + 0x0000002F);
#define DBGXDLM                         _DBGXDLM.Byte
#define DBGXDLM_BIT0                    _DBGXDLM.Bits.BIT0
#define DBGXDLM_BIT1                    _DBGXDLM.Bits.BIT1
#define DBGXDLM_BIT2                    _DBGXDLM.Bits.BIT2
#define DBGXDLM_BIT3                    _DBGXDLM.Bits.BIT3
#define DBGXDLM_BIT4                    _DBGXDLM.Bits.BIT4
#define DBGXDLM_BIT5                    _DBGXDLM.Bits.BIT5
#define DBGXDLM_BIT6                    _DBGXDLM.Bits.BIT6
#define DBGXDLM_BIT7                    _DBGXDLM.Bits.BIT7

#define DBGXDLM_BIT0_MASK               1
#define DBGXDLM_BIT1_MASK               2
#define DBGXDLM_BIT2_MASK               4
#define DBGXDLM_BIT3_MASK               8
#define DBGXDLM_BIT4_MASK               16
#define DBGXDLM_BIT5_MASK               32
#define DBGXDLM_BIT6_MASK               64
#define DBGXDLM_BIT7_MASK               128


 PPAGE - Program Page Index Register; 0x00000030 
typedef union {
  byte Byte;
  struct {
    byte PIX0        1;                                        Program Page Index Bit 0 
    byte PIX1        1;                                        Program Page Index Bit 1 
    byte PIX2        1;                                        Program Page Index Bit 2 
    byte PIX3        1;                                        Program Page Index Bit 3 
    byte PIX4        1;                                        Program Page Index Bit 4 
    byte PIX5        1;                                        Program Page Index Bit 5 
    byte PIX6        1;                                        Program Page Index Bit 6 
    byte PIX7        1;                                        Program Page Index Bit 7 
  } Bits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @(REG_BASE + 0x00000030);
#define PPAGE                           _PPAGE.Byte
#define PPAGE_PIX0                      _PPAGE.Bits.PIX0
#define PPAGE_PIX1                      _PPAGE.Bits.PIX1
#define PPAGE_PIX2                      _PPAGE.Bits.PIX2
#define PPAGE_PIX3                      _PPAGE.Bits.PIX3
#define PPAGE_PIX4                      _PPAGE.Bits.PIX4
#define PPAGE_PIX5                      _PPAGE.Bits.PIX5
#define PPAGE_PIX6                      _PPAGE.Bits.PIX6
#define PPAGE_PIX7                      _PPAGE.Bits.PIX7

#define PPAGE_PIX0_MASK                 1
#define PPAGE_PIX1_MASK                 2
#define PPAGE_PIX2_MASK                 4
#define PPAGE_PIX3_MASK                 8
#define PPAGE_PIX4_MASK                 16
#define PPAGE_PIX5_MASK                 32
#define PPAGE_PIX6_MASK                 64
#define PPAGE_PIX7_MASK                 128


 PORTK - Port K Data Register; 0x00000032 
typedef union {
  byte Byte;
  struct {
    byte PK0         1;                                        Port K Bit 0 
    byte PK1         1;                                        Port K Bit 1 
    byte PK2         1;                                        Port K Bit 2 
    byte PK3         1;                                        Port K Bit 3 
    byte PK4         1;                                        Port K Bit 4 
    byte PK5         1;                                        Port K Bit 5 
    byte PK6         1;                                        Port K Bit 6 
    byte PK7         1;                                        Port K Bit 7 
  } Bits;
} PORTKSTR;
extern volatile PORTKSTR _PORTK @(REG_BASE + 0x00000032);
#define PORTK                           _PORTK.Byte
#define PORTK_PK0                       _PORTK.Bits.PK0
#define PORTK_PK1                       _PORTK.Bits.PK1
#define PORTK_PK2                       _PORTK.Bits.PK2
#define PORTK_PK3                       _PORTK.Bits.PK3
#define PORTK_PK4                       _PORTK.Bits.PK4
#define PORTK_PK5                       _PORTK.Bits.PK5
#define PORTK_PK6                       _PORTK.Bits.PK6
#define PORTK_PK7                       _PORTK.Bits.PK7

#define PORTK_PK0_MASK                  1
#define PORTK_PK1_MASK                  2
#define PORTK_PK2_MASK                  4
#define PORTK_PK3_MASK                  8
#define PORTK_PK4_MASK                  16
#define PORTK_PK5_MASK                  32
#define PORTK_PK6_MASK                  64
#define PORTK_PK7_MASK                  128


 DDRK - Port K Data Direction Register; 0x00000033 
typedef union {
  byte Byte;
  struct {
    byte DDRK0       1;                                        Port K Data Direction Bit 0 
    byte DDRK1       1;                                        Port K Data Direction Bit 1 
    byte DDRK2       1;                                        Port K Data Direction Bit 2 
    byte DDRK3       1;                                        Port K Data Direction Bit 3 
    byte DDRK4       1;                                        Port K Data Direction Bit 4 
    byte DDRK5       1;                                        Port K Data Direction Bit 5 
    byte DDRK6       1;                                        Port K Data Direction Bit 6 
    byte DDRK7       1;                                        Port K Data Direction Bit 7 
  } Bits;
} DDRKSTR;
extern volatile DDRKSTR _DDRK @(REG_BASE + 0x00000033);
#define DDRK                            _DDRK.Byte
#define DDRK_DDRK0                      _DDRK.Bits.DDRK0
#define DDRK_DDRK1                      _DDRK.Bits.DDRK1
#define DDRK_DDRK2                      _DDRK.Bits.DDRK2
#define DDRK_DDRK3                      _DDRK.Bits.DDRK3
#define DDRK_DDRK4                      _DDRK.Bits.DDRK4
#define DDRK_DDRK5                      _DDRK.Bits.DDRK5
#define DDRK_DDRK6                      _DDRK.Bits.DDRK6
#define DDRK_DDRK7                      _DDRK.Bits.DDRK7

#define DDRK_DDRK0_MASK                 1
#define DDRK_DDRK1_MASK                 2
#define DDRK_DDRK2_MASK                 4
#define DDRK_DDRK3_MASK                 8
#define DDRK_DDRK4_MASK                 16
#define DDRK_DDRK5_MASK                 32
#define DDRK_DDRK6_MASK                 64
#define DDRK_DDRK7_MASK                 128


 SYNR - CRG Synthesizer Register; 0x00000034 
typedef union {
  byte Byte;
  struct {
    byte SYN0        1;                                        CRG Synthesizer Bit 0 
    byte SYN1        1;                                        CRG Synthesizer Bit 1 
    byte SYN2        1;                                        CRG Synthesizer Bit 2 
    byte SYN3        1;                                        CRG Synthesizer Bit 3 
    byte SYN4        1;                                        CRG Synthesizer Bit 4 
    byte SYN5        1;                                        CRG Synthesizer Bit 5 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpSYN  6;
    byte         1;
    byte         1;
  } MergedBits;
} SYNRSTR;
extern volatile SYNRSTR _SYNR @(REG_BASE + 0x00000034);
#define SYNR                            _SYNR.Byte
#define SYNR_SYN0                       _SYNR.Bits.SYN0
#define SYNR_SYN1                       _SYNR.Bits.SYN1
#define SYNR_SYN2                       _SYNR.Bits.SYN2
#define SYNR_SYN3                       _SYNR.Bits.SYN3
#define SYNR_SYN4                       _SYNR.Bits.SYN4
#define SYNR_SYN5                       _SYNR.Bits.SYN5
#define SYNR_SYN                        _SYNR.MergedBits.grpSYN

#define SYNR_SYN0_MASK                  1
#define SYNR_SYN1_MASK                  2
#define SYNR_SYN2_MASK                  4
#define SYNR_SYN3_MASK                  8
#define SYNR_SYN4_MASK                  16
#define SYNR_SYN5_MASK                  32
#define SYNR_SYN_MASK                   63
#define SYNR_SYN_BITNUM                 0


 REFDV - CRG Reference Divider Register; 0x00000035 
typedef union {
  byte Byte;
  struct {
    byte REFDV0      1;                                        CRG Reference Divider Bit 0 
    byte REFDV1      1;                                        CRG Reference Divider Bit 1 
    byte REFDV2      1;                                        CRG Reference Divider Bit 2 
    byte REFDV3      1;                                        CRG Reference Divider Bit 3 
    byte REFDV4      1;                                        CRG Reference Divider Bit 4 
    byte REFDV5      1;                                        CRG Reference Divider Bit 5 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpREFDV 6;
    byte         1;
    byte         1;
  } MergedBits;
} REFDVSTR;
extern volatile REFDVSTR _REFDV @(REG_BASE + 0x00000035);
#define REFDV                           _REFDV.Byte
#define REFDV_REFDV0                    _REFDV.Bits.REFDV0
#define REFDV_REFDV1                    _REFDV.Bits.REFDV1
#define REFDV_REFDV2                    _REFDV.Bits.REFDV2
#define REFDV_REFDV3                    _REFDV.Bits.REFDV3
#define REFDV_REFDV4                    _REFDV.Bits.REFDV4
#define REFDV_REFDV5                    _REFDV.Bits.REFDV5
#define REFDV_REFDV                     _REFDV.MergedBits.grpREFDV

#define REFDV_REFDV0_MASK               1
#define REFDV_REFDV1_MASK               2
#define REFDV_REFDV2_MASK               4
#define REFDV_REFDV3_MASK               8
#define REFDV_REFDV4_MASK               16
#define REFDV_REFDV5_MASK               32
#define REFDV_REFDV_MASK                63
#define REFDV_REFDV_BITNUM              0


 CRGFLG - CRG Flags Register; 0x00000037 
typedef union {
  byte Byte;
  struct {
    byte SCM         1;                                        Self-clock mode Status 
    byte SCMIF       1;                                        Self-clock mode Interrupt Flag 
    byte TRACK       1;                                        Track Status 
    byte LOCK        1;                                        Lock Status 
    byte LOCKIF      1;                                        PLL Lock Interrupt Flag 
    byte LVRF        1;                                        Low Voltage Reset Flag 
    byte PORF        1;                                        Power on Reset Flag 
    byte RTIF        1;                                        Real Time Interrupt Flag 
  } Bits;
} CRGFLGSTR;
extern volatile CRGFLGSTR _CRGFLG @(REG_BASE + 0x00000037);
#define CRGFLG                          _CRGFLG.Byte
#define CRGFLG_SCM                      _CRGFLG.Bits.SCM
#define CRGFLG_SCMIF                    _CRGFLG.Bits.SCMIF
#define CRGFLG_TRACK                    _CRGFLG.Bits.TRACK
#define CRGFLG_LOCK                     _CRGFLG.Bits.LOCK
#define CRGFLG_LOCKIF                   _CRGFLG.Bits.LOCKIF
#define CRGFLG_LVRF                     _CRGFLG.Bits.LVRF
#define CRGFLG_PORF                     _CRGFLG.Bits.PORF
#define CRGFLG_RTIF                     _CRGFLG.Bits.RTIF

#define CRGFLG_SCM_MASK                 1
#define CRGFLG_SCMIF_MASK               2
#define CRGFLG_TRACK_MASK               4
#define CRGFLG_LOCK_MASK                8
#define CRGFLG_LOCKIF_MASK              16
#define CRGFLG_LVRF_MASK                32
#define CRGFLG_PORF_MASK                64
#define CRGFLG_RTIF_MASK                128


 CRGINT - CRG Interrupt Enable Register; 0x00000038 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte SCMIE       1;                                        Self-clock mode Interrupt Enable 
    byte             1; 
    byte             1; 
    byte LOCKIE      1;                                        Lock Interrupt Enable 
    byte             1; 
    byte ILAF        1;                                        Illegal Address Reset Flag 
    byte RTIE        1;                                        Real Time Interrupt Enable 
  } Bits;
} CRGINTSTR;
extern volatile CRGINTSTR _CRGINT @(REG_BASE + 0x00000038);
#define CRGINT                          _CRGINT.Byte
#define CRGINT_SCMIE                    _CRGINT.Bits.SCMIE
#define CRGINT_LOCKIE                   _CRGINT.Bits.LOCKIE
#define CRGINT_ILAF                     _CRGINT.Bits.ILAF
#define CRGINT_RTIE                     _CRGINT.Bits.RTIE

#define CRGINT_SCMIE_MASK               2
#define CRGINT_LOCKIE_MASK              16
#define CRGINT_ILAF_MASK                64
#define CRGINT_RTIE_MASK                128


 CLKSEL - CRG Clock Select Register; 0x00000039 
typedef union {
  byte Byte;
  struct {
    byte COPWAI      1;                                        COP stops in WAIT mode 
    byte RTIWAI      1;                                        RTI stops in WAIT mode 
    byte             1; 
    byte PLLWAI      1;                                        PLL stops in WAIT mode 
    byte             1; 
    byte             1; 
    byte PSTP        1;                                        Pseudo Stop 
    byte PLLSEL      1;                                        PLL selected for system clock 
  } Bits;
} CLKSELSTR;
extern volatile CLKSELSTR _CLKSEL @(REG_BASE + 0x00000039);
#define CLKSEL                          _CLKSEL.Byte
#define CLKSEL_COPWAI                   _CLKSEL.Bits.COPWAI
#define CLKSEL_RTIWAI                   _CLKSEL.Bits.RTIWAI
#define CLKSEL_PLLWAI                   _CLKSEL.Bits.PLLWAI
#define CLKSEL_PSTP                     _CLKSEL.Bits.PSTP
#define CLKSEL_PLLSEL                   _CLKSEL.Bits.PLLSEL

#define CLKSEL_COPWAI_MASK              1
#define CLKSEL_RTIWAI_MASK              2
#define CLKSEL_PLLWAI_MASK              8
#define CLKSEL_PSTP_MASK                64
#define CLKSEL_PLLSEL_MASK              128


 PLLCTL - CRG PLL Control Register; 0x0000003A 
typedef union {
  byte Byte;
  struct {
    byte SCME        1;                                        Self-clock mode enable 
    byte PCE         1;                                        COP Enable during Pseudo Stop Bit 
    byte PRE         1;                                        RTI Enable during Pseudo Stop Bit 
    byte FSTWKP      1;                                        Fast Wake-up from Full Stop Bit 
    byte ACQ         1;                                        Acquisition 
    byte AUTO        1;                                        Automatic Bandwidth Control 
    byte PLLON       1;                                        Phase Lock Loop On 
    byte CME         1;                                        Clock Monitor Enable 
  } Bits;
} PLLCTLSTR;
extern volatile PLLCTLSTR _PLLCTL @(REG_BASE + 0x0000003A);
#define PLLCTL                          _PLLCTL.Byte
#define PLLCTL_SCME                     _PLLCTL.Bits.SCME
#define PLLCTL_PCE                      _PLLCTL.Bits.PCE
#define PLLCTL_PRE                      _PLLCTL.Bits.PRE
#define PLLCTL_FSTWKP                   _PLLCTL.Bits.FSTWKP
#define PLLCTL_ACQ                      _PLLCTL.Bits.ACQ
#define PLLCTL_AUTO                     _PLLCTL.Bits.AUTO
#define PLLCTL_PLLON                    _PLLCTL.Bits.PLLON
#define PLLCTL_CME                      _PLLCTL.Bits.CME

#define PLLCTL_SCME_MASK                1
#define PLLCTL_PCE_MASK                 2
#define PLLCTL_PRE_MASK                 4
#define PLLCTL_FSTWKP_MASK              8
#define PLLCTL_ACQ_MASK                 16
#define PLLCTL_AUTO_MASK                32
#define PLLCTL_PLLON_MASK               64
#define PLLCTL_CME_MASK                 128


 RTICTL - CRG RTI Control Register; 0x0000003B 
typedef union {
  byte Byte;
  struct {
    byte RTR0        1;                                        Real Time Interrupt Modulus Counter Select Bit 0 
    byte RTR1        1;                                        Real Time Interrupt Modulus Counter Select Bit 1 
    byte RTR2        1;                                        Real Time Interrupt Modulus Counter Select Bit 2 
    byte RTR3        1;                                        Real Time Interrupt Modulus Counter Select Bit 3 
    byte RTR4        1;                                        Real Time Interrupt Prescale Rate Select Bit 4 
    byte RTR5        1;                                        Real Time Interrupt Prescale Rate Select Bit 5 
    byte RTR6        1;                                        Real Time Interrupt Prescale Rate Select Bit 6 
    byte RTDEC       1;                                        Decimal or Binary Divider Select Bit 
  } Bits;
  struct {
    byte grpRTR  7;
    byte         1;
  } MergedBits;
} RTICTLSTR;
extern volatile RTICTLSTR _RTICTL @(REG_BASE + 0x0000003B);
#define RTICTL                          _RTICTL.Byte
#define RTICTL_RTR0                     _RTICTL.Bits.RTR0
#define RTICTL_RTR1                     _RTICTL.Bits.RTR1
#define RTICTL_RTR2                     _RTICTL.Bits.RTR2
#define RTICTL_RTR3                     _RTICTL.Bits.RTR3
#define RTICTL_RTR4                     _RTICTL.Bits.RTR4
#define RTICTL_RTR5                     _RTICTL.Bits.RTR5
#define RTICTL_RTR6                     _RTICTL.Bits.RTR6
#define RTICTL_RTDEC                    _RTICTL.Bits.RTDEC
#define RTICTL_RTR                      _RTICTL.MergedBits.grpRTR

#define RTICTL_RTR0_MASK                1
#define RTICTL_RTR1_MASK                2
#define RTICTL_RTR2_MASK                4
#define RTICTL_RTR3_MASK                8
#define RTICTL_RTR4_MASK                16
#define RTICTL_RTR5_MASK                32
#define RTICTL_RTR6_MASK                64
#define RTICTL_RTDEC_MASK               128
#define RTICTL_RTR_MASK                 127
#define RTICTL_RTR_BITNUM               0


 COPCTL - CRG COP Control Register; 0x0000003C 
typedef union {
  byte Byte;
  struct {
    byte CR0         1;                                        COP Watchdog Timer Rate select Bit 0 
    byte CR1         1;                                        COP Watchdog Timer Rate select Bit 1 
    byte CR2         1;                                        COP Watchdog Timer Rate select Bit 2 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RSBCK       1;                                        COP and RTI stop in Active BDM mode Bit 
    byte WCOP        1;                                        Window COP mode 
  } Bits;
  struct {
    byte grpCR   3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} COPCTLSTR;
extern volatile COPCTLSTR _COPCTL @(REG_BASE + 0x0000003C);
#define COPCTL                          _COPCTL.Byte
#define COPCTL_CR0                      _COPCTL.Bits.CR0
#define COPCTL_CR1                      _COPCTL.Bits.CR1
#define COPCTL_CR2                      _COPCTL.Bits.CR2
#define COPCTL_RSBCK                    _COPCTL.Bits.RSBCK
#define COPCTL_WCOP                     _COPCTL.Bits.WCOP
#define COPCTL_CR                       _COPCTL.MergedBits.grpCR

#define COPCTL_CR0_MASK                 1
#define COPCTL_CR1_MASK                 2
#define COPCTL_CR2_MASK                 4
#define COPCTL_RSBCK_MASK               64
#define COPCTL_WCOP_MASK                128
#define COPCTL_CR_MASK                  7
#define COPCTL_CR_BITNUM                0


 ARMCOP - CRG COP Timer ArmReset Register; 0x0000003F 
typedef union {
  byte Byte;
  struct {
    byte BIT0        1;                                        CRG COP Timer ArmReset Bit 0 
    byte BIT1        1;                                        CRG COP Timer ArmReset Bit 1 
    byte BIT2        1;                                        CRG COP Timer ArmReset Bit 2 
    byte BIT3        1;                                        CRG COP Timer ArmReset Bit 3 
    byte BIT4        1;                                        CRG COP Timer ArmReset Bit 4 
    byte BIT5        1;                                        CRG COP Timer ArmReset Bit 5 
    byte BIT6        1;                                        CRG COP Timer ArmReset Bit 6 
    byte BIT7        1;                                        CRG COP Timer ArmReset Bit 7 
  } Bits;
} ARMCOPSTR;
extern volatile ARMCOPSTR _ARMCOP @(REG_BASE + 0x0000003F);
#define ARMCOP                          _ARMCOP.Byte
#define ARMCOP_BIT0                     _ARMCOP.Bits.BIT0
#define ARMCOP_BIT1                     _ARMCOP.Bits.BIT1
#define ARMCOP_BIT2                     _ARMCOP.Bits.BIT2
#define ARMCOP_BIT3                     _ARMCOP.Bits.BIT3
#define ARMCOP_BIT4                     _ARMCOP.Bits.BIT4
#define ARMCOP_BIT5                     _ARMCOP.Bits.BIT5
#define ARMCOP_BIT6                     _ARMCOP.Bits.BIT6
#define ARMCOP_BIT7                     _ARMCOP.Bits.BIT7

#define ARMCOP_BIT0_MASK                1
#define ARMCOP_BIT1_MASK                2
#define ARMCOP_BIT2_MASK                4
#define ARMCOP_BIT3_MASK                8
#define ARMCOP_BIT4_MASK                16
#define ARMCOP_BIT5_MASK                32
#define ARMCOP_BIT6_MASK                64
#define ARMCOP_BIT7_MASK                128


 TIOS - Timer Input CaptureOutput Compare Select; 0x00000040 
typedef union {
  byte Byte;
  struct {
    byte IOS0        1;                                        Input Capture or Output Compare Channel Configuration Bit 0 
    byte IOS1        1;                                        Input Capture or Output Compare Channel Configuration Bit 1 
    byte IOS2        1;                                        Input Capture or Output Compare Channel Configuration Bit 2 
    byte IOS3        1;                                        Input Capture or Output Compare Channel Configuration Bit 3 
    byte IOS4        1;                                        Input Capture or Output Compare Channel Configuration Bit 4 
    byte IOS5        1;                                        Input Capture or Output Compare Channel Configuration Bit 5 
    byte IOS6        1;                                        Input Capture or Output Compare Channel Configuration Bit 6 
    byte IOS7        1;                                        Input Capture or Output Compare Channel Configuration Bit 7 
  } Bits;
} TIOSSTR;
extern volatile TIOSSTR _TIOS @(REG_BASE + 0x00000040);
#define TIOS                            _TIOS.Byte
#define TIOS_IOS0                       _TIOS.Bits.IOS0
#define TIOS_IOS1                       _TIOS.Bits.IOS1
#define TIOS_IOS2                       _TIOS.Bits.IOS2
#define TIOS_IOS3                       _TIOS.Bits.IOS3
#define TIOS_IOS4                       _TIOS.Bits.IOS4
#define TIOS_IOS5                       _TIOS.Bits.IOS5
#define TIOS_IOS6                       _TIOS.Bits.IOS6
#define TIOS_IOS7                       _TIOS.Bits.IOS7

#define TIOS_IOS0_MASK                  1
#define TIOS_IOS1_MASK                  2
#define TIOS_IOS2_MASK                  4
#define TIOS_IOS3_MASK                  8
#define TIOS_IOS4_MASK                  16
#define TIOS_IOS5_MASK                  32
#define TIOS_IOS6_MASK                  64
#define TIOS_IOS7_MASK                  128


 CFORC - Timer Compare Force Register; 0x00000041 
typedef union {
  byte Byte;
  struct {
    byte FOC0        1;                                        Force Output Compare Action for Channel 0 
    byte FOC1        1;                                        Force Output Compare Action for Channel 1 
    byte FOC2        1;                                        Force Output Compare Action for Channel 2 
    byte FOC3        1;                                        Force Output Compare Action for Channel 3 
    byte FOC4        1;                                        Force Output Compare Action for Channel 4 
    byte FOC5        1;                                        Force Output Compare Action for Channel 5 
    byte FOC6        1;                                        Force Output Compare Action for Channel 6 
    byte FOC7        1;                                        Force Output Compare Action for Channel 7 
  } Bits;
} CFORCSTR;
extern volatile CFORCSTR _CFORC @(REG_BASE + 0x00000041);
#define CFORC                           _CFORC.Byte
#define CFORC_FOC0                      _CFORC.Bits.FOC0
#define CFORC_FOC1                      _CFORC.Bits.FOC1
#define CFORC_FOC2                      _CFORC.Bits.FOC2
#define CFORC_FOC3                      _CFORC.Bits.FOC3
#define CFORC_FOC4                      _CFORC.Bits.FOC4
#define CFORC_FOC5                      _CFORC.Bits.FOC5
#define CFORC_FOC6                      _CFORC.Bits.FOC6
#define CFORC_FOC7                      _CFORC.Bits.FOC7

#define CFORC_FOC0_MASK                 1
#define CFORC_FOC1_MASK                 2
#define CFORC_FOC2_MASK                 4
#define CFORC_FOC3_MASK                 8
#define CFORC_FOC4_MASK                 16
#define CFORC_FOC5_MASK                 32
#define CFORC_FOC6_MASK                 64
#define CFORC_FOC7_MASK                 128


 OC7M - Output Compare 7 Mask Register; 0x00000042 
typedef union {
  byte Byte;
  struct {
    byte OC7M0       1;                                        Output Compare 7 Mask Bit 0 
    byte OC7M1       1;                                        Output Compare 7 Mask Bit 1 
    byte OC7M2       1;                                        Output Compare 7 Mask Bit 2 
    byte OC7M3       1;                                        Output Compare 7 Mask Bit 3 
    byte OC7M4       1;                                        Output Compare 7 Mask Bit 4 
    byte OC7M5       1;                                        Output Compare 7 Mask Bit 5 
    byte OC7M6       1;                                        Output Compare 7 Mask Bit 6 
    byte OC7M7       1;                                        Output Compare 7 Mask Bit 7 
  } Bits;
} OC7MSTR;
extern volatile OC7MSTR _OC7M @(REG_BASE + 0x00000042);
#define OC7M                            _OC7M.Byte
#define OC7M_OC7M0                      _OC7M.Bits.OC7M0
#define OC7M_OC7M1                      _OC7M.Bits.OC7M1
#define OC7M_OC7M2                      _OC7M.Bits.OC7M2
#define OC7M_OC7M3                      _OC7M.Bits.OC7M3
#define OC7M_OC7M4                      _OC7M.Bits.OC7M4
#define OC7M_OC7M5                      _OC7M.Bits.OC7M5
#define OC7M_OC7M6                      _OC7M.Bits.OC7M6
#define OC7M_OC7M7                      _OC7M.Bits.OC7M7

#define OC7M_OC7M0_MASK                 1
#define OC7M_OC7M1_MASK                 2
#define OC7M_OC7M2_MASK                 4
#define OC7M_OC7M3_MASK                 8
#define OC7M_OC7M4_MASK                 16
#define OC7M_OC7M5_MASK                 32
#define OC7M_OC7M6_MASK                 64
#define OC7M_OC7M7_MASK                 128


 OC7D - Output Compare 7 Data Register; 0x00000043 
typedef union {
  byte Byte;
} OC7DSTR;
extern volatile OC7DSTR _OC7D @(REG_BASE + 0x00000043);
#define OC7D                            _OC7D.Byte



 TCNT - Timer Count Register; 0x00000044 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TCNTHi - Timer Count Register High; 0x00000044 
    union {
      byte Byte;
    } TCNTHiSTR;
    #define TCNTHi                      _TCNT.Overlap_STR.TCNTHiSTR.Byte
    
    


     TCNTLo - Timer Count Register Low; 0x00000045 
    union {
      byte Byte;
    } TCNTLoSTR;
    #define TCNTLo                      _TCNT.Overlap_STR.TCNTLoSTR.Byte
    
    

  } Overlap_STR;

} TCNTSTR;
extern volatile TCNTSTR _TCNT @(REG_BASE + 0x00000044);
#define TCNT                            _TCNT.Word



 TSCR1 - Timer System Control Register1; 0x00000046 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte PRNT        1;                                        Precision Timer 
    byte TFFCA       1;                                        Timer Fast Flag Clear All 
    byte TSFRZ       1;                                        Timer and Modulus Counter Stop While in Freeze Mode 
    byte TSWAI       1;                                        Timer Module Stops While in Wait 
    byte TEN         1;                                        Timer Enable 
  } Bits;
} TSCR1STR;
extern volatile TSCR1STR _TSCR1 @(REG_BASE + 0x00000046);
#define TSCR1                           _TSCR1.Byte
#define TSCR1_PRNT                      _TSCR1.Bits.PRNT
#define TSCR1_TFFCA                     _TSCR1.Bits.TFFCA
#define TSCR1_TSFRZ                     _TSCR1.Bits.TSFRZ
#define TSCR1_TSWAI                     _TSCR1.Bits.TSWAI
#define TSCR1_TEN                       _TSCR1.Bits.TEN

#define TSCR1_PRNT_MASK                 8
#define TSCR1_TFFCA_MASK                16
#define TSCR1_TSFRZ_MASK                32
#define TSCR1_TSWAI_MASK                64
#define TSCR1_TEN_MASK                  128


 TTOV - Timer Toggle On Overflow Register; 0x00000047 
typedef union {
  byte Byte;
  struct {
    byte TOV0        1;                                        Toggle On Overflow Bit 0 
    byte TOV1        1;                                        Toggle On Overflow Bit 1 
    byte TOV2        1;                                        Toggle On Overflow Bit 2 
    byte TOV3        1;                                        Toggle On Overflow Bit 3 
    byte TOV4        1;                                        Toggle On Overflow Bit 4 
    byte TOV5        1;                                        Toggle On Overflow Bit 5 
    byte TOV6        1;                                        Toggle On Overflow Bit 6 
    byte TOV7        1;                                        Toggle On Overflow Bit 7 
  } Bits;
} TTOVSTR;
extern volatile TTOVSTR _TTOV @(REG_BASE + 0x00000047);
#define TTOV                            _TTOV.Byte
#define TTOV_TOV0                       _TTOV.Bits.TOV0
#define TTOV_TOV1                       _TTOV.Bits.TOV1
#define TTOV_TOV2                       _TTOV.Bits.TOV2
#define TTOV_TOV3                       _TTOV.Bits.TOV3
#define TTOV_TOV4                       _TTOV.Bits.TOV4
#define TTOV_TOV5                       _TTOV.Bits.TOV5
#define TTOV_TOV6                       _TTOV.Bits.TOV6
#define TTOV_TOV7                       _TTOV.Bits.TOV7

#define TTOV_TOV0_MASK                  1
#define TTOV_TOV1_MASK                  2
#define TTOV_TOV2_MASK                  4
#define TTOV_TOV3_MASK                  8
#define TTOV_TOV4_MASK                  16
#define TTOV_TOV5_MASK                  32
#define TTOV_TOV6_MASK                  64
#define TTOV_TOV7_MASK                  128


 TCTL1 - Timer Control Register 1; 0x00000048 
typedef union {
  byte Byte;
  struct {
    byte OL4         1;                                        Output Level Bit 4 
    byte OM4         1;                                        Output Mode Bit 4 
    byte OL5         1;                                        Output Level Bit 5 
    byte OM5         1;                                        Output Mode Bit 5 
    byte OL6         1;                                        Output Level Bit 6 
    byte OM6         1;                                        Output Mode Bit 6 
    byte OL7         1;                                        Output Level Bit 7 
    byte OM7         1;                                        Output Mode Bit 7 
  } Bits;
} TCTL1STR;
extern volatile TCTL1STR _TCTL1 @(REG_BASE + 0x00000048);
#define TCTL1                           _TCTL1.Byte
#define TCTL1_OL4                       _TCTL1.Bits.OL4
#define TCTL1_OM4                       _TCTL1.Bits.OM4
#define TCTL1_OL5                       _TCTL1.Bits.OL5
#define TCTL1_OM5                       _TCTL1.Bits.OM5
#define TCTL1_OL6                       _TCTL1.Bits.OL6
#define TCTL1_OM6                       _TCTL1.Bits.OM6
#define TCTL1_OL7                       _TCTL1.Bits.OL7
#define TCTL1_OM7                       _TCTL1.Bits.OM7

#define TCTL1_OL4_MASK                  1
#define TCTL1_OM4_MASK                  2
#define TCTL1_OL5_MASK                  4
#define TCTL1_OM5_MASK                  8
#define TCTL1_OL6_MASK                  16
#define TCTL1_OM6_MASK                  32
#define TCTL1_OL7_MASK                  64
#define TCTL1_OM7_MASK                  128


 TCTL2 - Timer Control Register 2; 0x00000049 
typedef union {
  byte Byte;
  struct {
    byte OL0         1;                                        Output Level Bit 0 
    byte OM0         1;                                        Output Mode Bit 0 
    byte OL1         1;                                        Output Level Bit 1 
    byte OM1         1;                                        Output Mode Bit 1 
    byte OL2         1;                                        Output Level Bit 2 
    byte OM2         1;                                        Output Mode Bit 2 
    byte OL3         1;                                        Output Level Bit 3 
    byte OM3         1;                                        Output Mode Bit 3 
  } Bits;
} TCTL2STR;
extern volatile TCTL2STR _TCTL2 @(REG_BASE + 0x00000049);
#define TCTL2                           _TCTL2.Byte
#define TCTL2_OL0                       _TCTL2.Bits.OL0
#define TCTL2_OM0                       _TCTL2.Bits.OM0
#define TCTL2_OL1                       _TCTL2.Bits.OL1
#define TCTL2_OM1                       _TCTL2.Bits.OM1
#define TCTL2_OL2                       _TCTL2.Bits.OL2
#define TCTL2_OM2                       _TCTL2.Bits.OM2
#define TCTL2_OL3                       _TCTL2.Bits.OL3
#define TCTL2_OM3                       _TCTL2.Bits.OM3

#define TCTL2_OL0_MASK                  1
#define TCTL2_OM0_MASK                  2
#define TCTL2_OL1_MASK                  4
#define TCTL2_OM1_MASK                  8
#define TCTL2_OL2_MASK                  16
#define TCTL2_OM2_MASK                  32
#define TCTL2_OL3_MASK                  64
#define TCTL2_OM3_MASK                  128


 TCTL3 - Timer Control Register 3; 0x0000004A 
typedef union {
  byte Byte;
  struct {
    byte EDG4A       1;                                        Input Capture Edge Control 4A 
    byte EDG4B       1;                                        Input Capture Edge Control 4B 
    byte EDG5A       1;                                        Input Capture Edge Control 5A 
    byte EDG5B       1;                                        Input Capture Edge Control 5B 
    byte EDG6A       1;                                        Input Capture Edge Control 6A 
    byte EDG6B       1;                                        Input Capture Edge Control 6B 
    byte EDG7A       1;                                        Input Capture Edge Control 7A 
    byte EDG7B       1;                                        Input Capture Edge Control 7B 
  } Bits;
  struct {
    byte grpEDG4x 2;
    byte grpEDG5x 2;
    byte grpEDG6x 2;
    byte grpEDG7x 2;
  } MergedBits;
} TCTL3STR;
extern volatile TCTL3STR _TCTL3 @(REG_BASE + 0x0000004A);
#define TCTL3                           _TCTL3.Byte
#define TCTL3_EDG4A                     _TCTL3.Bits.EDG4A
#define TCTL3_EDG4B                     _TCTL3.Bits.EDG4B
#define TCTL3_EDG5A                     _TCTL3.Bits.EDG5A
#define TCTL3_EDG5B                     _TCTL3.Bits.EDG5B
#define TCTL3_EDG6A                     _TCTL3.Bits.EDG6A
#define TCTL3_EDG6B                     _TCTL3.Bits.EDG6B
#define TCTL3_EDG7A                     _TCTL3.Bits.EDG7A
#define TCTL3_EDG7B                     _TCTL3.Bits.EDG7B
#define TCTL3_EDG4x                     _TCTL3.MergedBits.grpEDG4x
#define TCTL3_EDG5x                     _TCTL3.MergedBits.grpEDG5x
#define TCTL3_EDG6x                     _TCTL3.MergedBits.grpEDG6x
#define TCTL3_EDG7x                     _TCTL3.MergedBits.grpEDG7x

#define TCTL3_EDG4A_MASK                1
#define TCTL3_EDG4B_MASK                2
#define TCTL3_EDG5A_MASK                4
#define TCTL3_EDG5B_MASK                8
#define TCTL3_EDG6A_MASK                16
#define TCTL3_EDG6B_MASK                32
#define TCTL3_EDG7A_MASK                64
#define TCTL3_EDG7B_MASK                128
#define TCTL3_EDG4x_MASK                3
#define TCTL3_EDG4x_BITNUM              0
#define TCTL3_EDG5x_MASK                12
#define TCTL3_EDG5x_BITNUM              2
#define TCTL3_EDG6x_MASK                48
#define TCTL3_EDG6x_BITNUM              4
#define TCTL3_EDG7x_MASK                192
#define TCTL3_EDG7x_BITNUM              6


 TCTL4 - Timer Control Register 4; 0x0000004B 
typedef union {
  byte Byte;
  struct {
    byte EDG0A       1;                                        Input Capture Edge Control 0A 
    byte EDG0B       1;                                        Input Capture Edge Control 0B 
    byte EDG1A       1;                                        Input Capture Edge Control 1A 
    byte EDG1B       1;                                        Input Capture Edge Control 1B 
    byte EDG2A       1;                                        Input Capture Edge Control 2A 
    byte EDG2B       1;                                        Input Capture Edge Control 2B 
    byte EDG3A       1;                                        Input Capture Edge Control 3A 
    byte EDG3B       1;                                        Input Capture Edge Control 3B 
  } Bits;
  struct {
    byte grpEDG0x 2;
    byte grpEDG1x 2;
    byte grpEDG2x 2;
    byte grpEDG3x 2;
  } MergedBits;
} TCTL4STR;
extern volatile TCTL4STR _TCTL4 @(REG_BASE + 0x0000004B);
#define TCTL4                           _TCTL4.Byte
#define TCTL4_EDG0A                     _TCTL4.Bits.EDG0A
#define TCTL4_EDG0B                     _TCTL4.Bits.EDG0B
#define TCTL4_EDG1A                     _TCTL4.Bits.EDG1A
#define TCTL4_EDG1B                     _TCTL4.Bits.EDG1B
#define TCTL4_EDG2A                     _TCTL4.Bits.EDG2A
#define TCTL4_EDG2B                     _TCTL4.Bits.EDG2B
#define TCTL4_EDG3A                     _TCTL4.Bits.EDG3A
#define TCTL4_EDG3B                     _TCTL4.Bits.EDG3B
#define TCTL4_EDG0x                     _TCTL4.MergedBits.grpEDG0x
#define TCTL4_EDG1x                     _TCTL4.MergedBits.grpEDG1x
#define TCTL4_EDG2x                     _TCTL4.MergedBits.grpEDG2x
#define TCTL4_EDG3x                     _TCTL4.MergedBits.grpEDG3x

#define TCTL4_EDG0A_MASK                1
#define TCTL4_EDG0B_MASK                2
#define TCTL4_EDG1A_MASK                4
#define TCTL4_EDG1B_MASK                8
#define TCTL4_EDG2A_MASK                16
#define TCTL4_EDG2B_MASK                32
#define TCTL4_EDG3A_MASK                64
#define TCTL4_EDG3B_MASK                128
#define TCTL4_EDG0x_MASK                3
#define TCTL4_EDG0x_BITNUM              0
#define TCTL4_EDG1x_MASK                12
#define TCTL4_EDG1x_BITNUM              2
#define TCTL4_EDG2x_MASK                48
#define TCTL4_EDG2x_BITNUM              4
#define TCTL4_EDG3x_MASK                192
#define TCTL4_EDG3x_BITNUM              6


 TIE - Timer Interrupt Enable Register; 0x0000004C 
typedef union {
  byte Byte;
  struct {
    byte C0I         1;                                        Input CaptureOutput Compare Interrupt Enable Bit 0 
    byte C1I         1;                                        Input CaptureOutput Compare Interrupt Enable Bit 1 
    byte C2I         1;                                        Input CaptureOutput Compare Interrupt Enable Bit 2 
    byte C3I         1;                                        Input CaptureOutput Compare Interrupt Enable Bit 3 
    byte C4I         1;                                        Input CaptureOutput Compare Interrupt Enable Bit 4 
    byte C5I         1;                                        Input CaptureOutput Compare Interrupt Enable Bit 5 
    byte C6I         1;                                        Input CaptureOutput Compare Interrupt Enable Bit 6 
    byte C7I         1;                                        Input CaptureOutput Compare Interrupt Enable Bit 7 
  } Bits;
} TIESTR;
extern volatile TIESTR _TIE @(REG_BASE + 0x0000004C);
#define TIE                             _TIE.Byte
#define TIE_C0I                         _TIE.Bits.C0I
#define TIE_C1I                         _TIE.Bits.C1I
#define TIE_C2I                         _TIE.Bits.C2I
#define TIE_C3I                         _TIE.Bits.C3I
#define TIE_C4I                         _TIE.Bits.C4I
#define TIE_C5I                         _TIE.Bits.C5I
#define TIE_C6I                         _TIE.Bits.C6I
#define TIE_C7I                         _TIE.Bits.C7I

#define TIE_C0I_MASK                    1
#define TIE_C1I_MASK                    2
#define TIE_C2I_MASK                    4
#define TIE_C3I_MASK                    8
#define TIE_C4I_MASK                    16
#define TIE_C5I_MASK                    32
#define TIE_C6I_MASK                    64
#define TIE_C7I_MASK                    128


 TSCR2 - Timer System Control Register 2; 0x0000004D 
typedef union {
  byte Byte;
  struct {
    byte PR0         1;                                        Timer Prescaler Select Bit 0 
    byte PR1         1;                                        Timer Prescaler Select Bit 1 
    byte PR2         1;                                        Timer Prescaler Select Bit 2 
    byte TCRE        1;                                        Timer Counter Reset Enable 
    byte             1; 
    byte             1; 
    byte             1; 
    byte TOI         1;                                        Timer Overflow Interrupt Enable 
  } Bits;
  struct {
    byte grpPR   3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} TSCR2STR;
extern volatile TSCR2STR _TSCR2 @(REG_BASE + 0x0000004D);
#define TSCR2                           _TSCR2.Byte
#define TSCR2_PR0                       _TSCR2.Bits.PR0
#define TSCR2_PR1                       _TSCR2.Bits.PR1
#define TSCR2_PR2                       _TSCR2.Bits.PR2
#define TSCR2_TCRE                      _TSCR2.Bits.TCRE
#define TSCR2_TOI                       _TSCR2.Bits.TOI
#define TSCR2_PR                        _TSCR2.MergedBits.grpPR

#define TSCR2_PR0_MASK                  1
#define TSCR2_PR1_MASK                  2
#define TSCR2_PR2_MASK                  4
#define TSCR2_TCRE_MASK                 8
#define TSCR2_TOI_MASK                  128
#define TSCR2_PR_MASK                   7
#define TSCR2_PR_BITNUM                 0


 TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E 
typedef union {
  byte Byte;
  struct {
    byte C0F         1;                                        Input CaptureOutput Compare Channel Flag 0 
    byte C1F         1;                                        Input CaptureOutput Compare Channel Flag 1 
    byte C2F         1;                                        Input CaptureOutput Compare Channel Flag 2 
    byte C3F         1;                                        Input CaptureOutput Compare Channel Flag 3 
    byte C4F         1;                                        Input CaptureOutput Compare Channel Flag 4 
    byte C5F         1;                                        Input CaptureOutput Compare Channel Flag 5 
    byte C6F         1;                                        Input CaptureOutput Compare Channel Flag 6 
    byte C7F         1;                                        Input CaptureOutput Compare Channel Flag 7 
  } Bits;
} TFLG1STR;
extern volatile TFLG1STR _TFLG1 @(REG_BASE + 0x0000004E);
#define TFLG1                           _TFLG1.Byte
#define TFLG1_C0F                       _TFLG1.Bits.C0F
#define TFLG1_C1F                       _TFLG1.Bits.C1F
#define TFLG1_C2F                       _TFLG1.Bits.C2F
#define TFLG1_C3F                       _TFLG1.Bits.C3F
#define TFLG1_C4F                       _TFLG1.Bits.C4F
#define TFLG1_C5F                       _TFLG1.Bits.C5F
#define TFLG1_C6F                       _TFLG1.Bits.C6F
#define TFLG1_C7F                       _TFLG1.Bits.C7F

#define TFLG1_C0F_MASK                  1
#define TFLG1_C1F_MASK                  2
#define TFLG1_C2F_MASK                  4
#define TFLG1_C3F_MASK                  8
#define TFLG1_C4F_MASK                  16
#define TFLG1_C5F_MASK                  32
#define TFLG1_C6F_MASK                  64
#define TFLG1_C7F_MASK                  128


 TFLG2 - Main Timer Interrupt Flag 2; 0x0000004F 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte TOF         1;                                        Timer Overflow Flag 
  } Bits;
} TFLG2STR;
extern volatile TFLG2STR _TFLG2 @(REG_BASE + 0x0000004F);
#define TFLG2                           _TFLG2.Byte
#define TFLG2_TOF                       _TFLG2.Bits.TOF

#define TFLG2_TOF_MASK                  128


 TC0 - Timer Input CaptureOutput Compare Register 0; 0x00000050 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC0Hi - Timer Input CaptureOutput Compare Register 0 High; 0x00000050 
    union {
      byte Byte;
    } TC0HiSTR;
    #define TC0Hi                       _TC0.Overlap_STR.TC0HiSTR.Byte
    
    


     TC0Lo - Timer Input CaptureOutput Compare Register 0 Low; 0x00000051 
    union {
      byte Byte;
    } TC0LoSTR;
    #define TC0Lo                       _TC0.Overlap_STR.TC0LoSTR.Byte
    
    

  } Overlap_STR;

} TC0STR;
extern volatile TC0STR _TC0 @(REG_BASE + 0x00000050);
#define TC0                             _TC0.Word
 TC_ARR Access 8 TCx registers in an array 
#define TC_ARR                          ((volatile word ) &TC0)



 TC1 - Timer Input CaptureOutput Compare Register 1; 0x00000052 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC1Hi - Timer Input CaptureOutput Compare Register 1 High; 0x00000052 
    union {
      byte Byte;
    } TC1HiSTR;
    #define TC1Hi                       _TC1.Overlap_STR.TC1HiSTR.Byte
    
    


     TC1Lo - Timer Input CaptureOutput Compare Register 1 Low; 0x00000053 
    union {
      byte Byte;
    } TC1LoSTR;
    #define TC1Lo                       _TC1.Overlap_STR.TC1LoSTR.Byte
    
    

  } Overlap_STR;

} TC1STR;
extern volatile TC1STR _TC1 @(REG_BASE + 0x00000052);
#define TC1                             _TC1.Word



 TC2 - Timer Input CaptureOutput Compare Register 2; 0x00000054 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC2Hi - Timer Input CaptureOutput Compare Register 2 High; 0x00000054 
    union {
      byte Byte;
    } TC2HiSTR;
    #define TC2Hi                       _TC2.Overlap_STR.TC2HiSTR.Byte
    
    


     TC2Lo - Timer Input CaptureOutput Compare Register 2 Low; 0x00000055 
    union {
      byte Byte;
    } TC2LoSTR;
    #define TC2Lo                       _TC2.Overlap_STR.TC2LoSTR.Byte
    
    

  } Overlap_STR;

} TC2STR;
extern volatile TC2STR _TC2 @(REG_BASE + 0x00000054);
#define TC2                             _TC2.Word



 TC3 - Timer Input CaptureOutput Compare Register 3; 0x00000056 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC3Hi - Timer Input CaptureOutput Compare Register 3 High; 0x00000056 
    union {
      byte Byte;
    } TC3HiSTR;
    #define TC3Hi                       _TC3.Overlap_STR.TC3HiSTR.Byte
    
    


     TC3Lo - Timer Input CaptureOutput Compare Register 3 Low; 0x00000057 
    union {
      byte Byte;
    } TC3LoSTR;
    #define TC3Lo                       _TC3.Overlap_STR.TC3LoSTR.Byte
    
    

  } Overlap_STR;

} TC3STR;
extern volatile TC3STR _TC3 @(REG_BASE + 0x00000056);
#define TC3                             _TC3.Word



 TC4 - Timer Input CaptureOutput Compare Register 4; 0x00000058 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC4Hi - Timer Input CaptureOutput Compare Register 4 High; 0x00000058 
    union {
      byte Byte;
    } TC4HiSTR;
    #define TC4Hi                       _TC4.Overlap_STR.TC4HiSTR.Byte
    
    


     TC4Lo - Timer Input CaptureOutput Compare Register 4 Low; 0x00000059 
    union {
      byte Byte;
    } TC4LoSTR;
    #define TC4Lo                       _TC4.Overlap_STR.TC4LoSTR.Byte
    
    

  } Overlap_STR;

} TC4STR;
extern volatile TC4STR _TC4 @(REG_BASE + 0x00000058);
#define TC4                             _TC4.Word



 TC5 - Timer Input CaptureOutput Compare Register 5; 0x0000005A 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC5Hi - Timer Input CaptureOutput Compare Register 5 High; 0x0000005A 
    union {
      byte Byte;
    } TC5HiSTR;
    #define TC5Hi                       _TC5.Overlap_STR.TC5HiSTR.Byte
    
    


     TC5Lo - Timer Input CaptureOutput Compare Register 5 Low; 0x0000005B 
    union {
      byte Byte;
    } TC5LoSTR;
    #define TC5Lo                       _TC5.Overlap_STR.TC5LoSTR.Byte
    
    

  } Overlap_STR;

} TC5STR;
extern volatile TC5STR _TC5 @(REG_BASE + 0x0000005A);
#define TC5                             _TC5.Word



 TC6 - Timer Input CaptureOutput Compare Register 6; 0x0000005C 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC6Hi - Timer Input CaptureOutput Compare Register 6 High; 0x0000005C 
    union {
      byte Byte;
    } TC6HiSTR;
    #define TC6Hi                       _TC6.Overlap_STR.TC6HiSTR.Byte
    
    


     TC6Lo - Timer Input CaptureOutput Compare Register 6 Low; 0x0000005D 
    union {
      byte Byte;
    } TC6LoSTR;
    #define TC6Lo                       _TC6.Overlap_STR.TC6LoSTR.Byte
    
    

  } Overlap_STR;

} TC6STR;
extern volatile TC6STR _TC6 @(REG_BASE + 0x0000005C);
#define TC6                             _TC6.Word



 TC7 - Timer Input CaptureOutput Compare Register 7; 0x0000005E 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC7Hi - Timer Input CaptureOutput Compare Register 7 High; 0x0000005E 
    union {
      byte Byte;
    } TC7HiSTR;
    #define TC7Hi                       _TC7.Overlap_STR.TC7HiSTR.Byte
    
    


     TC7Lo - Timer Input CaptureOutput Compare Register 7 Low; 0x0000005F 
    union {
      byte Byte;
    } TC7LoSTR;
    #define TC7Lo                       _TC7.Overlap_STR.TC7LoSTR.Byte
    
    

  } Overlap_STR;

} TC7STR;
extern volatile TC7STR _TC7 @(REG_BASE + 0x0000005E);
#define TC7                             _TC7.Word



 PACTL - 16-Bit Pulse Accumulator A Control Register; 0x00000060 
typedef union {
  byte Byte;
  struct {
    byte PAI         1;                                        Pulse Accumulator Input Interrupt enable 
    byte PAOVI       1;                                        Pulse Accumulator A Overflow Interrupt enable 
    byte CLK0        1;                                        Clock Select Bit 0 
    byte CLK1        1;                                        Clock Select Bit 1 
    byte PEDGE       1;                                        Pulse Accumulator Edge Control 
    byte PAMOD       1;                                        Pulse Accumulator Mode 
    byte PAEN        1;                                        Pulse Accumulator A System Enable 
    byte             1; 
  } Bits;
  struct {
    byte         1;
    byte         1;
    byte grpCLK  2;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} PACTLSTR;
extern volatile PACTLSTR _PACTL @(REG_BASE + 0x00000060);
#define PACTL                           _PACTL.Byte
#define PACTL_PAI                       _PACTL.Bits.PAI
#define PACTL_PAOVI                     _PACTL.Bits.PAOVI
#define PACTL_CLK0                      _PACTL.Bits.CLK0
#define PACTL_CLK1                      _PACTL.Bits.CLK1
#define PACTL_PEDGE                     _PACTL.Bits.PEDGE
#define PACTL_PAMOD                     _PACTL.Bits.PAMOD
#define PACTL_PAEN                      _PACTL.Bits.PAEN
#define PACTL_CLK                       _PACTL.MergedBits.grpCLK

#define PACTL_PAI_MASK                  1
#define PACTL_PAOVI_MASK                2
#define PACTL_CLK0_MASK                 4
#define PACTL_CLK1_MASK                 8
#define PACTL_PEDGE_MASK                16
#define PACTL_PAMOD_MASK                32
#define PACTL_PAEN_MASK                 64
#define PACTL_CLK_MASK                  12
#define PACTL_CLK_BITNUM                2


 PAFLG - Pulse Accumulator A Flag Register; 0x00000061 
typedef union {
  byte Byte;
  struct {
    byte PAIF        1;                                        Pulse Accumulator Input edge Flag 
    byte PAOVF       1;                                        Pulse Accumulator A Overflow Flag 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} PAFLGSTR;
extern volatile PAFLGSTR _PAFLG @(REG_BASE + 0x00000061);
#define PAFLG                           _PAFLG.Byte
#define PAFLG_PAIF                      _PAFLG.Bits.PAIF
#define PAFLG_PAOVF                     _PAFLG.Bits.PAOVF

#define PAFLG_PAIF_MASK                 1
#define PAFLG_PAOVF_MASK                2


 PACN32 - Pulse Accumulators Count 32 Register; 0x00000062 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PACN3 - Pulse Accumulators Count 3 Register; 0x00000062 
    union {
      byte Byte;
    } PACN3STR;
    #define PACN3                       _PACN32.Overlap_STR.PACN3STR.Byte
    
    


     PACN2 - Pulse Accumulators Count 2 Register; 0x00000063 
    union {
      byte Byte;
    } PACN2STR;
    #define PACN2                       _PACN32.Overlap_STR.PACN2STR.Byte
    
    

  } Overlap_STR;

} PACN32STR;
extern volatile PACN32STR _PACN32 @(REG_BASE + 0x00000062);
#define PACN32                          _PACN32.Word



 PACN10 - Pulse Accumulators Count 10 Register; 0x00000064 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PACN1 - Pulse Accumulators Count 1 Register; 0x00000064 
    union {
      byte Byte;
    } PACN1STR;
    #define PACN1                       _PACN10.Overlap_STR.PACN1STR.Byte
    
    


     PACN0 - Pulse Accumulators Count 0 Register; 0x00000065 
    union {
      byte Byte;
    } PACN0STR;
    #define PACN0                       _PACN10.Overlap_STR.PACN0STR.Byte
    
    

  } Overlap_STR;

} PACN10STR;
extern volatile PACN10STR _PACN10 @(REG_BASE + 0x00000064);
#define PACN10                          _PACN10.Word



 MCCTL - Modulus Down Counter underflow; 0x00000066 
typedef union {
  byte Byte;
  struct {
    byte MCPR0       1;                                        Modulus Counter Prescaler select 0 
    byte MCPR1       1;                                        Modulus Counter Prescaler select 1 
    byte MCEN        1;                                        Modulus Down-Counter Enable 
    byte FLMC        1;                                        Force Load Register into the Modulus Counter Count Register 
    byte ICLAT       1;                                        Input Capture Force Latch Action 
    byte RDMCL       1;                                        Read Modulus Down-Counter Load 
    byte MODMC       1;                                        Modulus Mode Enable 
    byte MCZI        1;                                        Modulus Counter Underflow Interrupt Enable 
  } Bits;
  struct {
    byte grpMCPR 2;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} MCCTLSTR;
extern volatile MCCTLSTR _MCCTL @(REG_BASE + 0x00000066);
#define MCCTL                           _MCCTL.Byte
#define MCCTL_MCPR0                     _MCCTL.Bits.MCPR0
#define MCCTL_MCPR1                     _MCCTL.Bits.MCPR1
#define MCCTL_MCEN                      _MCCTL.Bits.MCEN
#define MCCTL_FLMC                      _MCCTL.Bits.FLMC
#define MCCTL_ICLAT                     _MCCTL.Bits.ICLAT
#define MCCTL_RDMCL                     _MCCTL.Bits.RDMCL
#define MCCTL_MODMC                     _MCCTL.Bits.MODMC
#define MCCTL_MCZI                      _MCCTL.Bits.MCZI
#define MCCTL_MCPR                      _MCCTL.MergedBits.grpMCPR

#define MCCTL_MCPR0_MASK                1
#define MCCTL_MCPR1_MASK                2
#define MCCTL_MCEN_MASK                 4
#define MCCTL_FLMC_MASK                 8
#define MCCTL_ICLAT_MASK                16
#define MCCTL_RDMCL_MASK                32
#define MCCTL_MODMC_MASK                64
#define MCCTL_MCZI_MASK                 128
#define MCCTL_MCPR_MASK                 3
#define MCCTL_MCPR_BITNUM               0


 MCFLG - 16-Bit Modulus Down Counter Flag Register; 0x00000067 
typedef union {
  byte Byte;
  struct {
    byte POLF0       1;                                        First Input Capture Polarity Status 0 
    byte POLF1       1;                                        First Input Capture Polarity Status 1 
    byte POLF2       1;                                        First Input Capture Polarity Status 2 
    byte POLF3       1;                                        First Input Capture Polarity Status 3 
    byte             1; 
    byte             1; 
    byte             1; 
    byte MCZF        1;                                        Modulus Counter Underflow Flag 
  } Bits;
  struct {
    byte grpPOLF 4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} MCFLGSTR;
extern volatile MCFLGSTR _MCFLG @(REG_BASE + 0x00000067);
#define MCFLG                           _MCFLG.Byte
#define MCFLG_POLF0                     _MCFLG.Bits.POLF0
#define MCFLG_POLF1                     _MCFLG.Bits.POLF1
#define MCFLG_POLF2                     _MCFLG.Bits.POLF2
#define MCFLG_POLF3                     _MCFLG.Bits.POLF3
#define MCFLG_MCZF                      _MCFLG.Bits.MCZF
#define MCFLG_POLF                      _MCFLG.MergedBits.grpPOLF

#define MCFLG_POLF0_MASK                1
#define MCFLG_POLF1_MASK                2
#define MCFLG_POLF2_MASK                4
#define MCFLG_POLF3_MASK                8
#define MCFLG_MCZF_MASK                 128
#define MCFLG_POLF_MASK                 15
#define MCFLG_POLF_BITNUM               0


 ICPAR - Input Control Pulse Accumulator Register; 0x00000068 
typedef union {
  byte Byte;
  struct {
    byte PA0EN       1;                                        8-Bit Pulse Accumulator 0 Enable 
    byte PA1EN       1;                                        8-Bit Pulse Accumulator 1 Enable 
    byte PA2EN       1;                                        8-Bit Pulse Accumulator 2 Enable 
    byte PA3EN       1;                                        8-Bit Pulse Accumulator 3 Enable 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} ICPARSTR;
extern volatile ICPARSTR _ICPAR @(REG_BASE + 0x00000068);
#define ICPAR                           _ICPAR.Byte
#define ICPAR_PA0EN                     _ICPAR.Bits.PA0EN
#define ICPAR_PA1EN                     _ICPAR.Bits.PA1EN
#define ICPAR_PA2EN                     _ICPAR.Bits.PA2EN
#define ICPAR_PA3EN                     _ICPAR.Bits.PA3EN

#define ICPAR_PA0EN_MASK                1
#define ICPAR_PA1EN_MASK                2
#define ICPAR_PA2EN_MASK                4
#define ICPAR_PA3EN_MASK                8


 DLYCT - Delay Counter Control Register; 0x00000069 
typedef union {
  byte Byte;
  struct {
    byte DLY0        1;                                        Delay Counter Select Bit 0 
    byte DLY1        1;                                        Delay Counter Select Bit 1 
    byte DLY2        1;                                        Delay Counter Select Bit 2 
    byte DLY3        1;                                        Delay Counter Select Bit 3 
    byte DLY4        1;                                        Delay Counter Select Bit 4 
    byte DLY5        1;                                        Delay Counter Select Bit 5 
    byte DLY6        1;                                        Delay Counter Select Bit 6 
    byte DLY7        1;                                        Delay Counter Select Bit 7 
  } Bits;
} DLYCTSTR;
extern volatile DLYCTSTR _DLYCT @(REG_BASE + 0x00000069);
#define DLYCT                           _DLYCT.Byte
#define DLYCT_DLY0                      _DLYCT.Bits.DLY0
#define DLYCT_DLY1                      _DLYCT.Bits.DLY1
#define DLYCT_DLY2                      _DLYCT.Bits.DLY2
#define DLYCT_DLY3                      _DLYCT.Bits.DLY3
#define DLYCT_DLY4                      _DLYCT.Bits.DLY4
#define DLYCT_DLY5                      _DLYCT.Bits.DLY5
#define DLYCT_DLY6                      _DLYCT.Bits.DLY6
#define DLYCT_DLY7                      _DLYCT.Bits.DLY7

#define DLYCT_DLY0_MASK                 1
#define DLYCT_DLY1_MASK                 2
#define DLYCT_DLY2_MASK                 4
#define DLYCT_DLY3_MASK                 8
#define DLYCT_DLY4_MASK                 16
#define DLYCT_DLY5_MASK                 32
#define DLYCT_DLY6_MASK                 64
#define DLYCT_DLY7_MASK                 128


 ICOVW - Input Control Overwrite Register; 0x0000006A 
typedef union {
  byte Byte;
  struct {
    byte NOVW0       1;                                        No Input Capture Overwrite 0 
    byte NOVW1       1;                                        No Input Capture Overwrite 1 
    byte NOVW2       1;                                        No Input Capture Overwrite 2 
    byte NOVW3       1;                                        No Input Capture Overwrite 3 
    byte NOVW4       1;                                        No Input Capture Overwrite 4 
    byte NOVW5       1;                                        No Input Capture Overwrite 5 
    byte NOVW6       1;                                        No Input Capture Overwrite 6 
    byte NOVW7       1;                                        No Input Capture Overwrite 7 
  } Bits;
} ICOVWSTR;
extern volatile ICOVWSTR _ICOVW @(REG_BASE + 0x0000006A);
#define ICOVW                           _ICOVW.Byte
#define ICOVW_NOVW0                     _ICOVW.Bits.NOVW0
#define ICOVW_NOVW1                     _ICOVW.Bits.NOVW1
#define ICOVW_NOVW2                     _ICOVW.Bits.NOVW2
#define ICOVW_NOVW3                     _ICOVW.Bits.NOVW3
#define ICOVW_NOVW4                     _ICOVW.Bits.NOVW4
#define ICOVW_NOVW5                     _ICOVW.Bits.NOVW5
#define ICOVW_NOVW6                     _ICOVW.Bits.NOVW6
#define ICOVW_NOVW7                     _ICOVW.Bits.NOVW7

#define ICOVW_NOVW0_MASK                1
#define ICOVW_NOVW1_MASK                2
#define ICOVW_NOVW2_MASK                4
#define ICOVW_NOVW3_MASK                8
#define ICOVW_NOVW4_MASK                16
#define ICOVW_NOVW5_MASK                32
#define ICOVW_NOVW6_MASK                64
#define ICOVW_NOVW7_MASK                128


 ICSYS - Input Control System Control Register; 0x0000006B 
typedef union {
  byte Byte;
  struct {
    byte LATQ        1;                                        Input Control Latch or Queue Mode Enable 
    byte BUFEN       1;                                        IC Buffer Enable 
    byte PACMX       1;                                        8-Bit Pulse Accumulators Maximum Count 
    byte TFMOD       1;                                        Timer Flag-setting Mode 
    byte SH04        1;                                        Share Input action of Input Capture Channels 0 and 4 
    byte SH15        1;                                        Share Input action of Input Capture Channels 1 and 5 
    byte SH26        1;                                        Share Input action of Input Capture Channels 2 and 6 
    byte SH37        1;                                        Share Input action of Input Capture Channels 3 and 7 
  } Bits;
} ICSYSSTR;
extern volatile ICSYSSTR _ICSYS @(REG_BASE + 0x0000006B);
#define ICSYS                           _ICSYS.Byte
#define ICSYS_LATQ                      _ICSYS.Bits.LATQ
#define ICSYS_BUFEN                     _ICSYS.Bits.BUFEN
#define ICSYS_PACMX                     _ICSYS.Bits.PACMX
#define ICSYS_TFMOD                     _ICSYS.Bits.TFMOD
#define ICSYS_SH04                      _ICSYS.Bits.SH04
#define ICSYS_SH15                      _ICSYS.Bits.SH15
#define ICSYS_SH26                      _ICSYS.Bits.SH26
#define ICSYS_SH37                      _ICSYS.Bits.SH37

#define ICSYS_LATQ_MASK                 1
#define ICSYS_BUFEN_MASK                2
#define ICSYS_PACMX_MASK                4
#define ICSYS_TFMOD_MASK                8
#define ICSYS_SH04_MASK                 16
#define ICSYS_SH15_MASK                 32
#define ICSYS_SH26_MASK                 64
#define ICSYS_SH37_MASK                 128


 PTPSR - Precision Timer Prescaler Select; 0x0000006E 
typedef union {
  byte Byte;
  struct {
    byte PTPS0       1;                                        Precision Timer Prescaler Select Bit 0 
    byte PTPS1       1;                                        Precision Timer Prescaler Select Bit 1 
    byte PTPS2       1;                                        Precision Timer Prescaler Select Bit 2 
    byte PTPS3       1;                                        Precision Timer Prescaler Select Bit 3 
    byte PTPS4       1;                                        Precision Timer Prescaler Select Bit 4 
    byte PTPS5       1;                                        Precision Timer Prescaler Select Bit 5 
    byte PTPS6       1;                                        Precision Timer Prescaler Select Bit 6 
    byte PTPS7       1;                                        Precision Timer Prescaler Select Bit 7 
  } Bits;
} PTPSRSTR;
extern volatile PTPSRSTR _PTPSR @(REG_BASE + 0x0000006E);
#define PTPSR                           _PTPSR.Byte
#define PTPSR_PTPS0                     _PTPSR.Bits.PTPS0
#define PTPSR_PTPS1                     _PTPSR.Bits.PTPS1
#define PTPSR_PTPS2                     _PTPSR.Bits.PTPS2
#define PTPSR_PTPS3                     _PTPSR.Bits.PTPS3
#define PTPSR_PTPS4                     _PTPSR.Bits.PTPS4
#define PTPSR_PTPS5                     _PTPSR.Bits.PTPS5
#define PTPSR_PTPS6                     _PTPSR.Bits.PTPS6
#define PTPSR_PTPS7                     _PTPSR.Bits.PTPS7

#define PTPSR_PTPS0_MASK                1
#define PTPSR_PTPS1_MASK                2
#define PTPSR_PTPS2_MASK                4
#define PTPSR_PTPS3_MASK                8
#define PTPSR_PTPS4_MASK                16
#define PTPSR_PTPS5_MASK                32
#define PTPSR_PTPS6_MASK                64
#define PTPSR_PTPS7_MASK                128


 PTMCPSR - Precision Timer Modulus Counter Prescaler Select Register; 0x0000006F 
typedef union {
  byte Byte;
  struct {
    byte PTMPS0      1;                                        Precision Timer Modulus Counter Prescaler Select bit 0 
    byte PTMPS1      1;                                        Precision Timer Modulus Counter Prescaler Select bit 1 
    byte PTMPS2      1;                                        Precision Timer Modulus Counter Prescaler Select bit 2 
    byte PTMPS3      1;                                        Precision Timer Modulus Counter Prescaler Select bit 3 
    byte PTMPS4      1;                                        Precision Timer Modulus Counter Prescaler Select bit 4 
    byte PTMPS5      1;                                        Precision Timer Modulus Counter Prescaler Select bit 5 
    byte PTMPS6      1;                                        Precision Timer Modulus Counter Prescaler Select bit 6 
    byte PTMPS7      1;                                        Precision Timer Modulus Counter Prescaler Select bit 7 
  } Bits;
} PTMCPSRSTR;
extern volatile PTMCPSRSTR _PTMCPSR @(REG_BASE + 0x0000006F);
#define PTMCPSR                         _PTMCPSR.Byte
#define PTMCPSR_PTMPS0                  _PTMCPSR.Bits.PTMPS0
#define PTMCPSR_PTMPS1                  _PTMCPSR.Bits.PTMPS1
#define PTMCPSR_PTMPS2                  _PTMCPSR.Bits.PTMPS2
#define PTMCPSR_PTMPS3                  _PTMCPSR.Bits.PTMPS3
#define PTMCPSR_PTMPS4                  _PTMCPSR.Bits.PTMPS4
#define PTMCPSR_PTMPS5                  _PTMCPSR.Bits.PTMPS5
#define PTMCPSR_PTMPS6                  _PTMCPSR.Bits.PTMPS6
#define PTMCPSR_PTMPS7                  _PTMCPSR.Bits.PTMPS7

#define PTMCPSR_PTMPS0_MASK             1
#define PTMCPSR_PTMPS1_MASK             2
#define PTMCPSR_PTMPS2_MASK             4
#define PTMCPSR_PTMPS3_MASK             8
#define PTMCPSR_PTMPS4_MASK             16
#define PTMCPSR_PTMPS5_MASK             32
#define PTMCPSR_PTMPS6_MASK             64
#define PTMCPSR_PTMPS7_MASK             128


 PBCTL - 16-Bit Pulse Accumulator B Control Register; 0x00000070 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte PBOVI       1;                                        Pulse Accumulator B Overflow Interrupt enable 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte PBEN        1;                                        Pulse Accumulator B System Enable 
    byte             1; 
  } Bits;
} PBCTLSTR;
extern volatile PBCTLSTR _PBCTL @(REG_BASE + 0x00000070);
#define PBCTL                           _PBCTL.Byte
#define PBCTL_PBOVI                     _PBCTL.Bits.PBOVI
#define PBCTL_PBEN                      _PBCTL.Bits.PBEN

#define PBCTL_PBOVI_MASK                2
#define PBCTL_PBEN_MASK                 64


 PBFLG - Pulse Accumulator B Flag Register; 0x00000071 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte PBOVF       1;                                        Pulse Accumulator B Overflow Flag 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} PBFLGSTR;
extern volatile PBFLGSTR _PBFLG @(REG_BASE + 0x00000071);
#define PBFLG                           _PBFLG.Byte
#define PBFLG_PBOVF                     _PBFLG.Bits.PBOVF

#define PBFLG_PBOVF_MASK                2


 PA32H - 8-Bit Pulse Accumulators Holding 32 Register; 0x00000072 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PA3H - 8-Bit Pulse Accumulators Holding 3 Register; 0x00000072 
    union {
      byte Byte;
      struct {
        byte BIT0        1;                                        Pulse Accumulator Bit 0 
        byte BIT1        1;                                        Pulse Accumulator Bit 1 
        byte BIT2        1;                                        Pulse Accumulator Bit 2 
        byte BIT3        1;                                        Pulse Accumulator Bit 3 
        byte BIT4        1;                                        Pulse Accumulator Bit 4 
        byte BIT5        1;                                        Pulse Accumulator Bit 5 
        byte BIT6        1;                                        Pulse Accumulator Bit 6 
        byte BIT7        1;                                        Pulse Accumulator Bit 7 
      } Bits;
    } PA3HSTR;
    #define PA3H                        _PA32H.Overlap_STR.PA3HSTR.Byte
    #define PA3H_BIT0                   _PA32H.Overlap_STR.PA3HSTR.Bits.BIT0
    #define PA3H_BIT1                   _PA32H.Overlap_STR.PA3HSTR.Bits.BIT1
    #define PA3H_BIT2                   _PA32H.Overlap_STR.PA3HSTR.Bits.BIT2
    #define PA3H_BIT3                   _PA32H.Overlap_STR.PA3HSTR.Bits.BIT3
    #define PA3H_BIT4                   _PA32H.Overlap_STR.PA3HSTR.Bits.BIT4
    #define PA3H_BIT5                   _PA32H.Overlap_STR.PA3HSTR.Bits.BIT5
    #define PA3H_BIT6                   _PA32H.Overlap_STR.PA3HSTR.Bits.BIT6
    #define PA3H_BIT7                   _PA32H.Overlap_STR.PA3HSTR.Bits.BIT7
    
    
    #define PA3H_BIT0_MASK              1
    #define PA3H_BIT1_MASK              2
    #define PA3H_BIT2_MASK              4
    #define PA3H_BIT3_MASK              8
    #define PA3H_BIT4_MASK              16
    #define PA3H_BIT5_MASK              32
    #define PA3H_BIT6_MASK              64
    #define PA3H_BIT7_MASK              128


     PA2H - 8-Bit Pulse Accumulators Holding 2 Register; 0x00000073 
    union {
      byte Byte;
      struct {
        byte BIT0        1;                                        Pulse Accumulator Bit 0 
        byte BIT1        1;                                        Pulse Accumulator Bit 1 
        byte BIT2        1;                                        Pulse Accumulator Bit 2 
        byte BIT3        1;                                        Pulse Accumulator Bit 3 
        byte BIT4        1;                                        Pulse Accumulator Bit 4 
        byte BIT5        1;                                        Pulse Accumulator Bit 5 
        byte BIT6        1;                                        Pulse Accumulator Bit 6 
        byte BIT7        1;                                        Pulse Accumulator Bit 7 
      } Bits;
    } PA2HSTR;
    #define PA2H                        _PA32H.Overlap_STR.PA2HSTR.Byte
    #define PA2H_BIT0                   _PA32H.Overlap_STR.PA2HSTR.Bits.BIT0
    #define PA2H_BIT1                   _PA32H.Overlap_STR.PA2HSTR.Bits.BIT1
    #define PA2H_BIT2                   _PA32H.Overlap_STR.PA2HSTR.Bits.BIT2
    #define PA2H_BIT3                   _PA32H.Overlap_STR.PA2HSTR.Bits.BIT3
    #define PA2H_BIT4                   _PA32H.Overlap_STR.PA2HSTR.Bits.BIT4
    #define PA2H_BIT5                   _PA32H.Overlap_STR.PA2HSTR.Bits.BIT5
    #define PA2H_BIT6                   _PA32H.Overlap_STR.PA2HSTR.Bits.BIT6
    #define PA2H_BIT7                   _PA32H.Overlap_STR.PA2HSTR.Bits.BIT7
    
    
    #define PA2H_BIT0_MASK              1
    #define PA2H_BIT1_MASK              2
    #define PA2H_BIT2_MASK              4
    #define PA2H_BIT3_MASK              8
    #define PA2H_BIT4_MASK              16
    #define PA2H_BIT5_MASK              32
    #define PA2H_BIT6_MASK              64
    #define PA2H_BIT7_MASK              128

  } Overlap_STR;

  struct {
    word BIT0        1;                                        Pulse Accumulator Bit 0 
    word BIT1        1;                                        Pulse Accumulator Bit 1 
    word BIT2        1;                                        Pulse Accumulator Bit 2 
    word BIT3        1;                                        Pulse Accumulator Bit 3 
    word BIT4        1;                                        Pulse Accumulator Bit 4 
    word BIT5        1;                                        Pulse Accumulator Bit 5 
    word BIT6        1;                                        Pulse Accumulator Bit 6 
    word BIT7        1;                                        Pulse Accumulator Bit 7 
    word BIT8        1;                                        Pulse Accumulator Bit 8 
    word BIT9        1;                                        Pulse Accumulator Bit 9 
    word BIT10       1;                                        Pulse Accumulator Bit 10 
    word BIT11       1;                                        Pulse Accumulator Bit 11 
    word BIT12       1;                                        Pulse Accumulator Bit 12 
    word BIT13       1;                                        Pulse Accumulator Bit 13 
    word BIT14       1;                                        Pulse Accumulator Bit 14 
    word BIT15       1;                                        Pulse Accumulator Bit 15 
  } Bits;
} PA32HSTR;
extern volatile PA32HSTR _PA32H @(REG_BASE + 0x00000072);
#define PA32H                           _PA32H.Word
#define PA32H_BIT0                      _PA32H.Bits.BIT0
#define PA32H_BIT1                      _PA32H.Bits.BIT1
#define PA32H_BIT2                      _PA32H.Bits.BIT2
#define PA32H_BIT3                      _PA32H.Bits.BIT3
#define PA32H_BIT4                      _PA32H.Bits.BIT4
#define PA32H_BIT5                      _PA32H.Bits.BIT5
#define PA32H_BIT6                      _PA32H.Bits.BIT6
#define PA32H_BIT7                      _PA32H.Bits.BIT7
#define PA32H_BIT8                      _PA32H.Bits.BIT8
#define PA32H_BIT9                      _PA32H.Bits.BIT9
#define PA32H_BIT10                     _PA32H.Bits.BIT10
#define PA32H_BIT11                     _PA32H.Bits.BIT11
#define PA32H_BIT12                     _PA32H.Bits.BIT12
#define PA32H_BIT13                     _PA32H.Bits.BIT13
#define PA32H_BIT14                     _PA32H.Bits.BIT14
#define PA32H_BIT15                     _PA32H.Bits.BIT15

#define PA32H_BIT0_MASK                 1
#define PA32H_BIT1_MASK                 2
#define PA32H_BIT2_MASK                 4
#define PA32H_BIT3_MASK                 8
#define PA32H_BIT4_MASK                 16
#define PA32H_BIT5_MASK                 32
#define PA32H_BIT6_MASK                 64
#define PA32H_BIT7_MASK                 128
#define PA32H_BIT8_MASK                 256
#define PA32H_BIT9_MASK                 512
#define PA32H_BIT10_MASK                1024
#define PA32H_BIT11_MASK                2048
#define PA32H_BIT12_MASK                4096
#define PA32H_BIT13_MASK                8192
#define PA32H_BIT14_MASK                16384
#define PA32H_BIT15_MASK                32768


 PA10H - 8-Bit Pulse Accumulators Holding 10 Register; 0x00000074 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PA1H - 8-Bit Pulse Accumulators Holding 1 Register; 0x00000074 
    union {
      byte Byte;
      struct {
        byte BIT0        1;                                        Pulse Accumulator Bit 0 
        byte BIT1        1;                                        Pulse Accumulator Bit 1 
        byte BIT2        1;                                        Pulse Accumulator Bit 2 
        byte BIT3        1;                                        Pulse Accumulator Bit 3 
        byte BIT4        1;                                        Pulse Accumulator Bit 4 
        byte BIT5        1;                                        Pulse Accumulator Bit 5 
        byte BIT6        1;                                        Pulse Accumulator Bit 6 
        byte BIT7        1;                                        Pulse Accumulator Bit 7 
      } Bits;
    } PA1HSTR;
    #define PA1H                        _PA10H.Overlap_STR.PA1HSTR.Byte
    #define PA1H_BIT0                   _PA10H.Overlap_STR.PA1HSTR.Bits.BIT0
    #define PA1H_BIT1                   _PA10H.Overlap_STR.PA1HSTR.Bits.BIT1
    #define PA1H_BIT2                   _PA10H.Overlap_STR.PA1HSTR.Bits.BIT2
    #define PA1H_BIT3                   _PA10H.Overlap_STR.PA1HSTR.Bits.BIT3
    #define PA1H_BIT4                   _PA10H.Overlap_STR.PA1HSTR.Bits.BIT4
    #define PA1H_BIT5                   _PA10H.Overlap_STR.PA1HSTR.Bits.BIT5
    #define PA1H_BIT6                   _PA10H.Overlap_STR.PA1HSTR.Bits.BIT6
    #define PA1H_BIT7                   _PA10H.Overlap_STR.PA1HSTR.Bits.BIT7
    
    
    #define PA1H_BIT0_MASK              1
    #define PA1H_BIT1_MASK              2
    #define PA1H_BIT2_MASK              4
    #define PA1H_BIT3_MASK              8
    #define PA1H_BIT4_MASK              16
    #define PA1H_BIT5_MASK              32
    #define PA1H_BIT6_MASK              64
    #define PA1H_BIT7_MASK              128


     PA0H - 8-Bit Pulse Accumulators Holding 0 Register; 0x00000075 
    union {
      byte Byte;
      struct {
        byte BIT0        1;                                        Pulse Accumulator Bit 0 
        byte BIT1        1;                                        Pulse Accumulator Bit 1 
        byte BIT2        1;                                        Pulse Accumulator Bit 2 
        byte BIT3        1;                                        Pulse Accumulator Bit 3 
        byte BIT4        1;                                        Pulse Accumulator Bit 4 
        byte BIT5        1;                                        Pulse Accumulator Bit 5 
        byte BIT6        1;                                        Pulse Accumulator Bit 6 
        byte BIT7        1;                                        Pulse Accumulator Bit 7 
      } Bits;
    } PA0HSTR;
    #define PA0H                        _PA10H.Overlap_STR.PA0HSTR.Byte
    #define PA0H_BIT0                   _PA10H.Overlap_STR.PA0HSTR.Bits.BIT0
    #define PA0H_BIT1                   _PA10H.Overlap_STR.PA0HSTR.Bits.BIT1
    #define PA0H_BIT2                   _PA10H.Overlap_STR.PA0HSTR.Bits.BIT2
    #define PA0H_BIT3                   _PA10H.Overlap_STR.PA0HSTR.Bits.BIT3
    #define PA0H_BIT4                   _PA10H.Overlap_STR.PA0HSTR.Bits.BIT4
    #define PA0H_BIT5                   _PA10H.Overlap_STR.PA0HSTR.Bits.BIT5
    #define PA0H_BIT6                   _PA10H.Overlap_STR.PA0HSTR.Bits.BIT6
    #define PA0H_BIT7                   _PA10H.Overlap_STR.PA0HSTR.Bits.BIT7
    
    
    #define PA0H_BIT0_MASK              1
    #define PA0H_BIT1_MASK              2
    #define PA0H_BIT2_MASK              4
    #define PA0H_BIT3_MASK              8
    #define PA0H_BIT4_MASK              16
    #define PA0H_BIT5_MASK              32
    #define PA0H_BIT6_MASK              64
    #define PA0H_BIT7_MASK              128

  } Overlap_STR;

  struct {
    word BIT0        1;                                        Pulse Accumulator Bit 0 
    word BIT1        1;                                        Pulse Accumulator Bit 1 
    word BIT2        1;                                        Pulse Accumulator Bit 2 
    word BIT3        1;                                        Pulse Accumulator Bit 3 
    word BIT4        1;                                        Pulse Accumulator Bit 4 
    word BIT5        1;                                        Pulse Accumulator Bit 5 
    word BIT6        1;                                        Pulse Accumulator Bit 6 
    word BIT7        1;                                        Pulse Accumulator Bit 7 
    word BIT8        1;                                        Pulse Accumulator Bit 8 
    word BIT9        1;                                        Pulse Accumulator Bit 9 
    word BIT10       1;                                        Pulse Accumulator Bit 10 
    word BIT11       1;                                        Pulse Accumulator Bit 11 
    word BIT12       1;                                        Pulse Accumulator Bit 12 
    word BIT13       1;                                        Pulse Accumulator Bit 13 
    word BIT14       1;                                        Pulse Accumulator Bit 14 
    word BIT15       1;                                        Pulse Accumulator Bit 15 
  } Bits;
} PA10HSTR;
extern volatile PA10HSTR _PA10H @(REG_BASE + 0x00000074);
#define PA10H                           _PA10H.Word
#define PA10H_BIT0                      _PA10H.Bits.BIT0
#define PA10H_BIT1                      _PA10H.Bits.BIT1
#define PA10H_BIT2                      _PA10H.Bits.BIT2
#define PA10H_BIT3                      _PA10H.Bits.BIT3
#define PA10H_BIT4                      _PA10H.Bits.BIT4
#define PA10H_BIT5                      _PA10H.Bits.BIT5
#define PA10H_BIT6                      _PA10H.Bits.BIT6
#define PA10H_BIT7                      _PA10H.Bits.BIT7
#define PA10H_BIT8                      _PA10H.Bits.BIT8
#define PA10H_BIT9                      _PA10H.Bits.BIT9
#define PA10H_BIT10                     _PA10H.Bits.BIT10
#define PA10H_BIT11                     _PA10H.Bits.BIT11
#define PA10H_BIT12                     _PA10H.Bits.BIT12
#define PA10H_BIT13                     _PA10H.Bits.BIT13
#define PA10H_BIT14                     _PA10H.Bits.BIT14
#define PA10H_BIT15                     _PA10H.Bits.BIT15

#define PA10H_BIT0_MASK                 1
#define PA10H_BIT1_MASK                 2
#define PA10H_BIT2_MASK                 4
#define PA10H_BIT3_MASK                 8
#define PA10H_BIT4_MASK                 16
#define PA10H_BIT5_MASK                 32
#define PA10H_BIT6_MASK                 64
#define PA10H_BIT7_MASK                 128
#define PA10H_BIT8_MASK                 256
#define PA10H_BIT9_MASK                 512
#define PA10H_BIT10_MASK                1024
#define PA10H_BIT11_MASK                2048
#define PA10H_BIT12_MASK                4096
#define PA10H_BIT13_MASK                8192
#define PA10H_BIT14_MASK                16384
#define PA10H_BIT15_MASK                32768


 MCCNT - Modulus Down-Counter Count Register; 0x00000076 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     MCCNThi - Modulus Down-Counter Count Register High; 0x00000076 
    union {
      byte Byte;
    } MCCNThiSTR;
    #define MCCNThi                     _MCCNT.Overlap_STR.MCCNThiSTR.Byte
    
    


     MCCNTlo - Modulus Down-Counter Count Register Low; 0x00000077 
    union {
      byte Byte;
    } MCCNTloSTR;
    #define MCCNTlo                     _MCCNT.Overlap_STR.MCCNTloSTR.Byte
    
    

  } Overlap_STR;

} MCCNTSTR;
extern volatile MCCNTSTR _MCCNT @(REG_BASE + 0x00000076);
#define MCCNT                           _MCCNT.Word



 TC0H - Timer Input Capture Holding Registers 0; 0x00000078 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC0Hhi - Timer Input Capture Holding Registers 0 High; 0x00000078 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Timer Input Capture Holding Bit 8 
        byte BIT9        1;                                        Timer Input Capture Holding Bit 9 
        byte BIT10       1;                                        Timer Input Capture Holding Bit 10 
        byte BIT11       1;                                        Timer Input Capture Holding Bit 11 
        byte BIT12       1;                                        Timer Input Capture Holding Bit 12 
        byte BIT13       1;                                        Timer Input Capture Holding Bit 13 
        byte BIT14       1;                                        Timer Input Capture Holding Bit 14 
        byte BIT15       1;                                        Timer Input Capture Holding Bit 15 
      } Bits;
    } TC0HhiSTR;
    #define TC0Hhi                      _TC0H.Overlap_STR.TC0HhiSTR.Byte
    #define TC0Hhi_BIT8                 _TC0H.Overlap_STR.TC0HhiSTR.Bits.BIT8
    #define TC0Hhi_BIT9                 _TC0H.Overlap_STR.TC0HhiSTR.Bits.BIT9
    #define TC0Hhi_BIT10                _TC0H.Overlap_STR.TC0HhiSTR.Bits.BIT10
    #define TC0Hhi_BIT11                _TC0H.Overlap_STR.TC0HhiSTR.Bits.BIT11
    #define TC0Hhi_BIT12                _TC0H.Overlap_STR.TC0HhiSTR.Bits.BIT12
    #define TC0Hhi_BIT13                _TC0H.Overlap_STR.TC0HhiSTR.Bits.BIT13
    #define TC0Hhi_BIT14                _TC0H.Overlap_STR.TC0HhiSTR.Bits.BIT14
    #define TC0Hhi_BIT15                _TC0H.Overlap_STR.TC0HhiSTR.Bits.BIT15
    
    
    #define TC0Hhi_BIT8_MASK            1
    #define TC0Hhi_BIT9_MASK            2
    #define TC0Hhi_BIT10_MASK           4
    #define TC0Hhi_BIT11_MASK           8
    #define TC0Hhi_BIT12_MASK           16
    #define TC0Hhi_BIT13_MASK           32
    #define TC0Hhi_BIT14_MASK           64
    #define TC0Hhi_BIT15_MASK           128


     TC0Hlo - Timer Input Capture Holding Registers 0 Low; 0x00000079 
    union {
      byte Byte;
      struct {
        byte BIT0        1;                                        Timer Input Capture Holding Bit 0 
        byte BIT1        1;                                        Timer Input Capture Holding Bit 1 
        byte BIT2        1;                                        Timer Input Capture Holding Bit 2 
        byte BIT3        1;                                        Timer Input Capture Holding Bit 3 
        byte BIT4        1;                                        Timer Input Capture Holding Bit 4 
        byte BIT5        1;                                        Timer Input Capture Holding Bit 5 
        byte BIT6        1;                                        Timer Input Capture Holding Bit 6 
        byte BIT7        1;                                        Timer Input Capture Holding Bit 7 
      } Bits;
    } TC0HloSTR;
    #define TC0Hlo                      _TC0H.Overlap_STR.TC0HloSTR.Byte
    #define TC0Hlo_BIT0                 _TC0H.Overlap_STR.TC0HloSTR.Bits.BIT0
    #define TC0Hlo_BIT1                 _TC0H.Overlap_STR.TC0HloSTR.Bits.BIT1
    #define TC0Hlo_BIT2                 _TC0H.Overlap_STR.TC0HloSTR.Bits.BIT2
    #define TC0Hlo_BIT3                 _TC0H.Overlap_STR.TC0HloSTR.Bits.BIT3
    #define TC0Hlo_BIT4                 _TC0H.Overlap_STR.TC0HloSTR.Bits.BIT4
    #define TC0Hlo_BIT5                 _TC0H.Overlap_STR.TC0HloSTR.Bits.BIT5
    #define TC0Hlo_BIT6                 _TC0H.Overlap_STR.TC0HloSTR.Bits.BIT6
    #define TC0Hlo_BIT7                 _TC0H.Overlap_STR.TC0HloSTR.Bits.BIT7
    
    
    #define TC0Hlo_BIT0_MASK            1
    #define TC0Hlo_BIT1_MASK            2
    #define TC0Hlo_BIT2_MASK            4
    #define TC0Hlo_BIT3_MASK            8
    #define TC0Hlo_BIT4_MASK            16
    #define TC0Hlo_BIT5_MASK            32
    #define TC0Hlo_BIT6_MASK            64
    #define TC0Hlo_BIT7_MASK            128

  } Overlap_STR;

  struct {
    word BIT0        1;                                        Timer Input Capture Holding Bit 0 
    word BIT1        1;                                        Timer Input Capture Holding Bit 1 
    word BIT2        1;                                        Timer Input Capture Holding Bit 2 
    word BIT3        1;                                        Timer Input Capture Holding Bit 3 
    word BIT4        1;                                        Timer Input Capture Holding Bit 4 
    word BIT5        1;                                        Timer Input Capture Holding Bit 5 
    word BIT6        1;                                        Timer Input Capture Holding Bit 6 
    word BIT7        1;                                        Timer Input Capture Holding Bit 7 
    word BIT8        1;                                        Timer Input Capture Holding Bit 8 
    word BIT9        1;                                        Timer Input Capture Holding Bit 9 
    word BIT10       1;                                        Timer Input Capture Holding Bit 10 
    word BIT11       1;                                        Timer Input Capture Holding Bit 11 
    word BIT12       1;                                        Timer Input Capture Holding Bit 12 
    word BIT13       1;                                        Timer Input Capture Holding Bit 13 
    word BIT14       1;                                        Timer Input Capture Holding Bit 14 
    word BIT15       1;                                        Timer Input Capture Holding Bit 15 
  } Bits;
} TC0HSTR;
extern volatile TC0HSTR _TC0H @(REG_BASE + 0x00000078);
#define TC0H                            _TC0H.Word
#define TC0H_BIT0                       _TC0H.Bits.BIT0
#define TC0H_BIT1                       _TC0H.Bits.BIT1
#define TC0H_BIT2                       _TC0H.Bits.BIT2
#define TC0H_BIT3                       _TC0H.Bits.BIT3
#define TC0H_BIT4                       _TC0H.Bits.BIT4
#define TC0H_BIT5                       _TC0H.Bits.BIT5
#define TC0H_BIT6                       _TC0H.Bits.BIT6
#define TC0H_BIT7                       _TC0H.Bits.BIT7
#define TC0H_BIT8                       _TC0H.Bits.BIT8
#define TC0H_BIT9                       _TC0H.Bits.BIT9
#define TC0H_BIT10                      _TC0H.Bits.BIT10
#define TC0H_BIT11                      _TC0H.Bits.BIT11
#define TC0H_BIT12                      _TC0H.Bits.BIT12
#define TC0H_BIT13                      _TC0H.Bits.BIT13
#define TC0H_BIT14                      _TC0H.Bits.BIT14
#define TC0H_BIT15                      _TC0H.Bits.BIT15

#define TC0H_BIT0_MASK                  1
#define TC0H_BIT1_MASK                  2
#define TC0H_BIT2_MASK                  4
#define TC0H_BIT3_MASK                  8
#define TC0H_BIT4_MASK                  16
#define TC0H_BIT5_MASK                  32
#define TC0H_BIT6_MASK                  64
#define TC0H_BIT7_MASK                  128
#define TC0H_BIT8_MASK                  256
#define TC0H_BIT9_MASK                  512
#define TC0H_BIT10_MASK                 1024
#define TC0H_BIT11_MASK                 2048
#define TC0H_BIT12_MASK                 4096
#define TC0H_BIT13_MASK                 8192
#define TC0H_BIT14_MASK                 16384
#define TC0H_BIT15_MASK                 32768


 TC1H - Timer Input Capture Holding Registers 1; 0x0000007A 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC1Hhi - Timer Input Capture Holding Registers 1 High; 0x0000007A 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Timer Input Capture Holding Bit 8 
        byte BIT9        1;                                        Timer Input Capture Holding Bit 9 
        byte BIT10       1;                                        Timer Input Capture Holding Bit 10 
        byte BIT11       1;                                        Timer Input Capture Holding Bit 11 
        byte BIT12       1;                                        Timer Input Capture Holding Bit 12 
        byte BIT13       1;                                        Timer Input Capture Holding Bit 13 
        byte BIT14       1;                                        Timer Input Capture Holding Bit 14 
        byte BIT15       1;                                        Timer Input Capture Holding Bit 15 
      } Bits;
    } TC1HhiSTR;
    #define TC1Hhi                      _TC1H.Overlap_STR.TC1HhiSTR.Byte
    #define TC1Hhi_BIT8                 _TC1H.Overlap_STR.TC1HhiSTR.Bits.BIT8
    #define TC1Hhi_BIT9                 _TC1H.Overlap_STR.TC1HhiSTR.Bits.BIT9
    #define TC1Hhi_BIT10                _TC1H.Overlap_STR.TC1HhiSTR.Bits.BIT10
    #define TC1Hhi_BIT11                _TC1H.Overlap_STR.TC1HhiSTR.Bits.BIT11
    #define TC1Hhi_BIT12                _TC1H.Overlap_STR.TC1HhiSTR.Bits.BIT12
    #define TC1Hhi_BIT13                _TC1H.Overlap_STR.TC1HhiSTR.Bits.BIT13
    #define TC1Hhi_BIT14                _TC1H.Overlap_STR.TC1HhiSTR.Bits.BIT14
    #define TC1Hhi_BIT15                _TC1H.Overlap_STR.TC1HhiSTR.Bits.BIT15
    
    
    #define TC1Hhi_BIT8_MASK            1
    #define TC1Hhi_BIT9_MASK            2
    #define TC1Hhi_BIT10_MASK           4
    #define TC1Hhi_BIT11_MASK           8
    #define TC1Hhi_BIT12_MASK           16
    #define TC1Hhi_BIT13_MASK           32
    #define TC1Hhi_BIT14_MASK           64
    #define TC1Hhi_BIT15_MASK           128


     TC1Hlo - Timer Input Capture Holding Registers 1 Low; 0x0000007B 
    union {
      byte Byte;
      struct {
        byte BIT0        1;                                        Timer Input Capture Holding Bit 0 
        byte BIT1        1;                                        Timer Input Capture Holding Bit 1 
        byte BIT2        1;                                        Timer Input Capture Holding Bit 2 
        byte BIT3        1;                                        Timer Input Capture Holding Bit 3 
        byte BIT4        1;                                        Timer Input Capture Holding Bit 4 
        byte BIT5        1;                                        Timer Input Capture Holding Bit 5 
        byte BIT6        1;                                        Timer Input Capture Holding Bit 6 
        byte BIT7        1;                                        Timer Input Capture Holding Bit 7 
      } Bits;
    } TC1HloSTR;
    #define TC1Hlo                      _TC1H.Overlap_STR.TC1HloSTR.Byte
    #define TC1Hlo_BIT0                 _TC1H.Overlap_STR.TC1HloSTR.Bits.BIT0
    #define TC1Hlo_BIT1                 _TC1H.Overlap_STR.TC1HloSTR.Bits.BIT1
    #define TC1Hlo_BIT2                 _TC1H.Overlap_STR.TC1HloSTR.Bits.BIT2
    #define TC1Hlo_BIT3                 _TC1H.Overlap_STR.TC1HloSTR.Bits.BIT3
    #define TC1Hlo_BIT4                 _TC1H.Overlap_STR.TC1HloSTR.Bits.BIT4
    #define TC1Hlo_BIT5                 _TC1H.Overlap_STR.TC1HloSTR.Bits.BIT5
    #define TC1Hlo_BIT6                 _TC1H.Overlap_STR.TC1HloSTR.Bits.BIT6
    #define TC1Hlo_BIT7                 _TC1H.Overlap_STR.TC1HloSTR.Bits.BIT7
    
    
    #define TC1Hlo_BIT0_MASK            1
    #define TC1Hlo_BIT1_MASK            2
    #define TC1Hlo_BIT2_MASK            4
    #define TC1Hlo_BIT3_MASK            8
    #define TC1Hlo_BIT4_MASK            16
    #define TC1Hlo_BIT5_MASK            32
    #define TC1Hlo_BIT6_MASK            64
    #define TC1Hlo_BIT7_MASK            128

  } Overlap_STR;

  struct {
    word BIT0        1;                                        Timer Input Capture Holding Bit 0 
    word BIT1        1;                                        Timer Input Capture Holding Bit 1 
    word BIT2        1;                                        Timer Input Capture Holding Bit 2 
    word BIT3        1;                                        Timer Input Capture Holding Bit 3 
    word BIT4        1;                                        Timer Input Capture Holding Bit 4 
    word BIT5        1;                                        Timer Input Capture Holding Bit 5 
    word BIT6        1;                                        Timer Input Capture Holding Bit 6 
    word BIT7        1;                                        Timer Input Capture Holding Bit 7 
    word BIT8        1;                                        Timer Input Capture Holding Bit 8 
    word BIT9        1;                                        Timer Input Capture Holding Bit 9 
    word BIT10       1;                                        Timer Input Capture Holding Bit 10 
    word BIT11       1;                                        Timer Input Capture Holding Bit 11 
    word BIT12       1;                                        Timer Input Capture Holding Bit 12 
    word BIT13       1;                                        Timer Input Capture Holding Bit 13 
    word BIT14       1;                                        Timer Input Capture Holding Bit 14 
    word BIT15       1;                                        Timer Input Capture Holding Bit 15 
  } Bits;
} TC1HSTR;
extern volatile TC1HSTR _TC1H @(REG_BASE + 0x0000007A);
#define TC1H                            _TC1H.Word
#define TC1H_BIT0                       _TC1H.Bits.BIT0
#define TC1H_BIT1                       _TC1H.Bits.BIT1
#define TC1H_BIT2                       _TC1H.Bits.BIT2
#define TC1H_BIT3                       _TC1H.Bits.BIT3
#define TC1H_BIT4                       _TC1H.Bits.BIT4
#define TC1H_BIT5                       _TC1H.Bits.BIT5
#define TC1H_BIT6                       _TC1H.Bits.BIT6
#define TC1H_BIT7                       _TC1H.Bits.BIT7
#define TC1H_BIT8                       _TC1H.Bits.BIT8
#define TC1H_BIT9                       _TC1H.Bits.BIT9
#define TC1H_BIT10                      _TC1H.Bits.BIT10
#define TC1H_BIT11                      _TC1H.Bits.BIT11
#define TC1H_BIT12                      _TC1H.Bits.BIT12
#define TC1H_BIT13                      _TC1H.Bits.BIT13
#define TC1H_BIT14                      _TC1H.Bits.BIT14
#define TC1H_BIT15                      _TC1H.Bits.BIT15

#define TC1H_BIT0_MASK                  1
#define TC1H_BIT1_MASK                  2
#define TC1H_BIT2_MASK                  4
#define TC1H_BIT3_MASK                  8
#define TC1H_BIT4_MASK                  16
#define TC1H_BIT5_MASK                  32
#define TC1H_BIT6_MASK                  64
#define TC1H_BIT7_MASK                  128
#define TC1H_BIT8_MASK                  256
#define TC1H_BIT9_MASK                  512
#define TC1H_BIT10_MASK                 1024
#define TC1H_BIT11_MASK                 2048
#define TC1H_BIT12_MASK                 4096
#define TC1H_BIT13_MASK                 8192
#define TC1H_BIT14_MASK                 16384
#define TC1H_BIT15_MASK                 32768


 TC2H - Timer Input Capture Holding Registers 2; 0x0000007C 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC2Hhi - Timer Input Capture Holding Registers 2 High; 0x0000007C 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Timer Input Capture Holding Bit 8 
        byte BIT9        1;                                        Timer Input Capture Holding Bit 9 
        byte BIT10       1;                                        Timer Input Capture Holding Bit 10 
        byte BIT11       1;                                        Timer Input Capture Holding Bit 11 
        byte BIT12       1;                                        Timer Input Capture Holding Bit 12 
        byte BIT13       1;                                        Timer Input Capture Holding Bit 13 
        byte BIT14       1;                                        Timer Input Capture Holding Bit 14 
        byte BIT15       1;                                        Timer Input Capture Holding Bit 15 
      } Bits;
    } TC2HhiSTR;
    #define TC2Hhi                      _TC2H.Overlap_STR.TC2HhiSTR.Byte
    #define TC2Hhi_BIT8                 _TC2H.Overlap_STR.TC2HhiSTR.Bits.BIT8
    #define TC2Hhi_BIT9                 _TC2H.Overlap_STR.TC2HhiSTR.Bits.BIT9
    #define TC2Hhi_BIT10                _TC2H.Overlap_STR.TC2HhiSTR.Bits.BIT10
    #define TC2Hhi_BIT11                _TC2H.Overlap_STR.TC2HhiSTR.Bits.BIT11
    #define TC2Hhi_BIT12                _TC2H.Overlap_STR.TC2HhiSTR.Bits.BIT12
    #define TC2Hhi_BIT13                _TC2H.Overlap_STR.TC2HhiSTR.Bits.BIT13
    #define TC2Hhi_BIT14                _TC2H.Overlap_STR.TC2HhiSTR.Bits.BIT14
    #define TC2Hhi_BIT15                _TC2H.Overlap_STR.TC2HhiSTR.Bits.BIT15
    
    
    #define TC2Hhi_BIT8_MASK            1
    #define TC2Hhi_BIT9_MASK            2
    #define TC2Hhi_BIT10_MASK           4
    #define TC2Hhi_BIT11_MASK           8
    #define TC2Hhi_BIT12_MASK           16
    #define TC2Hhi_BIT13_MASK           32
    #define TC2Hhi_BIT14_MASK           64
    #define TC2Hhi_BIT15_MASK           128


     TC2Hlo - Timer Input Capture Holding Registers 2 Low; 0x0000007D 
    union {
      byte Byte;
      struct {
        byte BIT0        1;                                        Timer Input Capture Holding Bit 0 
        byte BIT1        1;                                        Timer Input Capture Holding Bit 1 
        byte BIT2        1;                                        Timer Input Capture Holding Bit 2 
        byte BIT3        1;                                        Timer Input Capture Holding Bit 3 
        byte BIT4        1;                                        Timer Input Capture Holding Bit 4 
        byte BIT5        1;                                        Timer Input Capture Holding Bit 5 
        byte BIT6        1;                                        Timer Input Capture Holding Bit 6 
        byte BIT7        1;                                        Timer Input Capture Holding Bit 7 
      } Bits;
    } TC2HloSTR;
    #define TC2Hlo                      _TC2H.Overlap_STR.TC2HloSTR.Byte
    #define TC2Hlo_BIT0                 _TC2H.Overlap_STR.TC2HloSTR.Bits.BIT0
    #define TC2Hlo_BIT1                 _TC2H.Overlap_STR.TC2HloSTR.Bits.BIT1
    #define TC2Hlo_BIT2                 _TC2H.Overlap_STR.TC2HloSTR.Bits.BIT2
    #define TC2Hlo_BIT3                 _TC2H.Overlap_STR.TC2HloSTR.Bits.BIT3
    #define TC2Hlo_BIT4                 _TC2H.Overlap_STR.TC2HloSTR.Bits.BIT4
    #define TC2Hlo_BIT5                 _TC2H.Overlap_STR.TC2HloSTR.Bits.BIT5
    #define TC2Hlo_BIT6                 _TC2H.Overlap_STR.TC2HloSTR.Bits.BIT6
    #define TC2Hlo_BIT7                 _TC2H.Overlap_STR.TC2HloSTR.Bits.BIT7
    
    
    #define TC2Hlo_BIT0_MASK            1
    #define TC2Hlo_BIT1_MASK            2
    #define TC2Hlo_BIT2_MASK            4
    #define TC2Hlo_BIT3_MASK            8
    #define TC2Hlo_BIT4_MASK            16
    #define TC2Hlo_BIT5_MASK            32
    #define TC2Hlo_BIT6_MASK            64
    #define TC2Hlo_BIT7_MASK            128

  } Overlap_STR;

  struct {
    word BIT0        1;                                        Timer Input Capture Holding Bit 0 
    word BIT1        1;                                        Timer Input Capture Holding Bit 1 
    word BIT2        1;                                        Timer Input Capture Holding Bit 2 
    word BIT3        1;                                        Timer Input Capture Holding Bit 3 
    word BIT4        1;                                        Timer Input Capture Holding Bit 4 
    word BIT5        1;                                        Timer Input Capture Holding Bit 5 
    word BIT6        1;                                        Timer Input Capture Holding Bit 6 
    word BIT7        1;                                        Timer Input Capture Holding Bit 7 
    word BIT8        1;                                        Timer Input Capture Holding Bit 8 
    word BIT9        1;                                        Timer Input Capture Holding Bit 9 
    word BIT10       1;                                        Timer Input Capture Holding Bit 10 
    word BIT11       1;                                        Timer Input Capture Holding Bit 11 
    word BIT12       1;                                        Timer Input Capture Holding Bit 12 
    word BIT13       1;                                        Timer Input Capture Holding Bit 13 
    word BIT14       1;                                        Timer Input Capture Holding Bit 14 
    word BIT15       1;                                        Timer Input Capture Holding Bit 15 
  } Bits;
} TC2HSTR;
extern volatile TC2HSTR _TC2H @(REG_BASE + 0x0000007C);
#define TC2H                            _TC2H.Word
#define TC2H_BIT0                       _TC2H.Bits.BIT0
#define TC2H_BIT1                       _TC2H.Bits.BIT1
#define TC2H_BIT2                       _TC2H.Bits.BIT2
#define TC2H_BIT3                       _TC2H.Bits.BIT3
#define TC2H_BIT4                       _TC2H.Bits.BIT4
#define TC2H_BIT5                       _TC2H.Bits.BIT5
#define TC2H_BIT6                       _TC2H.Bits.BIT6
#define TC2H_BIT7                       _TC2H.Bits.BIT7
#define TC2H_BIT8                       _TC2H.Bits.BIT8
#define TC2H_BIT9                       _TC2H.Bits.BIT9
#define TC2H_BIT10                      _TC2H.Bits.BIT10
#define TC2H_BIT11                      _TC2H.Bits.BIT11
#define TC2H_BIT12                      _TC2H.Bits.BIT12
#define TC2H_BIT13                      _TC2H.Bits.BIT13
#define TC2H_BIT14                      _TC2H.Bits.BIT14
#define TC2H_BIT15                      _TC2H.Bits.BIT15

#define TC2H_BIT0_MASK                  1
#define TC2H_BIT1_MASK                  2
#define TC2H_BIT2_MASK                  4
#define TC2H_BIT3_MASK                  8
#define TC2H_BIT4_MASK                  16
#define TC2H_BIT5_MASK                  32
#define TC2H_BIT6_MASK                  64
#define TC2H_BIT7_MASK                  128
#define TC2H_BIT8_MASK                  256
#define TC2H_BIT9_MASK                  512
#define TC2H_BIT10_MASK                 1024
#define TC2H_BIT11_MASK                 2048
#define TC2H_BIT12_MASK                 4096
#define TC2H_BIT13_MASK                 8192
#define TC2H_BIT14_MASK                 16384
#define TC2H_BIT15_MASK                 32768


 TC3H - Timer Input Capture Holding Registers 3; 0x0000007E 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     TC3Hhi - Timer Input Capture Holding Registers 3 High; 0x0000007E 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Timer Input Capture Holding Bit 8 
        byte BIT9        1;                                        Timer Input Capture Holding Bit 9 
        byte BIT10       1;                                        Timer Input Capture Holding Bit 10 
        byte BIT11       1;                                        Timer Input Capture Holding Bit 11 
        byte BIT12       1;                                        Timer Input Capture Holding Bit 12 
        byte BIT13       1;                                        Timer Input Capture Holding Bit 13 
        byte BIT14       1;                                        Timer Input Capture Holding Bit 14 
        byte BIT15       1;                                        Timer Input Capture Holding Bit 15 
      } Bits;
    } TC3HhiSTR;
    #define TC3Hhi                      _TC3H.Overlap_STR.TC3HhiSTR.Byte
    #define TC3Hhi_BIT8                 _TC3H.Overlap_STR.TC3HhiSTR.Bits.BIT8
    #define TC3Hhi_BIT9                 _TC3H.Overlap_STR.TC3HhiSTR.Bits.BIT9
    #define TC3Hhi_BIT10                _TC3H.Overlap_STR.TC3HhiSTR.Bits.BIT10
    #define TC3Hhi_BIT11                _TC3H.Overlap_STR.TC3HhiSTR.Bits.BIT11
    #define TC3Hhi_BIT12                _TC3H.Overlap_STR.TC3HhiSTR.Bits.BIT12
    #define TC3Hhi_BIT13                _TC3H.Overlap_STR.TC3HhiSTR.Bits.BIT13
    #define TC3Hhi_BIT14                _TC3H.Overlap_STR.TC3HhiSTR.Bits.BIT14
    #define TC3Hhi_BIT15                _TC3H.Overlap_STR.TC3HhiSTR.Bits.BIT15
    
    
    #define TC3Hhi_BIT8_MASK            1
    #define TC3Hhi_BIT9_MASK            2
    #define TC3Hhi_BIT10_MASK           4
    #define TC3Hhi_BIT11_MASK           8
    #define TC3Hhi_BIT12_MASK           16
    #define TC3Hhi_BIT13_MASK           32
    #define TC3Hhi_BIT14_MASK           64
    #define TC3Hhi_BIT15_MASK           128


     TC3Hlo - Timer Input Capture Holding Registers 3 Low; 0x0000007F 
    union {
      byte Byte;
      struct {
        byte BIT0        1;                                        Timer Input Capture Holding Bit 0 
        byte BIT1        1;                                        Timer Input Capture Holding Bit 1 
        byte BIT2        1;                                        Timer Input Capture Holding Bit 2 
        byte BIT3        1;                                        Timer Input Capture Holding Bit 3 
        byte BIT4        1;                                        Timer Input Capture Holding Bit 4 
        byte BIT5        1;                                        Timer Input Capture Holding Bit 5 
        byte BIT6        1;                                        Timer Input Capture Holding Bit 6 
        byte BIT7        1;                                        Timer Input Capture Holding Bit 7 
      } Bits;
    } TC3HloSTR;
    #define TC3Hlo                      _TC3H.Overlap_STR.TC3HloSTR.Byte
    #define TC3Hlo_BIT0                 _TC3H.Overlap_STR.TC3HloSTR.Bits.BIT0
    #define TC3Hlo_BIT1                 _TC3H.Overlap_STR.TC3HloSTR.Bits.BIT1
    #define TC3Hlo_BIT2                 _TC3H.Overlap_STR.TC3HloSTR.Bits.BIT2
    #define TC3Hlo_BIT3                 _TC3H.Overlap_STR.TC3HloSTR.Bits.BIT3
    #define TC3Hlo_BIT4                 _TC3H.Overlap_STR.TC3HloSTR.Bits.BIT4
    #define TC3Hlo_BIT5                 _TC3H.Overlap_STR.TC3HloSTR.Bits.BIT5
    #define TC3Hlo_BIT6                 _TC3H.Overlap_STR.TC3HloSTR.Bits.BIT6
    #define TC3Hlo_BIT7                 _TC3H.Overlap_STR.TC3HloSTR.Bits.BIT7
    
    
    #define TC3Hlo_BIT0_MASK            1
    #define TC3Hlo_BIT1_MASK            2
    #define TC3Hlo_BIT2_MASK            4
    #define TC3Hlo_BIT3_MASK            8
    #define TC3Hlo_BIT4_MASK            16
    #define TC3Hlo_BIT5_MASK            32
    #define TC3Hlo_BIT6_MASK            64
    #define TC3Hlo_BIT7_MASK            128

  } Overlap_STR;

  struct {
    word BIT0        1;                                        Timer Input Capture Holding Bit 0 
    word BIT1        1;                                        Timer Input Capture Holding Bit 1 
    word BIT2        1;                                        Timer Input Capture Holding Bit 2 
    word BIT3        1;                                        Timer Input Capture Holding Bit 3 
    word BIT4        1;                                        Timer Input Capture Holding Bit 4 
    word BIT5        1;                                        Timer Input Capture Holding Bit 5 
    word BIT6        1;                                        Timer Input Capture Holding Bit 6 
    word BIT7        1;                                        Timer Input Capture Holding Bit 7 
    word BIT8        1;                                        Timer Input Capture Holding Bit 8 
    word BIT9        1;                                        Timer Input Capture Holding Bit 9 
    word BIT10       1;                                        Timer Input Capture Holding Bit 10 
    word BIT11       1;                                        Timer Input Capture Holding Bit 11 
    word BIT12       1;                                        Timer Input Capture Holding Bit 12 
    word BIT13       1;                                        Timer Input Capture Holding Bit 13 
    word BIT14       1;                                        Timer Input Capture Holding Bit 14 
    word BIT15       1;                                        Timer Input Capture Holding Bit 15 
  } Bits;
} TC3HSTR;
extern volatile TC3HSTR _TC3H @(REG_BASE + 0x0000007E);
#define TC3H                            _TC3H.Word
#define TC3H_BIT0                       _TC3H.Bits.BIT0
#define TC3H_BIT1                       _TC3H.Bits.BIT1
#define TC3H_BIT2                       _TC3H.Bits.BIT2
#define TC3H_BIT3                       _TC3H.Bits.BIT3
#define TC3H_BIT4                       _TC3H.Bits.BIT4
#define TC3H_BIT5                       _TC3H.Bits.BIT5
#define TC3H_BIT6                       _TC3H.Bits.BIT6
#define TC3H_BIT7                       _TC3H.Bits.BIT7
#define TC3H_BIT8                       _TC3H.Bits.BIT8
#define TC3H_BIT9                       _TC3H.Bits.BIT9
#define TC3H_BIT10                      _TC3H.Bits.BIT10
#define TC3H_BIT11                      _TC3H.Bits.BIT11
#define TC3H_BIT12                      _TC3H.Bits.BIT12
#define TC3H_BIT13                      _TC3H.Bits.BIT13
#define TC3H_BIT14                      _TC3H.Bits.BIT14
#define TC3H_BIT15                      _TC3H.Bits.BIT15

#define TC3H_BIT0_MASK                  1
#define TC3H_BIT1_MASK                  2
#define TC3H_BIT2_MASK                  4
#define TC3H_BIT3_MASK                  8
#define TC3H_BIT4_MASK                  16
#define TC3H_BIT5_MASK                  32
#define TC3H_BIT6_MASK                  64
#define TC3H_BIT7_MASK                  128
#define TC3H_BIT8_MASK                  256
#define TC3H_BIT9_MASK                  512
#define TC3H_BIT10_MASK                 1024
#define TC3H_BIT11_MASK                 2048
#define TC3H_BIT12_MASK                 4096
#define TC3H_BIT13_MASK                 8192
#define TC3H_BIT14_MASK                 16384
#define TC3H_BIT15_MASK                 32768


 ATD1CTL01 - ATD 1 Control Register 01; 0x00000080 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1CTL0 - ATD 1 Control Register 0; 0x00000080 
    union {
      byte Byte;
      struct {
        byte WRAP0       1;                                        Wrap Around Channel Select Bit 0 
        byte WRAP1       1;                                        Wrap Around Channel Select Bit 1 
        byte WRAP2       1;                                        Wrap Around Channel Select Bit 2 
        byte WRAP3       1;                                        Wrap Around Channel Select Bit 3 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
      } Bits;
      struct {
        byte grpWRAP 4;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } ATD1CTL0STR;
    #define ATD1CTL0                    _ATD1CTL01.Overlap_STR.ATD1CTL0STR.Byte
    #define ATD1CTL0_WRAP0              _ATD1CTL01.Overlap_STR.ATD1CTL0STR.Bits.WRAP0
    #define ATD1CTL0_WRAP1              _ATD1CTL01.Overlap_STR.ATD1CTL0STR.Bits.WRAP1
    #define ATD1CTL0_WRAP2              _ATD1CTL01.Overlap_STR.ATD1CTL0STR.Bits.WRAP2
    #define ATD1CTL0_WRAP3              _ATD1CTL01.Overlap_STR.ATD1CTL0STR.Bits.WRAP3
    
     ATD1CTL_ARR Access 6 ATD1CTLx registers in an array 
    #define ATD1CTL_ARR                 ((volatile byte ) &ATD1CTL0)
    #define ATD1CTL0_WRAP               _ATD1CTL01.Overlap_STR.ATD1CTL0STR.MergedBits.grpWRAP
    
    #define ATD1CTL0_WRAP0_MASK         1
    #define ATD1CTL0_WRAP1_MASK         2
    #define ATD1CTL0_WRAP2_MASK         4
    #define ATD1CTL0_WRAP3_MASK         8
    #define ATD1CTL0_WRAP_MASK          15
    #define ATD1CTL0_WRAP_BITNUM        0


     ATD1CTL1 - ATD1 Control Register 1; 0x00000081 
    union {
      byte Byte;
      struct {
        byte ETRIGCH0    1;                                        External Trigger Channel Select Bit 0 
        byte ETRIGCH1    1;                                        External Trigger Channel Select Bit 1 
        byte ETRIGCH2    1;                                        External Trigger Channel Select Bit 2 
        byte ETRIGCH3    1;                                        External Trigger Channel Select Bit 3 
        byte             1; 
        byte             1; 
        byte             1; 
        byte ETRIGSEL    1;                                        External Trigger Source Select 
      } Bits;
      struct {
        byte grpETRIGCH 4;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } ATD1CTL1STR;
    #define ATD1CTL1                    _ATD1CTL01.Overlap_STR.ATD1CTL1STR.Byte
    #define ATD1CTL1_ETRIGCH0           _ATD1CTL01.Overlap_STR.ATD1CTL1STR.Bits.ETRIGCH0
    #define ATD1CTL1_ETRIGCH1           _ATD1CTL01.Overlap_STR.ATD1CTL1STR.Bits.ETRIGCH1
    #define ATD1CTL1_ETRIGCH2           _ATD1CTL01.Overlap_STR.ATD1CTL1STR.Bits.ETRIGCH2
    #define ATD1CTL1_ETRIGCH3           _ATD1CTL01.Overlap_STR.ATD1CTL1STR.Bits.ETRIGCH3
    #define ATD1CTL1_ETRIGSEL           _ATD1CTL01.Overlap_STR.ATD1CTL1STR.Bits.ETRIGSEL
    
    #define ATD1CTL1_ETRIGCH            _ATD1CTL01.Overlap_STR.ATD1CTL1STR.MergedBits.grpETRIGCH
    
    #define ATD1CTL1_ETRIGCH0_MASK      1
    #define ATD1CTL1_ETRIGCH1_MASK      2
    #define ATD1CTL1_ETRIGCH2_MASK      4
    #define ATD1CTL1_ETRIGCH3_MASK      8
    #define ATD1CTL1_ETRIGSEL_MASK      128
    #define ATD1CTL1_ETRIGCH_MASK       15
    #define ATD1CTL1_ETRIGCH_BITNUM     0

  } Overlap_STR;

  struct {
    word ETRIGCH0    1;                                        External Trigger Channel Select Bit 0 
    word ETRIGCH1    1;                                        External Trigger Channel Select Bit 1 
    word ETRIGCH2    1;                                        External Trigger Channel Select Bit 2 
    word ETRIGCH3    1;                                        External Trigger Channel Select Bit 3 
    word             1; 
    word             1; 
    word             1; 
    word ETRIGSEL    1;                                        External Trigger Source Select 
    word WRAP0       1;                                        Wrap Around Channel Select Bit 0 
    word WRAP1       1;                                        Wrap Around Channel Select Bit 1 
    word WRAP2       1;                                        Wrap Around Channel Select Bit 2 
    word WRAP3       1;                                        Wrap Around Channel Select Bit 3 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
  } Bits;
  struct {
    word grpETRIGCH 4;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpWRAP 4;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} ATD1CTL01STR;
extern volatile ATD1CTL01STR _ATD1CTL01 @(REG_BASE + 0x00000080);
#define ATD1CTL01                       _ATD1CTL01.Word
#define ATD1CTL01_ETRIGCH0              _ATD1CTL01.Bits.ETRIGCH0
#define ATD1CTL01_ETRIGCH1              _ATD1CTL01.Bits.ETRIGCH1
#define ATD1CTL01_ETRIGCH2              _ATD1CTL01.Bits.ETRIGCH2
#define ATD1CTL01_ETRIGCH3              _ATD1CTL01.Bits.ETRIGCH3
#define ATD1CTL01_ETRIGSEL              _ATD1CTL01.Bits.ETRIGSEL
#define ATD1CTL01_WRAP0                 _ATD1CTL01.Bits.WRAP0
#define ATD1CTL01_WRAP1                 _ATD1CTL01.Bits.WRAP1
#define ATD1CTL01_WRAP2                 _ATD1CTL01.Bits.WRAP2
#define ATD1CTL01_WRAP3                 _ATD1CTL01.Bits.WRAP3
#define ATD1CTL01_ETRIGCH               _ATD1CTL01.MergedBits.grpETRIGCH
#define ATD1CTL01_WRAP                  _ATD1CTL01.MergedBits.grpWRAP

#define ATD1CTL01_ETRIGCH0_MASK         1
#define ATD1CTL01_ETRIGCH1_MASK         2
#define ATD1CTL01_ETRIGCH2_MASK         4
#define ATD1CTL01_ETRIGCH3_MASK         8
#define ATD1CTL01_ETRIGSEL_MASK         128
#define ATD1CTL01_WRAP0_MASK            256
#define ATD1CTL01_WRAP1_MASK            512
#define ATD1CTL01_WRAP2_MASK            1024
#define ATD1CTL01_WRAP3_MASK            2048
#define ATD1CTL01_ETRIGCH_MASK          15
#define ATD1CTL01_ETRIGCH_BITNUM        0
#define ATD1CTL01_WRAP_MASK             3840
#define ATD1CTL01_WRAP_BITNUM           8


 ATD1CTL23 - ATD 1 Control Register 23; 0x00000082 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1CTL2 - ATD 1 Control Register 2; 0x00000082 
    union {
      byte Byte;
      struct {
        byte ASCIF       1;                                        ATD 1 Sequence Complete Interrupt Flag 
        byte ASCIE       1;                                        ATD 1 Sequence Complete Interrupt Enable 
        byte ETRIGE      1;                                        External Trigger Mode enable 
        byte ETRIGP      1;                                        External Trigger Polarity 
        byte ETRIGLE     1;                                        External Trigger LevelEdge control 
        byte AWAI        1;                                        ATD Power Down in Wait Mode 
        byte AFFC        1;                                        ATD Fast Conversion Complete Flag Clear 
        byte ADPU        1;                                        ATD Disable  Power Down 
      } Bits;
    } ATD1CTL2STR;
    #define ATD1CTL2                    _ATD1CTL23.Overlap_STR.ATD1CTL2STR.Byte
    #define ATD1CTL2_ASCIF              _ATD1CTL23.Overlap_STR.ATD1CTL2STR.Bits.ASCIF
    #define ATD1CTL2_ASCIE              _ATD1CTL23.Overlap_STR.ATD1CTL2STR.Bits.ASCIE
    #define ATD1CTL2_ETRIGE             _ATD1CTL23.Overlap_STR.ATD1CTL2STR.Bits.ETRIGE
    #define ATD1CTL2_ETRIGP             _ATD1CTL23.Overlap_STR.ATD1CTL2STR.Bits.ETRIGP
    #define ATD1CTL2_ETRIGLE            _ATD1CTL23.Overlap_STR.ATD1CTL2STR.Bits.ETRIGLE
    #define ATD1CTL2_AWAI               _ATD1CTL23.Overlap_STR.ATD1CTL2STR.Bits.AWAI
    #define ATD1CTL2_AFFC               _ATD1CTL23.Overlap_STR.ATD1CTL2STR.Bits.AFFC
    #define ATD1CTL2_ADPU               _ATD1CTL23.Overlap_STR.ATD1CTL2STR.Bits.ADPU
    
    
    #define ATD1CTL2_ASCIF_MASK         1
    #define ATD1CTL2_ASCIE_MASK         2
    #define ATD1CTL2_ETRIGE_MASK        4
    #define ATD1CTL2_ETRIGP_MASK        8
    #define ATD1CTL2_ETRIGLE_MASK       16
    #define ATD1CTL2_AWAI_MASK          32
    #define ATD1CTL2_AFFC_MASK          64
    #define ATD1CTL2_ADPU_MASK          128


     ATD1CTL3 - ATD 1 Control Register 3; 0x00000083 
    union {
      byte Byte;
      struct {
        byte FRZ0        1;                                        Background Debug Freeze Enable Bit 0 
        byte FRZ1        1;                                        Background Debug Freeze Enable Bit 1 
        byte FIFO        1;                                        Result Register FIFO Mode 
        byte S1C         1;                                        Conversion Sequence Length 1 
        byte S2C         1;                                        Conversion Sequence Length 2 
        byte S4C         1;                                        Conversion Sequence Length 4 
        byte S8C         1;                                        Conversion Sequence Length 8 
        byte             1; 
      } Bits;
      struct {
        byte grpFRZ 2;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } ATD1CTL3STR;
    #define ATD1CTL3                    _ATD1CTL23.Overlap_STR.ATD1CTL3STR.Byte
    #define ATD1CTL3_FRZ0               _ATD1CTL23.Overlap_STR.ATD1CTL3STR.Bits.FRZ0
    #define ATD1CTL3_FRZ1               _ATD1CTL23.Overlap_STR.ATD1CTL3STR.Bits.FRZ1
    #define ATD1CTL3_FIFO               _ATD1CTL23.Overlap_STR.ATD1CTL3STR.Bits.FIFO
    #define ATD1CTL3_S1C                _ATD1CTL23.Overlap_STR.ATD1CTL3STR.Bits.S1C
    #define ATD1CTL3_S2C                _ATD1CTL23.Overlap_STR.ATD1CTL3STR.Bits.S2C
    #define ATD1CTL3_S4C                _ATD1CTL23.Overlap_STR.ATD1CTL3STR.Bits.S4C
    #define ATD1CTL3_S8C                _ATD1CTL23.Overlap_STR.ATD1CTL3STR.Bits.S8C
    
    #define ATD1CTL3_FRZ                _ATD1CTL23.Overlap_STR.ATD1CTL3STR.MergedBits.grpFRZ
    
    #define ATD1CTL3_FRZ0_MASK          1
    #define ATD1CTL3_FRZ1_MASK          2
    #define ATD1CTL3_FIFO_MASK          4
    #define ATD1CTL3_S1C_MASK           8
    #define ATD1CTL3_S2C_MASK           16
    #define ATD1CTL3_S4C_MASK           32
    #define ATD1CTL3_S8C_MASK           64
    #define ATD1CTL3_FRZ_MASK           3
    #define ATD1CTL3_FRZ_BITNUM         0

  } Overlap_STR;

  struct {
    word FRZ0        1;                                        Background Debug Freeze Enable Bit 0 
    word FRZ1        1;                                        Background Debug Freeze Enable Bit 1 
    word FIFO        1;                                        Result Register FIFO Mode 
    word S1C         1;                                        Conversion Sequence Length 1 
    word S2C         1;                                        Conversion Sequence Length 2 
    word S4C         1;                                        Conversion Sequence Length 4 
    word S8C         1;                                        Conversion Sequence Length 8 
    word             1; 
    word ASCIF       1;                                        ATD 1 Sequence Complete Interrupt Flag 
    word ASCIE       1;                                        ATD 1 Sequence Complete Interrupt Enable 
    word ETRIGE      1;                                        External Trigger Mode enable 
    word ETRIGP      1;                                        External Trigger Polarity 
    word ETRIGLE     1;                                        External Trigger LevelEdge control 
    word AWAI        1;                                        ATD Power Down in Wait Mode 
    word AFFC        1;                                        ATD Fast Conversion Complete Flag Clear 
    word ADPU        1;                                        ATD Disable  Power Down 
  } Bits;
  struct {
    word grpFRZ  2;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} ATD1CTL23STR;
extern volatile ATD1CTL23STR _ATD1CTL23 @(REG_BASE + 0x00000082);
#define ATD1CTL23                       _ATD1CTL23.Word
#define ATD1CTL23_FRZ0                  _ATD1CTL23.Bits.FRZ0
#define ATD1CTL23_FRZ1                  _ATD1CTL23.Bits.FRZ1
#define ATD1CTL23_FIFO                  _ATD1CTL23.Bits.FIFO
#define ATD1CTL23_S1C                   _ATD1CTL23.Bits.S1C
#define ATD1CTL23_S2C                   _ATD1CTL23.Bits.S2C
#define ATD1CTL23_S4C                   _ATD1CTL23.Bits.S4C
#define ATD1CTL23_S8C                   _ATD1CTL23.Bits.S8C
#define ATD1CTL23_ASCIF                 _ATD1CTL23.Bits.ASCIF
#define ATD1CTL23_ASCIE                 _ATD1CTL23.Bits.ASCIE
#define ATD1CTL23_ETRIGE                _ATD1CTL23.Bits.ETRIGE
#define ATD1CTL23_ETRIGP                _ATD1CTL23.Bits.ETRIGP
#define ATD1CTL23_ETRIGLE               _ATD1CTL23.Bits.ETRIGLE
#define ATD1CTL23_AWAI                  _ATD1CTL23.Bits.AWAI
#define ATD1CTL23_AFFC                  _ATD1CTL23.Bits.AFFC
#define ATD1CTL23_ADPU                  _ATD1CTL23.Bits.ADPU
#define ATD1CTL23_FRZ                   _ATD1CTL23.MergedBits.grpFRZ

#define ATD1CTL23_FRZ0_MASK             1
#define ATD1CTL23_FRZ1_MASK             2
#define ATD1CTL23_FIFO_MASK             4
#define ATD1CTL23_S1C_MASK              8
#define ATD1CTL23_S2C_MASK              16
#define ATD1CTL23_S4C_MASK              32
#define ATD1CTL23_S8C_MASK              64
#define ATD1CTL23_ASCIF_MASK            256
#define ATD1CTL23_ASCIE_MASK            512
#define ATD1CTL23_ETRIGE_MASK           1024
#define ATD1CTL23_ETRIGP_MASK           2048
#define ATD1CTL23_ETRIGLE_MASK          4096
#define ATD1CTL23_AWAI_MASK             8192
#define ATD1CTL23_AFFC_MASK             16384
#define ATD1CTL23_ADPU_MASK             32768
#define ATD1CTL23_FRZ_MASK              3
#define ATD1CTL23_FRZ_BITNUM            0


 ATD1CTL45 - ATD 1 Control Register 45; 0x00000084 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1CTL4 - ATD 1 Control Register 4; 0x00000084 
    union {
      byte Byte;
      struct {
        byte PRS0        1;                                        ATD Clock Prescaler 0 
        byte PRS1        1;                                        ATD Clock Prescaler 1 
        byte PRS2        1;                                        ATD Clock Prescaler 2 
        byte PRS3        1;                                        ATD Clock Prescaler 3 
        byte PRS4        1;                                        ATD Clock Prescaler 4 
        byte SMP0        1;                                        Sample Time Select 0 
        byte SMP1        1;                                        Sample Time Select 1 
        byte SRES8       1;                                        ATD Resolution Select 
      } Bits;
      struct {
        byte grpPRS 5;
        byte grpSMP 2;
        byte grpSRES_8 1;
      } MergedBits;
    } ATD1CTL4STR;
    #define ATD1CTL4                    _ATD1CTL45.Overlap_STR.ATD1CTL4STR.Byte
    #define ATD1CTL4_PRS0               _ATD1CTL45.Overlap_STR.ATD1CTL4STR.Bits.PRS0
    #define ATD1CTL4_PRS1               _ATD1CTL45.Overlap_STR.ATD1CTL4STR.Bits.PRS1
    #define ATD1CTL4_PRS2               _ATD1CTL45.Overlap_STR.ATD1CTL4STR.Bits.PRS2
    #define ATD1CTL4_PRS3               _ATD1CTL45.Overlap_STR.ATD1CTL4STR.Bits.PRS3
    #define ATD1CTL4_PRS4               _ATD1CTL45.Overlap_STR.ATD1CTL4STR.Bits.PRS4
    #define ATD1CTL4_SMP0               _ATD1CTL45.Overlap_STR.ATD1CTL4STR.Bits.SMP0
    #define ATD1CTL4_SMP1               _ATD1CTL45.Overlap_STR.ATD1CTL4STR.Bits.SMP1
    #define ATD1CTL4_SRES8              _ATD1CTL45.Overlap_STR.ATD1CTL4STR.Bits.SRES8
    
    #define ATD1CTL4_PRS                _ATD1CTL45.Overlap_STR.ATD1CTL4STR.MergedBits.grpPRS
    #define ATD1CTL4_SMP                _ATD1CTL45.Overlap_STR.ATD1CTL4STR.MergedBits.grpSMP
    
    #define ATD1CTL4_PRS0_MASK          1
    #define ATD1CTL4_PRS1_MASK          2
    #define ATD1CTL4_PRS2_MASK          4
    #define ATD1CTL4_PRS3_MASK          8
    #define ATD1CTL4_PRS4_MASK          16
    #define ATD1CTL4_SMP0_MASK          32
    #define ATD1CTL4_SMP1_MASK          64
    #define ATD1CTL4_SRES8_MASK         128
    #define ATD1CTL4_PRS_MASK           31
    #define ATD1CTL4_PRS_BITNUM         0
    #define ATD1CTL4_SMP_MASK           96
    #define ATD1CTL4_SMP_BITNUM         5


     ATD1CTL5 - ATD 1 Control Register 5; 0x00000085 
    union {
      byte Byte;
      struct {
        byte CA          1;                                        Analog Input Channel Select Code A 
        byte CB          1;                                        Analog Input Channel Select Code B 
        byte CC          1;                                        Analog Input Channel Select Code C 
        byte CD          1;                                        Analog Input Channel Select Code D 
        byte MULT        1;                                        Multi-Channel Sample Mode 
        byte SCAN        1;                                        Continuous Conversion Sequence Mode 
        byte DSGN        1;                                        SignedUnsigned Result Data Mode 
        byte DJM         1;                                        Result Register Data Justification Mode 
      } Bits;
      struct {
        byte grpCx 4;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } ATD1CTL5STR;
    #define ATD1CTL5                    _ATD1CTL45.Overlap_STR.ATD1CTL5STR.Byte
    #define ATD1CTL5_CA                 _ATD1CTL45.Overlap_STR.ATD1CTL5STR.Bits.CA
    #define ATD1CTL5_CB                 _ATD1CTL45.Overlap_STR.ATD1CTL5STR.Bits.CB
    #define ATD1CTL5_CC                 _ATD1CTL45.Overlap_STR.ATD1CTL5STR.Bits.CC
    #define ATD1CTL5_CD                 _ATD1CTL45.Overlap_STR.ATD1CTL5STR.Bits.CD
    #define ATD1CTL5_MULT               _ATD1CTL45.Overlap_STR.ATD1CTL5STR.Bits.MULT
    #define ATD1CTL5_SCAN               _ATD1CTL45.Overlap_STR.ATD1CTL5STR.Bits.SCAN
    #define ATD1CTL5_DSGN               _ATD1CTL45.Overlap_STR.ATD1CTL5STR.Bits.DSGN
    #define ATD1CTL5_DJM                _ATD1CTL45.Overlap_STR.ATD1CTL5STR.Bits.DJM
    
    #define ATD1CTL5_Cx                 _ATD1CTL45.Overlap_STR.ATD1CTL5STR.MergedBits.grpCx
    
    #define ATD1CTL5_CA_MASK            1
    #define ATD1CTL5_CB_MASK            2
    #define ATD1CTL5_CC_MASK            4
    #define ATD1CTL5_CD_MASK            8
    #define ATD1CTL5_MULT_MASK          16
    #define ATD1CTL5_SCAN_MASK          32
    #define ATD1CTL5_DSGN_MASK          64
    #define ATD1CTL5_DJM_MASK           128
    #define ATD1CTL5_Cx_MASK            15
    #define ATD1CTL5_Cx_BITNUM          0

  } Overlap_STR;

  struct {
    word CA          1;                                        Analog Input Channel Select Code A 
    word CB          1;                                        Analog Input Channel Select Code B 
    word CC          1;                                        Analog Input Channel Select Code C 
    word CD          1;                                        Analog Input Channel Select Code D 
    word MULT        1;                                        Multi-Channel Sample Mode 
    word SCAN        1;                                        Continuous Conversion Sequence Mode 
    word DSGN        1;                                        SignedUnsigned Result Data Mode 
    word DJM         1;                                        Result Register Data Justification Mode 
    word PRS0        1;                                        ATD Clock Prescaler 0 
    word PRS1        1;                                        ATD Clock Prescaler 1 
    word PRS2        1;                                        ATD Clock Prescaler 2 
    word PRS3        1;                                        ATD Clock Prescaler 3 
    word PRS4        1;                                        ATD Clock Prescaler 4 
    word SMP0        1;                                        Sample Time Select 0 
    word SMP1        1;                                        Sample Time Select 1 
    word SRES8       1;                                        ATD Resolution Select 
  } Bits;
  struct {
    word grpCx   4;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpPRS  5;
    word grpSMP  2;
    word grpSRES_8 1;
  } MergedBits;
} ATD1CTL45STR;
extern volatile ATD1CTL45STR _ATD1CTL45 @(REG_BASE + 0x00000084);
#define ATD1CTL45                       _ATD1CTL45.Word
#define ATD1CTL45_CA                    _ATD1CTL45.Bits.CA
#define ATD1CTL45_CB                    _ATD1CTL45.Bits.CB
#define ATD1CTL45_CC                    _ATD1CTL45.Bits.CC
#define ATD1CTL45_CD                    _ATD1CTL45.Bits.CD
#define ATD1CTL45_MULT                  _ATD1CTL45.Bits.MULT
#define ATD1CTL45_SCAN                  _ATD1CTL45.Bits.SCAN
#define ATD1CTL45_DSGN                  _ATD1CTL45.Bits.DSGN
#define ATD1CTL45_DJM                   _ATD1CTL45.Bits.DJM
#define ATD1CTL45_PRS0                  _ATD1CTL45.Bits.PRS0
#define ATD1CTL45_PRS1                  _ATD1CTL45.Bits.PRS1
#define ATD1CTL45_PRS2                  _ATD1CTL45.Bits.PRS2
#define ATD1CTL45_PRS3                  _ATD1CTL45.Bits.PRS3
#define ATD1CTL45_PRS4                  _ATD1CTL45.Bits.PRS4
#define ATD1CTL45_SMP0                  _ATD1CTL45.Bits.SMP0
#define ATD1CTL45_SMP1                  _ATD1CTL45.Bits.SMP1
#define ATD1CTL45_SRES8                 _ATD1CTL45.Bits.SRES8
#define ATD1CTL45_Cx                    _ATD1CTL45.MergedBits.grpCx
#define ATD1CTL45_PRS                   _ATD1CTL45.MergedBits.grpPRS
#define ATD1CTL45_SMP                   _ATD1CTL45.MergedBits.grpSMP

#define ATD1CTL45_CA_MASK               1
#define ATD1CTL45_CB_MASK               2
#define ATD1CTL45_CC_MASK               4
#define ATD1CTL45_CD_MASK               8
#define ATD1CTL45_MULT_MASK             16
#define ATD1CTL45_SCAN_MASK             32
#define ATD1CTL45_DSGN_MASK             64
#define ATD1CTL45_DJM_MASK              128
#define ATD1CTL45_PRS0_MASK             256
#define ATD1CTL45_PRS1_MASK             512
#define ATD1CTL45_PRS2_MASK             1024
#define ATD1CTL45_PRS3_MASK             2048
#define ATD1CTL45_PRS4_MASK             4096
#define ATD1CTL45_SMP0_MASK             8192
#define ATD1CTL45_SMP1_MASK             16384
#define ATD1CTL45_SRES8_MASK            32768
#define ATD1CTL45_Cx_MASK               15
#define ATD1CTL45_Cx_BITNUM             0
#define ATD1CTL45_PRS_MASK              7936
#define ATD1CTL45_PRS_BITNUM            8
#define ATD1CTL45_SMP_MASK              24576
#define ATD1CTL45_SMP_BITNUM            13


 ATD1STAT0 - ATD 1 Status Register 0; 0x00000086 
typedef union {
  byte Byte;
  struct {
    byte CC0         1;                                        Conversion Counter 0 
    byte CC1         1;                                        Conversion Counter 1 
    byte CC2         1;                                        Conversion Counter 2 
    byte CC3         1;                                        Conversion Counter 3 
    byte FIFOR       1;                                        FIFO Over Run Flag 
    byte ETORF       1;                                        External Trigger Overrun Flag 
    byte             1; 
    byte SCF         1;                                        Sequence Complete Flag 
  } Bits;
  struct {
    byte grpCC   4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} ATD1STAT0STR;
extern volatile ATD1STAT0STR _ATD1STAT0 @(REG_BASE + 0x00000086);
#define ATD1STAT0                       _ATD1STAT0.Byte
#define ATD1STAT0_CC0                   _ATD1STAT0.Bits.CC0
#define ATD1STAT0_CC1                   _ATD1STAT0.Bits.CC1
#define ATD1STAT0_CC2                   _ATD1STAT0.Bits.CC2
#define ATD1STAT0_CC3                   _ATD1STAT0.Bits.CC3
#define ATD1STAT0_FIFOR                 _ATD1STAT0.Bits.FIFOR
#define ATD1STAT0_ETORF                 _ATD1STAT0.Bits.ETORF
#define ATD1STAT0_SCF                   _ATD1STAT0.Bits.SCF
#define ATD1STAT0_CC                    _ATD1STAT0.MergedBits.grpCC

#define ATD1STAT0_CC0_MASK              1
#define ATD1STAT0_CC1_MASK              2
#define ATD1STAT0_CC2_MASK              4
#define ATD1STAT0_CC3_MASK              8
#define ATD1STAT0_FIFOR_MASK            16
#define ATD1STAT0_ETORF_MASK            32
#define ATD1STAT0_SCF_MASK              128
#define ATD1STAT0_CC_MASK               15
#define ATD1STAT0_CC_BITNUM             0


 ATD1TEST1 - ATD1 Test Register; 0x00000089 
typedef union {
  byte Byte;
  struct {
    byte SC          1;                                        Special Channel Conversion Bit 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} ATD1TEST1STR;
extern volatile ATD1TEST1STR _ATD1TEST1 @(REG_BASE + 0x00000089);
#define ATD1TEST1                       _ATD1TEST1.Byte
#define ATD1TEST1_SC                    _ATD1TEST1.Bits.SC

#define ATD1TEST1_SC_MASK               1


 ATD1STAT2 - ATD 1 Status Register 2; 0x0000008A 
typedef union {
  byte Byte;
  struct {
    byte CCF8        1;                                        Conversion Complete Flag 8 
    byte CCF9        1;                                        Conversion Complete Flag 9 
    byte CCF10       1;                                        Conversion Complete Flag 10 
    byte CCF11       1;                                        Conversion Complete Flag 11 
    byte CCF12       1;                                        Conversion Complete Flag 12 
    byte CCF13       1;                                        Conversion Complete Flag 13 
    byte CCF14       1;                                        Conversion Complete Flag 14 
    byte CCF15       1;                                        Conversion Complete Flag 15 
  } Bits;
} ATD1STAT2STR;
extern volatile ATD1STAT2STR _ATD1STAT2 @(REG_BASE + 0x0000008A);
#define ATD1STAT2                       _ATD1STAT2.Byte
#define ATD1STAT2_CCF8                  _ATD1STAT2.Bits.CCF8
#define ATD1STAT2_CCF9                  _ATD1STAT2.Bits.CCF9
#define ATD1STAT2_CCF10                 _ATD1STAT2.Bits.CCF10
#define ATD1STAT2_CCF11                 _ATD1STAT2.Bits.CCF11
#define ATD1STAT2_CCF12                 _ATD1STAT2.Bits.CCF12
#define ATD1STAT2_CCF13                 _ATD1STAT2.Bits.CCF13
#define ATD1STAT2_CCF14                 _ATD1STAT2.Bits.CCF14
#define ATD1STAT2_CCF15                 _ATD1STAT2.Bits.CCF15

#define ATD1STAT2_CCF8_MASK             1
#define ATD1STAT2_CCF9_MASK             2
#define ATD1STAT2_CCF10_MASK            4
#define ATD1STAT2_CCF11_MASK            8
#define ATD1STAT2_CCF12_MASK            16
#define ATD1STAT2_CCF13_MASK            32
#define ATD1STAT2_CCF14_MASK            64
#define ATD1STAT2_CCF15_MASK            128


 ATD1STAT1 - ATD 1 Status Register 1; 0x0000008B 
typedef union {
  byte Byte;
  struct {
    byte CCF0        1;                                        Conversion Complete Flag 0 
    byte CCF1        1;                                        Conversion Complete Flag 1 
    byte CCF2        1;                                        Conversion Complete Flag 2 
    byte CCF3        1;                                        Conversion Complete Flag 3 
    byte CCF4        1;                                        Conversion Complete Flag 4 
    byte CCF5        1;                                        Conversion Complete Flag 5 
    byte CCF6        1;                                        Conversion Complete Flag 6 
    byte CCF7        1;                                        Conversion Complete Flag 7 
  } Bits;
} ATD1STAT1STR;
extern volatile ATD1STAT1STR _ATD1STAT1 @(REG_BASE + 0x0000008B);
#define ATD1STAT1                       _ATD1STAT1.Byte
#define ATD1STAT1_CCF0                  _ATD1STAT1.Bits.CCF0
#define ATD1STAT1_CCF1                  _ATD1STAT1.Bits.CCF1
#define ATD1STAT1_CCF2                  _ATD1STAT1.Bits.CCF2
#define ATD1STAT1_CCF3                  _ATD1STAT1.Bits.CCF3
#define ATD1STAT1_CCF4                  _ATD1STAT1.Bits.CCF4
#define ATD1STAT1_CCF5                  _ATD1STAT1.Bits.CCF5
#define ATD1STAT1_CCF6                  _ATD1STAT1.Bits.CCF6
#define ATD1STAT1_CCF7                  _ATD1STAT1.Bits.CCF7

#define ATD1STAT1_CCF0_MASK             1
#define ATD1STAT1_CCF1_MASK             2
#define ATD1STAT1_CCF2_MASK             4
#define ATD1STAT1_CCF3_MASK             8
#define ATD1STAT1_CCF4_MASK             16
#define ATD1STAT1_CCF5_MASK             32
#define ATD1STAT1_CCF6_MASK             64
#define ATD1STAT1_CCF7_MASK             128


 ATD1DIEN - ATD 1 Input Enable Register; 0x0000008C 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DIEN0 - ATD 1 Input Enable Register 0; 0x0000008C 
    union {
      byte Byte;
      struct {
        byte IEN8        1;                                        ATD Digital Input Enable on channel 8 
        byte IEN9        1;                                        ATD Digital Input Enable on channel 9 
        byte IEN10       1;                                        ATD Digital Input Enable on channel 10 
        byte IEN11       1;                                        ATD Digital Input Enable on channel 11 
        byte IEN12       1;                                        ATD Digital Input Enable on channel 12 
        byte IEN13       1;                                        ATD Digital Input Enable on channel 13 
        byte IEN14       1;                                        ATD Digital Input Enable on channel 14 
        byte IEN15       1;                                        ATD Digital Input Enable on channel 15 
      } Bits;
    } ATD1DIEN0STR;
    #define ATD1DIEN0                   _ATD1DIEN.Overlap_STR.ATD1DIEN0STR.Byte
    #define ATD1DIEN0_IEN8              _ATD1DIEN.Overlap_STR.ATD1DIEN0STR.Bits.IEN8
    #define ATD1DIEN0_IEN9              _ATD1DIEN.Overlap_STR.ATD1DIEN0STR.Bits.IEN9
    #define ATD1DIEN0_IEN10             _ATD1DIEN.Overlap_STR.ATD1DIEN0STR.Bits.IEN10
    #define ATD1DIEN0_IEN11             _ATD1DIEN.Overlap_STR.ATD1DIEN0STR.Bits.IEN11
    #define ATD1DIEN0_IEN12             _ATD1DIEN.Overlap_STR.ATD1DIEN0STR.Bits.IEN12
    #define ATD1DIEN0_IEN13             _ATD1DIEN.Overlap_STR.ATD1DIEN0STR.Bits.IEN13
    #define ATD1DIEN0_IEN14             _ATD1DIEN.Overlap_STR.ATD1DIEN0STR.Bits.IEN14
    #define ATD1DIEN0_IEN15             _ATD1DIEN.Overlap_STR.ATD1DIEN0STR.Bits.IEN15
    
     ATD1DIEN_ARR Access 2 ATD1DIENx registers in an array 
    #define ATD1DIEN_ARR                ((volatile byte ) &ATD1DIEN0)
    
    #define ATD1DIEN0_IEN8_MASK         1
    #define ATD1DIEN0_IEN9_MASK         2
    #define ATD1DIEN0_IEN10_MASK        4
    #define ATD1DIEN0_IEN11_MASK        8
    #define ATD1DIEN0_IEN12_MASK        16
    #define ATD1DIEN0_IEN13_MASK        32
    #define ATD1DIEN0_IEN14_MASK        64
    #define ATD1DIEN0_IEN15_MASK        128


     ATD1DIEN1 - ATD 1 Input Enable Register 1; 0x0000008D 
    union {
      byte Byte;
      struct {
        byte IEN0        1;                                        ATD Digital Input Enable on channel 0 
        byte IEN1        1;                                        ATD Digital Input Enable on channel 1 
        byte IEN2        1;                                        ATD Digital Input Enable on channel 2 
        byte IEN3        1;                                        ATD Digital Input Enable on channel 3 
        byte IEN4        1;                                        ATD Digital Input Enable on channel 4 
        byte IEN5        1;                                        ATD Digital Input Enable on channel 5 
        byte IEN6        1;                                        ATD Digital Input Enable on channel 6 
        byte IEN7        1;                                        ATD Digital Input Enable on channel 7 
      } Bits;
    } ATD1DIEN1STR;
    #define ATD1DIEN1                   _ATD1DIEN.Overlap_STR.ATD1DIEN1STR.Byte
    #define ATD1DIEN1_IEN0              _ATD1DIEN.Overlap_STR.ATD1DIEN1STR.Bits.IEN0
    #define ATD1DIEN1_IEN1              _ATD1DIEN.Overlap_STR.ATD1DIEN1STR.Bits.IEN1
    #define ATD1DIEN1_IEN2              _ATD1DIEN.Overlap_STR.ATD1DIEN1STR.Bits.IEN2
    #define ATD1DIEN1_IEN3              _ATD1DIEN.Overlap_STR.ATD1DIEN1STR.Bits.IEN3
    #define ATD1DIEN1_IEN4              _ATD1DIEN.Overlap_STR.ATD1DIEN1STR.Bits.IEN4
    #define ATD1DIEN1_IEN5              _ATD1DIEN.Overlap_STR.ATD1DIEN1STR.Bits.IEN5
    #define ATD1DIEN1_IEN6              _ATD1DIEN.Overlap_STR.ATD1DIEN1STR.Bits.IEN6
    #define ATD1DIEN1_IEN7              _ATD1DIEN.Overlap_STR.ATD1DIEN1STR.Bits.IEN7
    
    
    #define ATD1DIEN1_IEN0_MASK         1
    #define ATD1DIEN1_IEN1_MASK         2
    #define ATD1DIEN1_IEN2_MASK         4
    #define ATD1DIEN1_IEN3_MASK         8
    #define ATD1DIEN1_IEN4_MASK         16
    #define ATD1DIEN1_IEN5_MASK         32
    #define ATD1DIEN1_IEN6_MASK         64
    #define ATD1DIEN1_IEN7_MASK         128

  } Overlap_STR;

  struct {
    word IEN0        1;                                        ATD Digital Input Enable on channel 0 
    word IEN1        1;                                        ATD Digital Input Enable on channel 1 
    word IEN2        1;                                        ATD Digital Input Enable on channel 2 
    word IEN3        1;                                        ATD Digital Input Enable on channel 3 
    word IEN4        1;                                        ATD Digital Input Enable on channel 4 
    word IEN5        1;                                        ATD Digital Input Enable on channel 5 
    word IEN6        1;                                        ATD Digital Input Enable on channel 6 
    word IEN7        1;                                        ATD Digital Input Enable on channel 7 
    word IEN8        1;                                        ATD Digital Input Enable on channel 8 
    word IEN9        1;                                        ATD Digital Input Enable on channel 9 
    word IEN10       1;                                        ATD Digital Input Enable on channel 10 
    word IEN11       1;                                        ATD Digital Input Enable on channel 11 
    word IEN12       1;                                        ATD Digital Input Enable on channel 12 
    word IEN13       1;                                        ATD Digital Input Enable on channel 13 
    word IEN14       1;                                        ATD Digital Input Enable on channel 14 
    word IEN15       1;                                        ATD Digital Input Enable on channel 15 
  } Bits;
} ATD1DIENSTR;
extern volatile ATD1DIENSTR _ATD1DIEN @(REG_BASE + 0x0000008C);
#define ATD1DIEN                        _ATD1DIEN.Word
#define ATD1DIEN_IEN0                   _ATD1DIEN.Bits.IEN0
#define ATD1DIEN_IEN1                   _ATD1DIEN.Bits.IEN1
#define ATD1DIEN_IEN2                   _ATD1DIEN.Bits.IEN2
#define ATD1DIEN_IEN3                   _ATD1DIEN.Bits.IEN3
#define ATD1DIEN_IEN4                   _ATD1DIEN.Bits.IEN4
#define ATD1DIEN_IEN5                   _ATD1DIEN.Bits.IEN5
#define ATD1DIEN_IEN6                   _ATD1DIEN.Bits.IEN6
#define ATD1DIEN_IEN7                   _ATD1DIEN.Bits.IEN7
#define ATD1DIEN_IEN8                   _ATD1DIEN.Bits.IEN8
#define ATD1DIEN_IEN9                   _ATD1DIEN.Bits.IEN9
#define ATD1DIEN_IEN10                  _ATD1DIEN.Bits.IEN10
#define ATD1DIEN_IEN11                  _ATD1DIEN.Bits.IEN11
#define ATD1DIEN_IEN12                  _ATD1DIEN.Bits.IEN12
#define ATD1DIEN_IEN13                  _ATD1DIEN.Bits.IEN13
#define ATD1DIEN_IEN14                  _ATD1DIEN.Bits.IEN14
#define ATD1DIEN_IEN15                  _ATD1DIEN.Bits.IEN15

#define ATD1DIEN_IEN0_MASK              1
#define ATD1DIEN_IEN1_MASK              2
#define ATD1DIEN_IEN2_MASK              4
#define ATD1DIEN_IEN3_MASK              8
#define ATD1DIEN_IEN4_MASK              16
#define ATD1DIEN_IEN5_MASK              32
#define ATD1DIEN_IEN6_MASK              64
#define ATD1DIEN_IEN7_MASK              128
#define ATD1DIEN_IEN8_MASK              256
#define ATD1DIEN_IEN9_MASK              512
#define ATD1DIEN_IEN10_MASK             1024
#define ATD1DIEN_IEN11_MASK             2048
#define ATD1DIEN_IEN12_MASK             4096
#define ATD1DIEN_IEN13_MASK             8192
#define ATD1DIEN_IEN14_MASK             16384
#define ATD1DIEN_IEN15_MASK             32768


 ATD1PTAD - ATD1 Port AD Register; 0x0000008E 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1PTAD0 - ATD1 Port AD0 Register; 0x0000008E 
    union {
      byte Byte;
      struct {
        byte PTAD8       1;                                        AD Channel 8 (AN8) Digital Input 
        byte PTAD9       1;                                        AD Channel 9 (AN9) Digital Input 
        byte PTAD10      1;                                        AD Channel 10 (AN10) Digital Input 
        byte PTAD11      1;                                        AD Channel 11 (AN11) Digital Input 
        byte PTAD12      1;                                        AD Channel 12 (AN12) Digital Input 
        byte PTAD13      1;                                        AD Channel 13 (AN13) Digital Input 
        byte PTAD14      1;                                        AD Channel 14 (AN14) Digital Input 
        byte PTAD15      1;                                        AD Channel 15 (AN15) Digital Input 
      } Bits;
    } ATD1PTAD0STR;
    #define ATD1PTAD0                   _ATD1PTAD.Overlap_STR.ATD1PTAD0STR.Byte
    #define ATD1PTAD0_PTAD8             _ATD1PTAD.Overlap_STR.ATD1PTAD0STR.Bits.PTAD8
    #define ATD1PTAD0_PTAD9             _ATD1PTAD.Overlap_STR.ATD1PTAD0STR.Bits.PTAD9
    #define ATD1PTAD0_PTAD10            _ATD1PTAD.Overlap_STR.ATD1PTAD0STR.Bits.PTAD10
    #define ATD1PTAD0_PTAD11            _ATD1PTAD.Overlap_STR.ATD1PTAD0STR.Bits.PTAD11
    #define ATD1PTAD0_PTAD12            _ATD1PTAD.Overlap_STR.ATD1PTAD0STR.Bits.PTAD12
    #define ATD1PTAD0_PTAD13            _ATD1PTAD.Overlap_STR.ATD1PTAD0STR.Bits.PTAD13
    #define ATD1PTAD0_PTAD14            _ATD1PTAD.Overlap_STR.ATD1PTAD0STR.Bits.PTAD14
    #define ATD1PTAD0_PTAD15            _ATD1PTAD.Overlap_STR.ATD1PTAD0STR.Bits.PTAD15
    
     ATD1PTAD_ARR Access 2 ATD1PTADx registers in an array 
    #define ATD1PTAD_ARR                ((volatile byte ) &ATD1PTAD0)
    
    #define ATD1PTAD0_PTAD8_MASK        1
    #define ATD1PTAD0_PTAD9_MASK        2
    #define ATD1PTAD0_PTAD10_MASK       4
    #define ATD1PTAD0_PTAD11_MASK       8
    #define ATD1PTAD0_PTAD12_MASK       16
    #define ATD1PTAD0_PTAD13_MASK       32
    #define ATD1PTAD0_PTAD14_MASK       64
    #define ATD1PTAD0_PTAD15_MASK       128


     ATD1PTAD1 - ATD1 Port AD1 Register; 0x0000008F 
    union {
      byte Byte;
      struct {
        byte PTAD0       1;                                        AD Channel 0 (AN0) Digital Input 
        byte PTAD1       1;                                        AD Channel 1 (AN1) Digital Input 
        byte PTAD2       1;                                        AD Channel 2 (AN2) Digital Input 
        byte PTAD3       1;                                        AD Channel 3 (AN3) Digital Input 
        byte PTAD4       1;                                        AD Channel 4 (AN4) Digital Input 
        byte PTAD5       1;                                        AD Channel 5 (AN5) Digital Input 
        byte PTAD6       1;                                        AD Channel 6 (AN6) Digital Input 
        byte PTAD7       1;                                        AD Channel 7 (AN7) Digital Input 
      } Bits;
    } ATD1PTAD1STR;
    #define ATD1PTAD1                   _ATD1PTAD.Overlap_STR.ATD1PTAD1STR.Byte
    #define ATD1PTAD1_PTAD0             _ATD1PTAD.Overlap_STR.ATD1PTAD1STR.Bits.PTAD0
    #define ATD1PTAD1_PTAD1             _ATD1PTAD.Overlap_STR.ATD1PTAD1STR.Bits.PTAD1
    #define ATD1PTAD1_PTAD2             _ATD1PTAD.Overlap_STR.ATD1PTAD1STR.Bits.PTAD2
    #define ATD1PTAD1_PTAD3             _ATD1PTAD.Overlap_STR.ATD1PTAD1STR.Bits.PTAD3
    #define ATD1PTAD1_PTAD4             _ATD1PTAD.Overlap_STR.ATD1PTAD1STR.Bits.PTAD4
    #define ATD1PTAD1_PTAD5             _ATD1PTAD.Overlap_STR.ATD1PTAD1STR.Bits.PTAD5
    #define ATD1PTAD1_PTAD6             _ATD1PTAD.Overlap_STR.ATD1PTAD1STR.Bits.PTAD6
    #define ATD1PTAD1_PTAD7             _ATD1PTAD.Overlap_STR.ATD1PTAD1STR.Bits.PTAD7
    
    
    #define ATD1PTAD1_PTAD0_MASK        1
    #define ATD1PTAD1_PTAD1_MASK        2
    #define ATD1PTAD1_PTAD2_MASK        4
    #define ATD1PTAD1_PTAD3_MASK        8
    #define ATD1PTAD1_PTAD4_MASK        16
    #define ATD1PTAD1_PTAD5_MASK        32
    #define ATD1PTAD1_PTAD6_MASK        64
    #define ATD1PTAD1_PTAD7_MASK        128

  } Overlap_STR;

  struct {
    word PTAD0       1;                                        AD Channel 0 (AN0) Digital Input 
    word PTAD1       1;                                        AD Channel 1 (AN1) Digital Input 
    word PTAD2       1;                                        AD Channel 2 (AN2) Digital Input 
    word PTAD3       1;                                        AD Channel 3 (AN3) Digital Input 
    word PTAD4       1;                                        AD Channel 4 (AN4) Digital Input 
    word PTAD5       1;                                        AD Channel 5 (AN5) Digital Input 
    word PTAD6       1;                                        AD Channel 6 (AN6) Digital Input 
    word PTAD7       1;                                        AD Channel 7 (AN7) Digital Input 
    word PTAD8       1;                                        AD Channel 8 (AN8) Digital Input 
    word PTAD9       1;                                        AD Channel 9 (AN9) Digital Input 
    word PTAD10      1;                                        AD Channel 10 (AN10) Digital Input 
    word PTAD11      1;                                        AD Channel 11 (AN11) Digital Input 
    word PTAD12      1;                                        AD Channel 12 (AN12) Digital Input 
    word PTAD13      1;                                        AD Channel 13 (AN13) Digital Input 
    word PTAD14      1;                                        AD Channel 14 (AN14) Digital Input 
    word PTAD15      1;                                        AD Channel 15 (AN15) Digital Input 
  } Bits;
} ATD1PTADSTR;
extern volatile ATD1PTADSTR _ATD1PTAD @(REG_BASE + 0x0000008E);
#define ATD1PTAD                        _ATD1PTAD.Word
#define ATD1PTAD_PTAD0                  _ATD1PTAD.Bits.PTAD0
#define ATD1PTAD_PTAD1                  _ATD1PTAD.Bits.PTAD1
#define ATD1PTAD_PTAD2                  _ATD1PTAD.Bits.PTAD2
#define ATD1PTAD_PTAD3                  _ATD1PTAD.Bits.PTAD3
#define ATD1PTAD_PTAD4                  _ATD1PTAD.Bits.PTAD4
#define ATD1PTAD_PTAD5                  _ATD1PTAD.Bits.PTAD5
#define ATD1PTAD_PTAD6                  _ATD1PTAD.Bits.PTAD6
#define ATD1PTAD_PTAD7                  _ATD1PTAD.Bits.PTAD7
#define ATD1PTAD_PTAD8                  _ATD1PTAD.Bits.PTAD8
#define ATD1PTAD_PTAD9                  _ATD1PTAD.Bits.PTAD9
#define ATD1PTAD_PTAD10                 _ATD1PTAD.Bits.PTAD10
#define ATD1PTAD_PTAD11                 _ATD1PTAD.Bits.PTAD11
#define ATD1PTAD_PTAD12                 _ATD1PTAD.Bits.PTAD12
#define ATD1PTAD_PTAD13                 _ATD1PTAD.Bits.PTAD13
#define ATD1PTAD_PTAD14                 _ATD1PTAD.Bits.PTAD14
#define ATD1PTAD_PTAD15                 _ATD1PTAD.Bits.PTAD15

#define ATD1PTAD_PTAD0_MASK             1
#define ATD1PTAD_PTAD1_MASK             2
#define ATD1PTAD_PTAD2_MASK             4
#define ATD1PTAD_PTAD3_MASK             8
#define ATD1PTAD_PTAD4_MASK             16
#define ATD1PTAD_PTAD5_MASK             32
#define ATD1PTAD_PTAD6_MASK             64
#define ATD1PTAD_PTAD7_MASK             128
#define ATD1PTAD_PTAD8_MASK             256
#define ATD1PTAD_PTAD9_MASK             512
#define ATD1PTAD_PTAD10_MASK            1024
#define ATD1PTAD_PTAD11_MASK            2048
#define ATD1PTAD_PTAD12_MASK            4096
#define ATD1PTAD_PTAD13_MASK            8192
#define ATD1PTAD_PTAD14_MASK            16384
#define ATD1PTAD_PTAD15_MASK            32768


 ATD1DR0 - ATD 1 Conversion Result Register 0; 0x00000090 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR0H - ATD 1 Conversion Result Register 0 High; 0x00000090 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR0HSTR;
    #define ATD1DR0H                    _ATD1DR0.Overlap_STR.ATD1DR0HSTR.Byte
    #define ATD1DR0H_BIT8               _ATD1DR0.Overlap_STR.ATD1DR0HSTR.Bits.BIT8
    #define ATD1DR0H_BIT9               _ATD1DR0.Overlap_STR.ATD1DR0HSTR.Bits.BIT9
    #define ATD1DR0H_BIT10              _ATD1DR0.Overlap_STR.ATD1DR0HSTR.Bits.BIT10
    #define ATD1DR0H_BIT11              _ATD1DR0.Overlap_STR.ATD1DR0HSTR.Bits.BIT11
    #define ATD1DR0H_BIT12              _ATD1DR0.Overlap_STR.ATD1DR0HSTR.Bits.BIT12
    #define ATD1DR0H_BIT13              _ATD1DR0.Overlap_STR.ATD1DR0HSTR.Bits.BIT13
    #define ATD1DR0H_BIT14              _ATD1DR0.Overlap_STR.ATD1DR0HSTR.Bits.BIT14
    #define ATD1DR0H_BIT15              _ATD1DR0.Overlap_STR.ATD1DR0HSTR.Bits.BIT15
    
    
    #define ATD1DR0H_BIT8_MASK          1
    #define ATD1DR0H_BIT9_MASK          2
    #define ATD1DR0H_BIT10_MASK         4
    #define ATD1DR0H_BIT11_MASK         8
    #define ATD1DR0H_BIT12_MASK         16
    #define ATD1DR0H_BIT13_MASK         32
    #define ATD1DR0H_BIT14_MASK         64
    #define ATD1DR0H_BIT15_MASK         128


     ATD1DR0L - ATD 1 Conversion Result Register 0 Low; 0x00000091 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR0LSTR;
    #define ATD1DR0L                    _ATD1DR0.Overlap_STR.ATD1DR0LSTR.Byte
    #define ATD1DR0L_BIT6               _ATD1DR0.Overlap_STR.ATD1DR0LSTR.Bits.BIT6
    #define ATD1DR0L_BIT7               _ATD1DR0.Overlap_STR.ATD1DR0LSTR.Bits.BIT7
    
    #define ATD1DR0L_BIT_6              _ATD1DR0.Overlap_STR.ATD1DR0LSTR.MergedBits.grpBIT_6
    #define ATD1DR0L_BIT                ATD1DR0L_BIT_6
    
    #define ATD1DR0L_BIT6_MASK          64
    #define ATD1DR0L_BIT7_MASK          128
    #define ATD1DR0L_BIT_6_MASK         192
    #define ATD1DR0L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR0STR;
extern volatile ATD1DR0STR _ATD1DR0 @(REG_BASE + 0x00000090);
#define ATD1DR0                         _ATD1DR0.Word
#define ATD1DR0_BIT6                    _ATD1DR0.Bits.BIT6
#define ATD1DR0_BIT7                    _ATD1DR0.Bits.BIT7
#define ATD1DR0_BIT8                    _ATD1DR0.Bits.BIT8
#define ATD1DR0_BIT9                    _ATD1DR0.Bits.BIT9
#define ATD1DR0_BIT10                   _ATD1DR0.Bits.BIT10
#define ATD1DR0_BIT11                   _ATD1DR0.Bits.BIT11
#define ATD1DR0_BIT12                   _ATD1DR0.Bits.BIT12
#define ATD1DR0_BIT13                   _ATD1DR0.Bits.BIT13
#define ATD1DR0_BIT14                   _ATD1DR0.Bits.BIT14
#define ATD1DR0_BIT15                   _ATD1DR0.Bits.BIT15
 ATD1DR_ARR Access 16 ATD1DRx registers in an array 
#define ATD1DR_ARR                      ((volatile word ) &ATD1DR0)
#define ATD1DR0_BIT_6                   _ATD1DR0.MergedBits.grpBIT_6
#define ATD1DR0_BIT                     ATD1DR0_BIT_6

#define ATD1DR0_BIT6_MASK               64
#define ATD1DR0_BIT7_MASK               128
#define ATD1DR0_BIT8_MASK               256
#define ATD1DR0_BIT9_MASK               512
#define ATD1DR0_BIT10_MASK              1024
#define ATD1DR0_BIT11_MASK              2048
#define ATD1DR0_BIT12_MASK              4096
#define ATD1DR0_BIT13_MASK              8192
#define ATD1DR0_BIT14_MASK              16384
#define ATD1DR0_BIT15_MASK              32768
#define ATD1DR0_BIT_6_MASK              65472
#define ATD1DR0_BIT_6_BITNUM            6


 ATD1DR1 - ATD 1 Conversion Result Register 1; 0x00000092 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR1H - ATD 1 Conversion Result Register 1 High; 0x00000092 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR1HSTR;
    #define ATD1DR1H                    _ATD1DR1.Overlap_STR.ATD1DR1HSTR.Byte
    #define ATD1DR1H_BIT8               _ATD1DR1.Overlap_STR.ATD1DR1HSTR.Bits.BIT8
    #define ATD1DR1H_BIT9               _ATD1DR1.Overlap_STR.ATD1DR1HSTR.Bits.BIT9
    #define ATD1DR1H_BIT10              _ATD1DR1.Overlap_STR.ATD1DR1HSTR.Bits.BIT10
    #define ATD1DR1H_BIT11              _ATD1DR1.Overlap_STR.ATD1DR1HSTR.Bits.BIT11
    #define ATD1DR1H_BIT12              _ATD1DR1.Overlap_STR.ATD1DR1HSTR.Bits.BIT12
    #define ATD1DR1H_BIT13              _ATD1DR1.Overlap_STR.ATD1DR1HSTR.Bits.BIT13
    #define ATD1DR1H_BIT14              _ATD1DR1.Overlap_STR.ATD1DR1HSTR.Bits.BIT14
    #define ATD1DR1H_BIT15              _ATD1DR1.Overlap_STR.ATD1DR1HSTR.Bits.BIT15
    
    
    #define ATD1DR1H_BIT8_MASK          1
    #define ATD1DR1H_BIT9_MASK          2
    #define ATD1DR1H_BIT10_MASK         4
    #define ATD1DR1H_BIT11_MASK         8
    #define ATD1DR1H_BIT12_MASK         16
    #define ATD1DR1H_BIT13_MASK         32
    #define ATD1DR1H_BIT14_MASK         64
    #define ATD1DR1H_BIT15_MASK         128


     ATD1DR1L - ATD 1 Conversion Result Register 1 Low; 0x00000093 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR1LSTR;
    #define ATD1DR1L                    _ATD1DR1.Overlap_STR.ATD1DR1LSTR.Byte
    #define ATD1DR1L_BIT6               _ATD1DR1.Overlap_STR.ATD1DR1LSTR.Bits.BIT6
    #define ATD1DR1L_BIT7               _ATD1DR1.Overlap_STR.ATD1DR1LSTR.Bits.BIT7
    
    #define ATD1DR1L_BIT_6              _ATD1DR1.Overlap_STR.ATD1DR1LSTR.MergedBits.grpBIT_6
    #define ATD1DR1L_BIT                ATD1DR1L_BIT_6
    
    #define ATD1DR1L_BIT6_MASK          64
    #define ATD1DR1L_BIT7_MASK          128
    #define ATD1DR1L_BIT_6_MASK         192
    #define ATD1DR1L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR1STR;
extern volatile ATD1DR1STR _ATD1DR1 @(REG_BASE + 0x00000092);
#define ATD1DR1                         _ATD1DR1.Word
#define ATD1DR1_BIT6                    _ATD1DR1.Bits.BIT6
#define ATD1DR1_BIT7                    _ATD1DR1.Bits.BIT7
#define ATD1DR1_BIT8                    _ATD1DR1.Bits.BIT8
#define ATD1DR1_BIT9                    _ATD1DR1.Bits.BIT9
#define ATD1DR1_BIT10                   _ATD1DR1.Bits.BIT10
#define ATD1DR1_BIT11                   _ATD1DR1.Bits.BIT11
#define ATD1DR1_BIT12                   _ATD1DR1.Bits.BIT12
#define ATD1DR1_BIT13                   _ATD1DR1.Bits.BIT13
#define ATD1DR1_BIT14                   _ATD1DR1.Bits.BIT14
#define ATD1DR1_BIT15                   _ATD1DR1.Bits.BIT15
#define ATD1DR1_BIT_6                   _ATD1DR1.MergedBits.grpBIT_6
#define ATD1DR1_BIT                     ATD1DR1_BIT_6

#define ATD1DR1_BIT6_MASK               64
#define ATD1DR1_BIT7_MASK               128
#define ATD1DR1_BIT8_MASK               256
#define ATD1DR1_BIT9_MASK               512
#define ATD1DR1_BIT10_MASK              1024
#define ATD1DR1_BIT11_MASK              2048
#define ATD1DR1_BIT12_MASK              4096
#define ATD1DR1_BIT13_MASK              8192
#define ATD1DR1_BIT14_MASK              16384
#define ATD1DR1_BIT15_MASK              32768
#define ATD1DR1_BIT_6_MASK              65472
#define ATD1DR1_BIT_6_BITNUM            6


 ATD1DR2 - ATD 1 Conversion Result Register 2; 0x00000094 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR2H - ATD 1 Conversion Result Register 2 High; 0x00000094 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR2HSTR;
    #define ATD1DR2H                    _ATD1DR2.Overlap_STR.ATD1DR2HSTR.Byte
    #define ATD1DR2H_BIT8               _ATD1DR2.Overlap_STR.ATD1DR2HSTR.Bits.BIT8
    #define ATD1DR2H_BIT9               _ATD1DR2.Overlap_STR.ATD1DR2HSTR.Bits.BIT9
    #define ATD1DR2H_BIT10              _ATD1DR2.Overlap_STR.ATD1DR2HSTR.Bits.BIT10
    #define ATD1DR2H_BIT11              _ATD1DR2.Overlap_STR.ATD1DR2HSTR.Bits.BIT11
    #define ATD1DR2H_BIT12              _ATD1DR2.Overlap_STR.ATD1DR2HSTR.Bits.BIT12
    #define ATD1DR2H_BIT13              _ATD1DR2.Overlap_STR.ATD1DR2HSTR.Bits.BIT13
    #define ATD1DR2H_BIT14              _ATD1DR2.Overlap_STR.ATD1DR2HSTR.Bits.BIT14
    #define ATD1DR2H_BIT15              _ATD1DR2.Overlap_STR.ATD1DR2HSTR.Bits.BIT15
    
    
    #define ATD1DR2H_BIT8_MASK          1
    #define ATD1DR2H_BIT9_MASK          2
    #define ATD1DR2H_BIT10_MASK         4
    #define ATD1DR2H_BIT11_MASK         8
    #define ATD1DR2H_BIT12_MASK         16
    #define ATD1DR2H_BIT13_MASK         32
    #define ATD1DR2H_BIT14_MASK         64
    #define ATD1DR2H_BIT15_MASK         128


     ATD1DR2L - ATD 1 Conversion Result Register 2 Low; 0x00000095 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR2LSTR;
    #define ATD1DR2L                    _ATD1DR2.Overlap_STR.ATD1DR2LSTR.Byte
    #define ATD1DR2L_BIT6               _ATD1DR2.Overlap_STR.ATD1DR2LSTR.Bits.BIT6
    #define ATD1DR2L_BIT7               _ATD1DR2.Overlap_STR.ATD1DR2LSTR.Bits.BIT7
    
    #define ATD1DR2L_BIT_6              _ATD1DR2.Overlap_STR.ATD1DR2LSTR.MergedBits.grpBIT_6
    #define ATD1DR2L_BIT                ATD1DR2L_BIT_6
    
    #define ATD1DR2L_BIT6_MASK          64
    #define ATD1DR2L_BIT7_MASK          128
    #define ATD1DR2L_BIT_6_MASK         192
    #define ATD1DR2L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR2STR;
extern volatile ATD1DR2STR _ATD1DR2 @(REG_BASE + 0x00000094);
#define ATD1DR2                         _ATD1DR2.Word
#define ATD1DR2_BIT6                    _ATD1DR2.Bits.BIT6
#define ATD1DR2_BIT7                    _ATD1DR2.Bits.BIT7
#define ATD1DR2_BIT8                    _ATD1DR2.Bits.BIT8
#define ATD1DR2_BIT9                    _ATD1DR2.Bits.BIT9
#define ATD1DR2_BIT10                   _ATD1DR2.Bits.BIT10
#define ATD1DR2_BIT11                   _ATD1DR2.Bits.BIT11
#define ATD1DR2_BIT12                   _ATD1DR2.Bits.BIT12
#define ATD1DR2_BIT13                   _ATD1DR2.Bits.BIT13
#define ATD1DR2_BIT14                   _ATD1DR2.Bits.BIT14
#define ATD1DR2_BIT15                   _ATD1DR2.Bits.BIT15
#define ATD1DR2_BIT_6                   _ATD1DR2.MergedBits.grpBIT_6
#define ATD1DR2_BIT                     ATD1DR2_BIT_6

#define ATD1DR2_BIT6_MASK               64
#define ATD1DR2_BIT7_MASK               128
#define ATD1DR2_BIT8_MASK               256
#define ATD1DR2_BIT9_MASK               512
#define ATD1DR2_BIT10_MASK              1024
#define ATD1DR2_BIT11_MASK              2048
#define ATD1DR2_BIT12_MASK              4096
#define ATD1DR2_BIT13_MASK              8192
#define ATD1DR2_BIT14_MASK              16384
#define ATD1DR2_BIT15_MASK              32768
#define ATD1DR2_BIT_6_MASK              65472
#define ATD1DR2_BIT_6_BITNUM            6


 ATD1DR3 - ATD 1 Conversion Result Register 3; 0x00000096 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR3H - ATD 1 Conversion Result Register 3 High; 0x00000096 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR3HSTR;
    #define ATD1DR3H                    _ATD1DR3.Overlap_STR.ATD1DR3HSTR.Byte
    #define ATD1DR3H_BIT8               _ATD1DR3.Overlap_STR.ATD1DR3HSTR.Bits.BIT8
    #define ATD1DR3H_BIT9               _ATD1DR3.Overlap_STR.ATD1DR3HSTR.Bits.BIT9
    #define ATD1DR3H_BIT10              _ATD1DR3.Overlap_STR.ATD1DR3HSTR.Bits.BIT10
    #define ATD1DR3H_BIT11              _ATD1DR3.Overlap_STR.ATD1DR3HSTR.Bits.BIT11
    #define ATD1DR3H_BIT12              _ATD1DR3.Overlap_STR.ATD1DR3HSTR.Bits.BIT12
    #define ATD1DR3H_BIT13              _ATD1DR3.Overlap_STR.ATD1DR3HSTR.Bits.BIT13
    #define ATD1DR3H_BIT14              _ATD1DR3.Overlap_STR.ATD1DR3HSTR.Bits.BIT14
    #define ATD1DR3H_BIT15              _ATD1DR3.Overlap_STR.ATD1DR3HSTR.Bits.BIT15
    
    
    #define ATD1DR3H_BIT8_MASK          1
    #define ATD1DR3H_BIT9_MASK          2
    #define ATD1DR3H_BIT10_MASK         4
    #define ATD1DR3H_BIT11_MASK         8
    #define ATD1DR3H_BIT12_MASK         16
    #define ATD1DR3H_BIT13_MASK         32
    #define ATD1DR3H_BIT14_MASK         64
    #define ATD1DR3H_BIT15_MASK         128


     ATD1DR3L - ATD 1 Conversion Result Register 3 Low; 0x00000097 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR3LSTR;
    #define ATD1DR3L                    _ATD1DR3.Overlap_STR.ATD1DR3LSTR.Byte
    #define ATD1DR3L_BIT6               _ATD1DR3.Overlap_STR.ATD1DR3LSTR.Bits.BIT6
    #define ATD1DR3L_BIT7               _ATD1DR3.Overlap_STR.ATD1DR3LSTR.Bits.BIT7
    
    #define ATD1DR3L_BIT_6              _ATD1DR3.Overlap_STR.ATD1DR3LSTR.MergedBits.grpBIT_6
    #define ATD1DR3L_BIT                ATD1DR3L_BIT_6
    
    #define ATD1DR3L_BIT6_MASK          64
    #define ATD1DR3L_BIT7_MASK          128
    #define ATD1DR3L_BIT_6_MASK         192
    #define ATD1DR3L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR3STR;
extern volatile ATD1DR3STR _ATD1DR3 @(REG_BASE + 0x00000096);
#define ATD1DR3                         _ATD1DR3.Word
#define ATD1DR3_BIT6                    _ATD1DR3.Bits.BIT6
#define ATD1DR3_BIT7                    _ATD1DR3.Bits.BIT7
#define ATD1DR3_BIT8                    _ATD1DR3.Bits.BIT8
#define ATD1DR3_BIT9                    _ATD1DR3.Bits.BIT9
#define ATD1DR3_BIT10                   _ATD1DR3.Bits.BIT10
#define ATD1DR3_BIT11                   _ATD1DR3.Bits.BIT11
#define ATD1DR3_BIT12                   _ATD1DR3.Bits.BIT12
#define ATD1DR3_BIT13                   _ATD1DR3.Bits.BIT13
#define ATD1DR3_BIT14                   _ATD1DR3.Bits.BIT14
#define ATD1DR3_BIT15                   _ATD1DR3.Bits.BIT15
#define ATD1DR3_BIT_6                   _ATD1DR3.MergedBits.grpBIT_6
#define ATD1DR3_BIT                     ATD1DR3_BIT_6

#define ATD1DR3_BIT6_MASK               64
#define ATD1DR3_BIT7_MASK               128
#define ATD1DR3_BIT8_MASK               256
#define ATD1DR3_BIT9_MASK               512
#define ATD1DR3_BIT10_MASK              1024
#define ATD1DR3_BIT11_MASK              2048
#define ATD1DR3_BIT12_MASK              4096
#define ATD1DR3_BIT13_MASK              8192
#define ATD1DR3_BIT14_MASK              16384
#define ATD1DR3_BIT15_MASK              32768
#define ATD1DR3_BIT_6_MASK              65472
#define ATD1DR3_BIT_6_BITNUM            6


 ATD1DR4 - ATD 1 Conversion Result Register 4; 0x00000098 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR4H - ATD 1 Conversion Result Register 4 High; 0x00000098 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR4HSTR;
    #define ATD1DR4H                    _ATD1DR4.Overlap_STR.ATD1DR4HSTR.Byte
    #define ATD1DR4H_BIT8               _ATD1DR4.Overlap_STR.ATD1DR4HSTR.Bits.BIT8
    #define ATD1DR4H_BIT9               _ATD1DR4.Overlap_STR.ATD1DR4HSTR.Bits.BIT9
    #define ATD1DR4H_BIT10              _ATD1DR4.Overlap_STR.ATD1DR4HSTR.Bits.BIT10
    #define ATD1DR4H_BIT11              _ATD1DR4.Overlap_STR.ATD1DR4HSTR.Bits.BIT11
    #define ATD1DR4H_BIT12              _ATD1DR4.Overlap_STR.ATD1DR4HSTR.Bits.BIT12
    #define ATD1DR4H_BIT13              _ATD1DR4.Overlap_STR.ATD1DR4HSTR.Bits.BIT13
    #define ATD1DR4H_BIT14              _ATD1DR4.Overlap_STR.ATD1DR4HSTR.Bits.BIT14
    #define ATD1DR4H_BIT15              _ATD1DR4.Overlap_STR.ATD1DR4HSTR.Bits.BIT15
    
    
    #define ATD1DR4H_BIT8_MASK          1
    #define ATD1DR4H_BIT9_MASK          2
    #define ATD1DR4H_BIT10_MASK         4
    #define ATD1DR4H_BIT11_MASK         8
    #define ATD1DR4H_BIT12_MASK         16
    #define ATD1DR4H_BIT13_MASK         32
    #define ATD1DR4H_BIT14_MASK         64
    #define ATD1DR4H_BIT15_MASK         128


     ATD1DR4L - ATD 1 Conversion Result Register 4 Low; 0x00000099 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR4LSTR;
    #define ATD1DR4L                    _ATD1DR4.Overlap_STR.ATD1DR4LSTR.Byte
    #define ATD1DR4L_BIT6               _ATD1DR4.Overlap_STR.ATD1DR4LSTR.Bits.BIT6
    #define ATD1DR4L_BIT7               _ATD1DR4.Overlap_STR.ATD1DR4LSTR.Bits.BIT7
    
    #define ATD1DR4L_BIT_6              _ATD1DR4.Overlap_STR.ATD1DR4LSTR.MergedBits.grpBIT_6
    #define ATD1DR4L_BIT                ATD1DR4L_BIT_6
    
    #define ATD1DR4L_BIT6_MASK          64
    #define ATD1DR4L_BIT7_MASK          128
    #define ATD1DR4L_BIT_6_MASK         192
    #define ATD1DR4L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR4STR;
extern volatile ATD1DR4STR _ATD1DR4 @(REG_BASE + 0x00000098);
#define ATD1DR4                         _ATD1DR4.Word
#define ATD1DR4_BIT6                    _ATD1DR4.Bits.BIT6
#define ATD1DR4_BIT7                    _ATD1DR4.Bits.BIT7
#define ATD1DR4_BIT8                    _ATD1DR4.Bits.BIT8
#define ATD1DR4_BIT9                    _ATD1DR4.Bits.BIT9
#define ATD1DR4_BIT10                   _ATD1DR4.Bits.BIT10
#define ATD1DR4_BIT11                   _ATD1DR4.Bits.BIT11
#define ATD1DR4_BIT12                   _ATD1DR4.Bits.BIT12
#define ATD1DR4_BIT13                   _ATD1DR4.Bits.BIT13
#define ATD1DR4_BIT14                   _ATD1DR4.Bits.BIT14
#define ATD1DR4_BIT15                   _ATD1DR4.Bits.BIT15
#define ATD1DR4_BIT_6                   _ATD1DR4.MergedBits.grpBIT_6
#define ATD1DR4_BIT                     ATD1DR4_BIT_6

#define ATD1DR4_BIT6_MASK               64
#define ATD1DR4_BIT7_MASK               128
#define ATD1DR4_BIT8_MASK               256
#define ATD1DR4_BIT9_MASK               512
#define ATD1DR4_BIT10_MASK              1024
#define ATD1DR4_BIT11_MASK              2048
#define ATD1DR4_BIT12_MASK              4096
#define ATD1DR4_BIT13_MASK              8192
#define ATD1DR4_BIT14_MASK              16384
#define ATD1DR4_BIT15_MASK              32768
#define ATD1DR4_BIT_6_MASK              65472
#define ATD1DR4_BIT_6_BITNUM            6


 ATD1DR5 - ATD 1 Conversion Result Register 5; 0x0000009A 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR5H - ATD 1 Conversion Result Register 5 High; 0x0000009A 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR5HSTR;
    #define ATD1DR5H                    _ATD1DR5.Overlap_STR.ATD1DR5HSTR.Byte
    #define ATD1DR5H_BIT8               _ATD1DR5.Overlap_STR.ATD1DR5HSTR.Bits.BIT8
    #define ATD1DR5H_BIT9               _ATD1DR5.Overlap_STR.ATD1DR5HSTR.Bits.BIT9
    #define ATD1DR5H_BIT10              _ATD1DR5.Overlap_STR.ATD1DR5HSTR.Bits.BIT10
    #define ATD1DR5H_BIT11              _ATD1DR5.Overlap_STR.ATD1DR5HSTR.Bits.BIT11
    #define ATD1DR5H_BIT12              _ATD1DR5.Overlap_STR.ATD1DR5HSTR.Bits.BIT12
    #define ATD1DR5H_BIT13              _ATD1DR5.Overlap_STR.ATD1DR5HSTR.Bits.BIT13
    #define ATD1DR5H_BIT14              _ATD1DR5.Overlap_STR.ATD1DR5HSTR.Bits.BIT14
    #define ATD1DR5H_BIT15              _ATD1DR5.Overlap_STR.ATD1DR5HSTR.Bits.BIT15
    
    
    #define ATD1DR5H_BIT8_MASK          1
    #define ATD1DR5H_BIT9_MASK          2
    #define ATD1DR5H_BIT10_MASK         4
    #define ATD1DR5H_BIT11_MASK         8
    #define ATD1DR5H_BIT12_MASK         16
    #define ATD1DR5H_BIT13_MASK         32
    #define ATD1DR5H_BIT14_MASK         64
    #define ATD1DR5H_BIT15_MASK         128


     ATD1DR5L - ATD 1 Conversion Result Register 5 Low; 0x0000009B 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR5LSTR;
    #define ATD1DR5L                    _ATD1DR5.Overlap_STR.ATD1DR5LSTR.Byte
    #define ATD1DR5L_BIT6               _ATD1DR5.Overlap_STR.ATD1DR5LSTR.Bits.BIT6
    #define ATD1DR5L_BIT7               _ATD1DR5.Overlap_STR.ATD1DR5LSTR.Bits.BIT7
    
    #define ATD1DR5L_BIT_6              _ATD1DR5.Overlap_STR.ATD1DR5LSTR.MergedBits.grpBIT_6
    #define ATD1DR5L_BIT                ATD1DR5L_BIT_6
    
    #define ATD1DR5L_BIT6_MASK          64
    #define ATD1DR5L_BIT7_MASK          128
    #define ATD1DR5L_BIT_6_MASK         192
    #define ATD1DR5L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR5STR;
extern volatile ATD1DR5STR _ATD1DR5 @(REG_BASE + 0x0000009A);
#define ATD1DR5                         _ATD1DR5.Word
#define ATD1DR5_BIT6                    _ATD1DR5.Bits.BIT6
#define ATD1DR5_BIT7                    _ATD1DR5.Bits.BIT7
#define ATD1DR5_BIT8                    _ATD1DR5.Bits.BIT8
#define ATD1DR5_BIT9                    _ATD1DR5.Bits.BIT9
#define ATD1DR5_BIT10                   _ATD1DR5.Bits.BIT10
#define ATD1DR5_BIT11                   _ATD1DR5.Bits.BIT11
#define ATD1DR5_BIT12                   _ATD1DR5.Bits.BIT12
#define ATD1DR5_BIT13                   _ATD1DR5.Bits.BIT13
#define ATD1DR5_BIT14                   _ATD1DR5.Bits.BIT14
#define ATD1DR5_BIT15                   _ATD1DR5.Bits.BIT15
#define ATD1DR5_BIT_6                   _ATD1DR5.MergedBits.grpBIT_6
#define ATD1DR5_BIT                     ATD1DR5_BIT_6

#define ATD1DR5_BIT6_MASK               64
#define ATD1DR5_BIT7_MASK               128
#define ATD1DR5_BIT8_MASK               256
#define ATD1DR5_BIT9_MASK               512
#define ATD1DR5_BIT10_MASK              1024
#define ATD1DR5_BIT11_MASK              2048
#define ATD1DR5_BIT12_MASK              4096
#define ATD1DR5_BIT13_MASK              8192
#define ATD1DR5_BIT14_MASK              16384
#define ATD1DR5_BIT15_MASK              32768
#define ATD1DR5_BIT_6_MASK              65472
#define ATD1DR5_BIT_6_BITNUM            6


 ATD1DR6 - ATD 1 Conversion Result Register 6; 0x0000009C 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR6H - ATD 1 Conversion Result Register 6 High; 0x0000009C 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR6HSTR;
    #define ATD1DR6H                    _ATD1DR6.Overlap_STR.ATD1DR6HSTR.Byte
    #define ATD1DR6H_BIT8               _ATD1DR6.Overlap_STR.ATD1DR6HSTR.Bits.BIT8
    #define ATD1DR6H_BIT9               _ATD1DR6.Overlap_STR.ATD1DR6HSTR.Bits.BIT9
    #define ATD1DR6H_BIT10              _ATD1DR6.Overlap_STR.ATD1DR6HSTR.Bits.BIT10
    #define ATD1DR6H_BIT11              _ATD1DR6.Overlap_STR.ATD1DR6HSTR.Bits.BIT11
    #define ATD1DR6H_BIT12              _ATD1DR6.Overlap_STR.ATD1DR6HSTR.Bits.BIT12
    #define ATD1DR6H_BIT13              _ATD1DR6.Overlap_STR.ATD1DR6HSTR.Bits.BIT13
    #define ATD1DR6H_BIT14              _ATD1DR6.Overlap_STR.ATD1DR6HSTR.Bits.BIT14
    #define ATD1DR6H_BIT15              _ATD1DR6.Overlap_STR.ATD1DR6HSTR.Bits.BIT15
    
    
    #define ATD1DR6H_BIT8_MASK          1
    #define ATD1DR6H_BIT9_MASK          2
    #define ATD1DR6H_BIT10_MASK         4
    #define ATD1DR6H_BIT11_MASK         8
    #define ATD1DR6H_BIT12_MASK         16
    #define ATD1DR6H_BIT13_MASK         32
    #define ATD1DR6H_BIT14_MASK         64
    #define ATD1DR6H_BIT15_MASK         128


     ATD1DR6L - ATD 1 Conversion Result Register 6 Low; 0x0000009D 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR6LSTR;
    #define ATD1DR6L                    _ATD1DR6.Overlap_STR.ATD1DR6LSTR.Byte
    #define ATD1DR6L_BIT6               _ATD1DR6.Overlap_STR.ATD1DR6LSTR.Bits.BIT6
    #define ATD1DR6L_BIT7               _ATD1DR6.Overlap_STR.ATD1DR6LSTR.Bits.BIT7
    
    #define ATD1DR6L_BIT_6              _ATD1DR6.Overlap_STR.ATD1DR6LSTR.MergedBits.grpBIT_6
    #define ATD1DR6L_BIT                ATD1DR6L_BIT_6
    
    #define ATD1DR6L_BIT6_MASK          64
    #define ATD1DR6L_BIT7_MASK          128
    #define ATD1DR6L_BIT_6_MASK         192
    #define ATD1DR6L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR6STR;
extern volatile ATD1DR6STR _ATD1DR6 @(REG_BASE + 0x0000009C);
#define ATD1DR6                         _ATD1DR6.Word
#define ATD1DR6_BIT6                    _ATD1DR6.Bits.BIT6
#define ATD1DR6_BIT7                    _ATD1DR6.Bits.BIT7
#define ATD1DR6_BIT8                    _ATD1DR6.Bits.BIT8
#define ATD1DR6_BIT9                    _ATD1DR6.Bits.BIT9
#define ATD1DR6_BIT10                   _ATD1DR6.Bits.BIT10
#define ATD1DR6_BIT11                   _ATD1DR6.Bits.BIT11
#define ATD1DR6_BIT12                   _ATD1DR6.Bits.BIT12
#define ATD1DR6_BIT13                   _ATD1DR6.Bits.BIT13
#define ATD1DR6_BIT14                   _ATD1DR6.Bits.BIT14
#define ATD1DR6_BIT15                   _ATD1DR6.Bits.BIT15
#define ATD1DR6_BIT_6                   _ATD1DR6.MergedBits.grpBIT_6
#define ATD1DR6_BIT                     ATD1DR6_BIT_6

#define ATD1DR6_BIT6_MASK               64
#define ATD1DR6_BIT7_MASK               128
#define ATD1DR6_BIT8_MASK               256
#define ATD1DR6_BIT9_MASK               512
#define ATD1DR6_BIT10_MASK              1024
#define ATD1DR6_BIT11_MASK              2048
#define ATD1DR6_BIT12_MASK              4096
#define ATD1DR6_BIT13_MASK              8192
#define ATD1DR6_BIT14_MASK              16384
#define ATD1DR6_BIT15_MASK              32768
#define ATD1DR6_BIT_6_MASK              65472
#define ATD1DR6_BIT_6_BITNUM            6


 ATD1DR7 - ATD 1 Conversion Result Register 7; 0x0000009E 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR7H - ATD 1 Conversion Result Register 7 High; 0x0000009E 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR7HSTR;
    #define ATD1DR7H                    _ATD1DR7.Overlap_STR.ATD1DR7HSTR.Byte
    #define ATD1DR7H_BIT8               _ATD1DR7.Overlap_STR.ATD1DR7HSTR.Bits.BIT8
    #define ATD1DR7H_BIT9               _ATD1DR7.Overlap_STR.ATD1DR7HSTR.Bits.BIT9
    #define ATD1DR7H_BIT10              _ATD1DR7.Overlap_STR.ATD1DR7HSTR.Bits.BIT10
    #define ATD1DR7H_BIT11              _ATD1DR7.Overlap_STR.ATD1DR7HSTR.Bits.BIT11
    #define ATD1DR7H_BIT12              _ATD1DR7.Overlap_STR.ATD1DR7HSTR.Bits.BIT12
    #define ATD1DR7H_BIT13              _ATD1DR7.Overlap_STR.ATD1DR7HSTR.Bits.BIT13
    #define ATD1DR7H_BIT14              _ATD1DR7.Overlap_STR.ATD1DR7HSTR.Bits.BIT14
    #define ATD1DR7H_BIT15              _ATD1DR7.Overlap_STR.ATD1DR7HSTR.Bits.BIT15
    
    
    #define ATD1DR7H_BIT8_MASK          1
    #define ATD1DR7H_BIT9_MASK          2
    #define ATD1DR7H_BIT10_MASK         4
    #define ATD1DR7H_BIT11_MASK         8
    #define ATD1DR7H_BIT12_MASK         16
    #define ATD1DR7H_BIT13_MASK         32
    #define ATD1DR7H_BIT14_MASK         64
    #define ATD1DR7H_BIT15_MASK         128


     ATD1DR7L - ATD 1 Conversion Result Register 7 Low; 0x0000009F 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR7LSTR;
    #define ATD1DR7L                    _ATD1DR7.Overlap_STR.ATD1DR7LSTR.Byte
    #define ATD1DR7L_BIT6               _ATD1DR7.Overlap_STR.ATD1DR7LSTR.Bits.BIT6
    #define ATD1DR7L_BIT7               _ATD1DR7.Overlap_STR.ATD1DR7LSTR.Bits.BIT7
    
    #define ATD1DR7L_BIT_6              _ATD1DR7.Overlap_STR.ATD1DR7LSTR.MergedBits.grpBIT_6
    #define ATD1DR7L_BIT                ATD1DR7L_BIT_6
    
    #define ATD1DR7L_BIT6_MASK          64
    #define ATD1DR7L_BIT7_MASK          128
    #define ATD1DR7L_BIT_6_MASK         192
    #define ATD1DR7L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR7STR;
extern volatile ATD1DR7STR _ATD1DR7 @(REG_BASE + 0x0000009E);
#define ATD1DR7                         _ATD1DR7.Word
#define ATD1DR7_BIT6                    _ATD1DR7.Bits.BIT6
#define ATD1DR7_BIT7                    _ATD1DR7.Bits.BIT7
#define ATD1DR7_BIT8                    _ATD1DR7.Bits.BIT8
#define ATD1DR7_BIT9                    _ATD1DR7.Bits.BIT9
#define ATD1DR7_BIT10                   _ATD1DR7.Bits.BIT10
#define ATD1DR7_BIT11                   _ATD1DR7.Bits.BIT11
#define ATD1DR7_BIT12                   _ATD1DR7.Bits.BIT12
#define ATD1DR7_BIT13                   _ATD1DR7.Bits.BIT13
#define ATD1DR7_BIT14                   _ATD1DR7.Bits.BIT14
#define ATD1DR7_BIT15                   _ATD1DR7.Bits.BIT15
#define ATD1DR7_BIT_6                   _ATD1DR7.MergedBits.grpBIT_6
#define ATD1DR7_BIT                     ATD1DR7_BIT_6

#define ATD1DR7_BIT6_MASK               64
#define ATD1DR7_BIT7_MASK               128
#define ATD1DR7_BIT8_MASK               256
#define ATD1DR7_BIT9_MASK               512
#define ATD1DR7_BIT10_MASK              1024
#define ATD1DR7_BIT11_MASK              2048
#define ATD1DR7_BIT12_MASK              4096
#define ATD1DR7_BIT13_MASK              8192
#define ATD1DR7_BIT14_MASK              16384
#define ATD1DR7_BIT15_MASK              32768
#define ATD1DR7_BIT_6_MASK              65472
#define ATD1DR7_BIT_6_BITNUM            6


 ATD1DR8 - ATD 1 Conversion Result Register 8; 0x000000A0 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR8H - ATD 1 Conversion Result Register 8 High; 0x000000A0 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR8HSTR;
    #define ATD1DR8H                    _ATD1DR8.Overlap_STR.ATD1DR8HSTR.Byte
    #define ATD1DR8H_BIT8               _ATD1DR8.Overlap_STR.ATD1DR8HSTR.Bits.BIT8
    #define ATD1DR8H_BIT9               _ATD1DR8.Overlap_STR.ATD1DR8HSTR.Bits.BIT9
    #define ATD1DR8H_BIT10              _ATD1DR8.Overlap_STR.ATD1DR8HSTR.Bits.BIT10
    #define ATD1DR8H_BIT11              _ATD1DR8.Overlap_STR.ATD1DR8HSTR.Bits.BIT11
    #define ATD1DR8H_BIT12              _ATD1DR8.Overlap_STR.ATD1DR8HSTR.Bits.BIT12
    #define ATD1DR8H_BIT13              _ATD1DR8.Overlap_STR.ATD1DR8HSTR.Bits.BIT13
    #define ATD1DR8H_BIT14              _ATD1DR8.Overlap_STR.ATD1DR8HSTR.Bits.BIT14
    #define ATD1DR8H_BIT15              _ATD1DR8.Overlap_STR.ATD1DR8HSTR.Bits.BIT15
    
    
    #define ATD1DR8H_BIT8_MASK          1
    #define ATD1DR8H_BIT9_MASK          2
    #define ATD1DR8H_BIT10_MASK         4
    #define ATD1DR8H_BIT11_MASK         8
    #define ATD1DR8H_BIT12_MASK         16
    #define ATD1DR8H_BIT13_MASK         32
    #define ATD1DR8H_BIT14_MASK         64
    #define ATD1DR8H_BIT15_MASK         128


     ATD1DR8L - ATD 1 Conversion Result Register 8 Low; 0x000000A1 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR8LSTR;
    #define ATD1DR8L                    _ATD1DR8.Overlap_STR.ATD1DR8LSTR.Byte
    #define ATD1DR8L_BIT6               _ATD1DR8.Overlap_STR.ATD1DR8LSTR.Bits.BIT6
    #define ATD1DR8L_BIT7               _ATD1DR8.Overlap_STR.ATD1DR8LSTR.Bits.BIT7
    
    #define ATD1DR8L_BIT_6              _ATD1DR8.Overlap_STR.ATD1DR8LSTR.MergedBits.grpBIT_6
    #define ATD1DR8L_BIT                ATD1DR8L_BIT_6
    
    #define ATD1DR8L_BIT6_MASK          64
    #define ATD1DR8L_BIT7_MASK          128
    #define ATD1DR8L_BIT_6_MASK         192
    #define ATD1DR8L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR8STR;
extern volatile ATD1DR8STR _ATD1DR8 @(REG_BASE + 0x000000A0);
#define ATD1DR8                         _ATD1DR8.Word
#define ATD1DR8_BIT6                    _ATD1DR8.Bits.BIT6
#define ATD1DR8_BIT7                    _ATD1DR8.Bits.BIT7
#define ATD1DR8_BIT8                    _ATD1DR8.Bits.BIT8
#define ATD1DR8_BIT9                    _ATD1DR8.Bits.BIT9
#define ATD1DR8_BIT10                   _ATD1DR8.Bits.BIT10
#define ATD1DR8_BIT11                   _ATD1DR8.Bits.BIT11
#define ATD1DR8_BIT12                   _ATD1DR8.Bits.BIT12
#define ATD1DR8_BIT13                   _ATD1DR8.Bits.BIT13
#define ATD1DR8_BIT14                   _ATD1DR8.Bits.BIT14
#define ATD1DR8_BIT15                   _ATD1DR8.Bits.BIT15
#define ATD1DR8_BIT_6                   _ATD1DR8.MergedBits.grpBIT_6
#define ATD1DR8_BIT                     ATD1DR8_BIT_6

#define ATD1DR8_BIT6_MASK               64
#define ATD1DR8_BIT7_MASK               128
#define ATD1DR8_BIT8_MASK               256
#define ATD1DR8_BIT9_MASK               512
#define ATD1DR8_BIT10_MASK              1024
#define ATD1DR8_BIT11_MASK              2048
#define ATD1DR8_BIT12_MASK              4096
#define ATD1DR8_BIT13_MASK              8192
#define ATD1DR8_BIT14_MASK              16384
#define ATD1DR8_BIT15_MASK              32768
#define ATD1DR8_BIT_6_MASK              65472
#define ATD1DR8_BIT_6_BITNUM            6


 ATD1DR9 - ATD 1 Conversion Result Register 9; 0x000000A2 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR9H - ATD 1 Conversion Result Register 9 High; 0x000000A2 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR9HSTR;
    #define ATD1DR9H                    _ATD1DR9.Overlap_STR.ATD1DR9HSTR.Byte
    #define ATD1DR9H_BIT8               _ATD1DR9.Overlap_STR.ATD1DR9HSTR.Bits.BIT8
    #define ATD1DR9H_BIT9               _ATD1DR9.Overlap_STR.ATD1DR9HSTR.Bits.BIT9
    #define ATD1DR9H_BIT10              _ATD1DR9.Overlap_STR.ATD1DR9HSTR.Bits.BIT10
    #define ATD1DR9H_BIT11              _ATD1DR9.Overlap_STR.ATD1DR9HSTR.Bits.BIT11
    #define ATD1DR9H_BIT12              _ATD1DR9.Overlap_STR.ATD1DR9HSTR.Bits.BIT12
    #define ATD1DR9H_BIT13              _ATD1DR9.Overlap_STR.ATD1DR9HSTR.Bits.BIT13
    #define ATD1DR9H_BIT14              _ATD1DR9.Overlap_STR.ATD1DR9HSTR.Bits.BIT14
    #define ATD1DR9H_BIT15              _ATD1DR9.Overlap_STR.ATD1DR9HSTR.Bits.BIT15
    
    
    #define ATD1DR9H_BIT8_MASK          1
    #define ATD1DR9H_BIT9_MASK          2
    #define ATD1DR9H_BIT10_MASK         4
    #define ATD1DR9H_BIT11_MASK         8
    #define ATD1DR9H_BIT12_MASK         16
    #define ATD1DR9H_BIT13_MASK         32
    #define ATD1DR9H_BIT14_MASK         64
    #define ATD1DR9H_BIT15_MASK         128


     ATD1DR9L - ATD 1 Conversion Result Register 9 Low; 0x000000A3 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR9LSTR;
    #define ATD1DR9L                    _ATD1DR9.Overlap_STR.ATD1DR9LSTR.Byte
    #define ATD1DR9L_BIT6               _ATD1DR9.Overlap_STR.ATD1DR9LSTR.Bits.BIT6
    #define ATD1DR9L_BIT7               _ATD1DR9.Overlap_STR.ATD1DR9LSTR.Bits.BIT7
    
    #define ATD1DR9L_BIT_6              _ATD1DR9.Overlap_STR.ATD1DR9LSTR.MergedBits.grpBIT_6
    #define ATD1DR9L_BIT                ATD1DR9L_BIT_6
    
    #define ATD1DR9L_BIT6_MASK          64
    #define ATD1DR9L_BIT7_MASK          128
    #define ATD1DR9L_BIT_6_MASK         192
    #define ATD1DR9L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR9STR;
extern volatile ATD1DR9STR _ATD1DR9 @(REG_BASE + 0x000000A2);
#define ATD1DR9                         _ATD1DR9.Word
#define ATD1DR9_BIT6                    _ATD1DR9.Bits.BIT6
#define ATD1DR9_BIT7                    _ATD1DR9.Bits.BIT7
#define ATD1DR9_BIT8                    _ATD1DR9.Bits.BIT8
#define ATD1DR9_BIT9                    _ATD1DR9.Bits.BIT9
#define ATD1DR9_BIT10                   _ATD1DR9.Bits.BIT10
#define ATD1DR9_BIT11                   _ATD1DR9.Bits.BIT11
#define ATD1DR9_BIT12                   _ATD1DR9.Bits.BIT12
#define ATD1DR9_BIT13                   _ATD1DR9.Bits.BIT13
#define ATD1DR9_BIT14                   _ATD1DR9.Bits.BIT14
#define ATD1DR9_BIT15                   _ATD1DR9.Bits.BIT15
#define ATD1DR9_BIT_6                   _ATD1DR9.MergedBits.grpBIT_6
#define ATD1DR9_BIT                     ATD1DR9_BIT_6

#define ATD1DR9_BIT6_MASK               64
#define ATD1DR9_BIT7_MASK               128
#define ATD1DR9_BIT8_MASK               256
#define ATD1DR9_BIT9_MASK               512
#define ATD1DR9_BIT10_MASK              1024
#define ATD1DR9_BIT11_MASK              2048
#define ATD1DR9_BIT12_MASK              4096
#define ATD1DR9_BIT13_MASK              8192
#define ATD1DR9_BIT14_MASK              16384
#define ATD1DR9_BIT15_MASK              32768
#define ATD1DR9_BIT_6_MASK              65472
#define ATD1DR9_BIT_6_BITNUM            6


 ATD1DR10 - ATD 1 Conversion Result Register 10; 0x000000A4 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR10H - ATD 1 Conversion Result Register 10 High; 0x000000A4 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR10HSTR;
    #define ATD1DR10H                   _ATD1DR10.Overlap_STR.ATD1DR10HSTR.Byte
    #define ATD1DR10H_BIT8              _ATD1DR10.Overlap_STR.ATD1DR10HSTR.Bits.BIT8
    #define ATD1DR10H_BIT9              _ATD1DR10.Overlap_STR.ATD1DR10HSTR.Bits.BIT9
    #define ATD1DR10H_BIT10             _ATD1DR10.Overlap_STR.ATD1DR10HSTR.Bits.BIT10
    #define ATD1DR10H_BIT11             _ATD1DR10.Overlap_STR.ATD1DR10HSTR.Bits.BIT11
    #define ATD1DR10H_BIT12             _ATD1DR10.Overlap_STR.ATD1DR10HSTR.Bits.BIT12
    #define ATD1DR10H_BIT13             _ATD1DR10.Overlap_STR.ATD1DR10HSTR.Bits.BIT13
    #define ATD1DR10H_BIT14             _ATD1DR10.Overlap_STR.ATD1DR10HSTR.Bits.BIT14
    #define ATD1DR10H_BIT15             _ATD1DR10.Overlap_STR.ATD1DR10HSTR.Bits.BIT15
    
    
    #define ATD1DR10H_BIT8_MASK         1
    #define ATD1DR10H_BIT9_MASK         2
    #define ATD1DR10H_BIT10_MASK        4
    #define ATD1DR10H_BIT11_MASK        8
    #define ATD1DR10H_BIT12_MASK        16
    #define ATD1DR10H_BIT13_MASK        32
    #define ATD1DR10H_BIT14_MASK        64
    #define ATD1DR10H_BIT15_MASK        128


     ATD1DR10L - ATD 1 Conversion Result Register 10 Low; 0x000000A5 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR10LSTR;
    #define ATD1DR10L                   _ATD1DR10.Overlap_STR.ATD1DR10LSTR.Byte
    #define ATD1DR10L_BIT6              _ATD1DR10.Overlap_STR.ATD1DR10LSTR.Bits.BIT6
    #define ATD1DR10L_BIT7              _ATD1DR10.Overlap_STR.ATD1DR10LSTR.Bits.BIT7
    
    #define ATD1DR10L_BIT_6             _ATD1DR10.Overlap_STR.ATD1DR10LSTR.MergedBits.grpBIT_6
    #define ATD1DR10L_BIT               ATD1DR10L_BIT_6
    
    #define ATD1DR10L_BIT6_MASK         64
    #define ATD1DR10L_BIT7_MASK         128
    #define ATD1DR10L_BIT_6_MASK        192
    #define ATD1DR10L_BIT_6_BITNUM      6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR10STR;
extern volatile ATD1DR10STR _ATD1DR10 @(REG_BASE + 0x000000A4);
#define ATD1DR10                        _ATD1DR10.Word
#define ATD1DR10_BIT6                   _ATD1DR10.Bits.BIT6
#define ATD1DR10_BIT7                   _ATD1DR10.Bits.BIT7
#define ATD1DR10_BIT8                   _ATD1DR10.Bits.BIT8
#define ATD1DR10_BIT9                   _ATD1DR10.Bits.BIT9
#define ATD1DR10_BIT10                  _ATD1DR10.Bits.BIT10
#define ATD1DR10_BIT11                  _ATD1DR10.Bits.BIT11
#define ATD1DR10_BIT12                  _ATD1DR10.Bits.BIT12
#define ATD1DR10_BIT13                  _ATD1DR10.Bits.BIT13
#define ATD1DR10_BIT14                  _ATD1DR10.Bits.BIT14
#define ATD1DR10_BIT15                  _ATD1DR10.Bits.BIT15
#define ATD1DR10_BIT_6                  _ATD1DR10.MergedBits.grpBIT_6
#define ATD1DR10_BIT                    ATD1DR10_BIT_6

#define ATD1DR10_BIT6_MASK              64
#define ATD1DR10_BIT7_MASK              128
#define ATD1DR10_BIT8_MASK              256
#define ATD1DR10_BIT9_MASK              512
#define ATD1DR10_BIT10_MASK             1024
#define ATD1DR10_BIT11_MASK             2048
#define ATD1DR10_BIT12_MASK             4096
#define ATD1DR10_BIT13_MASK             8192
#define ATD1DR10_BIT14_MASK             16384
#define ATD1DR10_BIT15_MASK             32768
#define ATD1DR10_BIT_6_MASK             65472
#define ATD1DR10_BIT_6_BITNUM           6


 ATD1DR11 - ATD 1 Conversion Result Register 11; 0x000000A6 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR11H - ATD 1 Conversion Result Register 11 High; 0x000000A6 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR11HSTR;
    #define ATD1DR11H                   _ATD1DR11.Overlap_STR.ATD1DR11HSTR.Byte
    #define ATD1DR11H_BIT8              _ATD1DR11.Overlap_STR.ATD1DR11HSTR.Bits.BIT8
    #define ATD1DR11H_BIT9              _ATD1DR11.Overlap_STR.ATD1DR11HSTR.Bits.BIT9
    #define ATD1DR11H_BIT10             _ATD1DR11.Overlap_STR.ATD1DR11HSTR.Bits.BIT10
    #define ATD1DR11H_BIT11             _ATD1DR11.Overlap_STR.ATD1DR11HSTR.Bits.BIT11
    #define ATD1DR11H_BIT12             _ATD1DR11.Overlap_STR.ATD1DR11HSTR.Bits.BIT12
    #define ATD1DR11H_BIT13             _ATD1DR11.Overlap_STR.ATD1DR11HSTR.Bits.BIT13
    #define ATD1DR11H_BIT14             _ATD1DR11.Overlap_STR.ATD1DR11HSTR.Bits.BIT14
    #define ATD1DR11H_BIT15             _ATD1DR11.Overlap_STR.ATD1DR11HSTR.Bits.BIT15
    
    
    #define ATD1DR11H_BIT8_MASK         1
    #define ATD1DR11H_BIT9_MASK         2
    #define ATD1DR11H_BIT10_MASK        4
    #define ATD1DR11H_BIT11_MASK        8
    #define ATD1DR11H_BIT12_MASK        16
    #define ATD1DR11H_BIT13_MASK        32
    #define ATD1DR11H_BIT14_MASK        64
    #define ATD1DR11H_BIT15_MASK        128


     ATD1DR11L - ATD 1 Conversion Result Register 11 Low; 0x000000A7 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR11LSTR;
    #define ATD1DR11L                   _ATD1DR11.Overlap_STR.ATD1DR11LSTR.Byte
    #define ATD1DR11L_BIT6              _ATD1DR11.Overlap_STR.ATD1DR11LSTR.Bits.BIT6
    #define ATD1DR11L_BIT7              _ATD1DR11.Overlap_STR.ATD1DR11LSTR.Bits.BIT7
    
    #define ATD1DR11L_BIT_6             _ATD1DR11.Overlap_STR.ATD1DR11LSTR.MergedBits.grpBIT_6
    #define ATD1DR11L_BIT               ATD1DR11L_BIT_6
    
    #define ATD1DR11L_BIT6_MASK         64
    #define ATD1DR11L_BIT7_MASK         128
    #define ATD1DR11L_BIT_6_MASK        192
    #define ATD1DR11L_BIT_6_BITNUM      6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR11STR;
extern volatile ATD1DR11STR _ATD1DR11 @(REG_BASE + 0x000000A6);
#define ATD1DR11                        _ATD1DR11.Word
#define ATD1DR11_BIT6                   _ATD1DR11.Bits.BIT6
#define ATD1DR11_BIT7                   _ATD1DR11.Bits.BIT7
#define ATD1DR11_BIT8                   _ATD1DR11.Bits.BIT8
#define ATD1DR11_BIT9                   _ATD1DR11.Bits.BIT9
#define ATD1DR11_BIT10                  _ATD1DR11.Bits.BIT10
#define ATD1DR11_BIT11                  _ATD1DR11.Bits.BIT11
#define ATD1DR11_BIT12                  _ATD1DR11.Bits.BIT12
#define ATD1DR11_BIT13                  _ATD1DR11.Bits.BIT13
#define ATD1DR11_BIT14                  _ATD1DR11.Bits.BIT14
#define ATD1DR11_BIT15                  _ATD1DR11.Bits.BIT15
#define ATD1DR11_BIT_6                  _ATD1DR11.MergedBits.grpBIT_6
#define ATD1DR11_BIT                    ATD1DR11_BIT_6

#define ATD1DR11_BIT6_MASK              64
#define ATD1DR11_BIT7_MASK              128
#define ATD1DR11_BIT8_MASK              256
#define ATD1DR11_BIT9_MASK              512
#define ATD1DR11_BIT10_MASK             1024
#define ATD1DR11_BIT11_MASK             2048
#define ATD1DR11_BIT12_MASK             4096
#define ATD1DR11_BIT13_MASK             8192
#define ATD1DR11_BIT14_MASK             16384
#define ATD1DR11_BIT15_MASK             32768
#define ATD1DR11_BIT_6_MASK             65472
#define ATD1DR11_BIT_6_BITNUM           6


 ATD1DR12 - ATD 1 Conversion Result Register 12; 0x000000A8 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR12H - ATD 1 Conversion Result Register 12 High; 0x000000A8 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR12HSTR;
    #define ATD1DR12H                   _ATD1DR12.Overlap_STR.ATD1DR12HSTR.Byte
    #define ATD1DR12H_BIT8              _ATD1DR12.Overlap_STR.ATD1DR12HSTR.Bits.BIT8
    #define ATD1DR12H_BIT9              _ATD1DR12.Overlap_STR.ATD1DR12HSTR.Bits.BIT9
    #define ATD1DR12H_BIT10             _ATD1DR12.Overlap_STR.ATD1DR12HSTR.Bits.BIT10
    #define ATD1DR12H_BIT11             _ATD1DR12.Overlap_STR.ATD1DR12HSTR.Bits.BIT11
    #define ATD1DR12H_BIT12             _ATD1DR12.Overlap_STR.ATD1DR12HSTR.Bits.BIT12
    #define ATD1DR12H_BIT13             _ATD1DR12.Overlap_STR.ATD1DR12HSTR.Bits.BIT13
    #define ATD1DR12H_BIT14             _ATD1DR12.Overlap_STR.ATD1DR12HSTR.Bits.BIT14
    #define ATD1DR12H_BIT15             _ATD1DR12.Overlap_STR.ATD1DR12HSTR.Bits.BIT15
    
    
    #define ATD1DR12H_BIT8_MASK         1
    #define ATD1DR12H_BIT9_MASK         2
    #define ATD1DR12H_BIT10_MASK        4
    #define ATD1DR12H_BIT11_MASK        8
    #define ATD1DR12H_BIT12_MASK        16
    #define ATD1DR12H_BIT13_MASK        32
    #define ATD1DR12H_BIT14_MASK        64
    #define ATD1DR12H_BIT15_MASK        128


     ATD1DR12L - ATD 1 Conversion Result Register 12 Low; 0x000000A9 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR12LSTR;
    #define ATD1DR12L                   _ATD1DR12.Overlap_STR.ATD1DR12LSTR.Byte
    #define ATD1DR12L_BIT6              _ATD1DR12.Overlap_STR.ATD1DR12LSTR.Bits.BIT6
    #define ATD1DR12L_BIT7              _ATD1DR12.Overlap_STR.ATD1DR12LSTR.Bits.BIT7
    
    #define ATD1DR12L_BIT_6             _ATD1DR12.Overlap_STR.ATD1DR12LSTR.MergedBits.grpBIT_6
    #define ATD1DR12L_BIT               ATD1DR12L_BIT_6
    
    #define ATD1DR12L_BIT6_MASK         64
    #define ATD1DR12L_BIT7_MASK         128
    #define ATD1DR12L_BIT_6_MASK        192
    #define ATD1DR12L_BIT_6_BITNUM      6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR12STR;
extern volatile ATD1DR12STR _ATD1DR12 @(REG_BASE + 0x000000A8);
#define ATD1DR12                        _ATD1DR12.Word
#define ATD1DR12_BIT6                   _ATD1DR12.Bits.BIT6
#define ATD1DR12_BIT7                   _ATD1DR12.Bits.BIT7
#define ATD1DR12_BIT8                   _ATD1DR12.Bits.BIT8
#define ATD1DR12_BIT9                   _ATD1DR12.Bits.BIT9
#define ATD1DR12_BIT10                  _ATD1DR12.Bits.BIT10
#define ATD1DR12_BIT11                  _ATD1DR12.Bits.BIT11
#define ATD1DR12_BIT12                  _ATD1DR12.Bits.BIT12
#define ATD1DR12_BIT13                  _ATD1DR12.Bits.BIT13
#define ATD1DR12_BIT14                  _ATD1DR12.Bits.BIT14
#define ATD1DR12_BIT15                  _ATD1DR12.Bits.BIT15
#define ATD1DR12_BIT_6                  _ATD1DR12.MergedBits.grpBIT_6
#define ATD1DR12_BIT                    ATD1DR12_BIT_6

#define ATD1DR12_BIT6_MASK              64
#define ATD1DR12_BIT7_MASK              128
#define ATD1DR12_BIT8_MASK              256
#define ATD1DR12_BIT9_MASK              512
#define ATD1DR12_BIT10_MASK             1024
#define ATD1DR12_BIT11_MASK             2048
#define ATD1DR12_BIT12_MASK             4096
#define ATD1DR12_BIT13_MASK             8192
#define ATD1DR12_BIT14_MASK             16384
#define ATD1DR12_BIT15_MASK             32768
#define ATD1DR12_BIT_6_MASK             65472
#define ATD1DR12_BIT_6_BITNUM           6


 ATD1DR13 - ATD 1 Conversion Result Register 13; 0x000000AA 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR13H - ATD 1 Conversion Result Register 13 High; 0x000000AA 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR13HSTR;
    #define ATD1DR13H                   _ATD1DR13.Overlap_STR.ATD1DR13HSTR.Byte
    #define ATD1DR13H_BIT8              _ATD1DR13.Overlap_STR.ATD1DR13HSTR.Bits.BIT8
    #define ATD1DR13H_BIT9              _ATD1DR13.Overlap_STR.ATD1DR13HSTR.Bits.BIT9
    #define ATD1DR13H_BIT10             _ATD1DR13.Overlap_STR.ATD1DR13HSTR.Bits.BIT10
    #define ATD1DR13H_BIT11             _ATD1DR13.Overlap_STR.ATD1DR13HSTR.Bits.BIT11
    #define ATD1DR13H_BIT12             _ATD1DR13.Overlap_STR.ATD1DR13HSTR.Bits.BIT12
    #define ATD1DR13H_BIT13             _ATD1DR13.Overlap_STR.ATD1DR13HSTR.Bits.BIT13
    #define ATD1DR13H_BIT14             _ATD1DR13.Overlap_STR.ATD1DR13HSTR.Bits.BIT14
    #define ATD1DR13H_BIT15             _ATD1DR13.Overlap_STR.ATD1DR13HSTR.Bits.BIT15
    
    
    #define ATD1DR13H_BIT8_MASK         1
    #define ATD1DR13H_BIT9_MASK         2
    #define ATD1DR13H_BIT10_MASK        4
    #define ATD1DR13H_BIT11_MASK        8
    #define ATD1DR13H_BIT12_MASK        16
    #define ATD1DR13H_BIT13_MASK        32
    #define ATD1DR13H_BIT14_MASK        64
    #define ATD1DR13H_BIT15_MASK        128


     ATD1DR13L - ATD 1 Conversion Result Register 13 Low; 0x000000AB 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR13LSTR;
    #define ATD1DR13L                   _ATD1DR13.Overlap_STR.ATD1DR13LSTR.Byte
    #define ATD1DR13L_BIT6              _ATD1DR13.Overlap_STR.ATD1DR13LSTR.Bits.BIT6
    #define ATD1DR13L_BIT7              _ATD1DR13.Overlap_STR.ATD1DR13LSTR.Bits.BIT7
    
    #define ATD1DR13L_BIT_6             _ATD1DR13.Overlap_STR.ATD1DR13LSTR.MergedBits.grpBIT_6
    #define ATD1DR13L_BIT               ATD1DR13L_BIT_6
    
    #define ATD1DR13L_BIT6_MASK         64
    #define ATD1DR13L_BIT7_MASK         128
    #define ATD1DR13L_BIT_6_MASK        192
    #define ATD1DR13L_BIT_6_BITNUM      6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR13STR;
extern volatile ATD1DR13STR _ATD1DR13 @(REG_BASE + 0x000000AA);
#define ATD1DR13                        _ATD1DR13.Word
#define ATD1DR13_BIT6                   _ATD1DR13.Bits.BIT6
#define ATD1DR13_BIT7                   _ATD1DR13.Bits.BIT7
#define ATD1DR13_BIT8                   _ATD1DR13.Bits.BIT8
#define ATD1DR13_BIT9                   _ATD1DR13.Bits.BIT9
#define ATD1DR13_BIT10                  _ATD1DR13.Bits.BIT10
#define ATD1DR13_BIT11                  _ATD1DR13.Bits.BIT11
#define ATD1DR13_BIT12                  _ATD1DR13.Bits.BIT12
#define ATD1DR13_BIT13                  _ATD1DR13.Bits.BIT13
#define ATD1DR13_BIT14                  _ATD1DR13.Bits.BIT14
#define ATD1DR13_BIT15                  _ATD1DR13.Bits.BIT15
#define ATD1DR13_BIT_6                  _ATD1DR13.MergedBits.grpBIT_6
#define ATD1DR13_BIT                    ATD1DR13_BIT_6

#define ATD1DR13_BIT6_MASK              64
#define ATD1DR13_BIT7_MASK              128
#define ATD1DR13_BIT8_MASK              256
#define ATD1DR13_BIT9_MASK              512
#define ATD1DR13_BIT10_MASK             1024
#define ATD1DR13_BIT11_MASK             2048
#define ATD1DR13_BIT12_MASK             4096
#define ATD1DR13_BIT13_MASK             8192
#define ATD1DR13_BIT14_MASK             16384
#define ATD1DR13_BIT15_MASK             32768
#define ATD1DR13_BIT_6_MASK             65472
#define ATD1DR13_BIT_6_BITNUM           6


 ATD1DR14 - ATD 1 Conversion Result Register 14; 0x000000AC 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR14H - ATD 1 Conversion Result Register 14 High; 0x000000AC 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR14HSTR;
    #define ATD1DR14H                   _ATD1DR14.Overlap_STR.ATD1DR14HSTR.Byte
    #define ATD1DR14H_BIT8              _ATD1DR14.Overlap_STR.ATD1DR14HSTR.Bits.BIT8
    #define ATD1DR14H_BIT9              _ATD1DR14.Overlap_STR.ATD1DR14HSTR.Bits.BIT9
    #define ATD1DR14H_BIT10             _ATD1DR14.Overlap_STR.ATD1DR14HSTR.Bits.BIT10
    #define ATD1DR14H_BIT11             _ATD1DR14.Overlap_STR.ATD1DR14HSTR.Bits.BIT11
    #define ATD1DR14H_BIT12             _ATD1DR14.Overlap_STR.ATD1DR14HSTR.Bits.BIT12
    #define ATD1DR14H_BIT13             _ATD1DR14.Overlap_STR.ATD1DR14HSTR.Bits.BIT13
    #define ATD1DR14H_BIT14             _ATD1DR14.Overlap_STR.ATD1DR14HSTR.Bits.BIT14
    #define ATD1DR14H_BIT15             _ATD1DR14.Overlap_STR.ATD1DR14HSTR.Bits.BIT15
    
    
    #define ATD1DR14H_BIT8_MASK         1
    #define ATD1DR14H_BIT9_MASK         2
    #define ATD1DR14H_BIT10_MASK        4
    #define ATD1DR14H_BIT11_MASK        8
    #define ATD1DR14H_BIT12_MASK        16
    #define ATD1DR14H_BIT13_MASK        32
    #define ATD1DR14H_BIT14_MASK        64
    #define ATD1DR14H_BIT15_MASK        128


     ATD1DR14L - ATD 1 Conversion Result Register 14 Low; 0x000000AD 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR14LSTR;
    #define ATD1DR14L                   _ATD1DR14.Overlap_STR.ATD1DR14LSTR.Byte
    #define ATD1DR14L_BIT6              _ATD1DR14.Overlap_STR.ATD1DR14LSTR.Bits.BIT6
    #define ATD1DR14L_BIT7              _ATD1DR14.Overlap_STR.ATD1DR14LSTR.Bits.BIT7
    
    #define ATD1DR14L_BIT_6             _ATD1DR14.Overlap_STR.ATD1DR14LSTR.MergedBits.grpBIT_6
    #define ATD1DR14L_BIT               ATD1DR14L_BIT_6
    
    #define ATD1DR14L_BIT6_MASK         64
    #define ATD1DR14L_BIT7_MASK         128
    #define ATD1DR14L_BIT_6_MASK        192
    #define ATD1DR14L_BIT_6_BITNUM      6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR14STR;
extern volatile ATD1DR14STR _ATD1DR14 @(REG_BASE + 0x000000AC);
#define ATD1DR14                        _ATD1DR14.Word
#define ATD1DR14_BIT6                   _ATD1DR14.Bits.BIT6
#define ATD1DR14_BIT7                   _ATD1DR14.Bits.BIT7
#define ATD1DR14_BIT8                   _ATD1DR14.Bits.BIT8
#define ATD1DR14_BIT9                   _ATD1DR14.Bits.BIT9
#define ATD1DR14_BIT10                  _ATD1DR14.Bits.BIT10
#define ATD1DR14_BIT11                  _ATD1DR14.Bits.BIT11
#define ATD1DR14_BIT12                  _ATD1DR14.Bits.BIT12
#define ATD1DR14_BIT13                  _ATD1DR14.Bits.BIT13
#define ATD1DR14_BIT14                  _ATD1DR14.Bits.BIT14
#define ATD1DR14_BIT15                  _ATD1DR14.Bits.BIT15
#define ATD1DR14_BIT_6                  _ATD1DR14.MergedBits.grpBIT_6
#define ATD1DR14_BIT                    ATD1DR14_BIT_6

#define ATD1DR14_BIT6_MASK              64
#define ATD1DR14_BIT7_MASK              128
#define ATD1DR14_BIT8_MASK              256
#define ATD1DR14_BIT9_MASK              512
#define ATD1DR14_BIT10_MASK             1024
#define ATD1DR14_BIT11_MASK             2048
#define ATD1DR14_BIT12_MASK             4096
#define ATD1DR14_BIT13_MASK             8192
#define ATD1DR14_BIT14_MASK             16384
#define ATD1DR14_BIT15_MASK             32768
#define ATD1DR14_BIT_6_MASK             65472
#define ATD1DR14_BIT_6_BITNUM           6


 ATD1DR15 - ATD 1 Conversion Result Register 15; 0x000000AE 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD1DR15H - ATD 1 Conversion Result Register 15 High; 0x000000AE 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD1DR15HSTR;
    #define ATD1DR15H                   _ATD1DR15.Overlap_STR.ATD1DR15HSTR.Byte
    #define ATD1DR15H_BIT8              _ATD1DR15.Overlap_STR.ATD1DR15HSTR.Bits.BIT8
    #define ATD1DR15H_BIT9              _ATD1DR15.Overlap_STR.ATD1DR15HSTR.Bits.BIT9
    #define ATD1DR15H_BIT10             _ATD1DR15.Overlap_STR.ATD1DR15HSTR.Bits.BIT10
    #define ATD1DR15H_BIT11             _ATD1DR15.Overlap_STR.ATD1DR15HSTR.Bits.BIT11
    #define ATD1DR15H_BIT12             _ATD1DR15.Overlap_STR.ATD1DR15HSTR.Bits.BIT12
    #define ATD1DR15H_BIT13             _ATD1DR15.Overlap_STR.ATD1DR15HSTR.Bits.BIT13
    #define ATD1DR15H_BIT14             _ATD1DR15.Overlap_STR.ATD1DR15HSTR.Bits.BIT14
    #define ATD1DR15H_BIT15             _ATD1DR15.Overlap_STR.ATD1DR15HSTR.Bits.BIT15
    
    
    #define ATD1DR15H_BIT8_MASK         1
    #define ATD1DR15H_BIT9_MASK         2
    #define ATD1DR15H_BIT10_MASK        4
    #define ATD1DR15H_BIT11_MASK        8
    #define ATD1DR15H_BIT12_MASK        16
    #define ATD1DR15H_BIT13_MASK        32
    #define ATD1DR15H_BIT14_MASK        64
    #define ATD1DR15H_BIT15_MASK        128


     ATD1DR15L - ATD 1 Conversion Result Register 15 Low; 0x000000AF 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD1DR15LSTR;
    #define ATD1DR15L                   _ATD1DR15.Overlap_STR.ATD1DR15LSTR.Byte
    #define ATD1DR15L_BIT6              _ATD1DR15.Overlap_STR.ATD1DR15LSTR.Bits.BIT6
    #define ATD1DR15L_BIT7              _ATD1DR15.Overlap_STR.ATD1DR15LSTR.Bits.BIT7
    
    #define ATD1DR15L_BIT_6             _ATD1DR15.Overlap_STR.ATD1DR15LSTR.MergedBits.grpBIT_6
    #define ATD1DR15L_BIT               ATD1DR15L_BIT_6
    
    #define ATD1DR15L_BIT6_MASK         64
    #define ATD1DR15L_BIT7_MASK         128
    #define ATD1DR15L_BIT_6_MASK        192
    #define ATD1DR15L_BIT_6_BITNUM      6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD1DR15STR;
extern volatile ATD1DR15STR _ATD1DR15 @(REG_BASE + 0x000000AE);
#define ATD1DR15                        _ATD1DR15.Word
#define ATD1DR15_BIT6                   _ATD1DR15.Bits.BIT6
#define ATD1DR15_BIT7                   _ATD1DR15.Bits.BIT7
#define ATD1DR15_BIT8                   _ATD1DR15.Bits.BIT8
#define ATD1DR15_BIT9                   _ATD1DR15.Bits.BIT9
#define ATD1DR15_BIT10                  _ATD1DR15.Bits.BIT10
#define ATD1DR15_BIT11                  _ATD1DR15.Bits.BIT11
#define ATD1DR15_BIT12                  _ATD1DR15.Bits.BIT12
#define ATD1DR15_BIT13                  _ATD1DR15.Bits.BIT13
#define ATD1DR15_BIT14                  _ATD1DR15.Bits.BIT14
#define ATD1DR15_BIT15                  _ATD1DR15.Bits.BIT15
#define ATD1DR15_BIT_6                  _ATD1DR15.MergedBits.grpBIT_6
#define ATD1DR15_BIT                    ATD1DR15_BIT_6

#define ATD1DR15_BIT6_MASK              64
#define ATD1DR15_BIT7_MASK              128
#define ATD1DR15_BIT8_MASK              256
#define ATD1DR15_BIT9_MASK              512
#define ATD1DR15_BIT10_MASK             1024
#define ATD1DR15_BIT11_MASK             2048
#define ATD1DR15_BIT12_MASK             4096
#define ATD1DR15_BIT13_MASK             8192
#define ATD1DR15_BIT14_MASK             16384
#define ATD1DR15_BIT15_MASK             32768
#define ATD1DR15_BIT_6_MASK             65472
#define ATD1DR15_BIT_6_BITNUM           6


 SCI2BD - SCI 2 Baud Rate Register; 0x000000B8 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     SCI2ASR1 - SCI 2 Alternative Status Register 1; 0x000000B8 
    union {
      byte Byte;
      union { Several registers at the same address 
         SCI2ASR1 - SCI 2 Alternative Status Register 1; Several registers at the same address 
        union {
          struct {
            byte BKDIF       1;                                        Break Detect Interrupt Flag 
            byte BERRIF      1;                                        Bit Error Interrupt Flag 
            byte BERRV       1;                                        Bit Error Value 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte RXEDGIF     1;                                        Receive Input Active Edge Interrupt Flag 
          } Bits;
        } SCI2ASR1STR;
        #define SCI2ASR1                _SCI2BD.Overlap_STR.SCI2ASR1STR.Byte
        #define SCI2ASR1_BKDIF          _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2ASR1STR.Bits.BKDIF
        #define SCI2ASR1_BERRIF         _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2ASR1STR.Bits.BERRIF
        #define SCI2ASR1_BERRV          _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2ASR1STR.Bits.BERRV
        #define SCI2ASR1_RXEDGIF        _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2ASR1STR.Bits.RXEDGIF
        
        
        #define SCI2ASR1_BKDIF_MASK     1
        #define SCI2ASR1_BERRIF_MASK    2
        #define SCI2ASR1_BERRV_MASK     4
        #define SCI2ASR1_RXEDGIF_MASK   128
    
         SCI2BDH - SCI 2 Baud Rate Register High; Several registers at the same address 
        union {
          struct {
            byte SBR8        1;                                        SCI Baud Rate Bit 8 
            byte SBR9        1;                                        SCI Baud Rate Bit 9 
            byte SBR10       1;                                        SCI Baud Rate Bit 10 
            byte SBR11       1;                                        SCI Baud Rate Bit 11 
            byte SBR12       1;                                        SCI Baud Rate Bit 12 
            byte TNP0        1;                                        Transmitter Narrow Pulse Bit 0 
            byte TNP1        1;                                        Transmitter Narrow Pulse Bit 1 
            byte IREN        1;                                        Infrared Enable Bit 
          } Bits;
          struct {
            byte grpSBR_8 5;
            byte grpTNP 2;
            byte 1;
          } MergedBits;
        } SCI2BDHSTR;
        #define SCI2BDH                 _SCI2BD.Overlap_STR.SCI2ASR1STR.Byte
        #define SCI2BDH_SBR8            _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.Bits.SBR8
        #define SCI2BDH_SBR9            _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.Bits.SBR9
        #define SCI2BDH_SBR10           _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.Bits.SBR10
        #define SCI2BDH_SBR11           _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.Bits.SBR11
        #define SCI2BDH_SBR12           _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.Bits.SBR12
        #define SCI2BDH_TNP0            _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.Bits.TNP0
        #define SCI2BDH_TNP1            _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.Bits.TNP1
        #define SCI2BDH_IREN            _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.Bits.IREN
        
        #define SCI2BDH_SBR_8           _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.MergedBits.grpSBR_8
        #define SCI2BDH_TNP             _SCI2BD.Overlap_STR.SCI2ASR1STR.SameAddr_STR.SCI2BDHSTR.MergedBits.grpTNP
        #define SCI2BDH_SBR             SCI2BDH_SBR_8
        
        #define SCI2BDH_SBR8_MASK       1
        #define SCI2BDH_SBR9_MASK       2
        #define SCI2BDH_SBR10_MASK      4
        #define SCI2BDH_SBR11_MASK      8
        #define SCI2BDH_SBR12_MASK      16
        #define SCI2BDH_TNP0_MASK       32
        #define SCI2BDH_TNP1_MASK       64
        #define SCI2BDH_IREN_MASK       128
        #define SCI2BDH_SBR_8_MASK      31
        #define SCI2BDH_SBR_8_BITNUM    0
        #define SCI2BDH_TNP_MASK        96
        #define SCI2BDH_TNP_BITNUM      5
    
      } SameAddr_STR; Several registers at the same address 
    
    } SCI2ASR1STR;
    


     SCI2ACR1 - SCI 2 Alternative Control Register 1; 0x000000B9 
    union {
      byte Byte;
      union { Several registers at the same address 
         SCI2ACR1 - SCI 2 Alternative Control Register 1; Several registers at the same address 
        union {
          struct {
            byte BKDIE       1;                                        Break Detect Interrupt Enable 
            byte BERRIE      1;                                        Bit Error Interrupt Enable 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte RXEDGIE     1;                                        Receive Input Active Edge Interrupt Enable 
          } Bits;
        } SCI2ACR1STR;
        #define SCI2ACR1                _SCI2BD.Overlap_STR.SCI2ACR1STR.Byte
        #define SCI2ACR1_BKDIE          _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2ACR1STR.Bits.BKDIE
        #define SCI2ACR1_BERRIE         _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2ACR1STR.Bits.BERRIE
        #define SCI2ACR1_RXEDGIE        _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2ACR1STR.Bits.RXEDGIE
        
        
        #define SCI2ACR1_BKDIE_MASK     1
        #define SCI2ACR1_BERRIE_MASK    2
        #define SCI2ACR1_RXEDGIE_MASK   128
    
         SCI2BDL - SCI 2 Baud Rate Register Low; Several registers at the same address 
        union {
          struct {
            byte SBR0        1;                                        SCI Baud Rate Bit 0 
            byte SBR1        1;                                        SCI Baud Rate Bit 1 
            byte SBR2        1;                                        SCI Baud Rate Bit 2 
            byte SBR3        1;                                        SCI Baud Rate Bit 3 
            byte SBR4        1;                                        SCI Baud Rate Bit 4 
            byte SBR5        1;                                        SCI Baud Rate Bit 5 
            byte SBR6        1;                                        SCI Baud Rate Bit 6 
            byte SBR7        1;                                        SCI Baud Rate Bit 7 
          } Bits;
        } SCI2BDLSTR;
        #define SCI2BDL                 _SCI2BD.Overlap_STR.SCI2ACR1STR.Byte
        #define SCI2BDL_SBR0            _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2BDLSTR.Bits.SBR0
        #define SCI2BDL_SBR1            _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2BDLSTR.Bits.SBR1
        #define SCI2BDL_SBR2            _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2BDLSTR.Bits.SBR2
        #define SCI2BDL_SBR3            _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2BDLSTR.Bits.SBR3
        #define SCI2BDL_SBR4            _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2BDLSTR.Bits.SBR4
        #define SCI2BDL_SBR5            _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2BDLSTR.Bits.SBR5
        #define SCI2BDL_SBR6            _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2BDLSTR.Bits.SBR6
        #define SCI2BDL_SBR7            _SCI2BD.Overlap_STR.SCI2ACR1STR.SameAddr_STR.SCI2BDLSTR.Bits.SBR7
        
        
        #define SCI2BDL_SBR0_MASK       1
        #define SCI2BDL_SBR1_MASK       2
        #define SCI2BDL_SBR2_MASK       4
        #define SCI2BDL_SBR3_MASK       8
        #define SCI2BDL_SBR4_MASK       16
        #define SCI2BDL_SBR5_MASK       32
        #define SCI2BDL_SBR6_MASK       64
        #define SCI2BDL_SBR7_MASK       128
    
      } SameAddr_STR; Several registers at the same address 
    
    } SCI2ACR1STR;
    

  } Overlap_STR;

  struct {
    word SBR0        1;                                        SCI Baud Rate Bit 0 
    word SBR1        1;                                        SCI Baud Rate Bit 1 
    word SBR2        1;                                        SCI Baud Rate Bit 2 
    word SBR3        1;                                        SCI Baud Rate Bit 3 
    word SBR4        1;                                        SCI Baud Rate Bit 4 
    word SBR5        1;                                        SCI Baud Rate Bit 5 
    word SBR6        1;                                        SCI Baud Rate Bit 6 
    word SBR7        1;                                        SCI Baud Rate Bit 7 
    word SBR8        1;                                        SCI Baud Rate Bit 8 
    word SBR9        1;                                        SCI Baud Rate Bit 9 
    word SBR10       1;                                        SCI Baud Rate Bit 10 
    word SBR11       1;                                        SCI Baud Rate Bit 11 
    word SBR12       1;                                        SCI Baud Rate Bit 12 
    word TNP0        1;                                        Transmitter Narrow Pulse Bit 0 
    word TNP1        1;                                        Transmitter Narrow Pulse Bit 1 
    word IREN        1;                                        Infrared Enable Bit 
  } Bits;
  struct {
    word grpSBR  13;
    word grpTNP  2;
    word         1;
  } MergedBits;
} SCI2BDSTR;
extern volatile SCI2BDSTR _SCI2BD @(REG_BASE + 0x000000B8);
#define SCI2BD                          _SCI2BD.Word
#define SCI2BD_SBR0                     _SCI2BD.Bits.SBR0
#define SCI2BD_SBR1                     _SCI2BD.Bits.SBR1
#define SCI2BD_SBR2                     _SCI2BD.Bits.SBR2
#define SCI2BD_SBR3                     _SCI2BD.Bits.SBR3
#define SCI2BD_SBR4                     _SCI2BD.Bits.SBR4
#define SCI2BD_SBR5                     _SCI2BD.Bits.SBR5
#define SCI2BD_SBR6                     _SCI2BD.Bits.SBR6
#define SCI2BD_SBR7                     _SCI2BD.Bits.SBR7
#define SCI2BD_SBR8                     _SCI2BD.Bits.SBR8
#define SCI2BD_SBR9                     _SCI2BD.Bits.SBR9
#define SCI2BD_SBR10                    _SCI2BD.Bits.SBR10
#define SCI2BD_SBR11                    _SCI2BD.Bits.SBR11
#define SCI2BD_SBR12                    _SCI2BD.Bits.SBR12
#define SCI2BD_TNP0                     _SCI2BD.Bits.TNP0
#define SCI2BD_TNP1                     _SCI2BD.Bits.TNP1
#define SCI2BD_IREN                     _SCI2BD.Bits.IREN
#define SCI2BD_SBR                      _SCI2BD.MergedBits.grpSBR
#define SCI2BD_TNP                      _SCI2BD.MergedBits.grpTNP

#define SCI2BD_SBR0_MASK                1
#define SCI2BD_SBR1_MASK                2
#define SCI2BD_SBR2_MASK                4
#define SCI2BD_SBR3_MASK                8
#define SCI2BD_SBR4_MASK                16
#define SCI2BD_SBR5_MASK                32
#define SCI2BD_SBR6_MASK                64
#define SCI2BD_SBR7_MASK                128
#define SCI2BD_SBR8_MASK                256
#define SCI2BD_SBR9_MASK                512
#define SCI2BD_SBR10_MASK               1024
#define SCI2BD_SBR11_MASK               2048
#define SCI2BD_SBR12_MASK               4096
#define SCI2BD_TNP0_MASK                8192
#define SCI2BD_TNP1_MASK                16384
#define SCI2BD_IREN_MASK                32768
#define SCI2BD_SBR_MASK                 8191
#define SCI2BD_SBR_BITNUM               0
#define SCI2BD_TNP_MASK                 24576
#define SCI2BD_TNP_BITNUM               13


 SCI2ACR2 - SCI 2 Alternative Control Register 2; 0x000000BA 
typedef union {
  byte Byte;
  union { Several registers at the same address 
     SCI2ACR2 - SCI 2 Alternative Control Register 2; Several registers at the same address 
    union {
      struct {
        byte BKDFE       1;                                        Break Detect Feature Enable 
        byte BERRM0      1;                                        Bit Error Mode Bit 0 
        byte BERRM1      1;                                        Bit Error Mode Bit 1 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
      } Bits;
      struct {
        byte     1;
        byte grpBERRM 2;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } SCI2ACR2STR;
    #define SCI2ACR2                    _SCI2ACR2.Byte
    #define SCI2ACR2_BKDFE              _SCI2ACR2.SameAddr_STR.SCI2ACR2STR.Bits.BKDFE
    #define SCI2ACR2_BERRM0             _SCI2ACR2.SameAddr_STR.SCI2ACR2STR.Bits.BERRM0
    #define SCI2ACR2_BERRM1             _SCI2ACR2.SameAddr_STR.SCI2ACR2STR.Bits.BERRM1
    
    #define SCI2ACR2_BERRM              _SCI2ACR2.SameAddr_STR.SCI2ACR2STR.MergedBits.grpBERRM
    
    #define SCI2ACR2_BKDFE_MASK         1
    #define SCI2ACR2_BERRM0_MASK        2
    #define SCI2ACR2_BERRM1_MASK        4
    #define SCI2ACR2_BERRM_MASK         6
    #define SCI2ACR2_BERRM_BITNUM       1

     SCI2CR1 - SCI 2 Control Register 1; Several registers at the same address 
    union {
      struct {
        byte PT          1;                                        Parity Type Bit 
        byte PE          1;                                        Parity Enable Bit 
        byte ILT         1;                                        Idle Line Type Bit 
        byte WAKE        1;                                        Wakeup Condition Bit 
        byte M           1;                                        Data Format Mode Bit 
        byte RSRC        1;                                        Receiver Source Bit 
        byte SCISWAI     1;                                        SCI Stop in Wait Mode Bit 
        byte LOOPS       1;                                        Loop Select Bit 
      } Bits;
    } SCI2CR1STR;
    #define SCI2CR1                     _SCI2ACR2.Byte
    #define SCI2CR1_PT                  _SCI2ACR2.SameAddr_STR.SCI2CR1STR.Bits.PT
    #define SCI2CR1_PE                  _SCI2ACR2.SameAddr_STR.SCI2CR1STR.Bits.PE
    #define SCI2CR1_ILT                 _SCI2ACR2.SameAddr_STR.SCI2CR1STR.Bits.ILT
    #define SCI2CR1_WAKE                _SCI2ACR2.SameAddr_STR.SCI2CR1STR.Bits.WAKE
    #define SCI2CR1_M                   _SCI2ACR2.SameAddr_STR.SCI2CR1STR.Bits.M
    #define SCI2CR1_RSRC                _SCI2ACR2.SameAddr_STR.SCI2CR1STR.Bits.RSRC
    #define SCI2CR1_SCISWAI             _SCI2ACR2.SameAddr_STR.SCI2CR1STR.Bits.SCISWAI
    #define SCI2CR1_LOOPS               _SCI2ACR2.SameAddr_STR.SCI2CR1STR.Bits.LOOPS
    
    
    #define SCI2CR1_PT_MASK             1
    #define SCI2CR1_PE_MASK             2
    #define SCI2CR1_ILT_MASK            4
    #define SCI2CR1_WAKE_MASK           8
    #define SCI2CR1_M_MASK              16
    #define SCI2CR1_RSRC_MASK           32
    #define SCI2CR1_SCISWAI_MASK        64
    #define SCI2CR1_LOOPS_MASK          128

  } SameAddr_STR; Several registers at the same address 

} SCI2ACR2STR;
extern volatile SCI2ACR2STR _SCI2ACR2 @(REG_BASE + 0x000000BA);



 SCI2CR2 - SCI 2 Control Register 2; 0x000000BB 
typedef union {
  byte Byte;
  struct {
    byte SBK         1;                                        Send Break Bit 
    byte RWU         1;                                        Receiver Wakeup Bit 
    byte RE          1;                                        Receiver Enable Bit 
    byte TE          1;                                        Transmitter Enable Bit 
    byte ILIE        1;                                        Idle Line Interrupt Enable Bit 
    byte RIE         1;                                        Receiver Full Interrupt Enable Bit 
    byte TCIE        1;                                        Transmission Complete Interrupt Enable Bit 
    byte SCTIE       1;                                        Transmitter Interrupt Enable Bit 
  } Bits;
} SCI2CR2STR;
extern volatile SCI2CR2STR _SCI2CR2 @(REG_BASE + 0x000000BB);
#define SCI2CR2                         _SCI2CR2.Byte
#define SCI2CR2_SBK                     _SCI2CR2.Bits.SBK
#define SCI2CR2_RWU                     _SCI2CR2.Bits.RWU
#define SCI2CR2_RE                      _SCI2CR2.Bits.RE
#define SCI2CR2_TE                      _SCI2CR2.Bits.TE
#define SCI2CR2_ILIE                    _SCI2CR2.Bits.ILIE
#define SCI2CR2_RIE                     _SCI2CR2.Bits.RIE
#define SCI2CR2_TCIE                    _SCI2CR2.Bits.TCIE
#define SCI2CR2_SCTIE                   _SCI2CR2.Bits.SCTIE

#define SCI2CR2_SBK_MASK                1
#define SCI2CR2_RWU_MASK                2
#define SCI2CR2_RE_MASK                 4
#define SCI2CR2_TE_MASK                 8
#define SCI2CR2_ILIE_MASK               16
#define SCI2CR2_RIE_MASK                32
#define SCI2CR2_TCIE_MASK               64
#define SCI2CR2_SCTIE_MASK              128


 SCI2SR1 - SCI 2 Status Register 1; 0x000000BC 
typedef union {
  byte Byte;
  struct {
    byte PF          1;                                        Parity Error Flag 
    byte FE          1;                                        Framing Error Flag 
    byte NF          1;                                        Noise Flag 
    byte OR          1;                                        Overrun Flag 
    byte IDLE        1;                                        Idle Line Flag 
    byte RDRF        1;                                        Receive Data Register Full Flag 
    byte TC          1;                                        Transmit Complete Flag 
    byte TDRE        1;                                        Transmit Data Register Empty Flag 
  } Bits;
} SCI2SR1STR;
extern volatile SCI2SR1STR _SCI2SR1 @(REG_BASE + 0x000000BC);
#define SCI2SR1                         _SCI2SR1.Byte
#define SCI2SR1_PF                      _SCI2SR1.Bits.PF
#define SCI2SR1_FE                      _SCI2SR1.Bits.FE
#define SCI2SR1_NF                      _SCI2SR1.Bits.NF
#define SCI2SR1_OR                      _SCI2SR1.Bits.OR
#define SCI2SR1_IDLE                    _SCI2SR1.Bits.IDLE
#define SCI2SR1_RDRF                    _SCI2SR1.Bits.RDRF
#define SCI2SR1_TC                      _SCI2SR1.Bits.TC
#define SCI2SR1_TDRE                    _SCI2SR1.Bits.TDRE

#define SCI2SR1_PF_MASK                 1
#define SCI2SR1_FE_MASK                 2
#define SCI2SR1_NF_MASK                 4
#define SCI2SR1_OR_MASK                 8
#define SCI2SR1_IDLE_MASK               16
#define SCI2SR1_RDRF_MASK               32
#define SCI2SR1_TC_MASK                 64
#define SCI2SR1_TDRE_MASK               128


 SCI2SR2 - SCI 2 Status Register 2; 0x000000BD 
typedef union {
  byte Byte;
  struct {
    byte RAF         1;                                        Receiver Active Flag 
    byte TXDIR       1;                                        Transmitter pin data direction in Single-Wire mode 
    byte BRK13       1;                                        Break Transmit character length 
    byte RXPOL       1;                                        Receive Polarity 
    byte TXPOL       1;                                        Transmit Polarity 
    byte             1; 
    byte             1; 
    byte AMAP        1;                                        Alternative Map 
  } Bits;
} SCI2SR2STR;
extern volatile SCI2SR2STR _SCI2SR2 @(REG_BASE + 0x000000BD);
#define SCI2SR2                         _SCI2SR2.Byte
#define SCI2SR2_RAF                     _SCI2SR2.Bits.RAF
#define SCI2SR2_TXDIR                   _SCI2SR2.Bits.TXDIR
#define SCI2SR2_BRK13                   _SCI2SR2.Bits.BRK13
#define SCI2SR2_RXPOL                   _SCI2SR2.Bits.RXPOL
#define SCI2SR2_TXPOL                   _SCI2SR2.Bits.TXPOL
#define SCI2SR2_AMAP                    _SCI2SR2.Bits.AMAP

#define SCI2SR2_RAF_MASK                1
#define SCI2SR2_TXDIR_MASK              2
#define SCI2SR2_BRK13_MASK              4
#define SCI2SR2_RXPOL_MASK              8
#define SCI2SR2_TXPOL_MASK              16
#define SCI2SR2_AMAP_MASK               128


 SCI2DRH - SCI 2 Data Register High; 0x000000BE 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte T8          1;                                        Transmit Bit 8 
    byte R8          1;                                        Received Bit 8 
  } Bits;
} SCI2DRHSTR;
extern volatile SCI2DRHSTR _SCI2DRH @(REG_BASE + 0x000000BE);
#define SCI2DRH                         _SCI2DRH.Byte
#define SCI2DRH_T8                      _SCI2DRH.Bits.T8
#define SCI2DRH_R8                      _SCI2DRH.Bits.R8

#define SCI2DRH_T8_MASK                 64
#define SCI2DRH_R8_MASK                 128


 SCI2DRL - SCI 2 Data Register Low; 0x000000BF 
typedef union {
  byte Byte;
  struct {
    byte R0_T0       1;                                        Received bit 0 or Transmit bit 0 
    byte R1_T1       1;                                        Received bit 1 or Transmit bit 1 
    byte R2_T2       1;                                        Received bit 2 or Transmit bit 2 
    byte R3_T3       1;                                        Received bit 3 or Transmit bit 3 
    byte R4_T4       1;                                        Received bit 4 or Transmit bit 4 
    byte R5_T5       1;                                        Received bit 5 or Transmit bit 5 
    byte R6_T6       1;                                        Received bit 6 or Transmit bit 6 
    byte R7_T7       1;                                        Received bit 7 or Transmit bit 7 
  } Bits;
} SCI2DRLSTR;
extern volatile SCI2DRLSTR _SCI2DRL @(REG_BASE + 0x000000BF);
#define SCI2DRL                         _SCI2DRL.Byte
#define SCI2DRL_R0_T0                   _SCI2DRL.Bits.R0_T0
#define SCI2DRL_R1_T1                   _SCI2DRL.Bits.R1_T1
#define SCI2DRL_R2_T2                   _SCI2DRL.Bits.R2_T2
#define SCI2DRL_R3_T3                   _SCI2DRL.Bits.R3_T3
#define SCI2DRL_R4_T4                   _SCI2DRL.Bits.R4_T4
#define SCI2DRL_R5_T5                   _SCI2DRL.Bits.R5_T5
#define SCI2DRL_R6_T6                   _SCI2DRL.Bits.R6_T6
#define SCI2DRL_R7_T7                   _SCI2DRL.Bits.R7_T7

#define SCI2DRL_R0_T0_MASK              1
#define SCI2DRL_R1_T1_MASK              2
#define SCI2DRL_R2_T2_MASK              4
#define SCI2DRL_R3_T3_MASK              8
#define SCI2DRL_R4_T4_MASK              16
#define SCI2DRL_R5_T5_MASK              32
#define SCI2DRL_R6_T6_MASK              64
#define SCI2DRL_R7_T7_MASK              128


 SCI0BD - SCI 0 Baud Rate Register; 0x000000C8 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     SCI0ASR1 - SCI 0 Alternative Status Register 1; 0x000000C8 
    union {
      byte Byte;
      union { Several registers at the same address 
         SCI0ASR1 - SCI 0 Alternative Status Register 1; Several registers at the same address 
        union {
          struct {
            byte BKDIF       1;                                        Break Detect Interrupt Flag 
            byte BERRIF      1;                                        Bit Error Interrupt Flag 
            byte BERRV       1;                                        Bit Error Value 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte RXEDGIF     1;                                        Receive Input Active Edge Interrupt Flag 
          } Bits;
        } SCI0ASR1STR;
        #define SCI0ASR1                _SCI0BD.Overlap_STR.SCI0ASR1STR.Byte
        #define SCI0ASR1_BKDIF          _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BKDIF
        #define SCI0ASR1_BERRIF         _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BERRIF
        #define SCI0ASR1_BERRV          _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BERRV
        #define SCI0ASR1_RXEDGIF        _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.RXEDGIF
        
        
        #define SCI0ASR1_BKDIF_MASK     1
        #define SCI0ASR1_BERRIF_MASK    2
        #define SCI0ASR1_BERRV_MASK     4
        #define SCI0ASR1_RXEDGIF_MASK   128
    
         SCI0BDH - SCI 0 Baud Rate Register High; Several registers at the same address 
        union {
          struct {
            byte SBR8        1;                                        SCI Baud Rate Bit 8 
            byte SBR9        1;                                        SCI Baud Rate Bit 9 
            byte SBR10       1;                                        SCI Baud Rate Bit 10 
            byte SBR11       1;                                        SCI Baud Rate Bit 11 
            byte SBR12       1;                                        SCI Baud Rate Bit 12 
            byte TNP0        1;                                        Transmitter Narrow Pulse Bit 0 
            byte TNP1        1;                                        Transmitter Narrow Pulse Bit 1 
            byte IREN        1;                                        Infrared Enable Bit 
          } Bits;
          struct {
            byte grpSBR_8 5;
            byte grpTNP 2;
            byte 1;
          } MergedBits;
        } SCI0BDHSTR;
        #define SCI0BDH                 _SCI0BD.Overlap_STR.SCI0ASR1STR.Byte
        #define SCI0BDH_SBR8            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR8
        #define SCI0BDH_SBR9            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR9
        #define SCI0BDH_SBR10           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR10
        #define SCI0BDH_SBR11           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR11
        #define SCI0BDH_SBR12           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR12
        #define SCI0BDH_TNP0            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.TNP0
        #define SCI0BDH_TNP1            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.TNP1
        #define SCI0BDH_IREN            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.IREN
        
        #define SCI0BDH_SBR_8           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.MergedBits.grpSBR_8
        #define SCI0BDH_TNP             _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.MergedBits.grpTNP
        #define SCI0BDH_SBR             SCI0BDH_SBR_8
        
        #define SCI0BDH_SBR8_MASK       1
        #define SCI0BDH_SBR9_MASK       2
        #define SCI0BDH_SBR10_MASK      4
        #define SCI0BDH_SBR11_MASK      8
        #define SCI0BDH_SBR12_MASK      16
        #define SCI0BDH_TNP0_MASK       32
        #define SCI0BDH_TNP1_MASK       64
        #define SCI0BDH_IREN_MASK       128
        #define SCI0BDH_SBR_8_MASK      31
        #define SCI0BDH_SBR_8_BITNUM    0
        #define SCI0BDH_TNP_MASK        96
        #define SCI0BDH_TNP_BITNUM      5
    
      } SameAddr_STR; Several registers at the same address 
    
    } SCI0ASR1STR;
    


     SCI0ACR1 - SCI 0 Alternative Control Register 1; 0x000000C9 
    union {
      byte Byte;
      union { Several registers at the same address 
         SCI0ACR1 - SCI 0 Alternative Control Register 1; Several registers at the same address 
        union {
          struct {
            byte BKDIE       1;                                        Break Detect Interrupt Enable 
            byte BERRIE      1;                                        Bit Error Interrupt Enable 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte RXEDGIE     1;                                        Receive Input Active Edge Interrupt Enable 
          } Bits;
        } SCI0ACR1STR;
        #define SCI0ACR1                _SCI0BD.Overlap_STR.SCI0ACR1STR.Byte
        #define SCI0ACR1_BKDIE          _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.BKDIE
        #define SCI0ACR1_BERRIE         _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.BERRIE
        #define SCI0ACR1_RXEDGIE        _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.RXEDGIE
        
        
        #define SCI0ACR1_BKDIE_MASK     1
        #define SCI0ACR1_BERRIE_MASK    2
        #define SCI0ACR1_RXEDGIE_MASK   128
    
         SCI0BDL - SCI 0 Baud Rate Register Low; Several registers at the same address 
        union {
          struct {
            byte SBR0        1;                                        SCI Baud Rate Bit 0 
            byte SBR1        1;                                        SCI Baud Rate Bit 1 
            byte SBR2        1;                                        SCI Baud Rate Bit 2 
            byte SBR3        1;                                        SCI Baud Rate Bit 3 
            byte SBR4        1;                                        SCI Baud Rate Bit 4 
            byte SBR5        1;                                        SCI Baud Rate Bit 5 
            byte SBR6        1;                                        SCI Baud Rate Bit 6 
            byte SBR7        1;                                        SCI Baud Rate Bit 7 
          } Bits;
        } SCI0BDLSTR;
        #define SCI0BDL                 _SCI0BD.Overlap_STR.SCI0ACR1STR.Byte
        #define SCI0BDL_SBR0            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR0
        #define SCI0BDL_SBR1            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR1
        #define SCI0BDL_SBR2            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR2
        #define SCI0BDL_SBR3            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR3
        #define SCI0BDL_SBR4            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR4
        #define SCI0BDL_SBR5            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR5
        #define SCI0BDL_SBR6            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR6
        #define SCI0BDL_SBR7            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR7
        
        
        #define SCI0BDL_SBR0_MASK       1
        #define SCI0BDL_SBR1_MASK       2
        #define SCI0BDL_SBR2_MASK       4
        #define SCI0BDL_SBR3_MASK       8
        #define SCI0BDL_SBR4_MASK       16
        #define SCI0BDL_SBR5_MASK       32
        #define SCI0BDL_SBR6_MASK       64
        #define SCI0BDL_SBR7_MASK       128
    
      } SameAddr_STR; Several registers at the same address 
    
    } SCI0ACR1STR;
    

  } Overlap_STR;

  struct {
    word SBR0        1;                                        SCI Baud Rate Bit 0 
    word SBR1        1;                                        SCI Baud Rate Bit 1 
    word SBR2        1;                                        SCI Baud Rate Bit 2 
    word SBR3        1;                                        SCI Baud Rate Bit 3 
    word SBR4        1;                                        SCI Baud Rate Bit 4 
    word SBR5        1;                                        SCI Baud Rate Bit 5 
    word SBR6        1;                                        SCI Baud Rate Bit 6 
    word SBR7        1;                                        SCI Baud Rate Bit 7 
    word SBR8        1;                                        SCI Baud Rate Bit 8 
    word SBR9        1;                                        SCI Baud Rate Bit 9 
    word SBR10       1;                                        SCI Baud Rate Bit 10 
    word SBR11       1;                                        SCI Baud Rate Bit 11 
    word SBR12       1;                                        SCI Baud Rate Bit 12 
    word TNP0        1;                                        Transmitter Narrow Pulse Bit 0 
    word TNP1        1;                                        Transmitter Narrow Pulse Bit 1 
    word IREN        1;                                        Infrared Enable Bit 
  } Bits;
  struct {
    word grpSBR  13;
    word grpTNP  2;
    word         1;
  } MergedBits;
} SCI0BDSTR;
extern volatile SCI0BDSTR _SCI0BD @(REG_BASE + 0x000000C8);
#define SCI0BD                          _SCI0BD.Word
#define SCI0BD_SBR0                     _SCI0BD.Bits.SBR0
#define SCI0BD_SBR1                     _SCI0BD.Bits.SBR1
#define SCI0BD_SBR2                     _SCI0BD.Bits.SBR2
#define SCI0BD_SBR3                     _SCI0BD.Bits.SBR3
#define SCI0BD_SBR4                     _SCI0BD.Bits.SBR4
#define SCI0BD_SBR5                     _SCI0BD.Bits.SBR5
#define SCI0BD_SBR6                     _SCI0BD.Bits.SBR6
#define SCI0BD_SBR7                     _SCI0BD.Bits.SBR7
#define SCI0BD_SBR8                     _SCI0BD.Bits.SBR8
#define SCI0BD_SBR9                     _SCI0BD.Bits.SBR9
#define SCI0BD_SBR10                    _SCI0BD.Bits.SBR10
#define SCI0BD_SBR11                    _SCI0BD.Bits.SBR11
#define SCI0BD_SBR12                    _SCI0BD.Bits.SBR12
#define SCI0BD_TNP0                     _SCI0BD.Bits.TNP0
#define SCI0BD_TNP1                     _SCI0BD.Bits.TNP1
#define SCI0BD_IREN                     _SCI0BD.Bits.IREN
#define SCI0BD_SBR                      _SCI0BD.MergedBits.grpSBR
#define SCI0BD_TNP                      _SCI0BD.MergedBits.grpTNP

#define SCI0BD_SBR0_MASK                1
#define SCI0BD_SBR1_MASK                2
#define SCI0BD_SBR2_MASK                4
#define SCI0BD_SBR3_MASK                8
#define SCI0BD_SBR4_MASK                16
#define SCI0BD_SBR5_MASK                32
#define SCI0BD_SBR6_MASK                64
#define SCI0BD_SBR7_MASK                128
#define SCI0BD_SBR8_MASK                256
#define SCI0BD_SBR9_MASK                512
#define SCI0BD_SBR10_MASK               1024
#define SCI0BD_SBR11_MASK               2048
#define SCI0BD_SBR12_MASK               4096
#define SCI0BD_TNP0_MASK                8192
#define SCI0BD_TNP1_MASK                16384
#define SCI0BD_IREN_MASK                32768
#define SCI0BD_SBR_MASK                 8191
#define SCI0BD_SBR_BITNUM               0
#define SCI0BD_TNP_MASK                 24576
#define SCI0BD_TNP_BITNUM               13


 SCI0ACR2 - SCI 0 Alternative Control Register 2; 0x000000CA 
typedef union {
  byte Byte;
  union { Several registers at the same address 
     SCI0ACR2 - SCI 0 Alternative Control Register 2; Several registers at the same address 
    union {
      struct {
        byte BKDFE       1;                                        Break Detect Feature Enable 
        byte BERRM0      1;                                        Bit Error Mode Bit 0 
        byte BERRM1      1;                                        Bit Error Mode Bit 1 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
      } Bits;
      struct {
        byte     1;
        byte grpBERRM 2;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } SCI0ACR2STR;
    #define SCI0ACR2                    _SCI0ACR2.Byte
    #define SCI0ACR2_BKDFE              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BKDFE
    #define SCI0ACR2_BERRM0             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM0
    #define SCI0ACR2_BERRM1             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM1
    
    #define SCI0ACR2_BERRM              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.MergedBits.grpBERRM
    
    #define SCI0ACR2_BKDFE_MASK         1
    #define SCI0ACR2_BERRM0_MASK        2
    #define SCI0ACR2_BERRM1_MASK        4
    #define SCI0ACR2_BERRM_MASK         6
    #define SCI0ACR2_BERRM_BITNUM       1

     SCI0CR1 - SCI 0 Control Register 1; Several registers at the same address 
    union {
      struct {
        byte PT          1;                                        Parity Type Bit 
        byte PE          1;                                        Parity Enable Bit 
        byte ILT         1;                                        Idle Line Type Bit 
        byte WAKE        1;                                        Wakeup Condition Bit 
        byte M           1;                                        Data Format Mode Bit 
        byte RSRC        1;                                        Receiver Source Bit 
        byte SCISWAI     1;                                        SCI Stop in Wait Mode Bit 
        byte LOOPS       1;                                        Loop Select Bit 
      } Bits;
    } SCI0CR1STR;
    #define SCI0CR1                     _SCI0ACR2.Byte
    #define SCI0CR1_PT                  _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.PT
    #define SCI0CR1_PE                  _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.PE
    #define SCI0CR1_ILT                 _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.ILT
    #define SCI0CR1_WAKE                _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.WAKE
    #define SCI0CR1_M                   _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.M
    #define SCI0CR1_RSRC                _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.RSRC
    #define SCI0CR1_SCISWAI             _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.SCISWAI
    #define SCI0CR1_LOOPS               _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.LOOPS
    
    
    #define SCI0CR1_PT_MASK             1
    #define SCI0CR1_PE_MASK             2
    #define SCI0CR1_ILT_MASK            4
    #define SCI0CR1_WAKE_MASK           8
    #define SCI0CR1_M_MASK              16
    #define SCI0CR1_RSRC_MASK           32
    #define SCI0CR1_SCISWAI_MASK        64
    #define SCI0CR1_LOOPS_MASK          128

  } SameAddr_STR; Several registers at the same address 

} SCI0ACR2STR;
extern volatile SCI0ACR2STR _SCI0ACR2 @(REG_BASE + 0x000000CA);



 SCI0CR2 - SCI 0 Control Register 2; 0x000000CB 
typedef union {
  byte Byte;
  struct {
    byte SBK         1;                                        Send Break Bit 
    byte RWU         1;                                        Receiver Wakeup Bit 
    byte RE          1;                                        Receiver Enable Bit 
    byte TE          1;                                        Transmitter Enable Bit 
    byte ILIE        1;                                        Idle Line Interrupt Enable Bit 
    byte RIE         1;                                        Receiver Full Interrupt Enable Bit 
    byte TCIE        1;                                        Transmission Complete Interrupt Enable Bit 
    byte SCTIE       1;                                        Transmitter Interrupt Enable Bit 
  } Bits;
} SCI0CR2STR;
extern volatile SCI0CR2STR _SCI0CR2 @(REG_BASE + 0x000000CB);
#define SCI0CR2                         _SCI0CR2.Byte
#define SCI0CR2_SBK                     _SCI0CR2.Bits.SBK
#define SCI0CR2_RWU                     _SCI0CR2.Bits.RWU
#define SCI0CR2_RE                      _SCI0CR2.Bits.RE
#define SCI0CR2_TE                      _SCI0CR2.Bits.TE
#define SCI0CR2_ILIE                    _SCI0CR2.Bits.ILIE
#define SCI0CR2_RIE                     _SCI0CR2.Bits.RIE
#define SCI0CR2_TCIE                    _SCI0CR2.Bits.TCIE
#define SCI0CR2_SCTIE                   _SCI0CR2.Bits.SCTIE

#define SCI0CR2_SBK_MASK                1
#define SCI0CR2_RWU_MASK                2
#define SCI0CR2_RE_MASK                 4
#define SCI0CR2_TE_MASK                 8
#define SCI0CR2_ILIE_MASK               16
#define SCI0CR2_RIE_MASK                32
#define SCI0CR2_TCIE_MASK               64
#define SCI0CR2_SCTIE_MASK              128


 SCI0SR1 - SCI 0 Status Register 1; 0x000000CC 
typedef union {
  byte Byte;
  struct {
    byte PF          1;                                        Parity Error Flag 
    byte FE          1;                                        Framing Error Flag 
    byte NF          1;                                        Noise Flag 
    byte OR          1;                                        Overrun Flag 
    byte IDLE        1;                                        Idle Line Flag 
    byte RDRF        1;                                        Receive Data Register Full Flag 
    byte TC          1;                                        Transmit Complete Flag 
    byte TDRE        1;                                        Transmit Data Register Empty Flag 
  } Bits;
} SCI0SR1STR;
extern volatile SCI0SR1STR _SCI0SR1 @(REG_BASE + 0x000000CC);
#define SCI0SR1                         _SCI0SR1.Byte
#define SCI0SR1_PF                      _SCI0SR1.Bits.PF
#define SCI0SR1_FE                      _SCI0SR1.Bits.FE
#define SCI0SR1_NF                      _SCI0SR1.Bits.NF
#define SCI0SR1_OR                      _SCI0SR1.Bits.OR
#define SCI0SR1_IDLE                    _SCI0SR1.Bits.IDLE
#define SCI0SR1_RDRF                    _SCI0SR1.Bits.RDRF
#define SCI0SR1_TC                      _SCI0SR1.Bits.TC
#define SCI0SR1_TDRE                    _SCI0SR1.Bits.TDRE

#define SCI0SR1_PF_MASK                 1
#define SCI0SR1_FE_MASK                 2
#define SCI0SR1_NF_MASK                 4
#define SCI0SR1_OR_MASK                 8
#define SCI0SR1_IDLE_MASK               16
#define SCI0SR1_RDRF_MASK               32
#define SCI0SR1_TC_MASK                 64
#define SCI0SR1_TDRE_MASK               128


 SCI0SR2 - SCI 0 Status Register 2; 0x000000CD 
typedef union {
  byte Byte;
  struct {
    byte RAF         1;                                        Receiver Active Flag 
    byte TXDIR       1;                                        Transmitter pin data direction in Single-Wire mode 
    byte BRK13       1;                                        Break Transmit character length 
    byte RXPOL       1;                                        Receive Polarity 
    byte TXPOL       1;                                        Transmit Polarity 
    byte             1; 
    byte             1; 
    byte AMAP        1;                                        Alternative Map 
  } Bits;
} SCI0SR2STR;
extern volatile SCI0SR2STR _SCI0SR2 @(REG_BASE + 0x000000CD);
#define SCI0SR2                         _SCI0SR2.Byte
#define SCI0SR2_RAF                     _SCI0SR2.Bits.RAF
#define SCI0SR2_TXDIR                   _SCI0SR2.Bits.TXDIR
#define SCI0SR2_BRK13                   _SCI0SR2.Bits.BRK13
#define SCI0SR2_RXPOL                   _SCI0SR2.Bits.RXPOL
#define SCI0SR2_TXPOL                   _SCI0SR2.Bits.TXPOL
#define SCI0SR2_AMAP                    _SCI0SR2.Bits.AMAP

#define SCI0SR2_RAF_MASK                1
#define SCI0SR2_TXDIR_MASK              2
#define SCI0SR2_BRK13_MASK              4
#define SCI0SR2_RXPOL_MASK              8
#define SCI0SR2_TXPOL_MASK              16
#define SCI0SR2_AMAP_MASK               128


 SCI0DRH - SCI 0 Data Register High; 0x000000CE 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte T8          1;                                        Transmit Bit 8 
    byte R8          1;                                        Received Bit 8 
  } Bits;
} SCI0DRHSTR;
extern volatile SCI0DRHSTR _SCI0DRH @(REG_BASE + 0x000000CE);
#define SCI0DRH                         _SCI0DRH.Byte
#define SCI0DRH_T8                      _SCI0DRH.Bits.T8
#define SCI0DRH_R8                      _SCI0DRH.Bits.R8

#define SCI0DRH_T8_MASK                 64
#define SCI0DRH_R8_MASK                 128


 SCI0DRL - SCI 0 Data Register Low; 0x000000CF 
typedef union {
  byte Byte;
  struct {
    byte R0_T0       1;                                        Received bit 0 or Transmit bit 0 
    byte R1_T1       1;                                        Received bit 1 or Transmit bit 1 
    byte R2_T2       1;                                        Received bit 2 or Transmit bit 2 
    byte R3_T3       1;                                        Received bit 3 or Transmit bit 3 
    byte R4_T4       1;                                        Received bit 4 or Transmit bit 4 
    byte R5_T5       1;                                        Received bit 5 or Transmit bit 5 
    byte R6_T6       1;                                        Received bit 6 or Transmit bit 6 
    byte R7_T7       1;                                        Received bit 7 or Transmit bit 7 
  } Bits;
} SCI0DRLSTR;
extern volatile SCI0DRLSTR _SCI0DRL @(REG_BASE + 0x000000CF);
#define SCI0DRL                         _SCI0DRL.Byte
#define SCI0DRL_R0_T0                   _SCI0DRL.Bits.R0_T0
#define SCI0DRL_R1_T1                   _SCI0DRL.Bits.R1_T1
#define SCI0DRL_R2_T2                   _SCI0DRL.Bits.R2_T2
#define SCI0DRL_R3_T3                   _SCI0DRL.Bits.R3_T3
#define SCI0DRL_R4_T4                   _SCI0DRL.Bits.R4_T4
#define SCI0DRL_R5_T5                   _SCI0DRL.Bits.R5_T5
#define SCI0DRL_R6_T6                   _SCI0DRL.Bits.R6_T6
#define SCI0DRL_R7_T7                   _SCI0DRL.Bits.R7_T7

#define SCI0DRL_R0_T0_MASK              1
#define SCI0DRL_R1_T1_MASK              2
#define SCI0DRL_R2_T2_MASK              4
#define SCI0DRL_R3_T3_MASK              8
#define SCI0DRL_R4_T4_MASK              16
#define SCI0DRL_R5_T5_MASK              32
#define SCI0DRL_R6_T6_MASK              64
#define SCI0DRL_R7_T7_MASK              128


 SCI1BD - SCI 1 Baud Rate Register; 0x000000D0 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     SCI1ASR1 - SCI 1 Alternative Status Register 1; 0x000000D0 
    union {
      byte Byte;
      union { Several registers at the same address 
         SCI1ASR1 - SCI 1 Alternative Status Register 1; Several registers at the same address 
        union {
          struct {
            byte BKDIF       1;                                        Break Detect Interrupt Flag 
            byte BERRIF      1;                                        Bit Error Interrupt Flag 
            byte BERRV       1;                                        Bit Error Value 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte RXEDGIF     1;                                        Receive Input Active Edge Interrupt Flag 
          } Bits;
        } SCI1ASR1STR;
        #define SCI1ASR1                _SCI1BD.Overlap_STR.SCI1ASR1STR.Byte
        #define SCI1ASR1_BKDIF          _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BKDIF
        #define SCI1ASR1_BERRIF         _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BERRIF
        #define SCI1ASR1_BERRV          _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BERRV
        #define SCI1ASR1_RXEDGIF        _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.RXEDGIF
        
        
        #define SCI1ASR1_BKDIF_MASK     1
        #define SCI1ASR1_BERRIF_MASK    2
        #define SCI1ASR1_BERRV_MASK     4
        #define SCI1ASR1_RXEDGIF_MASK   128
    
         SCI1BDH - SCI 1 Baud Rate Register High; Several registers at the same address 
        union {
          struct {
            byte SBR8        1;                                        SCI Baud Rate Bit 8 
            byte SBR9        1;                                        SCI Baud Rate Bit 9 
            byte SBR10       1;                                        SCI Baud Rate Bit 10 
            byte SBR11       1;                                        SCI Baud Rate Bit 11 
            byte SBR12       1;                                        SCI Baud Rate Bit 12 
            byte TNP0        1;                                        Transmitter Narrow Pulse Bit 0 
            byte TNP1        1;                                        Transmitter Narrow Pulse Bit 1 
            byte IREN        1;                                        Infrared Enable Bit 
          } Bits;
          struct {
            byte grpSBR_8 5;
            byte grpTNP 2;
            byte 1;
          } MergedBits;
        } SCI1BDHSTR;
        #define SCI1BDH                 _SCI1BD.Overlap_STR.SCI1ASR1STR.Byte
        #define SCI1BDH_SBR8            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR8
        #define SCI1BDH_SBR9            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR9
        #define SCI1BDH_SBR10           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR10
        #define SCI1BDH_SBR11           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR11
        #define SCI1BDH_SBR12           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR12
        #define SCI1BDH_TNP0            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.TNP0
        #define SCI1BDH_TNP1            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.TNP1
        #define SCI1BDH_IREN            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.IREN
        
        #define SCI1BDH_SBR_8           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.MergedBits.grpSBR_8
        #define SCI1BDH_TNP             _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.MergedBits.grpTNP
        #define SCI1BDH_SBR             SCI1BDH_SBR_8
        
        #define SCI1BDH_SBR8_MASK       1
        #define SCI1BDH_SBR9_MASK       2
        #define SCI1BDH_SBR10_MASK      4
        #define SCI1BDH_SBR11_MASK      8
        #define SCI1BDH_SBR12_MASK      16
        #define SCI1BDH_TNP0_MASK       32
        #define SCI1BDH_TNP1_MASK       64
        #define SCI1BDH_IREN_MASK       128
        #define SCI1BDH_SBR_8_MASK      31
        #define SCI1BDH_SBR_8_BITNUM    0
        #define SCI1BDH_TNP_MASK        96
        #define SCI1BDH_TNP_BITNUM      5
    
      } SameAddr_STR; Several registers at the same address 
    
    } SCI1ASR1STR;
    


     SCI1ACR1 - SCI 1 Alternative Control Register 1; 0x000000D1 
    union {
      byte Byte;
      union { Several registers at the same address 
         SCI1ACR1 - SCI 1 Alternative Control Register 1; Several registers at the same address 
        union {
          struct {
            byte BKDIE       1;                                        Break Detect Interrupt Enable 
            byte BERRIE      1;                                        Bit Error Interrupt Enable 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte RXEDGIE     1;                                        Receive Input Active Edge Interrupt Enable 
          } Bits;
        } SCI1ACR1STR;
        #define SCI1ACR1                _SCI1BD.Overlap_STR.SCI1ACR1STR.Byte
        #define SCI1ACR1_BKDIE          _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.BKDIE
        #define SCI1ACR1_BERRIE         _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.BERRIE
        #define SCI1ACR1_RXEDGIE        _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.RXEDGIE
        
        
        #define SCI1ACR1_BKDIE_MASK     1
        #define SCI1ACR1_BERRIE_MASK    2
        #define SCI1ACR1_RXEDGIE_MASK   128
    
         SCI1BDL - SCI 1 Baud Rate Register Low; Several registers at the same address 
        union {
          struct {
            byte SBR0        1;                                        SCI Baud Rate Bit 0 
            byte SBR1        1;                                        SCI Baud Rate Bit 1 
            byte SBR2        1;                                        SCI Baud Rate Bit 2 
            byte SBR3        1;                                        SCI Baud Rate Bit 3 
            byte SBR4        1;                                        SCI Baud Rate Bit 4 
            byte SBR5        1;                                        SCI Baud Rate Bit 5 
            byte SBR6        1;                                        SCI Baud Rate Bit 6 
            byte SBR7        1;                                        SCI Baud Rate Bit 7 
          } Bits;
        } SCI1BDLSTR;
        #define SCI1BDL                 _SCI1BD.Overlap_STR.SCI1ACR1STR.Byte
        #define SCI1BDL_SBR0            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR0
        #define SCI1BDL_SBR1            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR1
        #define SCI1BDL_SBR2            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR2
        #define SCI1BDL_SBR3            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR3
        #define SCI1BDL_SBR4            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR4
        #define SCI1BDL_SBR5            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR5
        #define SCI1BDL_SBR6            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR6
        #define SCI1BDL_SBR7            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR7
        
        
        #define SCI1BDL_SBR0_MASK       1
        #define SCI1BDL_SBR1_MASK       2
        #define SCI1BDL_SBR2_MASK       4
        #define SCI1BDL_SBR3_MASK       8
        #define SCI1BDL_SBR4_MASK       16
        #define SCI1BDL_SBR5_MASK       32
        #define SCI1BDL_SBR6_MASK       64
        #define SCI1BDL_SBR7_MASK       128
    
      } SameAddr_STR; Several registers at the same address 
    
    } SCI1ACR1STR;
    

  } Overlap_STR;

  struct {
    word SBR0        1;                                        SCI Baud Rate Bit 0 
    word SBR1        1;                                        SCI Baud Rate Bit 1 
    word SBR2        1;                                        SCI Baud Rate Bit 2 
    word SBR3        1;                                        SCI Baud Rate Bit 3 
    word SBR4        1;                                        SCI Baud Rate Bit 4 
    word SBR5        1;                                        SCI Baud Rate Bit 5 
    word SBR6        1;                                        SCI Baud Rate Bit 6 
    word SBR7        1;                                        SCI Baud Rate Bit 7 
    word SBR8        1;                                        SCI Baud Rate Bit 8 
    word SBR9        1;                                        SCI Baud Rate Bit 9 
    word SBR10       1;                                        SCI Baud Rate Bit 10 
    word SBR11       1;                                        SCI Baud Rate Bit 11 
    word SBR12       1;                                        SCI Baud Rate Bit 12 
    word TNP0        1;                                        Transmitter Narrow Pulse Bit 0 
    word TNP1        1;                                        Transmitter Narrow Pulse Bit 1 
    word IREN        1;                                        Infrared Enable Bit 
  } Bits;
  struct {
    word grpSBR  13;
    word grpTNP  2;
    word         1;
  } MergedBits;
} SCI1BDSTR;
extern volatile SCI1BDSTR _SCI1BD @(REG_BASE + 0x000000D0);
#define SCI1BD                          _SCI1BD.Word
#define SCI1BD_SBR0                     _SCI1BD.Bits.SBR0
#define SCI1BD_SBR1                     _SCI1BD.Bits.SBR1
#define SCI1BD_SBR2                     _SCI1BD.Bits.SBR2
#define SCI1BD_SBR3                     _SCI1BD.Bits.SBR3
#define SCI1BD_SBR4                     _SCI1BD.Bits.SBR4
#define SCI1BD_SBR5                     _SCI1BD.Bits.SBR5
#define SCI1BD_SBR6                     _SCI1BD.Bits.SBR6
#define SCI1BD_SBR7                     _SCI1BD.Bits.SBR7
#define SCI1BD_SBR8                     _SCI1BD.Bits.SBR8
#define SCI1BD_SBR9                     _SCI1BD.Bits.SBR9
#define SCI1BD_SBR10                    _SCI1BD.Bits.SBR10
#define SCI1BD_SBR11                    _SCI1BD.Bits.SBR11
#define SCI1BD_SBR12                    _SCI1BD.Bits.SBR12
#define SCI1BD_TNP0                     _SCI1BD.Bits.TNP0
#define SCI1BD_TNP1                     _SCI1BD.Bits.TNP1
#define SCI1BD_IREN                     _SCI1BD.Bits.IREN
#define SCI1BD_SBR                      _SCI1BD.MergedBits.grpSBR
#define SCI1BD_TNP                      _SCI1BD.MergedBits.grpTNP

#define SCI1BD_SBR0_MASK                1
#define SCI1BD_SBR1_MASK                2
#define SCI1BD_SBR2_MASK                4
#define SCI1BD_SBR3_MASK                8
#define SCI1BD_SBR4_MASK                16
#define SCI1BD_SBR5_MASK                32
#define SCI1BD_SBR6_MASK                64
#define SCI1BD_SBR7_MASK                128
#define SCI1BD_SBR8_MASK                256
#define SCI1BD_SBR9_MASK                512
#define SCI1BD_SBR10_MASK               1024
#define SCI1BD_SBR11_MASK               2048
#define SCI1BD_SBR12_MASK               4096
#define SCI1BD_TNP0_MASK                8192
#define SCI1BD_TNP1_MASK                16384
#define SCI1BD_IREN_MASK                32768
#define SCI1BD_SBR_MASK                 8191
#define SCI1BD_SBR_BITNUM               0
#define SCI1BD_TNP_MASK                 24576
#define SCI1BD_TNP_BITNUM               13


 SCI1ACR2 - SCI 1 Alternative Control Register 2; 0x000000D2 
typedef union {
  byte Byte;
  union { Several registers at the same address 
     SCI1ACR2 - SCI 1 Alternative Control Register 2; Several registers at the same address 
    union {
      struct {
        byte BKDFE       1;                                        Break Detect Feature Enable 
        byte BERRM0      1;                                        Bit Error Mode Bit 0 
        byte BERRM1      1;                                        Bit Error Mode Bit 1 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
      } Bits;
      struct {
        byte     1;
        byte grpBERRM 2;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } SCI1ACR2STR;
    #define SCI1ACR2                    _SCI1ACR2.Byte
    #define SCI1ACR2_BKDFE              _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BKDFE
    #define SCI1ACR2_BERRM0             _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BERRM0
    #define SCI1ACR2_BERRM1             _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BERRM1
    
    #define SCI1ACR2_BERRM              _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.MergedBits.grpBERRM
    
    #define SCI1ACR2_BKDFE_MASK         1
    #define SCI1ACR2_BERRM0_MASK        2
    #define SCI1ACR2_BERRM1_MASK        4
    #define SCI1ACR2_BERRM_MASK         6
    #define SCI1ACR2_BERRM_BITNUM       1

     SCI1CR1 - SCI 1 Control Register 1; Several registers at the same address 
    union {
      struct {
        byte PT          1;                                        Parity Type Bit 
        byte PE          1;                                        Parity Enable Bit 
        byte ILT         1;                                        Idle Line Type Bit 
        byte WAKE        1;                                        Wakeup Condition Bit 
        byte M           1;                                        Data Format Mode Bit 
        byte RSRC        1;                                        Receiver Source Bit 
        byte SCISWAI     1;                                        SCI Stop in Wait Mode Bit 
        byte LOOPS       1;                                        Loop Select Bit 
      } Bits;
    } SCI1CR1STR;
    #define SCI1CR1                     _SCI1ACR2.Byte
    #define SCI1CR1_PT                  _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.PT
    #define SCI1CR1_PE                  _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.PE
    #define SCI1CR1_ILT                 _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.ILT
    #define SCI1CR1_WAKE                _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.WAKE
    #define SCI1CR1_M                   _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.M
    #define SCI1CR1_RSRC                _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.RSRC
    #define SCI1CR1_SCISWAI             _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.SCISWAI
    #define SCI1CR1_LOOPS               _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.LOOPS
    
    
    #define SCI1CR1_PT_MASK             1
    #define SCI1CR1_PE_MASK             2
    #define SCI1CR1_ILT_MASK            4
    #define SCI1CR1_WAKE_MASK           8
    #define SCI1CR1_M_MASK              16
    #define SCI1CR1_RSRC_MASK           32
    #define SCI1CR1_SCISWAI_MASK        64
    #define SCI1CR1_LOOPS_MASK          128

  } SameAddr_STR; Several registers at the same address 

} SCI1ACR2STR;
extern volatile SCI1ACR2STR _SCI1ACR2 @(REG_BASE + 0x000000D2);



 SCI1CR2 - SCI 1 Control Register 2; 0x000000D3 
typedef union {
  byte Byte;
  struct {
    byte SBK         1;                                        Send Break Bit 
    byte RWU         1;                                        Receiver Wakeup Bit 
    byte RE          1;                                        Receiver Enable Bit 
    byte TE          1;                                        Transmitter Enable Bit 
    byte ILIE        1;                                        Idle Line Interrupt Enable Bit 
    byte RIE         1;                                        Receiver Full Interrupt Enable Bit 
    byte TCIE        1;                                        Transmission Complete Interrupt Enable Bit 
    byte SCTIE       1;                                        Transmitter Interrupt Enable Bit 
  } Bits;
} SCI1CR2STR;
extern volatile SCI1CR2STR _SCI1CR2 @(REG_BASE + 0x000000D3);
#define SCI1CR2                         _SCI1CR2.Byte
#define SCI1CR2_SBK                     _SCI1CR2.Bits.SBK
#define SCI1CR2_RWU                     _SCI1CR2.Bits.RWU
#define SCI1CR2_RE                      _SCI1CR2.Bits.RE
#define SCI1CR2_TE                      _SCI1CR2.Bits.TE
#define SCI1CR2_ILIE                    _SCI1CR2.Bits.ILIE
#define SCI1CR2_RIE                     _SCI1CR2.Bits.RIE
#define SCI1CR2_TCIE                    _SCI1CR2.Bits.TCIE
#define SCI1CR2_SCTIE                   _SCI1CR2.Bits.SCTIE

#define SCI1CR2_SBK_MASK                1
#define SCI1CR2_RWU_MASK                2
#define SCI1CR2_RE_MASK                 4
#define SCI1CR2_TE_MASK                 8
#define SCI1CR2_ILIE_MASK               16
#define SCI1CR2_RIE_MASK                32
#define SCI1CR2_TCIE_MASK               64
#define SCI1CR2_SCTIE_MASK              128


 SCI1SR1 - SCI 1 Status Register 1; 0x000000D4 
typedef union {
  byte Byte;
  struct {
    byte PF          1;                                        Parity Error Flag 
    byte FE          1;                                        Framing Error Flag 
    byte NF          1;                                        Noise Flag 
    byte OR          1;                                        Overrun Flag 
    byte IDLE        1;                                        Idle Line Flag 
    byte RDRF        1;                                        Receive Data Register Full Flag 
    byte TC          1;                                        Transmit Complete Flag 
    byte TDRE        1;                                        Transmit Data Register Empty Flag 
  } Bits;
} SCI1SR1STR;
extern volatile SCI1SR1STR _SCI1SR1 @(REG_BASE + 0x000000D4);
#define SCI1SR1                         _SCI1SR1.Byte
#define SCI1SR1_PF                      _SCI1SR1.Bits.PF
#define SCI1SR1_FE                      _SCI1SR1.Bits.FE
#define SCI1SR1_NF                      _SCI1SR1.Bits.NF
#define SCI1SR1_OR                      _SCI1SR1.Bits.OR
#define SCI1SR1_IDLE                    _SCI1SR1.Bits.IDLE
#define SCI1SR1_RDRF                    _SCI1SR1.Bits.RDRF
#define SCI1SR1_TC                      _SCI1SR1.Bits.TC
#define SCI1SR1_TDRE                    _SCI1SR1.Bits.TDRE

#define SCI1SR1_PF_MASK                 1
#define SCI1SR1_FE_MASK                 2
#define SCI1SR1_NF_MASK                 4
#define SCI1SR1_OR_MASK                 8
#define SCI1SR1_IDLE_MASK               16
#define SCI1SR1_RDRF_MASK               32
#define SCI1SR1_TC_MASK                 64
#define SCI1SR1_TDRE_MASK               128


 SCI1SR2 - SCI 1 Status Register 2; 0x000000D5 
typedef union {
  byte Byte;
  struct {
    byte RAF         1;                                        Receiver Active Flag 
    byte TXDIR       1;                                        Transmitter pin data direction in Single-Wire mode 
    byte BRK13       1;                                        Break Transmit character length 
    byte RXPOL       1;                                        Receive Polarity 
    byte TXPOL       1;                                        Transmit Polarity 
    byte             1; 
    byte             1; 
    byte AMAP        1;                                        Alternative Map 
  } Bits;
} SCI1SR2STR;
extern volatile SCI1SR2STR _SCI1SR2 @(REG_BASE + 0x000000D5);
#define SCI1SR2                         _SCI1SR2.Byte
#define SCI1SR2_RAF                     _SCI1SR2.Bits.RAF
#define SCI1SR2_TXDIR                   _SCI1SR2.Bits.TXDIR
#define SCI1SR2_BRK13                   _SCI1SR2.Bits.BRK13
#define SCI1SR2_RXPOL                   _SCI1SR2.Bits.RXPOL
#define SCI1SR2_TXPOL                   _SCI1SR2.Bits.TXPOL
#define SCI1SR2_AMAP                    _SCI1SR2.Bits.AMAP

#define SCI1SR2_RAF_MASK                1
#define SCI1SR2_TXDIR_MASK              2
#define SCI1SR2_BRK13_MASK              4
#define SCI1SR2_RXPOL_MASK              8
#define SCI1SR2_TXPOL_MASK              16
#define SCI1SR2_AMAP_MASK               128


 SCI1DRH - SCI 1 Data Register High; 0x000000D6 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte T8          1;                                        Transmit Bit 8 
    byte R8          1;                                        Received Bit 8 
  } Bits;
} SCI1DRHSTR;
extern volatile SCI1DRHSTR _SCI1DRH @(REG_BASE + 0x000000D6);
#define SCI1DRH                         _SCI1DRH.Byte
#define SCI1DRH_T8                      _SCI1DRH.Bits.T8
#define SCI1DRH_R8                      _SCI1DRH.Bits.R8

#define SCI1DRH_T8_MASK                 64
#define SCI1DRH_R8_MASK                 128


 SCI1DRL - SCI 1 Data Register Low; 0x000000D7 
typedef union {
  byte Byte;
  struct {
    byte R0_T0       1;                                        Received bit 0 or Transmit bit 0 
    byte R1_T1       1;                                        Received bit 1 or Transmit bit 1 
    byte R2_T2       1;                                        Received bit 2 or Transmit bit 2 
    byte R3_T3       1;                                        Received bit 3 or Transmit bit 3 
    byte R4_T4       1;                                        Received bit 4 or Transmit bit 4 
    byte R5_T5       1;                                        Received bit 5 or Transmit bit 5 
    byte R6_T6       1;                                        Received bit 6 or Transmit bit 6 
    byte R7_T7       1;                                        Received bit 7 or Transmit bit 7 
  } Bits;
} SCI1DRLSTR;
extern volatile SCI1DRLSTR _SCI1DRL @(REG_BASE + 0x000000D7);
#define SCI1DRL                         _SCI1DRL.Byte
#define SCI1DRL_R0_T0                   _SCI1DRL.Bits.R0_T0
#define SCI1DRL_R1_T1                   _SCI1DRL.Bits.R1_T1
#define SCI1DRL_R2_T2                   _SCI1DRL.Bits.R2_T2
#define SCI1DRL_R3_T3                   _SCI1DRL.Bits.R3_T3
#define SCI1DRL_R4_T4                   _SCI1DRL.Bits.R4_T4
#define SCI1DRL_R5_T5                   _SCI1DRL.Bits.R5_T5
#define SCI1DRL_R6_T6                   _SCI1DRL.Bits.R6_T6
#define SCI1DRL_R7_T7                   _SCI1DRL.Bits.R7_T7

#define SCI1DRL_R0_T0_MASK              1
#define SCI1DRL_R1_T1_MASK              2
#define SCI1DRL_R2_T2_MASK              4
#define SCI1DRL_R3_T3_MASK              8
#define SCI1DRL_R4_T4_MASK              16
#define SCI1DRL_R5_T5_MASK              32
#define SCI1DRL_R6_T6_MASK              64
#define SCI1DRL_R7_T7_MASK              128


 SPI0CR1 - SPI 0 Control Register; 0x000000D8 
typedef union {
  byte Byte;
  struct {
    byte LSBFE       1;                                        SPI LSB-First Enable 
    byte SSOE        1;                                        Slave Select Output Enable 
    byte CPHA        1;                                        SPI Clock Phase Bit 
    byte CPOL        1;                                        SPI Clock Polarity Bit 
    byte MSTR        1;                                        SPI MasterSlave Mode Select Bit 
    byte SPTIE       1;                                        SPI Transmit Interrupt Enable 
    byte SPE         1;                                        SPI System Enable Bit 
    byte SPIE        1;                                        SPI Interrupt Enable Bit 
  } Bits;
} SPI0CR1STR;
extern volatile SPI0CR1STR _SPI0CR1 @(REG_BASE + 0x000000D8);
#define SPI0CR1                         _SPI0CR1.Byte
#define SPI0CR1_LSBFE                   _SPI0CR1.Bits.LSBFE
#define SPI0CR1_SSOE                    _SPI0CR1.Bits.SSOE
#define SPI0CR1_CPHA                    _SPI0CR1.Bits.CPHA
#define SPI0CR1_CPOL                    _SPI0CR1.Bits.CPOL
#define SPI0CR1_MSTR                    _SPI0CR1.Bits.MSTR
#define SPI0CR1_SPTIE                   _SPI0CR1.Bits.SPTIE
#define SPI0CR1_SPE                     _SPI0CR1.Bits.SPE
#define SPI0CR1_SPIE                    _SPI0CR1.Bits.SPIE

#define SPI0CR1_LSBFE_MASK              1
#define SPI0CR1_SSOE_MASK               2
#define SPI0CR1_CPHA_MASK               4
#define SPI0CR1_CPOL_MASK               8
#define SPI0CR1_MSTR_MASK               16
#define SPI0CR1_SPTIE_MASK              32
#define SPI0CR1_SPE_MASK                64
#define SPI0CR1_SPIE_MASK               128


 SPI0CR2 - SPI 0 Control Register 2; 0x000000D9 
typedef union {
  byte Byte;
  struct {
    byte SPC0        1;                                        Serial Pin Control Bit 0 
    byte SPISWAI     1;                                        SPI Stop in Wait Mode Bit 
    byte             1; 
    byte BIDIROE     1;                                        Output enable in the Bidirectional mode of operation 
    byte MODFEN      1;                                        Mode Fault Enable Bit 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} SPI0CR2STR;
extern volatile SPI0CR2STR _SPI0CR2 @(REG_BASE + 0x000000D9);
#define SPI0CR2                         _SPI0CR2.Byte
#define SPI0CR2_SPC0                    _SPI0CR2.Bits.SPC0
#define SPI0CR2_SPISWAI                 _SPI0CR2.Bits.SPISWAI
#define SPI0CR2_BIDIROE                 _SPI0CR2.Bits.BIDIROE
#define SPI0CR2_MODFEN                  _SPI0CR2.Bits.MODFEN

#define SPI0CR2_SPC0_MASK               1
#define SPI0CR2_SPISWAI_MASK            2
#define SPI0CR2_BIDIROE_MASK            8
#define SPI0CR2_MODFEN_MASK             16


 SPI0BR - SPI 0 Baud Rate Register; 0x000000DA 
typedef union {
  byte Byte;
  struct {
    byte SPR0        1;                                        SPI Baud Rate Selection Bit 0 
    byte SPR1        1;                                        SPI Baud Rate Selection Bit 1 
    byte SPR2        1;                                        SPI Baud Rate Selection Bit 2 
    byte             1; 
    byte SPPR0       1;                                        SPI Baud Rate Preselection Bits 0 
    byte SPPR1       1;                                        SPI Baud Rate Preselection Bits 1 
    byte SPPR2       1;                                        SPI Baud Rate Preselection Bits 2 
    byte             1; 
  } Bits;
  struct {
    byte grpSPR  3;
    byte         1;
    byte grpSPPR 3;
    byte         1;
  } MergedBits;
} SPI0BRSTR;
extern volatile SPI0BRSTR _SPI0BR @(REG_BASE + 0x000000DA);
#define SPI0BR                          _SPI0BR.Byte
#define SPI0BR_SPR0                     _SPI0BR.Bits.SPR0
#define SPI0BR_SPR1                     _SPI0BR.Bits.SPR1
#define SPI0BR_SPR2                     _SPI0BR.Bits.SPR2
#define SPI0BR_SPPR0                    _SPI0BR.Bits.SPPR0
#define SPI0BR_SPPR1                    _SPI0BR.Bits.SPPR1
#define SPI0BR_SPPR2                    _SPI0BR.Bits.SPPR2
#define SPI0BR_SPR                      _SPI0BR.MergedBits.grpSPR
#define SPI0BR_SPPR                     _SPI0BR.MergedBits.grpSPPR

#define SPI0BR_SPR0_MASK                1
#define SPI0BR_SPR1_MASK                2
#define SPI0BR_SPR2_MASK                4
#define SPI0BR_SPPR0_MASK               16
#define SPI0BR_SPPR1_MASK               32
#define SPI0BR_SPPR2_MASK               64
#define SPI0BR_SPR_MASK                 7
#define SPI0BR_SPR_BITNUM               0
#define SPI0BR_SPPR_MASK                112
#define SPI0BR_SPPR_BITNUM              4


 SPI0SR - SPI 0 Status Register; 0x000000DB 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte MODF        1;                                        Mode Fault Flag 
    byte SPTEF       1;                                        SPI Transmit Empty Interrupt Flag 
    byte             1; 
    byte SPIF        1;                                        SPIF Receive Interrupt Flag 
  } Bits;
} SPI0SRSTR;
extern volatile SPI0SRSTR _SPI0SR @(REG_BASE + 0x000000DB);
#define SPI0SR                          _SPI0SR.Byte
#define SPI0SR_MODF                     _SPI0SR.Bits.MODF
#define SPI0SR_SPTEF                    _SPI0SR.Bits.SPTEF
#define SPI0SR_SPIF                     _SPI0SR.Bits.SPIF

#define SPI0SR_MODF_MASK                16
#define SPI0SR_SPTEF_MASK               32
#define SPI0SR_SPIF_MASK                128


 SPI0DR - SPI 0 Data Register; 0x000000DD 
typedef union {
  byte Byte;
} SPI0DRSTR;
extern volatile SPI0DRSTR _SPI0DR @(REG_BASE + 0x000000DD);
#define SPI0DR                          _SPI0DR.Byte



 IIC0_IBAD - IIC 0 Address Register; 0x000000E0 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte ADR1        1;                                        Slave Address Bit 1 
    byte ADR2        1;                                        Slave Address Bit 2 
    byte ADR3        1;                                        Slave Address Bit 3 
    byte ADR4        1;                                        Slave Address Bit 4 
    byte ADR5        1;                                        Slave Address Bit 5 
    byte ADR6        1;                                        Slave Address Bit 6 
    byte ADR7        1;                                        Slave Address Bit 7 
  } Bits;
  struct {
    byte         1;
    byte grpADR_1 7;
  } MergedBits;
} IIC0_IBADSTR;
extern volatile IIC0_IBADSTR _IIC0_IBAD @(REG_BASE + 0x000000E0);
#define IIC0_IBAD                       _IIC0_IBAD.Byte
#define IIC0_IBAD_ADR1                  _IIC0_IBAD.Bits.ADR1
#define IIC0_IBAD_ADR2                  _IIC0_IBAD.Bits.ADR2
#define IIC0_IBAD_ADR3                  _IIC0_IBAD.Bits.ADR3
#define IIC0_IBAD_ADR4                  _IIC0_IBAD.Bits.ADR4
#define IIC0_IBAD_ADR5                  _IIC0_IBAD.Bits.ADR5
#define IIC0_IBAD_ADR6                  _IIC0_IBAD.Bits.ADR6
#define IIC0_IBAD_ADR7                  _IIC0_IBAD.Bits.ADR7
#define IIC0_IBAD_ADR_1                 _IIC0_IBAD.MergedBits.grpADR_1
#define IIC0_IBAD_ADR                   IIC0_IBAD_ADR_1

#define IIC0_IBAD_ADR1_MASK             2
#define IIC0_IBAD_ADR2_MASK             4
#define IIC0_IBAD_ADR3_MASK             8
#define IIC0_IBAD_ADR4_MASK             16
#define IIC0_IBAD_ADR5_MASK             32
#define IIC0_IBAD_ADR6_MASK             64
#define IIC0_IBAD_ADR7_MASK             128
#define IIC0_IBAD_ADR_1_MASK            254
#define IIC0_IBAD_ADR_1_BITNUM          1


 IIC0_IBFD - IIC 0 Frequency Divider Register; 0x000000E1 
typedef union {
  byte Byte;
  struct {
    byte IBC0        1;                                        I-Bus Clock Rate 0 
    byte IBC1        1;                                        I-Bus Clock Rate 1 
    byte IBC2        1;                                        I-Bus Clock Rate 2 
    byte IBC3        1;                                        I-Bus Clock Rate 3 
    byte IBC4        1;                                        I-Bus Clock Rate 4 
    byte IBC5        1;                                        I-Bus Clock Rate 5 
    byte IBC6        1;                                        I-Bus Clock Rate 6 
    byte IBC7        1;                                        I-Bus Clock Rate 7 
  } Bits;
} IIC0_IBFDSTR;
extern volatile IIC0_IBFDSTR _IIC0_IBFD @(REG_BASE + 0x000000E1);
#define IIC0_IBFD                       _IIC0_IBFD.Byte
#define IIC0_IBFD_IBC0                  _IIC0_IBFD.Bits.IBC0
#define IIC0_IBFD_IBC1                  _IIC0_IBFD.Bits.IBC1
#define IIC0_IBFD_IBC2                  _IIC0_IBFD.Bits.IBC2
#define IIC0_IBFD_IBC3                  _IIC0_IBFD.Bits.IBC3
#define IIC0_IBFD_IBC4                  _IIC0_IBFD.Bits.IBC4
#define IIC0_IBFD_IBC5                  _IIC0_IBFD.Bits.IBC5
#define IIC0_IBFD_IBC6                  _IIC0_IBFD.Bits.IBC6
#define IIC0_IBFD_IBC7                  _IIC0_IBFD.Bits.IBC7

#define IIC0_IBFD_IBC0_MASK             1
#define IIC0_IBFD_IBC1_MASK             2
#define IIC0_IBFD_IBC2_MASK             4
#define IIC0_IBFD_IBC3_MASK             8
#define IIC0_IBFD_IBC4_MASK             16
#define IIC0_IBFD_IBC5_MASK             32
#define IIC0_IBFD_IBC6_MASK             64
#define IIC0_IBFD_IBC7_MASK             128


 IIC0_IBCR - IIC 0 Control Register; 0x000000E2 
typedef union {
  byte Byte;
  struct {
    byte IBSWAI      1;                                        I-Bus Interface Stop in WAIT mode 
    byte             1; 
    byte RSTA        1;                                        Repeat Start 
    byte TXAK        1;                                        Transmit Acknowledge enable 
    byte TX_RX       1;                                        TransmitReceive mode select bit 
    byte MS_SL       1;                                        MasterSlave mode select bit 
    byte IBIE        1;                                        I-Bus Interrupt Enable 
    byte IBEN        1;                                        I-Bus Enable 
  } Bits;
} IIC0_IBCRSTR;
extern volatile IIC0_IBCRSTR _IIC0_IBCR @(REG_BASE + 0x000000E2);
#define IIC0_IBCR                       _IIC0_IBCR.Byte
#define IIC0_IBCR_IBSWAI                _IIC0_IBCR.Bits.IBSWAI
#define IIC0_IBCR_RSTA                  _IIC0_IBCR.Bits.RSTA
#define IIC0_IBCR_TXAK                  _IIC0_IBCR.Bits.TXAK
#define IIC0_IBCR_TX_RX                 _IIC0_IBCR.Bits.TX_RX
#define IIC0_IBCR_MS_SL                 _IIC0_IBCR.Bits.MS_SL
#define IIC0_IBCR_IBIE                  _IIC0_IBCR.Bits.IBIE
#define IIC0_IBCR_IBEN                  _IIC0_IBCR.Bits.IBEN

#define IIC0_IBCR_IBSWAI_MASK           1
#define IIC0_IBCR_RSTA_MASK             4
#define IIC0_IBCR_TXAK_MASK             8
#define IIC0_IBCR_TX_RX_MASK            16
#define IIC0_IBCR_MS_SL_MASK            32
#define IIC0_IBCR_IBIE_MASK             64
#define IIC0_IBCR_IBEN_MASK             128


 IIC0_IBSR - IIC 0 Status Register; 0x000000E3 
typedef union {
  byte Byte;
  struct {
    byte RXAK        1;                                        Received Acknowledge 
    byte IBIF        1;                                        I-Bus Interrupt 
    byte SRW         1;                                        Slave ReadWrite 
    byte             1; 
    byte IBAL        1;                                        Arbitration Lost 
    byte IBB         1;                                        Bus busy bit 
    byte IAAS        1;                                        Addressed as a slave bit 
    byte TCF         1;                                        Data transferring bit 
  } Bits;
} IIC0_IBSRSTR;
extern volatile IIC0_IBSRSTR _IIC0_IBSR @(REG_BASE + 0x000000E3);
#define IIC0_IBSR                       _IIC0_IBSR.Byte
#define IIC0_IBSR_RXAK                  _IIC0_IBSR.Bits.RXAK
#define IIC0_IBSR_IBIF                  _IIC0_IBSR.Bits.IBIF
#define IIC0_IBSR_SRW                   _IIC0_IBSR.Bits.SRW
#define IIC0_IBSR_IBAL                  _IIC0_IBSR.Bits.IBAL
#define IIC0_IBSR_IBB                   _IIC0_IBSR.Bits.IBB
#define IIC0_IBSR_IAAS                  _IIC0_IBSR.Bits.IAAS
#define IIC0_IBSR_TCF                   _IIC0_IBSR.Bits.TCF

#define IIC0_IBSR_RXAK_MASK             1
#define IIC0_IBSR_IBIF_MASK             2
#define IIC0_IBSR_SRW_MASK              4
#define IIC0_IBSR_IBAL_MASK             16
#define IIC0_IBSR_IBB_MASK              32
#define IIC0_IBSR_IAAS_MASK             64
#define IIC0_IBSR_TCF_MASK              128


 IIC0_IBDR - IIC 0 Data IO Register; 0x000000E4 
typedef union {
  byte Byte;
  struct {
    byte D0          1;                                        IIC Data Bit 0 
    byte D1          1;                                        IIC Data Bit 1 
    byte D2          1;                                        IIC Data Bit 2 
    byte D3          1;                                        IIC Data Bit 3 
    byte D4          1;                                        IIC Data Bit 4 
    byte D5          1;                                        IIC Data Bit 5 
    byte D6          1;                                        IIC Data Bit 6 
    byte D7          1;                                        IIC Data Bit 7 
  } Bits;
} IIC0_IBDRSTR;
extern volatile IIC0_IBDRSTR _IIC0_IBDR @(REG_BASE + 0x000000E4);
#define IIC0_IBDR                       _IIC0_IBDR.Byte
#define IIC0_IBDR_D0                    _IIC0_IBDR.Bits.D0
#define IIC0_IBDR_D1                    _IIC0_IBDR.Bits.D1
#define IIC0_IBDR_D2                    _IIC0_IBDR.Bits.D2
#define IIC0_IBDR_D3                    _IIC0_IBDR.Bits.D3
#define IIC0_IBDR_D4                    _IIC0_IBDR.Bits.D4
#define IIC0_IBDR_D5                    _IIC0_IBDR.Bits.D5
#define IIC0_IBDR_D6                    _IIC0_IBDR.Bits.D6
#define IIC0_IBDR_D7                    _IIC0_IBDR.Bits.D7

#define IIC0_IBDR_D0_MASK               1
#define IIC0_IBDR_D1_MASK               2
#define IIC0_IBDR_D2_MASK               4
#define IIC0_IBDR_D3_MASK               8
#define IIC0_IBDR_D4_MASK               16
#define IIC0_IBDR_D5_MASK               32
#define IIC0_IBDR_D6_MASK               64
#define IIC0_IBDR_D7_MASK               128


 SPI1CR1 - SPI 1 Control Register; 0x000000F0 
typedef union {
  byte Byte;
  struct {
    byte LSBFE       1;                                        SPI LSB-First Enable 
    byte SSOE        1;                                        Slave Select Output Enable 
    byte CPHA        1;                                        SPI Clock Phase Bit 
    byte CPOL        1;                                        SPI Clock Polarity Bit 
    byte MSTR        1;                                        SPI MasterSlave Mode Select Bit 
    byte SPTIE       1;                                        SPI Transmit Interrupt Enable 
    byte SPE         1;                                        SPI System Enable Bit 
    byte SPIE        1;                                        SPI Interrupt Enable Bit 
  } Bits;
} SPI1CR1STR;
extern volatile SPI1CR1STR _SPI1CR1 @(REG_BASE + 0x000000F0);
#define SPI1CR1                         _SPI1CR1.Byte
#define SPI1CR1_LSBFE                   _SPI1CR1.Bits.LSBFE
#define SPI1CR1_SSOE                    _SPI1CR1.Bits.SSOE
#define SPI1CR1_CPHA                    _SPI1CR1.Bits.CPHA
#define SPI1CR1_CPOL                    _SPI1CR1.Bits.CPOL
#define SPI1CR1_MSTR                    _SPI1CR1.Bits.MSTR
#define SPI1CR1_SPTIE                   _SPI1CR1.Bits.SPTIE
#define SPI1CR1_SPE                     _SPI1CR1.Bits.SPE
#define SPI1CR1_SPIE                    _SPI1CR1.Bits.SPIE

#define SPI1CR1_LSBFE_MASK              1
#define SPI1CR1_SSOE_MASK               2
#define SPI1CR1_CPHA_MASK               4
#define SPI1CR1_CPOL_MASK               8
#define SPI1CR1_MSTR_MASK               16
#define SPI1CR1_SPTIE_MASK              32
#define SPI1CR1_SPE_MASK                64
#define SPI1CR1_SPIE_MASK               128


 SPI1CR2 - SPI 1 Control Register 2; 0x000000F1 
typedef union {
  byte Byte;
  struct {
    byte SPC0        1;                                        Serial Pin Control Bit 0 
    byte SPISWAI     1;                                        SPI Stop in Wait Mode Bit 
    byte             1; 
    byte BIDIROE     1;                                        Output enable in the Bidirectional mode of operation 
    byte MODFEN      1;                                        Mode Fault Enable Bit 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} SPI1CR2STR;
extern volatile SPI1CR2STR _SPI1CR2 @(REG_BASE + 0x000000F1);
#define SPI1CR2                         _SPI1CR2.Byte
#define SPI1CR2_SPC0                    _SPI1CR2.Bits.SPC0
#define SPI1CR2_SPISWAI                 _SPI1CR2.Bits.SPISWAI
#define SPI1CR2_BIDIROE                 _SPI1CR2.Bits.BIDIROE
#define SPI1CR2_MODFEN                  _SPI1CR2.Bits.MODFEN

#define SPI1CR2_SPC0_MASK               1
#define SPI1CR2_SPISWAI_MASK            2
#define SPI1CR2_BIDIROE_MASK            8
#define SPI1CR2_MODFEN_MASK             16


 SPI1BR - SPI 1 Baud Rate Register; 0x000000F2 
typedef union {
  byte Byte;
  struct {
    byte SPR0        1;                                        SPI Baud Rate Selection Bit 0 
    byte SPR1        1;                                        SPI Baud Rate Selection Bit 1 
    byte SPR2        1;                                        SPI Baud Rate Selection Bit 2 
    byte             1; 
    byte SPPR0       1;                                        SPI Baud Rate Preselection Bits 0 
    byte SPPR1       1;                                        SPI Baud Rate Preselection Bits 1 
    byte SPPR2       1;                                        SPI Baud Rate Preselection Bits 2 
    byte             1; 
  } Bits;
  struct {
    byte grpSPR  3;
    byte         1;
    byte grpSPPR 3;
    byte         1;
  } MergedBits;
} SPI1BRSTR;
extern volatile SPI1BRSTR _SPI1BR @(REG_BASE + 0x000000F2);
#define SPI1BR                          _SPI1BR.Byte
#define SPI1BR_SPR0                     _SPI1BR.Bits.SPR0
#define SPI1BR_SPR1                     _SPI1BR.Bits.SPR1
#define SPI1BR_SPR2                     _SPI1BR.Bits.SPR2
#define SPI1BR_SPPR0                    _SPI1BR.Bits.SPPR0
#define SPI1BR_SPPR1                    _SPI1BR.Bits.SPPR1
#define SPI1BR_SPPR2                    _SPI1BR.Bits.SPPR2
#define SPI1BR_SPR                      _SPI1BR.MergedBits.grpSPR
#define SPI1BR_SPPR                     _SPI1BR.MergedBits.grpSPPR

#define SPI1BR_SPR0_MASK                1
#define SPI1BR_SPR1_MASK                2
#define SPI1BR_SPR2_MASK                4
#define SPI1BR_SPPR0_MASK               16
#define SPI1BR_SPPR1_MASK               32
#define SPI1BR_SPPR2_MASK               64
#define SPI1BR_SPR_MASK                 7
#define SPI1BR_SPR_BITNUM               0
#define SPI1BR_SPPR_MASK                112
#define SPI1BR_SPPR_BITNUM              4


 SPI1SR - SPI 1 Status Register; 0x000000F3 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte MODF        1;                                        Mode Fault Flag 
    byte SPTEF       1;                                        SPI Transmit Empty Interrupt Flag 
    byte             1; 
    byte SPIF        1;                                        SPIF Receive Interrupt Flag 
  } Bits;
} SPI1SRSTR;
extern volatile SPI1SRSTR _SPI1SR @(REG_BASE + 0x000000F3);
#define SPI1SR                          _SPI1SR.Byte
#define SPI1SR_MODF                     _SPI1SR.Bits.MODF
#define SPI1SR_SPTEF                    _SPI1SR.Bits.SPTEF
#define SPI1SR_SPIF                     _SPI1SR.Bits.SPIF

#define SPI1SR_MODF_MASK                16
#define SPI1SR_SPTEF_MASK               32
#define SPI1SR_SPIF_MASK                128


 SPI1DR - SPI 1 Data Register; 0x000000F5 
typedef union {
  byte Byte;
} SPI1DRSTR;
extern volatile SPI1DRSTR _SPI1DR @(REG_BASE + 0x000000F5);
#define SPI1DR                          _SPI1DR.Byte



 SPI2CR1 - SPI 2 Control Register; 0x000000F8 
typedef union {
  byte Byte;
  struct {
    byte LSBFE       1;                                        SPI LSB-First Enable 
    byte SSOE        1;                                        Slave Select Output Enable 
    byte CPHA        1;                                        SPI Clock Phase Bit 
    byte CPOL        1;                                        SPI Clock Polarity Bit 
    byte MSTR        1;                                        SPI MasterSlave Mode Select Bit 
    byte SPTIE       1;                                        SPI Transmit Interrupt Enable 
    byte SPE         1;                                        SPI System Enable Bit 
    byte SPIE        1;                                        SPI Interrupt Enable Bit 
  } Bits;
} SPI2CR1STR;
extern volatile SPI2CR1STR _SPI2CR1 @(REG_BASE + 0x000000F8);
#define SPI2CR1                         _SPI2CR1.Byte
#define SPI2CR1_LSBFE                   _SPI2CR1.Bits.LSBFE
#define SPI2CR1_SSOE                    _SPI2CR1.Bits.SSOE
#define SPI2CR1_CPHA                    _SPI2CR1.Bits.CPHA
#define SPI2CR1_CPOL                    _SPI2CR1.Bits.CPOL
#define SPI2CR1_MSTR                    _SPI2CR1.Bits.MSTR
#define SPI2CR1_SPTIE                   _SPI2CR1.Bits.SPTIE
#define SPI2CR1_SPE                     _SPI2CR1.Bits.SPE
#define SPI2CR1_SPIE                    _SPI2CR1.Bits.SPIE

#define SPI2CR1_LSBFE_MASK              1
#define SPI2CR1_SSOE_MASK               2
#define SPI2CR1_CPHA_MASK               4
#define SPI2CR1_CPOL_MASK               8
#define SPI2CR1_MSTR_MASK               16
#define SPI2CR1_SPTIE_MASK              32
#define SPI2CR1_SPE_MASK                64
#define SPI2CR1_SPIE_MASK               128


 SPI2CR2 - SPI 2 Control Register 2; 0x000000F9 
typedef union {
  byte Byte;
  struct {
    byte SPC0        1;                                        Serial Pin Control Bit 0 
    byte SPISWAI     1;                                        SPI Stop in Wait Mode Bit 
    byte             1; 
    byte BIDIROE     1;                                        Output enable in the Bidirectional mode of operation 
    byte MODFEN      1;                                        Mode Fault Enable Bit 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} SPI2CR2STR;
extern volatile SPI2CR2STR _SPI2CR2 @(REG_BASE + 0x000000F9);
#define SPI2CR2                         _SPI2CR2.Byte
#define SPI2CR2_SPC0                    _SPI2CR2.Bits.SPC0
#define SPI2CR2_SPISWAI                 _SPI2CR2.Bits.SPISWAI
#define SPI2CR2_BIDIROE                 _SPI2CR2.Bits.BIDIROE
#define SPI2CR2_MODFEN                  _SPI2CR2.Bits.MODFEN

#define SPI2CR2_SPC0_MASK               1
#define SPI2CR2_SPISWAI_MASK            2
#define SPI2CR2_BIDIROE_MASK            8
#define SPI2CR2_MODFEN_MASK             16


 SPI2BR - SPI 2 Baud Rate Register; 0x000000FA 
typedef union {
  byte Byte;
  struct {
    byte SPR0        1;                                        SPI Baud Rate Selection Bit 0 
    byte SPR1        1;                                        SPI Baud Rate Selection Bit 1 
    byte SPR2        1;                                        SPI Baud Rate Selection Bit 2 
    byte             1; 
    byte SPPR0       1;                                        SPI Baud Rate Preselection Bits 0 
    byte SPPR1       1;                                        SPI Baud Rate Preselection Bits 1 
    byte SPPR2       1;                                        SPI Baud Rate Preselection Bits 2 
    byte             1; 
  } Bits;
  struct {
    byte grpSPR  3;
    byte         1;
    byte grpSPPR 3;
    byte         1;
  } MergedBits;
} SPI2BRSTR;
extern volatile SPI2BRSTR _SPI2BR @(REG_BASE + 0x000000FA);
#define SPI2BR                          _SPI2BR.Byte
#define SPI2BR_SPR0                     _SPI2BR.Bits.SPR0
#define SPI2BR_SPR1                     _SPI2BR.Bits.SPR1
#define SPI2BR_SPR2                     _SPI2BR.Bits.SPR2
#define SPI2BR_SPPR0                    _SPI2BR.Bits.SPPR0
#define SPI2BR_SPPR1                    _SPI2BR.Bits.SPPR1
#define SPI2BR_SPPR2                    _SPI2BR.Bits.SPPR2
#define SPI2BR_SPR                      _SPI2BR.MergedBits.grpSPR
#define SPI2BR_SPPR                     _SPI2BR.MergedBits.grpSPPR

#define SPI2BR_SPR0_MASK                1
#define SPI2BR_SPR1_MASK                2
#define SPI2BR_SPR2_MASK                4
#define SPI2BR_SPPR0_MASK               16
#define SPI2BR_SPPR1_MASK               32
#define SPI2BR_SPPR2_MASK               64
#define SPI2BR_SPR_MASK                 7
#define SPI2BR_SPR_BITNUM               0
#define SPI2BR_SPPR_MASK                112
#define SPI2BR_SPPR_BITNUM              4


 SPI2SR - SPI 2 Status Register; 0x000000FB 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte MODF        1;                                        Mode Fault Flag 
    byte SPTEF       1;                                        SPI Transmit Empty Interrupt Flag 
    byte             1; 
    byte SPIF        1;                                        SPIF Receive Interrupt Flag 
  } Bits;
} SPI2SRSTR;
extern volatile SPI2SRSTR _SPI2SR @(REG_BASE + 0x000000FB);
#define SPI2SR                          _SPI2SR.Byte
#define SPI2SR_MODF                     _SPI2SR.Bits.MODF
#define SPI2SR_SPTEF                    _SPI2SR.Bits.SPTEF
#define SPI2SR_SPIF                     _SPI2SR.Bits.SPIF

#define SPI2SR_MODF_MASK                16
#define SPI2SR_SPTEF_MASK               32
#define SPI2SR_SPIF_MASK                128


 SPI2DR - SPI 2 Data Register; 0x000000FD 
typedef union {
  byte Byte;
} SPI2DRSTR;
extern volatile SPI2DRSTR _SPI2DR @(REG_BASE + 0x000000FD);
#define SPI2DR                          _SPI2DR.Byte



 FCLKDIV - Flash Clock Divider Register; 0x00000100 
typedef union {
  byte Byte;
  struct {
    byte FDIV0       1;                                        Flash Clock Divider Bit 0 
    byte FDIV1       1;                                        Flash Clock Divider Bit 1 
    byte FDIV2       1;                                        Flash Clock Divider Bit 2 
    byte FDIV3       1;                                        Flash Clock Divider Bit 3 
    byte FDIV4       1;                                        Flash Clock Divider Bit 4 
    byte FDIV5       1;                                        Flash Clock Divider Bit 5 
    byte PRDIV8      1;                                        Enable Prescaler by 8 
    byte FDIVLD      1;                                        Flash Clock Divider Loaded 
  } Bits;
  struct {
    byte grpFDIV 6;
    byte grpPRDIV_8 1;
    byte         1;
  } MergedBits;
} FCLKDIVSTR;
extern volatile FCLKDIVSTR _FCLKDIV @(REG_BASE + 0x00000100);
#define FCLKDIV                         _FCLKDIV.Byte
#define FCLKDIV_FDIV0                   _FCLKDIV.Bits.FDIV0
#define FCLKDIV_FDIV1                   _FCLKDIV.Bits.FDIV1
#define FCLKDIV_FDIV2                   _FCLKDIV.Bits.FDIV2
#define FCLKDIV_FDIV3                   _FCLKDIV.Bits.FDIV3
#define FCLKDIV_FDIV4                   _FCLKDIV.Bits.FDIV4
#define FCLKDIV_FDIV5                   _FCLKDIV.Bits.FDIV5
#define FCLKDIV_PRDIV8                  _FCLKDIV.Bits.PRDIV8
#define FCLKDIV_FDIVLD                  _FCLKDIV.Bits.FDIVLD
#define FCLKDIV_FDIV                    _FCLKDIV.MergedBits.grpFDIV

#define FCLKDIV_FDIV0_MASK              1
#define FCLKDIV_FDIV1_MASK              2
#define FCLKDIV_FDIV2_MASK              4
#define FCLKDIV_FDIV3_MASK              8
#define FCLKDIV_FDIV4_MASK              16
#define FCLKDIV_FDIV5_MASK              32
#define FCLKDIV_PRDIV8_MASK             64
#define FCLKDIV_FDIVLD_MASK             128
#define FCLKDIV_FDIV_MASK               63
#define FCLKDIV_FDIV_BITNUM             0


 FSEC - Flash Security Register; 0x00000101 
typedef union {
  byte Byte;
  struct {
    byte SEC0        1;                                        Memory security bit 0 
    byte SEC1        1;                                        Memory security bit 1 
    byte RNV2        1;                                        Reserved Non Volatile flag bit 2 
    byte RNV3        1;                                        Reserved Non Volatile flag bit 3 
    byte RNV4        1;                                        Reserved Non Volatile flag bit 4 
    byte RNV5        1;                                        Reserved Non Volatile flag bit 5 
    byte KEYEN0      1;                                        Backdoor Key Security Enable Bit 0 
    byte KEYEN1      1;                                        Backdoor Key Security Enable Bit 1 
  } Bits;
  struct {
    byte grpSEC  2;
    byte grpRNV_2 4;
    byte grpKEYEN 2;
  } MergedBits;
} FSECSTR;
extern volatile FSECSTR _FSEC @(REG_BASE + 0x00000101);
#define FSEC                            _FSEC.Byte
#define FSEC_SEC0                       _FSEC.Bits.SEC0
#define FSEC_SEC1                       _FSEC.Bits.SEC1
#define FSEC_RNV2                       _FSEC.Bits.RNV2
#define FSEC_RNV3                       _FSEC.Bits.RNV3
#define FSEC_RNV4                       _FSEC.Bits.RNV4
#define FSEC_RNV5                       _FSEC.Bits.RNV5
#define FSEC_KEYEN0                     _FSEC.Bits.KEYEN0
#define FSEC_KEYEN1                     _FSEC.Bits.KEYEN1
#define FSEC_SEC                        _FSEC.MergedBits.grpSEC
#define FSEC_RNV_2                      _FSEC.MergedBits.grpRNV_2
#define FSEC_KEYEN                      _FSEC.MergedBits.grpKEYEN
#define FSEC_RNV                        FSEC_RNV_2

#define FSEC_SEC0_MASK                  1
#define FSEC_SEC1_MASK                  2
#define FSEC_RNV2_MASK                  4
#define FSEC_RNV3_MASK                  8
#define FSEC_RNV4_MASK                  16
#define FSEC_RNV5_MASK                  32
#define FSEC_KEYEN0_MASK                64
#define FSEC_KEYEN1_MASK                128
#define FSEC_SEC_MASK                   3
#define FSEC_SEC_BITNUM                 0
#define FSEC_RNV_2_MASK                 60
#define FSEC_RNV_2_BITNUM               2
#define FSEC_KEYEN_MASK                 192
#define FSEC_KEYEN_BITNUM               6


 FTSTMOD - Flash Test Mode Register; 0x00000102 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte WRALL       1;                                        Write to all register banks 
    byte MRDS        2;                                        Margin Read Setting 
    byte             1; 
  } Bits;
} FTSTMODSTR;
extern volatile FTSTMODSTR _FTSTMOD @(REG_BASE + 0x00000102);
#define FTSTMOD                         _FTSTMOD.Byte
#define FTSTMOD_WRALL                   _FTSTMOD.Bits.WRALL
#define FTSTMOD_MRDS                    _FTSTMOD.Bits.MRDS

#define FTSTMOD_WRALL_MASK              16
#define FTSTMOD_MRDS_MASK               96
#define FTSTMOD_MRDS_BITNUM             5


 FCNFG - Flash Configuration Register; 0x00000103 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte KEYACC      1;                                        Enable Security Key Writing 
    byte CCIE        1;                                        Command Complete Interrupt Enable 
    byte CBEIE       1;                                        Command Buffers Empty Interrupt Enable 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @(REG_BASE + 0x00000103);
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC
#define FCNFG_CCIE                      _FCNFG.Bits.CCIE
#define FCNFG_CBEIE                     _FCNFG.Bits.CBEIE

#define FCNFG_KEYACC_MASK               32
#define FCNFG_CCIE_MASK                 64
#define FCNFG_CBEIE_MASK                128


 FPROT - Flash Protection Register; 0x00000104 
typedef union {
  byte Byte;
  struct {
    byte FPLS0       1;                                        Flash Protection Lower Address size 0 
    byte FPLS1       1;                                        Flash Protection Lower Address size 1 
    byte FPLDIS      1;                                        Flash Protection Lower address range disable 
    byte FPHS0       1;                                        Flash Protection Higher address size 0 
    byte FPHS1       1;                                        Flash Protection Higher address size 1 
    byte FPHDIS      1;                                        Flash Protection Higher address range disable 
    byte RNV6        1;                                        Reserved Non-Volatile Bit 
    byte FPOPEN      1;                                        Opens the flash block or subsections of it for program or erase 
  } Bits;
  struct {
    byte grpFPLS 2;
    byte         1;
    byte grpFPHS 2;
    byte         1;
    byte grpRNV_6 1;
    byte         1;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @(REG_BASE + 0x00000104);
#define FPROT                           _FPROT.Byte
#define FPROT_FPLS0                     _FPROT.Bits.FPLS0
#define FPROT_FPLS1                     _FPROT.Bits.FPLS1
#define FPROT_FPLDIS                    _FPROT.Bits.FPLDIS
#define FPROT_FPHS0                     _FPROT.Bits.FPHS0
#define FPROT_FPHS1                     _FPROT.Bits.FPHS1
#define FPROT_FPHDIS                    _FPROT.Bits.FPHDIS
#define FPROT_RNV6                      _FPROT.Bits.RNV6
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPLS                      _FPROT.MergedBits.grpFPLS
#define FPROT_FPHS                      _FPROT.MergedBits.grpFPHS

#define FPROT_FPLS0_MASK                1
#define FPROT_FPLS1_MASK                2
#define FPROT_FPLDIS_MASK               4
#define FPROT_FPHS0_MASK                8
#define FPROT_FPHS1_MASK                16
#define FPROT_FPHDIS_MASK               32
#define FPROT_RNV6_MASK                 64
#define FPROT_FPOPEN_MASK               128
#define FPROT_FPLS_MASK                 3
#define FPROT_FPLS_BITNUM               0
#define FPROT_FPHS_MASK                 24
#define FPROT_FPHS_BITNUM               3


 FSTAT - Flash Status Register; 0x00000105 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte BLANK       1;                                        Blank Verify Flag 
    byte             1; 
    byte ACCERR      1;                                        Access error 
    byte PVIOL       1;                                        Protection violation 
    byte CCIF        1;                                        Command Complete Interrupt Flag 
    byte CBEIF       1;                                        Command Buffers Empty Interrupt Flag 
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @(REG_BASE + 0x00000105);
#define FSTAT                           _FSTAT.Byte
#define FSTAT_BLANK                     _FSTAT.Bits.BLANK
#define FSTAT_ACCERR                    _FSTAT.Bits.ACCERR
#define FSTAT_PVIOL                     _FSTAT.Bits.PVIOL
#define FSTAT_CCIF                      _FSTAT.Bits.CCIF
#define FSTAT_CBEIF                     _FSTAT.Bits.CBEIF

#define FSTAT_BLANK_MASK                4
#define FSTAT_ACCERR_MASK               16
#define FSTAT_PVIOL_MASK                32
#define FSTAT_CCIF_MASK                 64
#define FSTAT_CBEIF_MASK                128


 FCMD - Flash Command Buffer and Register; 0x00000106 
typedef union {
  byte Byte;
  struct {
    byte CMDB0       1;                                        NVM User Mode Command Bit 0 
    byte CMDB1       1;                                        NVM User Mode Command Bit 1 
    byte CMDB2       1;                                        NVM User Mode Command Bit 2 
    byte CMDB3       1;                                        NVM User Mode Command Bit 3 
    byte CMDB4       1;                                        NVM User Mode Command Bit 4 
    byte CMDB5       1;                                        NVM User Mode Command Bit 5 
    byte CMDB6       1;                                        NVM User Mode Command Bit 6 
    byte             1; 
  } Bits;
  struct {
    byte grpCMDB 7;
    byte         1;
  } MergedBits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @(REG_BASE + 0x00000106);
#define FCMD                            _FCMD.Byte
#define FCMD_CMDB0                      _FCMD.Bits.CMDB0
#define FCMD_CMDB1                      _FCMD.Bits.CMDB1
#define FCMD_CMDB2                      _FCMD.Bits.CMDB2
#define FCMD_CMDB3                      _FCMD.Bits.CMDB3
#define FCMD_CMDB4                      _FCMD.Bits.CMDB4
#define FCMD_CMDB5                      _FCMD.Bits.CMDB5
#define FCMD_CMDB6                      _FCMD.Bits.CMDB6
#define FCMD_CMDB                       _FCMD.MergedBits.grpCMDB

#define FCMD_CMDB0_MASK                 1
#define FCMD_CMDB1_MASK                 2
#define FCMD_CMDB2_MASK                 4
#define FCMD_CMDB3_MASK                 8
#define FCMD_CMDB4_MASK                 16
#define FCMD_CMDB5_MASK                 32
#define FCMD_CMDB6_MASK                 64
#define FCMD_CMDB_MASK                  127
#define FCMD_CMDB_BITNUM                0


 FADDRHI - Flash Address High Register; 0x00000108 
typedef union {
  byte Byte;
} FADDRHISTR;
extern volatile FADDRHISTR _FADDRHI @(REG_BASE + 0x00000108);
#define FADDRHI                         _FADDRHI.Byte



 FADDRLO - Flash Address Low Register; 0x00000109 
typedef union {
  byte Byte;
} FADDRLOSTR;
extern volatile FADDRLOSTR _FADDRLO @(REG_BASE + 0x00000109);
#define FADDRLO                         _FADDRLO.Byte



 FDATAHI - Flash Data High Register; 0x0000010A 
typedef union {
  byte Byte;
} FDATAHISTR;
extern volatile FDATAHISTR _FDATAHI @(REG_BASE + 0x0000010A);
#define FDATAHI                         _FDATAHI.Byte



 FDATALO - Flash Data Low Register; 0x0000010B 
typedef union {
  byte Byte;
} FDATALOSTR;
extern volatile FDATALOSTR _FDATALO @(REG_BASE + 0x0000010B);
#define FDATALO                         _FDATALO.Byte



 ECLKDIV - EEPROM Clock Divider Register; 0x00000110 
typedef union {
  byte Byte;
  struct {
    byte EDIV0       1;                                        EEPROM Clock Divider 0 
    byte EDIV1       1;                                        EEPROM Clock Divider 1 
    byte EDIV2       1;                                        EEPROM Clock Divider 2 
    byte EDIV3       1;                                        EEPROM Clock Divider 3 
    byte EDIV4       1;                                        EEPROM Clock Divider 4 
    byte EDIV5       1;                                        EEPROM Clock Divider 5 
    byte PRDIV8      1;                                        Enable Prescaler by 8 
    byte EDIVLD      1;                                        EEPROM Clock Divider Loaded 
  } Bits;
  struct {
    byte grpEDIV 6;
    byte grpPRDIV_8 1;
    byte         1;
  } MergedBits;
} ECLKDIVSTR;
extern volatile ECLKDIVSTR _ECLKDIV @(REG_BASE + 0x00000110);
#define ECLKDIV                         _ECLKDIV.Byte
#define ECLKDIV_EDIV0                   _ECLKDIV.Bits.EDIV0
#define ECLKDIV_EDIV1                   _ECLKDIV.Bits.EDIV1
#define ECLKDIV_EDIV2                   _ECLKDIV.Bits.EDIV2
#define ECLKDIV_EDIV3                   _ECLKDIV.Bits.EDIV3
#define ECLKDIV_EDIV4                   _ECLKDIV.Bits.EDIV4
#define ECLKDIV_EDIV5                   _ECLKDIV.Bits.EDIV5
#define ECLKDIV_PRDIV8                  _ECLKDIV.Bits.PRDIV8
#define ECLKDIV_EDIVLD                  _ECLKDIV.Bits.EDIVLD
#define ECLKDIV_EDIV                    _ECLKDIV.MergedBits.grpEDIV

#define ECLKDIV_EDIV0_MASK              1
#define ECLKDIV_EDIV1_MASK              2
#define ECLKDIV_EDIV2_MASK              4
#define ECLKDIV_EDIV3_MASK              8
#define ECLKDIV_EDIV4_MASK              16
#define ECLKDIV_EDIV5_MASK              32
#define ECLKDIV_PRDIV8_MASK             64
#define ECLKDIV_EDIVLD_MASK             128
#define ECLKDIV_EDIV_MASK               63
#define ECLKDIV_EDIV_BITNUM             0


 ECNFG - EEPROM Configuration Register; 0x00000113 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte CCIE        1;                                        Command Complete Interrupt Enable 
    byte CBEIE       1;                                        Command Buffers Empty Interrupt Enable 
  } Bits;
} ECNFGSTR;
extern volatile ECNFGSTR _ECNFG @(REG_BASE + 0x00000113);
#define ECNFG                           _ECNFG.Byte
#define ECNFG_CCIE                      _ECNFG.Bits.CCIE
#define ECNFG_CBEIE                     _ECNFG.Bits.CBEIE

#define ECNFG_CCIE_MASK                 64
#define ECNFG_CBEIE_MASK                128


 EPROT - EEPROM Protection Register; 0x00000114 
typedef union {
  byte Byte;
  struct {
    byte EPS0        1;                                        EEPROM Protection address size 0 
    byte EPS1        1;                                        EEPROM Protection address size 1 
    byte EPS2        1;                                        EEPROM Protection address size 2 
    byte EPDIS       1;                                        EEPROM Protection disable 
    byte RNV4        1;                                        EEPROM Protection address size 4 
    byte RNV5        1;                                        EEPROM Protection address size 5 
    byte RNV6        1;                                        EEPROM Protection address size 6 
    byte EPOPEN      1;                                        Opens the EEPROM block or a subsection of it for program or erase 
  } Bits;
  struct {
    byte grpEPS  3;
    byte         1;
    byte grpRNV_4 3;
    byte         1;
  } MergedBits;
} EPROTSTR;
extern volatile EPROTSTR _EPROT @(REG_BASE + 0x00000114);
#define EPROT                           _EPROT.Byte
#define EPROT_EPS0                      _EPROT.Bits.EPS0
#define EPROT_EPS1                      _EPROT.Bits.EPS1
#define EPROT_EPS2                      _EPROT.Bits.EPS2
#define EPROT_EPDIS                     _EPROT.Bits.EPDIS
#define EPROT_RNV4                      _EPROT.Bits.RNV4
#define EPROT_RNV5                      _EPROT.Bits.RNV5
#define EPROT_RNV6                      _EPROT.Bits.RNV6
#define EPROT_EPOPEN                    _EPROT.Bits.EPOPEN
#define EPROT_EPS                       _EPROT.MergedBits.grpEPS
#define EPROT_RNV_4                     _EPROT.MergedBits.grpRNV_4
#define EPROT_RNV                       EPROT_RNV_4

#define EPROT_EPS0_MASK                 1
#define EPROT_EPS1_MASK                 2
#define EPROT_EPS2_MASK                 4
#define EPROT_EPDIS_MASK                8
#define EPROT_RNV4_MASK                 16
#define EPROT_RNV5_MASK                 32
#define EPROT_RNV6_MASK                 64
#define EPROT_EPOPEN_MASK               128
#define EPROT_EPS_MASK                  7
#define EPROT_EPS_BITNUM                0
#define EPROT_RNV_4_MASK                112
#define EPROT_RNV_4_BITNUM              4


 ESTAT - EEPROM Status Register; 0x00000115 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte BLANK       1;                                        Blank Verify Flag 
    byte             1; 
    byte ACCERR      1;                                        Access error 
    byte PVIOL       1;                                        Protection violation 
    byte CCIF        1;                                        Command Complete Interrupt Flag 
    byte CBEIF       1;                                        Command Buffer Empty Interrupt Flag 
  } Bits;
} ESTATSTR;
extern volatile ESTATSTR _ESTAT @(REG_BASE + 0x00000115);
#define ESTAT                           _ESTAT.Byte
#define ESTAT_BLANK                     _ESTAT.Bits.BLANK
#define ESTAT_ACCERR                    _ESTAT.Bits.ACCERR
#define ESTAT_PVIOL                     _ESTAT.Bits.PVIOL
#define ESTAT_CCIF                      _ESTAT.Bits.CCIF
#define ESTAT_CBEIF                     _ESTAT.Bits.CBEIF

#define ESTAT_BLANK_MASK                4
#define ESTAT_ACCERR_MASK               16
#define ESTAT_PVIOL_MASK                32
#define ESTAT_CCIF_MASK                 64
#define ESTAT_CBEIF_MASK                128


 ECMD - EEPROM Command Buffer and Register; 0x00000116 
typedef union {
  byte Byte;
  struct {
    byte CMDB        7;                                        EEPROM command 
    byte             1; 
  } Bits;
} ECMDSTR;
extern volatile ECMDSTR _ECMD @(REG_BASE + 0x00000116);
#define ECMD                            _ECMD.Byte
#define ECMD_CMDB                       _ECMD.Bits.CMDB

#define ECMD_CMDB_MASK                  127
#define ECMD_CMDB_BITNUM                0


 EADDRHI - EEPROM Address High Register; 0x00000118 
typedef union {
  byte Byte;
  struct {
    byte EABHI       3;                                        EEPROM Address High Bits 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} EADDRHISTR;
extern volatile EADDRHISTR _EADDRHI @(REG_BASE + 0x00000118);
#define EADDRHI                         _EADDRHI.Byte
#define EADDRHI_EABHI                   _EADDRHI.Bits.EABHI

#define EADDRHI_EABHI_MASK              7
#define EADDRHI_EABHI_BITNUM            0


 EADDRLO - EEPROM Address Low Register; 0x00000119 
typedef union {
  byte Byte;
  struct {
    byte EABLO       8;                                        EEPROM Address Low Bits 
  } Bits;
} EADDRLOSTR;
extern volatile EADDRLOSTR _EADDRLO @(REG_BASE + 0x00000119);
#define EADDRLO                         _EADDRLO.Byte
#define EADDRLO_EABLO                   _EADDRLO.Bits.EABLO

#define EADDRLO_EABLO_MASK              255
#define EADDRLO_EABLO_BITNUM            0


 EDATAHI - EEPROM Data High Register; 0x0000011A 
typedef union {
  byte Byte;
} EDATAHISTR;
extern volatile EDATAHISTR _EDATAHI @(REG_BASE + 0x0000011A);
#define EDATAHI                         _EDATAHI.Byte



 EDATALO - EEPROM Data Low Register; 0x0000011B 
typedef union {
  byte Byte;
} EDATALOSTR;
extern volatile EDATALOSTR _EDATALO @(REG_BASE + 0x0000011B);
#define EDATALO                         _EDATALO.Byte



 RAMWPC - RAM Write Protection Control Register; 0x0000011C 
typedef union {
  byte Byte;
  struct {
    byte AVIF        1;                                        S12X_CPU Access Violation Interrupt Flag 
    byte AVIE        1;                                        S12X_CPU Access Violation Interrupt Enable 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RWPE        1;                                        RAM Write Protection Enable 
  } Bits;
} RAMWPCSTR;
extern volatile RAMWPCSTR _RAMWPC @(REG_BASE + 0x0000011C);
#define RAMWPC                          _RAMWPC.Byte
#define RAMWPC_AVIF                     _RAMWPC.Bits.AVIF
#define RAMWPC_AVIE                     _RAMWPC.Bits.AVIE
#define RAMWPC_RWPE                     _RAMWPC.Bits.RWPE

#define RAMWPC_AVIF_MASK                1
#define RAMWPC_AVIE_MASK                2
#define RAMWPC_RWPE_MASK                128


 RAMXGU - RAM XGATE Upper Boundary Register; 0x0000011D 
typedef union {
  byte Byte;
  struct {
    byte XGU0        1;                                        XGATE Region Upper Boundary Bit 0 
    byte XGU1        1;                                        XGATE Region Upper Boundary Bit 1 
    byte XGU2        1;                                        XGATE Region Upper Boundary Bit 2 
    byte XGU3        1;                                        XGATE Region Upper Boundary Bit 3 
    byte XGU4        1;                                        XGATE Region Upper Boundary Bit 4 
    byte XGU5        1;                                        XGATE Region Upper Boundary Bit 5 
    byte XGU6        1;                                        XGATE Region Upper Boundary Bit 6 
    byte             1; 
  } Bits;
  struct {
    byte grpXGU  7;
    byte         1;
  } MergedBits;
} RAMXGUSTR;
extern volatile RAMXGUSTR _RAMXGU @(REG_BASE + 0x0000011D);
#define RAMXGU                          _RAMXGU.Byte
#define RAMXGU_XGU0                     _RAMXGU.Bits.XGU0
#define RAMXGU_XGU1                     _RAMXGU.Bits.XGU1
#define RAMXGU_XGU2                     _RAMXGU.Bits.XGU2
#define RAMXGU_XGU3                     _RAMXGU.Bits.XGU3
#define RAMXGU_XGU4                     _RAMXGU.Bits.XGU4
#define RAMXGU_XGU5                     _RAMXGU.Bits.XGU5
#define RAMXGU_XGU6                     _RAMXGU.Bits.XGU6
#define RAMXGU_XGU                      _RAMXGU.MergedBits.grpXGU

#define RAMXGU_XGU0_MASK                1
#define RAMXGU_XGU1_MASK                2
#define RAMXGU_XGU2_MASK                4
#define RAMXGU_XGU3_MASK                8
#define RAMXGU_XGU4_MASK                16
#define RAMXGU_XGU5_MASK                32
#define RAMXGU_XGU6_MASK                64
#define RAMXGU_XGU_MASK                 127
#define RAMXGU_XGU_BITNUM               0


 RAMSHL - RAM Shared Region Lower Boundary Register; 0x0000011E 
typedef union {
  byte Byte;
  struct {
    byte SHL0        1;                                        RAM Shared Region Lower Boundary Bit 0 
    byte SHL1        1;                                        RAM Shared Region Lower Boundary Bit 1 
    byte SHL2        1;                                        RAM Shared Region Lower Boundary Bit 2 
    byte SHL3        1;                                        RAM Shared Region Lower Boundary Bit 3 
    byte SHL4        1;                                        RAM Shared Region Lower Boundary Bit 4 
    byte SHL5        1;                                        RAM Shared Region Lower Boundary Bit 5 
    byte SHL6        1;                                        RAM Shared Region Lower Boundary Bit 6 
    byte             1; 
  } Bits;
  struct {
    byte grpSHL  7;
    byte         1;
  } MergedBits;
} RAMSHLSTR;
extern volatile RAMSHLSTR _RAMSHL @(REG_BASE + 0x0000011E);
#define RAMSHL                          _RAMSHL.Byte
#define RAMSHL_SHL0                     _RAMSHL.Bits.SHL0
#define RAMSHL_SHL1                     _RAMSHL.Bits.SHL1
#define RAMSHL_SHL2                     _RAMSHL.Bits.SHL2
#define RAMSHL_SHL3                     _RAMSHL.Bits.SHL3
#define RAMSHL_SHL4                     _RAMSHL.Bits.SHL4
#define RAMSHL_SHL5                     _RAMSHL.Bits.SHL5
#define RAMSHL_SHL6                     _RAMSHL.Bits.SHL6
#define RAMSHL_SHL                      _RAMSHL.MergedBits.grpSHL

#define RAMSHL_SHL0_MASK                1
#define RAMSHL_SHL1_MASK                2
#define RAMSHL_SHL2_MASK                4
#define RAMSHL_SHL3_MASK                8
#define RAMSHL_SHL4_MASK                16
#define RAMSHL_SHL5_MASK                32
#define RAMSHL_SHL6_MASK                64
#define RAMSHL_SHL_MASK                 127
#define RAMSHL_SHL_BITNUM               0


 RAMSHU - RAM Shared Region Upper Boundary Register; 0x0000011F 
typedef union {
  byte Byte;
  struct {
    byte SHU0        1;                                        RAM Shared Region Upper Boundary Bit 0 
    byte SHU1        1;                                        RAM Shared Region Upper Boundary Bit 1 
    byte SHU2        1;                                        RAM Shared Region Upper Boundary Bit 2 
    byte SHU3        1;                                        RAM Shared Region Upper Boundary Bit 3 
    byte SHU4        1;                                        RAM Shared Region Upper Boundary Bit 4 
    byte SHU5        1;                                        RAM Shared Region Upper Boundary Bit 5 
    byte SHU6        1;                                        RAM Shared Region Upper Boundary Bit 6 
    byte             1; 
  } Bits;
  struct {
    byte grpSHU  7;
    byte         1;
  } MergedBits;
} RAMSHUSTR;
extern volatile RAMSHUSTR _RAMSHU @(REG_BASE + 0x0000011F);
#define RAMSHU                          _RAMSHU.Byte
#define RAMSHU_SHU0                     _RAMSHU.Bits.SHU0
#define RAMSHU_SHU1                     _RAMSHU.Bits.SHU1
#define RAMSHU_SHU2                     _RAMSHU.Bits.SHU2
#define RAMSHU_SHU3                     _RAMSHU.Bits.SHU3
#define RAMSHU_SHU4                     _RAMSHU.Bits.SHU4
#define RAMSHU_SHU5                     _RAMSHU.Bits.SHU5
#define RAMSHU_SHU6                     _RAMSHU.Bits.SHU6
#define RAMSHU_SHU                      _RAMSHU.MergedBits.grpSHU

#define RAMSHU_SHU0_MASK                1
#define RAMSHU_SHU1_MASK                2
#define RAMSHU_SHU2_MASK                4
#define RAMSHU_SHU3_MASK                8
#define RAMSHU_SHU4_MASK                16
#define RAMSHU_SHU5_MASK                32
#define RAMSHU_SHU6_MASK                64
#define RAMSHU_SHU_MASK                 127
#define RAMSHU_SHU_BITNUM               0


 IVBR - Interrupt Vector Base Register; 0x00000121 
typedef union {
  byte Byte;
  struct {
    byte IVB_ADDR    8;                                        Interrupt vector base address bits 
  } Bits;
} IVBRSTR;
extern volatile IVBRSTR _IVBR @(REG_BASE + 0x00000121);
#define IVBR                            _IVBR.Byte
#define IVBR_IVB_ADDR                   _IVBR.Bits.IVB_ADDR

#define IVBR_IVB_ADDR_MASK              255
#define IVBR_IVB_ADDR_BITNUM            0


 INT_XGPRIO - XGATE Interrupt Priority Configuration Register; 0x00000126 
typedef union {
  byte Byte;
  struct {
    byte XILVL       3;                                        XGATE Interrupt Priority Level 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} INT_XGPRIOSTR;
extern volatile INT_XGPRIOSTR _INT_XGPRIO @(REG_BASE + 0x00000126);
#define INT_XGPRIO                      _INT_XGPRIO.Byte
#define INT_XGPRIO_XILVL                _INT_XGPRIO.Bits.XILVL

#define INT_XGPRIO_XILVL_MASK           7
#define INT_XGPRIO_XILVL_BITNUM         0


 INT_CFADDR - Interrupt Configuration Address Register; 0x00000127 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte INT_CFADDRGrp 4;                                      Interrupt Request Configuration Data Register select bits 
  } Bits;
} INT_CFADDRSTR;
extern volatile INT_CFADDRSTR _INT_CFADDR @(REG_BASE + 0x00000127);
#define INT_CFADDR                      _INT_CFADDR.Byte
#define INT_CFADDR_INT_CFADDRGrp        _INT_CFADDR.Bits.INT_CFADDRGrp

#define INT_CFADDR_INT_CFADDRGrp_MASK   240
#define INT_CFADDR_INT_CFADDRGrp_BITNUM 4


 INT_CFDATA0 - Interrupt Configuration Data Register 0; 0x00000128 
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     3;                                        Interrupt Request Priority Level Bits 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RQST        1;                                        XGATE Request Enable 
  } Bits;
} INT_CFDATA0STR;
extern volatile INT_CFDATA0STR _INT_CFDATA0 @(REG_BASE + 0x00000128);
#define INT_CFDATA0                     _INT_CFDATA0.Byte
#define INT_CFDATA0_PRIOLVL             _INT_CFDATA0.Bits.PRIOLVL
#define INT_CFDATA0_RQST                _INT_CFDATA0.Bits.RQST
 INT_CFDATA_ARR Access 8 INT_CFDATAx registers in an array 
#define INT_CFDATA_ARR                  ((volatile byte ) &INT_CFDATA0)

#define INT_CFDATA0_PRIOLVL_MASK        7
#define INT_CFDATA0_PRIOLVL_BITNUM      0
#define INT_CFDATA0_RQST_MASK           128


 INT_CFDATA1 - Interrupt Configuration Data Register 1; 0x00000129 
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     3;                                        Interrupt Request Priority Level Bits 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RQST        1;                                        XGATE Request Enable 
  } Bits;
} INT_CFDATA1STR;
extern volatile INT_CFDATA1STR _INT_CFDATA1 @(REG_BASE + 0x00000129);
#define INT_CFDATA1                     _INT_CFDATA1.Byte
#define INT_CFDATA1_PRIOLVL             _INT_CFDATA1.Bits.PRIOLVL
#define INT_CFDATA1_RQST                _INT_CFDATA1.Bits.RQST

#define INT_CFDATA1_PRIOLVL_MASK        7
#define INT_CFDATA1_PRIOLVL_BITNUM      0
#define INT_CFDATA1_RQST_MASK           128


 INT_CFDATA2 - Interrupt Configuration Data Register 2; 0x0000012A 
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     3;                                        Interrupt Request Priority Level Bits 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RQST        1;                                        XGATE Request Enable 
  } Bits;
} INT_CFDATA2STR;
extern volatile INT_CFDATA2STR _INT_CFDATA2 @(REG_BASE + 0x0000012A);
#define INT_CFDATA2                     _INT_CFDATA2.Byte
#define INT_CFDATA2_PRIOLVL             _INT_CFDATA2.Bits.PRIOLVL
#define INT_CFDATA2_RQST                _INT_CFDATA2.Bits.RQST

#define INT_CFDATA2_PRIOLVL_MASK        7
#define INT_CFDATA2_PRIOLVL_BITNUM      0
#define INT_CFDATA2_RQST_MASK           128


 INT_CFDATA3 - Interrupt Configuration Data Register 3; 0x0000012B 
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     3;                                        Interrupt Request Priority Level Bits 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RQST        1;                                        XGATE Request Enable 
  } Bits;
} INT_CFDATA3STR;
extern volatile INT_CFDATA3STR _INT_CFDATA3 @(REG_BASE + 0x0000012B);
#define INT_CFDATA3                     _INT_CFDATA3.Byte
#define INT_CFDATA3_PRIOLVL             _INT_CFDATA3.Bits.PRIOLVL
#define INT_CFDATA3_RQST                _INT_CFDATA3.Bits.RQST

#define INT_CFDATA3_PRIOLVL_MASK        7
#define INT_CFDATA3_PRIOLVL_BITNUM      0
#define INT_CFDATA3_RQST_MASK           128


 INT_CFDATA4 - Interrupt Configuration Data Register 4; 0x0000012C 
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     3;                                        Interrupt Request Priority Level Bits 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RQST        1;                                        XGATE Request Enable 
  } Bits;
} INT_CFDATA4STR;
extern volatile INT_CFDATA4STR _INT_CFDATA4 @(REG_BASE + 0x0000012C);
#define INT_CFDATA4                     _INT_CFDATA4.Byte
#define INT_CFDATA4_PRIOLVL             _INT_CFDATA4.Bits.PRIOLVL
#define INT_CFDATA4_RQST                _INT_CFDATA4.Bits.RQST

#define INT_CFDATA4_PRIOLVL_MASK        7
#define INT_CFDATA4_PRIOLVL_BITNUM      0
#define INT_CFDATA4_RQST_MASK           128


 INT_CFDATA5 - Interrupt Configuration Data Register 5; 0x0000012D 
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     3;                                        Interrupt Request Priority Level Bits 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RQST        1;                                        XGATE Request Enable 
  } Bits;
} INT_CFDATA5STR;
extern volatile INT_CFDATA5STR _INT_CFDATA5 @(REG_BASE + 0x0000012D);
#define INT_CFDATA5                     _INT_CFDATA5.Byte
#define INT_CFDATA5_PRIOLVL             _INT_CFDATA5.Bits.PRIOLVL
#define INT_CFDATA5_RQST                _INT_CFDATA5.Bits.RQST

#define INT_CFDATA5_PRIOLVL_MASK        7
#define INT_CFDATA5_PRIOLVL_BITNUM      0
#define INT_CFDATA5_RQST_MASK           128


 INT_CFDATA6 - Interrupt Configuration Data Register 6; 0x0000012E 
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     3;                                        Interrupt Request Priority Level Bits 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RQST        1;                                        XGATE Request Enable 
  } Bits;
} INT_CFDATA6STR;
extern volatile INT_CFDATA6STR _INT_CFDATA6 @(REG_BASE + 0x0000012E);
#define INT_CFDATA6                     _INT_CFDATA6.Byte
#define INT_CFDATA6_PRIOLVL             _INT_CFDATA6.Bits.PRIOLVL
#define INT_CFDATA6_RQST                _INT_CFDATA6.Bits.RQST

#define INT_CFDATA6_PRIOLVL_MASK        7
#define INT_CFDATA6_PRIOLVL_BITNUM      0
#define INT_CFDATA6_RQST_MASK           128


 INT_CFDATA7 - Interrupt Configuration Data Register 7; 0x0000012F 
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     3;                                        Interrupt Request Priority Level Bits 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte RQST        1;                                        XGATE Request Enable 
  } Bits;
} INT_CFDATA7STR;
extern volatile INT_CFDATA7STR _INT_CFDATA7 @(REG_BASE + 0x0000012F);
#define INT_CFDATA7                     _INT_CFDATA7.Byte
#define INT_CFDATA7_PRIOLVL             _INT_CFDATA7.Bits.PRIOLVL
#define INT_CFDATA7_RQST                _INT_CFDATA7.Bits.RQST

#define INT_CFDATA7_PRIOLVL_MASK        7
#define INT_CFDATA7_PRIOLVL_BITNUM      0
#define INT_CFDATA7_RQST_MASK           128


 SCI4BD - SCI 4 Baud Rate Register; 0x00000130 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     SCI4ASR1 - SCI 4 Alternative Status Register 1; 0x00000130 
    union {
      byte Byte;
      union { Several registers at the same address 
         SCI4ASR1 - SCI 4 Alternative Status Register 1; Several registers at the same address 
        union {
          struct {
            byte BKDIF       1;                                        Break Detect Interrupt Flag 
            byte BERRIF      1;                                        Bit Error Interrupt Flag 
            byte BERRV       1;                                        Bit Error Value 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte RXEDGIF     1;                                        Receive Input Active Edge Interrupt Flag 
          } Bits;
        } SCI4ASR1STR;
        #define SCI4ASR1                _SCI4BD.Overlap_STR.SCI4ASR1STR.Byte
        #define SCI4ASR1_BKDIF          _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4ASR1STR.Bits.BKDIF
        #define SCI4ASR1_BERRIF         _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4ASR1STR.Bits.BERRIF
        #define SCI4ASR1_BERRV          _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4ASR1STR.Bits.BERRV
        #define SCI4ASR1_RXEDGIF        _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4ASR1STR.Bits.RXEDGIF
        
        
        #define SCI4ASR1_BKDIF_MASK     1
        #define SCI4ASR1_BERRIF_MASK    2
        #define SCI4ASR1_BERRV_MASK     4
        #define SCI4ASR1_RXEDGIF_MASK   128
    
         SCI4BDH - SCI 4 Baud Rate Register High; Several registers at the same address 
        union {
          struct {
            byte SBR8        1;                                        SCI Baud Rate Bit 8 
            byte SBR9        1;                                        SCI Baud Rate Bit 9 
            byte SBR10       1;                                        SCI Baud Rate Bit 10 
            byte SBR11       1;                                        SCI Baud Rate Bit 11 
            byte SBR12       1;                                        SCI Baud Rate Bit 12 
            byte TNP0        1;                                        Transmitter Narrow Pulse Bit 0 
            byte TNP1        1;                                        Transmitter Narrow Pulse Bit 1 
            byte IREN        1;                                        Infrared Enable Bit 
          } Bits;
          struct {
            byte grpSBR_8 5;
            byte grpTNP 2;
            byte 1;
          } MergedBits;
        } SCI4BDHSTR;
        #define SCI4BDH                 _SCI4BD.Overlap_STR.SCI4ASR1STR.Byte
        #define SCI4BDH_SBR8            _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.Bits.SBR8
        #define SCI4BDH_SBR9            _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.Bits.SBR9
        #define SCI4BDH_SBR10           _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.Bits.SBR10
        #define SCI4BDH_SBR11           _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.Bits.SBR11
        #define SCI4BDH_SBR12           _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.Bits.SBR12
        #define SCI4BDH_TNP0            _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.Bits.TNP0
        #define SCI4BDH_TNP1            _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.Bits.TNP1
        #define SCI4BDH_IREN            _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.Bits.IREN
        
        #define SCI4BDH_SBR_8           _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.MergedBits.grpSBR_8
        #define SCI4BDH_TNP             _SCI4BD.Overlap_STR.SCI4ASR1STR.SameAddr_STR.SCI4BDHSTR.MergedBits.grpTNP
        #define SCI4BDH_SBR             SCI4BDH_SBR_8
        
        #define SCI4BDH_SBR8_MASK       1
        #define SCI4BDH_SBR9_MASK       2
        #define SCI4BDH_SBR10_MASK      4
        #define SCI4BDH_SBR11_MASK      8
        #define SCI4BDH_SBR12_MASK      16
        #define SCI4BDH_TNP0_MASK       32
        #define SCI4BDH_TNP1_MASK       64
        #define SCI4BDH_IREN_MASK       128
        #define SCI4BDH_SBR_8_MASK      31
        #define SCI4BDH_SBR_8_BITNUM    0
        #define SCI4BDH_TNP_MASK        96
        #define SCI4BDH_TNP_BITNUM      5
    
      } SameAddr_STR; Several registers at the same address 
    
    } SCI4ASR1STR;
    


     SCI4ACR1 - SCI 4 Alternative Control Register 1; 0x00000131 
    union {
      byte Byte;
      union { Several registers at the same address 
         SCI4ACR1 - SCI 4 Alternative Control Register 1; Several registers at the same address 
        union {
          struct {
            byte BKDIE       1;                                        Break Detect Interrupt Enable 
            byte BERRIE      1;                                        Bit Error Interrupt Enable 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte             1; 
            byte RXEDGIE     1;                                        Receive Input Active Edge Interrupt Enable 
          } Bits;
        } SCI4ACR1STR;
        #define SCI4ACR1                _SCI4BD.Overlap_STR.SCI4ACR1STR.Byte
        #define SCI4ACR1_BKDIE          _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4ACR1STR.Bits.BKDIE
        #define SCI4ACR1_BERRIE         _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4ACR1STR.Bits.BERRIE
        #define SCI4ACR1_RXEDGIE        _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4ACR1STR.Bits.RXEDGIE
        
        
        #define SCI4ACR1_BKDIE_MASK     1
        #define SCI4ACR1_BERRIE_MASK    2
        #define SCI4ACR1_RXEDGIE_MASK   128
    
         SCI4BDL - SCI 4 Baud Rate Register Low; Several registers at the same address 
        union {
          struct {
            byte SBR0        1;                                        SCI Baud Rate Bit 0 
            byte SBR1        1;                                        SCI Baud Rate Bit 1 
            byte SBR2        1;                                        SCI Baud Rate Bit 2 
            byte SBR3        1;                                        SCI Baud Rate Bit 3 
            byte SBR4        1;                                        SCI Baud Rate Bit 4 
            byte SBR5        1;                                        SCI Baud Rate Bit 5 
            byte SBR6        1;                                        SCI Baud Rate Bit 6 
            byte SBR7        1;                                        SCI Baud Rate Bit 7 
          } Bits;
        } SCI4BDLSTR;
        #define SCI4BDL                 _SCI4BD.Overlap_STR.SCI4ACR1STR.Byte
        #define SCI4BDL_SBR0            _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4BDLSTR.Bits.SBR0
        #define SCI4BDL_SBR1            _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4BDLSTR.Bits.SBR1
        #define SCI4BDL_SBR2            _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4BDLSTR.Bits.SBR2
        #define SCI4BDL_SBR3            _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4BDLSTR.Bits.SBR3
        #define SCI4BDL_SBR4            _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4BDLSTR.Bits.SBR4
        #define SCI4BDL_SBR5            _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4BDLSTR.Bits.SBR5
        #define SCI4BDL_SBR6            _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4BDLSTR.Bits.SBR6
        #define SCI4BDL_SBR7            _SCI4BD.Overlap_STR.SCI4ACR1STR.SameAddr_STR.SCI4BDLSTR.Bits.SBR7
        
        
        #define SCI4BDL_SBR0_MASK       1
        #define SCI4BDL_SBR1_MASK       2
        #define SCI4BDL_SBR2_MASK       4
        #define SCI4BDL_SBR3_MASK       8
        #define SCI4BDL_SBR4_MASK       16
        #define SCI4BDL_SBR5_MASK       32
        #define SCI4BDL_SBR6_MASK       64
        #define SCI4BDL_SBR7_MASK       128
    
      } SameAddr_STR; Several registers at the same address 
    
    } SCI4ACR1STR;
    

  } Overlap_STR;

  struct {
    word SBR0        1;                                        SCI Baud Rate Bit 0 
    word SBR1        1;                                        SCI Baud Rate Bit 1 
    word SBR2        1;                                        SCI Baud Rate Bit 2 
    word SBR3        1;                                        SCI Baud Rate Bit 3 
    word SBR4        1;                                        SCI Baud Rate Bit 4 
    word SBR5        1;                                        SCI Baud Rate Bit 5 
    word SBR6        1;                                        SCI Baud Rate Bit 6 
    word SBR7        1;                                        SCI Baud Rate Bit 7 
    word SBR8        1;                                        SCI Baud Rate Bit 8 
    word SBR9        1;                                        SCI Baud Rate Bit 9 
    word SBR10       1;                                        SCI Baud Rate Bit 10 
    word SBR11       1;                                        SCI Baud Rate Bit 11 
    word SBR12       1;                                        SCI Baud Rate Bit 12 
    word TNP0        1;                                        Transmitter Narrow Pulse Bit 0 
    word TNP1        1;                                        Transmitter Narrow Pulse Bit 1 
    word IREN        1;                                        Infrared Enable Bit 
  } Bits;
  struct {
    word grpSBR  13;
    word grpTNP  2;
    word         1;
  } MergedBits;
} SCI4BDSTR;
extern volatile SCI4BDSTR _SCI4BD @(REG_BASE + 0x00000130);
#define SCI4BD                          _SCI4BD.Word
#define SCI4BD_SBR0                     _SCI4BD.Bits.SBR0
#define SCI4BD_SBR1                     _SCI4BD.Bits.SBR1
#define SCI4BD_SBR2                     _SCI4BD.Bits.SBR2
#define SCI4BD_SBR3                     _SCI4BD.Bits.SBR3
#define SCI4BD_SBR4                     _SCI4BD.Bits.SBR4
#define SCI4BD_SBR5                     _SCI4BD.Bits.SBR5
#define SCI4BD_SBR6                     _SCI4BD.Bits.SBR6
#define SCI4BD_SBR7                     _SCI4BD.Bits.SBR7
#define SCI4BD_SBR8                     _SCI4BD.Bits.SBR8
#define SCI4BD_SBR9                     _SCI4BD.Bits.SBR9
#define SCI4BD_SBR10                    _SCI4BD.Bits.SBR10
#define SCI4BD_SBR11                    _SCI4BD.Bits.SBR11
#define SCI4BD_SBR12                    _SCI4BD.Bits.SBR12
#define SCI4BD_TNP0                     _SCI4BD.Bits.TNP0
#define SCI4BD_TNP1                     _SCI4BD.Bits.TNP1
#define SCI4BD_IREN                     _SCI4BD.Bits.IREN
#define SCI4BD_SBR                      _SCI4BD.MergedBits.grpSBR
#define SCI4BD_TNP                      _SCI4BD.MergedBits.grpTNP

#define SCI4BD_SBR0_MASK                1
#define SCI4BD_SBR1_MASK                2
#define SCI4BD_SBR2_MASK                4
#define SCI4BD_SBR3_MASK                8
#define SCI4BD_SBR4_MASK                16
#define SCI4BD_SBR5_MASK                32
#define SCI4BD_SBR6_MASK                64
#define SCI4BD_SBR7_MASK                128
#define SCI4BD_SBR8_MASK                256
#define SCI4BD_SBR9_MASK                512
#define SCI4BD_SBR10_MASK               1024
#define SCI4BD_SBR11_MASK               2048
#define SCI4BD_SBR12_MASK               4096
#define SCI4BD_TNP0_MASK                8192
#define SCI4BD_TNP1_MASK                16384
#define SCI4BD_IREN_MASK                32768
#define SCI4BD_SBR_MASK                 8191
#define SCI4BD_SBR_BITNUM               0
#define SCI4BD_TNP_MASK                 24576
#define SCI4BD_TNP_BITNUM               13


 SCI4ACR2 - SCI 4 Alternative Control Register 2; 0x00000132 
typedef union {
  byte Byte;
  union { Several registers at the same address 
     SCI4ACR2 - SCI 4 Alternative Control Register 2; Several registers at the same address 
    union {
      struct {
        byte BKDFE       1;                                        Break Detect Feature Enable 
        byte BERRM0      1;                                        Bit Error Mode Bit 0 
        byte BERRM1      1;                                        Bit Error Mode Bit 1 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
      } Bits;
      struct {
        byte     1;
        byte grpBERRM 2;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } SCI4ACR2STR;
    #define SCI4ACR2                    _SCI4ACR2.Byte
    #define SCI4ACR2_BKDFE              _SCI4ACR2.SameAddr_STR.SCI4ACR2STR.Bits.BKDFE
    #define SCI4ACR2_BERRM0             _SCI4ACR2.SameAddr_STR.SCI4ACR2STR.Bits.BERRM0
    #define SCI4ACR2_BERRM1             _SCI4ACR2.SameAddr_STR.SCI4ACR2STR.Bits.BERRM1
    
    #define SCI4ACR2_BERRM              _SCI4ACR2.SameAddr_STR.SCI4ACR2STR.MergedBits.grpBERRM
    
    #define SCI4ACR2_BKDFE_MASK         1
    #define SCI4ACR2_BERRM0_MASK        2
    #define SCI4ACR2_BERRM1_MASK        4
    #define SCI4ACR2_BERRM_MASK         6
    #define SCI4ACR2_BERRM_BITNUM       1

     SCI4CR1 - SCI 4 Control Register 1; Several registers at the same address 
    union {
      struct {
        byte PT          1;                                        Parity Type Bit 
        byte PE          1;                                        Parity Enable Bit 
        byte ILT         1;                                        Idle Line Type Bit 
        byte WAKE        1;                                        Wakeup Condition Bit 
        byte M           1;                                        Data Format Mode Bit 
        byte RSRC        1;                                        Receiver Source Bit 
        byte SCISWAI     1;                                        SCI Stop in Wait Mode Bit 
        byte LOOPS       1;                                        Loop Select Bit 
      } Bits;
    } SCI4CR1STR;
    #define SCI4CR1                     _SCI4ACR2.Byte
    #define SCI4CR1_PT                  _SCI4ACR2.SameAddr_STR.SCI4CR1STR.Bits.PT
    #define SCI4CR1_PE                  _SCI4ACR2.SameAddr_STR.SCI4CR1STR.Bits.PE
    #define SCI4CR1_ILT                 _SCI4ACR2.SameAddr_STR.SCI4CR1STR.Bits.ILT
    #define SCI4CR1_WAKE                _SCI4ACR2.SameAddr_STR.SCI4CR1STR.Bits.WAKE
    #define SCI4CR1_M                   _SCI4ACR2.SameAddr_STR.SCI4CR1STR.Bits.M
    #define SCI4CR1_RSRC                _SCI4ACR2.SameAddr_STR.SCI4CR1STR.Bits.RSRC
    #define SCI4CR1_SCISWAI             _SCI4ACR2.SameAddr_STR.SCI4CR1STR.Bits.SCISWAI
    #define SCI4CR1_LOOPS               _SCI4ACR2.SameAddr_STR.SCI4CR1STR.Bits.LOOPS
    
    
    #define SCI4CR1_PT_MASK             1
    #define SCI4CR1_PE_MASK             2
    #define SCI4CR1_ILT_MASK            4
    #define SCI4CR1_WAKE_MASK           8
    #define SCI4CR1_M_MASK              16
    #define SCI4CR1_RSRC_MASK           32
    #define SCI4CR1_SCISWAI_MASK        64
    #define SCI4CR1_LOOPS_MASK          128

  } SameAddr_STR; Several registers at the same address 

} SCI4ACR2STR;
extern volatile SCI4ACR2STR _SCI4ACR2 @(REG_BASE + 0x00000132);



 SCI4CR2 - SCI 4 Control Register 2; 0x00000133 
typedef union {
  byte Byte;
  struct {
    byte SBK         1;                                        Send Break Bit 
    byte RWU         1;                                        Receiver Wakeup Bit 
    byte RE          1;                                        Receiver Enable Bit 
    byte TE          1;                                        Transmitter Enable Bit 
    byte ILIE        1;                                        Idle Line Interrupt Enable Bit 
    byte RIE         1;                                        Receiver Full Interrupt Enable Bit 
    byte TCIE        1;                                        Transmission Complete Interrupt Enable Bit 
    byte SCTIE       1;                                        Transmitter Interrupt Enable Bit 
  } Bits;
} SCI4CR2STR;
extern volatile SCI4CR2STR _SCI4CR2 @(REG_BASE + 0x00000133);
#define SCI4CR2                         _SCI4CR2.Byte
#define SCI4CR2_SBK                     _SCI4CR2.Bits.SBK
#define SCI4CR2_RWU                     _SCI4CR2.Bits.RWU
#define SCI4CR2_RE                      _SCI4CR2.Bits.RE
#define SCI4CR2_TE                      _SCI4CR2.Bits.TE
#define SCI4CR2_ILIE                    _SCI4CR2.Bits.ILIE
#define SCI4CR2_RIE                     _SCI4CR2.Bits.RIE
#define SCI4CR2_TCIE                    _SCI4CR2.Bits.TCIE
#define SCI4CR2_SCTIE                   _SCI4CR2.Bits.SCTIE

#define SCI4CR2_SBK_MASK                1
#define SCI4CR2_RWU_MASK                2
#define SCI4CR2_RE_MASK                 4
#define SCI4CR2_TE_MASK                 8
#define SCI4CR2_ILIE_MASK               16
#define SCI4CR2_RIE_MASK                32
#define SCI4CR2_TCIE_MASK               64
#define SCI4CR2_SCTIE_MASK              128


 SCI4SR1 - SCI 4 Status Register 1; 0x00000134 
typedef union {
  byte Byte;
  struct {
    byte PF          1;                                        Parity Error Flag 
    byte FE          1;                                        Framing Error Flag 
    byte NF          1;                                        Noise Flag 
    byte OR          1;                                        Overrun Flag 
    byte IDLE        1;                                        Idle Line Flag 
    byte RDRF        1;                                        Receive Data Register Full Flag 
    byte TC          1;                                        Transmit Complete Flag 
    byte TDRE        1;                                        Transmit Data Register Empty Flag 
  } Bits;
} SCI4SR1STR;
extern volatile SCI4SR1STR _SCI4SR1 @(REG_BASE + 0x00000134);
#define SCI4SR1                         _SCI4SR1.Byte
#define SCI4SR1_PF                      _SCI4SR1.Bits.PF
#define SCI4SR1_FE                      _SCI4SR1.Bits.FE
#define SCI4SR1_NF                      _SCI4SR1.Bits.NF
#define SCI4SR1_OR                      _SCI4SR1.Bits.OR
#define SCI4SR1_IDLE                    _SCI4SR1.Bits.IDLE
#define SCI4SR1_RDRF                    _SCI4SR1.Bits.RDRF
#define SCI4SR1_TC                      _SCI4SR1.Bits.TC
#define SCI4SR1_TDRE                    _SCI4SR1.Bits.TDRE

#define SCI4SR1_PF_MASK                 1
#define SCI4SR1_FE_MASK                 2
#define SCI4SR1_NF_MASK                 4
#define SCI4SR1_OR_MASK                 8
#define SCI4SR1_IDLE_MASK               16
#define SCI4SR1_RDRF_MASK               32
#define SCI4SR1_TC_MASK                 64
#define SCI4SR1_TDRE_MASK               128


 SCI4SR2 - SCI 4 Status Register 2; 0x00000135 
typedef union {
  byte Byte;
  struct {
    byte RAF         1;                                        Receiver Active Flag 
    byte TXDIR       1;                                        Transmitter pin data direction in Single-Wire mode 
    byte BRK13       1;                                        Break Transmit character length 
    byte RXPOL       1;                                        Receive Polarity 
    byte TXPOL       1;                                        Transmit Polarity 
    byte             1; 
    byte             1; 
    byte AMAP        1;                                        Alternative Map 
  } Bits;
} SCI4SR2STR;
extern volatile SCI4SR2STR _SCI4SR2 @(REG_BASE + 0x00000135);
#define SCI4SR2                         _SCI4SR2.Byte
#define SCI4SR2_RAF                     _SCI4SR2.Bits.RAF
#define SCI4SR2_TXDIR                   _SCI4SR2.Bits.TXDIR
#define SCI4SR2_BRK13                   _SCI4SR2.Bits.BRK13
#define SCI4SR2_RXPOL                   _SCI4SR2.Bits.RXPOL
#define SCI4SR2_TXPOL                   _SCI4SR2.Bits.TXPOL
#define SCI4SR2_AMAP                    _SCI4SR2.Bits.AMAP

#define SCI4SR2_RAF_MASK                1
#define SCI4SR2_TXDIR_MASK              2
#define SCI4SR2_BRK13_MASK              4
#define SCI4SR2_RXPOL_MASK              8
#define SCI4SR2_TXPOL_MASK              16
#define SCI4SR2_AMAP_MASK               128


 SCI4DRH - SCI 4 Data Register High; 0x00000136 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte T8          1;                                        Transmit Bit 8 
    byte R8          1;                                        Received Bit 8 
  } Bits;
} SCI4DRHSTR;
extern volatile SCI4DRHSTR _SCI4DRH @(REG_BASE + 0x00000136);
#define SCI4DRH                         _SCI4DRH.Byte
#define SCI4DRH_T8                      _SCI4DRH.Bits.T8
#define SCI4DRH_R8                      _SCI4DRH.Bits.R8

#define SCI4DRH_T8_MASK                 64
#define SCI4DRH_R8_MASK                 128


 SCI4DRL - SCI 4 Data Register Low; 0x00000137 
typedef union {
  byte Byte;
  struct {
    byte R0_T0       1;                                        Received bit 0 or Transmit bit 0 
    byte R1_T1       1;                                        Received bit 1 or Transmit bit 1 
    byte R2_T2       1;                                        Received bit 2 or Transmit bit 2 
    byte R3_T3       1;                                        Received bit 3 or Transmit bit 3 
    byte R4_T4       1;                                        Received bit 4 or Transmit bit 4 
    byte R5_T5       1;                                        Received bit 5 or Transmit bit 5 
    byte R6_T6       1;                                        Received bit 6 or Transmit bit 6 
    byte R7_T7       1;                                        Received bit 7 or Transmit bit 7 
  } Bits;
} SCI4DRLSTR;
extern volatile SCI4DRLSTR _SCI4DRL @(REG_BASE + 0x00000137);
#define SCI4DRL                         _SCI4DRL.Byte
#define SCI4DRL_R0_T0                   _SCI4DRL.Bits.R0_T0
#define SCI4DRL_R1_T1                   _SCI4DRL.Bits.R1_T1
#define SCI4DRL_R2_T2                   _SCI4DRL.Bits.R2_T2
#define SCI4DRL_R3_T3                   _SCI4DRL.Bits.R3_T3
#define SCI4DRL_R4_T4                   _SCI4DRL.Bits.R4_T4
#define SCI4DRL_R5_T5                   _SCI4DRL.Bits.R5_T5
#define SCI4DRL_R6_T6                   _SCI4DRL.Bits.R6_T6
#define SCI4DRL_R7_T7                   _SCI4DRL.Bits.R7_T7

#define SCI4DRL_R0_T0_MASK              1
#define SCI4DRL_R1_T1_MASK              2
#define SCI4DRL_R2_T2_MASK              4
#define SCI4DRL_R3_T3_MASK              8
#define SCI4DRL_R4_T4_MASK              16
#define SCI4DRL_R5_T5_MASK              32
#define SCI4DRL_R6_T6_MASK              64
#define SCI4DRL_R7_T7_MASK              128


 CAN0CTL0 - MSCAN 0 Control 0 Register; 0x00000140 
typedef union {
  byte Byte;
  struct {
    byte INITRQ      1;                                        Initialization Mode Request 
    byte SLPRQ       1;                                        Sleep Mode Request 
    byte WUPE        1;                                        Wake-Up Enable 
    byte TIME        1;                                        Timer Enable 
    byte SYNCH       1;                                        Synchronized Status 
    byte CSWAI       1;                                        CAN Stops in Wait Mode 
    byte RXACT       1;                                        Receiver Active Status 
    byte RXFRM       1;                                        Received Frame Flag 
  } Bits;
} CAN0CTL0STR;
extern volatile CAN0CTL0STR _CAN0CTL0 @(REG_BASE + 0x00000140);
#define CAN0CTL0                        _CAN0CTL0.Byte
#define CAN0CTL0_INITRQ                 _CAN0CTL0.Bits.INITRQ
#define CAN0CTL0_SLPRQ                  _CAN0CTL0.Bits.SLPRQ
#define CAN0CTL0_WUPE                   _CAN0CTL0.Bits.WUPE
#define CAN0CTL0_TIME                   _CAN0CTL0.Bits.TIME
#define CAN0CTL0_SYNCH                  _CAN0CTL0.Bits.SYNCH
#define CAN0CTL0_CSWAI                  _CAN0CTL0.Bits.CSWAI
#define CAN0CTL0_RXACT                  _CAN0CTL0.Bits.RXACT
#define CAN0CTL0_RXFRM                  _CAN0CTL0.Bits.RXFRM
 CAN0CTL_ARR Access 2 CAN0CTLx registers in an array 
#define CAN0CTL_ARR                     ((volatile byte ) &CAN0CTL0)

#define CAN0CTL0_INITRQ_MASK            1
#define CAN0CTL0_SLPRQ_MASK             2
#define CAN0CTL0_WUPE_MASK              4
#define CAN0CTL0_TIME_MASK              8
#define CAN0CTL0_SYNCH_MASK             16
#define CAN0CTL0_CSWAI_MASK             32
#define CAN0CTL0_RXACT_MASK             64
#define CAN0CTL0_RXFRM_MASK             128


 CAN0CTL1 - MSCAN 0 Control 1 Register; 0x00000141 
typedef union {
  byte Byte;
  struct {
    byte INITAK      1;                                        Initialization Mode Acknowledge 
    byte SLPAK       1;                                        Sleep Mode Acknowledge 
    byte WUPM        1;                                        Wake-Up Mode 
    byte BORM        1;                                        Bus-Off Recovery Mode 
    byte LISTEN      1;                                        Listen Only Mode 
    byte LOOPB       1;                                        Loop Back Self Test Mode 
    byte CLKSRC      1;                                        MSCAN 0 Clock Source 
    byte CANE        1;                                        MSCAN 0 Enable 
  } Bits;
} CAN0CTL1STR;
extern volatile CAN0CTL1STR _CAN0CTL1 @(REG_BASE + 0x00000141);
#define CAN0CTL1                        _CAN0CTL1.Byte
#define CAN0CTL1_INITAK                 _CAN0CTL1.Bits.INITAK
#define CAN0CTL1_SLPAK                  _CAN0CTL1.Bits.SLPAK
#define CAN0CTL1_WUPM                   _CAN0CTL1.Bits.WUPM
#define CAN0CTL1_BORM                   _CAN0CTL1.Bits.BORM
#define CAN0CTL1_LISTEN                 _CAN0CTL1.Bits.LISTEN
#define CAN0CTL1_LOOPB                  _CAN0CTL1.Bits.LOOPB
#define CAN0CTL1_CLKSRC                 _CAN0CTL1.Bits.CLKSRC
#define CAN0CTL1_CANE                   _CAN0CTL1.Bits.CANE

#define CAN0CTL1_INITAK_MASK            1
#define CAN0CTL1_SLPAK_MASK             2
#define CAN0CTL1_WUPM_MASK              4
#define CAN0CTL1_BORM_MASK              8
#define CAN0CTL1_LISTEN_MASK            16
#define CAN0CTL1_LOOPB_MASK             32
#define CAN0CTL1_CLKSRC_MASK            64
#define CAN0CTL1_CANE_MASK              128


 CAN0BTR0 - MSCAN 0 Bus Timing Register 0; 0x00000142 
typedef union {
  byte Byte;
  struct {
    byte BRP0        1;                                        Baud Rate Prescaler 0 
    byte BRP1        1;                                        Baud Rate Prescaler 1 
    byte BRP2        1;                                        Baud Rate Prescaler 2 
    byte BRP3        1;                                        Baud Rate Prescaler 3 
    byte BRP4        1;                                        Baud Rate Prescaler 4 
    byte BRP5        1;                                        Baud Rate Prescaler 5 
    byte SJW0        1;                                        Synchronization Jump Width 0 
    byte SJW1        1;                                        Synchronization Jump Width 1 
  } Bits;
  struct {
    byte grpBRP  6;
    byte grpSJW  2;
  } MergedBits;
} CAN0BTR0STR;
extern volatile CAN0BTR0STR _CAN0BTR0 @(REG_BASE + 0x00000142);
#define CAN0BTR0                        _CAN0BTR0.Byte
#define CAN0BTR0_BRP0                   _CAN0BTR0.Bits.BRP0
#define CAN0BTR0_BRP1                   _CAN0BTR0.Bits.BRP1
#define CAN0BTR0_BRP2                   _CAN0BTR0.Bits.BRP2
#define CAN0BTR0_BRP3                   _CAN0BTR0.Bits.BRP3
#define CAN0BTR0_BRP4                   _CAN0BTR0.Bits.BRP4
#define CAN0BTR0_BRP5                   _CAN0BTR0.Bits.BRP5
#define CAN0BTR0_SJW0                   _CAN0BTR0.Bits.SJW0
#define CAN0BTR0_SJW1                   _CAN0BTR0.Bits.SJW1
 CAN0BTR_ARR Access 2 CAN0BTRx registers in an array 
#define CAN0BTR_ARR                     ((volatile byte ) &CAN0BTR0)
#define CAN0BTR0_BRP                    _CAN0BTR0.MergedBits.grpBRP
#define CAN0BTR0_SJW                    _CAN0BTR0.MergedBits.grpSJW

#define CAN0BTR0_BRP0_MASK              1
#define CAN0BTR0_BRP1_MASK              2
#define CAN0BTR0_BRP2_MASK              4
#define CAN0BTR0_BRP3_MASK              8
#define CAN0BTR0_BRP4_MASK              16
#define CAN0BTR0_BRP5_MASK              32
#define CAN0BTR0_SJW0_MASK              64
#define CAN0BTR0_SJW1_MASK              128
#define CAN0BTR0_BRP_MASK               63
#define CAN0BTR0_BRP_BITNUM             0
#define CAN0BTR0_SJW_MASK               192
#define CAN0BTR0_SJW_BITNUM             6


 CAN0BTR1 - MSCAN 0 Bus Timing Register 1; 0x00000143 
typedef union {
  byte Byte;
  struct {
    byte TSEG10      1;                                        Time Segment 10 
    byte TSEG11      1;                                        Time Segment 11 
    byte TSEG12      1;                                        Time Segment 12 
    byte TSEG13      1;                                        Time Segment 13 
    byte TSEG20      1;                                        Time Segment 20 
    byte TSEG21      1;                                        Time Segment 21 
    byte TSEG22      1;                                        Time Segment 22 
    byte SAMP        1;                                        Sampling 
  } Bits;
  struct {
    byte grpTSEG_10 4;
    byte grpTSEG_20 3;
    byte         1;
  } MergedBits;
} CAN0BTR1STR;
extern volatile CAN0BTR1STR _CAN0BTR1 @(REG_BASE + 0x00000143);
#define CAN0BTR1                        _CAN0BTR1.Byte
#define CAN0BTR1_TSEG10                 _CAN0BTR1.Bits.TSEG10
#define CAN0BTR1_TSEG11                 _CAN0BTR1.Bits.TSEG11
#define CAN0BTR1_TSEG12                 _CAN0BTR1.Bits.TSEG12
#define CAN0BTR1_TSEG13                 _CAN0BTR1.Bits.TSEG13
#define CAN0BTR1_TSEG20                 _CAN0BTR1.Bits.TSEG20
#define CAN0BTR1_TSEG21                 _CAN0BTR1.Bits.TSEG21
#define CAN0BTR1_TSEG22                 _CAN0BTR1.Bits.TSEG22
#define CAN0BTR1_SAMP                   _CAN0BTR1.Bits.SAMP
#define CAN0BTR1_TSEG_10                _CAN0BTR1.MergedBits.grpTSEG_10
#define CAN0BTR1_TSEG_20                _CAN0BTR1.MergedBits.grpTSEG_20
#define CAN0BTR1_TSEG                   CAN0BTR1_TSEG_10

#define CAN0BTR1_TSEG10_MASK            1
#define CAN0BTR1_TSEG11_MASK            2
#define CAN0BTR1_TSEG12_MASK            4
#define CAN0BTR1_TSEG13_MASK            8
#define CAN0BTR1_TSEG20_MASK            16
#define CAN0BTR1_TSEG21_MASK            32
#define CAN0BTR1_TSEG22_MASK            64
#define CAN0BTR1_SAMP_MASK              128
#define CAN0BTR1_TSEG_10_MASK           15
#define CAN0BTR1_TSEG_10_BITNUM         0
#define CAN0BTR1_TSEG_20_MASK           112
#define CAN0BTR1_TSEG_20_BITNUM         4


 CAN0RFLG - MSCAN 0 Receiver Flag Register; 0x00000144 
typedef union {
  byte Byte;
  struct {
    byte RXF         1;                                        Receive Buffer Full 
    byte OVRIF       1;                                        Overrun Interrupt Flag 
    byte TSTAT0      1;                                        Transmitter Status Bit 0 
    byte TSTAT1      1;                                        Transmitter Status Bit 1 
    byte RSTAT0      1;                                        Receiver Status Bit 0 
    byte RSTAT1      1;                                        Receiver Status Bit 1 
    byte CSCIF       1;                                        CAN Status Change Interrupt Flag 
    byte WUPIF       1;                                        Wake-up Interrupt Flag 
  } Bits;
  struct {
    byte         1;
    byte         1;
    byte grpTSTAT 2;
    byte grpRSTAT 2;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0RFLGSTR;
extern volatile CAN0RFLGSTR _CAN0RFLG @(REG_BASE + 0x00000144);
#define CAN0RFLG                        _CAN0RFLG.Byte
#define CAN0RFLG_RXF                    _CAN0RFLG.Bits.RXF
#define CAN0RFLG_OVRIF                  _CAN0RFLG.Bits.OVRIF
#define CAN0RFLG_TSTAT0                 _CAN0RFLG.Bits.TSTAT0
#define CAN0RFLG_TSTAT1                 _CAN0RFLG.Bits.TSTAT1
#define CAN0RFLG_RSTAT0                 _CAN0RFLG.Bits.RSTAT0
#define CAN0RFLG_RSTAT1                 _CAN0RFLG.Bits.RSTAT1
#define CAN0RFLG_CSCIF                  _CAN0RFLG.Bits.CSCIF
#define CAN0RFLG_WUPIF                  _CAN0RFLG.Bits.WUPIF
#define CAN0RFLG_TSTAT                  _CAN0RFLG.MergedBits.grpTSTAT
#define CAN0RFLG_RSTAT                  _CAN0RFLG.MergedBits.grpRSTAT

#define CAN0RFLG_RXF_MASK               1
#define CAN0RFLG_OVRIF_MASK             2
#define CAN0RFLG_TSTAT0_MASK            4
#define CAN0RFLG_TSTAT1_MASK            8
#define CAN0RFLG_RSTAT0_MASK            16
#define CAN0RFLG_RSTAT1_MASK            32
#define CAN0RFLG_CSCIF_MASK             64
#define CAN0RFLG_WUPIF_MASK             128
#define CAN0RFLG_TSTAT_MASK             12
#define CAN0RFLG_TSTAT_BITNUM           2
#define CAN0RFLG_RSTAT_MASK             48
#define CAN0RFLG_RSTAT_BITNUM           4


 CAN0RIER - MSCAN 0 Receiver Interrupt Enable Register; 0x00000145 
typedef union {
  byte Byte;
  struct {
    byte RXFIE       1;                                        Receiver Full Interrupt Enable 
    byte OVRIE       1;                                        Overrun Interrupt Enable 
    byte TSTATE0     1;                                        Transmitter Status Change Enable 0 
    byte TSTATE1     1;                                        Transmitter Status Change Enable 1 
    byte RSTATE0     1;                                        Receiver Status Change Enable 0 
    byte RSTATE1     1;                                        Receiver Status Change Enable 1 
    byte CSCIE       1;                                        CAN Status Change Interrupt Enable 
    byte WUPIE       1;                                        Wake-up Interrupt Enable 
  } Bits;
  struct {
    byte         1;
    byte         1;
    byte grpTSTATE 2;
    byte grpRSTATE 2;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0RIERSTR;
extern volatile CAN0RIERSTR _CAN0RIER @(REG_BASE + 0x00000145);
#define CAN0RIER                        _CAN0RIER.Byte
#define CAN0RIER_RXFIE                  _CAN0RIER.Bits.RXFIE
#define CAN0RIER_OVRIE                  _CAN0RIER.Bits.OVRIE
#define CAN0RIER_TSTATE0                _CAN0RIER.Bits.TSTATE0
#define CAN0RIER_TSTATE1                _CAN0RIER.Bits.TSTATE1
#define CAN0RIER_RSTATE0                _CAN0RIER.Bits.RSTATE0
#define CAN0RIER_RSTATE1                _CAN0RIER.Bits.RSTATE1
#define CAN0RIER_CSCIE                  _CAN0RIER.Bits.CSCIE
#define CAN0RIER_WUPIE                  _CAN0RIER.Bits.WUPIE
#define CAN0RIER_TSTATE                 _CAN0RIER.MergedBits.grpTSTATE
#define CAN0RIER_RSTATE                 _CAN0RIER.MergedBits.grpRSTATE

#define CAN0RIER_RXFIE_MASK             1
#define CAN0RIER_OVRIE_MASK             2
#define CAN0RIER_TSTATE0_MASK           4
#define CAN0RIER_TSTATE1_MASK           8
#define CAN0RIER_RSTATE0_MASK           16
#define CAN0RIER_RSTATE1_MASK           32
#define CAN0RIER_CSCIE_MASK             64
#define CAN0RIER_WUPIE_MASK             128
#define CAN0RIER_TSTATE_MASK            12
#define CAN0RIER_TSTATE_BITNUM          2
#define CAN0RIER_RSTATE_MASK            48
#define CAN0RIER_RSTATE_BITNUM          4


 CAN0TFLG - MSCAN 0 Transmitter Flag Register; 0x00000146 
typedef union {
  byte Byte;
  struct {
    byte TXE0        1;                                        Transmitter Buffer Empty 0 
    byte TXE1        1;                                        Transmitter Buffer Empty 1 
    byte TXE2        1;                                        Transmitter Buffer Empty 2 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpTXE  3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0TFLGSTR;
extern volatile CAN0TFLGSTR _CAN0TFLG @(REG_BASE + 0x00000146);
#define CAN0TFLG                        _CAN0TFLG.Byte
#define CAN0TFLG_TXE0                   _CAN0TFLG.Bits.TXE0
#define CAN0TFLG_TXE1                   _CAN0TFLG.Bits.TXE1
#define CAN0TFLG_TXE2                   _CAN0TFLG.Bits.TXE2
#define CAN0TFLG_TXE                    _CAN0TFLG.MergedBits.grpTXE

#define CAN0TFLG_TXE0_MASK              1
#define CAN0TFLG_TXE1_MASK              2
#define CAN0TFLG_TXE2_MASK              4
#define CAN0TFLG_TXE_MASK               7
#define CAN0TFLG_TXE_BITNUM             0


 CAN0TIER - MSCAN 0 Transmitter Interrupt Enable Register; 0x00000147 
typedef union {
  byte Byte;
  struct {
    byte TXEIE0      1;                                        Transmitter Empty Interrupt Enable 0 
    byte TXEIE1      1;                                        Transmitter Empty Interrupt Enable 1 
    byte TXEIE2      1;                                        Transmitter Empty Interrupt Enable 2 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpTXEIE 3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0TIERSTR;
extern volatile CAN0TIERSTR _CAN0TIER @(REG_BASE + 0x00000147);
#define CAN0TIER                        _CAN0TIER.Byte
#define CAN0TIER_TXEIE0                 _CAN0TIER.Bits.TXEIE0
#define CAN0TIER_TXEIE1                 _CAN0TIER.Bits.TXEIE1
#define CAN0TIER_TXEIE2                 _CAN0TIER.Bits.TXEIE2
#define CAN0TIER_TXEIE                  _CAN0TIER.MergedBits.grpTXEIE

#define CAN0TIER_TXEIE0_MASK            1
#define CAN0TIER_TXEIE1_MASK            2
#define CAN0TIER_TXEIE2_MASK            4
#define CAN0TIER_TXEIE_MASK             7
#define CAN0TIER_TXEIE_BITNUM           0


 CAN0TARQ - MSCAN 0 Transmitter Message Abort Request; 0x00000148 
typedef union {
  byte Byte;
  struct {
    byte ABTRQ0      1;                                        Abort Request 0 
    byte ABTRQ1      1;                                        Abort Request 1 
    byte ABTRQ2      1;                                        Abort Request 2 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpABTRQ 3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0TARQSTR;
extern volatile CAN0TARQSTR _CAN0TARQ @(REG_BASE + 0x00000148);
#define CAN0TARQ                        _CAN0TARQ.Byte
#define CAN0TARQ_ABTRQ0                 _CAN0TARQ.Bits.ABTRQ0
#define CAN0TARQ_ABTRQ1                 _CAN0TARQ.Bits.ABTRQ1
#define CAN0TARQ_ABTRQ2                 _CAN0TARQ.Bits.ABTRQ2
#define CAN0TARQ_ABTRQ                  _CAN0TARQ.MergedBits.grpABTRQ

#define CAN0TARQ_ABTRQ0_MASK            1
#define CAN0TARQ_ABTRQ1_MASK            2
#define CAN0TARQ_ABTRQ2_MASK            4
#define CAN0TARQ_ABTRQ_MASK             7
#define CAN0TARQ_ABTRQ_BITNUM           0


 CAN0TAAK - MSCAN 0 Transmitter Message Abort Control; 0x00000149 
typedef union {
  byte Byte;
  struct {
    byte ABTAK0      1;                                        Abort Acknowledge 0 
    byte ABTAK1      1;                                        Abort Acknowledge 1 
    byte ABTAK2      1;                                        Abort Acknowledge 2 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpABTAK 3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0TAAKSTR;
extern volatile CAN0TAAKSTR _CAN0TAAK @(REG_BASE + 0x00000149);
#define CAN0TAAK                        _CAN0TAAK.Byte
#define CAN0TAAK_ABTAK0                 _CAN0TAAK.Bits.ABTAK0
#define CAN0TAAK_ABTAK1                 _CAN0TAAK.Bits.ABTAK1
#define CAN0TAAK_ABTAK2                 _CAN0TAAK.Bits.ABTAK2
#define CAN0TAAK_ABTAK                  _CAN0TAAK.MergedBits.grpABTAK

#define CAN0TAAK_ABTAK0_MASK            1
#define CAN0TAAK_ABTAK1_MASK            2
#define CAN0TAAK_ABTAK2_MASK            4
#define CAN0TAAK_ABTAK_MASK             7
#define CAN0TAAK_ABTAK_BITNUM           0


 CAN0TBSEL - MSCAN 0 Transmit Buffer Selection; 0x0000014A 
typedef union {
  byte Byte;
  struct {
    byte TX0         1;                                        Transmit Buffer Select 0 
    byte TX1         1;                                        Transmit Buffer Select 1 
    byte TX2         1;                                        Transmit Buffer Select 2 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpTX   3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0TBSELSTR;
extern volatile CAN0TBSELSTR _CAN0TBSEL @(REG_BASE + 0x0000014A);
#define CAN0TBSEL                       _CAN0TBSEL.Byte
#define CAN0TBSEL_TX0                   _CAN0TBSEL.Bits.TX0
#define CAN0TBSEL_TX1                   _CAN0TBSEL.Bits.TX1
#define CAN0TBSEL_TX2                   _CAN0TBSEL.Bits.TX2
#define CAN0TBSEL_TX                    _CAN0TBSEL.MergedBits.grpTX

#define CAN0TBSEL_TX0_MASK              1
#define CAN0TBSEL_TX1_MASK              2
#define CAN0TBSEL_TX2_MASK              4
#define CAN0TBSEL_TX_MASK               7
#define CAN0TBSEL_TX_BITNUM             0


 CAN0IDAC - MSCAN 0 Identifier Acceptance Control Register; 0x0000014B 
typedef union {
  byte Byte;
  struct {
    byte IDHIT0      1;                                        Identifier Acceptance Hit Indicator 0 
    byte IDHIT1      1;                                        Identifier Acceptance Hit Indicator 1 
    byte IDHIT2      1;                                        Identifier Acceptance Hit Indicator 2 
    byte             1; 
    byte IDAM0       1;                                        Identifier Acceptance Mode 0 
    byte IDAM1       1;                                        Identifier Acceptance Mode 1 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpIDHIT 3;
    byte         1;
    byte grpIDAM 2;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0IDACSTR;
extern volatile CAN0IDACSTR _CAN0IDAC @(REG_BASE + 0x0000014B);
#define CAN0IDAC                        _CAN0IDAC.Byte
#define CAN0IDAC_IDHIT0                 _CAN0IDAC.Bits.IDHIT0
#define CAN0IDAC_IDHIT1                 _CAN0IDAC.Bits.IDHIT1
#define CAN0IDAC_IDHIT2                 _CAN0IDAC.Bits.IDHIT2
#define CAN0IDAC_IDAM0                  _CAN0IDAC.Bits.IDAM0
#define CAN0IDAC_IDAM1                  _CAN0IDAC.Bits.IDAM1
#define CAN0IDAC_IDHIT                  _CAN0IDAC.MergedBits.grpIDHIT
#define CAN0IDAC_IDAM                   _CAN0IDAC.MergedBits.grpIDAM

#define CAN0IDAC_IDHIT0_MASK            1
#define CAN0IDAC_IDHIT1_MASK            2
#define CAN0IDAC_IDHIT2_MASK            4
#define CAN0IDAC_IDAM0_MASK             16
#define CAN0IDAC_IDAM1_MASK             32
#define CAN0IDAC_IDHIT_MASK             7
#define CAN0IDAC_IDHIT_BITNUM           0
#define CAN0IDAC_IDAM_MASK              48
#define CAN0IDAC_IDAM_BITNUM            4


 CAN0MISC - MSCAN 0 Miscellaneous Register; 0x0000014D 
typedef union {
  byte Byte;
  struct {
    byte BOHOLD      1;                                        Bus-Off state Hold until user request 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} CAN0MISCSTR;
extern volatile CAN0MISCSTR _CAN0MISC @(REG_BASE + 0x0000014D);
#define CAN0MISC                        _CAN0MISC.Byte
#define CAN0MISC_BOHOLD                 _CAN0MISC.Bits.BOHOLD

#define CAN0MISC_BOHOLD_MASK            1


 CAN0RXERR - MSCAN 0 Receive Error Counter Register; 0x0000014E 
typedef union {
  byte Byte;
  struct {
    byte RXERR0      1;                                        Bit 0 
    byte RXERR1      1;                                        Bit 1 
    byte RXERR2      1;                                        Bit 2 
    byte RXERR3      1;                                        Bit 3 
    byte RXERR4      1;                                        Bit 4 
    byte RXERR5      1;                                        Bit 5 
    byte RXERR6      1;                                        Bit 6 
    byte RXERR7      1;                                        Bit 7 
  } Bits;
} CAN0RXERRSTR;
extern volatile CAN0RXERRSTR _CAN0RXERR @(REG_BASE + 0x0000014E);
#define CAN0RXERR                       _CAN0RXERR.Byte
#define CAN0RXERR_RXERR0                _CAN0RXERR.Bits.RXERR0
#define CAN0RXERR_RXERR1                _CAN0RXERR.Bits.RXERR1
#define CAN0RXERR_RXERR2                _CAN0RXERR.Bits.RXERR2
#define CAN0RXERR_RXERR3                _CAN0RXERR.Bits.RXERR3
#define CAN0RXERR_RXERR4                _CAN0RXERR.Bits.RXERR4
#define CAN0RXERR_RXERR5                _CAN0RXERR.Bits.RXERR5
#define CAN0RXERR_RXERR6                _CAN0RXERR.Bits.RXERR6
#define CAN0RXERR_RXERR7                _CAN0RXERR.Bits.RXERR7

#define CAN0RXERR_RXERR0_MASK           1
#define CAN0RXERR_RXERR1_MASK           2
#define CAN0RXERR_RXERR2_MASK           4
#define CAN0RXERR_RXERR3_MASK           8
#define CAN0RXERR_RXERR4_MASK           16
#define CAN0RXERR_RXERR5_MASK           32
#define CAN0RXERR_RXERR6_MASK           64
#define CAN0RXERR_RXERR7_MASK           128


 CAN0TXERR - MSCAN 0 Transmit Error Counter Register; 0x0000014F 
typedef union {
  byte Byte;
  struct {
    byte TXERR0      1;                                        Bit 0 
    byte TXERR1      1;                                        Bit 1 
    byte TXERR2      1;                                        Bit 2 
    byte TXERR3      1;                                        Bit 3 
    byte TXERR4      1;                                        Bit 4 
    byte TXERR5      1;                                        Bit 5 
    byte TXERR6      1;                                        Bit 6 
    byte TXERR7      1;                                        Bit 7 
  } Bits;
} CAN0TXERRSTR;
extern volatile CAN0TXERRSTR _CAN0TXERR @(REG_BASE + 0x0000014F);
#define CAN0TXERR                       _CAN0TXERR.Byte
#define CAN0TXERR_TXERR0                _CAN0TXERR.Bits.TXERR0
#define CAN0TXERR_TXERR1                _CAN0TXERR.Bits.TXERR1
#define CAN0TXERR_TXERR2                _CAN0TXERR.Bits.TXERR2
#define CAN0TXERR_TXERR3                _CAN0TXERR.Bits.TXERR3
#define CAN0TXERR_TXERR4                _CAN0TXERR.Bits.TXERR4
#define CAN0TXERR_TXERR5                _CAN0TXERR.Bits.TXERR5
#define CAN0TXERR_TXERR6                _CAN0TXERR.Bits.TXERR6
#define CAN0TXERR_TXERR7                _CAN0TXERR.Bits.TXERR7

#define CAN0TXERR_TXERR0_MASK           1
#define CAN0TXERR_TXERR1_MASK           2
#define CAN0TXERR_TXERR2_MASK           4
#define CAN0TXERR_TXERR3_MASK           8
#define CAN0TXERR_TXERR4_MASK           16
#define CAN0TXERR_TXERR5_MASK           32
#define CAN0TXERR_TXERR6_MASK           64
#define CAN0TXERR_TXERR7_MASK           128


 CAN0IDAR0 - MSCAN 0 Identifier Acceptance Register 0; 0x00000150 
typedef union {
  byte Byte;
  struct {
    byte AC0         1;                                        Acceptance Code Bit 0 
    byte AC1         1;                                        Acceptance Code Bit 1 
    byte AC2         1;                                        Acceptance Code Bit 2 
    byte AC3         1;                                        Acceptance Code Bit 3 
    byte AC4         1;                                        Acceptance Code Bit 4 
    byte AC5         1;                                        Acceptance Code Bit 5 
    byte AC6         1;                                        Acceptance Code Bit 6 
    byte AC7         1;                                        Acceptance Code Bit 7 
  } Bits;
} CAN0IDAR0STR;
extern volatile CAN0IDAR0STR _CAN0IDAR0 @(REG_BASE + 0x00000150);
#define CAN0IDAR0                       _CAN0IDAR0.Byte
#define CAN0IDAR0_AC0                   _CAN0IDAR0.Bits.AC0
#define CAN0IDAR0_AC1                   _CAN0IDAR0.Bits.AC1
#define CAN0IDAR0_AC2                   _CAN0IDAR0.Bits.AC2
#define CAN0IDAR0_AC3                   _CAN0IDAR0.Bits.AC3
#define CAN0IDAR0_AC4                   _CAN0IDAR0.Bits.AC4
#define CAN0IDAR0_AC5                   _CAN0IDAR0.Bits.AC5
#define CAN0IDAR0_AC6                   _CAN0IDAR0.Bits.AC6
#define CAN0IDAR0_AC7                   _CAN0IDAR0.Bits.AC7
 CAN0IDAR_ARR Access 4 CAN0IDARx registers in an array 
#define CAN0IDAR_ARR                    ((volatile byte ) &CAN0IDAR0)

#define CAN0IDAR0_AC0_MASK              1
#define CAN0IDAR0_AC1_MASK              2
#define CAN0IDAR0_AC2_MASK              4
#define CAN0IDAR0_AC3_MASK              8
#define CAN0IDAR0_AC4_MASK              16
#define CAN0IDAR0_AC5_MASK              32
#define CAN0IDAR0_AC6_MASK              64
#define CAN0IDAR0_AC7_MASK              128


 CAN0IDAR1 - MSCAN 0 Identifier Acceptance Register 1; 0x00000151 
typedef union {
  byte Byte;
  struct {
    byte AC0         1;                                        Acceptance Code Bit 0 
    byte AC1         1;                                        Acceptance Code Bit 1 
    byte AC2         1;                                        Acceptance Code Bit 2 
    byte AC3         1;                                        Acceptance Code Bit 3 
    byte AC4         1;                                        Acceptance Code Bit 4 
    byte AC5         1;                                        Acceptance Code Bit 5 
    byte AC6         1;                                        Acceptance Code Bit 6 
    byte AC7         1;                                        Acceptance Code Bit 7 
  } Bits;
} CAN0IDAR1STR;
extern volatile CAN0IDAR1STR _CAN0IDAR1 @(REG_BASE + 0x00000151);
#define CAN0IDAR1                       _CAN0IDAR1.Byte
#define CAN0IDAR1_AC0                   _CAN0IDAR1.Bits.AC0
#define CAN0IDAR1_AC1                   _CAN0IDAR1.Bits.AC1
#define CAN0IDAR1_AC2                   _CAN0IDAR1.Bits.AC2
#define CAN0IDAR1_AC3                   _CAN0IDAR1.Bits.AC3
#define CAN0IDAR1_AC4                   _CAN0IDAR1.Bits.AC4
#define CAN0IDAR1_AC5                   _CAN0IDAR1.Bits.AC5
#define CAN0IDAR1_AC6                   _CAN0IDAR1.Bits.AC6
#define CAN0IDAR1_AC7                   _CAN0IDAR1.Bits.AC7

#define CAN0IDAR1_AC0_MASK              1
#define CAN0IDAR1_AC1_MASK              2
#define CAN0IDAR1_AC2_MASK              4
#define CAN0IDAR1_AC3_MASK              8
#define CAN0IDAR1_AC4_MASK              16
#define CAN0IDAR1_AC5_MASK              32
#define CAN0IDAR1_AC6_MASK              64
#define CAN0IDAR1_AC7_MASK              128


 CAN0IDAR2 - MSCAN 0 Identifier Acceptance Register 2; 0x00000152 
typedef union {
  byte Byte;
  struct {
    byte AC0         1;                                        Acceptance Code Bit 0 
    byte AC1         1;                                        Acceptance Code Bit 1 
    byte AC2         1;                                        Acceptance Code Bit 2 
    byte AC3         1;                                        Acceptance Code Bit 3 
    byte AC4         1;                                        Acceptance Code Bit 4 
    byte AC5         1;                                        Acceptance Code Bit 5 
    byte AC6         1;                                        Acceptance Code Bit 6 
    byte AC7         1;                                        Acceptance Code Bit 7 
  } Bits;
} CAN0IDAR2STR;
extern volatile CAN0IDAR2STR _CAN0IDAR2 @(REG_BASE + 0x00000152);
#define CAN0IDAR2                       _CAN0IDAR2.Byte
#define CAN0IDAR2_AC0                   _CAN0IDAR2.Bits.AC0
#define CAN0IDAR2_AC1                   _CAN0IDAR2.Bits.AC1
#define CAN0IDAR2_AC2                   _CAN0IDAR2.Bits.AC2
#define CAN0IDAR2_AC3                   _CAN0IDAR2.Bits.AC3
#define CAN0IDAR2_AC4                   _CAN0IDAR2.Bits.AC4
#define CAN0IDAR2_AC5                   _CAN0IDAR2.Bits.AC5
#define CAN0IDAR2_AC6                   _CAN0IDAR2.Bits.AC6
#define CAN0IDAR2_AC7                   _CAN0IDAR2.Bits.AC7

#define CAN0IDAR2_AC0_MASK              1
#define CAN0IDAR2_AC1_MASK              2
#define CAN0IDAR2_AC2_MASK              4
#define CAN0IDAR2_AC3_MASK              8
#define CAN0IDAR2_AC4_MASK              16
#define CAN0IDAR2_AC5_MASK              32
#define CAN0IDAR2_AC6_MASK              64
#define CAN0IDAR2_AC7_MASK              128


 CAN0IDAR3 - MSCAN 0 Identifier Acceptance Register 3; 0x00000153 
typedef union {
  byte Byte;
  struct {
    byte AC0         1;                                        Acceptance Code Bit 0 
    byte AC1         1;                                        Acceptance Code Bit 1 
    byte AC2         1;                                        Acceptance Code Bit 2 
    byte AC3         1;                                        Acceptance Code Bit 3 
    byte AC4         1;                                        Acceptance Code Bit 4 
    byte AC5         1;                                        Acceptance Code Bit 5 
    byte AC6         1;                                        Acceptance Code Bit 6 
    byte AC7         1;                                        Acceptance Code Bit 7 
  } Bits;
} CAN0IDAR3STR;
extern volatile CAN0IDAR3STR _CAN0IDAR3 @(REG_BASE + 0x00000153);
#define CAN0IDAR3                       _CAN0IDAR3.Byte
#define CAN0IDAR3_AC0                   _CAN0IDAR3.Bits.AC0
#define CAN0IDAR3_AC1                   _CAN0IDAR3.Bits.AC1
#define CAN0IDAR3_AC2                   _CAN0IDAR3.Bits.AC2
#define CAN0IDAR3_AC3                   _CAN0IDAR3.Bits.AC3
#define CAN0IDAR3_AC4                   _CAN0IDAR3.Bits.AC4
#define CAN0IDAR3_AC5                   _CAN0IDAR3.Bits.AC5
#define CAN0IDAR3_AC6                   _CAN0IDAR3.Bits.AC6
#define CAN0IDAR3_AC7                   _CAN0IDAR3.Bits.AC7

#define CAN0IDAR3_AC0_MASK              1
#define CAN0IDAR3_AC1_MASK              2
#define CAN0IDAR3_AC2_MASK              4
#define CAN0IDAR3_AC3_MASK              8
#define CAN0IDAR3_AC4_MASK              16
#define CAN0IDAR3_AC5_MASK              32
#define CAN0IDAR3_AC6_MASK              64
#define CAN0IDAR3_AC7_MASK              128


 CAN0IDMR0 - MSCAN 0 Identifier Mask Register 0; 0x00000154 
typedef union {
  byte Byte;
  struct {
    byte AM0         1;                                        Acceptance Mask Bit 0 
    byte AM1         1;                                        Acceptance Mask Bit 1 
    byte AM2         1;                                        Acceptance Mask Bit 2 
    byte AM3         1;                                        Acceptance Mask Bit 3 
    byte AM4         1;                                        Acceptance Mask Bit 4 
    byte AM5         1;                                        Acceptance Mask Bit 5 
    byte AM6         1;                                        Acceptance Mask Bit 6 
    byte AM7         1;                                        Acceptance Mask Bit 7 
  } Bits;
} CAN0IDMR0STR;
extern volatile CAN0IDMR0STR _CAN0IDMR0 @(REG_BASE + 0x00000154);
#define CAN0IDMR0                       _CAN0IDMR0.Byte
#define CAN0IDMR0_AM0                   _CAN0IDMR0.Bits.AM0
#define CAN0IDMR0_AM1                   _CAN0IDMR0.Bits.AM1
#define CAN0IDMR0_AM2                   _CAN0IDMR0.Bits.AM2
#define CAN0IDMR0_AM3                   _CAN0IDMR0.Bits.AM3
#define CAN0IDMR0_AM4                   _CAN0IDMR0.Bits.AM4
#define CAN0IDMR0_AM5                   _CAN0IDMR0.Bits.AM5
#define CAN0IDMR0_AM6                   _CAN0IDMR0.Bits.AM6
#define CAN0IDMR0_AM7                   _CAN0IDMR0.Bits.AM7
 CAN0IDMR_ARR Access 4 CAN0IDMRx registers in an array 
#define CAN0IDMR_ARR                    ((volatile byte ) &CAN0IDMR0)

#define CAN0IDMR0_AM0_MASK              1
#define CAN0IDMR0_AM1_MASK              2
#define CAN0IDMR0_AM2_MASK              4
#define CAN0IDMR0_AM3_MASK              8
#define CAN0IDMR0_AM4_MASK              16
#define CAN0IDMR0_AM5_MASK              32
#define CAN0IDMR0_AM6_MASK              64
#define CAN0IDMR0_AM7_MASK              128


 CAN0IDMR1 - MSCAN 0 Identifier Mask Register 1; 0x00000155 
typedef union {
  byte Byte;
  struct {
    byte AM0         1;                                        Acceptance Mask Bit 0 
    byte AM1         1;                                        Acceptance Mask Bit 1 
    byte AM2         1;                                        Acceptance Mask Bit 2 
    byte AM3         1;                                        Acceptance Mask Bit 3 
    byte AM4         1;                                        Acceptance Mask Bit 4 
    byte AM5         1;                                        Acceptance Mask Bit 5 
    byte AM6         1;                                        Acceptance Mask Bit 6 
    byte AM7         1;                                        Acceptance Mask Bit 7 
  } Bits;
} CAN0IDMR1STR;
extern volatile CAN0IDMR1STR _CAN0IDMR1 @(REG_BASE + 0x00000155);
#define CAN0IDMR1                       _CAN0IDMR1.Byte
#define CAN0IDMR1_AM0                   _CAN0IDMR1.Bits.AM0
#define CAN0IDMR1_AM1                   _CAN0IDMR1.Bits.AM1
#define CAN0IDMR1_AM2                   _CAN0IDMR1.Bits.AM2
#define CAN0IDMR1_AM3                   _CAN0IDMR1.Bits.AM3
#define CAN0IDMR1_AM4                   _CAN0IDMR1.Bits.AM4
#define CAN0IDMR1_AM5                   _CAN0IDMR1.Bits.AM5
#define CAN0IDMR1_AM6                   _CAN0IDMR1.Bits.AM6
#define CAN0IDMR1_AM7                   _CAN0IDMR1.Bits.AM7

#define CAN0IDMR1_AM0_MASK              1
#define CAN0IDMR1_AM1_MASK              2
#define CAN0IDMR1_AM2_MASK              4
#define CAN0IDMR1_AM3_MASK              8
#define CAN0IDMR1_AM4_MASK              16
#define CAN0IDMR1_AM5_MASK              32
#define CAN0IDMR1_AM6_MASK              64
#define CAN0IDMR1_AM7_MASK              128


 CAN0IDMR2 - MSCAN 0 Identifier Mask Register 2; 0x00000156 
typedef union {
  byte Byte;
  struct {
    byte AM0         1;                                        Acceptance Mask Bit 0 
    byte AM1         1;                                        Acceptance Mask Bit 1 
    byte AM2         1;                                        Acceptance Mask Bit 2 
    byte AM3         1;                                        Acceptance Mask Bit 3 
    byte AM4         1;                                        Acceptance Mask Bit 4 
    byte AM5         1;                                        Acceptance Mask Bit 5 
    byte AM6         1;                                        Acceptance Mask Bit 6 
    byte AM7         1;                                        Acceptance Mask Bit 7 
  } Bits;
} CAN0IDMR2STR;
extern volatile CAN0IDMR2STR _CAN0IDMR2 @(REG_BASE + 0x00000156);
#define CAN0IDMR2                       _CAN0IDMR2.Byte
#define CAN0IDMR2_AM0                   _CAN0IDMR2.Bits.AM0
#define CAN0IDMR2_AM1                   _CAN0IDMR2.Bits.AM1
#define CAN0IDMR2_AM2                   _CAN0IDMR2.Bits.AM2
#define CAN0IDMR2_AM3                   _CAN0IDMR2.Bits.AM3
#define CAN0IDMR2_AM4                   _CAN0IDMR2.Bits.AM4
#define CAN0IDMR2_AM5                   _CAN0IDMR2.Bits.AM5
#define CAN0IDMR2_AM6                   _CAN0IDMR2.Bits.AM6
#define CAN0IDMR2_AM7                   _CAN0IDMR2.Bits.AM7

#define CAN0IDMR2_AM0_MASK              1
#define CAN0IDMR2_AM1_MASK              2
#define CAN0IDMR2_AM2_MASK              4
#define CAN0IDMR2_AM3_MASK              8
#define CAN0IDMR2_AM4_MASK              16
#define CAN0IDMR2_AM5_MASK              32
#define CAN0IDMR2_AM6_MASK              64
#define CAN0IDMR2_AM7_MASK              128


 CAN0IDMR3 - MSCAN 0 Identifier Mask Register 3; 0x00000157 
typedef union {
  byte Byte;
  struct {
    byte AM0         1;                                        Acceptance Mask Bit 0 
    byte AM1         1;                                        Acceptance Mask Bit 1 
    byte AM2         1;                                        Acceptance Mask Bit 2 
    byte AM3         1;                                        Acceptance Mask Bit 3 
    byte AM4         1;                                        Acceptance Mask Bit 4 
    byte AM5         1;                                        Acceptance Mask Bit 5 
    byte AM6         1;                                        Acceptance Mask Bit 6 
    byte AM7         1;                                        Acceptance Mask Bit 7 
  } Bits;
} CAN0IDMR3STR;
extern volatile CAN0IDMR3STR _CAN0IDMR3 @(REG_BASE + 0x00000157);
#define CAN0IDMR3                       _CAN0IDMR3.Byte
#define CAN0IDMR3_AM0                   _CAN0IDMR3.Bits.AM0
#define CAN0IDMR3_AM1                   _CAN0IDMR3.Bits.AM1
#define CAN0IDMR3_AM2                   _CAN0IDMR3.Bits.AM2
#define CAN0IDMR3_AM3                   _CAN0IDMR3.Bits.AM3
#define CAN0IDMR3_AM4                   _CAN0IDMR3.Bits.AM4
#define CAN0IDMR3_AM5                   _CAN0IDMR3.Bits.AM5
#define CAN0IDMR3_AM6                   _CAN0IDMR3.Bits.AM6
#define CAN0IDMR3_AM7                   _CAN0IDMR3.Bits.AM7

#define CAN0IDMR3_AM0_MASK              1
#define CAN0IDMR3_AM1_MASK              2
#define CAN0IDMR3_AM2_MASK              4
#define CAN0IDMR3_AM3_MASK              8
#define CAN0IDMR3_AM4_MASK              16
#define CAN0IDMR3_AM5_MASK              32
#define CAN0IDMR3_AM6_MASK              64
#define CAN0IDMR3_AM7_MASK              128


 CAN0IDAR4 - MSCAN 0 Identifier Acceptance Register 4; 0x00000158 
typedef union {
  byte Byte;
  struct {
    byte AC0         1;                                        Acceptance Code Bit 0 
    byte AC1         1;                                        Acceptance Code Bit 1 
    byte AC2         1;                                        Acceptance Code Bit 2 
    byte AC3         1;                                        Acceptance Code Bit 3 
    byte AC4         1;                                        Acceptance Code Bit 4 
    byte AC5         1;                                        Acceptance Code Bit 5 
    byte AC6         1;                                        Acceptance Code Bit 6 
    byte AC7         1;                                        Acceptance Code Bit 7 
  } Bits;
} CAN0IDAR4STR;
extern volatile CAN0IDAR4STR _CAN0IDAR4 @(REG_BASE + 0x00000158);
#define CAN0IDAR4                       _CAN0IDAR4.Byte
#define CAN0IDAR4_AC0                   _CAN0IDAR4.Bits.AC0
#define CAN0IDAR4_AC1                   _CAN0IDAR4.Bits.AC1
#define CAN0IDAR4_AC2                   _CAN0IDAR4.Bits.AC2
#define CAN0IDAR4_AC3                   _CAN0IDAR4.Bits.AC3
#define CAN0IDAR4_AC4                   _CAN0IDAR4.Bits.AC4
#define CAN0IDAR4_AC5                   _CAN0IDAR4.Bits.AC5
#define CAN0IDAR4_AC6                   _CAN0IDAR4.Bits.AC6
#define CAN0IDAR4_AC7                   _CAN0IDAR4.Bits.AC7

#define CAN0IDAR4_AC0_MASK              1
#define CAN0IDAR4_AC1_MASK              2
#define CAN0IDAR4_AC2_MASK              4
#define CAN0IDAR4_AC3_MASK              8
#define CAN0IDAR4_AC4_MASK              16
#define CAN0IDAR4_AC5_MASK              32
#define CAN0IDAR4_AC6_MASK              64
#define CAN0IDAR4_AC7_MASK              128


 CAN0IDAR5 - MSCAN 0 Identifier Acceptance Register 5; 0x00000159 
typedef union {
  byte Byte;
  struct {
    byte AC0         1;                                        Acceptance Code Bit 0 
    byte AC1         1;                                        Acceptance Code Bit 1 
    byte AC2         1;                                        Acceptance Code Bit 2 
    byte AC3         1;                                        Acceptance Code Bit 3 
    byte AC4         1;                                        Acceptance Code Bit 4 
    byte AC5         1;                                        Acceptance Code Bit 5 
    byte AC6         1;                                        Acceptance Code Bit 6 
    byte AC7         1;                                        Acceptance Code Bit 7 
  } Bits;
} CAN0IDAR5STR;
extern volatile CAN0IDAR5STR _CAN0IDAR5 @(REG_BASE + 0x00000159);
#define CAN0IDAR5                       _CAN0IDAR5.Byte
#define CAN0IDAR5_AC0                   _CAN0IDAR5.Bits.AC0
#define CAN0IDAR5_AC1                   _CAN0IDAR5.Bits.AC1
#define CAN0IDAR5_AC2                   _CAN0IDAR5.Bits.AC2
#define CAN0IDAR5_AC3                   _CAN0IDAR5.Bits.AC3
#define CAN0IDAR5_AC4                   _CAN0IDAR5.Bits.AC4
#define CAN0IDAR5_AC5                   _CAN0IDAR5.Bits.AC5
#define CAN0IDAR5_AC6                   _CAN0IDAR5.Bits.AC6
#define CAN0IDAR5_AC7                   _CAN0IDAR5.Bits.AC7

#define CAN0IDAR5_AC0_MASK              1
#define CAN0IDAR5_AC1_MASK              2
#define CAN0IDAR5_AC2_MASK              4
#define CAN0IDAR5_AC3_MASK              8
#define CAN0IDAR5_AC4_MASK              16
#define CAN0IDAR5_AC5_MASK              32
#define CAN0IDAR5_AC6_MASK              64
#define CAN0IDAR5_AC7_MASK              128


 CAN0IDAR6 - MSCAN 0 Identifier Acceptance Register 6; 0x0000015A 
typedef union {
  byte Byte;
  struct {
    byte AC0         1;                                        Acceptance Code Bit 0 
    byte AC1         1;                                        Acceptance Code Bit 1 
    byte AC2         1;                                        Acceptance Code Bit 2 
    byte AC3         1;                                        Acceptance Code Bit 3 
    byte AC4         1;                                        Acceptance Code Bit 4 
    byte AC5         1;                                        Acceptance Code Bit 5 
    byte AC6         1;                                        Acceptance Code Bit 6 
    byte AC7         1;                                        Acceptance Code Bit 7 
  } Bits;
} CAN0IDAR6STR;
extern volatile CAN0IDAR6STR _CAN0IDAR6 @(REG_BASE + 0x0000015A);
#define CAN0IDAR6                       _CAN0IDAR6.Byte
#define CAN0IDAR6_AC0                   _CAN0IDAR6.Bits.AC0
#define CAN0IDAR6_AC1                   _CAN0IDAR6.Bits.AC1
#define CAN0IDAR6_AC2                   _CAN0IDAR6.Bits.AC2
#define CAN0IDAR6_AC3                   _CAN0IDAR6.Bits.AC3
#define CAN0IDAR6_AC4                   _CAN0IDAR6.Bits.AC4
#define CAN0IDAR6_AC5                   _CAN0IDAR6.Bits.AC5
#define CAN0IDAR6_AC6                   _CAN0IDAR6.Bits.AC6
#define CAN0IDAR6_AC7                   _CAN0IDAR6.Bits.AC7

#define CAN0IDAR6_AC0_MASK              1
#define CAN0IDAR6_AC1_MASK              2
#define CAN0IDAR6_AC2_MASK              4
#define CAN0IDAR6_AC3_MASK              8
#define CAN0IDAR6_AC4_MASK              16
#define CAN0IDAR6_AC5_MASK              32
#define CAN0IDAR6_AC6_MASK              64
#define CAN0IDAR6_AC7_MASK              128


 CAN0IDAR7 - MSCAN 0 Identifier Acceptance Register 7; 0x0000015B 
typedef union {
  byte Byte;
  struct {
    byte AC0         1;                                        Acceptance Code Bit 0 
    byte AC1         1;                                        Acceptance Code Bit 1 
    byte AC2         1;                                        Acceptance Code Bit 2 
    byte AC3         1;                                        Acceptance Code Bit 3 
    byte AC4         1;                                        Acceptance Code Bit 4 
    byte AC5         1;                                        Acceptance Code Bit 5 
    byte AC6         1;                                        Acceptance Code Bit 6 
    byte AC7         1;                                        Acceptance Code Bit 7 
  } Bits;
} CAN0IDAR7STR;
extern volatile CAN0IDAR7STR _CAN0IDAR7 @(REG_BASE + 0x0000015B);
#define CAN0IDAR7                       _CAN0IDAR7.Byte
#define CAN0IDAR7_AC0                   _CAN0IDAR7.Bits.AC0
#define CAN0IDAR7_AC1                   _CAN0IDAR7.Bits.AC1
#define CAN0IDAR7_AC2                   _CAN0IDAR7.Bits.AC2
#define CAN0IDAR7_AC3                   _CAN0IDAR7.Bits.AC3
#define CAN0IDAR7_AC4                   _CAN0IDAR7.Bits.AC4
#define CAN0IDAR7_AC5                   _CAN0IDAR7.Bits.AC5
#define CAN0IDAR7_AC6                   _CAN0IDAR7.Bits.AC6
#define CAN0IDAR7_AC7                   _CAN0IDAR7.Bits.AC7

#define CAN0IDAR7_AC0_MASK              1
#define CAN0IDAR7_AC1_MASK              2
#define CAN0IDAR7_AC2_MASK              4
#define CAN0IDAR7_AC3_MASK              8
#define CAN0IDAR7_AC4_MASK              16
#define CAN0IDAR7_AC5_MASK              32
#define CAN0IDAR7_AC6_MASK              64
#define CAN0IDAR7_AC7_MASK              128


 CAN0IDMR4 - MSCAN 0 Identifier Mask Register 4; 0x0000015C 
typedef union {
  byte Byte;
  struct {
    byte AM0         1;                                        Acceptance Mask Bit 0 
    byte AM1         1;                                        Acceptance Mask Bit 1 
    byte AM2         1;                                        Acceptance Mask Bit 2 
    byte AM3         1;                                        Acceptance Mask Bit 3 
    byte AM4         1;                                        Acceptance Mask Bit 4 
    byte AM5         1;                                        Acceptance Mask Bit 5 
    byte AM6         1;                                        Acceptance Mask Bit 6 
    byte AM7         1;                                        Acceptance Mask Bit 7 
  } Bits;
} CAN0IDMR4STR;
extern volatile CAN0IDMR4STR _CAN0IDMR4 @(REG_BASE + 0x0000015C);
#define CAN0IDMR4                       _CAN0IDMR4.Byte
#define CAN0IDMR4_AM0                   _CAN0IDMR4.Bits.AM0
#define CAN0IDMR4_AM1                   _CAN0IDMR4.Bits.AM1
#define CAN0IDMR4_AM2                   _CAN0IDMR4.Bits.AM2
#define CAN0IDMR4_AM3                   _CAN0IDMR4.Bits.AM3
#define CAN0IDMR4_AM4                   _CAN0IDMR4.Bits.AM4
#define CAN0IDMR4_AM5                   _CAN0IDMR4.Bits.AM5
#define CAN0IDMR4_AM6                   _CAN0IDMR4.Bits.AM6
#define CAN0IDMR4_AM7                   _CAN0IDMR4.Bits.AM7

#define CAN0IDMR4_AM0_MASK              1
#define CAN0IDMR4_AM1_MASK              2
#define CAN0IDMR4_AM2_MASK              4
#define CAN0IDMR4_AM3_MASK              8
#define CAN0IDMR4_AM4_MASK              16
#define CAN0IDMR4_AM5_MASK              32
#define CAN0IDMR4_AM6_MASK              64
#define CAN0IDMR4_AM7_MASK              128


 CAN0IDMR5 - MSCAN 0 Identifier Mask Register 5; 0x0000015D 
typedef union {
  byte Byte;
  struct {
    byte AM0         1;                                        Acceptance Mask Bit 0 
    byte AM1         1;                                        Acceptance Mask Bit 1 
    byte AM2         1;                                        Acceptance Mask Bit 2 
    byte AM3         1;                                        Acceptance Mask Bit 3 
    byte AM4         1;                                        Acceptance Mask Bit 4 
    byte AM5         1;                                        Acceptance Mask Bit 5 
    byte AM6         1;                                        Acceptance Mask Bit 6 
    byte AM7         1;                                        Acceptance Mask Bit 7 
  } Bits;
} CAN0IDMR5STR;
extern volatile CAN0IDMR5STR _CAN0IDMR5 @(REG_BASE + 0x0000015D);
#define CAN0IDMR5                       _CAN0IDMR5.Byte
#define CAN0IDMR5_AM0                   _CAN0IDMR5.Bits.AM0
#define CAN0IDMR5_AM1                   _CAN0IDMR5.Bits.AM1
#define CAN0IDMR5_AM2                   _CAN0IDMR5.Bits.AM2
#define CAN0IDMR5_AM3                   _CAN0IDMR5.Bits.AM3
#define CAN0IDMR5_AM4                   _CAN0IDMR5.Bits.AM4
#define CAN0IDMR5_AM5                   _CAN0IDMR5.Bits.AM5
#define CAN0IDMR5_AM6                   _CAN0IDMR5.Bits.AM6
#define CAN0IDMR5_AM7                   _CAN0IDMR5.Bits.AM7

#define CAN0IDMR5_AM0_MASK              1
#define CAN0IDMR5_AM1_MASK              2
#define CAN0IDMR5_AM2_MASK              4
#define CAN0IDMR5_AM3_MASK              8
#define CAN0IDMR5_AM4_MASK              16
#define CAN0IDMR5_AM5_MASK              32
#define CAN0IDMR5_AM6_MASK              64
#define CAN0IDMR5_AM7_MASK              128


 CAN0IDMR6 - MSCAN 0 Identifier Mask Register 6; 0x0000015E 
typedef union {
  byte Byte;
  struct {
    byte AM0         1;                                        Acceptance Mask Bit 0 
    byte AM1         1;                                        Acceptance Mask Bit 1 
    byte AM2         1;                                        Acceptance Mask Bit 2 
    byte AM3         1;                                        Acceptance Mask Bit 3 
    byte AM4         1;                                        Acceptance Mask Bit 4 
    byte AM5         1;                                        Acceptance Mask Bit 5 
    byte AM6         1;                                        Acceptance Mask Bit 6 
    byte AM7         1;                                        Acceptance Mask Bit 7 
  } Bits;
} CAN0IDMR6STR;
extern volatile CAN0IDMR6STR _CAN0IDMR6 @(REG_BASE + 0x0000015E);
#define CAN0IDMR6                       _CAN0IDMR6.Byte
#define CAN0IDMR6_AM0                   _CAN0IDMR6.Bits.AM0
#define CAN0IDMR6_AM1                   _CAN0IDMR6.Bits.AM1
#define CAN0IDMR6_AM2                   _CAN0IDMR6.Bits.AM2
#define CAN0IDMR6_AM3                   _CAN0IDMR6.Bits.AM3
#define CAN0IDMR6_AM4                   _CAN0IDMR6.Bits.AM4
#define CAN0IDMR6_AM5                   _CAN0IDMR6.Bits.AM5
#define CAN0IDMR6_AM6                   _CAN0IDMR6.Bits.AM6
#define CAN0IDMR6_AM7                   _CAN0IDMR6.Bits.AM7

#define CAN0IDMR6_AM0_MASK              1
#define CAN0IDMR6_AM1_MASK              2
#define CAN0IDMR6_AM2_MASK              4
#define CAN0IDMR6_AM3_MASK              8
#define CAN0IDMR6_AM4_MASK              16
#define CAN0IDMR6_AM5_MASK              32
#define CAN0IDMR6_AM6_MASK              64
#define CAN0IDMR6_AM7_MASK              128


 CAN0IDMR7 - MSCAN 0 Identifier Mask Register 7; 0x0000015F 
typedef union {
  byte Byte;
  struct {
    byte AM0         1;                                        Acceptance Mask Bit 0 
    byte AM1         1;                                        Acceptance Mask Bit 1 
    byte AM2         1;                                        Acceptance Mask Bit 2 
    byte AM3         1;                                        Acceptance Mask Bit 3 
    byte AM4         1;                                        Acceptance Mask Bit 4 
    byte AM5         1;                                        Acceptance Mask Bit 5 
    byte AM6         1;                                        Acceptance Mask Bit 6 
    byte AM7         1;                                        Acceptance Mask Bit 7 
  } Bits;
} CAN0IDMR7STR;
extern volatile CAN0IDMR7STR _CAN0IDMR7 @(REG_BASE + 0x0000015F);
#define CAN0IDMR7                       _CAN0IDMR7.Byte
#define CAN0IDMR7_AM0                   _CAN0IDMR7.Bits.AM0
#define CAN0IDMR7_AM1                   _CAN0IDMR7.Bits.AM1
#define CAN0IDMR7_AM2                   _CAN0IDMR7.Bits.AM2
#define CAN0IDMR7_AM3                   _CAN0IDMR7.Bits.AM3
#define CAN0IDMR7_AM4                   _CAN0IDMR7.Bits.AM4
#define CAN0IDMR7_AM5                   _CAN0IDMR7.Bits.AM5
#define CAN0IDMR7_AM6                   _CAN0IDMR7.Bits.AM6
#define CAN0IDMR7_AM7                   _CAN0IDMR7.Bits.AM7

#define CAN0IDMR7_AM0_MASK              1
#define CAN0IDMR7_AM1_MASK              2
#define CAN0IDMR7_AM2_MASK              4
#define CAN0IDMR7_AM3_MASK              8
#define CAN0IDMR7_AM4_MASK              16
#define CAN0IDMR7_AM5_MASK              32
#define CAN0IDMR7_AM6_MASK              64
#define CAN0IDMR7_AM7_MASK              128


 CAN0RXIDR0 - MSCAN 0 Receive Identifier Register 0; 0x00000160 
typedef union {
  byte Byte;
  struct {
    byte ID21        1;                                        Extended format identifier Bit 21 
    byte ID22        1;                                        Extended format identifier Bit 22 
    byte ID23        1;                                        Extended format identifier Bit 23 
    byte ID24        1;                                        Extended format identifier Bit 24 
    byte ID25        1;                                        Extended format identifier Bit 25 
    byte ID26        1;                                        Extended format identifier Bit 26 
    byte ID27        1;                                        Extended format identifier Bit 27 
    byte ID28        1;                                        Extended format identifier Bit 28 
  } Bits;
} CAN0RXIDR0STR;
extern volatile CAN0RXIDR0STR _CAN0RXIDR0 @(REG_BASE + 0x00000160);
#define CAN0RXIDR0                      _CAN0RXIDR0.Byte
#define CAN0RXIDR0_ID21                 _CAN0RXIDR0.Bits.ID21
#define CAN0RXIDR0_ID22                 _CAN0RXIDR0.Bits.ID22
#define CAN0RXIDR0_ID23                 _CAN0RXIDR0.Bits.ID23
#define CAN0RXIDR0_ID24                 _CAN0RXIDR0.Bits.ID24
#define CAN0RXIDR0_ID25                 _CAN0RXIDR0.Bits.ID25
#define CAN0RXIDR0_ID26                 _CAN0RXIDR0.Bits.ID26
#define CAN0RXIDR0_ID27                 _CAN0RXIDR0.Bits.ID27
#define CAN0RXIDR0_ID28                 _CAN0RXIDR0.Bits.ID28
 CAN0RXIDR_ARR Access 4 CAN0RXIDRx registers in an array 
#define CAN0RXIDR_ARR                   ((volatile byte ) &CAN0RXIDR0)

#define CAN0RXIDR0_ID21_MASK            1
#define CAN0RXIDR0_ID22_MASK            2
#define CAN0RXIDR0_ID23_MASK            4
#define CAN0RXIDR0_ID24_MASK            8
#define CAN0RXIDR0_ID25_MASK            16
#define CAN0RXIDR0_ID26_MASK            32
#define CAN0RXIDR0_ID27_MASK            64
#define CAN0RXIDR0_ID28_MASK            128


 CAN0RXIDR1 - MSCAN 0 Receive Identifier Register 1; 0x00000161 
typedef union {
  byte Byte;
  struct {
    byte ID15        1;                                        Extended format identifier Bit 15 
    byte ID16        1;                                        Extended format identifier Bit 16 
    byte ID17        1;                                        Extended format identifier Bit 17 
    byte IDE         1;                                        ID Extended 
    byte SRR         1;                                        Substitute Remote Request 
    byte ID18        1;                                        Extended format identifier Bit 18 
    byte ID19        1;                                        Extended format identifier Bit 19 
    byte ID20        1;                                        Extended format identifier Bit 20 
  } Bits;
  struct {
    byte grpID_15 3;
    byte         1;
    byte         1;
    byte grpID_18 3;
  } MergedBits;
} CAN0RXIDR1STR;
extern volatile CAN0RXIDR1STR _CAN0RXIDR1 @(REG_BASE + 0x00000161);
#define CAN0RXIDR1                      _CAN0RXIDR1.Byte
#define CAN0RXIDR1_ID15                 _CAN0RXIDR1.Bits.ID15
#define CAN0RXIDR1_ID16                 _CAN0RXIDR1.Bits.ID16
#define CAN0RXIDR1_ID17                 _CAN0RXIDR1.Bits.ID17
#define CAN0RXIDR1_IDE                  _CAN0RXIDR1.Bits.IDE
#define CAN0RXIDR1_SRR                  _CAN0RXIDR1.Bits.SRR
#define CAN0RXIDR1_ID18                 _CAN0RXIDR1.Bits.ID18
#define CAN0RXIDR1_ID19                 _CAN0RXIDR1.Bits.ID19
#define CAN0RXIDR1_ID20                 _CAN0RXIDR1.Bits.ID20
#define CAN0RXIDR1_ID_15                _CAN0RXIDR1.MergedBits.grpID_15
#define CAN0RXIDR1_ID_18                _CAN0RXIDR1.MergedBits.grpID_18
#define CAN0RXIDR1_ID                   CAN0RXIDR1_ID_15

#define CAN0RXIDR1_ID15_MASK            1
#define CAN0RXIDR1_ID16_MASK            2
#define CAN0RXIDR1_ID17_MASK            4
#define CAN0RXIDR1_IDE_MASK             8
#define CAN0RXIDR1_SRR_MASK             16
#define CAN0RXIDR1_ID18_MASK            32
#define CAN0RXIDR1_ID19_MASK            64
#define CAN0RXIDR1_ID20_MASK            128
#define CAN0RXIDR1_ID_15_MASK           7
#define CAN0RXIDR1_ID_15_BITNUM         0
#define CAN0RXIDR1_ID_18_MASK           224
#define CAN0RXIDR1_ID_18_BITNUM         5


 CAN0RXIDR2 - MSCAN 0 Receive Identifier Register 2; 0x00000162 
typedef union {
  byte Byte;
  struct {
    byte ID7         1;                                        Extended format identifier Bit 7 
    byte ID8         1;                                        Extended format identifier Bit 8 
    byte ID9         1;                                        Extended format identifier Bit 9 
    byte ID10        1;                                        Extended format identifier Bit 10 
    byte ID11        1;                                        Extended format identifier Bit 11 
    byte ID12        1;                                        Extended format identifier Bit 12 
    byte ID13        1;                                        Extended format identifier Bit 13 
    byte ID14        1;                                        Extended format identifier Bit 14 
  } Bits;
} CAN0RXIDR2STR;
extern volatile CAN0RXIDR2STR _CAN0RXIDR2 @(REG_BASE + 0x00000162);
#define CAN0RXIDR2                      _CAN0RXIDR2.Byte
#define CAN0RXIDR2_ID7                  _CAN0RXIDR2.Bits.ID7
#define CAN0RXIDR2_ID8                  _CAN0RXIDR2.Bits.ID8
#define CAN0RXIDR2_ID9                  _CAN0RXIDR2.Bits.ID9
#define CAN0RXIDR2_ID10                 _CAN0RXIDR2.Bits.ID10
#define CAN0RXIDR2_ID11                 _CAN0RXIDR2.Bits.ID11
#define CAN0RXIDR2_ID12                 _CAN0RXIDR2.Bits.ID12
#define CAN0RXIDR2_ID13                 _CAN0RXIDR2.Bits.ID13
#define CAN0RXIDR2_ID14                 _CAN0RXIDR2.Bits.ID14

#define CAN0RXIDR2_ID7_MASK             1
#define CAN0RXIDR2_ID8_MASK             2
#define CAN0RXIDR2_ID9_MASK             4
#define CAN0RXIDR2_ID10_MASK            8
#define CAN0RXIDR2_ID11_MASK            16
#define CAN0RXIDR2_ID12_MASK            32
#define CAN0RXIDR2_ID13_MASK            64
#define CAN0RXIDR2_ID14_MASK            128


 CAN0RXIDR3 - MSCAN 0 Receive Identifier Register 3; 0x00000163 
typedef union {
  byte Byte;
  struct {
    byte RTR         1;                                        Remote Transmission Request 
    byte ID0         1;                                        Extended format identifier Bit 0 
    byte ID1         1;                                        Extended format identifier Bit 1 
    byte ID2         1;                                        Extended format identifier Bit 2 
    byte ID3         1;                                        Extended format identifier Bit 3 
    byte ID4         1;                                        Extended format identifier Bit 4 
    byte ID5         1;                                        Extended format identifier Bit 5 
    byte ID6         1;                                        Extended format identifier Bit 6 
  } Bits;
  struct {
    byte         1;
    byte grpID   7;
  } MergedBits;
} CAN0RXIDR3STR;
extern volatile CAN0RXIDR3STR _CAN0RXIDR3 @(REG_BASE + 0x00000163);
#define CAN0RXIDR3                      _CAN0RXIDR3.Byte
#define CAN0RXIDR3_RTR                  _CAN0RXIDR3.Bits.RTR
#define CAN0RXIDR3_ID0                  _CAN0RXIDR3.Bits.ID0
#define CAN0RXIDR3_ID1                  _CAN0RXIDR3.Bits.ID1
#define CAN0RXIDR3_ID2                  _CAN0RXIDR3.Bits.ID2
#define CAN0RXIDR3_ID3                  _CAN0RXIDR3.Bits.ID3
#define CAN0RXIDR3_ID4                  _CAN0RXIDR3.Bits.ID4
#define CAN0RXIDR3_ID5                  _CAN0RXIDR3.Bits.ID5
#define CAN0RXIDR3_ID6                  _CAN0RXIDR3.Bits.ID6
#define CAN0RXIDR3_ID                   _CAN0RXIDR3.MergedBits.grpID

#define CAN0RXIDR3_RTR_MASK             1
#define CAN0RXIDR3_ID0_MASK             2
#define CAN0RXIDR3_ID1_MASK             4
#define CAN0RXIDR3_ID2_MASK             8
#define CAN0RXIDR3_ID3_MASK             16
#define CAN0RXIDR3_ID4_MASK             32
#define CAN0RXIDR3_ID5_MASK             64
#define CAN0RXIDR3_ID6_MASK             128
#define CAN0RXIDR3_ID_MASK              254
#define CAN0RXIDR3_ID_BITNUM            1


 CAN0RXDSR0 - MSCAN 0 Receive Data Segment Register 0; 0x00000164 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0RXDSR0STR;
extern volatile CAN0RXDSR0STR _CAN0RXDSR0 @(REG_BASE + 0x00000164);
#define CAN0RXDSR0                      _CAN0RXDSR0.Byte
#define CAN0RXDSR0_DB0                  _CAN0RXDSR0.Bits.DB0
#define CAN0RXDSR0_DB1                  _CAN0RXDSR0.Bits.DB1
#define CAN0RXDSR0_DB2                  _CAN0RXDSR0.Bits.DB2
#define CAN0RXDSR0_DB3                  _CAN0RXDSR0.Bits.DB3
#define CAN0RXDSR0_DB4                  _CAN0RXDSR0.Bits.DB4
#define CAN0RXDSR0_DB5                  _CAN0RXDSR0.Bits.DB5
#define CAN0RXDSR0_DB6                  _CAN0RXDSR0.Bits.DB6
#define CAN0RXDSR0_DB7                  _CAN0RXDSR0.Bits.DB7
 CAN0RXDSR_ARR Access 8 CAN0RXDSRx registers in an array 
#define CAN0RXDSR_ARR                   ((volatile byte ) &CAN0RXDSR0)

#define CAN0RXDSR0_DB0_MASK             1
#define CAN0RXDSR0_DB1_MASK             2
#define CAN0RXDSR0_DB2_MASK             4
#define CAN0RXDSR0_DB3_MASK             8
#define CAN0RXDSR0_DB4_MASK             16
#define CAN0RXDSR0_DB5_MASK             32
#define CAN0RXDSR0_DB6_MASK             64
#define CAN0RXDSR0_DB7_MASK             128


 CAN0RXDSR1 - MSCAN 0 Receive Data Segment Register 1; 0x00000165 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0RXDSR1STR;
extern volatile CAN0RXDSR1STR _CAN0RXDSR1 @(REG_BASE + 0x00000165);
#define CAN0RXDSR1                      _CAN0RXDSR1.Byte
#define CAN0RXDSR1_DB0                  _CAN0RXDSR1.Bits.DB0
#define CAN0RXDSR1_DB1                  _CAN0RXDSR1.Bits.DB1
#define CAN0RXDSR1_DB2                  _CAN0RXDSR1.Bits.DB2
#define CAN0RXDSR1_DB3                  _CAN0RXDSR1.Bits.DB3
#define CAN0RXDSR1_DB4                  _CAN0RXDSR1.Bits.DB4
#define CAN0RXDSR1_DB5                  _CAN0RXDSR1.Bits.DB5
#define CAN0RXDSR1_DB6                  _CAN0RXDSR1.Bits.DB6
#define CAN0RXDSR1_DB7                  _CAN0RXDSR1.Bits.DB7

#define CAN0RXDSR1_DB0_MASK             1
#define CAN0RXDSR1_DB1_MASK             2
#define CAN0RXDSR1_DB2_MASK             4
#define CAN0RXDSR1_DB3_MASK             8
#define CAN0RXDSR1_DB4_MASK             16
#define CAN0RXDSR1_DB5_MASK             32
#define CAN0RXDSR1_DB6_MASK             64
#define CAN0RXDSR1_DB7_MASK             128


 CAN0RXDSR2 - MSCAN 0 Receive Data Segment Register 2; 0x00000166 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0RXDSR2STR;
extern volatile CAN0RXDSR2STR _CAN0RXDSR2 @(REG_BASE + 0x00000166);
#define CAN0RXDSR2                      _CAN0RXDSR2.Byte
#define CAN0RXDSR2_DB0                  _CAN0RXDSR2.Bits.DB0
#define CAN0RXDSR2_DB1                  _CAN0RXDSR2.Bits.DB1
#define CAN0RXDSR2_DB2                  _CAN0RXDSR2.Bits.DB2
#define CAN0RXDSR2_DB3                  _CAN0RXDSR2.Bits.DB3
#define CAN0RXDSR2_DB4                  _CAN0RXDSR2.Bits.DB4
#define CAN0RXDSR2_DB5                  _CAN0RXDSR2.Bits.DB5
#define CAN0RXDSR2_DB6                  _CAN0RXDSR2.Bits.DB6
#define CAN0RXDSR2_DB7                  _CAN0RXDSR2.Bits.DB7

#define CAN0RXDSR2_DB0_MASK             1
#define CAN0RXDSR2_DB1_MASK             2
#define CAN0RXDSR2_DB2_MASK             4
#define CAN0RXDSR2_DB3_MASK             8
#define CAN0RXDSR2_DB4_MASK             16
#define CAN0RXDSR2_DB5_MASK             32
#define CAN0RXDSR2_DB6_MASK             64
#define CAN0RXDSR2_DB7_MASK             128


 CAN0RXDSR3 - MSCAN 0 Receive Data Segment Register 3; 0x00000167 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0RXDSR3STR;
extern volatile CAN0RXDSR3STR _CAN0RXDSR3 @(REG_BASE + 0x00000167);
#define CAN0RXDSR3                      _CAN0RXDSR3.Byte
#define CAN0RXDSR3_DB0                  _CAN0RXDSR3.Bits.DB0
#define CAN0RXDSR3_DB1                  _CAN0RXDSR3.Bits.DB1
#define CAN0RXDSR3_DB2                  _CAN0RXDSR3.Bits.DB2
#define CAN0RXDSR3_DB3                  _CAN0RXDSR3.Bits.DB3
#define CAN0RXDSR3_DB4                  _CAN0RXDSR3.Bits.DB4
#define CAN0RXDSR3_DB5                  _CAN0RXDSR3.Bits.DB5
#define CAN0RXDSR3_DB6                  _CAN0RXDSR3.Bits.DB6
#define CAN0RXDSR3_DB7                  _CAN0RXDSR3.Bits.DB7

#define CAN0RXDSR3_DB0_MASK             1
#define CAN0RXDSR3_DB1_MASK             2
#define CAN0RXDSR3_DB2_MASK             4
#define CAN0RXDSR3_DB3_MASK             8
#define CAN0RXDSR3_DB4_MASK             16
#define CAN0RXDSR3_DB5_MASK             32
#define CAN0RXDSR3_DB6_MASK             64
#define CAN0RXDSR3_DB7_MASK             128


 CAN0RXDSR4 - MSCAN 0 Receive Data Segment Register 4; 0x00000168 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0RXDSR4STR;
extern volatile CAN0RXDSR4STR _CAN0RXDSR4 @(REG_BASE + 0x00000168);
#define CAN0RXDSR4                      _CAN0RXDSR4.Byte
#define CAN0RXDSR4_DB0                  _CAN0RXDSR4.Bits.DB0
#define CAN0RXDSR4_DB1                  _CAN0RXDSR4.Bits.DB1
#define CAN0RXDSR4_DB2                  _CAN0RXDSR4.Bits.DB2
#define CAN0RXDSR4_DB3                  _CAN0RXDSR4.Bits.DB3
#define CAN0RXDSR4_DB4                  _CAN0RXDSR4.Bits.DB4
#define CAN0RXDSR4_DB5                  _CAN0RXDSR4.Bits.DB5
#define CAN0RXDSR4_DB6                  _CAN0RXDSR4.Bits.DB6
#define CAN0RXDSR4_DB7                  _CAN0RXDSR4.Bits.DB7

#define CAN0RXDSR4_DB0_MASK             1
#define CAN0RXDSR4_DB1_MASK             2
#define CAN0RXDSR4_DB2_MASK             4
#define CAN0RXDSR4_DB3_MASK             8
#define CAN0RXDSR4_DB4_MASK             16
#define CAN0RXDSR4_DB5_MASK             32
#define CAN0RXDSR4_DB6_MASK             64
#define CAN0RXDSR4_DB7_MASK             128


 CAN0RXDSR5 - MSCAN 0 Receive Data Segment Register 5; 0x00000169 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0RXDSR5STR;
extern volatile CAN0RXDSR5STR _CAN0RXDSR5 @(REG_BASE + 0x00000169);
#define CAN0RXDSR5                      _CAN0RXDSR5.Byte
#define CAN0RXDSR5_DB0                  _CAN0RXDSR5.Bits.DB0
#define CAN0RXDSR5_DB1                  _CAN0RXDSR5.Bits.DB1
#define CAN0RXDSR5_DB2                  _CAN0RXDSR5.Bits.DB2
#define CAN0RXDSR5_DB3                  _CAN0RXDSR5.Bits.DB3
#define CAN0RXDSR5_DB4                  _CAN0RXDSR5.Bits.DB4
#define CAN0RXDSR5_DB5                  _CAN0RXDSR5.Bits.DB5
#define CAN0RXDSR5_DB6                  _CAN0RXDSR5.Bits.DB6
#define CAN0RXDSR5_DB7                  _CAN0RXDSR5.Bits.DB7

#define CAN0RXDSR5_DB0_MASK             1
#define CAN0RXDSR5_DB1_MASK             2
#define CAN0RXDSR5_DB2_MASK             4
#define CAN0RXDSR5_DB3_MASK             8
#define CAN0RXDSR5_DB4_MASK             16
#define CAN0RXDSR5_DB5_MASK             32
#define CAN0RXDSR5_DB6_MASK             64
#define CAN0RXDSR5_DB7_MASK             128


 CAN0RXDSR6 - MSCAN 0 Receive Data Segment Register 6; 0x0000016A 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0RXDSR6STR;
extern volatile CAN0RXDSR6STR _CAN0RXDSR6 @(REG_BASE + 0x0000016A);
#define CAN0RXDSR6                      _CAN0RXDSR6.Byte
#define CAN0RXDSR6_DB0                  _CAN0RXDSR6.Bits.DB0
#define CAN0RXDSR6_DB1                  _CAN0RXDSR6.Bits.DB1
#define CAN0RXDSR6_DB2                  _CAN0RXDSR6.Bits.DB2
#define CAN0RXDSR6_DB3                  _CAN0RXDSR6.Bits.DB3
#define CAN0RXDSR6_DB4                  _CAN0RXDSR6.Bits.DB4
#define CAN0RXDSR6_DB5                  _CAN0RXDSR6.Bits.DB5
#define CAN0RXDSR6_DB6                  _CAN0RXDSR6.Bits.DB6
#define CAN0RXDSR6_DB7                  _CAN0RXDSR6.Bits.DB7

#define CAN0RXDSR6_DB0_MASK             1
#define CAN0RXDSR6_DB1_MASK             2
#define CAN0RXDSR6_DB2_MASK             4
#define CAN0RXDSR6_DB3_MASK             8
#define CAN0RXDSR6_DB4_MASK             16
#define CAN0RXDSR6_DB5_MASK             32
#define CAN0RXDSR6_DB6_MASK             64
#define CAN0RXDSR6_DB7_MASK             128


 CAN0RXDSR7 - MSCAN 0 Receive Data Segment Register 7; 0x0000016B 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0RXDSR7STR;
extern volatile CAN0RXDSR7STR _CAN0RXDSR7 @(REG_BASE + 0x0000016B);
#define CAN0RXDSR7                      _CAN0RXDSR7.Byte
#define CAN0RXDSR7_DB0                  _CAN0RXDSR7.Bits.DB0
#define CAN0RXDSR7_DB1                  _CAN0RXDSR7.Bits.DB1
#define CAN0RXDSR7_DB2                  _CAN0RXDSR7.Bits.DB2
#define CAN0RXDSR7_DB3                  _CAN0RXDSR7.Bits.DB3
#define CAN0RXDSR7_DB4                  _CAN0RXDSR7.Bits.DB4
#define CAN0RXDSR7_DB5                  _CAN0RXDSR7.Bits.DB5
#define CAN0RXDSR7_DB6                  _CAN0RXDSR7.Bits.DB6
#define CAN0RXDSR7_DB7                  _CAN0RXDSR7.Bits.DB7

#define CAN0RXDSR7_DB0_MASK             1
#define CAN0RXDSR7_DB1_MASK             2
#define CAN0RXDSR7_DB2_MASK             4
#define CAN0RXDSR7_DB3_MASK             8
#define CAN0RXDSR7_DB4_MASK             16
#define CAN0RXDSR7_DB5_MASK             32
#define CAN0RXDSR7_DB6_MASK             64
#define CAN0RXDSR7_DB7_MASK             128


 CAN0RXDLR - MSCAN 0 Receive Data Length Register; 0x0000016C 
typedef union {
  byte Byte;
  struct {
    byte DLC0        1;                                        Data Length Code Bit 0 
    byte DLC1        1;                                        Data Length Code Bit 1 
    byte DLC2        1;                                        Data Length Code Bit 2 
    byte DLC3        1;                                        Data Length Code Bit 3 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpDLC  4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0RXDLRSTR;
extern volatile CAN0RXDLRSTR _CAN0RXDLR @(REG_BASE + 0x0000016C);
#define CAN0RXDLR                       _CAN0RXDLR.Byte
#define CAN0RXDLR_DLC0                  _CAN0RXDLR.Bits.DLC0
#define CAN0RXDLR_DLC1                  _CAN0RXDLR.Bits.DLC1
#define CAN0RXDLR_DLC2                  _CAN0RXDLR.Bits.DLC2
#define CAN0RXDLR_DLC3                  _CAN0RXDLR.Bits.DLC3
#define CAN0RXDLR_DLC                   _CAN0RXDLR.MergedBits.grpDLC

#define CAN0RXDLR_DLC0_MASK             1
#define CAN0RXDLR_DLC1_MASK             2
#define CAN0RXDLR_DLC2_MASK             4
#define CAN0RXDLR_DLC3_MASK             8
#define CAN0RXDLR_DLC_MASK              15
#define CAN0RXDLR_DLC_BITNUM            0


 CAN0RXTSR - MSCAN 0 Receive Time Stamp Register; 0x0000016E 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     CAN0RXTSRH - MSCAN 0 Receive Time Stamp Register High; 0x0000016E 
    union {
      byte Byte;
      struct {
        byte TSR8        1;                                        Time Stamp Bit 8 
        byte TSR9        1;                                        Time Stamp Bit 9 
        byte TSR10       1;                                        Time Stamp Bit 10 
        byte TSR11       1;                                        Time Stamp Bit 11 
        byte TSR12       1;                                        Time Stamp Bit 12 
        byte TSR13       1;                                        Time Stamp Bit 13 
        byte TSR14       1;                                        Time Stamp Bit 14 
        byte TSR15       1;                                        Time Stamp Bit 15 
      } Bits;
    } CAN0RXTSRHSTR;
    #define CAN0RXTSRH                  _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Byte
    #define CAN0RXTSRH_TSR8             _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR8
    #define CAN0RXTSRH_TSR9             _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR9
    #define CAN0RXTSRH_TSR10            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR10
    #define CAN0RXTSRH_TSR11            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR11
    #define CAN0RXTSRH_TSR12            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR12
    #define CAN0RXTSRH_TSR13            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR13
    #define CAN0RXTSRH_TSR14            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR14
    #define CAN0RXTSRH_TSR15            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR15
    
    
    #define CAN0RXTSRH_TSR8_MASK        1
    #define CAN0RXTSRH_TSR9_MASK        2
    #define CAN0RXTSRH_TSR10_MASK       4
    #define CAN0RXTSRH_TSR11_MASK       8
    #define CAN0RXTSRH_TSR12_MASK       16
    #define CAN0RXTSRH_TSR13_MASK       32
    #define CAN0RXTSRH_TSR14_MASK       64
    #define CAN0RXTSRH_TSR15_MASK       128


     CAN0RXTSRL - MSCAN 0 Receive Time Stamp Register Low; 0x0000016F 
    union {
      byte Byte;
      struct {
        byte TSR0        1;                                        Time Stamp Bit 0 
        byte TSR1        1;                                        Time Stamp Bit 1 
        byte TSR2        1;                                        Time Stamp Bit 2 
        byte TSR3        1;                                        Time Stamp Bit 3 
        byte TSR4        1;                                        Time Stamp Bit 4 
        byte TSR5        1;                                        Time Stamp Bit 5 
        byte TSR6        1;                                        Time Stamp Bit 6 
        byte TSR7        1;                                        Time Stamp Bit 7 
      } Bits;
    } CAN0RXTSRLSTR;
    #define CAN0RXTSRL                  _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Byte
    #define CAN0RXTSRL_TSR0             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR0
    #define CAN0RXTSRL_TSR1             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR1
    #define CAN0RXTSRL_TSR2             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR2
    #define CAN0RXTSRL_TSR3             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR3
    #define CAN0RXTSRL_TSR4             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR4
    #define CAN0RXTSRL_TSR5             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR5
    #define CAN0RXTSRL_TSR6             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR6
    #define CAN0RXTSRL_TSR7             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR7
    
    
    #define CAN0RXTSRL_TSR0_MASK        1
    #define CAN0RXTSRL_TSR1_MASK        2
    #define CAN0RXTSRL_TSR2_MASK        4
    #define CAN0RXTSRL_TSR3_MASK        8
    #define CAN0RXTSRL_TSR4_MASK        16
    #define CAN0RXTSRL_TSR5_MASK        32
    #define CAN0RXTSRL_TSR6_MASK        64
    #define CAN0RXTSRL_TSR7_MASK        128

  } Overlap_STR;

  struct {
    word TSR0        1;                                        Time Stamp Bit 0 
    word TSR1        1;                                        Time Stamp Bit 1 
    word TSR2        1;                                        Time Stamp Bit 2 
    word TSR3        1;                                        Time Stamp Bit 3 
    word TSR4        1;                                        Time Stamp Bit 4 
    word TSR5        1;                                        Time Stamp Bit 5 
    word TSR6        1;                                        Time Stamp Bit 6 
    word TSR7        1;                                        Time Stamp Bit 7 
    word TSR8        1;                                        Time Stamp Bit 8 
    word TSR9        1;                                        Time Stamp Bit 9 
    word TSR10       1;                                        Time Stamp Bit 10 
    word TSR11       1;                                        Time Stamp Bit 11 
    word TSR12       1;                                        Time Stamp Bit 12 
    word TSR13       1;                                        Time Stamp Bit 13 
    word TSR14       1;                                        Time Stamp Bit 14 
    word TSR15       1;                                        Time Stamp Bit 15 
  } Bits;
} CAN0RXTSRSTR;
extern volatile CAN0RXTSRSTR _CAN0RXTSR @(REG_BASE + 0x0000016E);
#define CAN0RXTSR                       _CAN0RXTSR.Word
#define CAN0RXTSR_TSR0                  _CAN0RXTSR.Bits.TSR0
#define CAN0RXTSR_TSR1                  _CAN0RXTSR.Bits.TSR1
#define CAN0RXTSR_TSR2                  _CAN0RXTSR.Bits.TSR2
#define CAN0RXTSR_TSR3                  _CAN0RXTSR.Bits.TSR3
#define CAN0RXTSR_TSR4                  _CAN0RXTSR.Bits.TSR4
#define CAN0RXTSR_TSR5                  _CAN0RXTSR.Bits.TSR5
#define CAN0RXTSR_TSR6                  _CAN0RXTSR.Bits.TSR6
#define CAN0RXTSR_TSR7                  _CAN0RXTSR.Bits.TSR7
#define CAN0RXTSR_TSR8                  _CAN0RXTSR.Bits.TSR8
#define CAN0RXTSR_TSR9                  _CAN0RXTSR.Bits.TSR9
#define CAN0RXTSR_TSR10                 _CAN0RXTSR.Bits.TSR10
#define CAN0RXTSR_TSR11                 _CAN0RXTSR.Bits.TSR11
#define CAN0RXTSR_TSR12                 _CAN0RXTSR.Bits.TSR12
#define CAN0RXTSR_TSR13                 _CAN0RXTSR.Bits.TSR13
#define CAN0RXTSR_TSR14                 _CAN0RXTSR.Bits.TSR14
#define CAN0RXTSR_TSR15                 _CAN0RXTSR.Bits.TSR15

#define CAN0RXTSR_TSR0_MASK             1
#define CAN0RXTSR_TSR1_MASK             2
#define CAN0RXTSR_TSR2_MASK             4
#define CAN0RXTSR_TSR3_MASK             8
#define CAN0RXTSR_TSR4_MASK             16
#define CAN0RXTSR_TSR5_MASK             32
#define CAN0RXTSR_TSR6_MASK             64
#define CAN0RXTSR_TSR7_MASK             128
#define CAN0RXTSR_TSR8_MASK             256
#define CAN0RXTSR_TSR9_MASK             512
#define CAN0RXTSR_TSR10_MASK            1024
#define CAN0RXTSR_TSR11_MASK            2048
#define CAN0RXTSR_TSR12_MASK            4096
#define CAN0RXTSR_TSR13_MASK            8192
#define CAN0RXTSR_TSR14_MASK            16384
#define CAN0RXTSR_TSR15_MASK            32768


 CAN0TXIDR0 - MSCAN 0 Transmit Identifier Register 0; 0x00000170 
typedef union {
  byte Byte;
  struct {
    byte ID21        1;                                        Extended format identifier Bit 21 
    byte ID22        1;                                        Extended format identifier Bit 22 
    byte ID23        1;                                        Extended format identifier Bit 23 
    byte ID24        1;                                        Extended format identifier Bit 24 
    byte ID25        1;                                        Extended format identifier Bit 25 
    byte ID26        1;                                        Extended format identifier Bit 26 
    byte ID27        1;                                        Extended format identifier Bit 27 
    byte ID28        1;                                        Extended format identifier Bit 28 
  } Bits;
} CAN0TXIDR0STR;
extern volatile CAN0TXIDR0STR _CAN0TXIDR0 @(REG_BASE + 0x00000170);
#define CAN0TXIDR0                      _CAN0TXIDR0.Byte
#define CAN0TXIDR0_ID21                 _CAN0TXIDR0.Bits.ID21
#define CAN0TXIDR0_ID22                 _CAN0TXIDR0.Bits.ID22
#define CAN0TXIDR0_ID23                 _CAN0TXIDR0.Bits.ID23
#define CAN0TXIDR0_ID24                 _CAN0TXIDR0.Bits.ID24
#define CAN0TXIDR0_ID25                 _CAN0TXIDR0.Bits.ID25
#define CAN0TXIDR0_ID26                 _CAN0TXIDR0.Bits.ID26
#define CAN0TXIDR0_ID27                 _CAN0TXIDR0.Bits.ID27
#define CAN0TXIDR0_ID28                 _CAN0TXIDR0.Bits.ID28
 CAN0TXIDR_ARR Access 4 CAN0TXIDRx registers in an array 
#define CAN0TXIDR_ARR                   ((volatile byte ) &CAN0TXIDR0)

#define CAN0TXIDR0_ID21_MASK            1
#define CAN0TXIDR0_ID22_MASK            2
#define CAN0TXIDR0_ID23_MASK            4
#define CAN0TXIDR0_ID24_MASK            8
#define CAN0TXIDR0_ID25_MASK            16
#define CAN0TXIDR0_ID26_MASK            32
#define CAN0TXIDR0_ID27_MASK            64
#define CAN0TXIDR0_ID28_MASK            128


 CAN0TXIDR1 - MSCAN 0 Transmit Identifier Register 1; 0x00000171 
typedef union {
  byte Byte;
  struct {
    byte ID15        1;                                        Extended format identifier Bit 15 
    byte ID16        1;                                        Extended format identifier Bit 16 
    byte ID17        1;                                        Extended format identifier Bit 17 
    byte IDE         1;                                        ID Extended 
    byte SRR         1;                                        Substitute Remote Request 
    byte ID18        1;                                        Extended format identifier Bit 18 
    byte ID19        1;                                        Extended format identifier Bit 19 
    byte ID20        1;                                        Extended format identifier Bit 20 
  } Bits;
  struct {
    byte grpID_15 3;
    byte         1;
    byte         1;
    byte grpID_18 3;
  } MergedBits;
} CAN0TXIDR1STR;
extern volatile CAN0TXIDR1STR _CAN0TXIDR1 @(REG_BASE + 0x00000171);
#define CAN0TXIDR1                      _CAN0TXIDR1.Byte
#define CAN0TXIDR1_ID15                 _CAN0TXIDR1.Bits.ID15
#define CAN0TXIDR1_ID16                 _CAN0TXIDR1.Bits.ID16
#define CAN0TXIDR1_ID17                 _CAN0TXIDR1.Bits.ID17
#define CAN0TXIDR1_IDE                  _CAN0TXIDR1.Bits.IDE
#define CAN0TXIDR1_SRR                  _CAN0TXIDR1.Bits.SRR
#define CAN0TXIDR1_ID18                 _CAN0TXIDR1.Bits.ID18
#define CAN0TXIDR1_ID19                 _CAN0TXIDR1.Bits.ID19
#define CAN0TXIDR1_ID20                 _CAN0TXIDR1.Bits.ID20
#define CAN0TXIDR1_ID_15                _CAN0TXIDR1.MergedBits.grpID_15
#define CAN0TXIDR1_ID_18                _CAN0TXIDR1.MergedBits.grpID_18
#define CAN0TXIDR1_ID                   CAN0TXIDR1_ID_15

#define CAN0TXIDR1_ID15_MASK            1
#define CAN0TXIDR1_ID16_MASK            2
#define CAN0TXIDR1_ID17_MASK            4
#define CAN0TXIDR1_IDE_MASK             8
#define CAN0TXIDR1_SRR_MASK             16
#define CAN0TXIDR1_ID18_MASK            32
#define CAN0TXIDR1_ID19_MASK            64
#define CAN0TXIDR1_ID20_MASK            128
#define CAN0TXIDR1_ID_15_MASK           7
#define CAN0TXIDR1_ID_15_BITNUM         0
#define CAN0TXIDR1_ID_18_MASK           224
#define CAN0TXIDR1_ID_18_BITNUM         5


 CAN0TXIDR2 - MSCAN 0 Transmit Identifier Register 2; 0x00000172 
typedef union {
  byte Byte;
  struct {
    byte ID7         1;                                        Extended format identifier Bit 7 
    byte ID8         1;                                        Extended format identifier Bit 8 
    byte ID9         1;                                        Extended format identifier Bit 9 
    byte ID10        1;                                        Extended format identifier Bit 10 
    byte ID11        1;                                        Extended format identifier Bit 11 
    byte ID12        1;                                        Extended format identifier Bit 12 
    byte ID13        1;                                        Extended format identifier Bit 13 
    byte ID14        1;                                        Extended format identifier Bit 14 
  } Bits;
} CAN0TXIDR2STR;
extern volatile CAN0TXIDR2STR _CAN0TXIDR2 @(REG_BASE + 0x00000172);
#define CAN0TXIDR2                      _CAN0TXIDR2.Byte
#define CAN0TXIDR2_ID7                  _CAN0TXIDR2.Bits.ID7
#define CAN0TXIDR2_ID8                  _CAN0TXIDR2.Bits.ID8
#define CAN0TXIDR2_ID9                  _CAN0TXIDR2.Bits.ID9
#define CAN0TXIDR2_ID10                 _CAN0TXIDR2.Bits.ID10
#define CAN0TXIDR2_ID11                 _CAN0TXIDR2.Bits.ID11
#define CAN0TXIDR2_ID12                 _CAN0TXIDR2.Bits.ID12
#define CAN0TXIDR2_ID13                 _CAN0TXIDR2.Bits.ID13
#define CAN0TXIDR2_ID14                 _CAN0TXIDR2.Bits.ID14

#define CAN0TXIDR2_ID7_MASK             1
#define CAN0TXIDR2_ID8_MASK             2
#define CAN0TXIDR2_ID9_MASK             4
#define CAN0TXIDR2_ID10_MASK            8
#define CAN0TXIDR2_ID11_MASK            16
#define CAN0TXIDR2_ID12_MASK            32
#define CAN0TXIDR2_ID13_MASK            64
#define CAN0TXIDR2_ID14_MASK            128


 CAN0TXIDR3 - MSCAN 0 Transmit Identifier Register 3; 0x00000173 
typedef union {
  byte Byte;
  struct {
    byte RTR         1;                                        Remote Transmission Request 
    byte ID0         1;                                        Extended format identifier Bit 0 
    byte ID1         1;                                        Extended format identifier Bit 1 
    byte ID2         1;                                        Extended format identifier Bit 2 
    byte ID3         1;                                        Extended format identifier Bit 3 
    byte ID4         1;                                        Extended format identifier Bit 4 
    byte ID5         1;                                        Extended format identifier Bit 5 
    byte ID6         1;                                        Extended format identifier Bit 6 
  } Bits;
  struct {
    byte         1;
    byte grpID   7;
  } MergedBits;
} CAN0TXIDR3STR;
extern volatile CAN0TXIDR3STR _CAN0TXIDR3 @(REG_BASE + 0x00000173);
#define CAN0TXIDR3                      _CAN0TXIDR3.Byte
#define CAN0TXIDR3_RTR                  _CAN0TXIDR3.Bits.RTR
#define CAN0TXIDR3_ID0                  _CAN0TXIDR3.Bits.ID0
#define CAN0TXIDR3_ID1                  _CAN0TXIDR3.Bits.ID1
#define CAN0TXIDR3_ID2                  _CAN0TXIDR3.Bits.ID2
#define CAN0TXIDR3_ID3                  _CAN0TXIDR3.Bits.ID3
#define CAN0TXIDR3_ID4                  _CAN0TXIDR3.Bits.ID4
#define CAN0TXIDR3_ID5                  _CAN0TXIDR3.Bits.ID5
#define CAN0TXIDR3_ID6                  _CAN0TXIDR3.Bits.ID6
#define CAN0TXIDR3_ID                   _CAN0TXIDR3.MergedBits.grpID

#define CAN0TXIDR3_RTR_MASK             1
#define CAN0TXIDR3_ID0_MASK             2
#define CAN0TXIDR3_ID1_MASK             4
#define CAN0TXIDR3_ID2_MASK             8
#define CAN0TXIDR3_ID3_MASK             16
#define CAN0TXIDR3_ID4_MASK             32
#define CAN0TXIDR3_ID5_MASK             64
#define CAN0TXIDR3_ID6_MASK             128
#define CAN0TXIDR3_ID_MASK              254
#define CAN0TXIDR3_ID_BITNUM            1


 CAN0TXDSR0 - MSCAN 0 Transmit Data Segment Register 0; 0x00000174 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0TXDSR0STR;
extern volatile CAN0TXDSR0STR _CAN0TXDSR0 @(REG_BASE + 0x00000174);
#define CAN0TXDSR0                      _CAN0TXDSR0.Byte
#define CAN0TXDSR0_DB0                  _CAN0TXDSR0.Bits.DB0
#define CAN0TXDSR0_DB1                  _CAN0TXDSR0.Bits.DB1
#define CAN0TXDSR0_DB2                  _CAN0TXDSR0.Bits.DB2
#define CAN0TXDSR0_DB3                  _CAN0TXDSR0.Bits.DB3
#define CAN0TXDSR0_DB4                  _CAN0TXDSR0.Bits.DB4
#define CAN0TXDSR0_DB5                  _CAN0TXDSR0.Bits.DB5
#define CAN0TXDSR0_DB6                  _CAN0TXDSR0.Bits.DB6
#define CAN0TXDSR0_DB7                  _CAN0TXDSR0.Bits.DB7
 CAN0TXDSR_ARR Access 8 CAN0TXDSRx registers in an array 
#define CAN0TXDSR_ARR                   ((volatile byte ) &CAN0TXDSR0)

#define CAN0TXDSR0_DB0_MASK             1
#define CAN0TXDSR0_DB1_MASK             2
#define CAN0TXDSR0_DB2_MASK             4
#define CAN0TXDSR0_DB3_MASK             8
#define CAN0TXDSR0_DB4_MASK             16
#define CAN0TXDSR0_DB5_MASK             32
#define CAN0TXDSR0_DB6_MASK             64
#define CAN0TXDSR0_DB7_MASK             128


 CAN0TXDSR1 - MSCAN 0 Transmit Data Segment Register 1; 0x00000175 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0TXDSR1STR;
extern volatile CAN0TXDSR1STR _CAN0TXDSR1 @(REG_BASE + 0x00000175);
#define CAN0TXDSR1                      _CAN0TXDSR1.Byte
#define CAN0TXDSR1_DB0                  _CAN0TXDSR1.Bits.DB0
#define CAN0TXDSR1_DB1                  _CAN0TXDSR1.Bits.DB1
#define CAN0TXDSR1_DB2                  _CAN0TXDSR1.Bits.DB2
#define CAN0TXDSR1_DB3                  _CAN0TXDSR1.Bits.DB3
#define CAN0TXDSR1_DB4                  _CAN0TXDSR1.Bits.DB4
#define CAN0TXDSR1_DB5                  _CAN0TXDSR1.Bits.DB5
#define CAN0TXDSR1_DB6                  _CAN0TXDSR1.Bits.DB6
#define CAN0TXDSR1_DB7                  _CAN0TXDSR1.Bits.DB7

#define CAN0TXDSR1_DB0_MASK             1
#define CAN0TXDSR1_DB1_MASK             2
#define CAN0TXDSR1_DB2_MASK             4
#define CAN0TXDSR1_DB3_MASK             8
#define CAN0TXDSR1_DB4_MASK             16
#define CAN0TXDSR1_DB5_MASK             32
#define CAN0TXDSR1_DB6_MASK             64
#define CAN0TXDSR1_DB7_MASK             128


 CAN0TXDSR2 - MSCAN 0 Transmit Data Segment Register 2; 0x00000176 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0TXDSR2STR;
extern volatile CAN0TXDSR2STR _CAN0TXDSR2 @(REG_BASE + 0x00000176);
#define CAN0TXDSR2                      _CAN0TXDSR2.Byte
#define CAN0TXDSR2_DB0                  _CAN0TXDSR2.Bits.DB0
#define CAN0TXDSR2_DB1                  _CAN0TXDSR2.Bits.DB1
#define CAN0TXDSR2_DB2                  _CAN0TXDSR2.Bits.DB2
#define CAN0TXDSR2_DB3                  _CAN0TXDSR2.Bits.DB3
#define CAN0TXDSR2_DB4                  _CAN0TXDSR2.Bits.DB4
#define CAN0TXDSR2_DB5                  _CAN0TXDSR2.Bits.DB5
#define CAN0TXDSR2_DB6                  _CAN0TXDSR2.Bits.DB6
#define CAN0TXDSR2_DB7                  _CAN0TXDSR2.Bits.DB7

#define CAN0TXDSR2_DB0_MASK             1
#define CAN0TXDSR2_DB1_MASK             2
#define CAN0TXDSR2_DB2_MASK             4
#define CAN0TXDSR2_DB3_MASK             8
#define CAN0TXDSR2_DB4_MASK             16
#define CAN0TXDSR2_DB5_MASK             32
#define CAN0TXDSR2_DB6_MASK             64
#define CAN0TXDSR2_DB7_MASK             128


 CAN0TXDSR3 - MSCAN 0 Transmit Data Segment Register 3; 0x00000177 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0TXDSR3STR;
extern volatile CAN0TXDSR3STR _CAN0TXDSR3 @(REG_BASE + 0x00000177);
#define CAN0TXDSR3                      _CAN0TXDSR3.Byte
#define CAN0TXDSR3_DB0                  _CAN0TXDSR3.Bits.DB0
#define CAN0TXDSR3_DB1                  _CAN0TXDSR3.Bits.DB1
#define CAN0TXDSR3_DB2                  _CAN0TXDSR3.Bits.DB2
#define CAN0TXDSR3_DB3                  _CAN0TXDSR3.Bits.DB3
#define CAN0TXDSR3_DB4                  _CAN0TXDSR3.Bits.DB4
#define CAN0TXDSR3_DB5                  _CAN0TXDSR3.Bits.DB5
#define CAN0TXDSR3_DB6                  _CAN0TXDSR3.Bits.DB6
#define CAN0TXDSR3_DB7                  _CAN0TXDSR3.Bits.DB7

#define CAN0TXDSR3_DB0_MASK             1
#define CAN0TXDSR3_DB1_MASK             2
#define CAN0TXDSR3_DB2_MASK             4
#define CAN0TXDSR3_DB3_MASK             8
#define CAN0TXDSR3_DB4_MASK             16
#define CAN0TXDSR3_DB5_MASK             32
#define CAN0TXDSR3_DB6_MASK             64
#define CAN0TXDSR3_DB7_MASK             128


 CAN0TXDSR4 - MSCAN 0 Transmit Data Segment Register 4; 0x00000178 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0TXDSR4STR;
extern volatile CAN0TXDSR4STR _CAN0TXDSR4 @(REG_BASE + 0x00000178);
#define CAN0TXDSR4                      _CAN0TXDSR4.Byte
#define CAN0TXDSR4_DB0                  _CAN0TXDSR4.Bits.DB0
#define CAN0TXDSR4_DB1                  _CAN0TXDSR4.Bits.DB1
#define CAN0TXDSR4_DB2                  _CAN0TXDSR4.Bits.DB2
#define CAN0TXDSR4_DB3                  _CAN0TXDSR4.Bits.DB3
#define CAN0TXDSR4_DB4                  _CAN0TXDSR4.Bits.DB4
#define CAN0TXDSR4_DB5                  _CAN0TXDSR4.Bits.DB5
#define CAN0TXDSR4_DB6                  _CAN0TXDSR4.Bits.DB6
#define CAN0TXDSR4_DB7                  _CAN0TXDSR4.Bits.DB7

#define CAN0TXDSR4_DB0_MASK             1
#define CAN0TXDSR4_DB1_MASK             2
#define CAN0TXDSR4_DB2_MASK             4
#define CAN0TXDSR4_DB3_MASK             8
#define CAN0TXDSR4_DB4_MASK             16
#define CAN0TXDSR4_DB5_MASK             32
#define CAN0TXDSR4_DB6_MASK             64
#define CAN0TXDSR4_DB7_MASK             128


 CAN0TXDSR5 - MSCAN 0 Transmit Data Segment Register 5; 0x00000179 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0TXDSR5STR;
extern volatile CAN0TXDSR5STR _CAN0TXDSR5 @(REG_BASE + 0x00000179);
#define CAN0TXDSR5                      _CAN0TXDSR5.Byte
#define CAN0TXDSR5_DB0                  _CAN0TXDSR5.Bits.DB0
#define CAN0TXDSR5_DB1                  _CAN0TXDSR5.Bits.DB1
#define CAN0TXDSR5_DB2                  _CAN0TXDSR5.Bits.DB2
#define CAN0TXDSR5_DB3                  _CAN0TXDSR5.Bits.DB3
#define CAN0TXDSR5_DB4                  _CAN0TXDSR5.Bits.DB4
#define CAN0TXDSR5_DB5                  _CAN0TXDSR5.Bits.DB5
#define CAN0TXDSR5_DB6                  _CAN0TXDSR5.Bits.DB6
#define CAN0TXDSR5_DB7                  _CAN0TXDSR5.Bits.DB7

#define CAN0TXDSR5_DB0_MASK             1
#define CAN0TXDSR5_DB1_MASK             2
#define CAN0TXDSR5_DB2_MASK             4
#define CAN0TXDSR5_DB3_MASK             8
#define CAN0TXDSR5_DB4_MASK             16
#define CAN0TXDSR5_DB5_MASK             32
#define CAN0TXDSR5_DB6_MASK             64
#define CAN0TXDSR5_DB7_MASK             128


 CAN0TXDSR6 - MSCAN 0 Transmit Data Segment Register 6; 0x0000017A 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0TXDSR6STR;
extern volatile CAN0TXDSR6STR _CAN0TXDSR6 @(REG_BASE + 0x0000017A);
#define CAN0TXDSR6                      _CAN0TXDSR6.Byte
#define CAN0TXDSR6_DB0                  _CAN0TXDSR6.Bits.DB0
#define CAN0TXDSR6_DB1                  _CAN0TXDSR6.Bits.DB1
#define CAN0TXDSR6_DB2                  _CAN0TXDSR6.Bits.DB2
#define CAN0TXDSR6_DB3                  _CAN0TXDSR6.Bits.DB3
#define CAN0TXDSR6_DB4                  _CAN0TXDSR6.Bits.DB4
#define CAN0TXDSR6_DB5                  _CAN0TXDSR6.Bits.DB5
#define CAN0TXDSR6_DB6                  _CAN0TXDSR6.Bits.DB6
#define CAN0TXDSR6_DB7                  _CAN0TXDSR6.Bits.DB7

#define CAN0TXDSR6_DB0_MASK             1
#define CAN0TXDSR6_DB1_MASK             2
#define CAN0TXDSR6_DB2_MASK             4
#define CAN0TXDSR6_DB3_MASK             8
#define CAN0TXDSR6_DB4_MASK             16
#define CAN0TXDSR6_DB5_MASK             32
#define CAN0TXDSR6_DB6_MASK             64
#define CAN0TXDSR6_DB7_MASK             128


 CAN0TXDSR7 - MSCAN 0 Transmit Data Segment Register 7; 0x0000017B 
typedef union {
  byte Byte;
  struct {
    byte DB0         1;                                        Data Bit 0 
    byte DB1         1;                                        Data Bit 1 
    byte DB2         1;                                        Data Bit 2 
    byte DB3         1;                                        Data Bit 3 
    byte DB4         1;                                        Data Bit 4 
    byte DB5         1;                                        Data Bit 5 
    byte DB6         1;                                        Data Bit 6 
    byte DB7         1;                                        Data Bit 7 
  } Bits;
} CAN0TXDSR7STR;
extern volatile CAN0TXDSR7STR _CAN0TXDSR7 @(REG_BASE + 0x0000017B);
#define CAN0TXDSR7                      _CAN0TXDSR7.Byte
#define CAN0TXDSR7_DB0                  _CAN0TXDSR7.Bits.DB0
#define CAN0TXDSR7_DB1                  _CAN0TXDSR7.Bits.DB1
#define CAN0TXDSR7_DB2                  _CAN0TXDSR7.Bits.DB2
#define CAN0TXDSR7_DB3                  _CAN0TXDSR7.Bits.DB3
#define CAN0TXDSR7_DB4                  _CAN0TXDSR7.Bits.DB4
#define CAN0TXDSR7_DB5                  _CAN0TXDSR7.Bits.DB5
#define CAN0TXDSR7_DB6                  _CAN0TXDSR7.Bits.DB6
#define CAN0TXDSR7_DB7                  _CAN0TXDSR7.Bits.DB7

#define CAN0TXDSR7_DB0_MASK             1
#define CAN0TXDSR7_DB1_MASK             2
#define CAN0TXDSR7_DB2_MASK             4
#define CAN0TXDSR7_DB3_MASK             8
#define CAN0TXDSR7_DB4_MASK             16
#define CAN0TXDSR7_DB5_MASK             32
#define CAN0TXDSR7_DB6_MASK             64
#define CAN0TXDSR7_DB7_MASK             128


 CAN0TXDLR - MSCAN 0 Transmit Data Length Register; 0x0000017C 
typedef union {
  byte Byte;
  struct {
    byte DLC0        1;                                        Data Length Code Bit 0 
    byte DLC1        1;                                        Data Length Code Bit 1 
    byte DLC2        1;                                        Data Length Code Bit 2 
    byte DLC3        1;                                        Data Length Code Bit 3 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpDLC  4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} CAN0TXDLRSTR;
extern volatile CAN0TXDLRSTR _CAN0TXDLR @(REG_BASE + 0x0000017C);
#define CAN0TXDLR                       _CAN0TXDLR.Byte
#define CAN0TXDLR_DLC0                  _CAN0TXDLR.Bits.DLC0
#define CAN0TXDLR_DLC1                  _CAN0TXDLR.Bits.DLC1
#define CAN0TXDLR_DLC2                  _CAN0TXDLR.Bits.DLC2
#define CAN0TXDLR_DLC3                  _CAN0TXDLR.Bits.DLC3
#define CAN0TXDLR_DLC                   _CAN0TXDLR.MergedBits.grpDLC

#define CAN0TXDLR_DLC0_MASK             1
#define CAN0TXDLR_DLC1_MASK             2
#define CAN0TXDLR_DLC2_MASK             4
#define CAN0TXDLR_DLC3_MASK             8
#define CAN0TXDLR_DLC_MASK              15
#define CAN0TXDLR_DLC_BITNUM            0


 CAN0TXTBPR - MSCAN 0 Transmit Buffer Priority; 0x0000017D 
typedef union {
  byte Byte;
  struct {
    byte PRIO0       1;                                        Transmit Buffer Priority Bit 0 
    byte PRIO1       1;                                        Transmit Buffer Priority Bit 1 
    byte PRIO2       1;                                        Transmit Buffer Priority Bit 2 
    byte PRIO3       1;                                        Transmit Buffer Priority Bit 3 
    byte PRIO4       1;                                        Transmit Buffer Priority Bit 4 
    byte PRIO5       1;                                        Transmit Buffer Priority Bit 5 
    byte PRIO6       1;                                        Transmit Buffer Priority Bit 6 
    byte PRIO7       1;                                        Transmit Buffer Priority Bit 7 
  } Bits;
} CAN0TXTBPRSTR;
extern volatile CAN0TXTBPRSTR _CAN0TXTBPR @(REG_BASE + 0x0000017D);
#define CAN0TXTBPR                      _CAN0TXTBPR.Byte
#define CAN0TXTBPR_PRIO0                _CAN0TXTBPR.Bits.PRIO0
#define CAN0TXTBPR_PRIO1                _CAN0TXTBPR.Bits.PRIO1
#define CAN0TXTBPR_PRIO2                _CAN0TXTBPR.Bits.PRIO2
#define CAN0TXTBPR_PRIO3                _CAN0TXTBPR.Bits.PRIO3
#define CAN0TXTBPR_PRIO4                _CAN0TXTBPR.Bits.PRIO4
#define CAN0TXTBPR_PRIO5                _CAN0TXTBPR.Bits.PRIO5
#define CAN0TXTBPR_PRIO6                _CAN0TXTBPR.Bits.PRIO6
#define CAN0TXTBPR_PRIO7                _CAN0TXTBPR.Bits.PRIO7

#define CAN0TXTBPR_PRIO0_MASK           1
#define CAN0TXTBPR_PRIO1_MASK           2
#define CAN0TXTBPR_PRIO2_MASK           4
#define CAN0TXTBPR_PRIO3_MASK           8
#define CAN0TXTBPR_PRIO4_MASK           16
#define CAN0TXTBPR_PRIO5_MASK           32
#define CAN0TXTBPR_PRIO6_MASK           64
#define CAN0TXTBPR_PRIO7_MASK           128


 CAN0TXTSR - MSCAN 0 Transmit Time Stamp Register; 0x0000017E 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     CAN0TXTSRH - MSCAN 0 Transmit Time Stamp Register High; 0x0000017E 
    union {
      byte Byte;
      struct {
        byte TSR8        1;                                        Time Stamp Bit 8 
        byte TSR9        1;                                        Time Stamp Bit 9 
        byte TSR10       1;                                        Time Stamp Bit 10 
        byte TSR11       1;                                        Time Stamp Bit 11 
        byte TSR12       1;                                        Time Stamp Bit 12 
        byte TSR13       1;                                        Time Stamp Bit 13 
        byte TSR14       1;                                        Time Stamp Bit 14 
        byte TSR15       1;                                        Time Stamp Bit 15 
      } Bits;
    } CAN0TXTSRHSTR;
    #define CAN0TXTSRH                  _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Byte
    #define CAN0TXTSRH_TSR8             _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR8
    #define CAN0TXTSRH_TSR9             _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR9
    #define CAN0TXTSRH_TSR10            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR10
    #define CAN0TXTSRH_TSR11            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR11
    #define CAN0TXTSRH_TSR12            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR12
    #define CAN0TXTSRH_TSR13            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR13
    #define CAN0TXTSRH_TSR14            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR14
    #define CAN0TXTSRH_TSR15            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR15
    
    
    #define CAN0TXTSRH_TSR8_MASK        1
    #define CAN0TXTSRH_TSR9_MASK        2
    #define CAN0TXTSRH_TSR10_MASK       4
    #define CAN0TXTSRH_TSR11_MASK       8
    #define CAN0TXTSRH_TSR12_MASK       16
    #define CAN0TXTSRH_TSR13_MASK       32
    #define CAN0TXTSRH_TSR14_MASK       64
    #define CAN0TXTSRH_TSR15_MASK       128


     CAN0TXTSRL - MSCAN 0 Transmit Time Stamp Register Low; 0x0000017F 
    union {
      byte Byte;
      struct {
        byte TSR0        1;                                        Time Stamp Bit 0 
        byte TSR1        1;                                        Time Stamp Bit 1 
        byte TSR2        1;                                        Time Stamp Bit 2 
        byte TSR3        1;                                        Time Stamp Bit 3 
        byte TSR4        1;                                        Time Stamp Bit 4 
        byte TSR5        1;                                        Time Stamp Bit 5 
        byte TSR6        1;                                        Time Stamp Bit 6 
        byte TSR7        1;                                        Time Stamp Bit 7 
      } Bits;
    } CAN0TXTSRLSTR;
    #define CAN0TXTSRL                  _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Byte
    #define CAN0TXTSRL_TSR0             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR0
    #define CAN0TXTSRL_TSR1             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR1
    #define CAN0TXTSRL_TSR2             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR2
    #define CAN0TXTSRL_TSR3             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR3
    #define CAN0TXTSRL_TSR4             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR4
    #define CAN0TXTSRL_TSR5             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR5
    #define CAN0TXTSRL_TSR6             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR6
    #define CAN0TXTSRL_TSR7             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR7
    
    
    #define CAN0TXTSRL_TSR0_MASK        1
    #define CAN0TXTSRL_TSR1_MASK        2
    #define CAN0TXTSRL_TSR2_MASK        4
    #define CAN0TXTSRL_TSR3_MASK        8
    #define CAN0TXTSRL_TSR4_MASK        16
    #define CAN0TXTSRL_TSR5_MASK        32
    #define CAN0TXTSRL_TSR6_MASK        64
    #define CAN0TXTSRL_TSR7_MASK        128

  } Overlap_STR;

  struct {
    word TSR0        1;                                        Time Stamp Bit 0 
    word TSR1        1;                                        Time Stamp Bit 1 
    word TSR2        1;                                        Time Stamp Bit 2 
    word TSR3        1;                                        Time Stamp Bit 3 
    word TSR4        1;                                        Time Stamp Bit 4 
    word TSR5        1;                                        Time Stamp Bit 5 
    word TSR6        1;                                        Time Stamp Bit 6 
    word TSR7        1;                                        Time Stamp Bit 7 
    word TSR8        1;                                        Time Stamp Bit 8 
    word TSR9        1;                                        Time Stamp Bit 9 
    word TSR10       1;                                        Time Stamp Bit 10 
    word TSR11       1;                                        Time Stamp Bit 11 
    word TSR12       1;                                        Time Stamp Bit 12 
    word TSR13       1;                                        Time Stamp Bit 13 
    word TSR14       1;                                        Time Stamp Bit 14 
    word TSR15       1;                                        Time Stamp Bit 15 
  } Bits;
} CAN0TXTSRSTR;
extern volatile CAN0TXTSRSTR _CAN0TXTSR @(REG_BASE + 0x0000017E);
#define CAN0TXTSR                       _CAN0TXTSR.Word
#define CAN0TXTSR_TSR0                  _CAN0TXTSR.Bits.TSR0
#define CAN0TXTSR_TSR1                  _CAN0TXTSR.Bits.TSR1
#define CAN0TXTSR_TSR2                  _CAN0TXTSR.Bits.TSR2
#define CAN0TXTSR_TSR3                  _CAN0TXTSR.Bits.TSR3
#define CAN0TXTSR_TSR4                  _CAN0TXTSR.Bits.TSR4
#define CAN0TXTSR_TSR5                  _CAN0TXTSR.Bits.TSR5
#define CAN0TXTSR_TSR6                  _CAN0TXTSR.Bits.TSR6
#define CAN0TXTSR_TSR7                  _CAN0TXTSR.Bits.TSR7
#define CAN0TXTSR_TSR8                  _CAN0TXTSR.Bits.TSR8
#define CAN0TXTSR_TSR9                  _CAN0TXTSR.Bits.TSR9
#define CAN0TXTSR_TSR10                 _CAN0TXTSR.Bits.TSR10
#define CAN0TXTSR_TSR11                 _CAN0TXTSR.Bits.TSR11
#define CAN0TXTSR_TSR12                 _CAN0TXTSR.Bits.TSR12
#define CAN0TXTSR_TSR13                 _CAN0TXTSR.Bits.TSR13
#define CAN0TXTSR_TSR14                 _CAN0TXTSR.Bits.TSR14
#define CAN0TXTSR_TSR15                 _CAN0TXTSR.Bits.TSR15

#define CAN0TXTSR_TSR0_MASK             1
#define CAN0TXTSR_TSR1_MASK             2
#define CAN0TXTSR_TSR2_MASK             4
#define CAN0TXTSR_TSR3_MASK             8
#define CAN0TXTSR_TSR4_MASK             16
#define CAN0TXTSR_TSR5_MASK             32
#define CAN0TXTSR_TSR6_MASK             64
#define CAN0TXTSR_TSR7_MASK             128
#define CAN0TXTSR_TSR8_MASK             256
#define CAN0TXTSR_TSR9_MASK             512
#define CAN0TXTSR_TSR10_MASK            1024
#define CAN0TXTSR_TSR11_MASK            2048
#define CAN0TXTSR_TSR12_MASK            4096
#define CAN0TXTSR_TSR13_MASK            8192
#define CAN0TXTSR_TSR14_MASK            16384
#define CAN0TXTSR_TSR15_MASK            32768


 PTT - Port T IO Register; 0x00000240 
typedef union {
  byte Byte;
  struct {
    byte PTT0        1;                                        Port T Bit 0 
    byte PTT1        1;                                        Port T Bit 1 
    byte PTT2        1;                                        Port T Bit 2 
    byte PTT3        1;                                        Port T Bit 3 
    byte PTT4        1;                                        Port T Bit 4 
    byte PTT5        1;                                        Port T Bit 5 
    byte PTT6        1;                                        Port T Bit 6 
    byte PTT7        1;                                        Port T Bit 7 
  } Bits;
} PTTSTR;
extern volatile PTTSTR _PTT @(REG_BASE + 0x00000240);
#define PTT                             _PTT.Byte
#define PTT_PTT0                        _PTT.Bits.PTT0
#define PTT_PTT1                        _PTT.Bits.PTT1
#define PTT_PTT2                        _PTT.Bits.PTT2
#define PTT_PTT3                        _PTT.Bits.PTT3
#define PTT_PTT4                        _PTT.Bits.PTT4
#define PTT_PTT5                        _PTT.Bits.PTT5
#define PTT_PTT6                        _PTT.Bits.PTT6
#define PTT_PTT7                        _PTT.Bits.PTT7

#define PTT_PTT0_MASK                   1
#define PTT_PTT1_MASK                   2
#define PTT_PTT2_MASK                   4
#define PTT_PTT3_MASK                   8
#define PTT_PTT4_MASK                   16
#define PTT_PTT5_MASK                   32
#define PTT_PTT6_MASK                   64
#define PTT_PTT7_MASK                   128


 PTIT - Port T Input Register; 0x00000241 
typedef union {
  byte Byte;
  struct {
    byte PTIT0       1;                                        Port T Bit 0 
    byte PTIT1       1;                                        Port T Bit 1 
    byte PTIT2       1;                                        Port T Bit 2 
    byte PTIT3       1;                                        Port T Bit 3 
    byte PTIT4       1;                                        Port T Bit 4 
    byte PTIT5       1;                                        Port T Bit 5 
    byte PTIT6       1;                                        Port T Bit 6 
    byte PTIT7       1;                                        Port T Bit 7 
  } Bits;
} PTITSTR;
extern volatile PTITSTR _PTIT @(REG_BASE + 0x00000241);
#define PTIT                            _PTIT.Byte
#define PTIT_PTIT0                      _PTIT.Bits.PTIT0
#define PTIT_PTIT1                      _PTIT.Bits.PTIT1
#define PTIT_PTIT2                      _PTIT.Bits.PTIT2
#define PTIT_PTIT3                      _PTIT.Bits.PTIT3
#define PTIT_PTIT4                      _PTIT.Bits.PTIT4
#define PTIT_PTIT5                      _PTIT.Bits.PTIT5
#define PTIT_PTIT6                      _PTIT.Bits.PTIT6
#define PTIT_PTIT7                      _PTIT.Bits.PTIT7

#define PTIT_PTIT0_MASK                 1
#define PTIT_PTIT1_MASK                 2
#define PTIT_PTIT2_MASK                 4
#define PTIT_PTIT3_MASK                 8
#define PTIT_PTIT4_MASK                 16
#define PTIT_PTIT5_MASK                 32
#define PTIT_PTIT6_MASK                 64
#define PTIT_PTIT7_MASK                 128


 DDRT - Port T Data Direction Register; 0x00000242 
typedef union {
  byte Byte;
  struct {
    byte DDRT0       1;                                        Data Direction Port T Bit 0 
    byte DDRT1       1;                                        Data Direction Port T Bit 1 
    byte DDRT2       1;                                        Data Direction Port T Bit 2 
    byte DDRT3       1;                                        Data Direction Port T Bit 3 
    byte DDRT4       1;                                        Data Direction Port T Bit 4 
    byte DDRT5       1;                                        Data Direction Port T Bit 5 
    byte DDRT6       1;                                        Data Direction Port T Bit 6 
    byte DDRT7       1;                                        Data Direction Port T Bit 7 
  } Bits;
} DDRTSTR;
extern volatile DDRTSTR _DDRT @(REG_BASE + 0x00000242);
#define DDRT                            _DDRT.Byte
#define DDRT_DDRT0                      _DDRT.Bits.DDRT0
#define DDRT_DDRT1                      _DDRT.Bits.DDRT1
#define DDRT_DDRT2                      _DDRT.Bits.DDRT2
#define DDRT_DDRT3                      _DDRT.Bits.DDRT3
#define DDRT_DDRT4                      _DDRT.Bits.DDRT4
#define DDRT_DDRT5                      _DDRT.Bits.DDRT5
#define DDRT_DDRT6                      _DDRT.Bits.DDRT6
#define DDRT_DDRT7                      _DDRT.Bits.DDRT7

#define DDRT_DDRT0_MASK                 1
#define DDRT_DDRT1_MASK                 2
#define DDRT_DDRT2_MASK                 4
#define DDRT_DDRT3_MASK                 8
#define DDRT_DDRT4_MASK                 16
#define DDRT_DDRT5_MASK                 32
#define DDRT_DDRT6_MASK                 64
#define DDRT_DDRT7_MASK                 128


 RDRT - Port T Reduced Drive Register; 0x00000243 
typedef union {
  byte Byte;
  struct {
    byte RDRT0       1;                                        Reduced Drive Port T Bit 0 
    byte RDRT1       1;                                        Reduced Drive Port T Bit 1 
    byte RDRT2       1;                                        Reduced Drive Port T Bit 2 
    byte RDRT3       1;                                        Reduced Drive Port T Bit 3 
    byte RDRT4       1;                                        Reduced Drive Port T Bit 4 
    byte RDRT5       1;                                        Reduced Drive Port T Bit 5 
    byte RDRT6       1;                                        Reduced Drive Port T Bit 6 
    byte RDRT7       1;                                        Reduced Drive Port T Bit 7 
  } Bits;
} RDRTSTR;
extern volatile RDRTSTR _RDRT @(REG_BASE + 0x00000243);
#define RDRT                            _RDRT.Byte
#define RDRT_RDRT0                      _RDRT.Bits.RDRT0
#define RDRT_RDRT1                      _RDRT.Bits.RDRT1
#define RDRT_RDRT2                      _RDRT.Bits.RDRT2
#define RDRT_RDRT3                      _RDRT.Bits.RDRT3
#define RDRT_RDRT4                      _RDRT.Bits.RDRT4
#define RDRT_RDRT5                      _RDRT.Bits.RDRT5
#define RDRT_RDRT6                      _RDRT.Bits.RDRT6
#define RDRT_RDRT7                      _RDRT.Bits.RDRT7

#define RDRT_RDRT0_MASK                 1
#define RDRT_RDRT1_MASK                 2
#define RDRT_RDRT2_MASK                 4
#define RDRT_RDRT3_MASK                 8
#define RDRT_RDRT4_MASK                 16
#define RDRT_RDRT5_MASK                 32
#define RDRT_RDRT6_MASK                 64
#define RDRT_RDRT7_MASK                 128


 PERT - Port T Pull Device Enable Register; 0x00000244 
typedef union {
  byte Byte;
  struct {
    byte PERT0       1;                                        Pull Device Enable Port T Bit 0 
    byte PERT1       1;                                        Pull Device Enable Port T Bit 1 
    byte PERT2       1;                                        Pull Device Enable Port T Bit 2 
    byte PERT3       1;                                        Pull Device Enable Port T Bit 3 
    byte PERT4       1;                                        Pull Device Enable Port T Bit 4 
    byte PERT5       1;                                        Pull Device Enable Port T Bit 5 
    byte PERT6       1;                                        Pull Device Enable Port T Bit 6 
    byte PERT7       1;                                        Pull Device Enable Port T Bit 7 
  } Bits;
} PERTSTR;
extern volatile PERTSTR _PERT @(REG_BASE + 0x00000244);
#define PERT                            _PERT.Byte
#define PERT_PERT0                      _PERT.Bits.PERT0
#define PERT_PERT1                      _PERT.Bits.PERT1
#define PERT_PERT2                      _PERT.Bits.PERT2
#define PERT_PERT3                      _PERT.Bits.PERT3
#define PERT_PERT4                      _PERT.Bits.PERT4
#define PERT_PERT5                      _PERT.Bits.PERT5
#define PERT_PERT6                      _PERT.Bits.PERT6
#define PERT_PERT7                      _PERT.Bits.PERT7

#define PERT_PERT0_MASK                 1
#define PERT_PERT1_MASK                 2
#define PERT_PERT2_MASK                 4
#define PERT_PERT3_MASK                 8
#define PERT_PERT4_MASK                 16
#define PERT_PERT5_MASK                 32
#define PERT_PERT6_MASK                 64
#define PERT_PERT7_MASK                 128


 PPST - Port T Polarity Select Register; 0x00000245 
typedef union {
  byte Byte;
  struct {
    byte PPST0       1;                                        Pull Select Port T Bit 0 
    byte PPST1       1;                                        Pull Select Port T Bit 1 
    byte PPST2       1;                                        Pull Select Port T Bit 2 
    byte PPST3       1;                                        Pull Select Port T Bit 3 
    byte PPST4       1;                                        Pull Select Port T Bit 4 
    byte PPST5       1;                                        Pull Select Port T Bit 5 
    byte PPST6       1;                                        Pull Select Port T Bit 6 
    byte PPST7       1;                                        Pull Select Port T Bit 7 
  } Bits;
} PPSTSTR;
extern volatile PPSTSTR _PPST @(REG_BASE + 0x00000245);
#define PPST                            _PPST.Byte
#define PPST_PPST0                      _PPST.Bits.PPST0
#define PPST_PPST1                      _PPST.Bits.PPST1
#define PPST_PPST2                      _PPST.Bits.PPST2
#define PPST_PPST3                      _PPST.Bits.PPST3
#define PPST_PPST4                      _PPST.Bits.PPST4
#define PPST_PPST5                      _PPST.Bits.PPST5
#define PPST_PPST6                      _PPST.Bits.PPST6
#define PPST_PPST7                      _PPST.Bits.PPST7

#define PPST_PPST0_MASK                 1
#define PPST_PPST1_MASK                 2
#define PPST_PPST2_MASK                 4
#define PPST_PPST3_MASK                 8
#define PPST_PPST4_MASK                 16
#define PPST_PPST5_MASK                 32
#define PPST_PPST6_MASK                 64
#define PPST_PPST7_MASK                 128


 PTS - Port S IO Register; 0x00000248 
typedef union {
  byte Byte;
  struct {
    byte PTS0        1;                                        Port S Bit 0 
    byte PTS1        1;                                        Port S Bit 1 
    byte PTS2        1;                                        Port S Bit 2 
    byte PTS3        1;                                        Port S Bit 3 
    byte PTS4        1;                                        Port S Bit 4 
    byte PTS5        1;                                        Port S Bit 5 
    byte PTS6        1;                                        Port S Bit 6 
    byte PTS7        1;                                        Port S Bit 7 
  } Bits;
} PTSSTR;
extern volatile PTSSTR _PTS @(REG_BASE + 0x00000248);
#define PTS                             _PTS.Byte
#define PTS_PTS0                        _PTS.Bits.PTS0
#define PTS_PTS1                        _PTS.Bits.PTS1
#define PTS_PTS2                        _PTS.Bits.PTS2
#define PTS_PTS3                        _PTS.Bits.PTS3
#define PTS_PTS4                        _PTS.Bits.PTS4
#define PTS_PTS5                        _PTS.Bits.PTS5
#define PTS_PTS6                        _PTS.Bits.PTS6
#define PTS_PTS7                        _PTS.Bits.PTS7

#define PTS_PTS0_MASK                   1
#define PTS_PTS1_MASK                   2
#define PTS_PTS2_MASK                   4
#define PTS_PTS3_MASK                   8
#define PTS_PTS4_MASK                   16
#define PTS_PTS5_MASK                   32
#define PTS_PTS6_MASK                   64
#define PTS_PTS7_MASK                   128


 PTIS - Port S Input Register; 0x00000249 
typedef union {
  byte Byte;
  struct {
    byte PTIS0       1;                                        Port S Bit 0 
    byte PTIS1       1;                                        Port S Bit 1 
    byte PTIS2       1;                                        Port S Bit 2 
    byte PTIS3       1;                                        Port S Bit 3 
    byte PTIS4       1;                                        Port S Bit 4 
    byte PTIS5       1;                                        Port S Bit 5 
    byte PTIS6       1;                                        Port S Bit 6 
    byte PTIS7       1;                                        Port S Bit 7 
  } Bits;
} PTISSTR;
extern volatile PTISSTR _PTIS @(REG_BASE + 0x00000249);
#define PTIS                            _PTIS.Byte
#define PTIS_PTIS0                      _PTIS.Bits.PTIS0
#define PTIS_PTIS1                      _PTIS.Bits.PTIS1
#define PTIS_PTIS2                      _PTIS.Bits.PTIS2
#define PTIS_PTIS3                      _PTIS.Bits.PTIS3
#define PTIS_PTIS4                      _PTIS.Bits.PTIS4
#define PTIS_PTIS5                      _PTIS.Bits.PTIS5
#define PTIS_PTIS6                      _PTIS.Bits.PTIS6
#define PTIS_PTIS7                      _PTIS.Bits.PTIS7

#define PTIS_PTIS0_MASK                 1
#define PTIS_PTIS1_MASK                 2
#define PTIS_PTIS2_MASK                 4
#define PTIS_PTIS3_MASK                 8
#define PTIS_PTIS4_MASK                 16
#define PTIS_PTIS5_MASK                 32
#define PTIS_PTIS6_MASK                 64
#define PTIS_PTIS7_MASK                 128


 DDRS - Port S Data Direction Register; 0x0000024A 
typedef union {
  byte Byte;
  struct {
    byte DDRS0       1;                                        Data Direction Port S Bit 0 
    byte DDRS1       1;                                        Data Direction Port S Bit 1 
    byte DDRS2       1;                                        Data Direction Port S Bit 2 
    byte DDRS3       1;                                        Data Direction Port S Bit 3 
    byte DDRS4       1;                                        Data Direction Port S Bit 4 
    byte DDRS5       1;                                        Data Direction Port S Bit 5 
    byte DDRS6       1;                                        Data Direction Port S Bit 6 
    byte DDRS7       1;                                        Data Direction Port S Bit 7 
  } Bits;
} DDRSSTR;
extern volatile DDRSSTR _DDRS @(REG_BASE + 0x0000024A);
#define DDRS                            _DDRS.Byte
#define DDRS_DDRS0                      _DDRS.Bits.DDRS0
#define DDRS_DDRS1                      _DDRS.Bits.DDRS1
#define DDRS_DDRS2                      _DDRS.Bits.DDRS2
#define DDRS_DDRS3                      _DDRS.Bits.DDRS3
#define DDRS_DDRS4                      _DDRS.Bits.DDRS4
#define DDRS_DDRS5                      _DDRS.Bits.DDRS5
#define DDRS_DDRS6                      _DDRS.Bits.DDRS6
#define DDRS_DDRS7                      _DDRS.Bits.DDRS7

#define DDRS_DDRS0_MASK                 1
#define DDRS_DDRS1_MASK                 2
#define DDRS_DDRS2_MASK                 4
#define DDRS_DDRS3_MASK                 8
#define DDRS_DDRS4_MASK                 16
#define DDRS_DDRS5_MASK                 32
#define DDRS_DDRS6_MASK                 64
#define DDRS_DDRS7_MASK                 128


 RDRS - Port S Reduced Drive Register; 0x0000024B 
typedef union {
  byte Byte;
  struct {
    byte RDRS0       1;                                        Reduced Drive Port S Bit 0 
    byte RDRS1       1;                                        Reduced Drive Port S Bit 1 
    byte RDRS2       1;                                        Reduced Drive Port S Bit 2 
    byte RDRS3       1;                                        Reduced Drive Port S Bit 3 
    byte RDRS4       1;                                        Reduced Drive Port S Bit 4 
    byte RDRS5       1;                                        Reduced Drive Port S Bit 5 
    byte RDRS6       1;                                        Reduced Drive Port S Bit 6 
    byte RDRS7       1;                                        Reduced Drive Port S Bit 7 
  } Bits;
} RDRSSTR;
extern volatile RDRSSTR _RDRS @(REG_BASE + 0x0000024B);
#define RDRS                            _RDRS.Byte
#define RDRS_RDRS0                      _RDRS.Bits.RDRS0
#define RDRS_RDRS1                      _RDRS.Bits.RDRS1
#define RDRS_RDRS2                      _RDRS.Bits.RDRS2
#define RDRS_RDRS3                      _RDRS.Bits.RDRS3
#define RDRS_RDRS4                      _RDRS.Bits.RDRS4
#define RDRS_RDRS5                      _RDRS.Bits.RDRS5
#define RDRS_RDRS6                      _RDRS.Bits.RDRS6
#define RDRS_RDRS7                      _RDRS.Bits.RDRS7

#define RDRS_RDRS0_MASK                 1
#define RDRS_RDRS1_MASK                 2
#define RDRS_RDRS2_MASK                 4
#define RDRS_RDRS3_MASK                 8
#define RDRS_RDRS4_MASK                 16
#define RDRS_RDRS5_MASK                 32
#define RDRS_RDRS6_MASK                 64
#define RDRS_RDRS7_MASK                 128


 PERS - Port S Pull Device Enable Register; 0x0000024C 
typedef union {
  byte Byte;
  struct {
    byte PERS0       1;                                        Pull Device Enable Port S Bit 0 
    byte PERS1       1;                                        Pull Device Enable Port S Bit 1 
    byte PERS2       1;                                        Pull Device Enable Port S Bit 2 
    byte PERS3       1;                                        Pull Device Enable Port S Bit 3 
    byte PERS4       1;                                        Pull Device Enable Port S Bit 4 
    byte PERS5       1;                                        Pull Device Enable Port S Bit 5 
    byte PERS6       1;                                        Pull Device Enable Port S Bit 6 
    byte PERS7       1;                                        Pull Device Enable Port S Bit 7 
  } Bits;
} PERSSTR;
extern volatile PERSSTR _PERS @(REG_BASE + 0x0000024C);
#define PERS                            _PERS.Byte
#define PERS_PERS0                      _PERS.Bits.PERS0
#define PERS_PERS1                      _PERS.Bits.PERS1
#define PERS_PERS2                      _PERS.Bits.PERS2
#define PERS_PERS3                      _PERS.Bits.PERS3
#define PERS_PERS4                      _PERS.Bits.PERS4
#define PERS_PERS5                      _PERS.Bits.PERS5
#define PERS_PERS6                      _PERS.Bits.PERS6
#define PERS_PERS7                      _PERS.Bits.PERS7

#define PERS_PERS0_MASK                 1
#define PERS_PERS1_MASK                 2
#define PERS_PERS2_MASK                 4
#define PERS_PERS3_MASK                 8
#define PERS_PERS4_MASK                 16
#define PERS_PERS5_MASK                 32
#define PERS_PERS6_MASK                 64
#define PERS_PERS7_MASK                 128


 PPSS - Port S Polarity Select Register; 0x0000024D 
typedef union {
  byte Byte;
  struct {
    byte PPSS0       1;                                        Pull Select Port S Bit 0 
    byte PPSS1       1;                                        Pull Select Port S Bit 1 
    byte PPSS2       1;                                        Pull Select Port S Bit 2 
    byte PPSS3       1;                                        Pull Select Port S Bit 3 
    byte PPSS4       1;                                        Pull Select Port S Bit 4 
    byte PPSS5       1;                                        Pull Select Port S Bit 5 
    byte PPSS6       1;                                        Pull Select Port S Bit 6 
    byte PPSS7       1;                                        Pull Select Port S Bit 7 
  } Bits;
} PPSSSTR;
extern volatile PPSSSTR _PPSS @(REG_BASE + 0x0000024D);
#define PPSS                            _PPSS.Byte
#define PPSS_PPSS0                      _PPSS.Bits.PPSS0
#define PPSS_PPSS1                      _PPSS.Bits.PPSS1
#define PPSS_PPSS2                      _PPSS.Bits.PPSS2
#define PPSS_PPSS3                      _PPSS.Bits.PPSS3
#define PPSS_PPSS4                      _PPSS.Bits.PPSS4
#define PPSS_PPSS5                      _PPSS.Bits.PPSS5
#define PPSS_PPSS6                      _PPSS.Bits.PPSS6
#define PPSS_PPSS7                      _PPSS.Bits.PPSS7

#define PPSS_PPSS0_MASK                 1
#define PPSS_PPSS1_MASK                 2
#define PPSS_PPSS2_MASK                 4
#define PPSS_PPSS3_MASK                 8
#define PPSS_PPSS4_MASK                 16
#define PPSS_PPSS5_MASK                 32
#define PPSS_PPSS6_MASK                 64
#define PPSS_PPSS7_MASK                 128


 WOMS - Port S Wired-Or Mode Register; 0x0000024E 
typedef union {
  byte Byte;
  struct {
    byte WOMS0       1;                                        Wired-Or Mode Port S Bit 0 
    byte WOMS1       1;                                        Wired-Or Mode Port S Bit 1 
    byte WOMS2       1;                                        Wired-Or Mode Port S Bit 2 
    byte WOMS3       1;                                        Wired-Or Mode Port S Bit 3 
    byte WOMS4       1;                                        Wired-Or Mode Port S Bit 4 
    byte WOMS5       1;                                        Wired-Or Mode Port S Bit 5 
    byte WOMS6       1;                                        Wired-Or Mode Port S Bit 6 
    byte WOMS7       1;                                        Wired-Or Mode Port S Bit 7 
  } Bits;
} WOMSSTR;
extern volatile WOMSSTR _WOMS @(REG_BASE + 0x0000024E);
#define WOMS                            _WOMS.Byte
#define WOMS_WOMS0                      _WOMS.Bits.WOMS0
#define WOMS_WOMS1                      _WOMS.Bits.WOMS1
#define WOMS_WOMS2                      _WOMS.Bits.WOMS2
#define WOMS_WOMS3                      _WOMS.Bits.WOMS3
#define WOMS_WOMS4                      _WOMS.Bits.WOMS4
#define WOMS_WOMS5                      _WOMS.Bits.WOMS5
#define WOMS_WOMS6                      _WOMS.Bits.WOMS6
#define WOMS_WOMS7                      _WOMS.Bits.WOMS7

#define WOMS_WOMS0_MASK                 1
#define WOMS_WOMS1_MASK                 2
#define WOMS_WOMS2_MASK                 4
#define WOMS_WOMS3_MASK                 8
#define WOMS_WOMS4_MASK                 16
#define WOMS_WOMS5_MASK                 32
#define WOMS_WOMS6_MASK                 64
#define WOMS_WOMS7_MASK                 128


 PTM - Port M IO Register; 0x00000250 
typedef union {
  byte Byte;
  struct {
    byte PTM0        1;                                        Port M Bit 0 
    byte PTM1        1;                                        Port M Bit 1 
    byte PTM2        1;                                        Port M Bit 2 
    byte PTM3        1;                                        Port M Bit 3 
    byte PTM4        1;                                        Port M Bit 4 
    byte PTM5        1;                                        Port M Bit 5 
    byte PTM6        1;                                        Port M Bit 6 
    byte PTM7        1;                                        Port M Bit 7 
  } Bits;
} PTMSTR;
extern volatile PTMSTR _PTM @(REG_BASE + 0x00000250);
#define PTM                             _PTM.Byte
#define PTM_PTM0                        _PTM.Bits.PTM0
#define PTM_PTM1                        _PTM.Bits.PTM1
#define PTM_PTM2                        _PTM.Bits.PTM2
#define PTM_PTM3                        _PTM.Bits.PTM3
#define PTM_PTM4                        _PTM.Bits.PTM4
#define PTM_PTM5                        _PTM.Bits.PTM5
#define PTM_PTM6                        _PTM.Bits.PTM6
#define PTM_PTM7                        _PTM.Bits.PTM7

#define PTM_PTM0_MASK                   1
#define PTM_PTM1_MASK                   2
#define PTM_PTM2_MASK                   4
#define PTM_PTM3_MASK                   8
#define PTM_PTM4_MASK                   16
#define PTM_PTM5_MASK                   32
#define PTM_PTM6_MASK                   64
#define PTM_PTM7_MASK                   128


 PTIM - Port M Input Register; 0x00000251 
typedef union {
  byte Byte;
  struct {
    byte PTIM0       1;                                        Port M Bit 0 
    byte PTIM1       1;                                        Port M Bit 1 
    byte PTIM2       1;                                        Port M Bit 2 
    byte PTIM3       1;                                        Port M Bit 3 
    byte PTIM4       1;                                        Port M Bit 4 
    byte PTIM5       1;                                        Port M Bit 5 
    byte PTIM6       1;                                        Port M Bit 6 
    byte PTIM7       1;                                        Port M Bit 7 
  } Bits;
} PTIMSTR;
extern volatile PTIMSTR _PTIM @(REG_BASE + 0x00000251);
#define PTIM                            _PTIM.Byte
#define PTIM_PTIM0                      _PTIM.Bits.PTIM0
#define PTIM_PTIM1                      _PTIM.Bits.PTIM1
#define PTIM_PTIM2                      _PTIM.Bits.PTIM2
#define PTIM_PTIM3                      _PTIM.Bits.PTIM3
#define PTIM_PTIM4                      _PTIM.Bits.PTIM4
#define PTIM_PTIM5                      _PTIM.Bits.PTIM5
#define PTIM_PTIM6                      _PTIM.Bits.PTIM6
#define PTIM_PTIM7                      _PTIM.Bits.PTIM7

#define PTIM_PTIM0_MASK                 1
#define PTIM_PTIM1_MASK                 2
#define PTIM_PTIM2_MASK                 4
#define PTIM_PTIM3_MASK                 8
#define PTIM_PTIM4_MASK                 16
#define PTIM_PTIM5_MASK                 32
#define PTIM_PTIM6_MASK                 64
#define PTIM_PTIM7_MASK                 128


 DDRM - Port M Data Direction Register; 0x00000252 
typedef union {
  byte Byte;
  struct {
    byte DDRM0       1;                                        Data Direction Port M Bit 0 
    byte DDRM1       1;                                        Data Direction Port M Bit 1 
    byte DDRM2       1;                                        Data Direction Port M Bit 2 
    byte DDRM3       1;                                        Data Direction Port M Bit 3 
    byte DDRM4       1;                                        Data Direction Port M Bit 4 
    byte DDRM5       1;                                        Data Direction Port M Bit 5 
    byte DDRM6       1;                                        Data Direction Port M Bit 6 
    byte DDRM7       1;                                        Data Direction Port M Bit 7 
  } Bits;
} DDRMSTR;
extern volatile DDRMSTR _DDRM @(REG_BASE + 0x00000252);
#define DDRM                            _DDRM.Byte
#define DDRM_DDRM0                      _DDRM.Bits.DDRM0
#define DDRM_DDRM1                      _DDRM.Bits.DDRM1
#define DDRM_DDRM2                      _DDRM.Bits.DDRM2
#define DDRM_DDRM3                      _DDRM.Bits.DDRM3
#define DDRM_DDRM4                      _DDRM.Bits.DDRM4
#define DDRM_DDRM5                      _DDRM.Bits.DDRM5
#define DDRM_DDRM6                      _DDRM.Bits.DDRM6
#define DDRM_DDRM7                      _DDRM.Bits.DDRM7

#define DDRM_DDRM0_MASK                 1
#define DDRM_DDRM1_MASK                 2
#define DDRM_DDRM2_MASK                 4
#define DDRM_DDRM3_MASK                 8
#define DDRM_DDRM4_MASK                 16
#define DDRM_DDRM5_MASK                 32
#define DDRM_DDRM6_MASK                 64
#define DDRM_DDRM7_MASK                 128


 RDRM - Port M Reduced Drive Register; 0x00000253 
typedef union {
  byte Byte;
  struct {
    byte RDRM0       1;                                        Reduced Drive Port M Bit 0 
    byte RDRM1       1;                                        Reduced Drive Port M Bit 1 
    byte RDRM2       1;                                        Reduced Drive Port M Bit 2 
    byte RDRM3       1;                                        Reduced Drive Port M Bit 3 
    byte RDRM4       1;                                        Reduced Drive Port M Bit 4 
    byte RDRM5       1;                                        Reduced Drive Port M Bit 5 
    byte RDRM6       1;                                        Reduced Drive Port M Bit 6 
    byte RDRM7       1;                                        Reduced Drive Port M Bit 7 
  } Bits;
} RDRMSTR;
extern volatile RDRMSTR _RDRM @(REG_BASE + 0x00000253);
#define RDRM                            _RDRM.Byte
#define RDRM_RDRM0                      _RDRM.Bits.RDRM0
#define RDRM_RDRM1                      _RDRM.Bits.RDRM1
#define RDRM_RDRM2                      _RDRM.Bits.RDRM2
#define RDRM_RDRM3                      _RDRM.Bits.RDRM3
#define RDRM_RDRM4                      _RDRM.Bits.RDRM4
#define RDRM_RDRM5                      _RDRM.Bits.RDRM5
#define RDRM_RDRM6                      _RDRM.Bits.RDRM6
#define RDRM_RDRM7                      _RDRM.Bits.RDRM7

#define RDRM_RDRM0_MASK                 1
#define RDRM_RDRM1_MASK                 2
#define RDRM_RDRM2_MASK                 4
#define RDRM_RDRM3_MASK                 8
#define RDRM_RDRM4_MASK                 16
#define RDRM_RDRM5_MASK                 32
#define RDRM_RDRM6_MASK                 64
#define RDRM_RDRM7_MASK                 128


 PERM - Port M Pull Device Enable Register; 0x00000254 
typedef union {
  byte Byte;
  struct {
    byte PERM0       1;                                        Pull Device Enable Port M Bit 0 
    byte PERM1       1;                                        Pull Device Enable Port M Bit 1 
    byte PERM2       1;                                        Pull Device Enable Port M Bit 2 
    byte PERM3       1;                                        Pull Device Enable Port M Bit 3 
    byte PERM4       1;                                        Pull Device Enable Port M Bit 4 
    byte PERM5       1;                                        Pull Device Enable Port M Bit 5 
    byte PERM6       1;                                        Pull Device Enable Port M Bit 6 
    byte PERM7       1;                                        Pull Device Enable Port M Bit 7 
  } Bits;
} PERMSTR;
extern volatile PERMSTR _PERM @(REG_BASE + 0x00000254);
#define PERM                            _PERM.Byte
#define PERM_PERM0                      _PERM.Bits.PERM0
#define PERM_PERM1                      _PERM.Bits.PERM1
#define PERM_PERM2                      _PERM.Bits.PERM2
#define PERM_PERM3                      _PERM.Bits.PERM3
#define PERM_PERM4                      _PERM.Bits.PERM4
#define PERM_PERM5                      _PERM.Bits.PERM5
#define PERM_PERM6                      _PERM.Bits.PERM6
#define PERM_PERM7                      _PERM.Bits.PERM7

#define PERM_PERM0_MASK                 1
#define PERM_PERM1_MASK                 2
#define PERM_PERM2_MASK                 4
#define PERM_PERM3_MASK                 8
#define PERM_PERM4_MASK                 16
#define PERM_PERM5_MASK                 32
#define PERM_PERM6_MASK                 64
#define PERM_PERM7_MASK                 128


 PPSM - Port M Polarity Select Register; 0x00000255 
typedef union {
  byte Byte;
  struct {
    byte PPSM0       1;                                        Pull Select Port M Bit 0 
    byte PPSM1       1;                                        Pull Select Port M Bit 1 
    byte PPSM2       1;                                        Pull Select Port M Bit 2 
    byte PPSM3       1;                                        Pull Select Port M Bit 3 
    byte PPSM4       1;                                        Pull Select Port M Bit 4 
    byte PPSM5       1;                                        Pull Select Port M Bit 5 
    byte PPSM6       1;                                        Pull Select Port M Bit 6 
    byte PPSM7       1;                                        Pull Select Port M Bit 7 
  } Bits;
} PPSMSTR;
extern volatile PPSMSTR _PPSM @(REG_BASE + 0x00000255);
#define PPSM                            _PPSM.Byte
#define PPSM_PPSM0                      _PPSM.Bits.PPSM0
#define PPSM_PPSM1                      _PPSM.Bits.PPSM1
#define PPSM_PPSM2                      _PPSM.Bits.PPSM2
#define PPSM_PPSM3                      _PPSM.Bits.PPSM3
#define PPSM_PPSM4                      _PPSM.Bits.PPSM4
#define PPSM_PPSM5                      _PPSM.Bits.PPSM5
#define PPSM_PPSM6                      _PPSM.Bits.PPSM6
#define PPSM_PPSM7                      _PPSM.Bits.PPSM7

#define PPSM_PPSM0_MASK                 1
#define PPSM_PPSM1_MASK                 2
#define PPSM_PPSM2_MASK                 4
#define PPSM_PPSM3_MASK                 8
#define PPSM_PPSM4_MASK                 16
#define PPSM_PPSM5_MASK                 32
#define PPSM_PPSM6_MASK                 64
#define PPSM_PPSM7_MASK                 128


 WOMM - Port M Wired-Or Mode Register; 0x00000256 
typedef union {
  byte Byte;
  struct {
    byte WOMM0       1;                                        Wired-Or Mode Port M Bit 0 
    byte WOMM1       1;                                        Wired-Or Mode Port M Bit 1 
    byte WOMM2       1;                                        Wired-Or Mode Port M Bit 2 
    byte WOMM3       1;                                        Wired-Or Mode Port M Bit 3 
    byte WOMM4       1;                                        Wired-Or Mode Port M Bit 4 
    byte WOMM5       1;                                        Wired-Or Mode Port M Bit 5 
    byte WOMM6       1;                                        Wired-Or Mode Port M Bit 6 
    byte WOMM7       1;                                        Wired-Or Mode Port M Bit 7 
  } Bits;
} WOMMSTR;
extern volatile WOMMSTR _WOMM @(REG_BASE + 0x00000256);
#define WOMM                            _WOMM.Byte
#define WOMM_WOMM0                      _WOMM.Bits.WOMM0
#define WOMM_WOMM1                      _WOMM.Bits.WOMM1
#define WOMM_WOMM2                      _WOMM.Bits.WOMM2
#define WOMM_WOMM3                      _WOMM.Bits.WOMM3
#define WOMM_WOMM4                      _WOMM.Bits.WOMM4
#define WOMM_WOMM5                      _WOMM.Bits.WOMM5
#define WOMM_WOMM6                      _WOMM.Bits.WOMM6
#define WOMM_WOMM7                      _WOMM.Bits.WOMM7

#define WOMM_WOMM0_MASK                 1
#define WOMM_WOMM1_MASK                 2
#define WOMM_WOMM2_MASK                 4
#define WOMM_WOMM3_MASK                 8
#define WOMM_WOMM4_MASK                 16
#define WOMM_WOMM5_MASK                 32
#define WOMM_WOMM6_MASK                 64
#define WOMM_WOMM7_MASK                 128


 MODRR - Module Routing Register; 0x00000257 
typedef union {
  byte Byte;
  struct {
    byte MODRR0      1;                                        CAN0 Routing Bit 0 
    byte MODRR1      1;                                        CAN0 Routing Bit 1 
    byte MODRR2      1;                                        CAN4 Routing Bit 0 
    byte MODRR3      1;                                        CAN4 Routing Bit 1 
    byte MODRR4      1;                                        SPI0 Routing 
    byte MODRR5      1;                                        SPI1 Routing 
    byte MODRR6      1;                                        SPI2 Routing 
    byte             1; 
  } Bits;
  struct {
    byte grpMODRR 7;
    byte         1;
  } MergedBits;
} MODRRSTR;
extern volatile MODRRSTR _MODRR @(REG_BASE + 0x00000257);
#define MODRR                           _MODRR.Byte
#define MODRR_MODRR0                    _MODRR.Bits.MODRR0
#define MODRR_MODRR1                    _MODRR.Bits.MODRR1
#define MODRR_MODRR2                    _MODRR.Bits.MODRR2
#define MODRR_MODRR3                    _MODRR.Bits.MODRR3
#define MODRR_MODRR4                    _MODRR.Bits.MODRR4
#define MODRR_MODRR5                    _MODRR.Bits.MODRR5
#define MODRR_MODRR6                    _MODRR.Bits.MODRR6
#define MODRR_MODRR                     _MODRR.MergedBits.grpMODRR

#define MODRR_MODRR0_MASK               1
#define MODRR_MODRR1_MASK               2
#define MODRR_MODRR2_MASK               4
#define MODRR_MODRR3_MASK               8
#define MODRR_MODRR4_MASK               16
#define MODRR_MODRR5_MASK               32
#define MODRR_MODRR6_MASK               64
#define MODRR_MODRR_MASK                127
#define MODRR_MODRR_BITNUM              0


 PTP - Port P IO Register; 0x00000258 
typedef union {
  byte Byte;
  struct {
    byte PTP0        1;                                        Port P Bit 0 
    byte PTP1        1;                                        Port P Bit 1 
    byte PTP2        1;                                        Port P Bit 2 
    byte PTP3        1;                                        Port P Bit 3 
    byte PTP4        1;                                        Port P Bit 4 
    byte PTP5        1;                                        Port P Bit 5 
    byte PTP6        1;                                        Port P Bit 6 
    byte PTP7        1;                                        Port P Bit 7 
  } Bits;
} PTPSTR;
extern volatile PTPSTR _PTP @(REG_BASE + 0x00000258);
#define PTP                             _PTP.Byte
#define PTP_PTP0                        _PTP.Bits.PTP0
#define PTP_PTP1                        _PTP.Bits.PTP1
#define PTP_PTP2                        _PTP.Bits.PTP2
#define PTP_PTP3                        _PTP.Bits.PTP3
#define PTP_PTP4                        _PTP.Bits.PTP4
#define PTP_PTP5                        _PTP.Bits.PTP5
#define PTP_PTP6                        _PTP.Bits.PTP6
#define PTP_PTP7                        _PTP.Bits.PTP7

#define PTP_PTP0_MASK                   1
#define PTP_PTP1_MASK                   2
#define PTP_PTP2_MASK                   4
#define PTP_PTP3_MASK                   8
#define PTP_PTP4_MASK                   16
#define PTP_PTP5_MASK                   32
#define PTP_PTP6_MASK                   64
#define PTP_PTP7_MASK                   128


 PTIP - Port P Input Register; 0x00000259 
typedef union {
  byte Byte;
  struct {
    byte PTIP0       1;                                        Port P Bit 0 
    byte PTIP1       1;                                        Port P Bit 1 
    byte PTIP2       1;                                        Port P Bit 2 
    byte PTIP3       1;                                        Port P Bit 3 
    byte PTIP4       1;                                        Port P Bit 4 
    byte PTIP5       1;                                        Port P Bit 5 
    byte PTIP6       1;                                        Port P Bit 6 
    byte PTIP7       1;                                        Port P Bit 7 
  } Bits;
} PTIPSTR;
extern volatile PTIPSTR _PTIP @(REG_BASE + 0x00000259);
#define PTIP                            _PTIP.Byte
#define PTIP_PTIP0                      _PTIP.Bits.PTIP0
#define PTIP_PTIP1                      _PTIP.Bits.PTIP1
#define PTIP_PTIP2                      _PTIP.Bits.PTIP2
#define PTIP_PTIP3                      _PTIP.Bits.PTIP3
#define PTIP_PTIP4                      _PTIP.Bits.PTIP4
#define PTIP_PTIP5                      _PTIP.Bits.PTIP5
#define PTIP_PTIP6                      _PTIP.Bits.PTIP6
#define PTIP_PTIP7                      _PTIP.Bits.PTIP7

#define PTIP_PTIP0_MASK                 1
#define PTIP_PTIP1_MASK                 2
#define PTIP_PTIP2_MASK                 4
#define PTIP_PTIP3_MASK                 8
#define PTIP_PTIP4_MASK                 16
#define PTIP_PTIP5_MASK                 32
#define PTIP_PTIP6_MASK                 64
#define PTIP_PTIP7_MASK                 128


 DDRP - Port P Data Direction Register; 0x0000025A 
typedef union {
  byte Byte;
  struct {
    byte DDRP0       1;                                        Data Direction Port P Bit 0 
    byte DDRP1       1;                                        Data Direction Port P Bit 1 
    byte DDRP2       1;                                        Data Direction Port P Bit 2 
    byte DDRP3       1;                                        Data Direction Port P Bit 3 
    byte DDRP4       1;                                        Data Direction Port P Bit 4 
    byte DDRP5       1;                                        Data Direction Port P Bit 5 
    byte DDRP6       1;                                        Data Direction Port P Bit 6 
    byte DDRP7       1;                                        Data Direction Port P Bit 7 
  } Bits;
} DDRPSTR;
extern volatile DDRPSTR _DDRP @(REG_BASE + 0x0000025A);
#define DDRP                            _DDRP.Byte
#define DDRP_DDRP0                      _DDRP.Bits.DDRP0
#define DDRP_DDRP1                      _DDRP.Bits.DDRP1
#define DDRP_DDRP2                      _DDRP.Bits.DDRP2
#define DDRP_DDRP3                      _DDRP.Bits.DDRP3
#define DDRP_DDRP4                      _DDRP.Bits.DDRP4
#define DDRP_DDRP5                      _DDRP.Bits.DDRP5
#define DDRP_DDRP6                      _DDRP.Bits.DDRP6
#define DDRP_DDRP7                      _DDRP.Bits.DDRP7

#define DDRP_DDRP0_MASK                 1
#define DDRP_DDRP1_MASK                 2
#define DDRP_DDRP2_MASK                 4
#define DDRP_DDRP3_MASK                 8
#define DDRP_DDRP4_MASK                 16
#define DDRP_DDRP5_MASK                 32
#define DDRP_DDRP6_MASK                 64
#define DDRP_DDRP7_MASK                 128


 RDRP - Port P Reduced Drive Register; 0x0000025B 
typedef union {
  byte Byte;
  struct {
    byte RDRP0       1;                                        Reduced Drive Port P Bit 0 
    byte RDRP1       1;                                        Reduced Drive Port P Bit 1 
    byte RDRP2       1;                                        Reduced Drive Port P Bit 2 
    byte RDRP3       1;                                        Reduced Drive Port P Bit 3 
    byte RDRP4       1;                                        Reduced Drive Port P Bit 4 
    byte RDRP5       1;                                        Reduced Drive Port P Bit 5 
    byte RDRP6       1;                                        Reduced Drive Port P Bit 6 
    byte RDRP7       1;                                        Reduced Drive Port P Bit 7 
  } Bits;
} RDRPSTR;
extern volatile RDRPSTR _RDRP @(REG_BASE + 0x0000025B);
#define RDRP                            _RDRP.Byte
#define RDRP_RDRP0                      _RDRP.Bits.RDRP0
#define RDRP_RDRP1                      _RDRP.Bits.RDRP1
#define RDRP_RDRP2                      _RDRP.Bits.RDRP2
#define RDRP_RDRP3                      _RDRP.Bits.RDRP3
#define RDRP_RDRP4                      _RDRP.Bits.RDRP4
#define RDRP_RDRP5                      _RDRP.Bits.RDRP5
#define RDRP_RDRP6                      _RDRP.Bits.RDRP6
#define RDRP_RDRP7                      _RDRP.Bits.RDRP7

#define RDRP_RDRP0_MASK                 1
#define RDRP_RDRP1_MASK                 2
#define RDRP_RDRP2_MASK                 4
#define RDRP_RDRP3_MASK                 8
#define RDRP_RDRP4_MASK                 16
#define RDRP_RDRP5_MASK                 32
#define RDRP_RDRP6_MASK                 64
#define RDRP_RDRP7_MASK                 128


 PERP - Port P Pull Device Enable Register; 0x0000025C 
typedef union {
  byte Byte;
  struct {
    byte PERP0       1;                                        Pull Device Enable Port P Bit 0 
    byte PERP1       1;                                        Pull Device Enable Port P Bit 1 
    byte PERP2       1;                                        Pull Device Enable Port P Bit 2 
    byte PERP3       1;                                        Pull Device Enable Port P Bit 3 
    byte PERP4       1;                                        Pull Device Enable Port P Bit 4 
    byte PERP5       1;                                        Pull Device Enable Port P Bit 5 
    byte PERP6       1;                                        Pull Device Enable Port P Bit 6 
    byte PERP7       1;                                        Pull Device Enable Port P Bit 7 
  } Bits;
} PERPSTR;
extern volatile PERPSTR _PERP @(REG_BASE + 0x0000025C);
#define PERP                            _PERP.Byte
#define PERP_PERP0                      _PERP.Bits.PERP0
#define PERP_PERP1                      _PERP.Bits.PERP1
#define PERP_PERP2                      _PERP.Bits.PERP2
#define PERP_PERP3                      _PERP.Bits.PERP3
#define PERP_PERP4                      _PERP.Bits.PERP4
#define PERP_PERP5                      _PERP.Bits.PERP5
#define PERP_PERP6                      _PERP.Bits.PERP6
#define PERP_PERP7                      _PERP.Bits.PERP7

#define PERP_PERP0_MASK                 1
#define PERP_PERP1_MASK                 2
#define PERP_PERP2_MASK                 4
#define PERP_PERP3_MASK                 8
#define PERP_PERP4_MASK                 16
#define PERP_PERP5_MASK                 32
#define PERP_PERP6_MASK                 64
#define PERP_PERP7_MASK                 128


 PPSP - Port P Polarity Select Register; 0x0000025D 
typedef union {
  byte Byte;
  struct {
    byte PPSP0       1;                                        Pull Select Port P Bit 0 
    byte PPSP1       1;                                        Pull Select Port P Bit 1 
    byte PPSP2       1;                                        Pull Select Port P Bit 2 
    byte PPSP3       1;                                        Pull Select Port P Bit 3 
    byte PPSP4       1;                                        Pull Select Port P Bit 4 
    byte PPSP5       1;                                        Pull Select Port P Bit 5 
    byte PPSP6       1;                                        Pull Select Port P Bit 6 
    byte PPSP7       1;                                        Pull Select Port P Bit 7 
  } Bits;
} PPSPSTR;
extern volatile PPSPSTR _PPSP @(REG_BASE + 0x0000025D);
#define PPSP                            _PPSP.Byte
#define PPSP_PPSP0                      _PPSP.Bits.PPSP0
#define PPSP_PPSP1                      _PPSP.Bits.PPSP1
#define PPSP_PPSP2                      _PPSP.Bits.PPSP2
#define PPSP_PPSP3                      _PPSP.Bits.PPSP3
#define PPSP_PPSP4                      _PPSP.Bits.PPSP4
#define PPSP_PPSP5                      _PPSP.Bits.PPSP5
#define PPSP_PPSP6                      _PPSP.Bits.PPSP6
#define PPSP_PPSP7                      _PPSP.Bits.PPSP7

#define PPSP_PPSP0_MASK                 1
#define PPSP_PPSP1_MASK                 2
#define PPSP_PPSP2_MASK                 4
#define PPSP_PPSP3_MASK                 8
#define PPSP_PPSP4_MASK                 16
#define PPSP_PPSP5_MASK                 32
#define PPSP_PPSP6_MASK                 64
#define PPSP_PPSP7_MASK                 128


 PIEP - Port P Interrupt Enable Register; 0x0000025E 
typedef union {
  byte Byte;
  struct {
    byte PIEP0       1;                                        Interrupt Enable Port P Bit 0 
    byte PIEP1       1;                                        Interrupt Enable Port P Bit 1 
    byte PIEP2       1;                                        Interrupt Enable Port P Bit 2 
    byte PIEP3       1;                                        Interrupt Enable Port P Bit 3 
    byte PIEP4       1;                                        Interrupt Enable Port P Bit 4 
    byte PIEP5       1;                                        Interrupt Enable Port P Bit 5 
    byte PIEP6       1;                                        Interrupt Enable Port P Bit 6 
    byte PIEP7       1;                                        Interrupt Enable Port P Bit 7 
  } Bits;
} PIEPSTR;
extern volatile PIEPSTR _PIEP @(REG_BASE + 0x0000025E);
#define PIEP                            _PIEP.Byte
#define PIEP_PIEP0                      _PIEP.Bits.PIEP0
#define PIEP_PIEP1                      _PIEP.Bits.PIEP1
#define PIEP_PIEP2                      _PIEP.Bits.PIEP2
#define PIEP_PIEP3                      _PIEP.Bits.PIEP3
#define PIEP_PIEP4                      _PIEP.Bits.PIEP4
#define PIEP_PIEP5                      _PIEP.Bits.PIEP5
#define PIEP_PIEP6                      _PIEP.Bits.PIEP6
#define PIEP_PIEP7                      _PIEP.Bits.PIEP7

#define PIEP_PIEP0_MASK                 1
#define PIEP_PIEP1_MASK                 2
#define PIEP_PIEP2_MASK                 4
#define PIEP_PIEP3_MASK                 8
#define PIEP_PIEP4_MASK                 16
#define PIEP_PIEP5_MASK                 32
#define PIEP_PIEP6_MASK                 64
#define PIEP_PIEP7_MASK                 128


 PIFP - Port P Interrupt Flag Register; 0x0000025F 
typedef union {
  byte Byte;
  struct {
    byte PIFP0       1;                                        Interrupt Flags Port P Bit 0 
    byte PIFP1       1;                                        Interrupt Flags Port P Bit 1 
    byte PIFP2       1;                                        Interrupt Flags Port P Bit 2 
    byte PIFP3       1;                                        Interrupt Flags Port P Bit 3 
    byte PIFP4       1;                                        Interrupt Flags Port P Bit 4 
    byte PIFP5       1;                                        Interrupt Flags Port P Bit 5 
    byte PIFP6       1;                                        Interrupt Flags Port P Bit 6 
    byte PIFP7       1;                                        Interrupt Flags Port P Bit 7 
  } Bits;
} PIFPSTR;
extern volatile PIFPSTR _PIFP @(REG_BASE + 0x0000025F);
#define PIFP                            _PIFP.Byte
#define PIFP_PIFP0                      _PIFP.Bits.PIFP0
#define PIFP_PIFP1                      _PIFP.Bits.PIFP1
#define PIFP_PIFP2                      _PIFP.Bits.PIFP2
#define PIFP_PIFP3                      _PIFP.Bits.PIFP3
#define PIFP_PIFP4                      _PIFP.Bits.PIFP4
#define PIFP_PIFP5                      _PIFP.Bits.PIFP5
#define PIFP_PIFP6                      _PIFP.Bits.PIFP6
#define PIFP_PIFP7                      _PIFP.Bits.PIFP7

#define PIFP_PIFP0_MASK                 1
#define PIFP_PIFP1_MASK                 2
#define PIFP_PIFP2_MASK                 4
#define PIFP_PIFP3_MASK                 8
#define PIFP_PIFP4_MASK                 16
#define PIFP_PIFP5_MASK                 32
#define PIFP_PIFP6_MASK                 64
#define PIFP_PIFP7_MASK                 128


 PTH - Port H IO Register; 0x00000260 
typedef union {
  byte Byte;
  struct {
    byte PTH0        1;                                        Port H Bit 0 
    byte PTH1        1;                                        Port H Bit 1 
    byte PTH2        1;                                        Port H Bit 2 
    byte PTH3        1;                                        Port H Bit 3 
    byte PTH4        1;                                        Port H Bit 4 
    byte PTH5        1;                                        Port H Bit 5 
    byte PTH6        1;                                        Port H Bit 6 
    byte PTH7        1;                                        Port H Bit 7 
  } Bits;
} PTHSTR;
extern volatile PTHSTR _PTH @(REG_BASE + 0x00000260);
#define PTH                             _PTH.Byte
#define PTH_PTH0                        _PTH.Bits.PTH0
#define PTH_PTH1                        _PTH.Bits.PTH1
#define PTH_PTH2                        _PTH.Bits.PTH2
#define PTH_PTH3                        _PTH.Bits.PTH3
#define PTH_PTH4                        _PTH.Bits.PTH4
#define PTH_PTH5                        _PTH.Bits.PTH5
#define PTH_PTH6                        _PTH.Bits.PTH6
#define PTH_PTH7                        _PTH.Bits.PTH7

#define PTH_PTH0_MASK                   1
#define PTH_PTH1_MASK                   2
#define PTH_PTH2_MASK                   4
#define PTH_PTH3_MASK                   8
#define PTH_PTH4_MASK                   16
#define PTH_PTH5_MASK                   32
#define PTH_PTH6_MASK                   64
#define PTH_PTH7_MASK                   128


 PTIH - Port H Input Register; 0x00000261 
typedef union {
  byte Byte;
  struct {
    byte PTIH0       1;                                        Port H Bit 0 
    byte PTIH1       1;                                        Port H Bit 1 
    byte PTIH2       1;                                        Port H Bit 2 
    byte PTIH3       1;                                        Port H Bit 3 
    byte PTIH4       1;                                        Port H Bit 4 
    byte PTIH5       1;                                        Port H Bit 5 
    byte PTIH6       1;                                        Port H Bit 6 
    byte PTIH7       1;                                        Port H Bit 7 
  } Bits;
} PTIHSTR;
extern volatile PTIHSTR _PTIH @(REG_BASE + 0x00000261);
#define PTIH                            _PTIH.Byte
#define PTIH_PTIH0                      _PTIH.Bits.PTIH0
#define PTIH_PTIH1                      _PTIH.Bits.PTIH1
#define PTIH_PTIH2                      _PTIH.Bits.PTIH2
#define PTIH_PTIH3                      _PTIH.Bits.PTIH3
#define PTIH_PTIH4                      _PTIH.Bits.PTIH4
#define PTIH_PTIH5                      _PTIH.Bits.PTIH5
#define PTIH_PTIH6                      _PTIH.Bits.PTIH6
#define PTIH_PTIH7                      _PTIH.Bits.PTIH7

#define PTIH_PTIH0_MASK                 1
#define PTIH_PTIH1_MASK                 2
#define PTIH_PTIH2_MASK                 4
#define PTIH_PTIH3_MASK                 8
#define PTIH_PTIH4_MASK                 16
#define PTIH_PTIH5_MASK                 32
#define PTIH_PTIH6_MASK                 64
#define PTIH_PTIH7_MASK                 128


 DDRH - Port H Data Direction Register; 0x00000262 
typedef union {
  byte Byte;
  struct {
    byte DDRH0       1;                                        Data Direction Port H Bit 0 
    byte DDRH1       1;                                        Data Direction Port H Bit 1 
    byte DDRH2       1;                                        Data Direction Port H Bit 2 
    byte DDRH3       1;                                        Data Direction Port H Bit 3 
    byte DDRH4       1;                                        Data Direction Port H Bit 4 
    byte DDRH5       1;                                        Data Direction Port H Bit 5 
    byte DDRH6       1;                                        Data Direction Port H Bit 6 
    byte DDRH7       1;                                        Data Direction Port H Bit 7 
  } Bits;
} DDRHSTR;
extern volatile DDRHSTR _DDRH @(REG_BASE + 0x00000262);
#define DDRH                            _DDRH.Byte
#define DDRH_DDRH0                      _DDRH.Bits.DDRH0
#define DDRH_DDRH1                      _DDRH.Bits.DDRH1
#define DDRH_DDRH2                      _DDRH.Bits.DDRH2
#define DDRH_DDRH3                      _DDRH.Bits.DDRH3
#define DDRH_DDRH4                      _DDRH.Bits.DDRH4
#define DDRH_DDRH5                      _DDRH.Bits.DDRH5
#define DDRH_DDRH6                      _DDRH.Bits.DDRH6
#define DDRH_DDRH7                      _DDRH.Bits.DDRH7

#define DDRH_DDRH0_MASK                 1
#define DDRH_DDRH1_MASK                 2
#define DDRH_DDRH2_MASK                 4
#define DDRH_DDRH3_MASK                 8
#define DDRH_DDRH4_MASK                 16
#define DDRH_DDRH5_MASK                 32
#define DDRH_DDRH6_MASK                 64
#define DDRH_DDRH7_MASK                 128


 RDRH - Port H Reduced Drive Register; 0x00000263 
typedef union {
  byte Byte;
  struct {
    byte RDRH0       1;                                        Reduced Drive Port H Bit 0 
    byte RDRH1       1;                                        Reduced Drive Port H Bit 1 
    byte RDRH2       1;                                        Reduced Drive Port H Bit 2 
    byte RDRH3       1;                                        Reduced Drive Port H Bit 3 
    byte RDRH4       1;                                        Reduced Drive Port H Bit 4 
    byte RDRH5       1;                                        Reduced Drive Port H Bit 5 
    byte RDRH6       1;                                        Reduced Drive Port H Bit 6 
    byte RDRH7       1;                                        Reduced Drive Port H Bit 7 
  } Bits;
} RDRHSTR;
extern volatile RDRHSTR _RDRH @(REG_BASE + 0x00000263);
#define RDRH                            _RDRH.Byte
#define RDRH_RDRH0                      _RDRH.Bits.RDRH0
#define RDRH_RDRH1                      _RDRH.Bits.RDRH1
#define RDRH_RDRH2                      _RDRH.Bits.RDRH2
#define RDRH_RDRH3                      _RDRH.Bits.RDRH3
#define RDRH_RDRH4                      _RDRH.Bits.RDRH4
#define RDRH_RDRH5                      _RDRH.Bits.RDRH5
#define RDRH_RDRH6                      _RDRH.Bits.RDRH6
#define RDRH_RDRH7                      _RDRH.Bits.RDRH7

#define RDRH_RDRH0_MASK                 1
#define RDRH_RDRH1_MASK                 2
#define RDRH_RDRH2_MASK                 4
#define RDRH_RDRH3_MASK                 8
#define RDRH_RDRH4_MASK                 16
#define RDRH_RDRH5_MASK                 32
#define RDRH_RDRH6_MASK                 64
#define RDRH_RDRH7_MASK                 128


 PERH - Port H Pull Device Enable Register; 0x00000264 
typedef union {
  byte Byte;
  struct {
    byte PERH0       1;                                        Pull Device Enable Port H Bit 0 
    byte PERH1       1;                                        Pull Device Enable Port H Bit 1 
    byte PERH2       1;                                        Pull Device Enable Port H Bit 2 
    byte PERH3       1;                                        Pull Device Enable Port H Bit 3 
    byte PERH4       1;                                        Pull Device Enable Port H Bit 4 
    byte PERH5       1;                                        Pull Device Enable Port H Bit 5 
    byte PERH6       1;                                        Pull Device Enable Port H Bit 6 
    byte PERH7       1;                                        Pull Device Enable Port H Bit 7 
  } Bits;
} PERHSTR;
extern volatile PERHSTR _PERH @(REG_BASE + 0x00000264);
#define PERH                            _PERH.Byte
#define PERH_PERH0                      _PERH.Bits.PERH0
#define PERH_PERH1                      _PERH.Bits.PERH1
#define PERH_PERH2                      _PERH.Bits.PERH2
#define PERH_PERH3                      _PERH.Bits.PERH3
#define PERH_PERH4                      _PERH.Bits.PERH4
#define PERH_PERH5                      _PERH.Bits.PERH5
#define PERH_PERH6                      _PERH.Bits.PERH6
#define PERH_PERH7                      _PERH.Bits.PERH7

#define PERH_PERH0_MASK                 1
#define PERH_PERH1_MASK                 2
#define PERH_PERH2_MASK                 4
#define PERH_PERH3_MASK                 8
#define PERH_PERH4_MASK                 16
#define PERH_PERH5_MASK                 32
#define PERH_PERH6_MASK                 64
#define PERH_PERH7_MASK                 128


 PPSH - Port H Polarity Select Register; 0x00000265 
typedef union {
  byte Byte;
  struct {
    byte PPSH0       1;                                        Pull Select Port H Bit 0 
    byte PPSH1       1;                                        Pull Select Port H Bit 1 
    byte PPSH2       1;                                        Pull Select Port H Bit 2 
    byte PPSH3       1;                                        Pull Select Port H Bit 3 
    byte PPSH4       1;                                        Pull Select Port H Bit 4 
    byte PPSH5       1;                                        Pull Select Port H Bit 5 
    byte PPSH6       1;                                        Pull Select Port H Bit 6 
    byte PPSH7       1;                                        Pull Select Port H Bit 7 
  } Bits;
} PPSHSTR;
extern volatile PPSHSTR _PPSH @(REG_BASE + 0x00000265);
#define PPSH                            _PPSH.Byte
#define PPSH_PPSH0                      _PPSH.Bits.PPSH0
#define PPSH_PPSH1                      _PPSH.Bits.PPSH1
#define PPSH_PPSH2                      _PPSH.Bits.PPSH2
#define PPSH_PPSH3                      _PPSH.Bits.PPSH3
#define PPSH_PPSH4                      _PPSH.Bits.PPSH4
#define PPSH_PPSH5                      _PPSH.Bits.PPSH5
#define PPSH_PPSH6                      _PPSH.Bits.PPSH6
#define PPSH_PPSH7                      _PPSH.Bits.PPSH7

#define PPSH_PPSH0_MASK                 1
#define PPSH_PPSH1_MASK                 2
#define PPSH_PPSH2_MASK                 4
#define PPSH_PPSH3_MASK                 8
#define PPSH_PPSH4_MASK                 16
#define PPSH_PPSH5_MASK                 32
#define PPSH_PPSH6_MASK                 64
#define PPSH_PPSH7_MASK                 128


 PIEH - Port H Interrupt Enable Register; 0x00000266 
typedef union {
  byte Byte;
  struct {
    byte PIEH0       1;                                        Interrupt Enable Port H Bit 0 
    byte PIEH1       1;                                        Interrupt Enable Port H Bit 1 
    byte PIEH2       1;                                        Interrupt Enable Port H Bit 2 
    byte PIEH3       1;                                        Interrupt Enable Port H Bit 3 
    byte PIEH4       1;                                        Interrupt Enable Port H Bit 4 
    byte PIEH5       1;                                        Interrupt Enable Port H Bit 5 
    byte PIEH6       1;                                        Interrupt Enable Port H Bit 6 
    byte PIEH7       1;                                        Interrupt Enable Port H Bit 7 
  } Bits;
} PIEHSTR;
extern volatile PIEHSTR _PIEH @(REG_BASE + 0x00000266);
#define PIEH                            _PIEH.Byte
#define PIEH_PIEH0                      _PIEH.Bits.PIEH0
#define PIEH_PIEH1                      _PIEH.Bits.PIEH1
#define PIEH_PIEH2                      _PIEH.Bits.PIEH2
#define PIEH_PIEH3                      _PIEH.Bits.PIEH3
#define PIEH_PIEH4                      _PIEH.Bits.PIEH4
#define PIEH_PIEH5                      _PIEH.Bits.PIEH5
#define PIEH_PIEH6                      _PIEH.Bits.PIEH6
#define PIEH_PIEH7                      _PIEH.Bits.PIEH7

#define PIEH_PIEH0_MASK                 1
#define PIEH_PIEH1_MASK                 2
#define PIEH_PIEH2_MASK                 4
#define PIEH_PIEH3_MASK                 8
#define PIEH_PIEH4_MASK                 16
#define PIEH_PIEH5_MASK                 32
#define PIEH_PIEH6_MASK                 64
#define PIEH_PIEH7_MASK                 128


 PIFH - Port H Interrupt Flag Register; 0x00000267 
typedef union {
  byte Byte;
  struct {
    byte PIFH0       1;                                        Interrupt Flags Port H Bit 0 
    byte PIFH1       1;                                        Interrupt Flags Port H Bit 1 
    byte PIFH2       1;                                        Interrupt Flags Port H Bit 2 
    byte PIFH3       1;                                        Interrupt Flags Port H Bit 3 
    byte PIFH4       1;                                        Interrupt Flags Port H Bit 4 
    byte PIFH5       1;                                        Interrupt Flags Port H Bit 5 
    byte PIFH6       1;                                        Interrupt Flags Port H Bit 6 
    byte PIFH7       1;                                        Interrupt Flags Port H Bit 7 
  } Bits;
} PIFHSTR;
extern volatile PIFHSTR _PIFH @(REG_BASE + 0x00000267);
#define PIFH                            _PIFH.Byte
#define PIFH_PIFH0                      _PIFH.Bits.PIFH0
#define PIFH_PIFH1                      _PIFH.Bits.PIFH1
#define PIFH_PIFH2                      _PIFH.Bits.PIFH2
#define PIFH_PIFH3                      _PIFH.Bits.PIFH3
#define PIFH_PIFH4                      _PIFH.Bits.PIFH4
#define PIFH_PIFH5                      _PIFH.Bits.PIFH5
#define PIFH_PIFH6                      _PIFH.Bits.PIFH6
#define PIFH_PIFH7                      _PIFH.Bits.PIFH7

#define PIFH_PIFH0_MASK                 1
#define PIFH_PIFH1_MASK                 2
#define PIFH_PIFH2_MASK                 4
#define PIFH_PIFH3_MASK                 8
#define PIFH_PIFH4_MASK                 16
#define PIFH_PIFH5_MASK                 32
#define PIFH_PIFH6_MASK                 64
#define PIFH_PIFH7_MASK                 128


 PTJ - Port J IO Register; 0x00000268 
typedef union {
  byte Byte;
  struct {
    byte PTJ0        1;                                        Port J Bit 0 
    byte PTJ1        1;                                        Port J Bit 1 
    byte PTJ2        1;                                        Port J Bit 2 
    byte             1; 
    byte PTJ4        1;                                        Port J Bit 4 
    byte PTJ5        1;                                        Port J Bit 5 
    byte PTJ6        1;                                        Port J Bit 6 
    byte PTJ7        1;                                        Port J Bit 7 
  } Bits;
  struct {
    byte grpPTJ  3;
    byte         1;
    byte grpPTJ_4 4;
  } MergedBits;
} PTJSTR;
extern volatile PTJSTR _PTJ @(REG_BASE + 0x00000268);
#define PTJ                             _PTJ.Byte
#define PTJ_PTJ0                        _PTJ.Bits.PTJ0
#define PTJ_PTJ1                        _PTJ.Bits.PTJ1
#define PTJ_PTJ2                        _PTJ.Bits.PTJ2
#define PTJ_PTJ4                        _PTJ.Bits.PTJ4
#define PTJ_PTJ5                        _PTJ.Bits.PTJ5
#define PTJ_PTJ6                        _PTJ.Bits.PTJ6
#define PTJ_PTJ7                        _PTJ.Bits.PTJ7
#define PTJ_PTJ                         _PTJ.MergedBits.grpPTJ
#define PTJ_PTJ_4                       _PTJ.MergedBits.grpPTJ_4

#define PTJ_PTJ0_MASK                   1
#define PTJ_PTJ1_MASK                   2
#define PTJ_PTJ2_MASK                   4
#define PTJ_PTJ4_MASK                   16
#define PTJ_PTJ5_MASK                   32
#define PTJ_PTJ6_MASK                   64
#define PTJ_PTJ7_MASK                   128
#define PTJ_PTJ_MASK                    7
#define PTJ_PTJ_BITNUM                  0
#define PTJ_PTJ_4_MASK                  240
#define PTJ_PTJ_4_BITNUM                4


 PTIJ - Port J Input Register; 0x00000269 
typedef union {
  byte Byte;
  struct {
    byte PTIJ0       1;                                        Port J Bit 0 
    byte PTIJ1       1;                                        Port J Bit 1 
    byte PTIJ2       1;                                        Port J Bit 2 
    byte             1; 
    byte PTIJ4       1;                                        Port J Bit 4 
    byte PTIJ5       1;                                        Port J Bit 5 
    byte PTIJ6       1;                                        Port J Bit 6 
    byte PTIJ7       1;                                        Port J Bit 7 
  } Bits;
  struct {
    byte grpPTIJ 3;
    byte         1;
    byte grpPTIJ_4 4;
  } MergedBits;
} PTIJSTR;
extern volatile PTIJSTR _PTIJ @(REG_BASE + 0x00000269);
#define PTIJ                            _PTIJ.Byte
#define PTIJ_PTIJ0                      _PTIJ.Bits.PTIJ0
#define PTIJ_PTIJ1                      _PTIJ.Bits.PTIJ1
#define PTIJ_PTIJ2                      _PTIJ.Bits.PTIJ2
#define PTIJ_PTIJ4                      _PTIJ.Bits.PTIJ4
#define PTIJ_PTIJ5                      _PTIJ.Bits.PTIJ5
#define PTIJ_PTIJ6                      _PTIJ.Bits.PTIJ6
#define PTIJ_PTIJ7                      _PTIJ.Bits.PTIJ7
#define PTIJ_PTIJ                       _PTIJ.MergedBits.grpPTIJ
#define PTIJ_PTIJ_4                     _PTIJ.MergedBits.grpPTIJ_4

#define PTIJ_PTIJ0_MASK                 1
#define PTIJ_PTIJ1_MASK                 2
#define PTIJ_PTIJ2_MASK                 4
#define PTIJ_PTIJ4_MASK                 16
#define PTIJ_PTIJ5_MASK                 32
#define PTIJ_PTIJ6_MASK                 64
#define PTIJ_PTIJ7_MASK                 128
#define PTIJ_PTIJ_MASK                  7
#define PTIJ_PTIJ_BITNUM                0
#define PTIJ_PTIJ_4_MASK                240
#define PTIJ_PTIJ_4_BITNUM              4


 DDRJ - Port J Data Direction Register; 0x0000026A 
typedef union {
  byte Byte;
  struct {
    byte DDRJ0       1;                                        Data Direction Port J Bit 0 
    byte DDRJ1       1;                                        Data Direction Port J Bit 1 
    byte DDRJ2       1;                                        Data Direction Port J Bit 2 
    byte             1; 
    byte DDRJ4       1;                                        Data Direction Port J Bit 4 
    byte DDRJ5       1;                                        Data Direction Port J Bit 5 
    byte DDRJ6       1;                                        Data Direction Port J Bit 6 
    byte DDRJ7       1;                                        Data Direction Port J Bit 7 
  } Bits;
  struct {
    byte grpDDRJ 3;
    byte         1;
    byte grpDDRJ_4 4;
  } MergedBits;
} DDRJSTR;
extern volatile DDRJSTR _DDRJ @(REG_BASE + 0x0000026A);
#define DDRJ                            _DDRJ.Byte
#define DDRJ_DDRJ0                      _DDRJ.Bits.DDRJ0
#define DDRJ_DDRJ1                      _DDRJ.Bits.DDRJ1
#define DDRJ_DDRJ2                      _DDRJ.Bits.DDRJ2
#define DDRJ_DDRJ4                      _DDRJ.Bits.DDRJ4
#define DDRJ_DDRJ5                      _DDRJ.Bits.DDRJ5
#define DDRJ_DDRJ6                      _DDRJ.Bits.DDRJ6
#define DDRJ_DDRJ7                      _DDRJ.Bits.DDRJ7
#define DDRJ_DDRJ                       _DDRJ.MergedBits.grpDDRJ
#define DDRJ_DDRJ_4                     _DDRJ.MergedBits.grpDDRJ_4

#define DDRJ_DDRJ0_MASK                 1
#define DDRJ_DDRJ1_MASK                 2
#define DDRJ_DDRJ2_MASK                 4
#define DDRJ_DDRJ4_MASK                 16
#define DDRJ_DDRJ5_MASK                 32
#define DDRJ_DDRJ6_MASK                 64
#define DDRJ_DDRJ7_MASK                 128
#define DDRJ_DDRJ_MASK                  7
#define DDRJ_DDRJ_BITNUM                0
#define DDRJ_DDRJ_4_MASK                240
#define DDRJ_DDRJ_4_BITNUM              4


 RDRJ - Port J Reduced Drive Register; 0x0000026B 
typedef union {
  byte Byte;
  struct {
    byte RDRJ0       1;                                        Reduced Drive Port J Bit 0 
    byte RDRJ1       1;                                        Reduced Drive Port J Bit 1 
    byte RDRJ2       1;                                        Reduced Drive Port J Bit 2 
    byte             1; 
    byte RDRJ4       1;                                        Reduced Drive Port J Bit 4 
    byte RDRJ5       1;                                        Reduced Drive Port J Bit 5 
    byte RDRJ6       1;                                        Reduced Drive Port J Bit 6 
    byte RDRJ7       1;                                        Reduced Drive Port J Bit 7 
  } Bits;
  struct {
    byte grpRDRJ 3;
    byte         1;
    byte grpRDRJ_4 4;
  } MergedBits;
} RDRJSTR;
extern volatile RDRJSTR _RDRJ @(REG_BASE + 0x0000026B);
#define RDRJ                            _RDRJ.Byte
#define RDRJ_RDRJ0                      _RDRJ.Bits.RDRJ0
#define RDRJ_RDRJ1                      _RDRJ.Bits.RDRJ1
#define RDRJ_RDRJ2                      _RDRJ.Bits.RDRJ2
#define RDRJ_RDRJ4                      _RDRJ.Bits.RDRJ4
#define RDRJ_RDRJ5                      _RDRJ.Bits.RDRJ5
#define RDRJ_RDRJ6                      _RDRJ.Bits.RDRJ6
#define RDRJ_RDRJ7                      _RDRJ.Bits.RDRJ7
#define RDRJ_RDRJ                       _RDRJ.MergedBits.grpRDRJ
#define RDRJ_RDRJ_4                     _RDRJ.MergedBits.grpRDRJ_4

#define RDRJ_RDRJ0_MASK                 1
#define RDRJ_RDRJ1_MASK                 2
#define RDRJ_RDRJ2_MASK                 4
#define RDRJ_RDRJ4_MASK                 16
#define RDRJ_RDRJ5_MASK                 32
#define RDRJ_RDRJ6_MASK                 64
#define RDRJ_RDRJ7_MASK                 128
#define RDRJ_RDRJ_MASK                  7
#define RDRJ_RDRJ_BITNUM                0
#define RDRJ_RDRJ_4_MASK                240
#define RDRJ_RDRJ_4_BITNUM              4


 PERJ - Port J Pull Device Enable Register; 0x0000026C 
typedef union {
  byte Byte;
  struct {
    byte PERJ0       1;                                        Pull Device Enable Port J Bit 0 
    byte PERJ1       1;                                        Pull Device Enable Port J Bit 1 
    byte PERJ2       1;                                        Pull Device Enable Port J Bit 2 
    byte             1; 
    byte PERJ4       1;                                        Pull Device Enable Port J Bit 4 
    byte PERJ5       1;                                        Pull Device Enable Port J Bit 5 
    byte PERJ6       1;                                        Pull Device Enable Port J Bit 6 
    byte PERJ7       1;                                        Pull Device Enable Port J Bit 7 
  } Bits;
  struct {
    byte grpPERJ 3;
    byte         1;
    byte grpPERJ_4 4;
  } MergedBits;
} PERJSTR;
extern volatile PERJSTR _PERJ @(REG_BASE + 0x0000026C);
#define PERJ                            _PERJ.Byte
#define PERJ_PERJ0                      _PERJ.Bits.PERJ0
#define PERJ_PERJ1                      _PERJ.Bits.PERJ1
#define PERJ_PERJ2                      _PERJ.Bits.PERJ2
#define PERJ_PERJ4                      _PERJ.Bits.PERJ4
#define PERJ_PERJ5                      _PERJ.Bits.PERJ5
#define PERJ_PERJ6                      _PERJ.Bits.PERJ6
#define PERJ_PERJ7                      _PERJ.Bits.PERJ7
#define PERJ_PERJ                       _PERJ.MergedBits.grpPERJ
#define PERJ_PERJ_4                     _PERJ.MergedBits.grpPERJ_4

#define PERJ_PERJ0_MASK                 1
#define PERJ_PERJ1_MASK                 2
#define PERJ_PERJ2_MASK                 4
#define PERJ_PERJ4_MASK                 16
#define PERJ_PERJ5_MASK                 32
#define PERJ_PERJ6_MASK                 64
#define PERJ_PERJ7_MASK                 128
#define PERJ_PERJ_MASK                  7
#define PERJ_PERJ_BITNUM                0
#define PERJ_PERJ_4_MASK                240
#define PERJ_PERJ_4_BITNUM              4


 PPSJ - Port J Polarity Select Register; 0x0000026D 
typedef union {
  byte Byte;
  struct {
    byte PPSJ0       1;                                        Pull Select Port J Bit 0 
    byte PPSJ1       1;                                        Pull Select Port J Bit 1 
    byte PPSJ2       1;                                        Pull Select Port J Bit 2 
    byte             1; 
    byte PPSJ4       1;                                        Pull Select Port J Bit 4 
    byte PPSJ5       1;                                        Pull Select Port J Bit 5 
    byte PPSJ6       1;                                        Pull Select Port J Bit 6 
    byte PPSJ7       1;                                        Pull Select Port J Bit 7 
  } Bits;
  struct {
    byte grpPPSJ 3;
    byte         1;
    byte grpPPSJ_4 4;
  } MergedBits;
} PPSJSTR;
extern volatile PPSJSTR _PPSJ @(REG_BASE + 0x0000026D);
#define PPSJ                            _PPSJ.Byte
#define PPSJ_PPSJ0                      _PPSJ.Bits.PPSJ0
#define PPSJ_PPSJ1                      _PPSJ.Bits.PPSJ1
#define PPSJ_PPSJ2                      _PPSJ.Bits.PPSJ2
#define PPSJ_PPSJ4                      _PPSJ.Bits.PPSJ4
#define PPSJ_PPSJ5                      _PPSJ.Bits.PPSJ5
#define PPSJ_PPSJ6                      _PPSJ.Bits.PPSJ6
#define PPSJ_PPSJ7                      _PPSJ.Bits.PPSJ7
#define PPSJ_PPSJ                       _PPSJ.MergedBits.grpPPSJ
#define PPSJ_PPSJ_4                     _PPSJ.MergedBits.grpPPSJ_4

#define PPSJ_PPSJ0_MASK                 1
#define PPSJ_PPSJ1_MASK                 2
#define PPSJ_PPSJ2_MASK                 4
#define PPSJ_PPSJ4_MASK                 16
#define PPSJ_PPSJ5_MASK                 32
#define PPSJ_PPSJ6_MASK                 64
#define PPSJ_PPSJ7_MASK                 128
#define PPSJ_PPSJ_MASK                  7
#define PPSJ_PPSJ_BITNUM                0
#define PPSJ_PPSJ_4_MASK                240
#define PPSJ_PPSJ_4_BITNUM              4


 PIEJ - Port J Interrupt Enable Register; 0x0000026E 
typedef union {
  byte Byte;
  struct {
    byte PIEJ0       1;                                        Interrupt Enable Port J Bit 0 
    byte PIEJ1       1;                                        Interrupt Enable Port J Bit 1 
    byte PIEJ2       1;                                        Interrupt Enable Port J Bit 2 
    byte             1; 
    byte PIEJ4       1;                                        Interrupt Enable Port J Bit 4 
    byte PIEJ5       1;                                        Interrupt Enable Port J Bit 5 
    byte PIEJ6       1;                                        Interrupt Enable Port J Bit 6 
    byte PIEJ7       1;                                        Interrupt Enable Port J Bit 7 
  } Bits;
  struct {
    byte grpPIEJ 3;
    byte         1;
    byte grpPIEJ_4 4;
  } MergedBits;
} PIEJSTR;
extern volatile PIEJSTR _PIEJ @(REG_BASE + 0x0000026E);
#define PIEJ                            _PIEJ.Byte
#define PIEJ_PIEJ0                      _PIEJ.Bits.PIEJ0
#define PIEJ_PIEJ1                      _PIEJ.Bits.PIEJ1
#define PIEJ_PIEJ2                      _PIEJ.Bits.PIEJ2
#define PIEJ_PIEJ4                      _PIEJ.Bits.PIEJ4
#define PIEJ_PIEJ5                      _PIEJ.Bits.PIEJ5
#define PIEJ_PIEJ6                      _PIEJ.Bits.PIEJ6
#define PIEJ_PIEJ7                      _PIEJ.Bits.PIEJ7
#define PIEJ_PIEJ                       _PIEJ.MergedBits.grpPIEJ
#define PIEJ_PIEJ_4                     _PIEJ.MergedBits.grpPIEJ_4

#define PIEJ_PIEJ0_MASK                 1
#define PIEJ_PIEJ1_MASK                 2
#define PIEJ_PIEJ2_MASK                 4
#define PIEJ_PIEJ4_MASK                 16
#define PIEJ_PIEJ5_MASK                 32
#define PIEJ_PIEJ6_MASK                 64
#define PIEJ_PIEJ7_MASK                 128
#define PIEJ_PIEJ_MASK                  7
#define PIEJ_PIEJ_BITNUM                0
#define PIEJ_PIEJ_4_MASK                240
#define PIEJ_PIEJ_4_BITNUM              4


 PIFJ - Port J Interrupt Flag Register; 0x0000026F 
typedef union {
  byte Byte;
  struct {
    byte PIFJ0       1;                                        Interrupt Flags Port J Bit 0 
    byte PIFJ1       1;                                        Interrupt Flags Port J Bit 1 
    byte PIFJ2       1;                                        Interrupt Flags Port J Bit 2 
    byte             1; 
    byte PIFJ4       1;                                        Interrupt Flags Port J Bit 4 
    byte PIFJ5       1;                                        Interrupt Flags Port J Bit 5 
    byte PIFJ6       1;                                        Interrupt Flags Port J Bit 6 
    byte PIFJ7       1;                                        Interrupt Flags Port J Bit 7 
  } Bits;
  struct {
    byte grpPIFJ 3;
    byte         1;
    byte grpPIFJ_4 4;
  } MergedBits;
} PIFJSTR;
extern volatile PIFJSTR _PIFJ @(REG_BASE + 0x0000026F);
#define PIFJ                            _PIFJ.Byte
#define PIFJ_PIFJ0                      _PIFJ.Bits.PIFJ0
#define PIFJ_PIFJ1                      _PIFJ.Bits.PIFJ1
#define PIFJ_PIFJ2                      _PIFJ.Bits.PIFJ2
#define PIFJ_PIFJ4                      _PIFJ.Bits.PIFJ4
#define PIFJ_PIFJ5                      _PIFJ.Bits.PIFJ5
#define PIFJ_PIFJ6                      _PIFJ.Bits.PIFJ6
#define PIFJ_PIFJ7                      _PIFJ.Bits.PIFJ7
#define PIFJ_PIFJ                       _PIFJ.MergedBits.grpPIFJ
#define PIFJ_PIFJ_4                     _PIFJ.MergedBits.grpPIFJ_4

#define PIFJ_PIFJ0_MASK                 1
#define PIFJ_PIFJ1_MASK                 2
#define PIFJ_PIFJ2_MASK                 4
#define PIFJ_PIFJ4_MASK                 16
#define PIFJ_PIFJ5_MASK                 32
#define PIFJ_PIFJ6_MASK                 64
#define PIFJ_PIFJ7_MASK                 128
#define PIFJ_PIFJ_MASK                  7
#define PIFJ_PIFJ_BITNUM                0
#define PIFJ_PIFJ_4_MASK                240
#define PIFJ_PIFJ_4_BITNUM              4


 PT1AD0 - Port AD0 Data Register 1; 0x00000271 
typedef union {
  byte Byte;
  struct {
    byte PT1AD00     1;                                        Port AD0 Data Bit 0 
    byte PT1AD01     1;                                        Port AD0 Data Bit 1 
    byte PT1AD02     1;                                        Port AD0 Data Bit 2 
    byte PT1AD03     1;                                        Port AD0 Data Bit 3 
    byte PT1AD04     1;                                        Port AD0 Data Bit 4 
    byte PT1AD05     1;                                        Port AD0 Data Bit 5 
    byte PT1AD06     1;                                        Port AD0 Data Bit 6 
    byte PT1AD07     1;                                        Port AD0 Data Bit 7 
  } Bits;
} PT1AD0STR;
extern volatile PT1AD0STR _PT1AD0 @(REG_BASE + 0x00000271);
#define PT1AD0                          _PT1AD0.Byte
#define PT1AD0_PT1AD00                  _PT1AD0.Bits.PT1AD00
#define PT1AD0_PT1AD01                  _PT1AD0.Bits.PT1AD01
#define PT1AD0_PT1AD02                  _PT1AD0.Bits.PT1AD02
#define PT1AD0_PT1AD03                  _PT1AD0.Bits.PT1AD03
#define PT1AD0_PT1AD04                  _PT1AD0.Bits.PT1AD04
#define PT1AD0_PT1AD05                  _PT1AD0.Bits.PT1AD05
#define PT1AD0_PT1AD06                  _PT1AD0.Bits.PT1AD06
#define PT1AD0_PT1AD07                  _PT1AD0.Bits.PT1AD07

#define PT1AD0_PT1AD00_MASK             1
#define PT1AD0_PT1AD01_MASK             2
#define PT1AD0_PT1AD02_MASK             4
#define PT1AD0_PT1AD03_MASK             8
#define PT1AD0_PT1AD04_MASK             16
#define PT1AD0_PT1AD05_MASK             32
#define PT1AD0_PT1AD06_MASK             64
#define PT1AD0_PT1AD07_MASK             128


 DDR1AD0 - Port AD0 Data Direction Register 1; 0x00000273 
typedef union {
  byte Byte;
  struct {
    byte DDR1AD00    1;                                        Port AD0 Data Direction Bit 0 
    byte DDR1AD01    1;                                        Port AD0 Data Direction Bit 1 
    byte DDR1AD02    1;                                        Port AD0 Data Direction Bit 2 
    byte DDR1AD03    1;                                        Port AD0 Data Direction Bit 3 
    byte DDR1AD04    1;                                        Port AD0 Data Direction Bit 4 
    byte DDR1AD05    1;                                        Port AD0 Data Direction Bit 5 
    byte DDR1AD06    1;                                        Port AD0 Data Direction Bit 6 
    byte DDR1AD07    1;                                        Port AD0 Data Direction Bit 7 
  } Bits;
} DDR1AD0STR;
extern volatile DDR1AD0STR _DDR1AD0 @(REG_BASE + 0x00000273);
#define DDR1AD0                         _DDR1AD0.Byte
#define DDR1AD0_DDR1AD00                _DDR1AD0.Bits.DDR1AD00
#define DDR1AD0_DDR1AD01                _DDR1AD0.Bits.DDR1AD01
#define DDR1AD0_DDR1AD02                _DDR1AD0.Bits.DDR1AD02
#define DDR1AD0_DDR1AD03                _DDR1AD0.Bits.DDR1AD03
#define DDR1AD0_DDR1AD04                _DDR1AD0.Bits.DDR1AD04
#define DDR1AD0_DDR1AD05                _DDR1AD0.Bits.DDR1AD05
#define DDR1AD0_DDR1AD06                _DDR1AD0.Bits.DDR1AD06
#define DDR1AD0_DDR1AD07                _DDR1AD0.Bits.DDR1AD07

#define DDR1AD0_DDR1AD00_MASK           1
#define DDR1AD0_DDR1AD01_MASK           2
#define DDR1AD0_DDR1AD02_MASK           4
#define DDR1AD0_DDR1AD03_MASK           8
#define DDR1AD0_DDR1AD04_MASK           16
#define DDR1AD0_DDR1AD05_MASK           32
#define DDR1AD0_DDR1AD06_MASK           64
#define DDR1AD0_DDR1AD07_MASK           128


 RDR1AD0 - Port AD0 Reduced Drive Register 1; 0x00000275 
typedef union {
  byte Byte;
  struct {
    byte RDR1AD00    1;                                        Port AD0 Reduced Drive Bit 0 
    byte RDR1AD01    1;                                        Port AD0 Reduced Drive Bit 1 
    byte RDR1AD02    1;                                        Port AD0 Reduced Drive Bit 2 
    byte RDR1AD03    1;                                        Port AD0 Reduced Drive Bit 3 
    byte RDR1AD04    1;                                        Port AD0 Reduced Drive Bit 4 
    byte RDR1AD05    1;                                        Port AD0 Reduced Drive Bit 5 
    byte RDR1AD06    1;                                        Port AD0 Reduced Drive Bit 6 
    byte RDR1AD07    1;                                        Port AD0 Reduced Drive Bit 7 
  } Bits;
} RDR1AD0STR;
extern volatile RDR1AD0STR _RDR1AD0 @(REG_BASE + 0x00000275);
#define RDR1AD0                         _RDR1AD0.Byte
#define RDR1AD0_RDR1AD00                _RDR1AD0.Bits.RDR1AD00
#define RDR1AD0_RDR1AD01                _RDR1AD0.Bits.RDR1AD01
#define RDR1AD0_RDR1AD02                _RDR1AD0.Bits.RDR1AD02
#define RDR1AD0_RDR1AD03                _RDR1AD0.Bits.RDR1AD03
#define RDR1AD0_RDR1AD04                _RDR1AD0.Bits.RDR1AD04
#define RDR1AD0_RDR1AD05                _RDR1AD0.Bits.RDR1AD05
#define RDR1AD0_RDR1AD06                _RDR1AD0.Bits.RDR1AD06
#define RDR1AD0_RDR1AD07                _RDR1AD0.Bits.RDR1AD07

#define RDR1AD0_RDR1AD00_MASK           1
#define RDR1AD0_RDR1AD01_MASK           2
#define RDR1AD0_RDR1AD02_MASK           4
#define RDR1AD0_RDR1AD03_MASK           8
#define RDR1AD0_RDR1AD04_MASK           16
#define RDR1AD0_RDR1AD05_MASK           32
#define RDR1AD0_RDR1AD06_MASK           64
#define RDR1AD0_RDR1AD07_MASK           128


 PER1AD0 - Port AD0 Pull Up Enable Register 1; 0x00000277 
typedef union {
  byte Byte;
  struct {
    byte PER1AD00    1;                                        Port AD0 Pull Up Enable Bit 0 
    byte PER1AD01    1;                                        Port AD0 Pull Up Enable Bit 1 
    byte PER1AD02    1;                                        Port AD0 Pull Up Enable Bit 2 
    byte PER1AD03    1;                                        Port AD0 Pull Up Enable Bit 3 
    byte PER1AD04    1;                                        Port AD0 Pull Up Enable Bit 4 
    byte PER1AD05    1;                                        Port AD0 Pull Up Enable Bit 5 
    byte PER1AD06    1;                                        Port AD0 Pull Up Enable Bit 6 
    byte PER1AD07    1;                                        Port AD0 Pull Up Enable Bit 7 
  } Bits;
} PER1AD0STR;
extern volatile PER1AD0STR _PER1AD0 @(REG_BASE + 0x00000277);
#define PER1AD0                         _PER1AD0.Byte
#define PER1AD0_PER1AD00                _PER1AD0.Bits.PER1AD00
#define PER1AD0_PER1AD01                _PER1AD0.Bits.PER1AD01
#define PER1AD0_PER1AD02                _PER1AD0.Bits.PER1AD02
#define PER1AD0_PER1AD03                _PER1AD0.Bits.PER1AD03
#define PER1AD0_PER1AD04                _PER1AD0.Bits.PER1AD04
#define PER1AD0_PER1AD05                _PER1AD0.Bits.PER1AD05
#define PER1AD0_PER1AD06                _PER1AD0.Bits.PER1AD06
#define PER1AD0_PER1AD07                _PER1AD0.Bits.PER1AD07

#define PER1AD0_PER1AD00_MASK           1
#define PER1AD0_PER1AD01_MASK           2
#define PER1AD0_PER1AD02_MASK           4
#define PER1AD0_PER1AD03_MASK           8
#define PER1AD0_PER1AD04_MASK           16
#define PER1AD0_PER1AD05_MASK           32
#define PER1AD0_PER1AD06_MASK           64
#define PER1AD0_PER1AD07_MASK           128


 PT01AD1 - Port AD1 Data Register; 0x00000278 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PT0AD1 - Port AD1 Data Register 0; 0x00000278 
    union {
      byte Byte;
      struct {
        byte PT0AD116    1;                                        Port AD1 Data Bit 16 
        byte PT0AD117    1;                                        Port AD1 Data Bit 17 
        byte PT0AD118    1;                                        Port AD1 Data Bit 18 
        byte PT0AD119    1;                                        Port AD1 Data Bit 19 
        byte PT0AD120    1;                                        Port AD1 Data Bit 20 
        byte PT0AD121    1;                                        Port AD1 Data Bit 21 
        byte PT0AD122    1;                                        Port AD1 Data Bit 22 
        byte PT0AD123    1;                                        Port AD1 Data Bit 23 
      } Bits;
    } PT0AD1STR;
    #define PT0AD1                      _PT01AD1.Overlap_STR.PT0AD1STR.Byte
    #define PT0AD1_PT0AD116             _PT01AD1.Overlap_STR.PT0AD1STR.Bits.PT0AD116
    #define PT0AD1_PT0AD117             _PT01AD1.Overlap_STR.PT0AD1STR.Bits.PT0AD117
    #define PT0AD1_PT0AD118             _PT01AD1.Overlap_STR.PT0AD1STR.Bits.PT0AD118
    #define PT0AD1_PT0AD119             _PT01AD1.Overlap_STR.PT0AD1STR.Bits.PT0AD119
    #define PT0AD1_PT0AD120             _PT01AD1.Overlap_STR.PT0AD1STR.Bits.PT0AD120
    #define PT0AD1_PT0AD121             _PT01AD1.Overlap_STR.PT0AD1STR.Bits.PT0AD121
    #define PT0AD1_PT0AD122             _PT01AD1.Overlap_STR.PT0AD1STR.Bits.PT0AD122
    #define PT0AD1_PT0AD123             _PT01AD1.Overlap_STR.PT0AD1STR.Bits.PT0AD123
    
    
    #define PT0AD1_PT0AD116_MASK        1
    #define PT0AD1_PT0AD117_MASK        2
    #define PT0AD1_PT0AD118_MASK        4
    #define PT0AD1_PT0AD119_MASK        8
    #define PT0AD1_PT0AD120_MASK        16
    #define PT0AD1_PT0AD121_MASK        32
    #define PT0AD1_PT0AD122_MASK        64
    #define PT0AD1_PT0AD123_MASK        128


     PT1AD1 - Port AD1 Data Register 1; 0x00000279 
    union {
      byte Byte;
      struct {
        byte PT1AD18     1;                                        Port AD1 Data Bit 8 
        byte PT1AD19     1;                                        Port AD1 Data Bit 9 
        byte PT1AD110    1;                                        Port AD1 Data Bit 10 
        byte PT1AD111    1;                                        Port AD1 Data Bit 11 
        byte PT1AD112    1;                                        Port AD1 Data Bit 12 
        byte PT1AD113    1;                                        Port AD1 Data Bit 13 
        byte PT1AD114    1;                                        Port AD1 Data Bit 14 
        byte PT1AD115    1;                                        Port AD1 Data Bit 15 
      } Bits;
      struct {
        byte grpPT1AD_18 2;
        byte grpPT1AD1_10 6;
      } MergedBits;
    } PT1AD1STR;
    #define PT1AD1                      _PT01AD1.Overlap_STR.PT1AD1STR.Byte
    #define PT1AD1_PT1AD18              _PT01AD1.Overlap_STR.PT1AD1STR.Bits.PT1AD18
    #define PT1AD1_PT1AD19              _PT01AD1.Overlap_STR.PT1AD1STR.Bits.PT1AD19
    #define PT1AD1_PT1AD110             _PT01AD1.Overlap_STR.PT1AD1STR.Bits.PT1AD110
    #define PT1AD1_PT1AD111             _PT01AD1.Overlap_STR.PT1AD1STR.Bits.PT1AD111
    #define PT1AD1_PT1AD112             _PT01AD1.Overlap_STR.PT1AD1STR.Bits.PT1AD112
    #define PT1AD1_PT1AD113             _PT01AD1.Overlap_STR.PT1AD1STR.Bits.PT1AD113
    #define PT1AD1_PT1AD114             _PT01AD1.Overlap_STR.PT1AD1STR.Bits.PT1AD114
    #define PT1AD1_PT1AD115             _PT01AD1.Overlap_STR.PT1AD1STR.Bits.PT1AD115
    
    #define PT1AD1_PT1AD_18             _PT01AD1.Overlap_STR.PT1AD1STR.MergedBits.grpPT1AD_18
    #define PT1AD1_PT1AD1_10            _PT01AD1.Overlap_STR.PT1AD1STR.MergedBits.grpPT1AD1_10
    #define PT1AD1_PT1AD                PT1AD1_PT1AD_18
    
    #define PT1AD1_PT1AD18_MASK         1
    #define PT1AD1_PT1AD19_MASK         2
    #define PT1AD1_PT1AD110_MASK        4
    #define PT1AD1_PT1AD111_MASK        8
    #define PT1AD1_PT1AD112_MASK        16
    #define PT1AD1_PT1AD113_MASK        32
    #define PT1AD1_PT1AD114_MASK        64
    #define PT1AD1_PT1AD115_MASK        128
    #define PT1AD1_PT1AD_18_MASK        3
    #define PT1AD1_PT1AD_18_BITNUM      0
    #define PT1AD1_PT1AD1_10_MASK       252
    #define PT1AD1_PT1AD1_10_BITNUM     2

  } Overlap_STR;

  struct {
    word PT1AD18     1;                                        Port AD1 Data Bit 8 
    word PT1AD19     1;                                        Port AD1 Data Bit 9 
    word PT1AD110    1;                                        Port AD1 Data Bit 10 
    word PT1AD111    1;                                        Port AD1 Data Bit 11 
    word PT1AD112    1;                                        Port AD1 Data Bit 12 
    word PT1AD113    1;                                        Port AD1 Data Bit 13 
    word PT1AD114    1;                                        Port AD1 Data Bit 14 
    word PT1AD115    1;                                        Port AD1 Data Bit 15 
    word PT0AD116    1;                                        Port AD1 Data Bit 16 
    word PT0AD117    1;                                        Port AD1 Data Bit 17 
    word PT0AD118    1;                                        Port AD1 Data Bit 18 
    word PT0AD119    1;                                        Port AD1 Data Bit 19 
    word PT0AD120    1;                                        Port AD1 Data Bit 20 
    word PT0AD121    1;                                        Port AD1 Data Bit 21 
    word PT0AD122    1;                                        Port AD1 Data Bit 22 
    word PT0AD123    1;                                        Port AD1 Data Bit 23 
  } Bits;
  struct {
    word grpPT1AD_18 2;
    word grpPT1AD1_10 6;
    word grpPT0AD1_16 8;
  } MergedBits;
} PT01AD1STR;
extern volatile PT01AD1STR _PT01AD1 @(REG_BASE + 0x00000278);
#define PT01AD1                         _PT01AD1.Word
#define PT01AD1_PT1AD18                 _PT01AD1.Bits.PT1AD18
#define PT01AD1_PT1AD19                 _PT01AD1.Bits.PT1AD19
#define PT01AD1_PT1AD110                _PT01AD1.Bits.PT1AD110
#define PT01AD1_PT1AD111                _PT01AD1.Bits.PT1AD111
#define PT01AD1_PT1AD112                _PT01AD1.Bits.PT1AD112
#define PT01AD1_PT1AD113                _PT01AD1.Bits.PT1AD113
#define PT01AD1_PT1AD114                _PT01AD1.Bits.PT1AD114
#define PT01AD1_PT1AD115                _PT01AD1.Bits.PT1AD115
#define PT01AD1_PT0AD116                _PT01AD1.Bits.PT0AD116
#define PT01AD1_PT0AD117                _PT01AD1.Bits.PT0AD117
#define PT01AD1_PT0AD118                _PT01AD1.Bits.PT0AD118
#define PT01AD1_PT0AD119                _PT01AD1.Bits.PT0AD119
#define PT01AD1_PT0AD120                _PT01AD1.Bits.PT0AD120
#define PT01AD1_PT0AD121                _PT01AD1.Bits.PT0AD121
#define PT01AD1_PT0AD122                _PT01AD1.Bits.PT0AD122
#define PT01AD1_PT0AD123                _PT01AD1.Bits.PT0AD123
#define PT01AD1_PT1AD_18                _PT01AD1.MergedBits.grpPT1AD_18
#define PT01AD1_PT1AD1_10               _PT01AD1.MergedBits.grpPT1AD1_10
#define PT01AD1_PT0AD1_16               _PT01AD1.MergedBits.grpPT0AD1_16
#define PT01AD1_PT1AD                   PT01AD1_PT1AD_18
#define PT01AD1_PT1AD1                  PT01AD1_PT1AD1_10
#define PT01AD1_PT0AD1                  PT01AD1_PT0AD1_16

#define PT01AD1_PT1AD18_MASK            1
#define PT01AD1_PT1AD19_MASK            2
#define PT01AD1_PT1AD110_MASK           4
#define PT01AD1_PT1AD111_MASK           8
#define PT01AD1_PT1AD112_MASK           16
#define PT01AD1_PT1AD113_MASK           32
#define PT01AD1_PT1AD114_MASK           64
#define PT01AD1_PT1AD115_MASK           128
#define PT01AD1_PT0AD116_MASK           256
#define PT01AD1_PT0AD117_MASK           512
#define PT01AD1_PT0AD118_MASK           1024
#define PT01AD1_PT0AD119_MASK           2048
#define PT01AD1_PT0AD120_MASK           4096
#define PT01AD1_PT0AD121_MASK           8192
#define PT01AD1_PT0AD122_MASK           16384
#define PT01AD1_PT0AD123_MASK           32768
#define PT01AD1_PT1AD_18_MASK           3
#define PT01AD1_PT1AD_18_BITNUM         0
#define PT01AD1_PT1AD1_10_MASK          252
#define PT01AD1_PT1AD1_10_BITNUM        2
#define PT01AD1_PT0AD1_16_MASK          65280
#define PT01AD1_PT0AD1_16_BITNUM        8


 DDR01AD1 - Port AD1 Data Direction Register; 0x0000027A 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     DDR0AD1 - Port AD1 Data Direction Register 0; 0x0000027A 
    union {
      byte Byte;
      struct {
        byte DDR0AD116   1;                                        Port AD1 Data Direction Bit 16 
        byte DDR0AD117   1;                                        Port AD1 Data Direction Bit 17 
        byte DDR0AD118   1;                                        Port AD1 Data Direction Bit 18 
        byte DDR0AD119   1;                                        Port AD1 Data Direction Bit 19 
        byte DDR0AD120   1;                                        Port AD1 Data Direction Bit 20 
        byte DDR0AD121   1;                                        Port AD1 Data Direction Bit 21 
        byte DDR0AD122   1;                                        Port AD1 Data Direction Bit 22 
        byte DDR0AD123   1;                                        Port AD1 Data Direction Bit 23 
      } Bits;
    } DDR0AD1STR;
    #define DDR0AD1                     _DDR01AD1.Overlap_STR.DDR0AD1STR.Byte
    #define DDR0AD1_DDR0AD116           _DDR01AD1.Overlap_STR.DDR0AD1STR.Bits.DDR0AD116
    #define DDR0AD1_DDR0AD117           _DDR01AD1.Overlap_STR.DDR0AD1STR.Bits.DDR0AD117
    #define DDR0AD1_DDR0AD118           _DDR01AD1.Overlap_STR.DDR0AD1STR.Bits.DDR0AD118
    #define DDR0AD1_DDR0AD119           _DDR01AD1.Overlap_STR.DDR0AD1STR.Bits.DDR0AD119
    #define DDR0AD1_DDR0AD120           _DDR01AD1.Overlap_STR.DDR0AD1STR.Bits.DDR0AD120
    #define DDR0AD1_DDR0AD121           _DDR01AD1.Overlap_STR.DDR0AD1STR.Bits.DDR0AD121
    #define DDR0AD1_DDR0AD122           _DDR01AD1.Overlap_STR.DDR0AD1STR.Bits.DDR0AD122
    #define DDR0AD1_DDR0AD123           _DDR01AD1.Overlap_STR.DDR0AD1STR.Bits.DDR0AD123
    
    
    #define DDR0AD1_DDR0AD116_MASK      1
    #define DDR0AD1_DDR0AD117_MASK      2
    #define DDR0AD1_DDR0AD118_MASK      4
    #define DDR0AD1_DDR0AD119_MASK      8
    #define DDR0AD1_DDR0AD120_MASK      16
    #define DDR0AD1_DDR0AD121_MASK      32
    #define DDR0AD1_DDR0AD122_MASK      64
    #define DDR0AD1_DDR0AD123_MASK      128


     DDR1AD1 - Port AD1 Data Direction Register 1; 0x0000027B 
    union {
      byte Byte;
      struct {
        byte DDR1AD18    1;                                        Port AD1 Data Direction Bit 8 
        byte DDR1AD19    1;                                        Port AD1 Data Direction Bit 9 
        byte DDR1AD110   1;                                        Port AD1 Data Direction Bit 10 
        byte DDR1AD111   1;                                        Port AD1 Data Direction Bit 11 
        byte DDR1AD112   1;                                        Port AD1 Data Direction Bit 12 
        byte DDR1AD113   1;                                        Port AD1 Data Direction Bit 13 
        byte DDR1AD114   1;                                        Port AD1 Data Direction Bit 14 
        byte DDR1AD115   1;                                        Port AD1 Data Direction Bit 15 
      } Bits;
      struct {
        byte grpDDR1AD_18 2;
        byte grpDDR1AD1_10 6;
      } MergedBits;
    } DDR1AD1STR;
    #define DDR1AD1                     _DDR01AD1.Overlap_STR.DDR1AD1STR.Byte
    #define DDR1AD1_DDR1AD18            _DDR01AD1.Overlap_STR.DDR1AD1STR.Bits.DDR1AD18
    #define DDR1AD1_DDR1AD19            _DDR01AD1.Overlap_STR.DDR1AD1STR.Bits.DDR1AD19
    #define DDR1AD1_DDR1AD110           _DDR01AD1.Overlap_STR.DDR1AD1STR.Bits.DDR1AD110
    #define DDR1AD1_DDR1AD111           _DDR01AD1.Overlap_STR.DDR1AD1STR.Bits.DDR1AD111
    #define DDR1AD1_DDR1AD112           _DDR01AD1.Overlap_STR.DDR1AD1STR.Bits.DDR1AD112
    #define DDR1AD1_DDR1AD113           _DDR01AD1.Overlap_STR.DDR1AD1STR.Bits.DDR1AD113
    #define DDR1AD1_DDR1AD114           _DDR01AD1.Overlap_STR.DDR1AD1STR.Bits.DDR1AD114
    #define DDR1AD1_DDR1AD115           _DDR01AD1.Overlap_STR.DDR1AD1STR.Bits.DDR1AD115
    
    #define DDR1AD1_DDR1AD_18           _DDR01AD1.Overlap_STR.DDR1AD1STR.MergedBits.grpDDR1AD_18
    #define DDR1AD1_DDR1AD1_10          _DDR01AD1.Overlap_STR.DDR1AD1STR.MergedBits.grpDDR1AD1_10
    #define DDR1AD1_DDR1AD              DDR1AD1_DDR1AD_18
    
    #define DDR1AD1_DDR1AD18_MASK       1
    #define DDR1AD1_DDR1AD19_MASK       2
    #define DDR1AD1_DDR1AD110_MASK      4
    #define DDR1AD1_DDR1AD111_MASK      8
    #define DDR1AD1_DDR1AD112_MASK      16
    #define DDR1AD1_DDR1AD113_MASK      32
    #define DDR1AD1_DDR1AD114_MASK      64
    #define DDR1AD1_DDR1AD115_MASK      128
    #define DDR1AD1_DDR1AD_18_MASK      3
    #define DDR1AD1_DDR1AD_18_BITNUM    0
    #define DDR1AD1_DDR1AD1_10_MASK     252
    #define DDR1AD1_DDR1AD1_10_BITNUM   2

  } Overlap_STR;

  struct {
    word DDR1AD18    1;                                        Port AD1 Data Direction Bit 8 
    word DDR1AD19    1;                                        Port AD1 Data Direction Bit 9 
    word DDR1AD110   1;                                        Port AD1 Data Direction Bit 10 
    word DDR1AD111   1;                                        Port AD1 Data Direction Bit 11 
    word DDR1AD112   1;                                        Port AD1 Data Direction Bit 12 
    word DDR1AD113   1;                                        Port AD1 Data Direction Bit 13 
    word DDR1AD114   1;                                        Port AD1 Data Direction Bit 14 
    word DDR1AD115   1;                                        Port AD1 Data Direction Bit 15 
    word DDR0AD116   1;                                        Port AD1 Data Direction Bit 16 
    word DDR0AD117   1;                                        Port AD1 Data Direction Bit 17 
    word DDR0AD118   1;                                        Port AD1 Data Direction Bit 18 
    word DDR0AD119   1;                                        Port AD1 Data Direction Bit 19 
    word DDR0AD120   1;                                        Port AD1 Data Direction Bit 20 
    word DDR0AD121   1;                                        Port AD1 Data Direction Bit 21 
    word DDR0AD122   1;                                        Port AD1 Data Direction Bit 22 
    word DDR0AD123   1;                                        Port AD1 Data Direction Bit 23 
  } Bits;
  struct {
    word grpDDR1AD_18 2;
    word grpDDR1AD1_10 6;
    word grpDDR0AD1_16 8;
  } MergedBits;
} DDR01AD1STR;
extern volatile DDR01AD1STR _DDR01AD1 @(REG_BASE + 0x0000027A);
#define DDR01AD1                        _DDR01AD1.Word
#define DDR01AD1_DDR1AD18               _DDR01AD1.Bits.DDR1AD18
#define DDR01AD1_DDR1AD19               _DDR01AD1.Bits.DDR1AD19
#define DDR01AD1_DDR1AD110              _DDR01AD1.Bits.DDR1AD110
#define DDR01AD1_DDR1AD111              _DDR01AD1.Bits.DDR1AD111
#define DDR01AD1_DDR1AD112              _DDR01AD1.Bits.DDR1AD112
#define DDR01AD1_DDR1AD113              _DDR01AD1.Bits.DDR1AD113
#define DDR01AD1_DDR1AD114              _DDR01AD1.Bits.DDR1AD114
#define DDR01AD1_DDR1AD115              _DDR01AD1.Bits.DDR1AD115
#define DDR01AD1_DDR0AD116              _DDR01AD1.Bits.DDR0AD116
#define DDR01AD1_DDR0AD117              _DDR01AD1.Bits.DDR0AD117
#define DDR01AD1_DDR0AD118              _DDR01AD1.Bits.DDR0AD118
#define DDR01AD1_DDR0AD119              _DDR01AD1.Bits.DDR0AD119
#define DDR01AD1_DDR0AD120              _DDR01AD1.Bits.DDR0AD120
#define DDR01AD1_DDR0AD121              _DDR01AD1.Bits.DDR0AD121
#define DDR01AD1_DDR0AD122              _DDR01AD1.Bits.DDR0AD122
#define DDR01AD1_DDR0AD123              _DDR01AD1.Bits.DDR0AD123
#define DDR01AD1_DDR1AD_18              _DDR01AD1.MergedBits.grpDDR1AD_18
#define DDR01AD1_DDR1AD1_10             _DDR01AD1.MergedBits.grpDDR1AD1_10
#define DDR01AD1_DDR0AD1_16             _DDR01AD1.MergedBits.grpDDR0AD1_16
#define DDR01AD1_DDR1AD                 DDR01AD1_DDR1AD_18
#define DDR01AD1_DDR1AD1                DDR01AD1_DDR1AD1_10
#define DDR01AD1_DDR0AD1                DDR01AD1_DDR0AD1_16

#define DDR01AD1_DDR1AD18_MASK          1
#define DDR01AD1_DDR1AD19_MASK          2
#define DDR01AD1_DDR1AD110_MASK         4
#define DDR01AD1_DDR1AD111_MASK         8
#define DDR01AD1_DDR1AD112_MASK         16
#define DDR01AD1_DDR1AD113_MASK         32
#define DDR01AD1_DDR1AD114_MASK         64
#define DDR01AD1_DDR1AD115_MASK         128
#define DDR01AD1_DDR0AD116_MASK         256
#define DDR01AD1_DDR0AD117_MASK         512
#define DDR01AD1_DDR0AD118_MASK         1024
#define DDR01AD1_DDR0AD119_MASK         2048
#define DDR01AD1_DDR0AD120_MASK         4096
#define DDR01AD1_DDR0AD121_MASK         8192
#define DDR01AD1_DDR0AD122_MASK         16384
#define DDR01AD1_DDR0AD123_MASK         32768
#define DDR01AD1_DDR1AD_18_MASK         3
#define DDR01AD1_DDR1AD_18_BITNUM       0
#define DDR01AD1_DDR1AD1_10_MASK        252
#define DDR01AD1_DDR1AD1_10_BITNUM      2
#define DDR01AD1_DDR0AD1_16_MASK        65280
#define DDR01AD1_DDR0AD1_16_BITNUM      8


 RDR01AD1 - Port AD1 Reduced Drive Register; 0x0000027C 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     RDR0AD1 - Port AD1 Reduced Drive Register 0; 0x0000027C 
    union {
      byte Byte;
      struct {
        byte RDR0AD116   1;                                        Port AD1 Reduced Drive Bit 16 
        byte RDR0AD117   1;                                        Port AD1 Reduced Drive Bit 17 
        byte RDR0AD118   1;                                        Port AD1 Reduced Drive Bit 18 
        byte RDR0AD119   1;                                        Port AD1 Reduced Drive Bit 19 
        byte RDR0AD120   1;                                        Port AD1 Reduced Drive Bit 20 
        byte RDR0AD121   1;                                        Port AD1 Reduced Drive Bit 21 
        byte RDR0AD122   1;                                        Port AD1 Reduced Drive Bit 22 
        byte RDR0AD123   1;                                        Port AD1 Reduced Drive Bit 23 
      } Bits;
    } RDR0AD1STR;
    #define RDR0AD1                     _RDR01AD1.Overlap_STR.RDR0AD1STR.Byte
    #define RDR0AD1_RDR0AD116           _RDR01AD1.Overlap_STR.RDR0AD1STR.Bits.RDR0AD116
    #define RDR0AD1_RDR0AD117           _RDR01AD1.Overlap_STR.RDR0AD1STR.Bits.RDR0AD117
    #define RDR0AD1_RDR0AD118           _RDR01AD1.Overlap_STR.RDR0AD1STR.Bits.RDR0AD118
    #define RDR0AD1_RDR0AD119           _RDR01AD1.Overlap_STR.RDR0AD1STR.Bits.RDR0AD119
    #define RDR0AD1_RDR0AD120           _RDR01AD1.Overlap_STR.RDR0AD1STR.Bits.RDR0AD120
    #define RDR0AD1_RDR0AD121           _RDR01AD1.Overlap_STR.RDR0AD1STR.Bits.RDR0AD121
    #define RDR0AD1_RDR0AD122           _RDR01AD1.Overlap_STR.RDR0AD1STR.Bits.RDR0AD122
    #define RDR0AD1_RDR0AD123           _RDR01AD1.Overlap_STR.RDR0AD1STR.Bits.RDR0AD123
    
    
    #define RDR0AD1_RDR0AD116_MASK      1
    #define RDR0AD1_RDR0AD117_MASK      2
    #define RDR0AD1_RDR0AD118_MASK      4
    #define RDR0AD1_RDR0AD119_MASK      8
    #define RDR0AD1_RDR0AD120_MASK      16
    #define RDR0AD1_RDR0AD121_MASK      32
    #define RDR0AD1_RDR0AD122_MASK      64
    #define RDR0AD1_RDR0AD123_MASK      128


     RDR1AD1 - Port AD1 Reduced Drive Register 1; 0x0000027D 
    union {
      byte Byte;
      struct {
        byte RDR1AD18    1;                                        Port AD1 Reduced Drive Bit 8 
        byte RDR1AD19    1;                                        Port AD1 Reduced Drive Bit 9 
        byte RDR1AD110   1;                                        Port AD1 Reduced Drive Bit 10 
        byte RDR1AD111   1;                                        Port AD1 Reduced Drive Bit 11 
        byte RDR1AD112   1;                                        Port AD1 Reduced Drive Bit 12 
        byte RDR1AD113   1;                                        Port AD1 Reduced Drive Bit 13 
        byte RDR1AD114   1;                                        Port AD1 Reduced Drive Bit 14 
        byte RDR1AD115   1;                                        Port AD1 Reduced Drive Bit 15 
      } Bits;
      struct {
        byte grpRDR1AD_18 2;
        byte grpRDR1AD1_10 6;
      } MergedBits;
    } RDR1AD1STR;
    #define RDR1AD1                     _RDR01AD1.Overlap_STR.RDR1AD1STR.Byte
    #define RDR1AD1_RDR1AD18            _RDR01AD1.Overlap_STR.RDR1AD1STR.Bits.RDR1AD18
    #define RDR1AD1_RDR1AD19            _RDR01AD1.Overlap_STR.RDR1AD1STR.Bits.RDR1AD19
    #define RDR1AD1_RDR1AD110           _RDR01AD1.Overlap_STR.RDR1AD1STR.Bits.RDR1AD110
    #define RDR1AD1_RDR1AD111           _RDR01AD1.Overlap_STR.RDR1AD1STR.Bits.RDR1AD111
    #define RDR1AD1_RDR1AD112           _RDR01AD1.Overlap_STR.RDR1AD1STR.Bits.RDR1AD112
    #define RDR1AD1_RDR1AD113           _RDR01AD1.Overlap_STR.RDR1AD1STR.Bits.RDR1AD113
    #define RDR1AD1_RDR1AD114           _RDR01AD1.Overlap_STR.RDR1AD1STR.Bits.RDR1AD114
    #define RDR1AD1_RDR1AD115           _RDR01AD1.Overlap_STR.RDR1AD1STR.Bits.RDR1AD115
    
    #define RDR1AD1_RDR1AD_18           _RDR01AD1.Overlap_STR.RDR1AD1STR.MergedBits.grpRDR1AD_18
    #define RDR1AD1_RDR1AD1_10          _RDR01AD1.Overlap_STR.RDR1AD1STR.MergedBits.grpRDR1AD1_10
    #define RDR1AD1_RDR1AD              RDR1AD1_RDR1AD_18
    
    #define RDR1AD1_RDR1AD18_MASK       1
    #define RDR1AD1_RDR1AD19_MASK       2
    #define RDR1AD1_RDR1AD110_MASK      4
    #define RDR1AD1_RDR1AD111_MASK      8
    #define RDR1AD1_RDR1AD112_MASK      16
    #define RDR1AD1_RDR1AD113_MASK      32
    #define RDR1AD1_RDR1AD114_MASK      64
    #define RDR1AD1_RDR1AD115_MASK      128
    #define RDR1AD1_RDR1AD_18_MASK      3
    #define RDR1AD1_RDR1AD_18_BITNUM    0
    #define RDR1AD1_RDR1AD1_10_MASK     252
    #define RDR1AD1_RDR1AD1_10_BITNUM   2

  } Overlap_STR;

  struct {
    word RDR1AD18    1;                                        Port AD1 Reduced Drive Bit 8 
    word RDR1AD19    1;                                        Port AD1 Reduced Drive Bit 9 
    word RDR1AD110   1;                                        Port AD1 Reduced Drive Bit 10 
    word RDR1AD111   1;                                        Port AD1 Reduced Drive Bit 11 
    word RDR1AD112   1;                                        Port AD1 Reduced Drive Bit 12 
    word RDR1AD113   1;                                        Port AD1 Reduced Drive Bit 13 
    word RDR1AD114   1;                                        Port AD1 Reduced Drive Bit 14 
    word RDR1AD115   1;                                        Port AD1 Reduced Drive Bit 15 
    word RDR0AD116   1;                                        Port AD1 Reduced Drive Bit 16 
    word RDR0AD117   1;                                        Port AD1 Reduced Drive Bit 17 
    word RDR0AD118   1;                                        Port AD1 Reduced Drive Bit 18 
    word RDR0AD119   1;                                        Port AD1 Reduced Drive Bit 19 
    word RDR0AD120   1;                                        Port AD1 Reduced Drive Bit 20 
    word RDR0AD121   1;                                        Port AD1 Reduced Drive Bit 21 
    word RDR0AD122   1;                                        Port AD1 Reduced Drive Bit 22 
    word RDR0AD123   1;                                        Port AD1 Reduced Drive Bit 23 
  } Bits;
  struct {
    word grpRDR1AD_18 2;
    word grpRDR1AD1_10 6;
    word grpRDR0AD1_16 8;
  } MergedBits;
} RDR01AD1STR;
extern volatile RDR01AD1STR _RDR01AD1 @(REG_BASE + 0x0000027C);
#define RDR01AD1                        _RDR01AD1.Word
#define RDR01AD1_RDR1AD18               _RDR01AD1.Bits.RDR1AD18
#define RDR01AD1_RDR1AD19               _RDR01AD1.Bits.RDR1AD19
#define RDR01AD1_RDR1AD110              _RDR01AD1.Bits.RDR1AD110
#define RDR01AD1_RDR1AD111              _RDR01AD1.Bits.RDR1AD111
#define RDR01AD1_RDR1AD112              _RDR01AD1.Bits.RDR1AD112
#define RDR01AD1_RDR1AD113              _RDR01AD1.Bits.RDR1AD113
#define RDR01AD1_RDR1AD114              _RDR01AD1.Bits.RDR1AD114
#define RDR01AD1_RDR1AD115              _RDR01AD1.Bits.RDR1AD115
#define RDR01AD1_RDR0AD116              _RDR01AD1.Bits.RDR0AD116
#define RDR01AD1_RDR0AD117              _RDR01AD1.Bits.RDR0AD117
#define RDR01AD1_RDR0AD118              _RDR01AD1.Bits.RDR0AD118
#define RDR01AD1_RDR0AD119              _RDR01AD1.Bits.RDR0AD119
#define RDR01AD1_RDR0AD120              _RDR01AD1.Bits.RDR0AD120
#define RDR01AD1_RDR0AD121              _RDR01AD1.Bits.RDR0AD121
#define RDR01AD1_RDR0AD122              _RDR01AD1.Bits.RDR0AD122
#define RDR01AD1_RDR0AD123              _RDR01AD1.Bits.RDR0AD123
#define RDR01AD1_RDR1AD_18              _RDR01AD1.MergedBits.grpRDR1AD_18
#define RDR01AD1_RDR1AD1_10             _RDR01AD1.MergedBits.grpRDR1AD1_10
#define RDR01AD1_RDR0AD1_16             _RDR01AD1.MergedBits.grpRDR0AD1_16
#define RDR01AD1_RDR1AD                 RDR01AD1_RDR1AD_18
#define RDR01AD1_RDR1AD1                RDR01AD1_RDR1AD1_10
#define RDR01AD1_RDR0AD1                RDR01AD1_RDR0AD1_16

#define RDR01AD1_RDR1AD18_MASK          1
#define RDR01AD1_RDR1AD19_MASK          2
#define RDR01AD1_RDR1AD110_MASK         4
#define RDR01AD1_RDR1AD111_MASK         8
#define RDR01AD1_RDR1AD112_MASK         16
#define RDR01AD1_RDR1AD113_MASK         32
#define RDR01AD1_RDR1AD114_MASK         64
#define RDR01AD1_RDR1AD115_MASK         128
#define RDR01AD1_RDR0AD116_MASK         256
#define RDR01AD1_RDR0AD117_MASK         512
#define RDR01AD1_RDR0AD118_MASK         1024
#define RDR01AD1_RDR0AD119_MASK         2048
#define RDR01AD1_RDR0AD120_MASK         4096
#define RDR01AD1_RDR0AD121_MASK         8192
#define RDR01AD1_RDR0AD122_MASK         16384
#define RDR01AD1_RDR0AD123_MASK         32768
#define RDR01AD1_RDR1AD_18_MASK         3
#define RDR01AD1_RDR1AD_18_BITNUM       0
#define RDR01AD1_RDR1AD1_10_MASK        252
#define RDR01AD1_RDR1AD1_10_BITNUM      2
#define RDR01AD1_RDR0AD1_16_MASK        65280
#define RDR01AD1_RDR0AD1_16_BITNUM      8


 PER01AD1 - Port AD1 Pull Up Enable Register; 0x0000027E 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PER0AD1 - Port AD1 Pull Up Enable Register 0; 0x0000027E 
    union {
      byte Byte;
      struct {
        byte PER0AD116   1;                                        Port AD1 Pull Up Enable Bit 16 
        byte PER0AD117   1;                                        Port AD1 Pull Up Enable Bit 17 
        byte PER0AD118   1;                                        Port AD1 Pull Up Enable Bit 18 
        byte PER0AD119   1;                                        Port AD1 Pull Up Enable Bit 19 
        byte PER0AD120   1;                                        Port AD1 Pull Up Enable Bit 20 
        byte PER0AD121   1;                                        Port AD1 Pull Up Enable Bit 21 
        byte PER0AD122   1;                                        Port AD1 Pull Up Enable Bit 22 
        byte PER0AD123   1;                                        Port AD1 Pull Up Enable Bit 23 
      } Bits;
    } PER0AD1STR;
    #define PER0AD1                     _PER01AD1.Overlap_STR.PER0AD1STR.Byte
    #define PER0AD1_PER0AD116           _PER01AD1.Overlap_STR.PER0AD1STR.Bits.PER0AD116
    #define PER0AD1_PER0AD117           _PER01AD1.Overlap_STR.PER0AD1STR.Bits.PER0AD117
    #define PER0AD1_PER0AD118           _PER01AD1.Overlap_STR.PER0AD1STR.Bits.PER0AD118
    #define PER0AD1_PER0AD119           _PER01AD1.Overlap_STR.PER0AD1STR.Bits.PER0AD119
    #define PER0AD1_PER0AD120           _PER01AD1.Overlap_STR.PER0AD1STR.Bits.PER0AD120
    #define PER0AD1_PER0AD121           _PER01AD1.Overlap_STR.PER0AD1STR.Bits.PER0AD121
    #define PER0AD1_PER0AD122           _PER01AD1.Overlap_STR.PER0AD1STR.Bits.PER0AD122
    #define PER0AD1_PER0AD123           _PER01AD1.Overlap_STR.PER0AD1STR.Bits.PER0AD123
    
    
    #define PER0AD1_PER0AD116_MASK      1
    #define PER0AD1_PER0AD117_MASK      2
    #define PER0AD1_PER0AD118_MASK      4
    #define PER0AD1_PER0AD119_MASK      8
    #define PER0AD1_PER0AD120_MASK      16
    #define PER0AD1_PER0AD121_MASK      32
    #define PER0AD1_PER0AD122_MASK      64
    #define PER0AD1_PER0AD123_MASK      128


     PER1AD1 - Port AD1 Pull Up Enable Register 1; 0x0000027F 
    union {
      byte Byte;
      struct {
        byte PER1AD18    1;                                        Port AD1 Pull Up Enable Bit 8 
        byte PER1AD19    1;                                        Port AD1 Pull Up Enable Bit 9 
        byte PER1AD110   1;                                        Port AD1 Pull Up Enable Bit 10 
        byte PER1AD111   1;                                        Port AD1 Pull Up Enable Bit 11 
        byte PER1AD112   1;                                        Port AD1 Pull Up Enable Bit 12 
        byte PER1AD113   1;                                        Port AD1 Pull Up Enable Bit 13 
        byte PER1AD114   1;                                        Port AD1 Pull Up Enable Bit 14 
        byte PER1AD115   1;                                        Port AD1 Pull Up Enable Bit 15 
      } Bits;
      struct {
        byte grpPER1AD_18 2;
        byte grpPER1AD1_10 6;
      } MergedBits;
    } PER1AD1STR;
    #define PER1AD1                     _PER01AD1.Overlap_STR.PER1AD1STR.Byte
    #define PER1AD1_PER1AD18            _PER01AD1.Overlap_STR.PER1AD1STR.Bits.PER1AD18
    #define PER1AD1_PER1AD19            _PER01AD1.Overlap_STR.PER1AD1STR.Bits.PER1AD19
    #define PER1AD1_PER1AD110           _PER01AD1.Overlap_STR.PER1AD1STR.Bits.PER1AD110
    #define PER1AD1_PER1AD111           _PER01AD1.Overlap_STR.PER1AD1STR.Bits.PER1AD111
    #define PER1AD1_PER1AD112           _PER01AD1.Overlap_STR.PER1AD1STR.Bits.PER1AD112
    #define PER1AD1_PER1AD113           _PER01AD1.Overlap_STR.PER1AD1STR.Bits.PER1AD113
    #define PER1AD1_PER1AD114           _PER01AD1.Overlap_STR.PER1AD1STR.Bits.PER1AD114
    #define PER1AD1_PER1AD115           _PER01AD1.Overlap_STR.PER1AD1STR.Bits.PER1AD115
    
    #define PER1AD1_PER1AD_18           _PER01AD1.Overlap_STR.PER1AD1STR.MergedBits.grpPER1AD_18
    #define PER1AD1_PER1AD1_10          _PER01AD1.Overlap_STR.PER1AD1STR.MergedBits.grpPER1AD1_10
    #define PER1AD1_PER1AD              PER1AD1_PER1AD_18
    
    #define PER1AD1_PER1AD18_MASK       1
    #define PER1AD1_PER1AD19_MASK       2
    #define PER1AD1_PER1AD110_MASK      4
    #define PER1AD1_PER1AD111_MASK      8
    #define PER1AD1_PER1AD112_MASK      16
    #define PER1AD1_PER1AD113_MASK      32
    #define PER1AD1_PER1AD114_MASK      64
    #define PER1AD1_PER1AD115_MASK      128
    #define PER1AD1_PER1AD_18_MASK      3
    #define PER1AD1_PER1AD_18_BITNUM    0
    #define PER1AD1_PER1AD1_10_MASK     252
    #define PER1AD1_PER1AD1_10_BITNUM   2

  } Overlap_STR;

  struct {
    word PER1AD18    1;                                        Port AD1 Pull Up Enable Bit 8 
    word PER1AD19    1;                                        Port AD1 Pull Up Enable Bit 9 
    word PER1AD110   1;                                        Port AD1 Pull Up Enable Bit 10 
    word PER1AD111   1;                                        Port AD1 Pull Up Enable Bit 11 
    word PER1AD112   1;                                        Port AD1 Pull Up Enable Bit 12 
    word PER1AD113   1;                                        Port AD1 Pull Up Enable Bit 13 
    word PER1AD114   1;                                        Port AD1 Pull Up Enable Bit 14 
    word PER1AD115   1;                                        Port AD1 Pull Up Enable Bit 15 
    word PER0AD116   1;                                        Port AD1 Pull Up Enable Bit 16 
    word PER0AD117   1;                                        Port AD1 Pull Up Enable Bit 17 
    word PER0AD118   1;                                        Port AD1 Pull Up Enable Bit 18 
    word PER0AD119   1;                                        Port AD1 Pull Up Enable Bit 19 
    word PER0AD120   1;                                        Port AD1 Pull Up Enable Bit 20 
    word PER0AD121   1;                                        Port AD1 Pull Up Enable Bit 21 
    word PER0AD122   1;                                        Port AD1 Pull Up Enable Bit 22 
    word PER0AD123   1;                                        Port AD1 Pull Up Enable Bit 23 
  } Bits;
  struct {
    word grpPER1AD_18 2;
    word grpPER1AD1_10 6;
    word grpPER0AD1_16 8;
  } MergedBits;
} PER01AD1STR;
extern volatile PER01AD1STR _PER01AD1 @(REG_BASE + 0x0000027E);
#define PER01AD1                        _PER01AD1.Word
#define PER01AD1_PER1AD18               _PER01AD1.Bits.PER1AD18
#define PER01AD1_PER1AD19               _PER01AD1.Bits.PER1AD19
#define PER01AD1_PER1AD110              _PER01AD1.Bits.PER1AD110
#define PER01AD1_PER1AD111              _PER01AD1.Bits.PER1AD111
#define PER01AD1_PER1AD112              _PER01AD1.Bits.PER1AD112
#define PER01AD1_PER1AD113              _PER01AD1.Bits.PER1AD113
#define PER01AD1_PER1AD114              _PER01AD1.Bits.PER1AD114
#define PER01AD1_PER1AD115              _PER01AD1.Bits.PER1AD115
#define PER01AD1_PER0AD116              _PER01AD1.Bits.PER0AD116
#define PER01AD1_PER0AD117              _PER01AD1.Bits.PER0AD117
#define PER01AD1_PER0AD118              _PER01AD1.Bits.PER0AD118
#define PER01AD1_PER0AD119              _PER01AD1.Bits.PER0AD119
#define PER01AD1_PER0AD120              _PER01AD1.Bits.PER0AD120
#define PER01AD1_PER0AD121              _PER01AD1.Bits.PER0AD121
#define PER01AD1_PER0AD122              _PER01AD1.Bits.PER0AD122
#define PER01AD1_PER0AD123              _PER01AD1.Bits.PER0AD123
#define PER01AD1_PER1AD_18              _PER01AD1.MergedBits.grpPER1AD_18
#define PER01AD1_PER1AD1_10             _PER01AD1.MergedBits.grpPER1AD1_10
#define PER01AD1_PER0AD1_16             _PER01AD1.MergedBits.grpPER0AD1_16
#define PER01AD1_PER1AD                 PER01AD1_PER1AD_18
#define PER01AD1_PER1AD1                PER01AD1_PER1AD1_10
#define PER01AD1_PER0AD1                PER01AD1_PER0AD1_16

#define PER01AD1_PER1AD18_MASK          1
#define PER01AD1_PER1AD19_MASK          2
#define PER01AD1_PER1AD110_MASK         4
#define PER01AD1_PER1AD111_MASK         8
#define PER01AD1_PER1AD112_MASK         16
#define PER01AD1_PER1AD113_MASK         32
#define PER01AD1_PER1AD114_MASK         64
#define PER01AD1_PER1AD115_MASK         128
#define PER01AD1_PER0AD116_MASK         256
#define PER01AD1_PER0AD117_MASK         512
#define PER01AD1_PER0AD118_MASK         1024
#define PER01AD1_PER0AD119_MASK         2048
#define PER01AD1_PER0AD120_MASK         4096
#define PER01AD1_PER0AD121_MASK         8192
#define PER01AD1_PER0AD122_MASK         16384
#define PER01AD1_PER0AD123_MASK         32768
#define PER01AD1_PER1AD_18_MASK         3
#define PER01AD1_PER1AD_18_BITNUM       0
#define PER01AD1_PER1AD1_10_MASK        252
#define PER01AD1_PER1AD1_10_BITNUM      2
#define PER01AD1_PER0AD1_16_MASK        65280
#define PER01AD1_PER0AD1_16_BITNUM      8


 ATD0CTL01 - ATD 0 Control Register 01; 0x000002C0 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0CTL0 - ATD 0 Control Register 0; 0x000002C0 
    union {
      byte Byte;
      struct {
        byte WRAP0       1;                                        Wrap Around Channel Select Bit 0 
        byte WRAP1       1;                                        Wrap Around Channel Select Bit 1 
        byte WRAP2       1;                                        Wrap Around Channel Select Bit 2 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
      } Bits;
      struct {
        byte grpWRAP 3;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } ATD0CTL0STR;
    #define ATD0CTL0                    _ATD0CTL01.Overlap_STR.ATD0CTL0STR.Byte
    #define ATD0CTL0_WRAP0              _ATD0CTL01.Overlap_STR.ATD0CTL0STR.Bits.WRAP0
    #define ATD0CTL0_WRAP1              _ATD0CTL01.Overlap_STR.ATD0CTL0STR.Bits.WRAP1
    #define ATD0CTL0_WRAP2              _ATD0CTL01.Overlap_STR.ATD0CTL0STR.Bits.WRAP2
    
     ATD0CTL_ARR Access 6 ATD0CTLx registers in an array 
    #define ATD0CTL_ARR                 ((volatile byte ) &ATD0CTL0)
    #define ATD0CTL0_WRAP               _ATD0CTL01.Overlap_STR.ATD0CTL0STR.MergedBits.grpWRAP
    
    #define ATD0CTL0_WRAP0_MASK         1
    #define ATD0CTL0_WRAP1_MASK         2
    #define ATD0CTL0_WRAP2_MASK         4
    #define ATD0CTL0_WRAP_MASK          7
    #define ATD0CTL0_WRAP_BITNUM        0


     ATD0CTL1 - ATD0 Control Register 1; 0x000002C1 
    union {
      byte Byte;
      struct {
        byte ETRIGCH0    1;                                        External Trigger Channel Select Bit 0 
        byte ETRIGCH1    1;                                        External Trigger Channel Select Bit 1 
        byte ETRIGCH2    1;                                        External Trigger Channel Select Bit 2 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte ETRIGSEL    1;                                        External Trigger Source Select 
      } Bits;
      struct {
        byte grpETRIGCH 3;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } ATD0CTL1STR;
    #define ATD0CTL1                    _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Byte
    #define ATD0CTL1_ETRIGCH0           _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.ETRIGCH0
    #define ATD0CTL1_ETRIGCH1           _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.ETRIGCH1
    #define ATD0CTL1_ETRIGCH2           _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.ETRIGCH2
    #define ATD0CTL1_ETRIGSEL           _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.ETRIGSEL
    
    #define ATD0CTL1_ETRIGCH            _ATD0CTL01.Overlap_STR.ATD0CTL1STR.MergedBits.grpETRIGCH
    
    #define ATD0CTL1_ETRIGCH0_MASK      1
    #define ATD0CTL1_ETRIGCH1_MASK      2
    #define ATD0CTL1_ETRIGCH2_MASK      4
    #define ATD0CTL1_ETRIGSEL_MASK      128
    #define ATD0CTL1_ETRIGCH_MASK       7
    #define ATD0CTL1_ETRIGCH_BITNUM     0

  } Overlap_STR;

  struct {
    word ETRIGCH0    1;                                        External Trigger Channel Select Bit 0 
    word ETRIGCH1    1;                                        External Trigger Channel Select Bit 1 
    word ETRIGCH2    1;                                        External Trigger Channel Select Bit 2 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word ETRIGSEL    1;                                        External Trigger Source Select 
    word WRAP0       1;                                        Wrap Around Channel Select Bit 0 
    word WRAP1       1;                                        Wrap Around Channel Select Bit 1 
    word WRAP2       1;                                        Wrap Around Channel Select Bit 2 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
  } Bits;
  struct {
    word grpETRIGCH 3;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpWRAP 3;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} ATD0CTL01STR;
extern volatile ATD0CTL01STR _ATD0CTL01 @(REG_BASE + 0x000002C0);
#define ATD0CTL01                       _ATD0CTL01.Word
#define ATD0CTL01_ETRIGCH0              _ATD0CTL01.Bits.ETRIGCH0
#define ATD0CTL01_ETRIGCH1              _ATD0CTL01.Bits.ETRIGCH1
#define ATD0CTL01_ETRIGCH2              _ATD0CTL01.Bits.ETRIGCH2
#define ATD0CTL01_ETRIGSEL              _ATD0CTL01.Bits.ETRIGSEL
#define ATD0CTL01_WRAP0                 _ATD0CTL01.Bits.WRAP0
#define ATD0CTL01_WRAP1                 _ATD0CTL01.Bits.WRAP1
#define ATD0CTL01_WRAP2                 _ATD0CTL01.Bits.WRAP2
#define ATD0CTL01_ETRIGCH               _ATD0CTL01.MergedBits.grpETRIGCH
#define ATD0CTL01_WRAP                  _ATD0CTL01.MergedBits.grpWRAP

#define ATD0CTL01_ETRIGCH0_MASK         1
#define ATD0CTL01_ETRIGCH1_MASK         2
#define ATD0CTL01_ETRIGCH2_MASK         4
#define ATD0CTL01_ETRIGSEL_MASK         128
#define ATD0CTL01_WRAP0_MASK            256
#define ATD0CTL01_WRAP1_MASK            512
#define ATD0CTL01_WRAP2_MASK            1024
#define ATD0CTL01_ETRIGCH_MASK          7
#define ATD0CTL01_ETRIGCH_BITNUM        0
#define ATD0CTL01_WRAP_MASK             1792
#define ATD0CTL01_WRAP_BITNUM           8


 ATD0CTL23 - ATD 0 Control Register 23; 0x000002C2 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0CTL2 - ATD 0 Control Register 2; 0x000002C2 
    union {
      byte Byte;
      struct {
        byte ASCIF       1;                                        ATD 0 Sequence Complete Interrupt Flag 
        byte ASCIE       1;                                        ATD 0 Sequence Complete Interrupt Enable 
        byte ETRIGE      1;                                        External Trigger Mode enable 
        byte ETRIGP      1;                                        External Trigger Polarity 
        byte ETRIGLE     1;                                        External Trigger LevelEdge control 
        byte AWAI        1;                                        ATD Power Down in Wait Mode 
        byte AFFC        1;                                        ATD Fast Conversion Complete Flag Clear 
        byte ADPU        1;                                        ATD Disable  Power Down 
      } Bits;
    } ATD0CTL2STR;
    #define ATD0CTL2                    _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Byte
    #define ATD0CTL2_ASCIF              _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ASCIF
    #define ATD0CTL2_ASCIE              _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ASCIE
    #define ATD0CTL2_ETRIGE             _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ETRIGE
    #define ATD0CTL2_ETRIGP             _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ETRIGP
    #define ATD0CTL2_ETRIGLE            _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ETRIGLE
    #define ATD0CTL2_AWAI               _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.AWAI
    #define ATD0CTL2_AFFC               _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.AFFC
    #define ATD0CTL2_ADPU               _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ADPU
    
    
    #define ATD0CTL2_ASCIF_MASK         1
    #define ATD0CTL2_ASCIE_MASK         2
    #define ATD0CTL2_ETRIGE_MASK        4
    #define ATD0CTL2_ETRIGP_MASK        8
    #define ATD0CTL2_ETRIGLE_MASK       16
    #define ATD0CTL2_AWAI_MASK          32
    #define ATD0CTL2_AFFC_MASK          64
    #define ATD0CTL2_ADPU_MASK          128


     ATD0CTL3 - ATD 0 Control Register 3; 0x000002C3 
    union {
      byte Byte;
      struct {
        byte FRZ0        1;                                        Background Debug Freeze Enable Bit 0 
        byte FRZ1        1;                                        Background Debug Freeze Enable Bit 1 
        byte FIFO        1;                                        Result Register FIFO Mode 
        byte S1C         1;                                        Conversion Sequence Length 1 
        byte S2C         1;                                        Conversion Sequence Length 2 
        byte S4C         1;                                        Conversion Sequence Length 4 
        byte S8C         1;                                        Conversion Sequence Length 8 
        byte             1; 
      } Bits;
      struct {
        byte grpFRZ 2;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } ATD0CTL3STR;
    #define ATD0CTL3                    _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Byte
    #define ATD0CTL3_FRZ0               _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.FRZ0
    #define ATD0CTL3_FRZ1               _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.FRZ1
    #define ATD0CTL3_FIFO               _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.FIFO
    #define ATD0CTL3_S1C                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S1C
    #define ATD0CTL3_S2C                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S2C
    #define ATD0CTL3_S4C                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S4C
    #define ATD0CTL3_S8C                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S8C
    
    #define ATD0CTL3_FRZ                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.MergedBits.grpFRZ
    
    #define ATD0CTL3_FRZ0_MASK          1
    #define ATD0CTL3_FRZ1_MASK          2
    #define ATD0CTL3_FIFO_MASK          4
    #define ATD0CTL3_S1C_MASK           8
    #define ATD0CTL3_S2C_MASK           16
    #define ATD0CTL3_S4C_MASK           32
    #define ATD0CTL3_S8C_MASK           64
    #define ATD0CTL3_FRZ_MASK           3
    #define ATD0CTL3_FRZ_BITNUM         0

  } Overlap_STR;

  struct {
    word FRZ0        1;                                        Background Debug Freeze Enable Bit 0 
    word FRZ1        1;                                        Background Debug Freeze Enable Bit 1 
    word FIFO        1;                                        Result Register FIFO Mode 
    word S1C         1;                                        Conversion Sequence Length 1 
    word S2C         1;                                        Conversion Sequence Length 2 
    word S4C         1;                                        Conversion Sequence Length 4 
    word S8C         1;                                        Conversion Sequence Length 8 
    word             1; 
    word ASCIF       1;                                        ATD 0 Sequence Complete Interrupt Flag 
    word ASCIE       1;                                        ATD 0 Sequence Complete Interrupt Enable 
    word ETRIGE      1;                                        External Trigger Mode enable 
    word ETRIGP      1;                                        External Trigger Polarity 
    word ETRIGLE     1;                                        External Trigger LevelEdge control 
    word AWAI        1;                                        ATD Power Down in Wait Mode 
    word AFFC        1;                                        ATD Fast Conversion Complete Flag Clear 
    word ADPU        1;                                        ATD Disable  Power Down 
  } Bits;
  struct {
    word grpFRZ  2;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} ATD0CTL23STR;
extern volatile ATD0CTL23STR _ATD0CTL23 @(REG_BASE + 0x000002C2);
#define ATD0CTL23                       _ATD0CTL23.Word
#define ATD0CTL23_FRZ0                  _ATD0CTL23.Bits.FRZ0
#define ATD0CTL23_FRZ1                  _ATD0CTL23.Bits.FRZ1
#define ATD0CTL23_FIFO                  _ATD0CTL23.Bits.FIFO
#define ATD0CTL23_S1C                   _ATD0CTL23.Bits.S1C
#define ATD0CTL23_S2C                   _ATD0CTL23.Bits.S2C
#define ATD0CTL23_S4C                   _ATD0CTL23.Bits.S4C
#define ATD0CTL23_S8C                   _ATD0CTL23.Bits.S8C
#define ATD0CTL23_ASCIF                 _ATD0CTL23.Bits.ASCIF
#define ATD0CTL23_ASCIE                 _ATD0CTL23.Bits.ASCIE
#define ATD0CTL23_ETRIGE                _ATD0CTL23.Bits.ETRIGE
#define ATD0CTL23_ETRIGP                _ATD0CTL23.Bits.ETRIGP
#define ATD0CTL23_ETRIGLE               _ATD0CTL23.Bits.ETRIGLE
#define ATD0CTL23_AWAI                  _ATD0CTL23.Bits.AWAI
#define ATD0CTL23_AFFC                  _ATD0CTL23.Bits.AFFC
#define ATD0CTL23_ADPU                  _ATD0CTL23.Bits.ADPU
#define ATD0CTL23_FRZ                   _ATD0CTL23.MergedBits.grpFRZ

#define ATD0CTL23_FRZ0_MASK             1
#define ATD0CTL23_FRZ1_MASK             2
#define ATD0CTL23_FIFO_MASK             4
#define ATD0CTL23_S1C_MASK              8
#define ATD0CTL23_S2C_MASK              16
#define ATD0CTL23_S4C_MASK              32
#define ATD0CTL23_S8C_MASK              64
#define ATD0CTL23_ASCIF_MASK            256
#define ATD0CTL23_ASCIE_MASK            512
#define ATD0CTL23_ETRIGE_MASK           1024
#define ATD0CTL23_ETRIGP_MASK           2048
#define ATD0CTL23_ETRIGLE_MASK          4096
#define ATD0CTL23_AWAI_MASK             8192
#define ATD0CTL23_AFFC_MASK             16384
#define ATD0CTL23_ADPU_MASK             32768
#define ATD0CTL23_FRZ_MASK              3
#define ATD0CTL23_FRZ_BITNUM            0


 ATD0CTL45 - ATD 0 Control Register 45; 0x000002C4 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0CTL4 - ATD 0 Control Register 4; 0x000002C4 
    union {
      byte Byte;
      struct {
        byte PRS0        1;                                        ATD Clock Prescaler 0 
        byte PRS1        1;                                        ATD Clock Prescaler 1 
        byte PRS2        1;                                        ATD Clock Prescaler 2 
        byte PRS3        1;                                        ATD Clock Prescaler 3 
        byte PRS4        1;                                        ATD Clock Prescaler 4 
        byte SMP0        1;                                        Sample Time Select 0 
        byte SMP1        1;                                        Sample Time Select 1 
        byte SRES8       1;                                        ATD Resolution Select 
      } Bits;
      struct {
        byte grpPRS 5;
        byte grpSMP 2;
        byte grpSRES_8 1;
      } MergedBits;
    } ATD0CTL4STR;
    #define ATD0CTL4                    _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Byte
    #define ATD0CTL4_PRS0               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS0
    #define ATD0CTL4_PRS1               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS1
    #define ATD0CTL4_PRS2               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS2
    #define ATD0CTL4_PRS3               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS3
    #define ATD0CTL4_PRS4               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS4
    #define ATD0CTL4_SMP0               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.SMP0
    #define ATD0CTL4_SMP1               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.SMP1
    #define ATD0CTL4_SRES8              _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.SRES8
    
    #define ATD0CTL4_PRS                _ATD0CTL45.Overlap_STR.ATD0CTL4STR.MergedBits.grpPRS
    #define ATD0CTL4_SMP                _ATD0CTL45.Overlap_STR.ATD0CTL4STR.MergedBits.grpSMP
    
    #define ATD0CTL4_PRS0_MASK          1
    #define ATD0CTL4_PRS1_MASK          2
    #define ATD0CTL4_PRS2_MASK          4
    #define ATD0CTL4_PRS3_MASK          8
    #define ATD0CTL4_PRS4_MASK          16
    #define ATD0CTL4_SMP0_MASK          32
    #define ATD0CTL4_SMP1_MASK          64
    #define ATD0CTL4_SRES8_MASK         128
    #define ATD0CTL4_PRS_MASK           31
    #define ATD0CTL4_PRS_BITNUM         0
    #define ATD0CTL4_SMP_MASK           96
    #define ATD0CTL4_SMP_BITNUM         5


     ATD0CTL5 - ATD 0 Control Register 5; 0x000002C5 
    union {
      byte Byte;
      struct {
        byte CA          1;                                        Analog Input Channel Select Code A 
        byte CB          1;                                        Analog Input Channel Select Code B 
        byte CC          1;                                        Analog Input Channel Select Code C 
        byte             1; 
        byte MULT        1;                                        Multi-Channel Sample Mode 
        byte SCAN        1;                                        Continuous Conversion Sequence Mode 
        byte DSGN        1;                                        SignedUnsigned Result Data Mode 
        byte DJM         1;                                        Result Register Data Justification Mode 
      } Bits;
      struct {
        byte grpCx 3;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } ATD0CTL5STR;
    #define ATD0CTL5                    _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Byte
    #define ATD0CTL5_CA                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CA
    #define ATD0CTL5_CB                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CB
    #define ATD0CTL5_CC                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CC
    #define ATD0CTL5_MULT               _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.MULT
    #define ATD0CTL5_SCAN               _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.SCAN
    #define ATD0CTL5_DSGN               _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.DSGN
    #define ATD0CTL5_DJM                _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.DJM
    
    #define ATD0CTL5_Cx                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.MergedBits.grpCx
    
    #define ATD0CTL5_CA_MASK            1
    #define ATD0CTL5_CB_MASK            2
    #define ATD0CTL5_CC_MASK            4
    #define ATD0CTL5_MULT_MASK          16
    #define ATD0CTL5_SCAN_MASK          32
    #define ATD0CTL5_DSGN_MASK          64
    #define ATD0CTL5_DJM_MASK           128
    #define ATD0CTL5_Cx_MASK            7
    #define ATD0CTL5_Cx_BITNUM          0

  } Overlap_STR;

  struct {
    word CA          1;                                        Analog Input Channel Select Code A 
    word CB          1;                                        Analog Input Channel Select Code B 
    word CC          1;                                        Analog Input Channel Select Code C 
    word             1; 
    word MULT        1;                                        Multi-Channel Sample Mode 
    word SCAN        1;                                        Continuous Conversion Sequence Mode 
    word DSGN        1;                                        SignedUnsigned Result Data Mode 
    word DJM         1;                                        Result Register Data Justification Mode 
    word PRS0        1;                                        ATD Clock Prescaler 0 
    word PRS1        1;                                        ATD Clock Prescaler 1 
    word PRS2        1;                                        ATD Clock Prescaler 2 
    word PRS3        1;                                        ATD Clock Prescaler 3 
    word PRS4        1;                                        ATD Clock Prescaler 4 
    word SMP0        1;                                        Sample Time Select 0 
    word SMP1        1;                                        Sample Time Select 1 
    word SRES8       1;                                        ATD Resolution Select 
  } Bits;
  struct {
    word grpCx   3;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpPRS  5;
    word grpSMP  2;
    word grpSRES_8 1;
  } MergedBits;
} ATD0CTL45STR;
extern volatile ATD0CTL45STR _ATD0CTL45 @(REG_BASE + 0x000002C4);
#define ATD0CTL45                       _ATD0CTL45.Word
#define ATD0CTL45_CA                    _ATD0CTL45.Bits.CA
#define ATD0CTL45_CB                    _ATD0CTL45.Bits.CB
#define ATD0CTL45_CC                    _ATD0CTL45.Bits.CC
#define ATD0CTL45_MULT                  _ATD0CTL45.Bits.MULT
#define ATD0CTL45_SCAN                  _ATD0CTL45.Bits.SCAN
#define ATD0CTL45_DSGN                  _ATD0CTL45.Bits.DSGN
#define ATD0CTL45_DJM                   _ATD0CTL45.Bits.DJM
#define ATD0CTL45_PRS0                  _ATD0CTL45.Bits.PRS0
#define ATD0CTL45_PRS1                  _ATD0CTL45.Bits.PRS1
#define ATD0CTL45_PRS2                  _ATD0CTL45.Bits.PRS2
#define ATD0CTL45_PRS3                  _ATD0CTL45.Bits.PRS3
#define ATD0CTL45_PRS4                  _ATD0CTL45.Bits.PRS4
#define ATD0CTL45_SMP0                  _ATD0CTL45.Bits.SMP0
#define ATD0CTL45_SMP1                  _ATD0CTL45.Bits.SMP1
#define ATD0CTL45_SRES8                 _ATD0CTL45.Bits.SRES8
#define ATD0CTL45_Cx                    _ATD0CTL45.MergedBits.grpCx
#define ATD0CTL45_PRS                   _ATD0CTL45.MergedBits.grpPRS
#define ATD0CTL45_SMP                   _ATD0CTL45.MergedBits.grpSMP

#define ATD0CTL45_CA_MASK               1
#define ATD0CTL45_CB_MASK               2
#define ATD0CTL45_CC_MASK               4
#define ATD0CTL45_MULT_MASK             16
#define ATD0CTL45_SCAN_MASK             32
#define ATD0CTL45_DSGN_MASK             64
#define ATD0CTL45_DJM_MASK              128
#define ATD0CTL45_PRS0_MASK             256
#define ATD0CTL45_PRS1_MASK             512
#define ATD0CTL45_PRS2_MASK             1024
#define ATD0CTL45_PRS3_MASK             2048
#define ATD0CTL45_PRS4_MASK             4096
#define ATD0CTL45_SMP0_MASK             8192
#define ATD0CTL45_SMP1_MASK             16384
#define ATD0CTL45_SRES8_MASK            32768
#define ATD0CTL45_Cx_MASK               7
#define ATD0CTL45_Cx_BITNUM             0
#define ATD0CTL45_PRS_MASK              7936
#define ATD0CTL45_PRS_BITNUM            8
#define ATD0CTL45_SMP_MASK              24576
#define ATD0CTL45_SMP_BITNUM            13


 ATD0STAT0 - ATD 0 Status Register 0; 0x000002C6 
typedef union {
  byte Byte;
  struct {
    byte CC0         1;                                        Conversion Counter 0 
    byte CC1         1;                                        Conversion Counter 1 
    byte CC2         1;                                        Conversion Counter 2 
    byte             1; 
    byte FIFOR       1;                                        FIFO Over Run Flag 
    byte ETORF       1;                                        External Trigger Overrun Flag 
    byte             1; 
    byte SCF         1;                                        Sequence Complete Flag 
  } Bits;
  struct {
    byte grpCC   3;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} ATD0STAT0STR;
extern volatile ATD0STAT0STR _ATD0STAT0 @(REG_BASE + 0x000002C6);
#define ATD0STAT0                       _ATD0STAT0.Byte
#define ATD0STAT0_CC0                   _ATD0STAT0.Bits.CC0
#define ATD0STAT0_CC1                   _ATD0STAT0.Bits.CC1
#define ATD0STAT0_CC2                   _ATD0STAT0.Bits.CC2
#define ATD0STAT0_FIFOR                 _ATD0STAT0.Bits.FIFOR
#define ATD0STAT0_ETORF                 _ATD0STAT0.Bits.ETORF
#define ATD0STAT0_SCF                   _ATD0STAT0.Bits.SCF
#define ATD0STAT0_CC                    _ATD0STAT0.MergedBits.grpCC

#define ATD0STAT0_CC0_MASK              1
#define ATD0STAT0_CC1_MASK              2
#define ATD0STAT0_CC2_MASK              4
#define ATD0STAT0_FIFOR_MASK            16
#define ATD0STAT0_ETORF_MASK            32
#define ATD0STAT0_SCF_MASK              128
#define ATD0STAT0_CC_MASK               7
#define ATD0STAT0_CC_BITNUM             0


 ATD0TEST1 - ATD0 Test Register; 0x000002C9 
typedef union {
  byte Byte;
  struct {
    byte SC          1;                                        Special Channel Conversion Bit 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} ATD0TEST1STR;
extern volatile ATD0TEST1STR _ATD0TEST1 @(REG_BASE + 0x000002C9);
#define ATD0TEST1                       _ATD0TEST1.Byte
#define ATD0TEST1_SC                    _ATD0TEST1.Bits.SC

#define ATD0TEST1_SC_MASK               1


 ATD0STAT1 - ATD 0 Status Register 1; 0x000002CB 
typedef union {
  byte Byte;
  struct {
    byte CCF0        1;                                        Conversion Complete Flag 0 
    byte CCF1        1;                                        Conversion Complete Flag 1 
    byte CCF2        1;                                        Conversion Complete Flag 2 
    byte CCF3        1;                                        Conversion Complete Flag 3 
    byte CCF4        1;                                        Conversion Complete Flag 4 
    byte CCF5        1;                                        Conversion Complete Flag 5 
    byte CCF6        1;                                        Conversion Complete Flag 6 
    byte CCF7        1;                                        Conversion Complete Flag 7 
  } Bits;
} ATD0STAT1STR;
extern volatile ATD0STAT1STR _ATD0STAT1 @(REG_BASE + 0x000002CB);
#define ATD0STAT1                       _ATD0STAT1.Byte
#define ATD0STAT1_CCF0                  _ATD0STAT1.Bits.CCF0
#define ATD0STAT1_CCF1                  _ATD0STAT1.Bits.CCF1
#define ATD0STAT1_CCF2                  _ATD0STAT1.Bits.CCF2
#define ATD0STAT1_CCF3                  _ATD0STAT1.Bits.CCF3
#define ATD0STAT1_CCF4                  _ATD0STAT1.Bits.CCF4
#define ATD0STAT1_CCF5                  _ATD0STAT1.Bits.CCF5
#define ATD0STAT1_CCF6                  _ATD0STAT1.Bits.CCF6
#define ATD0STAT1_CCF7                  _ATD0STAT1.Bits.CCF7

#define ATD0STAT1_CCF0_MASK             1
#define ATD0STAT1_CCF1_MASK             2
#define ATD0STAT1_CCF2_MASK             4
#define ATD0STAT1_CCF3_MASK             8
#define ATD0STAT1_CCF4_MASK             16
#define ATD0STAT1_CCF5_MASK             32
#define ATD0STAT1_CCF6_MASK             64
#define ATD0STAT1_CCF7_MASK             128


 ATD0DIEN - ATD 0 Input Enable Register; 0x000002CD 
typedef union {
  byte Byte;
  struct {
    byte IEN0        1;                                        ATD Digital Input Enable on channel 0 
    byte IEN1        1;                                        ATD Digital Input Enable on channel 1 
    byte IEN2        1;                                        ATD Digital Input Enable on channel 2 
    byte IEN3        1;                                        ATD Digital Input Enable on channel 3 
    byte IEN4        1;                                        ATD Digital Input Enable on channel 4 
    byte IEN5        1;                                        ATD Digital Input Enable on channel 5 
    byte IEN6        1;                                        ATD Digital Input Enable on channel 6 
    byte IEN7        1;                                        ATD Digital Input Enable on channel 7 
  } Bits;
} ATD0DIENSTR;
extern volatile ATD0DIENSTR _ATD0DIEN @(REG_BASE + 0x000002CD);
#define ATD0DIEN                        _ATD0DIEN.Byte
#define ATD0DIEN_IEN0                   _ATD0DIEN.Bits.IEN0
#define ATD0DIEN_IEN1                   _ATD0DIEN.Bits.IEN1
#define ATD0DIEN_IEN2                   _ATD0DIEN.Bits.IEN2
#define ATD0DIEN_IEN3                   _ATD0DIEN.Bits.IEN3
#define ATD0DIEN_IEN4                   _ATD0DIEN.Bits.IEN4
#define ATD0DIEN_IEN5                   _ATD0DIEN.Bits.IEN5
#define ATD0DIEN_IEN6                   _ATD0DIEN.Bits.IEN6
#define ATD0DIEN_IEN7                   _ATD0DIEN.Bits.IEN7

#define ATD0DIEN_IEN0_MASK              1
#define ATD0DIEN_IEN1_MASK              2
#define ATD0DIEN_IEN2_MASK              4
#define ATD0DIEN_IEN3_MASK              8
#define ATD0DIEN_IEN4_MASK              16
#define ATD0DIEN_IEN5_MASK              32
#define ATD0DIEN_IEN6_MASK              64
#define ATD0DIEN_IEN7_MASK              128


 ATD0PTAD0 - ATD 0 Port AD0 Register; 0x000002CF 
typedef union {
  byte Byte;
  struct {
    byte PTAD0       1;                                        AD Channel 0 (AN0) Digital Input 
    byte PTAD1       1;                                        AD Channel 1 (AN1) Digital Input 
    byte PTAD2       1;                                        AD Channel 2 (AN2) Digital Input 
    byte PTAD3       1;                                        AD Channel 3 (AN3) Digital Input 
    byte PTAD4       1;                                        AD Channel 4 (AN4) Digital Input 
    byte PTAD5       1;                                        AD Channel 5 (AN5) Digital Input 
    byte PTAD6       1;                                        AD Channel 6 (AN6) Digital Input 
    byte PTAD7       1;                                        AD Channel 7 (AN7) Digital Input 
  } Bits;
} ATD0PTAD0STR;
extern volatile ATD0PTAD0STR _ATD0PTAD0 @(REG_BASE + 0x000002CF);
#define ATD0PTAD0                       _ATD0PTAD0.Byte
#define ATD0PTAD0_PTAD0                 _ATD0PTAD0.Bits.PTAD0
#define ATD0PTAD0_PTAD1                 _ATD0PTAD0.Bits.PTAD1
#define ATD0PTAD0_PTAD2                 _ATD0PTAD0.Bits.PTAD2
#define ATD0PTAD0_PTAD3                 _ATD0PTAD0.Bits.PTAD3
#define ATD0PTAD0_PTAD4                 _ATD0PTAD0.Bits.PTAD4
#define ATD0PTAD0_PTAD5                 _ATD0PTAD0.Bits.PTAD5
#define ATD0PTAD0_PTAD6                 _ATD0PTAD0.Bits.PTAD6
#define ATD0PTAD0_PTAD7                 _ATD0PTAD0.Bits.PTAD7

#define ATD0PTAD0_PTAD0_MASK            1
#define ATD0PTAD0_PTAD1_MASK            2
#define ATD0PTAD0_PTAD2_MASK            4
#define ATD0PTAD0_PTAD3_MASK            8
#define ATD0PTAD0_PTAD4_MASK            16
#define ATD0PTAD0_PTAD5_MASK            32
#define ATD0PTAD0_PTAD6_MASK            64
#define ATD0PTAD0_PTAD7_MASK            128


 ATD0DR0 - ATD 0 Conversion Result Register 0; 0x000002D0 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0DR0H - ATD 0 Conversion Result Register 0 High; 0x000002D0 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD0DR0HSTR;
    #define ATD0DR0H                    _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Byte
    #define ATD0DR0H_BIT8               _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT8
    #define ATD0DR0H_BIT9               _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT9
    #define ATD0DR0H_BIT10              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT10
    #define ATD0DR0H_BIT11              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT11
    #define ATD0DR0H_BIT12              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT12
    #define ATD0DR0H_BIT13              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT13
    #define ATD0DR0H_BIT14              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT14
    #define ATD0DR0H_BIT15              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT15
    
    
    #define ATD0DR0H_BIT8_MASK          1
    #define ATD0DR0H_BIT9_MASK          2
    #define ATD0DR0H_BIT10_MASK         4
    #define ATD0DR0H_BIT11_MASK         8
    #define ATD0DR0H_BIT12_MASK         16
    #define ATD0DR0H_BIT13_MASK         32
    #define ATD0DR0H_BIT14_MASK         64
    #define ATD0DR0H_BIT15_MASK         128


     ATD0DR0L - ATD 0 Conversion Result Register 0 Low; 0x000002D1 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD0DR0LSTR;
    #define ATD0DR0L                    _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Byte
    #define ATD0DR0L_BIT6               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT6
    #define ATD0DR0L_BIT7               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT7
    
    #define ATD0DR0L_BIT_6              _ATD0DR0.Overlap_STR.ATD0DR0LSTR.MergedBits.grpBIT_6
    #define ATD0DR0L_BIT                ATD0DR0L_BIT_6
    
    #define ATD0DR0L_BIT6_MASK          64
    #define ATD0DR0L_BIT7_MASK          128
    #define ATD0DR0L_BIT_6_MASK         192
    #define ATD0DR0L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD0DR0STR;
extern volatile ATD0DR0STR _ATD0DR0 @(REG_BASE + 0x000002D0);
#define ATD0DR0                         _ATD0DR0.Word
#define ATD0DR0_BIT6                    _ATD0DR0.Bits.BIT6
#define ATD0DR0_BIT7                    _ATD0DR0.Bits.BIT7
#define ATD0DR0_BIT8                    _ATD0DR0.Bits.BIT8
#define ATD0DR0_BIT9                    _ATD0DR0.Bits.BIT9
#define ATD0DR0_BIT10                   _ATD0DR0.Bits.BIT10
#define ATD0DR0_BIT11                   _ATD0DR0.Bits.BIT11
#define ATD0DR0_BIT12                   _ATD0DR0.Bits.BIT12
#define ATD0DR0_BIT13                   _ATD0DR0.Bits.BIT13
#define ATD0DR0_BIT14                   _ATD0DR0.Bits.BIT14
#define ATD0DR0_BIT15                   _ATD0DR0.Bits.BIT15
 ATD0DR_ARR Access 8 ATD0DRx registers in an array 
#define ATD0DR_ARR                      ((volatile word ) &ATD0DR0)
#define ATD0DR0_BIT_6                   _ATD0DR0.MergedBits.grpBIT_6
#define ATD0DR0_BIT                     ATD0DR0_BIT_6

#define ATD0DR0_BIT6_MASK               64
#define ATD0DR0_BIT7_MASK               128
#define ATD0DR0_BIT8_MASK               256
#define ATD0DR0_BIT9_MASK               512
#define ATD0DR0_BIT10_MASK              1024
#define ATD0DR0_BIT11_MASK              2048
#define ATD0DR0_BIT12_MASK              4096
#define ATD0DR0_BIT13_MASK              8192
#define ATD0DR0_BIT14_MASK              16384
#define ATD0DR0_BIT15_MASK              32768
#define ATD0DR0_BIT_6_MASK              65472
#define ATD0DR0_BIT_6_BITNUM            6


 ATD0DR1 - ATD 0 Conversion Result Register 1; 0x000002D2 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0DR1H - ATD 0 Conversion Result Register 1 High; 0x000002D2 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD0DR1HSTR;
    #define ATD0DR1H                    _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Byte
    #define ATD0DR1H_BIT8               _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT8
    #define ATD0DR1H_BIT9               _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT9
    #define ATD0DR1H_BIT10              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT10
    #define ATD0DR1H_BIT11              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT11
    #define ATD0DR1H_BIT12              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT12
    #define ATD0DR1H_BIT13              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT13
    #define ATD0DR1H_BIT14              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT14
    #define ATD0DR1H_BIT15              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT15
    
    
    #define ATD0DR1H_BIT8_MASK          1
    #define ATD0DR1H_BIT9_MASK          2
    #define ATD0DR1H_BIT10_MASK         4
    #define ATD0DR1H_BIT11_MASK         8
    #define ATD0DR1H_BIT12_MASK         16
    #define ATD0DR1H_BIT13_MASK         32
    #define ATD0DR1H_BIT14_MASK         64
    #define ATD0DR1H_BIT15_MASK         128


     ATD0DR1L - ATD 0 Conversion Result Register 1 Low; 0x000002D3 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD0DR1LSTR;
    #define ATD0DR1L                    _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Byte
    #define ATD0DR1L_BIT6               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT6
    #define ATD0DR1L_BIT7               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT7
    
    #define ATD0DR1L_BIT_6              _ATD0DR1.Overlap_STR.ATD0DR1LSTR.MergedBits.grpBIT_6
    #define ATD0DR1L_BIT                ATD0DR1L_BIT_6
    
    #define ATD0DR1L_BIT6_MASK          64
    #define ATD0DR1L_BIT7_MASK          128
    #define ATD0DR1L_BIT_6_MASK         192
    #define ATD0DR1L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD0DR1STR;
extern volatile ATD0DR1STR _ATD0DR1 @(REG_BASE + 0x000002D2);
#define ATD0DR1                         _ATD0DR1.Word
#define ATD0DR1_BIT6                    _ATD0DR1.Bits.BIT6
#define ATD0DR1_BIT7                    _ATD0DR1.Bits.BIT7
#define ATD0DR1_BIT8                    _ATD0DR1.Bits.BIT8
#define ATD0DR1_BIT9                    _ATD0DR1.Bits.BIT9
#define ATD0DR1_BIT10                   _ATD0DR1.Bits.BIT10
#define ATD0DR1_BIT11                   _ATD0DR1.Bits.BIT11
#define ATD0DR1_BIT12                   _ATD0DR1.Bits.BIT12
#define ATD0DR1_BIT13                   _ATD0DR1.Bits.BIT13
#define ATD0DR1_BIT14                   _ATD0DR1.Bits.BIT14
#define ATD0DR1_BIT15                   _ATD0DR1.Bits.BIT15
#define ATD0DR1_BIT_6                   _ATD0DR1.MergedBits.grpBIT_6
#define ATD0DR1_BIT                     ATD0DR1_BIT_6

#define ATD0DR1_BIT6_MASK               64
#define ATD0DR1_BIT7_MASK               128
#define ATD0DR1_BIT8_MASK               256
#define ATD0DR1_BIT9_MASK               512
#define ATD0DR1_BIT10_MASK              1024
#define ATD0DR1_BIT11_MASK              2048
#define ATD0DR1_BIT12_MASK              4096
#define ATD0DR1_BIT13_MASK              8192
#define ATD0DR1_BIT14_MASK              16384
#define ATD0DR1_BIT15_MASK              32768
#define ATD0DR1_BIT_6_MASK              65472
#define ATD0DR1_BIT_6_BITNUM            6


 ATD0DR2 - ATD 0 Conversion Result Register 2; 0x000002D4 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0DR2H - ATD 0 Conversion Result Register 2 High; 0x000002D4 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD0DR2HSTR;
    #define ATD0DR2H                    _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Byte
    #define ATD0DR2H_BIT8               _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT8
    #define ATD0DR2H_BIT9               _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT9
    #define ATD0DR2H_BIT10              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT10
    #define ATD0DR2H_BIT11              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT11
    #define ATD0DR2H_BIT12              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT12
    #define ATD0DR2H_BIT13              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT13
    #define ATD0DR2H_BIT14              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT14
    #define ATD0DR2H_BIT15              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT15
    
    
    #define ATD0DR2H_BIT8_MASK          1
    #define ATD0DR2H_BIT9_MASK          2
    #define ATD0DR2H_BIT10_MASK         4
    #define ATD0DR2H_BIT11_MASK         8
    #define ATD0DR2H_BIT12_MASK         16
    #define ATD0DR2H_BIT13_MASK         32
    #define ATD0DR2H_BIT14_MASK         64
    #define ATD0DR2H_BIT15_MASK         128


     ATD0DR2L - ATD 0 Conversion Result Register 2 Low; 0x000002D5 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD0DR2LSTR;
    #define ATD0DR2L                    _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Byte
    #define ATD0DR2L_BIT6               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT6
    #define ATD0DR2L_BIT7               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT7
    
    #define ATD0DR2L_BIT_6              _ATD0DR2.Overlap_STR.ATD0DR2LSTR.MergedBits.grpBIT_6
    #define ATD0DR2L_BIT                ATD0DR2L_BIT_6
    
    #define ATD0DR2L_BIT6_MASK          64
    #define ATD0DR2L_BIT7_MASK          128
    #define ATD0DR2L_BIT_6_MASK         192
    #define ATD0DR2L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD0DR2STR;
extern volatile ATD0DR2STR _ATD0DR2 @(REG_BASE + 0x000002D4);
#define ATD0DR2                         _ATD0DR2.Word
#define ATD0DR2_BIT6                    _ATD0DR2.Bits.BIT6
#define ATD0DR2_BIT7                    _ATD0DR2.Bits.BIT7
#define ATD0DR2_BIT8                    _ATD0DR2.Bits.BIT8
#define ATD0DR2_BIT9                    _ATD0DR2.Bits.BIT9
#define ATD0DR2_BIT10                   _ATD0DR2.Bits.BIT10
#define ATD0DR2_BIT11                   _ATD0DR2.Bits.BIT11
#define ATD0DR2_BIT12                   _ATD0DR2.Bits.BIT12
#define ATD0DR2_BIT13                   _ATD0DR2.Bits.BIT13
#define ATD0DR2_BIT14                   _ATD0DR2.Bits.BIT14
#define ATD0DR2_BIT15                   _ATD0DR2.Bits.BIT15
#define ATD0DR2_BIT_6                   _ATD0DR2.MergedBits.grpBIT_6
#define ATD0DR2_BIT                     ATD0DR2_BIT_6

#define ATD0DR2_BIT6_MASK               64
#define ATD0DR2_BIT7_MASK               128
#define ATD0DR2_BIT8_MASK               256
#define ATD0DR2_BIT9_MASK               512
#define ATD0DR2_BIT10_MASK              1024
#define ATD0DR2_BIT11_MASK              2048
#define ATD0DR2_BIT12_MASK              4096
#define ATD0DR2_BIT13_MASK              8192
#define ATD0DR2_BIT14_MASK              16384
#define ATD0DR2_BIT15_MASK              32768
#define ATD0DR2_BIT_6_MASK              65472
#define ATD0DR2_BIT_6_BITNUM            6


 ATD0DR3 - ATD 0 Conversion Result Register 3; 0x000002D6 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0DR3H - ATD 0 Conversion Result Register 3 High; 0x000002D6 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD0DR3HSTR;
    #define ATD0DR3H                    _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Byte
    #define ATD0DR3H_BIT8               _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT8
    #define ATD0DR3H_BIT9               _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT9
    #define ATD0DR3H_BIT10              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT10
    #define ATD0DR3H_BIT11              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT11
    #define ATD0DR3H_BIT12              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT12
    #define ATD0DR3H_BIT13              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT13
    #define ATD0DR3H_BIT14              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT14
    #define ATD0DR3H_BIT15              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT15
    
    
    #define ATD0DR3H_BIT8_MASK          1
    #define ATD0DR3H_BIT9_MASK          2
    #define ATD0DR3H_BIT10_MASK         4
    #define ATD0DR3H_BIT11_MASK         8
    #define ATD0DR3H_BIT12_MASK         16
    #define ATD0DR3H_BIT13_MASK         32
    #define ATD0DR3H_BIT14_MASK         64
    #define ATD0DR3H_BIT15_MASK         128


     ATD0DR3L - ATD 0 Conversion Result Register 3 Low; 0x000002D7 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD0DR3LSTR;
    #define ATD0DR3L                    _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Byte
    #define ATD0DR3L_BIT6               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT6
    #define ATD0DR3L_BIT7               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT7
    
    #define ATD0DR3L_BIT_6              _ATD0DR3.Overlap_STR.ATD0DR3LSTR.MergedBits.grpBIT_6
    #define ATD0DR3L_BIT                ATD0DR3L_BIT_6
    
    #define ATD0DR3L_BIT6_MASK          64
    #define ATD0DR3L_BIT7_MASK          128
    #define ATD0DR3L_BIT_6_MASK         192
    #define ATD0DR3L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD0DR3STR;
extern volatile ATD0DR3STR _ATD0DR3 @(REG_BASE + 0x000002D6);
#define ATD0DR3                         _ATD0DR3.Word
#define ATD0DR3_BIT6                    _ATD0DR3.Bits.BIT6
#define ATD0DR3_BIT7                    _ATD0DR3.Bits.BIT7
#define ATD0DR3_BIT8                    _ATD0DR3.Bits.BIT8
#define ATD0DR3_BIT9                    _ATD0DR3.Bits.BIT9
#define ATD0DR3_BIT10                   _ATD0DR3.Bits.BIT10
#define ATD0DR3_BIT11                   _ATD0DR3.Bits.BIT11
#define ATD0DR3_BIT12                   _ATD0DR3.Bits.BIT12
#define ATD0DR3_BIT13                   _ATD0DR3.Bits.BIT13
#define ATD0DR3_BIT14                   _ATD0DR3.Bits.BIT14
#define ATD0DR3_BIT15                   _ATD0DR3.Bits.BIT15
#define ATD0DR3_BIT_6                   _ATD0DR3.MergedBits.grpBIT_6
#define ATD0DR3_BIT                     ATD0DR3_BIT_6

#define ATD0DR3_BIT6_MASK               64
#define ATD0DR3_BIT7_MASK               128
#define ATD0DR3_BIT8_MASK               256
#define ATD0DR3_BIT9_MASK               512
#define ATD0DR3_BIT10_MASK              1024
#define ATD0DR3_BIT11_MASK              2048
#define ATD0DR3_BIT12_MASK              4096
#define ATD0DR3_BIT13_MASK              8192
#define ATD0DR3_BIT14_MASK              16384
#define ATD0DR3_BIT15_MASK              32768
#define ATD0DR3_BIT_6_MASK              65472
#define ATD0DR3_BIT_6_BITNUM            6


 ATD0DR4 - ATD 0 Conversion Result Register 4; 0x000002D8 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0DR4H - ATD 0 Conversion Result Register 4 High; 0x000002D8 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD0DR4HSTR;
    #define ATD0DR4H                    _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Byte
    #define ATD0DR4H_BIT8               _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT8
    #define ATD0DR4H_BIT9               _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT9
    #define ATD0DR4H_BIT10              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT10
    #define ATD0DR4H_BIT11              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT11
    #define ATD0DR4H_BIT12              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT12
    #define ATD0DR4H_BIT13              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT13
    #define ATD0DR4H_BIT14              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT14
    #define ATD0DR4H_BIT15              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT15
    
    
    #define ATD0DR4H_BIT8_MASK          1
    #define ATD0DR4H_BIT9_MASK          2
    #define ATD0DR4H_BIT10_MASK         4
    #define ATD0DR4H_BIT11_MASK         8
    #define ATD0DR4H_BIT12_MASK         16
    #define ATD0DR4H_BIT13_MASK         32
    #define ATD0DR4H_BIT14_MASK         64
    #define ATD0DR4H_BIT15_MASK         128


     ATD0DR4L - ATD 0 Conversion Result Register 4 Low; 0x000002D9 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD0DR4LSTR;
    #define ATD0DR4L                    _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Byte
    #define ATD0DR4L_BIT6               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT6
    #define ATD0DR4L_BIT7               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT7
    
    #define ATD0DR4L_BIT_6              _ATD0DR4.Overlap_STR.ATD0DR4LSTR.MergedBits.grpBIT_6
    #define ATD0DR4L_BIT                ATD0DR4L_BIT_6
    
    #define ATD0DR4L_BIT6_MASK          64
    #define ATD0DR4L_BIT7_MASK          128
    #define ATD0DR4L_BIT_6_MASK         192
    #define ATD0DR4L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD0DR4STR;
extern volatile ATD0DR4STR _ATD0DR4 @(REG_BASE + 0x000002D8);
#define ATD0DR4                         _ATD0DR4.Word
#define ATD0DR4_BIT6                    _ATD0DR4.Bits.BIT6
#define ATD0DR4_BIT7                    _ATD0DR4.Bits.BIT7
#define ATD0DR4_BIT8                    _ATD0DR4.Bits.BIT8
#define ATD0DR4_BIT9                    _ATD0DR4.Bits.BIT9
#define ATD0DR4_BIT10                   _ATD0DR4.Bits.BIT10
#define ATD0DR4_BIT11                   _ATD0DR4.Bits.BIT11
#define ATD0DR4_BIT12                   _ATD0DR4.Bits.BIT12
#define ATD0DR4_BIT13                   _ATD0DR4.Bits.BIT13
#define ATD0DR4_BIT14                   _ATD0DR4.Bits.BIT14
#define ATD0DR4_BIT15                   _ATD0DR4.Bits.BIT15
#define ATD0DR4_BIT_6                   _ATD0DR4.MergedBits.grpBIT_6
#define ATD0DR4_BIT                     ATD0DR4_BIT_6

#define ATD0DR4_BIT6_MASK               64
#define ATD0DR4_BIT7_MASK               128
#define ATD0DR4_BIT8_MASK               256
#define ATD0DR4_BIT9_MASK               512
#define ATD0DR4_BIT10_MASK              1024
#define ATD0DR4_BIT11_MASK              2048
#define ATD0DR4_BIT12_MASK              4096
#define ATD0DR4_BIT13_MASK              8192
#define ATD0DR4_BIT14_MASK              16384
#define ATD0DR4_BIT15_MASK              32768
#define ATD0DR4_BIT_6_MASK              65472
#define ATD0DR4_BIT_6_BITNUM            6


 ATD0DR5 - ATD 0 Conversion Result Register 5; 0x000002DA 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0DR5H - ATD 0 Conversion Result Register 5 High; 0x000002DA 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD0DR5HSTR;
    #define ATD0DR5H                    _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Byte
    #define ATD0DR5H_BIT8               _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT8
    #define ATD0DR5H_BIT9               _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT9
    #define ATD0DR5H_BIT10              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT10
    #define ATD0DR5H_BIT11              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT11
    #define ATD0DR5H_BIT12              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT12
    #define ATD0DR5H_BIT13              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT13
    #define ATD0DR5H_BIT14              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT14
    #define ATD0DR5H_BIT15              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT15
    
    
    #define ATD0DR5H_BIT8_MASK          1
    #define ATD0DR5H_BIT9_MASK          2
    #define ATD0DR5H_BIT10_MASK         4
    #define ATD0DR5H_BIT11_MASK         8
    #define ATD0DR5H_BIT12_MASK         16
    #define ATD0DR5H_BIT13_MASK         32
    #define ATD0DR5H_BIT14_MASK         64
    #define ATD0DR5H_BIT15_MASK         128


     ATD0DR5L - ATD 0 Conversion Result Register 5 Low; 0x000002DB 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD0DR5LSTR;
    #define ATD0DR5L                    _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Byte
    #define ATD0DR5L_BIT6               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT6
    #define ATD0DR5L_BIT7               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT7
    
    #define ATD0DR5L_BIT_6              _ATD0DR5.Overlap_STR.ATD0DR5LSTR.MergedBits.grpBIT_6
    #define ATD0DR5L_BIT                ATD0DR5L_BIT_6
    
    #define ATD0DR5L_BIT6_MASK          64
    #define ATD0DR5L_BIT7_MASK          128
    #define ATD0DR5L_BIT_6_MASK         192
    #define ATD0DR5L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD0DR5STR;
extern volatile ATD0DR5STR _ATD0DR5 @(REG_BASE + 0x000002DA);
#define ATD0DR5                         _ATD0DR5.Word
#define ATD0DR5_BIT6                    _ATD0DR5.Bits.BIT6
#define ATD0DR5_BIT7                    _ATD0DR5.Bits.BIT7
#define ATD0DR5_BIT8                    _ATD0DR5.Bits.BIT8
#define ATD0DR5_BIT9                    _ATD0DR5.Bits.BIT9
#define ATD0DR5_BIT10                   _ATD0DR5.Bits.BIT10
#define ATD0DR5_BIT11                   _ATD0DR5.Bits.BIT11
#define ATD0DR5_BIT12                   _ATD0DR5.Bits.BIT12
#define ATD0DR5_BIT13                   _ATD0DR5.Bits.BIT13
#define ATD0DR5_BIT14                   _ATD0DR5.Bits.BIT14
#define ATD0DR5_BIT15                   _ATD0DR5.Bits.BIT15
#define ATD0DR5_BIT_6                   _ATD0DR5.MergedBits.grpBIT_6
#define ATD0DR5_BIT                     ATD0DR5_BIT_6

#define ATD0DR5_BIT6_MASK               64
#define ATD0DR5_BIT7_MASK               128
#define ATD0DR5_BIT8_MASK               256
#define ATD0DR5_BIT9_MASK               512
#define ATD0DR5_BIT10_MASK              1024
#define ATD0DR5_BIT11_MASK              2048
#define ATD0DR5_BIT12_MASK              4096
#define ATD0DR5_BIT13_MASK              8192
#define ATD0DR5_BIT14_MASK              16384
#define ATD0DR5_BIT15_MASK              32768
#define ATD0DR5_BIT_6_MASK              65472
#define ATD0DR5_BIT_6_BITNUM            6


 ATD0DR6 - ATD 0 Conversion Result Register 6; 0x000002DC 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0DR6H - ATD 0 Conversion Result Register 6 High; 0x000002DC 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD0DR6HSTR;
    #define ATD0DR6H                    _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Byte
    #define ATD0DR6H_BIT8               _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT8
    #define ATD0DR6H_BIT9               _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT9
    #define ATD0DR6H_BIT10              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT10
    #define ATD0DR6H_BIT11              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT11
    #define ATD0DR6H_BIT12              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT12
    #define ATD0DR6H_BIT13              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT13
    #define ATD0DR6H_BIT14              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT14
    #define ATD0DR6H_BIT15              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT15
    
    
    #define ATD0DR6H_BIT8_MASK          1
    #define ATD0DR6H_BIT9_MASK          2
    #define ATD0DR6H_BIT10_MASK         4
    #define ATD0DR6H_BIT11_MASK         8
    #define ATD0DR6H_BIT12_MASK         16
    #define ATD0DR6H_BIT13_MASK         32
    #define ATD0DR6H_BIT14_MASK         64
    #define ATD0DR6H_BIT15_MASK         128


     ATD0DR6L - ATD 0 Conversion Result Register 6 Low; 0x000002DD 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD0DR6LSTR;
    #define ATD0DR6L                    _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Byte
    #define ATD0DR6L_BIT6               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT6
    #define ATD0DR6L_BIT7               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT7
    
    #define ATD0DR6L_BIT_6              _ATD0DR6.Overlap_STR.ATD0DR6LSTR.MergedBits.grpBIT_6
    #define ATD0DR6L_BIT                ATD0DR6L_BIT_6
    
    #define ATD0DR6L_BIT6_MASK          64
    #define ATD0DR6L_BIT7_MASK          128
    #define ATD0DR6L_BIT_6_MASK         192
    #define ATD0DR6L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD0DR6STR;
extern volatile ATD0DR6STR _ATD0DR6 @(REG_BASE + 0x000002DC);
#define ATD0DR6                         _ATD0DR6.Word
#define ATD0DR6_BIT6                    _ATD0DR6.Bits.BIT6
#define ATD0DR6_BIT7                    _ATD0DR6.Bits.BIT7
#define ATD0DR6_BIT8                    _ATD0DR6.Bits.BIT8
#define ATD0DR6_BIT9                    _ATD0DR6.Bits.BIT9
#define ATD0DR6_BIT10                   _ATD0DR6.Bits.BIT10
#define ATD0DR6_BIT11                   _ATD0DR6.Bits.BIT11
#define ATD0DR6_BIT12                   _ATD0DR6.Bits.BIT12
#define ATD0DR6_BIT13                   _ATD0DR6.Bits.BIT13
#define ATD0DR6_BIT14                   _ATD0DR6.Bits.BIT14
#define ATD0DR6_BIT15                   _ATD0DR6.Bits.BIT15
#define ATD0DR6_BIT_6                   _ATD0DR6.MergedBits.grpBIT_6
#define ATD0DR6_BIT                     ATD0DR6_BIT_6

#define ATD0DR6_BIT6_MASK               64
#define ATD0DR6_BIT7_MASK               128
#define ATD0DR6_BIT8_MASK               256
#define ATD0DR6_BIT9_MASK               512
#define ATD0DR6_BIT10_MASK              1024
#define ATD0DR6_BIT11_MASK              2048
#define ATD0DR6_BIT12_MASK              4096
#define ATD0DR6_BIT13_MASK              8192
#define ATD0DR6_BIT14_MASK              16384
#define ATD0DR6_BIT15_MASK              32768
#define ATD0DR6_BIT_6_MASK              65472
#define ATD0DR6_BIT_6_BITNUM            6


 ATD0DR7 - ATD 0 Conversion Result Register 7; 0x000002DE 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     ATD0DR7H - ATD 0 Conversion Result Register 7 High; 0x000002DE 
    union {
      byte Byte;
      struct {
        byte BIT8        1;                                        Bit 8 
        byte BIT9        1;                                        Bit 9 
        byte BIT10       1;                                        Bit 10 
        byte BIT11       1;                                        Bit 11 
        byte BIT12       1;                                        Bit 12 
        byte BIT13       1;                                        Bit 13 
        byte BIT14       1;                                        Bit 14 
        byte BIT15       1;                                        Bit 15 
      } Bits;
    } ATD0DR7HSTR;
    #define ATD0DR7H                    _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Byte
    #define ATD0DR7H_BIT8               _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT8
    #define ATD0DR7H_BIT9               _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT9
    #define ATD0DR7H_BIT10              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT10
    #define ATD0DR7H_BIT11              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT11
    #define ATD0DR7H_BIT12              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT12
    #define ATD0DR7H_BIT13              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT13
    #define ATD0DR7H_BIT14              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT14
    #define ATD0DR7H_BIT15              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT15
    
    
    #define ATD0DR7H_BIT8_MASK          1
    #define ATD0DR7H_BIT9_MASK          2
    #define ATD0DR7H_BIT10_MASK         4
    #define ATD0DR7H_BIT11_MASK         8
    #define ATD0DR7H_BIT12_MASK         16
    #define ATD0DR7H_BIT13_MASK         32
    #define ATD0DR7H_BIT14_MASK         64
    #define ATD0DR7H_BIT15_MASK         128


     ATD0DR7L - ATD 0 Conversion Result Register 7 Low; 0x000002DF 
    union {
      byte Byte;
      struct {
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
        byte BIT6        1;                                        Bit 6 
        byte BIT7        1;                                        Bit 7 
      } Bits;
      struct {
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
        byte grpBIT_6 2;
      } MergedBits;
    } ATD0DR7LSTR;
    #define ATD0DR7L                    _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Byte
    #define ATD0DR7L_BIT6               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT6
    #define ATD0DR7L_BIT7               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT7
    
    #define ATD0DR7L_BIT_6              _ATD0DR7.Overlap_STR.ATD0DR7LSTR.MergedBits.grpBIT_6
    #define ATD0DR7L_BIT                ATD0DR7L_BIT_6
    
    #define ATD0DR7L_BIT6_MASK          64
    #define ATD0DR7L_BIT7_MASK          128
    #define ATD0DR7L_BIT_6_MASK         192
    #define ATD0DR7L_BIT_6_BITNUM       6

  } Overlap_STR;

  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word BIT6        1;                                        Bit 6 
    word BIT7        1;                                        Bit 7 
    word BIT8        1;                                        Bit 8 
    word BIT9        1;                                        Bit 9 
    word BIT10       1;                                        Bit 10 
    word BIT11       1;                                        Bit 11 
    word BIT12       1;                                        Bit 12 
    word BIT13       1;                                        Bit 13 
    word BIT14       1;                                        Bit 14 
    word BIT15       1;                                        Bit 15 
  } Bits;
  struct {
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word grpBIT_6 10;
  } MergedBits;
} ATD0DR7STR;
extern volatile ATD0DR7STR _ATD0DR7 @(REG_BASE + 0x000002DE);
#define ATD0DR7                         _ATD0DR7.Word
#define ATD0DR7_BIT6                    _ATD0DR7.Bits.BIT6
#define ATD0DR7_BIT7                    _ATD0DR7.Bits.BIT7
#define ATD0DR7_BIT8                    _ATD0DR7.Bits.BIT8
#define ATD0DR7_BIT9                    _ATD0DR7.Bits.BIT9
#define ATD0DR7_BIT10                   _ATD0DR7.Bits.BIT10
#define ATD0DR7_BIT11                   _ATD0DR7.Bits.BIT11
#define ATD0DR7_BIT12                   _ATD0DR7.Bits.BIT12
#define ATD0DR7_BIT13                   _ATD0DR7.Bits.BIT13
#define ATD0DR7_BIT14                   _ATD0DR7.Bits.BIT14
#define ATD0DR7_BIT15                   _ATD0DR7.Bits.BIT15
#define ATD0DR7_BIT_6                   _ATD0DR7.MergedBits.grpBIT_6
#define ATD0DR7_BIT                     ATD0DR7_BIT_6

#define ATD0DR7_BIT6_MASK               64
#define ATD0DR7_BIT7_MASK               128
#define ATD0DR7_BIT8_MASK               256
#define ATD0DR7_BIT9_MASK               512
#define ATD0DR7_BIT10_MASK              1024
#define ATD0DR7_BIT11_MASK              2048
#define ATD0DR7_BIT12_MASK              4096
#define ATD0DR7_BIT13_MASK              8192
#define ATD0DR7_BIT14_MASK              16384
#define ATD0DR7_BIT15_MASK              32768
#define ATD0DR7_BIT_6_MASK              65472
#define ATD0DR7_BIT_6_BITNUM            6


 VREGCTRL - VREG_3V3 - Control Register; 0x000002F1 
typedef union {
  byte Byte;
  struct {
    byte LVIF        1;                                        Low Voltage Interrupt Flag 
    byte LVIE        1;                                        Low Voltage Interrupt Enable Bit 
    byte LVDS        1;                                        Low Voltage Detect Status Bit 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
} VREGCTRLSTR;
extern volatile VREGCTRLSTR _VREGCTRL @(REG_BASE + 0x000002F1);
#define VREGCTRL                        _VREGCTRL.Byte
#define VREGCTRL_LVIF                   _VREGCTRL.Bits.LVIF
#define VREGCTRL_LVIE                   _VREGCTRL.Bits.LVIE
#define VREGCTRL_LVDS                   _VREGCTRL.Bits.LVDS

#define VREGCTRL_LVIF_MASK              1
#define VREGCTRL_LVIE_MASK              2
#define VREGCTRL_LVDS_MASK              4


 VREGAPICL - VREG_3V3 - Autonomous Periodical Interrupt Control Register; 0x000002F2 
typedef union {
  byte Byte;
  struct {
    byte APIF        1;                                        Autonomous Periodical Interrupt Flag 
    byte APIE        1;                                        Autonomous Periodical Interrupt Enable Bit 
    byte APIFE       1;                                        Autonomous Periodical Interrupt Feature Enable Bit 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
    byte APICLK      1;                                        Autonomous Periodical Interrupt Clock Select Bit 
  } Bits;
} VREGAPICLSTR;
extern volatile VREGAPICLSTR _VREGAPICL @(REG_BASE + 0x000002F2);
#define VREGAPICL                       _VREGAPICL.Byte
#define VREGAPICL_APIF                  _VREGAPICL.Bits.APIF
#define VREGAPICL_APIE                  _VREGAPICL.Bits.APIE
#define VREGAPICL_APIFE                 _VREGAPICL.Bits.APIFE
#define VREGAPICL_APICLK                _VREGAPICL.Bits.APICLK

#define VREGAPICL_APIF_MASK             1
#define VREGAPICL_APIE_MASK             2
#define VREGAPICL_APIFE_MASK            4
#define VREGAPICL_APICLK_MASK           128


 VREGAPITR - VREG_3V3 - Autonomous Periodical Interrupt Trimming Register; 0x000002F3 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte APITR0      1;                                        Autonomous Periodical Interrupt Period Trimming Bit 0 
    byte APITR1      1;                                        Autonomous Periodical Interrupt Period Trimming Bit 1 
    byte APITR2      1;                                        Autonomous Periodical Interrupt Period Trimming Bit 2 
    byte APITR3      1;                                        Autonomous Periodical Interrupt Period Trimming Bit 3 
    byte APITR4      1;                                        Autonomous Periodical Interrupt Period Trimming Bit 4 
    byte APITR5      1;                                        Autonomous Periodical Interrupt Period Trimming Bit 5 
  } Bits;
  struct {
    byte         1;
    byte         1;
    byte grpAPITR 6;
  } MergedBits;
} VREGAPITRSTR;
extern volatile VREGAPITRSTR _VREGAPITR @(REG_BASE + 0x000002F3);
#define VREGAPITR                       _VREGAPITR.Byte
#define VREGAPITR_APITR0                _VREGAPITR.Bits.APITR0
#define VREGAPITR_APITR1                _VREGAPITR.Bits.APITR1
#define VREGAPITR_APITR2                _VREGAPITR.Bits.APITR2
#define VREGAPITR_APITR3                _VREGAPITR.Bits.APITR3
#define VREGAPITR_APITR4                _VREGAPITR.Bits.APITR4
#define VREGAPITR_APITR5                _VREGAPITR.Bits.APITR5
#define VREGAPITR_APITR                 _VREGAPITR.MergedBits.grpAPITR

#define VREGAPITR_APITR0_MASK           4
#define VREGAPITR_APITR1_MASK           8
#define VREGAPITR_APITR2_MASK           16
#define VREGAPITR_APITR3_MASK           32
#define VREGAPITR_APITR4_MASK           64
#define VREGAPITR_APITR5_MASK           128
#define VREGAPITR_APITR_MASK            252
#define VREGAPITR_APITR_BITNUM          2


 VREGAPIR - VREG_3V3 - Autonomous Periodical Interrupt Rate Register; 0x000002F4 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     VREGAPIRH - VREG_3V3 - Autonomous Periodical Interrupt Rate Register High; 0x000002F4 
    union {
      byte Byte;
      struct {
        byte APIR8       1;                                        Autonomous Periodical Interrupt Rate Bit 8 
        byte APIR9       1;                                        Autonomous Periodical Interrupt Rate Bit 9 
        byte APIR10      1;                                        Autonomous Periodical Interrupt Rate Bit 10 
        byte APIR11      1;                                        Autonomous Periodical Interrupt Rate Bit 11 
        byte             1; 
        byte             1; 
        byte             1; 
        byte             1; 
      } Bits;
      struct {
        byte grpAPIR_8 4;
        byte     1;
        byte     1;
        byte     1;
        byte     1;
      } MergedBits;
    } VREGAPIRHSTR;
    #define VREGAPIRH                   _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Byte
    #define VREGAPIRH_APIR8             _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR8
    #define VREGAPIRH_APIR9             _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR9
    #define VREGAPIRH_APIR10            _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR10
    #define VREGAPIRH_APIR11            _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR11
    
    #define VREGAPIRH_APIR_8            _VREGAPIR.Overlap_STR.VREGAPIRHSTR.MergedBits.grpAPIR_8
    #define VREGAPIRH_APIR              VREGAPIRH_APIR_8
    
    #define VREGAPIRH_APIR8_MASK        1
    #define VREGAPIRH_APIR9_MASK        2
    #define VREGAPIRH_APIR10_MASK       4
    #define VREGAPIRH_APIR11_MASK       8
    #define VREGAPIRH_APIR_8_MASK       15
    #define VREGAPIRH_APIR_8_BITNUM     0


     VREGAPIRL - VREG_3V3 - Autonomous Periodical Interrupt Rate Register Low; 0x000002F5 
    union {
      byte Byte;
      struct {
        byte APIR0       1;                                        Autonomous Periodical Interrupt Rate Bit 0 
        byte APIR1       1;                                        Autonomous Periodical Interrupt Rate Bit 1 
        byte APIR2       1;                                        Autonomous Periodical Interrupt Rate Bit 2 
        byte APIR3       1;                                        Autonomous Periodical Interrupt Rate Bit 3 
        byte APIR4       1;                                        Autonomous Periodical Interrupt Rate Bit 4 
        byte APIR5       1;                                        Autonomous Periodical Interrupt Rate Bit 5 
        byte APIR6       1;                                        Autonomous Periodical Interrupt Rate Bit 6 
        byte APIR7       1;                                        Autonomous Periodical Interrupt Rate Bit 7 
      } Bits;
    } VREGAPIRLSTR;
    #define VREGAPIRL                   _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Byte
    #define VREGAPIRL_APIR0             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR0
    #define VREGAPIRL_APIR1             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR1
    #define VREGAPIRL_APIR2             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR2
    #define VREGAPIRL_APIR3             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR3
    #define VREGAPIRL_APIR4             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR4
    #define VREGAPIRL_APIR5             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR5
    #define VREGAPIRL_APIR6             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR6
    #define VREGAPIRL_APIR7             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR7
    
    
    #define VREGAPIRL_APIR0_MASK        1
    #define VREGAPIRL_APIR1_MASK        2
    #define VREGAPIRL_APIR2_MASK        4
    #define VREGAPIRL_APIR3_MASK        8
    #define VREGAPIRL_APIR4_MASK        16
    #define VREGAPIRL_APIR5_MASK        32
    #define VREGAPIRL_APIR6_MASK        64
    #define VREGAPIRL_APIR7_MASK        128

  } Overlap_STR;

  struct {
    word APIR0       1;                                        Autonomous Periodical Interrupt Rate Bit 0 
    word APIR1       1;                                        Autonomous Periodical Interrupt Rate Bit 1 
    word APIR2       1;                                        Autonomous Periodical Interrupt Rate Bit 2 
    word APIR3       1;                                        Autonomous Periodical Interrupt Rate Bit 3 
    word APIR4       1;                                        Autonomous Periodical Interrupt Rate Bit 4 
    word APIR5       1;                                        Autonomous Periodical Interrupt Rate Bit 5 
    word APIR6       1;                                        Autonomous Periodical Interrupt Rate Bit 6 
    word APIR7       1;                                        Autonomous Periodical Interrupt Rate Bit 7 
    word APIR8       1;                                        Autonomous Periodical Interrupt Rate Bit 8 
    word APIR9       1;                                        Autonomous Periodical Interrupt Rate Bit 9 
    word APIR10      1;                                        Autonomous Periodical Interrupt Rate Bit 10 
    word APIR11      1;                                        Autonomous Periodical Interrupt Rate Bit 11 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
  } Bits;
  struct {
    word grpAPIR 12;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} VREGAPIRSTR;
extern volatile VREGAPIRSTR _VREGAPIR @(REG_BASE + 0x000002F4);
#define VREGAPIR                        _VREGAPIR.Word
#define VREGAPIR_APIR0                  _VREGAPIR.Bits.APIR0
#define VREGAPIR_APIR1                  _VREGAPIR.Bits.APIR1
#define VREGAPIR_APIR2                  _VREGAPIR.Bits.APIR2
#define VREGAPIR_APIR3                  _VREGAPIR.Bits.APIR3
#define VREGAPIR_APIR4                  _VREGAPIR.Bits.APIR4
#define VREGAPIR_APIR5                  _VREGAPIR.Bits.APIR5
#define VREGAPIR_APIR6                  _VREGAPIR.Bits.APIR6
#define VREGAPIR_APIR7                  _VREGAPIR.Bits.APIR7
#define VREGAPIR_APIR8                  _VREGAPIR.Bits.APIR8
#define VREGAPIR_APIR9                  _VREGAPIR.Bits.APIR9
#define VREGAPIR_APIR10                 _VREGAPIR.Bits.APIR10
#define VREGAPIR_APIR11                 _VREGAPIR.Bits.APIR11
#define VREGAPIR_APIR                   _VREGAPIR.MergedBits.grpAPIR

#define VREGAPIR_APIR0_MASK             1
#define VREGAPIR_APIR1_MASK             2
#define VREGAPIR_APIR2_MASK             4
#define VREGAPIR_APIR3_MASK             8
#define VREGAPIR_APIR4_MASK             16
#define VREGAPIR_APIR5_MASK             32
#define VREGAPIR_APIR6_MASK             64
#define VREGAPIR_APIR7_MASK             128
#define VREGAPIR_APIR8_MASK             256
#define VREGAPIR_APIR9_MASK             512
#define VREGAPIR_APIR10_MASK            1024
#define VREGAPIR_APIR11_MASK            2048
#define VREGAPIR_APIR_MASK              4095
#define VREGAPIR_APIR_BITNUM            0


 PWME - PWM Enable Register; 0x00000300 
typedef union {
  byte Byte;
  struct {
    byte PWME0       1;                                        Pulse Width Channel 0 Enable 
    byte PWME1       1;                                        Pulse Width Channel 1 Enable 
    byte PWME2       1;                                        Pulse Width Channel 2 Enable 
    byte PWME3       1;                                        Pulse Width Channel 3 Enable 
    byte PWME4       1;                                        Pulse Width Channel 4 Enable 
    byte PWME5       1;                                        Pulse Width Channel 5 Enable 
    byte PWME6       1;                                        Pulse Width Channel 6 Enable 
    byte PWME7       1;                                        Pulse Width Channel 7 Enable 
  } Bits;
} PWMESTR;
extern volatile PWMESTR _PWME @(REG_BASE + 0x00000300);
#define PWME                            _PWME.Byte
#define PWME_PWME0                      _PWME.Bits.PWME0
#define PWME_PWME1                      _PWME.Bits.PWME1
#define PWME_PWME2                      _PWME.Bits.PWME2
#define PWME_PWME3                      _PWME.Bits.PWME3
#define PWME_PWME4                      _PWME.Bits.PWME4
#define PWME_PWME5                      _PWME.Bits.PWME5
#define PWME_PWME6                      _PWME.Bits.PWME6
#define PWME_PWME7                      _PWME.Bits.PWME7

#define PWME_PWME0_MASK                 1
#define PWME_PWME1_MASK                 2
#define PWME_PWME2_MASK                 4
#define PWME_PWME3_MASK                 8
#define PWME_PWME4_MASK                 16
#define PWME_PWME5_MASK                 32
#define PWME_PWME6_MASK                 64
#define PWME_PWME7_MASK                 128


 PWMPOL - PWM Polarity Register; 0x00000301 
typedef union {
  byte Byte;
  struct {
    byte PPOL0       1;                                        Pulse Width Channel 0 Polarity 
    byte PPOL1       1;                                        Pulse Width Channel 1 Polarity 
    byte PPOL2       1;                                        Pulse Width Channel 2 Polarity 
    byte PPOL3       1;                                        Pulse Width Channel 3 Polarity 
    byte PPOL4       1;                                        Pulse Width Channel 4 Polarity 
    byte PPOL5       1;                                        Pulse Width Channel 5 Polarity 
    byte PPOL6       1;                                        Pulse Width Channel 6 Polarity 
    byte PPOL7       1;                                        Pulse Width Channel 7 Polarity 
  } Bits;
} PWMPOLSTR;
extern volatile PWMPOLSTR _PWMPOL @(REG_BASE + 0x00000301);
#define PWMPOL                          _PWMPOL.Byte
#define PWMPOL_PPOL0                    _PWMPOL.Bits.PPOL0
#define PWMPOL_PPOL1                    _PWMPOL.Bits.PPOL1
#define PWMPOL_PPOL2                    _PWMPOL.Bits.PPOL2
#define PWMPOL_PPOL3                    _PWMPOL.Bits.PPOL3
#define PWMPOL_PPOL4                    _PWMPOL.Bits.PPOL4
#define PWMPOL_PPOL5                    _PWMPOL.Bits.PPOL5
#define PWMPOL_PPOL6                    _PWMPOL.Bits.PPOL6
#define PWMPOL_PPOL7                    _PWMPOL.Bits.PPOL7

#define PWMPOL_PPOL0_MASK               1
#define PWMPOL_PPOL1_MASK               2
#define PWMPOL_PPOL2_MASK               4
#define PWMPOL_PPOL3_MASK               8
#define PWMPOL_PPOL4_MASK               16
#define PWMPOL_PPOL5_MASK               32
#define PWMPOL_PPOL6_MASK               64
#define PWMPOL_PPOL7_MASK               128


 PWMCLK - PWM Clock Select Register; 0x00000302 
typedef union {
  byte Byte;
  struct {
    byte PCLK0       1;                                        Pulse Width Channel 0 Clock Select 
    byte PCLK1       1;                                        Pulse Width Channel 1 Clock Select 
    byte PCLK2       1;                                        Pulse Width Channel 2 Clock Select 
    byte PCLK3       1;                                        Pulse Width Channel 3 Clock Select 
    byte PCLK4       1;                                        Pulse Width Channel 4 Clock Select 
    byte PCLK5       1;                                        Pulse Width Channel 5 Clock Select 
    byte PCLK6       1;                                        Pulse Width Channel 6 Clock Select 
    byte PCLK7       1;                                        Pulse Width Channel 7 Clock Select 
  } Bits;
} PWMCLKSTR;
extern volatile PWMCLKSTR _PWMCLK @(REG_BASE + 0x00000302);
#define PWMCLK                          _PWMCLK.Byte
#define PWMCLK_PCLK0                    _PWMCLK.Bits.PCLK0
#define PWMCLK_PCLK1                    _PWMCLK.Bits.PCLK1
#define PWMCLK_PCLK2                    _PWMCLK.Bits.PCLK2
#define PWMCLK_PCLK3                    _PWMCLK.Bits.PCLK3
#define PWMCLK_PCLK4                    _PWMCLK.Bits.PCLK4
#define PWMCLK_PCLK5                    _PWMCLK.Bits.PCLK5
#define PWMCLK_PCLK6                    _PWMCLK.Bits.PCLK6
#define PWMCLK_PCLK7                    _PWMCLK.Bits.PCLK7

#define PWMCLK_PCLK0_MASK               1
#define PWMCLK_PCLK1_MASK               2
#define PWMCLK_PCLK2_MASK               4
#define PWMCLK_PCLK3_MASK               8
#define PWMCLK_PCLK4_MASK               16
#define PWMCLK_PCLK5_MASK               32
#define PWMCLK_PCLK6_MASK               64
#define PWMCLK_PCLK7_MASK               128


 PWMPRCLK - PWM Prescale Clock Select Register; 0x00000303 
typedef union {
  byte Byte;
  struct {
    byte PCKA0       1;                                        Prescaler Select for Clock A 0 
    byte PCKA1       1;                                        Prescaler Select for Clock A 1 
    byte PCKA2       1;                                        Prescaler Select for Clock A 2 
    byte             1; 
    byte PCKB0       1;                                        Prescaler Select for Clock B 0 
    byte PCKB1       1;                                        Prescaler Select for Clock B 1 
    byte PCKB2       1;                                        Prescaler Select for Clock B 2 
    byte             1; 
  } Bits;
  struct {
    byte grpPCKA 3;
    byte         1;
    byte grpPCKB 3;
    byte         1;
  } MergedBits;
} PWMPRCLKSTR;
extern volatile PWMPRCLKSTR _PWMPRCLK @(REG_BASE + 0x00000303);
#define PWMPRCLK                        _PWMPRCLK.Byte
#define PWMPRCLK_PCKA0                  _PWMPRCLK.Bits.PCKA0
#define PWMPRCLK_PCKA1                  _PWMPRCLK.Bits.PCKA1
#define PWMPRCLK_PCKA2                  _PWMPRCLK.Bits.PCKA2
#define PWMPRCLK_PCKB0                  _PWMPRCLK.Bits.PCKB0
#define PWMPRCLK_PCKB1                  _PWMPRCLK.Bits.PCKB1
#define PWMPRCLK_PCKB2                  _PWMPRCLK.Bits.PCKB2
#define PWMPRCLK_PCKA                   _PWMPRCLK.MergedBits.grpPCKA
#define PWMPRCLK_PCKB                   _PWMPRCLK.MergedBits.grpPCKB

#define PWMPRCLK_PCKA0_MASK             1
#define PWMPRCLK_PCKA1_MASK             2
#define PWMPRCLK_PCKA2_MASK             4
#define PWMPRCLK_PCKB0_MASK             16
#define PWMPRCLK_PCKB1_MASK             32
#define PWMPRCLK_PCKB2_MASK             64
#define PWMPRCLK_PCKA_MASK              7
#define PWMPRCLK_PCKA_BITNUM            0
#define PWMPRCLK_PCKB_MASK              112
#define PWMPRCLK_PCKB_BITNUM            4


 PWMCAE - PWM Center Align Enable Register; 0x00000304 
typedef union {
  byte Byte;
  struct {
    byte CAE0        1;                                        Center Aligned Output Mode on channel 0 
    byte CAE1        1;                                        Center Aligned Output Mode on channel 1 
    byte CAE2        1;                                        Center Aligned Output Mode on channel 2 
    byte CAE3        1;                                        Center Aligned Output Mode on channel 3 
    byte CAE4        1;                                        Center Aligned Output Mode on channel 4 
    byte CAE5        1;                                        Center Aligned Output Mode on channel 5 
    byte CAE6        1;                                        Center Aligned Output Mode on channel 6 
    byte CAE7        1;                                        Center Aligned Output Mode on channel 7 
  } Bits;
} PWMCAESTR;
extern volatile PWMCAESTR _PWMCAE @(REG_BASE + 0x00000304);
#define PWMCAE                          _PWMCAE.Byte
#define PWMCAE_CAE0                     _PWMCAE.Bits.CAE0
#define PWMCAE_CAE1                     _PWMCAE.Bits.CAE1
#define PWMCAE_CAE2                     _PWMCAE.Bits.CAE2
#define PWMCAE_CAE3                     _PWMCAE.Bits.CAE3
#define PWMCAE_CAE4                     _PWMCAE.Bits.CAE4
#define PWMCAE_CAE5                     _PWMCAE.Bits.CAE5
#define PWMCAE_CAE6                     _PWMCAE.Bits.CAE6
#define PWMCAE_CAE7                     _PWMCAE.Bits.CAE7

#define PWMCAE_CAE0_MASK                1
#define PWMCAE_CAE1_MASK                2
#define PWMCAE_CAE2_MASK                4
#define PWMCAE_CAE3_MASK                8
#define PWMCAE_CAE4_MASK                16
#define PWMCAE_CAE5_MASK                32
#define PWMCAE_CAE6_MASK                64
#define PWMCAE_CAE7_MASK                128


 PWMCTL - PWM Control Register; 0x00000305 
typedef union {
  byte Byte;
  struct {
    byte             1; 
    byte             1; 
    byte PFRZ        1;                                        PWM Counters Stop in Freeze Mode 
    byte PSWAI       1;                                        PWM Stops in Wait Mode 
    byte CON01       1;                                        Concatenate channels 0 and 1 
    byte CON23       1;                                        Concatenate channels 2 and 3 
    byte CON45       1;                                        Concatenate channels 4 and 5 
    byte CON67       1;                                        Concatenate channels 6 and 7 
  } Bits;
} PWMCTLSTR;
extern volatile PWMCTLSTR _PWMCTL @(REG_BASE + 0x00000305);
#define PWMCTL                          _PWMCTL.Byte
#define PWMCTL_PFRZ                     _PWMCTL.Bits.PFRZ
#define PWMCTL_PSWAI                    _PWMCTL.Bits.PSWAI
#define PWMCTL_CON01                    _PWMCTL.Bits.CON01
#define PWMCTL_CON23                    _PWMCTL.Bits.CON23
#define PWMCTL_CON45                    _PWMCTL.Bits.CON45
#define PWMCTL_CON67                    _PWMCTL.Bits.CON67

#define PWMCTL_PFRZ_MASK                4
#define PWMCTL_PSWAI_MASK               8
#define PWMCTL_CON01_MASK               16
#define PWMCTL_CON23_MASK               32
#define PWMCTL_CON45_MASK               64
#define PWMCTL_CON67_MASK               128


 PWMSCLA - PWM Scale A Register; 0x00000308 
typedef union {
  byte Byte;
  struct {
    byte BIT0        1;                                        PWM Scale A Bit 0 
    byte BIT1        1;                                        PWM Scale A Bit 1 
    byte BIT2        1;                                        PWM Scale A Bit 2 
    byte BIT3        1;                                        PWM Scale A Bit 3 
    byte BIT4        1;                                        PWM Scale A Bit 4 
    byte BIT5        1;                                        PWM Scale A Bit 5 
    byte BIT6        1;                                        PWM Scale A Bit 6 
    byte BIT7        1;                                        PWM Scale A Bit 7 
  } Bits;
} PWMSCLASTR;
extern volatile PWMSCLASTR _PWMSCLA @(REG_BASE + 0x00000308);
#define PWMSCLA                         _PWMSCLA.Byte
#define PWMSCLA_BIT0                    _PWMSCLA.Bits.BIT0
#define PWMSCLA_BIT1                    _PWMSCLA.Bits.BIT1
#define PWMSCLA_BIT2                    _PWMSCLA.Bits.BIT2
#define PWMSCLA_BIT3                    _PWMSCLA.Bits.BIT3
#define PWMSCLA_BIT4                    _PWMSCLA.Bits.BIT4
#define PWMSCLA_BIT5                    _PWMSCLA.Bits.BIT5
#define PWMSCLA_BIT6                    _PWMSCLA.Bits.BIT6
#define PWMSCLA_BIT7                    _PWMSCLA.Bits.BIT7

#define PWMSCLA_BIT0_MASK               1
#define PWMSCLA_BIT1_MASK               2
#define PWMSCLA_BIT2_MASK               4
#define PWMSCLA_BIT3_MASK               8
#define PWMSCLA_BIT4_MASK               16
#define PWMSCLA_BIT5_MASK               32
#define PWMSCLA_BIT6_MASK               64
#define PWMSCLA_BIT7_MASK               128


 PWMSCLB - PWM Scale B Register; 0x00000309 
typedef union {
  byte Byte;
  struct {
    byte BIT0        1;                                        PWM Scale B Bit 0 
    byte BIT1        1;                                        PWM Scale B Bit 1 
    byte BIT2        1;                                        PWM Scale B Bit 2 
    byte BIT3        1;                                        PWM Scale B Bit 3 
    byte BIT4        1;                                        PWM Scale B Bit 4 
    byte BIT5        1;                                        PWM Scale B Bit 5 
    byte BIT6        1;                                        PWM Scale B Bit 6 
    byte BIT7        1;                                        PWM Scale B Bit 7 
  } Bits;
} PWMSCLBSTR;
extern volatile PWMSCLBSTR _PWMSCLB @(REG_BASE + 0x00000309);
#define PWMSCLB                         _PWMSCLB.Byte
#define PWMSCLB_BIT0                    _PWMSCLB.Bits.BIT0
#define PWMSCLB_BIT1                    _PWMSCLB.Bits.BIT1
#define PWMSCLB_BIT2                    _PWMSCLB.Bits.BIT2
#define PWMSCLB_BIT3                    _PWMSCLB.Bits.BIT3
#define PWMSCLB_BIT4                    _PWMSCLB.Bits.BIT4
#define PWMSCLB_BIT5                    _PWMSCLB.Bits.BIT5
#define PWMSCLB_BIT6                    _PWMSCLB.Bits.BIT6
#define PWMSCLB_BIT7                    _PWMSCLB.Bits.BIT7

#define PWMSCLB_BIT0_MASK               1
#define PWMSCLB_BIT1_MASK               2
#define PWMSCLB_BIT2_MASK               4
#define PWMSCLB_BIT3_MASK               8
#define PWMSCLB_BIT4_MASK               16
#define PWMSCLB_BIT5_MASK               32
#define PWMSCLB_BIT6_MASK               64
#define PWMSCLB_BIT7_MASK               128


 PWMCNT01 - PWM Channel Counter 01 Register; 0x0000030C 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMCNT0 - PWM Channel Counter 0 Register; 0x0000030C 
    union {
      byte Byte;
    } PWMCNT0STR;
    #define PWMCNT0                     _PWMCNT01.Overlap_STR.PWMCNT0STR.Byte
    
     PWMCNT_ARR Access 8 PWMCNTx registers in an array 
    #define PWMCNT_ARR                  ((volatile byte ) &PWMCNT0)
    


     PWMCNT1 - PWM Channel Counter 1 Register; 0x0000030D 
    union {
      byte Byte;
    } PWMCNT1STR;
    #define PWMCNT1                     _PWMCNT01.Overlap_STR.PWMCNT1STR.Byte
    
    

  } Overlap_STR;

} PWMCNT01STR;
extern volatile PWMCNT01STR _PWMCNT01 @(REG_BASE + 0x0000030C);
#define PWMCNT01                        _PWMCNT01.Word



 PWMCNT23 - PWM Channel Counter 23 Register; 0x0000030E 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMCNT2 - PWM Channel Counter 2 Register; 0x0000030E 
    union {
      byte Byte;
    } PWMCNT2STR;
    #define PWMCNT2                     _PWMCNT23.Overlap_STR.PWMCNT2STR.Byte
    
    


     PWMCNT3 - PWM Channel Counter 3 Register; 0x0000030F 
    union {
      byte Byte;
    } PWMCNT3STR;
    #define PWMCNT3                     _PWMCNT23.Overlap_STR.PWMCNT3STR.Byte
    
    

  } Overlap_STR;

} PWMCNT23STR;
extern volatile PWMCNT23STR _PWMCNT23 @(REG_BASE + 0x0000030E);
#define PWMCNT23                        _PWMCNT23.Word



 PWMCNT45 - PWM Channel Counter 45 Register; 0x00000310 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMCNT4 - PWM Channel Counter 4 Register; 0x00000310 
    union {
      byte Byte;
    } PWMCNT4STR;
    #define PWMCNT4                     _PWMCNT45.Overlap_STR.PWMCNT4STR.Byte
    
    


     PWMCNT5 - PWM Channel Counter 5 Register; 0x00000311 
    union {
      byte Byte;
    } PWMCNT5STR;
    #define PWMCNT5                     _PWMCNT45.Overlap_STR.PWMCNT5STR.Byte
    
    

  } Overlap_STR;

} PWMCNT45STR;
extern volatile PWMCNT45STR _PWMCNT45 @(REG_BASE + 0x00000310);
#define PWMCNT45                        _PWMCNT45.Word



 PWMCNT67 - PWM Channel Counter 67 Register; 0x00000312 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMCNT6 - PWM Channel Counter 6 Register; 0x00000312 
    union {
      byte Byte;
    } PWMCNT6STR;
    #define PWMCNT6                     _PWMCNT67.Overlap_STR.PWMCNT6STR.Byte
    
    


     PWMCNT7 - PWM Channel Counter 7 Register; 0x00000313 
    union {
      byte Byte;
    } PWMCNT7STR;
    #define PWMCNT7                     _PWMCNT67.Overlap_STR.PWMCNT7STR.Byte
    
    

  } Overlap_STR;

} PWMCNT67STR;
extern volatile PWMCNT67STR _PWMCNT67 @(REG_BASE + 0x00000312);
#define PWMCNT67                        _PWMCNT67.Word



 PWMPER01 - PWM Channel Period 01 Register; 0x00000314 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMPER0 - PWM Channel Period 0 Register; 0x00000314 
    union {
      byte Byte;
    } PWMPER0STR;
    #define PWMPER0                     _PWMPER01.Overlap_STR.PWMPER0STR.Byte
    
     PWMPER_ARR Access 8 PWMPERx registers in an array 
    #define PWMPER_ARR                  ((volatile byte ) &PWMPER0)
    


     PWMPER1 - PWM Channel Period 1 Register; 0x00000315 
    union {
      byte Byte;
    } PWMPER1STR;
    #define PWMPER1                     _PWMPER01.Overlap_STR.PWMPER1STR.Byte
    
    

  } Overlap_STR;

} PWMPER01STR;
extern volatile PWMPER01STR _PWMPER01 @(REG_BASE + 0x00000314);
#define PWMPER01                        _PWMPER01.Word



 PWMPER23 - PWM Channel Period 23 Register; 0x00000316 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMPER2 - PWM Channel Period 2 Register; 0x00000316 
    union {
      byte Byte;
    } PWMPER2STR;
    #define PWMPER2                     _PWMPER23.Overlap_STR.PWMPER2STR.Byte
    
    


     PWMPER3 - PWM Channel Period 3 Register; 0x00000317 
    union {
      byte Byte;
    } PWMPER3STR;
    #define PWMPER3                     _PWMPER23.Overlap_STR.PWMPER3STR.Byte
    
    

  } Overlap_STR;

} PWMPER23STR;
extern volatile PWMPER23STR _PWMPER23 @(REG_BASE + 0x00000316);
#define PWMPER23                        _PWMPER23.Word



 PWMPER45 - PWM Channel Period 45 Register; 0x00000318 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMPER4 - PWM Channel Period 4 Register; 0x00000318 
    union {
      byte Byte;
    } PWMPER4STR;
    #define PWMPER4                     _PWMPER45.Overlap_STR.PWMPER4STR.Byte
    
    


     PWMPER5 - PWM Channel Period 5 Register; 0x00000319 
    union {
      byte Byte;
    } PWMPER5STR;
    #define PWMPER5                     _PWMPER45.Overlap_STR.PWMPER5STR.Byte
    
    

  } Overlap_STR;

} PWMPER45STR;
extern volatile PWMPER45STR _PWMPER45 @(REG_BASE + 0x00000318);
#define PWMPER45                        _PWMPER45.Word



 PWMPER67 - PWM Channel Period 67 Register; 0x0000031A 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMPER6 - PWM Channel Period 6 Register; 0x0000031A 
    union {
      byte Byte;
    } PWMPER6STR;
    #define PWMPER6                     _PWMPER67.Overlap_STR.PWMPER6STR.Byte
    
    


     PWMPER7 - PWM Channel Period 7 Register; 0x0000031B 
    union {
      byte Byte;
    } PWMPER7STR;
    #define PWMPER7                     _PWMPER67.Overlap_STR.PWMPER7STR.Byte
    
    

  } Overlap_STR;

} PWMPER67STR;
extern volatile PWMPER67STR _PWMPER67 @(REG_BASE + 0x0000031A);
#define PWMPER67                        _PWMPER67.Word



 PWMDTY01 - PWM Channel Duty 01 Register; 0x0000031C 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMDTY0 - PWM Channel Duty 0 Register; 0x0000031C 
    union {
      byte Byte;
    } PWMDTY0STR;
    #define PWMDTY0                     _PWMDTY01.Overlap_STR.PWMDTY0STR.Byte
    
     PWMDTY_ARR Access 8 PWMDTYx registers in an array 
    #define PWMDTY_ARR                  ((volatile byte ) &PWMDTY0)
    


     PWMDTY1 - PWM Channel Duty 1 Register; 0x0000031D 
    union {
      byte Byte;
    } PWMDTY1STR;
    #define PWMDTY1                     _PWMDTY01.Overlap_STR.PWMDTY1STR.Byte
    
    

  } Overlap_STR;

} PWMDTY01STR;
extern volatile PWMDTY01STR _PWMDTY01 @(REG_BASE + 0x0000031C);
#define PWMDTY01                        _PWMDTY01.Word



 PWMDTY23 - PWM Channel Duty 23 Register; 0x0000031E 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMDTY2 - PWM Channel Duty 2 Register; 0x0000031E 
    union {
      byte Byte;
    } PWMDTY2STR;
    #define PWMDTY2                     _PWMDTY23.Overlap_STR.PWMDTY2STR.Byte
    
    


     PWMDTY3 - PWM Channel Duty 3 Register; 0x0000031F 
    union {
      byte Byte;
    } PWMDTY3STR;
    #define PWMDTY3                     _PWMDTY23.Overlap_STR.PWMDTY3STR.Byte
    
    

  } Overlap_STR;

} PWMDTY23STR;
extern volatile PWMDTY23STR _PWMDTY23 @(REG_BASE + 0x0000031E);
#define PWMDTY23                        _PWMDTY23.Word



 PWMDTY45 - PWM Channel Duty 45 Register; 0x00000320 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMDTY4 - PWM Channel Duty 4 Register; 0x00000320 
    union {
      byte Byte;
    } PWMDTY4STR;
    #define PWMDTY4                     _PWMDTY45.Overlap_STR.PWMDTY4STR.Byte
    
    


     PWMDTY5 - PWM Channel Duty 5 Register; 0x00000321 
    union {
      byte Byte;
    } PWMDTY5STR;
    #define PWMDTY5                     _PWMDTY45.Overlap_STR.PWMDTY5STR.Byte
    
    

  } Overlap_STR;

} PWMDTY45STR;
extern volatile PWMDTY45STR _PWMDTY45 @(REG_BASE + 0x00000320);
#define PWMDTY45                        _PWMDTY45.Word



 PWMDTY67 - PWM Channel Duty 67 Register; 0x00000322 
typedef union {
  word Word;
    Overlapped registers 
  struct {
     PWMDTY6 - PWM Channel Duty 6 Register; 0x00000322 
    union {
      byte Byte;
    } PWMDTY6STR;
    #define PWMDTY6                     _PWMDTY67.Overlap_STR.PWMDTY6STR.Byte
    
    


     PWMDTY7 - PWM Channel Duty 7 Register; 0x00000323 
    union {
      byte Byte;
    } PWMDTY7STR;
    #define PWMDTY7                     _PWMDTY67.Overlap_STR.PWMDTY7STR.Byte
    
    

  } Overlap_STR;

} PWMDTY67STR;
extern volatile PWMDTY67STR _PWMDTY67 @(REG_BASE + 0x00000322);
#define PWMDTY67                        _PWMDTY67.Word



 PWMSDN - PWM Shutdown Register; 0x00000324 
typedef union {
  byte Byte;
  struct {
    byte PWM7ENA     1;                                        PWM emergency shutdown Enable 
    byte PWM7INL     1;                                        PWM shutdown active input level for ch. 7 
    byte PWM7IN      1;                                        PWM channel 7 input status 
    byte             1; 
    byte PWMLVL      1;                                        PWM shutdown output Level 
    byte PWMRSTRT    1;                                        PWM Restart 
    byte PWMIE       1;                                        PWM Interrupt Enable 
    byte PWMIF       1;                                        PWM Interrupt Flag 
  } Bits;
} PWMSDNSTR;
extern volatile PWMSDNSTR _PWMSDN @(REG_BASE + 0x00000324);
#define PWMSDN                          _PWMSDN.Byte
#define PWMSDN_PWM7ENA                  _PWMSDN.Bits.PWM7ENA
#define PWMSDN_PWM7INL                  _PWMSDN.Bits.PWM7INL
#define PWMSDN_PWM7IN                   _PWMSDN.Bits.PWM7IN
#define PWMSDN_PWMLVL                   _PWMSDN.Bits.PWMLVL
#define PWMSDN_PWMRSTRT                 _PWMSDN.Bits.PWMRSTRT
#define PWMSDN_PWMIE                    _PWMSDN.Bits.PWMIE
#define PWMSDN_PWMIF                    _PWMSDN.Bits.PWMIF

#define PWMSDN_PWM7ENA_MASK             1
#define PWMSDN_PWM7INL_MASK             2
#define PWMSDN_PWM7IN_MASK              4
#define PWMSDN_PWMLVL_MASK              16
#define PWMSDN_PWMRSTRT_MASK            32
#define PWMSDN_PWMIE_MASK               64
#define PWMSDN_PWMIF_MASK               128


 PITCFLMT - PIT Control and Force Load Micro Timer Register; 0x00000340 
typedef union {
  byte Byte;
  struct {
    byte PFLMT0      1;                                        PIT Force Load Bits for Micro Timer 0 
    byte PFLMT1      1;                                        PIT Force Load Bits for Micro Timer 1 
    byte             1; 
    byte             1; 
    byte             1; 
    byte PITFRZ      1;                                        PIT Counter Freeze while in Freeze Mode Bit 
    byte PITSWAI     1;                                        PIT Stop in Wait Mode Bit 
    byte PITE        1;                                        PIT Module Enable Bit 
  } Bits;
  struct {
    byte grpPFLMT 2;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} PITCFLMTSTR;
extern volatile PITCFLMTSTR _PITCFLMT @(REG_BASE + 0x00000340);
#define PITCFLMT                        _PITCFLMT.Byte
#define PITCFLMT_PFLMT0                 _PITCFLMT.Bits.PFLMT0
#define PITCFLMT_PFLMT1                 _PITCFLMT.Bits.PFLMT1
#define PITCFLMT_PITFRZ                 _PITCFLMT.Bits.PITFRZ
#define PITCFLMT_PITSWAI                _PITCFLMT.Bits.PITSWAI
#define PITCFLMT_PITE                   _PITCFLMT.Bits.PITE
#define PITCFLMT_PFLMT                  _PITCFLMT.MergedBits.grpPFLMT

#define PITCFLMT_PFLMT0_MASK            1
#define PITCFLMT_PFLMT1_MASK            2
#define PITCFLMT_PITFRZ_MASK            32
#define PITCFLMT_PITSWAI_MASK           64
#define PITCFLMT_PITE_MASK              128
#define PITCFLMT_PFLMT_MASK             3
#define PITCFLMT_PFLMT_BITNUM           0


 PITFLT - PIT Force Load Timer Register; 0x00000341 
typedef union {
  byte Byte;
  struct {
    byte PFLT0       1;                                        PIT Force Load Bits for Timer 0 
    byte PFLT1       1;                                        PIT Force Load Bits for Timer 1 
    byte PFLT2       1;                                        PIT Force Load Bits for Timer 2 
    byte PFLT3       1;                                        PIT Force Load Bits for Timer 3 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpPFLT 4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} PITFLTSTR;
extern volatile PITFLTSTR _PITFLT @(REG_BASE + 0x00000341);
#define PITFLT                          _PITFLT.Byte
#define PITFLT_PFLT0                    _PITFLT.Bits.PFLT0
#define PITFLT_PFLT1                    _PITFLT.Bits.PFLT1
#define PITFLT_PFLT2                    _PITFLT.Bits.PFLT2
#define PITFLT_PFLT3                    _PITFLT.Bits.PFLT3
#define PITFLT_PFLT                     _PITFLT.MergedBits.grpPFLT

#define PITFLT_PFLT0_MASK               1
#define PITFLT_PFLT1_MASK               2
#define PITFLT_PFLT2_MASK               4
#define PITFLT_PFLT3_MASK               8
#define PITFLT_PFLT_MASK                15
#define PITFLT_PFLT_BITNUM              0


 PITCE - PIT Channel Enable Register; 0x00000342 
typedef union {
  byte Byte;
  struct {
    byte PCE0        1;                                        PIT Enable Bits for Timer Channel 0 
    byte PCE1        1;                                        PIT Enable Bits for Timer Channel 1 
    byte PCE2        1;                                        PIT Enable Bits for Timer Channel 2 
    byte PCE3        1;                                        PIT Enable Bits for Timer Channel 3 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpPCE  4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} PITCESTR;
extern volatile PITCESTR _PITCE @(REG_BASE + 0x00000342);
#define PITCE                           _PITCE.Byte
#define PITCE_PCE0                      _PITCE.Bits.PCE0
#define PITCE_PCE1                      _PITCE.Bits.PCE1
#define PITCE_PCE2                      _PITCE.Bits.PCE2
#define PITCE_PCE3                      _PITCE.Bits.PCE3
#define PITCE_PCE                       _PITCE.MergedBits.grpPCE

#define PITCE_PCE0_MASK                 1
#define PITCE_PCE1_MASK                 2
#define PITCE_PCE2_MASK                 4
#define PITCE_PCE3_MASK                 8
#define PITCE_PCE_MASK                  15
#define PITCE_PCE_BITNUM                0


 PITMUX - PIT Multiplex Register; 0x00000343 
typedef union {
  byte Byte;
  struct {
    byte PMUX0       1;                                        PIT Multiplex Bits for Timer Channel 0 
    byte PMUX1       1;                                        PIT Multiplex Bits for Timer Channel 1 
    byte PMUX2       1;                                        PIT Multiplex Bits for Timer Channel 2 
    byte PMUX3       1;                                        PIT Multiplex Bits for Timer Channel 3 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpPMUX 4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} PITMUXSTR;
extern volatile PITMUXSTR _PITMUX @(REG_BASE + 0x00000343);
#define PITMUX                          _PITMUX.Byte
#define PITMUX_PMUX0                    _PITMUX.Bits.PMUX0
#define PITMUX_PMUX1                    _PITMUX.Bits.PMUX1
#define PITMUX_PMUX2                    _PITMUX.Bits.PMUX2
#define PITMUX_PMUX3                    _PITMUX.Bits.PMUX3
#define PITMUX_PMUX                     _PITMUX.MergedBits.grpPMUX

#define PITMUX_PMUX0_MASK               1
#define PITMUX_PMUX1_MASK               2
#define PITMUX_PMUX2_MASK               4
#define PITMUX_PMUX3_MASK               8
#define PITMUX_PMUX_MASK                15
#define PITMUX_PMUX_BITNUM              0


 PITINTE - PIT Interrupt Enable Register; 0x00000344 
typedef union {
  byte Byte;
  struct {
    byte PINTE0      1;                                        PIT Time-out Interrupt Enable Bits for Timer Channel 0 
    byte PINTE1      1;                                        PIT Time-out Interrupt Enable Bits for Timer Channel 1 
    byte PINTE2      1;                                        PIT Time-out Interrupt Enable Bits for Timer Channel 2 
    byte PINTE3      1;                                        PIT Time-out Interrupt Enable Bits for Timer Channel 3 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpPINTE 4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} PITINTESTR;
extern volatile PITINTESTR _PITINTE @(REG_BASE + 0x00000344);
#define PITINTE                         _PITINTE.Byte
#define PITINTE_PINTE0                  _PITINTE.Bits.PINTE0
#define PITINTE_PINTE1                  _PITINTE.Bits.PINTE1
#define PITINTE_PINTE2                  _PITINTE.Bits.PINTE2
#define PITINTE_PINTE3                  _PITINTE.Bits.PINTE3
#define PITINTE_PINTE                   _PITINTE.MergedBits.grpPINTE

#define PITINTE_PINTE0_MASK             1
#define PITINTE_PINTE1_MASK             2
#define PITINTE_PINTE2_MASK             4
#define PITINTE_PINTE3_MASK             8
#define PITINTE_PINTE_MASK              15
#define PITINTE_PINTE_BITNUM            0


 PITTF - PIT Time-out Flag Register; 0x00000345 
typedef union {
  byte Byte;
  struct {
    byte PTF0        1;                                        PIT Time-out Flag Bits for Timer Channel 0 
    byte PTF1        1;                                        PIT Time-out Flag Bits for Timer Channel 1 
    byte PTF2        1;                                        PIT Time-out Flag Bits for Timer Channel 2 
    byte PTF3        1;                                        PIT Time-out Flag Bits for Timer Channel 3 
    byte             1; 
    byte             1; 
    byte             1; 
    byte             1; 
  } Bits;
  struct {
    byte grpPTF  4;
    byte         1;
    byte         1;
    byte         1;
    byte         1;
  } MergedBits;
} PITTFSTR;
extern volatile PITTFSTR _PITTF @(REG_BASE + 0x00000345);
#define PITTF                           _PITTF.Byte
#define PITTF_PTF0                      _PITTF.Bits.PTF0
#define PITTF_PTF1                      _PITTF.Bits.PTF1
#define PITTF_PTF2                      _PITTF.Bits.PTF2
#define PITTF_PTF3                      _PITTF.Bits.PTF3
#define PITTF_PTF                       _PITTF.MergedBits.grpPTF

#define PITTF_PTF0_MASK                 1
#define PITTF_PTF1_MASK                 2
#define PITTF_PTF2_MASK                 4
#define PITTF_PTF3_MASK                 8
#define PITTF_PTF_MASK                  15
#define PITTF_PTF_BITNUM                0


 PITMTLD0 - PIT Micro Timer Load Register 0; 0x00000346 
typedef union {
  byte Byte;
  struct {
    byte PMTLD0      1;                                        PIT Micro Timer Load Bit 0 
    byte PMTLD1      1;                                        PIT Micro Timer Load Bit 1 
    byte PMTLD2      1;                                        PIT Micro Timer Load Bit 2 
    byte PMTLD3      1;                                        PIT Micro Timer Load Bit 3 
    byte PMTLD4      1;                                        PIT Micro Timer Load Bit 4 
    byte PMTLD5      1;                                        PIT Micro Timer Load Bit 5 
    byte PMTLD6      1;                                        PIT Micro Timer Load Bit 6 
    byte PMTLD7      1;                                        PIT Micro Timer Load Bit 7 
  } Bits;
} PITMTLD0STR;
extern volatile PITMTLD0STR _PITMTLD0 @(REG_BASE + 0x00000346);
#define PITMTLD0                        _PITMTLD0.Byte
#define PITMTLD0_PMTLD0                 _PITMTLD0.Bits.PMTLD0
#define PITMTLD0_PMTLD1                 _PITMTLD0.Bits.PMTLD1
#define PITMTLD0_PMTLD2                 _PITMTLD0.Bits.PMTLD2
#define PITMTLD0_PMTLD3                 _PITMTLD0.Bits.PMTLD3
#define PITMTLD0_PMTLD4                 _PITMTLD0.Bits.PMTLD4
#define PITMTLD0_PMTLD5                 _PITMTLD0.Bits.PMTLD5
#define PITMTLD0_PMTLD6                 _PITMTLD0.Bits.PMTLD6
#define PITMTLD0_PMTLD7                 _PITMTLD0.Bits.PMTLD7
 PITMTLD_ARR Access 2 PITMTLDx registers in an array 
#define PITMTLD_ARR                     ((volatile byte ) &PITMTLD0)

#define PITMTLD0_PMTLD0_MASK            1
#define PITMTLD0_PMTLD1_MASK            2
#define PITMTLD0_PMTLD2_MASK            4
#define PITMTLD0_PMTLD3_MASK            8
#define PITMTLD0_PMTLD4_MASK            16
#define PITMTLD0_PMTLD5_MASK            32
#define PITMTLD0_PMTLD6_MASK            64
#define PITMTLD0_PMTLD7_MASK            128


 PITMTLD1 - PIT Micro Timer Load Register 1; 0x00000347 
typedef union {
  byte Byte;
  struct {
    byte PMTLD0      1;                                        PIT Micro Timer Load Bit 0 
    byte PMTLD1      1;                                        PIT Micro Timer Load Bit 1 
    byte PMTLD2      1;                                        PIT Micro Timer Load Bit 2 
    byte PMTLD3      1;                                        PIT Micro Timer Load Bit 3 
    byte PMTLD4      1;                                        PIT Micro Timer Load Bit 4 
    byte PMTLD5      1;                                        PIT Micro Timer Load Bit 5 
    byte PMTLD6      1;                                        PIT Micro Timer Load Bit 6 
    byte PMTLD7      1;                                        PIT Micro Timer Load Bit 7 
  } Bits;
} PITMTLD1STR;
extern volatile PITMTLD1STR _PITMTLD1 @(REG_BASE + 0x00000347);
#define PITMTLD1                        _PITMTLD1.Byte
#define PITMTLD1_PMTLD0                 _PITMTLD1.Bits.PMTLD0
#define PITMTLD1_PMTLD1                 _PITMTLD1.Bits.PMTLD1
#define PITMTLD1_PMTLD2                 _PITMTLD1.Bits.PMTLD2
#define PITMTLD1_PMTLD3                 _PITMTLD1.Bits.PMTLD3
#define PITMTLD1_PMTLD4                 _PITMTLD1.Bits.PMTLD4
#define PITMTLD1_PMTLD5                 _PITMTLD1.Bits.PMTLD5
#define PITMTLD1_PMTLD6                 _PITMTLD1.Bits.PMTLD6
#define PITMTLD1_PMTLD7                 _PITMTLD1.Bits.PMTLD7

#define PITMTLD1_PMTLD0_MASK            1
#define PITMTLD1_PMTLD1_MASK            2
#define PITMTLD1_PMTLD2_MASK            4
#define PITMTLD1_PMTLD3_MASK            8
#define PITMTLD1_PMTLD4_MASK            16
#define PITMTLD1_PMTLD5_MASK            32
#define PITMTLD1_PMTLD6_MASK            64
#define PITMTLD1_PMTLD7_MASK            128


 PITLD0 - PIT Load Register 0; 0x00000348 
typedef union {
  word Word;
} PITLD0STR;
extern volatile PITLD0STR _PITLD0 @(REG_BASE + 0x00000348);
#define PITLD0                          _PITLD0.Word



 PITCNT0 - PIT Count Register 0; 0x0000034A 
typedef union {
  word Word;
} PITCNT0STR;
extern volatile PITCNT0STR _PITCNT0 @(REG_BASE + 0x0000034A);
#define PITCNT0                         _PITCNT0.Word



 PITLD1 - PIT Load Register 1; 0x0000034C 
typedef union {
  word Word;
} PITLD1STR;
extern volatile PITLD1STR _PITLD1 @(REG_BASE + 0x0000034C);
#define PITLD1                          _PITLD1.Word



 PITCNT1 - PIT Count Register 1; 0x0000034E 
typedef union {
  word Word;
} PITCNT1STR;
extern volatile PITCNT1STR _PITCNT1 @(REG_BASE + 0x0000034E);
#define PITCNT1                         _PITCNT1.Word



 PITLD2 - PIT Load Register 2; 0x00000350 
typedef union {
  word Word;
} PITLD2STR;
extern volatile PITLD2STR _PITLD2 @(REG_BASE + 0x00000350);
#define PITLD2                          _PITLD2.Word



 PITCNT2 - PIT Count Register 2; 0x00000352 
typedef union {
  word Word;
} PITCNT2STR;
extern volatile PITCNT2STR _PITCNT2 @(REG_BASE + 0x00000352);
#define PITCNT2                         _PITCNT2.Word



 PITLD3 - PIT Load Register 3; 0x00000354 
typedef union {
  word Word;
} PITLD3STR;
extern volatile PITLD3STR _PITLD3 @(REG_BASE + 0x00000354);
#define PITLD3                          _PITLD3.Word



 PITCNT3 - PIT Count Register 3; 0x00000356 
typedef union {
  word Word;
} PITCNT3STR;
extern volatile PITCNT3STR _PITCNT3 @(REG_BASE + 0x00000356);
#define PITCNT3                         _PITCNT3.Word



 XGMCTL - XGATE Module Control Register; 0x00000380 
typedef union {
  word Word;
  struct {
    word XGIE        1;                                        XGATE Interrupt Enable 
    word XGSWEIF     1;                                        XGATE Software Error Interrupt Flag 
    word             1; 
    word XGFACT      1;                                        Fake XGATE Activity 
    word XGSS        1;                                        XGATE Single Step 
    word XGDBG       1;                                        XGATE Debug Mode 
    word XGFRZ       1;                                        Halt XGATE in Freeze Mode 
    word XGE         1;                                        XGATE Module Enable 
    word XGIEM       1;                                        XGIE Mask 
    word XGSWEIFM    1;                                        XGSWEIF Mask 
    word             1; 
    word XGFACTM     1;                                        XGFACT Mask 
    word XGSSM       1;                                        XGSS Mask 
    word XGDBGM      1;                                        XGDBG Mask 
    word XGFRZM      1;                                        XGFRZ Mask 
    word XGEM        1;                                        XGE Mask 
  } Bits;
} XGMCTLSTR;
extern volatile XGMCTLSTR _XGMCTL @(REG_BASE + 0x00000380);
#define XGMCTL                          _XGMCTL.Word
#define XGMCTL_XGIE                     _XGMCTL.Bits.XGIE
#define XGMCTL_XGSWEIF                  _XGMCTL.Bits.XGSWEIF
#define XGMCTL_XGFACT                   _XGMCTL.Bits.XGFACT
#define XGMCTL_XGSS                     _XGMCTL.Bits.XGSS
#define XGMCTL_XGDBG                    _XGMCTL.Bits.XGDBG
#define XGMCTL_XGFRZ                    _XGMCTL.Bits.XGFRZ
#define XGMCTL_XGE                      _XGMCTL.Bits.XGE
#define XGMCTL_XGIEM                    _XGMCTL.Bits.XGIEM
#define XGMCTL_XGSWEIFM                 _XGMCTL.Bits.XGSWEIFM
#define XGMCTL_XGFACTM                  _XGMCTL.Bits.XGFACTM
#define XGMCTL_XGSSM                    _XGMCTL.Bits.XGSSM
#define XGMCTL_XGDBGM                   _XGMCTL.Bits.XGDBGM
#define XGMCTL_XGFRZM                   _XGMCTL.Bits.XGFRZM
#define XGMCTL_XGEM                     _XGMCTL.Bits.XGEM

#define XGMCTL_XGIE_MASK                1
#define XGMCTL_XGSWEIF_MASK             2
#define XGMCTL_XGFACT_MASK              8
#define XGMCTL_XGSS_MASK                16
#define XGMCTL_XGDBG_MASK               32
#define XGMCTL_XGFRZ_MASK               64
#define XGMCTL_XGE_MASK                 128
#define XGMCTL_XGIEM_MASK               256
#define XGMCTL_XGSWEIFM_MASK            512
#define XGMCTL_XGFACTM_MASK             2048
#define XGMCTL_XGSSM_MASK               4096
#define XGMCTL_XGDBGM_MASK              8192
#define XGMCTL_XGFRZM_MASK              16384
#define XGMCTL_XGEM_MASK                32768


 XGCHID - XGATE Channel ID Register; 0x00000382 
typedef union {
  byte Byte;
  struct {
    byte XGCHIDGrp   7;                                        Request Identifier 
    byte             1; 
  } Bits;
} XGCHIDSTR;
extern volatile XGCHIDSTR _XGCHID @(REG_BASE + 0x00000382);
#define XGCHID                          _XGCHID.Byte
#define XGCHID_XGCHIDGrp                _XGCHID.Bits.XGCHIDGrp

#define XGCHID_XGCHIDGrp_MASK           127
#define XGCHID_XGCHIDGrp_BITNUM         0


 XGVBR - XGATE Vector Base Address Register; 0x00000386 
typedef union {
  word Word;
  struct {
    word             1; 
    word XGVBRGrp    15;                                       Vector Base Address 
  } Bits;
} XGVBRSTR;
extern volatile XGVBRSTR _XGVBR @(REG_BASE + 0x00000386);
#define XGVBR                           _XGVBR.Word
#define XGVBR_XGVBRGrp                  _XGVBR.Bits.XGVBRGrp

#define XGVBR_XGVBRGrp_MASK             65534
#define XGVBR_XGVBRGrp_BITNUM           1


 XGIF0 - XGATE Channel Interrupt Flag Vector 0; 0x00000388 
typedef union {
  word Word;
  struct {
    word XGIF_70     1;                                        Channel Interrupt Flag 70 
    word XGIF_71     1;                                        Channel Interrupt Flag 71 
    word XGIF_72     1;                                        Channel Interrupt Flag 72 
    word XGIF_73     1;                                        Channel Interrupt Flag 73 
    word XGIF_74     1;                                        Channel Interrupt Flag 74 
    word XGIF_75     1;                                        Channel Interrupt Flag 75 
    word XGIF_76     1;                                        Channel Interrupt Flag 76 
    word XGIF_77     1;                                        Channel Interrupt Flag 77 
    word XGIF_78     1;                                        Channel Interrupt Flag 78 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
  } Bits;
  struct {
    word grpXGIF__70 9;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} XGIF0STR;
extern volatile XGIF0STR _XGIF0 @(REG_BASE + 0x00000388);
#define XGIF0                           _XGIF0.Word
#define XGIF0_XGIF_70                   _XGIF0.Bits.XGIF_70
#define XGIF0_XGIF_71                   _XGIF0.Bits.XGIF_71
#define XGIF0_XGIF_72                   _XGIF0.Bits.XGIF_72
#define XGIF0_XGIF_73                   _XGIF0.Bits.XGIF_73
#define XGIF0_XGIF_74                   _XGIF0.Bits.XGIF_74
#define XGIF0_XGIF_75                   _XGIF0.Bits.XGIF_75
#define XGIF0_XGIF_76                   _XGIF0.Bits.XGIF_76
#define XGIF0_XGIF_77                   _XGIF0.Bits.XGIF_77
#define XGIF0_XGIF_78                   _XGIF0.Bits.XGIF_78
 XGIF_ARR Access 8 XGIFx registers in an array 
#define XGIF_ARR                        ((volatile word ) &XGIF0)
#define XGIF0_XGIF__70                  _XGIF0.MergedBits.grpXGIF__70
#define XGIF0_XGIF_                     XGIF0_XGIF__70

#define XGIF0_XGIF_70_MASK              1
#define XGIF0_XGIF_71_MASK              2
#define XGIF0_XGIF_72_MASK              4
#define XGIF0_XGIF_73_MASK              8
#define XGIF0_XGIF_74_MASK              16
#define XGIF0_XGIF_75_MASK              32
#define XGIF0_XGIF_76_MASK              64
#define XGIF0_XGIF_77_MASK              128
#define XGIF0_XGIF_78_MASK              256
#define XGIF0_XGIF__70_MASK             511
#define XGIF0_XGIF__70_BITNUM           0


 XGIF1 - XGATE Channel Interrupt Flag Vector 1; 0x0000038A 
typedef union {
  word Word;
  struct {
    word XGIF_60     1;                                        Channel Interrupt Flag 60 
    word XGIF_61     1;                                        Channel Interrupt Flag 61 
    word XGIF_62     1;                                        Channel Interrupt Flag 62 
    word XGIF_63     1;                                        Channel Interrupt Flag 63 
    word XGIF_64     1;                                        Channel Interrupt Flag 64 
    word XGIF_65     1;                                        Channel Interrupt Flag 65 
    word XGIF_66     1;                                        Channel Interrupt Flag 66 
    word XGIF_67     1;                                        Channel Interrupt Flag 67 
    word XGIF_68     1;                                        Channel Interrupt Flag 68 
    word XGIF_69     1;                                        Channel Interrupt Flag 69 
    word XGIF_6A     1;                                        Channel Interrupt Flag 6A 
    word XGIF_6B     1;                                        Channel Interrupt Flag 6B 
    word XGIF_6C     1;                                        Channel Interrupt Flag 6C 
    word XGIF_6D     1;                                        Channel Interrupt Flag 6D 
    word XGIF_6E     1;                                        Channel Interrupt Flag 6E 
    word XGIF_6F     1;                                        Channel Interrupt Flag 6F 
  } Bits;
  struct {
    word grpXGIF__60 10;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} XGIF1STR;
extern volatile XGIF1STR _XGIF1 @(REG_BASE + 0x0000038A);
#define XGIF1                           _XGIF1.Word
#define XGIF1_XGIF_60                   _XGIF1.Bits.XGIF_60
#define XGIF1_XGIF_61                   _XGIF1.Bits.XGIF_61
#define XGIF1_XGIF_62                   _XGIF1.Bits.XGIF_62
#define XGIF1_XGIF_63                   _XGIF1.Bits.XGIF_63
#define XGIF1_XGIF_64                   _XGIF1.Bits.XGIF_64
#define XGIF1_XGIF_65                   _XGIF1.Bits.XGIF_65
#define XGIF1_XGIF_66                   _XGIF1.Bits.XGIF_66
#define XGIF1_XGIF_67                   _XGIF1.Bits.XGIF_67
#define XGIF1_XGIF_68                   _XGIF1.Bits.XGIF_68
#define XGIF1_XGIF_69                   _XGIF1.Bits.XGIF_69
#define XGIF1_XGIF_6A                   _XGIF1.Bits.XGIF_6A
#define XGIF1_XGIF_6B                   _XGIF1.Bits.XGIF_6B
#define XGIF1_XGIF_6C                   _XGIF1.Bits.XGIF_6C
#define XGIF1_XGIF_6D                   _XGIF1.Bits.XGIF_6D
#define XGIF1_XGIF_6E                   _XGIF1.Bits.XGIF_6E
#define XGIF1_XGIF_6F                   _XGIF1.Bits.XGIF_6F
#define XGIF1_XGIF__60                  _XGIF1.MergedBits.grpXGIF__60
#define XGIF1_XGIF_                     XGIF1_XGIF__60

#define XGIF1_XGIF_60_MASK              1
#define XGIF1_XGIF_61_MASK              2
#define XGIF1_XGIF_62_MASK              4
#define XGIF1_XGIF_63_MASK              8
#define XGIF1_XGIF_64_MASK              16
#define XGIF1_XGIF_65_MASK              32
#define XGIF1_XGIF_66_MASK              64
#define XGIF1_XGIF_67_MASK              128
#define XGIF1_XGIF_68_MASK              256
#define XGIF1_XGIF_69_MASK              512
#define XGIF1_XGIF_6A_MASK              1024
#define XGIF1_XGIF_6B_MASK              2048
#define XGIF1_XGIF_6C_MASK              4096
#define XGIF1_XGIF_6D_MASK              8192
#define XGIF1_XGIF_6E_MASK              16384
#define XGIF1_XGIF_6F_MASK              32768
#define XGIF1_XGIF__60_MASK             1023
#define XGIF1_XGIF__60_BITNUM           0


 XGIF2 - XGATE Channel Interrupt Flag Vector 2; 0x0000038C 
typedef union {
  word Word;
  struct {
    word XGIF_50     1;                                        Channel Interrupt Flag 50 
    word XGIF_51     1;                                        Channel Interrupt Flag 51 
    word XGIF_52     1;                                        Channel Interrupt Flag 52 
    word XGIF_53     1;                                        Channel Interrupt Flag 53 
    word XGIF_54     1;                                        Channel Interrupt Flag 54 
    word XGIF_55     1;                                        Channel Interrupt Flag 55 
    word XGIF_56     1;                                        Channel Interrupt Flag 56 
    word XGIF_57     1;                                        Channel Interrupt Flag 57 
    word XGIF_58     1;                                        Channel Interrupt Flag 58 
    word XGIF_59     1;                                        Channel Interrupt Flag 59 
    word XGIF_5A     1;                                        Channel Interrupt Flag 5A 
    word XGIF_5B     1;                                        Channel Interrupt Flag 5B 
    word XGIF_5C     1;                                        Channel Interrupt Flag 5C 
    word XGIF_5D     1;                                        Channel Interrupt Flag 5D 
    word XGIF_5E     1;                                        Channel Interrupt Flag 5E 
    word XGIF_5F     1;                                        Channel Interrupt Flag 5F 
  } Bits;
  struct {
    word grpXGIF__50 10;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} XGIF2STR;
extern volatile XGIF2STR _XGIF2 @(REG_BASE + 0x0000038C);
#define XGIF2                           _XGIF2.Word
#define XGIF2_XGIF_50                   _XGIF2.Bits.XGIF_50
#define XGIF2_XGIF_51                   _XGIF2.Bits.XGIF_51
#define XGIF2_XGIF_52                   _XGIF2.Bits.XGIF_52
#define XGIF2_XGIF_53                   _XGIF2.Bits.XGIF_53
#define XGIF2_XGIF_54                   _XGIF2.Bits.XGIF_54
#define XGIF2_XGIF_55                   _XGIF2.Bits.XGIF_55
#define XGIF2_XGIF_56                   _XGIF2.Bits.XGIF_56
#define XGIF2_XGIF_57                   _XGIF2.Bits.XGIF_57
#define XGIF2_XGIF_58                   _XGIF2.Bits.XGIF_58
#define XGIF2_XGIF_59                   _XGIF2.Bits.XGIF_59
#define XGIF2_XGIF_5A                   _XGIF2.Bits.XGIF_5A
#define XGIF2_XGIF_5B                   _XGIF2.Bits.XGIF_5B
#define XGIF2_XGIF_5C                   _XGIF2.Bits.XGIF_5C
#define XGIF2_XGIF_5D                   _XGIF2.Bits.XGIF_5D
#define XGIF2_XGIF_5E                   _XGIF2.Bits.XGIF_5E
#define XGIF2_XGIF_5F                   _XGIF2.Bits.XGIF_5F
#define XGIF2_XGIF__50                  _XGIF2.MergedBits.grpXGIF__50
#define XGIF2_XGIF_                     XGIF2_XGIF__50

#define XGIF2_XGIF_50_MASK              1
#define XGIF2_XGIF_51_MASK              2
#define XGIF2_XGIF_52_MASK              4
#define XGIF2_XGIF_53_MASK              8
#define XGIF2_XGIF_54_MASK              16
#define XGIF2_XGIF_55_MASK              32
#define XGIF2_XGIF_56_MASK              64
#define XGIF2_XGIF_57_MASK              128
#define XGIF2_XGIF_58_MASK              256
#define XGIF2_XGIF_59_MASK              512
#define XGIF2_XGIF_5A_MASK              1024
#define XGIF2_XGIF_5B_MASK              2048
#define XGIF2_XGIF_5C_MASK              4096
#define XGIF2_XGIF_5D_MASK              8192
#define XGIF2_XGIF_5E_MASK              16384
#define XGIF2_XGIF_5F_MASK              32768
#define XGIF2_XGIF__50_MASK             1023
#define XGIF2_XGIF__50_BITNUM           0


 XGIF3 - XGATE Channel Interrupt Flag Vector 3; 0x0000038E 
typedef union {
  word Word;
  struct {
    word XGIF_40     1;                                        Channel Interrupt Flag 40 
    word XGIF_41     1;                                        Channel Interrupt Flag 41 
    word XGIF_42     1;                                        Channel Interrupt Flag 42 
    word XGIF_43     1;                                        Channel Interrupt Flag 43 
    word XGIF_44     1;                                        Channel Interrupt Flag 44 
    word XGIF_45     1;                                        Channel Interrupt Flag 45 
    word XGIF_46     1;                                        Channel Interrupt Flag 46 
    word XGIF_47     1;                                        Channel Interrupt Flag 47 
    word XGIF_48     1;                                        Channel Interrupt Flag 48 
    word XGIF_49     1;                                        Channel Interrupt Flag 49 
    word XGIF_4A     1;                                        Channel Interrupt Flag 4A 
    word XGIF_4B     1;                                        Channel Interrupt Flag 4B 
    word XGIF_4C     1;                                        Channel Interrupt Flag 4C 
    word XGIF_4D     1;                                        Channel Interrupt Flag 4D 
    word XGIF_4E     1;                                        Channel Interrupt Flag 4E 
    word XGIF_4F     1;                                        Channel Interrupt Flag 4F 
  } Bits;
  struct {
    word grpXGIF__40 10;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} XGIF3STR;
extern volatile XGIF3STR _XGIF3 @(REG_BASE + 0x0000038E);
#define XGIF3                           _XGIF3.Word
#define XGIF3_XGIF_40                   _XGIF3.Bits.XGIF_40
#define XGIF3_XGIF_41                   _XGIF3.Bits.XGIF_41
#define XGIF3_XGIF_42                   _XGIF3.Bits.XGIF_42
#define XGIF3_XGIF_43                   _XGIF3.Bits.XGIF_43
#define XGIF3_XGIF_44                   _XGIF3.Bits.XGIF_44
#define XGIF3_XGIF_45                   _XGIF3.Bits.XGIF_45
#define XGIF3_XGIF_46                   _XGIF3.Bits.XGIF_46
#define XGIF3_XGIF_47                   _XGIF3.Bits.XGIF_47
#define XGIF3_XGIF_48                   _XGIF3.Bits.XGIF_48
#define XGIF3_XGIF_49                   _XGIF3.Bits.XGIF_49
#define XGIF3_XGIF_4A                   _XGIF3.Bits.XGIF_4A
#define XGIF3_XGIF_4B                   _XGIF3.Bits.XGIF_4B
#define XGIF3_XGIF_4C                   _XGIF3.Bits.XGIF_4C
#define XGIF3_XGIF_4D                   _XGIF3.Bits.XGIF_4D
#define XGIF3_XGIF_4E                   _XGIF3.Bits.XGIF_4E
#define XGIF3_XGIF_4F                   _XGIF3.Bits.XGIF_4F
#define XGIF3_XGIF__40                  _XGIF3.MergedBits.grpXGIF__40
#define XGIF3_XGIF_                     XGIF3_XGIF__40

#define XGIF3_XGIF_40_MASK              1
#define XGIF3_XGIF_41_MASK              2
#define XGIF3_XGIF_42_MASK              4
#define XGIF3_XGIF_43_MASK              8
#define XGIF3_XGIF_44_MASK              16
#define XGIF3_XGIF_45_MASK              32
#define XGIF3_XGIF_46_MASK              64
#define XGIF3_XGIF_47_MASK              128
#define XGIF3_XGIF_48_MASK              256
#define XGIF3_XGIF_49_MASK              512
#define XGIF3_XGIF_4A_MASK              1024
#define XGIF3_XGIF_4B_MASK              2048
#define XGIF3_XGIF_4C_MASK              4096
#define XGIF3_XGIF_4D_MASK              8192
#define XGIF3_XGIF_4E_MASK              16384
#define XGIF3_XGIF_4F_MASK              32768
#define XGIF3_XGIF__40_MASK             1023
#define XGIF3_XGIF__40_BITNUM           0


 XGIF4 - XGATE Channel Interrupt Flag Vector 4; 0x00000390 
typedef union {
  word Word;
  struct {
    word XGIF_30     1;                                        Channel Interrupt Flag 30 
    word XGIF_31     1;                                        Channel Interrupt Flag 31 
    word XGIF_32     1;                                        Channel Interrupt Flag 32 
    word XGIF_33     1;                                        Channel Interrupt Flag 33 
    word XGIF_34     1;                                        Channel Interrupt Flag 34 
    word XGIF_35     1;                                        Channel Interrupt Flag 35 
    word XGIF_36     1;                                        Channel Interrupt Flag 36 
    word XGIF_37     1;                                        Channel Interrupt Flag 37 
    word XGIF_38     1;                                        Channel Interrupt Flag 38 
    word XGIF_39     1;                                        Channel Interrupt Flag 39 
    word XGIF_3A     1;                                        Channel Interrupt Flag 3A 
    word XGIF_3B     1;                                        Channel Interrupt Flag 3B 
    word XGIF_3C     1;                                        Channel Interrupt Flag 3C 
    word XGIF_3D     1;                                        Channel Interrupt Flag 3D 
    word XGIF_3E     1;                                        Channel Interrupt Flag 3E 
    word XGIF_3F     1;                                        Channel Interrupt Flag 3F 
  } Bits;
  struct {
    word grpXGIF__30 10;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} XGIF4STR;
extern volatile XGIF4STR _XGIF4 @(REG_BASE + 0x00000390);
#define XGIF4                           _XGIF4.Word
#define XGIF4_XGIF_30                   _XGIF4.Bits.XGIF_30
#define XGIF4_XGIF_31                   _XGIF4.Bits.XGIF_31
#define XGIF4_XGIF_32                   _XGIF4.Bits.XGIF_32
#define XGIF4_XGIF_33                   _XGIF4.Bits.XGIF_33
#define XGIF4_XGIF_34                   _XGIF4.Bits.XGIF_34
#define XGIF4_XGIF_35                   _XGIF4.Bits.XGIF_35
#define XGIF4_XGIF_36                   _XGIF4.Bits.XGIF_36
#define XGIF4_XGIF_37                   _XGIF4.Bits.XGIF_37
#define XGIF4_XGIF_38                   _XGIF4.Bits.XGIF_38
#define XGIF4_XGIF_39                   _XGIF4.Bits.XGIF_39
#define XGIF4_XGIF_3A                   _XGIF4.Bits.XGIF_3A
#define XGIF4_XGIF_3B                   _XGIF4.Bits.XGIF_3B
#define XGIF4_XGIF_3C                   _XGIF4.Bits.XGIF_3C
#define XGIF4_XGIF_3D                   _XGIF4.Bits.XGIF_3D
#define XGIF4_XGIF_3E                   _XGIF4.Bits.XGIF_3E
#define XGIF4_XGIF_3F                   _XGIF4.Bits.XGIF_3F
#define XGIF4_XGIF__30                  _XGIF4.MergedBits.grpXGIF__30
#define XGIF4_XGIF_                     XGIF4_XGIF__30

#define XGIF4_XGIF_30_MASK              1
#define XGIF4_XGIF_31_MASK              2
#define XGIF4_XGIF_32_MASK              4
#define XGIF4_XGIF_33_MASK              8
#define XGIF4_XGIF_34_MASK              16
#define XGIF4_XGIF_35_MASK              32
#define XGIF4_XGIF_36_MASK              64
#define XGIF4_XGIF_37_MASK              128
#define XGIF4_XGIF_38_MASK              256
#define XGIF4_XGIF_39_MASK              512
#define XGIF4_XGIF_3A_MASK              1024
#define XGIF4_XGIF_3B_MASK              2048
#define XGIF4_XGIF_3C_MASK              4096
#define XGIF4_XGIF_3D_MASK              8192
#define XGIF4_XGIF_3E_MASK              16384
#define XGIF4_XGIF_3F_MASK              32768
#define XGIF4_XGIF__30_MASK             1023
#define XGIF4_XGIF__30_BITNUM           0


 XGIF5 - XGATE Channel Interrupt Flag Vector 5; 0x00000392 
typedef union {
  word Word;
  struct {
    word XGIF_20     1;                                        Channel Interrupt Flag 20 
    word XGIF_21     1;                                        Channel Interrupt Flag 21 
    word XGIF_22     1;                                        Channel Interrupt Flag 22 
    word XGIF_23     1;                                        Channel Interrupt Flag 23 
    word XGIF_24     1;                                        Channel Interrupt Flag 24 
    word XGIF_25     1;                                        Channel Interrupt Flag 25 
    word XGIF_26     1;                                        Channel Interrupt Flag 26 
    word XGIF_27     1;                                        Channel Interrupt Flag 27 
    word XGIF_28     1;                                        Channel Interrupt Flag 28 
    word XGIF_29     1;                                        Channel Interrupt Flag 29 
    word XGIF_2A     1;                                        Channel Interrupt Flag 2A 
    word XGIF_2B     1;                                        Channel Interrupt Flag 2B 
    word XGIF_2C     1;                                        Channel Interrupt Flag 2C 
    word XGIF_2D     1;                                        Channel Interrupt Flag 2D 
    word XGIF_2E     1;                                        Channel Interrupt Flag 2E 
    word XGIF_2F     1;                                        Channel Interrupt Flag 2F 
  } Bits;
  struct {
    word grpXGIF__20 10;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} XGIF5STR;
extern volatile XGIF5STR _XGIF5 @(REG_BASE + 0x00000392);
#define XGIF5                           _XGIF5.Word
#define XGIF5_XGIF_20                   _XGIF5.Bits.XGIF_20
#define XGIF5_XGIF_21                   _XGIF5.Bits.XGIF_21
#define XGIF5_XGIF_22                   _XGIF5.Bits.XGIF_22
#define XGIF5_XGIF_23                   _XGIF5.Bits.XGIF_23
#define XGIF5_XGIF_24                   _XGIF5.Bits.XGIF_24
#define XGIF5_XGIF_25                   _XGIF5.Bits.XGIF_25
#define XGIF5_XGIF_26                   _XGIF5.Bits.XGIF_26
#define XGIF5_XGIF_27                   _XGIF5.Bits.XGIF_27
#define XGIF5_XGIF_28                   _XGIF5.Bits.XGIF_28
#define XGIF5_XGIF_29                   _XGIF5.Bits.XGIF_29
#define XGIF5_XGIF_2A                   _XGIF5.Bits.XGIF_2A
#define XGIF5_XGIF_2B                   _XGIF5.Bits.XGIF_2B
#define XGIF5_XGIF_2C                   _XGIF5.Bits.XGIF_2C
#define XGIF5_XGIF_2D                   _XGIF5.Bits.XGIF_2D
#define XGIF5_XGIF_2E                   _XGIF5.Bits.XGIF_2E
#define XGIF5_XGIF_2F                   _XGIF5.Bits.XGIF_2F
#define XGIF5_XGIF__20                  _XGIF5.MergedBits.grpXGIF__20
#define XGIF5_XGIF_                     XGIF5_XGIF__20

#define XGIF5_XGIF_20_MASK              1
#define XGIF5_XGIF_21_MASK              2
#define XGIF5_XGIF_22_MASK              4
#define XGIF5_XGIF_23_MASK              8
#define XGIF5_XGIF_24_MASK              16
#define XGIF5_XGIF_25_MASK              32
#define XGIF5_XGIF_26_MASK              64
#define XGIF5_XGIF_27_MASK              128
#define XGIF5_XGIF_28_MASK              256
#define XGIF5_XGIF_29_MASK              512
#define XGIF5_XGIF_2A_MASK              1024
#define XGIF5_XGIF_2B_MASK              2048
#define XGIF5_XGIF_2C_MASK              4096
#define XGIF5_XGIF_2D_MASK              8192
#define XGIF5_XGIF_2E_MASK              16384
#define XGIF5_XGIF_2F_MASK              32768
#define XGIF5_XGIF__20_MASK             1023
#define XGIF5_XGIF__20_BITNUM           0


 XGIF6 - XGATE Channel Interrupt Flag Vector 6; 0x00000394 
typedef union {
  word Word;
  struct {
    word XGIF_10     1;                                        Channel Interrupt Flag 10 
    word XGIF_11     1;                                        Channel Interrupt Flag 11 
    word XGIF_12     1;                                        Channel Interrupt Flag 12 
    word XGIF_13     1;                                        Channel Interrupt Flag 13 
    word XGIF_14     1;                                        Channel Interrupt Flag 14 
    word XGIF_15     1;                                        Channel Interrupt Flag 15 
    word XGIF_16     1;                                        Channel Interrupt Flag 16 
    word XGIF_17     1;                                        Channel Interrupt Flag 17 
    word XGIF_18     1;                                        Channel Interrupt Flag 18 
    word XGIF_19     1;                                        Channel Interrupt Flag 19 
    word XGIF_1A     1;                                        Channel Interrupt Flag 1A 
    word XGIF_1B     1;                                        Channel Interrupt Flag 1B 
    word XGIF_1C     1;                                        Channel Interrupt Flag 1C 
    word XGIF_1D     1;                                        Channel Interrupt Flag 1D 
    word XGIF_1E     1;                                        Channel Interrupt Flag 1E 
    word XGIF_1F     1;                                        Channel Interrupt Flag 1F 
  } Bits;
  struct {
    word grpXGIF__10 10;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
    word         1;
  } MergedBits;
} XGIF6STR;
extern volatile XGIF6STR _XGIF6 @(REG_BASE + 0x00000394);
#define XGIF6                           _XGIF6.Word
#define XGIF6_XGIF_10                   _XGIF6.Bits.XGIF_10
#define XGIF6_XGIF_11                   _XGIF6.Bits.XGIF_11
#define XGIF6_XGIF_12                   _XGIF6.Bits.XGIF_12
#define XGIF6_XGIF_13                   _XGIF6.Bits.XGIF_13
#define XGIF6_XGIF_14                   _XGIF6.Bits.XGIF_14
#define XGIF6_XGIF_15                   _XGIF6.Bits.XGIF_15
#define XGIF6_XGIF_16                   _XGIF6.Bits.XGIF_16
#define XGIF6_XGIF_17                   _XGIF6.Bits.XGIF_17
#define XGIF6_XGIF_18                   _XGIF6.Bits.XGIF_18
#define XGIF6_XGIF_19                   _XGIF6.Bits.XGIF_19
#define XGIF6_XGIF_1A                   _XGIF6.Bits.XGIF_1A
#define XGIF6_XGIF_1B                   _XGIF6.Bits.XGIF_1B
#define XGIF6_XGIF_1C                   _XGIF6.Bits.XGIF_1C
#define XGIF6_XGIF_1D                   _XGIF6.Bits.XGIF_1D
#define XGIF6_XGIF_1E                   _XGIF6.Bits.XGIF_1E
#define XGIF6_XGIF_1F                   _XGIF6.Bits.XGIF_1F
#define XGIF6_XGIF__10                  _XGIF6.MergedBits.grpXGIF__10
#define XGIF6_XGIF_                     XGIF6_XGIF__10

#define XGIF6_XGIF_10_MASK              1
#define XGIF6_XGIF_11_MASK              2
#define XGIF6_XGIF_12_MASK              4
#define XGIF6_XGIF_13_MASK              8
#define XGIF6_XGIF_14_MASK              16
#define XGIF6_XGIF_15_MASK              32
#define XGIF6_XGIF_16_MASK              64
#define XGIF6_XGIF_17_MASK              128
#define XGIF6_XGIF_18_MASK              256
#define XGIF6_XGIF_19_MASK              512
#define XGIF6_XGIF_1A_MASK              1024
#define XGIF6_XGIF_1B_MASK              2048
#define XGIF6_XGIF_1C_MASK              4096
#define XGIF6_XGIF_1D_MASK              8192
#define XGIF6_XGIF_1E_MASK              16384
#define XGIF6_XGIF_1F_MASK              32768
#define XGIF6_XGIF__10_MASK             1023
#define XGIF6_XGIF__10_BITNUM           0


 XGIF7 - XGATE Channel Interrupt Flag Vector 7; 0x00000396 
typedef union {
  word Word;
  struct {
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word             1; 
    word XGIF_09     1;                                        Channel Interrupt Flag 09 
    word XGIF_0A     1;                                        Channel Interrupt Flag 0A 
    word XGIF_0B     1;                                        Channel Interrupt Flag 0B 
    word XGIF_0C     1;                                        Channel Interrupt Flag 0C 
    word XGIF_0D     1;                                        Channel Interrupt Flag 0D 
    word XGIF_0E     1;                                        Channel Interrupt Flag 0E 
    word XGIF_0F     1;                                        Channel Interrupt Flag 0F 
  } Bits;
} XGIF7STR;
extern volatile XGIF7STR _XGIF7 @(REG_BASE + 0x00000396);
#define XGIF7                           _XGIF7.Word
#define XGIF7_XGIF_09                   _XGIF7.Bits.XGIF_09
#define XGIF7_XGIF_0A                   _XGIF7.Bits.XGIF_0A
#define XGIF7_XGIF_0B                   _XGIF7.Bits.XGIF_0B
#define XGIF7_XGIF_0C                   _XGIF7.Bits.XGIF_0C
#define XGIF7_XGIF_0D                   _XGIF7.Bits.XGIF_0D
#define XGIF7_XGIF_0E                   _XGIF7.Bits.XGIF_0E
#define XGIF7_XGIF_0F                   _XGIF7.Bits.XGIF_0F

#define XGIF7_XGIF_09_MASK              512
#define XGIF7_XGIF_0A_MASK              1024
#define XGIF7_XGIF_0B_MASK              2048
#define XGIF7_XGIF_0C_MASK              4096
#define XGIF7_XGIF_0D_MASK              8192
#define XGIF7_XGIF_0E_MASK              16384
#define XGIF7_XGIF_0F_MASK              32768


 XGSWT - XGATE Software Trigger Register; 0x00000398 
typedef union {
  word Word;
  struct {
    word XGSWTGrp    8;                                        Software Trigger Bits 
    word XGSWTM      8;                                        Software Trigger Mask 
  } Bits;
} XGSWTSTR;
extern volatile XGSWTSTR _XGSWT @(REG_BASE + 0x00000398);
#define XGSWT                           _XGSWT.Word
#define XGSWT_XGSWTGrp                  _XGSWT.Bits.XGSWTGrp
#define XGSWT_XGSWTM                    _XGSWT.Bits.XGSWTM

#define XGSWT_XGSWTGrp_MASK             255
#define XGSWT_XGSWTGrp_BITNUM           0
#define XGSWT_XGSWTM_MASK               65280
#define XGSWT_XGSWTM_BITNUM             8


 XGSEM - XGATE Semaphore Register; 0x0000039A 
typedef union {
  word Word;
  struct {
    word XGSEMGrp    8;                                        Semaphore Mask 
    word XGSEMM      8;                                        Semaphore Bits 
  } Bits;
} XGSEMSTR;
extern volatile XGSEMSTR _XGSEM @(REG_BASE + 0x0000039A);
#define XGSEM                           _XGSEM.Word
#define XGSEM_XGSEMGrp                  _XGSEM.Bits.XGSEMGrp
#define XGSEM_XGSEMM                    _XGSEM.Bits.XGSEMM

#define XGSEM_XGSEMGrp_MASK             255
#define XGSEM_XGSEMGrp_BITNUM           0
#define XGSEM_XGSEMM_MASK               65280
#define XGSEM_XGSEMM_BITNUM             8


 XGPC - XGATE Program Counter Register; 0x0000039E 
typedef union {
  word Word;
} XGPCSTR;
extern volatile XGPCSTR _XGPC @(REG_BASE + 0x0000039E);
#define XGPC                            _XGPC.Word



 XGR1 - XGATE Register 1; 0x000003A2 
typedef union {
  word Word;
} XGR1STR;
extern volatile XGR1STR _XGR1 @(REG_BASE + 0x000003A2);
#define XGR1                            _XGR1.Word



 XGR2 - XGATE Register 2; 0x000003A4 
typedef union {
  word Word;
} XGR2STR;
extern volatile XGR2STR _XGR2 @(REG_BASE + 0x000003A4);
#define XGR2                            _XGR2.Word



 XGR3 - XGATE Register 3; 0x000003A6 
typedef union {
  word Word;
} XGR3STR;
extern volatile XGR3STR _XGR3 @(REG_BASE + 0x000003A6);
#define XGR3                            _XGR3.Word



 XGR4 - XGATE Register 4; 0x000003A8 
typedef union {
  word Word;
} XGR4STR;
extern volatile XGR4STR _XGR4 @(REG_BASE + 0x000003A8);
#define XGR4                            _XGR4.Word



 XGR5 - XGATE Register 5; 0x000003AA 
typedef union {
  word Word;
} XGR5STR;
extern volatile XGR5STR _XGR5 @(REG_BASE + 0x000003AA);
#define XGR5                            _XGR5.Word



 XGR6 - XGATE Register 6; 0x000003AC 
typedef union {
  word Word;
} XGR6STR;
extern volatile XGR6STR _XGR6 @(REG_BASE + 0x000003AC);
#define XGR6                            _XGR6.Word



 XGR7 - XGATE Register 7; 0x000003AE 
typedef union {
  word Word;
} XGR7STR;
extern volatile XGR7STR _XGR7 @(REG_BASE + 0x000003AE);
#define XGR7                            _XGR7.Word



 BAKEY0 - Backdoor Access Key 0; 0x0000FF00 
typedef union {
  word Word;
  struct {
    word KEY         16;                                       Backdoor Access Key bits 
  } Bits;
} BAKEY0STR;
extern volatile BAKEY0STR _BAKEY0 @(0x0000FF00);
#define BAKEY0                          _BAKEY0.Word
#define BAKEY0_KEY                      _BAKEY0.Bits.KEY
 BAKEY_ARR Access 4 BAKEYx registers in an array 
#define BAKEY_ARR                       ((volatile word ) &BAKEY0)

#define BAKEY0_KEY_MASK                 65535
#define BAKEY0_KEY_BITNUM               0


 BAKEY1 - Backdoor Access Key 1; 0x0000FF02 
typedef union {
  word Word;
  struct {
    word KEY         16;                                       Backdoor Access Key bits 
  } Bits;
} BAKEY1STR;
extern volatile BAKEY1STR _BAKEY1 @(0x0000FF02);
#define BAKEY1                          _BAKEY1.Word
#define BAKEY1_KEY                      _BAKEY1.Bits.KEY

#define BAKEY1_KEY_MASK                 65535
#define BAKEY1_KEY_BITNUM               0


 BAKEY2 - Backdoor Access Key 2; 0x0000FF04 
typedef union {
  word Word;
  struct {
    word KEY         16;                                       Backdoor Access Key bits 
  } Bits;
} BAKEY2STR;
extern volatile BAKEY2STR _BAKEY2 @(0x0000FF04);
#define BAKEY2                          _BAKEY2.Word
#define BAKEY2_KEY                      _BAKEY2.Bits.KEY

#define BAKEY2_KEY_MASK                 65535
#define BAKEY2_KEY_BITNUM               0


 BAKEY3 - Backdoor Access Key 3; 0x0000FF06 
typedef union {
  word Word;
  struct {
    word KEY         16;                                       Backdoor Access Key bits 
  } Bits;
} BAKEY3STR;
extern volatile BAKEY3STR _BAKEY3 @(0x0000FF06);
#define BAKEY3                          _BAKEY3.Word
#define BAKEY3_KEY                      _BAKEY3.Bits.KEY

#define BAKEY3_KEY_MASK                 65535
#define BAKEY3_KEY_BITNUM               0


 NVFPROT - Non volatile Flash Protection Register; 0x0000FF0D 
typedef union {
  byte Byte;
  struct {
    byte FPLS0       1;                                        Flash Protection Lower Address size 0 
    byte FPLS1       1;                                        Flash Protection Lower Address size 1 
    byte FPLDIS      1;                                        Flash Protection Lower address range disable 
    byte FPHS0       1;                                        Flash Protection Higher address size 0 
    byte FPHS1       1;                                        Flash Protection Higher address size 1 
    byte FPHDIS      1;                                        Flash Protection Higher address range disable 
    byte NV6         1;                                        Non Volatile Flag Bit 
    byte FPOPEN      1;                                        Opens the flash block or subsections of it for program or erase 
  } Bits;
  struct {
    byte grpFPLS 2;
    byte         1;
    byte grpFPHS 2;
    byte         1;
    byte grpNV_6 1;
    byte         1;
  } MergedBits;
} NVFPROTSTR;
extern volatile NVFPROTSTR _NVFPROT @(0x0000FF0D);
#define NVFPROT                         _NVFPROT.Byte
#define NVFPROT_FPLS0                   _NVFPROT.Bits.FPLS0
#define NVFPROT_FPLS1                   _NVFPROT.Bits.FPLS1
#define NVFPROT_FPLDIS                  _NVFPROT.Bits.FPLDIS
#define NVFPROT_FPHS0                   _NVFPROT.Bits.FPHS0
#define NVFPROT_FPHS1                   _NVFPROT.Bits.FPHS1
#define NVFPROT_FPHDIS                  _NVFPROT.Bits.FPHDIS
#define NVFPROT_NV6                     _NVFPROT.Bits.NV6
#define NVFPROT_FPOPEN                  _NVFPROT.Bits.FPOPEN
#define NVFPROT_FPLS                    _NVFPROT.MergedBits.grpFPLS
#define NVFPROT_FPHS                    _NVFPROT.MergedBits.grpFPHS

#define NVFPROT_FPLS0_MASK              1
#define NVFPROT_FPLS1_MASK              2
#define NVFPROT_FPLDIS_MASK             4
#define NVFPROT_FPHS0_MASK              8
#define NVFPROT_FPHS1_MASK              16
#define NVFPROT_FPHDIS_MASK             32
#define NVFPROT_NV6_MASK                64
#define NVFPROT_FPOPEN_MASK             128
#define NVFPROT_FPLS_MASK               3
#define NVFPROT_FPLS_BITNUM             0
#define NVFPROT_FPHS_MASK               24
#define NVFPROT_FPHS_BITNUM             3


 NVFSEC - Non volatile Flash Security Register; 0x0000FF0F 
typedef union {
  byte Byte;
  struct {
    byte SEC0        1;                                        Memory security bit 0 
    byte SEC1        1;                                        Memory security bit 1 
    byte NV2         1;                                        Non Volatile flag bit 2 
    byte NV3         1;                                        Non Volatile flag bit 3 
    byte NV4         1;                                        Non Volatile flag bit 4 
    byte NV5         1;                                        Non Volatile flag bit 5 
    byte NV6         1;                                        Non Volatile flag bit 6 
    byte KEYEN       1;                                        Backdoor Key Security Enable 
  } Bits;
  struct {
    byte grpSEC  2;
    byte grpNV_2 5;
    byte         1;
  } MergedBits;
} NVFSECSTR;
extern volatile NVFSECSTR _NVFSEC @(0x0000FF0F);
#define NVFSEC                          _NVFSEC.Byte
#define NVFSEC_SEC0                     _NVFSEC.Bits.SEC0
#define NVFSEC_SEC1                     _NVFSEC.Bits.SEC1
#define NVFSEC_NV2                      _NVFSEC.Bits.NV2
#define NVFSEC_NV3                      _NVFSEC.Bits.NV3
#define NVFSEC_NV4                      _NVFSEC.Bits.NV4
#define NVFSEC_NV5                      _NVFSEC.Bits.NV5
#define NVFSEC_NV6                      _NVFSEC.Bits.NV6
#define NVFSEC_KEYEN                    _NVFSEC.Bits.KEYEN
#define NVFSEC_SEC                      _NVFSEC.MergedBits.grpSEC
#define NVFSEC_NV_2                     _NVFSEC.MergedBits.grpNV_2
#define NVFSEC_NV                       NVFSEC_NV_2

#define NVFSEC_SEC0_MASK                1
#define NVFSEC_SEC1_MASK                2
#define NVFSEC_NV2_MASK                 4
#define NVFSEC_NV3_MASK                 8
#define NVFSEC_NV4_MASK                 16
#define NVFSEC_NV5_MASK                 32
#define NVFSEC_NV6_MASK                 64
#define NVFSEC_KEYEN_MASK               128
#define NVFSEC_SEC_MASK                 3
#define NVFSEC_SEC_BITNUM               0
#define NVFSEC_NV_2_MASK                124
#define NVFSEC_NV_2_BITNUM              2


   Watchdog reset macro 
#ifdef _lint
  #define __RESET_WATCHDOG()   empty 
#else
  #define __RESET_WATCHDOG() (void)(ARMCOP = 0x55, ARMCOP = 0xAA)   Just write a byte to feed the dog 
#endif



   D E P R E C I A T E D   S Y M B O L S   

 --------------------------------------------------------------------------- 
 The following symbols were removed, because they were invalid or irrelevant 
 --------------------------------------------------------------------------- 
#define MCCNTlo_BIT0                     This_symb_has_been_depreciated
#define MCCNTlo_BIT1                     This_symb_has_been_depreciated
#define MCCNTlo_BIT2                     This_symb_has_been_depreciated
#define MCCNTlo_BIT3                     This_symb_has_been_depreciated
#define MCCNTlo_BIT4                     This_symb_has_been_depreciated
#define MCCNTlo_BIT5                     This_symb_has_been_depreciated
#define MCCNTlo_BIT6                     This_symb_has_been_depreciated
#define MCCNTlo_BIT7                     This_symb_has_been_depreciated
#define MCCNThi_BIT8                     This_symb_has_been_depreciated
#define MCCNThi_BIT9                     This_symb_has_been_depreciated
#define MCCNThi_BIT10                    This_symb_has_been_depreciated
#define MCCNThi_BIT11                    This_symb_has_been_depreciated
#define MCCNThi_BIT12                    This_symb_has_been_depreciated
#define MCCNThi_BIT13                    This_symb_has_been_depreciated
#define MCCNThi_BIT14                    This_symb_has_been_depreciated
#define MCCNThi_BIT15                    This_symb_has_been_depreciated
#define MCCNTlo_BIT0_MASK                This_symb_has_been_depreciated
#define MCCNTlo_BIT1_MASK                This_symb_has_been_depreciated
#define MCCNTlo_BIT2_MASK                This_symb_has_been_depreciated
#define MCCNTlo_BIT3_MASK                This_symb_has_been_depreciated
#define MCCNTlo_BIT4_MASK                This_symb_has_been_depreciated
#define MCCNTlo_BIT5_MASK                This_symb_has_been_depreciated
#define MCCNTlo_BIT6_MASK                This_symb_has_been_depreciated
#define MCCNTlo_BIT7_MASK                This_symb_has_been_depreciated
#define MCCNThi_BIT8_MASK                This_symb_has_been_depreciated
#define MCCNThi_BIT9_MASK                This_symb_has_been_depreciated
#define MCCNThi_BIT10_MASK               This_symb_has_been_depreciated
#define MCCNThi_BIT11_MASK               This_symb_has_been_depreciated
#define MCCNThi_BIT12_MASK               This_symb_has_been_depreciated
#define MCCNThi_BIT13_MASK               This_symb_has_been_depreciated
#define MCCNThi_BIT14_MASK               This_symb_has_been_depreciated
#define MCCNThi_BIT15_MASK               This_symb_has_been_depreciated

#endif
