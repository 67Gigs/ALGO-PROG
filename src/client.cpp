#include "../class/client.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "../class/bien.hpp"
#include "../class/maison.hpp"
#include "../class/appartement.hpp"
#include "../class/garage.hpp"


unsigned int client::uniqueID = 0;

// Constructeurs
client::client() {
    id = uniqueID++;
    nom = "";
    prenom = "";
    civilite = "";
    email = "";
    telephone = "";
}

client::client(std::string _nom, std::string _prenom, std::string _civilite, std::string _email, std::string _telephone) {
    id = ++uniqueID;

    nom = _nom;
    prenom = _prenom;
    civilite = _civilite;
    email = _email;
    telephone = _telephone;
}

// Destructeur
client::~client() {
}

// Getters

std::string client::getNom() {
    return nom;
}

std::string client::getPrenom() {
    return prenom;
}

std::string client::getCivilite() {
    return civilite;
}

std::string client::getEmail() {
    return email;
}

std::string client::getTelephone() {
    return telephone;
}

unsigned int client::getId() {
    return id;
}

// Setters

void client::setNom(std::string _nom) {
    if (_nom == "") {
        std::cout << "Le nom ne peut pas être vide" << std::endl;
    } else {
        nom = _nom;
    }
}

void client::setPrenom(std::string _prenom) {
    if (_prenom == "") {
        std::cout << "Le prenom ne peut pas être vide" << std::endl;
    } else {
        prenom = _prenom;
    }
}

void client::setCivilite(std::string _civilite) {
    if (_civilite == "") {
        std::cout << "La civilité ne peut pas être vide" << std::endl;
    } else {
        civilite = _civilite;
    }
}

void client::setEmail(std::string _email) {
    if (_email == "") {
        std::cout << "L'email ne peut pas être vide" << std::endl;
    } else {
        email = _email;
    }
}

void client::setTelephone(std::string _telephone) {
    if (_telephone == "") {
        std::cout << "Le telephone ne peut pas être vide" << std::endl;
    } else {
        telephone = _telephone;
    }
}

// methodes
void client::addMaison(maison maison) {
    maisons.push_back(maison);
}

void client::addAppartement(appartement appartement) {
    appartements.push_back(appartement);
}

void client::addGarage(garage garage) {
    garages.push_back(garage);
}

void client::removeMaison(maison maison) {
    for (int i = 0; i < maisons.size(); i++) {
        if (maisons[i].getId() == maison.getId()) {
            maisons.erase(maisons.begin() + i);
            break;
        }
    }
}

void client::removeAppartement(appartement appartement) {
    for (int i = 0; i < appartements.size(); i++) {
        if (appartements[i].getId() == appartement.getId()) {
            appartements.erase(appartements.begin() + i);
            break;
        }
    }
}

void client::removeGarage(garage garage) {
    for (int i = 0; i < garages.size(); i++) {
        if (garages[i].getId() == garage.getId()) {
            garages.erase(garages.begin() + i);
            break;
        }
    }
}

void client::afficherBiens() {
    std::cout << "Biens de " << civilite << " " << nom << " " << prenom << " :" << std::endl;
    std::cout << "Maisons :" << std::endl;
    for (int i = 0; i < maisons.size(); i++) {
        std::cout << "    " << maisons[i].getAdresse() << std::endl;
    }
    std::cout << "Appartements :" << std::endl;
    for (int i = 0; i < appartements.size(); i++) {
        std::cout << "    " << appartements[i].getAdresse() << std::endl;
    }
    std::cout << "Garages :" << std::endl;
    for (int i = 0; i < garages.size(); i++) {
        std::cout << "    " << garages[i].getAdresse() << std::endl;
    }
}