#include<stdio.h>
int main(){
    int n, i, a, max, c = 1;
    scanf("%d", &n);
    while(n--){
        int m;
        scanf("%d", &m);
        for(i=0; i<m; ++i){
            scanf("%d", &a);
            if(i == 0){
                max = a;
            }
            if(a > max){
                max  = a;
            }
        }
        printf("Case %d: %d\n", c++, max);
    }
    return 0;
}
