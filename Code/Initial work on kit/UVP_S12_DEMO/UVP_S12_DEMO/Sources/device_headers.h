//Only one of the groups below can be uncommented at a time.
//Uncomment the lines below for using the HCS12C128

//#include <mc9s12c128.h>
//#pragma LINK_INFO DERIVATIVE "mc9s12c128"
//#define HCS12D 0
//#include "AP_s12c128slk.h"   /* I/O definitions and init routines */
//#include "PB_s12c128slk.h"   /* I/O definitions and init routines */

//Uncomment the lines below for using the HCS12DT256
// #pragma LINK_INFO DERIVATIVE "mc9s12dt256"
// #include <mc9s12dt256.h>
// #define HCS12D 1
// #include "AP_s12dt256slk.h"   /* I/O definitions and init routines */
 //#include "PB_s12dt256slk.h"   /* I/O definitions and init routines */

//Uncomment the lines below for using the HCS12XDT512
  #pragma LINK_INFO DERIVATIVE "mc9s12xdt512"
  #include <mc9s12xdt512.h>
  #define HCS12D 1
  #include "AP_s12xdt512slk.h"   /* I/O definitions and init routines */
  #include "PB_s12xdt512slk.h"   /* I/O definitions and init routines */
