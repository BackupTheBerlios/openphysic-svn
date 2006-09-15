// ***********************************************************
// Project: OpenChrono
// Author: Sebastien CELLES
// Module description: an handhelds device for karts, bike or sport cars
// ***********************************************************

#include <avr/io.h>              // Most basic include files

#include <math.h>

#define F_CPU 1000000UL  // 1 MHz
#include <avr/delay.h>

//#include <avr/io.h>              // Most basic include files
#include <avr/interrupt.h>       // Add the necessary ones
//#include <avr/signal.h>          // here


volatile unsigned char a2dCompleteFlag;

int channel;
unsigned short analog_result;
int analog_busy;

#define Nleds 8  // number of leds connected to the uC

#define N 50 // number between 0 and 255
#define Nmax 0xFF


typedef struct {
    int hh; //8bits 0-255
    int mm; //8bits 0-255
    int ss; //8bits 0-255
    unsigned short int xx;  //16bits 0-65535
} time_t;

time_t current_time;
time_t last_time;
time_t best_time;

int running_chronometer = 0; // 0 false ; -1 true

void init_time(time_t time) {
    time.hh = 0;
    time.mm = 0;
    time.ss = 0;
    time.xx = 0;
}

void inc_time(time_t time) {
  if (running_chronometer) {
    time.xx++;
    if(time.xx >= 1000) {
        time.xx = 0;
        time.ss++;
        if (time.ss >= 60) {
            time.ss = 0;
            time.mm++;
            if (time.mm >= 60) {
                time.mm = 0;
                time.hh++;
                if (time.hh >= 24) {
                    time.hh = 0;
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
 *
 */
void switch_on_all_leds() {
    PORTC = 0x00;
}

/*
 *
 */
void switch_off_all_leds() {
    PORTC = 0xFF;
}

// led from 1 to 8 (LEDSNUM)
// PCx with w from 0 to 7

/*
 *  switch on the led with the number called "led"
 */
void switch_on_led(int led) {
    int pin = led - 1;
    int mask = ~(1<<pin);
    PORTC&=mask;
}

/*
 *  switch off the led with the number called "led"
 */
void switch_off_led(int led) {
    int pin = led - 1;
    int mask = (1<<pin);
    PORTC|=mask;
}

/*
 *  switch on every leds one after one with a delay (called "delay")
 */
void switch_on_leds_with_delay(double delay) {
    int i;
    for(i = 1; i<=Nleds; i++) {
        _delay_ms(delay);
        switch_on_led(i);
    }
}

/*
 *  switch off every leds on after one with a delay (called "delay")
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
void led_alarm(int n) {
    int i;
    for(i = 1; i<=n; i++) {
        switch_off_all_leds();
        _delay_ms(50);
        switch_on_all_leds();
        _delay_ms(50);
    }
}

/*
 * switch on every dels depending of the percentage p
 */
#define round floor
void show_percent(double p) {
    // p pourcent
    int n;
    //n = 4;
    n = round(p / 100.0 * (Nleds+0.5)); // TO FIX (math.h ceil floor ... round en Java !)
    // TO FIX : +0.5 is a very dirty hack
    switch_on_min_dels(n);
}


/*
 * start or stop chronometer
 */
void StartStopChronometer() {
    led_alarm(3);
    if (running_chronometer) {
       running_chronometer = 0; // false
    } else {
       running_chronometer = -1; // true
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
   // ********
   // * Dels *
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
   //GIMSK  |= (1<<INT0); // TO FIX

   GICR |= (1<<INT0); //INT0

   sei(); // enable interrupts

   // *************************************************
   // * Conv Analog to Digital (CAN for RPM and Temp) *
   // *************************************************

   volatile static int analog_result;
   volatile static unsigned char analog_busy;

   analog_busy=1; // busy mark the ADC function
   channel=0; // measure ADC0
   // use internal 2.56V ref
   //outb((1<<REFS1)|(1<<REFS0)|(channel & 0x07),ADMUX);
   ADMUX=(1<<REFS1)|(1<<REFS0)|(channel & 0x07);
   //outb((1<<ADEN)|(1<<ADIE)|(1<<ADIF)|(1<<ADPS2),ADCSRA);
   ADCSRA=(1<<ADEN)|(1<<ADIE)|(1<<ADIF)|(1<<ADPS2);
   //sbi(ADCSRA,ADSC); // start conversion
   (ADCSRA) |= (1 << (ADSC));


   /*
	ADCSRA |= (_BV(ADEN));   // enable ADC (turn on ADC power)
	ADCSRA &= ~(_BV(ADATE)); // default to single sample convert mode

   //  set default prescaler 0x06 -> CPU clk/64      a2dSetPrescaler(0x06)
   ADCSRA = (((ADCSRA) & ~0x07) | 0x06); // ADC_PRESCALE_MASK 0x07
	
   //	a2dSetReference(0x01);	// set default reference ADC_REFERENCE=0x01  ADC_REFERENCE_MASK=
   ADMUX = (((ADMUX) & ~0xC0) | (0x01<<6));
	
	ADMUX &= ~(_BV(ADLAR));  // set to right-adjusted result
   ADCSRA |= (_BV(ADIE));   // enable ADC interrupts

	a2dCompleteFlag = 0;		// clear conversion complete flag (FALSE=0 TRUE=-1)

	__asm__ __volatile__ ("sei" ::);

	
	// configure a2d port (PORTA) as input
	// so we can receive analog signals
   DDRA=0x00;
	// make sure pull-up resistors are turned off
	PORTA = 0x00;
	*/

   // **********
   // * Keypad *
   // **********
   // 1 joystick button (4 directions, up, down, left, right)
   // 2 push buttons (ok, cancel)
   //DDRB=0x00;
   //PORTB=0xFF;

   // ***************
   // * Graphic LCD *
   // ***************

   // Time
   init_time(current_time);
   init_time(last_time);
   init_time(best_time);

}

/*
 * convert from analog to digital (10 bits)
 */
unsigned short adcConvert10bit(unsigned char ch)
{
	a2dCompleteFlag = 0;				// clear conversion complete flag
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

/*
 *  this is the main loop
 */
void loop(void) {
   // Pb voir ADC (interruption)

   //inc_time(current_time);

   //TestRunningChronometer();

   //show_percent(0x80 * 100 / 0xFF);

   /*
   int i;
   for (i = 0; i<=Nleds; i++) {
       //switch_on_max_dels(i);
       switch_on_min_dels(i);
       _delay_ms(500);
   }
   */

   //show_percent(adcConvert8bit(0));
   //show_percent(adcConvert8bit(1));

   /*
   show_percent(25);
   _delay_ms(500);
   show_percent(50);
   _delay_ms(500);
   show_percent(100);
   _delay_ms(500);
   show_percent(75);
   _delay_ms(500);
   show_percent(50);
   */

   //led_alarm(3);

   //test_leds();
   //switch_on_min_dels(5);
   //switch_on_max_dels(3);

	//switch_on_led(3);
	//switch_on_led(5);
	//switch_on_led(7);
	//switch_on_led(8);	
	
	//switch_off_led(5);
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
    //StartStopChronometer();
    StartStopChronometer();
}

/*
 * interrupt handler for ADC
 */
SIGNAL(SIG_ADC) {
   inc_time(current_time);

   TestRunningChronometer();

        unsigned char adlow,adhigh;
        adlow=ADCL; /* read low first, two lines. Do not combine
                          the two lines into one C statement */
        adhigh=ADCH;
        //analog_result=(adhigh<<8)|(adlow & 0xFF);
        analog_busy=0;

        //double ch0 = adcConvert8bit(0) / 2^8 * 100;
        //double ch0 = adcConvert10bit(0) / 2^10 * 100;
        double ch0 = adcConvert10bit(0);
        double ch1 = adcConvert10bit(1);
        ch0 *= 0.09765625; // 0.09765625 = 100 / 2^10
        ch1 *= 0.09765625; // 0.09765625 = 100 / 2^10
        show_percent(ch0);
        //_delay_ms(1000);
        //show_percent(ch1);
        //_delay_ms(1000);
        // TO FIX : problem when using 2 ADC
}




