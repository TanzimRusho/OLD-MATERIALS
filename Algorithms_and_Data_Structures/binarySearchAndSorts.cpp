#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortArray(int *A, int n);
void binarySearch(int *A, int *low, int *high, int *key);

int main(){
    srand(time(NULL));
    int key = 0, n=0, toNum = 1000;

    printf("Enter array size\n");
    scanf("%d", &n);

    int *A = new int[n];
    int *B = new int[n];

    for(int i=0; i<n; i++){
        *(A+i) = rand() % toNum;
    }

    //sort the array
    sortArray(A, n);

    for(int i=0; i<n; i++){
        printf("%d ", *(A+i));
    }
    printf("\n");

    printf("Enter key:\n");
    scanf("%d", &key);

    int low = 0, high = n;
    binarySearch(A, &low, &high, &key);

    return 0;
}

void binarySearch(int *A, int *low, int *high, int *key){
    int mid=0;
    if(*low<=*high){
        mid = (*low+*high)/2;
        if(A[mid]==*key){
            printf("Found");
        }else if(A[mid] > *key){
            *high = mid-1;
            binarySearch(A, low, high, key);
        }else{
            *low = mid+1;
            binarySearch(A, low, high, key);
        }
    }else{
        printf("Not found\n");
    }
}

void sortArray(int *A, int n){
    int j=0, element=0;
    for(int i=0; i<n; i++){
        element = A[i];
        j = i;
        while(j>0 && A[j-1] > element){
            A[j] = A[j-1];
            --j;
        }
        A[j] = element;
    }
}
