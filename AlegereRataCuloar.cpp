#include "AlegereRataCuloar.h"
#include <iostream>
using namespace std;
void sorteazaRate(VectorDinamic<Rata>& rate) {
    rate.sort();
}

void sorteazaCuloare(VectorDinamic<Culoar>& culoare) {
    culoare.sort();
}


double calculeazaTimp(const Rata& rata, const Culoar& culoar) {
    return static_cast<double>(culoar.getDistanta()) / rata.getViteza();
}

double alegereRataCuloar(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    sorteazaRate(rate);
    sorteazaCuloare(culoare);
    if (rate.getSize() != culoare.getSize()) {
        cout << "Numărul de rațe nu corespunde cu numărul de culoare!" << std::endl;
        return -1;
    }
    double timpMaxim = 0.0;
    for (int i = 0; i < rate.getSize(); ++i) {
        double timpCurent = calculeazaTimp(rate[i], culoare[i]);
        timpMaxim = max(timpMaxim, timpCurent);
    }
    return timpMaxim;
}
