#include <iostream>
#include <fstream>
#include <vector>
#include "Service.h"
#include "Culoar.h"
#include "Rata.h"
#include "VectorDinamic.h"
#include <cassert>

using namespace std;

int main() {
    ifstream f("/Users/mihnea/Documents/GitHub/NatatieSD/Data/01-natatie.in");

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
    cout << getSolutie(rate, culoare) << endl;

    string path = "/Users/mihnea/Documents/GitHub/NatatieSD/Data/01-natatie.out";
    ifstream f2(path);
    double sol;
    f2 >> sol;

    cout << sol << endl;

    return 0;
}