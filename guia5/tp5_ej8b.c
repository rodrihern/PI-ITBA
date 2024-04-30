#include <stdio.h>
#include <math.h>
#include "../getnum.h"

double redondeo(double num, int dec);
int menu();

int main() {
    double num = getdouble("ingrese un numero: ");
    int opcion = menu();
    double result;

    switch (opcion)
    {
    case 1:
        result = redondeo(num, 0);
        break;
    case 2:
        result = redondeo(num, 1);
        break;
    case 3:
        result = redondeo(num, 2);
        break;
    case 4:
        result = redondeo(num, 3);
        break;
    default:
        break;
    }

    printf("Respuesta: %g\n", result);


}

double redondeo(double num, int dec) {
    int decPos = pow(10, dec);
    return floor(num * decPos + 0.5) / decPos;
}

int menu() {
    int opt;
    do {
        printf("\n1. Redondeo al entero mas cercano\n");
        printf("2. Redondeo a la decima mas cercana\n");
        printf("3. Redondeo a la centesima mas cercana\n");
        printf("4. Redondeo a la milesima mas cercana\n\n");
        opt = getint("ingrese la opcion que desee: ");
        if (opt <= 0 || opt >= 5) {
            printf("Dato incorrecto. \n\n");
        }
    } while(opt <= 0 || opt >= 5);

    return opt;
}