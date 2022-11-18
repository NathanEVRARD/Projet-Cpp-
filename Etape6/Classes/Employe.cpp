#include "Employe.h"
#include "Intervenant.h"
#include "PasswordException.h"

string Employe::VENDEUR = "VENDEUR";
string Employe::ADMINISTRATIF = "ADMINISTRATIF";

//---------------------  CONSTRUCTEURS  -------------------------------

Employe::Employe() : Intervenant()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut ! (Employe)" << endl;
	#endif

	setLogin("Login");
	setFonction("Fonction");
	resetMotDePasse();
}

Employe::Employe(string n, string p, int num, string l, string f) : Intervenant(num, n, p)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation' ! (Employe)" << endl;
	#endif

	setLogin(l);
	setFonction(f);
	resetMotDePasse();
}

Employe::Employe(Employe& e)
{
	#ifdef DEBUG
		cout << "Constructeur de copie ! (Employe)" << endl;
	#endif

	setNumero(e.getNumero());
	setNom(e.getNom());
	setPrenom(e.getPrenom());
	setLogin(e.getLogin());
	setFonction(e.getFonction());
	setMotDePasse(e.getMotDePasse());
}

//---------------------  DESTRUCTEUR  ----------------------------

Employe::~Employe()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Employe)" << endl;
	#endif

	resetMotDePasse();
}

//---------------------  SETTERS ET GETTERS  ---------------------

void Employe::setLogin(string l)
{	
	login = l;
}

void Employe::setFonction(string f)
{
	fonction = f;
}

void Employe::setMotDePasse(string m)
{
	int i, alpha = 0, digit = 0;

	if(m.length() < 6)
	{
		PasswordException e(1);
		throw e;
	}

	for(i = 0; i < m.length(); i++)
	{
		if(((int)m[i] < 123 && (int)m[i] > 96) || ((int)m[i] < 91 && (int)m[i] > 64))
			alpha = 1;

		if(((int)m[i] < 58 && (int)m[i] > 47))
			digit = 1;
	}

	if(!alpha)
	{
		PasswordException e(2);
		throw e;
	}
	if(!digit)
	{
		PasswordException e1(3);
		throw e1;
	}

	if(!motDePasse)
		motDePasse = new string;

	*motDePasse = m;
}

string Employe::getLogin() const
{
	return login;
}

string Employe::getMotDePasse() const
{
	if(!motDePasse)
	{
		PasswordException e(4);
		throw e;
	}
	return (*motDePasse);
}

string Employe::getFonction() const
{
	return fonction;
}

//--------------- AUTRES METHODES  ------------------------

void Employe::resetMotDePasse()
{
	if(motDePasse != NULL)
		delete motDePasse;
	motDePasse = NULL;
}

string Employe::ToString()
{
	char res[80];
	string resultat;

	sprintf(res, "[V%d] %s %s", getNumero(), getNom().c_str(), getPrenom().c_str());
	resultat = res;

	return resultat;
}

string Employe::Tuple()
{
	char res[80];
	string resultat;

	sprintf(res, "%d;%s;%s;%s", getNumero(), getNom().c_str(), getPrenom().c_str(), getFonction().c_str());
	resultat = res;

	return resultat;
}


//---------------------  OPERATEURS  ------------------------

Employe& Employe::operator=(Employe& e)
{
	setNumero(e.getNumero());
	setNom(e.getNom());
	setPrenom(e.getPrenom());
	setLogin(e.getLogin());
	setFonction(e.getFonction());
	setMotDePasse(e.getMotDePasse());

	return (*this);
}

ostream& operator<<(ostream& s, Employe& e)
{
	s << e.getPrenom() << " " << e.getNom() << "(" << e.getNumero() << ", " << e.getLogin() << ", "  << e.getFonction() <<")";

	return s;
}