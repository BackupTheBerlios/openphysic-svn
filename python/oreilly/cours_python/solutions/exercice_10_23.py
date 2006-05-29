#! /usr/bin/env python
# -*- coding: Latin-1 -*-

# Conversion en majuscule du premier caract�re de chaque ligne

fiSource = raw_input("Nom du fichier � traiter : ")
fiDest = raw_input("Nom du fichier destinataire : ")
fs = open(fiSource, 'r')
fd = open(fiDest, 'w')

while 1:
    ch = fs.readline()
    if ch == "":
        break
    if ch[0] >= "A" and ch[0] <= "Z":
        # le premier car. est une majuscule. On passe.
        pass
    else:
        # Reconstruction de la cha�ne:
        pc = ch[0].upper()      # Premier caract�re converti
        rc = ch[1:]             # toute le reste de la cha�ne  
        ch = pc + rc            # fusion
        # variante utilisant une m�thode encore plus int�gr�e :
        # ch = ch.capitalize()
    # Transcription :    
    fd.write(ch)

fd.close()    
fs.close()
