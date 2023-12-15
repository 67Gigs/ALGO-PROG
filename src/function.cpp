#include <iostream>
#include <vector>
#include <string>


void afficherMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Bienvenue dans l'agence immobiliere" << std::endl;
    std::cout << "1. Ajouter un bien" << std::endl;
    std::cout << "2. Modifier un bien" << std::endl;
    std::cout << "3. Supprimer un bien" << std::endl;
    std::cout << "4. Afficher les biens" << std::endl;
    std::cout << "5. Ajouter un client" << std::endl;
    std::cout << "6. Modifier un client" << std::endl;
    std::cout << "7. Supprimer un client" << std::endl;
    std::cout << "8. Afficher les clients" << std::endl;
    std::cout << "9. Sauvegarder" << std::endl;
    std::cout << "0. Quitter" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Votre choix : ";
}



void ajoutBien() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Ajouter une maison" << std::endl;
    std::cout << "2. Ajouter un appartement" << std::endl;
    std::cout << "3. Ajouter un garage" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Votre choix : ";
}

void modifierBien() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Modifier une maison" << std::endl;
    std::cout << "2. Modifier un appartement" << std::endl;
    std::cout << "3. Modifier un garage" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Votre choix : ";
}

void supprimerBien() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Supprimer une maison" << std::endl;
    std::cout << "2. Supprimer un appartement" << std::endl;
    std::cout << "3. Supprimer un garage" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Votre choix : ";
}

void afficherBiens() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Afficher les maisons" << std::endl;
    std::cout << "2. Afficher les appartements" << std::endl;
    std::cout << "3. Afficher les garages" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Votre choix : ";
}



void modifierClient() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Modifier le nom" << std::endl;
    std::cout << "2. Modifier le prenom" << std::endl;
    std::cout << "3. Modifier la civilité" << std::endl;
    std::cout << "4. Modifier l'email" << std::endl;
    std::cout << "5. Modifier le téléphone" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Votre choix : ";
}

void supprimerClient() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Supprimer un client" << std::endl;
    std::cout << "2. Supprimer tous les clients" << std::endl;
    std::cout << "3. Supprimer les clients ayant des biens" << std::endl;
    std::cout << "4. Supprimer les clients n'ayant pas de biens" << std::endl;
    std::cout << "0. Retour" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Votre choix : ";
}

