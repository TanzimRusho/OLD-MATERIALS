#include<stdio.h>

int main(){
	int n, m, i, c = 1, a[51];
	int high, low;
	scanf("%d", &n);
	while(n--){
        low = high = 0;
        scanf("%d", &m);
        for(i=0; i<m; ++i){
            scanf("%d", &a[i]);
        }
        for(i=0; i<m-1; ++i){
            if(a[i] < a[i+1]){
                ++high;
            }else if(a[i] > a[i+1]){
                ++low;
            }
        }
        printf("Case %d: %d %d\n", c, high, low);
        ++c;
	}
	return 0;
}
