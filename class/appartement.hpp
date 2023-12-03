#ifndef APPARTEMENT_HPP
#define APPARTEMENT_HPP


class appartement : protected bien {
private:
    int numEtage;
    int numAppartement;
    int nbPieces;
    bool garage;
    bool cave;
    bool balcon;
public:
    appartement();
    appartement(int numEtage, int numAppartement, int nbPieces, bool garage, bool cave, bool balcon);
    int getNumEtage();
    int getNumAppartement();
    int getNbPieces();
    bool getGarage();
    bool getCave();
    bool getBalcon();
    void setNumEtage(int numEtage);
    void setNumAppartement(int numAppartement);
    void setNbPieces(int nbPieces);
    void setGarage(bool garage);
    void setCave(bool cave);
    void setBalcon(bool balcon);
};


#endif