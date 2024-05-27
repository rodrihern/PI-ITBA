#ifndef UNTITLED_COMPLEXADT_H
#define UNTITLED_COMPLEXADT_H

typedef struct complexCDT * complexADT;

/*
    * crea un numero complejo con parte real real y parte imaginaria imag
*/
complexADT nuevoComp(double real, double imag);

/*
    * devuelve la suma de dos numeros complejos comp1 y comp2
*/
complexADT sumaComp(complexADT comp1, complexADT comp2 );

/*
    * devuelve la resta de dos numeros complejos comp1 y comp2
*/
complexADT restaComp(complexADT comp1, complexADT comp2 );

/*
    * devuelve la multiplicacion de dos numeros complejos comp1 y comp2
*/
complexADT multiplicaComp(complexADT comp1, complexADT comp2 );

/*
    * devuelve la division de dos numeros complejos num1 y num2
*/
complexADT divideComp(complexADT num1, complexADT num2);

/*
    * devuelve el conjugado del numero complejo num
*/
complexADT conjugadoComp(complexADT num);

/*
    * devuelve la parte real del numero complejo num
*/
double parteRealComp(complexADT num);

/*
    * devuelve la parte imaginaria del numero complejo num
*/
double parteImagComp(complexADT num);


/*
    * hace un free de memoria del numero complejo num
*/
void liberaComp(complexADT num);




#endif