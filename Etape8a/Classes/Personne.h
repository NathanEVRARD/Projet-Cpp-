#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Personne
{
	friend ostream& operator<<(ostream&, Personne&);
	friend istream& operator>>(istream&, Personne&);

protected:
	string nom;
	string prenom;
public:
	Personne();
	Personne(string nom, string prenom);
	Personne(const Personne&);

	virtual ~Personne();

	void setNom(string);
	void setPrenom(string);

	string getNom() const;
	string getPrenom() const;

	Personne& operator=(const Personne&);
	bool operator>(const Personne&) const;
};

#endif