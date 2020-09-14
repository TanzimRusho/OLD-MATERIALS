/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 11462 ( Age sort )
 * Solution Method: Count Sort
 */
#include<stdio.h>
#include<string.h>

unsigned int A[128];

int main(){
	register unsigned int n, i, c;
    unsigned int num;
	while(scanf("%u", &n) && n){             /* Test cases */
        memset(A, 0, sizeof A);              /* Clear memory for each test case */
        for(i = n; i; --i){                  /* Exits Loop when i is 0 */
            scanf("%u", &num);
            ++A[num];                        /* Since input is never greater than 100, we can use that as index and count occurrence of that index */
        }
        c = i = 1;                           /* i starts from 1 since i is never 0  */
        for(; i<100; ++i){
            while(A[i]--){                   /* Decrease number count at that index */
                if(c == n) printf("%u", i);  /* For the last item in sorted output there is no space */
                else{
                    printf("%u ", i);        /* Just print the index since that was our original input */
                    ++c;                     /* Counter to check if the last element is reached */
                }
            }
        }
        printf("\n");                        /* Print a new line for each test case */
	}
	return 0;
}
