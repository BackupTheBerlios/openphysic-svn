1 Cr�ation d'un LED avec un PictureBox
 2 boutons : Allumer / Eteindre
 Petite taille ! 255x255
 
2 Cr�ation d'un bouton inverser
 -> N�cessit� de stocker l'�tat de la LED dans une donn�e membre priv�e
  m_etat de type Boolean (True ou False)
  Creation d'une m�thode dessiner qui dessine de la bonne couleur la LED
  en fonction de l'�tat m_etat
 
3 Encapsulation dans un contr�le utilisateur
encapsulation = information hiding
On encapsule l'�tat de la led (la donn�e membre m_etat)
ainsi que les m�thode s'appliquant � notre objet : allumer eteindre inverser
Ces m�thodes doivent �tre "public" afin de pouvoir �tre accessible depuis l'ext�rieur de l'objet
La m�thode dessiner

Pb : lorsqu'on lance le prog la LED n'est pas dessin�e... (alors qu'elle est initialement �teinte)
Ev�nement Paint du PictureBox -> dessiner
Picture1.Cls

4 Cr�ation d'une propri�t� permettant d'acc�der � l'�tat (�criture) de la LED
Ecriture sur la propi�t� etat
Ajout d'un CheckBox (recup�ration de la propri�t� value du CheckBox lors de l'�v�nement Click)
Ajout de Property Let
Public Property Let Etat(new_etat As Boolean)
    m_Etat = new_etat
    dessiner
End Property

5 Cr�ation d'un �venement ChangementEtat et Lecture de la propri�t� Etat
Public Property Get Etat() As Boolean
    Etat = m_Etat
End Property

PropertyChanged "Etat" dans Property Let Etat ainsi que dans toutes les m�thodes qui changent l'�tat de la LED ???? n�cessaire
uniquement pour la fen�tre propri�t� !!!

D�claration de l'�v�nement
Event ChangementEtat()

Lancement de l'�v�nement
RaiseEvent ChangementEtat

C�t� feuille principale traitement de l'�v�nement ChangementEtat
If LED1.Etat Then
    chkEtatLed.Value = 1
Else
    chkEtatLed.Value = 0
End If


Resize !
Private Sub UserControl_Resize()
Picture1.Width = Me.Width
Picture1.Height = Me.Height
End Sub

Propri�t�s width et height du PictureBox


6 Diagramme UML de l'objet LED et d�ployment de l'objet

Am�liorations possibles :
Ajouter les propri�t�s Couleur_ON et Couleur_OFF
Faire en sorte que Couleur_OFF soit calcul� � partir de Couleur_ON, rendre priv� Couleur_ON Couleur_OFF et n'acc�der qu'� la propri�t� Couleur

6 Cr�ation d'un bouton bas� sur la LED
 Bouton avec commutation � l'appui

Notion d'h�ritage (Inheritance en anglais) n'existe pas en VB6 -> il faut recopier le code
en VB.Net mot-cl� "extends"


R�action � l'�v�nement MouseDown sur PictureBox lorsque l'on appuie sur le bouton de gauche (Button=1)


7. Bouton avec commutation jusqu'au rel�chement
R�action � l'�v�nement MouseDown et MouseUp sur PictureBox


Am�liorations possibles :
Propri�t�s m�caniques diff�rentes pour le bouton avec MouseUp et MouseDown
Ex Labview :
 Commutation � l'appui (FAIT en 6)
 Commutation au rel�chement
 Commutation jusqu'au rel�chement (FAIT en 7)
 Armement � l'appui
 Armement au rel�chement
 Armement jusqu'au rel�chement 


8. Afficheur d'octet
notion d'agr�gation (aggregation) ou de composition (object composition)
cr�er un nouveau projet dans lequel vous inclurez le dernier contr�le LED r�alis�.
Cr�eez un nouveau contr�le utilisateur appel� AfficheurOctet.
Ce contr�le doit permettre d'afficher un nombre entier positif cod� sur un octet (8 bits).
On cr�era pour cet objet une propri�t� (en lecture et en �criture) permettant
de stocker ce nombre dans l'afficheur d'octet et d'allumer les Leds n�cessaires.


autres notions objets non abord�es :
polymorphisme, template de classe