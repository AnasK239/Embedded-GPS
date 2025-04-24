#include "UART.h"


void UART_Init(){
    SET_BIT(SYSCTL_RCGCUART_R, UART_2); // Enable UART2 clock
    while (GET_BIT(SYSCTL_PRUART_R, UART_2) == 0); // Wait for UART2 to be ready
    SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_D); // Enable GPIOD clock
    while (GET_BIT(SYSCTL_PRGPIO_R, GPIO_D) == 0); // Wait for GPIOD to be ready

    CLR_BIT(UART2_CTL_R, 0); // Disable UART2 for configuration
    UART2_IBRD_R = 104; // Set integer baud rate divisor for 9600 baud
    UART2_FBRD_R = 11; // Set fractional baud rate divisor for 9600 baud
    SET(UART2_LCRH_R, Input_Shape); // 8 data bits, no parity, 1 stop bit
    SET(UART2_CTL_R, 0x301); // Enable UART2, TXE, RXE

    SET(GPIO_PORTD_AFSEL_R, Pin_6_7); // Enable alternate function for PD6 and PD7
    SET(GPIO_PORTD_DEN_R, Pin_6_7); // Enable digital function for PD6 and PD7
    CLR(GPIO_PORTD_PCTL_R, 0xFF000000); // Clear PD6 and PD7 PCTL bits
    SET(GPIO_PORTD_PCTL_R, 0x11000000); // Set PD6 and PD7 to UART2
    CLR(GPIO_PORTD_AMSEL_R, Pin_6_7); // Disable analog function for PD6 and PD7
    
    SET(GPIO_PORTD_DIR_R, 0x80); // Set PD7 as output (TX) and PD6 as input (RX)
}

char UART2_ReadChar(void) {
    while (UART2_FR_R & UART_FR_RXFE);      // Wait until data is received
    return (char)(UART2_DR_R & 0xFF);
}

void UART2_ReadString(char *line, uint8_t length) {
    char c;
    uint8_t i;

    for (i=0; i < length-1; i++)
    {
        c = UART2_ReadChar();
        if (c == '\r' || c == '\n') { // Stop on return/newline
            break;
        }
        line[i] = c; // Store the character
    }
    
    line[i] = '\0';
}

