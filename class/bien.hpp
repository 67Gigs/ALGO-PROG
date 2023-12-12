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
public:
    // Constructeurs
    bien();
    bien(std::string adresse, int surface, int loyer);

    // Destructeur
    ~bien();

    // Getters
    std::string getAdresse();
    int getSurface();
    double getPrix();
    unsigned int getId();

    // Setters
    void setAdresse(std::string adresse);
    void setSurface(int surface);
    void setPrix(double prix);
    virtual void affiche();
};

#endif