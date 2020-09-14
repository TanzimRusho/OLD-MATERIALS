#include<stdio.h>
int main(){
	unsigned int n, a, b, trade;
	scanf("%u", &n);
	while(n--){
        scanf("%u%u%u", &a, &b, &trade);
        unsigned int total = a + b, carry = 0, sum = 0;
        while(total>1){
            sum += total / trade;
            total = total / trade;
            carry = !(total % trade);
            printf("s: %u t: %u c: %u\n", sum, total, carry);
            total += carry;
            printf("%u\n", total);
        }
        printf("%u\n", sum);
	}
	return 0;
}
