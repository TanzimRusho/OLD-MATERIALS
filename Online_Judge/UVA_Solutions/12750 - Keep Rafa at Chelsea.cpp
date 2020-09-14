/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>

int main(){
	register unsigned int n, m, i, cases = 1;
	char c;
	scanf("%u", &n);
	while(n--){
        unsigned int count = 0, fail = 0;
        scanf("%u", &m); getchar();
        for(i=0; i<m; ++i){
            scanf("%c", &c); getchar();
            if(c == 'W')
                count = 0;
            else
                ++count;
            if(count == 3 && !fail) fail = i;
        }

        if(fail)
            printf("Case %u: %u\n", cases, fail+1);
        else
            printf("Case %u: Yay! Mighty Rafa persists!\n", cases);

        ++cases;
	}
	return 0;
}
