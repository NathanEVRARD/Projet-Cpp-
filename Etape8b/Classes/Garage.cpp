#include "Garage.h"

Garage Garage::instance;
Voiture Garage::projetEnCours;
//----------------------  CONSTRUCTEUR  -------------------------------

Garage::Garage()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut ! (Garage)" << endl;
	#endif
}

//----------------------  DESTRUCTEUR  --------------------------------

Garage::~Garage()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Garage)" << endl;
	#endif
}

//----------------------  METHODES MODELE  ----------------------------

void Garage::ajouteModele(const Modele& m)
{
	modeles.insere(m);
}

void Garage::afficheModelesDisponibles() const
{
	Iterateur<Modele> it(modeles);
	Modele m;

	for(it.reset(); !it.end(); it++)
	{
		m = (Modele)it;
		cout << m << endl;
	}
}

Modele Garage::getModele(int indice)
{
	Iterateur<Modele> it(modeles);
	Modele m;
	int i;

	for(it.reset(), i = 0; !it.end() && i != indice; it++, i++);

	if(i == indice)
		m = (Modele)it;
	else
		cout << "Indice non existant !";

	return m;
}

//--------------------  METHODES OPTION  -------------------------------

void Garage::ajouteOption(const Option& o)
{
	options.insere(o);
}

void Garage::afficheOptionsDisponibles() const
{
	Iterateur<Option> it(options);
	Option o;

	for(it.reset(); !it.end(); it++)
	{
		o = (Option)it;
		cout << o << endl;
	}
}

Option Garage::getOption(int indice)
{
	Iterateur<Option> it(options);
	Option o;
	int i;

	for(it.reset(), i = 0; !it.end() && i != indice; it++, i++);

	if(i == indice)
		o = (Option)it;
	else
		cout << "Indice non existant";

	return o;
}

//--------------------  METHODES CLIENT  --------------------------

void Garage::ajouteClient(string nom, string prenom, string gsm)
{
	Client c(nom, prenom, 0, gsm);
	clients.insere(c);
}

void Garage::afficheClients() const
{
	Iterateur<Client> it(clients);
	Client c;

	for(it.reset(); !it.end(); it++)
	{
		c = (Client)it;
		cout << c << endl;
	}
}

void Garage::supprimeClientParIndice(int ind)
{
	clients.retire(ind);
}

void Garage::supprimeClientParNumero(int num)
{
	Iterateur<Client> it(clients);
	int i;

	for(it.reset(), i = 0; !it.end() && ((Client)it).getNumero() != num; it++, i++);

	if(((Client)it).getNumero() == num)
		clients.retire(i);
}

//-------------------------  METHODES EMPLOYES  ---------------------------------

void Garage::ajouteEmploye(string nom, string prenom, string login, string fonction)
{
	Employe e(nom, prenom, 0, login, fonction);
	employes.insere(e);
}

void Garage::afficheEmployes() const
{
	Iterateur<Employe> it(employes);
	Employe e;

	for(it.reset(); !it.end(); it++)
	{
		e = (Employe)it;
		cout << e << endl;
	}
}

void Garage::supprimeEmployeParIndice(int ind)
{
	employes.retire(ind);
}

void Garage::supprimeEmployeParNumero(int num)
{
	Iterateur<Employe> it(employes);
	int i;

	for(it.reset(), i = 0; !it.end() && ((Employe)it).getNumero() != num; it++, i++);

	if(((Employe)it).getNumero() == num)
		employes.retire(i);
}

//------------------------  FONCTIONS STATIQUES  -------------------------

Garage& Garage::getInstance()
{
	return instance;
}

Voiture& Garage::getProjetEnCours()
{
	return projetEnCours;
}

void Garage::resetProjetEnCours()
{
	Voiture v;
	int i;

	projetEnCours = v;
}