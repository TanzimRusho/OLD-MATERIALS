#include<stdio.h>
#include<limits.h>

#define SIZE 2000002
unsigned int A[SIZE];

void Merge(register unsigned int front, register unsigned int mid, register unsigned int rear){
    register unsigned int n1 = mid-front+1;         /* Calculate size of left half of the array */
    register unsigned int n2 = rear - mid;          /* Calculate size of right half of the array */

    unsigned int *L = new unsigned int[n1 + 1];     /* Dynamically create and allocate calculated amount of memory */
    unsigned int *R = new unsigned int[n2 + 1];     /* plus 1 to hold Infinity or A Very large value for which any input can't be larger than */

    register unsigned int i = 0;
    for(; i<n1; ++i){
        L[i] = A[front+i];                          /* Copy elements from given original array to left sub array */
    }
    register unsigned int j = 0;
    for(; j<n2; ++j){
        R[j] = A[mid+1+j];                          /* Copy elements from given original array to right sub array */
    }
    L[n1] = INT_MAX;                                /* In the last position of sub array set a very large value */
    R[n2] = INT_MAX;
    i = j = 0;

    register unsigned int k = front;                /* Instead of wasting space creating a new array, we can use the original large array since we have already copied all items to sub arrays */
    for(; k<=rear; ++k){
        if(L[i] <= R[j]) A[k] = L[i++];             /* Compare and copy smaller elements of sub arrays onto original array */
        else A[k] = R[j++];
    }
}

void Mergesort(register unsigned int front, register unsigned int rear){
    if(front < rear){
       register unsigned int mid = (rear+front) >> 1;  /* Find the mid point of the array */
                                                    /* Shift bits to right once, equivalent of divided by TWO */

       Mergesort(front, mid);                       /* Recursively divide array in left portion */
       Mergesort(mid+1, rear);                      /* Recursively divide array in right portion */

       Merge(front, mid, rear);                     /* Merge the divided array back again in sorted order */
    }
}


int main(){
    register unsigned int n, i;
    while(scanf("%u", &n) && n){
        for(i=0; i<n; ++i){
            scanf("%u", &A[i]);
        }
        Mergesort(0, n-1);                          /* Call merge sort function for each test case */

        for(i = 0; i<n; ++i){
            printf("%u", A[i]);
            if(i!=n-1) printf(" ");                 /* Do not print a space after last sorted item */
        }
        printf("\n");
    }
    return 0;
}
