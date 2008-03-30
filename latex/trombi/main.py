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
FILE.write(r""" 
\documentclass[12pt,a4paper]{article}
\usepackage[french]{babel}     % specification francaise
\usepackage[latin1]{inputenc}   % entree clavier latin1
\usepackage[T1]{fontenc}        % sortie

\usepackage{lscape}
\title{Trombinoscope}
\author{\null}
\date{\today}
%\date{\null}
\begin{document}
\begin{landscape}
\maketitle
\section*{Introduction}
""")

# Partie centrale du fichier .tex
#for row in filecvs:
for NOM, PRENOM, NOMPRENOM, PHOTO in filecvs:
	#eleve = row[0]
	if PHOTO=='':
		PHOTO="no_photo.jpg"
	else:
		try:
			value = int(PHOTO)
		except ValueError:
			value = None

		if value is Not None:
			PHOTO="%(#)06d" % {"#": value} + ".jpg"
		else:
			PHOTO="err.jpg"
		#if value is not None:
		#	#Mise en forme du numero de la photo
		#	PHOTO="%(#)06d" % {"#": value} + ".jpg"
		#else:
		#	raise ValueError, "%s is not a number" % PHOTO


	PHOTO="img/"+PHOTO

	params={ 'NOM': NOM, 'PRENOM':PRENOM, 'NOMPRENOM':NOMPRENOM, 'PHOTO':PHOTO } 
	FILE.write(r""" 
%   %(NOM)s %(PRENOM)s %(NOMPRENOM)s %(PHOTO)s
"""%params)

# Fin du fichier .tex
FILE.write(r""" 
\end{landscape}
\end{document}
""")

# Fermeture du fichier .tex
FILE.close()

# Fermeture du fichier .csv
