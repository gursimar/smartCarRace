/*****************************************************************************/
/*                                             COPYRIGHT (c) Freescale 2005  */
/*                                                                           */
/* File Name          :    $RCSfile: S12PIT24BCV1.h,v $						     */
/*                                                                           */
/* Current Revision :      $Revision: 1.0 $                                  */
/*                                                                           */
/* PURPOSE: header file for S12X PIT register block.	   			           */
/*                                                                           */
/*  ***********************************************************************  */
/*  *  THIS CODE IS ONLY INTENDED AS AN EXAMPLE OF CODE FOR THE           *  */
/*  *  METROWERKS COMPILER AND THE S12X EVB AND HAS ONLY BEEN GIVEN A     *  */
/*  *  MIMIMUM LEVEL OF TEST. IT IS PROVIDED 'AS SEEN' WITH NO GUARANTEES *  */
/*  *  AND NO PROMISE OF SUPPORT.                                         *  */
/*  ***********************************************************************  */
/*                                                                           */
/* DESCRIPTION:  Defines the PIT register block as a datastructure of        */
/*               type tPIT.                                                  */
/*                                                                           */
/* UPDATE HISTORY                                                            */
/* REV  AUTHOR      DATE        DESCRIPTION OF CHANGE                        */
/* ---  ------      --------    ---------------------                        */
/* 1.0  r54430      23/03/04    Initial Revision                             */
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

#ifndef S12PIT24BCV1_H			/*prevent duplicated includes */
#define S12PIT24BCV1_H

#ifndef S12_COMMON_H		      /*prevent duplicated includes */
#include "S12_COMMON.h"
#endif

typedef union uPITCFLMT
{
  tU08	byte;
  struct
  {
    tU08 pflmt0  :1;
    tU08 pflmt1  :1;
    tU08 res1    :3;
    tU08 pitfrz  :1;
    tU08 pitswai :1;
    tU08 pite	  :1;
  }bit;
} tPITCFLMT;

#define PFLMT0	0x01	/*bit masks	*/
#define PFLMT1	0x02
#define PITFRZ  0x20
#define PITSWAI 0x40
#define PITE    0x80


typedef union uPITFLT
{
  tU08	byte;
  struct
  {
    tU08 pflt0  :1;
    tU08 pflt1	 :1;
    tU08 pflt2  :1;
    tU08 pflt3  :1;
  } bit;
} tPITFLT;

#define PFLT0	0x01	/*bit masks	*/
#define PFLT1	0x02
#define PFLT2	0x04
#define PFLT3	0x08

typedef union uPITCE
{
  tU08	byte;
  struct
  {
    tU08 pce0   :1;
    tU08 pce1   :1;
    tU08 pce2   :1;
    tU08 pce3   :1;
  } bit;
} tPITCE;

#define PCE0    0x01	/*bit masks	*/
#define PCE1    0x02
#define PCE2    0x04
#define PCE3    0x08

typedef union uPITMUX
{
  tU08	byte;
  struct
  {
    tU08 pmux0	:1;
    tU08 pmux1	:1;
    tU08 pmux2	:1;
    tU08 pmux3	:1;
  } bit;
} tPITMUX;

#define PMUX0		0x01	/*bit masks	*/
#define PMUX1		0x02
#define PMUX2		0x04
#define PMUX3		0x08

typedef union uPITINTE
{
  tU08	byte;
  struct
  {
    tU08 pinte0	:1;
    tU08 pinte1	:1;
    tU08 pinte2	:1;
    tU08 pinte3	:1;
  } bit;
} tPITINTE;

#define PINTE0  	0x01	/*bit masks	*/
#define PINTE1		0x02
#define PINTE2		0x04
#define PINTE3		0x08

typedef union uPITTF
{
  tU08	byte;
  struct
  {
    tU08 ptf0	:1;
    tU08 ptf1	:1;
    tU08 ptf2	:1;
    tU08 ptf3	:1;
  } bit;
} tPITTF;

#define PTF0   0x01	/*bit masks	*/
#define PTF1   0x02
#define PTF2   0x04
#define PTF3   0x08

typedef struct {				/* pit datastructure	*/
  volatile tPITCFLMT  pitcflmt;	
  volatile tPITFLT    pitflt;	
  volatile tPITCE     pitce;	
  volatile tPITMUX    pitmux;	
  volatile tPITINTE   pitinte;	
  volatile tPITTF     pittf;	
  volatile tREG08     pitmtld0;
  volatile tREG08     pitmtld1;
  volatile tREG16     pitld0;
  volatile tREG16     pitcnt0;
  volatile tREG16     pitld1;
  volatile tREG16     pitcnt1;
  volatile tREG16     pitld2;
  volatile tREG16     pitcnt2;
  volatile tREG16     pitld3;
  volatile tREG16     pitcnt3;
} tPIT;


#endif /*S12PIT24BCV1_H */