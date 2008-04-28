1 Création d'un LED avec un PictureBox
 2 boutons : Allumer / Eteindre
 
2 Création d'un bouton inverser
 -> Nécessité de stocker l'état de la LED dans une donnée membre privée
  m_etat de type Boolean (True ou False)
  Creation d'une méthode dessiner qui dessine de la bonne couleur la LED
  en fonction de l'état m_etat
 
3 Encapsulation dans un contrôle utilisateur
On encapsule l'état de la led (la donnée membre m_etat)
ainsi que les méthode s'appliquant à notre objet : allumer eteindre inverser
Ces méthodes doivent être "public" afin de pouvoir être accessible depuis l'extérieur de l'objet
La méthode dessiner

4 Création d'un propriété permettant d'accéder à l'état (lecture et écriture)

5 Diagramme UML de l'objet LED

6 Création d'un bouton poussoir basé sur la LED
