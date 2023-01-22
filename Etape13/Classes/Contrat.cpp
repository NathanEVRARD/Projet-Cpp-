#include "Contrat.h"

//---------------  CONSTRUCTEURS  -------------------------

Contrat::Contrat()
{
	#ifdef DEBUG
		cout << "Contructeur par défaut ! (Contrat)" << endl;
	#endif

	setNom("nom");
	setEmployeRef(NULL);
	setClientRef(NULL);
}

Contrat::Contrat(Employe& e, Client& c, string n)
{
	#ifdef DEBUG
		cout << "Contructeur d'initialisation ! (Contrat)" << endl;
	#endif

	setNom(n);
	setEmployeRef(e);
	setClientRef(c);
}

Contrat::Contrat(const Contrat& c)
{
	#ifdef DEBUG
		cout << "Contructeur de copie ! (Contrat)" << endl;
	#endif

	setNom(c.getNom());
	setEmployeRef(c.getEmployeRef());
	setClientRef(c.getClientRef());
}

//--------------------  DESTRUCTEUR  ------------------------

Contrat::~Contrat()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Contrat)" << endl;
	#endif
}

//--------------------  SETTERS ET GETTERS ----------------------

void setNom(string n)
{
	nom = n;
}

void setEmployeRef(Employe& e)
{
	employeRef = e;
}

void setClientRef(Client& c)
{
	clientRef = c;
}

string getNom() const
{
	return nom;
}

Employe& getEmployeRef() const
{
	return employeRef;
}

Client& getClientRef() const
{
	return clientRef;
}