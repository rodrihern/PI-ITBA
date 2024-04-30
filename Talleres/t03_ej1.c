#include <math.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int esPrimo(int num);
void generaPrimos(int cant);

int main() {

    generaPrimos(20);
    return 0;
}

int esPrimo(int num) {


    if(num < 0) {
        num *= -1; 
    }

    float root = sqrt(num);
    int rta = TRUE;

    if(num < 2) {
        rta = FALSE;
    }
    
    
    for(int i = 2; i <= root; i++) {
        if(num % i == 0) {
            rta = FALSE;
        }
    }

    
    return rta;
}


void generaPrimos(int cantidad) {

    int cont = 0;

    for(int i = 2; cont < cantidad; i++) {
        if(esPrimo(i)) {
            printf("%d\n", i);
            cont++;
        }
    }

}