#include<stdio.h>
#include<limits.h>

#define N 2000

int cs[N];
int s[N];

int countSteps(int n){
    if(cs[n] != -1)
        return cs[n];

    cs[n] = INT_MAX;
    int temp;

    if(n > 1){
        temp = 1 + countSteps(n - 1);
        if(cs[n] > temp){
            cs[n] = temp;
            s[n] = 1;
        }
    }

    if(n % 2 == 0){
        temp = 1 + countSteps(n / 2);
        if(cs[n] > temp){
            cs[n] = temp;
            s[n] = 2;
        }
    }

    if(n % 3 == 0){
        temp = 1 + countSteps(n / 3);
        if(cs[n] > temp){
            cs[n] = temp;
            s[n] = 3;
        }
    }

    return cs[n];
}

void printSolution(int n){
    if(s[n] != 0){
        if(s[n] == 1){
            printf("Minus 1\n");
            printSolution(n-1);
        }
        else{
            printf("Divide by %d\n", s[n]);
            printSolution(n / s[n]);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    cs[1] = 0;
    for(int i = 2; i <= n; ++i)
        cs[i] = -1;

    printf("%d\n", countSteps(n));

/*
    for (int i = 0; i <= n; ++i)
        printf("%d ", cs[i]);
    printf("\n");
*/

    printSolution(n);

    return 0;
}
