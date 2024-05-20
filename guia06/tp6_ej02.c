#include <stdlib.h>

#define NUM(f) f[0]
#define DENOM(f) f[1]



int mcd(int a, int b) {
    int resto;
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    
    return a;
}

void simplFrac(int frac[]) {
    int divisor, isNeg = (NUM(frac)*DENOM(frac) < 0);
    
    NUM(frac) = abs(NUM(frac));
    DENOM(frac) = abs(DENOM(frac));
    divisor = mcd(NUM(frac), DENOM(frac));
    NUM(frac) = isNeg ? -NUM(frac)/divisor : NUM(frac)/divisor;
    DENOM(frac) = DENOM(frac) / divisor;

    
}

void sumarFrac(const int frac1[], const int frac2[], int out[]) {
    NUM(out) = NUM(frac1) * DENOM(frac2) + NUM(frac2) * DENOM(frac1);
    DENOM(out) = DENOM(frac1) * DENOM(frac2);
    simplFrac(out);
}
