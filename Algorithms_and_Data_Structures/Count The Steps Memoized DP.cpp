#include<stdio.h>
#include<limits.h>

#define SIZE 2000

static int cs[SIZE];

int min(int a, int b){
    return a > b ? b : a;
}

int countTheSteps(int n){
    if(cs[n] != -1)
        return cs[n];

    int qmin = INT_MAX;

    if(n > 1)
        qmin = min(qmin, 1 + countTheSteps(n - 1));
    if(n % 2 == 0)
        qmin = min(qmin, 1 + countTheSteps(n / 2));
    if(n % 3 == 0)
        qmin = min(qmin, 1 + countTheSteps(n / 3));

    return cs[n] = qmin;
}

int main(){
    int n;
    scanf("%d", &n);

    cs[1] = 0;
    for(int i = 2; i <= n; ++i)
        cs[i] = -1;

    printf("%d\n", countTheSteps(n));

    return 0;
}
