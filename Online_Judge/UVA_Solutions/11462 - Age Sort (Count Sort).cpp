/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>
#include<string.h>

unsigned int A[128];

int main(){
	register unsigned int n, c, i;
    unsigned int num;
	while(scanf("%u", &n) && n){
        memset(A, 0, sizeof A);
        for(i = n; i; --i){
            scanf("%u", &num);
            ++A[num-1];
        }
        c = 1;
        for(i=0; i<100; ++i){
            while(A[i]--){
                if(c == n) printf("%u", i+1);
                else{
                    printf("%u ", i+1);
                    ++c;
                }
            }
        }
        printf("\n");
	}
	return 0;
}
