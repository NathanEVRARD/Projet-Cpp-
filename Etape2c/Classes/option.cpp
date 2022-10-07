#include "option.h"

//----------------  CONSTRUCTEURS  ---------------------------

Option::Option()
{
	setCode("Code");
	setIntitule("Intitule");
	setPrix(0);
}

Option::Option(string c, string i, float p)
{
	setCode(c);
	setIntitule(i);
	setPrix(p);
}

Option::Option(const Option& o)
{
	setCode(o.code);
	setIntitule(o.intitule);
	setPrix(o.prix);
}

//----------------  DESTRUCTEUR  -----------------------------

Option::~Option()
{

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

//----------------  AUTRES FONCTIONS  ------------------------

void Option::Affiche(void) const
{
	cout << getCode() << "(" << getIntitule() << ", "  << getPrix() << ")" << endl;
}
