#include <avr/io.h>
#include <avr/interrupt.h>

#define MIN 0x00
#define MAX 0xFF
#define MID 0x80

uint8_t i;

struct signal
{
   double freq;
   double alpha;
   double amplitude;
   double offset;
   void (*calculate) ();     // ptr de fct sur fonction
};

struct signal sgn;


inline void func_test_signal(void) {
   i++;
   PORTB = i;
}

inline void func_test_min(void) {
   PORTB = MIN;
}

inline void func_test_max(void) {
   PORTB = MAX;
}

inline void func_test_mid(void) {
   PORTB = MID;
}

void init_signal(void) {
	(&sgn)->freq = 5000.0;
	(&sgn)->alpha = 0.5;
	(&sgn)->amplitude = 1.0;
	(&sgn)->offset = 0.0;

   (&sgn)->calculate = &func_test_signal;
	//(&sgn)->calculate = &func_test_min;
	//(&sgn)->calculate = &func_test_max;
	//(&sgn)->calculate = &func_test_mid;
}

int main(void) {
   /* enable PORT Bx as output (led) */
   DDRB = 0xFF;

   PORTB = 0xFF; // TO FIX DAC problem

   i = 0;

	init_signal();

   while(1) {
   	//PORTB = 0x00; //0xFF;
      //func_test_signal();
      //func_test_mid();
      (&sgn)->calculate();
   }

}



