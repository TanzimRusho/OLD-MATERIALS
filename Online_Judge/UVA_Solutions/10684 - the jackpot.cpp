/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<stdio.h>

static int subset[10002];

int main(){
	static unsigned n, i;
	static int sum, max;

	while(scanf("%u", &n) && n){
        for(i = 0; i < n; ++i)
            scanf("%d", &subset[i]);

        sum = max = i = 0;

        for(; i < n; ++i){
            sum += subset[i];

            if(sum < 0)
                sum = 0;

            if(sum > max)
                max = sum;
        }

        if(max > 0)
            printf("The maximum winning streak is %d.\n", max);
        else
            printf("Losing streak.\n");
	}
	return 0;
}
