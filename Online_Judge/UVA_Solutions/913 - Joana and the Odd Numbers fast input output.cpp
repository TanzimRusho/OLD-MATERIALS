/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>


static unsigned long long n;

void Rfastscan(){
    register unsigned long long c = getchar();
    n = 0;
    for(;(c > 47 && c < 58); c = getchar())
        n = (n << 1) + (n << 3) + c - 48;
}


void print(long long x)
{
    // If number is 0
    if (x == 0)
        putchar('0');

    // Remove the last digit and recur
    if (x / 10)
        print(x / 10);

    // Print the last digit
    putchar(x % 10 + '0');
}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    Rfastscan();
    while( n ){

        long long ans =  3 * ( (n + 1) * ( n - (n >> 1) ) )  - 9;

        print(ans);
        putchar('\n');

        Rfastscan();
    }


    return 0;
}
