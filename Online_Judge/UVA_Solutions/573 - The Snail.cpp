#include<stdio.h>

#define REP(i,n) for(i=0; i<(n); ++i)
#define MAX (((a)>(b))?(a):(b))

template<class T> inline T abs(T x){
   return x<0?-x:x;
}

template<class T> void swap(T& x, T& y){
    T tmp = x;
    x = y;
    y = tmp;
}

int main(){
	int wallHeight, climb, slide, fatigue;
	while(scanf("%d%d%d%d", &wallHeight, &climb, &slide, &fatigue)){
        if(!wallHeight){
            return 0;
        }
        int day = 1;
        float totalHeight = 0;
        float fatigueAmount = (fatigue/100.0)*climb;
        float climbAmount = climb;
        while(1){
            totalHeight += climbAmount;
            if(totalHeight > wallHeight){
                printf("success on day %d\n", day);
                break;
            }
            totalHeight -= slide;
            if(totalHeight < 0){
                printf("failure on day %d\n", day);
                break;
            }
            climbAmount -= fatigueAmount;
            if(climbAmount < 0) climbAmount = 0;
            ++day;
        }
	}
	return 0;
}
