/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: Usage of Hexadecimal Values
 */

#include<cstdio>

int main () {
    /*
     * We represent hexadecimal ( Base 16, from 0 to F total of 16 ) with prefix, 0x
     */
    register unsigned i = 0x0;

    /*
     * ASCII code for capital A
     * Explanation:
     *  6*16^1 + 1*16^0
     * =    96 +      1
     * =    97
     */
    int A = 0x61;

    /*
     * ASCII code for line feed
     */
    int n = 0xA;
    int small_a = 0x41;

    while (i < 0x1A){
        int a = small_a++;

        /*
         * Here A starts from 'A' and goes to 'Z'
         * Here n represents new line
         */
        printf("Small: %c%c", A++, n);
        printf("capital: %c%c", a, n);

        ++i;
    }

    return 0;
}
