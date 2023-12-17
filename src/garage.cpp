#include "../class/garage.hpp"
#include <string>
#include <iostream>
#include <vector>

unsigned int garage::uniqueID = 1;

// Constructeurs
garage::garage() {
    id = uniqueID++;
    adresse = "";
    surface = 0;
    prix = 0;
    numPlace = 0;
    ferme = false;
    alarme = false;
    box = false;
    idClient = 0;
}


// Destructeur
garage::~garage() {}


// Getters

int garage::getNbPlaces() const {
    return numPlace;
}

bool garage::getFerme() const {
    return ferme;
}

bool garage::getAlarme() const {
    return alarme;
}

bool garage::getBox() const {
    return box;
}

unsigned int garage::getIdClient() const {
    return idClient;
}

// Setters

bool garage::setNbPlaces(int _numPlace) {
    if (_numPlace < 0) {
        std::cout << "Le nombre de places ne peut pas être négatif" << std::endl;
        return false;
    } else {
        numPlace = _numPlace;
    }
    return true;
}

bool garage::setFerme(bool _ferme) {
    if (ferme = _ferme) {
        return true;
    } else {
        std::cout << "Le garage doit avoir la valeur 0 ou 1 " << std::endl;
        return false;
    }
}

bool garage::setAlarme(bool _alarme) {
    if (alarme = _alarme) {
        return true;
    } else {
        std::cout << "L'alarme doit avoir la valeur 0 ou 1 " << std::endl;
        return false;
    }
}

bool garage::setBox(bool _box) {
    if (box = _box) {
        return true;
    } else {
        std::cout << "Le box doit avoir la valeur 0 ou 1 " << std::endl;
        return false;
    }
}

bool garage::setIdClient(unsigned int _idClient) {
    if (_idClient < 0) {
        std::cout << "L'ID du client ne peut pas être négatif" << std::endl;
        return false;
    } else {
        idClient = _idClient;
    }
    return true;
}

void garage::affiche() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "ID : " << id << std::endl;
    std::cout << "Adresse : " << adresse << std::endl;
    std::cout << "Surface : " << surface << std::endl;
    std::cout << "Prix : " << prix << std::endl;
    std::cout << "Nombre de places : " << numPlace << std::endl;
    if (ferme) {
        std::cout << "Ferme : Oui" << std::endl;
    } else {
        std::cout << "Ferme : Non" << std::endl;
    }    
    if (alarme) {
        std::cout << "Alarme : Oui" << std::endl;
    } else {
        std::cout << "Alarme : Non" << std::endl;
    }
    if (box) {
        std::cout << "Box : Oui" << std::endl;
    } else {
        std::cout << "Box : Non" << std::endl;
    }
    std::cout << "ID Client : " << idClient << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}