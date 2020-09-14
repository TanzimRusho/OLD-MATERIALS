/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 674 Coin Change ( Dynamic Programming )
 */

#include <stdio.h>
#define N 8192

static int a[N] = {1, 1, 1, 1, 1};
static const int coins[4] = {5, 10, 25, 50};

int main()
{
    register int i, j;

    /**
     * Bottom up iterative coin change DP ( Dynamic Programming )
     */
    for(i = 5; i < N; ++i)
        a[i] = a[i - 1];

    for(i = 0; i < 4; ++i){
        for(j = coins[i]; j < N; ++j)
            a[j] += a[ j - coins[i] ];
    }

    int n;
    a[0] = 0;
    while(scanf("%d", &n) == 1)
        printf("%d\n", a[n]);

    return 0;
}
