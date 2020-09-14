/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    http://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<stdlib.h>

static int a[4096];

int main(){
	register unsigned n, i;
	unsigned first, num;
	while(scanf("%u", &n) == 1){
        for(i=0; i<n; ++i){
            scanf("%llu", &a[i]);
        }

        unsigned long long first = abs(a[0] - a[1]), val;
        unsigned fail = 0;

        for(i=2; i<n; ++i){
            unsigned long long val = abs(a[i] - a[i-1]);
            if(val+1 != first){
                fail = 1;
                break;
            }
            else{
                first = val;
            }
        }

        if(fail){
            printf("Not jolly\n");
        }else{
            printf("Jolly\n");
        }
	}
	return 0;
}
