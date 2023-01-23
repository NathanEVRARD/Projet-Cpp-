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

//-----------------------  METHODES CONTRAT  ----------------------------

void Garage::ajouteContrat(const Contrat& c)
{
    contrats.insere(c);
}

Vecteur<Contrat>& Garage::getContrats()
{
    return contrats;
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

void Garage::Save(ofstream &fichier)
{
    cout << "<<save garage>>"<<endl;
    if(fichier.is_open())
    {
        // Enregistre le numCourant d'employe;
        fichier.write((char *)&Intervenant::numCourant,sizeof(int));

        int nbr = employes.size() - 1;
        fichier.write((char *)&nbr,sizeof(int)); // enregistre le nombre d'employé existant
        
        Iterateur<Employe>itE(employes);
        for(itE.reset();!itE.end();itE++)
        {
            Employe e = (Employe)itE;
            cout<<e<<endl;
            e.Save(fichier); // Enregistre toute les informations relatives au employé
        }
        nbr = clients.size();
        fichier.write((char *)&nbr,sizeof(int)); // Enregistre le nombre de client existant

        if(nbr!=0)
        {
            Iterateur<Client>itC(clients);
            for(itC.reset();!itC.end();itC++)
            {
                Client c = (Client)itC;
                cout<<c<<endl;
                c.Save(fichier); // Enregistre toutes les informations relative au client
            }
        }

        fichier.write((char*)&Contrat::numCourant,sizeof(int)); // Enregistre le numCourant de Contrat

        nbr = contrats.size();
        fichier.write((char *)&nbr,sizeof(int)); // Enregistre le nombre de contrats

        if(nbr!=0)
        {
            Iterateur<Contrat>itC(contrats);
            for(itC.reset();!itC.end();itC++)
            {
                Contrat c((Contrat)itC);
                c.Save(fichier); // Enregistre toutes les informations relative au client
            }
        }

    }    
}
void Garage::Load(ifstream &fichier)
{
    cout<<"<<load garage>>"<<endl;

    if(fichier.is_open())
    {
        //récupère le numCourant d'employé
        fichier.read((char *)&Intervenant::numCourant,sizeof(int));
        // récupère le nombre d'employés présent dans le fichier.
        int nbrEmploye;
        fichier.read((char *)&nbrEmploye,sizeof(int));
        cout<<endl<<"taille vec employes = "<<nbrEmploye;
        // récupère chaques employés et l'insère dans le vecteurs d'employés
        for(int i = 0; i<nbrEmploye;i++)
        {
            Employe e;
            e.Load(fichier);
            cout<<endl<<"EMPLOYE["<<i<<"] :"<< e;
            employes.insere(e);
                
        }
        // récupère le nombre de client présent dans le fichier et insère les clients dans le bon vecteur.
        int nbrClient;
        fichier.read((char *)&nbrClient,sizeof(int));
        for(int i = 0; i<nbrClient; i++)
        {
            Client c;
            c.Load(fichier);
            clients.insere(c);
        }

        fichier.read((char *)&Contrat::numCourant,sizeof(int)); // Récupère le numCourant de Contrat

        int nbrContrat;
        fichier.read((char *)&nbrContrat,sizeof(int));
        for(int i=0; i<nbrContrat;i++)
        {
            Contrat c;
            c.Load(fichier);
            
            Iterateur<Employe>itE(employes);
            for(itE.reset();!itE.end() && c.getEmployeRef()->getNumero() != ((Employe)itE).getNumero();itE++);
            if(c.getEmployeRef()->getNumero() == ((Employe)itE).getNumero())
            {
                c.setEmployeRef((Employe)itE);
            }
            Iterateur<Client>itC(clients);
            for(itC.reset();!itC.end() && c.getClientRef()->getNumero() != ((Client)itC).getNumero();itC++);
            if(c.getClientRef()->getNumero() == ((Client)itC).getNumero())
            {
                c.setClientRef((Client)itC);
            }
            contrats.insere(c);
        }



    }
}