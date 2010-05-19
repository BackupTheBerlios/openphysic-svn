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

#include	"track.h"

#include "global.h"

void init_track(track* my_track) {
	my_track->sectors = 1;
	my_track->initial_sector = my_track->sectors;
	my_track->current_sector = my_track->initial_sector;

	my_track->lap = 0;
}


void track_new_sect(track* my_track) {
	if ( my_track->current_sector == my_track->sectors ) { // new lap
		my_track->lap = (my_track->lap + 1) % 100;
		my_track->current_sector = 1;
	} else { // new sector
		my_track->current_sector++;
	}
}

unsigned char get_previous_sect(track* my_track) {
	return (my_track->current_sector+my_track->sectors-2) % my_track->sectors + 1;
}

void modify_sectors(track* my_track) {
	my_track->sectors = my_track->sectors % MAX_SECTORS + 1; // ajoute 1

	my_track->initial_sector = my_track->sectors;
	my_track->current_sector = my_track->initial_sector;
}