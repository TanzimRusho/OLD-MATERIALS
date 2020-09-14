#include<stdio.h>
int main(){
    int i,n,e,a,b,val;
    while(scanf("%d",&n) && n){
            scanf("%d",&e);
            val = 1;
            for(i=1; i<=e; i++){
                scanf("%d %d",&a,&b);
                if(a>=n || b==0 || b!=i){
                    val=0;
                }
                //printf("a: %d, b: %d, i: %d, val: %d\n",a, b,i, val);
            }
            if(b==e && val){
                printf("BICOLORABLE.\n");
            }else{
                printf("NOT BICOLORABLE.\n");
            }
    }
    return 0;
}
