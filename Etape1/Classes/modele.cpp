#include "modele.h"

//---------------  CONSTRUCTEURS  ---------------------------------------

Modele::Modele(void) // Par défaut
{
  #ifdef DEBUG
  cout << "Constructeur défaut !" << endl << endl;
  #endif
  nom = NULL;
  setNom("nom");
}

Modele::Modele(char const *temp, int puissance, enum Moteur moteur, float prix) // D'initialisation
{
  #ifdef DEBUG
  cout << "Constructeur initialisation !" << endl << endl;
  #endif
  nom = NULL;

  setNom(temp);
  setPuissance(puissance);
  setMoteur(moteur);
  setPrixDeBase(prix);
}

Modele::Modele(const Modele& m) // De copie
{
  nom = NULL;
  setNom(m.nom);
  setPuissance(m.puissance);
  setMoteur(m.moteur);
  setPrixDeBase(m.prix);
}

//---------------  DESTRUCTEUR  -----------------------------------------

Modele::~Modele()
{
  #ifdef DEBUG
  cout << endl << "Destructeur !" << endl << endl;
  #endif
  if (nom) delete nom;
}

//---------------  SETTERS ET GETTERS  ----------------------------------

void Modele::setNom(char const *n)
{
  if (n == NULL) return;
  if (nom) delete nom;

  nom = new char[strlen(n)+1];
  strcpy(nom, n);
}

void Modele::setPuissance(int p)
{
  puissance = p;
}

void Modele::setMoteur(enum Moteur m)
{
  moteur = m;
}

void Modele::setPrixDeBase(float p)
{
  if (p < 0) return;

  prix = p;
}



char *Modele::getNom() const
{
  return nom;
}

int Modele::getPuissance() const
{
  return puissance;
}

enum Moteur Modele::getMoteur() const
{
  return moteur;
}

float Modele::getPrixDeBase() const
{
  return prix;
}

//---------------  AUTRES METHODES  -------------------------------------

void Modele::Affiche() const
{
  cout << "Nom : " << getNom() << endl;
  cout << "Puissance : " << getPuissance() << endl;

  cout << "Moteur : ";
  switch(getMoteur())
  {
    case Essence:
      cout << "Essence";
      break;
    case Diesel:
      cout << "Diesel";
      break;
    case Electrique:
      cout << "Electrique";
      break;
    case Hybride:
      cout << "Hybride";
      break;
  }
  cout << endl;

  cout << "Prix : " << getPrixDeBase() << endl << endl; 
}



