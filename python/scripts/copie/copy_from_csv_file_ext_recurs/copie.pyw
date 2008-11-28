#!/usr/bin/env python

# Script Python de copie de fichiers depuis les comptes utilisateurs
# Sebastien CELLES
# 28/11/2008

import csv
import os
import shutil
import tkMessageBox

dirOrigine = "\\\\Andromede\\Comptes\\GTE\\dut"
zFile =  "C:\\Documents and Settings\\scelles\\Mes documents\\copie_autocad.zip"

#liste = "C:\\Documents and Settings\\scelles\\Mes documents\\liste.csv"
liste = "Z1PT11-500.csv"
extensions = [".dwg",".dwt"]

file = csv.reader(open(liste,"rb"), delimiter=';')



print "Debut de la copie"

for row in file:
  # recuperation du login de l'eleve
  login = row[1]
  print "*** Eleve = "+ login + " ***"

print "Fin de la copie"
