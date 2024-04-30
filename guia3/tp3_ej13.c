#include <stdio.h>
#include "../getnum.h"

int main() {
    int lado;

    do {
        lado = getint("ingrese el lado: ");
        if(lado <= 0) {
            printf("Dato incorrecto.\n\n");
        }
    } while(lado <= 0);
    
    for(int i = 0; i < lado; i++) {
        for(int j = 0; j < lado; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}