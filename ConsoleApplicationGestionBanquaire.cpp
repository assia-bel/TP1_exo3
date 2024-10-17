#include <iostream>
#include "Compte.h"

int main()
{
    // Création de deux comptes
    Compte compte1("A001", "Salma", 900.0, "MAD","courant");
    Compte compte2("B002", "Karima", 600.0, "USD","courant");

    // Dépôt sur le compte1
    compte1.depot(100.0);
    compte1.afficherDetails();

    // Retrait sur le compte2
    compte2.retrait(100.0);
    compte2.afficherDetails();

    // Transfert de compte1 vers compte2
    compte1.transfert(compte2, 200.0);

    // Affichage des historiques de transactions
    compte1.afficherHistorique();
    compte2.afficherHistorique();

    return 0;
}
