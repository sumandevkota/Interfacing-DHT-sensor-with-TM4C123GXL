// LCD_main.c
// Runs on TM4C123
// Test the functions in ST7735.c by printing basic
// patterns to the LCD.
// 16-bit color, 128 wide by 128 high LCD
// Daniel Valvano
// March 30, 2015

// Edited: Vamsi Borra
// Date: 11/23/2021

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
 You may use, edit, run or distribute this file
 as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

// hardware connections
// **********ST7735 TFT AFL 128128A0-1.44N12NTM
// ST7735
// LED (pin 8) Backlight connected to +3.3 V
// CS  (pin 7) connected to PA3 (SSI0Fss)
// DC - Data/Command (pin 6) connected to PA6, high for 
// data, low for command
// RESET (pin 5) connected to PA7 (GPIO)
// SDA (pin 4) connected to PA5 (SSI0Tx)
// SCL (pin 3) connected to PA2 (SSI0Clk)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground




#include <stdio.h>
#include <stdint.h>
#include "ST7735.h"
#include "PLL.h"
#include "tm4c123gh6pm.h"

void DelayWait10ms(uint32_t n);


int main(void)
	{
		int i;
  PLL_Init();
  Output_Init();
		for(i=0;i<4;i++)
		{
			printf("\n");
		}
		
		printf(" Ok, you connected");
    printf("\n the LCD properly !!");
		
  while(1)
	{
		
  }
	
	}
