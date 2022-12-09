#ifndef VOITURE_H
#define VOITURE_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "Modele.h"
#include "Option.h"

#define NBR_OPTIONS 5

using namespace std;

class Voiture
{
  friend Voiture operator+(const Option& o, const Voiture& v);
  friend ostream& operator<<(ostream& s, Voiture& v);

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

  string getNom() const;
  Modele getModele() const;
  Option getOption() const;
  float getPrix() const;

  Voiture& operator=(const Voiture&);
  Voiture operator+(const Option& o);
  Voiture operator-(const string s);
  Voiture operator-(const Option& o);
  int operator<(const Voiture&);
  int operator>(const Voiture&);
  int operator==(const Voiture&);
  Option* operator[](int); // Recherche options n°i

  void AjouteOption(const Option&);
  void RetireOption(string);
  void Affiche();
  void Save()const;
  void Load(string);
};

#endif