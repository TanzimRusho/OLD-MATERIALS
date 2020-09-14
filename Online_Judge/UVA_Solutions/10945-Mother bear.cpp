#include<stdio.h>
int main(){
    int i,j,p;
    char s[101],t[101];
    while(gets(s)){
        j=0, p=1;
        if(s[0]+s[1]+s[2]+s[3]==294) return 0;
        for(i=0;s[i]!='\0';++i){
            if(s[i]>=65 && s[i]<=90){
                t[j]=s[i]+32;
                ++j;
            }else if(s[i]>=97 && s[i]<=122){
                t[j]=s[i];
                ++j;
            }
        }
        for(i=0; i<=j/2; ++i){
            if(t[i]!=t[j-i-1]){
                p=0;
                printf("Uh oh..\n");
                break;
            }
        }
        if(p==1) printf("You won't be eaten!\n");
        for(i=0; i<j; ++i) t[i]=0;
    }
    return 0;
}
