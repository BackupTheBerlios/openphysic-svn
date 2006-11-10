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

void init_hw_keypad(void)
{
    // 1 joystick button (4 directions, up, down, left, right)
    // 2 push buttons (ok, cancel)
    // keypad input
    DDRB=0x00;
    PORTB=0xFF;
    // keypad interrupt with OR output on INT1
    //MCUCR |= (1<<ISC11) | (0<<ISC10); // falling edge ATmega8535
    EICRA |= (1<<ISC11) | (0<<ISC10); // falling edge ATmega8535 (relachement bouton)
    //EICRA |= (0<<ISC11) | (1<<ISC10); // changement d'état (appui ou relachement bouton)
    //MCUCR |= (0<<ISC11) | (0<<ISC10); // low level (for test)

    //GICR |= (1<<INT1); // turn on interrupts INT1  (ATmega8535)
    EIMSK |= (1<<INT1); // ATmega128
}

inline void SeekButtons(void)
{
    if ( (PINB>>B_OK)&0x01 )
    { // OK
        StartStopChronometer();
    }

    if ( (PINB>>B_CANCEL)&0x01 )
    { // CANCEL

    }

    if ( (PINB>>B_LEFT)&0x01 )
    { // LEFT

    }

    if ( (PINB>>B_RIGHT)&0x01 )
    { // RIGHT

    }

    if ( (PINB>>B_UP)&0x01 )
    { // UP

    }

    if ( (PINB>>B_DOWN)&0x01 )
    { // DOWN

    }
}

/*
 * interrupt handler for INT1 (KEYPAD)
 * a OR function is made using diodes
 * and is send to INT1
 */
//SIGNAL(SIG_INTERRUPT1)
ISR(INT1_vect)
{
    //PORTC = 0x00;
    SeekButtons();
}


