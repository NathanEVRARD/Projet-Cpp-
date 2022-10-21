#ifndef MODELE_H
#define MODELE_H

#include <iostream>
#include <cstring>
    
using namespace std;

enum Moteur {Essence, Diesel, Electrique, Hybride};

class Modele
{
private:
  char *nom;
  int puissance;
  enum Moteur moteur;
  float prix;

public:
  //---------------  CONSTRUCTEURS  ---------------------------------------

  Modele(void);
  Modele(char const *temp, int puissance, enum Moteur moteur, float prix);
  Modele(const Modele& m);

  //---------------  DESTRUCTEUR  -----------------------------------------

  ~Modele();

  //---------------  SETTERS ET GETTERS  ----------------------------------

  void setNom(char const *n);
  void setPuissance(int p);
  void setMoteur(enum Moteur m);
  void setPrixDeBase(float p);

  char *getNom() const;
  int getPuissance() const;
  enum Moteur getMoteur() const;
  float getPrixDeBase() const;

  //--------------- OPERATEURS  ------------------------------------------

  

  //---------------  AUTRES METHODES  -------------------------------------

  void Affiche() const;


};
#endif