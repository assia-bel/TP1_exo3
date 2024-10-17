#include "Transaction.h"
#include<iostream>

Transaction::Transaction(std::string type, double m, std::string dest, std::string date):typeOperation(type),montant(m),destinataire(dest),date(date)
{}

void Transaction::afficherT() const
{
    std::cout << " - " << typeOperation << " de " << montant;
    if (!destinataire.empty()) 
    {
        std::cout << " vers " << destinataire;
    }
    std::cout << " le " << date << std::endl;
}
