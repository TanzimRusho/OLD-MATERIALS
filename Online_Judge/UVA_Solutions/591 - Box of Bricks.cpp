#include<stdio.h>

int main(){
    int n,i,sum,maxHeight,moves,temp,c=1;
    int a[100];
    while(scanf("%d", &n)==1 && n!=0){
        moves = sum = 0;
        for(i=0; i<n; ++i){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        maxHeight = sum / n;
        for(i=0; i<n; ++i){
            if(a[i] > maxHeight){
                moves += a[i]-maxHeight;
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", c++, moves);
    }
    return 0;
}
