#ifndef CONTRAT_H
#define CONTRAT_H

#include "Client.h"
#include "Employe.h"

#include <iostream>

using namespace std;

class Contrat
{
private:
	Client& clientRef;
	Employe& employeRef;
	string nom;
public:
	Contrat();
	Contrat(Employe&, Client&, string);
	Contrat(const Contrat&);

	~Contrat();

	void setClientRef(Client&);
	void setEmployeRef(Employe&);
	void setNom(string);

	Client& getClientRef() const;
	Employe& getEmployeRef() const;
	string getNom() const;
};

#endif