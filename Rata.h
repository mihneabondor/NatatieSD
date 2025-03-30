//
// Created by Mihnea on 3/30/25.
//

#ifndef RATA_H
#define RATA_H
#include <ostream>

class Rata {
  int viteza, rezistenta;

  public:
    Rata();
    Rata(int, int);

    int getViteza() const;
    int getRezistenta() const;


    void setViteza(int);
    void setRezistenta(int);

    bool operator<=(const Rata& r) const;

    friend std::ostream& operator<<(std::ostream& os, const Rata& r);
};



#endif //RATA_H
