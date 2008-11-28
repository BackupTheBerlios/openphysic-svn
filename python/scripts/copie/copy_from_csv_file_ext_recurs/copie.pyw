#!/usr/bin/env python
# -*- coding: cp1252 -*-

# Script Python de copie de fichiers depuis les comptes utilisateurs
# Les comptes utilisateurs sont dans un fichier .csv
# Le script parcourt les sous-repertoire de chaque compte
# a la recherche de fichiers d'extension donnee
# Il cree un fichier zip contenant tous les fichiers
# Il cree egalement un fichier de log qui indique ce que le script a fait

# Sebastien CELLES
# 28/11/2008

import csv
import os
import shutil
import zipfile
#import tkMessageBox
import logging

dirOrigine = "\\\\Andromede\\Comptes\\GTE\\dut" # repertoire reseau contenant les fichiers
#zFile =  "C:\\Documents and Settings\\scelles\\Mes documents\\copie_autocad.zip"
zFile =  "copie_autocad.zip" #fichier zip final

#liste = "C:\\Documents and Settings\\scelles\\Mes documents\\liste.csv"
liste = "Z1PT11-500.csv" # fichier csv contenant les login
extensions = [".dwg",".dwt"] # extension des fichiers a recuperer


# Configuration du logger
log = logging.getLogger("MyApp")
logFile = "copie.log" # nom du fichier de log (stockage des actions du script)
hdlr = logging.FileHandler(logFile)
FORMAT='%(asctime)s\t%(levelname)s\t%(message)s'
formatter = logging.Formatter(FORMAT)
logging.basicConfig(format=FORMAT) # conf de base (log sur console)
hdlr.setFormatter(formatter)
log.addHandler(hdlr)
#hdlrConsole = logging.StreamHandler(sys.stderr)
#hdlrConsole.setFormatter(formatter)
#log.addHandler(hdlrConsole)
log.setLevel(logging.DEBUG) #set verbosity to show all messages of severity >= DEBUG CRITICAL

log.info("Ouverture du fichier .csv contenant les logins en lecture")
file = csv.reader(open(liste,"rb"), delimiter=';')

log.info("Creation du fichier "+zFile)
zip=zipfile.ZipFile(zFile, 'w', zipfile.ZIP_DEFLATED)

log.info("Debut de la copie")

for row in file:
  # recuperation du login de l'eleve
  login = row[1]
  log.info("******** Eleve = "+ login + " - "+ row[2] +" ********")

  root=''
  dirs=[]
  files=[]
  for root, dirs, files in os.walk(os.path.join(dirOrigine, login), topdown=True):
    for file in files:
      (shortname, extension) = os.path.splitext(file)
      if (extension in extensions):
        log.info("  "+os.path.join(root, file))
        zip.write(os.path.join(root, file))

log.info("Fin de la copie")

log.info("Ajout du fichier de log")
zip.write(logFile)

log.info("Fermeture de l'archive")
zip.close()
