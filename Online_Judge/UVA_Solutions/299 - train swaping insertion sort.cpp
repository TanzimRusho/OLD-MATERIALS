/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>

static int A[64], c;

int main(){
    register int n, i, j;
    int m, key;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        for(i = c = 0; i < m; ++i)
            scanf("%d", &A[i]);

        /**
         * Insertion sort using inner for loop
         */
        for(i = 1; i < m; ++i){
            key = A[i];
            for(j = i - 1; j >= 0 && A[j] > key; --j){
                A[j + 1] = A[j];
                ++c;
            }
            A[j + 1] = key;
        }

        printf("Optimal train swapping takes %d swaps.\n", c);
    }
    return 0;
}
