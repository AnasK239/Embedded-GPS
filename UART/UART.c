#include "UART.h"


void UART_Init(){
    SET_BIT(SYSCTL_RCGCUART_R, UART_2);
    while (GET_BIT(SYSCTL_PRUART_R, UART_2) == 0);
    SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_D);
    while (GET_BIT(SYSCTL_PRGPIO_R, GPIO_D) == 0);

    CLR_BIT(UART2_CTL_R, 0); // Disable UART2
    UART2_IBRD_R = int_baud;
    UART2_FBRD_R = Float_baud;
    SET(UART2_LCRH_R, Input_Shape);
    SET(UART2_CTL_R, Control_Shape);

    SET(GPIO_PORTD_AFSEL_R, Functions_D6_D7);
    SET(GPIO_PORTD_DEN_R, Functions_D6_D7);
    CLR(GPIO_PORTD_PCTL_R, Clear_PCTL_D6_D7);
    SET(GPIO_PORTD_PCTL_R, Set_PCTL_D6_D7);
    CLR(GPIO_PORTD_AMSEL_R, Functions_D6_D7);
    
    SET(GPIO_PORTD_DIR_R, 0x80); // Set PD7 as output (TX) and PD6 as input (RX)
}

char UART2_ReadChar(void) {
    while ((UART2_FR_R & UART_FR_RXFE) != 0);      // Wait until data is received
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

