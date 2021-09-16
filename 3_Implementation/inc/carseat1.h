/**
 * @file carseat1.h
 * @Shivam_sas (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CARSEAT1_H_INCLUDED
#define CARSEAT1_H_INCLUDED

#include <avr/io.h>			/* Header files */
#include <util/delay.h>		/* Header files */

#define LCD_DIRECTION  DDRB			
#define PORT_B PORTB			/* data port define*/
#define LCD_EN PB3 				/*Signal pin enable  */
#define LCD_RS PB2				/*Signal pin enable */


void LCD_CMD( unsigned char command );
void LCD_CHAR_WISE( unsigned char ch );
void DECLARATION_LCD(void);
void LCD_DISPLAY (char *temperature_value);
void CLEAR_LCD();

#endif 
