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

#include "display.h"
#include "track.h"
#include "chrono.h"

#include "global.h"


void timer_init() {
	// Timer 0 (8 bits) utilis� pour le chrono 1ms
	TMR0 = 0x0E; // initial value of timer 0 theory=0x06 practical=0x0E

	T0IE = 1; // On autorise les interruptions du timer 0

	T0IF = 0; // RAZ flag interruption

	T0CS = 0;
	PSA = 0;
	PS2 = 0; PS1 = 0; PS0 = 1; // prescaler 1:4
	
/*
	// Timer 1 (16 bits) utilis� pour l'horloge
	// Quartz 4 Mhz => 1 instruction = 1 �s
	// 1ms -> 0xFC17 ; 0.1ms->0xFF9B -> TMR1H=0xFF; TMR1L= 0x9B

	T1CON = 0x00 ; // Pr�division de l'horloge par 1
	TMR1H = 0xFC; // 0xFF
	TMR1L = 0x36; // 100us=0x9B 10us=0xF5 // 0xC1 ; // 0xFFFF - 0xFFC1 = 62 => 62 x 1 �s = 62 �s
	TMR1ON = 1 ; // On lance le timer 1
	TMR1IE = 1 ; // On autorise les interruptions du timer 1
*/

	INTEDG = 0; // external interrupt on falling edge
	//INTEDG = 1; // external interrupt on rising edge

	// Autorisation des interruptions
	//PEIE = 1 ; // Autorisation des IT peripherique
	
	ei();	//GIE = 1 ; // Autorisation g�n�ral des IT
}

void interrupt tc_int(void) {
if (T0IF) { // increment timer 1ms
	RE0 = !RE0; // signal pour calibrage horloge 1ms
	//PORTB ^= (1 << 5); // inversion bit 5 ( http://fr.wikipedia.org/wiki/Manipulation_de_bit )
	TMR0 = 0x0E; // theorie 0x06->1000us ; pratique 0x06->1034 , 0x10->996us , 0x11->1024us

	//increment();
	time++;

	T0IF = 0;
}

if (INTF && LINE) { // line
	unsigned long int time2;
	time2 = time;
	track_new_sect(&current_track);

	if ( state == state_stop ) {
		state = state_run;
	} else {
		flag_sector = 1;
		new_page_flag = 1;
		if ((&current_track)->current_sector==1) {
			flag_lap = 1;
			new_page_flag = 1;
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

if (INTF && B_LEFT) {
	goto_next_page();
	INTF = 0;
}

if (INTF && B_RIGHT) {
	if (state == state_run) {
		state = state_stop;
	} else {
		modify_sectors(&current_track);
	}
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

	//reset_time();

	lcd_init();
	init_pages();

	state = state_splash;
	//splashscreen2buffer();
	//buffer2lcd();

	ptr_current_page->display();
	DelayMs(500); // Comment for debug
	goto_next_page();
	//lcd_clear();

	timer_init();

	state = state_stop;

	init_track(&current_track);

	while(1) {
		ticks++;

		//(&current_track)->sectors = ( (&current_track)->sectors + 1 ) % 50;

		if (new_page_flag) {
			lcd_clear();
			new_page_flag=0;
		}
		ptr_current_page->display();

		if (state == state_run && time-laptime_evt[0]>=10*60000) { // ->stop apr�s 10' en run sans rencontrer de ligne
			state = state_stop;
			(&current_track)->current_sector = (&current_track)->initial_sector;
		}
	}

	return 0;
}