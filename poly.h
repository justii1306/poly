#include <stdio.h>
#include <iostream>
#include "wektor.h"

class poly{
public:
    poly();
    poly(double wartosc);
    double& operator[] (int);
    friend std::ostream& operator <<(std::ostream &s, poly &p);
    friend poly operator +(poly, poly);
    friend poly operator *(poly, poly);
    friend poly operator *(double, poly);
    double operator ()(double);
    poly& operator =(int);
private:
    wektor w;
};
