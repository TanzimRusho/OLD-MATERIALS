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

void dynamicKnapsack(){
    int i = 0;

    /*
     * Set each column in first(zeroth) row to zero
     */
    for(; i <= total_weight; ++i)
        CostTable[0][i] = 0;

    /*
     * Set each row in first(zeroth) column to zero
     */
    for(int i = 0; i <= item_count; ++i){
        CostTable[i][0] = 0;

        /*
         * calculate till required weight
         */
        for(int w = 1; w <= total_weight; ++w){
            /*
             * Get value from row above
             * or,
             * the value from a left column (w - Weight[i]) in the row above with added benefit
             */
            if(Weight[i] <= w)
                CostTable[i][w] = max(Benefit[i] + CostTable[i-1][w - Weight[i]], CostTable[i-1][w]);
            else
                CostTable[i][w] = CostTable[i-1][w];
        }
    }


    for(int j = 0; j <= item_count; ++j){
        for(int k = 0; k <= total_weight; ++k)
            printf("%d ", CostTable[j][k], j, k);
        printf("\n");
    }

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

    dynamicKnapsack();

    printf("%d\n", CostTable[item_count][total_weight]);

    return 0;
}
