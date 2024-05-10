#include <stdio.h>

int igualesRet(int v1[], int v2[]) {
    if(*v1 == -1 || *v2 == -1) {
        return (*v1 == *v2);
    }
    return (*v1 == *v2) && igualesRet(v1+1, v2+1);
}

void igualesVoid(int v1[], int v2[], int * ans) {
    if(*v1 == -1 || *v2 == -1) {
        *ans = (*v1 == *v2);      
        return;
    }
    if(*v1 != *v2) {
        *ans = 0;
        return;
    }
    
    igualesVoid(v1+1, v2+1, ans);    
}

int main() {
    int v1[] = {1, 2, 3, -1};
    int v2[] = {1, 2, 3, -1};
    int ans;

    igualesVoid(v1, v2, &ans);

    printf("%d", ans);
}