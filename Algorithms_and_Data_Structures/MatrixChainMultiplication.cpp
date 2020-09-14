#include<stdio.h>
#include<limits.h>

#define N 6

int count;
int p[] = {30,35,15,5,10,20,25};
int m[N+1][N+1], s[N+1][N+1];

void PrintOptimalParentheses(int i, int j){
    if(i == j)
        printf("A%d", i);
    else{
        printf("(");
        PrintOptimalParentheses(i, s[i][j]);
        PrintOptimalParentheses(s[i][j] + 1, j);
        printf(")");
        ++count;
    }
}

int main(){
    count = 0;

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

    PrintOptimalParentheses(1, N);
    printf("\nCount: %d\n", count);

    return 0;
}
