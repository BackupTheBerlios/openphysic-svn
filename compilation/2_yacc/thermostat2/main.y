

%token NUMBER TOKHEAT STATE TOKSET TOKTEMPERATURE TOKGET

%%

commands: /* empty */
        | commands command
        ;

command:
        heat_switch
        |
        target_set
        |
        target_get
        ;

heat_switch:
        TOKHEAT STATE
        {
                printf("\tHeat turned on or off\n");
        }
        ;

target_set:
        TOKSET TOKTEMPERATURE NUMBER
        {
        		value=yylval;
                printf("\tTemperature set to %d\n",value); /* ToFiX */
        }
        ;
        
target_get:
        TOKGET TOKTEMPERATURE
        {
                printf("\tTemperature is %d\n",value); /* ToFiX */
        }
        ;
%%


#include <stdio.h>
#include "lex.yy.c"

#include <string.h>

int value;
 
void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
        return 1;
} 
  
main()
{
        yyparse();
} 