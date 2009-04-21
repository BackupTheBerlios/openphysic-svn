
%%

[0-9]+                  {yylval=atoi(yytext); return NUMBER;}
heat                    return TOKHEAT;
on|off                  return STATE;
set                     return TOKSET;
temperature             return TOKTEMPERATURE;
get                     return TOKGET;
\n                      /* ignore end of line */;
[ \t]+                  /* ignore whitespace */;

%%

