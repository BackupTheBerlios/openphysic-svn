#set terminal x11 # affichage en fen�tre

set border# bordure
set grid # grille
set key # l�gende (activer l�gende=set, pas de l�gende=unset)

# set xrange [-5:5] # intervalle de x
# set yrange [0:20] # intervalle de y
set yrange [-25:25]

# set xtics 1
# set ytics 5

set xlabel "temps (s)" # titre des x

set ylabel "Ay (m/s^2)" # titre des y
plot 'main.dat' using 1:5

