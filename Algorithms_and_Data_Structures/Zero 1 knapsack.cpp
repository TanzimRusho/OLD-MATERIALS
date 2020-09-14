#include<stdio.h>

#define N 128

int C[N][N];
int W[N];
int V[N];

int total = 10;
int n = 6;

int max(int a, int b){
    return a > b ? a : b;
}

void dynamicKnapsack(){
    int i = 0;

    /*
     * Set each column in first(zeroth) row to zero
     */
    for(; i <= total; ++i)
        C[0][i] = 0;

    /*
     * Set each row in first(zeroth) column to zero
     */
    for(int i = 0; i <= n; ++i){
        C[i][0] = 0;

        /*
         * calculate till required weight
         */
        for(int w = 1; w <= total; ++w){
            /*
             * Get value from row above
             * or,
             * the value from a left column in the row above with added benefit
             */
            if(W[i] <= w)
                C[i][w] = max(V[i] + C[i-1][w - W[i]], C[i-1][w]);
            else
                C[i][w] = C[i-1][w];
        }
    }

    /*
    for(int j = 0; j < n; ++j){
        for(int k = 0; k < total; ++k)
            printf("%d (%d,%d)", C[j][k], j, k);
        printf("\n");
    }
    */
}

int main(){

    W[0] = 6;
    W[1] = 1;
    W[2] = 2;
    W[3] = 5;
    W[4] = 4;
    W[5] = 3;

    V[0] = 10;
    V[1] = 5;
    V[2] = 7;
    V[3] = 12;
    V[4] = 8;
    V[5] = 6;

    dynamicKnapsack();

    printf("%d\n", C[n][total]);

    return 0;
}
