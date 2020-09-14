#include<stdio.h>
int main(){
    int i,n;
    scanf("%d",&n);
    char a[6];
    while(n--){
        gets(a);
        for(i=0;a[i]!='\0';i++);
        if(i==3){
            if((a[0]+a[1]+a[2]>='a'+'n'+'o' && a[0]+a[1]+a[2]<='n'+'o'+'z')||(a[0]+a[1]+a[2]>='a'+'n'+'e' && a[0]+a[1]+a[2]<='n'+'e'+'z')||(a[0]+a[1]+a[2]>='a'+'o'+'e' && a[0]+a[1]+a[2]<='z'+'o'+'e')){
                printf("one\n");
            }
            if((a[0]+a[1]+a[2]>='a'+'w'+'o' && a[0]+a[1]+a[2]<='w'+'o'+'z')||(a[0]+a[1]+a[2]>='a'+'t'+'w' && a[0]+a[1]+a[2]<='t'+'w'+'z')||(a[0]+a[1]+a[2]>='a'+'t'+'o' && a[0]+a[1]+a[2]<='z'+'t'+'o')){
                printf("two\n");
            }
        }else{

        }
    }
    return 0;
}
