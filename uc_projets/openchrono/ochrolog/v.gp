#set terminal x11 # affichage en fen�tre

set border# bordure
set grid # grille
set key # l�gende (activer l�gende=set, pas de l�gende=unset)

# set xrange [-5:5] # intervalle de x
# set yrange [0:20] # intervalle de y
set yrange [0:150]

# set xtics 1
# set ytics 5

set xlabel "temps (s)" # titre des x

set ylabel "V (km/h)" # titre des y
plot 'main.dat' using 1:3
