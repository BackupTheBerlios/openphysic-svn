#include <avr/io.h>
#include <avr/interrupt.h>

#include <math.h>
#define PI 4*atan(1)

#define F_CPU 8000000UL  // 8 MHz

#define MIN 0x00
#define MAX 0xFF
#define MID 0x80

#define PORTOUT PORTB

uint8_t i;

double time;

#define N 256 // nb de valeurs precalculees
uint8_t tab_signal[N];
//uint8_t * ptr_tab_signal[];


struct signal
{
   double freq;
   double alpha;
   double amplitude;
   double offset;
   void (*init) ();     // ptr de fct sur fonction de calcul
};

struct signal sgn;

inline void func_test_signal_inc(void) {
   PORTOUT++;
}

inline void func_test_signal_dec(void) {
   PORTOUT--;
}


// sine wave
// square
// triangle
// sawtooth
// inverted sawtooth

void init_func_sin(void) {
   uint16_t j;
   uint8_t tmp;
	for(j = 0 ; j<N ; j++ ) {
	   tmp = MID * sin(2*PI/N*j) + MID;
	   tab_signal[j] = tmp;	
	}
}

void init_func_min(void) {
   uint16_t j;
	for(j = 0 ; j<N ; j++ ) {
	   tab_signal[j] = MIN;	
	}
}	

void init_func_max(void) {
   uint16_t j;
	for(j = 0 ; j<N ; j++ ) {
	   tab_signal[j] = MAX;	
	}
}

void init_func_mid(void) {
   uint16_t j;
	for(j = 0 ; j<N ; j++ ) {
	   tab_signal[j] = MID;	
	}
}
	
void init_signal(void) {
	(&sgn)->freq = 5000.0;
	(&sgn)->alpha = 0.5;
	(&sgn)->amplitude = 1.0;
	(&sgn)->offset = 0.0;

	(&sgn)->init = &init_func_sin;
	
	(&sgn)->init();
}

int main(void) {
   /* enable PORT Bx as output (led) */
   DDRB = 0xFF;

   PORTOUT = 0xFF; // PORTB TO FIX DAC problem
   PORTOUT = 0x00;

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

	//uint8_t tmrh;
	//uint8_t tmrl;
   while(1) {
   	//tmrh = TCNT1H;
   	//tmrl = TCNT1L;
		//time = (double) (((tmrh<<8) + tmrl)/pow(2,16)); // TO FIX

      //(&sgn)->calculate();
      i++;
      PORTOUT = tab_signal[i];
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

