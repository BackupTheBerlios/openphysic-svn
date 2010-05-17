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

#include <stdio.h>

#include "track.h"
#include "display.h"
#include "lcd.h"
#include "global.h"
#include "chrono.h"

void display_lcd(void) {
	//lcd_clear();

	disp++;
	lcd_goto(L_OFFSET[0]);	// select first line
	if (rpm!=0) {
		nbc = sprintf(buffer, "%05d", 0);
		lcd_puts(buffer);
	} else {
		lcd_puts("_____");
	}
	lcd_putch(' ');
	if ( state==state_run || state==state_stop && (&current_track)->lap!=0 ) {
		nbc = sprintf(buffer, "L%02d", (&current_track)->lap); // lap
		lcd_puts(buffer);
	} else {
		lcd_puts("L__");
	}
	lcd_putch(' ');
	//nbc = sprintf(buffer, "%06u", ticks); // ticks
	//lcd_puts(buffer);
	lcd_puts("OpenChrono");

	lcd_goto(L_OFFSET[1]);	// Select second line
	if (state==state_run) {
		ms2timestruct(time-laptime_evt[0], &laptime_st);
		nbc = sprintf(buffer, " %01u:%02u:%03u", ((&laptime_st)->mm)%10, (&laptime_st)->ss, (&laptime_st)->xx); // temps tour en cours
		lcd_puts(buffer);
	} else {
		lcd_puts(" * STOP *");
		//lcd_puts(" 0:00:000");
	}
	lcd_puts("  ");
	if (laptime_best!=0) {
		ms2timestruct(laptime_best, &laptime_st);
		nbc = sprintf(buffer, "B%01u:%02u:%03u", ((&laptime_st)->mm)%10, (&laptime_st)->ss, (&laptime_st)->xx); // meilleur temps au tour
		lcd_puts(buffer);
	} else {
		lcd_puts("B_:__:___");
	}

	lcd_goto(L_OFFSET[2]);
	if (laptime_last!=0) {
		ms2timestruct(laptime_last, &laptime_st);
		nbc = sprintf(buffer, "L%01u:%02u:%03u", ((&laptime_st)->mm)%10, (&laptime_st)->ss, (&laptime_st)->xx); // dernier temps tour
		lcd_puts(buffer);
	} else {
		lcd_puts("L_:__:___");
	}
	lcd_puts("  ");
	if (laptime_best!=0 && laptime_best_old!=0) {
		lcd_putch('B');
		if (laptime_last>laptime_best) {
			lcd_putch('+');
			ms2timestruct(laptime_last-laptime_best, &laptime_st);
		} else if (laptime_best_old==laptime_best) {
			lcd_putch('=');
			ms2timestruct(0, &laptime_st);
		} else if (laptime_best<laptime_best_old) {
			lcd_putch('-');
			ms2timestruct(laptime_best_old-laptime_best, &laptime_st);
		}
		nbc = sprintf(buffer, ":%02u:%03u", (&laptime_st)->ss, (&laptime_st)->xx); // ecart meilleur temps au tour - dernier temps au tour
		lcd_puts(buffer);
	} else {
		lcd_puts("B?:__:___"); // ToFix symbole +/-
	}

	lcd_goto(L_OFFSET[3]);
	if (laptime_penultimate!=0) {
		lcd_putch('L');
		if (laptime_last>laptime_penultimate) {
			lcd_putch('+');
			ms2timestruct(laptime_last-laptime_penultimate, &laptime_st);
		} else if (laptime_last==laptime_penultimate) {
			lcd_putch('=');
			ms2timestruct(0, &laptime_st);
		} else if (laptime_last<laptime_penultimate) {
			lcd_putch('-');
			ms2timestruct(laptime_penultimate-laptime_last, &laptime_st);
		}
		nbc = sprintf(buffer, ":%02u:%03u", (&laptime_st)->ss, (&laptime_st)->xx); // écart dernier temps au tour et avant dernier temps au tour
		lcd_puts(buffer);
	} else {
		lcd_puts("L?:__:___");
	}
	lcd_puts(" ");


	nbc = sprintf(buffer, "%1u/%1u:", ((&current_track)->current_sector)%10, ((&current_track)->sectors)%10); // temps étape
	lcd_puts(buffer);

	if (state==state_run && (&current_track)->sectors!=1) {
		ms2timestruct(time-laptime_evt[(&current_track)->current_sector-1], &laptime_st);
		nbc = sprintf(buffer, "%02u:%03u", (&laptime_st)->ss, (&laptime_st)->xx); // temps étape
		lcd_puts(buffer);
	} else {
		lcd_puts("__:___");
	}
}