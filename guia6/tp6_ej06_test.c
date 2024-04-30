#include <stdio.h>
#include <assert.h>
#include "../rand.h"
#define DIM 30


void
shuffle(int v[], unsigned int dim);

int main(void) {
  int v[DIM];
  randomize();

  for(int i=0; i<DIM; i++) {
	  v[i] = -10 + i*2;
  }
  shuffle(v,DIM);

  puts("Vamos a imprimir el vector, debería estar desordenado");
  for(int i=0; i<DIM; i++) {
	  printf("%03d\t", v[i]);
  }
  putchar('\n');

  int aux=v[0];
  puts("A continuación desordeamos un vector vacío, no debería fallar");
  shuffle(v,0);
  assert(v[0]==aux);

  return 0;
}
