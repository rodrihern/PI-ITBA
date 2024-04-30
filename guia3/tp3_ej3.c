#include <stdio.h>
#include "../getnum.h"

int main() {

    int sum = 0, price = 300;

    do {
        if (sum < 0) {
            printf("Dato incorrecto\n");
        }
        sum = getint("ingrese la suma vendida: ");

    }   while (sum < 0);

    if (1000 <= sum && sum < 2000) {
        price += sum * 0.02;
    }
    else if (2000 <= sum && sum < 4000) {
        price += sum * 0.07;
    }
    else if (sum >= 4000){
        price += sum * 0.09;
    }
    printf("Monto total a cobrar: %d\n", price);

    return 0;
}