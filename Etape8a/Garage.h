#ifndef GARAGE_H
#define GARAGE_H

class Garage
{
private:
	VecteurTrie<Employe> employes;
	VecteurTrie<Client> clients;
	Vecteur<Modele> modeles;
	Vecteur<Option> options;

public:
	Garage();

	~Garage();

	void ajouteModele(const Modele& m);
	void afficheModelesDisponibles() const;
	Modele getModele(int indice);

	void ajouteOption(const Option& o);
	void afficheOptionsDisponibles() const;
	Option getOption(int indice);

	void ajouteClient(string nom, string prenom, string login, string gsm);
	void afficheClients() const;
	void supprimeClientParIndice(int ind);
	void supprimeClientParNumero(int num);

	void ajouteEmploye(string nom, string prenom, string login, string fonction);
	void afficheEmployes() const;
	void supprimeEmployeParIndice(int ind);
	void supprimeEmployeParNumero(int num);
};

#endif