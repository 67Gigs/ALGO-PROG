#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "src/bien.cpp"
#include "src/maison.cpp"
#include "src/appartement.cpp"


int main() {
    
    // Création d'un vecteur de biens


    bien* b1 = new bien("1 rue de la paix", 100, 1000);
    bien* b2 = new bien("2 rue de la paix", 200, 2000);
    bien* b3 = new bien("3 rue de la paix", 300, 3000);

    // std::cout << "Bien 1  " << b1->getId() << std::endl;
    // std::cout << "Bien 2  " << b2->getId() << std::endl;
    // std::cout << "Bien 3  " << b3->getId() << std::endl;

    std::vector<bien*> biens;


    // Ouverture du fichier en lecture et écriture
    std::ifstream InputFile("./files/data.dat", std::ios::binary);
    std::ofstream OutputFile("./files/data.dat", std::ios::binary | std::ios::app);

    // Vérification de l'ouverture du fichier
    if (!InputFile || !OutputFile) {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return 1;
    }


    // Création d'un bien
    // bien* b1 = new bien();

    // ecriture dans le fichier binaire

    // exemples d'écriture dans le fichier
    // OutputFile.seekp(0, std::ios::end);
    // OutputFile.write((char*)b1, sizeof(bien));
    // OutputFile.write((char*)b2, sizeof(bien));
    // OutputFile.write((char*)b3, sizeof(bien));
    OutputFile.close();




    // lecture dans le fichier binaire et stocker dans un vecteur
    while (!InputFile.eof()) {
        bien* b = new bien();
        if (InputFile.read((char*)b, sizeof(bien))) {
            bien *b_p = new bien("", b->getSurface(), b->getPrix());
            biens.push_back(b_p);
            std::cout << "Bien " << b_p->getId() << " ajouté" << std::endl;
        }
    }


    // affichage des biens
    for (int i = 0; i < biens.size(); i++) {
        std::cout << "Bien " << i << std::endl;
        std::cout << "Adresse : " << biens[i]->getAdresse() << std::endl;
        std::cout << "Surface : " << biens[i]->getSurface() << std::endl;
        std::cout << "Prix : " << biens[i]->getPrix() << std::endl;
        std::cout << "ID : " << biens[i]->getId() << std::endl;
        std::cout << std::endl;

    }
    InputFile.close();

    
    // Réecrire dans le fichier binaire les biens du vecteur pour garder les modifications    
    OutputFile.open("./files/data.dat", std::ios::binary | std::ios::app);
    for (int i = 0; i < biens.size(); i++) {
        OutputFile.write((char*)biens[i], sizeof(bien));
    }
    OutputFile.close();

    // Suppression des biens
    for (int i = 0; i < biens.size(); i++) {
        delete biens[i];
    }

    std::cout << "Fin du programme" << std::endl;

    return 0;
}