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
    void setNumEtage(int numEtage);
    void setNumAppartement(int numAppartement);
    void setAscenseur(bool ascenseur);
    void setNbPieces(int nbPieces);
    void setGarage(bool garage);
    void setBalcon(bool balcon);
    void setIdClient(unsigned int idClient);

    // methodes
    void affiche();
};


#endif