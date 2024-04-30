#include <stdio.h>
#include <stdlib.h>

#define ELAPSED(h1, m1, h2, m2) abs(((h2)*60 + (m2))-((h2)*60 + (m2)))


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