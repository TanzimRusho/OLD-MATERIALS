#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>

#define SIZE 10000
long A[SIZE], heapsize = SIZE;

void maxHeapify(long i){
    long largest;

    /**
     * Find index of first, second, third child
     */
    long l = 3 * i + 1;
    long m = 3 * i + 2;
    long r = 3 * i + 3;

    /**
     * Find largest among the parent and its child. And save that index
     */
    if(l < heapsize && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if(m < heapsize && A[m] > A[largest])
        largest = m;

    if(r < heapsize && A[r] > A[largest])
        largest = r;

    /**
     * If the largest index is not of parent then there is another bigger value
     * So swap that value with parent
     */
    if(largest != i){
        std::swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

void buildMaxHeap(){
    long j;
    /**
     * Starting from the last parent to root max heapify
     */
    for(j = heapsize / 3 - 1; j >= 0; --j)
        maxHeapify(j);
}

void heapsort(){
    buildMaxHeap();

    long i;
    /**
     * Send biggest value root in the end
     * then max heapify from root again
     * this procedure sorts in ascending order because of max heap
     */
    for(i = heapsize - 1; i > 0; --i){
        std::swap(A[0], A[i]);

        --heapsize;
        maxHeapify(0);
    }
}

int main(){
    clock_t begin, end;
    double time_elapsed;

    srand(time(NULL));
    register long i = 0;
    for(; i<SIZE; ++i){
        A[i] = rand() % SIZE;
        //printf("%ld ", A[i]);
    }
    //printf("\n");

    begin = clock();
    heapsort();
    end = clock();

    time_elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

    //for(i=0; i<SIZE; ++i)
      //  printf("%ld ", A[i]);

    printf("\n\nTime elapsed: %lf\n", time_elapsed);

    return 0;
}
