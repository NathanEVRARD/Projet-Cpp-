#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include <cstring>

using namespace std;

class Option
{
	friend istream& operator>>(istream& s, Option o);
	friend ostream& operator<<(ostream& s, Option o);

private:
	string code;
	string intitule;
	float prix;
public:
	Option();
	Option(string, string, float);
	Option(const Option&);

	~Option();

	void setCode(string);
	void setIntitule(string);
	void setPrix(float);

	string getCode(void) const;
	string getIntitule(void) const;
	float getPrix(void) const;

	Option operator--();
	Option operator--(int);

	void Affiche(void) const;
};

#endif