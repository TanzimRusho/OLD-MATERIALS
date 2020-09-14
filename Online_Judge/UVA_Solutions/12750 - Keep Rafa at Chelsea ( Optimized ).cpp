/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */
#include<stdio.h>

unsigned int count, fail;
int main(){
	register unsigned int n, m, i, cases = 1;
	char c;
	scanf("%u", &n);
	while(n--){
        scanf("%u", &m); getchar();
        for(i=1; i<=m; ++i){
            if(fail){
                getchar(); getchar();
                continue;
            }else{
                c = getchar(); getchar();
                if(c == 'W')
                    count = 0;
                else
                    ++count;
                if(count == 3) fail = i;
            }
        }

        if(fail)
            printf("Case %u: %u\n", cases, fail);
        else
            printf("Case %u: Yay! Mighty Rafa persists!\n", cases);

        ++cases;

        count = fail = 0;
	}
	return 0;
}
