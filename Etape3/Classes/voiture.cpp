#include "voiture.h"
#include "option.h"
#include <iostream>

#define NBR_OPTIONS 5

using namespace std;

//-------------------  FONCTIONS AMIES  ------------------- 


//-------------------  CONSTRUCTEURS  ---------------------

Voiture::Voiture(void)
{
	#ifdef DEBUG
  	cout << "Constructeur par défaut ! (Voiture)" << endl << endl;
  	#endif

	setNom("Nom");
	Modele m;
	setModele(m);
	int i = 0;
	while(i < 5)
	{
		options[i] = NULL;
		i++;
	}
}

Voiture::Voiture(string n, Modele m)
{

	#ifdef DEBUG
	cout << "Constructeur initialisation ! (Voiture)" << endl << endl;
	#endif

	setNom(n);
	setModele(m);
	int i = 0;
	while(i < 5)
	{
		options[i] = NULL;
		i++;
	}
}

Voiture::Voiture(const Voiture& v)
{

	#ifdef DEBUG
  	cout << "Constructeur de copie ! (Voiture)" << endl << endl;
  	#endif

	int i;

	setNom(v.getNom());
	setModele(v.getModele());
	
	for(i = 0; i < NBR_OPTIONS; i++)
	{
		options[i] = NULL;
	}

	for(i = 0; i < NBR_OPTIONS; i++)
	{
		if(v.options[i] != NULL)
		{
			AjouteOption(*v.options[i]);
		}
	}
}

//-------------------  DESTRUCTEUR  ---------------------

Voiture::~Voiture()
{
	#ifdef DEBUG
  	cout << "Destructeur ! (Voiture)" << endl << endl;
  	#endif

	for(int i = 0; i < NBR_OPTIONS; i++)
	{
		if(options[i] != NULL)
			RetireOption(options[i]->getCode());
	}
}

//-------------------  SETTERS ET GETTERS  ----------------

void Voiture::setNom(string n)
{
	nomProjet = n;
}

void Voiture::setModele(Modele m)
{
	modele.setNom(m.getNom());
	modele.setPuissance(m.getPuissance());
	modele.setMoteur(m.getMoteur());
	modele.setPrixDeBase(m.getPrixDeBase());
}

string Voiture::getNom() const
{
	return nomProjet;
}

Modele Voiture::getModele() const
{
	return modele;
}

float Voiture::getPrix() const
{
	float prix;
	int i;

	prix = modele.getPrixDeBase();

	for(i = 0; i < NBR_OPTIONS; i++)
	{
		if(options[i] != NULL)
			prix += options[i]->getPrix();
	}

	return prix;
}
//--------------------  OPERATEURS  --------------------------

Voiture& Voiture::operator=(const Voiture& v)
{
    int i;

    setNom(v.getNom());
    setModele(v.getModele());

    for(i = 0; i < NBR_OPTIONS; i++)
    {
        if(options[i] != NULL)
        {
            RetireOption(options[i]->getCode());
        }
    }

    for(i = 0; i < NBR_OPTIONS; i++)
    {
        if(v.options[i] != NULL)
        {
            AjouteOption(*v.options[i]);
        }
    }

    return (*this);
}


Voiture operator+(const Option& o, const Voiture& v)
{
	Voiture vtemp(v);

	vtemp.AjouteOption(o);

	return vtemp;
}

Voiture Voiture::operator+(const Option& o)
{
	Voiture vtemp(*this);

	vtemp.AjouteOption(o);

	return vtemp;
}

Voiture Voiture::operator-(const string s)
{
	Voiture vtemp(*this);

	vtemp.RetireOption(s);

	return vtemp;
}

Voiture Voiture::operator-(const Option& o)
{
	Voiture vtemp(*this);

	vtemp.RetireOption(o.getCode());

	return vtemp;
}

int Voiture::operator<(const Voiture& v)
{
	if(this->getPrix() < v.getPrix())
		return 1;
	else
		return 0;
}

int Voiture::operator>(const Voiture&v)
{
	if(this->getPrix() > v.getPrix())
		return 1;
	else
		return 0;
}

int Voiture::operator==(const Voiture&v)
{
	if(this->getPrix() == v.getPrix())
		return 1;
	else
		return 0;
}

ostream& operator<<(ostream& s, Voiture& v)
{
	int i;
	Option *p;
	s << "Modele : ";
	v.getModele().Affiche();

	for(i = 0; i < NBR_OPTIONS && v.options[i] != NULL; i++)
	{
		v.options[i]->Affiche();
	}

	return s;
}

Option* Voiture::operator[](int i)
{
	return this->options[i];
}

//--------------------  AUTRES FONCTIONS  --------------------

void Voiture::AjouteOption(const Option& o)
{
	int i;
	Option *op;


	for(i = 0; i < NBR_OPTIONS; i++)
	{
		if(options[i] == NULL)
		{
			op = new Option(o);
			options[i] = op;
			i+= NBR_OPTIONS;
		}
	}
}

void Voiture::RetireOption(string c)
{
	int i;

	for(i = 0; i < NBR_OPTIONS; i++)
	{
		if(options[i] != NULL)
		{
			if(options[i]->getCode() == c)
			{
				delete options[i];
				options[i] = NULL;
				i += NBR_OPTIONS;
			}
		}
	}
}

void Voiture::Affiche()
{
	
	cout << "Nom du projet : " << getNom() << endl << "Modele : ";
	getModele().Affiche();
	int i = 0;
	while(i < NBR_OPTIONS)
	{
		if(options[i] != NULL)
		{
			options[i]->Affiche();
		}
		i++;
	}
}