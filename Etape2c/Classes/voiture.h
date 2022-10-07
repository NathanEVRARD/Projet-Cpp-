#ifndef VOITURE_H
#define VOITURE_H

#include <iostream>
#include <cstring>
#include "modele.h"
#include "option.h"

using namespace std;

class Voiture
{
private:
  string nomProjet;
  Modele modele;
  Option *options[5];
public:
  Voiture(void);
  Voiture(string, Modele);

  Voiture(const Voiture&);

  ~Voiture();

  void setNom(string);
  void setModele(Modele);
  void setOption(Option*);

  string getNom() const;
  Modele getModele() const;
  Option getOption() const;
  float getPrix() const;

  void AjouteOption(const Option&);
  void RetireOption(string);
  void Affiche();
};

#endif