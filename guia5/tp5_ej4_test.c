#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int randInt(int left, int right);

int main(void){

    int rand=randInt(1, 10);
    assert(rand<=10 && rand>=1);
    rand=randInt(-10, -2);
    assert(rand<=-2 && rand >=-10);
    assert(randInt(0,0)==0);
    assert(randInt(10,10)==10);
    
    // Solo estamos testeando que caiga dentro del rango, habria que realizar un test
    // mas sofisticado que analizara la desviacion estandar
    for(int i=0; i < 1000; i++) {
        rand = randInt(-10, 10);
        assert(rand<=10 && rand >=-10);    
    }

    puts("OK!");
    return 0;
}