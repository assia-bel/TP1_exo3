#pragma once
#include<string>
class Transaction
{
private:
	std::string typeOperation;//'depot' , 'transfert' , 'retrait'
	double montant;
	std::string destinataire;// au cas de transfert
	std::string date;
public:
	Transaction(std::string, double,std::string,std::string);
	//afficher details e la transaction
	void afficherT() const; 

};

