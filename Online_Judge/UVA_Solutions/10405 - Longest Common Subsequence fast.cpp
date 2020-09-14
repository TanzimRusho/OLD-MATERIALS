#include<stdio.h>
#include<string.h>

static char x[1024], y[1024];
static int lcs[1024][1024];

int main(){
    int i, j;

	while(gets(x) && gets(y)){

        unsigned int xlen = strlen(x);
        unsigned int ylen = strlen(y);

        for(i = 1; i <= xlen; ++i){
            for(j = 1; j <= ylen; ++j){
                if(x[i-1] == y[j-1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else if(lcs[i-1][j] > lcs[i][j-1])
                    lcs[i][j] = lcs[i-1][j];
                else
                    lcs[i][j] = lcs[i][j-1];
            }
        }

        printf("%d\n", lcs[xlen][ylen] );

	}
	return 0;
}
