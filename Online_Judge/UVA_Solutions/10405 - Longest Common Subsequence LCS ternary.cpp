#include<stdio.h>
#include<string.h>

static char x[1001], y[1001];
static unsigned lcs[1001][1001];

int main(){
    register unsigned i, j;

	while(gets(x) && gets(y)){

        unsigned xlen = strlen(x);
        unsigned ylen = strlen(y);

        for(i = 0; i < xlen; ++i)
            for(j = 0; j < ylen; ++j)
                lcs[i+1][j+1] = x[i] == y[j] ? lcs[i][j] + 1 : ( lcs[i][j+1] > lcs[i+1][j] ? lcs[i][j+1] : lcs[i+1][j] );

        printf("%u\n", lcs[xlen][ylen] );

	}
	return 0;
}
