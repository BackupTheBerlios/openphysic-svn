#!/usr/bin/env python

# *************************************************************
# * Script en Python permettant de generer un trombinoscope   *
# * Technique : ce script crée un fichier LaTeX .tex          *
# *  le fichier .tex est ensuite compilé via pdflatex         *
# *  Les photos sont stockées dans un répertoire ./img        *
# *  Les noms/prénoms des personnes sont dans un fichier .csv *
# *************************************************************


FILE = open('main.tex', 'w')

# En tete du fichier .tex
FILE.write("Test Debut"+"\n")

# Partie centrale du fichier .tex

# Fin du fichier .tex
FILE.write("Test fin"+"\n")

# Fermeture du fichier
FILE.close()
