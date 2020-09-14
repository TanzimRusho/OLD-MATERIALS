/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<string.h>
int main(){
    char input[110];
	while(gets(input)){
        const unsigned int len = strlen(input);
        if(input[0] == '0' && len == 1) return 0;
        register unsigned int i = 0;
        unsigned int digit, remainder = 0;
        for(; i < len; ++i){
            remainder = (remainder*10 + input[i]-'0') % 17;
        }
        remainder ? printf("0\n") : printf("1\n");
	}
	return 0;
}
