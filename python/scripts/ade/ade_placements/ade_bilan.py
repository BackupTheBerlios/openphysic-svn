#!/usr/bin/env python
# -*- coding: utf8 -*-

"""
    Bilan pour ADE - v 0.1

       But : ce script permet de générer des bilans à partir
       des données présentes dans l'onglet "Placement" d'ADE
        * Bilan matières
        * Bilan enseignants

       Remarque : modifier le fichier ade_entete.txt afin d'avoir
       une disposition des données convenables

    Copyright (C) 2011  "Sébastien CELLES" <sebastien.celles@univ-poitiers.fr>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
"""

import csv
from datetime import date, datetime, timedelta

class Placement():
    def __init__(self):
        pass

    def __repr__(self):
        return repr(self.__dict__)

class Bilan():
    def __init__(self):
        self.CM = 0
        self.TD = 0        
        self.TP = 0
        self.autres = 0

    def __repr__(self):
        return repr(self.__dict__)
    

class BilanEnseignants():
    def __init__(self):
        pass

    def append(self, placement):
        pass

    def __repr__(self):
        return repr(self.__dict__)

#class BilanMatieres():
#    def __init__(self):
#        pass

#    def __repr__(self):
#        return repr(self.__dict__)

# Lecture des entêtes de colonnes
fileHead = open('ade_entete.txt', 'r')
strHead = fileHead.read()
lstHead = strHead.split("\n")
fileHead.close()
#print(lstHead)

# Lecture du fichier ade_onglet_placement.txt
placements = csv.reader(open('ade_onglet_placement_mini.txt'), delimiter='\t')
lstPlacements = []
for placement in placements:
    #print(placement)
    p = Placement()
    for i in range(0, len(placement)):
        strP = placement[i]
        #try:
        if lstHead[i] == 'Durée (h)':
            val = strP.split('h')
            val = timedelta(hours=int(val[0]), minutes=int(val[1])) # conversion de la chaine en heure Python
        elif lstHead[i] == 'Ressources verouillées' or lstHead[i] == 'Date verrouillée':
            val = bool(strP) # conversion de la chaine en booléen
        elif lstHead[i] == 'Type': # tout ce qui n'est pas de type CM TD TP est de type autre
            if strP!='CM' and strP!='TD' and strP!='TP':
                val = 'autres'
            else:
                val = strP
        else:
            val = strP
        #except:
        #    val = strP
        p.__dict__[lstHead[i]] = val
    lstPlacements.append(p)
#print(lstPlacements)

# Création du bilan enseignants

#print(lstPlacements[0]) # voir une ligne de l'onglet placement pour test

bilanTotalEns = {'CM': timedelta(), 'TD': timedelta(), 'TP': timedelta(), 'autres': timedelta()}
bilanEns = dict()

for placement in lstPlacements:
    enseignant = placement.__dict__['Enseignants au choix (noms)']
    typeAct = placement.__dict__['Type']
    duree = placement.__dict__['Durée (h)']

    # Total CM TD TP autres de l'ensemble des enseignants    
    if typeAct in bilanTotalEns:
        bilanTotalEns[typeAct] = bilanTotalEns[typeAct] + duree
    else:
        bilanTotalEns[typeAct] = duree
    
    # Total CM TD TP autres pour chaque enseignant
    if enseignant not in bilanEns:
        bilanEns[enseignant] = {'CM': timedelta(), 'TD': timedelta(), 'TP': timedelta(), 'autres': timedelta()}
    
    if typeAct in bilanEns[enseignant]:
        bilanEns[enseignant][typeAct] = bilanEns[enseignant][typeAct] + duree
    else:
        bilanEns[enseignant][typeAct] = duree

    # Total CM TD TP autre pour chaque matière pour un enseignant donné

#print(bilanTotalEns)

#print('='*30)

CM = bilanTotalEns['CM']
TD = bilanTotalEns['TD']
TP = bilanTotalEns['TP']
autres = bilanTotalEns['autres']
print("""Bilan {0}
CM     : {1}
TD     : {2}
TP     : {3}
autres : {4}""".format('total des enseignants', CM, TD, TP, autres))

print('='*30)
print()

#print(bilanEns)

for key in bilanEns:
    #print(key)
    CM = bilanEns[key]['CM']
    TD = bilanEns[key]['TD']
    TP = bilanEns[key]['TP']
    autres = bilanEns[key]['autres']
    print("""Bilan {0}
CM     : {1}
TD     : {2}
TP     : {3}
autres : {4}""".format(key, CM, TD, TP, autres))
    print('='*15)


#print('='*30)

# Création du bilan matières
