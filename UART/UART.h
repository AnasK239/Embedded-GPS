#ifndef UART_H_
#define UART_H_

#include "../tm4c123gh6pm.h"
#include "../Bit_util.h"
#include "stdio.h"
#include "stdint.h"

#define UART_2 2
#define GPIO_D 3
#define Pin_6_7 0xc0
#define Data_Shape 0x70

void UART_Init();
void UART2_WriteChar(char c);
char UART2_ReadChar(void);
void UART2_ReadString(char *line, uint8_t length);


#endif