#include "Garage.h"
#include "PasswordException.h"
#include <cstring>
#include <fstream>

Garage Garage::instance;
Voiture Garage::projetEnCours;
Employe* Garage::employeLogged = NULL;
//----------------------  CONSTRUCTEUR  -------------------------------

Garage::Garage()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut ! (Garage)" << endl;
	#endif

	ajouteEmploye("ADMIN", "ADMIN", "ADMIN", Employe::ADMINISTRATIF);
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
	return modeles[indice];
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
	return options[indice];
}

//--------------------  METHODES CLIENT  --------------------------

void Garage::ajouteClient(string nom, string prenom, string gsm)
{
	clients.insere(Client(nom, prenom, Intervenant::numCourant++, gsm));
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

VecteurTrie<Client>& Garage::getClients()
{
	return clients;
}

//-------------------------  METHODES EMPLOYES  ---------------------------------

void Garage::ajouteEmploye(string nom, string prenom, string login, string fonction)
{
	employes.insere(Employe(nom, prenom, Intervenant::numCourant++, login, fonction));
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

VecteurTrie<Employe>& Garage::getEmployes()
{
	return employes;
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

	projetEnCours = v;
}

//-----------------------  FONCTIONS CSV  ---------------------------------

void Garage::importeModeles(string nomFichier) // permet d'importer des modèles du fichier CSV dans Garage
{
    ifstream fichier(nomFichier);
    string buffer;
    
  	
    if(fichier.is_open())
    {
        while(getline(fichier,buffer))
        {
        	Modele m;
            char phrase[400];
            char nomTemp[50];

          	fflush(stdin);
            strcpy(phrase,buffer.c_str());

            strcpy(nomTemp, strtok(phrase, ";"));
            m.setNom(nomTemp);
            
            m.setPuissance(atoi(strtok(NULL,";")));

            string moteur = strtok(NULL,";");

            if(moteur == "essence")
            {
                m.setMoteur((enum Moteur) 0);
            }
            if(moteur == "diesel")
            {
                m.setMoteur((enum Moteur) 1);
            }
            if(moteur == "electrique")
            {
                m.setMoteur((enum Moteur) 2);
            }
            if(moteur == "hybride")
            {
                m.setMoteur((enum Moteur) 3);
            }

            m.setImage(strtok(NULL,";"));

            m.setPrixDeBase(atof(strtok(NULL,"\n")));

            getInstance().ajouteModele(m);
        }
        fichier.close(); // Fermeture du fichier
    }

}

void Garage::importeOptions(string nomFichier)
{
	ifstream fichier(nomFichier);
    string buffer;
  	
    if(fichier.is_open())
    {
        while(getline(fichier,buffer))
        {
        	Option o;
            char phrase[400];

          	fflush(stdin);
            strcpy(phrase,buffer.c_str());

            o.setCode(strtok(phrase, ";"));
            
            o.setIntitule(strtok(NULL,";"));

            o.setPrix(atof(strtok(NULL, "\n")));

            getInstance().ajouteOption(o);
        }
        fichier.close(); // Fermeture du fichier
    }
}

int Garage::nbModeles()
{
	return modeles.size();
}

int Garage::nbOptions()
{
	return options.size();
}