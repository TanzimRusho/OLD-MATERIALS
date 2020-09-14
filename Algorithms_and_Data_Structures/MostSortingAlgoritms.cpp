#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swapArray(int *arr, int minIndex, int oldIndex);
void recuriveBinarySearch(int *A, int *key, int *left, int *right, int *mid);

int main(){
	srand(time(NULL));
	int n=0;
	int toNum = 0;
	int element=0, j=0;
	int minIndex=0;
	int temp=0;

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

	printf("Sorting....\n");

    /*
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
    */


    //selection sort
    for(int i=0; i<n-1; i++){
        minIndex = i;
        for(int j=i+1; j<n; j++){
            if(A[minIndex]>A[j]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swapArray(A, minIndex, i);
        }
    }


   /*
    //bubble sort
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(A[j]>A[j+1]){
                swapArray(A, j, j+1);
            }
        }
    }
    */

    //quick sort

    /*
    //replacement selection sort
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(A[i] > A[j]){
                swapArray(A, i, j);
            }
        }
    }
    */

    //print the sorted array
    printf("Sorted Array is:\n");
	for(int i=0; i<n; i++){
        printf("%d ", A[i]);
	}
	printf("\n");

    //binary search
    int key=0;
    int mid=0;
	int left = 0;
	int right = n-1;
	printf("Enter number to search:\n");
	scanf("%d", &key);
	printf("Searching....\n");

    /*
    //normal binary search
	while(left<=right){
        mid = (left+right)/2;
        if(A[mid]==key){
            printf("Found.....");
            break;
        }else if(A[mid]>key){
            right = mid-1;
        }else if(A[mid]<key){
            left = mid+1;
        }
	}
	if(left>right){
        printf("Not Found.....\n");
	}
	*/

	//recursive binary search
    recuriveBinarySearch(A, &key, &left, &right, &mid);


	return 0;
}

void swapArray(int *arr, int minIndex, int oldIndex){
    int temp;
    temp = *(arr+oldIndex);
    *(arr+oldIndex) = *(arr+minIndex);
    *(arr+minIndex) = temp;
}

void recuriveBinarySearch(int *A, int *key, int *left, int *right, int *mid){
    while(*left <= *right){
        *mid = (*left + *right)/2;
        if( *(A + *mid) == *key ){
            printf("found at: ", *mid);
            break;
        }
        else if( *(A + *mid) > *key ){
            *right = *mid - 1;
        }
        else if( *(A + *mid) < *key ){
            *left = *mid + 1;
        }
        recuriveBinarySearch(A, key, left, right, mid);
    }
    if(*left > *right){
        printf("Not found.....\n");
    }
}
