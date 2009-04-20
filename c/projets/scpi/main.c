/*
This program emulate a device's firmware which is
able to understand some SCPI commands
Standard Commands for Programmable Instruments (SCPI)

Supported commands are:
*IDN? : get device identification
MEASure? : get value stored in the device
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "scpi.h"
#include "cmds.h"
#include "tests.h"

char s[STR_SIZE]; /* received string */
int parse_result;

/**
 * \fn int main (void)
 * \brief Program's entry point.
 *
 * \return 0 - Arrt normal du programme.
 */
int main(void) {
  printf("Running\n");
  
  tests();
  
  while(1) {
    printf("mydevice> "); /* show device prompt */
    /* scanf("%s",s); *//* sending query string to device */
    fgets(s, STR_SIZE, stdin);
    /* delete \n char */
    s[strlen(s)-1]='\0';
    printf("%s\n",s);
    
    /* parse query string */
    do {
      parse_result = SCPI_Parse(s);
    } while (parse_result != 0);
    
  }

  printf("Stopping\n"); /* it should never happen on a real device ! */
  
  return EXIT_SUCCESS;
}
