#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

static string x[101], y[101];
static unsigned lcs[101][101];
static unsigned xlen, ylen, k;

void PrintLCS(int i, int j){
    if(i == 0 || j == 0)
        return;

    if(x[i-1] == y[j-1]){
        PrintLCS(i-1, j-1);
        printf("%c", x[i-1]);
    }
    else if(lcs[i][j-1] > lcs[i-1][j])
        PrintLCS(i, j-1);
    else
        PrintLCS(i-1, j);
}

void gcn1(){
    char c = '0';
    x.clear();
    while((c = getchar()) && (c != -1 && c != '\r' && c != '\n' && c != '#'))
        x[k] += c;
}

void gcn2(){
    char c = '0';
    y.clear();
    while((c = getchar()) && (c != -1 && c != '\r' && c != '\n' && c != '#'))
        y[k] += c;
}


int main(){
    register unsigned i, j, c = 0;

    gcn1();
    xlen = x.length();

	while(xlen){

        gcn2();
        ylen = y.length();

        for(i = 0; i < xlen; ++i)
            for(j = 0; j < ylen; ++j)
                lcs[i+1][j+1] = x[i] == y[j] ? lcs[i][j] + 1 : ( lcs[i][j+1] > lcs[i+1][j] ? lcs[i][j+1] : lcs[i+1][j] );


        PrintLCS(xlen, ylen);
        printf("\n");

        gcn1();
        xlen = x.length();
	}
	return 0;
}
