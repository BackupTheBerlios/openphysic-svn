Buffer circulaire


permet de stocker des double sur un espace lin�aire de m�moire de taille fix�e
(� la compilation ou � l'ex�cution)

Mode wrap (�crasement des donn�es les plus anciennes)
ou mode fill (lancement d'une exception lors du d�passement de taille)



� faire :
redimensionnement du buffer � l'ex�cution avec conservation des donn�es

Redim Preserve
puis copie en 2 parties (d'abord les donn�es les plus r�centes puis les plus anciennes)

envisager aussi le cas du redimensionnement vers un buffer plus petit