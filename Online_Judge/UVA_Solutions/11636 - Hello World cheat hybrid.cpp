#include<stdio.h>
unsigned int arr[10010];

void precalculate(){
    register unsigned int n = 10001;
    for(; n>1024; --n){
        if(n > 8192)
            arr[n] = 14;
        else if(n >= 4097)
            arr[n] = 13;
        else if(n >= 2049)
            arr[n] = 12;
        else if(n >= 1025)
            arr[n] = 11;
    }
}
int main(){
    precalculate();
    int n;
    register unsigned int c = 1;
	while(scanf("%d", &n) && n>-1){
        switch(n){
        case 0:
        case 1:
            printf("Case %u: 0\n", c);
            break;
        default:
            if(n>1024){
                printf("Case %u: %u\n", c, arr[n]);
            }else{
                register unsigned int lines = 1, i = 1;
                for(; i<=n; ++i){
                    lines <<= 1;
                    if(lines >= n){
                        break;
                    }
                }
                printf("Case %u: %u\n", c, i);
            }
        }
        ++c;
	}
	return 0;
}

