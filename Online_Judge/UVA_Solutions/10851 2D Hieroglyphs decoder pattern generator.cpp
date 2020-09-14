/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<string.h>
#include<math.h>

//static char c[] = "b";
//static char c[] = "abcdefghi";
static char c[] = "LA LLUVIA EN SEVILLA ES UNA MARAVILLA";


void b(int i, char ch){
    if( (ch / (long long) pow(2, i) ) % 2 == 0 )
        printf("/");
    else
        printf("\\");
}

void H(int row, int M){
    // String length is M and column is M + 2 so from 0 to M - 1
    M = M + 2;

    for(int i = 0; i < row; ++i ){
        if(i == 0 || i == row - 1){
            for(int j = 0; j < M; ++j)
                printf("/");
        }
        else{
            for(int j = 0; j < M; ++j){
                // Since M = M + 2 so j is j == (M - 1) = (M + 2 - 1) = (M + 1)
                if(j == 0 || j == M - 1)
                    printf("/");
                else
                    b(i - 1, c[j - 1]);
            }
        }
        printf("\n");
    }

}


int main(){

    H(10, strlen(c) );

    return 0;
}
