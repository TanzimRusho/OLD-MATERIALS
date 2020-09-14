#include<stdio.h>
#include<math.h>

int main(){
    int a,i,n;
    long long s;

    while(scanf("%d %d",&n, &a) == 2){
        s = 0;
        for(i = 1;i <= n; ++i)
            s += i * pow(a,i);

        printf("%lld\n", s);
    }
    return 0;
}
