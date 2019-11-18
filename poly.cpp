#include "poly.h"
#include <stdio.h>
#include <iostream>
#include "wektor.h"

#define polysize 10

poly::poly(){
    this->w.insert(this->w.begin(), polysize, 0.0);
}

poly::poly(double wartosc){
    this->w.insert(this->w.begin(), wartosc);
    this->w.insert(this->w.begin()+1, polysize-1, 0.0);
}


poly operator +(poly P1, poly P2){
    poly temp;
    if(P1.w.size()>P2.w.size()){
        for (int i=0;i<P1.w.size();i++)
            temp[i]=P1[i]+P2[i];
    }else{
        for (int i=0;i<P2.w.size();i++)
            temp[i]=P1[i]+P2[i];
    }
   return temp;
}

poly operator *(poly P1, poly P2){
    poly temp(P1.w.size()+P2.w.size());
    for (int i=0; i<P1.w.size(); i++){
        for (int j=0; j<P2.w.size(); j++)
            temp[i+j] += P1[i]*P2[j];
    }
    return temp;
}

poly operator *(double l, poly P){
    poly temp;
    for (int i=0; i<P.w.size(); i++)
            temp[i] = l*P[i];
    return temp;
}


