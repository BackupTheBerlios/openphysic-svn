set encoding iso_8859_1 # encodage des caract�res
set terminal postscript #portrait color
set output 'main.ps'

set autoscale x # set xrange [0:1]
set autoscale y # set yrange [0:1]

unset key # legende
set grid  # grille

set title "Caract�ristique d'un �lectrolyseur"
set ylabel "U (V)"
set xlabel "I (mA)"

U(x) = a*x*0.001+b

fit U(x) 'main_select.dat' using 1:2 via a,b
#fit U(x) 'main.dat' using 1:2 via a,b


plot 'main.dat' using 1:2,U(x)

!gv main.ps # affichage du fichier .ps