#include "Contrat.h"

int Contrat::numCourant = 1;

//---------------  CONSTRUCTEURS  -------------------------

Contrat::Contrat()
{
	#ifdef DEBUG
		cout << "Contructeur par défaut ! (Contrat)" << endl;
	#endif

	setNom("nom");
	setNumero(0);
	employeRef = NULL;
	clientRef = NULL;
}

Contrat::Contrat(Employe& e, Client& c, string n, int num)
{
	#ifdef DEBUG
		cout << "Contructeur d'initialisation ! (Contrat)" << endl;
	#endif


	employeRef = NULL;
	clientRef = NULL;
	setNom(n);
	setEmployeRef(e);
	setClientRef(c);
	setNumero(num);
}

Contrat::Contrat(const Contrat& c)
{
	#ifdef DEBUG
		cout << "Contructeur de copie ! (Contrat)" << endl;
	#endif

	employeRef = NULL;
	clientRef = NULL;

	setNom(c.getNom());
	setEmployeRef(*(c.getEmployeRef()));
	setClientRef(*(c.getClientRef()));
	setNumero(c.getNumero());
}

//--------------------  DESTRUCTEUR  ------------------------

Contrat::~Contrat()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Contrat)" << endl;
	#endif

	if(employeRef != NULL)
		delete employeRef;
	if(clientRef != NULL)
		delete clientRef;
}

//--------------------  SETTERS ET GETTERS ----------------------

void Contrat::setNom(string n)
{
	nom = n;
}

void Contrat::setEmployeRef(const Employe& e)
{
	if(employeRef != NULL)
		delete employeRef;
	employeRef = new Employe(e);
}

void Contrat::setClientRef(const Client& c)
{
	if(clientRef != NULL)
		delete clientRef;
	clientRef = new Client(c);
}

void Contrat::setNumero(int n)
{
	numero = n;
}

string Contrat::getNom() const
{
	return nom;
}

Employe* Contrat::getEmployeRef() const
{
	return employeRef;
}

Client* Contrat::getClientRef() const
{
	return clientRef;
}

int Contrat::getNumero() const
{
	return numero;
}
//---------------------  OPERATEURS  ---------------------------

Contrat& Contrat::operator=(const Contrat& c)
{
	setNom(c.getNom());
	setEmployeRef(*(c.getEmployeRef()));
	setClientRef(*(c.getClientRef()));

	return (*this);
}

ostream& operator<<(ostream& s, const Contrat& c)
{
	s << "Numéro du contrat : " << c.getNumero() << endl << " Employé : " << c.getEmployeRef()->getNom() << " " << c.getEmployeRef()->getPrenom() << endl << c.getClientRef()->getNom() << " " << c.getClientRef()->getPrenom() << endl << "Nom du contrat : " << c.getNom() << endl;

	return s;
}