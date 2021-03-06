/* vim: set sw=8 ts=8 si et: */
/*********************************************
* Timer for timeout supervision of the stk 500 protocol
* Author: Guido Socher, Copyright: GPL 
* Copyright: GPL
**********************************************/

//#include <avr/signal.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/wdt.h>
#define F_CPU 3686400UL  // 3.6864 MHz
#include <avr/delay.h>
#include "avr_compat.h"

void delay_ms(unsigned int ms)
/* delay for a minimum of <ms> */
{
        // we use a calibrated macro. This is more
        // accurate and not so much compiler dependent
        // as self made code.
        while(ms){
                _delay_ms(0.96);
                ms--;
        }
}

void wd_init(void)
{
        // timeout the watchdog after 2 sec:
        wdt_enable(WDTO_2S);
}

void wd_kick(void)
{
        wdt_reset();
}


