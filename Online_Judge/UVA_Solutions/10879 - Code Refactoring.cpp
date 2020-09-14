#include<stdio.h>
int main(){
	unsigned int n, c = 1;
	scanf("%u", &n);
	while(n--){
        unsigned int m, i, found = 0;
        scanf("%u", &m);
        printf("Case #%u: %u", c++, m);
        for(i=2; i<m; ++i){
            if(found == 2){
                break;
            }
            if(m%i==0){
                printf(" = %u * %u", i, m/i);
                ++found;
            }
        }
        printf("\n");
	}
	return 0;
}
