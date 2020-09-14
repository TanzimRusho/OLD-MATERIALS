/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>

int A[512];

int main(){
	register int n,m,i,j;
	scanf("%d", &n);
	while(n--){
        scanf("%u", &m);
        int dist = 0, median, key;
        for(i=0; i<m; ++i){
            scanf("%d", &A[i]);
        }

        for(i=1; i<m; ++i){
            key = A[i];
            j = i-1;
            while(j >= 0 && A[j] > key){
                A[j+1] = A[j];
                --j;
            }
            A[j+1] = key;
        }

        median = m >> 1;
        key = A[m >> 1];

        for(i=0; i<median; ++i){
            dist += key - A[i];
        }
        for(i=median+1; i<m; ++i){
            dist += A[i] - key;
        }

        printf("%d\n", dist);
	}
	return 0;
}
