#include<stdio.h>
int main(){
    int a,b,c,m;
    while(scanf("%d %d %d",&a,&b,&c)==3){
        if(a+b+c==0) return 0;
        if(a>b && a>c){
            if(c*c+b*b==a*a) printf("right\n");
            else printf("wrong\n");
        }else if(b>c && b>a){
            if(a*a+c*c==b*b) printf("right\n");
            else printf("wrong\n");
        }else{
            if(a*a+b*b==c*c) printf("right\n");
            else printf("wrong\n");
        }
    }
    return 0;
}
