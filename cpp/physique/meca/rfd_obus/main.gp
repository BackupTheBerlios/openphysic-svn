#set terminal x11 # affichage en fen�tre

set border# bordure
set grid # grille
set key # l�gende (activer l�gende=set, pas de l�gende=unset)

#set xrange [-5:5] # intervalle de x
#set yrange [0:20] # intervalle de y

#set xtics 1
#set ytics 5

#set xlabel "axe des abscisses : x" # titre des x
#set ylabel "axe des ordonn�es : z" # titre des z

plot 'main.dat' using 2:4 # using 1:2 sert � choisir la colonne
#splot 'main.dat' using 2:3:4