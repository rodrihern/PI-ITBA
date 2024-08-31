#include <stdio.h>


int 
main(void)
{
    float a = 0.1;


    if (a == 0.1)
        printf("SON iguales\n");
    else
        printf("NO SON iguales: a vale %g que no es igual a 0.1\n",a);


    return 0;
}
/*
NO SON IGUALES YA QUE EL 0.1 NO TIENE REPRESENTACION EXACTA,
AL ASIGNARLE A a = 0.1 ESTA CASTEANDO A FLOAT EL 0.1 (MENOR PRESICION)
Y LUEGO AL COMPARAR LO CASTEA DE VUELTA A DOUBLE (HABIENDO PERDIDO PRESICION)
POR LO TANTO NO ES EXACTAMENTE IGUAL AL 0.1 (DOUBLE)
*/