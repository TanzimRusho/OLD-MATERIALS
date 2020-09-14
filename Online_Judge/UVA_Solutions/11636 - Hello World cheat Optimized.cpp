#include<stdio.h>
static unsigned arr[10010];

void precalculate(){
    register unsigned n = 10001;
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 2;
    arr[5] = 3;
    arr[6] = 3;
    arr[7] = 3;
    arr[8] = 3;

    /**
     * If you look carefully there is a nice pattern here
     * This code can be shorted with a nested loop
     * 2^N < Number <= 2^(N-1) + 1
     */
    for(; n >= 8193; --n)
        arr[n] = 14;
    for(; n >= 4097; --n)
        arr[n] = 13;
    for(; n >= 2049; --n)
        arr[n] = 12;
    for(; n >= 1025; --n)
        arr[n] = 11;
    for(; n >= 513; --n)
        arr[n] = 10;
    for(; n >= 257; --n)
        arr[n] = 9;
    for(; n >= 129; --n)
        arr[n] = 8;
    for(; n >= 65; --n)
        arr[n] = 7;
    for(; n >= 33; --n)
        arr[n] = 6;
    for(; n >= 17; --n)
        arr[n] = 5;
    for(; n >= 9; --n)
        arr[n] = 4;
}
int main(){
    precalculate();
    int n;
    register unsigned c = 1;
    while(scanf("%d", &n) && n>-1){
        printf("Case %u: %u\n", c, arr[n]);
        ++c;
    }
    return 0;
}
