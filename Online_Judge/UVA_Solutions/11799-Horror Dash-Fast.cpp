//actually this is even more slower
#include<stdio.h>
int main(){
    int a,c=0,m=-1,n,j;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&j);
        ++c;
        while(j--){
            scanf("%d",&a);
            if(a>m){
                m=a;
            }
        }
        printf("Case %d: %d\n",c,m);
        m=-1;
    }
    return 0;
}
