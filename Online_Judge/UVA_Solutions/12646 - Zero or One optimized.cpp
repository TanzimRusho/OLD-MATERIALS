/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 12646 - zero or one
 * Technique: XOR Between Bits.
 */

#include<stdio.h>


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int A, B, C;
    while( scanf("%d%d%d", &A, &B, &C) == 3 ){

        if( !( A ^ B ) && !( A ^ C ) )
            putchar('*');
        else{
            if( A ^ B ){
                if( B ^ C )
                    putchar('B');
                else
                    putchar('A');
            }
            else
                putchar('C');
        }
        putchar('\n');
    }


    return 0;
}
