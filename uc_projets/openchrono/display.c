void display(void) {
   lcd_clrscr();

   lcd_gotoxy(0,0); 	//Curseur  1ère colonne 1ère ligne
   lcd_puts("Boujour");
   lcd_gotoxy(0,1);
   lcd_puts("le monde");

   //delay_ms(500); // delay (Fleury)
   _delay_ms(250);
   //lcd_clrscr();     
}


void display2(void)
{
    // clear screen
    // TO DO

    // line 1

    print_time(&current_time); // ZONE 1

    printf(" ");

    print_time(&best_time); // ZONE 2


    printf("\n");
    // line 2

    print_time(&last_time); // ZONE 3

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
