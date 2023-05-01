// LCD_main.c
// Runs on TM4C123
// Test the functions in ST7735.c by printing basic
// patterns to the LCD.
// 16-bit color, 128 wide by 128 high LCD
// Daniel Valvano
// March 30, 2015

// Edited: Vamsi Borra
// Date: 4/10/2019
// Edited Again: Andrew Geyer and Cody Garcia
// Date: 4/24/2019

// Edited: Vamsi Borra
// Date: 11/23/2021



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
void StartUpScreen(void);
void FlashingLetters(void);
void LoadingBar(void);
void static drawthecolors(uint8_t red, uint8_t green, uint8_t blue);
//void LCDMain();

//int main(void){
//  Output_Init();              // initialize output device
//  Output_Color(ST7735_RED);
//	printf(" \n");      //Formatting
//	printf(" Music Player:\n");      //Print Statement
//	ST7735_DrawFastHLine(1, 20, 120, ST7735_BLUE);
//	printf(" Current MIDI:\n");				//Print Statement
//  }

int main(void)
	{
			Output_Init(); 
		//uint32_t t,n;
			
			
		
			LoadingBar();
		
		
		uint8_t red, green, blue;
		  // test display with a colorful demo
			red = 0;
			green = 0;
			blue = 255;
			static uint16_t i = 0;
		
		while(i<= 1){
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
		i--;
  }
			Output_Init(); 

	
			DelayWait10ms(10);
		
			StartUpScreen();
		
			DelayWait10ms(10);

			FlashingLetters();
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


void static drawthecolors(uint8_t red, uint8_t green, uint8_t blue){
  static uint16_t y = 0, x = 0;
  ST7735_DrawFastHLine(0, y, ST7735_TFTWIDTH, ST7735_Color565(red, green, blue));
	ST7735_DrawFastVLine(x, 0, ST7735_TFTHEIGHT, ST7735_Color565(red, green, blue));
  y = y + 1;
	x = x + 1;
  if(y >= ST7735_TFTHEIGHT){
     y = 0;
  }
	if(x >= ST7735_TFTWIDTH){
     x = 0;
  }
  DelayWait10ms(1);
}

//Subroutine for Loading Bar
//Inputs: None
//Outputs: None
void LoadingBar(){
			ST7735_SetCursor(4, 30);
			ST7735_SetTextColor(ST7735_YELLOW);
			
			ST7735_DrawString(1, 6, "Loading...", ST7735_YELLOW);
			ST7735_FillRect(4, 10, 2, 8, ST7735_RED);
			DelayWait10ms(10);
			ST7735_FillRect(4, 10, 4, 8, ST7735_RED);
			DelayWait10ms(10);
			ST7735_FillRect(4, 10, 8, 8, ST7735_RED);
			DelayWait10ms(10);
			ST7735_FillRect(4, 10, 16, 8, ST7735_RED);
			DelayWait10ms(10);
			ST7735_FillRect(4, 10, 32, 8, ST7735_RED);
			DelayWait10ms(10);
			ST7735_FillRect(4, 10, 64, 8, ST7735_RED);
			DelayWait10ms(10);
			ST7735_FillRect(4, 10, 75, 8, ST7735_RED);
			DelayWait10ms(10);
			ST7735_FillRect(4, 10, 100, 8, ST7735_RED);
			DelayWait10ms(100);
			ST7735_DrawString(1, 6, "ERROR!!!!", ST7735_BLUE);
			DelayWait10ms(200);
			ST7735_DrawString(1, 6, "OOPS!", ST7735_YELLOW);
			DelayWait10ms(60);
			ST7735_DrawString(1, 6, "Just Kidding...", ST7735_YELLOW);
			DelayWait10ms(60);
			ST7735_FillRect(4, 10, 120, 8, ST7735_GREEN);
			ST7735_DrawString(1, 6, "STARTUP SUCCESSFUL", ST7735_GREEN);
			DelayWait10ms(100);
			ST7735_SetCursor(0, 0);
			Output_Clear();
		}
	

//Subroutine for Startup Sequence
//Inputs: None
//Outputs: None
void StartUpScreen(){
			ST7735_DrawChar(4, 20, 'G', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(14, 20, 'O', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(24, 20, 'O', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(34, 20, 'D', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(44, 20, 'D', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(4, 40, 'L', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(14, 40, 'U', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(24, 40, 'C', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(34, 40, 'K', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
			ST7735_DrawCharS(44, 40, ':', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(54, 40, '-', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);
		  ST7735_DrawCharS(64, 40, ')', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(20);			
			ST7735_SetCursor(0, 0);
			ST7735_SetTextColor(ST7735_YELLOW);
			ST7735_DrawString(1, 6, "Current MIDI:", ST7735_YELLOW);
			ST7735_DrawString(1, 7, "SONG NAME", ST7735_YELLOW);
			ST7735_SetTextColor(ST7735_CYAN);
			ST7735_DrawString(1, 9, "Press Buttons For", ST7735_CYAN);
			ST7735_DrawString(1, 10, "Track Controls:", ST7735_CYAN);
			ST7735_DrawString(1, 11, "<RW><PLAY/STOP><FF>", ST7735_CYAN);
		}
	

void FlashingLetters(){
			while(1){
			ST7735_DrawChar(4, 20, 'M', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(14, 20, 'U', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(24, 20, 'S', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(34, 20, 'I', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(44, 20, 'C', ST7735_RED, ST7735_BLACK, 2);
			DelayWait10ms(5);
			ST7735_DrawChar(4, 20, 'M', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(14, 20, 'U', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(24, 20, 'S', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(34, 20, 'I', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(44, 20, 'C', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(1);
		  ST7735_DrawCharS(4, 40, 'P', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(14, 40, 'L', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(24, 40, 'A', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(34, 40, 'Y', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(44, 40, 'E', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(54, 40, 'R', ST7735_RED, ST7735_BLACK, 2);
		  ST7735_DrawCharS(64, 40, '!', ST7735_RED, ST7735_BLACK, 2);
			DelayWait10ms(5);
			ST7735_DrawCharS(4, 40, 'P', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(14, 40, 'L', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(24, 40, 'A', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(34, 40, 'Y', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(44, 40, 'E', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(54, 40, 'R', ST7735_WHITE, ST7735_BLACK, 2);
		  ST7735_DrawCharS(64, 40, '!', ST7735_WHITE, ST7735_BLACK, 2);
			DelayWait10ms(1);
		}}		