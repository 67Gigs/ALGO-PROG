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
    int getNbPlaces() const;
    bool getFerme() const;
    bool getAlarme() const;
    bool getBox() const;
    unsigned int getIdClient() const;

    // setters
    bool setNbPlaces(int nbPlaces);
    bool setFerme(bool ferme);
    bool setAlarme(bool alarme);
    bool setBox(bool box);
    bool setIdClient(unsigned int idClient);

    // methodes
    void affiche();
};


#endif