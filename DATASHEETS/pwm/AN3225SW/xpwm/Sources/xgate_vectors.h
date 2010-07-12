#ifndef __XGATE_H_
#define __XGATE_H_

#pragma CODE_SEG XGATE_CODE
#pragma DATA_SEG XGATE_DATA

typedef struct {
  void (*isr)(void);	/* address of the routine itself */
/*	unsigned int *const data; */		/* private data of that routine */	
	void *const data;			        /* private data of that routine */	
} xgate_vector;

const xgate_vector XGATEVectorTable[];	/* XGATE vector table */

#pragma CODE_SEG DEFAULT

/* used with XGATE_CODE section (see prm file) */

extern char __SEG_START_XGATE_CODE[];
#define XGATE_ROM_CODE_START ((void*)__SEG_START_XGATE_CODE)

extern char __SEG_SIZE_XGATE_CODE[];
#define XGATE_CODE_SIZE ((int)__SEG_SIZE_XGATE_CODE)

extern char __SEG_RELOCATE_TO_XGATE_CODE[];
#define XGATE_RAM_CODE_START ((void*)__SEG_RELOCATE_TO_XGATE_CODE)

#endif /* __XGATE_H_ */
