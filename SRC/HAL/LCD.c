#include "../../HEADERS/HAL/LCD.h"

/*
    d0=a7
    d1=a6
    d2=a5
    d3=b4
    d4=e5
    d5=e4
    d6=b1
    d7=b0

    RS = d0
    RW = d1
    E  = d2
*/

void Printdata(unsigned char data)
{
    //d0 = a7
    if((data& 0x01) == 0x01){
        GPIO_PORTA_DATA_R |= (1<<7);
    }
    else{
        GPIO_PORTA_DATA_R &= ~(1<<7);
    }
    //d1 = a6
    if((data& 0x02) == 0x02){
        GPIO_PORTA_DATA_R |= (1<<6);
    }
    else{
        GPIO_PORTA_DATA_R &= ~(1<<6);
    }
    //d2 = a5
    if((data& 0x04) == 0x04){
        GPIO_PORTA_DATA_R |= (1<<5);
    }
    else{
        GPIO_PORTA_DATA_R &= ~(1<<5);
    }
    //d3 = b4
    if((data& 0x08) == 0x08){
        GPIO_PORTB_DATA_R |= (1<<4);
    }
    else{
        GPIO_PORTB_DATA_R &= ~(1<<4);
    }
    //d4 = E5
    if((data& 0x10) == 0x10){
        GPIO_PORTE_DATA_R |= (1<<5);
    }
    else{
        GPIO_PORTE_DATA_R &= ~(1<<5);
    }
    //d5 = E4
    if((data& 0x20) == 0x20){
        GPIO_PORTE_DATA_R |= (1<<4);
    }
    else{
        GPIO_PORTE_DATA_R &= ~(1<<4);
    }
    //d6 = b1
    if((data& 0x40) == 0x40){
        GPIO_PORTB_DATA_R |= (1<<1);
    }
    else{
        GPIO_PORTB_DATA_R &= ~(1<<1);
    }
    //d7 = b0
    if((data& 0x80) == 0x80){
        GPIO_PORTB_DATA_R |= (1<<0);
    }
    else{
        GPIO_PORTB_DATA_R &= ~(1<<0);
    }
}

void Lcd_init(void)
{
    Lcd_ports_init(); 

    SysTick_Wait1ms(1); // delay remove it when delay of timer is implemented

    Lcd_command(Fn_set); 
    Lcd_command(AUTO_CUORSER_INC); 
    Lcd_command(EN_DISP_CURSOR_OFF); 
    Lcd_command(CLEAR); 
    Lcd_command(INITIAL_POSITION); 
}

void Lcd_data(unsigned char data)
{
    GPIO_PORTD_DATA_R |= RS_ON; 
    GPIO_PORTD_DATA_R &= ~(RW_ON); 
    Printdata(data);
    GPIO_PORTD_DATA_R |= EN_ON; 
    SysTick_Wait1us(10); // delay remoce it when delay of timer is implemented
    GPIO_PORTD_DATA_R &= ~(EN_ON); 
    SysTick_Wait1us(10); // delay remoce it when delay of timer is implemented
}

void Lcd_command(unsigned char command)
{
    GPIO_PORTD_DATA_R &= ~(RS_ON); 
    GPIO_PORTD_DATA_R &= ~(RW_ON); 
    Printdata(command);
    GPIO_PORTD_DATA_R |= EN_ON; 
    SysTick_Wait1us(10); // delay remove it when delay of timer is implemented
    GPIO_PORTD_DATA_R &= ~(EN_ON); 
    SysTick_Wait1us(10); // delay remove it when delay of timer is implemented
}

void Lcd_string(char *str)
{
    while(*str != '\0')
    {
        unsigned char c = *str;
        Lcd_data(c);
        str++;
    }
}

void Lcd_clear(void)
{
    Lcd_command(CLEAR); 
    Lcd_command(INITIAL_POSITION); 
}
