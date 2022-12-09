#ifndef VECTEURTRIE_H
#define VECTEURTRIE_H

#include <iostream>
#include <cstring>
#include "Vecteur.h"

using namespace std;

template <class T> class VecteurTrie : public Vecteur<T>
{
public:
	VecteurTrie();
	VecteurTrie(int);
	VecteurTrie(const VecteurTrie<T>&);

	~VecteurTrie();

	void insere(const T&);
};

#endif