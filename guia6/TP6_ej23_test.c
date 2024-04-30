#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned int uInt ;


/* Recibe un string con el formato dd/mm/yyyy y retorna por parámetro el día, mes
** y año de la misma. En caso de que el formato sea inválido
** o la fecha incorrecta, retorna FALSE y no altera los parámetros
*/
int valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio);
// devuelve true si el año es bisiesto.
int esBisiesto(uInt y);
// devuelve true si es una fecha valida
int isValid(int d, int m, int y);
// devuelve true si el formato de la fecha es dd/mm/yyyy
int isFmtValid(const char * fecha);


int main(void) {
	unsigned int d=100, m=200, a=300;
	int res;
	res = valorFecha("", &d, &m, &a);
	assert(res==0);
	assert(d==100);
	assert(m==200);
	assert(a==300);

	res = valorFecha("29/02/1999", &d, &m, &a);
	assert(res==0);
	assert(d==100);
	assert(m==200);
	assert(a==300);

	res = valorFecha("30/14/2020", &d, &m, &a);
	assert(res==0);
	assert(d==100);
	assert(m==200);
	assert(a==300);

	res = valorFecha("12/12/", &d, &m, &a);
	assert(res==0);
	assert(d==100);
	assert(m==200);
	assert(a==300);

	res = valorFecha("1/1/2000", &d, &m, &a);
	assert(res==0);
	assert(d==100);
	assert(m==200);
	assert(a==300);

	res = valorFecha("12/01/2000", &d, &m, &a);
	assert(res==1);
	assert(d==12);
	assert(m==1);
	assert(a==2000);

	res = valorFecha("29/02/1900", &d, &m, &a);
	assert(res==0);
	assert(d==12);
	assert(m==1);
	assert(a==2000);

	res = valorFecha("29/02/2000", &d, &m, &a);
	assert(res==1);
	assert(d==29);
	assert(m==2);
	assert(a==2000);

	printf("OK");
	return 0;
}

int isFmtValid(const char * fecha) {
	// fmt: dd/mm/yyyy
	int fmtOk = 1;

	//valido longitud y separadores
	fmtOk = (fecha[2] == '/' && fecha[5] == '/' && strlen(fecha) == 10);

	//valido que los demas sean digitos
	if(fmtOk) {
		for(int i = 0; i < 10; i++) {
			if(i != 2 && i != 5 && !isdigit(fecha[i])) {
				fmtOk = 0;
			}
		}
	}

	return fmtOk;
}


int esBisiesto(uInt y) {
	return ( (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 );
}

int isValid(int d, int m, int y) {
	int monthDays[] = {31, (esBisiesto(y) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};

	return ( 1 <= m && m <= 12 && 1 <= d && d <= monthDays[m-1] );
}

int valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio) {
	
	if( !isFmtValid(fecha) ) {
		return 0;
	}

	int d = atoi(fecha);
	int m = atoi(fecha + 3);	
	int y = atoi(fecha + 6);

	if( isValid(d, m, y) ) {
		*dia = d;
		*mes = m;
		*anio = y;

		return 1;
	}

	return 0;
}