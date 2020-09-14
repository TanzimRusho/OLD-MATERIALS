/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<stdio.h>

static unsigned a[1010][1010];
static char s[1010], t[1010];
static unsigned lens, lent;

int main(){
    unsigned i, j;

    while(scanf("%u %s", &lens, s) == 2){
        scanf("%u %s", &lent, t);

        for(i = 0; i <= lent; ++i)
            a[0][i] = i;
        for(i = 1; i <= lens; ++i)
            a[i][0] = i;

        for(i = 1; i <= lens; ++i){
            for(j = 1; j <= lent; ++j){
                if(s[i-1] == t[j-1])
                    a[i][j] = a[i-1][j-1];
                else
                    a[i][j] = ((a[i-1][j] > a[i][j-1]) ? a[i][j-1] : ( a[i-1][j-1] > a[i-1][j] ? a[i-1][j] : a[i-1][j-1] ) ) + 1;
            }
        }

        printf("%u\n", a[lens][lent]);
    }
	return 0;
}
