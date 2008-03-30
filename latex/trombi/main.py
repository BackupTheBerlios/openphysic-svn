#!/usr/bin/env python
# -*- coding: utf-8 -*-

# **************************************************************
# * Script en Python permettant de générer un trombinoscope    *
# * Technique : ce script crée un fichier LaTeX .tex           *
# *  le fichier .tex est ensuite compilé via pdflatex          *
# *  Les photos doivent être stockées dans un répertoire ./img *
# *  Les noms/prénoms des personnes sont dans un fichier .csv  *
# **************************************************************

import csv

liste="main.csv"

filecvs = csv.reader(open(liste,"rb"))

FILE = open('main.tex', 'w')

# En tete du fichier .tex
FILE.write("Test Debut"+"\n")

# Partie centrale du fichier .tex

# Fin du fichier .tex
FILE.write("Test fin"+"\n")

# Fermeture du fichier .tex
FILE.close()

# Fermeture du fichier .csv
