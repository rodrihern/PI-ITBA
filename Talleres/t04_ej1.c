#include "../rand.h"
#include <stdio.h>
#include <ctype.h>

int countLetter(int letter, int max);

int main() {

    randomize();

    int letra = randInt('A', 'Z');
    int num = randInt(1, 256);
    printf("letra: %c, n: %d\n\n", letra, num);
    int rta = countLetter(letra, num);
    printf("aparece: %d veces \n", rta);
    
}

int countLetter(int letter, int max) {
    int sum = 0;
    int c;
    for (int i = 0; (c = getchar()) != EOF && i < max; i++) {
        if(toupper(c) == letter) {
            sum++;
        }
    }

    return sum;
}
