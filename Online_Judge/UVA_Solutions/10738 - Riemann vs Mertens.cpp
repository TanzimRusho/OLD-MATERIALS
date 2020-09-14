/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>
#include<math.h>

#define N 1000001

unsigned int *primes = new unsigned int[N];

void sieveOfEratosthenes(){
    register unsigned int i = 2;
    for(; i<N; ++i){
        primes[i] = 1;
    }
    primes[0] = primes[1] = 0;
    unsigned int len = sqrt(N);
    for(i=2; i<len; ++i){
        if(primes[i]){
            for(unsigned int k = i*i; i<=N; k+=i){
                primes[k] = 0;
            }
        }
    }
}

int main(){
	register unsigned int n, i;
	sieveOfEratosthenes();
	while(scanf("%u", &n) && n!=0){
        if(primes[n]){

        }else{

        }
	}
	return 0;
}
