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

const uint16_t Test2[] = {
  0x0000, 0x4208, 0x8410, 0xC618, 0xFFFF,
  0x001F, 0x07FF, 0x07E0, 0xF800, 0x0000,
  0x001F, 0x07FF, 0x07E0, 0xF800, 0xFFFF,
  0x001F, 0x07FF, 0x07E0, 0xF800, 0x0000,
  0x001F, 0x07FF, 0x07E0, 0xF800, 0xFFFF,
  0x001F, 0x07FF, 0x07E0, 0xF800, 0x0000
};





// private function draws a color band on the screen
void static drawthecolors(uint8_t red, uint8_t green, uint8_t blue){
  static uint16_t y = 0;
  ST7735_DrawFastHLine(0, y, ST7735_TFTWIDTH, ST7735_Color565(red, green, blue));
  y = y + 1;
  if(y >= ST7735_TFTHEIGHT){
     y = 0;
  }
  DelayWait10ms(1);
}
int main(void){ // main3
  uint8_t red, green, blue;
  PLL_Init();                           // set system clock to 80 MHz
  // test DrawChar() and DrawCharS()
  ST7735_InitR(INITR_REDTAB);

  // test display with a colorful demo
  red = 255;
  green = 0;
  blue = 0;
  while(1){
    // transition from red to yellow by increasing green
    for(green=0; green<255; green=green+1){
      drawthecolors(red, green, blue);
    }
    // transition from yellow to green by decreasing red
    for(red=255; red>0; red=red-1){
      drawthecolors(red, green, blue);
    }
    // transition from green to light blue by increasing blue
    for(blue=0; blue<255; blue=blue+1){
      drawthecolors(red, green, blue);
    }
    // transition from light blue to true blue by decreasing green
    for(green=255; green>0; green=green-1){
      drawthecolors(red, green, blue);
    }
    // transition from true blue to pink by increasing red
    for(red=0; red<255; red=red+1){
      drawthecolors(red, green, blue);
    }
    // transition from pink to red by decreasing blue
    for(blue=255; blue>0; blue=blue-1){
      drawthecolors(red, green, blue);
    }
  }
}
// Subroutine to wait 10 msec
// Inputs: None
// Outputs: None
// Notes: ...
void DelayWait10ms(uint32_t n){uint32_t volatile time;
  while(n){
    time = 727240*2/91;  // 10msec
    while(time){
      time--;
    }
    n--;
  }
}
