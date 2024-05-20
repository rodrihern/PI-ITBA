#include <stdio.h>

int main() {
    char c = getchar();

    if('a' <= c && c <= 'z') {
        printf("%c es una letra minuscula\n", c);
    }
    else if('A' <= c && c <= 'Z') {
        printf("%c es una letra mayuscula\n", c);
    }
    else {
        printf("%c no es una letra\n", c);
    }

    return 0;
}