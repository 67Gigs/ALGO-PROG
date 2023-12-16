#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "src/function.cpp"

#include "src/bien.cpp"
#include "src/maison.cpp"
#include "src/appartement.cpp"
#include "src/client.cpp"
#include "src/garage.cpp"
#include "src/date.cpp"

#include "nlohmann/json.hpp"




using json = nlohmann::json;


int main() {
    
    // std::ifstream inputFile("./files/data.json");
    std::ifstream inputClient("./files/clients.json");
    std::ifstream inputMaison("./files/maisons.json");
    std::ifstream inputAppartement("./files/appartements.json");
    std::ifstream inputGarage("./files/garages.json");
    std::vector<bien*> biens;
    std::vector<maison*> maisons;
    std::vector<appartement*> appartements;
    std::vector<client*> clients;
    std::vector<garage*> garages;
    json jsonData, jsonClient, jsonMaison, jsonAppartement, jsonGarage;
    int j = 0;
    int i = 0;
    int maxId = 0;
    int choix;

    // lecture de fichier

    if (!inputAppartement.is_open() || !inputClient.is_open() || !inputMaison.is_open() || !inputGarage.is_open()) {
        std::cout << "Erreur lors de l'ouverture des fichiers" << std::endl;
        return 1;
    } else {

        jsonClient = json::parse(inputClient);
        inputClient.close();
        jsonMaison = json::parse(inputMaison);
        inputMaison.close();
        jsonAppartement = json::parse(inputAppartement);
        inputAppartement.close();
        jsonGarage = json::parse(inputGarage);
        inputGarage.close();
        
    }

    // stockage des données dans les vecteurs
    i = 0;
    for (auto& c : jsonClient) {
        client *cl = new client();
        cl->setNom(c[i]["nom"]);
        cl->setPrenom(c[i]["prenom"]);
        cl->setCivilite(c[i]["civilite"]);
        cl->setEmail(c[i]["email"]);
        cl->setTelephone(c[i]["telephone"]);
        cl->setId(c[i]["id"]);
        cl->setSolde(c[i]["solde"]);
        cl->setJourNaissance(c[i]["jourNaissance"]);
        cl->setMoisNaissance(c[i]["moisNaissance"]);
        cl->setAnneeNaissance(c[i]["anneeNaissance"]);
        clients.push_back(cl);
        // std::cout << "Client " << cl->getNom() << " " << cl->getPrenom() << " ajoute" << std::endl;
        i++;
    }

    for (size_t i = 0; i < clients.size(); i++) {
        if (clients[i]->getId() > maxId) {
            maxId = clients[i]->getId();
        }
    }

    client::uniqueID = maxId + 1;

    i = 0;
    for (auto& m : jsonMaison) {
        maison *ma = new maison();
        ma->setAdresse(m[i]["adresse"]);
        ma->setSurface(m[i]["surface"]);
        ma->setPrix(m[i]["prix"]);
        ma->setNbPieces(m[i]["nbPieces"]);
        ma->setGarage(m[i]["garage"]);
        ma->setJardin(m[i]["jardin"]);
        ma->setPiscine(m[i]["piscine"]);
        ma->setCave(m[i]["cave"]);
        for (auto& c : clients) {
            if (ma->getIdClient() == 0) {
                break;
            }
            if (c->getId() == m[i]["idClient"]) {
                c->addMaison(ma);
                break;
            }
        }
        i++;
        maisons.push_back(ma);
    }

    i = 0;
    for (auto& a : jsonAppartement) {
        appartement *ap = new appartement();
        ap->setAdresse(a[i]["adresse"]);
        ap->setSurface(a[i]["surface"]);
        ap->setPrix(a[i]["prix"]);
        ap->setNbPieces(a[i]["nbPieces"]);
        ap->setNumEtage(a[i]["numEtage"]);
        ap->setNumAppartement(a[i]["numAppartement"]);
        ap->setAscenseur(a[i]["ascenseur"]);
        ap->setBalcon(a[i]["balcon"]);
        ap->setGarage(a[i]["garage"]);
        for (auto& c : clients) {
            if (ap->getIdClient() == 0) {
                break;
            }
            if (c->getId() == a[i]["idClient"]) {
                c->addAppartement(ap);
                break;
            }
        }

        i++;
        appartements.push_back(ap);
    }

    i = 0;
    for (auto& g : jsonGarage) {
        garage *ga = new garage();
        ga->setAdresse(g[i]["adresse"]);
        ga->setSurface(g[i]["surface"]);
        ga->setPrix(g[i]["prix"]);
        ga->setFerme(g[i]["ferme"]);
        ga->setAlarme(g[i]["alarme"]);
        ga->setBox(g[i]["box"]);
        for (auto& c : clients) {
            if (ga->getIdClient() == 0) {
                break;
            }
            if (c->getId() == g[i]["idClient"]) {
                c->addGarage(ga);
                break;
            }
        }
        
        i++;
        garages.push_back(ga);
    }

    // getch();

    // programme principal

    // menu
    while (true) {
        system("cls");
        afficherMenu();
        if (!(std::cin >> choix)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            choix = -1;
        }

        if (choix == 1) { // ajouter un bien
            system("cls");
            ajoutBien();
            if (!(std::cin >> choix)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                choix = -1;
            }
            system("cls");
            if (choix == 0) {
                continue;
            } else if (choix == 1) {
                maison *ma = new maison();
                std::string adresse;
                int surface;
                int prix;
                int nbPieces;
                bool garage;
                bool jardin;
                bool piscine;
                bool cave;
                int idClient;

                std::cout << "----------------------------------------" << std::endl;
                std::cout << "Ajout d'une maison" << std::endl;
                std::cout << "----------------------------------------" << std::endl;
                std::cout << "Adresse : ";
                std::getline(std::cin >> std::ws, adresse);
                ma->setAdresse(adresse);
                
                std::cout << "Surface : ";
                if (!(std::cin >> surface)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    surface = -1;
                }
                while (!ma->setSurface(surface)) {
                    std::cout << "Surface : ";
                    if (!(std::cin >> surface)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        surface = -1;
                    }                    
                }

                std::cout << "Prix : ";
                if (!(std::cin >> prix)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    prix = -1;
                }
                while (!ma->setPrix(prix)) {
                    std::cout << "Prix : ";
                    if (!(std::cin >> prix)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        prix = -1;
                    }                    
                }

                std::cout << "Nombre de pieces : ";
                if (!(std::cin >> nbPieces)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    nbPieces = -1;
                }
                while (!ma->setNbPieces(nbPieces)) {
                    std::cout << "Nombre de pieces : ";
                    if (!(std::cin >> nbPieces)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        nbPieces = -1;
                    }                    
                }

                std::cout << "Garage (false/true) : ";
                if (!(std::cin >> garage)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    garage = -1;
                }
                while (!ma->setGarage(garage)) {
                    std::cout << "Garage (false/true) : ";
                    if (!(std::cin >> garage)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        garage = -1;
                    }                    
                }

                std::cout << "Jardin (false/true) : ";
                if (!(std::cin >> jardin)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    jardin = -1;
                }
                while (!ma->setJardin(jardin)) {
                    std::cout << "Jardin (false/true) : ";
                    if (!(std::cin >> jardin)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        jardin = -1;
                    }                    
                }

                std::cout << "Piscine (false/true) : ";
                if (!(std::cin >> piscine)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    piscine = -1;
                }
                while (!ma->setPiscine(piscine)) {
                    std::cout << "Piscine (false/true) : ";
                    if (!(std::cin >> piscine)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        piscine = -1;
                    }                    
                }

                std::cout << "Cave (false/true) : ";
                if (!(std::cin >> cave)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    cave = -1;
                }
                while (!ma->setCave(cave)) {
                    std::cout << "Cave (false/true) : ";
                    if (!(std::cin >> cave)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        cave = -1;
                    }                    
                }

                std::cout << "ID du client : ";
                if (!(std::cin >> idClient)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    idClient = -1;
                }
                while (idClient < 0) {
                    std::cout << "ID du client : ";
                    if (!(std::cin >> idClient)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        idClient = -1;
                    }
                }
                ma->setIdClient(idClient);

                if (idClient != 0) {
                    for (auto& c : clients) {
                        if (c->getId() == idClient) {
                            c->addMaison(ma);
                            break;
                        }
                    }
                }

                maisons.push_back(ma);

            } else if (choix == 2) {
                appartement *ap = new appartement();
                std::string adresse;
                int surface;
                int prix;
                int nbPieces;
                int numEtage;
                int numAppartement;
                bool ascenseur;
                bool balcon;
                bool garage;
                int idClient;

                std::cout << "----------------------------------------" << std::endl;
                std::cout << "Ajout d'un appartement" << std::endl;
                std::cout << "----------------------------------------" << std::endl;

                std::cout << "Adresse : ";
                std::getline(std::cin >> std::ws, adresse);
                ap->setAdresse(adresse);

                std::cout << "Surface : ";
                if (!(std::cin >> surface)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    surface = -1;
                }
                while (!ap->setSurface(surface)) {
                    std::cout << "Surface : ";
                    if (!(std::cin >> surface)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        surface = -1;
                    }                    
                }

                std::cout << "Prix : ";
                if (!(std::cin >> prix)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    prix = -1;
                }
                while (!ap->setPrix(prix)) {
                    std::cout << "Prix : ";
                    if (!(std::cin >> prix)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        prix = -1;
                    }                    
                }

                std::cout << "Nombre de pieces : ";
                if (!(std::cin >> nbPieces)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    nbPieces = -1;
                }
                while (!ap->setNbPieces(nbPieces)) {
                    std::cout << "Nombre de pieces : ";
                    if (!(std::cin >> nbPieces)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        nbPieces = -1;
                    }                    
                }

                std::cout << "Numero d'etage : ";
                if (!(std::cin >> numEtage)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    numEtage = -1;
                }
                while (!ap->setNumEtage(numEtage)) {
                    std::cout << "Numero d'etage : ";
                    if (!(std::cin >> numEtage)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        numEtage = -1;
                    }                    
                }

                std::cout << "Numero d'appartement : ";
                if (!(std::cin >> numAppartement)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    numAppartement = -1;
                }
                while (!ap->setNumAppartement(numAppartement)) {
                    std::cout << "Numero d'appartement : ";
                    if (!(std::cin >> numAppartement)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        numAppartement = -1;
                    }                    
                }

                std::cout << "Ascenseur (false/true) : ";
                if (!(std::cin >> ascenseur)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    ascenseur = -1;
                }
                while (!ap->setAscenseur(ascenseur)) {
                    std::cout << "Ascenseur (false/true) : ";
                    if (!(std::cin >> ascenseur)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        ascenseur = -1;
                    }                    
                }

                std::cout << "Balcon (false/true) : ";
                if (!(std::cin >> balcon)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    balcon = -1;
                }
                while (!ap->setBalcon(balcon)) {
                    std::cout << "Balcon (false/true) : ";
                    if (!(std::cin >> balcon)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        balcon = -1;
                    }                    
                }

                std::cout << "Garage (false/true) : ";
                if (!(std::cin >> garage)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    garage = -1;
                }
                while (!ap->setGarage(garage)) {
                    std::cout << "Garage (false/true) : ";
                    if (!(std::cin >> garage)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        garage = -1;
                    }                    
                }

                std::cout << "ID du client : ";
                if (!(std::cin >> idClient)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    idClient = -1;
                }
                while (idClient < 0) {
                    std::cout << "ID du client : ";
                    if (!(std::cin >> idClient)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        idClient = -1;
                    }
                }
                ap->setIdClient(idClient);

                if (idClient != 0) {
                    for (auto& c : clients) {
                        if (c->getId() == idClient) {
                            c->addAppartement(ap);
                            break;
                        }
                    }
                }

                appartements.push_back(ap);


            } else if (choix == 3) {
                garage *ga = new garage();
                std::string adresse;
                int surface;
                int prix;
                bool ferme;
                bool alarme;
                bool box;
                int idClient;

                std::cout << "----------------------------------------" << std::endl;
                std::cout << "Ajout d'un garage" << std::endl;
                std::cout << "----------------------------------------" << std::endl;
                
                std::cout << "Adresse : ";
                std::getline(std::cin >> std::ws, adresse);
                ga->setAdresse(adresse);

                std::cout << "Surface : ";
                if (!(std::cin >> surface)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    surface = -1;
                }
                while (!ga->setSurface(surface)) {
                    std::cout << "Surface : ";
                    if (!(std::cin >> surface)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        surface = -1;
                    }                    
                }

                std::cout << "Prix : ";
                if (!(std::cin >> prix)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    prix = -1;
                }
                while (!ga->setPrix(prix)) {
                    std::cout << "Prix : ";
                    if (!(std::cin >> prix)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        prix = -1;
                    }                    
                }

                std::cout << "Ferme (false/true) : ";
                if (!(std::cin >> ferme)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    ferme = -1;
                }
                while (!ga->setFerme(ferme)) {
                    std::cout << "Ferme (false/true) : ";
                    if (!(std::cin >> ferme)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        ferme = -1;
                    }                    
                }

                std::cout << "Alarme (false/true) : ";
                if (!(std::cin >> alarme)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    alarme = -1;
                }
                while (!ga->setAlarme(alarme)) {
                    std::cout << "Alarme (false/true) : ";
                    if (!(std::cin >> alarme)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        alarme = -1;
                    }                    
                }

                std::cout << "Box (false/true) : ";
                if (!(std::cin >> box)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    box = -1;
                }
                while (!ga->setBox(box)) {
                    std::cout << "Box (false/true) : ";
                    if (!(std::cin >> box)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        box = -1;
                    }                    
                }

                std::cout << "ID du client : ";
                if (!(std::cin >> idClient)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    idClient = -1;
                }
                while (idClient < 0) {
                    std::cout << "ID du client : ";
                    if (!(std::cin >> idClient)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        idClient = -1;
                    }
                }

                ga->setIdClient(idClient);

                if (idClient != 0) {
                    for (auto& c : clients) {
                        if (c->getId() == idClient) {
                            c->addGarage(ga);
                            break;
                        }
                    }
                }

                garages.push_back(ga);

            } else {
                std::cout << "Erreur de saisie" << std::endl;
            }
            std::cout << "Appuyez sur une touche pour continuer" << std::endl;
            getch();


        } else if (choix == 2) { // modifier un bien
            system("cls");
            modifierBien();
            if (!(std::cin >> choix)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                choix = -1;
            }
            system("cls");
            if (choix == 0) {
                continue;
            } else if (choix == 1) {
                for (auto& m : maisons) {
                    m->affiche();
                }
                std::cout << "Donnez l'ID de la maison a modifier : ";
                if (!(std::cin >> choix)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    choix = -1;
                }

                for (auto& m : maisons) {
                    if (m->getId() == choix) {
                        std::string adresse;
                        int surface;
                        int prix;
                        int nbPieces;
                        bool garage;
                        bool jardin;
                        bool piscine;
                        bool cave;
                        int idClient;

                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "Modification d'une maison" << std::endl;
                        std::cout << "----------------------------------------" << std::endl;
                       
                        std::cout << "Adresse : ";
                        std::getline(std::cin >> std::ws, adresse);
                        m->setAdresse(adresse);

                        std::cout << "Surface : ";
                        if (!(std::cin >> surface)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            surface = -1;
                        }
                        while (!m->setSurface(surface)) {
                            std::cout << "Surface : ";
                            if (!(std::cin >> surface)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                surface = -1;
                            }                    
                        }

                        std::cout << "Prix : ";
                        if (!(std::cin >> prix)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            prix = -1;
                        }
                        while (!m->setPrix(prix)) {
                            std::cout << "Prix : ";
                            if (!(std::cin >> prix)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                prix = -1;
                            }                    
                        }


                        std::cout << "Nombre de pieces : ";
                        if (!(std::cin >> nbPieces)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            nbPieces = -1;
                        }
                        while (!m->setNbPieces(nbPieces)) {
                            std::cout << "Nombre de pieces : ";
                            if (!(std::cin >> nbPieces)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                nbPieces = -1;
                            }                    
                        }

                        std::cout << "Garage (false/true) : ";
                        if (!(std::cin >> garage)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            garage = -1;
                        }
                        while (!m->setGarage(garage)) {
                            std::cout << "Garage (false/true) : ";
                            if (!(std::cin >> garage)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                garage = -1;
                            }                    
                        }

                        std::cout << "Jardin (false/true) : ";
                        if (!(std::cin >> jardin)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            jardin = -1;
                        }
                        while (!m->setJardin(jardin)) {
                            std::cout << "Jardin (false/true) : ";
                            if (!(std::cin >> jardin)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                jardin = -1;
                            }                    
                        }

                        std::cout << "Piscine (false/true) : ";
                        if (!(std::cin >> piscine)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            piscine = -1;
                        }
                        while (!m->setPiscine(piscine)) {
                            std::cout << "Piscine (false/true) : ";
                            if (!(std::cin >> piscine)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                piscine = -1;
                            }                    
                        }

                        std::cout << "Cave (false/true) : ";
                        if (!(std::cin >> cave)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            cave = -1;
                        }
                        while (!m->setCave(cave)) {
                            std::cout << "Cave (false/true) : ";
                            if (!(std::cin >> cave)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                cave = -1;
                            }                    
                        }

                        std::cout << "ID du client (0 pour enlever le client) : ";
                        if (!(std::cin >> idClient)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            idClient = -1;
                        }
                        while (idClient < 0) {
                            std::cout << "ID du client (0 pour enlever le client) : ";
                            if (!(std::cin >> idClient)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                idClient = -1;
                            }
                        }

                        for (auto& c : clients) {
                            if (c->getId() == m->getIdClient()) {
                                c->removeMaison(m);
                                break;
                            }
                        }

                        for (auto& c : clients) {
                            if (c->getId() == idClient) {
                                c->addMaison(m);
                                break;
                            }
                        }

                        m->setIdClient(idClient);

                        break;
                    }
                }
            } else if (choix == 2) {
                for (auto& ap : appartements) {
                    ap->affiche();
                }
                std::cout << "Donnez l'ID de l'appartement a modifier : ";
                if (!(std::cin >> choix)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    choix = -1;
                }

                for (auto& ap : appartements) {
                    if (ap->getId() == choix) {
                        std::string adresse;
                        int surface;
                        int prix;
                        int nbPieces;
                        int numEtage;
                        int numAppartement;
                        bool ascenseur;
                        bool balcon;
                        bool garage;
                        int idClient;

                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "Modification d'un appartement" << std::endl;
                        std::cout << "----------------------------------------" << std::endl;
                        
                        std::cout << "Adresse : ";
                        std::getline(std::cin >> std::ws, adresse);
                        ap->setAdresse(adresse);

                        std::cout << "Surface : ";
                        if (!(std::cin >> surface)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            surface = -1;
                        }
                        while (!ap->setSurface(surface)) {
                            std::cout << "Surface : ";
                            if (!(std::cin >> surface)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                surface = -1;
                            }                    
                        }

                        std::cout << "Prix : ";
                        if (!(std::cin >> prix)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            prix = -1;
                        }
                        while (!ap->setPrix(prix)) {
                            std::cout << "Prix : ";
                            if (!(std::cin >> prix)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                prix = -1;
                            }                    
                        }

                        std::cout << "Nombre de pieces : ";
                        if (!(std::cin >> nbPieces)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            nbPieces = -1;
                        }
                        while (!ap->setNbPieces(nbPieces)) {
                            std::cout << "Nombre de pieces : ";
                            if (!(std::cin >> nbPieces)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                nbPieces = -1;
                            }                    
                        }

                        std::cout << "Numero d'etage : ";
                        if (!(std::cin >> numEtage)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            numEtage = -1;
                        }
                        while (!ap->setNumEtage(numEtage)) {
                            std::cout << "Numero d'etage : ";
                            if (!(std::cin >> numEtage)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                numEtage = -1;
                            }                    
                        }

                        std::cout << "Numero d'appartement : ";
                        if (!(std::cin >> numAppartement)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            numAppartement = -1;
                        }
                        while (!ap->setNumAppartement(numAppartement)) {
                            std::cout << "Numero d'appartement : ";
                            if (!(std::cin >> numAppartement)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                numAppartement = -1;
                            }                    
                        }

                        std::cout << "Ascenseur (false/true) : ";
                        if (!(std::cin >> ascenseur)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            ascenseur = -1;
                        }

                        while (!ap->setAscenseur(ascenseur)) {
                            std::cout << "Ascenseur (false/true) : ";
                            if (!(std::cin >> ascenseur)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                ascenseur = -1;
                            }                    
                        }

                        std::cout << "Balcon (false/true) : ";
                        if (!(std::cin >> balcon)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            balcon = -1;
                        }
                        while (!ap->setBalcon(balcon)) {
                            std::cout << "Balcon (false/true) : ";
                            if (!(std::cin >> balcon)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                balcon = -1;
                            }                    
                        }

                        std::cout << "Garage (false/true) : ";
                        if (!(std::cin >> garage)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            garage = -1;
                        }
                        while (!ap->setGarage(garage)) {
                            std::cout << "Garage (false/true) : ";
                            if (!(std::cin >> garage)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                garage = -1;
                            }                    
                        }



                        for (auto& c : clients) {
                            if (c->getId() == ap->getIdClient()) {
                                c->removeAppartement(ap);
                                break;
                            }
                        }

                        for (auto& c : clients) {
                            if (c->getId() == idClient) {
                                c->addAppartement(ap);
                                break;
                            }
                        }

                        ap->setIdClient(idClient);
                        break;
                    }
                }
            } else if (choix == 3) {
                for (auto& g : garages) {
                    g->affiche();
                }
                std::cout << "Donnez l'ID du garage a modifier : ";
                if (!(std::cin >> choix)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    choix = -1;
                }

                for (auto& g : garages) {
                    if (g->getId() == choix) {
                        std::string adresse;
                        int surface;
                        int prix;
                        bool ferme;
                        bool alarme;
                        bool box;
                        int idClient;

                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "Modification d'un garage" << std::endl;
                        std::cout << "----------------------------------------" << std::endl;
                       
                        std::cout << "Adresse : ";
                        std::getline(std::cin >> std::ws, adresse);
                        g->setAdresse(adresse);

                        std::cout << "Surface : ";
                        if (!(std::cin >> surface)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            surface = -1;
                        }
                        while (!g->setSurface(surface)) {
                            std::cout << "Surface : ";
                            if (!(std::cin >> surface)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                surface = -1;
                            }                    
                        }

                        std::cout << "Prix : ";
                        if (!(std::cin >> prix)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            prix = -1;
                        }
                        while (!g->setPrix(prix)) {
                            std::cout << "Prix : ";
                            if (!(std::cin >> prix)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                prix = -1;
                            }                    
                        }

                        std::cout << "Ferme (false/true) : ";
                        if (!(std::cin >> ferme)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            ferme = -1;
                        }
                        while (!g->setFerme(ferme)) {
                            std::cout << "Ferme (false/true) : ";
                            if (!(std::cin >> ferme)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                ferme = -1;
                            }                    
                        }

                        std::cout << "Alarme (false/true) : ";
                        if (!(std::cin >> alarme)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            alarme = -1;
                        }
                        while (!g->setAlarme(alarme)) {
                            std::cout << "Alarme (false/true) : ";
                            if (!(std::cin >> alarme)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                alarme = -1;
                            }                    
                        }

                        std::cout << "Box (false/true) : ";
                        if (!(std::cin >> box)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            box = -1;
                        }
                        while (!g->setBox(box)) {
                            std::cout << "Box (false/true) : ";
                            if (!(std::cin >> box)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                box = -1;
                            }                    
                        }

                        std::cout << "ID du client (0 pour enlever le client) : ";
                        if (!(std::cin >> idClient)) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            idClient = -1;
                        }
                        while (idClient < 0) {
                            std::cout << "ID du client (0 pour enlever le client) : ";
                            if (!(std::cin >> idClient)) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                idClient = -1;
                            }
                        }

                        for (auto& c : clients) {
                            if (c->getId() == g->getIdClient()) {
                                c->removeGarage(g);
                                break;
                            }
                        }

                        for (auto& c : clients) {
                            if (c->getId() == idClient) {
                                c->addGarage(g);
                                break;
                            }
                        }

                        g->setIdClient(idClient);
                        break;
                    }
                }
            } else {
                std::cout << "Erreur de saisie" << std::endl;
            }

            std::cout << "Appuyez sur une touche pour continuer" << std::endl;
            getch();

        } else if (choix == 3) { // supprimer un bien
            system("cls");
            supprimerBien();
            if (!(std::cin >> choix)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                choix = -1;
            }
            system("cls");
            if (choix == 0) {
                continue;
            } else if (choix == 1) {
                for (auto& m : maisons) {
                    m->affiche();
                }
                std::cout << "Donnez l'ID de la maison a supprimer : ";
                if (!(std::cin >> choix)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    choix = -1;
                }

                if (choix == 0) {
                    continue;
                } else if (choix > 0) {
                    for (auto& m : maisons) {
                        if (m->getId() == choix) {
                            maisons.erase(maisons.begin() + i);
                            break;
                        }
                        i++;
                    }
                    std::cout << "Maison supprimee" << std::endl;
                    std::cout << "Appuyez sur une touche pour continuer" << std::endl;
                    getch();
                } else {
                    std::cout << "Erreur de saisie" << std::endl;
                    std::cout << "Appuyez sur une touche pour continuer" << std::endl;
                    getch();
                }
            } else if (choix == 2) {
                for (auto& ap : appartements) {
                    ap->affiche();
                }
                std::cout << "Donnez l'ID de l'appartement a supprimer : ";
                if (!(std::cin >> choix)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    choix = -1;
                }

                if (choix == 0) {
                    continue;
                } else if (choix > 0) {
                    for (auto& ap : appartements) {
                        if (ap->getId() == choix) {
                            appartements.erase(appartements.begin() + i);
                            break;
                        }
                        i++;
                    }
                    std::cout << "Appartement supprime" << std::endl;
                    std::cout << "Appuyez sur une touche pour continuer" << std::endl;
                    getch();
                } else {
                    std::cout << "Erreur de saisie" << std::endl;
                    std::cout << "Appuyez sur une touche pour continuer" << std::endl;
                    getch();
                }
            } else if (choix == 3) {
                for (auto& g : garages) {
                    g->affiche();
                }
                std::cout << "Donnez l'ID du garage a supprimer : ";
                if (!(std::cin >> choix)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    choix = -1;
                }
                if (choix == 0) {
                    continue;
                } else if (choix > 0) {
                    for (auto& g : garages) {
                        if (g->getId() == choix) {
                            garages.erase(garages.begin() + i);
                            break;
                        }
                        i++;
                    }
                    std::cout << "Garage supprime" << std::endl;
                    std::cout << "Appuyez sur une touche pour continuer" << std::endl;
                    getch();
                } else {
                    std::cout << "Erreur de saisie" << std::endl;
                    std::cout << "Appuyez sur une touche pour continuer" << std::endl;
                    getch();
                }
            } else {
                std::cout << "Erreur de saisie" << std::endl;
                
            }
            std::cout << "Appuyez sur une touche pour continuer" << std::endl;
            getch();   
        } else if (choix == 4) { // afficher les biens
            system("cls");
            afficherBiens();
            if (!(std::cin >> choix)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                choix = -1;
            }
            system("cls");
            if (choix == 0) {
                continue;
            } else if (choix == 1) {
                system("cls");
                for (auto& m : maisons) {
                    m->affiche();
                }
            } else if (choix == 2) {
                system("cls");
                for (auto& ap : appartements) {
                    ap->affiche();
                }
            } else if (choix == 3) {
                system("cls");
                for (auto& g : garages) {
                    g->affiche();
                }
            } else {
                std::cout << "Erreur de saisie" << std::endl;
            }
            std::cout << "Appuyez sur une touche pour continuer" << std::endl;
            getch();

        } else if (choix == 5) { // ajouter un client
            system("cls");
            // fonction ajout client
            client *clTMP = new client();
            std::string civilite;
            std::string nom;
            std::string prenom;
            std::string email;
            std::string telephone;
            int jourNaissance;
            int moisNaissance;
            int anneeNaissance;

            std::cout << "----------------------------------------" << std::endl;
            std::cout << "Ajout d'un client" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            std::cout << "Civilite (M./Mme) : ";
            if (!(std::cin >> civilite)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                civilite = "";
            }
            while (civilite != "M." && civilite != "Mme") {
                std::cout << "Civilite : ";
                std::cin >> civilite;
            }

            clTMP->setCivilite(civilite);

            std::cout << "Nom : ";
            std::getline(std::cin >> std::ws, nom);

            std::cout << "Prenom : ";
            std::getline(std::cin >> std::ws, prenom);

            for (auto& c : clients) {
                if (c == clTMP) {
                    std::cout << "Client deja existant" << std::endl;
                    std::cout << "Appuyez sur une touche pour continuer" << std::endl;
                    getch();
                    break;
                }
            }

            clTMP->setNom(nom);
            clTMP->setPrenom(prenom);

            std::cout << "Email : ";
            std::getline(std::cin >> std::ws, email);
            clTMP->setEmail(email);

            std::cout << "Telephone : ";
            std::getline(std::cin >> std::ws, telephone);
            while(clTMP->setTelephone(telephone) == false) {
                std::cout << "Telephone : ";
                std::getline(std::cin >> std::ws, telephone);
            }

            std::cout << "Jour de naissance : ";
            if (!(std::cin >> jourNaissance)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                jourNaissance = -1;
            }
            while (!clTMP->setJourNaissance(jourNaissance)) {
                std::cout << "Jour de naissance : ";
                std::cin >> jourNaissance;
            }

            std::cout << "Mois de naissance : ";
            if (!(std::cin >> moisNaissance)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                moisNaissance = -1;
            }
            while (!clTMP->setMoisNaissance(moisNaissance)) {
                std::cout << "Mois de naissance : ";
                std::cin >> moisNaissance;
            }

            std::cout << "Annee de naissance : ";
            if (!(std::cin >> anneeNaissance)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                anneeNaissance = -1;
            }
            while (!clTMP->setAnneeNaissance(anneeNaissance)) {
                std::cout << "Annee de naissance : ";
                std::cin >> anneeNaissance;
            }

            clients.push_back(clTMP);

        } else if (choix == 6) { // modifier un client
            system("cls");
            // fonction modifier client
            std::cout << "----------------------------------------" << std::endl;
            std::cout << "Liste des clients" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            for (auto& c : clients) {
                std::cout << "ID : " << c->getId() << std::endl;
                std::cout << c->getCivilite() << " " << c->getNom() << " " << c->getPrenom() << std::endl;
                std::cout << "----------------------------------------" << std::endl;
            }
            std::cout << "Donnez l'ID du client a modifier : ";
            if (!(std::cin >> choix)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                choix = -1;
            }

            for (auto& c : clients) {
                if (c->getId() == choix) {
                    std::string civilite;
                    std::string nom;
                    std::string prenom;
                    std::string email;
                    std::string telephone;
                    int jourNaissance;
                    int moisNaissance;
                    int anneeNaissance;

                    std::cout << "----------------------------------------" << std::endl;
                    std::cout << "Modification d'un client" << std::endl;
                    std::cout << "----------------------------------------" << std::endl;
                    std::cout << "Civilite (M./Mme) : ";
                    if (!(std::cin >> civilite)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        civilite = "";
                    }
                    while (civilite != "M." && civilite != "Mme") {
                        std::cout << "Civilite : ";
                        std::cin >> civilite;
                    }
                    std::cout << "Nom : ";
                    std::getline(std::cin >> std::ws, nom);
                    c->setNom(nom);
                    
                    std::cout << "Prenom : ";
                    std::getline(std::cin >> std::ws, prenom);
                    c->setPrenom(prenom);

                    std::cout << "Email : ";
                    std::getline(std::cin >> std::ws, email);
                    c->setEmail(email);

                    std::cout << "Telephone : ";
                    std::getline(std::cin >> std::ws, telephone);
                    while(c->setTelephone(telephone) == false) {
                        std::cout << "Telephone : ";
                        std::getline(std::cin >> std::ws, telephone);
                    }

                    std::cout << "Jour de naissance : ";
                    if (!(std::cin >> jourNaissance)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        jourNaissance = -1;
                    }
                    while (!c->setJourNaissance(jourNaissance)) {
                        std::cout << "Jour de naissance : ";
                        std::cin >> jourNaissance;
                    }

                    std::cout << "Mois de naissance : ";
                    if (!(std::cin >> moisNaissance)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        moisNaissance = -1;
                    }

                    while (!c->setMoisNaissance(moisNaissance)) {
                        std::cout << "Mois de naissance : ";
                        std::cin >> moisNaissance;
                    }

                    std::cout << "Annee de naissance : ";
                    if (!(std::cin >> anneeNaissance)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        anneeNaissance = -1;
                    }
                    while (!c->setAnneeNaissance(anneeNaissance)) {
                        std::cout << "Annee de naissance : ";
                        std::cin >> anneeNaissance;
                    }
                    break;
                }
            }

        } else if (choix == 7) { // supprimer un client
            system("cls");
            // fonction supprimer client

            std::cout << "----------------------------------------" << std::endl;
            std::cout << "Liste des clients" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            for (auto& c : clients) {
                std::cout << "ID : " << c->getId() << std::endl;
                std::cout << c->getCivilite() << " " << c->getNom() << " " << c->getPrenom() << std::endl;
                std::cout << "----------------------------------------" << std::endl;
            }
            std::cout << "Donnez l'ID du client a supprimer : ";
            if (!(std::cin >> choix)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                choix = -1;
            }

            if (choix == 0) {
                continue;
            } else if (choix > 0) {
                for (auto& c : clients) {
                    if (c->getId() == choix) {
                        clients.erase(clients.begin() + i);
                        break;
                    }
                    i++;
                }
                std::cout << "Client supprime" << std::endl;
                std::cout << "Appuyez sur une touche pour continuer" << std::endl;
                getch();
            } else {
                std::cout << "Erreur de saisie" << std::endl;
                std::cout << "Appuyez sur une touche pour continuer" << std::endl;
                getch();
            }
        } else if (choix == 8) { // afficher les clients
            system("cls");
            // fonction afficher clients
            std::cout << "----------------------------------------" << std::endl;
            std::cout << "Liste des clients" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            for (auto& c : clients) {
                std::cout << "ID : " << c->getId() << std::endl;
                std::cout << c->getCivilite() << " " << c->getNom() << " " << c->getPrenom() << std::endl;
                std::cout << "Email : " << c->getEmail() << std::endl;
                std::cout << "Telephone : " << c->getTelephone() << std::endl;
                std::cout << "Solde : " << c->getSolde() << std::endl;
                std::cout << "Bien : " << std::endl;
                c->afficherBiens();
                std::cout << "----------------------------------------" << std::endl;
            }
            std::cout << "Appuyez sur une touche pour continuer" << std::endl;
            getch();
        } else if (choix == 9) { // sauvegarder  
            system("cls");

            jsonClient = json::array();
            jsonMaison = json::array();
            jsonAppartement = json::array();
            jsonGarage = json::array();

            j = 0;
            for (auto& c : clients) {
                jsonClient[j].push_back({
                    {"nom", c->getNom()},
                    {"prenom", c->getPrenom()},
                    {"civilite", c->getCivilite()},
                    {"email", c->getEmail()},
                    {"telephone", c->getTelephone()},
                    {"id", c->getId()}
                });
                j++;
            }

            j = 0;
            for (auto& m : maisons) {
                jsonMaison[j].push_back({
                    {"adresse", m->getAdresse()},
                    {"surface", m->getSurface()},
                    {"prix", m->getPrix()},
                    {"nbPieces", m->getNbPieces()},
                    {"garage", m->getGarage()},
                    {"jardin", m->getJardin()},
                    {"piscine", m->getPiscine()},
                    {"cave", m->getCave()},
                    {"idClient", m->getIdClient()}
                });
                j++;
            }

            j = 0;
            for (auto& a : appartements) {
                jsonAppartement[j].push_back({
                    {"adresse", a->getAdresse()},
                    {"surface", a->getSurface()},
                    {"prix", a->getPrix()},
                    {"nbPieces", a->getNbPieces()},
                    {"numEtage", a->getNumEtage()},
                    {"numAppartement", a->getNumAppartement()},
                    {"ascenseur", a->getAscenseur()},
                    {"balcon", a->getBalcon()},
                    {"garage", a->getGarage()},
                    {"idClient", a->getIdClient()}
                });
                j++;
            }

            j = 0;
            for (auto& g : garages) {
                jsonGarage[j].push_back({
                    {"adresse", g->getAdresse()},
                    {"surface", g->getSurface()},
                    {"prix", g->getPrix()},
                    {"ferme", g->getFerme()},
                    {"alarme", g->getAlarme()},
                    {"box", g->getBox()},
                    {"idClient", g->getIdClient()}
                });
                j++;
            }

            // sauvegarde dans les fichiers
            
            std::ofstream outputClient("./files/clients.json", std::ios::out | std::ios::trunc);
            outputClient << jsonClient;

            std::ofstream outputMaison("./files/maisons.json", std::ios::out | std::ios::trunc);
            outputMaison << jsonMaison;

            std::ofstream outputAppartement("./files/appartements.json", std::ios::out | std::ios::trunc);
            outputAppartement << jsonAppartement;

            std::ofstream outputGarage("./files/garages.json", std::ios::out | std::ios::trunc);
            outputGarage << jsonGarage;

            outputClient.close();
            outputAppartement.close();
            outputMaison.close();
            outputGarage.close();

            std::cout << "Sauvegarde effectuee" << std::endl;   
            std::cout << "Appuyez sur une touche pour continuer" << std::endl;
            getch();

        } else if (choix == 0) { // quitter
            
            system("cls");
            std::cout << "Au revoir !" << std::endl;
            break;
                
        } else {
            system("cls");
            std::cout << "Erreur de saisie" << std::endl;
            std::cout << "Appuyez sur une touche pour continuer" << std::endl;
            // stop le programme jusqu'à ce qu'une touche soit appuyée
            getch();
        }
    }
    







   

    // en fin de programme, on réécrit les fichiers
    // stockage des données dans les objet json

    jsonClient = json::array();
    jsonMaison = json::array();
    jsonAppartement = json::array();
    jsonGarage = json::array();


    j = 0;
    for (auto& c : clients) {
        jsonClient[j].push_back({
            {"nom", c->getNom()},
            {"prenom", c->getPrenom()},
            {"civilite", c->getCivilite()},
            {"email", c->getEmail()},
            {"telephone", c->getTelephone()},
            {"id", c->getId()},
            {"solde", c->getSolde()},
            {"jourNaissance", c->getNaissance().jour},
            {"moisNaissance", c->getNaissance().mois},
            {"anneeNaissance", c->getNaissance().annee}
        });
        j++;
    }

    j = 0;
    for (auto& m : maisons) {
        jsonMaison[j].push_back({
            {"adresse", m->getAdresse()},
            {"surface", m->getSurface()},
            {"prix", m->getPrix()},
            {"nbPieces", m->getNbPieces()},
            {"garage", m->getGarage()},
            {"jardin", m->getJardin()},
            {"piscine", m->getPiscine()},
            {"cave", m->getCave()},
            {"idClient", m->getIdClient()}
        });
        j++;
    }

    j = 0;
    for (auto& a : appartements) {
        jsonAppartement[j].push_back({
            {"adresse", a->getAdresse()},
            {"surface", a->getSurface()},
            {"prix", a->getPrix()},
            {"nbPieces", a->getNbPieces()},
            {"numEtage", a->getNumEtage()},
            {"numAppartement", a->getNumAppartement()},
            {"ascenseur", a->getAscenseur()},
            {"balcon", a->getBalcon()},
            {"garage", a->getGarage()},
            {"idClient", a->getIdClient()}
        });
        j++;
    }

    j = 0;
    for (auto& g : garages) {
        jsonGarage[j].push_back({
            {"adresse", g->getAdresse()},
            {"surface", g->getSurface()},
            {"prix", g->getPrix()},
            {"ferme", g->getFerme()},
            {"alarme", g->getAlarme()},
            {"box", g->getBox()},
            {"idClient", g->getIdClient()}
        });
        j++;
    }

    // std::cout << jsonData << std::endl;

    // écriture dans les fichiers

    std::ofstream outputClient("./files/clients.json", std::ios::out | std::ios::trunc);
    outputClient << jsonClient;

    std::ofstream outputMaison("./files/maisons.json", std::ios::out | std::ios::trunc);
    outputMaison << jsonMaison;

    std::ofstream outputAppartement("./files/appartements.json", std::ios::out | std::ios::trunc);
    outputAppartement << jsonAppartement;

    std::ofstream outputGarage("./files/garages.json", std::ios::out | std::ios::trunc);
    outputGarage << jsonGarage;

    // std::ofstream outputFile("./files/data.json", std::ios::out | std::ios::trunc);
    // outputFile << jsonData;

    // libération de la mémoire
    jsonClient.clear();
    jsonMaison.clear();
    jsonAppartement.clear();
    jsonGarage.clear();


    return 0;
}