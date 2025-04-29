#ifndef UART_H_
#define UART_H_

#include "../tm4c123gh6pm.h"
#include "../Bit_util.h"
#include "stdio.h"
#include "stdint.h"

#define UART_2 2
#define GPIO_D 3
#define Functions_D6_D7 0xc0     // Enable alternate function, digital function and Disable analog function for PD6 and PD7
#define Input_Shape 0x70         // 8 data bits, no parity, 1 stop bit
#define Control_Shape 0x301      // Enable UART2, TXE, RXE
#define int_baud 104             // 9600 baud rate with 16 MHz clock
#define Float_baud 11
#define Clear_PCTL_D6_D7 0xFF000000
#define Set_PCTL_D6_D7 0x11000000

void UART_Init();
char UART2_ReadChar(void);
void UART2_ReadString(char *line, uint8_t length);


#endif