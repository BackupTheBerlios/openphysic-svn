Exemples permettant de cacher/afficher des parties d'un VI LabVIEW.

Un mot de passe permet par exemple de faire en sorte qu'un VI minimal avec juste
les donn�es devienne un VI "complet" avec tous les calculs exp�rimentaux effectu�s
Dans mon exemple le mot de passe est 123 (suivi de entr�e ou suivi d'un clic � l'ext�rieur
de la zone de saisie du mot de passe).

main.vi
Avec le noeud de propri�t� (clic droit sur un �l�ment du diagramme / Cr�er noeud de propri�t�)
on peut changer la propri�t� "Visible" et la mettre � VRAI ou FAUX.

main_tab.vi
Le concept est similaire mais j'utilise un conteneur (tab control) que je rends visible ou pas.
Sur un autre tab control je modifie la propri�t� "Visible" d'une page donn�e via
une r�f�rence au tab control, un noeud de propri�t�s pour r�cup�rer un tableau de page.
A partir du tableau de pages je r�cup�re la page � cacher/afficher via le noeud de propri�t� Visible.