/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 10696 - f91
 * Type:    Top Down (Recursive) without Memoization
 */

#include<stdio.h>

int f(int n){
    return (n >= 101) ? n - 10 : f(f(n + 11));
}

int main(){
    int n;

    while(scanf("%d",&n) && n)
        printf("f91(%d) = %d\n", n, f(n));

    return 0;
}
