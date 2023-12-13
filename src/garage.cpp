#include "../class/garage.hpp"
#include <string>
#include <iostream>
#include <vector>

unsigned int garage::uniqueID = 0;

// Constructeurs
garage::garage() {
    id = ++uniqueID;
    adresse = "";
    surface = 0;
    prix = 0;
    numPlace = 0;
    ferme = false;
    alarme = false;
    box = false;
}

garage::garage(std::string _adresse, int _surface, int _prix, int _numPlace, bool _ferme, bool _alarme, bool _box) {
    id = ++uniqueID;
    adresse = _adresse;
    surface = _surface;
    prix = _prix;
    numPlace = _numPlace;
    ferme = _ferme;
    alarme = _alarme;
}


// Getters

int garage::getNbPlaces() {
    return numPlace;
}

bool garage::getFerme() {
    return ferme;
}

bool garage::getAlarme() {
    return alarme;
}

bool garage::getBox() {
    return box;
}

unsigned int garage::getId() {
    return id;
}

// Setters

void garage::setNbPlaces(int _numPlace) {
    if (_numPlace < 0) {
        std::cout << "Le nombre de places ne peut pas être négatif" << std::endl;
    } else {
        numPlace = _numPlace;
    }
}

void garage::setFerme(bool _ferme) {
    ferme = _ferme;
}

void garage::setAlarme(bool _alarme) {
    alarme = _alarme;
}

void garage::setBox(bool _box) {
    box = _box;
}

void garage::affiche() {
    std::cout << "Garage n°" << id << std::endl;
    std::cout << "Adresse : " << adresse << std::endl;
    std::cout << "Surface : " << surface << " m²" << std::endl;
    std::cout << "Prix : " << prix << " €" << std::endl;
    std::cout << "Nombre de places : " << numPlace << std::endl;
    std::cout << "Fermé : " << ferme << std::endl;
    std::cout << "Alarme : " << alarme << std::endl;
    std::cout << "Box : " << box << std::endl;
}