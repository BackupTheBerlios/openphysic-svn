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

# 8x3 pour 1ere page
# 8x4 pour autres pages
nb_lignes=4 # 3 pour la premiere page
nb_colonnes=8
nb_lignes_page1=3

def page(i):
	if i<=nb_lignes_page1*nb_colonnes:
		return 1
	else:
		i=i-nb_lignes_page1*nb_colonnes
		return (i-1)/(nb_lignes*nb_colonnes)+2

def indice_dans_page(i):
	if i<=nb_lignes_page1*nb_colonnes:
		return i
	else:
		return i-nb_lignes_page1*nb_colonnes-(page(i)-2)*nb_lignes*nb_colonnes
	

def ligne(ip):
	return (ip-1)/nb_colonnes+1

def colonne(ip):
	if ip<=nb_colonnes:
		return ip
	else:
		return ip-(ligne(ip)-1)*nb_colonnes
		

def main():
	filecvs = csv.reader(open(liste,"rb"))

	FILE = open('main.tex', 'w')

	# En tete du fichier .tex
	FILE.write(r""" 
\documentclass[landscape,a4paper]{article}
%\documentclass[12pt,a4paper]{article}
\usepackage[french]{babel}     % specification francaise
\usepackage[latin1]{inputenc}   % entree clavier latin1
\usepackage[T1]{fontenc}        % sortie

\usepackage{lscape}
\usepackage{graphicx}
%\usepackage{tabularx}

\usepackage{geometry}
\geometry{ hmargin=1cm, vmargin=1cm }

%\title{Trombinoscope}
\author{\null}
%\date{\today}
\date{\null}
\begin{document}
%\begin{landscape}
%\maketitle
%\pagestyle{empty}
\begin{center}
Trombinoscope
\end{center}
%\section*{Introduction}
%\begin{tabular}{|c|c|c|c|c|c|c|c|}
""")

	# Partie centrale du fichier .tex
	#for row in filecvs:
	i=0
	for NOM, PRENOM, NOMPRENOM, PHOTO in filecvs:
		if i<>0:
			if PHOTO=='':
				PHOTO="img/"+"nophoto.png"
			else:
				try:
					numphoto = int(PHOTO)
				except ValueError:
					numphoto = None

				if numphoto is not None:
					PHOTO="img/"+"%(#)06d" % {"#": numphoto} + ".jpg"
				#else:
				#	PHOTO="err.jpg"

			params={'NOM':NOM, 'PRENOM':PRENOM, 'NOMPRENOM':NOMPRENOM, 'PHOTO':PHOTO, "#":i} 
			FILE.write(r""" 
   %(#)03d %(NOM)s %(PRENOM)s %(NOMPRENOM)s \includegraphics[width=2cm]{%(PHOTO)s}
"""%params)
		i=i+1

	# Fin du fichier .tex
	FILE.write(r"""
%\end{tabular} 
%\end{landscape}
\end{document}
""")

	# Fermeture du fichier .tex
	FILE.close()

	# Fermeture du fichier .csv
main()
#print page(8*3+8*4*3+1)
#print indice_dans_page(8*3+8*4*2+1)
#print colonne(19)
