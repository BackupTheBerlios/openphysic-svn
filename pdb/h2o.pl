#!/usr/bin/perl
#
# Fichier permettant de générer
# plusieurs molécules d'eau
# =============================

# TO FIX :
# file output
# generate many molecules
# 0.926 ? -0.240 ?

open(FILE,">h2o_plein.pdb");

# liaison O-H  0.0957nm = 0.957A (et pas 0,957)
# angle 104.52°

$l_OH = 0.957;
$alpha = 104.52;

# En tête du fichier pdb
print FILE "HEADER"."\n";
print FILE "COMPND    H2Os"."\n";
print FILE "HEAD"."\n";


# partie centrale (molécules d'eau)

print FILE "ATOM      1  O                   0.000   0.000   0.000"."\n";                          
print FILE "ATOM      2  H                   $l_OH   0.000   0.000"."\n";                          
print FILE "ATOM      3  H                  -0.240   0.926   0.000"."\n";                         
print FILE "CONECT    1    2    3"."\n";


# fin du fichier pdb
print FILE "END"."\n";
print FILE "TAIL"."\n";

close(FILE);
