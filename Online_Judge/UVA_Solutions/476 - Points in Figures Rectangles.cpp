#include<stdio.h>
#include<stdbool.h>

int main(){
    char c;
	int i,j=0,k=1;
	float f[11][11],x,y;
	bool available;

	while(scanf("%c", &c)==1 && c!='*'){
        for(i=0; i<4; ++i){
            scanf("%f", &f[j][i]);
        }
        ++j;
	}

	while(scanf("%f%f", &x, &y)==2){
        available = false;
        if(x==y && (long) x == (long) 9999.9){
            return 0;
        }
        for(i=0; i<j; ++i){
            if( x>=f[i][0] && x<=f[i][2] && y>=f[i][3] && y<=f[i][1] ){
                printf("Point %d is contained in figure %d\n", k, i+1);
                available = true;
            }
        }
        if(!available){
            printf("Point %d is not contained in any figure\n", k);
        }
        ++k;
	}
	return 0;
}
