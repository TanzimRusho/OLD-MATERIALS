#include<stdio.h>

#define N 128

int C[N][N];
int W[N];
int V[N];

int total;

void dynamicKnapsack(){
    int i = 0;
    for(; i < total; i += 10)
        C[0][i] = 0;

    for(int j = 0; j < n; ++j){
        C[j][0] = 0;
        for(i = 1; i < total; ++i){
            if(W[j] >= i){
                C[j][i] = max(V[j] + C[j-1][i - W[j]], C[j-1][i]);
            }
            else
                C[j][i] = C[j-1][i];
        }
    }
}

int main(){

    total = 50;
    W[] = {10, 20, 30};
    V[] = {60, 100, 120};

    return 0;
}
