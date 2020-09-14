#include<stdio.h>
int main(){
    int n;
    unsigned int c = 1;
	while(scanf("%d", &n) && n>-1){
        unsigned int i = 0;
        if(n>1){
            unsigned int lines = 1;
            for(i=1; i<=n; ++i){
                lines *= 2;
                if(lines >= n){
                    break;
                }
            }
        }
        printf("Case %u: %u\n", c++, i);
	}
	return 0;
}
