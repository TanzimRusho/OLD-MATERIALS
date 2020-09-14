#include<stdio.h>
unsigned int twoPow(unsigned int m){
    if(m==1){
        return 2;
    }
    m--;
    return 2*twoPow(m);
}
int main(){
	unsigned int n, m, c=1;
	scanf("%d", &n);
	while(n--){
        scanf("%d", &m);
        if(m==1){
            printf("Scenario #%d:\n%d\n", c++, 2);
        }else{
            printf("Scenario #%d:\n%d\n", c++, twoPow(m)-m);
        }
	}
	return 0;
}
