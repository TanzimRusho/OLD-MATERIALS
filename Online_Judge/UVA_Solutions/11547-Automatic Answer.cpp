#include<stdio.h>
int main(){
    register int n;
    int a;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);

        //a = (((((((a * 567) / 9) + 7492) * 235) / 47) - 498) / 10) % 10;

        a = (315 * a + 36962) / 10 % 10;

        printf("%d\n", a < 0 ? -a : a);
    }
    return 0;
}
