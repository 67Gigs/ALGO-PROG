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
    std::ofstream OutputFile("./files/data.dat", std::ios::binary | std::ios::app);
    

    if (!InputFile || !OutputFile) {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return 1;
    }


    // Création d'un bien
    bien* b1 = new bien();

    // ecriture dans le fichier binaire

    // OutputFile.seekp(0, std::ios::end);
    // OutputFile.write((char*)b1, sizeof(bien));
    // OutputFile.write((char*)b1, sizeof(bien));
    // OutputFile.write((char*)b1, sizeof(bien));
    OutputFile.close();

    // Lecture du fichier jusqu'à la fin
    while (!InputFile.eof()) {
        bien* b = new bien();
        if (InputFile.read((char*)b, sizeof(bien))) {
            biens.push_back(b);
        }
        

    }

    for (int i = 0; i < biens.size(); i++) {
        std::cout << "Bien " << i << std::endl;
        biens[i]->affiche();
        std::cout << std::endl;
    }


    InputFile.close();
    return 0;
}