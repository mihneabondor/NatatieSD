//
// Created by Mihnea on 3/30/25.
//

#include "Service.h"
using namespace std;
bool config1(VectorDinamic<Rata>& rate) {
    for (int i = 1; i < rate.getSize(); i++)
        if (rate[i-1].getViteza() != rate[i].getViteza())
            return false;
    return true;
}

bool config2(VectorDinamic<Rata>& rate) {
    for (int i = 1; i < rate.getSize(); i++)
        if (rate[i-1].getRezistenta() != rate[i].getRezistenta())
            return false;
    return true;
}

bool config3(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    return rate.getSize() - culoare.getSize() == 1;
}

bool config4(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    for (int i = 0; i < rate.getSize(); i++)
        if (rate[i].getRezistenta() != i)
            return false;
    return culoare.getSize() < rate.getSize() && culoare.getSize() > 1 && rate.getSize() > 1 && culoare.getSize() < 100 && rate.getSize() < 100;
}

int getConfiguratie(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    if (config1(rate))
        return 1;
    if (config2(rate))
        return 2;
    if (config3(rate, culoare))
        return 3;

    return 4;
}

float getTimp(Rata r, Culoar c) {
    return (2.0 * c.getDistanta()) / r.getViteza();
}

float subtask1(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    return getTimp(rate[0], culoare[culoare.getSize() - 1]);
}

float subtask2(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    float minim = 1e9;
    for (int i = 0; i < culoare.getSize(); i++)
        minim = min(minim, getTimp(rate[i], culoare[i]));
    return minim;
}

bool cmp(const Rata &a, const Rata &b) {
    if (a.getRezistenta() == b.getRezistenta())
        return a.getViteza() > b.getViteza();
    return a.getRezistenta() < b.getRezistenta();
}

void sortareRate(VectorDinamic<Rata>& rate) {
    for (int i = 0; i < rate.getSize() - 1; i++)
        for (int j = i + 1; j < rate.getSize(); j++)
            if (cmp(rate[i], rate[j]))
                std::swap(rate[i], rate[j]);
}

float subtask3(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    VectorDinamic<Rata> temp = rate;
    sortareRate(temp);

    float timpMax = 0;
    for (int i = 0; i < culoare.getSize(); ++i) {
        float timp_min = 1e9;
        for (int j = 0; j < rate.getSize(); ++j) {
            if (rate[j].getRezistenta() >= culoare[i].getDistanta()) {
                timp_min = min(timp_min, getTimp(rate[j], culoare[i]));
            }
        }
        timpMax = max(timpMax, timp_min);
    }

    return timpMax;
}

bool validare(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare, float timpMax) {
    vector<bool> folosit(culoare.getSize(), false);
    int count = 0;
    for (int j = 0; j < rate.getSize(); j++) {
        for (int i = 0; i < culoare.getSize(); ++i) {
            if (!folosit[i] && rate[j].getRezistenta() >= culoare[i].getDistanta() && getTimp(rate[j], culoare[i]) <= timpMax) {
                folosit[i] = true;
                count++;
                break;
            }
        }
        if (count == culoare.getSize())
            return true;
    }
    return false;
}

float subtask4(VectorDinamic<float>& timpiPosibili, VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    float rez = 1e9;
    for (int i = 0; i < timpiPosibili.getSize(); i++) {
        if (validare(rate, culoare, timpiPosibili[i])) {
            rez = timpiPosibili[i];
            break;
        }
    }

    return rez;
}

float subtask5(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    int rez = 6000;
    for (int i = 0; i <= 6000; ++i) {
        if (validare(rate, culoare, i)) {
            rez = i;
            break;
        }
    }

    return rez;
}

float subtask6(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    float st = 0, dr = 6000, rez = 6000;
    while (dr - st > 1e-3) {
        float mij = (st + dr) / 2.0;
        if (validare(rate, culoare, mij)) {
            rez = mij;
            dr = mij;
        } else {
            st = mij;
        }
    }

    return rez;
}

float subtask7(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    float st = 0, dr = 6000, rez = 6000;
    while (dr - st > 1e-3) {
        float mij = (st + dr) / 2.0;
        if (validare(rate, culoare, mij)) {
            rez = mij;
            dr = mij;
        } else {
            st = mij;
        }
    }

    return rez;
}

float solutieGenerala(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    VectorDinamic<Rata> temp = rate;
    sortareRate(temp);

    VectorDinamic<float> timpiPosibili;
    for (int i = 0; i < rate.getSize(); i++)
        for (int j = 0; j < culoare.getSize(); j++)
            timpiPosibili.add(getTimp(rate[i], culoare[j]));

    // return subtask4(timpiPosibili, rate, culoare);
    // return subtask5(rate, culoare);
    // return subtask6(rate, culoare);
    return subtask7(rate, culoare);
}

float getSolutie(VectorDinamic<Rata>& rate, VectorDinamic<Culoar>& culoare) {
    if (config1(rate))
        return subtask1(rate, culoare);
    if (config2(rate))
        return subtask2(rate, culoare);
    if (config3(rate, culoare))
        return subtask3(rate, culoare);

    return solutieGenerala(rate, culoare);
}