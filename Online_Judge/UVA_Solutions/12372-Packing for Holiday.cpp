#include<stdio.h>
int main(){
    int a,b,c,d;
    scanf("%d",&a);
    while(a--){
        scanf("%d %d %d",&b,&c,&d);
        if(b==c&&d<=b) printf("Case 1: good\n");
        else printf("Case 2: bad\n");
    }
    return 0;
}
