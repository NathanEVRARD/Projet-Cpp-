#ifndef INTERVENANT_H
#define INTERVENANT_H

#include <iostream>
using namespace std;
#include "Personne.h"

class Intervenant : public Personne
{
protected:
	int numero;
public:
	static int numCourant;

	Intervenant();
	Intervenant(int, string, string);
	Intervenant(const Intervenant&);

	virtual ~Intervenant();

	void setNumero(int);

	int getNumero() const;

	virtual string Tuple() = 0;
	virtual string ToString() = 0;

	Intervenant& operator=(Intervenant&);
};

#endif