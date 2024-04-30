#include <stdlib.h>
#include <stdio.h>
#define BLOCK 10

int main () {
    int c, dim = 0;
    char * arr = NULL;

    while((c = getchar()) != EOF) {
        if(dim % BLOCK == 0) {
            arr = realloc(arr, (dim + BLOCK) * sizeof(char));
        }
        arr[dim++] = c;
    }

    arr = realloc(arr, dim * sizeof(char));

    for(int i = 0; i < dim; i++) {
        putchar(arr[i]);
    }

    free(arr);

    return 0;
}