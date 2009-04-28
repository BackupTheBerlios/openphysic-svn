%{
#include <string.h>
#include "main.tab.h"

/*
extern int myinput(char *buf, int max);
#undef YY_INPUT
#define YY_INPUT(b, r, ms) (r=myinput(b, ms))
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

