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
    int getNbPieces() const;
    bool getGarage() const;
    bool getJardin() const;
    bool getPiscine() const;
    bool getCave() const;
    unsigned int getId() const;
    unsigned int getIdClient() const;

    // setters
    bool setNbPieces(int nbPieces);
    bool setGarage(bool garage);
    bool setJardin(bool jardin);
    bool setPiscine(bool piscine);
    bool setCave(bool cave);
    bool setIdClient(unsigned int idClient);
    
    // autres methodes
    void affiche();
};

#endif