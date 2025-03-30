//
// Created by Mihnea on 3/30/25.
//

#include "Rata.h"

Rata::Rata() {
    viteza = 0;
    rezistenta = 0;
}

Rata::Rata(int viteza, int rezistenta) {
    this->viteza = viteza;
    this->rezistenta = rezistenta;
}

int Rata::getViteza() const {
    return viteza;
}

int Rata::getRezistenta() const {
    return rezistenta;
}

void Rata::setViteza(int viteza) {
    this->viteza = viteza;
}

void Rata::setRezistenta(int rezistenta) {
    this->rezistenta = rezistenta;
}

bool Rata::operator<=(const Rata &r) const {
    return rezistenta < r.rezistenta;
}


std::ostream & operator<<(std::ostream &os, const Rata &r) {
    os << r.viteza << " " << r.rezistenta;
    return os;
}
