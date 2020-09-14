#include<stdio.h>

int main(){
	int n,a,b,c;
	scanf("%d", &n);
	while(n--){
        scanf("%d%d", &a, &b);
        if(b>a || (a-b)%2!=0){
            printf("impossible\n");
        }else{
            c = (a-b)/2;
            b = b+c;
            printf("%d %d\n", b, c);
        }
	}
	return 0;
}
