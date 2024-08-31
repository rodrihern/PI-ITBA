#include <stdio.h>

int main() {

    char x = getchar();
    char y = getchar();

    printf("El de mayor valor ASCII es: %c\n", x>y ? x : y);

    return 0;
}