#include<stdio.h>
#include<limits.h>

static int p[128], m[128][128], s[128][128];

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
    int n, i, l, j, k, c = 0;

    while(scanf("%d", &n) && n){

        for(i = 0; i < n - 1; ++i)
            scanf("%d%*d", &p[i]);
        scanf("%d", &p[i]);
        ++i;
        scanf("%d", &p[i]);

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

        printf("Case %d: ", ++c);
        PrintOptimalParentheses(1, n);
        printf("\n");
    }

    return 0;
}
