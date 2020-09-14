#include<stdio.h>
#include<string.h>

#define N 100000

static char stackArray[N];
static char inputString[N];

int stringLength;
int top = -1;

void push(char c){
    stackArray[++top] = c;
}

void pop(){
    if(top == -1)
        return;
    printf("%c ", stackArray[top]);
    stackArray[--top] = '\0';
}

int main(){
    int i, j;

    while(gets(inputString)){

        stringLength = strlen(inputString);
        int backTrace = stringLength - 1;

        for(i = 0; i < (stringLength - 1); ++i){
            if(inputString[i] != inputString[backTrace])
                push(inputString[i]);
            else
                break;
        }

        printf("\n%s", inputString);
        for(j = 0; stackArray[j]; ++j)
            pop();

        printf("\n");
    }

    return 0;
}
