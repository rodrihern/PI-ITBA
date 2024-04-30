#include <stdio.h>
#include "../getnum.h"

int main() {

    int time, hours, minutes, seconds;

    time = getint("ingrese un intervalo de tiempo en segundos: ");

    hours = time / 3600;
    minutes = (time - 3600*hours) / 60;
    seconds = time - 3600*hours - 60*minutes;

    printf("son %02dh %02dm %02ds\n", hours, minutes, seconds);

    return 0;
}