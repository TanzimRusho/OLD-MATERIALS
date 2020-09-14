#include<stdio.h>

char b[101] = {'\0'};
int top = -1;

void push(char c){
    if(top+1 >= 101){
        return;
    }
    int i;
    int match = 0;
    for(i=0; i<top; ++i){
        if(b[i]==c){
            match = 1;
        }
    }
    if(!match){
        b[++top] = c;
    }
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
        int m, i;
        char a[101];
        scanf("%d", &m);
        for(i=0; i<m; ++i){
            scanf("%d", &a[i]);
            push(a[i]+48);
        }
        printf("\t\t%d\n", top+1);
	}
	return 0;
}
