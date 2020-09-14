/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<cstdio>

static int a[1001][1001];
static char s[1001];


static int x, y, len, n;


static char S[20];

static void lprint(){
    int i = 0;

    int d = a[0][len-1];

    while(d > 0)
    {
        S[++i] = d % 10 + '0';
        d = d / 10;
    }

    while(i > 0)
        putchar(S[i--]);
    putchar('\n');
}


void Rfastscan(){
    register unsigned c = getchar();
    n = 0;
    for(;(c > 47 && c < 58); c = getchar())
        n = (n << 1) + (n << 3) + c - 48;
}


void gcn(){
    char c = '0';
    len = 0;

    while((c = getchar()) && (c != -1 && c != '\n' && c != '\r'))
        s[len++] = c - 48;
}


int main(){
    int i, j, k;

    /*
    * Fill diagonals with 1
    */
    for(i = 0; i < 1001; ++i)
        a[i][i] = 1;

    Rfastscan();

    while(n--){
        gcn();

        if(len == 0){
            printf("0\n");
            continue;
        }

        k = 1;

        for(i = 0; i < len; ++i){
            x = j = 0;
            y = k;
            for(; j < len - k; ++j, ++x, ++y){
                if(s[x] == s[y])
                    a[x][y] = a[x+1][y-1] + 2;
                else
                    a[x][y] = (a[x+1][y] > a[x][y-1]) ? a[x+1][y] : a[x][y-1];
            }
            ++k;
        }

        lprint();
    }
	return 0;
}
