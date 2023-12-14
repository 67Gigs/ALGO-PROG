#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>
#include "bien.hpp"
#include "maison.hpp"
#include "appartement.hpp"
#include "garage.hpp"


class client {
private:
    std::string nom;
    std::string prenom; 
    std::string civilite; // format M. ou Mme
    std::string email; // format xxx@xxx.xxx
    std::string telephone; // format +33 6 12 34 56 78
    // pour les different type de biens, on utilise des classes d'aggregation, car si un client est supprimé, on ne veut pas supprimer ses biens (on ne veut pas supprimer les biens de la base de données)
    std::vector<maison> maisons;
    std::vector<appartement> appartements;
    std::vector<garage> garages;
    unsigned int id;

public:
    static unsigned int uniqueID;
    
    // constructeurs
    client();

    // destructeur
    ~client();

    // getters
    std::string getNom();
    std::string getPrenom();
    std::string getCivilite();
    std::string getEmail();
    std::string getTelephone();
    unsigned int getId();

    // setters
    void setNom(std::string nom);
    void setPrenom(std::string prenom);
    void setCivilite(std::string civilite);
    void setEmail(std::string email);
    void setTelephone(std::string telephone);
    void setId(unsigned int id);

    // methodes
    void addMaison(maison maison);
    void addAppartement(appartement appartement);
    void addGarage(garage garage);
    void removeMaison(maison maison);
    void removeAppartement(appartement appartement);
    void removeGarage(garage garage);
    virtual void afficherBiens();
    
};



#endif