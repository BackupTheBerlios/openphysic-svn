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

4 Création d'une propriété permettant d'accéder à l'état (lecture et écriture) de la LED
Ecriture sur la propiété etat
Ajout d'un CheckBox (recupération de la propriété value du CheckBox lors de l'évènement Click)
Ajout de Property Let
Public Property Let Etat(new_etat As Boolean)
    m_Etat = new_etat
    dessiner
End Property

5 Création d'un évenement etat_changed et Lecture de la propriété etat
Public Property Get Etat() As Boolean
    Etat = m_Etat
End Property

PropertyChanged "Etat" dans Property Let Etat ainsi que dans toutes les méthodes qui changent l'état de la LED

Event etat_changed()

6 Diagramme UML de l'objet LED

Améliorations possibles :
Ajouter les propriétés Couleur_ON et Couleur_OFF
Faire en sorte que Couleur_OFF soit calculé à partir de Couleur_ON, rendre privé Couleur_ON Couleur_OFF et n'accéder qu'à la propriété Couleur

6 Création d'un bouton poussoir basé sur la LED
' Transmission de l'évènement Click
Private Sub shaLED_Click()
    RaiseEvent Click
End Sub