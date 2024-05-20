#include <stdio.h>


//ESTE PROGRAMA REEMPLAZA LOS ESPACIOS MULTIPLES POR UN SOLO ESPACIO

int main() {
    
    int c, prev = 'a';

    while((c = getchar()) != '\n' && c != EOF) {
        if( prev != ' ' || c != ' ' ) {
            putchar(c);
        } 
        prev = c;
    }

    printf("\n");
}


/*
int main() {

    int c;

    while((c = getchar()) != '\n' && c != EOF) {
        if(c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if(c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if(c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else {
            putchar(c);
        }
    }

    printf("\n");

}
*/
