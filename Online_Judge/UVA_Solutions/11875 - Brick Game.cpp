#include<stdio.h>

int main(){
	int n, m, c=1, i, a[11];
	scanf("%d", &n);
	while(n--){
        scanf("%d", &m);
        for(i=0; i<m; ++i){
            scanf("%d", &a[i]);
        }
        printf("Case %d: %d\n", c,a[i/2]);
        ++c;
	}
	return 0;
}
