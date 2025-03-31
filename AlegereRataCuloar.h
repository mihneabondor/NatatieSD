#ifndef ALEGERERATACULOAR_H
#define ALEGERERATACULOAR_H

#include "Rata.h"
#include "Culoar.h"
#include "VectorDinamic.h"



double alegereRataCuloar(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare);
void sorteazaRate(VectorDinamic<Rata>& rate);
void sorteazaCuloare(VectorDinamic<Culoar>& culoare);
double calculeazaTimp(const Rata& rata, const Culoar& culoar);

#endif // ALEGERERATACULOAR_H
