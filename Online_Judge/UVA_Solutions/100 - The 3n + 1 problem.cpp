#include<stdio.h>

#define rep(i,n) for(i=0; i<(n); ++i)
#define max (((a)>(b))?(a):(b))

template<class T> inline T abs(T x){
   return x<0?-x:x;
}

template<class T> void swap(T& x, T& y){
    T tmp = x;
    x = y;
    y = tmp;
}

int main(){
	int a,b,i,len=0;
	while(scanf("%d", &a)==1){
        while(1){
            if(a%2){
                a = 3*a+1;
                printf("%d\n", a);
            }else{
                a = a/2;
                printf("%d\n", a);
            }
            ++len;
            if(a==b){
                break;
            }
        }
        printf("%d %d\n", a, len);
	}
	return 0;
}
