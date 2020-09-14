/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<stdio.h>
#include<string.h>

static int a[1000][1000];
static char s[1000];

int main(){
    int i, j, k, len;

    int cases;
    scanf("%d", &cases);
    getchar();

    while(cases--){
        gets(s);
        len = strlen(s);

        if(len == 0){
            printf("0\n");
            continue;
        }

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

        printf("%d\n", a[0][len-1]);
    }
	return 0;
}
