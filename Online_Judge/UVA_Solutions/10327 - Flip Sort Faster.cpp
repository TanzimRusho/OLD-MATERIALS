/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 10327 Flip Sort
 */

#include<cstdio>
#include<iostream>

static unsigned a[1024];

int main(){
    register unsigned int i, j, k, n;
	while(scanf("%u", &n) == 1){
        for(i = 0; i < n; ++i)
            scanf("%u", &a[i]);

        /**
         * Bubble Sort
         */
        for(k = j = 0; j < n; ++j){
            for(i = 0; i < n - j - 1; ++i){
                if(a[i] > a[i + 1]){
                    std::swap(a[i], a[i + 1]);
                    ++k;
                }
            }
        }

        printf("Minimum exchange operations : %u\n", k);
	}
	return 0;
}
