#include<stdio.h>
int main(){
    int a,c=0,n,i,j,m;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&j);
        ++c;
        for(i=0;i!=j;++i){
            scanf("%d",&a);
            if(i==0){
                m=a;
            }else{
                if(m<a){
                    m=a;
                }
            }
        }
        printf("Case %d: %d\n",c,m);
    }
    return 0;
}
