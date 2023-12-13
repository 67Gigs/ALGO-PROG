#include "../class/appartement.hpp"
#include <string>
#include <iostream>
#include <vector>

unsigned int appartement::uniqueID = 0;

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
}

appartement::appartement(std::string _adresse, int _surface, double _prix, int _nbPieces, int _numEtage, int _numAppartement, bool _ascenseur, bool _balcon, bool _garage) {
    id = uniqueID++;

    adresse = _adresse;
    surface = _surface;
    prix = _prix;
    nbPieces = _nbPieces;
    numEtage = _numEtage;
    ascenseur = _ascenseur;
    balcon = _balcon;
    garage = _garage;
}

// Destructeur

appartement::~appartement() {}

// Getters
int appartement::getNbPieces() {
    return nbPieces;
}

int appartement::getNumEtage() {
    return numEtage;
}

int appartement::getNumAppartement() {
    return numAppartement;
}

bool appartement::getAscenseur() {
    return ascenseur;
}

bool appartement::getBalcon() {
    return balcon;
}

bool appartement::getGarage() {
    return garage;
}

// Setters


void appartement::setNbPieces(int _nbPieces) {
    nbPieces = _nbPieces;
}

void appartement::setNumEtage(int _numEtage) {
    numEtage = _numEtage;
}

void appartement::setNumAppartement(int _numAppartement) {
    numAppartement = _numAppartement;
}

void appartement::setAscenseur(bool _ascenseur) {
    ascenseur = _ascenseur;
}

void appartement::setBalcon(bool _balcon) {
    balcon = _balcon;
}


void appartement::setGarage(bool _garage) {
    garage = _garage;
}

// Methodes
void appartement::affiche() {
    std::cout << "Appartement " << id << " : " << std::endl;
    std::cout << "Adresse : " << adresse << std::endl;
    std::cout << "Surface : " << surface << " m²" << std::endl;
    std::cout << "Prix : " << prix << " €" << std::endl;
    std::cout << "Nombre de pièces : " << nbPieces << std::endl;
    std::cout << "Numéro d'étage : " << numEtage << std::endl;
    std::cout << "Numéro d'appartement : " << numAppartement << std::endl;
    std::cout << "Ascenseur : " << (ascenseur ? "oui" : "non") << std::endl;
    std::cout << "Balcon : " << (balcon ? "oui" : "non") << std::endl;
    std::cout << "Garage : " << (garage ? "oui" : "non") << std::endl;
    std::cout << std::endl;
}