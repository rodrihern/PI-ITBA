#include <stdio.h>
#define isdigit(c) ('0' <= (c) && (c) <= '9')

int main() {
    int letra = getchar();
    if( isdigit(letra) ) {
        printf("es un digito\n");
    }
}