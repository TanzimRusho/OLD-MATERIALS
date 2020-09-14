/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<string.h>

#define N 256

static char text[N];
static char plaintext[N];
static char substitution[N];


static char newLayout[N];

static char output[N];


int main(){

    int n;

    scanf("%d", &n);
    getchar();
    getchar();

    for(int j = 0; j < n; ++j){

        if(j)
            printf("\n");

        gets(plaintext);
        gets(substitution);

        for(int i = 0; i < 256; ++i)
            newLayout[i] = i;

        for(int i = 0; plaintext[i]; ++i)
            newLayout[ plaintext[i] ] = substitution[i];


        puts(substitution);
        puts(plaintext);


        while(gets(text) && strlen(text)){

            memset(output, 0, sizeof output);

            for( int i = 0; i < strlen( text ); ++i )
                output[i] = newLayout[ text[i] ];

            puts(output);

        }

    }

    return 0;
}
