/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: LCS Print
 * MUST READ: THIS IS NOT A SOLUTION TO UVA 10405
 */

#include<stdio.h>
#include<string.h>
#define SIZE 1024

static char x[SIZE], y[SIZE];
static int lcs[SIZE][SIZE];

int maxval(int a, int b){
    return a > b ? a : b;
}

/**
 * Print the LCS string
 */
void PrintLCS(int i, int j){
    if(i == 0 || j == 0)
        return;

    if(x[i-1] == y[j-1]){
        PrintLCS(i-1, j-1);
        printf("%c", x[i-1]);
    }
    else if(lcs[i][j-1] > lcs[i-1][j]){
        PrintLCS(i, j-1);
    }
    else
        PrintLCS(i-1, j);
}

int main(){
    register int i, j;

	while(gets(x) && gets(y)){

        int xlen = strlen(x);
        int ylen = strlen(y);

        /*
         * Set the first row and column to zero
         */
        for(i = 0; i <= xlen; ++i)
            lcs[i][0] = 0;

        for(i = 1; i <= ylen; ++i)
            lcs[0][i] = 0;

        /*
         * If both of the characters in string are same then we can reduce both string size by 1 length and calculate rest
         * Else among sub problems by reducing one string and keeping the other one same find the one with the max length
         */
        for(i = 1; i <= xlen; ++i){
            for(j = 1; j <= ylen; ++j){
                if(x[i-1] == y[j-1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = maxval(lcs[i-1][j], lcs[i][j-1]);
            }
        }

        /**
         * Print the LCS string
         */
        printf("LCS String: ");
        PrintLCS(xlen, ylen);
        printf("\n");

        /*
         * The max length is at the bottom right corner of the table
         */
        printf("LCS Length: %d\n", lcs[xlen][ylen] );


        /*
         * LCS table print
         */
        printf("\n");
        printf("LCS Table:\n");
        for(i = 0; i <= xlen; ++i){
            //printf("%d: ", i);
            for(j = 0; j <= ylen; ++j){
                printf("%d ", lcs[i][j]);
            }
            printf("\n");
        }
        printf("\n");

	}
	return 0;
}
