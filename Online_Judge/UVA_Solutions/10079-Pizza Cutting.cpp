#include<stdio.h>

int main(){
    long long c, i, n;

    while(scanf("%lld",&n) && n >= 0){

        for(i = c = 1; i <= n; ++i)
            c += i;

        printf("%lld\n", c);
    }
    return 0;
}
