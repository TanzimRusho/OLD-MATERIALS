//12372 - Packing for Holiday
#include<stdio.h>

int main(){
	int l,w,h,n, i=1;
	scanf("%d", &n);
	while(n--){
        scanf("%d %d %d", &l, &w, &h);
        if(l <= 20 && w <= 20 && h <= 20){
            printf("Case %d: good\n", i);
        }else{
            printf("Case %d: bad\n", i);
        }
        ++i;
	}
	return 0;
}
