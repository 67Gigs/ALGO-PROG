#ifndef BIEN_HPP
#define BIEN_HPP

#include <string>

class bien {
protected:
    std::string adresse;
    int surface; // en m²
    double prix; // en €
public:
    bien();
    bien(std::string adresse, int surface, int loyer);
    std::string getAdresse();
    int getSurface();
    double getPrix();
    void setAdresse(std::string adresse);
    void setSurface(int surface);
    void setPrix(double prix);
    virtual void affiche();
};

#endif