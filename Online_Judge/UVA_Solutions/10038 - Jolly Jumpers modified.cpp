/*
 * Author:   Quickgrid ( Asif Ahmed )
 * Site:     https://quickgrid.wordpress.com
 * Problem:  UVA
 * Solution:
 */

#include<stdio.h>


#define N 3002


static unsigned int A[N];
static unsigned int B[N];


int main(){

    int n;

    while( scanf("%u", &n) == 1 ){

        for(int i = 0; i < n; ++i){
            A[i] = i;
            scanf("%d", &B[i]);
        }


        bool failed = false;


        for(int i = 1; i < n; ++i){

            int value = B[i] - B[i - 1];

            if( value < 0 )
                value = - value;

            if( value = A[value] )
                A[value] = 0;
            else {
                failed = true;
                break;
            }
        }


        if(failed)
            printf("Not jolly\n");
        else{

            for(int i = 1; i < n; ++i){
                if( A[i] ){
                    failed = true;
                    break;
                }
            }

            if( failed )
                printf("Not jolly\n");
            else
                printf("Jolly\n");
        }

    }


    return 0;
}
