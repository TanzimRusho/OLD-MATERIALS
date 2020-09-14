#include<stdio.h>
#include<limits.h>

#define SIZE 128

int count, N;
int m[SIZE+1][SIZE+1], s[SIZE+1][SIZE+1], p[SIZE+1];

void PrintOptimalParentheses(int i, int j){
    if(i == j)
        printf("A%d", i);
    else{
        printf("(");
        PrintOptimalParentheses(i, s[i][j]);
        printf(" x ");
        PrintOptimalParentheses(s[i][j] + 1, j);
        printf(")");
        ++count;
    }
}

void MatrixChainMultiplication(){
    for(int i = 0; i <= N; ++i)
        m[i][i] = 0;

    /*
     * Go through every matrix length
     */
    for(int l = 1; l <= N; ++l){
        for(int i = 1; i <= N - l + 1; ++i){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; ++k){
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void TakeInput(){
    printf("Enter Matrix Count:\n");
    scanf("%d", &N);
    int k = 0;
    for(int i = 0; i < N; ++i){
        if(i == N - 1){
            scanf("%d", &p[k]);
            ++k;
            scanf("%d", &p[k]);
            ++k;
        }
        else
            scanf("%d %*d", &p[k++]);
    }

    for(int i = 0; i <= N; ++i)
        printf("%d ", p[i]);
}

int main(){
    TakeInput();
    MatrixChainMultiplication();
    PrintOptimalParentheses(1, N);
    printf("\nCount: %d\n", count);

    return 0;
}
