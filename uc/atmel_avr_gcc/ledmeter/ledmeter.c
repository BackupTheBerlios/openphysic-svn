// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr/io.h>              // Most basic include files

#include <math.h>

#define F_CPU 1000000UL  // 1 MHz
#include <avr/delay.h>

//#include <avr/io.h>              // Most basic include files
#include <avr/interrupt.h>       // Add the necessary ones
//#include <avr/signal.h>          // here


volatile unsigned char a2dCompleteFlag;


#define Nleds 8  // number of leds connected to the uC

#define N 50 // number between 0 and 255
#define Nmax 0xFF



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
    int mask = ~(0x01<<pin);
    PORTC&=mask;
}

/*
 *  switch off the led with the number called "led"
 */
void switch_off_led(int led) {
    int pin = led - 1;
    int mask = (0x01<<pin);
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
 *  switch on every leds (from 0 to n)
 */
void switch_on_min_dels(int n) {
    int i;
    for(i = 1; (i<=Nleds) && (i<=n); i++) {
        switch_on_led(i);
    }
}

/*
 *  switch on every leds (from Nleds to n)
 */
void switch_on_max_dels(int n) {
    int i;
    for(i = Nleds; i>=n; i--) {
        switch_on_led(i);
    }
}

/*
 * switch off every leds, wait and swith them all, n times (a sort of visual alarm)
 */
void led_alarm(int n) {
    int i;
    for(i = 1; i<=n; i++) {
        switch_off_all_leds();
        _delay_ms(100);
        switch_on_all_leds();
        _delay_ms(100);
    }
}

/*
 * switch on every dels depending of the percentage p
 */
void show_percent(double p) {
    // p pourcent
    int n;
    //n = 4;
    n = floor(p / 100.0 * Nleds); // TO FIX (math.h ceil floor ...)
    switch_on_min_dels(n);
}


/*
 * Start or stop chronometer
 */
void StartStopChronometer() {
    led_alarm(3);
}

/*
 * Interrupt handler example for INT0
 */
SIGNAL(SIG_INTERRUPT0) {
    //StartStopChronometer();
    switch_on_led(8);
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

   // interrupt on INT0 pin falling edge (sensor triggered)
   MCUCR = (1<<ISC01) | (1<<ISC00);

   // turn on interrupts!
   //GIMSK  |= (1<<INT0); // TO FIX

   // *************************************************
   // * Conv Analog to Digital (CAN for RPM and Temp) *
   // *************************************************

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
*/
	
	// configure a2d port (PORTA) as input
	// so we can receive analog signals
   DDRA=0x00;
	// make sure pull-up resistors are turned off
	PORTA = 0x00;

   // ***************
   // * Graphic LCD *
   // ***************
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
 *  This is the main loop
 */
void loop(void) {
   show_percent(0x80 * 100 / 0xFF);
   //show_percent(adcConvert10bit(0));

   //show_percent(25);
   //_delay_ms(500);                                how
   //show_percent(50);
   //_delay_ms(500);
   //show_percent(100);

   //led_alarm(3);

   //test_leds();
   //switch_on_min_dels(5);
   //switch_on_max_dels(3);

	//switch_on_led(3);
	//switch_on_led(5);
	//switch_on_led(7);	
	
	//switch_off_led(5);
}


/*
 * Main program
 */
int main(void) {
   init();

   while(1) {             // Infinite loop; define here the
      loop();      // system behaviour
   }

   return 0;
}





