#include "scpi.h"
#include "cmds.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>

int i;

int SCPI_Compare(char * s1, char * s2) {
  return strcmp(s1, s2)==0;
}

/* convert to upper case */
char * strupr(char * s) {
  for (i=0 ; i<sizeof(s) ; ++i)
  {
    s[i] = toupper(s[i]);
  }
  return s;
}

int SCPI_Parse(char * s) {
  s=strupr(s);
  
  printf("%s",s);

  if ( SCPI_Compare(s,"*IDN?") ) {
    printf("*IDN? = device identification\n");
  } else if ( SCPI_Compare(s,"MEASure?") ) {
    printf("Measure=\n");
  } else {
    fprintf(stderr,"Error ! this firmware doesn't understand this command\n");
  }
  return 0;
}
