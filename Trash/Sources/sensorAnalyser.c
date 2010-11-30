
// file: sensorAnalyser.c

// Performs the task of calculating compensated ratio and error. Then it provides the desred
// sensor values to Main.c


#include "sensorAnalyser.h"
#include "sensor.h"
#include "global.h"

//Global Variables
int condition_var = LED1;
int index[BYTES];
int black[BYTES], white[BYTES];
int comp_ratio[BYTES];
int ATD_comp_arr[BYTES];
int clb_sns_black = FALSE;
int clb_sns_white = FALSE;



//***************************************************************************************************


// Name: Read_Sensor_Values 
// Function: Read the sensors value from the ATD pins and guides the whole process to get error
// Input: NULL
// Output: Error

int Read_Sensor_Values(void) {
  
  int error= NONE;
  int ATD_comp_ptr[BYTES];
  Comp_Sensor_Value(ATD_comp_ptr);
  Bubble_sort();

  error = Position_center();
  
  return error;
}

//***************************************************************************************************
  // Name: Calibrate_Sensors 
  // Function: Calibrating the Sensors against the black and white region of the track before racing.
  // to compensate for the sensitivity difference of the sensors. A compensation ratio can be
  // calculated from these 'black' and 'white' values.It is scalling factor to be applied to future
  // readings so that '0' would be obtained when each sensor is on white region and 255(for 8-bit ATD)
  // when each sensor is on black region.
  //
  // Compensation Ratio = 256 / (Black value - White Value) 
  // if Reading > 'Black value", then Reading = Black
  // if Reading < 'White Value', then Reading = White
  // Compensated Reading = (Reading - White) * Compensation Ratio
  //
  // Input: NULL
  // Output: NULL

Bool Calibrate_Sensors(void) {

      int count, clb_result;
      int finish_process = FALSE;
      
      int ATD_arr[BYTES];
      
      switch(condition_var){
        case LED1:    Switch_ON_LED(LED1);
                      ++condition_var;           //Forward the process to next case
                      break;
        
        case LED2:    if(Switch_Pressed(SW2)){           //Check for if SW2 is pressed
                        Uncomp_Sensor_Value(ATD_arr);        //Read Sensor values for black
                        count = LED1;
                        for (;count<LED8;count++) {
                            black[count]=ATD_arr[count];   //Get the black values
                        }
                        
                        clb_sns_black = TRUE;  
    
                        Switch_ON_LED(LED2);
                        ++condition_var;           //Forward the process to next case
                        } 
                        
                      break;
        
        case LED3:    if(Switch_Pressed(SW3)){           //Check for if SW3 is pressed
                        Uncomp_Sensor_Value(ATD_arr);        //Read Sensor values for white
	                      count = LED1;
                        for (;count<LED8;count++) {
                            white[count]=ATD_arr[count];  //get the White Values
                        }
                        
                        clb_sns_white = TRUE;

                        Switch_ON_LED(LED3);
                        ++condition_var;           //Forward the process to next case
                        }  
                      break;
        
        case LED4:    if(Switch_Pressed(SW2)){           //Check for if SW2 is pressed
                        finish_process = TRUE;
                        Switch_ON_LED(LED4);
                      }
                      break; 
      }

  clb_result = clb_sns_black & clb_sns_white;
	
	if(clb_result == TRUE){
	    for( count=LED1;count<=LED7;count++)
	    {
		      comp_ratio[count]=(MAX_CAL*Scaling_factor)/(black[count]-white[count]);		//Compensation Ratio of black and white values
	    }
	    clb_sns_black = FALSE;    //Only to store the compensation value during actual calibration process and
	    clb_sns_white = FALSE;    //avoid over writing of the compensation ratio value
	}
		
	clb_result = finish_process;
	
	if(clb_result == TRUE){
	  return clb_result;
	}
}

//***************************************************************************************************


// Name: Comp_Sensor_Value 
// Function: Read the sensors value from the ATD pins and perform compensation
// Input: NULL
// Output: Pointer to the ATD sensor values

void Comp_Sensor_Value(int *ATD_comp_ptr) {
        
   int ATD_arr[BYTES];
   int count = NONE;
  
   Uncomp_Sensor_Value(ATD_arr); 
   
   *ATD_comp_ptr  = ((ATD_arr[LED1]-white[LED1])*comp_ratio[LED1])/Scaling_factor;      //Do compensation for current value available at the pin: ATD0
   *(ATD_comp_ptr+1)= ((ATD_arr[LED2]-white[LED2])*comp_ratio[LED2])/Scaling_factor;    //Do compensation for current value available at the pin: ATD1
   *(ATD_comp_ptr+2)= ((ATD_arr[LED3]-white[LED3])*comp_ratio[LED3])/Scaling_factor;    //Do compensation for current value available at the pin: ATD2
   *(ATD_comp_ptr+3)= ((ATD_arr[LED4]-white[LED4])*comp_ratio[LED4])/Scaling_factor;    //Do compensation for current value available at the pin: ATD3
   *(ATD_comp_ptr+4)= ((ATD_arr[LED5]-white[LED5])*comp_ratio[LED5])/Scaling_factor;    //Do compensation for current value available at the pin: ATD4
   *(ATD_comp_ptr+5)= ((ATD_arr[LED6]-white[LED6])*comp_ratio[LED6])/Scaling_factor;    //Do compensation for current value available at the pin: ATD5
   *(ATD_comp_ptr+6)= ((ATD_arr[LED7]-white[LED7])*comp_ratio[LED7])/Scaling_factor;    //Do compensation for current value available at the pin: ATD6
   
   for(count=LED1;count<TOTAL_LEDS;count++){
      ATD_comp_arr[count] = ATD_comp_ptr[count];
   }
}

//***************************************************************************************************


// Name: Bubble_sort 
// Function: Bubble sort the compensated values 
// Input: NULL
// Output: NULL

void Bubble_sort(void){
      
        //Variable Declaration
        int count, count1, count2,temp;
        int BIN_SORT[BYTES];
        
        for (count=LED1;count<LED7;count++)  {
          BIN_SORT[count]=ATD_comp_arr[count];
        }
        
        for (count1=LED1;count1<LED8;count1++)  {
          for (count2=count1+LED1;count2<LED8;count2++ ) {
            if ( BIN_SORT[count1]<BIN_SORT[count2]) {      // Compare the reading of sensors
                temp=BIN_SORT[count1];
                BIN_SORT[count1]=BIN_SORT[count2];
                BIN_SORT[count2]=temp;                           // Bubble sort the sensor readings
            }  
          }
        }
        
        for (count=LED1;count<LED7;count++)                      // Initialize the outer loop
        {
          if (BIN_SORT[LED1]==ATD_comp_arr[count])
             index[LED1]=count;
          if (BIN_SORT[LED2]==ATD_comp_arr[count])
             index[LED2]=count;
          if (BIN_SORT[LED3]==ATD_comp_arr[count] )
             index[LED3]=count;
        }
         
        for (count1=LED1;count1<LED4;count1++)  {
          for (count2=count1+LED1;count2<LED4;count2++ ) {
            if ( index[count1]<index[count2]) {                    // Compare the reading of sensors
              temp=index[count1];
              index[count1]=index[count2];
              index[count2]=temp;                           // Bubble sort the sensor readings with indeces
            }
          }
        }
}

//***************************************************************************************************


// Name: Postion_center 
// Function: To find the final position of center of track according to sensors
// Input: NULL
// Output: Error (integer)

int Position_center(void) {
  
          int pos_data[BYTES],pos_center,count,error;
          
          pos_center= index[LED2]*ASST_SENSORS*MAX_CAL + 
                                                    (ATD_comp_arr[index[LED1]]- ATD_comp_arr[index[LED3]]);
          
          count = LED1;
          for (;count<LED8;count++) {
            pos_data[count]= MAX_CAL_SNS_VALUE * count;   
          }  
          
          error = 1536 - pos_center ;
          return error;
}