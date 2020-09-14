#include<stdio.h>

int main(){
    long long n,f;

    while(scanf("%lld",&n) == 1){
        f = 0;

        if((n%4==0 && n%100!=0) || n%400==0){
            printf("This is leap year.\n");
            f=1;
        }

        if(n%15==0){
            printf("This is huluculu festival year.\n");
            f=1;
        }

        if(n%55==0 && ((n%4==0 && n%100!=0) || n%400==0)){
            printf("This is buluculu festival year.\n");
            f=1;
        }

        if(!f)
            printf("This is an ordinary year.\n");
    }
    return 0;
}
