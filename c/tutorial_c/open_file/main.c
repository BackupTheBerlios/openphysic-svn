#include <stdio.h>

int main(void)
{ 
  FILE * fic;
  char c;
  
  fic = fopen("main.txt", "r"); // Ouverture du fichier
  //fscanf
  // to do
  fclose(fic); // Fermeture du fichier

  return 0;
}
