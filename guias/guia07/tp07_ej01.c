#include <stdlib.h>
#include <stdio.h>

int
main(void) {
        // hola manola
        char * p = malloc(11);

        for(int i=0; i <= 10; i++)
                p[i] = (char) i * 10;


        for(int i=0; i <= 10; i++)
                printf("%d\n", p[i]);

        free(p);

        return 0;
}
