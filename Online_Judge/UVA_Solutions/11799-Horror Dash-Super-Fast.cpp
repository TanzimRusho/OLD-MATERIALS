#include<stdio.h>
int main(){
    int a,c=0,n,i,j,m;
    n=getchar()-48;
    while(n--){
        j=getchar()-48;
        for(i=0;i!=j;++i){
            a=getchar()-48;
            if(i==0){
                m=a;
            }else{
                if(m<a){
                    m=a;
                }
            }
        }
		printf("Case %d: %d\n",++c,m);
    }
    return 0;
}
