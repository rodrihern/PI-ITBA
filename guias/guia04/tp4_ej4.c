#include <stdio.h>
#define SWAP(t, x, y) {t aux; aux = x; x = y; y = aux;} 


int main() {

    int a = 5, b = 1234;
    SWAP(int, a, b);
    printf("a = %d\nb = %d\n", a, b);


    return 0;
}
