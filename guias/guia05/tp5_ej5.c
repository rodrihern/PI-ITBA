#include <stdio.h>



double potencia(double base, int exp) {

    int isNegative = (exp < 0);
    if (base == 0 && (isNegative || exp == 0)) {
        return -1;
    }
    double result = 1;
    exp = exp > 0 ? exp : -exp;

    for(int i = 0; i < exp; i++) {
        result *= base;
    }

    return isNegative ? 1.0/result : result;

}