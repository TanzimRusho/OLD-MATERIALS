/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 11879 ( Multiple of 17 )
 */

#include<stdio.h>

int main(){
    char input[110];
	while(gets(input)){
        if(input[0] == '0' && input[1] == '\0') return 0;   /* You can substitute '0' with 48 and '\0' with 0, ASCII */
        register unsigned int i = 0;
        unsigned int digit, remainder = 0;
        for(; input[i]!='\0'; ++i){
            digit = remainder*10 + input[i]-'0';            /* Each time we multiply by 10 to the digit we are working with and add if there are any remainder from previous operations */
            remainder = digit % 17;                         /* Calculate remainder, if divisible by 17 then remainder becomes 0 */
        }
        remainder ? printf("0\n") : printf("1\n");
	}
	return 0;
}
