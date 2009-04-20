 /* 
This program emulate a device's firmware which is
able to understand some SCPI commands
Standard Commands for Programmable Instruments (SCPI)
    */

%{
#define IDENT "MyDevice"
double value;
%}

INTEGER   [0-9]+

%%

"*IDN\?"  {printf ("IDENTIFICATION=%s", IDENT);}
"MEAS\?"|"MEASure?"  {printf ("MEASURE=%f", value);}
"SET"  {printf ("SET");}

[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?  {printf ("FLOATING_POINT_NUMBER");}

#[-+]?[0-9]*\.?[0-9]*  {printf ("FIXED_POINT_NUMBER");}
#[0-9]+  {printf ("INTEGER");}
#INTEGER  {printf ("INTEGER");}


#[*]?[A-Z]+[a-z]*[\?]?  {printf ("SCPI_Command");}

%%

int main(void) {
  value=5.1;
  yylex();
  return 0;
}
