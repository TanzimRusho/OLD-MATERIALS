/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 * Problem:
 */

#include<stdio.h>

static int sequence[10000];
static int csort[10000];

int main(){

    int num, j, c = 0;

    while(scanf("%d", &num) == 1){

        for(j = 0; j < c; ++j){
            if(sequence[j] == num){
                ++csort[j];
                break;
            }
        }

        if(j == c){
            sequence[j] = num;
            ++csort[c];
            ++c;
        }
    }

    for(j = 0; j < c; ++j)
        printf("%d %d\n", sequence[j], csort[j]);


    return 0;
}
