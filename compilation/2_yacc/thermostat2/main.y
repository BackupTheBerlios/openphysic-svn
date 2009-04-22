

%token NUMBER TOKHEAT STATE TOKSET TOKTEMPERATURE TOKGET TOKEOL

%%

commands: /* empty */
        | commands command TOKEOL
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
        TOKHEAT STATE
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
        TOKGET TOKHEAT
        {
                show_heat_state();        
        }
        ;


target_set:
        TOKSET TOKTEMPERATURE NUMBER
        {
        		value=$3;
                printf("\tTemperature set to %d\n",value);
        }
        ;
        
target_get:
        TOKGET TOKTEMPERATURE
        {
                printf("\tTemperature is %d\n",value);
        }
        ;
%%


#include <stdio.h>
#include "lex.yy.c"

#include <string.h>

int value; /* temperature value */

enum _state {
   off,
   on
};
enum _state state;

 
void yyerror(const char *str) {
  fprintf(stderr,"error: %s\n",str);
}
 
int yywrap() {
  return 1;
}

void show_heat_state(void) {
  if (state==off) {
    printf("\tHeat is off\n");
  } else {
    printf("\tHeat is on\n");
  }
}
  
int main(void) {
  value=0;
  state=off;

  yyparse();
} 