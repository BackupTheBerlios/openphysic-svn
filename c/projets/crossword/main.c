// TO DO

#include <stdio.h>

#define str_file_in "dic_fr.txt"

char minucule_majuscule(char c) {
  if ( c >='a' && c<='z' ) {
    c -= 'a'-'A'; // mettre en majuscule
  } else if ( c >='A' && c<='Z' ) {
    // ne rien faire (normal)
  } else if ( c=='-' || c=='\'' || c=='.' ) {
    // ne rien faire (enlever le mot ?)
  } else if ( c=='�' || c=='�' || c=='�' || c=='�'
              || c=='�') {
    c = 'A';
  } else if ( c=='�' || c=='�' || c=='�' || c=='�'
              || c=='�' || c=='�' || c=='�' ) {
    c = 'E';
  } else if ( c=='�' || c=='�' || c=='�' ) {
    c = 'I';
  } else if ( c=='�' || c=='�' || c=='�' ) {
    c = 'O';
  } else if ( c=='�' || c=='�' || c=='�' ) {
    c = 'U';
  } else if ( c=='�' ) {
    c = 'Y';
  } else if ( c=='�' ) {
    c = 'C';
  } else if ( c >='0' && c<='9' ) {
    c = ' ';
  }
  return c;
}

int main(void)
{ 
  FILE * file_in;
  file_in = fopen(str_file_in, "r");

  char c;

  while( (c = getc(file_in)) != EOF ) {
    if ( c=='\n' ) {
      
    } else {
      
    }
  }
  
  fclose(file_in); /* Fermeture du fichier */
}
