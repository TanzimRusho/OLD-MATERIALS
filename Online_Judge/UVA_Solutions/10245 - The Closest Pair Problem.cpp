#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
	unsigned int n;
	while(scanf("%u", &n) && n){
        unsigned int i = 0;
        float shortdist = 10000, curdist = 0, x[10000], y[10000];
        for(; i<n ; ++i){
            scanf("%f%f", &x[i], &y[i]);
        }
        for(i=0; i<n; ++i){
            if(i!=0){
                curdist = sqrt(pow(x[i]-x[i-1], 2)+pow(y[i]-y[i-1], 2));
                if(curdist < shortdist){
                    shortdist = curdist;
                }
            }
        }
        if(shortdist >= 10000){
            printf("INFINITY\n");
        }else{
            printf("%.4f\n", shortdist);
        }
	}
	return 0;
}
