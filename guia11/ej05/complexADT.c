#include "complexADT.h"
#include <stdlib.h>
#include <stdio.h>

#define EPS 0.01

typedef struct complexCDT {
    double real;
    double imag;
} complexCDT;

complexADT nuevoComp(double real, double imag) {
    complexADT num = malloc(sizeof(complexCDT));
    num->real = real;
    num->imag = imag;

    return num;
}


complexADT sumaComp(complexADT comp1, complexADT comp2 ) {
    if(comp1 == NULL || comp2 == NULL) {
        exit(1);
    }
    complexADT ans = malloc(sizeof(complexCDT));
    ans->real = comp1->real + comp2->real;
    ans->imag = comp1->imag + comp2->imag;

    return ans;
}


complexADT restaComp(complexADT comp1, complexADT comp2 ) {
    if(comp1 == NULL || comp2 == NULL) {
        exit(1);
    }
    complexADT ans = malloc(sizeof(complexCDT));
    ans->real = comp1->real - comp2->real;
    ans->imag = comp1->imag - comp2->imag;

    return ans;
}

complexADT multiplicaComp(complexADT comp1, complexADT comp2 ) {
    if(comp1 == NULL || comp2 == NULL) {
        exit(1);
    }
    complexADT ans = malloc(sizeof(complexCDT));
    ans->real = comp1->real * comp2->real - comp1->imag * comp2->imag;
    ans->imag = comp1->real * comp2->imag + comp1->imag * comp2->real;

    return ans;
}

complexADT divideComp(complexADT num1, complexADT num2) {
    if (num1 == NULL || num2 == NULL) {
        fprintf(stderr, "error división 1");
        exit(1);
    }
    double norma = (num2->real * num2->real) + (num2->imag * num2->imag);
    if (norma < EPS) {
        fprintf(stderr, "error división 2");
        exit(1);
    }
    complexADT ans = multiplicaComp(num1, conjugadoComp(num2));

    ans->real = ans->real / norma;
    ans->imag = ans->imag / norma;

    return ans;
}

complexADT conjugadoComp(complexADT num) {
    if(num == NULL) {
        exit(1);
    }

    complexADT ans = malloc(sizeof(complexCDT));

    ans->real = num->real;
    ans->imag = - num->imag;

    return ans;
}


double parteRealComp(complexADT num) {
    if(num == NULL) {
        exit(1);
    }
    return num->real;
}


double parteImagComp(complexADT num) {
    if(num == NULL) {
        exit(1);
    }
    return num->imag;
}



void liberaComp(complexADT num) {
    if(num == NULL) {
        exit(1);
    }
    free(num);
}
