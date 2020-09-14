#include<stdio.h>
unsigned int arr[10010];

void precalculate(){
    register unsigned int n = 10001;
    for(; n; --n){
        if(n > 8192)
            arr[n] = 14;
        else if(n >= 4097)
            arr[n] = 13;
        else if(n >= 2049)
            arr[n] = 12;
        else if(n >= 1025)
            arr[n] = 11;
        else if(n >= 513)
            arr[n] = 10;
        else if(n >= 257)
            arr[n] = 9;
        else if(n >= 129)
            arr[n] = 8;
        else if(n >= 65)
            arr[n] = 7;
        else if(n >= 33)
            arr[n] = 6;
        else if(n >= 17)
            arr[n] = 5;
        else if(n >= 9)
            arr[n] = 4;
        else if(n >= 5)
            arr[n] = 3;
        else if(n >= 3)
            arr[n] = 2;
        else if(n >= 2)
            arr[n] = 1;
        else arr[n] = 0;
    }
}
int main(){
    precalculate();
    int n;
    register unsigned int c = 1;
	while(scanf("%d", &n) && n>-1){
        printf("Case %u: %u\n", c, arr[n]);
        ++c;
	}
	return 0;
}

/*
#include<stdio.h>
int main(){
    int n;
    register unsigned int c = 1;
	while(scanf("%d", &n) && n>-1){
        if(n>1){
            if(n > 8192)
                printf("Case %u: 14\n", c);
            else if(n >= 4097)
                printf("Case %u: 13\n", c);
            else if(n >= 2049)
                printf("Case %u: 12\n", c);
            else if(n >= 1025)
                printf("Case %u: 11\n", c);
            else{
                register unsigned int i = 1, lines = 1;
                for(; i<=n; ++i){
                    lines <<= 1;
                    if(lines >= n){
                        break;
                    }
                }
                printf("Case %u: %u\n", c, i);
            }
        }else printf("Case %u: 0\n", c);
        ++c;
	}
	return 0;
}
*/
