#include <stdio.h>
#include <assert.h>
#include <string.h>

void insertaDesde(char * s1, const char * s2, char c);

int main(void) {
    char str1[60] = "manuel";
    char str2[] = "javi";
    insertaDesde(str1, str2,'n');
    assert(strcmp(str1,"majavi")==0);

    char str3[20];
    strcpy(str3, "manuel");
    insertaDesde(str3, "javi" ,'l');
    assert(strcmp(str3,"manuejavi")==0); // muestra manuejavi

    char str4[60];
    strcpy(str4, "lalala");
    insertaDesde(str4, "javi",'j');
    assert(strcmp("lalala",str4)==0);

    insertaDesde(str4, "javier ibaniez de toledo",'l');
    assert(strcmp("javier ibaniez de toledo",str4)==0);

    strcpy(str4,"12345");
    insertaDesde(str4, "6789abcdefgh",'5');
    assert(strcmp("12346789abcdefgh",str4)==0);


    puts("OK!");
    return 0;
}

void insertaDesde(char * s1, const char * s2, char c) {
    int found = 0;
    int i;
    for(i = 0; s1[i] && !found; i++) {
        if(s1[i] == c) {
            found = 1;
            for(int j = 0; s2[j]; j++) {
                s1[i++] = s2[j];
            }
        }
    }
    
    if(found) {
        s1[--i] = 0;
    }
}