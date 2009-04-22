INTEGER                 [0-9]+
FLOATING                [-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?

%%

{INTEGER}               printf("NUMBER ");
heat                    printf("TOKHEAT ");
on|off                  printf("STATE ");
set                     printf("TOKSET ");
temperature             printf("TOKTEMPERATURE ");
get                     printf("TOKGET ");
\n                      printf("TOKEOL "); /* end of line */;
[ \t]+                  /* ignore whitespace */;

%%

