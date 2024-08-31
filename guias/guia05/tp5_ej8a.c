#include <stdio.h>
#include <math.h>

double redondeo(double num, int dec) {
    int decPos = pow(10, dec);
    return floor(num * decPos + 0.5) / decPos;
}