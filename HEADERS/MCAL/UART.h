#ifndef UART_H_
#define UART_H_

#include "../../SERVICES/tm4c123gh6pm.h"
#include "../../SERVICES/Bit_util.h"
#include "../MCAL/GPIO.h"
#include "stdio.h"
#include "stdint.h"


#define UART_2 2
#define GPIO_D 3
#define Input_Shape 0x70         // 8 data bits, no parity, 1 stop bit
#define Control_Shape 0x301      // Enable UART2, TXE, RXE
#define int_baud 104             // 9600 baud rate with 16 MHz clock
#define Float_baud 11

void UART_Init(void);
char UART2_ReadChar(void);
void UART2_ReadString(char *line, uint8_t length);


#endif
