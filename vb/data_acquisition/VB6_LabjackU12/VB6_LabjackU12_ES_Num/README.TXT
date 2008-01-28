Objet Visual Basic 6 permettant d'accéder à la carte d'entrée/sortie Labjack U12
================================================================================
Entrées / sorties numériques
============================

Installation (pour les utilisateurs de l'objet)
============
Exécuter l'installeur U12SetupV120a.exe
 (ce fichier fournit par Labjack installe les DLL, les contrôles OCX (ActiveX), etc... nécessaires à l'utilisation de la carte

Copier le fichier ES_Analog_LabjackU12.ocx dans le répertoire
C:\Program Files\DevStudio\VB\ES_Num_LabjackU12
ou
C:\Program Files\Microsoft Visual Studio\VB98\ES_Analog_LabjackU12

Utilisation du composant
========================
Fichier Nouveau projet Exe
Clic droit sur composant et ajouter ES_Num_LabjackU12


Développeur (pour modifier l'objet et en recréer un)
===========
ES_Num.ctl : fichier contrôle Utilisateur
Test et modification du contrôle utilisateur
 ouvrir le projet Test_ES_Num_LabjackU12.vbp
 Rem : mettre la propriété Public du contrôle utilisateur à False 
 Exécuter avec compilation complète
 modifier, etc...

Création du fichier ocx
 ouvrir le projet ES_Num_LabjackU12.vbp
 Rem : mettre la propriété Public à True
 Menu Fichier>Créer fichier.ocx
 

Déploiement
 voir installation (pour les utilisateurs de l'objet)