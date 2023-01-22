#include "Option.h"
#include "OptionException.h"

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
	if(c.length() != 4)
	{
		cout << "taille : " << c.length() << endl;
		OptionException e("Format incorrect (code) !");
		throw e;
	}
	code = c;
}

void Option::setIntitule(string i)
{
	if(i == "")
	{
		cout << "Intitule vide !" << endl;
		OptionException e("Intitule vide !");
		throw e;
	}

	intitule = i;
}

void Option::setPrix(float p)
{
	if(p < 0)
	{
		
		OptionException e("Prix negatif !");
		throw e;
	}

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

//---------------- OPERATEURS  --------------------------------

istream& operator>>(istream& s, Option& o)
{
	string codeTemp, intituleTemp;
	float prixTemp;

  cout << "Saisissez le code de l'option : "; s >> codeTemp;
  cout << "Saisissez l'intitule de l'option : "; s >> intituleTemp;
  cout << "Saisissez le prix de l'option : "; s >> prixTemp;

  o.setCode(codeTemp);
  o.setIntitule(intituleTemp);
  o.setPrix(prixTemp);

  return s;
}

ostream& operator<<(ostream& s, const Option& o)
{
	s << o.getCode() << "(" << o.getIntitule() << ", " << o.getPrix() << ")";

	return s;
}
Option Option::operator--()
{
	if(this->getPrix() < 50)
	{
		OptionException e("Prix rendu negatif !");
		throw e;
	}

	setPrix(this->getPrix() - 50);

	return (*this);
}

Option Option::operator--(int)
{
	Option otemp(*this);

	setPrix(this->getPrix() - 50);

	return otemp;
}


//----------------  AUTRES FONCTIONS  ------------------------

void Option::Affiche(void) const
{
	cout << getCode() << "(" << getIntitule() << ", "  << getPrix() << ")" << endl;
}

void Option::Save(ofstream &fichier)const
{
    int tailleCode = getCode().size();
    int tailleIntitule = getIntitule().size();

    if(fichier.is_open())
    {

        fichier.write((char*)&tailleCode,sizeof(int));
        fichier.write((char*)getCode().data(),sizeof(char) * tailleCode);

        fichier.write((char*)&tailleIntitule,sizeof(int));
        fichier.write((char*)getIntitule().data(),sizeof(char) * tailleIntitule);

        fichier.write((char*)&prix,sizeof(float));

    }
}

void Option::Load(ifstream &fichier)
{    
    int tailleCode;
    int tailleIntitule;

    if(fichier.is_open())
    {
        fichier.read((char*)&tailleCode,sizeof(int));
        intitule.resize(tailleCode);
        fichier.read((char*)code.data(),sizeof(char)*tailleCode);

        fichier.read((char*)&tailleIntitule,sizeof(int));
        intitule.resize(tailleIntitule);
        fichier.read((char*)intitule.data(),sizeof(char)*tailleIntitule);

        fichier.read((char*)&prix,sizeof(float));

    }
}