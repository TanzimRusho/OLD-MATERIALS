#include<stdio.h>

static char t[1024];

int main(){
    register unsigned i;

    char c = 'H';
    int mask = 0b1000001;
    int fix = 0b0000001;

    printf("%c%c\n", (++c & ++mask) | ++fix, 0b0001000 );

    while(gets(t)){
        for(i = 0; t[i]; t[i] -= 7, ++i);
        puts(t);
    }

    return 0;
}
