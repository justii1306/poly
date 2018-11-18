#include <vector>
#include <stdio.h>
#include <iostream>

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

//private:
    std::vector<double> w;
};

