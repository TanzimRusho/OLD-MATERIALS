#include<stdio.h>
int main(){
    int i, j, a[100], x;
    char s[1000+1];
    while(gets(s)){
        x=0;
        for(i=0; s[i]!='\0'; i++){
            if(s[i]-' '==0){
                a[x] = i;
                ++x;
                for(j=x+1; s[j]-' '!=0; j++){
                    s[j-x] = s[i];
                }
            }
        }

        puts(s);
    }
    return 0;
}
