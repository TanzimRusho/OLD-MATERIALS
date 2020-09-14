#include<stdio.h>
int main(){
    char s[101][101], i=0,j,k;
	for(j=0; j<101; ++j){
        for(k=0; k<101; ++k){
            s[j][k] = '\0';
        }
	}
    while(gets(s[i])){
        ++i;
	}

	for(j=0; j<101; ++j){
        for(k=0; j<101; ++k){
            printf("%c%c",s[j][k]);
        }
        printf("\n");
	}
	return 0;
}
