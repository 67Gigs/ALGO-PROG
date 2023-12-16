#ifndef BIEN_HPP
#define BIEN_HPP

#include <string>

class bien {
protected:
    static unsigned int uniqueID;
    unsigned int id;
    std::string adresse;
    int surface; // en m²
    double prix; // en €
    unsigned int idClient;
    
public:
    // Constructeurs
    bien();

    // Destructeur
    ~bien();

    // Getters
    std::string getAdresse() const;
    int getSurface() const;
    double getPrix() const;
    unsigned int getId() const;

    // Setters
    bool setAdresse(std::string adresse);
    bool setSurface(int surface);
    bool setPrix(double prix);
    
    // autres methodes
    virtual void affiche();
};

#endif