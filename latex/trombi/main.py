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
%\title{Trombinoscope}
\author{\null}
%\date{\today}
\date{\null}
\begin{document}
\begin{landscape}
%\maketitle
%\pagestyle{empty}
\begin{center}
Trombinoscope
\end{center}
%\section*{Introduction}
""")

# Partie centrale du fichier .tex
#for row in filecvs:
i=0
for NOM, PRENOM, NOMPRENOM, PHOTO in filecvs:
	#eleve = row[0]
	if i<>0:
		if PHOTO=='':
			PHOTO="img/"+"nophoto.png"
		else:
			try:
				value = int(PHOTO)
			except ValueError:
				value = None

			if value is not None:
				PHOTO="img/"+"%(#)06d" % {"#": value} + ".jpg"
			#else:
			#	PHOTO="err.jpg"

		params={ 'NOM':NOM, 'PRENOM':PRENOM, 'NOMPRENOM':NOMPRENOM, 'PHOTO':PHOTO, "#":i} 
		FILE.write(r""" 
%   %(NOM)s %(PRENOM)s %(NOMPRENOM)s %(PHOTO)s
   %(#)03d %(NOM)s %(PRENOM)s %(NOMPRENOM)s \includegraphics{%(PHOTO)s}
"""%params)
	i=i+1

# Fin du fichier .tex
FILE.write(r""" 
\end{landscape}
\end{document}
""")

# Fermeture du fichier .tex
FILE.close()

# Fermeture du fichier .csv
