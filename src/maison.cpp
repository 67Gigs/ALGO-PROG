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

maison::~maison() {}

// Getters

int maison::getNbPieces() {
    return nbPieces;
}

bool maison::getGarage() {
    return garage;
}

bool maison::getJardin() {
    return jardin;
}

bool maison::getPiscine() {
    return piscine;
}

bool maison::getCave() {
    return cave;
}

unsigned int maison::getId() {
    return id;
}

unsigned int maison::getIdClient() {
    return idClient;
}

// Setters

void maison::setNbPieces(int _nbPieces) {
    nbPieces = _nbPieces;
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
