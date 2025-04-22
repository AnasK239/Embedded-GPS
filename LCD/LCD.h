#ifndef LCD_H_
#define LCD_H_

#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "string.h"
// #include "systick.h" implement the delay here 
#include "stdio.h"


void Printdata(unsigned char data);
void Lcd_command(unsigned char command);
void Lcd_data(unsigned char data);
void Lcd_string(char *str);
void Lcd_ports_init(void);
void Lcd_init(void);
void Lcd_clear(void);



#define ALL_ON 0XFF
#define ALL_OFF 0X00
#define RS_ONLY_OFF 0XFE
#define RS_ON 0X01
#define RW_ON 0X02
#define EN_ON 0X04


#define Fn_set 0X38 // 8-bit mode,16 col , 2 lines
#define AUTO_CUORSER_INC 0X06
#define CLEAR 0X01
#define LCD_OFF 0X08
#define LCD_ON 0X03
#define INITIAL_POSITION 0X80
#define EN_DISP_CURSOR_OFF 0X0C

//
#endif
