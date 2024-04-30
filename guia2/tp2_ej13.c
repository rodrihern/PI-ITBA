#include <stdio.h>
#include "../getnum.h"

int main() {

    int num1, num2;
    num1  = getint("ingrese un numero: ");
    num2  = getint("ingrese un numero: ");

    printf("%d %ses multiplo de %d\n", num2, num2%num1 == 0 ? "" : "no " , num1);


    return 0;
}