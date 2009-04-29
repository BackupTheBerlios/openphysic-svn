%{
#include <stdio.h>
#include <string.h>

#define STR_SIZE 50
char g_str[STR_SIZE];
/*char* g_str;*/
size_t g_str_size; /* taille de g_str */
int g_str_read; /* nombre de caractre dŽjˆ envoyŽs ˆ lex, initializŽ au dŽpart ˆ 0 */

/*
#define STR_SIZE 50
char str[STR_SIZE];

int myinput(char *buf, int max){
  memcpy(buf, str, STR_SIZE);
}
*/
/*
  int n = min(max, gStringLimit-gStringPtr);
  if(n>0){
    memcpy(buf, gStringPtr, n);
    gStringPtr +=n;
  }
  return n;
}
*/


int value; /* temperature value */

enum _state {
   off,
   on
};
enum _state state;

void show_heat_state() {
  if (state==off) {
    printf("\tHeat is off\n");
  } else {
    printf("\tHeat is on\n");
  }
}

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
  fprintf(stderr,"yyerror: %s\n",str);
}
 
int yywrap() {
  return 1;
}


  
int main(void) {

  strcpy(g_str,"get temperature");
  /* printf(g_str); */

  value=0;
  state=off;

  yyparse();

  return 0;
} 
