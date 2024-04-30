#include <stdio.h>

int dcm(int a, int b);

int main() {

    int n1 = 78, n2 = 204;

    printf("(%d : %d) = %d\n", n1, n2, dcm(n1, n2));

    return 0;
}

int dcm (int a, int b) {
	int auxi;

	while (auxi>0)
	{	
        auxi = a % b ;
		a = b;
        b = auxi;
    }

	return a;
}
