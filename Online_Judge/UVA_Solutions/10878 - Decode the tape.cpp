#include<stdio.h>
int main(){
    char s[50];
	while(gets(s)){
        unsigned int bit = 128, sum = 0, found = 0, i = 0;  /* Since the binary form is 8 characters long ( not including . or | ) 2^7 = 128 ( 7 but not 8 starts from 0. 2^0....2^7 total 8 digits ) we keep left shifting and adding only if we find a hole */
        if(s[i]!='|') continue;     /* We don't want to print anything for lines not starting with | */
        for(i=0; s[i]!='\0'; ++i){
            if(s[i]==' '){
                bit >>= 1;          /* keep shifting bits right ( makes them smaller. Ex, 128 = 2^7. So, 128 >> 1 = 64, 2^7 >> 1 = 2^6 = 64 ) OR, you can shift bits to left make them bigger but then you have search the string in reverse order */
            }else if(s[i]=='o'){
                sum += bit;         /* Add the bits where we find a hole */
                bit >>= 1;
            }
        }
        printf("%c", sum);          /* Print the sum. No need to print newline. The last line of tape represents a newline character |    o. o | */
	}
	return 0;
}
