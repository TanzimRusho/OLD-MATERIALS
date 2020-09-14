/**
 * Author:     Quickgrid ( Asif Ahmed )
 * Site:       https://quickgrid.wordpress.com
 * Problem:    UVA 543 - Goldbach's Conjecture
 * Techniques: Primality Test, Prime Number Generation.
 */

#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

#define N 100000000

/**
 * Since value can be up to 100000000
 */
static bool primesTable[N];
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
    primesTable[0] = primesTable[1] = 0;

    for( i = 4; i < N; i += 2)
        primesTable[i] = 0;

    int len = sqrt(N);
    for(i = 3; i <= len; i += 2){
        if(primesTable[i]){
            for( int k = i * i; k <= N; k += i + i )
                primesTable[k] = 0;
        }
    }
    primes.push_back(2);

    for(int i = 3; i <= N; i += 2)
        if( primesTable[i] ) primes.push_back(i);

}

void check(){
    if( n & 1 ){
        if( primesTable[ n - 2 ] )
            printf("%d is the sum of %d and %d.\n", n, 2, n - 2 );
        else
            printf("%d is not the sum of two primes!\n", n);

        return;
    }


    int k = int( upper_bound(primes.begin(), primes.end(), n / 2) - primes.begin() );


    for( ; k >= 0; --k){
        if( primesTable[ n - primes[k] ] ){
            if( primes[k] == n - primes[k] )
                continue;
            int a = min(primes[k], n - primes[k]);
            printf("%d is the sum of %d and %d.\n", n, a, n - a );
            return;
        }
    }


    printf("%d is not the sum of two primes!\n", n);
    return;
}


int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    SieveOfEratosthenes();


    /**
     * Input the number and check if its 0.
     */
    Rfastscan();

    while(n){
        check();
        Rfastscan();
    }


    return 0;
}
