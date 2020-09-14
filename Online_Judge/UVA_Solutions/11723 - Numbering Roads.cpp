#include<stdio.h>
int main(){
	unsigned int s, n, c = 1;
	while(scanf("%u%u", &s, &n) && s && n){
        if(n*26 < s){
            printf("Case %u: impossible\n", c++);
        }else{
            unsigned int letter  = 0, i;
            if(s!=n){
                for(i=1; i<26; ++i){
                    if((n*i)+n > s){
                        break;
                    }else{
                        printf("%u\n", ++letter);
                        //++letter;
                    }
                }
            }
            printf("Case %u: %u\n", c++, letter);
        }
	}
	return 0;
}
