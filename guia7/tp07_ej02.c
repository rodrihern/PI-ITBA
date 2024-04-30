#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../getnum.h"
#include <math.h>
#define BLOCK 10

int validBase(int a, int b); 
int * convert(int num, int inBase, int outBase, int * dim);

int main() {
    int cant, inBase, outBase, num, dim;


    printf("Ingrese las bases [<inBase>outBase]: ");
    do {
        cant = scanf("<%d>%d", &inBase, &outBase);
    } while (cant > 6 && !validBase(inBase, outBase));

    num = getint("ingrese el numero: ");

    int * numConverted = convert(num, inBase, outBase, &dim);

    if(numConverted != NULL) {
        for(int i = dim-1; i >= 0 ; i--) {
            printf("%d", numConverted[i]);
        }
    }
    putchar('\n');

    free(numConverted);
    return 0;
}

int validBase(int a, int b) {
    return (2 <= a && a <= 10 && 2 <= b && b <= 10);
}

int * convert(int num, int inBase, int outBase, int * dim) {

    //primero pasamos a decimal
    if(inBase != 10) {
        int aux = 0;
        for(int i = 0; num > 0; i++) {
            int digit = num % 10;

            if(digit >= inBase) {
                return NULL;
            }

            aux += digit * pow(inBase, i);
            
            num /= 10;
        }
        num = aux;
    }

    int i;
    int * converted = NULL; 
    for(i = 0; num > 0; i++) {
        if(i % BLOCK == 0) {
            converted = realloc(converted, (i + BLOCK) * sizeof(int));
        }

        converted[i] = num % outBase;
        num /= outBase;
        

    }

    converted = realloc(converted, i * sizeof(int));

    *dim = i;

    return converted;


}