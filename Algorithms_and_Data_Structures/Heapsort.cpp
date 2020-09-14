#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

#define SIZE 10000
long A[SIZE];

/**
 * In the beginning the heap size is same as the array size
 */
long heapsize = SIZE;

void maxHeapify(long i){
    long largest;

    /**
     * Find right child index
     */
    long l = 2 * i +1;

    /**
     * Compare left child against the current node
     */
    if (l < heapsize && A[l] > A[i])
        largest = l;
    else
        largest = i;

    /**
     * Find right child index
     */
    long r = 2 * i +2;

    /**
     * Compare right child against the calculated largest value node
     */
    if (r < heapsize && A[r] > A[largest])
        largest = r;

    /**
     * Swap the current value with the largest value
     */
    if (largest != i){
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
    register long j;
    /**
     * Start from the last parent and go to root
     */
    for (j = heapsize / 2 - 1; j >= 0; --j)
        maxHeapify(j);
}

void heapsort(){
    buildMaxHeap();

    /**
     * Start from the end of heap swap with root and decrease heap size
     * We know in max heap the biggest item is on top so swapping with the
     * last element will put the biggest value in the end. That way the
     * smallest value will be at the beginning and the biggest will be at the end
     * So by using max heap we can sort in Ascending order.
     */
    register long i;
    for (i = heapsize - 1; i > 0; --i){
        std::swap(A[0], A[i]);

        --heapsize;
        maxHeapify(0);
    }
}

int main(){
    register long i = 0;

    clock_t begin, end;
    double time_elapsed;

    srand(time(NULL));
    for (i = 0; i < SIZE; ++i){
        A[i] = rand() % SIZE;
        //printf("%ld ", A[i]);
    }
    //printf("\n");

    begin = clock();
    heapsort();
    end = clock();

    time_elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

    /**
     * Comment this code if you do not want to see sorted output but just time
     */
    for(i = 0; i < SIZE; ++i){
        printf("%ld ", A[i]);
    }

    printf("\n\nTime elapsed: %lf\n", time_elapsed);

    return 0;
}
