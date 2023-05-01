
// Vamsi Borra
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
void StartUpScreen(void);
void FlashingLetters(void);
void LoadingBar(uint16_t x, uint16_t color );

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
		static uint16_t j = 0;
		//uint32_t t,n;
			while(j<=10)
			{
			LoadingBar( 10+ (j*10), ST7735_GREEN);
			LoadingBar( 10+ (j*10), ST7735_BLACK);
	
			LoadingBar( 20+ (j*10), ST7735_CYAN);
			LoadingBar( 20+ (j*10), ST7735_BLACK);

			
			LoadingBar( 30+ (j*10), ST7735_BLUE);
			LoadingBar( 30+ (j*10), ST7735_BLACK);
			
			LoadingBar( 40+ (j*10), ST7735_RED);
			LoadingBar( 40+ (j*10), ST7735_BLACK);
			
			LoadingBar( 50+ (j*10), ST7735_MAGENTA);
			LoadingBar( 50+ (j*10), ST7735_BLACK);

				
			LoadingBar( 60+ (j*10), ST7735_YELLOW);
			LoadingBar( 60+ (j*10), ST7735_BLACK);
			
			LoadingBar( 70+ (j*10), ST7735_WHITE);
			LoadingBar( 70+ (j*10), ST7735_BLACK);
			j++;
			if (j<=11)
				{
					j = 0;
				}
			}
			
		

	}
// Subroutine to wait 10 msec
// Inputs: None
// Outputs: None
// Notes: ...
void DelayWait10ms(uint32_t n){uint32_t volatile time;
  while(n){
    time = 727*2/910;  // 10msec
    while(time){
      time--;
    }
    n--;
  }
}



//Subroutine for Loading Bar
//Inputs: None
//Outputs: None
void LoadingBar(uint16_t x, uint16_t color ){
			//ST7735_SetCursor(4, 30);
			//ST7735_SetTextColor(ST7735_YELLOW);
			static uint16_t i = 0;
			//ST7735_DrawString(1, 6, "Loading...", ST7735_YELLOW);
		
	while(i<=ST7735_TFTWIDTH)
			{
			
				ST7735_FillRect(4, x, i, 8, color);
				DelayWait10ms(1);
				i++;
				
			}		
	
//			Output_Clear();
		//	i = 0;
		if (i<=ST7735_TFTWIDTH+1)
		{
			i = 0;
		}
						
		//DelayWait10ms(100);
		//	Output_Clear();

		//ST7735_SetCursor(0, 0);
		}
	

