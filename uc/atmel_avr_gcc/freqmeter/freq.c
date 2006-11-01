// from http://www.jelectronique.com/pwm.php
// pwm_atmega32 pour la génération du signal

#define F_CPU 4000000UL

#include <avr/io.h>

#include <avr/interrupt.h>

#include <stdio.h>
#include "lcd.h"	//Fonction de gestion LCD (Fleury)
#include "lcd.c"

// Declare your global variables here

uint8_t FREQ = 0;

static FILE lcdout = FDEV_SETUP_STREAM( (void *)lcd_putc, NULL,_FDEV_SETUP_WRITE );

void display(void) {
   lcd_clrscr();

   lcd_gotoxy(0,0); 	//Curseur  1ère colonne 1ère ligne
   lcd_puts("Hello");
   lcd_gotoxy(0,1);
   printf("%d",FREQ);
}

void init_lcd(void) {
   // Port des bits de données du lcd
   PORTC=0x00;
   DDRC=0xFF; //Port en sortie
   // Port des bits de controles du lcd
   PORTB=0x00;   // R/W=0
   DDRB=0xFF;//Port en sortie

   lcd_init(LCD_DISP_ON_CURSOR_BLINK); //Initialisation curseur clignotant
   lcd_command(LCD_DISP_ON); //curseur éteint

   stdout = &lcdout; // printf

   lcd_clrscr(); //efface l'écran
   //Active la gestion des accents français	éèêëàùçô
   lcd_ChargeAccentsFrancais(); // Charge 8 caractères accentués dans la CGRAM et active leur utilisation
}

void init_signal(void) {

// Port D initialization
// Func7=In Func6=In Func5=Out Func4=In Func3=In Func2=In Func1=In Func0=In
// State7=T State6=T State5=0 State4=T State3=T State2=T State1=T State0=T
PORTD=0x00;
DDRD=0x20;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=FFh
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 62,500 kHz
// Mode: Fast PWM top=ICR1
// OC1A output: Non-Inv.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x82;
TCCR1B=0x1B;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x04; //Ox04
ICR1L=0xE2;
OCR1AH=0x00;
OCR1AL=0x1F;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer 2 Stopped
// Mode: Normal top=FFh
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;
}

void init_frequencemeter(void) {
// init the external interrupt
MCUCR |= (1<<ISC01) | (1<<ISC00); // rising edge INT0 ATmega32
GICR |= (1<<INT0);
sei(); // enable interrupts

// init the counter
TCNT0=0x00; // initial value
// prescaler (shared with TIMER/COUNTER1 on ATmega32)
//TCCR0=0x03;	        //Lancement du comptage avec prédiv de 64
TCCR0=(1<<CS02)|(0<<CS01)|(1<<CS00); // prédiv de 1024
//TCCR0=(1<<CS02)|(0<<CS01)|(0<<CS00); // prédiv de 256
//TCCR0=(0<<CS02)|(1<<CS01)|(1<<CS00); // prédiv de 64
//TCCR0=(0<<CS02)|(1<<CS01)|(0<<CS00); // prédiv de 8
//TCCR0=(0<<CS02)|(0<<CS01)|(1<<CS00); // pas de prédiv

// init output (for test)
DDRA=0xFF; // port A en sortie
PORTA=0xFF; // switch off led

}

int main(void)
{
// Declare your local variables here

init_signal();

init_frequencemeter();

init_lcd();


while (1)
      {
      display();
      asm("nop");          // Inline assembly example
      asm("nop");          // Inline assembly example
      };

return 0;
}

/*
 * interrupt handler for INT0 (input)
 */
ISR(INT0_vect)
{
	 FREQ = TCNT0;
	
    //PORTA=~PORTA; // test interrupt
    PORTA=~TCNT0;

    // counter
    TCNT0=0x00; // initialize counter
}





