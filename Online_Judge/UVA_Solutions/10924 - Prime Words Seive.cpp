/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<math.h>

/**
 * Since there is max of 20 characters in a single line
 * Calculating with biggest value 'Z' gives a max of 1040
 */
#define N 1041

static int table[128];
static unsigned primes[N];

void PreSum(){
    register unsigned i, j = 1;

    /**
     * Set 1 to 26 for 'a' to 'z'
     */
    for(i = 'a'; i <= 'z'; ++i, ++j)
        table[i] = j;

    /**
     * Set 27 to 52 for 'a' to 'z'
     */
    for(i = 'A'; i <= 'Z'; ++i, ++j)
        table[i] = j;
}

void SieveOfEratosthenes(){
    register unsigned i, j;

    /**
     * For this problem though 0 and 1 is prime
     */
    for(i = 0; i < N; ++i)
        primes[i] = 1;

    unsigned len = sqrt(N);

    for(i = 2; i <= len; ++i){
        if(primes[i]){
            for(j = i*i; j <= N; j += i)
                primes[j] = 0;
        }
    }
}

int main(){
    /**
     * Pre calculate character value table
     * Pre calculate prime values using Sieve of Eratosthenes
     */
    PreSum();
    SieveOfEratosthenes();

    char s[32];
    register unsigned i;

	while(gets(s)){
        unsigned sum = 0;

        /**
         * Get character value from pre calculated character value table and sum them
         */
        for(i=0; s[i]; ++i)
            sum += table[s[i]];

        /**
         * Get primality from pre calculated prime table
         */
        if(primes[sum])
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
	}
	return 0;
}
