/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 10082 WERTYU ( using c++ string stream )
 */

#include<cstdio>
#include<sstream>
#include<iostream>

#define N 256

/**
 * Predefined keyboard layout
 */
static const char kb[64] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
static char s[N], A[N];

void createTable(){
    /**
     * space character does not change
     */
    A[' '] = ' ';

    /**
     * Create keyboard layout from broken keyboard
     */
    register int i = 0;
    for(; kb[i]; ++i)
        A[kb[i+1]] = kb[i];
}

int main(){
    std::ios_base::sync_with_stdio(NULL);
    std::cin.tie(0);
    register int i, j;

    /**
     * Create the keyboard layout beforehand
     */
    createTable();

	while(gets(s)){
        /**
         * Create a string stream from table to print all together
         * We can also use string and add each character then print
         */
        std::stringstream ss;

        /**
         * Lookup characters from predefined table
         */
        for(i = 0; s[i]; ++i)
            ss << A[s[i]];

        std::cout << ss.str() << "\n";
	}
	return 0;
}
