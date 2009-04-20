 /* 
    Ce programme interpète quelques commandes SCPI
    */

    int nbParOuv=0; /* Variable globale du nb de par ouvrantes */
%%
"("     {printf ("Votre parenthesage est incorrect\n");}

