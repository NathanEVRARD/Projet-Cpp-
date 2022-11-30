#include "Iterateur.h"

//------------------  CONSTRTCTETRS  --------------------------------

template <class T> Iterateur<T>::Iterateur(Vecteur<T>& vt) : vec(vt), pCur(vt.v)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation ! (Iterateur)" << endl;
	#endif
}

//-----------------  DESTRTCTETR  ---------------------------------

template <class T> Iterateur<T>::~Iterateur()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Iterateur)" << endl;
	#endif
}

//-----------------  OPERATETRS  -----------------------------------

template <class T> bool Iterateur<T>::operator++(int)
{
	if(!end())
	{
		pCur++;
		return true;
	}
	return false;
}

template <class T> Iterateur<T>::operator T()  const
{
	return *pCur;
}

//----------------  METHODES DE PARCOTRS  --------------------------

template <class T> void Iterateur<T>::reset()
{
	pCur = vec.v;
}

template <class T> bool Iterateur<T>::end()
{
	if(pCur - vec.v >= vec.size()) return true;
	else return false;
}

template class Iterateur<int>;
template class Iterateur<Client>;