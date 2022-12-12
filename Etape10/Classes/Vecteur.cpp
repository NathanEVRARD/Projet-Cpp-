#include "Vecteur.h"

//------------  CONSTRUCTEURS  ------------------------

template <class T> Vecteur<T>::Vecteur()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut ! (Vecteur)" << endl;
	#endif

	_sizeMax = 50;
	_size = 0;
	v = new T[sizeMax()];
}

template <class T> Vecteur<T>::Vecteur(int i)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation ! (Vecteur)" << endl;
	#endif

	_sizeMax = i;
	_size = 0;
	v = new T[i];
}

template <class T> Vecteur<T>::Vecteur(const Vecteur<T>& vect)
{
	#ifdef DEBUG
		cout << "Constructeur de copie ! (Vecteur)" << endl;
	#endif

	int i;
	_sizeMax = vect.sizeMax();
	_size = vect.size();
	v = new T[sizeMax()];

	for(i = 0; i < _size; i++)
	{
		v[i] = vect.v[i];
	}
}

//--------------  DESTRUCTEUR  ------------------------

template <class T> Vecteur<T>::~Vecteur()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Vecteur)" << endl;
	#endif

	delete [] v;
}

//--------------  GETTERS  ----------------------------

template <class T> int Vecteur<T>::sizeMax() const
{
	return _sizeMax;
}

template <class T> int Vecteur<T>::size() const
{
	return _size;
}

//---------------  OPERATEURS  -------------------------

template <class T> Vecteur<T>& Vecteur<T>::operator=(const Vecteur& vect)
{
	int i;
	_sizeMax = vect.sizeMax();
	_size = vect.size();

	if(v != NULL)
		delete [] v;

	v = new T[sizeMax()];

	for(i = 0; i < sizeMax(); i++)
	{
		v[i] = vect.v[i];
	}

	return (*this);
}

template <class T> const T& Vecteur<T>::operator[](int i)
{
	return *(v+i);
}

//------------  AJOUT ET SUPPRESSION  ------------------

template <class T> void Vecteur<T>::insere(const T& val)
{
	// if(size() >= sizeMax())
	// 	return;
	v[size()] = val;
	_size += 1;
}

template <class T> T Vecteur<T>::retire(int e)
{
    int i;
    T temp;

    if(e > size())
        return v[0];

    temp = v[e];

    for(i = e; i < size() - 1; i++)
    {
        v[i] = v[i+1];
    }
    _size-= 1;

    return temp;
}

template <class T> void Vecteur<T>::Affiche() const
{
	cout << "[";
	for(int i = 0; i < size(); i++)
	{
		cout << v[i] << "";
		if(i < size() - 1)
			cout << ", ";
	}
	cout << "]" << endl;
}

//----------  INSTANCES  -----------------
#include "Client.h"
#include "Employe.h"
#include "Modele.h"
#include "Option.h"

template class Vecteur<Client>;
template class Vecteur<int>;
template class Vecteur<Employe>;
template class Vecteur<Modele>;
template class Vecteur<Option>;
//template class Vecteur<string>;
