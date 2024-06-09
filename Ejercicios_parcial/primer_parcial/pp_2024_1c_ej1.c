#include <stdio.h>
#include <assert.h>

void firstN(unsigned char v[], int dim, unsigned int n, int *newDim, int *del);
int apariciones(unsigned char elem, unsigned char vec[], int dim);

int main(void) {
    unsigned char v[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim, del;
    firstN(v, 8, 3, &dim, &del); // dim es 8, del es 0, v no cambia
    assert(dim == 8);
    assert(del == 0);
    firstN(v, 8, 8, &dim, &del); // dim es 8, del es 0, v no cambia
    assert(dim == 8);
    assert(del == 0);
    firstN(v, 8, 4, &dim, &del); // dim es 8, del es 0, v no cambia
    assert(dim == 8);
    assert(del == 0);
    firstN(v, 8, 1, &dim, &del); // dim=5, del=3, v = {1, 2, 3, 4, 5};
    assert(dim == 5);
    assert(del == 3);
    unsigned char w[] = {1, 2, 1, 3, 1, 4, 5, 2};
    firstN(w, 8, 0, &dim, &del); // dim=0, del=8, w = {}
    assert(dim == 0);
    assert(del == 8);
    unsigned char t[] = {1, 2, 1, 3, 1, 4, 5, 2};
    firstN(t, 8, 2, &dim, &del); // dim=7, del=1, t = {1, 2, 1, 3, 4, 5, 2}
    assert(dim == 7);
    assert(del == 1);

    puts("OK !");

    return 0;
}

// devuelve cuantas apariciones tiene el elemento elem en el vector vec de dimension dim
int apariciones(unsigned char elem, unsigned char vec[], int dim) {
  int sum = 0;
  for(int i = 0; i < dim; i++) {
    if(elem == vec[i]) {
      sum++;
    }
  }
 
  return sum;
}
 
void firstN(unsigned char v[], int dim, unsigned int n, int *newDim, int *del) {
  *newDim = 0;
  for(int i = 0; i < dim; i++){
    if( apariciones(v[i], v, *newDim) < n ) {
      v[*newDim] = v[i];
      (*newDim)++;
    }
  } 
  *del = dim - (*newDim);
}