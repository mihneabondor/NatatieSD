//
// Created by Andrei Biro on 31.03.2025.
//

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "VectorDinamic.h"

template <typename T>
void scrieInFisier( VectorDinamic<T>& vec, const std::string& numeFisier) {
    std::ofstream fout(numeFisier);
    if (!fout.is_open()) {
        std::cerr << "Eroare la deschiderea fișierului: " << numeFisier << "\n";
        return;
    }

    for (int i = 0; i < vec.getSize(); i++) {
        fout << vec[i] << "\n";
    }

    fout.close();
}
