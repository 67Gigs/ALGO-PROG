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
    bool ascenseur;
    static unsigned int uniqueID;
    unsigned int id;
    
public:
    appartement();
    appartement(std::string adresse, int surface, double prix, int nbPieces, int numEtage, int numAppartement, bool ascenseur, bool balcon, bool cave, bool garage);
    int getNumEtage();
    int getNumAppartement();
    int getNbPieces();
    bool getGarage();
    bool getCave();
    bool getBalcon();
    bool getAscenseur();
    void setNumEtage(int numEtage);
    void setNumAppartement(int numAppartement);
    void setAscenseur(bool ascenseur);
    void setNbPieces(int nbPieces);
    void setGarage(bool garage);
    void setCave(bool cave);
    void setBalcon(bool balcon);
    void affiche();
};


#endif