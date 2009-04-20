 /* 
    Ce programme interpète quelques commandes SCPI
    */

%%
[*]?[A-Z]+[a-z]*[\?]?  {printf ("SCPI_Command");}
