#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
	srand(time(NULL));
	int n=0;
	int toNum = 0;
	int element=0, j=0;

	printf("Enter array size:\n");
	scanf("%d", &n);

	printf("Enter the max test number:\n");
	scanf("%d", &toNum);

	int * A = new int[n];
	int * B = new int[n];

	for(int i=0; i<n; i++){
		A[i] = rand() % toNum + 1;
		B[i] = A[i];
	}
	printf("\n");

    printf("Input Array is:\n");
	for(int i=0; i<n; i++){
        printf("%d ", B[i]);
	}
	printf("\n\n");

	//insertion sort
	for(int i=0; i<n; i++){
		element = A[i];
		j = i;
		while(j>0 && A[j-1] > element){
			A[j] = A[j-1];
			j = j - 1;
		}
		A[j] = element;

        //print every step
        printf("\nFor i=%d :\t", i);
        for(int x=0; x<n; x++){
            printf("%d ", A[x]);
        }
        printf("\n");
	}
	printf("\n");

    printf("Sorted Array is:\n");
	for(int i=0; i<n; i++){
        printf("%d ", A[i]);
	}

	return 0;
}
