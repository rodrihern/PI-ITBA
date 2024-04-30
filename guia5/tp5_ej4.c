#include <time.h>
#include <stdlib.h>



int randInt(int left, int right) {
    srand((int)time(NULL));
    return rand() % (right - left + 1) + left;
}
