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

4 Cr�ation d'une propri�t� permettant d'acc�der � l'�tat (lecture et �criture) de la LED
Ecriture sur la propi�t� etat
Ajout d'un CheckBox (recup�ration de la propri�t� value du CheckBox lors de l'�v�nement Click)
Ajout de Property Let
Public Property Let Etat(new_etat As Boolean)
    m_Etat = new_etat
    dessiner
End Property

5 Cr�ation d'un �venement etat_changed et Lecture de la propri�t� etat
Public Property Get Etat() As Boolean
    Etat = m_Etat
End Property

PropertyChanged "Etat" dans Property Let Etat ainsi que dans toutes les m�thodes qui changent l'�tat de la LED

Event etat_changed()

6 Diagramme UML de l'objet LED

Am�liorations possibles :
Ajouter les propri�t�s Couleur_ON et Couleur_OFF
Faire en sorte que Couleur_OFF soit calcul� � partir de Couleur_ON, rendre priv� Couleur_ON Couleur_OFF et n'acc�der qu'� la propri�t� Couleur

6 Cr�ation d'un bouton poussoir bas� sur la LED
' Transmission de l'�v�nement Click
Private Sub shaLED_Click()
    RaiseEvent Click
End Sub