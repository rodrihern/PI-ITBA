#include <stdio.h>

#define EXP(hora1, min1, hora2, min2) (((hora2)*60 + (min2))-((hora1)*60 + (min1)))
#define ELAPSED(h1, m1, h2, m2) (EXP(h1, m1, h2, m2) > 0 ? EXP(h1, m1, h2, m2) : -EXP(h1, m1, h2, m2))


int main() {
    int minutos, h1, h2, m1, m2;
    h1 = 2; m1 = 10; h2 = 3; m2 = 15;
    minutos = ELAPSED(h1, m1, h2, m2);		/* minutos = 65 */
    printf("%d\n", minutos);
    minutos = ELAPSED(3, 15, 2, 10);		/* minutos = 65 */
    printf("%d\n", minutos);
    minutos = ELAPSED(h1, m1, h1 + 1, m1);	/* minutos = 60 */
    printf("%d\n", minutos);


    return 0;
}

// int ELAPSED(int h1, int m1, int h2, int m2) {
//     int resp = (h2*60 + m2) - (h1*60 + m1);
//     return resp > 0 ? resp : -resp;

// }