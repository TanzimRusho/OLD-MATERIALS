/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>
int main(){
	register unsigned int n, i;
    while(scanf("%u", &n) && n){
        register unsigned int works = 1;
        unsigned int *a = new unsigned int[n+1];
        for(i=0; i<n; ++i){
            scanf("%u", &a[i]);
        }
        /* Insertion Sort Slower but an example how it works  */
        for(i=1; i<n; ++i){
            unsigned int temp = a[i];
            unsigned int j = i;
            while(j>0 && a[j-1]>temp){
                a[j] = a[j-1];
                --j;
            }
            a[j] = temp;
        }

        for(i=1; i<n; ++i){
            if(a[i]-a[i-1]>200){                /* If distance of two points is greater than 200 then the car can't make it */
                works = 0;
                break;
            }
        }
        if(2*(1422 - a[n-1]) > 200) works = 0;  /* Since there are no gas station in the last point, we can make it there but we may not have enough to get back to the previous gas station */
        works ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    }
	return 0;
}
