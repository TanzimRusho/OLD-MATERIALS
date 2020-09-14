#include<stdio.h>

int top = -1;
char st[1000], sentence[1000];

void push(char c){
    st[++top] = c;
}

void pop(){
    printf("%c", st[top]);
    st[top--] = '\0';
}

int main(){
    int c=0;
    while(gets(sentence)){
        for(int i=0; sentence[i]!='\0'; ++i){
            if(sentence[i+1]=='\0' || sentence[i]!=' '){
                push(sentence[i]);
                ++c;
            }
            if(sentence[i] == ' ' || sentence[i+1]=='\0'){
                for(int j=0; j<c; ++j){
                    pop();
                }
                c = 0;
                if(sentence[i+1]!='\0'){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
