#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
#include <string>
#include "Iterateur.h"
#include "VecteurTrie.h"
#include "Vecteur.h"
#include "Client.h"
#include "Modele.h"
#include "Option.h"
#include "Employe.h"
#include "Voiture.h"
#include "Contrat.h"
using namespace std;

class Garage
{
private:
	Garage();
	Garage(const Garage&);

	Garage& operator=(const Garage&);

	static Garage instance;
	static Voiture projetEnCours;

	VecteurTrie<Employe> employes;
	VecteurTrie<Client> clients;
	Vecteur<Modele> modeles;
	Vecteur<Option> options;
	Vecteur<Contrat> contrats;

public:
	static Garage& getInstance();
	static Voiture& getProjetEnCours();
	static void resetProjetEnCours();
	static Employe* employeLogged;

	~Garage();

	void ajouteModele(const Modele& m);
	void afficheModelesDisponibles() const;
	Modele getModele(int indice);

	void ajouteOption(const Option& o);
	void afficheOptionsDisponibles() const;
	Option getOption(int indice);

	void ajouteClient(string nom, string prenom, string gsm);
	void afficheClients() const;
	void supprimeClientParIndice(int ind);
	void supprimeClientParNumero(int num);
	VecteurTrie<Client>& getClients();

	void ajouteEmploye(string nom, string prenom, string login, string fonction);
	void afficheEmployes() const;
	void supprimeEmployeParIndice(int ind);
	void supprimeEmployeParNumero(int num);
	VecteurTrie<Employe>& getEmployes();

	void ajouteContrat(const Contrat&);

	void importeModeles(string);
	void importeOptions(string);

	int nbModeles();
	int nbOptions();

	void Save(ofstream&);
	void Load(ifstream&);
};

#endif