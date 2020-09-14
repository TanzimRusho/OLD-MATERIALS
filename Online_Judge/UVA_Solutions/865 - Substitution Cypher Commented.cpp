/**
 * Author:    Quickgrid ( Asif Ahmed )
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 865 - Substitution Cypher
 * Technique: Character Mapping, Array Mapping, Array Manipulation
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

    /**
     * Input an integer.
     * discard new line character for enter.
     * discard empty line.
     */
    scanf("%d", &n);
    getchar();
    getchar();


    for(int j = 0; j < n; ++j){

        /**
         * Print spaces between test cases.
         */
        if(j)
            printf("\n");


        /**
         * Input plain text and cipher text.
         */
        gets(plaintext);
        gets(substitution);


        /**
         * Map each character to its ASCII decimal value.
         * In other words map the same character to itself.
         *
         * This is done because not all characters are changed by
         * substitution cipher so rest of the characters map to itself.
         */
        for(int i = 0; i < 256; ++i)
            newLayout[i] = i;


        /**
         * Since plain text and cipher text will equal size any of them
         * can be used to check termination condition.
         *
         * Inside the loop map plain text characters to its substitution.
         */
        for(int i = 0; plaintext[i]; ++i)
            newLayout[ plaintext[i] ] = substitution[i];


        /**
         * Print substitution string first and plain text as per requirement.
         */
        puts(substitution);
        puts(plaintext);


        /**
         * Now take input and scramble until a blank line is found.
         *
         * Here i have used string to output each line but character
         * by character output will also work.
         */
        while(gets(text) && strlen(text)){

            memset(output, 0, sizeof output);

            for( int i = 0; i < strlen( text ); ++i )
                output[i] = newLayout[ text[i] ];

            puts(output);

        }

    }

    return 0;
}
