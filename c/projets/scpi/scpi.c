#include "scpi.h"
#include "cmds.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int i;

/*
http://groups.google.de/group/de.sci.electronics/msg/c1467276cd3776c9
http://groups.google.fr/group/comp.arch.embedded/browse_thread/thread/ccb95613fc65cb27#
enum TokenType {
        TOKEN_IDN,
        TOKEN_MEAS,
        TOKEN_SET,
        TOKEN_NUMBER
};
*/

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
  char *s2_abb = NULL;
  s2_abb=SCPI_Abbreviate(s2);
  return ( strcasecmp(s1, s2)==0 ) || ( strcasecmp(s1, s2_abb)==0 ) ;
  /*
  strcmp, strncmp - Comparaison de deux cha�nes.
  strcasecmp, strncasecmp - Comparer deux cha�nes en ignorant les diff�rences majuscules/minuscules. 
  */
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
  free(s);
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
  if (ct != NULL) {
    s = malloc (sizeof (*s) * (strlen (ct) + 1)); 
    
    if (ct != NULL) {
      int i, j;
      /* int state=0; */
      j=0;
      /*
      state==0 : upper case
      state==1 : lower case
      state==2 : symbol ? * ...
      */
    
      for (i = 0; i<strlen(ct)+1 ; i++) {
        if ( isalpha(ct[i]) ) {
          if (isupper(ct[i])) {
            /* state=0; */
            s[j]=ct[i];
            j=j+1;
          } /* else {
            state=1;
          } */
        } else {
          /* state=2; */
          s[j]=ct[i];
          j=j+1;
        }
  
        /* printf("%i",state); */
      }
    }
    /* printf("\n"); */
  }
  return s;
}

char *token;
/* const char delimiters[] = " .,;:!-"; */
const char delimiters[] = " ";

/**
 * \fn int SCPI_Parse(char * s)
 * \brief Parse a query string.
 *
 * \param s string to parse.
 * \return 0 if string has been well parsed.
 */
int SCPI_Parse(char * s) {
  // puts(s);
  
  token = strtok (s, delimiters);
  while (token!=NULL) {
    if ( SCPI_Compare(token,"*IDN?") ) {
      printf("*IDN? = device identification\n");
    } else if ( SCPI_Compare(token,"MEASure?") ) {
      printf("measure=%d\n",measure);
    } else {
      fprintf(stderr,"Error ! this firmware doesn't understand this command\n");
    }
    token = strtok (NULL, delimiters);
  }
  
  return 0;
}
