#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortArray(int *A, int n);
int binarySearch(int *A, int *low, int *high, int *key);

int main(){
    srand(time(NULL));
    int key = 0, n=0, toNum = 1000;

    printf("Enter array size:\n");
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
    int isFound = binarySearch(A, &low, &high, &key);

    if(isFound){
        printf("Found\n");
    }else{
        printf("Not Found\n");
    }

    return 0;
}

int binarySearch(int *A, int *low, int *high, int *key){
    int mid=0;
    if(*low<=*high){
        mid = (*low+*high)/2;
        if(A[mid]==*key){
            return 1;   //means found
        }else if(A[mid] > *key){
            *high = mid-1;
            binarySearch(A, low, high, key);
        }else{
            *low = mid+1;
            binarySearch(A, low, high, key);
        }
    }else{
        return 0;   //means not found
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
