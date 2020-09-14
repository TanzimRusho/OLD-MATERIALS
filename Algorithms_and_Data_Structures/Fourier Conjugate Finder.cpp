/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>

static char s[16];

int main(){
	register unsigned n, i;

	printf("How many times do you want to run the program?\n");
	scanf("%u", &n); getchar();

	while (n--){

        printf("Enter complex number to find conjugate:\n");
        gets(s);

        for (i = 0; s[i]; ++i){
            /*
             * A simple check to see if it is a valid complex number or not
             * This code is not full proof, easily breakable for many input instances
             */
            if ((s[i] >= '0' && s[i] <= '9') || s[i] == 'i' || s[i] == '+' || s[i] == '-' || s[i] == '/' ){
                if (s[i] == '+'){
                    s[i] = '-';
                    break;
                }
                else if (s[i] == '-'){
                    s[i] = '+';
                    break;
                }
            }
        }

        printf("Conjugate: %s\n", s);
	}
	return 0;
}
