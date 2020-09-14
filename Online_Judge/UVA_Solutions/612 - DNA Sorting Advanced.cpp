/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 * Problem: UVA 612 (DNA Sorting)
 */

#include<cstdio>
#include<cstring>
#include<iostream>

int main(){
    register unsigned int n,i,j,k;
    unsigned int blank = 0;
    scanf("%u", &n);
    while(n--){
        unsigned int w,t;
        scanf("%u %u", &w, &t);
        char **s = new char*[t+1];                  /* Array of strings, initialize element count */
        unsigned int *inv = new unsigned int[t+1];  /* Mapping array for sortedness count */
        for(i=0; i<t; ++i){
            s[i] = new char[w+1];                   /* Initialize size of each string in array */
            scanf("%s", s[i]);
            inv[i] = j = 0;
            for(; j<w; ++j){
                for(k=j+1; k<w; ++k){
                    if(s[i][j] > s[i][k]){
                        ++inv[i];                   /* Count sortedness, number of inversions */
                    }
                }
            }
        }
        for(i=0; i<t; ++i){
            for(j=0; j<t-i-1; ++j){                 /* Bubble sort */
                if(inv[j] > inv[j+1]){
                    std::swap(inv[j], inv[j+1]);    /* Swap the inversion count */
                    std::swap(s[j], s[j+1]);        /* Swap the strings */
                }
            }
        }
        if(blank) printf("\n");                     /* Print a blank line for consecutive test cases */
        blank = 1;
        for(i=0; i<t; ++i) printf("%s\n", s[i]);
    }
    return 0;
}
