/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<stdio.h>
#define N 30002

static long long a[N];
static const unsigned coins[5] = {1, 5, 10, 25, 50};

int main(){
    register unsigned int i, j;
	unsigned n;

    /**
     * This is a bit slower than split loop version
     * In problem 674 i split the loop in two different ways
     * We can apply this for both UVA problem 357 and 674
     */
    a[0] = 1;
    for(i = 0; i < 5; ++i){
        for(j = coins[i]; j < N; ++j)
            a[j] += a[j - coins[i]];
    }

	while(scanf("%lld", &n) == 1){
        if(a[n] == 1)
            printf("There is only %lld way to produce %u cents change.\n", a[n], n);
        else
            printf("There are %lld ways to produce %u cents change.\n", a[n], n);
    }
	return 0;
}
