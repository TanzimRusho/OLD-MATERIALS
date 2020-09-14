/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 913 - Joana and the odd numbers
 * Technique: Brute Force. Won't get Accepted.
 *            This is just for demonstration. This
 *            won't get accepted due to huge size that
 *            array can't process.
 */

#include<stdio.h>
#include<string.h>


#define N 100000000
//#define M 1000000000


static long long value[N];


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    value[0] = 1;
    value[1] = 15;
    long long offset = 30;


    for( long long i = 2; i < N; ++i ){
        value[i] = value[i-1] + offset;
        offset = offset + 12;
    }


    long long n;
    while( scanf("%lld", &n) == 1 ){
        printf("%lld\n", value[n/2] );
    }


    return 0;
}
