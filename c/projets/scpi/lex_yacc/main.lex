 /* 
    Ce programme interpète quelques commandes SCPI
    */

ENTIER   [0-9]+

%%

#"*IDN?"  {printf ("IDENTIFICATION=");}
#"MEAS?"|"MEASure?"  {printf ("MEASURE=");}
#"SET"  {printf ("SET");}

[-+]?[0-9]*\.?[0-9]*  {printf ("REEL");}
[0-9]+  {printf ("ENTIER");}
#ENTIER  {printf ("ENTIER");}


[*]?[A-Z]+[a-z]*[\?]?  {printf ("SCPI_Command");}

%%

int main(void) {
  yylex();
  return 0;
}
