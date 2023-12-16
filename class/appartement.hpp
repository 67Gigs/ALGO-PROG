#ifndef APPARTEMENT_HPP
#define APPARTEMENT_HPP

#include "bien.hpp"
#include <string>


class appartement : public bien {
private:
    int numEtage;
    int numAppartement;
    int nbPieces;
    bool garage;
    bool balcon;
    bool ascenseur;
    static unsigned int uniqueID;

public:
    // Constructeurs
    appartement();
    
    // Destructeur
    ~appartement();

    // getters
    int getNumEtage() const;
    int getNumAppartement() const;
    int getNbPieces() const;
    bool getGarage() const;
    bool getBalcon() const;
    bool getAscenseur() const;
    unsigned int getIdClient() const;

    // Setters
    bool setNumEtage(int numEtage);
    bool setNumAppartement(int numAppartement);
    bool setAscenseur(bool ascenseur);
    bool setNbPieces(int nbPieces);
    bool setGarage(bool garage);
    bool setBalcon(bool balcon);
    bool setIdClient(unsigned int idClient);

    // methodes
    void affiche();
};


#endif