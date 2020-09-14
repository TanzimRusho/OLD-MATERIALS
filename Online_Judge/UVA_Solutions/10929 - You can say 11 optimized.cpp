#include<stdio.h>
#include<string.h>
static char s[1024];
int main(){
    register unsigned i;
    while(gets(s)){
        unsigned len = strlen(s);
        if(s[0] == '0' && len == 1) return 0;
        int sum = 0;
        for(i = 0; i < len; i+=2)
            sum += s[i] - '0';

        for(i = 1; i < len; i+=2)
            sum -= s[i] - '0';

        printf(sum%11 ? "%s is not a multiple of 11.\n" : "%s is a multiple of 11.\n", s);
    }
    return 0;
}
