#include<cstdio>
#include<iostream>

#define SIZE 2000002

int A[SIZE];

void quick_sort (int *a, register int n) {
    register int i, j, mid;
    if (n < 2) return;

    mid = a[n >> 1];

    for (i = 0, j = n - 1; ; i++, j--) {
        while (a[i] < mid)
            i++;
        while (mid < a[j])
            j--;

        if (i >= j) break;
        std::swap(a[i], a[j]);
    }
    quick_sort(a, i);
    quick_sort(a + i, n - i);
}

int main () {
    register unsigned int n, i;
    while(scanf("%u", &n) && n){
        for(i=0; i<n; ++i){
            scanf("%d", &A[i]);
        }
        quick_sort(A, n);

        for (i = 0; i < n; i++)
            printf("%d%s", A[i], i == n - 1 ? "\n" : " ");

    }
    return 0;
}
