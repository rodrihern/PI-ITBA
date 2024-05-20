#include <math.h>
#include <stdio.h>
#define MASK 0x0F

/*
Se desea calcular la desviación estándar de un arreglo de números enteros. 
Los números del arreglo toman valores entre 0 y 15 inclusive, 
por lo que para almacenar cada número se utilizarán solo 4 bits, pudiendo almacenar dos números en un solo byte. 
Para representar dicho arreglo se utilizará un vector de caracteres, 
donde cada elemento del vector contendrá dos números 
(uno en los cuatro bits superiores y el otro en los cuatro bits inferiores). 
Escribir una función que reciba un arreglo como el mencionado anteriormente y la cantidad de números que contiene 
y retorne en su nombre la desviación estándar de los números recibidos.



*/

double desv(const unsigned char arr[], int dim ) {
    
    if(dim == 0) {
        return 0;
    }

    char values[dim*2];
    int sum = 0, elements = (dim + 1) / 2;
    double avg, numerator = 0;

    // guardo los valores y calculo el valor medio
    for(int i = 0; i < elements; i++) {
        values[2*i] = (arr[i] >> 4) & MASK; // guardo el valor en la posicion alta
        sum += values[2*i];
        if( !(elements - i == 1 && dim % 2 == 1) ) {// si estoy en el ultimo elemento y la dim es impar no debo guardar el valor            
            values[2*i + 1] = arr[i] & MASK; // guardo el valor en la posicion baja
            sum += values[2*i + 1];
        }
    }
    avg = (double) sum / dim; 

    // calculo el numerador
    for(int i = 0; i < dim; i++) {
        numerator += (values[i] - avg) * (values[i] - avg);
    }


    return sqrt(numerator / dim);
}