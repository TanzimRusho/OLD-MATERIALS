/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
    unsigned long long F[128];
	register unsigned int n, i;
	F[0] = F[1] = 1;
	F[2] = 2;                   /* Fib cheating :) this code runs slightly faster than not predefining some values */
	F[3] = 3;
	F[4] = 5;
	F[5] = 8;
	for(i=6; i<=80; ++i){
        F[i] = F[i-1] + F[i-2];
	}
	while(std::cin >> n){
        if(!n) return 0;
        std::cout << F[n] << "\n";
	}
	return 0;
}
