#include<stdio.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>

#define SIZE 10000
long A[SIZE];
/*
 * Divides The array to Sub arrays until only one element is left
 * Then calls Merge function on each sub arrays
 */

void Merge(unsigned long front, unsigned long mid, unsigned long rear){
    /*
     * Get size of the left sub array
     */
    unsigned long n1 = mid-front+1;

    /*
     * Get size of the right sub array
     */
    unsigned long n2 = rear - mid;

    /*
     * Declare left and right sub array with 1 more than original size to store INFINITY
     */
    long *L = new long[n1 + 1];
    long *R = new long[n2 + 1];

    /*
     * Copy elements of given array to Left sub array
     */
    register unsigned long i = 0;
    for(; i<n1; ++i){
        L[i] = A[front+i];
    }

    /*
     * Copy elements of given array to Right sub array
     */
    register unsigned long j = 0;
    for(j=0; j<n2; ++j){
        R[j] = A[mid+1+j];
    }

    /*
     * Set the last element in array to an infinitely big value
     */
    L[n1] = LONG_MAX;
    R[n2] = LONG_MAX;

    /*
     * Reset both sub array index
     */
    i = 0;
    j = 0;

    /*
     * Merge:
     * Compare left and right sub array
     * Merge the smaller element back to original array
     */
    register unsigned long k = front;
    for(; k<=rear; ++k){
        /*
         * The left array item is smaller
         * Increment sub array counter to check for next element
         */
        if(L[i] <= R[j]){
            A[k] = L[i];
            ++i;
        }
        /*
         * The right array item is smaller
         * Increment sub array counter to check for next element
         */
        else{
            A[k] = R[j];
            ++j;
        }
    }
}

void Mergesort(unsigned long front, unsigned long rear){
    if(front < rear){
        /*
         * Calculate the mid point of the given array
         */
        unsigned long mid = (rear+front) >> 1;

        /*
         * Divide given array by recursive sending left half of original array
         */
        Mergesort(front, mid);

        /*
         * Divide given array by recursive sending right half of original array
         */
        Mergesort(mid+1, rear);

        /*
         * Merge the sub array
         */
        Merge(front, mid, rear);
    }
}

int main(){
    long i=0, j=0, temp;

    //variables needed to record time
    clock_t begin, end;

    double time_spent;

    srand(time(NULL));
    for(; i<SIZE; ++i){
        A[i] = rand() % SIZE;
    }

    begin = clock();

    Mergesort(0, SIZE-1);

    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    for(i=0; i<SIZE; ++i){
        printf("%ld ", A[i]);
    }

    printf("\nTime elapsed: %lf\n", time_spent);

    return 0;
}
