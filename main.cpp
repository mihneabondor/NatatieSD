#include <iostream>

#include "Culoar.h"
#include "Rata.h"
#include "VectorDinamic.h"
#include "AlegereRataCuloar.h"

using namespace std;

int main() {
    VectorDinamic<Rata> rate;
    Rata r1(1, 1), r2(2, 2), r3(3, 3), r4(4, 4), r5(5, 5);
    rate.add(r2);
    rate.add(r1);
    rate.add(r3);
    rate.add(r5);
    rate.add(r4);

    for (int i = 0; i < rate.getSize(); i++)
        cout << rate[i] << '\n';
    // ratele sunt sortate automat dupa rezistenta si culoarele dupa dimensiune

    VectorDinamic<Culoar> culoare;
    Culoar c1(1), c2(2), c3(3), c4(4), c5(5);
    culoare.add(c2);
    culoare.add(c1);
    culoare.add(c5);
    culoare.add(c3);
    culoare.add(c2);

    for (int i = 0; i < culoare.getSize(); i++)
        cout << culoare[i] << '\n';
    double timpMaxim = alegereRataCuloar(rate, culoare);

    // Afișăm rezultatul
    cout << "Timpul maxim al cursei este: " << timpMaxim << " unitati de timp." << endl;

    return 0;
}
