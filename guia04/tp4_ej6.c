#include <stdio.h>
#define MAXIMO2(x, y, resp) (resp = (x) > (y) ? (x) : (y))
#define MAXIMO3(a, b, c, resp) (resp = MAXIMO2(a, b, resp) > (c) ? resp : (c))

int main() {
    int maximo;

    MAXIMO3(100, 40, 30, maximo);

    printf("max: %d\n", maximo);

    return 0;
}