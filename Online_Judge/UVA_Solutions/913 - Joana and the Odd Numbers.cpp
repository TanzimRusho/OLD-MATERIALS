/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 913 Joana and Odd numbers
 * Technique: Generate Sequence Sum, First number
 *            then generate sum of next numbers
 *            including the generated number.
 */

#include<stdio.h>
#include<string.h>


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    long long n;

    while( scanf("%lld", &n) == 1 ){

        long long m = n >> 1;

        long long part = ( (n * (n + 1)) >> 1 ) - ( m * ( m + 1 ) ) - 4;

        long long firstNum = 2 * part + 3;

        printf("%lld\n", 3 * firstNum + 6);

    }


    return 0;
}
