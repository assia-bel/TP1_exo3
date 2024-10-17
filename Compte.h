#pragma once
#include <string>
#include"Transaction.h"
#define MAX 100 //taille max de tableau historique

class Compte
{
private:
	std::string id;
	std::string proprietaire;
	double solde;
	std::string devise; //'MAD','USD',...
	std::string typeCompte;//'courant', 'epargne',...

	Transaction* historique[MAX];  // Tableau pour stocker les transactions
	int nbT;//nombre totale des transactions
public:
	//constructeur
	Compte(std::string,std::string, double,std::string,std::string);
	
	void depot(double);
	bool retrait(double);
	bool transfert(Compte&,double);//on aura besoin l'id de compte destinataire
	
	
	void afficherDetails() const;

	void afficherHistorique() const;
	~Compte();


};

