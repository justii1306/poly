#include <stdio.h>
#include <iostream>
#include <cstring>

#define polysize 10

class wektor{

public:
    wektor(size_t s) : size(s)
    {
        vec = calloc(size,sizeof(double));
    }

    int size(){ return size; }
      int j = 0;
      for (int i = 0; i < 9; i++)
        if (vec[i] != 0)
          j = i;
      return j+1;
    };

    wektor &operator=(int f){
      vec[0] = f;
      return *this;
    };
private:
    double* vec;
	int size;
};
