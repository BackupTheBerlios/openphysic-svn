#include "scpi.h"

#include <string.h>
#include <stdio.h>

int SCPI_Compare(char * s1, char * s2) {
  return strcmp(s1, s2)==0;
}

int SCPI_Parse(char * s) {
  if ( SCPI_Compare(s,"*IDN?") ) {
    printf("*IDN? = device identification\n");
  } else {
    fprintf(stderr,"Error ! this firmware doesn't understand this command\n");
  }
  return 0;
}