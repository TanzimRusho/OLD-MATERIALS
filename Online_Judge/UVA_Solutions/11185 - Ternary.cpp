#include<stdio.h>

static int a[20];

int main(){
	int n, k, i;

	while(scanf("%d", &n) && n > -1){
        k = i = 0;
        while(n){
            a[k++] = n % 3;
            n /= 3;
        }

        if(k){
            for(i = k - 1; i >= 0; --i)
                printf("%d", a[i]);
            printf("\n");
        }else
            printf("0\n");
	}
	return 0;
}
