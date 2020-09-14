/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<string.h>
char s[81];

int main(){
	register unsigned int n;
	unsigned int blank = 0;
	scanf("%u", &n);
	getchar();
	while(n--){
        if(blank) printf("\n");
        blank = 1;
        while(gets(s)){
            if(!strlen(s)) break;
            register unsigned int i = 0;
            for(; s[i]!='\0'; ++i){
                switch(s[i]){
                case '3':
                    s[i] = 'E';
                    break;
                case '7':
                    s[i] = 'T';
                    break;
                case '4':
                    s[i] = 'A';
                    break;
                case '0':
                    s[i] = 'O';
                    break;
                case '1':
                    s[i] = 'I';
                    break;
                case '5':
                    s[i] = 'S';
                    break;
                case '6':
                    s[i] = 'G';
                    break;
                case '9':
                    s[i] = 'P';
                    break;
                case '8':
                    s[i] = 'B';
                    break;
                case '2':
                    s[i] = 'Z';
                    break;
                }
            }
            puts(s);
        }
	}
	return 0;
}
