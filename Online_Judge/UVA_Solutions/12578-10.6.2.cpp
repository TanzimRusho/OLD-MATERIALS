#include<stdio.h>
#include<math.h>
int main(){
    int n;
    double a,l;
    scanf("%d",&n);
    while(n--){
        scanf("%lf",&l);
        a = acos(-1)*(l*l)/25;
        printf("%0.30lf\n",acos(-1));
        printf("%.2lf %.2lf\n", a, (l*((l*6)/10))-a);
    }
    return 0;
}
/*
#include<stdio.h>
#define P 3.1415926535897931
int main(){
    int n;
    double a,l;
    scanf("%d",&n);
    while(n--){
        scanf("%lf",&l);
        l=l*l;
        a = P*l/25;
        printf("%.2lf %.2lf\n", a, l*0.6-a);
    }
    return 0;
}
*/
