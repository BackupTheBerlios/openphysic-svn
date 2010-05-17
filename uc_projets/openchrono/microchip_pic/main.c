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
uC: Microchip 16F877
IDE: MPLAB
Compiler: HI-TECH C Compiler for PIC10/12/16 MCUs
Simulator: Proteus VSM
*/

//#define _XTAL_FREQ 4000000

#include <pic.h>
#include "lcd.h"
#include "delay.h"
#include <stdio.h>
#include <string.h>

#include "display.h"
#include "track.h"

#include "global.h"

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
	TMR0 = 0x0E; // initial value of timer 0 theory=0x06 practical=0x0E

	T0IE = 1; // On autorise les interruptions du timer 0

	T0IF = 0; // RAZ flag interruption

	T0CS = 0;
	PSA = 0;
	PS2 = 0; PS1 = 0; PS0 = 1; // prescaler 1:4
	
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
	//PEIE = 1 ; // Autorisation des IT peripherique
	
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
	unsigned long int time2;
	time2 = time;
	track_new_sect(&current_track);

	if ( state == state_stop ) {
		state = state_run;
	} else {
		if ((&current_track)->current_sector==1) {
			laptime_penultimate = laptime_last;
			laptime_last = time2 - laptime_evt[0];
			if (laptime_best==0 || time2-laptime_evt[0]<laptime_best) {
				laptime_best_old = laptime_best;
				laptime_best = time2-laptime_evt[0];
			}
		}
	}

	laptime_evt[(&current_track)->current_sector-1] = time2;

	INTF = 0;
}
	// process other interrupt sources here
}

int main(void) {
	state = state_off;
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

	state = state_splash;
	splashscreen2buffer();
	buffer2lcd();
	//DelayMs(500); // Comment for debug
	lcd_clear();

	state = state_stop;

	init_track(&current_track);

	while(1) {
		ticks++;

		display_lcd();
	}

	return 0;
}
