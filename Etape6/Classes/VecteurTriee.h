#ifndef VECTEURTRIEE_H
#define VECTEURTRIEE_H

#include <iostream>
#include <cstring>
#include "Vecteur.h"

using namespace std;

template <class T> class VecteurTriee : public Vecteur<T>
{
public:
	VecteurTriee();
	VecteurTriee(int);
	VecteurTriee(VecteurTriee&);

	~VecteurTriee();

	void insere(const Client&);
	void insere(const int&);
};

#endif