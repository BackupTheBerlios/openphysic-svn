
%%

[0-9]+                  {yylval=atoi(yytext); return NUMBER;}
heat                    return TOKHEAT;
on|off                  {yylval=!strcmp(yytext,"on"); return STATE;}
set                     return TOKSET;
temperature             return TOKTEMPERATURE;
get                     return TOKGET;
\n                      return TOKEOL; /* ignore end of line */;
[ \t]+                  /* ignore whitespace */;

%%

