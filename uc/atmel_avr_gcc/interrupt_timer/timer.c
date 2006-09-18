// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************
/* TO DO
CTC MODE

*/
#include <avr/io.h>              // Most basic include files
#include <avr/interrupt.h>       // Add the necessary ones
#include <avr/signal.h>          // here

#include <stdbool.h>


// Define here the global static variables
//
bool light_on = false;


void light_on_off(void) {
   if (light_on)
     PORTC = 0x00; // switch on all leds
   else
     PORTC = 0xFF; // switch off all leds
}

// Interrupt handler example for INT0
//
//SIGNAL(SIG_INTERRUPT0) {
//}

// Interrupt handler for TIMER
//SIGNAL(SIG_OUTPUT_COMPARE1A) {
ISR(TIMER1_COMPA_vect) {
   light_on = ~light_on;

   light_on_off();
}

// init
void init(void) {
   DDRC=0xFF; // set up PORTC pins 0 to 7 as output

   light_on_off();

   // Timer init
   ICR1H=0x00;
   ICR1L;0x63;
   OCR1AH=0x00;
   OCR1AL=0x31;

   TIMSK=(1<<OCIE1A)|(1<<TOIE1);
}

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
void my_function(void) {  // Put the open brace '{' here
   // In the loop !

   //asm("nop");          // Inline assembly example
}

// ***********************************************************
// Main program
//
int main(void) {
   init();
   while(1) {             // Infinite loop; define here the
      my_function();      // system behaviour
   }
   return 0;
}

