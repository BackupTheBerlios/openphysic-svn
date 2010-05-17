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

#ifndef GLOBAL_H
#define GLOBAL_H

unsigned char state;
enum state_value { state_off = 0, state_splash, state_stop, state_run};

unsigned int ticks;
unsigned int disp;

unsigned char hh=0; /* 0-24 */
unsigned char mm=0; /* 0-60 */
unsigned char ss=0; /* 0-60 */
unsigned int xx=0; /* 0-1000 */

unsigned long int time;
//unsigned long int time_remain;
unsigned long int laptime_evt[9];

/* Temps en ms */
unsigned long int laptime_current;
unsigned long int laptime_best;
unsigned long int laptime_last;

unsigned long int laptime_best_old;
unsigned long int laptime_penultimate;
//unsigned long int laptime_antepenultimate;



//#define RUNNING T0IE



char L_OFFSET[] = {0x00, 0x40, 0x14, 0x54};
/*	i=0 -> L1 0x00=0
	i=1 -> L1 0x40=64
	i=2 -> L1 0x14=0x40-22*2
	i=3 -> L1 0x54=0x40+20
*/

#define NB_COLS 20
#define NB_LINES 4

char buffer[NB_COLS+1];

unsigned int rpm;

int nbc;

//char bufferScreen[NB_COLS*NB_LINES+1];

char bufferScreen[NB_LINES][NB_COLS+1];

#endif //GLOBAL_H