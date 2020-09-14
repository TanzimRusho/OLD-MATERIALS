#include<stdio.h>
#include<math.h>

#define N 1000000

unsigned int *primes = new unsigned int[N];         /* Since value can be up to 1000000 */
unsigned int *SieveOfEratosthenes(unsigned int n){
    register unsigned int i = 2;
    for(; i<=n; ++i){
        primes[i] = 1;
    }
    primes[0] = primes[1] = 0;
    unsigned int len = sqrt(n);
    for(i=2; i<=len; ++i){
        if(primes[i]){
            for(unsigned int k = i*i; k<=n; k+=i){
                primes[k] = 0;
            }
        }
    }
    return primes;
}
int main(){
    register unsigned int n;
    unsigned int prime, mod;
    primes = SieveOfEratosthenes(N);    /* Pre calculate sieve for every value */
    while(scanf("%u", &n)==1){
        if(primes[n]){                  /* Since sieve is calculated and stored on table just do a look up */
            prime = n;
            mod = 1;
            while(prime/mod){
                mod *= 10;
            }
            mod /= 10;
            unsigned int reversePrime = 0;
            while(prime){
                reversePrime += mod * (prime%10);
                prime /= 10;
                mod /= 10;
            }
            if(primes[reversePrime] && reversePrime != n){  /* Again access table to see if it is a prime */
                printf("%u is emirp.\n", n);
            }else{
                printf("%u is prime.\n", n);
            }
        }else{
            printf("%u is not prime.\n", n);
        }
    }
    return 0;
}
