#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>
#include <avr/delay.h>

#define KEY0 0
#define KEY1 1
#define KEY2 2
#define KEY3 3
#define KEY4 4
#define KEY5 5
#define KEY6 6
#define KEY7 7


ISR(SIG_INTERRUPT0) {	
	//PORTB = PINC;	

	if ( PINC & (1<<KEY0) ) {
	   PORTB |= (1<<KEY0);
	}
	else {
	   PORTB &= (~(1<<KEY0));
	}

	if ( PINC & (1<<KEY1) ) {
	   PORTB |= (1<<KEY1);
	}
	else {
	   PORTB &= (~(1<<KEY1));
	}
	

	
}

int main(void) {
   // PORTD INPUT (INT)
   DDRD = 0x00;
   PORTD = 0xFF;

   //MCUCR = (1<<ISC01) | (1<<ISC00); // Interruption sur appui d'une touche (front montant INT0)
   MCUCR = (0<<ISC01) | (1<<ISC00); // Interruption sur appui ou relachement de touche

   GICR = (1<<INT0);

   sei();

   // PORTC (KEY)
   DDRC = 0x00;
   PORTC = 0xFF;

   // PORTB OUTPUT (LED)
   DDRB = 0xFF;
   PORTB = 0xFF; // LED OFF

   while(1) {
   }

}


