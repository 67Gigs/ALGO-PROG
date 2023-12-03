#ifndef GARAGE_HPP
#define GARAGE_HPP

#include <string>
#include "bien.hpp"


class garage : protected bien {
private:
    int numPlace;
    bool ferme;
    bool alarme;
public:
    garage();
    garage(std::string adresse, int surface, int loyer, int nbPlaces, bool ferme, bool alarme, bool box);
    int getNbPlaces();
    bool getFerme();
    bool getAlarme();
    bool getBox();
    void setNbPlaces(int nbPlaces);
    void setFerme(bool ferme);
    void setAlarme(bool alarme);
    void setBox(bool box);

};


#endif