#! /usr/bin/env python
# -*- coding: Latin-1 -*-

# Histogramme des fr�quences de chaque mot dans un texte

nFich = raw_input('Nom du fichier � traiter : ')
fi = open(nFich, 'r')
texte = fi.read()
fi.close()

# afin de pouvoir ais�ment s�parer les mots du texte, on commence 
# par convertir tous les caract�res non-alphab�tiques en espaces  :

alpha = "abcdefghijklmnopqrstuvwxyz���������������"

lettres = ''            # nouvelle cha�ne � construire
for c in texte:
    c = c.lower()       # conversion de chaque caract�re en minuscule
    if c in alpha:
        lettres = lettres + c
    else:
        lettres = lettres + ' '

# conversion de la cha�ne r�sultante en une liste de mots :
mots = lettres.split()

# construction de l'histogramme :
dico ={}
for m in mots:
    dico[m] = dico.get(m, 0) +1

liste = dico.items()

# tri de la liste r�sultante :
liste.sort()

# affichage en clair :
for item in liste:
    print item[0], ":", item[1]