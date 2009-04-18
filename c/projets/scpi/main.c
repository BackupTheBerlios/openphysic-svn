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
int parse_result;

int main(void)
{
  printf("Running\n");
  
  while(1) {
    printf("mydevice> "); /* show device prompt */
    scanf("%s",s); /* sending query string to device */
    
    /* convert to upper case */
    for (i=0 ; i<sizeof(s)-1 ; ++i)
    {
      s2[i]=toupper(s[i]);
    }
    
    /* parse query string */
    do {
      parse_result=SCPI_Parse(s2);
    } while (parse_result!=0);
    
  }

  printf("Stopping\n"); /* it should never happen */
  
  return 0;
}
