/*
Escribir un programa que lea un número entero,
 y escriba por salida estándar  dicho número y un cartel indicando si es capicúa o no. (En no más de 10 líneas)

*/

#include <stdio.h>
#include "../getnum.h"

int main() {

    int num = getint("ingrese un numero: ");
    int aux = num, reverse = 0;

    while(aux > 0) {
        reverse = (reverse * 10) + (aux % 10);
        aux /= 10;
    }

    printf("%s capicua \n", (num == reverse) ? "Es" : "No es");


    return 0;
}