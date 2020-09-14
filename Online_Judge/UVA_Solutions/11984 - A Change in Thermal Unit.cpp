#include<stdio.h>

int main(){
	int n, c = 1;
	float ce, fa;
	scanf("%d", &n);
	while(n--){
        scanf("%f %f", &ce, &fa);
        fa = ((9*ce/5)+ fa) *5/9;
        printf("Case %d: %.2f\n", c, fa);
        ++c;
	}
	return 0;
}
