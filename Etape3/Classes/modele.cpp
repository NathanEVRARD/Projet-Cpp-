#include "modele.h"

//---------------  CONSTRUCTEURS  ---------------------------------------

Modele::Modele(void) // Par défaut
{
  #ifdef DEBUG
  cout << "Constructeur défaut !" << endl << endl;
  #endif
  nom = NULL;
  setNom("nom");
  setPuissance(0);
  setMoteur(Essence);
  setPrixDeBase(0.0f);
}

Modele::Modele(char const *temp, int puissance, enum Moteur moteur, float prix) // D'initialisation
{
  #ifdef DEBUG
  cout << "Constructeur initialisation ! (Modele)" << endl << endl;
  #endif
  nom = NULL;

  setNom(temp);
  setPuissance(puissance);
  setMoteur(moteur);
  setPrixDeBase(prix);
}

Modele::Modele(const Modele& m) // De copie
{
  #ifdef DEBUG
  cout << "Constructeur de copie ! (Modele)" << endl << endl;
  #endif

  nom = NULL;
  setNom(m.getNom());
  setPuissance(m.getPuissance());
  setMoteur(m.getMoteur());
  setPrixDeBase(m.getPrixDeBase());
}

//---------------  DESTRUCTEUR  -----------------------------------------

Modele::~Modele()
{
  #ifdef DEBUG
  cout << endl << "Destructeur ! (Modele)" << endl << endl;
  #endif
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
  if(p < 0) return;

  puissance = p;
}

void Modele::setMoteur(enum Moteur m)
{
  if(m < 0 || m > 3) return;

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

//---------------  OPERATEURS  ------------------------------------------



//---------------  AUTRES METHODES  -------------------------------------

void Modele::Affiche() const
{
  if(nom != NULL)
    cout << getNom();
  cout << "(" << getPuissance() << ", ";

  switch(getMoteur())
  {
    case 0:
      cout << "Essence";
      break;
    case 1:
      cout << "Diesel";
      break;
    case 2:
      cout << "Electrique";
      break;
    case 3:
      cout << "Hybride";
      break;

    default:
      cout << "Moteur";
      break;
  }
  cout << ", ";

  cout << getPrixDeBase() << ")" << endl << endl; 
}



