Projet de chrono, mesure de température
Microcontrôleur
Afficheur LCD graphique
Boutons




Inspiré de Alphano dont voici les caractéristiques de certains modèles
http://www.alfano-usa.com
http://www.chrono-sport.fr (importateur pour la France)
http://www.alfano.be (manuel en français)
voir docs dans /media/graver/auto/sports_mecaniques/kart/alfano


"Le chronomètre Alfano PRO fonctionne grâce à un capteur fixé sur le plancher du kart qui détecte la présence du champ magnétique implanté dans la piste. Très utilisé pour les réglages des moteurs, il affiche également les régimes moteur ainsi que la température du moteur. Caractéristiques : - Mémoire de 98 tours. - Compte-tours (différentes lectures) Maximum 26.000 tr/m. - Affichage du meilleur tour, écart avec le meilleur tour, nombre de tours et temps total de roulage. - 5 Compteurs temps moteurs. - Température moteur Dimensions du Boîtier : 115 mm X 90 mm / Dimensions de l' Ecran : 86 mm X 35 mm. Poids : +/- 460 Gr Matériel inclus : 1 capteur magnétique 1 câble pour le capteur magnétique 1 Câble pour le compte-tours 3 Colsons noirs 1 Manuel ""mode d´emploi"" En option : Capteur de t° eau / Capteur de t° à la bougie / Emetteur et récepteur infrarouge"


"Caractéristques : - Temps au tour / meilleur temps - Configurable jusquÇà 6 partiels - Comparateur de temps (sur le meilleur temps, sur le temps précédent, sur le temps cible « configurable ») - RPM en lecture directe, Shift Lights et Bar Graph - 2 entrées de température (De 0°C à 1.500°C: Eau, Culasse, Bougie, Echappements, etcÄ) - Configuration de la température : Maximum, minimum pour chaque tour avec alarmes luminescentes - Vitesse (Configurable avec ou sans le capteur de roue) - Rapport de boîte jusqu'à 9 vitesses - 8 compteurs configurables - Simulation dÇun tour en temps réel, pendant 15 Minutes - Force G Latérale et Longitudinale - Fonctionne en infrarouge pour les pistes non équippées de la bande magnétique - Données de téléchargement à un PC par l'intermédiaire de stylo infrarouge USB - Système up-gradable Dimension du système : 123 x 104 mm Dimension écran : 85 x 49 mm Poids : +/- 425 Gr Batteries : 2 x AA "





Affichage
=========
Possible : LCD (alphanumérique ou graphique ?)
graphique car plus joli et plus facile à faire évoluer...


possibilité de tester le LCD avec lcdproc http://lcdproc.omnipotent.net
This is a client/server suite including drivers for all kinds of
nifty LCD displays. The server supports several serial devices: Matrix
Orbital, Crystal Fontz, Bayrad, LB216, LCDM001 (kernelconcepts.de),
Wirz-SLI and PIC-an-LCD; and some devices connected to the LPT port:
HD44780, STV5730, T6963, SED1520 and SED1330. As of 0.4.4 some USB
displays are also supported by the drivers CFonz633, CwLnx, and USBLCD.


http://www.matrixorbital.com

Taille autour de 85x49mm 

voir docs dans /media/graver/sciences/programmation/microcontroleurs/display_7seg_lcd_graph/


Choix final : 


Affichage à compléter avec des LEDs (vert jaune rouge)
- pour compte-tours (total 10)
  lent   2 LED vertes
  moyen  4 LED jaunes
  rapide 4 LED rouges

- autres (à définir)
  passage de 1 LED rouge


Attention au domaine de température d'utilisation du LCD !!! (surtout l'été !!!)


Microcontrôleur
===============
PIC ou ATMEL AVR ou ARM ou ...
Prévoir de la mémoire pour pouvoir stocker des données

PIC
 + beaucoup de doc en français
 - compilateur C gratuit limité

ATMEL AVR
 + quelques exemples avec ATméga sur GNU/Linux Mag France
 + compilateur C gcc-avr
 + prix
 - limité (?)

ARM
 + cross-compilation facile avec Scratchbox
 + possibilité de mettre un noyau Linux embarqué (voir uclibc ...)
 - prix !!!


Choix final :


Capteurs
========

Sonde à effet Hall
------------------
Choix final : 


Sonde température
-----------------
Choix final : 


Accéléromètre
-------------
Choix final :



Fonctionnalités supplémentaires (pas implanté dans un premier temps)
===============================
WIFI (pour envoyer les temps)
clé USB (pour récupérer les données) data-logger
coupure à distance du kart
reflashage facile du microcontroleur voir In Situ Programming ISP... par port série mais l'idéal serait par USB... voir si c'est possible !!!)

