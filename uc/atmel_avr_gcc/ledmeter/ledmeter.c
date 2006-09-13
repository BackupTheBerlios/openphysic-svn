// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr/io.h>              // Most basic include files

#include <math.h>

#define F_CPU 1000000UL  // 1 MHz
#include <avr/delay.h>

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



void switch_on_all_leds() {
    PORTD = 0x00;
}

void switch_off_all_leds() {
    PORTD = 0xFF;
}

// led from 1 to 8 (LEDSNUM)
// PDx with w from 0 to 7
void switch_on_led(int led) {
    int pin = led - 1;
    int mask = ~(0x01<<pin);
    PORTD&=mask;
}

void switch_off_led(int led) {
    int pin = led - 1;
    int mask = (0x01<<pin);
    PORTD|=mask;
}



void switch_on_leds_with_delay(double delay) {
    int i;
    for(i = 1; i<=Nleds; i++) {
        _delay_ms(delay);
        switch_on_led(i);
    }
}

void switch_off_leds_with_delay(double delay) {
    int i;
    for(i = Nleds; i>=0; i--) {
        _delay_ms(delay);
        switch_off_led(i);
    }
}

void test_leds() {
    switch_on_leds_with_delay(100);
    _delay_ms(50);
    switch_off_leds_with_delay(100);
}

void switch_on_min_dels(int n) {
    int i;
    for(i = 1; (i<=Nleds) && (i<=n); i++) {
        switch_on_led(i);
    }
}

void switch_on_max_dels(int n) {
    int i;
    for(i = Nleds; i>=n; i--) {
        switch_on_led(i);
    }
}

void show_percent(double p) {
    // p pourcent
    int n;
    //n = 4;
    n = floor(p / 100.0 * Nleds); // TO FIX (math.h ceil floor ...)
    switch_on_min_dels(n);
}


void init() {

   DDRD=0xFF; // set up PORTD pins 0 to 7 as output

   //switch_on_all_leds();
   switch_off_all_leds();
}

void loop(void) {
   show_percent(25);

   //test_leds();
   //switch_on_min_dels(5);
   //switch_on_max_dels(3);

	//switch_on_led(3);
	//switch_on_led(5);
	//switch_on_led(7);	
	
	//switch_off_led(5);
}

// ***********************************************************
// Main program
//
int main(void) {
   init();

   while(1) {             // Infinite loop; define here the
      loop();      // system behaviour
   }

   return 0;
}


