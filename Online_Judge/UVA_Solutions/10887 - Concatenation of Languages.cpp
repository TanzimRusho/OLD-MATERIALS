/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>
int main(){
    char s[11];
	int n,a,b,c = 0;
	scanf("%d", &n);
	while(n--){
        scanf("%d%d", &a, &b);
        unsigned int k = 0, t = a + b, i = a, j = b;
        while(a--){
            scanf("%s", &s);
            if(s[0] == ' '){
                ++k;
            }
        }
        i -= k;
        //printf("%u\n",i);
        k = 0;
        while(b--){
            scanf("%s", &s);
            if(s[0] == ' '){
                ++k;
            }
        }
        j -= k;
        printf("Case %u: %u\n", ++c, i*j);
	}
	return 0;
}
