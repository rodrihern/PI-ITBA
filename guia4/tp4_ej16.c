#include <stdio.h>
#define DIVISOR(x, y) ((x) % (y) ? 0 : 1) 


int main() {

    int a, b = 10, c = 3;
    a = DIVISOR(b,c); 	/* a = 0 */
    printf("%d\n", a);
    a = DIVISOR(b,c-1);	/* a = 1 */
    printf("%d\n", a);
    
    
    return 0;
}


