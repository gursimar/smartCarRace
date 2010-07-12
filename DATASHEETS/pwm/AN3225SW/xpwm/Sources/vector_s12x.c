/******************************************************************************
Copyright (c) Freescale Semiconductor 2006
File Name		 :	$RCSfile: vector_s12x.c,v $
Current Revision :	$Revision: 1.10 $
Notes            :  
*******************************************************************************/
#pragma CODE_SEG __NEAR_SEG NON_BANKED 
/* dummy interrupt routine */
static interrupt void dummit(void) {
	_asm("BGND");
}

extern void interrupt _Startup(void);

#pragma CONST_SEG __NEAR_SEG S12_VEC_TABLE
/* vector table to be located at address 0xFF00 */
void  (* near const _vectab[])(void) = {
	(void*)0xFFFF,		/* 0xFF00 backdoor key               */
	(void*)0xFFFF,		/* 0xFF02                            */
	(void*)0xFFFF,		/* 0xFF04                            */
	(void*)0xFFFF,		/* 0xFF06                            */
	(void*)0xFFFF,		/* 0xFF08                            */
	(void*)0xFFFF,		/* 0xFF0A                            */ 
	(void*)0xFFFF,		/* 0xFF0C                            */ 
	(void*)0xFFFE,		/* 0xFF0E security                   */
	dummit,		/* 0xFF10 Spurious Interrupt         */
	dummit,		/* 0xFF12                            */
	dummit, 	/* 0xFF14                            */
	dummit, 	/* 0xFF16                            */ 
	dummit, 	/* 0xFF18                            */
	dummit, 	/* 0xFF1A                            */ 
	dummit, 	/* 0xFF1C                            */ 
	dummit, 	/* 0xFF1E                            */
	dummit,  	/* 0xFF20                            */
	dummit, 	/* 0xFF22                            */
	dummit, 	/* 0xFF24                            */
	dummit, 	/* 0xFF26                            */
	dummit, 	/* 0xFF28                            */
	dummit, 	/* 0xFF2A                            */
	dummit, 	/* 0xFF2C                            */
	dummit, 	/* 0xFF2E                            */
	dummit, 	/* 0xFF30                            */
	dummit, 	/* 0xFF32                            */
	dummit, 	/* 0xFF34                            */
	dummit, 	/* 0xFF36                            */
	dummit, 	/* 0xFF38                            */
	dummit, 	/* 0xFF3A                            */
	dummit, 	/* 0xFF3C                            */
	dummit, 	/* 0xFF3E                            */
	dummit, 	/* 0xFF40                            */
	dummit, 	/* 0xFF42                            */
	dummit, 	/* 0xFF44                            */
	dummit, 	/* 0xFF46                            */
	dummit, 	/* 0xFF48                            */
	dummit, 	/* 0xFF4A                            */
	dummit, 	/* 0xFF4C                            */
	dummit, 	/* 0xFF4E                            */
	dummit, 	/* 0xFF50                            */
	dummit, 	/* 0xFF52                            */
	dummit, 	/* 0xFF54                            */
	dummit, 	/* 0xFF56                            */
	dummit, 	/* 0xFF58                            */
	dummit, 	/* 0xFF5A                            */
	dummit, 	/* 0xFF5C                            */
	dummit, 	/* 0xFF5E                            */
	dummit,		/* 0xFF60  XRAM access violation     */
	dummit,		/* 0xFF62  XGATE software error      */
	dummit,		/* 0xFF64  XGATE software trigger 7  */
	dummit,		/* 0xFF66  XGATE software trigger 6  */
	dummit,		/* 0xFF68  XGATE software trigger 5  */
	dummit,		/* 0xFF6a  XGATE software trigger 4  */
	dummit,		/* 0xFF6c  XGATE software trigger 3  */
	dummit,		/* 0xFF6e  XGATE software trigger 2  */
	dummit,		/* 0xFF70  XGATE software trigger 1  */
	dummit,		/* 0xFF72  XGATE software trigger 0  */
	dummit,		/* 0xFF74  Periodic Interrupt Timer 3 */
	dummit,		/* 0xFF76  Periodic Interrupt Timer 2 */
	dummit,		/* 0xFF78  Periodic Interrupt Timer 1 */
	dummit,		/* 0xFF7A  Periodic Interrupt Timer 0 */
	dummit,		/* 0xFF7C  reserved                  */
	dummit,		/* 0xFF7E  Autonomous Periodical Int */
	dummit,		/* 0xFF80  Low Voltage Interrupt     */
	dummit,		/* 0xFF82  IIC1                      */
	dummit,		/* 0xFF84  SCI5                      */
	dummit,		/* 0xFF86  SCI4                      */
	dummit,		/* 0xFF88  SCI3                      */
	dummit,		/* 0xFF8A  SCI2                      */
	dummit,		/* 0xFF8C  PWM Emergency Shutdown    */
	dummit,		/* 0xFF8E  Port P Interrupt          */
	dummit,		/* 0xFF90  MSCAN 4 transmit          */
 	dummit,		/* 0xFF92  MSCAN 4 receive           */
 	dummit,		/* 0xFF94  MSCAN 4 errors            */
 	dummit,		/* 0xFF96  MSCAN 4 wake-up           */
 	dummit,		/* 0xFF98  MSCAN 3 transmit          */
 	dummit,		/* 0xFF9A  MSCAN 3 receive           */
 	dummit,		/* 0xFF9C  MSCAN 3 errors            */
 	dummit,		/* 0xFF9E  MSCAN 3 wake-up           */
 	dummit,		/* 0xFFA0  MSCAN 2 transmit          */
 	dummit,		/* 0xFFA2  MSCAN 2 receive           */
 	dummit,		/* 0xFFA4  MSCAN 2 errors            */
 	dummit,		/* 0xFFA6  MSCAN 2 wake-up           */
 	dummit,		/* 0xFFA8  MSCAN 1 transmit          */
 	dummit,		/* 0xFFAA  MSCAN 1 receive           */
 	dummit,		/* 0xFFAC  MSCAN 1 errors            */
 	dummit,		/* 0xFFAE  MSCAN 1 wake-up           */
 	dummit,		/* 0xFFB0  MSCAN 0 transmit          */
 	dummit,		/* 0xFFB2  MSCAN 0 receive           */
 	dummit,		/* 0xFFB4  MSCAN 0 errors            */
	dummit,		/* 0xFFB6  MSCAN 0 wake-up           */
	dummit,		/* 0xFFB8  FLASH                     */
	dummit,		/* 0xFFBA  EEPROM                    */
	dummit,		/* 0xFFBC  SPI2                      */
	dummit,		/* 0xFFBE  SPI1                      */
	dummit,		/* 0xFFC0  IIC0                      */
	dummit,		/* 0xFFC2  reserved                  */
	dummit,		/* 0xFFC4  SCME                      */
	dummit,		/* 0xFFC6  CRG lock                  */
	dummit,		/* 0xFFC8  Pulse Acc B Overflow      */
	dummit,		/* 0xFFCA  Modulus Counter underflow */
	dummit,		/* 0xFFCC  Port H                    */
	dummit,		/* 0xFFCE  Port J                    */
	dummit,		/* 0xFFD0  ATD1                      */
	dummit,		/* 0xFFD2  ATD0                      */
	dummit,		/* 0xFFD4  SCI 1                     */
	dummit,		/* 0xFFD6  SCI 0                     */
	dummit,		/* 0xFFD8  SPI0                      */
	dummit,		/* 0xFFDA  Pulse acc input edge      */
	dummit,		/* 0xFFDC  Pulse acc A overflow      */
	dummit,		/* 0xFFDE  Timer overflow            */
	dummit,		/* 0xFFE0  Timer channel 7           */
	dummit,		/* 0xFFE2  Timer channel 6           */
	dummit,		/* 0xFFE4  Timer channel 5           */
	dummit,		/* 0xFFE6  Timer channel 4           */
	dummit,		/* 0xFFE8  Timer channel 3           */
	dummit,		/* 0xFFEA  Timer channel 2           */
	dummit,		/* 0xFFEC  Timer channel 1           */
	dummit,		/* 0xFFEE  Timer channel 0           */
	dummit,		/* 0xFFF0  Real Time Interrupt       */
	dummit,		/* 0xFFF2  IRQ                       */
	dummit,		/* 0xFFF4  XIRQ                      */
	dummit,		/* 0xFFF6  SWI                       */
	dummit,		/* 0xFFF8  Illegal opcode            */
	dummit,		/* 0xFFFA  COP failure reset         */
	dummit,		/* 0xFFFC  Clock Monitor fail reset  */
	_Startup,	/* 0xFFFE  Reset                     */
};

//#pragma section const {}
