#include<stdio.h>

int main(){
	int n;
	while(scanf("%d", &n)==1){
        int i=1;
        if(n!=1){
            unsigned long long s = 0;
            for(; i<=n; ++i){
                s += i*i*i;
            }
            printf("%llu\n", s);
        }else{
            printf("1\n");
        }
	}
	return 0;
}
