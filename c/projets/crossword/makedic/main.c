#include <stdio.h>
#include <stdbool.h>

#define putchar(c) putc((c), stdout)

#define str_file_in "fr_FR.dic" 
#define str_file_out "cw_fr_FR.txt"

int main(void)
{ 
  FILE * file_in;
  char c;

  bool good_part; // bonne partie du mot
  good_part = true;

  file_in = fopen(str_file_in, "r"); /* Ouverture du fichier fcntl.h */
  file_out = fopen(str_file_out, "w+");

  while( (c = getc(file_in)) != EOF ) {
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
    } else if ( c=='/' ) {
      good_part = false;
      c = '\0';
    } else if ( c=='\n' ) {
      // Ne rien faire
      good_part = true;
    } else {
      c = '#';
    }

    if (good_part==true) {
      //putchar(c);
      //putc((c), stdout);
      putc((c), file_out);
    }

  }
  
  fclose(file_in); /* Fermeture du fichier */

  return 0;
}
