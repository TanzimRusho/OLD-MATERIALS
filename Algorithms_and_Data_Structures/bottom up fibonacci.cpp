/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>

/**
 * Increase this value for numbers more than 64
 */
#define N 64
long long F[N];

/**
 * Top Down Fibonacci Memoization
 */
long long bottomUpMemFib(long long n){
    /**
     * Terminating Condition
     */
    F[0] = 0;
    F[1] = 1;

    register unsigned i;
    for(i = 2; i <= n; ++i)
        F[i] = F[i - 1] + F[i - 2];

    return F[n];
}

int main(){
    register unsigned i;

    unsigned n;
    printf("Enter a number:\n");
    scanf("%u", &n);

    printf("%lld\n", bottomUpMemFib(n));

    return 0;
}
