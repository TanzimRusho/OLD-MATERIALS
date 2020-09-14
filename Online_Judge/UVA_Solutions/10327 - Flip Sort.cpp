#include<stdio.h>

int main(){
    int n, i, temp, j, k;
    int a[1010];
	while(scanf("%d", &n)==1){
        for(i = k = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }

        for(j = 0; j < n; ++j){
            for(i = 0; i < n - 1; ++i){
                if(a[i] > a[i + 1]){
                    temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                    ++k;
                }
            }
        }

        printf("Minimum exchange operations : %d\n", k);
	}
	return 0;
}
