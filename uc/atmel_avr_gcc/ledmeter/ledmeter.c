/***************************************************************************
 * Project: OpenChrono                                                     *
 * Author: Sebastien CELLES                                                *
 * Module description: an handhelds device for karts, bikes or sport cars  *
 ***************************************************************************/

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


#include <avr/io.h> // Most basic include files

#include <stdint.h> // uint8_t = unsigned char

#include <stdio.h> // TO FIX (LCD)

#include <math.h>

#define F_CPU 1000000UL  // 1 MHz
#include <util/delay.h>

//#include <avr/io.h>              // Most basic include files
#include <avr/interrupt.h>       // Add the necessary ones
//#include <avr/signal.h>          // here

#include <stdbool.h>           // boolean

//volatile unsigned char a2dCompleteFlag;

//int channel;
//unsigned short analog_result;
//int analog_busy;

#define Nleds 8  // number of leds connected to the uC

#define N 50 // number between 0 and 255
#define Nmax 0xFF



#define CHR_PRECISION 4 // precision 1/10000eme = 1/(10^4)
#define CHR_DISPLAY 3 // display 1/1000  = 1/(10^3)

uint8_t running_chronometer = false; // 0 false ; -1 true

typedef struct {
  uint8_t hh; //8bits 0-255
  uint8_t mm; //8bits 0-255
  uint8_t ss; //8bits 0-255
  unsigned short int xx;  //16bits 0-65535
} time_typ;

time_typ current_time;
time_typ last_time;
time_typ best_time;

void init_time(time_typ * time) {
  time->hh = 0;
  time->mm = 0;
  time->ss = 0;
  time->xx = 0;
}

void def_time(time_typ * time, uint8_t _hh, uint8_t _mm, uint8_t _ss, unsigned short int _xx) {
  time->hh = _hh;
  time->mm = _mm;
  time->ss = _ss;
  time->xx = _xx;
}

void print_time(time_typ * t) {
  //printf("===%02i:%02i:%02i:%03u===\n",t->hh,t->mm,t->ss,t->xx/10);
  printf("%02i:%02i:%02i:%03u",t->hh,t->mm,t->ss,t->xx/((int) pow(10,CHR_PRECISION-CHR_DISPLAY)));
}

inline void inc_time(time_typ * time) {
  if (running_chronometer) {
    time->xx++;
    if(time->xx >= pow(10,CHR_PRECISION)) {
      time->xx = 0;
      time->ss++;
      if (time->ss >= 60) {
	time->ss = 0;
	time->mm++;
	if (time->mm >= 60) {
	  time->mm = 0;
	  time->hh++;
	  if (time->hh >= 24) {
	    time->hh = 0;
	  }
	}
      }
    }
    //_delay_ms(1); // use timer interrupts instead of delay
  }
}

void copy_time(time_typ * time_source, time_typ * time_dest) {
  time_dest->hh = time_source->hh;
  time_dest->mm = time_source->mm;
  time_dest->ss = time_source->ss;
  time_dest->xx = time_source->xx;
}

bool time_is_null(time_typ * time) {
  if ( (time->hh == 0) &&  (time->mm == 0) && (time->ss == 0) && (time->xx == 0) ) {
    return true;
  } else {
    return false;
  }
}

uint8_t compare_time(time_typ * time1, time_typ * time2) {
  uint8_t result = 0;

  if ( time_is_null(time1) && time_is_null(time2) ) {
    return 0;
  }

  if ( time_is_null(time1) ) {
    return 2;
  }

  if ( time_is_null(time2) ) {
    return 1;
  }


  if (time1->hh > time2->hh) {
    result = 2;
  }
  else if (time1->hh < time2->hh) {
    result = 1;
  }	
  else {
    if (time1->mm > time2->mm) {
      result = 2;
    }
    else if (time1->mm < time2->mm) {
      result = 1;
    }	
    else {
      if (time1->ss > time2->ss) {
	result = 2;
      }
      else if (time1->ss < time2->ss) {
	result = 1;
      }	
      else {
	if (time1->xx > time2->xx) {
	  result = 2;
	}
	else if (time1->xx < time2->xx) {
	  result = 1;
	}	
	else {
	  result = 0;
	}
      }
    }
  }

  // return the best time (lower) (if different from 00:00:00:000)
  // 0 time1=time2
  // 1 time1>time2
  // 2 time1<time2
  return result;

}



/*
  void switch_on_all_leds();
  void switch_off_all_leds();
  void switch_on_led(uint8_t led);
  void switch_off_led(uint8_t led);
  void loop(void);
  void init(void);
*/

// 1=off
// 0=on

/*
 * switch on all leds
 */
void switch_on_all_leds(void) {
  PORTC = 0x00;
}

/*
 * switch off all leds
 */
void switch_off_all_leds(void) {
  PORTC = 0xFF;
}

// led from 1 to 8 (LEDSNUM)
// PCx with w from 0 to 7

/*
 * switch on the led with the number called "led"
 */
void switch_on_led(uint8_t led) {
  uint8_t pin = led - 1;
  uint8_t mask = ~(1<<pin);
  PORTC&=mask;
}

/*
 * switch off the led with the number called "led"
 */
void switch_off_led(uint8_t led) {
  uint8_t pin = led - 1;
  uint8_t mask = (1<<pin);
  PORTC|=mask;
}

/*
 * switch on every leds one after one with a delay (called "delay")
 */
void switch_on_leds_with_delay(double delay) {
  uint8_t i;
  for(i = 1; i<=Nleds; i++) {
    _delay_ms(delay);
    switch_on_led(i);
  }
}

/*
 * switch off every leds on after one with a delay (called "delay")
 */
void switch_off_leds_with_delay(double delay) {
  uint8_t i;
  for(i = Nleds; i>=1; i--) {
    _delay_ms(delay);
    switch_off_led(i);
  }
}

/*
 * a function for testing leds that switch on every leds and switch off every leds (one after one)
 */
void test_leds_up_down(void) {
  switch_on_leds_with_delay(50); //100
  _delay_ms(50); //50
  switch_off_leds_with_delay(50); //100
}

void test_leds_up_off(void) {
  switch_on_leds_with_delay(50); //100
  _delay_ms(50); //50
  switch_off_all_leds();
}

/*
 *  switch on every leds (from 0 to n)  (and switch off others)
 */
void switch_on_min_dels(uint8_t n) {
  uint8_t i;
  for(i = 1; i<=Nleds; i++) {
    if (i<=n) {
      switch_on_led(i);
    } else {
      switch_off_led(i);
    }
  }
}

/*
 *  switch on every leds (from Nleds to n)
 */
void switch_on_max_dels(uint8_t n) {
  uint8_t i;
  for(i = Nleds; i>=1; i--) {
    if (i>=Nleds-n) {
      switch_on_led(i);
    } else {
      switch_off_led(i);
    }
  }
  // TO TEST (switch off)
}

/*
 * switch off every leds, wait and swith them all, n times (a sort of visual alarm)
 */
void led_alarm(uint8_t n, double delay) {
  uint8_t i;
  for(i = 1; i<=n; i++) {
    switch_off_all_leds();
    _delay_ms(delay);
    switch_on_all_leds();
    _delay_ms(delay);
  }
  switch_off_all_leds();
}

/*
 * switch on every dels depending of the percentage p
 */
//#define roundp floor
inline uint8_t roundp(double n) {
  return floor(n+0.5);
}

// roundp = round for positive number
void show_percent(double p) {
  // p pourcent
  uint8_t n;
  //n = 4;
  n = roundp(p / 100.0 * Nleds); // TO FIX (math.h ceil floor ... round en Java !)
  // TO FIX : +0.5 is a very dirty hack
  switch_on_min_dels(n);
}

/*
 * send a sound (on or more beep(s))
 */
void beep(uint8_t n, double delay) {
  // TO DO
  uint8_t i;
  for(i = 1; i<=n; i++) {
    //TO DO : send a beep
    if (n>1) {
      _delay_ms(delay);
    }
  }
}

/*
 * start or stop chronometer
 */
inline void StartStopChronometer(void) {
  beep(1,100);
  led_alarm(3,50);
  if (running_chronometer) {
    //running_chronometer = false; // false = 0
    if (compare_time(&current_time,&best_time) == 1) {
      // better time them the best time
      copy_time(&current_time,&best_time);
      led_alarm(3,50);
    }
    if (compare_time(&current_time,&last_time) == 1) {
      // better time them the last time
      led_alarm(1,50);
    }
    copy_time(&current_time,&last_time);
    init_time(&current_time);
  } else {
    // this is before first lap (start from pit)
    running_chronometer = true; // true = -1
    // this is after first lap
  }
}


void TestRunningChronometer(void) {
  if (running_chronometer) {
    switch_on_led(8);
    _delay_ms(100);
    switch_off_led(8);
    _delay_ms(100);
  }
}

/*
 * software init function
 */
void sf_init(void) {
  // Leds
  //test_leds_up_off(); // uncomment for release or comment for debug

  // Sound
  //beep(3,100); // uncomment for release or comment for debug

  // Time
  running_chronometer = false;
  init_time(&current_time);
  init_time(&last_time);
  init_time(&best_time);
}

/*
 *  hardware init function
 */
void hw_init(void) {
  // **************
  // * Oscillator *
  // **************
  // internal oscillator set as 1MHz
  // CKSEL

  // ******************
  // * WatchDog Timer *
  // ******************
  // disable by default

  // ********
  // * LEDs *
  // ********
  DDRC=0xFF; // set up PORTD pins 0 to 7 as output
  //switch_on_all_leds();
  switch_off_all_leds();

  // *********************************
  // * Start/Stop chronometer (INT0) *
  // *********************************
  // Set Pin 6 (PD2) as the pin to use for this example
  //PCMSK |= (1<<PIND2); // TO FIX
  //PIND |= (1<<PIND2); // try scls:Error : read-only !!!

  // interrupt on INT0 pin falling edge (sensor triggered)
  MCUCR = (1<<ISC01) | (1<<ISC00);

  // turn on interrupts!

  GICR |= (1<<INT0); //INT0

  sei(); // enable interrupts

  // *************************************************
  // * Conv Analog to Digital (CAN for RPM and Temp) *
  // *************************************************

  //volatile static int analog_result;
  //volatile static unsigned char analog_busy;

  //analog_busy=1; // busy mark the ADC function
  uint8_t channel = 0; // measure ADC0

  // use internal 2.56V ref  REFS1=1 & REFS0=1 (11)
  // use external ref (01)
  ADMUX=(0<<REFS1)|(1<<REFS0)|(channel & 0x07); // channel & 0x07

  //ADCSRA=(1<<ADEN)|(1<<ADIE)|(1<<ADIF)|(1<<ADPS2); // interrupt ADIE=1
  ADCSRA=(1<<ADEN)|(0<<ADIE)|(1<<ADIF)|(1<<ADPS2); // no interrupt ADIE=0

  ADCSRA |= (1 << (ADSC)); // start conversion

  DDRA=0x00;
  // make sure pull-up resistors are turned off
  PORTA = 0x00;
	

  // **********
  // * Keypad *
  // **********
  // 1 joystick button (4 directions, up, down, left, right)
  // 2 push buttons (ok, cancel)
  DDRB=0x00;
  PORTB=0xFF;

  // ***************
  // * Graphic LCD *
  // ***************

  // *********
  // * Timer *
  // *********
  //FPWM=Fquartz/(N.256) with N={1,8,64,256,1024}
  //N=Fquartz/(FPWM.256)
  //http://www.jelectronique.com/pwm.php
  // here Fquartz = F_CPU = 1MHz
  // here T = 0.1ms so FPWM = 10 000 Hz  = 10 kHZ
  // That's a  bab idea because
  // we need a variable number of step in the timer TCNT1=ICR1
  //FPWM=Fquartz/((N.(1+TOP))
  //TOP=Fquartz/(FPWM.N)-1
  // N=1 SO TOP=99=Ox63=ICR1 (2 registres de 8 bits)
  // TOP
  ICR1H=0x00;
  ICR1L=0x63;
  // START
  OCR1AH = 0x00;
  OCR1AL = 31;//0x00;
  // Timer(s)/Counter(s) Interrupt(s) initialization
  TIMSK=(1<<OCIE1A)|(1<<TOIE1); //0x00;

  // Sound

  // Time
}

/*
 * init function
 */
void init(void) {
  hw_init();
  sf_init();
}

/*
 * convert from analog to digital (10 bits)
 */
unsigned short adcConvert10bit(uint8_t ch)
{
  //a2dCompleteFlag = 0;				// clear conversion complete flag
  ADMUX = ((ADMUX) & ~0x1F) | (ch & 0x1F);	// set channel ADC_MUX_MASK=0x1F
  ADCSRA |= (_BV(ADIF)); // clear hardware "conversion complete" flag
  ADCSRA |= (_BV(ADSC)); // start conversion
							
  //while(!a2dCompleteFlag);				// wait until conversion complete
  //while( bit_is_clear(ADCSR, ADIF) );		// wait until conversion complete
  while( bit_is_set(ADCSRA, ADSC) );		// wait until conversion complete

  // CAUTION: MUST READ ADCL BEFORE ADCH!!!
  return ((ADCL) | ((ADCH)<<8));	// read ADC (full 10 bits);
}

/*
 * convert from analog to digital (8 bits)
 * starts conversion, waits until conversion is done, and returns result
 */
unsigned char adcConvert8bit(unsigned char ch)
{
  // do 10-bit conversion and return highest 8 bits
  return adcConvert10bit(ch)>>2;			// return ADC MSB byte
}

#define Nbuts 6
#define B_OK 0
#define B_CANCEL 1
#define B_LEFT 2
#define B_RIGHT 3
#define B_UP 4
#define B_DOWN 5


inline void SeekButtons(void) {
  if ( (PINB>>B_OK)&0x01 ) { // OK
    StartStopChronometer();
  }
	
  if ( (PINB>>B_CANCEL)&0x01 ) { // CANCEL

  }		
	
  if ( (PINB>>B_LEFT)&0x01 ) { // LEFT

  }
	
  if ( (PINB>>B_RIGHT)&0x01 ) { // RIGHT

  }
	
  if ( (PINB>>B_UP)&0x01 ) { // UP

  }
	
  if ( (PINB>>B_DOWN)&0x01 ) { // DOWN

  }	     	     	     	
}

void display(void) {
  // clear screen
  // TO DO

  // line 1

  print_time(&current_time); // ZONE 1
	
  printf(" ");
	
  print_time(&best_time); // ZONE 2
	
	
  printf("\n");	
  // line 2
	
  print_time(&last_time); // ZONE 3
	
  printf(" ");
	
  // ZONE 4
  if( compare_time(&current_time,&last_time) == 0 ) {
    printf("LST=");
  }
  if( compare_time(&current_time,&last_time) == 1 ) {
    printf("LST-");
  }
  if( compare_time(&current_time,&last_time) == 2 ) {
    printf("LST-");
  }
	
  if( compare_time(&current_time,&best_time) == 0 ) {
    printf("BST=");
  }
  if( compare_time(&current_time,&best_time) == 1 ) {
    printf("BST-");
  }
  if( compare_time(&current_time,&best_time) == 2 ) {
    printf("BST+");
  }			
	
}

/*
 *  this is the main loop
 */
void loop(void) {
  //SeekButtons(); // use INT1 instead

  // RPM
  volatile double ch0 = adcConvert10bit(0);
  ch0 *= 0.09765625; // 0.09765625 = 100 / 2^10
  show_percent(ch0);

  // display (LCD)
  display();

  /*
    _delay_ms(500);

    double ch1 = adcConvert10bit(1);
    ch1 *= 0.09765625; // 0.09765625 = 100 / 2^10
    show_percent(ch1);

    _delay_ms(500);
  */

  //TestRunningChronometer();

  //inc_time(&current_time);
}


/*
 * main program
 */
int main(void) {
  init();
  while(1) { // Infinite loop; define here the
    loop(); // system behaviour
  }
  return 0;
}

/*
 * interrupt handler for INT0 (HALL PROBE)
 */
SIGNAL(SIG_INTERRUPT0) {
  StartStopChronometer();
}

/*
 * interrupt handler for INT1 (KEYPAD)
 */
SIGNAL(SIG_INTERRUPT1) {
  SeekButtons();
}

/*
 * interrupt handler for TIMER
 */
SIGNAL(SIG_OUTPUT_COMPARE1A) {
  StartStopChronometer();
  inc_time(&current_time);
}

