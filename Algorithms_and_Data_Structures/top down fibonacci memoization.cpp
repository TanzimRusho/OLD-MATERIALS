/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>

#define N 64
long long F[N];

/**
 * Top Down Fibonacci Memoization
 */
long long topDownMemFib(long long n){
    /**
     * If its not 1 then it means there is already a calculated value
     * So no more need to compute, just return that value
     */
    if(F[n] != -1)
        return F[n];

    F[n] = topDownMemFib(n - 1) + topDownMemFib(n - 2);
    return F[n];
}

int main(){
    register unsigned i;

    unsigned n;
    printf("Enter a number:\n");
    scanf("%u", &n);

    /**
     * First set the whole array to -1, means there are no calculated value
     */
    F[0] = 0;
    F[1] = 1;
    for(i = 2; i <= n; ++i)
        F[i] = -1;

    printf("%lld\n", topDownMemFib(n));

    return 0;
}
