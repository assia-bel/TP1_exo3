#include "Compte.h"
#include <iostream>



Compte::Compte(std::string id, std::string proprietaire, double solde, std::string devise, std::string type):
	id(id),proprietaire(proprietaire),solde(solde),devise(devise),typeCompte(type),nbT(0)
{
	for (int i = 0; i < MAX; ++i) {
		this->historique[i] = nullptr;
	}
}



void Compte::depot(double montant)
{
	this->solde += montant;
	if (this->nbT < MAX) {
		//Enregistrer la transaction dans l'historique
		historique[nbT] = new Transaction("depot", montant, "", "17/10/2024");
		this->nbT++;
		std::cout << "Depot de " << montant << " effectue avec succes." << std::endl;
	}
	else 
	{
		std::cout << "Historique plein, impossible d'enregistrer plus de transactions."<< std::endl;
	}
	

}

bool Compte::retrait(double montant)
{
	if (this->solde < montant)
	{
		std::cout << "Retrait echoue : solde insufisant." << std::endl;
		return false;
	}
	this->solde -= montant;
	if (this->nbT < MAX) 
	{
		//Enregistrer la transaction dans l'historique
		historique[nbT] = new Transaction("retrait", montant, "", "17/10/2024");
		this->nbT++;
	}
	std::cout << "Retrait de " << montant << " effectue avec succes." << std::endl;
	return true;
}

bool Compte::transfert(Compte& destinataire, double montant)
{
	if (this->retrait(montant))
	{
		destinataire.depot(montant);
		if (this->nbT < MAX)
		{
			//Enregistrer la transaction dans l'historique
			historique[nbT] = new Transaction("transfert", montant, destinataire.id, "17/10/2024");
			this->nbT++;
		}
		std::cout << "Transfert de " << montant << " vers "<< destinataire.id  << " effectue avec succes." << std::endl;
		return true;
	}
	std::cout << "Transfert echoue : solde insufisant." << std::endl;
	return false;
}



void Compte::afficherDetails() const
{
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Informations de compte :" << std::endl;
	std::cout << "Identifiant de compte: " << this->id << std::endl;
	std::cout << "Proprietaire: " << this->proprietaire << std::endl;
	std::cout << "Solde: " << this->solde << std::endl;
	std::cout << "Devise : " << this->devise << std::endl;
	std::cout << "Type : " << this->typeCompte << std::endl;
	std::cout << "--------------------------------------" << std::endl;

}

void Compte::afficherHistorique() const
{
	std::cout << "--------------------------------------"<< std::endl;
	std::cout << "Historique des transactions du compte " << this->id << std::endl;
	for (int i = 0; i < this->nbT; ++i) {
		this->historique[i]->afficherT();
	}
	std::cout << "--------------------------------------" << std::endl;
}

Compte::~Compte()
{
	for (int i = 0; i < this->nbT; ++i) {
		delete historique[i];
	}
}
