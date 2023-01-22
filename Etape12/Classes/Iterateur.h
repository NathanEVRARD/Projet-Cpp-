#ifndef ITERATEUR_H
#define ITERATEUR_H

#include "Vecteur.h"
#include <iostream>
using namespace std;

template <class T> class Iterateur
{
private:
	const Vecteur<T>& vec;
	T * pCur;

public:
	Iterateur(const Vecteur<T>&);

	~Iterateur();

	void reset();
	bool end();
	bool operator++(int);
	operator T() const;
};

#endif