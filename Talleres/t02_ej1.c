#include <stdio.h>
#include "../getnum.h"
#include <math.h>


int main() {

    int a, b, c;
    double root1, root2, discriminante, rDisc;

    printf("ingrese los coeficientes de una ecuacion cuadratica de la siguiente forma\nax^2 + bx + c\n");

    a = getint("ingrese a: ");
    b = getint("ingrese b: ");
    c = getint("ingrese c: ");

    discriminante = b*b - 4*a*c;
    
    if (a == 0) {
        printf("la ecuacion no es cuadratica\n");
        return 0;
    }
    else if (discriminante < 0) {
        printf("tiene raices complejas brodi\n");
        return 0;
    }
    else {
        rDisc = sqrt(discriminante);
        root1 = ( -b + rDisc ) / (2*a);
        root2 = ( -b - rDisc ) / (2*a);

        if (root1 == root2) {
            printf("tiene una raiz doble x = %.2f\n", root1);
        }
        else {
            printf("las raices son\nx1 = %.2f\nx2 = %.2f\n", root1, root2);
        }
    }

    return 0;
}

