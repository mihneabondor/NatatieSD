//
// Created by Mihnea on 3/30/25.
//

#ifndef CULOAR_H
#define CULOAR_H
#include <ostream>


class Culoar {
  int distanta;
  public:
    Culoar();
    Culoar(int);

    int getDistanta();

    void setDistanta(int);

    bool operator<=(const Culoar& v) const;

    friend std::ostream& operator<<(std::ostream& os, const Culoar& v) {
        os << v.distanta;
        return os;
    }
};



#endif //CULOAR_H
