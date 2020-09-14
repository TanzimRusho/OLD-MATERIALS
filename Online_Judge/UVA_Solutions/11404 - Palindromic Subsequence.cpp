/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<stdio.h>
#include<string.h>

static int a[1010][1010];
static char s[1010];
static char output[1010];
static int len, index;

void printString(int i, int j){
    if(a[i][j] == 0)
        return;

    if(s[i] == s[j]){
        output[index++] = s[i];
        printString(i + 1, j - 1);
    }
    else{
        if(a[i][j] == a[i][j-1])
            printString(i, j - 1);
        else if(a[i][j] == a[i+1][j])
            printString(i + 1, j);

    }
}

int main(){
    int i, j, k;

    while(gets(s)){
        len = strlen(s);

        /*
         * Fill diagonals with 1
         */
        for(i = 0; i < len; ++i)
            a[i][i] = 1;

        /*
         * K limits the number of steps to process
         * Also sets the column for which to start processing
         */
        int x, y;
        k = 1;

        /*
         * Reset output array
         */
        index = 0;
        memset(output, 0, sizeof output);

        for(i = 0; i < len; ++i){
            x = 0;
            y = k;
            for(j = 0; j < len - k; ++j, ++x, ++y){
                if(s[x] == s[y])
                    a[x][y] = a[x+1][y-1] + 2;
                else
                    a[x][y] = (a[x+1][y] > a[x][y-1]) ? a[x+1][y] : a[x][y-1];
            }
            ++k;
        }

        if(a[0][len - 1] == 1)
            printf("%c\n", s[0]);
        else{
            printString(0, len - 1);
            printf("%s", output);
            i = strlen(output) - 2;
            for(; i >= 0; --i)
                printf("%c", output[i]);
            printf("\n");
        }
    }
	return 0;
}
