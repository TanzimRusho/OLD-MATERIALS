/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    http://quickgrid.wordpress.com
 */

#include<cstdio>
#include<algorithm>

static int A[512];

int main(){
	register int n, m, i, j;
	scanf("%d", &n);

	while (n--){
        scanf("%d", &m);

        if (m == 1){
            /**
             * If only 1 input then no need to process
             * For 1 input the distance is always Zero
             */
            scanf("%*d");
            printf("0\n");
        }

        else{
            int dist = 0, median, key;

            for (i = 0; i < m; ++i)
                scanf("%d", &A[i]);

            /**
             * Sort the input using stl sort
             * Instead of using sorting algorithm, Try to implement Selection Algorithm to find Median in O(n) time
             */
            std::sort(A, A + m);

            /**
             * Find median dividing by two or shifting bit to left once
             * @var key
             * @brief value of median
             */
            median = m >> 1;
            key = A[median];

            /**
             * @var dist
             * @brief summation of distance of every house
             * Any value less than Median can subtracted from median will result in a positive value
             */
            for (i = 0; i< median; ++i)
                dist += key - A[i];

            /**
             * No need calculate for the median so start from (median + 1)
             * In case of value greater than Median, the Median must be subtracted from that value for positive number
             * Also by removing duplicates of median we may speed up the code
             */
            for (i = median + 1; i < m; ++i)
                dist += A[i] - key;

            printf("%d\n", dist);
        }
	}
	return 0;
}
