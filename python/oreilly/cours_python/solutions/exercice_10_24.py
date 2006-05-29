#! /usr/bin/env python
# -*- coding: Latin-1 -*-

# Fusion de lignes pour former des phrases

fiSource = raw_input("Nom du fichier � traiter : ")
fiDest = raw_input("Nom du fichier destinataire : ")
fs = open(fiSource, 'r')
fd = open(fiDest, 'w')


# On lit d'abord la premi�re ligne :
ch1 = fs.readline()
# On lit ensuite les suivantes, en les fusionnant si n�cessaire :
while 1:
    ch2 = fs.readline()
    if ch2 == "":
        break
    # Si la cha�ne lue commence par une majuscule, on transcrit
    # la pr�c�dente dans le fichier destinataire, et on la
    # remplace par celle que l'on vient de lire :
    if ch2[0] >= "A" and ch2[0] <= "Z":
        fd.write(ch1)
        ch1 = ch2
    # Sinon, on la fusionne avec la pr�c�dente :
    else:
        ch1 = ch1[:-1] + " " + ch2
        # (veiller � enlever de ch1 le caract�re de fin de ligne)
        
fd.write(ch1)        # ne pas oublier de transcrire la derni�re !
fd.close()    
fs.close()
