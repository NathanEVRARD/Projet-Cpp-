#include "Employe.h"
#include "Intervenant.h"
#include "PasswordException.h"
#include <iostream>
#include <string>
#include <fstream>


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

Employe::Employe(const Employe& e) : Intervenant(e)
{
	#ifdef DEBUG
		cout << "Constructeur de copie ! (Employe)" << endl;
	#endif

	setLogin(e.getLogin());
	setFonction(e.getFonction());
	if(e.motDePasse != NULL)
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
		PasswordException e("", 1);
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
		PasswordException e("", 2);
		throw e;
	}
	if(!digit)
	{
		PasswordException e1("", 3);
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
		PasswordException e("", 4);
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

void Employe::Save(ofstream & fichier) // Écriture d'un employé dans le fichier passé en paramètre
{
    cout<<"save Employe"<<endl;
    if(fichier.is_open())
    {
        if(numero != 0)
        {
            fichier.write((char *)&numero,sizeof(int));                        // Enregistre le numéro de l'employé 
        
            int tailleNom = nom.size();
            fichier.write((char *)&tailleNom,sizeof(int));                
            fichier.write((char *)nom.data(),sizeof(char) * tailleNom);     // Enregistre le nom de l'employé
            
            int taillePrenom = prenom.size();
            fichier.write((char *)&taillePrenom,sizeof(int));
            fichier.write((char *)prenom.data(),sizeof(char) * taillePrenom);  // Enregistre le prénom de l'employé
            
            int tailleLogin = login.size();
            fichier.write((char *)&tailleLogin,sizeof(int));
            fichier.write((char *)login.data(),sizeof(char)*tailleLogin);    // Enregistre le login de l'employé
            
            int verif;

            if(motDePasse == NULL)
            {    
            	cout << "Mot de passe non defini" << endl;
                verif = 0;
                fichier.write((char *)&verif,sizeof(int));
           	}
            else
            {	
            	cout << "Mot de passe defini" << endl;

                verif = 1;
                fichier.write((char *)&verif,sizeof(int));
                int tailleMotDePasse = motDePasse->size();
                fichier.write((char *)&tailleMotDePasse,sizeof(int));
                string mdp = *motDePasse;
                fichier.write((char *)mdp.data(),sizeof(char)*tailleMotDePasse); // Enregistre le mot de passe de l'employé
            }

            int tailleFonction = fonction.size();
            fichier.write((char *)&tailleFonction,sizeof(int));
            fichier.write((char *)fonction.data(),sizeof(char) * tailleFonction); //Enregistre la fonction de l'employé 
                
        }
        
    }
}

void Employe::Load(ifstream &fichier) // Lecture d'un employé dans le fichier passé en paramètre.
{
    cout<<"load Employe"<<endl;
    if(fichier.is_open())
    {
        //récupère le numéro de l'employé
        fichier.read((char*)&numero,sizeof(int));
        
        // récupère le nom de l'employé
        int tailleNom;
        fichier.read((char *)&tailleNom , sizeof(int));
        nom.resize(tailleNom);
        fichier.read((char *)nom.data(),sizeof(char) * tailleNom);
        
        // récupère le numéro de l'employé
        int taillePrenom;
        fichier.read((char *)&taillePrenom,sizeof(int));
        prenom.resize(taillePrenom);
        fichier.read((char *)prenom.data(),sizeof(char)*taillePrenom);
        
        // récupère le login de l'employé
        int tailleLogin;
        fichier.read((char *)&tailleLogin,sizeof(int));
        login.resize(tailleLogin);
        fichier.read((char *)login.data(),sizeof(char)*tailleLogin);
        
        //récupère le mot de passe
        int verif;
        fichier.read((char *)&verif,sizeof(int));
        if(verif)
        {
            int tailleMotDePasse;
            string mdp;
            fichier.read((char *)&tailleMotDePasse,sizeof(int));
            mdp.resize(tailleMotDePasse);
            fichier.read((char *)mdp.data(),sizeof(char)*tailleMotDePasse);
            setMotDePasse(mdp);
        }

        //récupère la fonction de l'employé
        int tailleFonction;
        fichier.read((char *)&tailleFonction,sizeof(int));
        fonction.resize(tailleFonction);
        fichier.read((char *)fonction.data(),sizeof(char) * tailleFonction);
    }
}


//---------------------  OPERATEURS  ------------------------

Employe& Employe::operator=(const Employe& e)
{
	setNumero(e.getNumero());
	setNom(e.getNom());
	setPrenom(e.getPrenom());
	setLogin(e.getLogin());
	setFonction(e.getFonction());
	if(e.motDePasse != NULL)
		setMotDePasse(e.getMotDePasse());

	return (*this);
}

ostream& operator<<(ostream& s, Employe& e)
{
	s << e.getPrenom() << " " << e.getNom() << "(" << e.getNumero() << ", " << e.getLogin() << ", "  << e.getFonction() <<")";

	return s;
}