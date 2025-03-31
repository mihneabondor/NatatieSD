//
// Created by Mihnea on 3/30/25.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "Culoar.h"
#include "Rata.h"
#include "VectorDinamic.h"

int getConfiguratie(VectorDinamic<Rata>&, VectorDinamic<Culoar>&);
float getSolutie(VectorDinamic<Rata>&, VectorDinamic<Culoar>&);
#endif //SERVICE_H