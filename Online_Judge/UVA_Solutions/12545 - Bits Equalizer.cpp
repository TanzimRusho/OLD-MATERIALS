/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>
#include<string.h>
int main(){
	register unsigned int n, i, c = 0;
	char a[128], b[128];
	scanf("%u", &n);
	while(n--){
        scanf("%s%s", &a, &b);
        unsigned int qMark = 0, flip1 = 0, flip2 = 0, alen = strlen(a), a0 = 0, b0 = 0;
        for(i = 0; i < alen; ++i){
            qMark += a[i] == '?';
            a0 += a[i] == '0';
            b0 += b[i] == '0';
            flip1 += a[i] == '1' && b[i] == '0';
            flip2 += a[i] == '0' && b[i] == '1';
        }
        if(b0 > a0 + qMark){
            printf("Case %u: -1\n", ++c);
            continue;
        }
        if(flip1>flip2){
            printf("Case %u: %u\n", ++c, flip1+qMark);
        }else{
            printf("Case %u: %u\n", ++c, flip2+qMark);
        }

	}
	return 0;
}
