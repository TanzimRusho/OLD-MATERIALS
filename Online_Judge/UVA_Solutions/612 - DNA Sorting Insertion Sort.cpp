/*
 * @author Quickgrid ( Asif Ahmed )
 * @link   https://quickgrid.wordpress.com
 * Problem UVA 612 (DNA Sorting)
 */

#include<cstdio>
#include<iostream>
#include<cstring>

int main(){
    register unsigned n,i,j,k;
    unsigned blank = 0;

    scanf("%u", &n);
    while (n--){
        unsigned w,t;
        scanf("%u%u", &w, &t);

        /* Array of strings, initialize element count */
        char **s = new char *[t + 1];
        /* Mapping array for sortedness count */
        unsigned *inv = new unsigned[t + 1];

        for (i = 0; i < t; ++i){
            /* Initialize size of each string in array */
            s[i] = new char[w + 1];
            scanf("%s", s[i]);
            inv[i] = j = 0;
            for (; j < w; ++j){
                for (k = j + 1; k < w; ++k){
                    if (s[i][j] > s[i][k])
                        /* Count sortedness, number of inversions */
                        ++inv[i];
                }
            }
        }

        /*
         * Bubble sort
         * Any stable sort should be able to sort it correctly e.g. insertion sort, merge sort
         */
//        for (i = 0; i < t - 1; ++i){
//            for (j = 0; j < t - i - 1; ++j){
//                if (inv[j] > inv[j+1]){
//                    /* Swap the inversion count */
//                    std::swap(inv[j], inv[j+1]);
//                    /* Swap the strings */
//                    std::swap(s[j], s[j+1]);
//                }
//            }
//        }

        /*
         * Insertion Sort
         */
        unsigned key;
        int q;
        char *strkey = new char[w + 1];
        for(i = 1; i < t; ++i){
            key = inv[i];
            strcpy(strkey, s[i]);
            q = i - 1;
            while(q >= 0 && inv[q] > key){
                inv[q + 1] = inv[q];
                strcpy(s[q + 1], s[q]);
                --q;
            }
            inv[q + 1] = key;
            strcpy(s[q + 1], strkey);
        }

        /* Print a blank line for consecutive test cases */
        if (blank) printf("\n");
        blank = 1;

        for (i = 0; i < t; ++i)
            printf("%s\n", s[i]);
    }
    return 0;
}
