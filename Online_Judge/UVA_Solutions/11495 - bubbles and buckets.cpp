/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<stdio.h>
#include<limits.h>

static unsigned A[100001], L[50001], R[50001], c;

void Merge(unsigned front, unsigned mid, unsigned rear){
    unsigned n1 = mid-front+1;
    unsigned n2 = rear - mid;

    unsigned i = 0;
    for(; i < n1; ++i)
        L[i] = A[front + i];

    unsigned j = 0;
    for(; j < n2; ++j)
        R[j] = A[mid + 1 + j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = j = 0;

    /**
     * Might work without swaps by just incrementing index counters
     */
    unsigned k = front;
    for(; k <= rear; ++k){
        if(L[i] <= R[j]){
            A[k] = L[i++];
            c += j;
        }
        else
            A[k] = R[j++];
    }
}

void Mergesort(unsigned front, unsigned rear){
    if(front < rear){
       unsigned mid = (rear + front) >> 1;
       Mergesort(front, mid);
       Mergesort(mid + 1, rear);
       Merge(front, mid, rear);
    }
}

int main(){
	unsigned n, k, i, j;

	while(scanf("%u", &n) && n){
        c = i = 0;
        for(; i < n; ++i)
            scanf("%u", &A[i]);

        Mergesort(0, n - 1);

        (c & 1) ? printf("Marcelo\n") : printf("Carlos\n");

	}
	return 0;
}
