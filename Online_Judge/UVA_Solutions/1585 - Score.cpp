#include<stdio.h>

int main(){
	register unsigned int n, i;
    char s[128];

	scanf("%u", &n);

	while (n--){
        scanf("%s", s);
        unsigned int sum = 0, val = 0;

        for (i=0; s[i]; ++i){

            /**
             * 79 is decimal ASCII 'O', Applying XOR
             * If two numbers are same then we get 0, otherwise 1
             */
            (s[i] ^ 79) ? val = 0: ++val;
            sum += val;
        }

        printf("%u\n", sum);
	}
	return 0;
}
