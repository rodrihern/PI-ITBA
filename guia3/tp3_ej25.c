/*
Escriba un programa que lea de entrada estándar un número entero positivo y calcule la cantidad de bits en ‘1’ que contiene.
*/


#include <stdio.h>
#include "../getnum.h"

int main() {

    int acc = 0, num = getint("ingrese un numero entero positivo: ");
    
    if (num < 0) {
        num += (-1);
    }

    while (num > 0) {
        if (num%2 == 1) {
            acc++;
        }
        num /= 2;
    }

    printf("%d\n", acc);

    return 0;
}