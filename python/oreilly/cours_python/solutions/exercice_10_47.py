#! /usr/bin/env python
# -*- coding: Latin-1 -*-

# Histogramme des fr�quences de chaque lettre dans un texte

nFich = raw_input('Nom du fichier : ')
fi = open(nFich, 'r')
texte = fi.read()		# conversion du fichier en une cha�ne de caract�res
fi.close()

print texte
dico ={}
for c in texte:
    c = c.upper()		# conversion de toutes les lettres en majuscules
    dico[c] = dico.get(c, 0) +1

liste = dico.items()
liste.sort()
print liste