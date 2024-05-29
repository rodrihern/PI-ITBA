#include <stdio.h>

int belongs(int v[], int elem, int dim) {
    int found = 0, i;
    for(i = 0; i < dim && !found; i++) {
        if( v[i] == elem ) {
            found = 1;
        }
    }

    return found ? i-1 : -1;
}


int main(void) {

	int vec[] = {0, 1, 2, 3, 4};
	int dim = 5;

	printf("indice: %d\n", belongs(vec, 2, dim));

	
}





