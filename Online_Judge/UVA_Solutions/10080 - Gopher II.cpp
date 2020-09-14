#include<stdio.h>
int main(){
	unsigned int n,m,s,v;
	float gx[100], gy[100], hx[100], hy[100];
	while(scanf("%u%u%u%u", &n, &m, &s, &v)==1){
        unsigned int i=0, j=0;
        for(; i<n; ++i){
            scanf("%f%f", &gx[i], &gy[i]);
        }
        for( j<m; ++j){
            scanf("%f%f", &hx[i], &hy[i]);
        }
	}
	return 0;
}
