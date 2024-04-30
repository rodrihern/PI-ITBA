#include <stdio.h>

int dondeEsta(int arr[], int dim, int value, int out[]);

int main() {
    int arr[] = {1, 2, 3, 4, 4, 4, 5, 6};
    int out[8];
    int dimOut = dondeEsta(arr, 8, 4, out);

    for (int i = 0; i < dimOut; i++) {
        printf("%d\n", out[i]);
    }
}


int dondeEsta(int arr[], int dim, int elem, int out[]) {
    int j = 0;
    for(int i = 0; i < dim && arr[i] <= elem; i++) {
        if(arr[i] == elem) {
            out[j++] = i;
        }
    }

    return j;


}