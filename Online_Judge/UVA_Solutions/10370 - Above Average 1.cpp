#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int m;
        scanf("%d", &m);
        int i;
        int a[1001];
        float sum = 0;
        for(i=0; i<m; ++i){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sum /= m;
        int c = 0;
        for(i=0; i<m; ++i){
            if(sum < a[i]){
                ++c;
            }
        }
        printf("%.3f%\n", (c*100.0)/m);
    }
    return 0;
}
