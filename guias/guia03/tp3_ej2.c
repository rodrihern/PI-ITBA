#include <stdio.h>

int main() {

    char c1 = getchar(), c2 = getchar();

    if (c1 < c2) {
        printf("%c es menor que %c\n", c1, c2);
    }
    else if (c2 < c1) {
        printf("%c es menor que %c\n", c2, c1);
    }
    else {
        printf("ambos caracteres son iguales\n");
    }

    return 0;
}