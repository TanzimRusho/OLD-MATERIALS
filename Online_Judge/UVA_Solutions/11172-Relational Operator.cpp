#include<stdio.h>
int main(){
    register unsigned int i;
    unsigned int a,b;
    scanf("%u", &i);
    while(i--){
        scanf("%u%u",&a,&b);
        printf("%c\n", a>b?'>':a<b?'<':'=');
    }
    return 0;
}
