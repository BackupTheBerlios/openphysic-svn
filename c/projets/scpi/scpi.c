#include "scpi.h"
#include "cmds.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int i;

int SCPI_Compare(char * s1, char * s2) {
  /* s2=strupr(s2); */
  return strcmp(s1, s2)==0;
}

/* convert to upper case */
char *str_toupper (const char *ct)
{
  char *s = NULL;
  if (ct != NULL) {
    int i;
    /* (1) */
    s = malloc (sizeof (*s) * (strlen (ct) + 1));
    if (s != NULL) {
      /* (2) */
      for (i = 0; ct[i]; i++) {
        s[i] = toupper (ct[i]);
      }
      s[i] = '\0';
    }
  }
  return s;
}

int SCPI_Parse(char * s) {
  /* s=strupr(s); */
  
  /* printf("%s",s); */

  if ( SCPI_Compare(s,"*IDN?") ) {
    printf("*IDN? = device identification\n");
  } else if ( SCPI_Compare(s,"MEASure?") ) {
    printf("Measure=\n");
  } else {
    fprintf(stderr,"Error ! this firmware doesn't understand this command\n");
  }
  return 0;
}
