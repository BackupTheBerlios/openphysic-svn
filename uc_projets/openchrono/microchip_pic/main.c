/***************************************************************************
 *   OpenChrono                                                            *
 *   Copyright (C) 2010 by Sebastien CELLES                                *
 *   s.celles@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*
Microchip 16F877
IDE : MPLAB
Compiler: HI-TECH C Compiler for PIC10/12/16 MCUs
Simulator : Proteus VSM
*/

#include <pic.h>
#include "lcd.h"
#include "delay.h"
#include <stdio.h>

//int i;

int hh;
int mm;
int ss;
int xx;


#define L1_OFFSET 0x0
#define L2_OFFSET 0x40 // 64
#define L3_OFFSET 0x14 // 0x40-22*2
#define L4_OFFSET 0x54 // 0x40+20

#define NB_COLS 20 //16
#define NB_LINES 4 //2
char buffer[NB_COLS+1];
int nbc;

void display_lcd(void) {
	//lcd_clear();

	//lcd_puts("12345678901234567890");

	lcd_goto(L1_OFFSET);	// select first line
	lcd_puts("L1: 567890123456");

	lcd_goto(L2_OFFSET);	// Select second line
	lcd_puts("L2: 5678901234567");

	lcd_goto(L3_OFFSET);
	lcd_puts("L3: 56789012345678");

	lcd_goto(L4_OFFSET);
	//lcd_puts("L4: 567890123456789");
	nbc = sprintf(buffer, "%02d:%02d:%02d:%03d",hh,mm,ss,xx);
	//nbc = sprintf(buffer, "%02d:%02d:%03d",mm,ss,xx);
	lcd_puts(buffer);

}

void increment(void) {
	xx++;
	if (xx==1000) {
		ss++;
		xx=0;
		if (ss==60) {
			mm++;
			ss=0;
			if (mm==60) {
				hh++;
				mm=0;
				if (hh==24) {
					//dd++;
					hh=0;
				}
			}
		}
	}
}

void main(void) {
/*
	hh=0;
	mm=0;
	ss=0;
	xx=0;
*/

	hh=23;
	mm=59;
	ss=59;
	xx=990;

	lcd_init();

	while(1) {
		display_lcd();	

		increment();
		//i=i+1;



		//DelayMs(100);
	}
}
