/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 10696 - f91
 * Type:    Bottom Up (Iterative) Dynamic Programming
 */

#include<cstdio>

#define N 1000000

static int F[N];

int main(){
    int n, i;

    for(i = N; i >= 0; --i){
        if(i >= 101)
            F[i] = i - 10;
        else
            F[i] = F[F[i + 11]];
    }

    while(scanf("%d", &n) && n)
        printf("f91(%d) = %d\n", n, F[n]);

    return 0;
}
