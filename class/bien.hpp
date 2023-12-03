#ifndef BIEN_HPP
#define BIEN_HPP

#include <string>

class bien {
private:
    std::string adresse;
    int surface; // en m²
    double prix; // en €
public:
    bien();
    bien(std::string adresse, int surface, int loyer);
    std::string getAdresse();
    int getSurface();
    void setAdresse(std::string adresse);
    void setSurface(int surface);
};

#endif