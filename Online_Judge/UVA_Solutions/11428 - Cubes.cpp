#include<stdio.h>
#include<math.h>
int main(){
	int n;
	while(scanf("%d", &n) && n!=0){
        int works = 0, i, j;
        for(i=1; i<=sqrt(n);){
            if(i*i*i > n){
                for(j=1; j<i;){
                    if(i*i*i - j*j*j == n){
                        works = 1;
                        break;
                    }
                    ++j;
                }
                if(works) break;
            }
            ++i;
        }
        if(works){
            printf("%d %d\n", i, j);
        }else{
            printf("No solution\n");
        }
	}
	return 0;
}
