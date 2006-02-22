#include <iostream>
#include <vector>

// un 'vector' ne contient pas de contr�le de limite
// si ce dispositif est n�cessaire il faut utiliser une 'list'

// size() fournit le nb d'�l�ments
// myVct.resize(myVct.size()+n) augmente la taille du vecteur n

using namespace std;

int main()
{
	vector <int> myVct(5); // vector est un 'template' mod�le... ici on l'applique � des nombres entiers (int ... pour integer)
	// on cr�e un vecteur de 5 entiers
	// attention � ne pas �crire :
	// vector <int> myVct[5];
	// car l� on cr�e 5 vecteurs vides
	
	myVct[0]=0;
	myVct[1]=10;
	myVct[2]=20;
//	myVct[3]=30;	// les �l�ments sont initialis�s � 0 dans un vector
	myVct[4]=40;
	
	cout<<"myVct\n";
	for (int i=0 ; i<myVct.size() ; i++)
	{
		cout<<myVct[i]<<"\n";
	}
	
	cout<<"Pas de contr�le de d�passement\n";
	cout<<myVct[12500]<<"\n"; // pas de contr�le de d�passement
	
}
