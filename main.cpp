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
    
    std::ifstream inputFile("./files/data.json");
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

    if (!inputFile.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
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
        jsonData = json::parse(inputFile);
        inputFile.close();

    }

    // for (auto& c : jsonClient) {
    //     clients.push_back(new client(c["nom"], c["prenom"], c["civilite"], c["email"], c["telephone"]));
    // }






    jsonData = json::array();

    bien b1("1 rue de la paix", 100, 1000);

    biens.push_back(&b1);

    for (auto& b : biens) {
        jsonData[i].push_back({
            {"adresse", b->getAdresse()},
            {"surface", b->getSurface()},
            {"prix", b->getPrix()}
        });
        i++;
    }



    std::cout << jsonData << std::endl;

    std::ofstream outputFile("./files/data.json", std::ios::out | std::ios::trunc);
    outputFile << jsonData;


    return 0;
}