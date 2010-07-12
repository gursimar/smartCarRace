
#ifndef __XGATE_H_
#define __XGATE_H_

/* XGATE vector table */
typedef void (*_NEAR XGATE_Function)(int);
typedef struct {
  XGATE_Function pc;        /* pointer to the handler */
  int dataptr;              /* pointer to the data of the handler */
} XGATE_TableEntry;

#pragma push
#pragma CONST_SEG __GPAGE_SEG XGATE_CONST  /* for the HCS12X/XGATE shared setup, the XGATE constants must be in RAM. */
#define XGATE_VECTOR_OFFSET 9
extern const XGATE_TableEntry XGATE_VectorTable[];
#pragma pop

#endif /* __XGATE_H_ */
