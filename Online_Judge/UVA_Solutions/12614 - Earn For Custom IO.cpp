#include<stdio.h>
void Rfastscan(register unsigned int &x){
    register int c;
    x = 0;
    c = getchar();
    for(;(c>47 && c<58); c = getchar()) x = (x<<1) + (x<<3) +c -48;
}

void fastscan(int &x){
    unsigned int neg = 0;
    register unsigned int c;
    x = 0;
    c = getchar();
    if(c == '-'){
        neg = 1;
        c = getchar();
    }
    for(;(c>47 && c<58); c = getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x = ~x+1;   /* 2's complement */
}


int main(){
    register unsigned int n, m, i, c = 1;
    int a, max;
    Rfastscan(n);
    while(n--){
        Rfastscan(m);
        fastscan(max);
        for(i=1; i<m; ++i){
            fastscan(a);
            if(a > max){
                max = a;
            }
        }
        printf("Case %u: %u\n", c++, max);
    }
    return 0;
}
