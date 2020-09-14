#include<stdio.h>
#include<math.h>
int main(){
	unsigned int type, c = 1;
	double a,u,v,t,s;
	while(scanf("%u", &type)){
        switch(type){
        case 1:
            scanf("%lf%lf%lf", &u, &v, &t);
            a = (v-u)/t;
            s = ((v*v)-(u*u))/(2*a);
            printf("Case %d: %.3lf %.3lf\n", c++, s, a);
            break;
        case 2:
            scanf("%lf%lf%lf", &u, &v, &a);
            t = (v-u)/a;
            s = ((v*v)-(u*u))/(2*a);
            printf("Case %d: %.3lf %.3lf\n", c++, s, t);
            break;
        case 3:
            scanf("%lf%lf%lf", &u, &a, &s);
            v = sqrt((u*u)+(2*a*s));
            t = (v-u)/a;
            printf("Case %d: %.3lf %.3lf\n", c++, v, t);
            break;
        case 4:
            scanf("%lf%lf%lf", &v, &a, &s);
            u = sqrt((v*v)-(2*a*s));
            t = (v-u)/a;
            printf("Case %d: %.3lf %.3lf\n", c++, u, t);
            break;
        default:
            return 0;
        }
	}
}
