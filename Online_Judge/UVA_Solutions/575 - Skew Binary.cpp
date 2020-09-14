#include<stdio.h>
unsigned int twoPow(unsigned int n){    /* My custom recursive function to calculate power of two */
    if(n==0){
        return 1;
    }
    n--;    /* this is our recursive counter we need to decrease it otherwise it will go to infinite loop */
    return 2*twoPow(n); /* simply keep multiplying 2 given times to get power of two */
}
int main(){
    char s[32];
    unsigned int i,j,sum;   /* here i used unsigned since none of our input or outputs are negative */
    while(gets(s)){
        if(s[0]=='0' && s[1]=='\0'){    /* check if its 0 then exit, Maybe even deleting the NULL check will work for this problem */
            return 0;
        }
        sum = 0;
        for(i=0; s[i]!='\0'; ++i);  /* get the string length */
        for(j=0; s[j]!='\0'; ++j){
            sum = sum + (s[j]-48)*(twoPow(i-j)-1);  /* convert character to integer, then multiply 2 to the power n, then subtract 1 and add to sum */
        }
        printf("%u\n", sum);
    }
    return 0;
}
