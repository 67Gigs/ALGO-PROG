#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "src/bien.cpp"
#include "src/maison.cpp"
#include "src/appartement.cpp"
#include "src/client.cpp"
#include "src/garage.cpp"

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

    // lecture de fichier

    if (!inputAppartement.is_open() || !inputClient.is_open() || !inputMaison.is_open() || !inputGarage.is_open()) {
        std::cout << "Erreur lors de l'ouverture des fichiers" << std::endl;
        return 1;
    } else {

        // jsonClient = json::parse(inputClient);
        // inputClient.close();
        jsonMaison = json::parse(inputMaison);
        inputMaison.close();
        jsonAppartement = json::parse(inputAppartement);
        inputAppartement.close();
        jsonGarage = json::parse(inputGarage);
        inputGarage.close();
        // jsonData = json::parse(inputFile);
        // inputFile.close();
    }

    // stockage des données dans les vecteurs

    for (auto& c : jsonClient) {
        client *cl = new client();
        cl->setNom(c["nom"]);
        cl->setPrenom(c["prenom"]);
        cl->setCivilite(c["civilite"]);
        cl->setEmail(c["email"]);
        cl->setTelephone(c["telephone"]);
        clients.push_back(cl);
    }

    for (auto& m : jsonMaison) {
        maison *ma = new maison();
        ma->setAdresse(m["adresse"]);
        ma->setSurface(m["surface"]);
        ma->setPrix(m["prix"]);
        ma->setNbPieces(m["nbPieces"]);
        ma->setGarage(m["garage"]);
        ma->setJardin(m["jardin"]);
        ma->setPiscine(m["piscine"]);
        ma->setCave(m["cave"]);
        maisons.push_back(ma);
    }

    for (auto& a : jsonAppartement) {
        appartement *ap = new appartement();
        ap->setAdresse(a["adresse"]);
        ap->setSurface(a["surface"]);
        ap->setPrix(a["prix"]);
        ap->setNbPieces(a["nbPieces"]);
        ap->setNumEtage(a["numEtage"]);
        ap->setNumAppartement(a["numAppartement"]);
        ap->setAscenseur(a["ascenseur"]);
        ap->setBalcon(a["balcon"]);
        ap->setGarage(a["garage"]);
        appartements.push_back(ap);
    }

    for (auto& g : jsonGarage) {
        garage *ga = new garage();
        ga->setAdresse(g["adresse"]);
        ga->setSurface(g["surface"]);
        ga->setPrix(g["prix"]);
        ga->setFerme(g["ferme"]);
        ga->setAlarme(g["alarme"]);
        ga->setBox(g["box"]);
        garages.push_back(ga);
    }


    // reconstruction des objets

    jsonClient = json::array();
    jsonMaison = json::array();
    jsonAppartement = json::array();
    jsonGarage = json::array();

















    // en fin de programme, on réécrit les fichiers
    // stockage des données dans les objet json
    j = 0;
    for (auto& c : clients) {
        jsonClient[j].push_back({
            {"nom", c->getNom()},
            {"prenom", c->getPrenom()},
            {"civilite", c->getCivilite()},
            {"email", c->getEmail()},
            {"telephone", c->getTelephone()}
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
            {"cave", m->getCave()}
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
            {"garage", a->getGarage()}
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
            {"box", g->getBox()}
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


    jsonClient.clear();
    jsonMaison.clear();
    jsonAppartement.clear();
    jsonGarage.clear();


    return 0;
}