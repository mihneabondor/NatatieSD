//
// Created by Mihnea on 3/30/25.
//

#include "Culoar.h"

Culoar::Culoar() {
    distanta = 0;
}

Culoar::Culoar(int distanta) {
    this->distanta = distanta;
}

int Culoar::getDistanta() {
    return distanta;
}

void Culoar::setDistanta(int distanta) {
    this->distanta = distanta;
}

bool Culoar::operator<=(const Culoar &v) const {
    return distanta <= v.distanta;
}
