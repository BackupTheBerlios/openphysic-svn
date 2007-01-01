#include <stdio.h>
#define putchar(c) putc((c), stdout)

#define str_file_in "fr_FR.dic" 
#define str_file_out "cw_fr_FR.txt"

int main(void)
{ 
  FILE * file_in;
  char c;
  file_in = fopen(str_file_in, "r"); /* Ouverture du fichier fcntl.h */
  while( (c = getc(file_in)) != EOF ) {
    
    putchar(c);
  }
  
  fclose(file_in); /* Fermeture du fichier */

  return 0;
}
