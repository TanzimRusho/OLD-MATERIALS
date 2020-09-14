/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    http://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<stdlib.h>

static int A[512];

int main(){
	register int n,m,i,j;
	scanf("%d", &n);

	while (n--){
        scanf("%d", &m);
        int dist = 0, median, key;

        for (i = 0; i < m; ++i){
            scanf("%d", &A[i]);
        }

        /**
         * Insertion Sort:
         * Two portions sorted and unsorted
         */
        for (i = 1; i < m; ++i){
            key = A[i];
            j = i - 1;

            /**
             * Compare every element with sorted portion ( elements to its left )
             */
            while (j >= 0 && A[j] > key){

                /**
                 * While comparing shift items to right until the comparison is false
                 */
                A[j + 1] = A[j];
                --j;
            }

            /**
             * When comparison is False or done, we found the sorted position for that element so we insert it in that position
             */
            A[j + 1] = key;
        }

        /**
         * Find Median value, left shift once is divided by Two
         */
        key = A[m >> 1];

        /**
         * Since elements after Median is bigger than Median So, we need to find absolute value of them
         */
        for (i = 0; i < m; ++i){
            dist += abs(key - A[i]);
        }

        printf("%d\n", dist);
	}
	return 0;
}
