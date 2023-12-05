#include "../class/bien.hpp"

#include <string>
#include <iostream>



bien::bien() {
    adresse = "";
    surface = 0;
    prix = 0;
}

bien::bien(std::string _adresse, int _surface=0, int _loyer=0) {
    
    adresse = _adresse;
    
    if (_surface < 0) {
        std::cout << "La surface ne peut pas être négative" << std::endl;
    } else {
        surface = _surface;
    }
    if (_loyer < 0) {
        std::cout << "Le loyer ne peut pas être négatif" << std::endl;
    } else {
        prix = _loyer;
    }
}

std::string bien::getAdresse() {
    return adresse;
}

int bien::getSurface() {
    return surface;
}

double bien::getPrix() {
    return prix;
}

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

void bien::affiche() {
    std::cout << "Adresse : " << getAdresse() << std::endl;
    std::cout << "Surface : " << getSurface() << " m2" << std::endl;
    std::cout << "Loyer : " << getPrix() << " euro" << std::endl;
}