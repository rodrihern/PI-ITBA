#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 0.0000001
#define FUNCION(x) (sin((x)))
#define BLOCK 5

typedef struct {
    double min, max;
} tipoIntervalo;

typedef struct {
    tipoIntervalo * raiz;
    int dim;
} tipoRaices;

tipoRaices * buscarRaices(tipoIntervalo intervalo);

int detectaCero(double x, double paso);

int main() {
    tipoIntervalo intervalo = {-4, 4};
    tipoRaices * raices = buscarRaices(intervalo);

    printf("cantidad de raices: %d\n", raices->dim);
   
    for(int i = 0; i < raices->dim; i++) {
        printf("Raiz en: (%g, %g)\n", raices->raiz[i].min, raices->raiz[i].max);
    }
   

    free(raices->raiz);
    free(raices);

    return 0;
}

tipoRaices * buscarRaices(tipoIntervalo intervalo) {
    double paso = (intervalo.max - intervalo.min) / 100000;
    tipoRaices * rta = malloc(sizeof(tipoRaices));
    rta->raiz = NULL;
    rta->dim = 0;
    double x;

    for(x = intervalo.min; x < intervalo.max; x += paso) {
        if(rta->dim % BLOCK == 0) {
            rta->raiz = realloc(rta->raiz, (rta->dim + BLOCK) * sizeof(tipoIntervalo));
        }

        if(detectaCero(x, paso)) {
            rta->raiz[rta->dim].min = x;
            x += paso;
            while(detectaCero(x, paso) && x < intervalo.max) {
                x += paso;
            }
            rta->raiz[rta->dim].max = x;
            (rta->dim)++;
        }
    }

    rta->raiz = realloc(rta->raiz, rta->dim * sizeof(tipoIntervalo));

    return rta;
}

int detectaCero(double x, double paso) {
    return (fabs(FUNCION(x)) < EPS) || (FUNCION(x) * FUNCION(x+paso) < 0);
}
