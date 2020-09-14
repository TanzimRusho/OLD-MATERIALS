/*
 * Author:   Quickgrid ( Asif Ahmed )
 * Site:     https://quickgrid.wordpress.com
 * Problem:  UVA 12592 Slogan Learning Princess
 * Solution: Knuth Morris Pratt ( KMP ) algorithm implementation
 */

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

static string slogan[100];
static string query;

#define r 160

/**
 * Space may be further minimized at the cost of running time
 */
static unsigned DFA[r][100];

unsigned DFAStringMatching(string text, string pattern){
    unsigned m = pattern.length();
    unsigned n = query.length();

    /**
     * i is incrementing by 1, meaning using text[i] whole input string can be traversed.
     * text[i] is a character. DFA[text[i]][j] means text[i] character column and j th row.
     * This position or cell contains the column for next transition.
     */
    unsigned i, j;
    for(i = 0, j = 0; i < n && j < m; ++i)
        j = DFA[text[i]][j];

    /**
     * If j equals m then all transition completed successfully
     * meaning the string are a match.
     */
    if(j == m)
        return 1;
    else
        return 0;
}

void CreateDFA(string pattern){
    unsigned m = pattern.length();

    /**
     * Set the first state to 1
     */
    DFA[pattern[0]][0] = 1;

    unsigned x, j, k;
    for(x = 0, j = 1; j < m; ++j){
        /**
         * Copy all values from x column to j column.
         */
        for(k = 0; k < r; ++k)
            DFA[k][j] = DFA[k][x];

        /**
         * Update position in table to the next transition.
         */
        DFA[pattern[j]][j] = j + 1;

        /**
         * Update the column from which to copy values.
         */
        x = DFA[pattern[j]][x];
    }


    /**
     * Uncomment code below to see transitions to states in DFA table
     * For printing transitions in DFA
     * Delete this before submitting to UVA
     * Empty or Zero in DFA means transition to initial state
     */

    /*
    int val = 0;
    for(j = 0; j < m; ++j){
        for(k = 0; k < r; ++k){
            val = DFA[k][j];
            if(val)
                printf("Transition from state (%d) to state (%d) for input: %c\n", j, DFA[k][j], k);
        }
        printf("\n");
    }
    */

}

int main()
{
    static unsigned n, i, q;

    scanf("%u", &n);
    getchar();

    /**
     * Since each input has two lines
     */
    static unsigned limit = 2 * n;

    for(i = 0; i < limit; i += 2){
        getline(cin, slogan[i]);
        getline(cin, slogan[i+1]);
    }

    scanf("%u", &q);
    getchar();

    while(q--){
        getline(cin, query);

        /**
         * Create the DFA table from input
         */
        CreateDFA(query);

        for(i = 0; i < limit; i += 2){
            /**
             * If the first line matches a String stored in memory
             * then print the next one
             */
            if(DFAStringMatching(slogan[i], query))
                cout << slogan[i+1] << "\n";
        }
    }

    return 0;
}
