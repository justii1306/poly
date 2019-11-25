#include "poly.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>


poly::poly(){
  this->size = 1;
  vec = (double*)calloc(this->size, sizeof(double));
}

poly::poly(int value){
  this->size = 1;
  vec = (double*)calloc(this->size, sizeof(double));
  vec[0] = value;
}

poly::poly(const poly& P){
  this->size = P.size;
  this->vec = (double*)calloc(this->size, sizeof(double));
  for (int i=0; i < this->size; i++)
    this->vec[i] = P.vec[i];
}

poly::poly(int size, int second_constructor_just_for_the_sake_of_not_writing_different_function){
  this->size = size;
  this->vec = (double*)calloc(this->size, sizeof(double));
}

poly::~poly(){
  free(vec);
}

double& poly::operator[] (int i){
  if (i >= this->size){
    int oldsize = this->size;
    this->size = i+1;
    double* temp;
    temp = (double*) realloc(vec, this->size * sizeof(double));
    if(!temp){
      std::cout << "Realloc error!" << std::endl;
      free(vec);
      exit(EXIT_FAILURE);
    } else {
      for (int j=this->size-1;j>oldsize-1;j--){
        temp[j] = 0;}
      vec = temp;
    }
  }
  return vec[i];
}

std::ostream& operator <<(std::ostream &s, poly &P){
    for (int n = P.size-1; n>0;n--){
        if ((P.vec[n]) != 0){
            s << (P.vec[n]) << "x^"<< n << " + ";
        }
    }
    if ((P.vec[0]) != 0){
        s << (P.vec[0]);
    }
    return s;
}

poly operator +(poly P1, poly P2){
    int biggersize = P1.size >= P2.size ? P1.size : P2.size;
    poly temp(biggersize,0);
    if(P1.size<P2.size){
        int i = 0; //Jesli P2 jest wieksze
        for (;i<P1.size;i++) //Przejdz przez cale P1
            temp.vec[i]=P1.vec[i]+P2.vec[i]; 
        for (;i<P2.size;i++) //Dodaj reszte P2
            temp.vec[i]=P2.vec[i];
    }else{
        int i = 0; //Jesli P1 jest wieksze
        for (;i<P2.size;i++) //Przejdz przez cale P2
            temp.vec[i]=P1.vec[i]+P2.vec[i];
        for (;i<P1.size;i++) //Dodaj reszte z P1
            temp.vec[i]=P1.vec[i];
    }
    return temp;
}

poly operator *(poly P1, poly P2){
    poly temp(P1.size+P2.size,0); //Rozmiar bedzie suma rozmiarow wielomianow
    for (int i=0; i<P1.size; i++){
        for (int j=0; j<P2.size; j++)
            temp.vec[i+j] += P1.vec[i]*P2.vec[j];
    }
    return temp;
}

poly operator *(double l, poly P){
    poly temp(P); //skopiujmy wielomian P
    for (int i=0; i<temp.size; i++)
            temp.vec[i] = l*P.vec[i];
    return temp;
}

double poly::operator ()(double l){
    double temp;
    temp = this->vec[this->size-1];
    for (int i=1; i<this->size; i++)
        temp = temp*l + this->vec[this->size-i-1];
    return temp;
}
