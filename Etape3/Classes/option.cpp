#include "option.h"

//----------------  CONSTRUCTEURS  ---------------------------

Option::Option()
{
	#ifdef DEBUG
  	cout << "Constructeur par défaut ! (Option)" << endl << endl;
  	#endif

	setCode("Code");
	setIntitule("Intitule");
	setPrix(0);
}

Option::Option(string c, string i, float p)
{
	#ifdef DEBUG
	cout << "Constructeur initialisation ! (Option)" << endl << endl;
	#endif

	setCode(c);
	setIntitule(i);
	setPrix(p);
}

Option::Option(const Option& o)
{
	#ifdef DEBUG
  	cout << "Constructeur de copie ! (Option)" << endl << endl;
  	#endif

	setCode(o.getCode());
	setIntitule(o.getIntitule());
	setPrix(o.getPrix());
}

//----------------  DESTRUCTEUR  -----------------------------

Option::~Option()
{
	#ifdef DEBUG
	  cout << "Destructeur ! (Option)" << endl << endl;
	  #endif
}

//----------------  SETTERS  ---------------------------------

void Option::setCode(string c)
{
	code = c;
}

void Option::setIntitule(string i)
{
	intitule = i;
}

void Option::setPrix(float p)
{
	prix = p;
}

//----------------  GETTERS  ---------------------------------

string Option::getCode(void) const
{
	return code;
}

string Option::getIntitule(void) const
{
	return intitule;
}

float Option::getPrix(void) const
{
	return prix;
}

//---------------- OPERATEURS  -------------------------------

Option Option::operator>>(Option& o)
{
  
}

//----------------  AUTRES FONCTIONS  ------------------------

void Option::Affiche(void) const
{
	cout << getCode() << "(" << getIntitule() << ", "  << getPrix() << ")" << endl;
}
