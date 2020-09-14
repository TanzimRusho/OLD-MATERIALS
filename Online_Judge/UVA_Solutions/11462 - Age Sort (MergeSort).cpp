#include<stdio.h>
#include<limits.h>

#define SIZE 2000002
unsigned int A[SIZE];

void Merge(register unsigned int front, register unsigned int mid1, register unsigned int mid2, register unsigned int rear){
    /*
     * Calculate size for creating sub array
     * In this case calculate size for three sub arrays
     */
    unsigned int n1 = mid1-front+1;
    unsigned int n2 = mid2 - mid1;
    unsigned int n3 = rear - mid2;

    /*
     * Dynamically allocate memory for three sub arrays
     * Here Plus One because we will set a very large value for last position of the array
     */
    unsigned int *L = new unsigned int[n1 + 1];
    unsigned int *R = new unsigned int[n2 + 1];
    unsigned int *X = new unsigned int[n3 + 1];

    /*
     * Copy 1/3 of original array to sub arrays
     * First 1/3 to L array, next 1/3 to R array, last 1/3 to X array
     */
    register  int i = 0;
    for(; i<n1; ++i){
        L[i] = A[front+i];
    }
    for(i=0; i<n2; ++i){
        R[i] = A[mid1+1+i];
    }
    for(i=0; i<n3; ++i){
        X[i] = A[mid2+1+i];
    }

    /*
     * INT_MAX is found in <limits.h>
     * Instead of traversing the whole array increasing runtime
     * We can compare every element again a very large value which will always be greater than or equal to any input
     */
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    X[n3] = INT_MAX;

    /*
     * Reset index counter for sorting
     */
    i = 0;
    register unsigned int p = 0, j = 0, k = front;

    /*
     * Sort:
     * Compare items of each array against each other
     * Copy back the smaller item from the comparison to original array
     */
    for(; k<=rear; ++k){
        if(L[i] <= R[j] && L[i] <= X[p]){
            A[k] = L[i];
            ++i;
        }else if(R[j] <= X[p]){
            A[k] = R[j];
            ++j;
        }else{
            A[k] = X[p];
            ++p;
        }
    }
}

void Mergesort(register int front, register int rear){
    /*
     * Check if there is only One element in array
     */
    if(front < rear){
        /*
         * calculate the size of 1/3 of array
         * Now calculate two mid points since it is 3 way partition
         */
        register int dist = (rear-front+1) /3;
        int mid1 = front + dist;
        int mid2 = mid1 + dist;

        /*
         * Recursively call this array cutting down original array by 1/3 ( One Third )
         */
        Mergesort(front, mid1);
        Mergesort(mid1+1, mid2);
        Mergesort(mid2+1, rear);

        /*
         * Merge divided elements back into original array
         */
        Merge(front, mid1, mid2, rear);
    }
}


int main(){
    register int n, i;
    while(scanf("%u", &n) && n){
        for(i=0; i<n; ++i){
            scanf("%u", &A[i]);
        }

        /*
         * Merge sort from index 0 to index n-1
         */
        Mergesort(0, n-1);

        for(i = 0; i<n; ++i){
            printf("%u", A[i]);
            /*
             * For the last sorted element do not print a space
             */
            if(i!=n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
