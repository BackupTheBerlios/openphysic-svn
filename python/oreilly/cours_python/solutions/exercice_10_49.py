# -*- coding: Latin-1 -*-
# encodage d'un texte dans un dictionnaire

nFich = raw_input('Nom du fichier � traiter : ')
fi = open(nFich, 'r')
texte = fi.read()
fi.close()

# On consid�re que les mots sont des suites de caract�res faisant partie
# de la cha�ne ci-dessous. Tous les autres sont des s�parateurs :

alpha = "abcdefghijklmnopqrstuvwxyz���������������"

# construction du dictionnaire :
dico ={}
# parcours de tous les caract�res du texte :
i =0                    # indice du caract�re en cours de lecture
mot =""                 # variable de travail : mot en cours de lecture
for c in texte:
    c = c.lower()       # conversion de chaque caract�re en minuscule
    
    if c in alpha:      # car. alphab�tique => on est � l'int�rieur d'un mot
        mot = mot + c   
    else:               # car. non-alphab. => fin de mot
        if mot !="":    # afin d'ignorer les car. non-alphab. successifs
            # pour chaque mot, on construit une liste d'indices :
            if dico.has_key(mot):       # mot d�j� r�pertori� :
                dico[mot].append(i)     # ajout d'un indice � la liste
            else:                       # mot rencontr� pour la 1e fois :
                dico[mot] =[i]          # cr�ation de la liste d'indices
            mot =""     # pr�parer la lecture du mot suivant
    i += 1              # indice du caract�re suivant
      
# Affichage du dictionnaire, en clair :
for clef, valeur in dico.items():
    print clef, ":", valeur