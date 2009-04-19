/*
This program emulate a device's firmware which is
able to understand some SCPI commands
Standard Commands for Programmable Instruments (SCPI)
*/

#include <stdio.h>
#include <string.h>

#include "scpi.h"
#include "cmds.h"

char s[STR_SIZE]; /* received string */
int parse_result;

char s1[STR_SIZE];
char * s2;

/**
 * \fn int main (void)
 * \brief Program's entry point.
 *
 * \return 0 - Arrt normal du programme.
 */
int main(void) {
  printf("Running\n");
  
  
  strcpy(s1,"*MEASure?");
  s2=SCPI_Abbreviate(s1);
  printf("%s\n",s1);
  printf("%s\n",s2);
  
  
  while(1) {
    printf("mydevice> "); /* show device prompt */
    scanf("%s",s); /* sending query string to device */
    
    /* parse query string */
    do {
      parse_result = SCPI_Parse(s);
    } while (parse_result != 0);
    
  }

  printf("Stopping\n"); /* it should never happen on a real device ! */
  
  return 0;
}
