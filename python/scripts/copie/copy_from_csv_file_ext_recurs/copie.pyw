#!/usr/bin/env python

# Script Python de copie de fichiers depuis les comptes utilisateurs
# Sebastien CELLES
# 28/11/2008

import csv
import os
import shutil
import zipfile
#import tkMessageBox

dirOrigine = "\\\\Andromede\\Comptes\\GTE\\dut"
#zFile =  "C:\\Documents and Settings\\scelles\\Mes documents\\copie_autocad.zip"
zFile =  "copie_autocad.zip"

#liste = "C:\\Documents and Settings\\scelles\\Mes documents\\liste.csv"
liste = "Z1PT11-500.csv"
extensions = [".dwg",".dwt"]

def message_info(msg):
  #tkMessageBox.showinfo("Copie", msg)
  print msg

#ouverture du fichier csv contenant les logins en lecture
file = csv.reader(open(liste,"rb"), delimiter=';')

message_info("Creation du fichier "+zFile)
zip=zipfile.ZipFile(zFile, 'w')

message_info("Debut de la copie")

for row in file:
  # recuperation du login de l'eleve
  login = row[1]
  print "******** Eleve = "+ login + " - "+ row[2] +" ********"

  root=''
  dirs=[]
  files=[]
  for root, dirs, files in os.walk(os.path.join(dirOrigine, login), topdown=True):
    for file in files:
      (shortname, extension) = os.path.splitext(file)
      if (extension in extensions):
        message_info(os.path.join(root, file))
        zip.write(os.path.join(root, file))

zip.close()

message_info("Fin de la copie")
