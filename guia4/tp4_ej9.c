#include <stdio.h>
#define ENT_HORA 11
#define ENT_MINUTOS 30

int llegaTemprano(const int hora, const int minutos);

int main() {

    if(llegaTemprano(10, 40)) {
        printf("temprano\n");
    }
    else {
        printf("tarde\n");
    }

    return 0;
}



int llegaTemprano (const int hora, const int minutos)
{
	return (hora < ENT_HORA || (hora == ENT_HORA && minutos <= ENT_MINUTOS));
}
