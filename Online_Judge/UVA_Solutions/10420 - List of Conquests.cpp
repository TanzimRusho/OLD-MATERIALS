#include<stdio.h>
#include<string.h>

char s[2000][75];
int top = -1;

void push(char *country){
    if(top + 1 >= 2000){
        return;
    }
    strcpy(s[top++], country);
}

void pop(){
    if(top == -1){
        return;
    }

}

int main(){
    int n,i;
    scanf("%d", &n);
    while(n--){
        scanf("%s", &country);
        gets(name);
    }
}
