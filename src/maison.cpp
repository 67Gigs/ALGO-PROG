#include "../class/maison.hpp"
#include <string>
#include <iostream>
#include <vector>

unsigned int maison::uniqueID = 1;

// Constructeurs

maison::maison() {
    id = uniqueID++;
    nbPieces = 0;
    garage = false;
    jardin = false;
    piscine = false;
    cave = false;
    idClient = 0;
}

// Destructeur

maison::~maison() {
}

// Getters

int maison::getNbPieces() const {
    return nbPieces;
}

bool maison::getGarage() const {
    return garage;
}

bool maison::getJardin() const {
    return jardin;
}

bool maison::getPiscine() const {
    return piscine;
}

bool maison::getCave() const {
    return cave;
}

unsigned int maison::getId() const {
    return id;
}

unsigned int maison::getIdClient() const {
    return idClient;
}

// Setters

bool maison::setNbPieces(int _nbPieces) {
    if (_nbPieces > 0) {
        nbPieces = _nbPieces;
        return true;
    } else {
        std::cout << "Le nombre de pieces doit etre superieur a 0" << std::endl;
        return false;
    }
}

bool maison::setGarage(bool _garage) {
    if (garage = _garage) {
        return true;
    } else {
        std::cout << "Le garage doit etre un booleen" << std::endl;
        return false;
    }
}

bool maison::setJardin(bool _jardin) {
    if (jardin = _jardin) {
        return true;
    } else {
        std::cout << "Le jardin doit etre un booleen" << std::endl;
        return false;
    }
}

bool maison::setPiscine(bool _piscine) {
    if (piscine = _piscine) {
        return true;
    } else {
        std::cout << "La piscine doit etre un booleen" << std::endl;
        return false;
    }
}

bool maison::setCave(bool _cave) {
    if (cave = _cave) {
        return true;
    } else {
        std::cout << "La cave doit etre un booleen" << std::endl;
        return false;
    }
}

bool maison::setIdClient(unsigned int _idClient) {
    if (_idClient >= 0) {
        idClient = _idClient;
        return true;
    } else {
        std::cout << "L'id du client doit etre superieur a 0" << std::endl;
        return false;
    }
}

// Methodes

void maison::affiche() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "ID : " << id << std::endl;
    std::cout << "Adresse : " << adresse << std::endl;
    std::cout << "Surface : " << surface << std::endl;
    std::cout << "Prix : " << prix << std::endl;
    std::cout << "Nombre de pieces : " << nbPieces << std::endl;
    if (garage) {
        std::cout << "Garage : Oui" << std::endl;
    } else {
        std::cout << "Garage : Non" << std::endl;
    }
    if (jardin) {
        std::cout << "Jardin : Oui" << std::endl;
    } else {
        std::cout << "Jardin : Non" << std::endl;
    }
    if (piscine) {
        std::cout << "Piscine : Oui" << std::endl;
    } else {
        std::cout << "Piscine : Non" << std::endl;
    }
    if (cave) {
        std::cout << "Cave : Oui" << std::endl;
    } else {
        std::cout << "Cave : Non" << std::endl;
    }
    std::cout << "ID du client : " << idClient << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}
