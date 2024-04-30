#include <stdio.h>
#include <stdbool.h>

int main() {

    bool isDecimal = false;
    int c, accEntero = 0, accDecimal = 0;
    
    printf("ingrese un numero decimal: ");

    while((c = getchar()) != '\n') {
        if (c == '.' || c == ',') {
            isDecimal = true;
        }
        else if(c == '5') {
            if(isDecimal) {
                accDecimal++;
            }
            else {
                accEntero++;
            }
        }
        
    }
    printf("cantidad de 5:\nen la parte entera:\t%d\nen la parte decimal:\t%d\n", accEntero, accDecimal);


}