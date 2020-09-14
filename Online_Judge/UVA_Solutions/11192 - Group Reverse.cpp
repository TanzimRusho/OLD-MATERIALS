#include<stdio.h>
char s[101];
int top = -1;
void push(char c){
    if(top+1 >= 101){
        return;
    }
    s[++top] = c;
}
void pop(){
    if(top==-1){
        return;
    }
    printf("%c", s[top]);
    s[top--] = '\0';
}
int main(){
	int n,j,i,x;
	while(scanf("%d", &n)==1 && n!=0){
        x = 0;
        scanf("%s", &s);
        for(i=0; s[i]!='\0'; ++i);
        n = i/n;
        for(i=0; s[i]!='\0'; ++i){
            if(s[i+1]=='\0' || x != n){
                push(s[i]);
                ++x;
            }
            if(s[i+1]=='\0' || x==n){
                while(x--){
                    pop();
                }
                x = 0;
            }
        }
        printf("\n");
	}
	return 0;
}
