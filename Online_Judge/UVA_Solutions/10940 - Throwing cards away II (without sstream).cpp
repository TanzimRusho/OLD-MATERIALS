#include<stdio.h>

#define SIZE 500002
static char buffer[SIZE];

int main(){
    register unsigned int n,x;
    while(scanf("%u",&n) && n){
        x = 1;
        while(x <= n){
            x <<= 1;
        }

        printf("%u\n", n - x % n);
    }
    return 0;
}
