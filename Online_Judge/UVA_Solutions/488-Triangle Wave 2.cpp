/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 488 ( Triangle Wave )
 */

#include<stdio.h>
#include<string.h>
int main(){
	register unsigned int n, i, j, k;
	scanf("%u", &n);
	while(n--){
        unsigned int amp, times;
        scanf("%u%u", &amp, &times);
        while(times--){
            char **a = new char*[amp+1];        /* Allocate memory for string array, allocates memory for string count */
            for(i=1; i<=amp; ++i){
                a[i] = new char[i+1];           /* Allocate memory for the string */
                memset(a[i], 0, sizeof a[i]);   /* Reset the array */
                for(j=0; j<i; ++j){
                    a[i][j] = i+48;             /* Populate the string with numbers */
                }
                printf("%s\n", a[i]);           /* Print the generated strings */
            }
            for(k = amp-1; k>0; --k){
                printf("%s\n", a[k]);           /* Print the rest in reverse */
            }
            if(times || n){                     /* For the last loop do not print new line */
                printf("\n");
            }
        }
	}
	return 0;
}

