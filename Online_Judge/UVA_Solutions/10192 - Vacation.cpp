#include<stdio.h>
#include<string.h>

static char x[101], y[101];
static unsigned lcs[101][101];

int main(){
    register unsigned i, j, c = 0;

	while(gets(x)){

        unsigned xlen = strlen(x);

        if(x[0] == '#' && xlen == 1)
            return 0;

        gets(y);
        unsigned ylen = strlen(y);

        for(i = 0; i < xlen; ++i)
            for(j = 0; j < ylen; ++j)
                lcs[i+1][j+1] = x[i] == y[j] ? lcs[i][j] + 1 : ( lcs[i][j+1] > lcs[i+1][j] ? lcs[i][j+1] : lcs[i+1][j] );


        printf("Case #%u: you can visit at most %u cities.\n", ++c, lcs[xlen][ylen]);
	}
	return 0;
}
