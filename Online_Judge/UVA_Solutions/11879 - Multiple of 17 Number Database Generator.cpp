/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */

#include<bits/stdc++.h>

int main(){
	register unsigned int n, i = 1;
	printf("Enter a number for which to generate multiple:\n");
	unsigned int num;
	scanf("%u", &num);
	printf("How many multiple of %u to generate:\n", num);
	scanf("%u", &n);
	for(; i < n; ++i){
        printf("%u %u\n", num*i, i);
	}
	return 0;
}
