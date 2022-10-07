#ifndef VOITURE_H
#define VOITURE_H

#include <iostream>
#include <cstring>
#include "modele.h"

using namespace std;

class Voiture
{
private:
  string nomProjet;
  Modele modele;
public:
  Voiture(void);
  Voiture(string, Modele);

  Voiture(const Voiture&);

  ~Voiture();

  void setNom(string);
  void setModele(Modele);

  string getNom() const;
  Modele getModele() const;

  void Affiche();
};

#endif