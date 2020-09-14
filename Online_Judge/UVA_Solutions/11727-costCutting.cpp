#include<cstdio>
#include<algorithm>

static unsigned a[4];

int main(){
    static unsigned i, j, n;
    scanf("%u", &n);

    for(i = 1; i <= n; ++i){
        for(j = 0; j < 3; ++j)
            scanf("%u", &a[j]);

        std::sort(a, a + 3);
        printf("Case %u: %u\n", i, a[1]);
    }

    return 0;
}
