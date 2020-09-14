/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 10696 - f91
 * Type:    Top Down (Recursive) with Memoization
 */

#include<stdio.h>

static unsigned F[1000000];

unsigned f(unsigned n){
    if(F[n])
        return F[n];

    if(n >= 101)
        return F[n] = n - 10;
    else
        return F[n] = f(f(n+11));
}

int main(){
    unsigned n;

    while(scanf("%u",&n) && n)
        printf("f91(%u) = %u\n", n, f(n));

    return 0;
}
