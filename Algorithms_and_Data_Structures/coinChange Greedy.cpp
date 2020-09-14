#include<stdio.h>
#include<limits.h>

#define N 1000

static int cc[N];
static int s[N];

int min(int qmin, int cc){
    return qmin > cc ? cc : qmin;
}

int coinChange(int n){
    if ( cc[n] != -1 )
        return cc[n];

    int qmin = INT_MAX;
    int cmin = -1;

    if (n >= 50)
        qmin = min(qmin, 1 + coinChange(n - 50));

    if (n >= 25)
        qmin = min(qmin, 1 + coinChange(n - 25));

    if (n >= 10)
        qmin = min(qmin, 1 + coinChange(n - 10));

    if (n >= 1)
        qmin = min(qmin, 1 + coinChange(n - 1));

    return cc[n] = qmin;
}

int main(){

    cc[0] = 0;
    for (int i = 1; i < N; ++i)
        cc[i] = -1;

    printf("Number of coins %d\n", coinChange(300));

    return 0;
}
