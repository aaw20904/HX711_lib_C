#include "HX711.h"
#include "main.h"

void delay_hx711(void){
 int q = 0;
	while(q < 30){
	  q++;
	}
}

int HX711_GetData(short param){
 int32_t Data = 0;
  short Loop = 0;
 
//wait until conversion done
while(GPIOB->IDR & INP_PORT_MASK){}
 
while(Loop<param){
  //set clock to 1
  GPIOB->BSRR = CLK_1;
  delay_hx711();
     //reset clock to 0
  GPIOB->BSRR = CLK_0;
  //checking if data word had end
      if(Loop < 24){
      Data |= ((GPIOB->IDR & INP_PORT_MASK) >> 10);
      //if last bit - don`t shift
      if(Loop < 23)
        Data <<= 1;
      }
  delay_hx711();
  Loop++;
  }
//conveert int24 to int32
//check if Data is negative
if(Data & (1<<23)){
	Data |= 0xff000000;
	return Data;
}
//if data is positive
else return Data;

}
