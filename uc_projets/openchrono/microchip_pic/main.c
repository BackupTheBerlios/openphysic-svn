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
#include <string.h>

#include "track.h"

unsigned char state;
unsigned int ticks;
unsigned int disp;

unsigned char hh=0; /* 0-24 */
unsigned char mm=0; /* 0-60 */
unsigned char ss=0; /* 0-60 */
unsigned int xx=0; /* 0-1000 */

unsigned long int time;
//unsigned long int time_remain;

typedef struct {
	unsigned char hh; /* 0-24 */
	unsigned char mm; /* 0-60 */
	unsigned char ss; /* 0-60 */
	unsigned int xx; /* 0-1000 */
} time_struct;

time_struct laptime;

char L_OFFSET[] = {0x00, 0x40, 0x14, 0x54};
/*	i=0 -> L1 0x00=0
	i=1 -> L1 0x40=64
	i=2 -> L1 0x14=0x40-22*2
	i=3 -> L1 0x54=0x40+20
*/

#define NB_COLS 20
#define NB_LINES 4

char buffer[NB_COLS+1];

int nbc;

//char bufferScreen[NB_COLS*NB_LINES+1];

char bufferScreen[NB_LINES][NB_COLS+1];

/*
// Tester le LCD en envoyant
// A2345678901234567890
// B2345678901234567890
// C2345678901234567890
// D2345678901234567890
void test_buffer(void) {
	for (unsigned char i=0 ; i<NB_LINES ; i++) {
		for(unsigned char j=0 ; j<NB_COLS ; j++) {
			if (j!=0) {
				bufferScreen[i][j] = 0b0011<<4 | (j+1)%10 ;
			} else {
				bufferScreen[i][j] = 0b0100<<4 | (i+1)%10 ;
			}
		}
	}
}
*/

/* Effacer le buffer */
void clear_buffer(void) {
	for (unsigned char i=0 ; i<NB_LINES ; i++) {
		for(unsigned char j=0 ; j<NB_COLS ; j++) {
			bufferScreen[i][j] = 0;
		}
	}
}

void flag2buffer(void) {
	/* Drapeau à damier */
	for (unsigned char i=0 ; i<NB_LINES ; i++) {
		for(unsigned char j=0 ; j<NB_COLS ; j++) {
			if (((j+i) % 2) == 0) {
				bufferScreen[i][j] = 0b11111111; // nb pair -> pavé plein
			} else {
				bufferScreen[i][j] = 0b11111110; // nb impair -> pavé vide
			}
		}
	}
}

void splashscreen2buffer(void) {
	flag2buffer();

	/* Texte */
	strcpy(bufferScreen[1]+4, " OpenChrono ");
	strcpy(bufferScreen[2]+5, " S. Celles");
}

void buffer2lcd(void) {
	//lcd_clear();
	for (unsigned char i=0 ; i<NB_LINES ; i++) {
		lcd_goto(L_OFFSET[i]);
		for(unsigned char j=0 ; j<NB_COLS ; j++) {
			lcd_putch(bufferScreen[i][j]);
		}
	}
}

int ms2timestruct(unsigned long int t, time_struct * ts) {
	unsigned long int time_remain = t;
	ts->hh = time_remain / 3600000;

	time_remain = time_remain % 3600000;
	ts->mm = time_remain / 60000;

	time_remain = time_remain % 60000;
	ts->ss = time_remain / 1000;

	time_remain = time_remain % 1000;
	ts->xx = time_remain;	

	return 0;
}

void display_lcd(void) {
	disp++;
	lcd_goto(L_OFFSET[0]);	// select first line
	nbc = sprintf(buffer, "%05d L%02d", 0, (&current_track)->lap);
	lcd_puts(buffer);

	lcd_goto(L_OFFSET[1]);	// Select second line
	nbc = sprintf(buffer, " %01u:%02u:%03u  B%01u:%02u:%03u", mm%10, ss, xx, 0%10, 0, 0); // temps tour en cours & meilleur tour
	lcd_puts(buffer);

	lcd_goto(L_OFFSET[2]);
	ms2timestruct(time, &laptime);
	nbc = sprintf(buffer, " %01u:%02u:%03u", ((&laptime)->mm)%10, (&laptime)->ss, (&laptime)->xx); // temps tour en cours
	lcd_puts(buffer);
/*
	nbc = sprintf(buffer, "L%01u:%02u:%03u  B+:%02u:%03u", 0%10, 0, 0, 0, 0); // temps tour en cours & meilleur tour
	lcd_puts(buffer);
*/
	lcd_goto(L_OFFSET[3]);
	nbc = sprintf(buffer, "L+:%02u:%03u", 0%60, 0); // temps tour en cours & meilleur tour
	lcd_puts(buffer);
	lcd_puts(" ");
	nbc = sprintf(buffer, "%1u/%1u:%02u:%03u", ((&current_track)->current_sector)%9, 0, 0%60, 0); // temps tour en cours & meilleur tour
	lcd_puts(buffer);
}

void increment(void) {
	time++;

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

	INTEDG = 0; // external interrupt on falling edge
	//INTEDG = 1; // external interrupt on rising edge

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
if (T0IF) { // increment timer 1ms
	RE0 = !RE0; // signal pour calibrage horloge 1ms
	//PORTB ^= (1 << 5); // inversion bit 5 ( http://fr.wikipedia.org/wiki/Manipulation_de_bit )
	TMR0 = 0x0E; // theorie 0x06->1000us ; pratique 0x06->1034 , 0x10->996us , 0x11->1024us

	increment();

	T0IF = 0;
}

if (INTF && RB1) { // line
	reset_time();
	track_new_sect(&current_track);

	INTF = 0;
}
	// process other interrupt sources here
}

int main(void) {
	state = 1;
	ticks = 0;
	disp = 0;

	TRISB = 0b11111111; // digital inputs on PORTB (keypad, line)
	//TRISB = 0b11011111; // sortie sur RB5 pour calibrage horloge
	//RBPU = 0; // enable pull-up resistors on RBx
	//PORTB = 0b00000000;

	TRISE = 0b00001110; // sortie sur RE0 pour calibrage horloge
	PORTE = 0b00000000;

	reset_time();

	timer_init();

	lcd_init();

	splashscreen2buffer();
	buffer2lcd();
	//DelayMs(500); // Comment for debug
	lcd_clear();

	state = 2;

	init_track(&current_track);

	while(1) {
		ticks++;

		display_lcd();
	}

	return 0;
}
