#ifndef MODELE_H
#define MODELE_H

#include <iostream>
#include <cstring>
#include <fstream>
    
using namespace std;

enum Moteur {Essence, Diesel, Electrique, Hybride};

class Modele
{
  friend istream& operator>>(istream& s, Modele& m);
  friend ostream& operator<<(ostream& s, Modele& m);

private:
  char *nom;
  int puissance;
  enum Moteur moteur;
  float prix;
  string image;

public:
  //---------------  CONSTRUCTEURS  ---------------------------------------

  Modele(void);
  Modele(char const *temp, int puissance, enum Moteur moteur, float prix, string image);
  Modele(const Modele& m);

  //----------------  DESTRUCTEUR  ----------------------------------------

  ~Modele();

  //---------------  SETTERS ET GETTERS  ----------------------------------

  void setNom(char const *n);
  void setPuissance(int p);
  void setMoteur(enum Moteur m);
  void setPrixDeBase(float p);
  void setImage(string i);

  char *getNom() const;
  int getPuissance() const;
  enum Moteur getMoteur() const;
  float getPrixDeBase() const;
  string getStrMoteur() const;
  string getImage() const;

  //--------------- OPERATEURS  ------------------------------------------

  

  //---------------  AUTRES METHODES  -------------------------------------

  void Affiche() const;
  void Save(ofstream&) const;
  void Load(ifstream&);


};
#endif