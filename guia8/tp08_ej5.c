#include <stdio.h>
#include "../rand.h"

#define MUESTRAS 20



int walk(unsigned int r);

typedef struct {
    int x, y;
} point;

int main() {
    randomize();
    puts("radio\ttiempo\tratio");
    for(int i = 1; i <= MUESTRAS; i++) {
        int time = walk(i);
        double ratio = (double) i / time;
        printf("%d\t%d\t%.2f\n", i, time, ratio);
    }

    return 0;
}

int walk(unsigned int r) {
    int time, inside = 1;
    point coor = {0, 0};
    int dir[] = {-1, 1};

    for(time = 0; inside; time++) {
    
        int num = randInt(1, 4);

        // es medio una cagada pero tenia ganas de hinchar los huevos a feli
        switch(num) {
            case 1:
            case 2:    
                coor.x += dir[num%2];
                break;
            case 3:
            case 4:    
                coor.y += dir[num%2];
                break;
            default:
                break;
        }

        if(coor.x*coor.x + coor.y*coor.y >= r * r) {
            inside = 0;
        }
    }

    return time;
}
