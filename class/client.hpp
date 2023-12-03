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

public:
    client();
    client(std::string nom, std::string prenom, std::string civilite, std::string email, std::string telephone);

};



#endif