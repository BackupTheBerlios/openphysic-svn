#include "scpi.h"
#include "cmds.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int i;

/**
 * \fn int SCPI_Compare(char * s1, char * s2)
 * \brief Compare two strings
 *
 * \param s1 string to compare.
 * \param s2 string to compare.
 * \return 0 if s1==s2.
 */
int SCPI_Compare(char * s1, char * s2) {
  /* s2=strupr(s2); */
  return strcmp(s1, s2)==0;
}


/**
 * \fn char * str_toupper (const char *ct)
 * \brief Convert a string to upper case.
 *
 * \param ct string to convert.
 * \return Converted string.
 */
char * str_toupper (const char *ct) {
  char *s = NULL;
  if (ct != NULL) {
    int i;
    s = malloc (sizeof (*s) * (strlen (ct) + 1));
    if (s != NULL) {
      for (i = 0; ct[i]; i++) {
        s[i] = toupper (ct[i]);
      }
      s[i] = '\0';
    }
  }
  return s;
}


/**
 * \fn char * SCPI_Abbreviate (const char *ct)
 * \brief Convert a string to its abbreviated form.
 *
 * \param ct string to convert.
 * \return Converted string.
 */
char * SCPI_Abbreviate (const char *ct) {
  char *s = NULL;
/*	strcpy(s,ct);
  
  if (ct != NULL) {
	strcpy(s,ct);
  }
  return s;
  */
  
  int i;
  
  int state;
  state=0;
  /*
  state==0 : upper case
  state==1 : lower case
  state==2 : end of query string (symbol ? ...)
  */
  for (i = 0; i<strlen(ct)+1 ; i++) {
    if(state==0) {
    
    }
    
    if (state==1) {
    
    }
    
    if (state==2) {
    
    }
  
    printf("%c",ct[i]);
  }
  printf("\n");
      
  /* printf("%d\n",sizeof (*s) * (strlen (ct) + 1)); */
  
  /* return str_toupper(ct); */
  
  return s;
}


/**
 * \fn int SCPI_Parse(char * s)
 * \brief Parse a query string.
 *
 * \param s string to parse.
 * \return 0 if string has been well parsed.
 */
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
