#include <stdio.h>
#include <stdbool.h>

int main() {

    int suma = 0, c;
    bool isDecimal = false;
    printf("ingrese un numero decimal: ");


    while ( (c=getchar()) != '\n' && c != EOF ) {

        if (isDecimal) {
            suma += c - '0';
        }
        else if (c == '.' || c == ',') {
            isDecimal = true;
        }

    }

    printf("la suma es: %d \n", suma);


    return 0;
}