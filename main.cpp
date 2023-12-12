#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "src/bien.cpp"
#include "src/maison.cpp"
#include "src/appartement.cpp"
#include "nlohmann/json.hpp"


using json = nlohmann::json;


int main() {
    
    std::ifstream inputFile("./files/data.json");
    // std::ofstream outputFile("./files/data.json", std::ios::out | std::ios::trunc);
    
    // std::vector<bien*> biens;
    json jsonData;

    if (!inputFile.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return 1;
    } else {

        // read the file into the json object

        jsonData = json::parse(inputFile);
        inputFile.close();

    }


    std::vector<bien*> biens;

    std::cout << jsonData << std::endl;

    int j = 0;
    
    for (auto& element : jsonData) {
        bien *b;
        

        b = new bien(element[j]["adresse"], element[j]["surface"], element[j]["prix"]);

        biens.push_back(b);

    }

    std::cout << "test" << std::endl;


    jsonData = json::array();

    bien b1("1 rue de la paix", 100, 1000);

    biens.push_back(&b1);

    int i = 0;

    for (auto& b : biens) {
        jsonData[i].push_back({
            {"id", b->getId()},
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