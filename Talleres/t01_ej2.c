#include <stdio.h>

int main () {
    int a = 1, b = 100, c = 3, max;

    max = a>b ? a : b;
    max = c>max ? c : max;


    printf("el mayor es: %d \n", max);
}