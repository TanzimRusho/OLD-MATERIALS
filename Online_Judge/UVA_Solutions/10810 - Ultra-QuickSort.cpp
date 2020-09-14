/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<stdio.h>
#include<limits.h>

static long long A[1000001], L[500001], R[500001];
static long long c;

void Merge(unsigned front, unsigned mid, unsigned rear){
    unsigned n1 = mid-front+1;
    unsigned n2 = rear - mid;

    unsigned i = 0;
    for(; i < n1; ++i)
        L[i] = A[front + i];

    unsigned j = 0;
    for(; j < n2; ++j)
        R[j] = A[mid + 1 + j];

    L[n1] = LONG_MAX;
    R[n2] = LONG_MAX;
    i = j = 0;

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
	unsigned n, i;

	while(scanf("%u", &n) && n){
        c = i = 0;
        for(; i < n; ++i)
            scanf("%u", &A[i]);

        Mergesort(0, n - 1);

        printf("%llu\n", c);

	}
	return 0;
}
