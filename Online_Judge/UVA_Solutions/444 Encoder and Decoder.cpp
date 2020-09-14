#include<stdio.h>

int main(){
    int i,j,a;
    char s[101];
	while(gets(s)){
        for(i=0; s[i]!='\0'; ++i);
        if(s[0]>='0' && s[0]<='9'){
            for(j=i-1; j>=0; --j){
                if(s[j]!='1'){
                    a = s[j-1] + s[j]*10 - '0' +32;
                    if(j-1>=0){
                        j--;
                    }
                }else{
                    a = s[j-2]-'0' + (s[j-1]-'0')*10 + (s[j] -'0')*100;
                    if(j-2>=0){
                        j-=2;
                    }
                }
                printf("%c", a);
            }
            printf("\n");
        }else{
            for(j=i-1; j>=0; --j){
                a = s[j];
                if((s[j]>='a' && s[j]<='c') || (s[j]>='A' && s[j]<='Z') || s[j]==' ' || s[j]==';' || s[j]=='.' || s[j]==',' || s[j]=='!' || s[j]==':' || s[j]=='?'){
                    a = (a%10)*10 + (a/10);
                    if(s[j]=='P' || s[j]=='F'){
                        printf("0");
                    }
                    printf("%d",a);
                }else if(s[j]=='d'){
                    printf("001");
                }else if(s[j]=='x'){
                    printf("021");
                }else{
                    a = (a%100)*100 + ((a/=10)%10)*10 + (a/10);
                    if(a>2000){
                        a-=2000;
                    }else if(a>1000){
                        a-=1000;
                    }
                    printf("%d",a);
                }
            }
            printf("\n");
        }
	}
	return 0;
}
