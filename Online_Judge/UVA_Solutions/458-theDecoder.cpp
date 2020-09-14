#include<stdio.h>
int main(){
    int i;
    char t[10000+1];
    while(gets(t)){
        for(i=0; t[i]!='\0'; i++){
            t[i] -= 7;
        }
        puts(t);
    }
    return 0;
}
