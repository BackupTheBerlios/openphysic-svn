1 Cr�ation d'un LED avec un PictureBox
 2 boutons : Allumer / Eteindre
 
2 Cr�ation d'un bouton inverser
 -> N�cessit� de stocker l'�tat de la LED dans une donn�e membre priv�e
  m_etat de type Boolean (True ou False)
  Creation d'une m�thode dessiner qui dessine de la bonne couleur la LED
  en fonction de l'�tat m_etat
 
3 Encapsulation dans un contr�le utilisateur
On encapsule l'�tat de la led (la donn�e membre m_etat)
ainsi que les m�thode s'appliquant � notre objet : allumer eteindre inverser
Ces m�thodes doivent �tre "public" afin de pouvoir �tre accessible depuis l'ext�rieur de l'objet
La m�thode dessiner

4 Cr�ation d'un propri�t� permettant d'acc�der � l'�tat (lecture et �criture)

5 Diagramme UML de l'objet LED

6 Cr�ation d'un bouton poussoir bas� sur la LED
