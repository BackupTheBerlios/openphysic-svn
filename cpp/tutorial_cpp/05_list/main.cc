#include <iostream>
#include <list>

using namespace std;

// myList.begin()
//	renvoie un it�rateur vers le premier �l�ment
// myList.end()
//	renvoie un it�rateur vers le dernier �l�ment

// push_front(e)
//	ajout l'�l�ment e au d�but
// push_back(e)
//	ajout l'�l�ment e � la fin
// insert(i,e)
//	insert l'�l�ment e avant l'�l�ment auquel l'it�rateur 'i' fait r�f�rence

int main()
{
	list <int> myList;
	typedef list <int>::const_iterator LI; // type it�rateur (pour modification dans liste) ... pour lecture seule on utilise le type 'iterator'
	// on acc�de � un �l�men d'une liste
	// non pas � l'aide d'une indice (comme pour un vector)
	// mais � l'aide d'une valeur donn�
	
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.push_front(4);
	myList.push_front(5);
	
/*	
	list <int>::iterator myIterator;
	myIterator = myList.begin();	// TO DO : l'it�rateur doit �tre ailleurs qu'au d�but
	myList.insert(myIterator,6);
*/

	for (LI i = myList.begin() ; i != myList.end() ; ++i)
	{
		int elt = *i; // MyStruct& elt = *i;
		cout << elt << "\n";
	}
}
