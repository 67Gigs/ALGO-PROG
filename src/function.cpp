#include <iostream>
#include <vector>
#include <string>


void afficherMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Bienvenue dans l'agence immobiliere" << std::endl;
    std::cout << "1. Bien" << std::endl;
    std::cout << "2. Client" << std::endl;
    std::cout << "0. Quitter" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void afficherMenuBien() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Ajouter un bien" << std::endl;
    std::cout << "2. Modifier un bien" << std::endl;
    std::cout << "3. Supprimer un bien" << std::endl;
    std::cout << "4. Afficher les biens" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void afficherBiens() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Afficher les maisons" << std::endl;
    std::cout << "2. Afficher les appartements" << std::endl;
    std::cout << "3. Afficher les garages" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void afficherMenuClient() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Ajouter un client" << std::endl;
    std::cout << "2. Modifier un client" << std::endl;
    std::cout << "3. Supprimer un client" << std::endl;
    std::cout << "4. Afficher les clients" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void afficherClients() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Afficher les clients" << std::endl;
    std::cout << "2. Afficher les clients ayant des biens" << std::endl;
    std::cout << "3. Afficher les clients n'ayant pas de biens" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}



