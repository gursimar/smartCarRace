void pulse_counter_init()
{
        PBCTL_PBEN=1;              //16 bit pulse accumulator enable bit (cascading two 8 bit pulse accumulator)
        
        TCTL4_EDG0B=1;        //configure the edge detector circuits
        TCTL4_EDG0A=0;        //10 is capture on falling edges only..
        
        DLYCT_DLY0=1;         //introduces delay of 1024 bus clock cycles..
        DLYCT_DLY1=1;
        PACN10=0;   //Sets the data register to 0.
}


/*
       uart0_tx_int(PACN10/8);
        uart0_tx_newline();
        PACN10=0;
       */