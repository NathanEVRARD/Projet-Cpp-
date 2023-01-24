#include "Contrat.h"
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

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

string Contrat::Tuple() const
{
	string tuple =  to_string(Contrat::getNumero()) + ";" + getEmployeRef()->getNom() + " " + getEmployeRef()->getPrenom() + ";" + getClientRef()->getNom() + " " + getClientRef()->getPrenom() + ";" + Contrat::getNom();

	return tuple;
}

void Contrat::Save(ofstream &fichier)
{
	cout<<"<<Save de Contrat>>"<<endl;
	if(fichier.is_open())
	{
		int n;

		fichier.write((char *)&numero,sizeof(int));

		n = getEmployeRef()->getNumero();
		fichier.write((char *)&n,sizeof(int)); // Numéro du vendeur
		n = getClientRef()->getNumero();

		fichier.write((char *)&n,sizeof(int)); // Numéro du client

		n = getNom().size();
		fichier.write((char *)&n,sizeof(int)); // Taille du nom du projet
		fichier.write((char *)nom.data(),sizeof(char)*n);// Nom du projet
	}
}	

void Contrat::Load(ifstream &fichier)
{	
	cout<<"<<Load de Contrat>>"<<endl;
	if(fichier.is_open())
	{
		// récupération info vendeur
		int num;
		fichier.read((char *)&numero,sizeof(int));
		fichier.read((char *)&num,sizeof(int)); // Numéro du vendeur
		employeRef = new Employe;
		getEmployeRef()->setNumero(num);
		
		// récupération info client
		fichier.read((char *)&num,sizeof(int)); // Numéro du client
		clientRef = new Client;
		getClientRef()->setNumero(num);

		// récupération nom projet
		int taille;
		string chaine;
		fichier.read((char*)&taille,sizeof(int));
		chaine.resize(taille);
		fichier.read((char *)chaine.data(),sizeof(char)*taille);
		setNom(chaine);

	}
}
//---------------------  OPERATEURS  ---------------------------

Contrat& Contrat::operator=(const Contrat& c)
{
	setNom(c.getNom());
	setEmployeRef(*(c.getEmployeRef()));
	setClientRef(*(c.getClientRef()));
	setNumero(c.getNumero());

	return (*this);
}

ostream& operator<<(ostream& s, const Contrat& c)
{
	s << "Numéro du contrat : " << c.getNumero() << endl << " Employé : " << c.getEmployeRef()->getNom() << " " << c.getEmployeRef()->getPrenom() << endl << c.getClientRef()->getNom() << " " << c.getClientRef()->getPrenom() << endl << "Nom du contrat : " << c.getNom() << endl;

	return s;
}