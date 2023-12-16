#include "../class/client.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>
#include "../class/appartement.hpp"
#include "../class/maison.hpp"
#include "../class/garage.hpp"
#include "../class/bien.hpp"
#include "../class/date.hpp"


unsigned int client::uniqueID = 1;

// Constructeurs
client::client() {
    id = uniqueID++;
    nom = "";
    prenom = "";
    civilite = "";
    email = "";
    telephone = "";
    solde = 0;
    naissance.jour = 0;
    naissance.mois = 0;
    naissance.annee = 0;
}


// Destructeur
client::~client() {
    std::cout << "client detruit" << std::endl;
}

// Getters

std::string client::getNom() const {
    return nom;
}

std::string client::getPrenom() const {
    return prenom;
}

std::string client::getCivilite() const {
    return civilite;
}

std::string client::getEmail() const {
    return email;
}

std::string client::getTelephone() const {
    return telephone;
}

unsigned int client::getId() const {
    return id;
}

double client::getSolde() const {
    return solde;
}

date client::getNaissance() const {
    return naissance;
}

// Setters

bool client::setNom(std::string _nom) {
    if (_nom == "") {
        std::cout << "Le nom ne peut pas être vide" << std::endl;
        return false;
    } else {
        nom = _nom;
        return true;
    }
}

bool client::setPrenom(std::string _prenom) {
    if (_prenom == "") {
        std::cout << "Le prenom ne peut pas être vide" << std::endl;
        return false;
    } else {
        prenom = _prenom;
        return true;
    }
}

bool client::setCivilite(std::string _civilite) {
    if (_civilite == "") {
        std::cout << "La civilité ne peut pas être vide" << std::endl;
        return false;
    } else {
        civilite = _civilite;
        return true;
    }
}

bool client::setEmail(std::string _email) {
    if (_email == "") {
        std::cout << "L'email ne peut pas être vide" << std::endl;
        return false;
    } else {
        email = _email;
        return true;
    }
}

bool client::setTelephone(std::string _telephone) {
    if (_telephone == "") {
        std::cout << "Le telephone ne peut pas être vide" << std::endl;
        return false;
    } else if (_telephone.length() != 14) {
        std::cout << "Le telephone doit être au format +33 x xx xx xx xx" << std::endl;
        return false;
    } else {
        telephone = _telephone;
        return true;
    }
}

bool client::setId(unsigned int _id) {
    id = _id;
}

bool client::setSolde(double _solde) {
    if (_solde < 0) {
        std::cout << "Le solde ne peut pas être négatif" << std::endl;
        return false;
    } else {
        solde = _solde;
        return true;
    }
}

bool client::setJourNaissance(int jour) {
    if (jour < 1 || jour > 31) {
        std::cout << "Le jour doit être compris entre 1 et 31" << std::endl;
        return false;
    } else {
        naissance.jour = jour;
        return true;
    }
}

bool client::setMoisNaissance(int mois) {
    if (mois < 1 || mois > 12) {
        std::cout << "Le mois doit être compris entre 1 et 12" << std::endl;
        return false;
    } else {
        naissance.mois = mois;
        return true;
    }
}

bool client::setAnneeNaissance(int annee) {
    if (annee > 2004) {
        std::cout << "Le.a client.e doit etre majeur.e" << std::endl;
        return false;
    } else {
        naissance.annee = annee;
        return true;
    }
}

// methodes
void client::addMaison(maison *maison) {
    maisons.push_back(maison);
    maison->setIdClient(id);
}

void client::addAppartement(appartement *appartement) {
    appartements.push_back(appartement);
    appartement->setIdClient(id);
}

void client::addGarage(garage *garage) {
    garages.push_back(garage);
    garage->setIdClient(id);
}

void client::removeMaison(maison *maison) {
    for (int i = 0; i < maisons.size(); i++) {
        if (maisons[i]->getId() == maison->getId()) {
            maisons.erase(maisons.begin() + i);
            maison->setIdClient(0);
            break;
        }
    }
}

void client::removeAppartement(appartement *appartement) {
    for (int i = 0; i < appartements.size(); i++) {
        if (appartements[i]->getId() == appartement->getId()) {
            appartements.erase(appartements.begin() + i);
            appartement->setIdClient(0);
            break;
        }
    }
}

void client::removeGarage(garage *garage) {
    for (int i = 0; i < garages.size(); i++) {
        if (garages[i]->getId() == garage->getId()) {
            garages.erase(garages.begin() + i);
            garage->setIdClient(0);
            break;
        }
    }
}

void client::afficherBiens() const{
    std::cout << "Biens de " << civilite << " " << nom << " " << prenom << " :" << std::endl;
    std::cout << "Maisons :" << std::endl;
    for (int i = 0; i < maisons.size(); i++) {
        std::cout << "    " << maisons[i]->getAdresse() << std::endl;
        std::cout << "    " << maisons[i]->getPrix() << "euros/mois" << std::endl;
        std::cout << "    " << maisons[i]->getSurface() << "m²" << std::endl;
        std::cout << "    " << maisons[i]->getNbPieces() << " pièces" << std::endl;
        std::cout << "Appuyez sur une touche pour continuer" << std::endl;
        getch();
    }
    std::cout << "Appartements :" << std::endl;
    for (int i = 0; i < appartements.size(); i++) {
        std::cout << "    " << appartements[i]->getAdresse() << std::endl;
        std::cout << "    " << appartements[i]->getPrix() << "euros/mois" << std::endl;
        std::cout << "    " << appartements[i]->getSurface() << "m²" << std::endl;
        std::cout << "    " << appartements[i]->getNbPieces() << " pièces" << std::endl;
        std::cout << "Appuyez sur une touche pour continuer" << std::endl;
        getch();
    }
    std::cout << "Garages :" << std::endl;
    for (int i = 0; i < garages.size(); i++) {
        std::cout << "    " << garages[i]->getAdresse() << std::endl;
        std::cout << "    " << garages[i]->getPrix() << "euros/mois" << std::endl;
        std::cout << "    " << garages[i]->getSurface() << "m²" << std::endl;
        std::cout << "    " << garages[i]->getNbPlaces() << " pièces" << std::endl;
        std::cout << "Appuyez sur une touche pour continuer" << std::endl;
        getch();
    }
}

// operateurs de comparaison
bool client::operator==(client const& a) const {
    bool nom = this->nom == a.nom;
    bool prenom = this->prenom == a.prenom;
    return nom && prenom;    
}