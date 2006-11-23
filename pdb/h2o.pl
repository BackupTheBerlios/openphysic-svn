#!/usr/bin/perl
#
# ************************************************************
# * Script permettant de g�n�rer une mol�cule d'eau � partir *
# * de calculs lorsque l'on connait la taille des liaisons   *
# * et les angles                                            *
# ************************************************************

open(FILE,">h2o_calc.pdb") or die("Erreur d'�criture");

# d�finition de la fonction qui ajoute un atome dans le fichier .pdb
sub print_atom {
  printf(FILE "ATOM      %d  %s                  %1.3f   %1.3f   %1.3f"."\n",$_[0],$_[1],$_[2],$_[3],$_[4]);
}


$pi = 4*atan2(1, 1); # calcul de pi (petite astuce vieille comme le monde informatique)

# D�finition des constantes
# liaison O-H  0.0957nm = 0.957A (et pas 0,957)
# angle 104.52�
$l_OH = 0.957;
$alpha = 104.52;

# En t�te du fichier .pdb
print FILE "HEADER"."\n";
print FILE "COMPND    H2Os"."\n";
print FILE "HEAD"."\n";


# partie centrale du fichier .pdb (ex : mol�cule d'eau)            
&print_atom(1, O,
   0,
   0,
   0
);

&print_atom(2, H,
   $l_OH,
   0,
   0
);

&print_atom(3, C,
   $l_OH * cos($alpha*$pi/180),
   $l_OH * sin($alpha*$pi/180),
   0
);
                         
print FILE "CONECT    1    2    3"."\n";


# fin du fichier .pdb
print FILE "END"."\n";
print FILE "TAIL"."\n";

close(FILE);
