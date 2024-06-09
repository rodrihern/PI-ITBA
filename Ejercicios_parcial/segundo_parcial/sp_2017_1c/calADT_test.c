#include "calADT.h"
#include <stdio.h>

int main() {

    calADT cal = newCal();

    tDate d1 = {24, 6, 2017};
    tEvent e1 = {"Segundo Parcial", d1};
    addEvent(cal, e1);

    tDate d2 = {28, 4, 2017};
    tEvent e2 = {"Primer Parcial", d2};
    addEvent(cal, e2);

    tDate d3 = {3, 7, 2017};
    tEvent e3 = {"Entrega de notas de cursada", d3};
    addEvent(cal, e3);

    tDate d4 = {28, 4, 2017};
    tEvent e4 = {"Este no deberia agregarse", d4};
    addEvent(cal, e4);

    toBegin(cal);
    tEvent aux;

    do {
        aux = nextElement(cal);
        if(aux.date.day > 0) {
            printf("%02d/%02d/%d: %s\n", aux.date.day, aux.date.month, aux.date.year, aux.eventName);
        }
        
    } while(aux.date.day > 0);

    return 0;
}