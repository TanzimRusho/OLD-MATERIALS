#include<stdio.h>

int main(){
	int n;
	while(scanf("%d", &n)==1 && n!=0){
        int a[105] = {0}, k=0, p=0, i=0;

        while(n){
            a[k++] = n%2;
            n /= 2;
        }

        printf("The parity of ");
        for(i=k-1; i>=0; --i){
            printf("%d", a[i]);
            if(a[i]==1){
                ++p;
            }
        }
        printf(" is %d (mod 2).\n", p);
	}
	return 0;
}
