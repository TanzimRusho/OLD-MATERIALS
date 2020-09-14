#include<stdio.h>

inline long long min(long long a, long long b){
    return a > b ? b : a;
}

long long calculateUgly(long long n){
    if(n <= 0)
        return 0;

    long long * uglyNumber = new long long[n+1];
    uglyNumber[0] = 1;
    long long nextUglyIndex = 1;

    long long index2 = 0;
    long long index3 = 0;
    long long index5 = 0;

    while(nextUglyIndex < n){
        long long minimum = min(uglyNumber[index2] * 2, min(uglyNumber[index3] * 3, uglyNumber[index5] * 5));

        uglyNumber[nextUglyIndex] = minimum;

        while(uglyNumber[index2] * 2 <= uglyNumber[nextUglyIndex])
            ++index2;
        while(uglyNumber[index3] * 3 <= uglyNumber[nextUglyIndex])
            ++index3;
        while(uglyNumber[index5] * 5 <= uglyNumber[nextUglyIndex])
            ++index5;

        ++nextUglyIndex;
    }

    return uglyNumber[nextUglyIndex - 1];
}

int main(){

    long long n = 1500;
    printf("%lld\n", calculateUgly(n));

    return 0;
}
