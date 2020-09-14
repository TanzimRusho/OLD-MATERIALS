#include<stdio.h>
#include<math.h>
int main(){
    int n;
    float a,b,c;
    scanf("%d", &n);
    while(n--){
        scanf("%f%f%f", &a, &b, &c);
        a = sqrt(a*a+b*b);
        printf("%.2f %.2f\n", c-a, c+a);
    }
    return 0;
}
