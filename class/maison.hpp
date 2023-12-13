#ifndef MAISON_HPP
#define MAISON_HPP

#include "bien.hpp"
#include <string>


class maison : protected bien {
private:
    int nbPieces;
    bool garage;
    bool jardin;
    bool piscine;
    bool cave;
    static unsigned int uniqueID;
    unsigned int id;

public:
    // constructeurs
    maison();
    maison(int nbPieces, bool garage, bool jardin, bool piscine, bool cave);
    
    // destructeur
    ~maison();

    // getters et setters
    int getNbPieces();
    bool getGarage();
    bool getJardin();
    bool getPiscine();
    bool getCave();
    unsigned int getId();
    void setNbPieces(int nbPieces);
    void setGarage(bool garage);
    void setJardin(bool jardin);
    void setPiscine(bool piscine);
    void setCave(bool cave);
};

#endif