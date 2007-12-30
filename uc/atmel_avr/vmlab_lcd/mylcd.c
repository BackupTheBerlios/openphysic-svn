// ***********************************************************
// Project: Test LCD
// Author: S. CELLES
// Module description: Essai LCD avec VMLAB, WinAVR et la
//                     biblioth�que LCD de Fleury
// ***********************************************************

#define F_CPU 4000000UL		//1MHz

#include "lcd.h"	//Fonction de gestion LCD (Fleury)
#include "lcd.c"
//#include "sup_avr/delay.h"

#include <util/delay.h>

void init(void) {
   // Port des bits de donn�es du lcd
   PORTC=0x00;
   DDRC=0xFF; //Port en sortie
   // Port des bits de controles du lcd
   PORTD=0x00;   // R/W=0
   DDRD=0xFF;//Port en sortie

   lcd_init(LCD_DISP_ON_CURSOR_BLINK); //Initialisation curseur clignotant
   lcd_command(LCD_DISP_ON); //curseur �teint

   lcd_clrscr(); //efface l'�cran
   //Active la gestion des accents fran�ais	��������
   lcd_ChargeAccentsFrancais(); // Charge 8 caract�res accentu�s dans la CGRAM et active leur utilisation
}

void display(void) {
   lcd_clrscr();

   lcd_gotoxy(0,0); 	//Curseur  1�re colonne 1�re ligne
   lcd_puts("Boujour");
   lcd_gotoxy(0,1);
   lcd_puts("le monde");

   //delay_ms(500); // delay (Fleury)
   _delay_ms(250);
   //lcd_clrscr();
}

// ***********************************************************
// Main program
//
int main(void) {
    init();
    while(1) {             // Infinite loop
        display();
    }
    return 0;
}



