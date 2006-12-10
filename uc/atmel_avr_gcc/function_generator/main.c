#include <avr/io.h>
#include <avr/interrupt.h>

#include <math.h>

#define F_CPU 8000000UL  // 8 MHz

#define MIN 0x00
#define MAX 0xFF
#define MID 0x80

#define PORTOUT PORTB

//uint8_t i;

double time;


struct signal
{
   double freq;
   double alpha;
   double amplitude;
   double offset;
   void (*calculate) ();     // ptr de fct sur fonction de calcul
};

struct signal sgn;



inline void func_test_signal_inc(void) {
   //i++;
   //PORTOUT = i;
   PORTOUT++;
}

inline void func_test_signal_dec(void) {
   PORTOUT--;
}

inline void func_test_min(void) {
   PORTOUT = MIN;
}

inline void func_test_max(void) {
   PORTOUT = MAX;
}

inline void func_test_mid(void) {
   PORTOUT = MID;
}

void func_sin(void) {
   // TO DO
   PORTOUT = MID*sin(time)+MID;
}

void func_square(void) {
   // TO DO
}

void func_triangle(void) {
   // TO DO
}

void func_rampe_croissante(void) {
   // TO DO
   // triangle avec alpha = 0
}

void func_rampe_decroissante(void) {
   // TO DO
   // triangle avec alpha = 1
}



void init_signal(void) {
	(&sgn)->freq = 5000.0;
	(&sgn)->alpha = 0.5;
	(&sgn)->amplitude = 1.0;
	(&sgn)->offset = 0.0;

   //(&sgn)->calculate = &func_test_signal_inc;
   //(&sgn)->calculate = &func_test_signal_dec;
	//(&sgn)->calculate = &func_test_min;
	//(&sgn)->calculate = &func_test_max;
	//(&sgn)->calculate = &func_test_mid;
	(&sgn)->calculate = &func_sin;
}

int main(void) {
   /* enable PORT Bx as output (led) */
   DDRB = 0xFF;

   PORTOUT = 0xFF; // PORTB TO FIX DAC problem

   /* variable for test purpose */
   //i = 0;

   /* init counter */
   OCR1AH = 0x00;
   OCR1AL = 0x00;
   //OCR1AH=0x03; //Ox00
   //OCR1AL=0x20; //0x63

	TCCR1A = 0x00;
	TCCR1B = (0<<CS12)|(0<<CS11)|(1<<CS10);
	
   //TCCR1B |=(1<<WGM12)|(0<<CS11)|(1<<CS10); //CTC division F_CPU 1  (1<<WGM12)|(1<<CS11)|(1<<CS10)

   TIMSK |= (1<<OCIE1A);

	time = 0.0;

   //sei(); // set interrupt enable

   /* init signal */
   init_signal();

	uint8_t tmrh;
	uint8_t tmrl;
   while(1) {
   	tmrh = TCNT1H;
   	tmrl = TCNT1L;
		time = (double) (((tmrh<<8) + tmrl)/pow(2,16)); // TO FIX

      (&sgn)->calculate();
   }

}



/*
 * interrupt handler for TIMER
 */
//SIGNAL(SIG_OUTPUT_COMPARE1A)
//ISR(TIM1_COMPA_vect)
ISR(SIG_OUTPUT_COMPARE1A)
{
// TO DO
}
