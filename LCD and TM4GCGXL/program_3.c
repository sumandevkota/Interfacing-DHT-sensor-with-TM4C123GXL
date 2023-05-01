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

int main(void){
	
	
  
  while(1)
{
	
int x, y, dx, dy;
//  uint8_t red, green, blue;
  PLL_Init();                           // set system clock to 80 MHz
  // test DrawChar() and DrawCharS()
  ST7735_InitR(INITR_REDTAB);
  ST7735_DrawCharS(0, 0, 'c', ST7735_Color565(255, 0, 0), 0, 1);
  ST7735_DrawCharS(6, 0, 'h', ST7735_Color565(255, 128, 0), 0, 1);
  ST7735_DrawCharS(12, 0, 'a', ST7735_Color565(255, 255, 0), 0, 1);
  ST7735_DrawCharS(18, 0, 'r', ST7735_Color565(128, 255, 0), 0, 1);
  ST7735_DrawCharS(30, 0, 'T', ST7735_Color565(0, 255, 0), 0, 1);
  ST7735_DrawCharS(36, 0, 'E', ST7735_Color565(0, 255, 255), 0, 1);
  ST7735_DrawCharS(42, 0, 'S', ST7735_Color565(0, 0, 255), 0, 1);
  ST7735_DrawCharS(48, 0, 'T', ST7735_Color565(128, 0, 255), 0, 1);

  ST7735_DrawCharS(0, 8, 'c', ST7735_Color565(255, 0, 0), 0, 2);
  ST7735_DrawCharS(12, 8, 'h', ST7735_Color565(255, 128, 0), 0, 2);
  ST7735_DrawCharS(24, 8, 'a', ST7735_Color565(255, 255, 0), 0, 2);
  ST7735_DrawCharS(36, 8, 'r', ST7735_Color565(128, 255, 0), 0, 2);
  ST7735_DrawCharS(60, 8, 'T', ST7735_Color565(0, 255, 0), 0, 2);
  ST7735_DrawCharS(72, 8, 'E', ST7735_Color565(0, 255, 255), 0, 2);
  ST7735_DrawCharS(84, 8, 'S', ST7735_Color565(0, 0, 255), 0, 2);
  ST7735_DrawCharS(96, 8, 'T', ST7735_Color565(128, 0, 255), 0, 2);

  ST7735_DrawCharS(0, 24, 'c', ST7735_Color565(255, 0, 0), 0, 3);
  ST7735_DrawCharS(18, 24, 'h', ST7735_Color565(255, 128, 0), 0, 3);
  ST7735_DrawCharS(36, 24, 'a', ST7735_Color565(255, 255, 0), 0, 3);
  ST7735_DrawCharS(54, 24, 'r', ST7735_Color565(128, 255, 0), 0, 3);
  ST7735_DrawCharS(90, 24, 'T', ST7735_Color565(0, 255, 0), 0, 3);
  ST7735_DrawCharS(108, 24, 'E', ST7735_Color565(0, 255, 255), 0, 3);
  ST7735_DrawCharS(126, 24, 'S', ST7735_Color565(0, 0, 255), 0, 3); // off the screen
  ST7735_DrawCharS(144, 24, 'T', ST7735_Color565(128, 0, 255), 0, 3); // totally off the screen

  ST7735_DrawCharS(0, 48, 'c', ST7735_Color565(255, 0, 0), 0, 4);
  ST7735_DrawCharS(24, 48, 'h', ST7735_Color565(255, 128, 0), 0, 4);
  ST7735_DrawCharS(48, 48, 'a', ST7735_Color565(255, 255, 0), 0, 4);
  ST7735_DrawCharS(72, 48, 'r', ST7735_Color565(128, 255, 0), 0, 4);
  ST7735_DrawCharS(120, 48, 'T', ST7735_Color565(0, 255, 0), 0, 4); // off the screen
  ST7735_DrawCharS(144, 48, 'E', ST7735_Color565(0, 255, 255), 0, 4); // totally off the screen
  ST7735_DrawCharS(168, 48, 'S', ST7735_Color565(0, 0, 255), 0, 4); // totally off the screen
  ST7735_DrawCharS(192, 48, 'T', ST7735_Color565(128, 0, 255), 0, 4); // totally off the screen

  ST7735_DrawCharS(0, 80, 'c', ST7735_Color565(255, 0, 0), 0, 6);
  ST7735_DrawCharS(36, 80, 'h', ST7735_Color565(255, 128, 0), 0, 6);
  ST7735_DrawCharS(72, 80, 'a', ST7735_Color565(255, 255, 0), 0, 6);
  ST7735_DrawCharS(108, 80, 'r', ST7735_Color565(128, 255, 0), 0, 6); // off the screen

  ST7735_DrawChar(0, 135, 'A', ST7735_Color565(255, 128, 128), 0, 2);
  ST7735_DrawChar(12, 135, 'd', ST7735_Color565(255, 0, 0), 0, 2);
  ST7735_DrawChar(24, 135, 'v', ST7735_Color565(255, 128, 0), 0, 2);
  ST7735_DrawChar(48, 135, 'c', ST7735_Color565(255, 255, 0), 0, 2);
  ST7735_DrawChar(60, 135, 'h', ST7735_Color565(128, 255, 0), 0, 2);
  ST7735_DrawChar(72, 135, 'a', ST7735_Color565(0, 255, 0), 0, 2);
  ST7735_DrawChar(84, 135, 'r', ST7735_Color565(0, 255, 255), 0, 2);
  ST7735_DrawChar(108, 135, 't', ST7735_Color565(0, 0, 255), 0, 2);
  ST7735_DrawChar(120, 135, 'e', ST7735_Color565(128, 0, 255), 0, 2); // off the screen
  ST7735_DrawChar(132, 135, 's', ST7735_Color565(255, 0, 255), 0, 2); // totally off the screen
  ST7735_DrawChar(144, 135, 't', ST7735_Color565(255, 255, 255), 0, 2); // totally off the screen

  ST7735_DrawChar(0, 151, 'A', ST7735_Color565(255, 128, 128), 0, 1);
  ST7735_DrawChar(6, 151, 'd', ST7735_Color565(255, 0, 0), 0, 1);
  ST7735_DrawChar(12, 151, 'v', ST7735_Color565(255, 128, 0), 0, 1);
  ST7735_DrawChar(24, 151, 'c', ST7735_Color565(255, 255, 0), 0, 1);
  ST7735_DrawChar(30, 151, 'h', ST7735_Color565(128, 255, 0), 0, 1);
  ST7735_DrawChar(36, 151, 'a', ST7735_Color565(0, 255, 0), 0, 1);
  ST7735_DrawChar(42, 151, 'r', ST7735_Color565(0, 255, 255), 0, 1);
  ST7735_DrawChar(54, 151, 't', ST7735_Color565(0, 0, 255), 0, 1);
  ST7735_DrawChar(60, 151, 'e', ST7735_Color565(128, 0, 255), 0, 1);
  ST7735_DrawChar(66, 151, 's', ST7735_Color565(255, 0, 255), 0, 1);
  ST7735_DrawChar(72, 151, 't', ST7735_Color565(255, 255, 255), 0, 1);
  DelayWait10ms(100);

  // test DrawBitmap() including clipping test with images off the screen
  ST7735_FillScreen(0xFFFF);            // set screen to white
  ST7735_DrawBitmap(0, 5, Test2, 5, 6);   // top left corner of the screen
  ST7735_DrawBitmap(59, 74, Test2, 5, 6); // center of the screen
  ST7735_DrawBitmap(125, 74, Test2, 5, 6);// clip right
  ST7735_DrawBitmap(59, 162, Test2, 5, 6);// clip bottom
  ST7735_DrawBitmap(-2, 74, Test2, 5, 6); // clip left
  ST7735_DrawBitmap(59, 2, Test2, 5, 6);  // clip top
  DelayWait10ms(100);

  ST7735_FillScreen(0xFFFF);            // set screen to white	
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
