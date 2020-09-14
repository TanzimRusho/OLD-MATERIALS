#include<stdio.h>
int main(){
	unsigned char n, s[6];
	scanf("%d", &n);
	while(n--){
        scanf("%s", &s);
        if(s[3]!='\0'){
            printf("3\n");
        }else{
            if((s[0]=='o' && s[1]=='n') || (s[1]=='n' && s[2]=='e') || (s[0]=='o' && s[2]=='e')){
                printf("1\n");
            }else{
                printf("2\n");
            }
        }
	}
	return 0;
}
