#include<stdio.h>
unsigned int twoPow(unsigned int n){
    if(n==0){
        return 1;
    }
    n--;
    return 2*twoPow(n);
}
int main(){
    char s[32];
    unsigned int i,j,sum;
    while(gets(s)){
        if(s[0]=='0' && s[1]=='\0'){
            return 0;
        }
        sum = 0;
        for(i=0; s[i]!='\0'; ++i);
        for(j=0; s[j]!='\0'; ++j){
            sum = sum + (s[j]-48)*(twoPow(i-j)-1);
        }
        printf("%u\n", sum);
    }
    return 0;
}
