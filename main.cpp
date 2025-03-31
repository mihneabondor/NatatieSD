#include <iostream>
#include <fstream>
#include <vector>

#include "Culoar.h"
#include "Rata.h"
#include "VectorDinamic.h"

using namespace std;

int main() {
    ifstream f("/Users/mihnea/Documents/GitHub/NatatieSD/Data/01-natatie.in");
    if (!f) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int N,M;
    f >> N >> M;
    vector<int> viteza(N);
    for (int i = 0; i < N; i++) {
        f >> viteza[i];
    }
    vector<int> rezistenta(N);
    for (int i = 0; i < N; i++) {
        f >> rezistenta[i];
    }
    VectorDinamic<Culoar> culoare;
    for (int i = 0; i < M; i++) {
        int x;
        f >> x;
        Culoar c(x);
        culoare.add(c);
    }
    f.close();

    VectorDinamic<Rata> rate;
    for (int i = 0; i < N; i++) {
        Rata r(viteza[i], rezistenta[i]);
        rate.add(r);
    }

    for (int i = 0; i < culoare.getSize(); i++)
        cout << culoare[i] << endl;

    return 0;
}