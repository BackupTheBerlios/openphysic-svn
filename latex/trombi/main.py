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
FILE.write("\\documentclass[12pt,a4paper]{article}"+"\n")
FILE.write("\\usepackage[french]{babel}     % specification francaise"+"\n")
FILE.write("\\usepackage[latin1]{inputenc}   % entree clavier latin1"+"\n")
FILE.write("\\usepackage[T1]{fontenc}        % sortie"+"\n")
FILE.write("\\title{Trombinoscope}"+"\n")
FILE.write("\\author{\\null}"+"\n")
FILE.write("\\date{\\today}"+"\n")
FILE.write("\\begin{document}"+"\n")
FILE.write("\\maketitle"+"\n")
FILE.write("\\section*{Introduction}"+"\n")

# Partie centrale du fichier .tex

# Fin du fichier .tex
FILE.write("\\end{document}"+"\n")

# Fermeture du fichier .tex
FILE.close()

# Fermeture du fichier .csv
