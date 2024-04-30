#include <stdio.h>
#include "../getnum.h"

int main() {

    int suma = 0, num;
    num = getint("ingrese un numero entero: ");

    if (num < 0) {
        num = 0 - num;
    }


    do {
        suma += num%10;
        num /= 10;
    } while (num > 0);

    

    printf("la suma es: %d \n", suma);

    

    return 0;
}