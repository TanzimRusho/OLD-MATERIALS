#include<stdio.h>

long long n, d, a, b;

void inline minus(long long x, long long y, long long r, long long t){
    a = x * t - y;
    b = y * t;
}

int main(){
    register long long i;
    while(scanf("%lld%lld", &n, &d) == 2){

        for(i = 2; ; ++i){
            minus(n, d, 1, i);

            if( a >= 0 ){
                printf("1/%lld\n", i);
                n = a;
                d = b;
                if(a == 0) break;
            }
        }

    }

    return 0;
}
