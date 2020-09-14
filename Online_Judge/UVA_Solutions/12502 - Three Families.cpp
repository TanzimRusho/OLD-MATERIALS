/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>
int main(){
    unsigned int n,x,y,z,k;
    scanf("%u",&n);
    while(n--){
        scanf("%u%u%u",&x,&y,&z);
        k = 3*z*x /(x+y) -z;
        printf("%u\n", k);
    }
    return 0;
}
