#include<stdio.h>
int main(){
    int n,a,f,i,j;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d",&a,&f);
        while(f--){
            for(i=1;i<=a;i++){
                for(j=a-i; j<a;j++){
                    printf("%d",i);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
