#include<stdio.h>
int main(){
    register unsigned int n, m, i;
    unsigned int a, max, c = 1;     /* Since we are told we won't get any negative numbers */
    scanf("%u", &n);
    while(n--){
        scanf("%u%u", &m, &max);    /* Assuming m is at least 1, so i scan the first one as max  */
        m -= 1;                     /* Already one input taken, so decrease counter */
        while(m--){
            scanf("%u", &a);
            if(a > max) max = a;
        }
        printf("Case %u: %u\n", c++, max);
    }
    return 0;
}
