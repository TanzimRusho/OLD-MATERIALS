#include<stdio.h>

#define N 128

int CostTable[N][N];
int Weight[N];
int Benefit[N];

int total_weight = 10;
int item_count = 6;

inline int max(int a, int b){
    return a > b ? a : b;
}

int RecursiveKnapsack(int i, int w){
    if(CostTable[i][w] != -1)
        return CostTable[i][w];

    if(Weight[i] > w)
        CostTable[i][w] = RecursiveKnapsack(i - 1, w);
    else
        CostTable[i][w] = max(RecursiveKnapsack(i - 1, w), RecursiveKnapsack(i - 1, w - Weight[i]) + Benefit[i]);
}

int main(){

    Weight[1] = 6;
    Weight[2] = 1;
    Weight[3] = 2;
    Weight[4] = 5;
    Weight[5] = 4;
    Weight[6] = 3;

    Benefit[1] = 10;
    Benefit[2] = 5;
    Benefit[3] = 7;
    Benefit[4] = 12;
    Benefit[5] = 8;
    Benefit[6] = 6;

    /*
     * Set all values of 2D matrix CostTable to Minus 1
     */
    for(int i = 0; i <= item_count; ++i)
        for(int w = 0; w <= total_weight; ++w)
            CostTable[i][w] = -1;


    printf("Max Benefit: %d\n", RecursiveKnapsack(item_count, total_weight));

    return 0;
}
