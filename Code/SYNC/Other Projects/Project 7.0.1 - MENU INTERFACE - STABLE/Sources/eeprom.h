#define ERR_OK           0             /* OK */
#define ERR_SPEED        1             /* This device does not work in the active speed mode. */
#define ERR_RANGE        2             /* Parameter out of range. */
#define ERR_VALUE        3             /* Parameter of incorrect value. */
#define ERR_OVERFLOW     4             /* Timer overflow. */
#define ERR_MATH         5             /* Overflow during evaluation. */
#define ERR_ENABLED      6             /* Device is enabled. */
#define ERR_DISABLED     7             /* Device is disabled. */
#define ERR_BUSY         8             /* Device is busy. */
#define ERR_NOTAVAIL     9             /* Requested value or method not available. */
#define ERR_RXEMPTY      10            /* No data in receiver. */
#define ERR_TXFULL       11            /* Transmitter is full. */
#define ERR_BUSOFF       12            /* Bus not available. */
#define ERR_OVERRUN      13            /* Overrun error is detected. */
#define ERR_FRAMING      14            /* Framing error is detected. */
#define ERR_PARITY       15            /* Parity error is detected. */
#define ERR_NOISE        16            /* Noise error is detected. */
#define ERR_IDLE         17            /* Idle error is detected. */
#define ERR_FAULT        18            /* Fault error is detected. */
#define ERR_BREAK        19            /* Break char is received during communication. */
#define ERR_CRC          20            /* CRC error is detected. */
#define ERR_ARBITR       21            /* A node losts arbitration. This error occurs if two nodes start transmission at the same time. */
#define ERR_PROTECT      22            /* Protection error is detected. */
#define ERR_UNDERFLOW    23            /* Underflow error is detected. */
#define ERR_UNDERRUN     24            /* Underrun error is detected. */
#define ERR_COMMON       25            /* Common error of a device. */
#define ERR_LINSYNC      26            /* LIN synchronization error is detected. */


/* User type for addressing of the EEPROM. Actual type depends on the CPU family. */
  typedef far unsigned int * far IEE1_TAddress; /* Type of address to the EEPROM */

/* EEPROM area start address (in the format used by bean methods). */
#define IEE1_AREA_START                 ((IEE1_TAddress)1306624UL)
/* EEPROM area last address (in the format used by bean methods). */
#define IEE1_AREA_END                   ((IEE1_TAddress)1310715UL)
/* EEPROM area size (in bytes). */
#define IEE1_AREA_SIZE                  4092U
/* EEPROM area sector size: minimal erasable unit (in bytes). */
#define IEE1_AREA_SECTOR_SIZE           4U
/* TRUE if the bean setting allows clear bits of already programmed flash memory location without destruction of the value in surrounding addresses by sector erase. */
#define IEE1_ALLOW_CLEAR                (TRUE)
/* Size of programming phrase, i.e. number of bytes that must be programmed at once */
#define IEE1_PROGRAMMING_PHRASE         (2U)


/*
** ===================================================================
**     Method      :  WriteWord (bean IntEEPROM)
**
**     Description :
**         The method writes the word data to EEPROM memory.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static byte WriteWord(IEE1_TAddress AddrRow,word Data16)
{
  if (ESTAT_CBEIF == 0) {              /* Is command buffer full ? */
    return ERR_BUSY;                   /* If yes then error */
  }
  /* ESTAT: PVIOL=1,ACCERR=1 */
  ESTAT = 48;                          /* Clear error flags */
  *(AddrRow) = Data16;                 /* Array address and program data */
  /* ECMD: ??=0,CMDB=32 */
  ECMD = 32;                           /* Word program command */
  ESTAT = 128;                         /* Clear flag command buffer empty */
  if ((ESTAT_PVIOL == 1) || (ESTAT_ACCERR == 1)) { /* Is protection violation or acces error detected ? */
    return ERR_NOTAVAIL;               /* If yes then error */
  }
  while ((ESTAT & 0xC0) != 0xC0) {}    /* Wait for command completition */
  if (*(AddrRow) != Data16) {          /* Was attempt to write data to the given address errorneous? */
    return ERR_VALUE;                  /* If yes then error */
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  WriteSector (bean IntEEPROM)
**
**     Description :
**         The method writes the data block to EEPROM memory.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static byte WriteSector(IEE1_TAddress AddrSec,dword Data32)
{
  byte err;                            /* Temporary variable */

  if (ESTAT_CBEIF == 0) {              /* Is command buffer full ? */
    return ERR_BUSY;                   /* If yes then error */
  }
  /* ESTAT: PVIOL=1,ACCERR=1 */
  ESTAT = 48;                          /* Clear error flags */
  *(AddrSec) = (word)(Data32 >> 16);   /* Array address and program data - higher part */
  /* ECMD: ??=0,CMDB=64 */
  ECMD = 64;                           /* Sector erase command */
  ESTAT = 128;                         /* Clear flag command buffer empty */
  if ((ESTAT_PVIOL == 1) || (ESTAT_ACCERR == 1)) { /* Is protection violation or acces error detected ? */
    return ERR_NOTAVAIL;               /* If yes then error */
  }
  while ((ESTAT & 0xC0) != 0xC0) {}    /* Wait for command completition */
  ESTAT = 48;                          /* Clear error flags */
  *(AddrSec) = (word)(Data32 >> 16);   /* Array address and program data - higher part */
  /* ECMD: ??=0,CMDB=32 */
  ECMD = 32;                           /* Word program command */
  ESTAT = 128;                         /* Clear flag command buffer empty */
  if ((ESTAT_PVIOL == 1) || (ESTAT_ACCERR == 1)) { /* Is protection violation or acces error detected ? */
    return ERR_NOTAVAIL;               /* If yes then error */
  }
  while ((ESTAT & 0xC0) != 0xC0) {}    /* If yes then wait for command completition */
  err=WriteWord(AddrSec + 1,(word)Data32); /* Write lower part */
  if (err != ERR_OK) {                 /* Was attemp to write data to the given address errorneous? */
    return err;                        /* If yes then error */
  }
  if (*(AddrSec) != (word)(Data32 >> 16)) { /* Was attempt to write data to the given address errorneous? */
    return ERR_VALUE;                  /* If yes then error */
  }
  return ERR_OK;
}

byte IEE1_SetLong(IEE1_TAddress Addr,dword Data)
{
  if((Addr < IEE1_AREA_START) || (Addr > IEE1_AREA_END)) { /* Is given address out of EEPROM area array ? */
    return ERR_RANGE;                  /* If yes then error */
  }
  if ((dword)Addr & 3) {               /* Aligned address ? */
    return ERR_NOTAVAIL;
  }
  if((ESTAT & 192) != 192) {           /* Is reading from EEPROM possible? */
    return ERR_BUSY;                   /* If no then error */
  }
  return (WriteSector(Addr,Data));     /* Write new content of given sector */
}

/*
** ===================================================================
**     Method      :  IEE1_GetLong (bean IntEEPROM)
**
**     Description :
**         This method reads a long word (4 bytes) from the specified
**         EEPROM address. The method also sets address pointer for
**         <SetActByte> and <GetActByte> methods (applicable only if
**         these methods are enabled). The pointer is set to address
**         passed as the parameter + 3.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Addr            - Address to EEPROM
**       * Data            - A pointer to the returned 32-bit data
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_BUSY - device is busy 
**                           - ERR_RANGE - selected address out of the
**                           selected address range
** ===================================================================
*/
byte IEE1_GetLong(IEE1_TAddress Addr,dword *Data)
{
  if((Addr < IEE1_AREA_START) || (Addr > IEE1_AREA_END)) { /* Is given address out of EEPROM area array ? */
    return ERR_RANGE;                  /* If yes then error */
  }
  if((ESTAT & 192) != 192) {           /* Is reading from EEPROM possible? */
    return ERR_BUSY;                   /* If no then error */
  }
  *Data = *(far dword *far)(Addr);     /* Return data from given address */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  IEE1_EraseEeprom (bean IntEEPROM)
**
**     Description :
**         The method mass erases all EEPROM memory. The method also
**         sets address pointer for <SetActByte> and <GetActByte>
**         methods (applicable only if these methods are enabled). The
**         pointer is set to address passed as the parameter - 1.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Addr            - Pass any valid EEPROM address. EEPROM
**                           module in some CPU families don't require
**                           address for mass erase, then the parameter
**                           is ignored.
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_SPEED - the bean does not work in the
**                           active speed mode 
**                           - ERR_BUSY - device is busy 
**                           - ERR_NOTAVAIL - other device-specific error
** ===================================================================
*/
byte IEE1_EraseEeprom(IEE1_TAddress Addr)
{
  if((ESTAT & 192) != 192) {           /* Is reading from EEPROM possible? */
    return ERR_BUSY;                   /* If no then error */
  }
  /* ESTAT: PVIOL=1,ACCERR=1 */
  ESTAT = 48;                          /* Clear error flags */
  *((IEE1_TAddress)Addr) = 0;          /* Array address */
  /* ECMD: ??=0,CMDB=64 */
  ECMD = 65;                           /* Mass erase command */
  ESTAT = 128;                         /* Clear flag command buffer empty */
  if ((ESTAT_PVIOL == 1) || (ESTAT_ACCERR == 1)) { /* Is protection violation or acces error detected ? */
    return ERR_NOTAVAIL;               /* If yes then error */
  }
  while ((ESTAT & 0xC0) != 0xC0) {}    /* Wait for command completition */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  IEE1_Init (bean IntEEPROM)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void IEE1_Init(void)
{
  ECLKDIV = 74;                        /* Set up Clock Divider Register */
}


void EEPROM_masserase()
{
          unsigned char return_val;
          return_val = IEE1_EraseEeprom(IEE1_AREA_START);
          if(return_val == ERR_OK) 
          {
                    //Sucessfully erased..
          }
}

void EEPROM_read()
{
          union long_to_float simar_read;
          unsigned char return_val;
          unsigned long* read_pointer;
          
          read_pointer = &simar_read.long_val;

          // To read kp from EEPROM
          return_val=IEE1_GetLong(EEPROM_KP,read_pointer);
          if(return_val == ERR_OK) 
          {
                    kp = simar_read.float_val;
          }
          
          else
          {
                    //ERROR_LED=LED_ON
          }
  
          // To read ki from EEPROM
          return_val=IEE1_GetLong(EEPROM_KI,read_pointer);
          if(return_val == ERR_OK) 
          {
                    ki = simar_read.float_val;
          }
          
          else
          {
                    //ERROR_LED=LED_ON
          }
}
 
void EEPROM_reset()
{
union long_to_float simar_read,simar_write ;
unsigned char return_val;
 unsigned long* read_data;
 read_data = &simar_read.long_val;

  return_val = IEE1_EraseEeprom(IEE1_AREA_START);
  if(return_val == ERR_OK) 
  {
          LED4=LED_OFF;
          Delay(2);
          LED4=LED_ON;
          Delay(2);
  }
  
 
 // for kp
simar_write.float_val = 0.0800;
 
  return_val = IEE1_SetLong(EEPROM_KP,simar_write.long_val);
  if(return_val == ERR_OK) {
   
    return_val=IEE1_GetLong(EEPROM_KP,read_data);
    if(return_val == ERR_OK) {
      if(simar_read.float_val == 0.0800) {
          LED4=LED_OFF;
          Delay(2);
          LED4=LED_ON;
   
      } else {
   
      }
    }
  }
 // for ki
simar_write.float_val = 0.00200;
 
  return_val = IEE1_SetLong(EEPROM_KI,simar_write.long_val);
  if(return_val == ERR_OK) {
   
    return_val=IEE1_GetLong(EEPROM_KI,read_data);
    if(return_val == ERR_OK) {
      if(simar_read.float_val == 0.00200)
      {
            LED4=LED_OFF;
          Delay(2);
          LED4=LED_ON;
 
      } 
      else 
      {
   
      }
    }
  }
}

