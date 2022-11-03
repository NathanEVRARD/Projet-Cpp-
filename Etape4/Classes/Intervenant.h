#ifndef INTERVENANT_H
#define INTERVENANT_H

#include <iostream>
#include "Personne.h"

using namespace std;

class Intervenant : public Personne
{
protected:
	int numero;
public:
	Intervenant();
	Intervenant(int, string, string);
	Intervenant(Intervenant&);

	~Intervenant();

	void setNumero(int);

	int getNumero() const;

	virtual string Tuple() = 0;
	virtual string ToString() = 0;

	Intervenant& operator=(Intervenant&);
};

#endif