/*
This program emulate a device's firmware which is
able to uderstand some SCPI commands
Standard Commands for Programmable Instruments (SCPI)
*/

#include <stdio.h> 
#include <ctype.h>

#include "scpi.h"

#define STR_SIZE 10
char s[STR_SIZE]; /* received string */
char s2[STR_SIZE]; /* string converted to upper case */
int i;

int main(void)
{
  printf("Running\n");
  
  while(1) {
    printf("mydevice> ");
    scanf("%s",s);
    for (i=0 ; i<STR_SIZE ; ++i)
    {
      s2[i]=toupper(s[i]);
    }
    if ( SCPI_Compare(s2,"*IDN?") ) {
      printf("*IDN? = device identification\n");
    } else {
      fprintf(stderr,"Error ! this firmware doesn't understand this command\n");
    }
  }

  printf("Stopping\n"); /* it should never happen */
  
  return 0;
}
