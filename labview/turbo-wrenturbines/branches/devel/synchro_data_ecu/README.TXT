http://www.celles.net/wiki/ProjetInstrumentationTurboreacteur

========

Synchronisation liaison s�rie (cable Xicoy USB)
Permet de r�cup�rer RPM, EGT, ...

http://www.espiell.com/fadprot.pdf


Actuellement la synchro fonctionne ainsi :
- lecture de 50 octets
- observation des 2 premiers octets, si �a n'est pas 252 - 253 en t�te
on demande une lecture de 1 octet (afin de faire un d�calage) puis
on recommence en lisant 50 octets.
- si on a bien 252-253 en t�te on d�coupe la chaine et on fabrique le
cluster contenant les donn�es

Je pense qu'il faudrait essayer detecter le d�but de la trame et
d�duire l'offset (d�calage) c'est � dire
la position du d�but de la trame enti�re dans l'ensemble de ces 100 octets.
et ensuite r�cup�rer les donn�es � partir de ce d�calage.

J'ai fait un exemple minimaliste qui d�crit cette id�e
J'ai consid�r� dans mon exemple que le d�but d'une trame est marqu�
par les caract�res "��" (FC -FD en hexa ou 252 - 253 en d�cimal)
N'ayant pas le turbo chez moi j'ai g�n�r� un exemple de trame avec
turbo-wrenturbines\tags\2008-04-02\test_sim_turbo.vi
J'ai coll� deux trames et je les ai d�cal� vers la droite. Le d�but
d'une trame commence dans mon exemple au 4i�me octet (en comptant �
partir de 0).

Le programme synchro.vi d�tecte bien le d�but
de la trame en 4i�me position.

========

Autre id�e... ne lire que 50 octets (longueur d'une trame)
mais utiliser la fonction modulo
on aura ainsi l'impression d'avoir une seule trame mais en fait
�a sera la fin d'une trame et le d�but de la suivante


========
Autre id�e... 
consid�rer que le FC FD de "d�but" de trame est en fait 2 caract�res
de "fin" de trame
Utiliser une fonction Labview de lecture jusqu'� un caract�re de fin de trame