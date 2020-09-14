/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   Fibonacci number generation using golden ratio.
 * Technique:
 */

#include<bits/stdc++.h>
using namespace std;


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long double phi  = 1.61803398874989484820458683436563811772030917980576286213544862270526046281890;
    long double phiN = 0.61803398874989484820458683436563811772030917980576286213544862270526046281890;


    // Change value of n to desired value.
    // Should give correct Fibonacci value for 1 to 70.
    int n = 70;

    long double F = ( pow(phi, n) - pow( phiN, n ) ) / sqrt(5);

    cout.setf(ios::fixed);
    cout << setprecision(0) << round(F) << "\n";



    return 0;
}
