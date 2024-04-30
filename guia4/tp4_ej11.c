#include <stdio.h>

int max(int a, int b, int c);

int main() {


    printf("%d\n", max(120, 10, 3));
    return 0;
}

int max(int a, int b, int c) {
    int mayor = a>b ? a : b;
    return mayor > c ? mayor : c;
}