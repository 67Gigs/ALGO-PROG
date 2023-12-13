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
    appartement(std::string adresse, int surface, double prix, int nbPieces, int numEtage, int numAppartement, bool ascenseur, bool balcon, bool garage);
    
    // Destructeur
    ~appartement();

    // getters
    int getNumEtage();
    int getNumAppartement();
    int getNbPieces();
    bool getGarage();
    bool getCave();
    bool getBalcon();
    bool getAscenseur();

    // Setters
    void setNumEtage(int numEtage);
    void setNumAppartement(int numAppartement);
    void setAscenseur(bool ascenseur);
    void setNbPieces(int nbPieces);
    void setGarage(bool garage);
    void setBalcon(bool balcon);

    // methodes
    void affiche();
};


#endif