/**
 * Author:     Quickgrid ( Asif Ahmed )
 * Site:       https://quickgrid.wordpress.com
 * Problem:    UVA 543 - Goldbach's Conjecture
 * Techniques: Primality Test, Prime Number Generation.
 */

#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


#define N 1000000

/**
 * Since value can be up to 1000000
 */
int primesTable[N];
vector<int> primes;
static int n;

void Rfastscan(){
    register unsigned c = getchar_unlocked();
    n = 0;
    for(;(c > 47 && c < 58); c = getchar_unlocked())
        n = (n << 1) + (n << 3) + c - 48;
}

void SieveOfEratosthenes(){

    int i;

    /**
     * Set Every index in the table to be prime.
     */
    memset(primesTable, 1, sizeof primesTable);

    /**
     * Base case 0 and 1 are not primes.
     */
    primesTable[0] = primesTable[1] = primesTable[2] = 0;

    for( i = 4; i < N; i += 2)
        primesTable[i] = 0;

    int len = sqrt(N);
    for(i = 3; i <= len; i += 2){
        if(primesTable[i]){
            for( int k = i * i; k <= N; k += i + i )
                primesTable[k] = 0;
        }
    }

    for(int i = 3; i <= N; i += 2){
        if( primesTable[i] )
            primes.push_back(i);
    }

}

int main() {

    SieveOfEratosthenes();

    /**
     * Input the number and check if its 0.
     */
    Rfastscan();
    while(n){

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

        int k = int( upper_bound( primes.begin(), primes.end(), n >> 1 ) - primes.begin() );

            for(int a = 0; a < k; ++a){

                    /**
                     * Since, n = a + b
                     * Then,  b = n - a
                     */
                    int b = n - primes[a];


                    /**
                     * Check if the resulting number is prime since a and b both are primes.
                     * A number may be made up of multiple primes but print the first one since
                     * we are asked to maximize b - a.
                     */
                    if( primesTable[b]){
                        printf("%d = %d + %d\n", n, primes[a], b);
                        break;
                    }

            }

        Rfastscan();
    }


    return 0;
}
