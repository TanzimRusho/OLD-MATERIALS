#include<stdio.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#define SIZE 100000

long long A[SIZE];

long partition(long long front, long long rear){
    long long element = A[rear];
    long long i = front - 1;
    for(long long j = front; j<rear; ++j){
        if(A[j] <=  element){
            ++i;
            long long temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    long long temp = A[i+1];
    A[i+1] = A[rear];
    A[rear] = temp;
    return i+1;
}

void quicksort(long long front, long long rear){
    if(front < rear){
        long long part = partition(front, rear);
        quicksort(front, part-1);
        quicksort(part+1, rear);
    }
}

int main(){
    register long long i = 0;

    clock_t begin, end;
    double time_elapsed;

    srand(time(NULL));
    for(; i<SIZE; ++i){
        A[i] = rand() % SIZE;
    }

    begin = clock();
    quicksort(0, SIZE-1);
    end = clock();

    time_elapsed = (double) (end - begin) / CLOCKS_PER_SEC;

    for(long long i=0; i<SIZE; ++i){
        printf("%lld ", A[i]);
    }
    printf("\nTotal Time Elapsed: %lf\n", time_elapsed);

    return 0;
}
