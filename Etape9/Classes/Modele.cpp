#include "Modele.h"

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

Modele::Modele(char const *temp, int puissance, enum Moteur moteur, float prix, string image) // D'initialisation
{
  #ifdef DEBUG
  cout << "Constructeur initialisation ! (Modele)" << endl << endl;
  #endif
  nom = NULL;

  setNom(temp);
  setPuissance(puissance);
  setMoteur(moteur);
  setPrixDeBase(prix);
  setImage(image);
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
  setImage(m.getImage());
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

void Modele::setImage(string i)
{
  image = i;
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

string Modele::getStrMoteur() const
{
  string s;

  switch(getMoteur())
  {
    case 0:
      s = "Essence";
      break;
    case 1:
      s = "Diesel";
      break;
    case 2:
      s = "Electrique";
      break;
    case 3:
      s = "Hybride";
      break;

    default:
      s = "Moteur";
      break;
  }

  return s;
}

string Modele::getImage() const
{
  return image;
}
//----------------  OPERATEURS  ------------------------------------

istream& operator>>(istream& s, Modele& m)
{
  char nomTemp[30];
  int puissanceTemp;
  int moteurTemp;
  float prixTemp;

  cout << "Saisissez le nom du modele : "; s >> nomTemp;
  cout << "Saisissez la puissance du modele : "; s >> puissanceTemp;
  cout << "Saisissez le moteur du modele :" << endl << "(0)-> Essence" << endl << "(1)-> Diesel" << endl << "(2)-> Electrique" << endl << "(3)-> Hybride" << endl << endl << "Votre choix : "; s >> moteurTemp;
  cout << "Saisissez le prix de base du modele : "; s >> prixTemp;

  m.setNom(nomTemp);
  m.setPuissance(puissanceTemp);
  m.setMoteur((enum Moteur)moteurTemp);
  m.setPrixDeBase(prixTemp);

  return s;
}

ostream& operator<<(ostream& s, Modele& m)
{
  s << m.getNom() << "(" << m.getPuissance() << ", " << m.getStrMoteur() << ", " << m.getPrixDeBase() << ")" << endl;

  return s;
}

//---------------  AUTRES METHODES  -------------------------------------

void Modele::Affiche() const
{
  if(nom != NULL)
    cout << getNom();
  cout << "(" << getPuissance() << ", ";

  cout << getStrMoteur();
  cout << ", ";

  cout << getPrixDeBase() << ")" << endl << endl; 
}

void Modele::Save(ofstream& fichier) const
{
  int nomLength = strlen(getNom());
  int imageLength = getImage().size();

  if(fichier.is_open())
  {
    fichier.write((char*)&nomLength, sizeof(int));
    fichier.write(nom, strlen(getNom()));
    fichier.write((char*)&puissance, sizeof(int));
    fichier.write((char*)&moteur, sizeof(enum Moteur));
    fichier.write((char*)&prix, sizeof(float));
    fichier.write((char*)&imageLength, sizeof(int));
    fichier.write((char*)getImage().data(), sizeof(char)*imageLength);
  }
}

void Modele::Load(ifstream& fichier)
{
  int nomLength, imageLength;

  if(fichier.is_open())
  {
    fichier.read((char*)&nomLength, sizeof(int));
    fichier.read(nom, nomLength);
    fichier.read((char*)&puissance, sizeof(int));
    fichier.read((char*)&moteur, sizeof(enum Moteur));
    fichier.read((char*)&prix, sizeof(float));  
    fichier.read((char*)&imageLength, sizeof(int));
    image.resize(imageLength);
    fichier.read((char*)image.data(), sizeof(char)*imageLength);
  }

  
}



