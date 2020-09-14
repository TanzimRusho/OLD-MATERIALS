#include<stdio.h>
#include<limits.h>

#define INSERTION_SORT_THERSHOLD 20

static int A[1024], c;

void Merge(int front, int mid, int rear){
    int n1 = mid - front + 1;
    int n2 = rear - mid;

    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    register unsigned i = 0;
    for(; i < n1; ++i)
        L[i] = A[front + i];

    register unsigned j = 0;
    for(; j < n2; ++j)
        R[j] = A[mid + 1 + j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = j = 0;

    /**
     * Might work without swaps by just incrementing index counters
     */
    register unsigned k = front;
    for(; k <= rear; ++k){
        if(L[i] <= R[j]){
            A[k] = L[i++];
            c += j;
        }
        else
            A[k] = R[j++];
    }
}

void insertionSort(int front, int rear) {
    register int i, j;
    int key;

    for (i = front + 1; i <= rear; ++i) {
        key = A[i];
        j = i - 1;
        while (j >= front && A[j] > key) {
            A[j + 1] = A[j];
            ++c;
            --j;
        }
        A[j + 1] = key;
    }
}

/**
 * Hybrid distribution between insertion sort and merge sort
 * Performs slower than regular merge sort for this small input range
 * Such distribution also works with selection sort
 * Please refer to book introduction to algorithm for more
 */
void HybridMergesort(int front, int rear){
    if(rear - front < INSERTION_SORT_THERSHOLD)
        insertionSort(front, rear);
    if(front < rear){
       int mid = (rear + front) >> 1;
       HybridMergesort(front, mid);
       HybridMergesort(mid + 1, rear);
       Merge(front, mid, rear);
    }
}

int main(){
    register unsigned int i, j, n;
    unsigned key;
	while(scanf("%u", &n) == 1){
        for(i = c = 0; i < n; ++i)
            scanf("%u", &A[i]);

        HybridMergesort(0, n - 1);

        printf("Minimum exchange operations : %u\n", c);
	}
	return 0;
}
