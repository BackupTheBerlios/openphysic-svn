/***************************************************************************
 *   Copyright (C) 2006 by Sebastien CELLES                                *
 *   s.cls@laposte.net                                                     *
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
 
#define Nbuts 6
#define B_OK 0
#define B_CANCEL 1
#define B_LEFT 2
#define B_RIGHT 3
#define B_UP 4
#define B_DOWN 5


inline void SeekButtons(void)
{
    if ( !((PINB>>B_OK)&0x01) )
    { // OK
        StartStopChronometer();
    }

    if ( !((PINB>>B_CANCEL)&0x01) )
    { // CANCEL

    }

    if ( !((PINB>>B_LEFT)&0x01) )
    { // LEFT

    }

    if ( !((PINB>>B_RIGHT)&0x01) )
    { // RIGHT

    }

    if ( !((PINB>>B_UP)&0x01) )
    { // UP

    }

    if ( !((PINB>>B_DOWN)&0x01) )
    { // DOWN

    }
}
