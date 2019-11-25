#include <stdio.h>
#include <iostream>
#include <cstring>

#define polysize 10

class wektor{
public:
    wektor(){
      size = 1;
      vec = calloc(size, sizeof(double));
    };
    wektor(int size){
      vec = calloc(size, sizeof(double));
    };
    wektor(const wektor &w2){
      vec = calloc(w2.size, sizeof(double));
      for (int i = 0; i < this.size; i++)
        vec[i] = w2.vec[i];
    };
    ~wektor(){
      free(vec);
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
//      int j = 0;
//      for (int i = 0; i < 9; i++)
//        if (vec[i] != 0)
//          j = i;
//      std::cout << "J: " << j << std::endl;
//      return j+1;
    return size;
    };
    double &operator[](int index) {
        if (index >= size){
          size = index+1;
          vec = realloc(size, sizeof(double)
        }
        return vec[index];
    };
    wektor &operator=(int foo){
      vec[0] = foo;
      return *this;
    };
private:
    double* vec;
    int size;
};

