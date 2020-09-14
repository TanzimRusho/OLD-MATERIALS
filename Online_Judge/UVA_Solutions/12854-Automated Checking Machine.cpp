#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    while(scanf("%d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j)==10){
        (a+f==1&&b+g==1&&c+h==1&&d+i==1&&e+j==1)?printf("Y\n"):printf("N\n");
    }
    return 0;
}
