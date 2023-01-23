#ifndef CONTRAT_H
#define CONTRAT_H

#include "Client.h"
#include "Employe.h"

#include <iostream>

using namespace std;

class Contrat
{
private:
	int numero;
	Client* clientRef;
	Employe* employeRef;
	string nom;
public:
	static int numCourant;
	friend ostream& operator<<(ostream&, const Contrat&);

	Contrat();
	Contrat(Employe&, Client&, string, int);
	Contrat(const Contrat&);

	~Contrat();

	void setClientRef(const Client&);
	void setEmployeRef(const Employe&);
	void setNom(string);
	void setNumero(int);

	Client* getClientRef() const;
	Employe* getEmployeRef() const;
	string getNom() const;
	int getNumero() const;

	Contrat& operator=(const Contrat&);

};

#endif