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
}

maison::maison(int _nbPieces, bool _garage, bool _jardin, bool _piscine, bool _cave) {
    id = ++uniqueID;

    nbPieces = _nbPieces;
    garage = _garage;
    jardin = _jardin;
    piscine = _piscine;
    cave = _cave;
}

// Destructeur

maison::~maison() {
}

// Getters et setters

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

// Methodes

// void maison::affiche() {
//     std::cout << "Maison " << id << " : " << std::endl;
//     std::cout << "Nombre de pieces : " << nbPieces << std::endl;
//     std::cout << "Garage : " << garage << std::endl;
//     std::cout << "Jardin : " << jardin << std::endl;
//     std::cout << "Piscine : " << piscine << std::endl;
//     std::cout << "Cave : " << cave << std::endl;
// }
