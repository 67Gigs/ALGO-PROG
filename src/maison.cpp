#include "../class/maison.hpp"
#include <string>
#include <iostream>
#include <vector>

unsigned int maison::uniqueID = 0;

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
    std::cout << "Maison detruite" << std::endl;
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

void maison::setNbPieces(int _nbPieces) {
    if (_nbPieces > 0) {
        nbPieces = _nbPieces;
    } else {
        std::cout << "Le nombre de pieces doit etre superieur a 0" << std::endl;
    }
}

void maison::setGarage(bool _garage) {
    garage = _garage;
}

void maison::setJardin(bool _jardin) {
    jardin = _jardin;
}

void maison::setPiscine(bool _piscine) {
    piscine = _piscine;
}

void maison::setCave(bool _cave) {
    cave = _cave;
}

void maison::setIdClient(unsigned int _idClient) {
    idClient = _idClient;
}

// Methodes

void maison::affiche() {
    std::cout << "Maison " << id << " : " << std::endl;
    std::cout << "Nombre de pieces : " << nbPieces << std::endl;
    std::cout << "Garage : " << garage << std::endl;
    std::cout << "Jardin : " << jardin << std::endl;
    std::cout << "Piscine : " << piscine << std::endl;
    std::cout << "Cave : " << cave << std::endl;
}
