INTEGER                 [0-9]+

%%

{INTEGER}                  {yylval=atoi(yytext); return NUMBER;}
heat                    return TOKHEAT;
on|off                  {yylval=!strcmp(yytext,"on"); return STATE;}
set                     return TOKSET;
temperature             return TOKTEMPERATURE;
get                     return TOKGET;
\n                      return TOKEOL; /* end of line */;
[ \t]+                  /* ignore whitespace */;

%%

