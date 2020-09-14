/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 913 Joana and Odd numbers
 * Technique: Reduced formula.
 */

#include<stdio.h>
#include<string.h>


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    unsigned long long n;

    while( scanf("%lld", &n) == 1 ){

        long long ans =  3 * ( (n + 1) * ( n - (n >> 1) ) )  - 9;

        printf("%lld\n", ans);
    }


    return 0;
}
