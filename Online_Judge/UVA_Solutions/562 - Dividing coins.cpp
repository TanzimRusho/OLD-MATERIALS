#include <stdio.h>

static int weight[501];
static int cost[501];
static int K[501][50001];

static int i, w;

int maximum(int a, int b){
    return a > b ? a : b;
}

int knapsack(int W, int n) {

    for (w = 0; w <= W; ++w)
        K[0][w] = 0;

    for (i = 1; i <= n; ++i) {
        K[i][0] = 0;

        for (w = 1; w <= W; ++w) {

            if (weight[i - 1] <= w)
                K[i][w] = maximum(cost[i - 1] + K[i - 1][w - weight[i - 1]],  K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {

    int i, test_cases, n, total, max;

    scanf("%d", &test_cases);

    while (test_cases--) {

        scanf("%d", &n);

        total = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d", &weight[i]);
            total += cost[i] = weight[i];
        }

        max = knapsack(total / 2, n); /* total - max is what the other guy recieved */

        printf("%d\n", total - 2 * max);
    }

    return 0;
}
