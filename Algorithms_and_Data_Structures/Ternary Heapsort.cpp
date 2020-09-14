/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: Ternary Heap Sort
 */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

#define SIZE 10000000
int A[SIZE], heapsize = SIZE;

void maxHeapify(int i){
    int largest;

    /**
     * Find right child index
     */
    int l = 3 * i + 1;

    /**
     * Compare left child against the current node
     */
    if(l < heapsize && A[l] > A[i])
        largest = l;
    else
        largest = i;

    /**
     * find mid child index
     */
    int m = 3 * i + 2;

    /**
     * Compare mid child against the calculated largest value node
     */
    if(m < heapsize && A[m] > A[largest])
        largest = m;

    /**
     * Find right child index
     */
    int r = 3 * i + 3;

    /**
     * Compare right child against the calculated largest value node
     */
    if(r < heapsize && A[r] > A[largest])
        largest = r;

    /*
     * If child nodes have larger value then current node
     */
    if(largest != i){
        /**
         * Swap the two values
         */
        std::swap(A[i], A[largest]);

        /**
         * Max heapify again rest of the heap
         */
        maxHeapify(largest);
    }
}

void buildMaxHeap(){
    int j;
    /**
     * operate on third of array
     */
    for(j = heapsize / 3 - 1; j >= 0; --j)
        maxHeapify(j);
}

void heapsort(){
    buildMaxHeap();

    int i;
    for(i = heapsize - 1; i > 0; --i){
        std::swap(A[0], A[i]);

        /**
         * Decrease the heap size as right of heap is already sorted
         */
        --heapsize;

        /**
         * Again max heapify the rest of the heap
         */
        maxHeapify(0);
    }
}

int main(){
    int i;

    clock_t begin, end;
    double time_elapsed;

    srand(time(NULL));
    for(i=0; i<SIZE; ++i){
        A[i] = rand() % SIZE;
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Sorting Now....\n");
    begin = clock();
    heapsort();
    end = clock();

    time_elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

    for(i=0; i<SIZE; ++i)
        printf("%d ", A[i]);

    printf("\n\nTime elapsed: %lf\n", time_elapsed);

    return 0;
}
