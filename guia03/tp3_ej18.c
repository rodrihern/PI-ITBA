#include <stdio.h>
#include "../getnum.h"

int main() {
    int num, fact = 1;

    do {
        num = getint("ingrese un numero: ");
        if(num < 0) {
            printf("el numero debe ser positivo o 0\n\n");
        }
    } while(num < 0);

    for(int i = 2; i <= num; i++) {
        fact *= i;
    }

    printf("el factorial es: %d\n", fact);
}