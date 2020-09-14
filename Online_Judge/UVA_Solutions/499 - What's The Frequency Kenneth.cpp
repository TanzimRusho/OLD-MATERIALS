/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: uva 499 ( What's The Frequency, Kenneth )
 */
#include<stdio.h>
int main(){
    char s[201];
	while(gets(s)){
        unsigned int i = 0, upcase[27] = {0}, lowcase[27] = {0};    /* Declare array for counting upper and lower case letters */
        for(; s[i]!='\0'; ++i){
            if(s[i] >= 'A' && s[i] <= 'Z'){         /* Check if upper case letter as the input may contain other characters */
                upcase[s[i] - 'A']++;               /* Subtracting a character ASCII ( upper and lower case ) from its base ASCII will give us an index from 0 to 26 */
            }else if(s[i] >= 'a' && s[i] <= 'z'){   /* Check if lower case letter */
                lowcase[s[i] - 'a']++;
            }
        }
        unsigned int max = upcase[0];               /* Set the first index as max then compare against all array to find maximum occurrence of a letter */
        for(i=0; i<26; ++i){
            if(upcase[i] > max){
                max = upcase[i];
            }
            if(lowcase[i] > max){
                max = lowcase[i];
            }
        }
        for(i=0; i<26; ++i){
            if(upcase[i] == max){
                printf("%c", 'A'+i);                /* Print the uppercase letters first since it was specified in the problem */
            }
        }
        for(i=0; i<26; ++i){
            if(lowcase[i] == max){
                printf("%c", 'a'+i);                /* Now print the uppercase letters */
            }
        }
        printf(" %u\n", max);                       /* Now print their frequency which is the max frequency */
	}
	return 0;
}
