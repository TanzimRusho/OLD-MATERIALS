/**
 * Author:     Quickgrid ( Asif Ahmed )
 * Site:       https://quickgrid.wordpress.com
 * Problem:    UVA 543 - Goldbach's Conjecture
 * Techniques: Primality Test, Prime Number Generation.
 */

#include<stdio.h>
#include<math.h>

#define N 1000000

/**
 * Since value can be up to 1000000
 */
int primesTable[N];

void SieveOfEratosthenes(){

    int i = 2;

    /**
     * Set Every index in the table to be prime.
     */
    for(; i <= N; ++i)
        primesTable[i] = 1;

    /**
     * Base case 0 and 1 are not primes.
     */
    primesTable[0] = primesTable[1] = 0;

    int len = sqrt(N);

    /**
     * Set all multiples of a number to 0 since primes can't divisible by other than itself.
     */
    for(i = 2; i <= len; ++i){
        if(primesTable[i]){
            for( int k = i * i; k <= N; k += i )
                primesTable[k] = 0;
        }
    }

    /**
     * 2 is an Even Prime but the question states only odd primes,
     * So 2 should be left out.
     */
    //primesTable[2] = 0;

}

int main() {

    SieveOfEratosthenes();

    int n;

    /**
     * Input the number and check if its 0.
     */
    while(scanf("%d", &n) && n){

        /**
         * The bound here does not matter much. a < ( n >> 1 ) will also work.
         * But no need for that, max(n) = b - a will be always found before n / 2 for this problem.
         *
         * Since we are maximizing and starting with the lowest value and
         * generating the larger value from that so a and b will be at most n / 2.
         *
         * If, a + b = n, then if a > n / 2 then, b < n / 2 otherwise a + b != n.
         *
         * Also start from 3 since 2 is an even prime and not allowed in this problem.
         */
        int PairCount = 0;

        if( primesTable[ n - 2 ] )
            ++PairCount;


        int tmp = n >> 1;
        for(int a = 3; a <= tmp; a += 2){

            if( primesTable[a] ){

                /**
                 * Since, n = a + b
                 * Them,  b = n - a
                 */
                int b = n - a;

                /**
                 * Check if the resulting number is prime since a and b both are primes.
                 * A number may be made up of multiple primes but print the first one since
                 * we are asked to maximize b - a.
                 */
                if( primesTable[b] ){
                    ++PairCount;
                    //printf("%d = %d + %d\n", n, a, b);
                    //break;
                }
            }
        }

        printf("%d\n", PairCount);

    }


    return 0;
}
