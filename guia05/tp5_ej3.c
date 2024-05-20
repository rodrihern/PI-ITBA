#include <stdio.h>
#include "../getnum.h"
#include <math.h>


int lugar (int num, int pos);


int
main( void )
{
	int boleto, esCapicua=1, aux, cifras;
	int  j;
	
	boleto = getint("Ingrese un número de 5 dígitos:");
        
    aux = boleto;
    for(cifras = 0; aux > 0; cifras++) {
        aux /= 10;
    }


	for (j=1; j<=2; j++)
		if ( lugar(boleto, j) != lugar(boleto, cifras-j+1))
		{	
 			esCapicua=0;
			break;
		}
	printf("El boleto %ses capicúa",(esCapicua)? "":"no ");
	return esCapicua;
}


int 
lugar( int num, int pos )
{	
    return (num / (int)pow(10, pos-1)) % 10;
}
