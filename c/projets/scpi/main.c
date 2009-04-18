/*
This program emulate a device's firmware which is
able to uderstand some SCPI commands
Standard Commands for Programmable Instruments (SCPI)
*/

#include <stdio.h> 
#include <string.h>

#define STR_SIZE 10
char s[STR_SIZE];
char * p;

int main(void)
{
  puts("Running");
  
  while(1) {
    puts("mydevice> ");
    fgets(s, STR_SIZE, stdin);
    /* ToDo 
      Enlever le \n dans la cha”ne
      Mettre en majuscule
    */
    if ( strcmp(s, "*IDN?\n")==0 ) {
      puts("*IDN? = device identification");
    } else {
      fprintf(stderr,"Error ! this firmware doesn't understand this command");
    }
  }

  puts("Stopping"); /* it should never happen */
  
  return 0;
}
