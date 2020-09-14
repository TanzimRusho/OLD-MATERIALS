#include<stdio.h>
#include<limits.h>

#define N 1024

/**
 * Array to hold minimum number of steps
 */
int CS[N];

/**
 * Parallel array to hold operation numbers EX: 1,2,3
 */
int S[N];

/**
 * Function to calculate minimum number of steps
 */
int countSteps(int n){
    /**
     * Terminating condition for Top Down Recursion
     * If there exist a positive value in the array that means no further calculation needed
     * In this case just return the already calculated value
     */
    if(CS[n] != -1)
        return CS[n];

    /**
     * Since we are minimizing the number of steps So we set the biggest value
     * Now in our calculations the we will only find smaller values and replace in the array
     */
    CS[n] = INT_MAX;
    int temp;

    /**
     * Taking the branch on 1 calculate all possible steps
     * If smaller steps found then already calculated small steps
     * So store the count and also store the value for which smaller steps found
     */
    if(n > 1){
        temp = 1 + countSteps(n - 1);
        if(temp < CS[n]){
            CS[n] = temp;
            S[n] = 1;
        }
    }

    if(n % 2 == 0){
        temp = 1 + countSteps(n / 2);
        if(temp < CS[n]){
            CS[n] = temp;
            S[n] = 2;
        }
    }

    if(n % 3 == 0){
        temp = 1 + countSteps(n / 3);
        if(temp < CS[n]){
            CS[n] = temp;
            S[n] = 3;
        }
    }

    return CS[n];
}

/**
 * If there is one step then we print that step and from array we print the rest of the steps
 * If it was 2 or 3 we print that and we print rest of the operation
 */
void printSolution(int n){
    if(S[n] != 0){
        if(S[n] == 1){
            printf("Minus 1\n");
            printSolution(n - 1);
        }
        else{
            printf("Divide by %d\n", S[n]);
            printSolution(n / S[n]);
        }
    }
}

int main(){
    register unsigned i, n;

    printf("Enter Steps to Find Minimum Steps:\n");
    scanf("%u", &n);

    CS[1] = 0;
    for(i = 2; i <= n; ++i)
        CS[i] = -1;

    printf("%d steps\n", countSteps(n));
    printSolution(n);

    return 0;
}
