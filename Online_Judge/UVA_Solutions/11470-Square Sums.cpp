#include<stdio.h>
int main(){
    int n,i,j;
    int s1,s2;
    int m[15][15];
    while(scanf("%d",&n)==1){
        if(!n) return 0;
        s1=s2=0;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%d",&m[i][j]);
            }
        }
        //outer layer sum
        for(j=0; j<n; j++) s1+=m[0][j];
        for(j=0; j<n; j++) s1+=m[n-1][j];
        for(i=0; i<n; i++) s1+=m[i][0];
        for(i=0; i<n; i++) s1+=m[i][n-1];
        s1 = s1-m[0][0]-m[0][n-1]-m[n-1][0]-m[n-1][n-1];
        //inner layer sum
        for(j=1; j<n-1; j++) s2+=m[1][j];
        for(j=1; j<n-1; j++) s2+=m[n-2][j];
        for(i=1; i<n-1; i++) s2+=m[i][1];
        for(i=1; i<n-1; i++) s2+=m[i][n-2];
        s2 = s2-m[1][1]-m[1][n-2]-m[n-2][1]-m[n-2][n-2];
        printf("%d\n", s1);
        printf("%d\n", s2);
    }
    return 0;
}
