#ifndef ITERATETR_H
#define ITERATETR_H

#include "Vecteur.h"
#include <iostream>

using namespace std;

template <class T> class Iterateur
{
private:
	Vecteur<T>& vec;
	T * pCur;

public:
	Iterateur(Vecteur<T>&);

	~Iterateur();

	void reset();
	bool end();
	bool operator++(int);
	operator T() const;
};

#endif