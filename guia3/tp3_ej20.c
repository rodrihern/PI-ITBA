#include <stdio.h>
#define EPSILON 0.000000000001

int main() {

    printf("\tN\te\n");
    double e = 1, prev = 0;
    int factorial = 1;

    for(int i = 1; e - prev > EPSILON; i++ ) {
        printf("\t%d\t%.10f\n", i, e);
        prev = e;
        factorial *= i;
        e += 1.0/factorial;
        
    }

}