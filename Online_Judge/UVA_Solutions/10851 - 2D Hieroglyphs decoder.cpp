/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 10851 - 2D Hieroglyphs Decoder
 * Technique: Binary to Decimal, 2D row wise calculation.
 */

#include<stdio.h>
#include<string.h>

static char c[10][80];

int main(){

    int n, i;

    scanf("%u", &n);
    getchar();

    while( n-- ){

        /**
         * Reset each of the strings ignoring first and last row.
         */
        for(i = 1; i < 9; ++i)
            memset(c[i], 0, sizeof c[i]);


        /**
         * Reuse i for taking string inputs.
         */
        i = 0;


        /**
         * Take input of 10 rows.
         * Another logic is to discard first and last line when taking input.
         * But this method is easier to code.
         */
        while(gets(c[i]) && strlen(c[i]))
            ++i;


        /**
         * Take count of the column.
         * Since input is a rectangle so any column length will work.
         */
        int cols = strlen(c[0]);


        /**
         * Ignore last column.
         * Also last row.
         */
        cols = cols - 1;
        i = i - 1;


        /**
         * k represents columns and j represents rows.
         * k starts from 1 ignoring first column.
         */
        for(int k = 1; k < cols; ++k){

            // Reset for each column.
            int sum = 0;
            int shift = 1;

            /**
             * Ignoring the first and last character.
             * i starts from 1 ignoring first row.
             */
            for(int j = 1; j < i; ++j){

                // Double slash means (for this case) in binary 1 and add that value.
                // Otherwise its zero.
                if( c[j][k] == '\\' )
                    sum = sum + shift;

                // Bitwise shift left once for each column.
                shift = shift << 1;
            }

            // Print character wise or use string then print outside this loop.
            printf("%c", sum);
        }

        printf("\n");

    }

    return 0;
}
