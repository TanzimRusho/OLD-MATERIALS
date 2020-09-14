#include<stdio.h>
int main(){
    int k,n,m,x,y;
    while(scanf("%d",&k)==1){
        if(!k) return 0;
        scanf("%d %d",&n,&m);
        while(k--){
            scanf("%d %d",&x,&y);
            if(n==x || m==y) printf("divisa\n");
            else if(x>n && y>m) printf("NE\n");
            else if(x<n && y>m) printf("NO\n");
            else if(x>n && y<m) printf("SE\n");
            else if(x<n && y<m) printf("SO\n");
        }
    }
    return 0;
}
