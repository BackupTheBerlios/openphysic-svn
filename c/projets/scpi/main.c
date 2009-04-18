/*
This program emulate a device's firmware which is
able to uderstand some SCPI commands
Standard Commands for Programmable Instruments (SCPI)
*/

#include <stdio.h> 
#include <string.h>

int main(void)
{
  puts("Running");

  char* s;
  
  while(1) {
    puts("mydevice> ");
    fgets(s, 10, stdin);
    
    if ( strcmp(s,"IDN")==0 ) {
      puts("*IDN? identification \r\n");
    } else {
      puts("Error ! this firmware doesn't understand this command\r\n");
    }
  }

  puts("Stopping\r\n"); /* it should never happen */
  
  return 0;
}
