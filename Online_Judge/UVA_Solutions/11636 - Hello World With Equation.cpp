#include<stdio.h>

int main(){
    int n;
    register unsigned c = 1;
    while(scanf("%d", &n) && n>-1){
        register unsigned i = 1, p = 0;
        while(i < n){
            /**
             * 2^P > N, Break
             */
            i <<= 1;
            ++p;
        }
        printf("Case %u: %u\n", c, p);
        ++c;
    }
    return 0;
}
