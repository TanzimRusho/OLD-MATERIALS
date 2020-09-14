/**
 * Author:     Quickgrid ( Asif Ahmed )
 * Site:       https://quickgrid.wordpress.com
 * Problem:    UVA
 * Techniques:
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
    primesTable[2] = 0;

}

int main() {

    SieveOfEratosthenes();

    int n;

    /**
     * Input the number and check if its 0.
     */
    while(scanf("%d", &n) && n){

        /**
         *
         */
        for(int i = 0; i < n; ++i){

            if( primesTable[i] ){

                int temp = n - i;

                if(primesTable[temp]){
                    printf("%d = %d + %d\n", n, i, temp);
                    break;
                }

            }
        }

    }


    return 0;
}
