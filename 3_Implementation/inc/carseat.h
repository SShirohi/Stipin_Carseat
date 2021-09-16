/**
 * @file carseat.h
 * @Shivam_sas (you@domain.com)
 * @brief Initialization of seat, heater and led
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CARSEAT_H_INCLUDED
#define CARSEAT_H_INCLUDED

#include <avr/io.h>
#include<util/delay.h>


#define TIMER1_FAST_PWM TCCR1A|=(1<<COM1A1)|(1<<WGM10)|(1<<WGM11)
#define TIMER_PRESCALER_AS_64 TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10)
#define PWM_OUTPUT_PIN DDRB|=(1<<PB1)


#define STATUS_SEAT !(PIND &(1<<PD0))
#define ONHEATER (PIND &(1<<PD2))
#define OFFHEATER PORTD&=~(1<<PD2)
#define OFFLED PORTD &=~(1<<PD0)
#define ONLED PORTD|=(1<<PD0)  // definind the real pins


void SEAT_CHECKING();
uint16_t SENSE_ADC(uint8_t channel);
void DECLARATION_ADC();
void DECLARATION_TIMER(void);
void PWM_OUPUT(uint16_t ADC_READING);

#endif 

#endif 
