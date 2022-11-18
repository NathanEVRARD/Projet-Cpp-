#include "Personne.h"

//--------------  CONSTRUCTEURS  -----------------------------------

Personne::Personne() 
{
	#ifdef DEBUG
		cout << "Constructeur par defaut ! (Personne)" << endl;
	#endif
	setNom("nom");
	setPrenom("prenom");
}

Personne::Personne(string nom, string prenom)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation ! (Personne)" << endl;
	#endif

	setNom(nom);
	setPrenom(prenom);
}

Personne::Personne(const Personne& p)
{
	#ifdef DEBUG
		cout << "Constructeur de copie ! (Personne)" << endl;
	#endif

	setNom(p.getNom());
	setPrenom(p.getPrenom());
}
//--------------------  DESTRUCTEUR  -------------------------------

Personne::~Personne()
{
	#ifdef DEBUG
		cout << "Destructeur ! (Personne)" << endl;
	#endif
}

//------------------- SETTERS ET GETTERS  --------------------------

void Personne::setNom(string n)
{
	transform(n.begin(), n.end(), n.begin(), ::toupper);

	nom = n;
}

void Personne::setPrenom(string p)
{
	p[0] = toupper(p[0]);

	prenom = p;
}

string Personne::getNom() const
{
	return nom;
}

string Personne::getPrenom() const
{
	return prenom;
}

//-------------------  OPERATEURS  -------------------------------

Personne& Personne::operator=(const Personne& p)
{
	setNom(p.getNom());
	setPrenom(p.getPrenom());

	return (*this);
}

ostream& operator<<(ostream& s, Personne& p)
{
	s << p.getPrenom() << " " << p.getNom();

	return s;
}

istream& operator>>(istream& s, Personne& p)
{
	string nom, prenom;

	cout << "Saisissez le nom de la personne : "; s >> nom; p.setNom(nom);
	cout << "Saisissez le preonm de la personne : "; s >> prenom; p.setPrenom(prenom);

	return s;
}
