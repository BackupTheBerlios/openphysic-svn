#include <avr/io.h>

#define PERIOD 20000
#define MIN_WIDTH 1000
#define MAX_WIDTH 2000
#define MED_WIDTH 1500

#include "global.h"		// include our global settings
#include "a2d.h"		// include A/D converter function library (AVRLib)

void init_output(void) {
	// OC1A as output
   DDRB |= (1<<PB1);
   // TOP, set for 50Hz (20ms)
   ICR1 = PERIOD;
   // Center outputs (1.5ms)
	//OCR1A = MIN_WIDTH;
   OCR1A = MED_WIDTH;
	//OCR1A = MAX_WIDTH;
   // Timer 1 fast PWM mode 14
   // Clear on compare, set at TOP
   TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
   //TCCR1B = (1<<WGM13)|(1<<WGM12)|(1<<CS11); // clk=8Mhz - prescaler=8
   TCCR1B = (1<<WGM13)|(1<<WGM12)|(1<<CS10); // clk=1Mhz - no prescaler
}

//unsigned char pos; // 8 bits
unsigned short pos; // 16 bits

int main(void)
{
	init_output();
	
	a2dInit();
	
//	pos=0x00; // MIN
	pos=0x7F; // MED
//	pos=0xFF; // MAX
	
	while (1)
      {
			//pos=a2dConvert8bit(0);
			//pos=a2dConvert8bit(0);
			pos=a2dConvert10bit(0);
			//OCR1A=(pos<<2) + MIN_WIDTH; // 1000 approx 1024
			//OCR1A=((((double) pos)*1000.0)/255.0) + MIN_WIDTH;
			OCR1A=((((double) pos)*1000.0)/1023.0) + MIN_WIDTH;
      };

	return 0;
}


















