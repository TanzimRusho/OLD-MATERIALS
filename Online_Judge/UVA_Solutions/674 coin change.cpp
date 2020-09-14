#include <stdio.h>
#define N 8192

static int a[N] = {1, 1};
static const int coins[5] = {1, 5, 10, 25, 50};

int main()
{
    register int i, j;
    for(i = 0; i < 5; ++i){
        for(j = 2; j < N; ++j){
            if(j >= coins[i])
                a[j] += a[ j - coins[i] ];
        }
    }

    int n;
    a[0] = 0;
    while(scanf("%d", &n) == 1)
        printf("%d\n", a[n]);

    return 0;
}
