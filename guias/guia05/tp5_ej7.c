#include <stdio.h>
#define EPSILON 0.0000000000000000000000001

double exp(double x);

int main() {
    for (int i = 0; i <= 20; i++) {
        printf("e^%d = %.10f\n", i, exp(i));
    }
    
}

double exp(double x) {
    double rta = 1, prev = 0, potencia = x, fact = 1;

    for (int i = 2; rta - prev > EPSILON; i++) {
        prev = rta;
        rta += potencia / fact;
        potencia *= x;
        fact *= i;
    }
    return rta;
    
}
 

