#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>
#include "bien.hpp"
#include "maison.hpp"
#include "appartement.hpp"
#include "garage.hpp"
#include "date.hpp"


class client {
private:
    std::string nom;
    std::string prenom; 
    std::string civilite; // format M. ou Mme
    std::string email; // format xxx@xxx.xxx
    std::string telephone; // format +33 6 12 34 56 78
    // pour les different type de biens, on utilise des classes d'aggregation, car si un client est supprimé, on ne veut pas supprimer ses biens (on ne veut pas supprimer les biens de la base de données)
    std::vector<maison*> maisons;
    std::vector<appartement*> appartements;
    std::vector<garage*> garages;

    unsigned int id;
    double solde;
    date naissance;

public:
    static unsigned int uniqueID;

    // constructeurs
    client();

    // destructeur
    ~client();

    // getters
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getCivilite() const;
    std::string getEmail() const;
    std::string getTelephone() const;
    unsigned int getId() const;
    double getSolde() const;
    date getNaissance() const;

    // setters
    bool setNom(std::string nom);
    bool setPrenom(std::string prenom);
    bool setCivilite(std::string civilite);
    bool setEmail(std::string email);
    bool setTelephone(std::string telephone);
    bool setId(unsigned int id);
    bool setSolde(double solde);
    bool setJourNaissance(int jour);
    bool setMoisNaissance(int mois);
    bool setAnneeNaissance(int annee);

    // methodes
    void addMaison(maison *maison);
    void addAppartement(appartement *appartement);
    void addGarage(garage *garage);
    void removeMaison(maison *maison);
    void removeAppartement(appartement *appartement);
    void removeGarage(garage *garage);
    virtual void afficherBiens() const;

    // operateurs de comparaison entre deux clients avec leur nom et prenom
    bool operator==(const client &c) const;

};



#endif