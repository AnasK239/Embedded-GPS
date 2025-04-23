#include "../tm4c123gh6pm.h"
#include "../Bit_util.h"
#include "stdio.h"
#include "stdint.h"


void UART_Init();
void UART2_WriteChar(char c);
char UART2_ReadChar(void);
void UART2_ReadString(char *line, uint8_t length);