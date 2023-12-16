#include "../class/appartement.hpp"
#include <string>
#include <iostream>
#include <vector>

unsigned int appartement::uniqueID = 1;

// Constructeurs
appartement::appartement() {
    id = uniqueID++;
    numAppartement = 0;
    adresse = "";
    surface = 0;
    prix = 0;
    nbPieces = 0;
    numEtage = 0;
    ascenseur = false;
    balcon = false;
    garage = false;
    idClient = 0;
}

// Destructeur

appartement::~appartement() {}

// Getters
int appartement::getNbPieces() const {
    return nbPieces;
}

int appartement::getNumEtage() const {
    return numEtage;
}

int appartement::getNumAppartement() const {
    return numAppartement;
}

bool appartement::getAscenseur() const {
    return ascenseur;
}

bool appartement::getBalcon() const {
    return balcon;
}

bool appartement::getGarage() const {
    return garage;
}

unsigned int appartement::getIdClient() const {
    return idClient;
}

// Setters


bool appartement::setNbPieces(int _nbPieces) {
    if (_nbPieces < 0) {
        std::cout << "Le nombre de pieces ne peut pas être négatif" << std::endl;
        return false;
    } else {
        nbPieces = _nbPieces;
    }
    return true;
}

bool appartement::setNumEtage(int _numEtage) {
    if (_numEtage < 0) {
        std::cout << "Le nombre d'étages ne peut pas être négatif" << std::endl;
        return false;
    } else {
        numEtage = _numEtage;
    }
    return true;
}

bool appartement::setNumAppartement(int _numAppartement) {
    if (_numAppartement < 0) {
        std::cout << "Le nombre d'appartement ne peut pas être négatif" << std::endl;
        return false;
    } else {
        numAppartement = _numAppartement;
    }
    return true;
}

bool appartement::setAscenseur(bool _ascenseur) {
    if (ascenseur = _ascenseur) {
        return true;
    } else {
        std::cout << "L'ascenseur doit être un booleen" << std::endl;
        return false;
    }
}

bool appartement::setBalcon(bool _balcon) {
    if (balcon = _balcon) {
        return true;
    } else {
        std::cout << "Le balcon doit être un booleen" << std::endl;
        return false;
    }
}


bool appartement::setGarage(bool _garage) {
    if (garage = _garage) {
        return true;
    } else {
        std::cout << "Le garage doit être un booleen" << std::endl;
        return false;
    }
}

bool appartement::setIdClient(unsigned int _idClient) {
    if (_idClient >= 0) {
        idClient = _idClient;
        return true;
    } else {
        std::cout << "L'id du client doit être supérieur à 0" << std::endl;
        return false;
    }
}

// Methodes
void appartement::affiche() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "ID : " << id << std::endl;
    std::cout << "Adresse : " << adresse << std::endl;
    std::cout << "Surface : " << surface << std::endl;
    std::cout << "Prix : " << prix << std::endl;
    std::cout << "Nombres de pieces : " << nbPieces << std::endl;
    std::cout << "Balcon : " << balcon << std::endl;
    std::cout << "Garage : " << garage << std::endl;
    std::cout << "Ascenseur : " << ascenseur << std::endl;
    std::cout << "ID Client : " << idClient << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}