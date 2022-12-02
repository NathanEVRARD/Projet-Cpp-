#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
using namespace std;

template <class T> class Iterateur;

template<class T> class Vecteur
{
protected:
	T * v;
	int _sizeMax;
	int _size;
public:
	Vecteur();
	Vecteur(int);
	Vecteur(const Vecteur<T>&);

	virtual ~Vecteur();

	int size() const;
	int sizeMax() const;

	Vecteur& operator=(const Vecteur&);
	const T& operator[](int);

	virtual void insere(const T&);
	T retire(int);

	void Affiche() const;

	friend class Iterateur<T>;

};

#endif