#ifndef MAISON_HPP
#define MAISON_HPP




class maison {
private:
    int nbPieces;
    bool garage;
    bool jardin;
    bool piscine;
    bool cave;

public:
    maison();
    maison(int nbPieces, bool garage, bool jardin, bool piscine, bool cave);
    int getNbPieces();
    bool getGarage();
    bool getJardin();
    bool getPiscine();
    bool getCave();
    void setNbPieces(int nbPieces);
    void setGarage(bool garage);
    void setJardin(bool jardin);
    void setPiscine(bool piscine);
    void setCave(bool cave);
};

#endif