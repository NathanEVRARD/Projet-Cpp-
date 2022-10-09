#include "voiture.h"
#include "option.h"

#include <iostream>

#define NBR_OPTIONS 5

using namespace std;

//-------------------  CONSTRUCTEURS  ---------------------

Voiture::Voiture(void)
{
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
	modele = m;
}

void Voiture::setOption(Option *o)
{
	for(int i = 0; i < NBR_OPTIONS; i++)
	{
		if(options[i] == NULL)
		{
			options[i] = o;
			i += NBR_OPTIONS;
		}
	}
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