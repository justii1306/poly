#include "poly.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
//#include "wektor.h"


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
  std::cout<<std::endl<<"COPYCOPYCOPY"<<std::endl;
  this->size = P.size;
  this->vec = (double*)calloc(this->size, sizeof(double));
  for (int i=0; i < this->size; i++)
    this->vec[i] = P.vec[i];
  for(int j = 0; j < this->size; j++)
    std::cout << "vec[" << j << "]: " << this->vec[j] << std::endl;
    std::cout << "this->size: " << this->size << std::endl;
}

poly::poly(int size, int second_constructor_just_for_the_sake_of_not_writing_different_function){
  this->size = size;
  std::cout<<"size: "<<size<<" this->size: "<<this->size<<std::endl;
  this->vec = (double*)calloc(this->size, sizeof(double));
}

poly::~poly(){
  free(vec);
}

double& poly::operator[] (int i){
  //std::cout << "Inside []: " << i << std::endl;
  //for(int j = 0; j < this->size; j++)
    //std::cout << "vec[" << j << "]: " << vec[j] << std::endl;
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
	std::cout<<"Usuwamy: "<<temp[j]<<std::endl;
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
    for(int j = 0; j < P.size; j++)
    std::cout << "vec[" << j << "]: " << P.vec[j] << std::endl;
    std::cout << "P.size: " << P.size << std::endl;
    return s;
}

poly operator +(poly P1, poly P2){
    int biggersize = P1.size >= P2.size ? P1.size : P2.size;
    poly temp(biggersize,0);
    if(P1.size>P2.size){
        for (int i=0;i<P1.size;i++)
            temp.vec[i]=P1.vec[i]+P2.vec[i];
    }else{
        for (int i=0;i<P2.size;i++)
            temp.vec[i]=P1.vec[i]+P2.vec[i];
    }
    return temp;
}

poly operator *(poly P1, poly P2){
    //std::cout <<"P1.size: "<<P1.size<<" P2.size: "<<P2.size<<std::endl;
    poly temp(P1.size+P2.size,0);
    for (int i=0; i<P1.size; i++){
        for (int j=0; j<P2.size; j++)
            temp.vec[i+j] += P1.vec[i]*P2.vec[j];
    }
    for(int j = 0; j < temp.size; j++)
    std::cout << "vec[" << j << "]: " << temp.vec[j] << std::endl;
    std::cout << "temp.size: " << temp.size << std::endl;
    return temp;
}

poly operator *(double l, poly P){
    poly temp(P);
    for (int i=0; i<P.size; i++)
            temp.vec[i] = l*P.vec[i];
    for(int j = 0; j < temp.size; j++)
    std::cout << "vec[" << j << "]: " << temp.vec[j] << std::endl;
    std::cout << "temp.size: " << temp.size << std::endl;
    return temp;
}

double poly::operator ()(double l){
    double temp;
    temp = this->vec[this->size-1];
    for (int i=1; i<this->size; i++)
        temp = temp*l + this->vec[this->size-i-1];
    return temp;
}

//poly &poly::operator =(int foo){
//  std::cout<<"KURWA"<<std::endl;
//  this->vec[0] = foo;
//  return *this;
//}
