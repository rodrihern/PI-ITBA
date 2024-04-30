#include <stdio.h>
#include "../getnum.h"
#include <math.h>


int main() {
    int suma = 0;
    float num = getfloat("ingrese un numero decimal: ");

    if (num < 0) {
        num = 0 - num;
    }


    while (num != 0) {
        num = num - (int) num;
        num *= 10;
        suma += num;
    }
        
        
        

    printf("la suma es: %d \n", suma);
}