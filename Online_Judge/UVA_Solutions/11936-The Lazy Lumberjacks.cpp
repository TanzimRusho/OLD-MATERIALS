#include<stdio.h>
int main(){
    unsigned short a,b,c,n;
    scanf("%hu",&n);
    while(n--){
        scanf("%hu %hu %hu",&a,&b,&c);
        (a+b>c&&b+c>a&&c+a>b)?printf("OK\n"):printf("Wrong!!\n");
    }
    return 0;
}
