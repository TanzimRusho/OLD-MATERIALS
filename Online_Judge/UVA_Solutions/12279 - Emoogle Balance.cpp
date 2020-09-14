#include<stdio.h>
int main(){
	int n,i,m,c,k=1;
	while(scanf("%d", &n)==1 && n!=0){
        c = 0;
        for(i=0; i<n; ++i){
            scanf("%d", &m);
            m>0? ++c : --c;
        }
        printf("Case %d: %d\n", k++, c);
	}
	return 0;
}
