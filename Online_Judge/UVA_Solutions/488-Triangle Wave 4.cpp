/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 488 ( Triangle Wave )
 */
#include<stdio.h>

/* For this problem amplitude does not exceed 9, so you can cheat :) */
const char *a[] = {"", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999"};

int main(){
	register unsigned int n, i, j, k;
	scanf("%u", &n);
	while(n--){
        unsigned int amp, times;
        scanf("%u%u", &amp, &times);
        while(times--){
            for(i=1; i<amp; ++i){
                printf("%s\n", a[i]);   /* Just print the predefined strings */
            }
            for(k = i; k; --k){
                printf("%s\n", a[k]);
            }
            if(times || n){
                printf("\n");
            }
        }
	}
	return 0;
}

