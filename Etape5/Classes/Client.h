#ifndef CLIENT_H
#define CLIENT_H

#include "Intervenant.h"
#include <iostream>

using namespace std;

class Client : public Intervenant
{
	friend ostream& operator<<(ostream&, Client&);

private:
	string gsm;
public:
	Client();
	Client(string, string, int, string);
	Client(Client&);

	~Client();

	void setGsm(string);

	string getGsm() const;

	string Tuple();
	string ToString();

	Client& operator=(Client&);
};

#endif