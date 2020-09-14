#include<stdio.h>
#include<string.h>
int main(){
	register unsigned int n;
	unsigned int m, t = 0;
	char s[8];
	scanf("%u", &n);
	while(n--){
        scanf("%s",&s);
        if(!strcmp(s,"report")){
            printf("%u\n",t);
        }else if(!strcmp(s,"donate")){
            scanf("%u",&m);
            t += m;
        }
	}
	return 0;
}
