Ce script est r�alis� en Python avec PIL (Python Imaging Library).
Il transforme une image (logo.gif) en un grand nombre d'images temp_xxxx.gif
qui montrent une vue r�duite en largeur de logo.gif qui d�file vers la droite.
Ensuite la commande "convert" d'ImageMagick est utilis�e pour transformer la
succession d'images en une animation nomm�e animated.gif.
On peut jouer sur 2 param�tres dans le script Python :
 * Nb : le nombre de "tranches verticales" dans l'image.
 * Nbsize : le nombre de tranches n�cessaire pour fabriquer une image.
On peut aussi jouer sur le param�tre -delay de la commande convert pour d�finir
le temps entre deux images pour fabriquer l'animation.
Comment voir l'animation ?
Ouvrir le fichier index.htm avec un navigateur (il contient une balise img vers l'animation)
Comment recr�er l'animation ?
sous Linux/Unix taper
$ make
pr�requis :
installer Python + PIL (Python Imaging Library)
installer ImageMagick
pour effacer les images temporaires taper :
$ make clean