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
    void setNbPieces(int nbPieces);
    void setGarage(bool garage);
    void setJardin(bool jardin);
    void setPiscine(bool piscine);
    void setCave(bool cave);
    void setIdClient(unsigned int idClient);
    void affiche();
};

#endif