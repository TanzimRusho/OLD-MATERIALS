/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 299 Train Swapping (Merge Sort)
 */

#include<stdio.h>
#include<limits.h>

static int A[64], c;

void Merge(int front, int mid, int rear){
    int n1 = mid-front+1;
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

void Mergesort(int front, int rear){
    if(front < rear){
       int mid = (rear + front) >> 1;
       Mergesort(front, mid);
       Mergesort(mid + 1, rear);
       Merge(front, mid, rear);
    }
}

int main(){
    int n, i, j, m;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        for(i = c = 0; i < m; ++i)
            scanf("%d", &A[i]);

        /**
         * To understand Merge sort see my UVA solution age sort 11462
         */
        Mergesort(0, m - 1);

        printf("Optimal train swapping takes %d swaps.\n", c);
    }
    return 0;
}
