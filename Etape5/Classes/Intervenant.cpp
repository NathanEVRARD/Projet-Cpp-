#include "Intervenant.h"

//--------------------  CONSTRUCTEURS  ------------------------------

Intervenant::Intervenant() : Personne()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut ! (Intervenant)" << endl;
	#endif

	setNumero(0);
}

Intervenant::Intervenant(int i, string n, string p) : Personne(n, p)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation ! (Intervenant)" << endl;
	#endif

	setNumero(i);
}

Intervenant::Intervenant(Intervenant& i)
{
	#ifdef DEBUG
		cout << "Constructeur de copie ! (Intervenant)" << endl;
	#endif

	setNumero(i.getNumero());
}

//-------------------  DESTRUCTEUR   ---------------------------------

Intervenant::~Intervenant()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Intervenant)" << endl;
	#endif
}

//------------------  SETTERS ET GETTERS  ----------------------------

void Intervenant::setNumero(int n)
{
	if(n > -1)
		numero = n;
}

int Intervenant::getNumero() const
{
	return numero;
}

//----------------- AUTRES METHODES  ------------------------------



//----------------  OPERATEURS  ----------------------------------

Intervenant& Intervenant::operator=(Intervenant& i)
{
	Personne::setNom(i.Personne::getNom());
	Personne::setPrenom(i.Personne::getPrenom());
	setNumero(i.getNumero());

	return (*this);
}