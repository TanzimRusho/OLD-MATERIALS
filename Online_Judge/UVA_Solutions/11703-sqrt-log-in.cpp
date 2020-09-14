#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)==1){
        if(n==-1){
            return 0;
        }
        if(n==0){
            printf("1\n");
        }else{
            printf("%lf\n",__builtin_sqrtf(n));
        }
    }
    return 0;
}

/*
#include<stdio.h>
inline double rsqrt(int i){
    if(i==0){
        return 1;
    }
    return __builtin_floorf(rsqrt(i-__builtin_sqrtl(i)));
}
inline double rln(int i){
    if(i==0){
        return 1;
    }
    return __builtin_floorf(rsqrt(__builtin_logl(i)));
}
inline double rsin(int i){
    if(i==0){
        return 1;
    }
    return __builtin_floorf(i*__builtin_powl(__builtin_sinl(i), 2));
}
int main(){
    int n;
    while(scanf("%d",&n)==1){
        if(n==-1){
            return 0;
        }
        if(n==0){
            printf("1\n");
        }else{
            printf("%lf\n",rsqrt(n)+rln(n)+rsin(n));
        }
    }
    return 0;
}
*/
