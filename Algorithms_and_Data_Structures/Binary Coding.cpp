/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: Usage of Binary Values
 */

#include<cstdio>

int main () {
    /*
     * We represent binary ( Base 2, 0 and 1 ) with prefix, 0b
     */
    register unsigned i = 0b0;

    /*
     * ASCII code for capital A
     * Explanation:
     *  1*2^6 + 0*2^5 + 0*2^4 + 0*2^3 + 0*2^2 + 0*2^1 + 1*2^0
     * =   64 +     0 +     0 +     0 +     0 +     0 +     1
     * =   65
     */
    int A = 0b1000001;

    /*
     * ASCII code for line feed
     */
    int n = 0b0001010;

    /*
     * The trick here is that difference between An ASCII Code for a capital
     * and small letter is always 32. So if we can toggle that bit representing
     * 32 then we can convert capital to small letter and vice versa.
     */
    while (i < 0b0011010){
        /*
         * Since Capital letter differ in the bit representing 32 bit
         * We can just bitwise OR it with any capital letter and get
         * its small letter representation.
         * We know from truth table of OR that
         * 0 OR 1 = 1, meaning our bit representing 32 is active
         */
        int a = 0b0100000 | A;

        /*
         * Here A starts from 'A' and goes to 'Z'
         * Here n represents new line
         */
        printf("Capital: %c%c", A++, n);
        printf("Small: %c%c", a, n);

        ++i;
    }

    return 0;
}
