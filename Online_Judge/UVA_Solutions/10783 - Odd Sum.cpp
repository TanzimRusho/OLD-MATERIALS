#include<stdio.h>
int main(){
    int n,c=1,i,s,a,b;
    scanf("%d",&n);
    while(n--){
        s=0;
        scanf("%d%d",&a,&b);
        for(i=a;i<=b;i++){
            if(i%2==1){
                s+=i;
            }
        }
        printf("Case %d: %d\n",c,s);
        ++c;
    }
	return 0;
}
