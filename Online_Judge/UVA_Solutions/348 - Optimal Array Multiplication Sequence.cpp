#include<stdio.h>
#include<limits.h>

#define SIZE 128

static int p[SIZE], m[SIZE][SIZE], s[SIZE][SIZE];

void PrintOptimalParentheses(int i, int j){
    if(i == j)
        printf("A%d", i);
    else{
        printf("(");
        PrintOptimalParentheses(i, s[i][j]);
        printf(" x ");
        PrintOptimalParentheses(s[i][j] + 1, j);
        printf(")");
    }
}

int main(){
    register int n, i, l, j, k, c = 0;

    while(scanf("%d", &n) && n){

        /*
         * Input Sequence
         */
        for(i = 0; i < n - 1; ++i)
            scanf("%d%*d", &p[i]);
        scanf("%d", &p[i]);
        ++i;
        scanf("%d", &p[i]);

        /*
         * Matrix Multiplication Cost
         */
        for(int i = 0; i < n; ++i)
            m[i][i] = 0;

        /*
         * Go through every matrix length
         */
        for(l = 1; l <= n; ++l){
            for(i = 1; i <= n - l + 1; ++i){
                j = i + l - 1;
                m[i][j] = INT_MAX;
                for(k = i; k < j; ++k){
                    int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                    if(q < m[i][j]){
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }

        /*
         * Print Optimal Parenthesis
         */
        printf("Case %d: ", ++c);
        PrintOptimalParentheses(1, n);
        printf("\n");
    }

    return 0;
}
