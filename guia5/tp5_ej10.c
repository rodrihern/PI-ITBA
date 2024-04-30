#include <stdio.h>
#include <stdlib.h>
#include "../getnum.h"

int menu();
int getDenom();
int mcd(int a, int b);
void simplificarFraccion(int num, int denom);
void sumarFracciones(int n1, int d1, int n2, int d2);

int main() {
    int opcion, a, b, c, d;

    do {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            a = getint("ingrese numerador: ");
            b = getDenom();
            simplificarFraccion(a, b);
            break;
        case 2: 
            a = getint("ingrese la primera fraccion\ningrese el numerador: ");
            b = getDenom();
            c = getint("ingrese la segunda fraccion\ningrese el numerador: ");
            d = getDenom();
            sumarFracciones(a, b, c, d);
        case 3:
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
    } while (opcion != 3);

    return 0;
}

int menu() {
    printf("\n1. Simplificar una fraccion\n");
    printf("2. Sumar dos fracciones\n");
    printf("3. Terminar el programa\n\n");
    int opt = getint("ingrese la opcion que desee: ");

    return opt;
}

int getDenom() {
    int denom;
    do {
        denom = getint("ingrese el denominador: ");
        if (denom == 0) {
            printf("el denominador no puede ser 0\n");
        }
    } while(denom == 0);

    return denom;
}

int mcd(int a, int b) {
    int resto;
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    
    return a;
}

void simplificarFraccion(int num, int denom) {
    int divisor, isNeg = (num*denom < 0);
    
    num = abs(num);
    denom = abs(denom);
    divisor = mcd(num, denom);
    num = isNeg ? -num/divisor : num/divisor;
    denom = denom / divisor;

    printf("\nRespuesta: %d", num);
    if(denom != 1) {
        printf("/%d\n", denom);
    } else {
        printf("\n");
    }

    
}

void sumarFracciones(int n1, int d1, int n2, int d2) {
    int num = n1 * d2 + n2 * d1;
    int denom = d1 * d2;
    simplificarFraccion(num, denom);
}