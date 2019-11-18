#include <stdio.h>
#include <iostream>
#include <cstring>

#define polysize 10

class wektor{
public:
    wektor(){
      //vecsize = 10; 
      //vec = new double[vecsize]();
    };
    wektor(int size){
      //vec = new double[size]();
      //vecsize = size;
    };
    void freeme(){
//      delete vec;
    }
    double* insert(double* position, double value){
      int pos = vec-position;
      vec[pos] = value;
      return &vec[pos];
    };
    double* insert(double* position, int size, double value){
      int i = 0;
      for (; i < size; i++){
        vec[i] = value;
      }
      return vec;
    };
    double* begin(){
      return vec;
    };
    int size(){
      int j = 0;
      for (int i = 0; i < 9; i++)
        if (vec[i] != 0)
          j = i;
//      std::cout << "J: " << j << std::endl;
      return j+1;
    };
    double &operator[](int index) {
        return vec[index];
    };
    wektor &operator=(int foo){
      vec[0] = foo;
      return *this;
    };
private:
    double vec[10];
    int vecsize;
};

