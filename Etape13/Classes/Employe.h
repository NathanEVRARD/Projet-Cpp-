#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <iostream>
#include "Intervenant.h"

using namespace std;

class Employe : public Intervenant
{
	friend ostream& operator<<(ostream&, Employe&);
	
private:
	string login;
	string *motDePasse = NULL;
	string fonction;
	

public:
	static string ADMINISTRATIF;
	static string VENDEUR;

	Employe();
	Employe(string, string, int, string, string);
	Employe(const Employe&);

	~Employe();

	void setLogin(string);
	void setMotDePasse(string);
	void setFonction(string);

	string getLogin() const;
	string getMotDePasse() const;
	string getFonction() const;

	void resetMotDePasse();
	string Tuple();
	string ToString();

	Employe& operator=(const Employe&);

	void Save(ofstream&);
	void Load(ifstream&);
};

#endif