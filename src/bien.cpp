#include "../class/bien.hpp"

#include <string>
#include <iostream>

unsigned int bien::uniqueID = 0;


// Constructeurs
bien::bien() {
    id = uniqueID++;
    adresse = "";
    surface = 0;
    prix = 0;
}

// Destructeur
bien::~bien() {}

// Getters

std::string bien::getAdresse() const {
    return adresse;
}

int bien::getSurface() const {
    return surface;
}

double bien::getPrix() const {
    return prix;
}

unsigned int bien::getId() const {
    return id;
}

// Setters

void bien::setAdresse(std::string _adresse) {
    if (_adresse == "") {
        std::cout << "L'adresse ne peut pas être vide" << std::endl;
    } else {
        adresse = _adresse;
    }
}

void bien::setSurface(int _surface) {
    if (_surface < 0) {
        std::cout << "La surface ne peut pas être négative" << std::endl;
    } else {
        surface = _surface;
    }
}

void bien::setPrix(double _prix) {
    if (_prix < 0) {
        std::cout << "Le prix ne peut pas être négatif" << std::endl;
    } else {
        prix = _prix;
    }
}


// Fonctions membres

void bien::affiche() {
    std::cout << "Adresse : " << getAdresse() << std::endl;
    std::cout << "Surface : " << getSurface() << " m2" << std::endl;
    std::cout << "Loyer : " << getPrix() << " euro" << std::endl;
}