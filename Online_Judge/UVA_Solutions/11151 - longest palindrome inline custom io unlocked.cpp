/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<stdio.h>

static unsigned a[1000][1000];
static char s[1000];

static unsigned len, n;

static char S[16];

int main(){
    register unsigned i, j, k, x, y, d;

    for(i = 0; i < 1000; ++i)
        a[i][i] = 1;

    register unsigned c = getchar();
    n = 0;
    for(;(c > 47 && c < 58); c = getchar())
        n = (n << 1) + (n << 3) + c - 48;

    while(n--){
        char c = '0';
        len = 0;

        while((c = getchar()) && (c != -1 && c != '\n' && c != '\r'))
            s[len++] = c - 48;

        if(len == 0){
            printf("0\n");
            continue;
        }

        k = 1;

        for(i = 0; i < len; ++i){
            x = j = 0;
            y = k;
            for(; j < len - k; ++j, ++x, ++y)
                a[x][y] = s[x] == s[y] ? a[x+1][y-1] + 2 : (a[x+1][y] > a[x][y-1] ? a[x+1][y] : a[x][y-1]);
            ++k;
        }


        for(i = 0, d = a[0][len-1]; d > 0; d /= 10)
            S[++i] = d % 10 + '0';

        while(i > 0)
            putchar(S[i--]);
        putchar('\n');


    }
	return 0;
}
