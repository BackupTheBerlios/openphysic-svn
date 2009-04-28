%{
#include <string.h>
#include "main.tab.h"

#define STR_SIZE 50 /* buffer size */
char str[STR_SIZE];

/*
int myinput(char *buf, int max);
#undef YY_INPUT
#define YY_INPUT(b, r, ms) (r=myinput(b, ms))

int myinput(char *buf, int max){
  int n = min(max, gStringLimit-gStringPtr);
  if(n>0){
    memcpy(buf, gStringPtr, n);
    gStringPtr +=n;
  }
  return n;
}
*/

%}

%option case-insensitive

INTEGER                 [0-9]+
FLOATING                [-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?

%%

{INTEGER}               {yylval=atoi(yytext); return TOK_NUMBER;}
heat                    return TOK_HEAT;
on|off                  {yylval=!strcmp(yytext,"on"); return TOK_STATE;}
set                     return TOK_SET;
temperature             return TOK_TEMPERATURE;
get                     return TOK_GET;
\n                      return TOK_EOL; /* end of line */;
[ \t]+                  /* ignore whitespace */;

%%

