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



int main(void){uint32_t j; // main 1
  PLL_Init();
  ST7735_InitR(INITR_REDTAB);
  printf("\n");
	ST7735_OutString(" Graphics test\n");
  ST7735_OutString(" cubic function\n");
  ST7735_PlotClear(0,4095);  // range from 0 to 4095
  for(j=0;j<128;j++){
    ST7735_PlotPoints(j*j/2+900-(j*j/256)*j,32*j); // cubic,linear
    ST7735_PlotNext();
  }   // called 128 times
  while(1){
  }
}
