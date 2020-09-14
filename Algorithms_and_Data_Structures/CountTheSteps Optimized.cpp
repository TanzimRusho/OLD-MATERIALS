#include<stdio.h>
#include<limits.h>

int min(int a, int b){
    return a < b ? a : b;
}

int countSteps(int n){
    int qmin = INT_MAX;

    if(n <= 1)
        return 0;

    if(n > 1){
        qmin = min(qmin, 1 + countSteps(n - 1));
    }
    if(n % 2 == 0){
        qmin = min(qmin, 1 + countSteps(n / 2));
    }
    if(n % 3 == 0){
        qmin = min(qmin, 1 + countSteps(n / 3));
    }

    return qmin;
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n", countSteps(n));

    return 0;
}
