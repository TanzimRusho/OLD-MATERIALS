/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 10696 - f91
 * Type:    Trickery :)
 */

#include<stdio.h>

static unsigned n;

void Rfastscan(){
    register unsigned c = getchar_unlocked();
    n = 0;
    for(;(c > 47 && c < 58); c = getchar_unlocked())
        n = (n << 1) + (n << 3) + c - 48;
}

int main(){

    Rfastscan();
    while(n){
        if(n > 100)
            printf("f91(%u) = %u\n", n, n - 10);
        else
            printf("f91(%u) = 91\n", n);
        Rfastscan();
    }

    return 0;
}
