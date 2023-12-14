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
    unsigned int idClient;

public:
    // constructeurs
    garage();
    
    // destructeur
    ~garage();
    
    // getters
    int getNbPlaces();
    bool getFerme();
    bool getAlarme();
    bool getBox();
    unsigned int getIdClient();

    // setters
    void setNbPlaces(int nbPlaces);
    void setFerme(bool ferme);
    void setAlarme(bool alarme);
    void setBox(bool box);
    void setIdClient(unsigned int idClient);

    // methodes
    void affiche();
};


#endif