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

//#define _XTAL_FREQ 4000000

#include <pic.h>
#include "lcd.h"
#include "delay.h"
#include <stdio.h>


unsigned char state;
unsigned int ticks;
unsigned int disp;

unsigned char hh; /* 0-24 */
unsigned char mm; /* 0-60 */
unsigned char ss; /* 0-60 */
unsigned xx; /* 0-1000 */


#define L1_OFFSET 0x0
#define L2_OFFSET 0x40 // 64
#define L3_OFFSET 0x14 // 0x40-22*2
#define L4_OFFSET 0x54 // 0x40+20

#define NB_COLS 20 //16
#define NB_LINES 4 //2
char buffer[NB_COLS+1];
int nbc;

void display_lcd_flag_line(char offset) {
	for(int i=0 ; i<NB_COLS ; i++) {
		if (((i+offset) % 2) == 0) {
			lcd_putch(0b11111111); // nb pair -> pavé plein
		} else {
			lcd_putch(0b11111110); // nb impair -> pavé vide
		}
	}
}

void display_lcd_flag_screen(void) {
	/* Drapeau à damier */
	lcd_goto(L1_OFFSET);
	display_lcd_flag_line(0);
	lcd_goto(L2_OFFSET);
	display_lcd_flag_line(1);
	lcd_goto(L3_OFFSET);
	display_lcd_flag_line(2);
	lcd_goto(L4_OFFSET);
	display_lcd_flag_line(3);

	/* Texte */
	lcd_goto(L2_OFFSET+3);
	lcd_puts(" OpenChrono ");

	lcd_goto(L3_OFFSET+4);
	lcd_puts(" S. Celles ");

}

void display_lcd_splash_screen(void) {
	lcd_goto(L1_OFFSET);
	for(int i=0 ; i<NB_COLS ; i++) {
		lcd_putch(0b11111111); // pavé plein
	}

	lcd_goto(L2_OFFSET);
	nbc = sprintf(buffer, "**   OpenChrono   **");
	for(int i=0 ; i<2 ; i++) {
		buffer[i]=0b11111111;
		buffer[NB_COLS-i-1]=0b11111111;
	}
	lcd_puts(buffer);

	lcd_goto(L3_OFFSET);
	nbc = sprintf(buffer, "**   S. Celles    **");
	for(int i=0 ; i<2 ; i++) {
		buffer[i]=0b11111111;
		buffer[NB_COLS-i-1]=0b11111111;
	}
	lcd_puts(buffer);

	lcd_goto(L4_OFFSET);
	for(int i=0 ; i<NB_COLS ; i++) {
		lcd_putch(0b11111111); // pavé plein
	}

}

void display_lcd(void) {
/*
12345678901234567890
mm:ss:xxx  mm:ss:xxx L1
xxxxxxxxxxxxxxxxxxxx L2
xxxxxxxxxxxxxxxxxxxx L3
xxxxxxxxxxxxxxxxxxxx L4
*/
	disp++;

	//lcd_clear();

	//lcd_puts("12345678901234567890");

	lcd_goto(L1_OFFSET);	// select first line
	//lcd_puts("L1: 567890123456");
	//lcd_puts("**** OpenChrono ****");
	//lcd_puts("********************");
	//for(int i=0 ; i<NB_COLS ; i++) {
	//	lcd_putch(0b11111111); // pavé plein
	//}
	/*
	nbc = sprintf(buffer, "xxxx OpenChrono xxxx");
	for(int i=0 ; i<4 ; i++) {
		buffer[i]=0b11111111;
		buffer[NB_COLS-i-1]=0b11111111;
	}
	lcd_puts(buffer);
	*/
	nbc = sprintf(buffer, "%05d RPM OpenChrono",0);
	lcd_puts(buffer);

	lcd_goto(L2_OFFSET);	// Select second line
	//lcd_puts("L2: 5678901234567");
	//lcd_puts("**** S. Celles  ****");
	//nbc = sprintf(buffer, "disp=%05d",disp);
	//lcd_puts(buffer);
	//for(int i=0 ; i<NB_COLS ; i++) {
	//	lcd_putch(0b11111111); // pavé plein
	//}
	nbc = sprintf(buffer, " %01u:%02u:%03u  B%01u:%02u:%03u",mm%10,ss,xx,0%10,0,0); // temps tour en cours & meilleur tour
	lcd_puts(buffer);

	lcd_goto(L3_OFFSET);
	//lcd_puts("L3: 56789012345678");
	//nbc = sprintf(buffer, "ticks=%05u",ticks);
	//lcd_puts(buffer);
	nbc = sprintf(buffer, "L%01u:%02u:%03u  B+:%02u:%03u",0%10,0,0,0,0); // temps tour en cours & meilleur tour
	lcd_puts(buffer);

	lcd_goto(L4_OFFSET);
	//lcd_puts("L4: 567890123456789");
	//nbc = sprintf(buffer, "%02d:%02d:%02d:%03d",hh,mm,ss,xx)
	nbc = sprintf(buffer, "L+:%02u:%03u",0%60,0); // temps tour en cours & meilleur tour
	lcd_puts(buffer);
	lcd_puts("  ");
	nbc = sprintf(buffer, "E%1u:%02u:%03u",2%9,0%60,0); // temps tour en cours & meilleur tour
	lcd_puts(buffer);
}

void increment(void) {
	xx++;
	if (xx==1000) {
		xx=0;
		ss++;
		if (ss==60) {
			ss=0;
			mm++;
			if (mm==60) {
				mm=0;
				hh++;
				if (hh==24) {
					hh=0;
					//dd++;
				}
			}
		}
	}
}

void timer_init() {
	// Timer 0 (8 bits) utilisé pour le chrono 1ms
	TMR0 = 0x0E; // valeur initiale timer 0 theorie=0x06 pratique=0x10

	T0IE = 1; // On autorise les interruptions du timer 0

	T0IF = 0; // RAZ flag interruption

	T0CS = 0;
	PSA = 0;
	PS2 = 0;
	PS1 = 0;
	PS0 = 1;
	//TMR0ON = 1;
	//TMR0ON = 1 ; // On lance le timer 1
	//TMR0IE = 1 ; // On autorise les interruptions du timer 1
	
/*
	// Timer 1 (16 bits) utilisé pour l'horloge
	// Quartz 4 Mhz => 1 instruction = 1 µs
	// 1ms -> 0xFC17 ; 0.1ms->0xFF9B -> TMR1H=0xFF; TMR1L= 0x9B

	T1CON = 0x00 ; // Prédivision de l'horloge par 1
	TMR1H = 0xFC; // 0xFF
	TMR1L = 0x36; // 100us=0x9B 10us=0xF5 // 0xC1 ; // 0xFFFF - 0xFFC1 = 62 => 62 x 1 µs = 62 µs
	TMR1ON = 1 ; // On lance le timer 1
	TMR1IE = 1 ; // On autorise les interruptions du timer 1
*/

	// Autorisation des interruptions
	PEIE = 1 ; // Autorisation des IT peripherique
	
	ei();	//GIE = 1 ; // Autorisation général des IT
}

void reset_time(void) {

	hh=0;
	mm=0;
	ss=0;
	xx=0;


/*
	hh=23;
	mm=59;
	ss=59;
	xx=990;
*/
}

void interrupt tc_int(void) {
if (T0IF) {
	PORTB ^= (1 << 5); // inversion bit 5 ( http://fr.wikipedia.org/wiki/Manipulation_de_bit )
	TMR0 = 0x0E; // theorie 0x06->1000us ; pratique 0x06->1034 , 0x10->996us , 0x11->1024us

	increment();
	//display_lcd();
	//lcd_goto(L1_OFFSET);	// select first line
	//lcd_puts("++++++++++++++++++++");

	T0IF = 0;
}
//} else if(TMR1IF) {

/*
if(TMR1IF) {
	//di(); //GIE = 0 ; // interdiction interruption

	// calibrage horloge 1 ms
	//PORTB = ~PORTB;
	PORTB ^= (1 << 5); // inversion bit 5 ( http://fr.wikipedia.org/wiki/Manipulation_de_bit )

	//Flag62us = 1 ;
	TMR1H = 0xFC ;
	TMR1L = 0x36; // 100us=0x9B ; 10us //0xC1 ; // 0xFFFF - 0xFFC1 = 62 => 62 x 1 µs = 62 µs

	//reset_time();
	//increment();

	//ei(); //GIE = 1; // autorisation interruption

	TMR1IF = 0;
}
*/

if (INTF) {
	reset_time();

	INTF = 0;
}

/*
	if (T0IE && T0IF) {
		T0IF=0;
		++tick_count;
		return;
	}
*/
	// process other interrupt sources here
}

void main(void) {
	state = 1;
	ticks = 0;
	disp = 0;

	TRISB = 0b11011111; // sortie sur RB5 pour calibrage horloge
	//PORTB = 0b00000000;

	reset_time();

	timer_init();

	lcd_init();
	
	while(1) {

		ticks++;

		if (state==1) {
			//display_lcd_splash_screen();
			if ((ticks%5000)==1) {
				display_lcd_flag_screen();
			} else if ((ticks%5000)==0) {
				state = 2;
				lcd_clear();
			}
		} else {		
			display_lcd();
		}
		//increment();
		//i=i+1;



		//DelayMs(500);
	}
}
