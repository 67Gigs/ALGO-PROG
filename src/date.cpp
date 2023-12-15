#include "../class/date.hpp"
#include <iostream>

date::date() {
    jour = 0;
    mois = 0;
    annee = 0;
}

date::~date() {
    std::cout << "date detruite" << std::endl;
}