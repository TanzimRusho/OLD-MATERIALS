#include<stdio.h>
#include<string.h>

static long long s[30], b[30];

int main() {
    static unsigned i, n;

    b[1] = b[2] = 1;
    for(i = 3; i < 27; ++i)
        b[i] = b[i-1] * (4 * i - 6)/i;

    s[1] = s[2] = 1;
    for(i = 3; i < 27; ++i)
        s[i] = ( (6 * i - 9) * s[i - 1] - (i - 3) * s[i - 2] ) / i;

    while (scanf("%u", &n) == 1)
        printf("%lld\n", s[n] - b[n]);

    return 0;
}
