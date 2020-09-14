/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<limits.h>

/**
 * c is swap count
 */
static int A[64], c;

int main(){
    int n, i, j, m;
    scanf("%d", &n);

    while(n--){
        scanf("%d", &m);
        for(i = c = 0; i < m; ++i)
            scanf("%d", &A[i]);

        /**
         * Bubble Sort
         */
        for(i = 0; i < m - 1; ++i){
            for(j = i + 1; j < m; ++j){
                /**
                 * No need to swap elements
                 * This code may be moved input loop
                 */
                if(A[i] > A[j])
                    ++c;
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", c);
    }
    return 0;
}
