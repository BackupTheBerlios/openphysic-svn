 /* 
    Ce programme interp�te quelques commandes SCPI
    */

%%
[*]?[A-Z]+[a-z]*[\?]?  {printf ("SCPI_Command");}
