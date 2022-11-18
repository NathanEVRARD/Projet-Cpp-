#include "VecteurTriee.h"

//------------------------  CONSTRUCTEURS  ----------------------------

template <class T>
VecteurTriee<T>::VecteurTriee() : Vecteur<T>()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut ! (VecteurTriee)" << endl;
	#endif
}

template <class T>
VecteurTriee<T>::VecteurTriee(int t) : Vecteur<T>(t)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation ! (VecteurTriee)" << endl;
	#endif
}

template <class T>
VecteurTriee<T>::VecteurTriee(VecteurTriee& v) : Vecteur<T>(v)
{
	#ifdef DEBUG
		cout << "Constructeur de copie ! (VecteurTriee)" << endl;
	#endif
}

//-----------------------  DESTRUCTEUR  -------------------------------

template <class T>
VecteurTriee<T>::~VecteurTriee()
{
	#ifdef DEBUG
		cout << "Destructeur ! (VecteurTriee)" << endl;
	#endif
}

//-----------------------  AJOUT  -------------------------------------

template <class T>
void VecteurTriee<T>::insere(const Client& c)
{
	int i, cpt;
	Client temp;
	bool trouve;

	if(size() == sizeMax())
		return;

	for(i = 0, trouve = false; i < size() && !trouve; i++)
	{
		if(strcmp(c.getNom(), v[i].getNom()) == 0)
		{
			if(strcmp(c.getPrenom(), v[i].getPrenom()) == 1)
			{
				i--;
				trouve = true;
			}
		}
	}

	if(trouve)
	{
		for(cpt = i;cpt < sizeMax() - 1; cpt++)
		{
			temp = v[cpt+1];
			v[cpt+1] = v[cpt];
		}
	}
	v[i] = c;
	_size += 1;


}

template <class T>
void VecteurTriee<T>::insere(const int& i)
{

}