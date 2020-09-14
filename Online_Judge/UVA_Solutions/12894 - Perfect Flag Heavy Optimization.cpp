/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 * Problem: UVA 12894 ( Perfect Flag )
 */

#include<stdio.h>

int main(){
    register unsigned n;
    int x0, y0, cx, cy, r;
    scanf("%u", &n);

    while (n--){
        scanf("%u%u%*u%*u%u%u%u", &x0, &y0, &cx, &cy, &r);

        if (2 * ( cx - x0 ) + ( y0 - cy ) == 3 * r)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}


/*

#include<cstdio>

int main(){
    register unsigned n;
    int x0, y0, cx, cy, r;
    scanf("%u", &n);

    while (n--){
        scanf("%u%u%*u%*u%u%u%u", &x0, &y0, &cx, &cy, &r);
        (2 * ( cx - x0 ) + ( y0 - cy ) == 3 * r) ? printf("YES\n") : printf("NO\n");

    }
    return 0;
}

*/
