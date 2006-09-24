/***************************************************************************
 *   Copyright (C) 2006 by Sebastien CELLES                                *
 *   s.cls@laposte.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
inline void display_openchrono_center(void) {
   lcd_clrscr();
 //lcd_EcrisAuCentre("12345678901234567890",0);
 //lcd_EcrisAuCentre("===OpenChrono===",0);
 //lcd_EcrisAuCentre("----S.CELLES----",1);
   //lcd_printf("OpenChrono");
   lcd_EcrisAuCentre("OpenChrono",0);
   lcd_EcrisAuCentre("S.Celles",1);
}

inline void display_openchrono(void) {
   lcd_clrscr();

   lcd_gotoxy(0,0); 	//Curseur  1ère colonne 1ère ligne
   lcd_puts("OpenChrono");
   lcd_gotoxy(0,1);
   lcd_puts("S. CELLES");

   //delay_ms(500); // delay (Fleury)
   _delay_ms(250);
   //lcd_clrscr();
}


inline void display_time(void)
{
    // clear screen
    // TO DO
    lcd_clrscr();

    // line 1

    print_time_mm_ss_xxx(&current_time); // ZONE 1

    printf(" ");

    print_time_mm_ss_xxx(&best_time); // ZONE 2


    printf("\n");
    // line 2

    print_time_mm_ss_xxx(&last_time); // ZONE 3

    printf(" ");

    // ZONE 4
    if( compare_time(&current_time,&last_time) == 0 )
    {
        printf("LST=");
    }
    if( compare_time(&current_time,&last_time) == 1 )
    {
        printf("LST-");
    }
    if( compare_time(&current_time,&last_time) == 2 )
    {
        printf("LST-");
    }

    if( compare_time(&current_time,&best_time) == 0 )
    {
        printf("BST=");
    }
    if( compare_time(&current_time,&best_time) == 1 )
    {
        printf("BST-");
    }
    if( compare_time(&current_time,&best_time) == 2 )
    {
        printf("BST+");
    }

}

void display(void) {
   //display_openchrono_center();
   display_time();
}



