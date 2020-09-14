/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>

#define N 128

static char input[N];
static int surface[N];


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;

    while( scanf("%d", &n) && n ){
        gets(input);

        int maximum = 0;

        int k = 0;
        for( int i = 0; i < n; ++i ){
            gets(input);

            int xcount = 0;

            for(int j = 0; input[j]; ++j){
                if( input[j] == 'X' )
                    ++xcount;
            }

            if( xcount > maximum )
                maximum = xcount;

            surface[k++] = xcount;
        }


        int sum = 0;
        for( int i = 0; i < n; ++i ){
            sum = sum + maximum - surface[i];
        }

        printf("%d\n", sum);

    }


    return 0;
}
