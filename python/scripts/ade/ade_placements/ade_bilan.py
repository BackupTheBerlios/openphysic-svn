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
       l'ordre des colonnes de l'onglet "Placement" doit être
       le même que l'ordre dans le fichier ade_entete.txt
       Il est nécessaire d'afficher les informations suivantes dans le client ADE
        - Type
        - Durée
        - Enseignants au choix (noms)
        - Code
        - Activité

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

class Bilan(dict):
    def __init__(self):
        self['CM'] = 0 #timedelta() # durée en minutes
        self['TD'] = 0 #timedelta()
        self['TP'] = 0 #timedelta()
        self['autres'] = 0 #timedelta()

    def __repr__(self):
        return repr(self.__dict__)

#class BilanEnseignants():
#    def __init__(self):
#        pass

#    def append(self, placement):
#        pass

#    def __repr__(self):
#        return repr(self.__dict__)

#class BilanMatieres():
#    def __init__(self):
#        pass

#    def __repr__(self):
#        return repr(self.__dict__)

# Lecture des entêtes de colonnes
fileHead = open('ade_entete.txt', 'r', encoding='latin-1')
strHead = fileHead.read()
lstHead = strHead.split("\n")
fileHead.close()
#print(lstHead)

# Lecture du fichier ade_onglet_placement.txt
placements = csv.reader(open('ade_onglet_placement_mini.txt', encoding='latin-1'), delimiter='\t')
lstPlacements = []
for placement in placements:
    #print(placement)
    p = Placement()
    for i in range(0, len(placement)):
        strP = placement[i]
        #try:
        if lstHead[i] == 'Durée (h)':
            val = strP.split('h')
            #val = timedelta(hours=int(val[0]), minutes=int(val[1])) # conversion de la chaine en heure Python
            #val = float(val[0]) + float(val[1])/60 # numérique (heures)
            val = int(val[0])*60 + int(val[1]) # numérique (minutes)
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

# Création des bilan

#print(lstPlacements[0]) # voir une ligne de l'onglet placement pour test

bilan = dict()
bilan['total'] = dict()
bilan['enseignants'] = dict()
bilan['matieres'] = dict()

for placement in lstPlacements:
    enseignant = placement.__dict__['Enseignants au choix (noms)'] # ToFix : double encadrement
    typeAct = placement.__dict__['Type']
    duree = placement.__dict__['Durée (h)']
    code = placement.__dict__['Activité']

    # Total CM TD TP autres de l'ensemble des enseignants    
    if typeAct in bilan['total']:
        bilan['total'][typeAct] = bilan['total'][typeAct] + duree
    else:
        bilan['total'][typeAct] = duree
    
    # Total CM TD TP autres pour chaque enseignant
    if enseignant not in bilan['enseignants']:
        bilan['enseignants'][enseignant] = Bilan() #{'CM': timedelta(), 'TD': timedelta(), 'TP': timedelta(), 'autres': timedelta()}
    
    if typeAct in bilan['enseignants'][enseignant]:
        bilan['enseignants'][enseignant][typeAct] = bilan['enseignants'][enseignant][typeAct] + duree
    else:
        bilan['enseignants'][enseignant][typeAct] = duree

    # Total CM TD TP autres pour chaque matière pour un enseignant donné

    # ###########################################################

    # Total CM TD TP autres pour chaque matiere (regroupement par code Apogée)
    if code not in bilan['matieres']:
        bilan['matieres'][code] = Bilan()
    
    if typeAct in bilan['matieres'][code]:
        bilan['matieres'][code][typeAct] = bilan['matieres'][code][typeAct] + duree
    else:
        bilan['matieres'][code][typeAct] = duree
        
    #print(bilanMatiere)

    # Total CM TP TP autres pour chaque enseignant dans une matière donnée
    #if enseignant not in bilanMatiere:

CM = bilan['total']['CM']/60
TD = bilan['total']['TD']/60
TP = bilan['total']['TP']/60
autres = bilan['total']['autres']/60
print("""Bilan {0}
CM     : {1}
TD     : {2}
TP     : {3}
autres : {4}

H eq TD(*) : {5}""".format('total des enseignants', CM, TD, TP, autres, CM*1.5 + TD + TP))

print('='*30)
print()


# Affichage bilan enseignant
for enseignant in bilan['enseignants']:
    #print(enseignant)
    CM = bilan['enseignants'][enseignant]['CM']/60
    TD = bilan['enseignants'][enseignant]['TD']/60
    TP = bilan['enseignants'][enseignant]['TP']/60
    autres = bilan['enseignants'][enseignant]['autres']/60
    print("""    Bilan {0}
    CM     : {1}
    TD     : {2}
    TP     : {3}
    autres : {4}

    H eq TD(*) : {5}""".format(enseignant, CM, TD, TP, autres, CM*1.5 + TD + TP))
    print()
    print('='*15)
    print()


print('='*30)

# Affichage bilan matiere
for matiere in bilan['matieres']:
    #print(enseignant)
    CM = bilan['matieres'][matiere]['CM']/60
    TD = bilan['matieres'][matiere]['TD']/60
    TP = bilan['matieres'][matiere]['TP']/60
    autres = bilan['matieres'][matiere]['autres']/60
    print("""Bilan {0}
CM     : {1}
TD     : {2}
TP     : {3}
autres : {4}

H eq TD(*) : {5}""".format(matiere, CM, TD, TP, autres, CM*1.5 + TD + TP))
    print()
    print('='*15)
    print()

print('='*30)

print("""(*) Les heures équivalents TD sont calculées à titre indicatif
sans prendre en compte le prorata (dépend du statut) avec les coefficients suivants :
CM=1.5 ; TD=1 ; TP=1""")