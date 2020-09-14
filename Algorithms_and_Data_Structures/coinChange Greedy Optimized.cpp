#include<stdio.h>
#include<limits.h>

#define N 1000

int cc[N];
int s[N];

int min(int qmin, int cc){
    return qmin > cc ? cc : qmin;
}

int coinChange(int n){
    if ( cc[n] != -1 ) return cc[n];

    cc[n] = INT_MAX;
    int temp;

    if (n >= 50){
        temp = 1 + coinChange(n - 50);
        if (cc[n] > temp){
            cc[n] = temp;
            s[n] = 50;
        }
    }

    if (n >= 25){
        temp = 1 + coinChange(n - 25);
        if (cc[n] > temp){
            cc[n] = temp;
            s[n] = 25;
        }
    }

    if (n >= 10){
        temp = 1 + coinChange(n - 10);
        if (cc[n] > temp){
            cc[n] = temp;
            s[n] = 10;
        }
    }

    if (n >= 1){
        temp = 1 + coinChange(n - 1);
        if (cc[n] > temp){
            cc[n] = temp;
            s[n] = 1;
        }
    }

    return cc[n];
}

void printSolution(int n){
    if(s[n] != 0){
        printSolution(n - s[n]);
        printf("%d cents\n", s[n]);
    }
}

int main(){

    int amount = 309;

    cc[0] = 0;
    for (int i = 1; i <= amount; ++i)
        cc[i] = -1;

    printf("Number of coins %d\n", coinChange(amount));

    //coinChange(amount);

    for (int i = 0; i <= amount; ++i)
        printf("%d ", cc[i]);
    printf("\n");

    for (int i = 0; i <= amount; ++i)
        printf("%d ", s[i]);
    printf("\n");

    printSolution(amount);

    return 0;
}
