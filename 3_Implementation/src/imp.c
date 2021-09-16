/**
 * @file imp.c
 * @author SHIVAM_sas (you@domain.com)
 * @brief Heat Monitoring System
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include<util/delay.h>
#include "carseat.h"
#include "carseat1.h"

int main(void)
{
    STATUS_SEAT(); //Initializing Drivers seat
    DECLARATION_ADC(); //Initializing ADC to accept temperature values
    DECLARATION_TIMER(); //Initializing Timer by dividing clock with 64 prescale
    DECLARATION_LCD(); //Initializing LCD

    uint16_t read;
while(1)
    {
 if(SEAT_CHECK)
{
  PORTD|=(1<<PD2);
 if(HEATER_ON){
  LED_ON
    _delay_ms(200);
    CLEAR_LCD();
 read=SENSE_ADC(0);
   PWM_OUPUT(read);
 }
   else
   {
   LED_OFF;
 _delay_ms(200);
   HEATER_OFF;
    _delay_ms(200);
      CLEAR_LCD();
  }
   }
  else{
  LED_OFF;
_delay_ms(200);
   HEATER_OFF;
_delay_ms(200);
    CLEAR_LCD();
  }
    }
    return 0;
}
