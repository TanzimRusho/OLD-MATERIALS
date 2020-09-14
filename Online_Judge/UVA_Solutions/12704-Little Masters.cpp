#include<stdio.h>
#include<math.h>
int main(){
    int n,x,y,r;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d", &x, &y, &r);
        if(x+y==0){
            printf("%.2f %.2f\n", r, r);
        }else if(x==0 || y==0){
            printf("%.2f %.2f\n", 0, (float)x+y+r);
        }else{
            printf("%.2f %.2f\n", sqrt(x*x+y*y), x*x+y*y-r);
        }
    }
    return 0;
}
