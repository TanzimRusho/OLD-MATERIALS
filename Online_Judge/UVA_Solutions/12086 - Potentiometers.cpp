/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */

#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
using namespace std;

#define SIZE 100000
static char buffer[SIZE], A[SIZE];

int main(){
	fread(buffer, 1, sizeof buffer, stdin);
	stringstream ss(buffer);
	register unsigned int i, c = 0;
	unsigned int n,m,k;
	while(ss >> n){
        if(!n) return 0;
        k = n; --k;

        memset(A, 0, sizeof A);
        for(i=0; i<n; ++i){
            ss >> m;
            A[i] = m;
        }

        char str[128] = {'\0'};
        unsigned int x, y;
        if(c) printf("\n");
        printf("Case %u:\n", ++c);

        while(ss >> str){
            if(!strcmp(str, "END")) break;
            ss >> x >> y;
            unsigned int sum = 0;
            if(!strcmp(str, "M")){
                if(x == y) printf("%u\n", A[x-1]);
                else{
                    for(i=x-1; i<=y; ++i)
                        sum += A[i];
                    printf("%u\n", sum);
                }
            }else if(!strcmp(str, "S")){
                A[y-1] = x;
            }else break;
        }
	}
	return 0;
}
