#include "VecteurTrie.h"
//#include "Client.h"

//------------------------  CONSTRUCTEURS  ----------------------------

template <class T>
VecteurTrie<T>::VecteurTrie() : Vecteur<T>()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut ! (VecteurTrie)" << endl;
	#endif
}

template <class T>
VecteurTrie<T>::VecteurTrie(int t) : Vecteur<T>(t)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation ! (VecteurTrie)" << endl;
	#endif
}

template <class T>
VecteurTrie<T>::VecteurTrie(const VecteurTrie& v) : Vecteur<T>(v)
{
	#ifdef DEBUG
		cout << "Constructeur de copie ! (VecteurTrie)" << endl;
	#endif
}

//-----------------------  DESTRUCTEUR  -------------------------------

template <class T>
VecteurTrie<T>::~VecteurTrie()
{
	#ifdef DEBUG
		cout << "Destructeur ! (VecteurTrie)" << endl;
	#endif
}

//-----------------------  AJOUT  -------------------------------------

template <class T>
void VecteurTrie<T>::insere(const T& val)
{
    int i, temp;

    if(this->size() >= this->sizeMax())
        return;
    for(i = 0; i < this->size() && val > (this->v[i]); i++);

    for(temp = this->size(); temp >= i + 1; temp--)
    {
    	this->v[temp] = this->v[temp - 1];
    }
    this->v[i] = val;
    this->_size++;
}

template class VecteurTrie<Client>;
template class VecteurTrie<int>; 
