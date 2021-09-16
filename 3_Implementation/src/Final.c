/**
 * @file carseat.c
 * @authorShivam_sas (you@domain.com)
 * @brief Seat Checking
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "carseat.h"

void STATUS_SEAT(){
    DDRD|=(1<<PD0); //Setting PDO pin
    DDRD&=~(1<<PD1); //clearing PD1 pin
    PORTD|=(1<<PD1); //Setting PD1 pin
    DDRD&=~(1<<PD2); //clearing PD2 pin
    PORTD|=(1<<PD2); //Setting PD2 pin
}

void LCD_CMD( unsigned char command )
{
	PORT_B = (PORT_B & 0x0F) | (command & 0xF0); // Taking Upper nibble only
	PORT_B &= ~ (1<<LCD_RS); // Making LCD_RS=0
	PORT_B |= (1<<LCD_EN); // Enabling EN=1
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);

	_delay_us(250);

	PORT_B = (PORT_B & 0x0F) | (command << 4); //Taking Lower nibble only
	PORT_B |= (1<<LCD_EN);
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);
	_delay_ms(50);
}

void LCD_CHAR_WISE( unsigned char ch )
{
	PORT_B = (PORT_B & 0x0F) | (ch & 0xF0); /* sending upper nibble */
	PORT_B |= (1<<LCD_RS);		/* LCD_RS=1, ch reg. */
	PORT_B|= (1<<LCD_EN);
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);

	_delay_us(250);

	PORT_B = (PORT_B & 0x0F) | (ch << 4); /* sending lower nibble */
	PORT_B |= (1<<LCD_EN);
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);
	_delay_ms(50);
}


void DECLARATION_LCD(void)
{
	LCD_DIRECTION = 0xFF; // LCD port as output
	_delay_ms(50);

	LCD_CMD(0x02);	// 4 bit LCD
	LCD_CMD(0x28);  // 5x7 Matrix(2 line)
	LCD_CMD(0x0c);  // Display On cursor Off
	LCD_CMD(0x06);  // Increment cursor
	LCD_CMD(0x01);  // LCD Clear
	_delay_ms(5);
}

void LCD_DISPLAY (char *temperature_value)
{
	int Index;
	for(Index=0;temperature_value[Index]!=0;Index++)
	{
		LCD_CHAR_WISE(temperature_value[Index]);
	}
}


void CLEAR_LCD()
{
	LCD_CMD (0x01);	// LCD Clear
	_delay_ms(50);
	LCD_CMD (0x80);	// cursor back to start position
}
void DECLARATION_ADC()
{
    ADMUX=(1<<REFS0);   //AVCC = +5V
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}


uint16_t SENSE_ADC(uint8_t channel)
{
    // Making ADC to accept channels from 0-7
    ADMUX&=0xf8;
    channel=channel&0b00000111;
    ADMUX|=channel;

    ADCSRA|=(1<<ADSC); //Enable Conversion

    while(!(ADCSRA & (1<<ADIF))); // Transferring the data

    ADCSRA|=(1<<ADIF); // ADIF=0
    return(ADC);
}

void DECLARATION_TIMER(void){

    TIMER1_FAST_PWM;
    TIMER_PRESCALER_AS_64;
    PWM_OUTPUT_PIN;
}

void PWM_OUPUT(uint16_t ADC_READING){
    char Temp[20];
    char start[]="Temperature :)";

    if(ADC_READING>0 && ADC_READING<=200){

        OCR1A = 195; // Duty cycle 20%
        Temp[0] = '2';
        Temp[1] = '0';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=210) && (ADC_READING<=500)){

        OCR1A = 495; // duty cycle 40%
        Temp[0] = '2';
        Temp[1] = '5';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=501) && (ADC_READING<=700)){

        OCR1A = 695;// duty cycle 70%
        Temp[0] = '2';
        Temp[1] = '9';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=701) && (ADC_READING<=1024)){

        OCR1A = 1019; // duty cycle 95%
        Temp[0] = '3';
        Temp[1] = '3';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }
    else{
        OCR1A = 0; // Duty cycle 0%
        Temp[0] = 'O';
        Temp[1] = 'F';
        Temp[2] = 'F';
        Temp[3] = ' ';
        Temp[4] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }

}
