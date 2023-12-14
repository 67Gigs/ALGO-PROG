#ifndef MAISON_HPP
#define MAISON_HPP

#include "bien.hpp"
#include <string>



class maison : public bien {
private:
    int nbPieces;
    bool garage;
    bool jardin;
    bool piscine;
    bool cave;
    static unsigned int uniqueID;

public:
    // constructeurs
    maison();
    
    // destructeur
    ~maison();

    // getters
    int getNbPieces();
    bool getGarage();
    bool getJardin();
    bool getPiscine();
    bool getCave();
    unsigned int getId();
    unsigned int getIdClient();

    // setters
    void setNbPieces(int nbPieces);
    void setGarage(bool garage);
    void setJardin(bool jardin);
    void setPiscine(bool piscine);
    void setCave(bool cave);
    void setIdClient(unsigned int idClient);
    void affiche();
};

#endif