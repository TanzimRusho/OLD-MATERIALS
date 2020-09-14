#include<stdio.h>
#include<math.h>
unsigned int checkPrime(unsigned int n){
    if(n == 2){
        return 1;
    }
    if(n%2 == 0 || n<2 ){
        return 0;
    }
    register unsigned int i;
    unsigned int len = sqrt(n);
    for(i=3; i<=len; i+=2){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    register unsigned int n;
    unsigned int p, prime, mod;
    while(scanf("%u", &n)==1){
        p = checkPrime(n);  /* check if number is prime */
        if(p){
            /* Reverse prime */
            prime = n;
            mod = 1;
            while(prime/mod){
                mod *= 10;
            }
            mod /= 10;
            unsigned int reversePrime = 0;
            while(prime){
                reversePrime += mod * (prime%10);    /* Here reversePrime is the reversed prime */
                prime /= 10;
                mod /= 10;
            }
            /* Reverse prime end */
            if(checkPrime(reversePrime) && reversePrime != n){  /* check if reverse is prime but also check the reversed number does not match the original */
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
