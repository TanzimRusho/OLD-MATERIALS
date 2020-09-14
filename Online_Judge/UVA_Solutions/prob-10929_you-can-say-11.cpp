#include<stdio.h>
int main(){
    unsigned long long N;
    while(scanf("%llu",&N)==1){
        if(N==0){
            break;
        }
        /*
        !(n%11)? printf("%lld is a multiple of 11.\n", n) : printf("%lld is not a multiple of 11.\n", n);
        */
        if(N%11==0){
            printf("%llu is a multiple of 11.\n", N);
        }else{
            printf("%llu is not a multiple of 11.\n", N);
        }
    }
    return 0;
}
