#include<stdio.h>
int main(){
	unsigned int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
        printf("%u\n",(a-1)+a*(b-1));
	}
	return 0;
}
