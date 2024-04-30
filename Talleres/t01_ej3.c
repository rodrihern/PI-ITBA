#include <stdio.h>

int main() {
    int num = 3;
    char ascii = num<=15 ? (num>=0 ? (num<=9 ? num+'0' : num-10+'A') : num) : num;

    printf("es el %c \n", ascii);


}