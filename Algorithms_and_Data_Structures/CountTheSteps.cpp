#include<stdio.h>

int steps = 0;

void countSteps(int n){
    if(n == 1)
        return;

    if (n % 3 == 0){
        ++steps;
        printf("n/3\n");
        countSteps(n/3);
    }
    else if (n % 2 == 0){
        ++steps;
        printf("n/2\n");
        countSteps(n/2);
    }
    else{
        ++steps;
        printf("n-1\n");
        countSteps(n-1);
    }
}

int main(){

    countSteps(30);
    printf("%d\n", steps);

    return 0;
}
