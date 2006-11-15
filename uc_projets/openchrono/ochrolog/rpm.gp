#set terminal x11 # affichage en fen�tre

set border# bordure
set grid # grille
set key # l�gende (activer l�gende=set, pas de l�gende=unset)

# set xrange [-5:5] # intervalle de x
# set yrange [0:20] # intervalle de y
set yrange [0:15000]

# set xtics 1
# set ytics 5

set xlabel "temps (s)" # titre des x

set ylabel "RPM (tr/min)" # titre des y

# plot 'main.dat' using 1:2,x**2 # using 1:2 sert � choisir la colonne
plot 'main.dat' using 1:2
