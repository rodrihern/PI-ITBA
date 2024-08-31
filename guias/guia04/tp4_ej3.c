#include <stdio.h>
#define VOL_ESFERA(r) ((4.0/3) * 3.1416 * (r)*(r)*(r))

int main() {
    printf("radio\tvolumen\n");
    
    for(int i = 1; i <= 10; i++) {
        printf("%2d cm\t%-7g cm3\n", i, VOL_ESFERA(i));
    }

    return 0;
}