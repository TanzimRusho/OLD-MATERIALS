/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<string.h>
int main(){
	register unsigned int n, i, j, k;
	scanf("%u", &n);
	while(n--){
        unsigned int amp, times;
        scanf("%u%u", &amp, &times);
        char **a = new char*[amp+1];
        a[1] = new char[2];
        a[1] = "1";
        a[2] = new char[3];
        a[2] = "22";
        a[3] = new char[4];
        a[3] = "333";
        a[4] = new char[5];
        a[4] = "4444";
        a[5] = new char[6];
        a[5] = "55555";
        a[6] = new char[7];
        a[6] = "666666";
        a[7] = new char[8];
        a[7] = "7777777";
        a[8] = new char[9];
        a[8] = "88888888";
        a[9] = new char[10];
        a[9] = "999999999";
        while(times--){
            for(i=1; i<=amp; ++i){
                printf("%s\n", a[i]);
            }
            for(int k = amp-1; k>0; --k){
                printf("%s\n", a[k]);
            }
            if(times || n){
                printf("\n");
            }
        }
	}
	return 0;
}

