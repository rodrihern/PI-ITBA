#include <stdio.h>
#include <stdlib.h>
#include "../rand.h"

#define RANGO 2
#define BLOCK 10

typedef struct {
    int x;
    int y;
} tPunto2D;

typedef tPunto2D * tPosiciones;

int main() {
    randomize();
    tPunto2D actual = {.x = 0, .y = 0};
    tPosiciones puntos = NULL;
    int dim = 0;

    do {
        if(dim % BLOCK == 0) {
            puntos = realloc(puntos, (dim + BLOCK) * sizeof(tPunto2D));
        }
        puntos[dim++] = actual;
        int dx = randInt(-RANGO, RANGO);
        int dy = randInt(-RANGO, RANGO);
        actual.x += dx;
        actual.y += dy;
    } while(actual.x != 0 || actual.y != 0);

    for(int i = 0; i < dim; i++) {
        printf("{%d, %d} ", puntos[i].x, puntos[i].y);
    }

    free(puntos);

    return 0;
}