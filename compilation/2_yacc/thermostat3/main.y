%{
#include <stdio.h>
#include <string.h>

/* char * str; */


int value; /* temperature value */

enum _state {
   off,
   on
};
enum _state state;
%}

%token TOK_NUMBER TOK_HEAT TOK_STATE TOK_SET TOK_TEMPERATURE TOK_GET TOK_EOL

%%

commands: /* empty */
        | commands command TOK_EOL
        ;

command:
        heat_switch
        |
        heat_get
        |
        target_set
        |
        target_get
        ;

heat_switch:
        TOK_HEAT TOK_STATE
        {
        	if ($2==0) {
     		  state=off;
                } else if ($2==1) {
                  state=on;
                }
                show_heat_state();
        }
        ;

heat_get:
        TOK_GET TOK_HEAT
        {
                show_heat_state();        
        }
        ;


target_set:
        TOK_SET TOK_TEMPERATURE TOK_NUMBER
        {
        	value=$3;
                printf("\tTemperature set to %d\n",value);
        }
        ;
        
target_get:
        TOK_GET TOK_TEMPERATURE
        {
                printf("\tTemperature is %d\n",value);
        }
        ;
%%

 
void yyerror(const char *str) {
  fprintf(stderr,"error: %s\n",str);
}
 
int yywrap() {
  return 1;
}

void show_heat_state() {
  if (state==off) {
    printf("\tHeat is off\n");
  } else {
    printf("\tHeat is on\n");
  }
}
  
int main(void) {
/*
  strcpy(str,"*MEASSSure???ureME");
  printf(str);
*/
  value=0;
  state=off;

  yyparse();

  return 0;
} 
