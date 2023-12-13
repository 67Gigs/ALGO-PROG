#ifndef GARAGE_HPP
#define GARAGE_HPP
#include "bien.hpp"

#include <string>


class garage : public bien {
private:
    int numPlace;
    bool ferme;
    bool alarme;
    bool box;
    static unsigned int uniqueID;

public:
    // constructeurs
    garage();
    garage(std::string adresse, int surface, int loyer, int nbPlaces, bool ferme, bool alarme, bool box);
    
    // destructeur
    ~garage();
    
    // getters
    int getNbPlaces();
    bool getFerme();
    bool getAlarme();
    bool getBox();

    // setters
    void setNbPlaces(int nbPlaces);
    void setFerme(bool ferme);
    void setAlarme(bool alarme);
    void setBox(bool box);

    // methodes
    void affiche();
};


#endif