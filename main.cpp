#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "src/bien.cpp"
#include "src/maison.cpp"
#include "src/appartement.cpp"


int main() {
    
    // Création d'un vecteur de biens
    std::vector<bien*> biens;

    std::ifstream InputFile("./files/data.dat", std::ios::binary);
    std::ofstream OutputFile("./files/data.dat", std::ios::binary);
    
    if (!InputFile || !OutputFile) {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return 1;
    }


    // Création d'un bien
    bien* b1 = new bien();
    OutputFile.write((char*)b1, sizeof(bien));
    OutputFile.write((char*)b1, sizeof(bien));
    OutputFile.write((char*)b1, sizeof(bien));

    for (int i = 0; i < 3; i++) {
        bien* b = new bien();
        InputFile.read((char*)b, sizeof(bien));
        biens.push_back(b);
    }

    for (int i = 0; i < biens.size(); i++) {
        std::cout << "Bien " << i << std::endl;
        biens[i]->affiche();
        std::cout << std::endl;
    }


    
    return 0;
}