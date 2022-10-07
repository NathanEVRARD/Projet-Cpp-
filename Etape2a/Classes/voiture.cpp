#include "voiture.h"
#include <iostream>

using namespace std;

//-------------------  CONSTRUCTEURS  ---------------------

Voiture::Voiture(void)
{

}

Voiture::Voiture(string n, Modele m)
{

	setNom(n);
	setModele(m);
}

Voiture::Voiture(const Voiture& v)
{
	setNom(v.nomProjet);
	setModele(v.modele);
}

//-------------------  DESTRUCTEUR  ---------------------

Voiture::~Voiture()
{
	
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


string Voiture::getNom() const
{
	return nomProjet;
}

Modele Voiture::getModele() const
{
	return modele;
}

//--------------------  AUTRES FONCTIONS  --------------------

void Voiture::Affiche()
{
	cout << "Nom du projet : " << getNom() << endl << "Modele : ";
	getModele().Affiche();
}