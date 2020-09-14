#include<stdio.h>

unsigned int a[1001] = {0};
int top;

void push(int num){
    if(top+1 >= 1001){
        return;
    }
    top = num;
    a[num]++;
}

int main(){
    unsigned int n;
    scanf("%u", &n);
    while(n--){
        unsigned int m, i, num;
        scanf("%u", &m);
        for(i=0; i<m; ++i){
            scanf("%u", &num);
            push(num);
        }
        for(int j=0; j<=top; ++j){
            if(a[j]!=0){
                printf("%u: %u\n",j, a[j]);
                a[j] = 0;
            }
        }
    }
    return 0;
}
