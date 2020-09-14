#include<stdio.h>
int main(){
    int n,i,j,x,y,sum;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        sum=0;
        scanf("%d%d", &x, &y);
        for(j=x; j<=y; j++){
            if(j%2==1){
                sum += j;
            }
        }
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}
