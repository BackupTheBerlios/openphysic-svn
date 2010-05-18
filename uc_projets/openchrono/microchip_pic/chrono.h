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

#ifndef CHRONO_H
#define CHRONO_H

#include "global.h"

/*
unsigned char hh=0; // 0-24
unsigned char mm=0; // 0-60
unsigned char ss=0; // 0-60
unsigned int xx=0; // 0-1000
*/

typedef struct {
	unsigned char hh; /* 0-24 */
	unsigned char mm; /* 0-60 */
	unsigned char ss; /* 0-60 */
	unsigned int xx; /* 0-1000 */
} time_struct;

time_struct laptime_st;



unsigned long int time;
//unsigned long int time_remain;
unsigned long int laptime_evt[MAX_SECTORS];

//unsigned long int laptime_evt2[9][100];
//unsigned long int laptimes[20];

/* Temps en ms */
unsigned long int laptime_current;
unsigned long int laptime_best;
unsigned long int laptime_last;

unsigned long int laptime_best_old;
unsigned long int laptime_penultimate;
//unsigned long int laptime_antepenultimate;

int ms2timestruct(unsigned long int t, time_struct * ts);

#endif //CHRONO_H