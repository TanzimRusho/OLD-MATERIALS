/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>
int main(){
	register unsigned int n, ones;
	unsigned int num;
	while(scanf("%u", &n) != EOF){
        ones = num = 1;
        while(num){
            while(num < n){
                num = num*10 + 1;
                ++ones;
            }
            num = num % n;
        }
        printf("%u\n", ones);
	}
	return 0;
}
