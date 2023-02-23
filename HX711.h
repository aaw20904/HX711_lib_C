/*********HX711 DEVICE DRIVER****/
/*****clk-GPIOB 11; dout-GPIOB 10; LED-GPIOB12***/
//////INPUT  A Gain=128
#define HX711_A128 25
//////INPUT  B Gain=64
#define HX711_B64 26
//////INPUT  B Gain=32
#define HX711_B32 27

#define CLK_0   GPIO_BSRR_BR11  
#define CLK_1  GPIO_BSRR_BS11  
///const for right shift.It shift data bit to LSB. It`s 10 because dout=GPIO10
#define REQ_BIT_SHIFT 10
//mast for getting only one bit from the port
#define INP_PORT_MASK   GPIO_IDR_IDR10  
 int HX711_GetData(short param);
void delay_hx711(void);
