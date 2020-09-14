#include<stdio.h>
int main(){
    int n;
    register unsigned int c = 1;
	while(scanf("%d", &n) && n>-1){
        if(n>1){
            if(n > 8192)
                printf("Case %u: 14\n", c);
            else if(n >= 4097)
                printf("Case %u: 13\n", c);
            else if(n >= 2049)
                printf("Case %u: 12\n", c);
            else if(n >= 1025)
                printf("Case %u: 11\n", c);
            else{
                register unsigned int i = 1, lines = 1;
                for(; i<=n; ++i){
                    lines <<= 1;
                    if(lines >= n){
                        break;
                    }
                }
                printf("Case %u: %u\n", c, i);
            }
        }else printf("Case %u: 0\n", c);
        ++c;
	}
	return 0;
}
