/*
* Assignment 4
*
* a4.c
*
* A program which displays a scrolling message on two lines
* of an LCD display.
*
* Button Functionality:
* 	up - pause scrolling
* 	down - resume scrolling
* 	left - increase scroll speed
* 	     - increases LEDs toward pin 42(PORTL bit7)
* 	right - decrease scroll speed
* 	      - decreases LEDs toward pin 52(PORTB bit1)
* 	select - change display message
* 		   - displays and then reverts back to main scrolling message 
*		     after a short delay
*  
* This program is designed with the assumption that the button
* activation ranges are:
* 
* value = (ADCH << 8) +  ADCL
*
* value > 0x3E8 - no button pressed 	 0b00 1111 1010 00
*
* Otherwise:
* value < 0x032 - right button pressed - 0b00 0000 1100 10
* value < 0x0C3 - up button pressed	   - 0b00 0011 0000 11
* value < 0x17C - down button pressed  - 0b00 0101 1111 00
* value < 0x22B - left button pressed  - 0b00 1000 1010 11
* value < 0x316 - sel button pressed   - 0b00 1100 0101 10 
*
*
* Author: Mark Worrall - 07/25/16
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "main.h"
#include "lcd_drv.h"


int button = 0;
int pause = 0;
int delay_value = 4;
int press = 0;

// These are included by the LCD driver code, so 
// we don't need to include them here.
// #include <avr/io.h>
// #include <util/delay.h>


void clear_screen(){
		lcd_command( 0x01 );
}

/*
* Returns the number of characters in a null terminated
* C-string.
*/
int len(char* s){
	int i = 0;
	while(s[i] != 0){
		i++;
	}
	return i;
}
/*
* Pre-conditions:
* 	buff is a string array of at least length 16, ptr 
*   is a pointer to a character in a C-string, and s is the
*   C-string which ptr is pointing to.
* 
* Post-conditions:
*	buff is populated with chars from s starting from the char which
*	ptr is pointing to. The chars will be taken from the beginning of
*	s if ptr reaches the end of s
*/ 
void fill_buffer(char* buff, char* ptr, char* s){
		for(int p = 0; p < 16;p++){
			if(p < len(ptr)){
				buff[p] = ptr[p];
			} else {
				buff[p] = s[p-len(ptr)];
			}
		}
}
/*
* A function which initiates the adc and then reads the 
* result to determine which function is activated if any.
* Also return a value specific to each button:
* 	right - 1
*	up - 2
* 	down - 4
* 	left - 8
* 	select - 16
*/
int check_button(){
	
	// start conversion
	ADCSRA |= 0x40;

	// bit 6 in ADCSRA is 1 while conversion is in progress
	// 0b0100 0000
	// 0x40
	while (ADCSRA & 0x40)
		;
	unsigned int val = ADCL;
	unsigned int val2 = ADCH;

	val += (val2 << 8);
	
	/* From the arduino example sketch, we have:
	 *
 	 *  if (adc_key > 1000 )   return btnNONE;
	 *  if (adc_key_in < 50)   return btnRIGHT;  
	 *  if (adc_key_in < 195)  return btnUP; 
	 *  if (adc_key_in < 380)  return btnDOWN; 
	 *  if (adc_key_in < 555)  return btnLEFT; 
	 *  if (adc_key_in < 790)  return btnSELECT;   
	 */
	if(press == 1){
		if(val > 900) press = 0;
		return 0;
	}
	if(val<790) press = 1;

	if (val < 50){   //right-inc. scroll speed, inc led
	  if(delay_value>2) delay_value--;
	  inc_led();
	  return 1;  
    }else if (val < 195){//up-pause scroll
	  pause = 1;
	  return 2;  
    }else if (val < 380){//down-resume scroll
	  pause = 0; 
	  return 4;  
    }else if (val < 555){//left-dec. scroll speed, dec led
	  if(delay_value<6)delay_value++;
	  dec_led();
	  return 8;  
    }else if (val < 790){//sel-display alternate message
	  alt_msg();
	  return 16;
	}else 
	  return 0;  
}

/*
* Delay takes a multiplier argument which produces a delay
* equal to multiplier*100ms. Also calls the check_button()
* function every 100ms. 
*/
void delay(int multiplier){
	for(int i =0; i < multiplier; i++){
		_delay_ms(100);
		button = check_button();
	}
}

void led_init(){
	DDRB = 0xFF;
	DDRL = 0xFF;

	PORTB = 0;
	PORTL = 0x0A;
}

void inc_led(){
	if(PORTL==0x80){
		return;
	}else if(PORTL==0x20){
		PORTL = 0x80;
	}else if(PORTL==0x08){
		PORTL = 0x20;
	}else if(PORTL==0x0A){
		PORTL = 0x08;
	}else if(PORTL==0x02){
		PORTL = 0x0A;
	}else if(PORTL==0x00){
		if(PORTB==0x08){
			PORTL = 0x02;
			PORTB = 0x00;
		}else{
			PORTB = 0x08;
		}
	}
}

void dec_led(){
	if(PORTL==0x80){
		PORTL = 0x20;
	}else if(PORTL==0x20){
		PORTL = 0x08;
	}else if(PORTL==0x08){
		PORTL = 0x0A;
	}else if(PORTL==0x0A){
		PORTL = 0x02;
	}else if(PORTL==0x02){
		PORTL = 0x00;
		PORTB = 0x08;
	}else if(PORTL==0x00){
		if(PORTB==0x08){
			PORTB = 0x02;
		}else{
			return;
		}
	}
}
/*
* Displays an alternate message for 3 seconds.
*/
void alt_msg(){
	char* s_alt1 = "This Feature Is";
	char* s_alt2 = "Not Available";
	clear_screen();
	lcd_xy(0,0);
	lcd_puts(s_alt1);
	lcd_xy(0,1);
	lcd_puts(s_alt2);
	for(int i = 0;i < 3;i++){
		_delay_ms(1000);
	}
	clear_screen();
}

int main( void )
{

	lcd_init();
	led_init();
	
	/* enable A2D: */

	/* ADCSRA:
	 * bit 7 - ADC enable
	 * bit 6 - ADC start conversion
	 * bit 5 - ADC auto trigger enable
	 * bit 4 - ADC interrupt flag
	 * bit 3 - ADC interrupt enable
	 * bit 2 |
	 * bit 1 |- ADC prescalar select bits
	 * bit 0 |
	 * 
	 * we want:
	 * 0b1000 0111
	 * which is:
	 * 0x87
	 */
	ADCSRA = 0x87;

	/* ADMUX - ADC Multiplexer Selection Register
	 *
	 * Select ADC0
     */
	ADMUX = 0x40;

	unsigned int i=0, j=0;
	char* s1 = "This a message to the reader - ";
	char* s2 = "- hello - hello - hello ";
	char* ptr1 = s1;
	char* ptr2 = s2;
	char buff1[16];
	char buff2[16];
	
//Infinite loops runs the scrolling
	for(;;){
		ptr1 = &s1[i];
		ptr2 = &s2[j];
		
		fill_buffer(buff1, ptr1, s1);
		fill_buffer(buff2, ptr2, s2);
		lcd_xy(0,0);
		lcd_puts(buff1);
		lcd_xy(0,1);
		lcd_puts(buff2);
		if(i<(len(s1)-1) && !pause){
			i++;
		}else if(pause){
			
		}else{
			i = 0;
		}
		if(j<(len(s2)-1) && !pause){
			j++;
		}else if(pause){
			
		}else{
			j = 0;
		}
		delay(delay_value);
		clear_screen();
	}
}
