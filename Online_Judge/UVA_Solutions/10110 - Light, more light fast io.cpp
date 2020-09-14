/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>
#include<math.h>


static unsigned n;

void Rfastscan(){
    register unsigned c = getchar();
    n = 0;
    for(;(c > 47 && c < 58); c = getchar())
        n = (n << 1) + (n << 3) + c - 48;
}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    Rfastscan();
    while( n ){


        unsigned c = sqrt(n);


        if( c * c == n )
            puts("yes");
        else
            puts("no");


        Rfastscan();
    }


    return 0;
}
