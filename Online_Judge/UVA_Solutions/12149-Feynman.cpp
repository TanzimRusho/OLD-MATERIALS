/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 12149 Feynman
 * Type:    Mathematics ( 1^2 + 2^2 + .... + n^2 )
 */

#include<stdio.h>

int main(){
    static unsigned n;

    while(scanf("%u",&n) && n)
        printf("%u\n", n * (n + 1) * (2 * n + 1 ) / 6 );

    return 0;
}
