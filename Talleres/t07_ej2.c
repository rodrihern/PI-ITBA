#include <stdio.h>
#include <stdlib.h>
#include "../getnum.h"
/*

VER SOLUCION DE LA CATEDRA


*/  
#define TOTAL_ITEMS 2
#define MAX_LONG 10
 
typedef struct {
    int codigo;
    char desc[MAX_LONG];
    float precio;
} tItem;
 
typedef tItem tFactura[TOTAL_ITEMS];
 
void cargar(tFactura fact, int cant);
float importe(tFactura fact, int cant);
 
int main(void) {
    tFactura f;
    cargar(f, TOTAL_ITEMS);
    printf("%.2f", importe(f, TOTAL_ITEMS));
    return 0;

    
}

void cargar(tFactura fact, int cant) {
    for(int i = 0; i < TOTAL_ITEMS; i++) {
        
    }
}


