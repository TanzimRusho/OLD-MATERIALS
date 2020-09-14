#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void binarySearch(int *A);

int main(){
    srand(time(NULL));
    int key = 0, n=0;

    printf("Enter array size\n");
    scanf("%d", &n);

    int *A = new int[n];
    itn *B = new int[n];

    printf("Enter key:\n");
    scanf("%d", &key);


    return 0;
}
