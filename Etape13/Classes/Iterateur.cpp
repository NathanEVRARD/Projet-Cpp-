#include "Iterateur.h"

//------------------  CONSTRUCTEURS  --------------------------------

template <class T> Iterateur<T>::Iterateur(const Vecteur<T>& vt) : vec(vt), pCur(vt.v)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation ! (Iterateur)" << endl;
	#endif
}

//-----------------  DESTRUCTEUR  ---------------------------------

template <class T> Iterateur<T>::~Iterateur()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Iterateur)" << endl;
	#endif
}

//-----------------  OPERATEURS  -----------------------------------

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

//----------------  METHODES DE PARCOURS  --------------------------

template <class T> void Iterateur<T>::reset()
{
	pCur = vec.v;
}

template <class T> bool Iterateur<T>::end()
{
	if(pCur - vec.v >= vec.size()) return true;
	else return false;
}
#include "Client.h"
#include "Modele.h"
#include "Option.h"
#include "Employe.h"
#include "Contrat.h"

template class Iterateur<int>;
template class Iterateur<Client>;
template class Iterateur<Modele>;
template class Iterateur<Option>;
template class Iterateur<Employe>;
template class Iterateur<Contrat>;