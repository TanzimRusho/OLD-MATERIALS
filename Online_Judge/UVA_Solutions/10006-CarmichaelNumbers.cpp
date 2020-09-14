#include<stdio.h>
#include<math.h>
int main(){
    long long n,i,x;
    while(scanf("%lld",&n)==1){
        if(n==0) return 0;
        x=0;
        for(i=2; i<n; ++i){
            if((long long)pow(i,n)%n-i==0){
                x=1;
            }else x=0;
        }
        if(x==1){
            printf("The number %lld is a Carmichael number.\n",n);
        }
        else printf("%lld is normal.\n",n);
    }
    return 0;
}
