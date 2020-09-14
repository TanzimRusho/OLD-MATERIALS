#include<stdio.h>
int main(){
    int n,i,j;
    float a[15],av,s;
    int p1,p2;
    float p3;
    scanf("%d",&n);
    for(j=1;j<=n;j++){
        s=0;
        for(i=0; i<12; i++){
            scanf("%f",&a[i]);
            s+=a[i];
        }
        av=s/12;

        if(av/1000>0){
           p1=av/1000;
           printf("%d $%d,%.2f\n",j, p1, av-p1*1000);
        }else{
            printf("%d $%.2f\n",j,av);
        }
    }
    return 0;
}
