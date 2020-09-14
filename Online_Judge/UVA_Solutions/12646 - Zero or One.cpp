/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 12646 - zero or one
 * Technique: XOR Between Bits.
 */

#include<stdio.h>
#include<string.h>


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int A, B, C;
    while( scanf("%d%d%d", &A, &B, &C) == 3 ){

        if( A == B && A == C )
            printf("*\n");
        else{
            if( !(A^B) )
                printf("C\n");
            else{
                if( !(B^C) )
                    printf("A\n");
                else
                    printf("B\n");
            }
        }
    }


    return 0;
}
