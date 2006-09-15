// ***********************************************************
// Project: OpenChrono
// Author: Sebastien CELLES
// Module description: an handhelds device for karts, bike or sport cars
// ***********************************************************

#include <avr/io.h>              // Most basic include files

#include <math.h>

#define F_CPU 1000000UL  // 1 MHz
#include <util/delay.h>

//#include <avr/io.h>              // Most basic include files
#include <avr/interrupt.h>       // Add the necessary ones
//#include <avr/signal.h>          // here

#define TRUE -1
#define FALSE 0

//volatile unsigned char a2dCompleteFlag;

//int channel;
//unsigned short analog_result;
//int analog_busy;

#define Nleds 8  // number of leds connected to the uC

#define N 50 // number between 0 and 255
#define Nmax 0xFF


int running_chronometer = FALSE; // 0 false ; -1 true

typedef struct {
    int hh; //8bits 0-255
    int mm; //8bits 0-255
    int ss; //8bits 0-255
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

void print_time(time_typ * t) {
    printf("===%02i:%02i:%02i:%03u===\n",t->hh,t->mm,t->ss,t->xx);
}

void copy_time(time_typ * time_source, time_typ * time_dest) { // TO TEST (pointer ?)
    time_dest->hh = time_source->hh;
    time_dest->mm = time_source->mm;
    time_dest->ss = time_source->ss;
    time_dest->xx = time_source->xx;
}

int compare_time(time_typ * time1, time_typ * time2) {
    //  0 time1=time2
    // -1 time1<time2
    //  1 time1>time2
    return 0;
}

void inc_time(time_typ * time) {
  if (running_chronometer) {
    time->xx++;
    if(time->xx >= 1000) {
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
    _delay_ms(1);
  }
}



/*
void switch_on_all_leds();
void switch_off_all_leds();
void switch_on_led(int led);
void switch_off_led(int led);
void loop(void);
void init(void);
*/

// 1=off
// 0=on

/*
 * switch on all leds
 */
void switch_on_all_leds() {
    PORTC = 0x00;
}

/*
 * switch off all leds
 */
void switch_off_all_leds() {
    PORTC = 0xFF;
}

// led from 1 to 8 (LEDSNUM)
// PCx with w from 0 to 7

/*
 * switch on the led with the number called "led"
 */
void switch_on_led(int led) {
    int pin = led - 1;
    int mask = ~(1<<pin);
    PORTC&=mask;
}

/*
 * switch off the led with the number called "led"
 */
void switch_off_led(int led) {
    int pin = led - 1;
    int mask = (1<<pin);
    PORTC|=mask;
}

/*
 * switch on every leds one after one with a delay (called "delay")
 */
void switch_on_leds_with_delay(double delay) {
    int i;
    for(i = 1; i<=Nleds; i++) {
        _delay_ms(delay);
        switch_on_led(i);
    }
}

/*
 * switch off every leds on after one with a delay (called "delay")
 */
void switch_off_leds_with_delay(double delay) {
    int i;
    for(i = Nleds; i>=0; i--) {
        _delay_ms(delay);
        switch_off_led(i);
    }
}

/*
 * a function for testing leds that switch on every leds and switch off every leds (one after one)
 */
void test_leds() {
    switch_on_leds_with_delay(100);
    _delay_ms(50);
    switch_off_leds_with_delay(100);
}

/*
 *  switch on every leds (from 0 to n)  (and switch off others)
 */
void switch_on_min_dels(int n) {
    int i;
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
void switch_on_max_dels(int n) {
    int i;
    for(i = Nleds; i>=0; i--) {
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
void led_alarm(int n, double delay) {
    int i;
    for(i = 1; i<=n; i++) {
        switch_off_all_leds();
        _delay_ms(delay);
        switch_on_all_leds();
        _delay_ms(delay);
    }
}

/*
 * switch on every dels depending of the percentage p
 */
//#define roundp floor
inline int roundp(double n) {
    return floor(n+0.5);
}

// roundp = round for positive number
void show_percent(double p) {
    // p pourcent
    int n;
    //n = 4;
    n = roundp(p / 100.0 * Nleds); // TO FIX (math.h ceil floor ... round en Java !)
    // TO FIX : +0.5 is a very dirty hack
    switch_on_min_dels(n);
}

/*
 * send a sound (on or more beep(s))
 */
void beep(int n, double delay) {
    // TO DO
    int i;
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
inline void StartStopChronometer() {
    beep(1,100);
    led_alarm(3,50);
    if (running_chronometer) {
       running_chronometer = FALSE; // false = 0
    } else {
       running_chronometer = TRUE; // true = -1
    }
}

void TestRunningChronometer() {
    if (running_chronometer) {
        switch_on_led(8);
        _delay_ms(100);
        switch_off_led(8);
        _delay_ms(100);
    }
}


/*
 *  init function
 */
void init() {
   // ******************
   // * WatchDog Timer *
   // ******************


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
   int channel = 0; // measure ADC0

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

   // Sound
   beep(3,300);

   // Time
   running_chronometer = FALSE;
   init_time(&current_time);
   init_time(&last_time);
   init_time(&best_time);

}

/*
 * convert from analog to digital (10 bits)
 */
unsigned short adcConvert10bit(unsigned char ch)
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
#define B_LEFT 0
#define B_RIGHT 1
#define B_UP 2
#define B_DOWN 3
#define B_OK 4
#define B_CANCEL 5

void SeekButtons(void) {
    int bstate = 0;
    int i;
	 for (i=0; i<=Nbuts-1; i++) {
	     if ( (PINB>>i) == 0 ) {
	         bstate = TRUE;
	     } else {
	         bstate = FALSE;
	     }
		
	     if ( i==0 && bstate ) { // LEFT

	     }
	     if ( i==1 && bstate ) { // RIGHT

	     }
	     if ( i==2 && bstate ) { // UP

	     }
	     if ( i==3 && bstate ) { // DOWN

	     }
	     if ( i==4 && bstate ) { // OK
            StartStopChronometer();
	     }
	     if ( i==5 && bstate ) { // CANCEL

	     }	     	     	     	
	}
}

/*
 *  this is the main loop
 */
void loop(void) {
    SeekButtons();

    double ch0 = adcConvert10bit(0);
    ch0 *= 0.09765625; // 0.09765625 = 100 / 2^10
    show_percent(ch0);

/*
    _delay_ms(500);

    double ch1 = adcConvert10bit(1);
    ch1 *= 0.09765625; // 0.09765625 = 100 / 2^10
    show_percent(ch1);

    _delay_ms(500);
*/

    TestRunningChronometer();

    inc_time(&current_time);
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
 * interrupt handler for INT0
 */
SIGNAL(SIG_INTERRUPT0) {
    StartStopChronometer();
}

