#include "Client.h"

//---------------------  CONSTRUCTEURS --------------------------------

Client::Client() : Intervenant()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut ! (Client)" << endl;
	#endif

	setGsm("gsm");
}

Client::Client(string n, string p, int num, string g) : Intervenant(num, n, p)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation ! (Client)" << endl;
	#endif

	setGsm(g);
}

Client::Client(const Client& c) : Intervenant(c)
{
	#ifdef DEBUG
		cout << "Constructeur de copie ! (Client)" << endl;
	#endif

	setNumero(c.getNumero());
	setNom(c.getNom());
	setPrenom(c.getPrenom());
	setGsm(c.getGsm());
}

//---------------------  DESTRUCTEUR  ----------------------------------

Client::~Client()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Client)" << endl;
	#endif
}

//---------------------  SETTERS ET GETTERS  ---------------------------

void Client::setGsm(string g)
{
	gsm = g;
}

string Client::getGsm() const
{
	return gsm;
}

//-------------------- AUTRES METHODES  --------------------------------

string Client::Tuple()
{
	char res[80];
	string resultat;

	sprintf(res, "%d;%s;%s;%s", getNumero(), getNom().c_str(), getPrenom().c_str(), getGsm().c_str());
	resultat = res;

	return resultat;
	
}

string Client::ToString()
{
	char res[80];
	string resultat;

	sprintf(res, "[C%d] %s %s", getNumero(), getNom().c_str(), getPrenom().c_str());
	resultat = res;

	return resultat;
}

//--------------------  OPERATEURS  ------------------------------------

Client& Client::operator=(const Client& c)
{
	Personne::setNom(c.Personne::getNom());
	Personne::setPrenom(c.Personne::getPrenom());
	Intervenant::setNumero(c.Intervenant::getNumero());
	setGsm(c.getGsm());

	return (*this);
}

ostream& operator<<(ostream& s, const Client& c)
{
	s << c.getPrenom() << " " << c.getNom() << "(" << c.getNumero() << ", " << c.getGsm() << ")";

	return s;
}