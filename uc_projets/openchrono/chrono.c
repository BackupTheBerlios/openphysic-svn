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
 
/*
 * start or stop chronometer
 */
inline void StartStopChronometer(void)
{
    beep(1,100);
    led_alarm(3,50);
    if (running_chronometer)
    {
        //running_chronometer = false; // false = 0
        if (compare_time(&current_time,&best_time) == 1)
        {
            // better time them the best time
            copy_time(&current_time,&best_time);
            led_alarm(3,50);
        }
        if (compare_time(&current_time,&last_time) == 1)
        {
            // better time them the last time
            led_alarm(1,50);
        }
        copy_time(&current_time,&last_time);
        init_time(&current_time);
    }
    else
    {
        // this is before first lap (start from pit)
        running_chronometer = true; // true = -1
        // this is after first lap
    }
}


void TestRunningChronometer(void)
{
    if (running_chronometer)
    {
        switch_on_led(8);
        _delay_ms(100);
        switch_off_led(8);
        _delay_ms(100);
    }
}

