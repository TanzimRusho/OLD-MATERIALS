/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 12894 ( Perfect Flag )
 */

#include<stdio.h>

int main(){
	register unsigned int n;
	scanf("%u", &n);
	while(n--){
        int x0, y0, x1, y1, cx, cy, r;
        scanf("%u%u%u%u%u%u%u", &x0, &y0, &x1, &y1, &cx, &cy, &r);
        unsigned int len = x1 - x0;
        unsigned int wid = y1 - y0;
        if( ( 5*wid == 3*len ) && ( len == 5*r ) && 20*( cx - x0 ) == 9*len && 2*( cy-y0 ) == wid ){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
	}
	return 0;
}
