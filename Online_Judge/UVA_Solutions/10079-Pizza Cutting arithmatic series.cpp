/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>

int main(){
    long long n;
    while(scanf("%lld", &n)){
        if(n < 0)
            return 0;

        /**
         * Arithmetic series 1 to n with extra 1
         */
        printf("%lld\n", 1 + n * (n + 1) / 2);
    }
    return 0;
}
