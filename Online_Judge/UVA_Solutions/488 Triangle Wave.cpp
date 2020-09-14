/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */

#include<stdio.h>
int main(){
	register unsigned int n, i, j, k;
	scanf("%u", &n);
	while(n--){
        unsigned int amp, times;
        scanf("%u%u", &amp, &times);
        while(times--){
            for(i=1; i<=amp; ++i){
                for(j=0; j<i; ++j){
                    printf("%u", i);
                }
                printf("\n");
            }
            for(k=amp-1; k>0; --k){
                for(j=0; j<k; ++j){
                    printf("%u", k);
                }
                printf("\n");
            }
            if(times || n){
                printf("\n");
            }
        }
	}
	return 0;
}
