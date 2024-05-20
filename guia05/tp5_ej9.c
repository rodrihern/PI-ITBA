#include <stdio.h>
#include <math.h>
#define A -7
#define B 7
#define DELTA 0.001
#define EPSILON 0.0000000001

// BUSCO RAICES EN EL INTERVALO [A, B] CON UNA PRESICION DE DELTA 
// si EPSILON es lo suficientemente grande puede ser que omita una raiz (en especial si es una raiz de multiplicidad par)
// se EPSILON es lo suficientemente chico puede ser que encuentre varias veces la misma raiz
// para mejorar la presicion basta con elegir un DELTA mas chico

double f(double x);

int main() {

    double current, prev = 0;

    for(double i = A; i <= B; i += DELTA) {
        current = f(i);
        if(fabs(current) < EPSILON|| prev*current < 0) {
            printf("x = %.3f es raiz\n", i);
        }
        prev = current;
    }
}

double f(double x) {
    return sin(x);
}